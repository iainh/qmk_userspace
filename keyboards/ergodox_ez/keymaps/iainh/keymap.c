#include QMK_KEYBOARD_H
#include "version.h"
#include "iainh.h"

#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
  VRSN = SAFE_RANGE,
  RGB_SLD,
  HSV_172_255_255,
  HSV_86_255_128,
  HSV_27_255_255,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE]  = LAYOUT_ergodox_pretty_wrapper(
   KC_EQUAL, ________________NUMBERS_L0_________________, KC_MAC_COPY, KC_MAC_PASTE, ________________NUMBERS_R0_________________, KC_MINUS,
  KC_DELETE, ______________COLEMAK_MOD_DH_L1____________, TG(1),              TG(1), ______________COLEMAK_MOD_DH_R1____________, KC_BSLS,
    KC_BSPC, ______________COLEMAK_MOD_DH_L2____________,                            ______________COLEMAK_MOD_DH_R2____________, LGUI_T(KC_QUOTE),
    KC_LSFT, ______________COLEMAK_MOD_DH_L3____________, KC_HYPR,           KC_MEH, ______________COLEMAK_MOD_DH_R3____________, KC_RSFT,
          LT(1,KC_GRAVE), KC_LALT, KC_LGUI, KC_LEFT, KC_RIGHT,                KC_UP, KC_DOWN, KC_RALT, KC_RALT, MO(1),
                                             LALT_T(KC_APPLICATION),KC_LGUI,        KC_LALT,        LCTL_T(KC_ESCAPE),
                                                                    KC_HOME,        KC_PGUP,
                                      NAV_SPC,        KC_BSPC,      KC_END,         KC_PGDN,      KC_TAB,         KC_ENTER
  ),
[SYMB] = LAYOUT_ergodox_pretty_wrapper(
  KC_ESCAPE, _______________FUNCTIONS_L0________________, _______, _______, _______________FUNCTIONS_R0________________, KC_F11,
   _______, ________________SYMBOLS_L1_________________, _______, _______, ________________SYMBOLS_R1_________________, KC_F12,
   _______, ________________SYMBOLS_L2_________________,                     ________________SYMBOLS_R2_________________, _______,
   _______, ________________SYMBOLS_L3_________________, _______, _______, ________________SYMBOLS_R3_________________, _______,
   _______, KC_EQUAL,    _______, _______, _______,         _______, KC_DOT,     KC_0,           KC_EQUAL,       _______,
                RM_NEXT,        HSV_172_255_255,RM_TOGG,        RGB_SLD,                                        HSV_86_255_128, _______,
                                                                                    RM_VALD,        RM_VALU,        HSV_27_255_255, _______, RM_HUED,        RM_HUEU
  ),
[MDIA]  = LAYOUT_ergodox_pretty_wrapper(
    _______, ___________________BLANK___________________, _______, _______, ___________________BLANK___________________, CK_RST,
    _______, _______, _______, MS_UP,   _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, MS_LEFT,    MS_DOWN,    MS_RGHT,           _______, ___________________BLANK___________________, KC_MEDIA_PLAY_PAUSE,
    _______, ___________________BLANK___________________, _______,         _______, _______, _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,_______, _______,
    _______, WEBUSB_PAIR,    _______, MS_BTN1,        MS_BTN2,             KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  _______, _______,
                                                                                                    _______, _______, _______, _______,
                                                                                                                    _______, _______,
                                                                                    _______, _______, _______, _______, _______, KC_WWW_BACK
  ),
};
// clang-format on

char chordal_hold_handedness(keypos_t key) {
    if (key.col == 0 || key.col == MATRIX_COLS - 1) {
        return '*';  // Exempt the outer columns.
    }
    // On split keyboards, typically, the first half of the rows are on the
    // left, and the other half are on the right.
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
