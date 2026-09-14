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

/*
 * Cursor speed: MX Ergo–ish default (~1000 DPI). Sniping stays manual
 * (hold SNIPING on POINTER); no auto-snipe on the pointer layer.
 */
#define CHARYBDIS_MINIMUM_DEFAULT_DPI 1000

/*
 * Auto-mouse: ~1 cm of ball travel before POINTER activates.
 *
 * AUTO_MOUSE_THRESHOLD is accumulated report motion. At 1000 DPI:
 * 1000 counts/inch ≈ 394 counts/cm → 400 ≈ 1 cm.
 */
#ifdef AUTO_MOUSE_DEFAULT_LAYER
#    undef AUTO_MOUSE_DEFAULT_LAYER
#endif
#define AUTO_MOUSE_DEFAULT_LAYER 4
#define AUTO_MOUSE_TIME 650
#define AUTO_MOUSE_DELAY 250
#define AUTO_MOUSE_THRESHOLD 400
