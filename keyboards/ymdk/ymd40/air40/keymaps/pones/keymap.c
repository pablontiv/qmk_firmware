#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _NUMBER,
  _SYMBOL,
  _NAV,
  _DEV,
  _TESTS
};

// Fancy zones keycodes
#define FZ_EXT G(S(KC_UP))
#define FZ_LFT G(KC_LEFT)
#define FZ_RGT G(KC_RIGHT)

// Word navigation and selection keycodes
#define WO_LFT C(KC_LEFT)
#define WO_RGT C(KC_RIGHT)
#define WO_SLF C(S(KC_LEFT))
#define WO_SRG C(S(KC_RIGHT))
#define WO_SDW S(KC_DOWN)
#define WO_SUP S(KC_UP)

// Windows management keycodes
#define WD_CLO C(KC_F4)
#define WI_CLO A(KC_F4)
// #define WD_CYC C(KC_TAB)
// #define WD_RCY C(S(KC_TAB))
// #define WI_CYC A(KC_TAB)
// #define WI_RCY A(KC_TAB)

// Shorthand macros
#define TAP(x) tap_code16(x)
#define ___ KC_NO

enum custom_keycodes {
  DV_ARR = SAFE_RANGE
};

enum combo_events {
  EM_EMAIL,
  BSPC_LSFT_CLEAR,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; 

const uint16_t PROGMEM email_combo[] = {KC_E, KC_M, COMBO_END};
const uint16_t PROGMEM clear_line_combo[] = {KC_BSPC, KC_LSFT, COMBO_END};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_ortho_4x12(
    QK_GESC, KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,  KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
    KC_LCTL, KC_LGUI, KC_LALT, MO(4), MO(1), LT(5,KC_SPC), KC_SPC, MO(2), MO(3),   KC_LALT, KC_LGUI, KC_LCTL
  ),
  [_NUMBER] = LAYOUT_ortho_4x12(
    ___,   KC_F1, KC_F2,  KC_F3,  KC_F4,  ___, ___, KC_7, KC_8, KC_9,   ___, KC_BSPC,
    ___,   KC_F5, KC_F6,  KC_F7,  KC_F8,  ___, ___, KC_4, KC_5, KC_6,   ___, ___,
    ___,   KC_F9, KC_F10, KC_F11, KC_F12, ___, ___, KC_1, KC_2, KC_3,   ___, KC_RSFT,
    KC_WAKE, ___, ___,  ___,  ___,  ___, ___, KC_0, KC_0, KC_DOT, ___, KC_RCTL
  ),
  [_SYMBOL] = LAYOUT_ortho_4x12(
    KC_GRV, S(KC_1),     S(KC_2), S(KC_3),     S(KC_4),     S(KC_5),  ___,       DV_ARR,   ___,      ___,   ___,    KC_DELETE,
    ___,  S(KC_SLASH), ___,   KC_MINUS,    KC_EQUAL,    S(KC_8),  S(KC_COMMA), S(KC_9), S(KC_LBRC), KC_LBRC, KC_SLASH, S(KC_7),
    ___,  S(KC_6),     ___,   S(KC_MINUS), S(KC_EQUAL), KC_SLASH, S(KC_DOT),   S(KC_0), S(KC_RBRC), KC_RBRC, KC_BSLS,  S(KC_BSLS),
    ___,  ___,       ___,   ___,       ___,       ___,    ___,       ___,   ___,      ___,   ___,    ___
  ),
  [_NAV] = LAYOUT_ortho_4x12(
    ___, FZ_EXT, FZ_LFT, FZ_RGT, WD_CLO,  WI_CLO,   ___, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  KC_BTN1,
    ___, ___, ___, ___, ___, ___, ___, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_WH_U,
    ___, ___,  ___,  ___, ___, ___,   ___, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_WH_D,
    ___, ___,  ___,  ___,  ___,  ___,   ___, ___,   ___,   KC_LALT, KC_LGUI,  KC_LCTL
  ),
  [_DEV] = LAYOUT_ortho_4x12(
    C(KC_GRV),  C(S(KC_GRV)), C(KC_PGDN), ___, ___, ___, ___, ___,     ___, ___, ___, ___,
    C(S(KC_B)), KC_F9, KC_F10, KC_F11, S(KC_F11), KC_F5, ___, WO_LFT, WO_SLF,  WO_SUP,  ___,     ___,
    ___,      ___, ___, ___, ___, C(KC_F12), ___, WO_RGT,     WO_SRG,  WO_SDW,  ___,     ___,
    ___,      ___, ___, ___, ___, ___, ___, ___,     ___,  ___,  ___,     ___
  ),
  [_TESTS] = LAYOUT_ortho_4x12(
    DT_PRNT,  RGB_TOG,  RGB_VAI, RGB_HUI, ___,  ___, ___, ___, ___, ___, ___, ___,
    DT_UP,   RGB_MOD,  RGB_VAD, RGB_HUD, ___,  ___, KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, ___,
    DT_DOWN, RGB_RMOD, RGB_SPI, RGB_SAI, ___,  ___, ___, ___, ___, ___, ___, ___,
    ___, ___,    RGB_SPD, RGB_SAD, ___,  ___, ___, ___, ___, ___, ___, ___
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case DV_ARR:
        SEND_STRING("=>");
        break;
    }
  }

  return true;
};

combo_t key_combos[] = {
  [EM_EMAIL] = COMBO_ACTION(email_combo),
  [BSPC_LSFT_CLEAR] = COMBO_ACTION(clear_line_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  if (!pressed) {
    return;
  }

  switch(combo_index) {
    case EM_EMAIL:
      SEND_STRING("pablo.ontiveros@gmail.com");
      break;
    case BSPC_LSFT_CLEAR:
      TAP(KC_END);
      TAP(S(KC_HOME));
      TAP(KC_BSPC);
      break;
  }
}
