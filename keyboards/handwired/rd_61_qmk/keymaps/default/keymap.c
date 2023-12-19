// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT_60_ansi(
            KC_ESC,   KC_1,               KC_2,         KC_3,      KC_4,            KC_5,      KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
            KC_TAB,   KC_Q,               KC_W,         KC_E,      KC_R,            KC_T,      KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
            KC_CAPS,  KC_A,               KC_S,         KC_D,      KC_F,            KC_G,      KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
            KC_LSFT,                      KC_Z,         KC_X,      KC_C,            KC_V,      KC_B,     KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
            KC_LCTL,  LT(MO(1), KC_LGUI), KC_LALT,                                             KC_SPC,                               KC_RALT, MO(3),   KC_RCTL, KC_PENT
            ),

        [1] = LAYOUT_60_ansi(
            KC_GRV,   KC_F1,              KC_F2,        KC_F3,        KC_F4,        KC_F5,     KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
            KC_PSCR,  DF(0),              KC_UP,        KC_MUTE,      KC_VOLD,      KC_VOLU,   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_DEL,   KC_LEFT,            KC_DOWN,      KC_RGHT,      KC_BRID,      KC_BRIU,   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
            KC_LSFT,                      A(KC_TAB),    A(S(KC_TAB)), C(S(KC_TAB)), C(KC_TAB), KC_MPLY,  KC_MPRV,  KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS,          KC_RSFT,
            KC_LGUI,  KC_TRNS,            MO(2),                                               KC_MPLY,                              KC_TRNS, MO(3),   KC_TRNS, KC_TRNS
            ),

        [2] = LAYOUT_60_ansi(
            QK_RBT,   KC_TRNS,            KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,  KC_BSPC,
            KC_PSCR,  KC_P7,              KC_P8,        KC_P9,        KC_PSLS,      KC_PAST,   KC_LEFT,  KC_TRNS,  KC_TRNS, KC_7,    KC_8,    KC_9,    KC_TRNS, KC_PSCR,
            KC_DEL,   KC_P4,              KC_P5,        KC_P6,        KC_PMNS,      KC_PPLS,   KC_RGHT,  KC_TRNS,  KC_TRNS, KC_4,    KC_5,    KC_6,             KC_TRNS,
            KC_LSFT,                      KC_P1,        KC_P2,        KC_P3,        KC_PDOT,   KC_P0,    KC_ENT,   KC_TRNS, KC_1,    KC_2,    KC_3,             KC_RSFT,
            KC_TRNS,  KC_TRNS,            KC_TRNS,                                             KC_TRNS,                              KC_TRNS, MO(3),   KC_TRNS, KC_TRNS
            ),

        [3] = LAYOUT_60_ansi(
            KC_TRNS,  KC_TRNS,            KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, DB_TOGG, QK_RBT,  QK_BOOT, QK_MAKE,
            KC_TRNS,  KC_TRNS,            KC_P7,        KC_P8,        KC_P9,        KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_P7,   KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,  KC_TRNS,            KC_P4,        KC_P2,        KC_P6,        KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_P1,   KC_P9,   KC_P3,            KC_TRNS,
            KC_TRNS,                      KC_P0,        KC_P1,        KC_P2,        KC_P3,     KC_TRNS,  DF(3),    DF(2),   DF(1),   DF(0),   RGB_VAI,          KC_TRNS,
            KC_TRNS,  KC_TRNS,            KC_TRNS,                                             KC_TRNS,                              RGB_MOD, KC_TRNS, RGB_HUI, RGB_SAI
  )
};

// Joystick feature

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_VIRTUAL, // x
    JOYSTICK_AXIS_VIRTUAL,  // y
    JOYSTICK_AXIS_VIRTUAL, // Rx
    JOYSTICK_AXIS_VIRTUAL  // Ry
};

// Virtual joystick keymap, precision mod

static bool precision = false;
static uint16_t precision_mod = 800;
static uint16_t axis_val = 1023;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    int16_t precision_val = axis_val;
    if (precision) {
        precision_val -= precision_mod;
    }

    switch (keycode) {
        case KC_P8:
            joystick_set_axis(1, record->event.pressed ? -precision_val : 0);
            return false;
        case KC_P2:
            joystick_set_axis(1, record->event.pressed ? precision_val : 0);
            return false;
        case KC_P4:
            joystick_set_axis(0, record->event.pressed ? -precision_val : 0);
            return false;
        case KC_P6:
            joystick_set_axis(0, record->event.pressed ? precision_val : 0);
            return false;
        case KC_P7:
            joystick_set_axis(3, record->event.pressed ? -precision_val : 0);
            return false;
        case KC_P9:
            joystick_set_axis(3, record->event.pressed ? precision_val : 0);
            return false;
        case KC_P1:
            joystick_set_axis(2, record->event.pressed ? -precision_val : 0);
            return false;
        case KC_P3:
            joystick_set_axis(2, record->event.pressed ? precision_val : 0);
            return false;
        case KC_P0:
            precision = record->event.pressed;
            return false;
    }
    return true;
}
