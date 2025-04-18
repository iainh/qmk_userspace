/* Copyright 2023-2024 iainh <iain@spiralpoint.org>
 *
 *  This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "iainh.h"

enum my_layers {
  _COLEMAK,
  _SYMB,
  _NAV,
  _FUNC,
};

enum my_tds {
  TdH,
  TdL
};

#define FUNC LT(_FUNC, KC_SPC)
#define SYMBOL OSL(_SYMB)

#define OSMCMD OSM(MOD_LGUI)
#define OSMOPT OSM(MOD_LALT)
#define OSMCTL OSM(MOD_LCTL)
#define OSMSFT OSM(MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_wrapper(
    ______________COLEMAK_MOD_DH_L1____________,                              ______________COLEMAK_MOD_DH_R1____________,
    ______________COLEMAK_MOD_DH_L2____________,                              ______________COLEMAK_MOD_DH_R2____________,
    ______________COLEMAK_MOD_DH_L3____________, KC_ESC,              KC_ESC, ______________COLEMAK_MOD_DH_R3____________,
    MO(_SYMB), LGUI_T(KC_EQUAL), KC_DELETE, KC_APP, KC_SPC, KC_BSPC, KC_TAB, KC_ENT, KC_MINUS, KC_BSLS, RGUI_T(KC_QUOTE), MO(_SYMB)
  ),

  [_SYMB] = LAYOUT_wrapper(
    ________________SYMBOLS_L1_________________,                   ________________SYMBOLS_R1_________________,
    ________________SYMBOLS_L2_________________,                   ________________SYMBOLS_R2_________________,
    ________________SYMBOLS_L3_________________, _______, _______, ________________SYMBOLS_R3_________________,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DOT,    KC_0, _______
  ),

  [_FUNC] = LAYOUT(
    KC_MRWD, KC_VOLU, KC_VOLD, KC_MFFD, KC_MPLY,                   KC_INS,  KC_F7,   KC_F8,   KC_F9,   KC_CAPS,
    KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_BRIU,                   KC_F12,  KC_F4,   KC_F5,   KC_F6,   TD(TdL),
    KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_BRID, _______, _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_F11,
    _______, _______, _______, CW_TOGG, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NAV] = LAYOUT_wrapper(
     _______________NAVIGATION_L1_______________,                   _______________NAVIGATION_R1_______________,
     _______________NAVIGATION_L2_______________,                   _______________NAVIGATION_R2_______________,
     _______________NAVIGATION_L3_______________, _______, _______, _______________NAVIGATION_R3_______________,
     _______, _______, _______, CW_TOGG, _______, _______, _______, _______, _______, _______, _______, _______
   ),
};

char chordal_hold_handedness(keypos_t key) {
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
