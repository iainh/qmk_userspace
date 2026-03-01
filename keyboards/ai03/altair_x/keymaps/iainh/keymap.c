/* Copyright 2024 ai03 Design Studio */
/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
#include "iainh.h"

enum layers {
    _COLEMAK,
    _SYMB,
    _NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_COLEMAK] = LAYOUT_wrapper(
        KC_DELETE, ______________COLEMAK_MOD_DH_L1____________, KC_EQUAL, KC_MINUS, ______________COLEMAK_MOD_DH_R1____________, KC_BSLS,
  LGUI_T(KC_BSPC), ______________COLEMAK_MOD_DH_L2____________, KC_ESC,     KC_ESC, ______________COLEMAK_MOD_DH_R2____________, RGUI_T(KC_QUOTE),
          KC_LSFT, ______________COLEMAK_MOD_DH_L3____________, KC_MEH,     KC_MEH, ______________COLEMAK_MOD_DH_R3____________, KC_RSFT,
                            KC_LEFT, KC_RIGHT, KC_SPC, KC_BSPC,                 KC_TAB, KC_ENTER, KC_UP, KC_DOWN
 ),

 [_SYMB] = LAYOUT_wrapper(
     _______, ________________SYMBOLS_L1_________________, _______, _______,  ________________SYMBOLS_R1_________________, KC_F12,
     _______, ________________SYMBOLS_L2_________________, _______, _______, ________________SYMBOLS_R2_________________, _______,
     _______, ________________SYMBOLS_L3_________________, _______, _______, ________________SYMBOLS_R3_________________, _______,
                             _______, _______, _______, _______, _______, _______, KC_DOT,     KC_0
  ),

 [_NAV] = LAYOUT_wrapper(
   _______, _______________NAVIGATION_L1_______________, _______, _______, _______________NAVIGATION_R1_______________, _______,
   _______, _______________NAVIGATION_L2_______________, _______, _______, _______________NAVIGATION_R2_______________, _______,
   _______, _______________NAVIGATION_L3_______________, _______, _______, _______________NAVIGATION_R3_______________, _______,
                            _______, _______, _______, _______, _______, _______, _______, _______
  )
};


char chordal_hold_handedness(keypos_t key) {
    if (key.col == 0 || key.col == MATRIX_COLS - 1) {
        return '*';  // Exempt the outer columns.
    }
    // On split keyboards, typically, the first half of the rows are on the
    // left, and the other half are on the right.
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}


