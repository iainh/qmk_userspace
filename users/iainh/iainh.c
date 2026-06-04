#include "iainh.h"

#define TMUX_PREFIX SS_DOWN(X_LCTL) "b" SS_UP(X_LCTL)

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SCRNSHT:
            if (record->event.pressed) {
                switch (detected_host_os()) {
                    case OS_MACOS:
                    case OS_IOS:
                        tap_code16(LGUI(LSFT(KC_4)));
                        break;
                    case OS_WINDOWS:
                    case OS_UNSURE:
                    default:
                        tap_code16(LGUI(LSFT(KC_S)));
                        break;
                }
            }
            return false;
        case TMUX_LEFT:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX SS_TAP(X_LEFT));
            }
            return false;
        case TMUX_DOWN:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX SS_TAP(X_DOWN));
            }
            return false;
        case TMUX_UP:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX SS_TAP(X_UP));
            }
            return false;
        case TMUX_RIGHT:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX SS_TAP(X_RIGHT));
            }
            return false;
        case TMUX_COPY:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "[");
            }
            return false;
        case TMUX_CMD:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX ":");
            }
            return false;
        case TMUX_DETACH:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "d");
            }
            return false;
        case TMUX_KILL:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "x");
            }
            return false;
        case TMUX_ZOOM:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "z");
            }
            return false;
        case TMUX_SPLIT_H:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "%");
            }
            return false;
        case TMUX_SPLIT_V:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "\"");
            }
            return false;
        case TMUX_LAST_PANE:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX ";");
            }
            return false;
    }

    return process_record_keymap(keycode, record);
}

bool is_flow_tap_key(uint16_t keycode) {
    // Do not include Space: after a word break, home-row Shift should still
    // have a chance to resolve as a hold for sentence capitalization.
    switch (get_tap_keycode(keycode)) {
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    return get_chordal_hold_default(tap_hold_record, other_record);
}
