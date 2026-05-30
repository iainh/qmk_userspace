#pragma once

#include "wrappers.h"

enum iainh_keycodes {
    SCRNSHT = SAFE_RANGE,
    IAINH_SAFE_RANGE,
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
