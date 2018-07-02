#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// TT(...)
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 3

// Layers.
#define LAY0 0 // ASCII and programming.
#define LAY1 1 // Like LAY0 but with uppercase letters.
#define LAY2 2 // Letters and accents of latin european languages.
#define LAY3 3 // Letters of LAY2 in uppercase.
#define LAY4 4 // Media keys, Fn keys, mouse, keypad.
#define LAY5 5 // Like LAY4, for TG() purposes.

// us altgr-intl keycodes
#define UAI_STAR S(KC_8) // *
#define UAI_DQUO S(KC_QUOT) /* " */
#define UAI_COLO S(KC_SCLN) // :
#define UAI_LANG S(KC_COMMA) // <
#define UAI_RANG S(KC_DOT) // >
#define UAI_LCRB S(KC_LBRACKET) // {
#define UAI_RCRB S(KC_RBRACKET) // }
#define UAI_LGUIL RALT(KC_LBRACKET) // «
#define UAI_RGUIL RALT(KC_RBRACKET) // »
#define UAI_LDQUO RALT(S(KC_LBRACKET)) // “
#define UAI_RDQUO RALT(S(KC_RBRACKET)) // ”
#define UAI_LQUO RALT(KC_9) // ‘
#define UAI_RQUO RALT(KC_0) // ’
#define UAI_LPAR S(KC_9) // (
#define UAI_RPAR S(KC_0) // )
#define UAI_QUES S(KC_SLSH) // ?
#define UAI_CAROT S(KC_6) // ^
#define UAI_VERTB S(KC_BSLS) // |
#define UAI_AT S(KC_2) // @
#define UAI_RBANG S(KC_1) // !
#define UAI_AMP S(KC_7) // &
#define UAI_DOLLAR S(KC_4) // $
#define UAI_EURO RALT(KC_5) // €
#define UAI_PERC S(KC_5) // %
#define UAI_USCOR S(KC_MINUS) // _
#define UAI_PLUS S(KC_EQL) // +
#define UAI_TILDE S(KC_GRV) // ~
#define UAI_HASH S(KC_3) // #
#define UAI_A_ACUTE RALT(KC_A) // á
#define UAI_E_ACUTE RALT(KC_E) // é
#define UAI_I_ACUTE RALT(KC_I) // í
#define UAI_O_ACUTE RALT(KC_O) // ó
#define UAI_U_ACUTE RALT(KC_U) // ú
#define UAI_O_SLASH RALT(KC_L) // ø
#define UAI_C_CEDILLA RALT(KC_COMMA) // ç
#define UAI_N_TILDE RALT(KC_N) // ñ
#define UAI_ESZET RALT(KC_S) // ß
#define UAI_OE RALT(KC_X) // œ
#define UAI_AE RALT(KC_Z) // æ
#define UAI_DEAD_ACUTE RALT(KC_QUOT) // ◌́ – acute
#define UAI_DEAD_UMLAUT S(RALT(KC_QUOT)) // ◌̈ – diaeresis or umlaut
#define UAI_DEAD_GRAVE RALT(KC_GRV) // ◌̀ – grave
#define UAI_DEAD_DACUTE S(RALT(KC_2)) // ◌̋ – double acute
#define UAI_DEAD_CAROT RALT(KC_6) // ◌̂ – circumflex
#define UAI_DEAD_CARON S(RALT(KC_DOT)) // ◌̌ – caron
#define UAI_DEAD_OVERDOT RALT(KC_DOT) // ◌̇ – overdot
#define UAI_DEAD_UNDERDOT S(RALT(KC_MINUS)) // ◌̣ – underdot
#define UAI_DEAD_BREVE S(RALT(KC_9)) // ◌̆ – breve
#define UAI_DEAD_TILDE S(RALT(KC_GRV)) // ◌̃ - tilde
#define UAI_DEAD_MACRON S(RALT(KC_3)) // ◌̄ – macron
#define UAI_DEAD_ORING S(RALT(KC_0)) // ◌̊ – overring
#define UAI_DEAD_OGONEK S(RALT(KC_8)) // ◌̨ – ogonek
#define UAI_DEAD_CEDILLA S(RALT(KC_5)) // ◌̧ – cedilla

