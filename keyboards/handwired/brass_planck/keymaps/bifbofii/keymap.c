/* Personal Planck Layout of BifbofII
 */

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

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
  RAISE,
  LOWER,
  FUNCTIONS,
  UNICODE,
  SPECIALS,
};

#define L_LOW  MO(LOWER)
#define L_RAIS MO(RAISE)
#define L_FNC  MO(FUNCTIONS)
#define L_SPEC MO(SPECIALS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * | Tab |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | Bsp |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * | Esc |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |Shift|  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Ret |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |Ctrl |Super|     | Alt |Lower| Spc | Spc |Raise| Alt |Super|Ctrl |Spec |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 */
[QWERTY] = LAYOUT_planck_grid(
    KC_TAB,              KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                  KC_Y,                  KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LT(UNICODE, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                  KC_H,                  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                  KC_N,                  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
    KC_LCTL,             KC_LGUI, XXXXXXX, KC_LALT, L_LOW,   LT(FUNCTIONS, KC_SPC), LT(FUNCTIONS, KC_SPC), L_RAIS,  KC_RALT, KC_RGUI, KC_RCTL, L_SPEC
),

/* Raise
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | Bsp |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |     |     |     |     |     |     |  -  |  =  |  [  |  ]  |  \  |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 */
[RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Lower
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |  ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  | Bsp |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |     |     |     |     |     |     |  _  |  +  |  {  |  }  |  |  |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 */
[LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Functions Layer 1
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |     |     |     |     |     |Prev |Vol- |Vol+ |Next |Play | Del |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |Caps |     |     |     |     |     |Left |Down | Up  |Right|     |     |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |     |     |     |     |     |     |Mute |     |     |     |Fnc2 |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 */
[FUNCTIONS] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, KC__MUTE, KC_MPRV, KC__VOLDOWN, KC_VOLU, KC_MNXT, KC_MEDIA_PLAY_PAUSE, KC_DEL,
    KC_CAPS, _______, _______, _______, _______, _______,  KC_LEFT, KC_DOWN,     KC_UP,   KC_RGHT, _______,             _______,
    _______, _______, _______, _______, _______, _______,  KC_HOME, KC_PGDN,     KC_PGUP, KC_END,  _______,             _______,
    _______, _______, _______, _______, _______, _______,  _______, _______,     _______, _______, _______,             _______
),

/* Unicode Layer
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |     |     |  €  |     |     |     |  Ü  |     |  Ö  |     |     |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |  Ä  |  ß  |     |     |     |     |     |     |     |     |     |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |     |     |  ©  |     |     |     |     |     |     |     |     |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 */
[UNICODE] = LAYOUT_planck_grid(
    _______, _______,      _______, X(EUR),  _______, _______, _______, XP(SUE, BUE), _______, XP(SOE, BOE), _______, _______,
    _______, XP(SAE, BAE), X(SS),   _______, _______, _______, _______, _______,      _______, _______,      _______, _______,
    _______, _______,      _______, X(CPR),  _______, _______, _______, _______,      _______, _______,      _______, _______,
    _______, _______,      _______, _______, _______, _______, _______, _______,      _______, _______,      _______, _______
),

/* Specials Layer
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * | XXX | XXX | Win | XXX | XXX | XXX | XXX | XXX | XXX | OSX | XXX | XXX |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | Lnx | XXX | XXX |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * | XXX | XXX | XXX | XXX | XXX |RESET| XXX | XXX | XXX | XXX | XXX | XXX |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX | XXX |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 */
[SPECIALS] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, UC_M_WC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UC_M_OS, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UC_M_LN, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};
