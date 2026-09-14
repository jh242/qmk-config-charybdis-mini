# qmk-config-charybdis-mini

QMK userspace for a **BastardKB Charybdis Mini (3×6)** — keymap ported from
[`jh242/zmk-config-totem`](https://github.com/jh242/zmk-config-totem), plus a
Voyager-style **auto mouse layer** on trackball motion.

## Layout (from Totem)

| Layer | How | Notes |
|-------|-----|-------|
| **BASE** | default | Home-row mods: `A` Gui · `S` Alt · `D` Ctrl · `F` Shift / `J` Shift · `K` Ctrl · `L` Alt · `;` Gui |
| **NAV** | hold left-thumb Ctrl | Numbers on left, vim arrows + Home/End/Pg on right |
| **SYM** | hold right-thumb Esc | Symbols / brackets |
| **NUM** | NAV + SYM together | F-keys + numpad (BT keys → RGB / boot / EEPROM clear) |
| **POINTER** | move trackball | Mouse buttons, DPI, sniping, drag-scroll; auto-exits after idle |

**Thumbs** (Totem had 6; Mini has 5 — ball eats one):

`Alt` · `Ctrl(NAV)` · `Enter` | `Space` · `Esc(SYM)`

Gui sits on the **right outer home** key.

**Combos:** `J`+`K` → Esc · `Z`+`X` → Caps Word

**Bottom outers:** `Shift(Tab)` · `Backspace` (same as Totem)

## Build (GitHub Actions)

1. Enable Actions on this repo.
2. Push to `main` (or run **Build QMK firmware** manually).
3. Grab the `.uf2` from the run artifacts / Releases.

Target: `bastardkb/charybdis/3x6/splinktegrated_rev1` · keymap `totem`

## Build (local)

```bash
# QMK home = BastardKB fork
git clone https://github.com/Bastardkb/bastardkb-qmk
cd bastardkb-qmk && git checkout main && qmk git-submodule
qmk config user.qmk_home="$(pwd)"

# This repo as userspace
cd /path/to/qmk-config-charybdis-mini
git submodule update --init --recursive
qmk config user.overlay_dir="$(pwd)"

qmk compile -c -kb bastardkb/charybdis/3x6/splinktegrated_rev1 -km totem
```

Flash the UF2 (double-reset Splinky → `RPI-RP2` drive), or `qmk flash` with the same `-kb`/`-km`.

Left-ball boards: swap the keyboard arg to `bastardkb/charybdis/3x6_left/splinktegrated_rev1` in `qmk.json` and rebuild.

## Tuning

| Define | File | Default | Meaning |
|--------|------|---------|---------|
| `TAPPING_TERM` | `config.h` | 280 | Home-row mod hold time |
| `FLOW_TAP_TERM` | `config.h` | 150 | Prefer tap while already typing |
| `AUTO_MOUSE_TIME` | `config.h` | 650 | Pointer layer linger after ball stops |
| `AUTO_MOUSE_THRESHOLD` | `config.h` | 10 | Ball motion needed to trigger |

Sniping auto-enables on POINTER (`CHARYBDIS_AUTO_SNIPING_ON_LAYER`).
