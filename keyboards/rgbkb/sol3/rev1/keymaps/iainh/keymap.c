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

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)


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
       _______, MO(1), RGB_TOG, KC_LEFT, KC_RIGHT, KC_SPC,   KC_HOME, KC_BSPC, KC_TAB, LCTL_T(KC_ESCAPE), KC_ENTER, KC_UP, KC_DOWN, KC_RALT, MO(1), _______,
        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                       KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
  ),

  [_SYMB] = LAYOUT_wrapper(
     KC_ESCAPE, _______________FUNCTIONS_L0________________, KC_TRNS, KC_TRNS, _______________FUNCTIONS_R0________________, KC_F11,
      KC_TRNS, ________________SYMBOLS_L1_________________, KC_TRNS, KC_TRNS, ________________SYMBOLS_R1_________________, KC_F12,
      KC_TRNS, ________________SYMBOLS_L2_________________, KC_TRNS, KC_TRNS, ________________SYMBOLS_R2_________________, KC_TRNS,
      KC_TRNS, ________________SYMBOLS_L3_________________, KC_TRNS, KC_TRNS, ________________SYMBOLS_R3_________________, KC_TRNS,
      KC_TRNS, KC_EQUAL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOT, KC_0,           KC_EQUAL, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
  ),

  [_NAV] = LAYOUT_wrapper(
    KC_TRNS, ___________________BLANK___________________, KC_TRNS,        KC_TRNS, ___________________BLANK___________________, KC_TRNS,
    KC_TRNS, _______________NAVIGATION_L1_______________, KC_TRNS,        KC_TRNS, _______________NAVIGATION_R1_______________, KC_TRNS,
    KC_TRNS, _______________NAVIGATION_L2_______________, KC_TRNS,        KC_TRNS, _______________NAVIGATION_R2_______________, KC_TRNS,
    KC_TRNS, _______________NAVIGATION_L3_______________, KC_TRNS,        KC_TRNS, _______________NAVIGATION_R3_______________, KC_TRNS,
    KC_TRNS, KC_EQUAL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,       _______,
     _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  _______,
    _______, RGB_SAD, RGB_VAI, RGB_SAI, RESET,   _______, _______,                   _______, _______, KC_P7,   KC_P8,   KC_P9,  _______, _______,
    _______, RGB_HUD, RGB_VAD, RGB_HUI, RGB_RST, _______, DM_REC1,                   _______, _______, KC_P4,   KC_P5,   KC_P6,  _______, _______,
    _______, RGB_SPD, _______, RGB_SPI, _______, _______, DM_RSTP,                   _______, _______, KC_P1,   KC_P2,   KC_P3,  _______, _______,
    _______, RGB_RMOD,RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_NUM, _______,  COLEMAK,
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
