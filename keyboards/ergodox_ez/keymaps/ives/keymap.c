#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

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
#define _VRSN    12 // Used to define the version macro

// Toggled Layers
#define TO_QWTY TO(_QWERTY)   // Sets Qwerty as the default layer
#define TO_WKMN TO(_WORKMAN)  // Sets Workman as the default layer
#define TO_CLMK TO(_COLEMAK)  // Sets Colemak as the default layer
#define TO_DVRK TO(_DVORAK)   // Sets Dvorak as the default layer
#define TO_NAV  TO(_NAV) // Toggle Nav Layer
#define TO_WIN  TO(_WIN) // Toggle Windows mode

// Momentary Layers
#define MO_RS   M(_RAISE) // Momentarily activate raise the layer, clear all keys on release
#define MO_LW   M(_LOWER) // Momentarily activate lower the layer, clear all keys on release
#define MO_NAV  M(_NAV)   // Momentarily activate nav layer, clear all keys on release

// Special Keys
#define SK_VRSN M(_VRSN)         // Version macro, prints out the layout version.
#define SK_HYCL ALL_T(M(_CLEAR)) // Clear all keys
#define SK_CTES CTL_T(KC_ESC)    // Ctrl/Escape key
#define SK_CTRL_A M(_CTRL_A)     // Ctrl-A Key Macro Key
#define SK_SPTB LGUI(KC_TAB)     // Super + Tab
#define SK_SPGV LGUI(KC_GRV)     // Super + `
#define SK_ALTB LALT(KC_TAB)     // Alt + Tab (for windows mode)
#define SK_SLCB LGUI(KC_LCBR)    // Super + { (previous tab in chrome)
#define SK_SRCB LGUI(KC_RCBR)    // Super + } (next tab in chrome)

// Fillers to make layering more clear
#define _______ KC_TRNS // Transparent Key
#define XXXXXXX KC_NO   // Disable Key

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
 *   |Sleep | Nav  | Ctrl | Ledr | Alt  |                                       | Left | Down |  Up  |Right |  -   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Vol- | Vol+ |       | play | next |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Mute |       | al/t |      |      |
 *                                 | Gui  |Lower |------|       |------| Raise| Space|
 *                                 |      |      | Alt  |       | al/~ |      |      |
 *                                 `--------------------'       `--------------------'
 * | Nav  | Ctrl | Ledr | Alt  |Super |Lower |Raise |Space | Left | Down |  Up  | Right|
 */
[_QWERTY] = KEYMAP(
    // left hand
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,
    SK_CTES, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LPRN,
    KC_SLEP, KC_HYPR, KC_LCTL, KC_LALT, MO_NAV,
                                                 KC_VOLD, KC_VOLU,
                                                          KC_MUTE,
                                        KC_LGUI, MO_RS,   KC_LALT,
    // right hand
    KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_RPRN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MINS,
    KC_MPLY, KC_MNXT,
    SK_SPGV,
    SK_SPTB, MO_LW,   KC_SPC
),

