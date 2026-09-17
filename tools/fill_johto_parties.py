#!/usr/bin/env python3
"""Fuellt Johtos Trainerteams auf, stufenweise nach den Levelkorridoren.

Regeln, wie mit Marc abgestimmt:
  - Bosse (Leiter, Top Vier, Champion, Rocket-Admins, Silber) auf sechs.
  - Routentrainer mit weniger als drei auf drei.
  - Neuzugaenge kommen aus dem Wildbestand der Karte, auf der der Trainer
    steht, und teilen sich einen Typ mit dem vorhandenen Team.
  - Kein Attackenblock: ohne Angabe nimmt die Engine die Lernsatzattacken
    zum jeweiligen Level. Das ist verlaesslicher als handgesetzte Listen.
"""
import collections
import glob
import json
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PARTY = os.path.join(REPO, 'src/data/trainers_hns.party')

BOSS_CLASSES = {'Leader Hns', 'Leader Kanto Hns', 'Elite Four Hns', 'Champion Hns',
                'Rocket Admin Hns', 'Rival Hns'}
# Klassen, die am Wasser stehen - fuer sie zaehlt der Wasserbestand.
WATER_CLASSES = {'Fisherman Hns', 'Swimmer M Hns', 'Swimmer F Hns', 'Sailor Hns'}

# Klassen mit klarer Erwartung an den Typ. Ein Kaefersammler bekommt Kaefer,
# kein Iksbat, auch wenn sein Spinarak zufaellig ebenfalls Gift ist. Nur die
# Klassen, bei denen die Erwartung eindeutig ist - fuer alle anderen bleibt es
# beim Typbezug zum vorhandenen Team.
CLASS_TYPES = {
    'Bug Catcher Hns':   {'BUG'},
    'Bird Keeper Hns':   {'FLYING'},
    'Fisherman Hns':     {'WATER'},
    'Swimmer M Hns':     {'WATER'},
    'Swimmer F Hns':     {'WATER'},
    'Sailor Hns':        {'WATER'},
    'Firebreather Hns':  {'FIRE'},
    'Hiker Hns':         {'ROCK', 'GROUND'},
    'Black Belt Hns':    {'FIGHTING'},
    'Battle Girl Hns':   {'FIGHTING'},
    'Hex Maniac Hns':    {'GHOST', 'PSYCHIC'},
    'Psychic M Hns':     {'PSYCHIC'},
    'Psychic Hns':       {'PSYCHIC'},
    'Dragon Tamer Hns':  {'DRAGON'},
    'Skier Hns':         {'ICE'},
    'Sage Hns':          {'GHOST', 'PSYCHIC', 'FLYING'},
    'Kimono Girl Hns':   {'PSYCHIC', 'FIRE', 'WATER', 'ELECTRIC', 'GRASS'},
    'Team Rocket Hns':   {'POISON', 'DARK', 'ELECTRIC'},
    'Rocket Admin Hns':  {'POISON', 'DARK', 'ELECTRIC'},
    'Juggler Hns':       {'PSYCHIC', 'ELECTRIC'},
    'Pokemaniac Hns':    {'ROCK', 'GROUND', 'NORMAL'},
    'Biker Hns':         {'POISON', 'FIRE'},
    'Burglar Hns':       {'FIRE'},
    'Officer Hns':       {'NORMAL', 'DARK'},
    'Parasol Lady Hns':  {'WATER'},
}


def species_types():
    types = {}
    for f in glob.glob(os.path.join(REPO, 'src/data/pokemon/species_info/*families.h')):
        t = open(f, encoding='utf-8', errors='replace').read()
        for m in re.finditer(r'\[SPECIES_([A-Z_0-9]+)\]\s*=\s*\{(.*?)\n    \},', t, re.S):
            tm = re.search(r'\.types\s*=\s*MON_TYPES\(([^)]*)\)', m.group(2))
            if tm:
                types[m.group(1)] = {x.strip().replace('TYPE_', '') for x in tm.group(1).split(',') if x.strip()}
    return types


