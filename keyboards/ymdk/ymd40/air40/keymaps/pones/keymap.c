/* Copyright 2021 James Young (@noroadsleft)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum custom_keycodes {
    WO_SELN = SAFE_RANGE,
    DV_ARR
};

enum layer_names {
  _QWERTY,
  _NUMBER,
  _SYMBOL,
  _NAV,
  _DEV,
  _TESTS
};

#define FZ_EXT G(S(KC_UP))
#define FZ_LFT G(KC_LEFT)
#define FZ_RGT G(KC_RIGHT)
#define WO_LFT C(KC_LEFT)
#define WO_RGT C(KC_RIGHT)
#define WO_SLF C(S(KC_LEFT))
#define WO_SRG C(S(KC_RIGHT))
#define WO_SDW S(KC_DOWN)
#define WO_SUP S(KC_UP)
#define WD_CLO C(KC_F4)
#define WI_CLO A(KC_F4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ortho_4x12(
        QK_GESC, KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,  KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
        KC_LCTL, KC_LGUI, KC_LALT, MO(3), MO(1), KC_SPC, KC_SPC, MO(2), MO(4),   KC_LALT, KC_LGUI, KC_LCTL
    ),
    [_NUMBER] = LAYOUT_ortho_4x12(
        KC_NO,   KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_NO, KC_NO, KC_7, KC_8, KC_9,   KC_NO, KC_BSPC,
        KC_NO,   KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_NO, KC_NO, KC_4, KC_5, KC_6,   KC_NO, KC_NO,
        KC_NO,   KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_1, KC_2, KC_3,   KC_NO, KC_RSFT,
        KC_WAKE, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO, KC_0, KC_0, KC_DOT, KC_NO, KC_RCTL
    ),
    [_SYMBOL] = LAYOUT_ortho_4x12(
        KC_GRV, S(KC_1),     S(KC_2), S(KC_3),     S(KC_4),     S(KC_5),  KC_NO,       DV_ARR,   KC_NO,      KC_NO,   KC_NO,    KC_DELETE,
        KC_NO,  S(KC_SLASH), KC_NO,   KC_MINUS,    KC_EQUAL,    S(KC_8),  S(KC_COMMA), S(KC_9), S(KC_LBRC), KC_LBRC, KC_SLASH, S(KC_7),
        KC_NO,  S(KC_6),     KC_NO,   S(KC_MINUS), S(KC_EQUAL), KC_SLASH, S(KC_DOT),   S(KC_0), S(KC_RBRC), KC_RBRC, KC_BSLS,  S(KC_BSLS),
        KC_NO,  KC_NO,       KC_NO,   KC_NO,       KC_NO,       KC_NO,    KC_NO,       KC_NO,   KC_NO,      KC_NO,   KC_NO,    KC_NO
    ),
    [_NAV] = LAYOUT_ortho_4x12(
        KC_NO, FZ_EXT, FZ_LFT, FZ_RGT, WD_CLO,  WI_CLO,   KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  KC_BTN1,
        KC_NO, WO_LFT, WO_RGT, WO_SLF, WO_SRG, WO_SELN, KC_NO, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_WH_U,
        KC_NO, KC_NO,  KC_NO,  WO_SDW, WO_SUP, KC_NO,   KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_WH_D,
        KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO, MO(5),   KC_NO,   KC_LALT, KC_LGUI,  KC_LCTL
    ),
    [_DEV] = LAYOUT_ortho_4x12(
        C(KC_GRV),  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F9, KC_F5,     KC_F10, KC_F11, S(KC_F11), C(S(KC_B)),
        KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, C(KC_F12), KC_NO,  KC_NO,  KC_NO,     KC_NO,
        KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,  KC_NO,  KC_NO,     KC_NO,
        KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,  KC_NO,  KC_NO,     KC_NO
    ),
    [_TESTS] = LAYOUT_ortho_4x12(
        AS_RPT,  RGB_TOG,  RGB_VAI, RGB_HUI, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        AS_UP,   RGB_MOD,  RGB_VAD, RGB_HUD, KC_NO,  KC_NO, KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,
        AS_DOWN, RGB_RMOD, RGB_SPI, RGB_SAI, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        AS_TOGG, KC_NO,    RGB_SPD, RGB_SAD, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case WO_SELN:
                SEND_STRING(SS_TAP(X_HOME)SS_TAP(X_HOME)SS_DOWN(X_LSFT)SS_TAP(X_END)SS_UP(X_LSFT));
            break;
            case DV_ARR:
                SEND_STRING("=>");
            break;

        }
    }

    return true;
};
