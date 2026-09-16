#ifndef GUARD_CONFIG_JOHTO_SCALING_H
#define GUARD_CONFIG_JOHTO_SCALING_H

// =====================================================================
// Johto-Levelscaling - Regeldatei (hns_de / modern_hns_engde)
//
// Origin Jade schickt den Spieler als Champion von Kanto nach Johto.
// HnS baut Johto dagegen als Startregion (Falkner Level 8-11). Statt
// alle Trainer und Wildtabellen von Hand hochzuziehen, gilt hier
// dasselbe Prinzip wie in Hoenn: Trainer und wilde Pokemon skalieren
// dynamisch mit dem Spieler, innerhalb eines vom Autor gesetzten
// Korridors pro Gebiet. Die statischen Level in trainers_hns.party
// zaehlen dann nur noch als *Abstaende innerhalb eines Teams*.
//
// Kernregeln (mit Marc abgestimmt):
//  - Anker  = hoechstes Level im Spielerteam, wie in Hoenn.
//  - Routentrainer liegen bei Anker -3 bis +2, Bosse bei Anker +3.
//  - Johto spannt sich ueber Level 45 bis 80: der Einstieg liegt
//    knapp unter dem Kanto-Abschluss (Champion 50-52), die Liga
//    endet bei 80 und uebergibt an Hoenn. Die Deckel der Stufen 1 bis 4
//    sind eng gesetzt (55/61/67/73), damit der Ankunftsbereich nicht
//    sofort ueber dem Spieler liegt.
//  - Die Korridortabelle definiert zugleich die Region: was hier
//    NICHT steht, behaelt die statische HnS-Balance. Damit bleibt
//    Kanto unangetastet (dort gilt Marcs handgesetzte Leiter bis 52),
//    und Sinjoh, die Alola-Inseln, Route 49/50, der Felsenherzturm
//    und der Trainerberg bleiben aussen vor, solange sie nicht
//    erreichbar sind.
//  - Artenzusammensetzung bleibt vanilla - es skalieren NUR Level.
// =====================================================================

#define JOHTO_LEVEL_SCALING          TRUE  // Hauptschalter

// Enger als in Hoenn (-5/+3). Origin Jade schickt keinen Anfaenger durch
// Johto, sondern einen Champion mit gewachsenem Team - da reicht ein
// knapper Abstand, um Kaempfe interessant zu halten. Vier Level ueber dem
// Spieler ist bereits anspruchsvoll, das bleibt den Bossen vorbehalten.
#define JOHTO_SCALING_TRAINER_BELOW  3     // Trainerband: Anker - 3 ...
#define JOHTO_SCALING_TRAINER_ABOVE  2     // ... bis Anker + 2
#define JOHTO_SCALING_WILD_BELOW     10    // Wildband: Anker - 10 ...
#define JOHTO_SCALING_WILD_ABOVE     4     // ... bis Anker - 4
// Ein Level Aufschlag, nicht zwei. Vier ueber dem staerksten Teammitglied
// ist viel, wenn der Anker ohnehin schon die Spitze des Spielerteams ist -
// gegenueber dem Rest des Teams sind es dann schnell acht. Der Unterschied
// zu einem Routentrainer kommt in Johto ueber Teamgroesse und Deckung,
// nicht ueber rohe Level. Zum Vergleich: Hoenn faehrt +5, ist aber die
// Endregion.
#define JOHTO_SCALING_BOSS_EXTRA     1     // Boss-Ass: Anker + 2 + 1

// Trainer, deren Originalteam bereits auf oder ueber diesem Level liegt,
// sind bewusst gesetzte Superbosse und werden NICHT skaliert. In Johto
// trifft das nur Rot am Silberberg (77-93) - Lance' Champion-Team
// (68-75) und die Top-Vier-Rematches (63-70) skalieren weiterhin mit.
#define JOHTO_SCALING_FIXED_MIN_LEVEL 77

// Entwicklungsangleich wie in Hoenn: Falkners Taubsi tritt auf
// Level 55 als Tauboss an, nicht als Scheingegner.
#define JOHTO_SCALING_TRAINER_EVOLVE TRUE
#define JOHTO_SCALING_EVO_OTHER_LEVEL 36   // Schwelle fuer Stein/Tausch

// Nur als Rueckfallebene - in Johto definiert die Korridortabelle die
// Region, ein Gebiet ohne Eintrag wird gar nicht erst skaliert.
#define JOHTO_SCALING_MIN_LEVEL      5     // absolute Untergrenze
#define JOHTO_SCALING_MAX_LEVEL      100   // absolute Obergrenze

#define JOHTO_SCALING_DEFAULT_FLOOR    45
#define JOHTO_SCALING_DEFAULT_CEILING  80

