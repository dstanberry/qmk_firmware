#pragma once

#define USE_SERIAL

#define MASTER_LEFT

#define PREVENT_STUCK_MODIFIERS

// Define how long a TAP event should last
#undef TAPPING_TERM
#define TAPPING_TERM 180

// Holding a Mod Tap chord is registered as a hold if held longer than
// TAPPING_TERM. Otherwise it will register each as a TAP.
#define IGNORE_MOD_TAP_INTERRUPT

// If you press a Mod Tap key, tap another key (press and release) and then
// release the Mod Tap key, all within the tapping term, it will output the
// tapping function for both keys.
#define PERMISSIVE_HOLD

// Activate Caps Word by pressing Left Shift + Right Shift
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
