// This layout is geared towards those who want easy access to 
//
#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY  0  // Qwerty Layer
#define _WORKMAN 1  // Workman Layer
#define _COLEMAK 2  // Colemak Layer
#define _DVORAK  3  // Dvorak Layer
#define _LOWER   4  // Lower - Number layer
#define _RAISE   5  // Raise - Symbol layer
#define _ADJUST  7  // Adjustments layer (keymap, ect)
#define _NAV     8  // Mouse Layer
#define _WIN     9  // Windows mode layer
#define _CLEAR   10 // Clear all keys
#define _CTRL_A  11 // Ctrl-A Macro

// Toggled Layers
#define TO_QWTY   TO(_QWERTY)   // Sets Qwerty as the default layer
#define TO_WKMN   TO(_WORKMAN)  // Sets Workman as the default layer
#define TO_CLMK   TO(_COLEMAK)  // Sets Colemak as the default layer
#define TO_DVRK   TO(_DVORAK)   // Sets Dvorak as the default layer
#define TG_WIN  TO(_WIN) // Toggle Windows mode

// Momentary Layers
#define MO_RS   M(_RAISE) // Momentarily activate raise the layer, clear all keys on release
#define MO_LW   M(_LOWER) // Momentarily activate lower the layer, clear all keys on release
#define MO_NAV  M(_NAV)   // Momentarily activate nav layer, clear all keys on release

// Special Keys
#define SK_CTLB LCTL(KC_B)       // Ctrl-B Key Macro Key
#define SK_HYCL ALL_T(M(_CLEAR)) // Clear all keys
#define SK_CTES CTL_T(KC_ESC)    // Ctrl/Escape key
#define SK_OSMH OSM(KC_MEH)      // One Shot Meh Key
#define SK_OSHY OSM(KC_HYPR)    // One shot hyper key
#define SK_CLBR LGUI(KC_LBRC)    // GUI + [
#define SK_CRBR LGUI(KC_RBRC)    // GUI + ]
#define SK_CLCB LGUI(KC_LCBR)    // GUI + {
#define SK_CRCB LGUI(KC_RCBR)    // GUI + }

