// Copyright 2026 Jack Hu (@jh242)
// Port of jh242/zmk-config-totem (Totem) to BastardKB Charybdis Mini 3x6.
//
// Totem layers/alphas kept; thumbs & pinkies reworked for HRM:
//   - Home-row mods own Gui/Alt/Ctrl/Shift → thumbs are NOT mod-taps
//   - Thumbs: NAV · Bspc · Ent | SYM(Esc) · Spc
//   - Left pinkies: Tab / ` / MOUSE
//   - Right pinkies: \ / ' / MOUSE
//   Combos: Z+X → Caps Word
//   Auto-mouse ON (layer 3 = POINTER); either bottom pinky also forces POINTER.
//   Default DPI ~800; sniping is hold-only (no auto-snipe).

#include QMK_KEYBOARD_H
#include "bk_pointing_device.h"
#ifdef COMMUNITY_MODULE_ARGOS_ENABLE
#include "argos.h"
#include "argos_combo.h"
#endif

enum layers {
    LAYER_BASE = 0,
    LAYER_NAV,
    LAYER_SYM,
    LAYER_POINTER,
    LAYER_NUM,
};

/* Home-row mods — Totem: GUI ALT CTL SFT / SFT CTL ALT GUI */
#define HRM_A    LGUI_T(KC_A)
#define HRM_S    LALT_T(KC_S)
#define HRM_D    LCTL_T(KC_D)
#define HRM_F    LSFT_T(KC_F)
#define HRM_J    RSFT_T(KC_J)
#define HRM_K    RCTL_T(KC_K)
#define HRM_L    RALT_T(KC_L)
#define HRM_SCLN RGUI_T(KC_SCLN)

#define NAV MO(LAYER_NAV)
#define SYM LT(LAYER_SYM, KC_ESC)
#define MSE MO(LAYER_POINTER)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
       KC_GRV,  HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,        KC_H,    HRM_J,   HRM_K,   HRM_L,   HRM_SCLN,KC_QUOT,
       MSE,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MSE,
                                  NAV,     KC_BSPC, KC_ENT,      SYM,     KC_SPC
  ),

  [LAYER_NAV] = LAYOUT(
       _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
       _______, _______, _______, _______, _______, _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
       _______, _______, _______,C(KC_BSPC),_______, _______,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_GRV,  _______,
                                  _______, _______, _______,     _______, _______
  ),

  [LAYER_SYM] = LAYOUT(
       _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
       _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_TILD,     KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______,
       _______, KC_LCBR, KC_RCBR, KC_LT,   KC_GT,   KC_QUES,     KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV,
                                  _______, _______, _______,     _______, _______
  ),

  [LAYER_POINTER] = LAYOUT(
       QK_BOOT, EE_CLR,  _______, _______, DPI_MOD, S_D_MOD,     S_D_MOD, DPI_MOD, _______, _______, EE_CLR,  QK_BOOT,
       _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,     _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
       _______, _______, DRGSCRL, SNIPING, _______, _______,     _______, _______, SNIPING, DRGSCRL, _______, _______,
                                  MS_BTN2, MS_BTN1, MS_BTN3,     MS_BTN1, MS_BTN2
  ),

  [LAYER_NUM] = LAYOUT(
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_PAST, KC_7,    KC_8,    KC_9,    KC_PMNS, _______,
       _______, RM_TOGG, RM_NEXT, RM_PREV, RM_HUEU, RM_SATU,     KC_PSLS, KC_4,    KC_5,    KC_6,    KC_PPLS, _______,
       QK_BOOT, EE_CLR,  _______, _______, KC_F11,  KC_F12,      KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  KC_BSPC,
                                  _______, _______, _______,     _______, _______
  ),
};
// clang-format on

const uint16_t PROGMEM combo_zx_caps[] = {KC_Z, KC_X, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_zx_caps, QK_CAPS_WORD_TOGGLE),
};

