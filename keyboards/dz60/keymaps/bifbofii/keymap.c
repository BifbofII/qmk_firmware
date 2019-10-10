#include QMK_KEYBOARD_H

// ====== Unicode ======
// Character names
enum unicode_names {
  SAE,
  BAE,
  SUE,
  BUE,
  SOE,
  BOE,
  SS,
  EUR,
  CPR
};

// Unicode map
const uint32_t PROGMEM unicode_map[] = {
  [SAE] = 0x00E4, // ä
  [BAE] = 0x00C4, // Ä
  [SUE] = 0x00FC, // ü
  [BUE] = 0x00DC, // Ü
  [SOE] = 0x00F6, // ü
  [BOE] = 0x00D6, // Ü
  [SS]  = 0x00DF, // ß
  [EUR] = 0x20AC, // €
  [CPR] = 0x00A9  // ©
};

// ====== Layers ======
// Layer numbers
enum layer_names {
  QWERTY = 0,
  GAMING,
  FUNCTIONS_1,
  FUNCTIONS_2,
  UNICODE,
  SPECIALS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Enter |
   * |-----------------------------------------------------------------------------------+     +
   * | Esc/Unic|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    \  |     |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |      RShift     |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl | Super |  Alt  |              Space/Fnc            |  Alt  | Super |  Ctrl | Spec |
   * `-----------------------------------------------------------------------------------------'
   */
	[QWERTY] = LAYOUT_60_iso_5x1u(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,
      LT(UNICODE, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
      KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
      KC_LCTL, KC_LGUI, KC_LALT, LT(FUNCTIONS_1, KC_SPC), KC_RALT, KC_RGUI, KC_RGUI, KC_RCTL, MO(SPECIALS)),

  /* Arrows and media keys
   * ,-----------------------------------------------------------------------------------------.
   * |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |    Del    |
   * |-----------------------------------------------------------------------------------------+
   * |        |     |     |     |     |     | Prev| V-  | V+  | Next| Play|     |     |  Enter |
   * |-----------------------------------------------------------------------------------+     +
   * | Caps    |     |  <  |     |     |  >  |  R  |  D  |  U  |  L  |     |     |       |     |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |     |     |     |     |     |     | Mute|     |     |     |         Fnc2    |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl | Super |  Alt  |             Trans                 |  Alt  | Super |  Ctrl |      |
   * `-----------------------------------------------------------------------------------------'
   */
	[FUNCTIONS_1] = LAYOUT_60_iso_5x1u(KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC__VOLDOWN, KC_VOLU, KC_MNXT, KC_MEDIA_PLAY_PAUSE, KC_NO, KC_NO,
      KC_CAPS, KC_NO, KC_WBAK, KC_NO, KC_NO, KC_WFWD, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_ENT,
      KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC__MUTE, KC_NO, KC_NO, KC_NO, MO(FUNCTIONS_2),
      KC_LCTL, KC_LGUI, KC_LALT, KC_TRNS, KC_RALT, KC_RGUI, KC_RGUI, KC_RCTL, KC_NO),

  /* More Function keys
   * ,-----------------------------------------------------------------------------------------.
   * |     | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23 | F24 |    Del    |
   * |-----------------------------------------------------------------------------------------+
   * |        |     |     |     |     |     |     |     |     |     |     |     |     |  Enter |
   * |-----------------------------------------------------------------------------------+     +
   * | Caps    |     |     |     |     |     | Home|Page-|Page+| End |     |     |       |     |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |     |     |     |     |     |     |     |     |     |     |      Trans      |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl | Super |  Alt  |              Trans                |  Alt  | Super |  Ctrl |      |
   * `-----------------------------------------------------------------------------------------'
   */
	[FUNCTIONS_2] = LAYOUT_60_iso_5x1u(KC_NO, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, KC_DEL,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_NO, KC_NO, KC_ENT,
      KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
      KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_RALT, KC_RGUI, KC_RGUI, KC_RCTL, KC_NO),

  /* German Umlauts
   * ,-----------------------------------------------------------------------------------------.
   * |     |     |     |     |     |     |     |     |     |     |     |  ß  |     |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * |        |     |     |  €  |     |     |     |     |     |     |     |  Ü  |     |  Enter |
   * |-----------------------------------------------------------------------------------+     +
   * | Trans   |     |     |     |     |     |     |     |     |     |  Ö  |  Ä  |       |     |
   * |-----------------------------------------------------------------------------------------+
   * | Trans     |     |     |  ©  |     |     |     |     |     |     |     |      Trans      |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl | Super |  Alt  |              Space                |  Alt  | Super |  Ctrl |      |
   * `-----------------------------------------------------------------------------------------'
   */
	[UNICODE] = LAYOUT_60_iso_5x1u(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, X(SS), KC_NO, KC_BSPC,
      KC_NO, KC_NO, KC_NO, X(EUR), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, XP(SUE, BUE), KC_NO,
      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, XP(SOE, BOE), XP(SAE, BAE), KC_NO, KC_ENT,
      KC_LSFT, KC_NO, KC_NO, KC_NO, X(CPR), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, KC_RGUI, KC_RCTL, KC_NO),

  /* Specials (Reset, etc)
   * ,-----------------------------------------------------------------------------------------.
   * |     |     |     |     |     |     |     |     |     |     |     | RGB-|RGB+ |           |
   * |-----------------------------------------------------------------------------------------+
   * |        |     | Win |     |     |     |     |     |     | OSX |     |     |     |  RGB   |
   * |-----------------------------------------------------------------------------------+ tog +
   * |         |     |     |     |     |Gamin|     |     |     | Lnx |     |     |       |     |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |RESET|     |     |     |     |     |                 |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |       |       |       | Trans|
   * `-----------------------------------------------------------------------------------------'
   */
	[SPECIALS] = LAYOUT_60_iso_5x1u(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_VAD, RGB_VAI, KC_NO,
      KC_NO, KC_NO, UC_M_WC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, UC_M_OS, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(GAMING), KC_NO, KC_NO, KC_NO, UC_M_LN, KC_NO, KC_NO, KC_NO, RGB_TOG,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS),

  /* Gaming
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Enter |
   * |-----------------------------------------------------------------------------------+     +
   * | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    \  |     |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |      RShift     |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl | Super |  Alt  |              Space                |  Alt  | Super |  Ctrl | Spec |
   * `-----------------------------------------------------------------------------------------'
   */
	[GAMING] = LAYOUT_60_iso_5x1u(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,
      KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
      KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, KC_RGUI, KC_RCTL, MO(SPECIALS)),
};

// ====== LED Underglow ======
// Caps lock as underglow
void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    rgblight_mode(1);
    rgblight_sethsv(0, 255, rgblight_get_val());
  } else {
    rgblight_mode(1);
    rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val());
  }
}
// Gaming layer as underglow
uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case GAMING:
      rgblight_mode(1);
      rgblight_sethsv(170, 255, rgblight_get_val());
      break;
    default:
      rgblight_mode(1);
      rgblight_sethsv(rgblight_get_hue(), 0, rgblight_get_val());
      break;
  }
  return state;
}