def johto_stages():
    """Mapsection -> Korridorboden, als Stufenkennung."""
    s = open(os.path.join(REPO, 'include/config/johto_scaling.h'), encoding='utf-8').read()
    out = {}
    for m in re.finditer(r'\{\s*(MAPSEC_\w+),\s*(\d+),\s*(\d+)\s*\}', s):
        out[m.group(1)] = (int(m.group(2)), int(m.group(3)))
    return out


def map_info():
    """Kartenverzeichnis -> (Mapsec, Karten-ID)."""
    out = {}
    for p in glob.glob(os.path.join(REPO, 'data/maps/*/map.json')):
        j = json.load(open(p, encoding='utf-8'))
        out[os.path.basename(os.path.dirname(p))] = (j.get('region_map_section'), j.get('id'))
    return out


def wild_pools():
    """Karten-ID -> {'land': [...], 'water': [...]}"""
    d = json.load(open(os.path.join(REPO, 'src/data/wild_encounters.json')))
    g = [x for x in d['wild_encounter_groups'] if x['label'] == 'gWildMonHeaders'][0]
    out = collections.defaultdict(lambda: collections.defaultdict(collections.Counter))
    for e in g['encounters']:
        for field, bucket in (('land_mons', 'land'), ('rock_smash_mons', 'land'),
                              ('water_mons', 'water'), ('fishing_mons', 'water')):
            v = e.get(field)
            if isinstance(v, dict):
                for mon in v['mons']:
                    nm = mon['species'][8:]
                    if nm != 'NONE':
                        out[e['map']][bucket][nm] += 1
    return out


def parse_party():
    txt = open(PARTY, encoding='utf-8', errors='replace').read()
    blocks = re.split(r'(?m)^(?==== )', txt)
    parsed = []
    for b in blocks:
        m = re.match(r'=== (\S+) ===', b)
        if not m:
            parsed.append((None, b))
            continue
        parsed.append((m.group(1), b))
    return parsed


def trainer_maps():
    """Trainer -> Kartenverzeichnisse, auf denen er referenziert wird."""
    out = collections.defaultdict(set)
    for f in glob.glob(os.path.join(REPO, 'data/maps/*/scripts.inc')):
        d = os.path.basename(os.path.dirname(f))
        for m in re.finditer(r'\b(TRAINER_[A-Z_0-9]+_HNS)\b', open(f, encoding='utf-8', errors='replace').read()):
            out[m.group(1)].add(d)
    return out


