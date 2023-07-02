/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

// Fancy zones keycodes
#define FZ_EXT G(S(KC_UP)) // Expand window vertically
#define FZ_LFT G(KC_LEFT) // Move window to previous area
#define FZ_RGT G(KC_RIGHT) // Move window to next area
#define VD_NXT G(C(KC_LEFT)) // Move window to previous area
#define VD_PRV G(C(KC_RIGHT)) // Move window to next area

// Word navigation and selection keycodes
#define C_LFT C(KC_LEFT) // Move to previous word
#define C_RGT C(KC_RIGHT) // Move to next word
#define C_UP C(KC_HOME)
#define C_DWN C(KC_END)
#define CS_LFT C(S(KC_LEFT)) // Select previous word
#define CS_RGT C(S(KC_RIGHT)) // Select next word
#define CS_UP C(S(KC_UP))
#define CS_DWN C(S(KC_DOWN))
#define S_PGUP S(KC_PGUP)
#define S_PGDW S(KC_PGDN)
#define LN_UP A(KC_UP) // Move line up
#define LN_DN A(KC_DOWN) // Move line down

// Windows management keycodes
#define WD_CLO C(KC_F4) // Close document or tab
#define WI_CLO A(KC_F4) // Close window

// Shorthand macros and keycodes
#define DV_TRM C(KC_GRV) // VS Code terminal
#define DV_NTRM C(S(KC_GRV)) // VS Code new terminal
#define DV_CTRM C(KC_PGDN) // VS Code cycle terminal
#define DV_BLD C(S(KC_B)) // VS build
#define DV_BRKP KC_F9 // VS breakpoint
#define DV_SOUT S(KC_F11) // VS Step Out
#define DV_SIN KC_F11 // VS Step Into
#define DV_SOVR KC_F10 // VS Step Over
#define DV_IMPL C(KC_F12) // VS Go to Implementation
#define DV_NXER C(S(KC_F12)) // VS Next error
#define DV_NVFW C(S(KC_MINUS)) // VS Navigate forward
#define DV_NVBW C(KC_MINUS) // VS Navigate backwards
#define CS_P C(S(KC_P))
#define CS_V C(S(KC_V))
#define CS_F C(S(KC_F))
#define CS_S C(S(KC_S))

enum layer_names {
  _QWERTY,
  _NUMBER,
  _SYMBOL,
  _DEV,
  _UTIL,
};

#define L_TAB_N LT(1, KC_TAB)
#define L_ESC_S LT(2, KC_ESCAPE)
#define L_SPC_D LT(3, KC_SPACE)
#define L_ENT_U LT(4, KC_ENTER)

enum custom_keycodes {
  DV_ARR = SAFE_RANGE, // Print C# lambda arrow
  DV_CMNT, // Comment line
  DV_UNCMT, // Uncomment line
  DV_SELLN, // Select line
  DV_REFS,  // Find references
  WI_MAX,  // Maximize window
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, L_TAB_N, L_SPC_D,    L_ENT_U, L_ESC_S, KC_LALT
                                      //`--------------------------'  `--------------------------'

  ),

    [_NUMBER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                      XXXXXXX,    KC_7,    KC_8,    KC_9,KC_EQUAL,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,                      KC_ASTR,    KC_4,    KC_5,    KC_6,  KC_DOT, KC_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                     KC_SLASH,    KC_1,    KC_2,    KC_3,    KC_0,KC_MINUS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,  KC_GRV,   KC_LT,   KC_GT, XXXXXXX, XXXXXXX,                      XXXXXXX,  DV_ARR, KC_LBRC, KC_RBRC, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM,KC_MINUS, KC_PLUS,KC_EQUAL,KC_TILDE,                      KC_AMPR,   KC_AT, KC_LPRN, KC_RPRN, KC_HASH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_QUES,KC_SLASH, KC_ASTR, XXXXXXX, KC_CIRC,                      KC_PIPE,  KC_DLR, KC_LCBR, KC_RCBR, KC_PERC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_DEV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  DV_TRM, DV_NTRM, DV_CTRM, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, DV_BRKP, DV_SOUT,  DV_SIN, DV_SOVR,  DV_BLD,                      XXXXXXX, KC_LEFT,   KC_UP, KC_DOWN,KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, DV_NXER, XXXXXXX, DV_REFS, DV_IMPL,   KC_F5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_UTIL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, DT_PRNT,  AS_RPT, AS_TOGG, RGB_SPI, RGB_SPD,                       WI_CLO,  WD_CLO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   DT_UP,   AS_UP, CW_TOGG, RGB_MOD,RGB_RMOD,                      XXXXXXX,  FZ_EXT,  FZ_LFT,  FZ_RGT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, DT_DOWN, AS_DOWN, RGB_TOG, RGB_VAI, RGB_VAD,                      KC_MPLY, KC_MPRV, KC_VOLU, KC_VOLD, KC_MNXT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case DV_CMNT:
        SEND_STRING(SS_LCTL("kc"));
        break;
      case DV_UNCMT:
        SEND_STRING(SS_LCTL("ku"));
        break;
      case DV_REFS:
        SEND_STRING(SS_LCTL("kr"));
        break;
      case DV_SELLN:
        tap_code16(KC_HOME);
        tap_code16(KC_HOME);
        tap_code16(S(KC_END));
        break;
      case WI_MAX:
        tap_code16(A(KC_SPC));
        tap_code16(S(KC_X));
        break;
    }
  }

  return true;
};

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case DV_ARR:
      return true;
    default:
      return false;
  }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch(keycode) {
    case KC_DOT:
      (shifted) ? tap_code16(KC_UNDS) : tap_code16(KC_DOT);
      break;
    case KC_SLSH:
      (shifted) ? tap_code16(KC_BSLS) : tap_code16(KC_SLSH);
      break;
    case KC_COMM:
      (shifted) ? tap_code16(KC_MINUS) : SEND_STRING(", ");
      break;
    case DV_ARR:
      (shifted) ? SEND_STRING("/>") : SEND_STRING("=>");
      break;
    case KC_GRV:
      (shifted) ? SEND_STRING("``` ") : tap_code16(KC_GRV);
      break;
    default:
      if (shifted) {
        add_weak_mods(MOD_BIT(KC_LSFT));
      }
      // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
      register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch(keycode) {
    case KC_DOT:
    case KC_SLSH:
    case KC_COMM:
    case DV_ARR:
    case KC_GRV:
      break;
    default:
      // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
      // The IS_RETRO check isn't really necessary here, always using
      // keycode & 0xFF would be fine.
      unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
  }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(corne_logo, false);
    oled_write_P(PSTR("corne"), false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_DEV)) {
        oled_write_P(adjust_layer, false);
    } else if(layer_state_is(_NUMBER)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_SYMBOL)) {
        oled_write_P(raise_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

bool oled_task_user(void) {
    // Renders the current keyboard state (layers and mods)
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    return false;
}

#endif