// Shift HRMs are exempt so a fast "t" → Shift+/ still yields "?" instead of "f/".
// Argos owns get_flow_tap_term(), so the exemption lives here; it also skips
// Flow Tap for the key right after a tapped F/J.
bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false;
    }
    switch (keycode) {
        case HRM_F:
        case HRM_J:
            return false;
    }
    switch (get_tap_keycode(keycode)) {
        case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, LAYER_NAV, LAYER_SYM, LAYER_NUM);
}

void pointing_device_init_user(void) {
    set_auto_mouse_layer(LAYER_POINTER);
}

/*
 * Drag-scroll vertical: module already applies invert_y flag.
 * If traditional scroll (ball up = scroll up) is wanted:
 * In pointing_device_task_bk_pointing_device:
 *   scroll_buffer_y += (invert_y ? -1 : 1) * mouse_report.y;
 *   v = scroll_buffer_y > 0 ? 1 : -1;
 * When rolling ball UP: mouse_report.y < 0.
 * Without invert: scroll_buffer_y becomes negative → v = -1 (down).
 * So invert_y=true produces scroll_buffer_y > 0 → v = +1 (up/traditional)!
 */
void keyboard_post_init_user(void) {
#ifdef COMMUNITY_MODULE_ARGOS_ENABLE
    argos_combos_copy_from_QMK();
    argos_combos_load_from_eeprom();
#endif
    /* Module post_init disables auto-mouse unless this EEPROM flag is set. */
    bkpd_set_auto_mouse_layer_enabled(true);
    set_auto_mouse_enable(true);
    bkpd_set_auto_precision_on_mouse_layer_enabled(false);

    /* Invert Y so ball up (y<0) becomes positive scroll buffer → v=+1 (wheel up).
     * The setters write EEPROM, so only call them when the value differs. */
    if (!bkpd_mode_get_invert(MODE_DRAGSCROLL, 1)) bkpd_mode_set_invert(MODE_DRAGSCROLL, 1, true);
    if (bkpd_mode_get_invert(MODE_DRAGSCROLL, 0)) bkpd_mode_set_invert(MODE_DRAGSCROLL, 0, false);

    /* Force ~800 DPI on the sensor. */
    if (bkpd_mode_get_dpi(MODE_NORMAL) != 800) bkpd_mode_change_dpi(MODE_NORMAL, 800);
    pointing_device_set_cpi(800);
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    return mouse_report;
}

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
#    define MOUSE_KEY_RELEASE_GRACE_MS 300

static uint16_t last_motion_timer;
static uint16_t last_mouse_key_release_timer;
static int16_t  motion_acc_x, motion_acc_y;

// Only ball motion activates/refreshes; once on, any motion counts as keep-alive.
bool auto_mouse_activation(report_mouse_t report) {
    bool moved = report.x || report.y || report.h || report.v;
    if (moved && layer_state_is(LAYER_POINTER)) {
        last_motion_timer = timer_read();
        return true;
    }
    if (timer_elapsed(last_motion_timer) > AUTO_MOUSE_TIME) {
        motion_acc_x = motion_acc_y = 0;
    }
    if (moved) {
        last_motion_timer = timer_read();
        motion_acc_x += report.x + report.h;
        motion_acc_y += report.y + report.v;
    }
    if (abs(motion_acc_x) > AUTO_MOUSE_THRESHOLD || abs(motion_acc_y) > AUTO_MOUSE_THRESHOLD) {
        motion_acc_x = motion_acc_y = 0;
        return true;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed && layer_state_is(LAYER_POINTER) && IS_MOUSEKEY(keycode)) {
        last_mouse_key_release_timer = timer_read();
    }
    return true;
}

// QMK restarts the timeout on every mouse-key release; cap that to a short grace.
void housekeeping_task_user(void) {
    if (!layer_state_is(LAYER_POINTER) || !get_auto_mouse_enable() || get_auto_mouse_toggle() || get_auto_mouse_key_tracker() > 0) {
        return;
    }
    if (timer_elapsed(last_motion_timer) > AUTO_MOUSE_TIME && timer_elapsed(last_mouse_key_release_timer) > MOUSE_KEY_RELEASE_GRACE_MS) {
        auto_mouse_layer_off();
    }
}
#endif
