#pragma once

#define USE_SERIAL

#define MASTER_LEFT

#define PREVENT_STUCK_MODIFIERS

// Define how long a TAP event should last
#undef TAPPING_TERM
#define TAPPING_TERM 180

// If you press a Mod Tap key, tap another key (press and release) and then
// release the Mod Tap key, all within the tapping term, it will output the
// tapping function for both keys.
#define PERMISSIVE_HOLD

// Activate Caps Word by pressing Left Shift + Right Shift
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Double tap reset button to enter bootloader
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
