# qmk-config-charybdis-mini

QMK userspace for a **BastardKB Charybdis Mini (3×6)** — layers from
[`jh242/zmk-config-totem`](https://github.com/jh242/zmk-config-totem), thumbs/pinkies
rewritten for home-row mods.

## Layout

| Layer | How | Notes |
|-------|-----|-------|
| **BASE** | default | Home-row mods: `A` Gui · `S` Alt · `D` Ctrl · `F` Shift / `J` Shift · `K` Ctrl · `L` Alt · `;` Gui |
| **NAV** | hold left-outer thumb | Numbers left, vim arrows + Home/End/Pg right |
| **SYM** | hold right-inner thumb | Symbols / brackets |
| **NUM** | NAV + SYM together | F-keys + numpad |
| **POINTER** | hold bottom-left pinky, or ~1 cm ball move | Mouse buttons, DPI, optional sniping, drag-scroll |

**Thumbs** (no mod-taps):

`NAV` · `Bspc` · `Enter` | `SYM` · `Space`

**Pinky outers:** `Tab` `` ` `` `MOUSE` / `'` `\` `-`

**Combos:** `J`+`K` → Esc · `Z`+`X` → Caps Word

**Trackball:** default ~1000 DPI (MX Ergo–ish). Auto-mouse on with `AUTO_MOUSE_THRESHOLD 400` (~1 cm). Sniping is hold-to-enable only (no auto-snipe). Bottom-left pinky still forces POINTER.

## Build

```bash
qmk compile -c -kb bastardkb/charybdis/3x6/splinktegrated_rev1 -km totem
```
