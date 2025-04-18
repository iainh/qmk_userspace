#pragma once

// No need for the single versions when multi performance isn't a problem =D
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH

// 20m timeout (20m * 60s * 1000mil)
// #define RGB_DISABLE_TIMEOUT 1200000
#define RGB_DISABLE_WHEN_USB_SUSPENDED

#define STM32_ONBOARD_EEPROM_SIZE 2048

// Tap-hold configuration for home row mods.
#define TAPPING_TERM 175
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM_PER_KEY

#define CHORDAL_HOLD
