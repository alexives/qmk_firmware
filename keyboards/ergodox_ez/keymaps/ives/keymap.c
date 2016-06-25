#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define QWERTY  0 // Qwerty
#define COLEMAK 1 // Qwerty
#define DVORAK  2 // Qwerty
#define RAISE   3 // Raise
#define LOWER   4 // Lower
#define NAV     5 // Mouse/Nav Keys
#define WIN     6 // Windows Mode

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |  `   |           |   =  |   6  |   7  |   8  |   9  |   0  |  Bkspc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |    \   |
 * |--------+------+------+------+------+------|  [   |           |   ]  |------+------+------+------+------+--------|
 * | Ctl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |    '   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |  (   |           |   )  |   N  |   M  |   ,  |   .  |   /  |  Enter |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Sleep | Hyper| Ctrl |  Alt |  Nav |                                       |  Del | Left | Down |  Up  | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Vol- | Vol+ |       | play | next |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Mute |       | al/t |      |      |
 *                                 |  Gui | Raise|------|       |------| Lower| Space|
 *                                 |      |      | Alt  |       | al/~ |      |      |
 *                                 `--------------------'       `--------------------'
 */
[QWERTY] = KEYMAP(
    // left hand
    KC_ESC,        KC_1,    KC_2,    KC_3,    KC_4,          KC_5,      KC_GRV,
    KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,          KC_T,      KC_LCBR,
    CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,          KC_G,
    KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,          KC_B,      KC_LPRN,
    KC_SLEP,       KC_HYPR, KC_LCTL, KC_LALT, LT(NAV,KC_ENT),
                                                             KC_VOLD,   KC_VOLU,
                                                                        KC_MUTE,
                                                LGUI(KC_NO), MO(RAISE), KC_LALT,
    // right hand
    KC_EQL,  KC_6, KC_7,      KC_8,    KC_9,   KC_0,    KC_BSPC,
    KC_RCBR, KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLS,
             KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LPRN, KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
                     KC_DELT, KC_LEFT, KC_DOWN,KC_UP,   KC_RGHT,
    KC_MPLY,         KC_MNXT,
    LGUI(KC_GRV),
    LGUI(KC_TAB),    MO(LOWER), KC_SPC
),

/* COLEMAK
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |  `   |           |   =  |   6  |   7  |   8  |   9  |   0  |  Bkspc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   F  |   P  |   G  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |    \   |
 * |--------+------+------+------+------+------|  [   |           |   ]  |------+------+------+------+------+--------|
 * | Ctl/Esc|   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |    '   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |  (   |           |   )  |   N  |   M  |   ,  |   .  |   /  |  Enter |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Sleep | Hyper| Ctrl |  Alt |  Nav |                                       |  Del | Left | Down |  Up  | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Vol- | Vol+ |       | play | next |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Mute |       | al/t |      |      |
 *                                 |  Gui | Raise|------|       |------| Lower| Space|
 *                                 |      |      | Alt  |       | al/~ |      |      |
 *                                 `--------------------'       `--------------------'
 */
[COLEMAK] = KEYMAP(
    // left hand
    KC_ESC,        KC_1,    KC_2,    KC_3,    KC_4,          KC_5,      KC_GRV,
    KC_TAB,        KC_Q,    KC_W,    KC_F,    KC_P,          KC_G,      KC_LBRC,
    CTL_T(KC_ESC), KC_A,    KC_R,    KC_S,    KC_T,          KC_D,
    KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,          KC_B,      KC_LPRN,
    KC_SLEP,       KC_HYPR, KC_LCTL, KC_LALT, LT(NAV,KC_ENT),
                                                             KC_VOLD,   KC_VOLU,
                                                                        KC_MUTE,
                                                LGUI(KC_NO), MO(RAISE), KC_LALT,
    // right hand
    KC_EQL,  KC_6,   KC_7,      KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_RBRC, KC_J,   KC_L,      KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
             KC_H,   KC_N,      KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LPRN, KC_N,   KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                     KC_DELT,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_MPLY,         KC_MNXT,
    LGUI(KC_GRV),
    LGUI(KC_TAB),    MO(LOWER), KC_SPC
),

/* DVORAK
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |  `   |           |   =  |   6  |   7  |   8  |   9  |   0  |  Bkspc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   "  |   ,  |   .  |   P  |   Y  |      |           |      |   F  |   G  |   C  |   R  |   L  |    \   |
 * |--------+------+------+------+------+------|  [   |           |   ]  |------+------+------+------+------+--------|
 * | Ctl/Esc|   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |    /   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   ;  |   Q  |   J  |   K  |   X  |  (   |           |   )  |   B  |   M  |   W  |   V  |   Z  |  Enter |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Sleep | Hyper| Ctrl |  Alt |  Nav |                                       |  Del | Left | Down |  Up  | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Vol- | Vol+ |       | play | next |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Mute |       | al/t |      |      |
 *                                 |  Gui | Raise|------|       |------| Lower| Space|
 *                                 |      |      | Alt  |       | al/~ |      |      |
 *                                 `--------------------'       `--------------------'
 */
