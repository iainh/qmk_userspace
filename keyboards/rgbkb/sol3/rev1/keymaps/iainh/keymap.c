#include QMK_KEYBOARD_H

#include "iainh.h"

/* Qwerty
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ GESC │   1  │   2  │   3  │   4  │   5  │   -  │  │   =  │   6  │   7  │   8  │   9  │   0  │ BkSp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │   [  │  │   ]  │   Y  │   U  │   I  │   O  │   P  │   \  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │FNCAPS│   A  │   S  │   D  │   F  │   G  │   (  │  │   )  │   H  │   J  │   K  │   L  │   ;  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │   Z  │   X  │   C  │   V  │   B  │   {  │  │   }  │   N  │   M  │   ,  │   .  │   /  │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │  Win │  Alt │  RGB │ ADJ  │      │ DEL  │  │ Enter│      │  FN  │ Left │ Down │ Up   │Right │
 * └──────┴──────┴──────┴──────┴──────┤ Space├──────┤  ├──────┤ Space├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │ DEL  │  │ Enter│      │
 *                                    └──────┴──────┘  └──────┴──────┘
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │Vol Dn│Vol Up│Vol Dn│Vol Up│Vol Dn│Vol Up│                │Vol Dn│Vol Up│Vol Dn│Vol Up│Vol Dn│Vol Up│
 * └──────┴──────┴──────┴──────┴──────┴──────┘                └──────┴──────┴──────┴──────┴──────┴──────┘
 * ┌──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┐
 * │Vol Dn│Vol Up│ Prev │ Play │ Next │                              │Vol Dn│Vol Up│ Prev │ Play │ Next │
 * └──────┴──────┴──────┴──────┴──────┘                              └──────┴──────┴──────┴──────┴──────┘
 */

enum sol_layers {
    _COLEMAK,
    _SYMB,
    _NAV,
    _ADJUST
};

enum sol_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE,
    MENU_BTN,
    MENU_UP,
    MENU_DN,
    RGB_RST
};

#define FN       MO(_FN)
#define ADJUST   MO(_ADJUST)
#define COLEMAK  DF(_COLEMAK)
#define SYMBOLS  MO(_SYMB)
#define FN_CAPS  LT(_FN, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_wrapper(
      KC_EQUAL, ________________NUMBERS_L0_________________, KC_LCTL, KC_RCTL, ________________NUMBERS_R0_________________, KC_MINUS,
     KC_DELETE, ______________COLEMAK_MOD_DH_L1____________, KC_LALT, KC_RALT, ______________COLEMAK_MOD_DH_R1____________, KC_BSLS,
       KC_BSPC, ______________COLEMAK_MOD_DH_L2____________, TG(1),     TG(1), ______________COLEMAK_MOD_DH_R2____________, LGUI_T(KC_QUOTE),
       KC_LSFT, ______________COLEMAK_MOD_DH_L3____________, KC_HYPR,  KC_MEH, ______________COLEMAK_MOD_DH_R3____________, KC_RSFT,
       _______, MO(1), RM_TOGG, KC_LEFT, KC_RIGHT, NAV_SPC,  KC_HOME, KC_BSPC, KC_TAB, LCTL_T(KC_ESCAPE), KC_ENTER, KC_UP, KC_DOWN, KC_RALT, MO(1), _______,
        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                       KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
  ),

  [_SYMB] = LAYOUT_wrapper(
     KC_ESCAPE, _______________FUNCTIONS_L0________________, _______, _______, _______________FUNCTIONS_R0________________, KC_F11,
      _______, ________________SYMBOLS_L1_________________, _______, _______, ________________SYMBOLS_R1_________________, KC_F12,
      _______, ________________SYMBOLS_L2_________________, _______, _______, ________________SYMBOLS_R2_________________, _______,
      _______, ________________SYMBOLS_L3_________________, _______, _______, ________________SYMBOLS_R3_________________, _______,
      _______, KC_EQUAL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DOT, KC_0,           KC_EQUAL, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
  ),

  [_NAV] = LAYOUT_wrapper(
    _______, ___________________BLANK___________________, _______,        _______, ___________________BLANK___________________, _______,
    _______, _______________NAVIGATION_L1_______________, _______,        _______, _______________NAVIGATION_R1_______________, _______,
    _______, _______________NAVIGATION_L2_______________, _______,        _______, _______________NAVIGATION_R2_______________, _______,
    _______, _______________NAVIGATION_L3_______________, _______,        _______, _______________NAVIGATION_R3_______________, _______,
    _______, KC_EQUAL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,       _______,
     _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  _______,
    _______, RM_SATD, RM_VALU, RM_SATU, QK_BOOT, _______, _______,                   _______, _______, KC_P7,   KC_P8,   KC_P9,  _______, _______,
    _______, RM_HUED, RM_VALD, RM_HUEU, RGB_RST, _______, DM_REC1,                   _______, _______, KC_P4,   KC_P5,   KC_P6,  _______, _______,
    _______, RM_SPDD, _______, RM_SPDU, _______, _______, DM_RSTP,                   _______, _______, KC_P1,   KC_P2,   KC_P3,  _______, _______,
    _______, RM_PREV, RM_TOGG, RM_NEXT, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_NUM, _______,  COLEMAK,
    _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
  ),
};

void render_layer_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
            oled_write_ln_P(PSTR("Colemk"), false);
            break;
        case _SYMB:
            oled_write_ln_P(PSTR("SYMB   "), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("NAV  "), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjst"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

char chordal_hold_handedness(keypos_t key) {
    if (key.col == 0 || key.col == MATRIX_COLS - 1) {
        return '*';  // Exempt the outer columns.
    }
    // On split keyboards, typically, the first half of the rows are on the
    // left, and the other half are on the right.
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}


