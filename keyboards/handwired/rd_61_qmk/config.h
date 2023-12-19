// Copyright 2023 abhiakl (@abhijithabhiakl)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* QK_MAKE support*/
#define ENABLE_COMPILE_KEYCODE

// Min 0, max 32
#define JOYSTICK_BUTTON_COUNT 2
// Min 0, max 6: X, Y, Z, Rx, Ry, Rz
#define JOYSTICK_AXIS_COUNT 4
// Min 8, max 16
#define JOYSTICK_AXIS_RESOLUTION 10
