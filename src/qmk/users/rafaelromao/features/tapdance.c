#include QMK_KEYBOARD_H

#include "tapdance.h"

static td_tap_t tap_state = {.state = TD_NONE};

__attribute__((weak)) td_state_t dance_state(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else
            return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted)
            return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TD_TRIPLE_TAP;
        else
            return TD_TRIPLE_HOLD;
    } else
        return TD_UNKNOWN;
}

bool is_shifted(void) {
    return get_mods() & MOD_MASK_SHIFT || get_oneshot_mods() & MOD_MASK_SHIFT ||
           get_oneshot_locked_mods() & MOD_MASK_SHIFT;
}

void td_open_parentesis(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LPRN);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_LPRN);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("var ");
            break;
        default:
            break;
    }
}

void td_close_parentesis(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_RPRN);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_RPRN);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("return ");
            break;
        default:
            break;
    }
}

void td_enter_end(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_END);
            tap_code(KC_ENT);
            break;
        case TD_DOUBLE_TAP:
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_END));
            break;
        default:
            break;
    }
}

void td_open_curly_braces(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LCBR);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_LCBR);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("for(");
            break;
        default:
            break;
    }
}

void td_close_curly_braces(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_RCBR);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_RCBR);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("if(");
            break;
        default:
            break;
    }
}

void td_dquo(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_macros(MC_DQUO, NULL);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            process_macros(MC_DQUO, NULL);
            break;
        case TD_DOUBLE_TAP:
            process_macros(MC_DQUO, NULL);
            process_macros(MC_DQUO, NULL);
            tap_code(KC_LEFT);
            break;
        default:
            break;
    }
}

void td_hash(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_HASH);
            break;
        case TD_SINGLE_HOLD:
            process_macros(MC_SQUO, NULL);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_HASH);
            tap_code16(KC_HASH);
            break;
        case TD_TRIPLE_TAP:
            tap_code16(KC_HASH);
            tap_code16(KC_HASH);
            tap_code16(KC_HASH);
            break;
        default:
            break;
    }
}

void td_and(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_AMPR);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_RIGHT);
            process_macros(MC_DAND, NULL);
            break;
        case TD_DOUBLE_TAP:
            process_macros(MC_DAND, NULL);
            break;
        default:
            break;
    }
}

void td_or(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_PIPE);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_RIGHT);
            process_macros(MC_DPIP, NULL);
            break;
        case TD_DOUBLE_TAP:
            process_macros(MC_DPIP, NULL);
            break;
        default:
            break;
    }
}

void td_colon(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);

    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            if (is_shifted()) {
                clear_shift();
                tap_code(KC_SCLN);
            } else {
                tap_code16(KC_COLN);
            }
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_COLN);
            tap_code16(KC_COLN);
            break;
        case TD_SINGLE_HOLD:
            process_macros(MC_CIRC, NULL);
            break;
        default:
            break;
    }
}

void td_semicolon(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_SCLN);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code(KC_SCLN);
            break;
        default:
            break;
    }
}

void td_parentesis(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LPRN);
            tap_code16(KC_RPRN);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_LPRN);
            tap_code16(KC_RPRN);
            break;
        default:
            break;
    }
}

void td_zj(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_Z);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_J);
            break;
        default:
            break;
    }
}

void td_pq(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_P);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_Q);
            break;
        default:
            break;
    }
}

void td_macro(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_DOUBLE_TAP:
            dyn_macro_toggle(is_shifted() ? QK_DYNAMIC_MACRO_RECORD_START_2 : QK_DYNAMIC_MACRO_RECORD_START_1);
            break;
        case TD_SINGLE_TAP:
            dyn_macro_play(is_shifted() ? QK_DYNAMIC_MACRO_PLAY_2 : QK_DYNAMIC_MACRO_PLAY_1);
            break;
        default:
            break;
    }
}

void td_plus(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_PLUS);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code16(KC_PLUS);
            tap_code16(KC_PLUS);
            break;
        case TD_TRIPLE_TAP:
            tap_code16(KC_PLUS);
            tap_code16(KC_PLUS);
            tap_code16(KC_PLUS);
            break;
        case TD_SINGLE_HOLD:
            process_macros(MC_EUR, NULL);
            break;
        default:
            break;
    }
}

void td_mins(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_MINS);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code16(KC_MINS);
            tap_code16(KC_MINS);
            break;
        case TD_TRIPLE_TAP:
            tap_code16(KC_MINS);
            tap_code16(KC_MINS);
            tap_code16(KC_MINS);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_DLR);
            break;
        default:
            break;
    }
}

void td_eql(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_EQL);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code(KC_EQL);
            tap_code(KC_EQL);
            break;
        case TD_TRIPLE_TAP:
            tap_code(KC_EQL);
            tap_code(KC_EQL);
            tap_code(KC_EQL);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_END);
            tap_code(KC_EQL);
            break;
        default:
            break;
    }
}

void td_open_brackets(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LBRC);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_LBRC);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("switch(");
            break;
        default:
            break;
    }
}

void td_close_brackets(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_RBRC);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_RBRC);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("case ");
            break;
        default:
            break;
    }
}

void td_ques(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_macros(MC_QUES, NULL);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code16(KC_QUES);
            tap_code16(KC_QUES);
            break;
        case TD_SINGLE_HOLD:
            process_macros(MC_BTIC, NULL);
            break;
        default:
            break;
    }
}

