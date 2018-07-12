#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// TT(...)
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 3

// Layers.
enum my_layers {
  LAY1, // ASCII and programming.
  LAY2, // Shift-like applied to LAY0
  LAY3, // AltGr-like applied to LAY0
  LAY4, // AltGr-Shift-like applied to LAY0
  LMED, // Media keys, Fn keys, mouse.
  LNUM  // Numeric keypad.
};

// us altgr-intl keycodes
enum keycodes_us_altgr_intl {
  // 0 - 9
  K0 = KC_0, K1 = KC_1, K2 = KC_2, K3 = KC_3, K4 = KC_4,
  K5 = KC_5, K6 = KC_6, K7 = KC_7, K8 = KC_8, K9 = KC_9,
  // a - z
  KA = KC_A, KB = KC_B, KC = KC_C, KD = KC_D, KE = KC_E, KF = KC_F,
  KG = KC_G, KH = KC_H, KI = KC_I, KJ = KC_J, KK = KC_K, KL = KC_L,
  KM = KC_M, KN = KC_N, KO = KC_O, KP = KC_P, KQ = KC_Q, KR = KC_R,
  KS = KC_S, KT = KC_T, KU = KC_U, KV = KC_V, KW = KC_W, KX = KC_X,
  KY = KC_Y, KZ = KC_Z,
  // A - Z
  KAU = S(KC_A), KBU = S(KC_B), KCU = S(KC_C), KDU = S(KC_D), KEU = S(KC_E), KFU = S(KC_F),
  KGU = S(KC_G), KHU = S(KC_H), KIU = S(KC_I), KJU = S(KC_J), KKU = S(KC_K), KLU = S(KC_L),
  KMU = S(KC_M), KNU = S(KC_N), KOU = S(KC_O), KPU = S(KC_P), KQU = S(KC_Q), KRU = S(KC_R),
  KSU = S(KC_S), KTU = S(KC_T), KUU = S(KC_U), KVU = S(KC_V), KWU = S(KC_W), KXU = S(KC_X),
  KYU = S(KC_Y), KZU = S(KC_Z),
  KSTAR = S(KC_8), // *
  KCOMMA = KC_COMMA, // ,
  KLBRK = KC_LBRACKET, // [
  KRBRK = KC_RBRACKET, // ]
  KQUOT = KC_QUOT, /* " */
  KDQUO = S(KC_QUOT), /* " */
  KCOLO = S(KC_SCLN), // :
  KSCOLO = KC_SCLN, // :
  KLANG = S(KC_COMMA), // <
  KEQL = KC_EQL, // =
  KRANG = S(KC_DOT), // >
  KLCRB = S(KC_LBRACKET), // {
  KRCRB = S(KC_RBRACKET), // }
  KLGUIL = RALT(KC_LBRACKET), // «
  KRGUIL = RALT(KC_RBRACKET), // »
  KLDQUO = RALT(S(KC_LBRACKET)), // “
  KRDQUO = RALT(S(KC_RBRACKET)), // ”
  KLQUO = RALT(KC_9), // ‘
  KRQUO = RALT(KC_0), // ’
  KLPAR = S(KC_9), // (
  KRPAR = S(KC_0), // )
  KSLSH = KC_SLSH, // /
  KLQUES = RALT(KC_SLSH), // ¿
  KRQUES = S(KC_SLSH), // ?
  KCAROT = S(KC_6), // ^
  KBSLS = KC_BSLS, // backslash
  KVERTB = S(KC_BSLS), // |
  KAT = S(KC_2), // @
  KLEXCL = RALT(S(KC_1)), // ¡
  KREXCL = S(KC_1), // !
  KAMP = S(KC_7), // &
  KDOLLAR = S(KC_4), // $
  KEURO = RALT(KC_5), // €
  KPERC = S(KC_5), // %
  KUSCOR = S(KC_MINUS), // _
  KPLUS = S(KC_EQL), // +
  KGRAVE = KC_GRV, // `
  KTILDE = S(KC_GRV), // ~
  KHASH = S(KC_3), // #
  KAACUTE = RALT(KC_A), // á
  KEACUTE = RALT(KC_E), // é
  KIACUTE = RALT(KC_I), // í
  KOACUTE = RALT(KC_O), // ó
  KUACUTE = RALT(KC_U), // ú
  KOSLASH = RALT(KC_L), // ø
  KCCEDILLA = RALT(KC_COMMA), // ç
  KNTILDE = RALT(KC_N), // ñ
  KAACUTEU = RALT(S(KC_A)), // á
  KEACUTEU = RALT(S(KC_E)), // é
  KIACUTEU = RALT(S(KC_I)), // í
  KOACUTEU = RALT(S(KC_O)), // ó
  KUACUTEU = RALT(S(KC_U)), // ú
  KOSLASHU = RALT(S(KC_L)), // ø
  KCCEDILLAU = RALT(S(KC_COMMA)), // ç
  KNTILDEU = RALT(S(KC_N)), // ñ
  KESZET = RALT(KC_S), // ß
  KOE = RALT(KC_X), // œ
  KOEU = RALT(S(KC_X)), // Œ
  KDOT = KC_DOT, // .
  KMINUS = KC_MINUS, // -
  KAE = RALT(KC_Z), // æ
  KAEU = RALT(S(KC_Z)), // Æ
  KDEADACUTE = RALT(KC_QUOT), // ◌́ – acute
  KDEADUMLAUT = S(RALT(KC_QUOT)), // ◌̈ – diaeresis or umlaut
  KDEADGRAVE = RALT(KC_GRV), // ◌̀ – grave
  KDEADDACUTE = S(RALT(KC_2)), // ◌̋ – double acute
  KDEADCAROT = RALT(KC_6), // ◌̂ – circumflex
  KDEADCARON = RALT(S(KC_DOT)), // ◌̌ – caron
  KPOUND = RALT(S(KC_4)), // £
  KDEADOVERDOT = RALT(KC_DOT), // ◌̇ – overdot
  KDEADUNDERDOT = S(RALT(KC_MINUS)), // ◌̣ – underdot
  KDEADBREVE = S(RALT(KC_9)), // ◌̆ – breve
  KDEADTILDE = S(RALT(KC_GRV)), // ◌̃ - tilde
  KDEADMACRON = S(RALT(KC_3)), // ◌̄ – macron
  KDEADORING = S(RALT(KC_0)), // ◌̊ – overring
  KDEADOGONEK = S(RALT(KC_8)), // ◌̨ – ogonek
  KDEADCEDILLA = S(RALT(KC_5)), // ◌̧ – cedilla
  KCOPYRIGHT = RALT(KC_C) // ©
};