/* Workman
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |  `   |           |   =  |   6  |   7  |   8  |   9  |   0  |  Bkspc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   D  |   R  |   W  |   B  |      |           |      |   J  |   F  |   U  |   P  |   ;  |    \   |
 * |--------+------+------+------+------+------|  [   |           |   ]  |------+------+------+------+------+--------|
 * | Ctl/Esc|   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  |    '   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   M  |   C  |   V  |  (   |           |   )  |   K  |   L  |   ,  |   .  |   /  |  Enter |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Sleep | Hyper| Alt  | Nav  |Raise |                                       | Left | Down |  Up  |Right |  -   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Vol- | Vol+ |       | play | next |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Mute |       | al/t |      |      |
 *                                 | Gui  |Lower |------|       |------| Raise| Space|
 *                                 |      |      | Alt  |       | al/~ |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_WORKMAN] = KEYMAP(
    // left hand
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,
    KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_LBRC,
    SK_CTES, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_LPRN,
    KC_SLEP, KC_HYPR, KC_LCTL, KC_LALT, MO_NAV,
                                                 KC_VOLD, KC_VOLU,
                                                          KC_MUTE,
                                        KC_LGUI, MO_RS,   KC_LALT,
    // right hand
    KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_RBRC, KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_BSLS,
             KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT,
    KC_RPRN, KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MINS,
    KC_MPLY, KC_MNXT,
    SK_SPGV,
    SK_SPTB, MO_LW,   KC_SPC
),

/* Colemak
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
 *   |Sleep | Hyper| Alt  | Nav  |Raise |                                       | Left | Down |  Up  |Right |  -   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Vol- | Vol+ |       | play | next |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Mute |       | al/t |      |      |
 *                                 | Gui  |Lower |------|       |------| Raise| Space|
 *                                 |      |      | Alt  |       | al/~ |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_COLEMAK] = KEYMAP(
    // left hand
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_LBRC,
    SK_CTES, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LPRN,
    KC_SLEP, KC_HYPR, KC_LCTL, KC_LALT, MO_NAV,
                                                 KC_VOLD, KC_VOLU,
                                                          KC_MUTE,
                                        KC_LGUI, MO_RS,   KC_LALT,
    // right hand
    KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
             KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_RPRN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MINS,
    KC_MPLY, KC_MNXT,
    SK_SPGV,
    SK_SPTB,  MO_LW, KC_SPC
),

/* Dvorak
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
 *   |Sleep | Hyper| Alt  | Nav  |Raise |                                       | Left | Down |  Up  |Right |  -   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Vol- | Vol+ |       | play | next |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Mute |       | al/t |      |      |
 *                                 | Gui  |Lower |------|       |------| Raise| Space|
 *                                 |      |      | Alt  |       | al/~ |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_DVORAK] = KEYMAP(
    // left hand
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,
    KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_LBRC,
    SK_CTES, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LPRN,
    KC_SLEP, KC_HYPR, KC_LCTL, KC_LALT, MO_NAV,
                                                 KC_VOLD, KC_VOLU,
                                                          KC_MUTE,
                                       KC_LGUI,  MO_RS,   KC_LALT,
    // right hand
    KC_EQL,  KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_RBRC, KC_F,    KC_G,      KC_C,    KC_R,    KC_L,    KC_BSLS,
             KC_D,    KC_H,      KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_RPRN, KC_B,    KC_M,      KC_W,    KC_V,    KC_Z,    KC_ENT,
                      KC_LEFT,   KC_DOWN, KC_UP,   KC_RGHT, KC_MINS,
    KC_MPLY, KC_MNXT,
    SK_SPGV,
    SK_SPTB,  MO_LW, KC_SPC
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
 *                                 |      | XXXX |------|       |------|      | GUI  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RAISE] = KEYMAP(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_AT,   KC_LCBR, KC_RCBR, _______, SK_SLCB,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
    _______, _______, _______, _______, _______,
                                                 KC_PSCR, KC_SLCK,
                                                          _______,
                                        _______, _______, _______,
    // right hand
    _______, _______, _______, _______, _______, _______, KC_DELT,
    SK_SRCB, _______, KC_BSLS, KC_EXLM, KC_TILD, _______, _______,
             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
                      _______, KC_PGDN, KC_PGUP, KC_INS,  _______,
    _______, KC_MPRV,
    _______,
    _______, _______, KC_LGUI
),

/* Lower
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
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
[_LOWER] = KEYMAP(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_DLR,  KC_LBRC, KC_RBRC, _______, _______,
    _______, KC_MINS, KC_EQL,  KC_HASH, KC_PLUS, KC_PERC,
    _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______,
    _______, _______, _______, _______, _______,
                                                 KC_PSCR, KC_SLCK,
                                                          _______,
                                        _______, _______, _______,
    // right hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_PIPE, KC_AMPR, KC_GRV,  _______, _______,
             KC_CIRC, KC_UNDS, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
    _______, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
                      _______, _______, KC_PGDN, KC_PGUP, KC_INS,
    _______, KC_MPRV,
    _______,
    _______, _______, _______
),

/* Adjust
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
 *                                 | Ctrl |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_ADJUST] = KEYMAP(
    // left hand
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, TO_QWTY, TO_WKMN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, TO_DVRK, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, TO_CLMK, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 XXXXXXX, XXXXXXX,
                                                          XXXXXXX,
                                        _______, XXXXXXX, XXXXXXX,
    // right hand
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAGIC_UNNO_GUI,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX,
    XXXXXXX,
    XXXXXXX, XXXXXXX, _______
),

/* Nav/Mouse Mode
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | FIX GUI|
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      | M Up |      |M W Up|      |      |           |      |      | L Clk| R Clk|      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | M Le | M Dn | M Rt |M W Dn|      |------|           |------|      | Left | Down |  Up  | Right|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | XXXX |                                       |      |  Win |Qwerty|Dvorak|Colmak|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                     a            |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|  Gui | Alt  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_NAV] = KEYMAP(
    // left hand
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, KC_MS_U, XXXXXXX, KC_WH_D, XXXXXXX, _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
    _______, _______, _______, _______, _______,
                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,
    // right hand
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, _______,
             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, KC_LALT, KC_LGUI
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
 *                                 |      |      |      |       |Alt Tb|      |      |
 *                                 | Ctrl |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_WIN] = KEYMAP(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_LGUI, KC_LALT, _______,
                                                 _______, _______,
                                                          _______,
                                        KC_LCTL, _______, _______,
    // right hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______,
    _______, _______,
    SK_ALTB,
    _______, _______, _______
),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case _VRSN:
          if (record->event.pressed) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
          }
          break;
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
        case _CTRL_A:
          if (record->event.pressed) {
            return MACRO( D(LCTL), T(A), U(LCTL), END  );
          }
          break;
      }
    return MACRO_NONE;
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