def main(stage_floor):
    types = species_types()
    stages = johto_stages()
    minfo = map_info()
    pools = wild_pools()
    tmaps = trainer_maps()
    parsed = parse_party()

    # Klassenweiter Rueckfall: welche Arten nutzen andere Trainer derselben Klasse?
    by_class = collections.defaultdict(collections.Counter)
    for name, b in parsed:
        if not name:
            continue
        cm = re.search(r'^Class:\s*(.+)$', b, re.M)
        if not cm:
            continue
        for seg in b.rstrip('\n').split('\n\n')[1:]:
            if 'Level:' in seg:
                by_class[cm.group(1).strip()][seg.split('\n')[0].split(' @ ')[0].strip()] += 1

    added = collections.Counter()
    out = []
    for name, b in parsed:
        if not name or name not in tmaps:
            out.append(b)
            continue
        dirs = [d for d in tmaps[name] if minfo.get(d, (None,))[0] in stages]
        if not dirs:
            out.append(b)
            continue
        # Stufe des Trainers: der niedrigste Korridorboden seiner Karten
        floors = {stages[minfo[d][0]][0] for d in dirs}
        if stage_floor not in floors:
            out.append(b)
            continue

        cls = re.search(r'^Class:\s*(.+)$', b, re.M)
        cls = cls.group(1).strip() if cls else ''
        target = 6 if cls in BOSS_CLASSES else 3

        trail = len(b) - len(b.rstrip('\n'))
        chunks = b.rstrip('\n').split('\n\n')
        header, mons = chunks[0], [c.split('\n') for c in chunks[1:]]
        mons = [m for m in mons if any(l.startswith('Level:') for l in m)]
        if not mons or len(mons) >= target:
            out.append(b)
            continue

        have = {m[0].split(' @ ')[0].strip().upper().replace("'", '').replace('-', '').replace('.', '')
                for m in mons}
        team_types = set()
        for h in have:
            team_types |= types.get(h, set())

        bucket = 'water' if cls in WATER_CLASSES else 'land'
        pool = collections.Counter()
        for d in dirs:
            mid = minfo[d][1]
            pool.update(pools.get(mid, {}).get(bucket, {}))
            if not pool:
                pool.update(pools.get(mid, {}).get('land' if bucket == 'water' else 'water', {}))

        want = CLASS_TYPES.get(cls)

        def rank(sp):
            shared = len(types.get(sp, set()) & team_types)
            return (-shared, -pool[sp])

        cands = [sp for sp in pool if sp not in have]
        # Klassenerwartung geht vor allem anderen. Gibt der Wildbestand der
        # Karte nichts Passendes her, wird lieber ein Pokemon des Trainers
        # verdoppelt, als die Klasse zu brechen - der Wildbestand ist nur eine
        # Grundorientierung, damit keine Endgame-Arten bei frueh sichtbaren
        # Trainern auftauchen.
        if want:
            strict = [sp for sp in cands if types.get(sp, set()) & want]
            if not strict:
                strict = [sp for sp in sorted(have) if types.get(sp, set()) & want]
            if strict:
                cands = strict
        cands.sort(key=rank)
        # Gleichrangige durchrotieren, sonst bekommt jeder Youngster auf einer
        # Route dasselbe Pokemon. Der Versatz haengt am Trainernamen, ist also
        # stabil und nicht zufaellig.
        if len(cands) > 2:
            top = [sp for sp in cands if rank(sp)[0] == rank(cands[0])[0]]
            rest = [sp for sp in cands if sp not in top]
            off = sum(ord(ch) for ch in name) % len(top)
            cands = top[off:] + top[:off] + rest
        # Ohne Wildbestand (Arenen, Gebaeude): Arten derselben Trainerklasse
        if not cands:
            cands = [sp for sp, _ in by_class[cls].most_common()
                     if sp.upper().replace("'", '').replace('-', '').replace('.', '') not in have
                     and types.get(sp.upper().replace("'", '').replace('-', '').replace('.', ''), set()) & team_types]
        if not cands:
            out.append(b)
            continue

        iv = next((l for l in mons[0] if l.startswith('IVs:')), None)
        lvls = [int(re.search(r'Level:\s*(\d+)', '\n'.join(m)).group(1)) for m in mons]
        lo, hi = min(lvls), max(lvls)
        need = target - len(mons)
        for i in range(need):
            sp = cands[i % len(cands)]
            pretty = sp.title().replace('_', ' ')
            seg = [pretty, f'Level: {lo}']
            if iv:
                seg.append(iv)
            mons.insert(len(mons) - 1, seg)   # vor dem bisherigen Ass einfuegen
            added[name] += 1
        n = len(mons)
        for i, seg in enumerate(mons):
            lvl = lo + round((hi - lo) * i / (n - 1)) if n > 1 else lo
            for k, l in enumerate(seg):
                if l.startswith('Level:'):
                    seg[k] = f'Level: {lvl}'
        out.append(header + '\n\n' + '\n\n'.join('\n'.join(s) for s in mons) + '\n' * trail)

    open(PARTY, 'w', encoding='utf-8').write(''.join(out))
    print(f'Stufe mit Boden {stage_floor}: {len(added)} Trainer ergaenzt, {sum(added.values())} Pokemon')


if __name__ == '__main__':
    main(int(sys.argv[1]))
