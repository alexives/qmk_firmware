#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define CODE 1 // symbols
#define NUMP 2 // media keys
#define MDIA 3 // media keys
#define WINL 4 // windows mode

/* About this file: This is just an experimental keymap for my own use, with some ideas I'm testing out.
*  Changlog:
*  Jan 19: * Made J into dual-action key (Alt when held down), to make Alt-tab more ergonomic.
*          * Made ' into dual-action key (Win/Cmd when held down).
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Ctrl/ESC|   1  |   2  |   3  |   4  |   5  |   6  |           |  =/+ |   7  |   8  |   9  |   0  |  -/_ | Backs  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   {  |           |  }   |   Y  |   U  |   I  |   O  |   P  |   \ |  |
 * |--------+------+------+------+------+------|   [  |           |  ]   |------+------+------+------+------+--------|
 * |Ctrl/ESC|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ; ; |   ' "  |
 * |--------+------+------+------+------+------|   (  |           |  )   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  / ? | Return |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Sleep |  `~  | Win  |Alt/Re|Return|                                       | PgUp | PgDn | ins  |  del | Num  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      | Brt+ | Brt- |           | Vol+ | Vol- |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      | Meh  |           | Alt~ |      |      |
 *                               | Gui  |Code  |------|           |------|Mouse |Space |
 *                               |      |      |Hyper |           | AltT |      |      |
 *                               `--------------------'           `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        CTL_T(KC_ESC),    KC_1,     KC_2,     KC_3,            KC_4,    KC_5,   KC_6,
        KC_TAB,          KC_Q,     KC_W,     KC_E,            KC_R,    KC_T,   KC_LBRACKET,
        CTL_T(KC_ESC),    KC_A,     KC_S,     KC_D,            KC_F,    KC_G,
        KC_LSFT,         KC_Z,     KC_X,     KC_C,            KC_V,    KC_B,   KC_LPRN,
        KC_SYSTEM_SLEEP, KC_GRAVE, TG(WINL), ALT_T(KC_ENT), KC_ENT,
                                                 KC_PSCREEN,  KC_SCROLLLOCK,
                                                              KC_HYPR,
                                                 LGUI(KC_NO), KC_FN1,  KC_MEH,
        // right hand
        KC_EQUAL,    KC_7, KC_8,    KC_9,      KC_0,      KC_MINS,   KC_BSPACE,
        KC_RBRACKET, KC_Y, KC_U,    KC_I,      KC_O,      KC_P,      KC_BSLS,
                     KC_H, KC_J,    KC_K,      KC_L,      KC_SCLN,   KC_QUOT,
        KC_RPRN,     KC_N, KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
                           KC_PGUP, KC_PGDOWN, KC_INSERT, KC_DELETE, TG(NUMP),
        KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN,
        LGUI(KC_GRAVE),
        LGUI(KC_TAB),  LT(MDIA,KC_FN5), KC_SPACE
    ),
/* Keymap 1: Code Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | TEENSY |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F12 |  F7  |  F8  |  F9  |  F10 |  F11 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   ~  |   `  |   {  |   }  |      |      |           |      |      |   +  |   =  |   [  |   ]  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   -  |   _  |   \  |   |  |      |------|           |------| Left | Down |  Up  |Right |   ~  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |Cmd+C | Shift|  Alt |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[CODE] = KEYMAP(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,          KC_F3,   KC_F4,     KC_F5,   KC_TRNS,
       KC_TRNS, KC_TILD, KC_GRAVE,       KC_LCBR, KC_RCBR,   KC_PIPE, KC_TRNS,
       KC_TRNS, KC_MINS, LSFT(KC_MINUS), KC_BSLS, KC_PIPE,   KC_GRV,
       KC_TRNS, KC_TRNS, KC_TRNS,        LGUI(KC_C), KC_LSHIFT, KC_LALT, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,
                                                             KC_TRNS, KC_TRNS,
                                                                      KC_TRNS,
                                                  KC_TRNS,   KC_TRNS, KC_TRNS,
       // right hand
       KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_AMPR, KC_PLUS, KC_EQL,  KC_LBRC, KC_RBRC, KC_TRNS,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PLUS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: NumPad Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   Up |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   0  |   .  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Number Pad
[NUMP] = KEYMAP(
       // left hand
       KC_BOOTLOADER, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_TRNS,
                                                          KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_TRNS,
                KC_TRNS, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_0,    KC_0,    KC_DOT,  KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MsUp |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsLeft|MsDown|MsRght|      |      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 | Lclk | Rclk |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: Windows Mode - Remaps CMD to Ctrl/ESC and Search (CMD-Space) to LGUI (Win)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | Alt~ |      |      |
 *                                 |Ctl/ES|      |------|       |------| LGUI |      |
 *                                 |      |      |      |       | Altab|      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[WINL] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                            CTL_T(KC_ESC), KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,      KC_TRNS,
       LALT(KC_GRAVE),
       LALT(KC_TAB), LT(MDIA,KC_LGUI), KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(CODE),                // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(NUMP),                // FN2 - Momentary Layer 1 (Number Pad)
    [3] = ACTION_LAYER_TAP_TOGGLE(MDIA),                // FN3 - Momentary Layer 1 (Mouse Layer)
    [4] = ACTION_LAYER_TAP_TOGGLE(WINL),                // FN4 - Momentary Layer 1 (Windows Mode)
    [5] = LGUI(KC_SPACE)                                // FN5 - Search Button for OS X
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

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