// Right Control is our Compose Key.
#define SS_COMPOSE(string) SS_DOWN(X_RCTRL) string SS_UP(X_RCTRL)
#define SEND_COMPOSE(string) SEND_STRING(SS_COMPOSE(string))

enum my_keycodes {
    /* These keycodes get mapped to macros that emit Compose strings */
    KSCOMMA = SAFE_RANGE, // ș
    KSCOMMAU,  // Ș
    KTCOMMA,   // ț
    KTCOMMAU,  // Ț
    KYACUTE,   // ý
    KYACUTEU,  // Ý
    KLSLASH,   // ł
    KLSLASHU,  // Ł
    KAORING,   // å
    KAORINGU,  // Å
    KUORING,   // ů
    KUORINGU,  // Ů
    KATILDE,   // ã
    KATILDEU,  // Ã
    KABREVE,   // ă
    KABREVEU,  // Ă
    KESZETU,   // ẞ
    KBRDN,     // Screen brightness down
    KBRUP,     // Screen brightness UP

    // TODO
    KDEGREE = 0,
    KCOMPOSE = 0,
    KBITCOIN = 0,
    KFORALL= 0,
    KEXISTS = 0,
    KEMDASH = 0,
    KENDASH = 0,
    KELLIPSIS = 0,
    KLAMBDA = 0,
    KLAMBDAU = 0,
    KARROWUP = 0,
    KARROWDOWN = 0,
    KARROWLEFT = 0,
    KARROWRIGHT = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAY1] = LAYOUT_ergodox_80(
    // left hand
    0, KAMP, KSTAR, KMINUS, KHASH, KBSLS, KC_MUTE,
    KLPAR, KX, KF, KR, KP, KV, KC_VOLU,
    LT(LNUM, KCOMMA), KA, KS, KH, KT, KG,
    KDOT, KQ, KZ, KSCOLO, KM, KK, KC_VOLD,
    0, KC_LALT, 0, KC_LGUI, KC_LCTL,
    // left thumb
    KC_MPLY, KBRUP,
    KC_MPRV, KC_MNXT, KBRUP,
    KC_SPC, LT(LAY2, KC_LSFT), KC_ENTER,

    // right hand
    KLBRK, KRBRK, KDQUO, KQUOT, KLANG, KRANG, KEQL,
    TO(LMED), KB, KL, KO, KW, KUSCOR, KRPAR,
    KC, KN, KE, KU, KI, MT(MOD_RGUI, KY),
    TO(LNUM), KRQUES, KD, KC_UP, KCOLO, KJ, KSLSH,
    KC_LEFT, KC_DOWN, KC_RIGHT, KC_ESC, 0,
    // right thumb
    0, KCOMPOSE,
    KC_PSCR, KC_INSERT, KC_DELETE,
    KC_TAB, LT(LAY3, KC_RALT), KC_BSPC
    ),

