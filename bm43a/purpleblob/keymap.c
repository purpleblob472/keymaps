#include QMK_KEYBOARD_H

enum {
   TD_SFT_CAPS, TD_SPC_ENT, TD_SCLN_CLN
};

tap_dance_action_t tap_dance_actions[] = {
   [TD_SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
   [TD_SCLN_CLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
   [TD_SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //Main
    [0] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,SFT_T(KC_A),CTL_T(KC_S),ALT_T(KC_D),GUI_T(KC_F),KC_G,KC_H,KC_J,  KC_K,    KC_L,    SFT_T(KC_ENT),
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_LCTL, KC_LGUI,  KC_LALT,          MO(2),   LT(3, KC_SPC),    KC_SCLN, KC_GUI, KC_LCTL, MO(4)
    ),

    //Gaming
    [1] = LAYOUT(
	    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
	    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
	    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
	    KC_LCTL, KC_LGUI, KC_LALT,          MO(2),   KC_SPC,           MO(3),   KC_GUI, KC_LCTL, MO(4)
	),

    //Puctuation (Lower)
    [2] = LAYOUT(
	    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    C(KC_BSPC),
	    KC_NUHS, KC_DQT,  KC_AT,   KC_LCBR, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, KC_RCBR, KC_QUOT, _______,
	    S(KC_NUHS),KC_EXLM,S(KC_NUBS),KC_AMPR,KC_PERC,KC_CIRC,KC_DLR,  KC_ASTR, KC_LT,   KC_GT,   KC_NUBS,
	    _______, _______, _______,          _______, _______,          KC_COLN, CM_TOGG, DF(0),   DF(1)
    ),

    //OS (Raise)
    [3] = LAYOUT(
        A(KC_F4),KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
	    KC_TAB,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F11,  KC_F12,  C(KC_LEFT),C(KC_DOWN),C(KC_UP),C(KC_RGHT),
	    KC_INS,  KC_PGDN, KC_PGUP, KC_HOME, KC_PSCR, XXXXXXX, KC_END,  XXXXXXX, KC_MUTE, KC_VOLU, KC_MPLY,
	    _______, _______, _______,          _______, _______,          _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),

    //Hyprland
    [4] = LAYOUT(
        KC_ESC,  G(KC_1),   G(KC_2),   G(KC_3),   G(KC_4),   G(KC_5),   G(KC_6),   G(KC_7),   G(KC_8),   G(KC_9),   G(KC_0), _______,
        KC_TAB,  SGUI(KC_1),SGUI(KC_2),SGUI(KC_3),SGUI(KC_4),SGUI(KC_5),SGUI(KC_6),SGUI(KC_7),SGUI(KC_8),SGUI(KC_9),SGUI(KC_0),
        KC_LSFT, G(KC_LEFT), G(KC_DOWN), G(KC_UP), G(KC_RGHT), _______,_______, _______, _______, _______, _______,
	    _______, _______, _______,          _______, _______,                   _______, _______, _______, _______


    ),

};

const uint16_t PROGMEM cmb_mins[] = {ALT_T(KC_D), GUI_T(KC_F), COMBO_END};
const uint16_t PROGMEM cmb_plus[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_eql[] = {GUI_T(KC_F), KC_J, COMBO_END};
const uint16_t PROGMEM cmb_unds[] = {KC_C, KC_N, COMBO_END};
combo_t key_combos[] = {
    COMBO(cmb_mins, KC_MINS),
    COMBO(cmb_plus, KC_PLUS),
    COMBO(cmb_eql, KC_EQL),
    COMBO(cmb_unds, KC_UNDS),
};