// Fillers to make layering more clear
#define _______ KC_TRNS // Transparent Key
#define XXXXXXX KC_NO   // Disable Key

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * Like the default QWERTY layout, expect with the space split into a nav and space buttons
 * as well as escape as a dual button (escape unless another button is pressed)
 *
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |ES/CTL|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Hyper| Ctrl | Alt  | Nav  |Super |Lower |Raise |Space | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC, \
   SK_CTES, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
   KC_HYPR, SK_CTLB, KC_LALT, MO_NAV,  KC_LGUI, MO_LW,  MO_RS,  KC_SPC,KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Workman
 *
 * A workman varient of my Qwerty layout
 *
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |ES/CTL|   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Hyper|Ctrl+B| Alt  | Nav  |Super |Lower |Raise |Space | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_WORKMAN] = LAYOUT( \
   KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,   KC_J,   KC_F,  KC_U,    KC_P,    KC_SCLN, KC_BSPC, \
   SK_CTES, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,   KC_Y,   KC_N,  KC_E,    KC_O,    KC_I,    KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,   KC_K,   KC_L,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
   KC_HYPR, SK_CTLB, KC_LALT, MO_NAV,  KC_LGUI, MO_LW,  MO_RS,  KC_SPC,KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Colemak
 *
 * Almost just the standard Planck Colemak layout, except for the FN, Page Up, Page Down, Delete keys
 *
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |ES/CTL|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Hyper|Ctrl+B| Alt  | Nav  |Super |Lower |Raise |Space | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT( \
   KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,   KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
   SK_CTES, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,   KC_H,   KC_N,  KC_E,    KC_I,    KC_O,    KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_K,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
   KC_HYPR, SK_CTLB, KC_LALT, MO_NAV,  KC_LGUI, MO_LW,  MO_RS,  KC_SPC,KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Dvorak
 *
 * Almost just the standard Planck Dvorak layout, except for the FN, Page Up, Page Down, Delete keys
 *
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |ES/CTL|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Hyper|Ctrl+B| Alt  | Nav  |Super |Lower |Raise |Space | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT( \
   KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,   KC_F,   KC_G,  KC_C,    KC_R,    KC_L,    KC_BSPC, \
   SK_CTES, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,   KC_D,   KC_H,  KC_T,    KC_N,    KC_S,    KC_SLSH, \
   KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   KC_B,   KC_M,  KC_W,    KC_V,    KC_Z,    KC_ENT, \
   KC_HYPR, SK_CTLB, KC_LALT, MO_NAV,  KC_LGUI, MO_LW,  MO_RS,  KC_SPC,KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 *
 * This layer activates the numbers like the standard layout, but also puts parentheses
 *
 * ,-----------------------------------------------------------------------------------.
 * |  `   | ---- |   @  |   {  |   }  |Gui+[ |Gui+] |   \  |   !  |   ~  | ---- |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Sleep |      |      |      |      | XXXX |      |  GUI | Next | Vol+ | Vol- | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
   KC_GRV,  XXXXXXX, KC_AT,   KC_LCBR, KC_RCBR, SK_CLBR, SK_CRBR, KC_BSLS, KC_EXLM, KC_TILD, XXXXXXX, _______, \
   _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
   KC_SLEP, _______, _______, _______, _______, _______, _______, KC_LGUI, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 *
 * This layer activates symbols and a bunch of other stuff.
 *
 * ,-----------------------------------------------------------------------------------.
 * |  `   | ---- |   $  |   [  |   ]  |Gui+{ |Gui+} |   |  |   &  |   `  | ---- |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   -  |   =  |   #  |   +  |   %  |   ^  |   _  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 |  F12 |  F13 |  F14 |  F15 | Left | Down |  Up  | Right|  F20 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Sleep |      |      |      |      |      | XXXX |      |      | BL + | BL - |BL Tgl|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
   KC_GRV,  XXXXXXX, KC_DLR,  KC_LBRC, KC_RBRC, SK_CLCB, SK_CRCB, KC_PIPE, KC_AMPR, KC_GRV,  XXXXXXX, _______, \
   _______, KC_MINS, KC_EQL,  KC_HASH, KC_PLUS, KC_PERC, KC_CIRC, KC_UNDS, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, \
   _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F20,  _______, \
   KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* FN/Mouse
 *
 * Allows for Layer swapping. Also activates a mouse at WASD for movement and JK for left
 * and right click.
 *
 * ,-----------------------------------------------------------------------------------.
 * |      | ---- | M Up | ---- |      | ---- | ---- | L Clk| R Clk| ---- | ---- |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | M Le | M Dn | M Rt |      | ---- | Left | Down |  Up  | Right| ---- |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | ---- | ---- | ---- |      |<- www|www ->| ---- | ---- | ---- | ---- | ---- |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      | XXXX |      |      | Alt  | Gui  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT( \
   _______, XXXXXXX, KC_MS_U, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, _______, \
   _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______, \
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WBAK, KC_WFWD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO_WKMN, \
   _______, _______, _______, _______, _______, _______, KC_LALT, KC_LGUI, _______, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 *
 * This is the layer used to change default layers from QWERTY to another option.
 *
 * ,-----------------------------------------------------------------------------------.
 * | Reset|Qwerty|Workmn| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ---- | ---- |Dvorak| ---- | Hyper| ---- | ---- | Meh  | ---- | ---- | ---- | ---- |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | ---- | ---- |Colemk| ---- | ---- |BL Tgl| ---- | ---- | ---- | ---- | ---- | ---- |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ---- | ---- | ---- | ---- | ---- | XXXX | XXXX | ---- | ---- | ---- | ---- | ---- |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT( \
   RESET,   TO_QWTY, TO_WKMN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
   XXXXXXX, XXXXXXX, XXXXXXX, TO_DVRK, SK_OSHY, XXXXXXX, XXXXXXX, SK_OSMH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
   XXXXXXX, XXXXXXX, XXXXXXX, TO_CLMK, XXXXXXX, BL_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
),

/* Windows
 *
 * Swaps the Ctrl and GUI keys so the keyboard acts more like windows.
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  Gui |      |      | Ctrl |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_WIN] = LAYOUT( \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
   _______, KC_LGUI, _______, _______, KC_LCTL, _______, _______, _______, _______, _______, _______, _______ \
)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case _CLEAR:
          clear_keyboard();
        break;
        case _RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_RAISE, _LOWER, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_RAISE, _LOWER, _ADJUST);
          }
          break;
        case _LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_RAISE, _LOWER, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_RAISE, _LOWER, _ADJUST);
          }
          break;
        case _NAV:
          if(record->event.pressed) {
            layer_on(_NAV);
          } else {
            clear_keyboard();
            layer_off(_NAV);
          }
          break;
      }
    return MACRO_NONE;
};
