#include QMK_KEYBOARD_H

#include "macros.h"

extern os_t os;

bool is_shift_macro_keycode(uint16_t keycode) {
    return keycode > SFT_MACRO_START && keycode < SFT_MACRO_END;
}

process_record_result_t process_macro_keycode(uint16_t keycode, bool isOneShotShift, bool isShifted) {
    bool isMacOS = os.type == MACOS;

    switch (keycode) {
            // Inverted underscore and minus

        case MC_UNDS:
            if (isShifted) {
                tap_code(KC_MINS);
            } else {
                tap_code16(KC_UNDS);
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Select All

        case MC_SELC:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("a"));
            } else {
                SEND_STRING(SS_LGUI("a"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Save

        case MC_SAVE:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("s"));
            } else {
                SEND_STRING(SS_LGUI("s"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Undo

        case MC_UNDO:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("z"));
            } else {
                SEND_STRING(SS_LGUI("z"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Copy

        case MC_COPY:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("c"));
            } else {
                SEND_STRING(SS_LGUI("c"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Paste

        case MC_PAST:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("v"));
            } else {
                SEND_STRING(SS_LGUI("v"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Find

        case MC_FIND:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LCTL("f"));
            } else {
                SEND_STRING(SS_LGUI("f"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Lock

        case MC_LOCK:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                SEND_STRING(SS_LGUI("l"));
            } else {
                SEND_STRING(SS_LGUI(SS_LCTL("q")));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Full Screen

        case MC_FULL:
            clear_locked_and_oneshot_mods();
            if (should_send_ctrl(isMacOS, isOneShotShift)) {
                tap_code(KC_F11);
            } else {
                SEND_STRING(SS_LGUI(SS_LCTL("f")));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Conditional operators

        case MC_DAND:
            tap_code16(KC_AMPR);
            if (!isShifted) {
                tap_code16(KC_AMPR);
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case MC_DPIP:
            tap_code16(KC_PIPE);
            if (!isShifted) {
                tap_code16(KC_PIPE);
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Quick Actions / Breakpoint

        case MC_QUIK:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_F8)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_F8)));
                    break;
                }
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_ENT)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Type-matching Auto Complete / Basic Auto Complete

        case MC_AUCO:
            if (isShifted) {
                SEND_STRING(SS_LCTL(SS_TAP(X_SPC)));
            } else {
                SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_SPC))));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Quick Docs / Parameter Info

        case MC_QDOC:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LCMD(SS_TAP(X_P)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_P)));
                    break;
                }
            } else {
                if (isMacOS) {
                    tap_code(KC_F1);
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_Q)));
                    break;
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Find Symbol / Find Action

        case MC_FSYM:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_A))));
                } else {
                    SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_A))));
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_O))));
                } else {
                    SEND_STRING(SS_LALT(SS_LSFT(SS_LCTL(SS_TAP(X_N)))));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Run / Stop

        case MC_RUN:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_F2)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_F2)));
                    break;
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_R)));
                } else {
                    SEND_STRING(SS_LSFT(SS_TAP(X_F10)));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Debug / Resume

        case MC_DBUG:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_R))));
                } else {
                    SEND_STRING(SS_TAP(X_F9));
                    break;
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_D)));
                } else {
                    SEND_STRING(SS_LSFT(SS_TAP(X_F9)));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Build / Rebuild

        case MC_BUID:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_F9))));
                } else {
                    SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_F9))));
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_F9)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_F9)));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Project Files / Select In

        case MC_PROJ:
            if (isShifted) {
                SEND_STRING(SS_LALT(SS_TAP(X_F1)));
                return PROCESS_RECORD_RETURN_FALSE;
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_1)));
                } else {
                    SEND_STRING(SS_LALT(SS_TAP(X_1)));
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }

            // Recent Files / Previous Error

        case MC_RECE:
            if (isShifted) {
                SEND_STRING(SS_LSFT(SS_TAP(X_F2)));
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_E)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_E)));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Complete Statement / Next Error

        case MC_COMP:
            if (isShifted) {
                SEND_STRING(SS_TAP(X_F2));
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_ENT))));
                } else {
                    SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_ENT))));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Find Usages / Quick Definition

        case MC_FIUS:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LALT(SS_TAP(X_SPC)));
                } else {
                    SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_I))));
                    break;
                }
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_F7)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Refactor / Format

        case MC_REFC:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_LALT(SS_TAP(X_L))));
                } else {
                    SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_L))));
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_T)));
                } else {
                    SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT(SS_TAP(X_T)))));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Join Lines

        case MC_JOIN:
            SEND_STRING(SS_TAP(X_END) SS_TAP(X_DEL));
            return PROCESS_RECORD_RETURN_FALSE;

            // Comment Lines

        case MC_COMT:
            if (isMacOS) {
                SEND_STRING(SS_LGUI("/"));
            } else {
                SEND_STRING(SS_LCTL("/"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // END { ENTER }

        case MC_CUR:
            SEND_STRING(SS_TAP(X_END) "{}" SS_DELAY(50) SS_TAP(X_LEFT) SS_TAP(X_ENT));
            return PROCESS_RECORD_RETURN_FALSE;

            // END ; ENTER

        case MC_SENT:
            tap_code(KC_END);
            tap_code(KC_SCLN);
            tap_code(KC_ENT);
            return PROCESS_RECORD_RETURN_FALSE;

            // Refresh / Clear Cache

        case MC_REF:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_R))));
                } else {
                    SEND_STRING(SS_LSFT(SS_TAP(X_F5)));
                }
            } else {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_R)));
                } else {
                    tap_code(KC_F5);
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Esc, Tab, Enter

        case MC_ESC:
            tap_code(KC_ESC); // It works when shifted, since shifted is removed for macros
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_TAB:
            tap_code(KC_TAB); // It works when shifted, since shifted is removed for macros
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_ENT:
            tap_code(KC_ENT); // It works when shifted, since shifted is removed for macros
            return PROCESS_RECORD_RETURN_FALSE;

            // Close Tab
        case MC_CTAB:
            if (isShifted) {
                if (isMacOS) {
                    SEND_STRING(SS_LGUI(SS_TAP(X_W)));
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_F4)));
                    break;
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // Save + Esc

        case MC_ESAV:
            process_macro_keycode(MC_SAVE, false, false);
            process_macro_keycode(MC_ESC, false, false);
            return PROCESS_RECORD_RETURN_FALSE;
    }

    return PROCESS_RECORD_CONTINUE;
}

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record) {
    if (record != NULL && record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }
    if (!is_shift_macro_keycode(keycode)) {
        return PROCESS_RECORD_CONTINUE;
    }

    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted            = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    // Macros

    int8_t mods = get_mods();
    if (isShifted) {
        clear_locked_and_oneshot_mods();
        unregister_mods(mods);
    }
    process_record_result_t result = process_macro_keycode(keycode, isOneShotShift, isShifted);
    if (isShifted) {
        wait_ms(100);
        register_mods(mods);
    }

    return result;
}
