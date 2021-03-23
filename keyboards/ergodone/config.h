#ifndef ERGODOX_ERGODONE_CONFIG_H
#define ERGODOX_ERGODONE_CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x1209  
#define PRODUCT_ID      0x2328  
// The official ErgoDone VID and PID are documented at http://pid.codes/1209/2328/.
#define DEVICE_VER      0x0001
#define MANUFACTURER    K.T.E.C.
#define PRODUCT         ErgoDone

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 14

#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY 0

#define TAPPING_TOGGLE  1

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* #define RETRO_TAPPING */
#define PERMISSIVE_HOLD
#define TAPPING_TERM   180
#define IGNORE_MOD_TAP_INTERRUPT // this makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
/* #define LOCKING_SUPPORT_ENABLE */
/* Locking resynchronize hack */
/* #define LOCKING_RESYNC_ENABLE */

/* key combination for command */
/* #define IS_COMMAND() ( \ */
/*     get_mods() == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)) || \ */
/*     get_mods() == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)) \ */
/* ) */

/* number of backlight levels */
#define BACKLIGHT_LEVELS 3

#define LED_BRIGHTNESS_LO       15
#define LED_BRIGHTNESS_HI       127

/* fix space cadet rollover issue */
#define DISABLE_SPACE_CADET_ROLLOVER

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    6

#define USB_MAX_POWER_CONSUMPTION 500

#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING

#define DYNAMIC_MACRO_NO_NESTING
#define UNICODE_SELECTED_MODES UC_LNX

/* NKRO */
#ifndef FORCE_NKRO
    #define FORCE_NKRO  // Depends on NKRO_ENABLE.
#endif

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
//#define DEBUG_MATRIX_SCAN_RATE

#endif
