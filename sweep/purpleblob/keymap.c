#include QMK_KEYBOARD_H

//TAP DANCE ( f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 )
//COMBOS ( - + = _ )
//Left ( INS )

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_TRIPLE_TAP,
    TD_QUADRA_TAP,
    TD_QUINTA_TAP,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    TF1, TF5, TF9, TH1, TH2, TH3, TH4, TH5, TH6, TH7, TH8, TH9, TH0
};

td_state_t cur_dance(tap_dance_state_t *state);

void tf1_finished(tap_dance_state_t *state, void *user_data);
void tf1_reset(tap_dance_state_t *state, void *user_data);
void tf5_finished(tap_dance_state_t *state, void *user_data);
void tf5_reset(tap_dance_state_t *state, void *user_data);
void tf9_finished(tap_dance_state_t *state, void *user_data);
void tf9_reset(tap_dance_state_t *state, void *user_data);

void th1_finished(tap_dance_state_t *state, void *user_data);
void th1_reset(tap_dance_state_t *state, void *user_data);
void th2_finished(tap_dance_state_t *state, void *user_data);
void th2_reset(tap_dance_state_t *state, void *user_data);
void th3_finished(tap_dance_state_t *state, void *user_data);
void th3_reset(tap_dance_state_t *state, void *user_data);
void th4_finished(tap_dance_state_t *state, void *user_data);
void th4_reset(tap_dance_state_t *state, void *user_data);
void th5_finished(tap_dance_state_t *state, void *user_data);
void th5_reset(tap_dance_state_t *state, void *user_data);
void th6_finished(tap_dance_state_t *state, void *user_data);
void th6_reset(tap_dance_state_t *state, void *user_data);
void th7_finished(tap_dance_state_t *state, void *user_data);
void th7_reset(tap_dance_state_t *state, void *user_data);
void th8_finished(tap_dance_state_t *state, void *user_data);
void th8_reset(tap_dance_state_t *state, void *user_data);
void th9_finished(tap_dance_state_t *state, void *user_data);
void th9_reset(tap_dance_state_t *state, void *user_data);
void th9_finished(tap_dance_state_t *state, void *user_data);
void th0_reset(tap_dance_state_t *state, void *user_data);
void th0_finished(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//Main Layer
    [0] = LAYOUT(

        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        LSFT_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
        KC_P,         KC_Z,         KC_X,         KC_C,         KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,
                                   KC_BSPC, MO(1), LT(2, KC_SPC),  KC_LCTL
    ),

//Punc Layer
    [1] = LAYOUT(

        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TAB,  KC_AT,   KC_LCBR, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, KC_RCBR, KC_QUOT, KC_SCLN,
        KC_DQT,  KC_NUHS, KC_PERC, KC_COLN, _______, KC_CIRC, KC_DLR,  KC_ASTR, KC_NUBS, KC_SLSH,
                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

//Nav Layer
    [2] = LAYOUT(

        KC_ESC,  KC_EXLM, S(KC_NUBS), KC_AMPR, _______, KC_INS,  TD(TF1), TD(TF5), TD(TF9), KC_DEL,
        KC_LEFT, KC_DOWN, KC_UP,      KC_RGHT, _______, _______, C(KC_LEFT), C(KC_DOWN), C(KC_UP), C(KC_RGHT),
        S(KC_NUHS), KC_PGDN, KC_PGUP, KC_HOME, _______, _______, KC_END,  _______, _______, _______,
                                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

//Hypr Layer (TRI LAYER = PUNC+NAV)
    [3] = LAYOUT(

        TD(TH1), TD(TH2), TD(TH3), TD(TH4), TD(TH5), TD(TH6), TD(TH7), TD(TH8), TD(TH9), TD(TH0),
        A(KC_SPC),_______,_______, _______, _______, _______, _______, _______, _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

//Gaming Layer
    [4] = LAYOUT(

        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    _______, _______, _______, _______, _______,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    _______, _______, _______, _______, _______,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    _______, _______, _______, _______, _______,
                                   MO(5), KC_SPC,  _______, _______
    ),

//Gaming Upper Layer
    [5] = LAYOUT(

        KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    _______, _______, _______, _______, _______,
        KC_TAB, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, _______, _______,
        KC_LALT, KC_I,    KC_P,    KC_G,    KC_M,    _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______
    ),

};

const uint16_t PROGMEM cmb_mins[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_plus[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_eql[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_unds[] = {KC_C, KC_N, COMBO_END};
combo_t key_combos[] = {
    COMBO(cmb_mins, KC_MINS),
    COMBO(cmb_plus, KC_PLUS),
    COMBO(cmb_eql, KC_EQL),
    COMBO(cmb_unds, KC_UNDS),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, 1, 2, 3);
}

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1){
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    else if (state->count == 2) return TD_DOUBLE_TAP;
    else if (state->count == 3) return TD_TRIPLE_TAP;
    else if (state->count == 4) return TD_QUADRA_TAP;
    else return TD_UNKNOWN;
}

static td_tap_t tf1tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void tf1_finished(tap_dance_state_t *state, void *user_data) {
    tf1tap_state.state = cur_dance(state);
    switch (tf1tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_F1); break;
        case TD_DOUBLE_TAP: register_code(KC_F2); break;
        case TD_TRIPLE_TAP: register_code(KC_F3); break;
        case TD_QUADRA_TAP: register_code(KC_F4); break;
        default: break;
    }
}

void tf1_reset(tap_dance_state_t *state, void *user_data) {
    switch (tf1tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_F1); break;
        case TD_DOUBLE_TAP: unregister_code(KC_F2); break;
        case TD_TRIPLE_TAP: unregister_code(KC_F3); break;
        case TD_QUADRA_TAP: unregister_code(KC_F4); break;
        default: break;
    }
    tf1tap_state.state = TD_NONE;
}

static td_tap_t tf5tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void tf5_finished(tap_dance_state_t *state, void *user_data) {
    tf5tap_state.state = cur_dance(state);
    switch (tf5tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_F5); break;
        case TD_DOUBLE_TAP: register_code(KC_F6); break;
        case TD_TRIPLE_TAP: register_code(KC_F7); break;
        case TD_QUADRA_TAP: register_code(KC_F8); break;
        default: break;
    }
}

void tf5_reset(tap_dance_state_t *state, void *user_data) {
    switch (tf5tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_F5); break;
        case TD_DOUBLE_TAP: unregister_code(KC_F6); break;
        case TD_TRIPLE_TAP: unregister_code(KC_F7); break;
        case TD_QUADRA_TAP: unregister_code(KC_F8); break;
        default: break;
    }
    tf5tap_state.state = TD_NONE;
}

