// Copyright 2026 Jack Hu (@jh242)
// Port of jh242/zmk-config-totem (Totem) to BastardKB Charybdis Mini 3x6.
//
// Totem (ZMK) → QMK:
//   BASE / NAV / SYM / NUM tri-layer, home-row mods, thumb LT(NAV/SYM)
//   Combos: J+K → Esc, Z+X → Caps Word
// Extra on Mini:
//   Outer columns (Totem is 5-wide + Tab/Bspc), 5 thumbs (ball eats one)
//   POINTER layer via QMK auto-mouse (Voyager-style trackball trigger)

#include QMK_KEYBOARD_H

enum layers {
    LAYER_BASE = 0,
    LAYER_NAV,
    LAYER_SYM,
    LAYER_NUM,
    LAYER_POINTER,
};

/* Home-row mods — same as Totem: GUI ALT CTL SFT / SFT CTL ALT GUI */
#define HRM_A LGUI_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LCTL_T(KC_D)
#define HRM_F LSFT_T(KC_F)
#define HRM_J RSFT_T(KC_J)
#define HRM_K RCTL_T(KC_K)
#define HRM_L RALT_T(KC_L)
#define HRM_SCLN RGUI_T(KC_SCLN)

#define NAV_CTL LT(LAYER_NAV, KC_LCTL)
#define SYM_ESC LT(LAYER_SYM, KC_ESC)
#define TAB_SFT LSFT_T(KC_TAB)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // Outer cols are Mini extras vs Totem 5-col. Gui on right outer home
  // (Totem Gui was 6th thumb; Mini has 5 — trackball takes the 6th).
       KC_ESC,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL,
       KC_GRV,     HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,       KC_H,    HRM_J,   HRM_K,   HRM_L, HRM_SCLN, KC_LGUI,
       TAB_SFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSPC,
  // Totem thumbs: Alt · Ctrl(NAV) · Ent | Spc · Esc(SYM) · Gui
                                  KC_LALT, NAV_CTL,  KC_ENT,     KC_SPC, SYM_ESC
  ),

  [LAYER_NAV] = LAYOUT(
  // Numbers left, vim arrows / home-end-pg right (Totem NAV)
       _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
       _______,  _______, _______, _______, _______, _______,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_QUOT, _______,
       _______,  _______, _______,C(KC_BSPC),_______, _______,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_GRV, _______/*,
                                  _______, _______, _______,    _______, _______ */
                                  _______, _______, _______,    _______, _______
  ),

  [LAYER_SYM] = LAYOUT(
  // Brackets / operators (Totem SYM)
       _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
       _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_TILD,    KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE, _______,
       _______, KC_LCBR, KC_RCBR, KC_LT,   KC_GT,   _______,    KC_UNDS, KC_PLUS, _______, _______, KC_BSLS,  KC_GRV,
                                  _______, _______, _______,    _______, _______
  ),

  [LAYER_NUM] = LAYOUT(
  // NAV+SYM tri-layer: F-keys + numpad. BT → boot/EEPROM/RGB (wired QMK).
       _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_PAST,    KC_7,    KC_8,    KC_9, KC_PMNS, _______,
       _______, RM_TOGG, RM_NEXT, RM_PREV, RM_HUEU, RM_SATU,    KC_PSLS,    KC_4,    KC_5,    KC_6, KC_PPLS, _______,
       QK_BOOT,  EE_CLR, _______, _______,  KC_F11,  KC_F12,       KC_0,    KC_1,    KC_2,    KC_3,  KC_DOT, KC_BSPC,
                                  _______, _______, _______,    _______, _______
  ),

  [LAYER_POINTER] = LAYOUT(
  // Auto-mouse target (Voyager-like). Buttons on thumbs; DPI / snip / drag.
       QK_BOOT,  EE_CLR, _______, _______, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, _______, _______,  EE_CLR, QK_BOOT,
       _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,    _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
       _______, _______, DRGSCRL, SNIPING, _______, _______,    _______, _______, SNIPING, DRGSCRL, _______, _______,
                                  MS_BTN2, MS_BTN1, MS_BTN3,    MS_BTN1, MS_BTN2
  ),
};
// clang-format on

/* Combos — Totem: J+K Esc, Z+X caps-word */
const uint16_t PROGMEM combo_jk_esc[] = {HRM_J, HRM_K, COMBO_END};
const uint16_t PROGMEM combo_zx_caps[] = {KC_Z, KC_X, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_jk_esc, KC_ESC),
    COMBO(combo_zx_caps, QK_CAPS_WORD_TOGGLE),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, LAYER_NAV, LAYER_SYM, LAYER_NUM);
}

void pointing_device_init_user(void) {
    set_auto_mouse_layer(LAYER_POINTER);
    set_auto_mouse_enable(true);
}
