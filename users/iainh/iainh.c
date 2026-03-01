#include "iainh.h"

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally allow some one-handed chords for hotkeys.
    switch (tap_hold_keycode) {
        // Left hand CTRL-C, CTRL-D, CTRL-S, CTRL-V
        case LCTL_T(KC_Z):
            if (other_keycode == KC_C || other_keycode == KC_D || other_keycode == KC_S || other_keycode == KC_V) {
                return true;
            }
            break;

        // Right hand CTRL-L
        case RCTL_T(KC_SLSH):
            if (other_keycode == KC_L) {
                return true;
            }
            break;

        // Right hand ALT-TAB
        case RALT_T(KC_DOT):
            if (other_keycode == KC_TAB) {
                return true;
            }
            break;
    }

    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}