static td_tap_t tf9tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void tf9_finished(tap_dance_state_t *state, void *user_data) {
    tf9tap_state.state = cur_dance(state);
    switch (tf9tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_F9); break;
        case TD_DOUBLE_TAP: register_code(KC_F10); break;
        case TD_TRIPLE_TAP: register_code(KC_F11); break;
        case TD_QUADRA_TAP: register_code(KC_F12); break;
        default: break;
    }
}

void tf9_reset(tap_dance_state_t *state, void *user_data) {
    switch (tf9tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_F9); break;
        case TD_DOUBLE_TAP: unregister_code(KC_F10); break;
        case TD_TRIPLE_TAP: unregister_code(KC_F11); break;
        case TD_QUADRA_TAP: unregister_code(KC_F12); break;
        default: break;
    }
    tf9tap_state.state = TD_NONE;
}

static td_tap_t th1tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void th1_finished(tap_dance_state_t *state, void *user_data) {
    th1tap_state.state = cur_dance(state);
    switch (th1tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_1);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_1);
            break;
        default: break;
    }
}

void th1_reset(tap_dance_state_t *state, void *user_data) {
    switch (th1tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_LGUI);
            unregister_code(KC_1);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_1);
            break;
        default: break;
    }
    th1tap_state.state = TD_NONE;
}
static td_tap_t th2tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void th2_finished(tap_dance_state_t *state, void *user_data) {
    th2tap_state.state = cur_dance(state);
    switch (th2tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_2);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_2);
            break;
        default: break;
    }
}

void th2_reset(tap_dance_state_t *state, void *user_data) {
    switch (th2tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_LGUI);
            unregister_code(KC_2);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_2);
            break;
        default: break;
    }
    th2tap_state.state = TD_NONE;
}
static td_tap_t th3tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void th3_finished(tap_dance_state_t *state, void *user_data) {
    th3tap_state.state = cur_dance(state);
    switch (th3tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_3);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_3);
            break;
        default: break;
    }
}

