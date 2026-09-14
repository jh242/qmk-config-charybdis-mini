# qmk-config-charybdis-mini

QMK userspace for a **BastardKB Charybdis Mini (3×6)** — layers from
[`jh242/zmk-config-totem`](https://github.com/jh242/zmk-config-totem), thumbs/pinkies
rewritten for home-row mods, plus Voyager-style **auto mouse** on the trackball.

## Layout

| Layer | How | Notes |
|-------|-----|-------|
| **BASE** | default | Home-row mods: `A` Gui · `S` Alt · `D` Ctrl · `F` Shift / `J` Shift · `K` Ctrl · `L` Alt · `;` Gui |
| **NAV** | hold left-outer thumb | Numbers left, vim arrows + Home/End/Pg right |
| **SYM** | hold right-inner thumb | Symbols / brackets |
| **NUM** | NAV + SYM together | F-keys + numpad (BT → RGB / boot / EEPROM clear) |
| **POINTER** | move trackball | Mouse buttons, DPI, sniping, drag-scroll |

**Thumbs** (no mod-taps — HRM already owns the mods):

`NAV` · `Bspc` · `Enter` | `SYM` · `Space`

**Pinky outers:** `Esc` `` ` `` `Tab` / `'` `\` `-`

**Combos:** `J`+`K` → Esc · `Z`+`X` → Caps Word

## Build

```bash
qmk compile -c -kb bastardkb/charybdis/3x6/splinktegrated_rev1 -km totem
```

Or enable Actions on this repo and grab the UF2 from the run.