[LAY2] = LAYOUT_ergodox_80(
    // left hand
    0, K1, K2, K3, K4, K5, 0,
    KLCRB, KXU, KFU, KRU, KPU, KVU, 0,
    KPLUS, KAU, KSU, KHU, KTU, KGU,
    KTILDE, KQU, KZU, 1, KMU, KKU, 0,
    0, 0, 0, 0, 0,
    // left thumb
    0, 0,
    0, 0, 0,
    S(KC_SPACE), 0, S(KC_ENTER),
    // right hand
    0, K6, K7, K8, K9, K0, 0,
    0, KBU, KLU, KOU, KWU, KCAROT, KRCRB,
    KCU, KNU, KEU, KUU, KIU, KYU,
    0, KREXCL, KDU, KC_PGUP, 0, KJU, KPERC,
    KC_HOME, KC_PGDN, KC_END, 0, 0,
    // right thumb
    0, 0,
    0, S(KC_INSERT), S(KC_DELETE),
    S(KC_TAB), MO(LAY4), S(KC_BSPC)
    ),

[LAY3] = LAYOUT_ergodox_80(
    // left hand
    0, KDEGREE, KLDQUO, KRDQUO, KAT, KENDASH, 0,
    KDOLLAR, KAE, KSCOMMA, KDEADGRAVE, KTCOMMA, 0, 0,
    KABREVE, KAACUTE, KESZET, KDEADMACRON, KDEADUMLAUT, KDEADACUTE,
    KAORING, KATILDE, 0, KDEADDACUTE, KDEADCAROT, 0, 0,
    0, 0, 0, 0, 0,
    // left thumb
    0, 0,
    0, 0, 0,
    RALT(KC_SPACE), MO(LAY4), RALT(KC_ENTER),
    // right hand
    0, 0, KFORALL, KGRAVE, KLGUIL, KRGUIL, 0,
    0, KLAMBDA, KLSLASH, KOACUTE, KDEADCARON, KOSLASH, KPOUND,
    KCCEDILLA, KNTILDE, KEACUTE, KUACUTE, KIACUTE, KYACUTE,
    0, KLQUES, KDEADOGONEK, KARROWUP, KUORING, KOE, KDEADOVERDOT,
    KARROWLEFT, KARROWDOWN, KARROWRIGHT, 0, 0,
    // right thumb
    0, 0,
    0, RALT(KC_INSERT), RALT(KC_DELETE),
    RALT(KC_TAB), 0, RALT(KC_BSPC)
    ),

