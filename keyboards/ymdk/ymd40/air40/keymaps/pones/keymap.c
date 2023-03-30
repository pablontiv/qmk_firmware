#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _NUMBER,
  _SYMBOL,
  _NAV,
  _DEV,
  _TESTS,
  _GAME
};

// Fancy zones keycodes
#define FZ_EXT G(S(KC_UP)) // Expand window vertically
#define FZ_LFT G(KC_LEFT) // Move window to previous area
#define FZ_RGT G(KC_RIGHT) // Move window to next area

// Word navigation and selection keycodes
#define WO_LFT C(KC_LEFT) // Move to previous word
#define WO_RGT C(KC_RIGHT) // Move to next word
#define WO_SLF C(S(KC_LEFT)) // Select previous word
#define WO_SRG C(S(KC_RIGHT)) // Select next word
#define WO_SDW S(KC_DOWN) // Select previous line
#define WO_SUP S(KC_UP) // Select next line
#define LN_UP A(KC_UP) // Move line up
#define LN_DN A(KC_DOWN) // Move line down

// Windows management keycodes
#define WD_CLO C(KC_F4) // Close document or tab
#define WI_CLO A(KC_F4) // Close window

// Shorthand macros and keycodes
#define TAP(x) tap_code16(x)
#define SPC_TE LT(5,KC_SPC) // Space on tap Test layer on hold
#define DV_TRM C(KC_GRV) // VS Code terminal
#define DV_NTRM C(S(KC_GRV)) // VS Code new terminal
#define DV_CTRM C(KC_PGDN) // VS Code cycle terminal
#define DV_BLD C(S(KC_B)) // VS build
#define DV_BRKP KC_F9 // VS breakpoint
#define DV_SOUT S(KC_F11) // VS Step Out
#define DV_SIN KC_F11 // VS Step Into
#define DV_SOVR KC_F10 // VS Step Over
#define DV_GIMP C(KC_F12) // VS Go to Implementation
#define SY_EXCL S(KC_1) // Exclamation mark
#define SY_ARB S(KC_2) // Arobase
#define SY_NUM S(KC_3) // Number
#define SY_CRCY S(KC_4) // Currency
#define SY_PERC S(KC_5) // Percent
#define SY_CRT S(KC_6) // Caret
#define SY_AMP S(KC_7) // Ampersand
#define SY_ASTK S(KC_8) // Asterisk
#define SY_QSTN S(KC_SLASH) // Question mark
#define SY_LPRN S(KC_9) // Left parenthesis
#define SY_RPRN S(KC_0) // Right parenthesis
#define SY_UND S(KC_MINUS) // Underscore
#define SY_PLS S(KC_EQUAL) // Plus
#define SY_LCRY S(KC_LBRC) // Left curly braces
#define SY_RCRY S(KC_RBRC) // Right curly braces
#define SY_PIP S(KC_BSLS) // Pipe
#define SY_GRT S(KC_DOT) // Greater than
#define SY_LST S(KC_COMMA) // Less than

enum custom_keycodes {
  DV_ARR = SAFE_RANGE, // Print C# lambda arrow
  DV_COMM, // Comment line
  DV_UNCOM // Uncomment line
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
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Dev  |Number|    Space    |Symbol| Nav  | Alt  | GUI  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_ortho_4x12(
    QK_GESC,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_TAB,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SC_SENT,
    KC_LCTL,  KC_LGUI,  KC_LALT,  MO(4),    TT(1),    SPC_TE,   KC_SPC,   MO(2),    TT(3),    KC_LALT,  KC_LGUI,  KC_LCTL
  ),
  [_NUMBER] = LAYOUT_ortho_4x12(
    TO(0),    KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX,  XXXXXXX,  KC_7,     KC_8,     KC_9,     KC_EQUAL, KC_BSPC,
    XXXXXXX,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX,  XXXXXXX,  KC_4,     KC_5,     KC_6,     SY_PLS,   KC_MINUS,
    XXXXXXX,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,  XXXXXXX,  KC_1,     KC_2,     KC_3,     SY_ASTK,  KC_SLASH,
    KC_WAKE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_0,     KC_0,     KC_DOT,   KC_ENT,   XXXXXXX
  ),
  [_SYMBOL] = LAYOUT_ortho_4x12(
    KC_GRV,   SY_EXCL,  SY_ARB,  SY_NUM,    SY_CRCY,  SY_PERC,  XXXXXXX,  DV_ARR,   XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DEL,
    XXXXXXX,  SY_QSTN,  XXXXXXX,  KC_MINUS, KC_EQUAL, SY_ASTK,  SY_LST,   SY_LPRN,  SY_LCRY,  KC_LBRC,  KC_SLASH, SY_AMP,
    XXXXXXX,  SY_CRT,   XXXXXXX,  SY_UND,   SY_PLS,   KC_SLASH, SY_GRT,   SY_RPRN,  SY_RCRY,  KC_RBRC,  KC_BSLS,  SY_PIP,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),
  [_NAV] = LAYOUT_ortho_4x12(
    TO(0),    XXXXXXX,  XXXXXXX,  XXXXXXX,  WD_CLO,   WI_CLO,   XXXXXXX,  KC_HOME,  KC_PGUP,  KC_PGDN,  KC_END,   FZ_EXT,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  LN_UP,    KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT, FZ_LFT,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  LN_DN,    WO_LFT,   WO_SLF,   WO_SRG,   WO_RGT,   FZ_RGT,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_SPC,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),
  [_DEV] = LAYOUT_ortho_4x12(
    DV_TRM,  DV_NTRM, DV_CTRM, XXXXXXX,      XXXXXXX,     XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    DV_BLD,  DV_BRKP, DV_SOUT, DV_SIN,   DV_SOVR, KC_F5, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,     DV_GIMP,     XXXXXXX, DV_UNCOM, DV_COMM, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,      XXXXXXX,     XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_TESTS] = LAYOUT_ortho_4x12(
    AS_RPT,  RGB_TOG,  RGB_VAI, RGB_HUI, XXXXXXX,  XXXXXXX, XXXXXXX,     KC_BTN1, KC_WH_U, KC_WH_D, XXXXXXX,     TO(6),
    AS_UP,   RGB_MOD,  RGB_VAD, RGB_HUD, XXXXXXX,  XXXXXXX, XXXXXXX,     KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, XXXXXXX,
    AS_DOWN, RGB_RMOD, RGB_SPI, RGB_SAI, XXXXXXX,  XXXXXXX, KC_MPLY, KC_MPRV, KC_VOLU, KC_VOLD, KC_MNXT, XXXXXXX,
    AS_TOGG,     XXXXXXX,      RGB_SPD, RGB_SAD, XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX
  ),
  [_GAME] = LAYOUT_ortho_4x12(
    QK_GESC,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     TO(0),
    KC_TAB,   KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  SC_SENT,
    KC_LCTL,  KC_LGUI,  KC_LALT,  XXXXXXX,   XXXXXXX,   KC_SPC,  KC_SPC,  XXXXXXX,   XXXXXXX,   KC_LALT, KC_LGUI,  KC_LCTL
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case DV_ARR:
        SEND_STRING("=>");
        break;
      case DV_COMM:
        SEND_STRING(SS_DOWN(X_LCTL) "kc" SS_UP(X_LCTL));
        break;
      case DV_UNCOM:
        SEND_STRING(SS_DOWN(X_LCTL) "ku" SS_UP(X_LCTL));
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
