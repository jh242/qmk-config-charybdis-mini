// Copyright 2026 Jack Hu (@jh242)
#pragma once

/* Totem-style hold-taps (urob-ish): longer HRM term, chordal + flow tap. */
#define TAPPING_TERM 280
#define QUICK_TAP_TERM 175
#define FLOW_TAP_TERM 150
#define CHORDAL_HOLD
#define PERMISSIVE_HOLD

#ifdef VIA_ENABLE
#    undef DYNAMIC_KEYMAP_LAYER_COUNT
#    define DYNAMIC_KEYMAP_LAYER_COUNT 5
#endif

/* Required by bastardkb/bk_pointing_device DPI LED indicator. */
#ifdef LED_DPI_INDICATOR_INDEX
#    undef LED_DPI_INDICATOR_INDEX
#endif
#define LED_DPI_INDICATOR_INDEX 0
#ifdef RGBLIGHT_LED_COUNT
#    undef RGBLIGHT_LED_COUNT
#endif
#define RGBLIGHT_LED_COUNT 41

/*
 * Cursor speed: ~800 DPI (set in keymap.c). Sniping stays hold-only.
 */

/*
 * Auto-mouse: ~1 cm of ball travel before POINTER activates.
 * Accumulated report motion (QMK default is 10).
 */
#ifdef AUTO_MOUSE_DEFAULT_LAYER
#    undef AUTO_MOUSE_DEFAULT_LAYER
#endif
#define AUTO_MOUSE_DEFAULT_LAYER 4
#define AUTO_MOUSE_TIME 650
#define AUTO_MOUSE_DELAY 250
#define AUTO_MOUSE_THRESHOLD 40