[LAY4] = LAYOUT_ergodox_80(
    // left hand
    0, 0, 0, 0, 0, KEMDASH, 0,
    KEURO, KAEU, KSCOMMAU, KELLIPSIS, KTCOMMAU, 0, 0,
    KABREVEU, KAACUTEU, KESZETU, 0, 0, 0,
    KAORINGU, KATILDEU, 0, 0, KMU, 0, 0,
    0, 0, 0, 0, 0,
    // left thumb
    0, 0,
    0, 0, 0,
    RALT(S(KC_SPACE)), 0, RALT(S(KC_ENTER)),
    // right hand
    0, 0, KEXISTS, 0, 0, 0, 0,
    0, KLAMBDAU, KLSLASHU, KOACUTEU, 0, KOSLASHU, KBITCOIN,
    KCCEDILLAU, KNTILDEU, KEACUTEU, KUACUTEU, KIACUTEU, KYACUTEU,
    0, KLEXCL, KCOPYRIGHT, 0, KUORINGU, KOEU, 0,
    0, 0, 0, 0, 0,
    // right thumb
    0, 0,
    0, RALT(S(KC_INSERT)), RALT(S(KC_DELETE)),
    RALT(S(KC_TAB)), 0, RALT(S(KC_BSPC))
    ),

[LMED] = LAYOUT_ergodox_80(
    // left hand
    KC_F1, KC_F2, KC_F3, KC_BTN3, KC_F4, KC_F5, KC_F6,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 1, 1,
    // left thumb
    1, 1,
    1, 1, 1,
    1, 1, 1,
    // right hand
    KC_F7, KC_F8, KC_F9, KC_BTN3,KC_F10, KC_F11, KC_F12,
    TO(LAY1), KC_PGUP, KC_BTN1, KC_MS_U, KC_BTN2, 0, 0,
    KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_R, 0, 0,
    0, 0, 0, 1, 0, 0, 0,
    1, 1, 1, 0, 1,
    // right thumb
    0, 0,
    1, 1, 1,
    1, 1, 1
    ),

[LNUM] = LAYOUT_ergodox_80(
    // left hand
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    // left thumb
    0, 0,
    0, 0, 0,
    0, 0, 0,
    // right hand
    0, 0, KA, KB, KC, KPERC, 0,
    0, KF, K7, K8, K9, KSTAR, KSLSH,
    KE, K4, K5, K6, KPLUS, KMINUS,
    TO(LAY1), KD, K1, K2, K3, KLPAR, KRPAR,
    KC_0, KC_DOT, KC_COMMA, 0, 0,
    // right thumb
    0, 0,
    0, 0, 0,
    0, 0, 0
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        /* On key down */
        switch (keycode) {
        // Compose key stuff.
        case KSCOMMA:   SEND_COMPOSE(";s"); return false;
        case KSCOMMAU:  SEND_COMPOSE(";S"); return false;
        case KTCOMMA:   SEND_COMPOSE(";t"); return false;
        case KTCOMMAU:  SEND_COMPOSE(";T"); return false;
        case KYACUTE:   SEND_COMPOSE("'y"); return false;
        case KYACUTEU:  SEND_COMPOSE("'Y"); return false;
        case KLSLASH:   SEND_COMPOSE("/l"); return false;
        case KLSLASHU:  SEND_COMPOSE("/L"); return false;
        case KAORING:   SEND_COMPOSE("oa"); return false;
        case KAORINGU:  SEND_COMPOSE("oA"); return false;
        case KUORING:   SEND_COMPOSE("ou"); return false;
        case KUORINGU:  SEND_COMPOSE("oU"); return false;
        case KATILDE:   SEND_COMPOSE("~a"); return false;
        case KATILDEU:  SEND_COMPOSE("~A"); return false;
        case KABREVE:   SEND_COMPOSE("ba"); return false;
        case KABREVEU:  SEND_COMPOSE("bA"); return false;
        case KESZETU:   SEND_COMPOSE("SS"); return false;
        default: break;
        }
    } else {
        /* On key down */
        switch (keycode) {
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
        case LMED:
            ergodox_right_led_2_on();
            break;
        case LNUM:
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