void td_excl(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_macros(MC_EXLM, NULL);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code16(KC_EXLM);
            tap_code16(KC_EXLM);
            break;
        case TD_SINGLE_HOLD:
            process_macros(MC_TILD, NULL);
            break;
        default:
            break;
    }
}

void td_percent(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);

    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_PERC);
            break;
        case TD_DOUBLE_TAP:
            if (is_macos()) {
                tap_code16(RALT(KC_0));
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_7)));
            }
            break;
        case TD_TRIPLE_TAP:
            if (is_macos()) {
                tap_code16(RALT(KC_9));
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_6)));
            }
            break;
        case TD_SINGLE_HOLD:
            if (is_macos()) {
                tap_code16(LSFT(RALT(KC_8)));
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_6)));
            }
            break;
        default:
            break;
    }
}

void td_comm(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_COMM);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code(KC_COMM);
            tap_code(KC_COMM);
            break;
        case TD_TRIPLE_TAP:
            tap_code(KC_COMM);
            tap_code(KC_COMM);
            tap_code(KC_COMM);
            break;
        case TD_SINGLE_HOLD:
            leader_start();
            break;
        default:
            break;
    }
}

void td_dot(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_DOT);
            start_sentence_case();
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            break;
        case TD_TRIPLE_TAP:
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code(KC_DOT);
            start_sentence_case();
            break;
        default:
            break;
    }
}

void td_slash(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_SLSH);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code(KC_SLSH);
            tap_code(KC_SLSH);
            break;
        case TD_TRIPLE_TAP:
            tap_code(KC_SLSH);
            tap_code(KC_SLSH);
            tap_code(KC_SLSH);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_BSLS);
            break;
        default:
            break;
    }
}

void td_lt(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LT);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code16(KC_LT);
            tap_code16(KC_LT);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_END);
            tap_code16(KC_LT);
            break;
        default:
            break;
    }
}

void td_gt(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_GT);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code16(KC_GT);
            tap_code16(KC_GT);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_END);
            tap_code16(KC_GT);
            break;
        default:
            break;
    }
}

void td_dcol(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_macros(MC_DCOL, NULL);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_END);
            process_macros(MC_DCOL, NULL);
            break;
        default:
            break;
    }
}

void td_quot(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            if (!is_shifted()) {
                process_macros(MC_DQUO, NULL);
            } else {
                process_macros(MC_SQUO, NULL);
            }
            break;
        case TD_SINGLE_HOLD:
            process_macros(MC_DQUO, NULL);
            break;
        default:
            break;
    }
}

void td_sarr(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_macros(MC_SAR, NULL);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_END);
            process_macros(MC_SAR, NULL);
            break;
        default:
            break;
    }
}

// clang-format off

// Tap dance declarations

tap_dance_action_t tap_dance_actions[] = {
    [ENT_END] = ACTION_TAP_DANCE_FN(td_enter_end),
    [SCL_END] = ACTION_TAP_DANCE_FN(td_semicolon),
    [BRT_LCR] = ACTION_TAP_DANCE_FN(td_open_curly_braces),
    [BRT_RCR] = ACTION_TAP_DANCE_FN(td_close_curly_braces),
    [BRT_OPA] = ACTION_TAP_DANCE_FN(td_open_parentesis),
    [BRT_CPA] = ACTION_TAP_DANCE_FN(td_close_parentesis),
    [BRT_OBR] = ACTION_TAP_DANCE_FN(td_open_brackets),
    [BRT_CBR] = ACTION_TAP_DANCE_FN(td_close_brackets),
    [DQU_FIN] = ACTION_TAP_DANCE_FN(td_dquo),
    [EXL_EEX] = ACTION_TAP_DANCE_FN(td_excl),
    [AND_EAN] = ACTION_TAP_DANCE_FN(td_and),
    [OR_EOR]  = ACTION_TAP_DANCE_FN(td_or),
    [BRT_PAR] = ACTION_TAP_DANCE_FN(td_parentesis),
#ifdef DYNAMIC_MACRO_ENABLE
    [REC_MAC] = ACTION_TAP_DANCE_FN(td_macro),
#endif
    [COM_LEA] = ACTION_TAP_DANCE_FN(td_comm),
    [MIN_CUR] = ACTION_TAP_DANCE_FN(td_mins),
    [COL_ECO] = ACTION_TAP_DANCE_FN(td_colon),
    [PER_DEG] = ACTION_TAP_DANCE_FN(td_percent),
    [QUE_EXC] = ACTION_TAP_DANCE_FN(td_ques),
    [EQL_EEQ] = ACTION_TAP_DANCE_FN(td_eql),
    [PLU_EPL] = ACTION_TAP_DANCE_FN(td_plus),
    [LET_ELT] = ACTION_TAP_DANCE_FN(td_lt),
    [GRT_EGT] = ACTION_TAP_DANCE_FN(td_gt),
    [SLS_BSL] = ACTION_TAP_DANCE_FN(td_slash),
    [DCO_EDC] = ACTION_TAP_DANCE_FN(td_dcol),
    [SAR_ESA] = ACTION_TAP_DANCE_FN(td_sarr),
    [HAS_SQO] = ACTION_TAP_DANCE_FN(td_hash),
    [Z_J] = ACTION_TAP_DANCE_FN(td_zj),
    [P_Q] = ACTION_TAP_DANCE_FN(td_pq),
    [SQO_DQO] = ACTION_TAP_DANCE_FN(td_quot),
    [DOT_DOT] = ACTION_TAP_DANCE_FN(td_dot)};

// clang-format on
