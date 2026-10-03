# Ash Palette Notes

## Why Running Was Miscolored

The HnS player uses one overworld palette for both walking and running. The source images can look correct individually because each indexed PNG carries its own palette, but the game uses the palette registered for the player object. The running PNG therefore needs the same palette **and the same index order** as `walking_ash.png`.

The inspected files contained the same RGB colors, but their palette entries were ordered differently. Running used these different index assignments:

| Running index | Matching walking index | Color role |
| ---: | ---: | --- |
| 2 | 3 | red cap shade |
| 3 | 2 | red cap shade |
| 8 | 9 | brown |
| 9 | 8 | light gray |
| 12 | 13 | dark color |
| 13 | 12 | dark color |

Walking and running are concatenated into one object-event graphics array in `src/data/object_events/object_event_graphics.h`, and share the normal Ash graphics descriptor and palette in `src/data/object_events/object_event_graphics_info.h`.

## Remap Running Indices

This Pillow script remaps running's pixel indexes to the walking palette while preserving the rendered RGBA pixels. It writes a temporary candidate; review it before replacing the source.

```python
from pathlib import Path
from PIL import Image

walking_path = Path("graphics/object_events/pics/people/ash/walking_ash.png")
running_path = Path("graphics/object_events/pics/people/ash/running_ash.png")
output_path = Path("/tmp/running_ash_indexfixed.png")

walking = Image.open(walking_path)
running = Image.open(running_path)
if walking.mode != "P" or running.mode != "P":
    raise ValueError("Both images must be indexed PNGs")

walking_palette = walking.getpalette()
running_palette = running.getpalette()
if walking_palette is None or running_palette is None:
    raise ValueError("Missing PNG palette")

walking_colors = [tuple(walking_palette[i:i + 3]) for i in range(0, 48, 3)]
running_colors = [tuple(running_palette[i:i + 3]) for i in range(0, 48, 3)]
if len(set(walking_colors)) != len(walking_colors):
    raise ValueError("Walking palette has duplicate colors; mapping is ambiguous")

index_map = [walking_colors.index(color) for color in running_colors]
remapped = running.point(index_map + list(range(16, 256)))
remapped.putpalette(walking_palette)

if remapped.convert("RGBA").tobytes() != running.convert("RGBA").tobytes():
    raise ValueError("Remap changes the rendered image; source was not written")

remapped.save(output_path)
print("Palette index changes:", {i: j for i, j in enumerate(index_map) if i != j})
print("Wrote", output_path)
```

The remap should report `2 -> 3`, `3 -> 2`, `8 -> 9`, `9 -> 8`, `12 -> 13`, and `13 -> 12` for the palette inspected on 2026-10-03. If the source PNG changes, rerun the script and inspect the mapping rather than assuming these indexes remain the same.

## Convert To GBA Graphics

After reviewing the temporary image, install it as the running source and convert that one sheet directly:

```sh
cp /tmp/running_ash_indexfixed.png graphics/object_events/pics/people/ash/running_ash.png
tools/gbagfx/gbagfx graphics/object_events/pics/people/ash/running_ash.png graphics/object_events/pics/people/ash/running_ash.4bpp -mwidth 2 -mheight 4
```

Confirm the indexed palette order matches walking:

```python
from PIL import Image

walking = Image.open("graphics/object_events/pics/people/ash/walking_ash.png")
running = Image.open("graphics/object_events/pics/people/ash/running_ash.png")
assert walking.mode == running.mode == "P"
assert walking.getpalette() == running.getpalette()
```

No ROM build was run as part of this palette repair. The ROM must be rebuilt before testing the updated `.4bpp` in-game.
