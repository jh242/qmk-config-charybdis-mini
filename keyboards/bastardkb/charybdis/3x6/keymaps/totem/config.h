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
 * Auto-mouse: ~1 cm of ball travel before POINTER activates.
 *
 * AUTO_MOUSE_THRESHOLD is raw sensor counts (accumulated). At Charybdis
 * default 400 DPI: 400 counts/inch ≈ 157 counts/cm. Round up a bit so a
 * resting palm doesn't trip it; intentional flicks still will.
 */
#ifdef AUTO_MOUSE_DEFAULT_LAYER
#    undef AUTO_MOUSE_DEFAULT_LAYER
#endif
#define AUTO_MOUSE_DEFAULT_LAYER 4
#define AUTO_MOUSE_TIME 650
#define AUTO_MOUSE_DELAY 250
#define AUTO_MOUSE_THRESHOLD 160

#define CHARYBDIS_AUTO_SNIPING_ON_LAYER 4
