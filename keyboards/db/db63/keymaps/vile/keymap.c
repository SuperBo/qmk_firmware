/*
Copyright 2020 Hung DO <hungdohuy@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define MY_CTL CTL_T(KC_CAPS)
#define FN1_PLY LT(1, KC_MPLY)

uint8_t current_mode;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        MY_CTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT, KC_UP,   KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, FN1_PLY, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        KC_GRV,  RGB_TOG, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, BL_BRTG, BL_TOGG, BL_DEC, BL_INC,  KC_PGUP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, KC_PGDN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______,
        _______, _______, _______,                            _______,                   _______, _______, KC_MPRV, KC_VOLD, KC_MNXT 
    ),
};

void dynamic_macro_record_start_user(void) {
    current_mode = rgblight_get_mode();
    rgblight_mode(16);
}

void dynamic_macro_record_end_user(int8_t direction) {
    rgblight_mode(current_mode);
}

bool led_update_user(led_t led_state) {
    if (led_state.caps_lock) {
        rgblight_sethsv(HSV_CYAN);
        writePinHigh(D1);
    } else {
        rgblight_sethsv(HSV_GREEN);
        writePinLow(D1);
    }
    return false;
}

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        backlight_enable();
        backlight_disable();
    }
      return true; // Process all other keycodes normally
} */
