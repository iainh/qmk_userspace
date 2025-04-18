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
          KC_LSFT, ______________COLEMAK_MOD_DH_L3____________, KC_TRNS,   KC_TRNS, ______________COLEMAK_MOD_DH_R3____________, KC_RSFT,
                            KC_LEFT, KC_RIGHT, KC_SPC, KC_BSPC,                 KC_TAB, KC_ENTER, KC_UP, KC_DOWN
 ),

 [_SYMB] = LAYOUT_wrapper(
     KC_TRNS, ________________SYMBOLS_L1_________________, KC_TRNS, KC_TRNS,  ________________SYMBOLS_R1_________________, KC_F12,
     KC_TRNS, ________________SYMBOLS_L2_________________, KC_TRNS, KC_TRNS, ________________SYMBOLS_R2_________________, KC_TRNS,
     KC_TRNS, ________________SYMBOLS_L3_________________, KC_TRNS, KC_TRNS, ________________SYMBOLS_R3_________________, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOT,     KC_0
  ),

 [_NAV] = LAYOUT_wrapper(
   KC_TRNS, _______________NAVIGATION_L1_______________, KC_TRNS, KC_TRNS, _______________NAVIGATION_R1_______________, KC_TRNS,
   KC_TRNS, _______________NAVIGATION_L2_______________, KC_TRNS, KC_TRNS, _______________NAVIGATION_R2_______________, KC_TRNS,
   KC_TRNS, _______________NAVIGATION_L3_______________, KC_TRNS, KC_TRNS, _______________NAVIGATION_R3_______________, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally allow some one-handed chords for hotkeys.
    switch (tap_hold_keycode) {
        case LCTL_T(KC_Z):
            if (other_keycode == KC_C || other_keycode == KC_D || other_keycode == KC_S || other_keycode == KC_V) {
                return true;
            }
            break;

        case RCTL_T(KC_SLSH):
            if (other_keycode == KC_L) {
                return true;
            }
            break;
    }

    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}