// Right Control is our Compose Key.
#define SS_COMPOSE(string) SS_DOWN(X_RCTRL) string SS_UP(X_RCTRL)
#define SEND_COMPOSE(string) SEND_STRING(SS_COMPOSE(string))

enum my_keycodes {
    /* These keycodes get mapped to macros that emit Compose strings */
    MY_S_COMMA = SAFE_RANGE, // ș
    MY_S_COMMA_U,  // Ș
    MY_T_COMMA,    // ț
    MY_T_COMMA_U,  // Ț
    MY_Y_ACUTE,    // ý
    MY_Y_ACUTE_U,  // Ý
    MY_L_SLASH,    // ł
    MY_L_SLASH_U,  // Ł
    MY_A_ORING,    // å
    MY_A_ORING_U,  // Å
    MY_U_ORING,    // ů
    MY_U_ORING_U,  // Ů
    MY_A_TILDE,    // ã
    MY_A_TILDE_U,  // Ã
    MY_A_BREVE,    // ă
    MY_A_BREVE_U,  // Ă
    MY_ESZET_U,    // ẞ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0: ASCII and programming layer.
 *
 * Left:
 * ,--------------------------------------------------.
 * |      | |   &  |   *  |   -  |   @  |   ^  |   ~  |
 * |--------+------+------+------+------+-------------|
 * |      ( |   x  |   f  |   r  |   p  |   v  |   +  |
 * |--------+------+------+------+------+------|      |
 * | LAY4 , |   a  |   s  |   h  |   t  |   g  |------|
 * |--------+------+------+------+------+------|   #  |
 * | LCTL . |   q  |   z  |   :  |   m  |   k  |      |
 * `--------+------+------+------+------+-------------'
 *   | TAB  |      |      |TAB ` |   _  |
 *   `----------------------------------'
 * Right:
 * ,--------------------------------------------------.
 * |  [   |   ]  |   "" |   !  |   <  |  >   | =      |
 * |------+------+------+------+------+------+--------|
 * |  \   |   b  |   l  |   o  |   w  |  '   | )      |
 * |      |------+------+------+------+------+--------|
 * |------|   c  |   n  |   e  |   u  |  i   | y      |
 * |  %   |------+------+------+------+------+--------|
 * |      |   ?  |   d  |   {  |   }  |  j   | /      |
 * `-------------+------+------+------+------+--------'
 *               |  Esc |   $  |   €  |      |      |
 *               `----------------------------------'
 * Left:                        Right:
 *        ,-------------.       ,-------------.
 *        |      |      |       |      |        |
 * ,------|------|------|       |------+--------+------.
 * |      |      |      |       |PrtScr|        |      |
 * |------|------|------|       |------|--------|------|
 * | Space| LAY2 | Enter|       |      | LAY1   |Backsp|
 * `--------------------'       `----------------------'
 *
 * - '.' emits ';' if ',' is pressed as well.
 */
[LAY0] = LAYOUT_ergodox_80(
    // left hand
    UAI_VERTB,            UAI_AMP,   UAI_STAR,  KC_MINUS,                UAI_AT,                  UAI_CAROT, UAI_TILDE,
    UAI_LPAR,             KC_X,      KC_F,      KC_R,                    KC_P,                    KC_V,      UAI_PLUS,
    LT(LAY4, KC_COMMA),   KC_A,      KC_S,      KC_H,                    KC_T,                    KC_G,
    MT(MOD_LCTL, KC_DOT), KC_Q,      KC_Z,      UAI_COLO,                KC_M,                    KC_K,      UAI_HASH,
    KC_TAB,               KC_NO,     MY_S_COMMA,MT(MOD_LALT, KC_GRV),    UAI_USCOR,
    // left thumb
            KC_NO,   KC_NO,
    KC_NO,  KC_NO,   KC_NO,
    KC_SPC, MO(LAY2),KC_ENTER,

    // right hand
    KC_LBRACKET, KC_RBRACKET,  UAI_DQUO, UAI_RBANG, UAI_LANG, UAI_RANG, KC_EQL,
    KC_BSLS,     KC_B,         KC_L,     KC_O,      KC_W,     KC_QUOT,  UAI_RPAR,
                 KC_C,         KC_N,     KC_E,      KC_U,     KC_I,     KC_Y,
    UAI_PERC,    UAI_QUES,     KC_D,     UAI_LCRB,  UAI_RCRB, KC_J,     KC_SLSH,
                               KC_ESC,   UAI_DOLLAR,UAI_EURO, KC_NO,    KC_NO,
    // right thumb
    KC_NO,     KC_NO,
    KC_PSCR,   KC_NO,    KC_NO,
    KC_NO,     MO(LAY1), KC_BSPACE
    ),

/* Layer 1: Uppercase letters */
[LAY1] = LAYOUT_ergodox_80(
    // left hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, S(KC_F), S(KC_R), S(KC_P), S(KC_V), KC_TRNS,
    KC_TRNS, S(KC_A), S(KC_S), S(KC_H), S(KC_T), S(KC_G),
    KC_TRNS, S(KC_Q), S(KC_Z), KC_TRNS, S(KC_M), S(KC_K), KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // left thumb
              KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  MO(LAY3),  KC_TRNS,

    // right hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, S(KC_B), S(KC_L), S(KC_O), S(KC_W), S(KC_X), KC_TRNS,
             S(KC_C), S(KC_N), S(KC_E), S(KC_U), S(KC_I), KC_TRNS,
    KC_TRNS, KC_TRNS, S(KC_D), KC_TRNS, S(KC_J), S(KC_Y), KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // right thumb
    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS,  KC_TRNS
    ),

/* Layer 2: Letters and accents of latin european languages.
 *
 * Left:
 * ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |
 * |--------+------+------+------+------+-------------|
 * |        |   æ  |   ș  |   ◌̀  |   ț  |      |      |
 * |--------+------+------+------+------+------|      |
 * |     ă  |   á  |   ß  |   ◌̄  |  ◌̈   |   ◌́  |------|
 * |--------+------+------+------+------+------|      |
 * |     å  |   ã  |      |   ◌̋  |  ◌̂   |     |       |
 * `--------+------+------+------+------+-------------'
 *   |      |      |      |      |      |
 *   `----------------------------------'
 * Right:
 * ,--------------------------------------------------.
 * |      |      |      |      |      |      |        |
 * |------+------+------+------+------+------+--------|
 * |      |      |   ł  |   ó  |   ◌̌  |  œ   |        |
 * |      |------+------+------+------+------+--------|
 * |------|   ç  |   ñ  |   é  |   ú  |  í   |  ø     |
 * |      |------+------+------+------+------+--------|
 * |      |      |   ◌̨  |   ◌̇  |   ů  |  ý   |        |
 * `-------------+------+------+------+------+--------'
 *               |      |      |      |      |      |
 *               `----------------------------------'
 * Left:                        Right:
 *        ,-------------.       ,-------------.
 *        |      |      |       |      |        |
 * ,------|------|------|       |------+--------+------.
 * |      |      |      |       |      |        |      |
 * |------|------|------|       |------|--------|------|
 * |      |      |      |       |      | LAY3   |      |
 * `--------------------'       `----------------------'
 */
[LAY2] = LAYOUT_ergodox_80(
    // left hand
    KC_NO,      KC_NO,       KC_NO,      KC_NO,           KC_NO,           KC_NO,          KC_NO,
    KC_NO,      UAI_AE,      MY_S_COMMA, UAI_DEAD_GRAVE,  MY_T_COMMA,      KC_NO,          KC_NO,
    MY_A_BREVE, UAI_A_ACUTE, UAI_ESZET,  UAI_DEAD_MACRON, UAI_DEAD_UMLAUT, UAI_DEAD_ACUTE,
    MY_A_ORING, MY_A_TILDE,  KC_NO,      UAI_DEAD_DACUTE, UAI_DEAD_CAROT,  KC_NO,          KC_NO,
    KC_NO,      KC_NO,       KC_NO,      KC_NO,           KC_NO,
    // left thumb
           KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO,

    // right hand
    KC_NO, KC_NO,         KC_NO,           KC_NO,            KC_NO,          KC_NO,       KC_NO,
    KC_NO, KC_NO,         MY_L_SLASH,      UAI_O_ACUTE,      UAI_DEAD_CARON, UAI_OE,      KC_NO,
           UAI_C_CEDILLA, UAI_N_TILDE,     UAI_E_ACUTE,      UAI_U_ACUTE,    UAI_I_ACUTE, UAI_O_SLASH,
    KC_NO, KC_NO,         UAI_DEAD_OGONEK, UAI_DEAD_OVERDOT, MY_U_ORING,     MY_Y_ACUTE,  KC_NO,
                          KC_NO,           KC_NO,            KC_NO,          KC_NO,       KC_NO,
    // right thumb
    KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO,
    KC_NO, MO(LAY3), KC_NO
    ),

/* Layer 3: Letters of LAY2 in uppercase. */
[LAY3] = LAYOUT_ergodox_80(
    // left hand
    KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS,
    KC_TRNS,      S(UAI_AE),      MY_S_COMMA_U, KC_TRNS,MY_T_COMMA_U,  KC_TRNS, KC_TRNS,
    MY_A_BREVE_U, S(UAI_A_ACUTE), MY_ESZET_U,   KC_TRNS,KC_TRNS,       KC_TRNS,
    MY_A_ORING_U, MY_A_TILDE_U,   KC_TRNS,      KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS,
    KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,KC_TRNS,
    // left thumb
             KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,

    // right hand
    KC_TRNS, KC_TRNS,          KC_TRNS,        KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS, KC_TRNS,          MY_L_SLASH_U,   S(UAI_O_ACUTE),   KC_TRNS,        S(UAI_OE),      KC_TRNS,
             S(UAI_C_CEDILLA), S(UAI_N_TILDE), S(UAI_E_ACUTE),   S(UAI_U_ACUTE), S(UAI_I_ACUTE), S(UAI_O_SLASH),
    KC_TRNS, KC_TRNS,          KC_TRNS,        KC_TRNS,          MY_U_ORING_U,   MY_Y_ACUTE_U,   KC_TRNS,
                               KC_TRNS,        KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_TRNS,
    // right thumb
    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Layer 4: Media keys, Fn keys, mouse, keypad.
 *
 * Left hand:
 * ,--------------------------------------------------.
 * |    F1  |   F2 |  F3  |  F4  |   F5 |  F6  |  F7  |
 * |--------+------+------+------+------+-------------|
 * |        |      | Btn2 | MsUp | Btn3 |      | PgUp |
 * |--------+------+------+------+------+------|      |
 * |   Prev | Btn1 |MsLeft|MsDown|MsRght| WBack|------|
 * |--------+------+------+------+------+------| PgDn |
 * |   Next |  F8  |  F9  |  F10 |  F11 |  F12 |      |
 * `--------+------+------+------+------+-------------'
 *   | LAY0 | VMute| VolDn| VolUp| Play |
 *   `----------------------------------'
 * Right:
 * ,--------------------------------------------------.
 * |    a |   b  |   c  |   d  |   e  |  f   |  =     |
 * |------+------+------+------+------+------+--------|
 % |      |   %  |   7  |   8  |   9  |  (   |  )     |
 * |      |------+------+------+------+------+--------|
 * |------|   /  |   4  |   5  |   6  |  -   |        |
 * |      |------+------+------+------+------+--------|
 * |      |   *  |   1  |   2  |   3  |  +   |        |
 * `-------------+------+------+------+------+--------'
 *               |   0  |   .  |   ,  |      | Enter|
 *               `----------------------------------'
 * Left:                        Right:
 *        ,-------------.       ,-------------.
 *        |      |      |       |      |        |
 * ,------|------|------|       |------+--------+------.
 * |      |      |      |       |      |        |      |
 * |------|------|------|       |------|--------|------|
 * | Btn1 |      |      |       |      |        |      |
 * `--------------------'       `----------------------'
 */
[LAY4] = LAYOUT_ergodox_80(
    // left hand
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,
    TO(LAY5), KC_NO,   KC_BTN2, KC_MS_U, KC_BTN3, KC_NO,   KC_PGUP,
    KC_NO,   KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WBAK,
    KC_MUTE, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PGDN,
    KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
    // left thumb
             KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,
    KC_BTN1, KC_NO,   KC_NO,
    // right hand
    KC_A,  KC_B,     KC_C, KC_D,   KC_E,     KC_F,     KC_EQL,
    KC_NO, UAI_PERC, KC_7, KC_8,   KC_9,     UAI_LPAR, UAI_RPAR,
           KC_SLSH,  KC_4, KC_5,   KC_6,     KC_MINUS, KC_SCLN,
    KC_NO, UAI_STAR, KC_1, KC_2,   KC_3,     UAI_PLUS, KC_NO,
                     KC_0, KC_DOT, KC_COMMA, KC_NO,    KC_ENTER,
    // right thumb
    KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO
    ),

/* Layer 5: Like LAY4, for TG() purposes. */
[LAY5] = LAYOUT_ergodox_80(
    // left hand
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,
    KC_NO,   KC_NO,   KC_BTN2, KC_MS_U, KC_BTN3, KC_NO,   KC_PGUP,
    TO(LAY0),KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WBAK,
    KC_MUTE, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PGDN,
    KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
    // left thumb
             KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,
    KC_BTN1, KC_NO,   KC_NO,
    // right hand
    KC_A,  KC_B,     KC_C, KC_D,   KC_E,     KC_F,     KC_EQL,
    KC_NO, UAI_PERC, KC_7, KC_8,   KC_9,     UAI_LPAR, UAI_RPAR,
           KC_SLSH,  KC_4, KC_5,   KC_6,     KC_MINUS, KC_SCLN,
    KC_NO, UAI_STAR, KC_1, KC_2,   KC_3,     UAI_PLUS, KC_NO,
                     KC_0, KC_DOT, KC_COMMA, KC_NO,    KC_ENTER,
    // right thumb
    KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // On key down
        switch (keycode) {
        // Compose key stuff.
        case MY_S_COMMA:   SEND_COMPOSE(";s"); return false;
        case MY_S_COMMA_U: SEND_COMPOSE(";S"); return false;
        case MY_T_COMMA:   SEND_COMPOSE(";t"); return false;
        case MY_T_COMMA_U: SEND_COMPOSE(";T"); return false;
        case MY_Y_ACUTE:   SEND_COMPOSE("'y"); return false;
        case MY_Y_ACUTE_U: SEND_COMPOSE("'Y"); return false;
        case MY_L_SLASH:   SEND_COMPOSE("/l"); return false;
        case MY_L_SLASH_U: SEND_COMPOSE("/L"); return false;
        case MY_A_ORING:   SEND_COMPOSE("oa"); return false;
        case MY_A_ORING_U: SEND_COMPOSE("oA"); return false;
        case MY_U_ORING:   SEND_COMPOSE("ou"); return false;
        case MY_U_ORING_U: SEND_COMPOSE("oU"); return false;
        case MY_A_TILDE:   SEND_COMPOSE("~a"); return false;
        case MY_A_TILDE_U: SEND_COMPOSE("~A"); return false;
        case MY_A_BREVE:   SEND_COMPOSE("ba"); return false;
        case MY_A_BREVE_U: SEND_COMPOSE("bA"); return false;
        case MY_ESZET_U:   SEND_COMPOSE("SS"); return false;
        default: break;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case LAY1:
            ergodox_right_led_2_on();
            break;
        case LAY2:
            ergodox_right_led_3_on();
            break;
        case LAY3:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case LAY4:
            ergodox_right_led_1_on();
            break;
        case LAY5:
            ergodox_right_led_1_on();
            break;
        default:
            break;
    }

};
