#pragma once

#include QMK_KEYBOARD_H

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...)      LAYOUT_split_3x6_3(__VA_ARGS__)

#define LSFT_A LSFT_T(KC_A)
#define LCTL_Z LCTL_T(KC_Z)
#define LALT_X LALT_T(KC_X)

#define RSFT_O RSFT_T(KC_O)
#define RCTL_SLASH RCTL_T(KC_SLASH)
#define RALT_DOT RALT_T(KC_DOT)

#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,   KC_W,   KC_F, KC_P,       KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_A,   KC_R,   KC_S, LT(2,KC_T), LT(1,KC_G)
#define ______________COLEMAK_MOD_DH_L3____________       LCTL_Z, LALT_X, KC_C, KC_D,       KC_V

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,       KC_L, KC_U,    KC_Y,     KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________       LT(1,KC_M), KC_N, KC_E,    KC_I,     RSFT_O
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,       KC_H, KC_COMM, RALT_DOT, RCTL_SLASH

#define ________________NUMBERS_L0_________________       KC_1, KC_2, KC_3, KC_4, KC_5
#define ________________NUMBERS_R0_________________       KC_6, KC_7, KC_8, KC_9, KC_0

#define _______________FUNCTIONS_L0________________       KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define _______________FUNCTIONS_R0________________       KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

#define ________________SYMBOLS_L1_________________       KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE
#define ________________SYMBOLS_L2_________________       KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRAVE
#define ________________SYMBOLS_L3_________________       KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD

#define ________________SYMBOLS_R1_________________       KC_UP,   KC_7, KC_8, KC_9, KC_ASTR
#define ________________SYMBOLS_R2_________________       KC_DOWN, KC_4, KC_5, KC_6, KC_PLUS
#define ________________SYMBOLS_R3_________________       KC_AMPR, KC_1, KC_2, KC_3, KC_BSLS

#define _______________NAVIGATION_L1_______________       _______, _______, _______, _______, _______
#define _______________NAVIGATION_L2_______________       _______, _______, _______, _______, _______
#define _______________NAVIGATION_L3_______________       _______, _______, _______, _______, _______

#define _______________NAVIGATION_R1_______________       _______, _______, _______, _______, _______
                                                          // ADM-3A style arrows
#define _______________NAVIGATION_R2_______________       KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, _______
#define _______________NAVIGATION_R3_______________       _______, _______, _______, _______, _______

#define ___________________BLANK___________________       _______, _______, _______, _______, _______

// clang-format on
