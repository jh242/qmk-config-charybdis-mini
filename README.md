# qmk-config-charybdis-mini

QMK userspace for a **BastardKB Charybdis Mini (3×6)** — layers from
[`jh242/zmk-config-totem`](https://github.com/jh242/zmk-config-totem), thumbs/pinkies
rewritten for home-row mods.

## Layout

| Layer | How | Notes |
|-------|-----|-------|
| **BASE** | default | Home-row mods: `A` Gui · `S` Alt · `D` Ctrl · `F` Shift / `J` Shift · `K` Ctrl · `L` Alt · `;` Gui |
| **NAV** | hold left-outer thumb | Numbers left, vim arrows + Home/End/Pg right |
| **SYM** | hold right-inner thumb (tap: Esc) | Symbols / brackets, `?` on `B` |
| **NUM** | NAV + SYM together | F-keys + numpad |
| **POINTER** | hold bottom-right pinky, or move the ball | Mouse buttons, DPI, sniping, plain mods on the home row |

**Thumbs**:

`NAV` · `Bspc` · `Enter` | `SYM(Esc)` · `Space`

**Pinky outers:** `Tab` `` ` `` `SCROLL` / `\` `'` `MOUSE`

**Combos:** `Z`+`X` → Caps Word

**Trackball:** default 800 DPI. Auto-mouse on with `AUTO_MOUSE_THRESHOLD 40`; only ball motion activates or keeps POINTER alive (mouse-key releases get a 300 ms grace for double-clicks). Sniping is hold-to-enable only (no auto-snipe). Bottom-right pinky still forces POINTER.

**Scroll:** hold bottom-left pinky (`SCROLL`, any layer) and roll the ball. One axis at a time, ball up = scroll up, `SCROLL_DIVISOR 32` counts per wheel tick (~1 mm at 800 DPI). Scrolling never wakes POINTER.

**Paste after mouse use:** for 1 s after ball motion or a mouse-button release (or while POINTER is on), `K`(Ctrl) + `Z`/`X`/`C`/`V` resolves as Ctrl as soon as the second key goes down; any other key taps `k` immediately.

**Home-row Shift:** `F`/`J` are exempt from Flow Tap so fast `Shift`+`/` gives `?`.

## Build

Uses the BastardKB [`qmk_modules`](https://github.com/Bastardkb/qmk_modules) submodule (`bk_pointing_device`, `argos`) against [`bastardkb/bastardkb-qmk`](https://github.com/bastardkb/bastardkb-qmk) `main`.

```bash
git submodule update --init
qmk compile -c -kb bastardkb/charybdis/3x6/splinktegrated_rev1 -km totem
```