void th3_reset(tap_dance_state_t *state, void *user_data) {
    switch (th3tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_LGUI);
            unregister_code(KC_3);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_3);
            break;
        default: break;
    }
    th3tap_state.state = TD_NONE;
}
static td_tap_t th4tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void th4_finished(tap_dance_state_t *state, void *user_data) {
    th4tap_state.state = cur_dance(state);
    switch (th4tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_4);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_4);
            break;
        default: break;
    }
}

void th4_reset(tap_dance_state_t *state, void *user_data) {
    switch (th4tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_LGUI);
            unregister_code(KC_4);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_4);
            break;
        default: break;
    }
    th4tap_state.state = TD_NONE;
}
static td_tap_t th5tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void th5_finished(tap_dance_state_t *state, void *user_data) {
    th5tap_state.state = cur_dance(state);
    switch (th5tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_5);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_5);
            break;
        default: break;
    }
}

void th5_reset(tap_dance_state_t *state, void *user_data) {
    switch (th5tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_LGUI);
            unregister_code(KC_5);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_5);
            break;
        default: break;
    }
    th5tap_state.state = TD_NONE;
}
static td_tap_t th6tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void th6_finished(tap_dance_state_t *state, void *user_data) {
    th6tap_state.state = cur_dance(state);
    switch (th6tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_6);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_6);
            break;
        default: break;
    }
}

void th6_reset(tap_dance_state_t *state, void *user_data) {
    switch (th6tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_LGUI);
            unregister_code(KC_6);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_6);
            break;
        default: break;
    }
    th6tap_state.state = TD_NONE;
}
static td_tap_t th7tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void th7_finished(tap_dance_state_t *state, void *user_data) {
    th7tap_state.state = cur_dance(state);
    switch (th7tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_7);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_7);
            break;
        default: break;
    }
}

void th7_reset(tap_dance_state_t *state, void *user_data) {
    switch (th7tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_LGUI);
            unregister_code(KC_7);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_7);
            break;
        default: break;
    }
    th7tap_state.state = TD_NONE;
}
static td_tap_t th8tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void th8_finished(tap_dance_state_t *state, void *user_data) {
    th8tap_state.state = cur_dance(state);
    switch (th8tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_8);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_8);
            break;
        default: break;
    }
}

void th8_reset(tap_dance_state_t *state, void *user_data) {
    switch (th8tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_LGUI);
            unregister_code(KC_8);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_8);
            break;
        default: break;
    }
    th8tap_state.state = TD_NONE;
}
static td_tap_t th9tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void th9_finished(tap_dance_state_t *state, void *user_data) {
    th9tap_state.state = cur_dance(state);
    switch (th9tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_9);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_9);
            break;
        default: break;
    }
}

void th9_reset(tap_dance_state_t *state, void *user_data) {
    switch (th9tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_LGUI);
            unregister_code(KC_9);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_9);
            break;
        default: break;
    }
    th9tap_state.state = TD_NONE;
}
static td_tap_t th0tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void th0_finished(tap_dance_state_t *state, void *user_data) {
    th0tap_state.state = cur_dance(state);
    switch (th0tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_0);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_0);
            break;
        default: break;
    }
}

void th0_reset(tap_dance_state_t *state, void *user_data) {
    switch (th0tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_LGUI);
            unregister_code(KC_0);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_0);
            break;
        default: break;
    }
    th0tap_state.state = TD_NONE;
}


tap_dance_action_t tap_dance_actions[] = {
    [TF1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tf1_finished, tf1_reset),
    [TF5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tf5_finished, tf5_reset),
    [TF9] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tf9_finished, tf9_reset),
    [TH1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th1_finished, th1_reset),
    [TH2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th2_finished, th2_reset),
    [TH3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th3_finished, th3_reset),
    [TH4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th4_finished, th4_reset),
    [TH5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th5_finished, th5_reset),
    [TH6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th6_finished, th6_reset),
    [TH7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th7_finished, th7_reset),
    [TH8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th8_finished, th8_reset),
    [TH9] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th9_finished, th9_reset),
    [TH0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, th0_finished, th0_reset)

};
