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

/* Voyager-style auto mouse → POINTER (layer 4). */
#ifdef AUTO_MOUSE_DEFAULT_LAYER
#    undef AUTO_MOUSE_DEFAULT_LAYER
#endif
#define AUTO_MOUSE_DEFAULT_LAYER 4
#define AUTO_MOUSE_TIME 650
#define AUTO_MOUSE_DELAY 250
#define AUTO_MOUSE_THRESHOLD 10

#define CHARYBDIS_AUTO_SNIPING_ON_LAYER 4