[DVORAK] = KEYMAP(
    // left hand
    KC_ESC,        KC_1,    KC_2,    KC_3,    KC_4,           KC_5,      KC_GRV,
    KC_TAB,        KC_A,    KC_O,    KC_E,    KC_U,           KC_I,      KC_LCBR,
    CTL_T(KC_ESC), KC_A,    KC_O,    KC_E,    KC_U,           KC_I,
    KC_LSFT,       KC_SCLN, KC_Q,    KC_J,    KC_K,           KC_X,      KC_LPRN,
    KC_SLEP,       KC_HYPR, KC_LCTL, KC_LALT, LT(NAV,KC_ENT),
                                                              KC_VOLD,   KC_VOLU,
                                                                         KC_MUTE,
                                                 LGUI(KC_NO), MO(RAISE), KC_LALT,
    // right hand
    KC_EQL,  KC_6, KC_7,      KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_RCBR, KC_F, KC_G,      KC_C,    KC_R,    KC_L,    KC_BSLS,
             KC_D, KC_H,      KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LPRN, KC_B, KC_M,      KC_W,    KC_V,    KC_Z,    KC_ENT, 
                   KC_DELT,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_MPLY,       KC_MNXT,
    LGUI(KC_GRV),
    LGUI(KC_TAB),  MO(LOWER), KC_SPC
),

/* Raise
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  Del   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   @  |   {  |   }  |      | Gui+{|           |Gui+} |      |   \  |   !  |   ~  |      |  Del   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |   `    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      | PgDn | PgUp |  Ins |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Brt- | Brt+ |       |      | Prev |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      | XXXX |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[RAISE] = KEYMAP(
    // left hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_AT,   KC_LCBR, KC_RCBR, KC_TRNS, LGUI(KC_LCBR),
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_PSCR, KC_SLCK,
                                                          KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DELT,
    LGUI(KC_RCBR), KC_TRNS, KC_BSLS, KC_EXLM, KC_TILD, KC_TRNS, KC_TRNS,
                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TRNS,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
                            KC_TRNS, KC_PGDN, KC_PGUP, KC_INS,  KC_TRNS,
    KC_TRNS,       KC_MPRV,
    KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS
),

/* Lower
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | lock |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   $  |   [  |   ]  |      |      |           |      |      |   |  |   &  |   `  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   -  |   =  |   #  |   +  |   %  |------|           |------|   ^  |   _  |   *  |   (  |   )  |    ~   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F11 |  F12 |  F13 |  F14 |  F15 |      |           |      |  F16 |  F17 |  F18 |  F19 |  F20 |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      | PgUp | PgDn |  Ins |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Brt- | Brt+ |       |      | Prev |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| XXXX |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LOWER] = KEYMAP(
    // left hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_DLR,  KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_MINS, KC_EQL,  KC_HASH, KC_PLUS, KC_PERC,
    KC_TRNS, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_PSCR, KC_SLCK,
                                                          KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_PIPE, KC_AMPR, KC_GRV,  KC_TRNS, KC_TRNS,
             KC_CIRC, KC_UNDS, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
    KC_TRNS, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_PGDN, KC_PGUP, KC_INS,
    KC_TRNS, KC_MPRV,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),

/* Nav / Mode
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | VERSIN |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      | M Up |      |      |      |      |           |      |      | L Clk| R Clk|      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | M Le | M Dn | M Rt |      |      |------|           |------|      | Left | Down |  Up  | Right|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  Win |Qwerty|Dvorak|Colmak|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | XXXX |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|  Gui | Alt  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NAV] = KEYMAP(
    // left hand
    M(0),    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_MS_U, KC_NO,   KC_WH_D, KC_NO,   KC_TRNS,
    KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_TRNS,
                                                          KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,      KC_TRNS,
    KC_TRNS, KC_NO,   KC_BTN1, KC_BTN2, KC_NO,      KC_NO,      KC_TRNS,
             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,    KC_NO,       KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,      KC_TRNS,
                      KC_TRNS, TG(WIN), DF(QWERTY), DF(DVORAK), DF(COLEMAK), 
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_LALT, LGUI(KC_NO)
),

/* Windows
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |  GUI |  Alt |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[WIN] = KEYMAP(
    // left hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_LGUI, KC_LALT, KC_TRNS,
                                                 KC_TRNS, KC_TRNS,
                                                          KC_TRNS,
                                        KC_LGUI, KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(RAISE),  // FN1 - Momentary Layer 1 (Raise)
    [2] = ACTION_LAYER_TAP_TOGGLE(LOWER),  // FN1 - Momentary Layer 2 (Lower)
    [3] = ACTION_LAYER_TAP_TOGGLE(NAV),    // FN1 - Momentary Layer 3 (Nav/Mouse)
    [4] = ACTION_LAYER_TAP_TOGGLE(WIN)     // FN1 - Momentary Layer 4 (Windows)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break; 
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
