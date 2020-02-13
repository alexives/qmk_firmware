#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _MAC 1
#define _FN1 2

enum unicode_names {
    ROCKET,
    TREX,
    DINO,
    UFO,
    FIRE,
};

const uint32_t PROGMEM unicode_map[] = {
    [ROCKET] = 0x1F680, // 🚀
    [TREX]   = 0x1F996, // 🦖
    [DINO]   = 0x1F995, // 🦕
    [UFO]    = 0x1F6F8, // 🛸
    [FIRE]   = 0x1F525, // 🔥
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65(
    KC_GESC, KC_1,     KC_2,    KC_3,    KC_4,      KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS, KC_DEL, \
    KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,      KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_HOME, \
    KC_CAPS, KC_A,     KC_S,    KC_D,    KC_F,      KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME, \
    KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_V,      KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,  \
    KC_LCTL, KC_LGUI,  KC_LALT, KC_SPC, MO(_FN1),            KC_SPC,  KC_SPC,  KC_RALT, KC_LCTL, _______, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_MAC] = LAYOUT_65(
    KC_GESC, KC_1,     KC_2,    KC_3,    KC_4,      KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS, KC_DEL, \
    KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,      KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_HOME, \
    KC_CAPS, KC_A,     KC_S,    KC_D,    KC_F,      KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME, \
    KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_V,      KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,  \
    KC_LCTL, KC_LALT,  KC_LGUI, KC_SPC, MO(_FN1),            KC_SPC,  KC_SPC,  KC_LGUI, KC_RALT, _______, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN1] = LAYOUT_65(
    KC_GRV,  KC_F1,    KC_F2,     KC_F3,   KC_F4,     KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, UC_M_OS, \
    RGB_TOG, RGB_MOD,  KC_UP,     X(DINO), X(ROCKET), X(TREX), _______, X(UFO),  _______, _______, _______, _______, _______, _______, UC_M_WC, \
    _______, KC_LEFT,  KC_DOWN,   KC_RGHT, X(FIRE),   _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______,  _______,   _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_TILD, DF(_MAC), DF(_BASE), _______, _______,            _______, _______, _______, _______, _______, _______, _______, _______
  )
};