#define JOHTO_SCALING_CORRIDORS \
    /* Uebergang aus Kanto (45-80). Diese drei Gebiete werden ZWEIMAL \
       durchlaufen: auf dem Hinweg als frischgebackener Kanto-Champion \
       und auf dem Rueckweg zur Johto-Liga. Deshalb bewusst das volle \
       Band - der Anker entscheidet, welcher der beiden Besuche es \
       gerade ist. */ \
    { MAPSEC_ROUTE_26,          45,  80 }, \
    { MAPSEC_ROUTE_27,          45,  80 }, \
    { MAPSEC_TOHJO_FALLS,       45,  80 }, \
    /* Stufe 1: Ankunft bis Bugsy (45-55). Der Deckel ist bewusst knapp:
       wer mit 50 aus Kanto kommt, soll Silber beim ersten Treffen nicht
       auf 60 gegenueberstehen. Das Ass eines Bosses liegt bei Anker + 5. */ \
    { MAPSEC_NEW_BARK_TOWN,     45,  55 }, \
    { MAPSEC_ROUTE_29,          45,  55 }, \
    { MAPSEC_CHERRYGROVE_CITY,  45,  55 }, \
    { MAPSEC_ROUTE_30,          45,  55 }, \
    { MAPSEC_ROUTE_31,          45,  55 }, \
    { MAPSEC_VIOLET_CITY,       45,  55 }, \
    { MAPSEC_SPROUT_TOWER,      45,  55 }, \
    { MAPSEC_RUINS_OF_ALPH,     45,  55 }, \
    { MAPSEC_ROUTE_32,          45,  55 }, \
    { MAPSEC_UNION_CAVE,        45,  55 }, \
    { MAPSEC_ROUTE_33,          45,  55 }, \
    { MAPSEC_AZALEA_TOWN,       45,  55 }, \
    { MAPSEC_SLOWPOKE_WELL,     45,  55 }, \
    { MAPSEC_ILEX_FOREST,       45,  55 }, \
    /* Dunkelhoehle und Route 46 haengen beide auch an der spaeten \
       Seite (Route 45 / Ebenholz). Sie bleiben trotzdem in Stufe 1, \
       weil der frueheste Zugang das Niveau vorgibt. */ \
    { MAPSEC_DARK_CAVE,         45,  55 }, \
    { MAPSEC_ROUTE_46,          45,  55 }, \
    /* Stufe 2: Whitney und Morty (50-61) */ \
    { MAPSEC_ROUTE_34,          50,  61 }, \
    { MAPSEC_GOLDENROD_CITY,    50,  61 }, \
    { MAPSEC_ROUTE_35,          50,  61 }, \
    { MAPSEC_NATIONAL_PARK,     50,  61 }, \
    { MAPSEC_ROUTE_36,          50,  61 }, \
    { MAPSEC_ROUTE_37,          50,  61 }, \
    { MAPSEC_ECRUTEAK_CITY,     50,  61 }, \
    { MAPSEC_BURNED_TOWER,      50,  61 }, \
    { MAPSEC_TIN_TOWER,         50,  61 }, \
    /* Stufe 3: Jasmine und Chuck (55-67) */ \
    { MAPSEC_ROUTE_38,          55,  67 }, \
    { MAPSEC_ROUTE_39,          55,  67 }, \
    { MAPSEC_OLIVINE_CITY,      55,  67 }, \
    { MAPSEC_OLIVINE_LIGHTHOUSE, 55, 71 }, \
    { MAPSEC_SS_AQUA,           55,  67 }, \
    { MAPSEC_ROUTE_40,          55,  67 }, \
    { MAPSEC_ROUTE_41,          55,  67 }, \
    { MAPSEC_WHIRL_ISLANDS,     55,  67 }, \
    { MAPSEC_CIANWOOD_CITY,     55,  67 }, \
    { MAPSEC_ROUTE_47,          55,  67 }, \
    { MAPSEC_ROUTE_48,          55,  67 }, \
    { MAPSEC_CLIFF_CAVE,        55,  67 }, \
    { MAPSEC_SAFARI_ZONE_GATE,  55,  67 }, \
    /* Stufe 4: Pryce und Clair (60-73) */ \
    { MAPSEC_ROUTE_42,          60,  73 }, \
    { MAPSEC_MT_MORTAR,         60,  73 }, \
    { MAPSEC_MAHOGANY_TOWN,     60,  73 }, \
    { MAPSEC_ROUTE_43,          60,  73 }, \
    { MAPSEC_LAKE_OF_RAGE,      60,  73 }, \
    { MAPSEC_ROCKET_HIDEOUT_HNS, 60, 76 }, \
    { MAPSEC_ROUTE_44,          60,  73 }, \
    { MAPSEC_ICE_PATH,          60,  73 }, \
    { MAPSEC_BLACKTHORN_CITY,   60,  73 }, \
    { MAPSEC_DRAGONS_DEN,       60,  73 }, \
    { MAPSEC_ROUTE_45,          60,  73 }, \
    /* Stufe 5: Siegesstrasse und Liga (65-80). Achtung: \
       MAPSEC_INDIGO_PLATEAU traegt Johtos Top-Vier-Raeume \
       (PokemonLeague_*_hns) UND Kantos Aussenbereich; Kantos eigene \
       Liga sitzt dagegen unter MAPSEC_POKEMON_LEAGUE (*_Frlg) und \
       bleibt damit ausserhalb des Scalings. */ \
    { MAPSEC_VICTORY_ROAD_HNS,  65,  80 }, \
    { MAPSEC_INDIGO_PLATEAU,    65,  80 }, \
    /* Silberberg: bewusst ueber dem Johto-Deckel, der Berg ist der \
       haerteste Ort der Region. Rot selbst bleibt unskaliert \
       (JOHTO_SCALING_FIXED_MIN_LEVEL). Route 28 steht mit drin, \
       damit der Zugang passt, sobald er geoeffnet wird. */ \
    { MAPSEC_ROUTE_28,          70,  90 }, \
    { MAPSEC_MT_SILVER,         70,  90 },

#endif // GUARD_CONFIG_JOHTO_SCALING_H
