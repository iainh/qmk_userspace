#pragma once

#include "wrappers.h"

enum iainh_keycodes {
    SCRNSHT = SAFE_RANGE,
    TMUX_LEFT,
    TMUX_DOWN,
    TMUX_UP,
    TMUX_RIGHT,
    TMUX_COPY,
    TMUX_CMD,
    TMUX_DETACH,
    TMUX_KILL,
    TMUX_ZOOM,
    TMUX_SPLIT_H,
    TMUX_SPLIT_V,
    TMUX_LAST_PANE,
    IAINH_SAFE_RANGE,
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
