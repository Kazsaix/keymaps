#pragma once

#include "layers.h"

// clang-format off

// Tap dance codes

enum {
    TD_CODE_START,
    ENT_END,
    SCL_END,
    BRT_LCR,
    BRT_RCR,
    BRT_PAR,
    BRT_OPA,
    BRT_CPA,
    BRT_OBR,
    BRT_CBR,
    DQU_FIN,
    EXL_EEX,
    AND_EAN,
#ifdef DYNAMIC_MACRO_ENABLE
    REC_MAC,
#endif
    COM_LEA,
    DOT_DOT,
    MIN_CUR,
    COL_ECO,
    PER_DEG,
    SLS_BSL,
    QUE_EXC,
    EQL_EEQ,
    PLU_EPL,
    LET_ELT,
    GRT_EGT,
    OR_EOR,
    DCO_EDC,
    SAR_ESA,
    HAS_SQO,
    Z_J,
    P_Q,
    SQO_DQO,
    TD_CODE_END
};

// Tap dance keycodes

#define TD_EENT TD(ENT_END)
#define TD_SCLE TD(SCL_END)
#define TD_LCRB TD(BRT_LCR)
#define TD_RCRB TD(BRT_RCR)
#define TD_PARN TD(BRT_PAR)
#define TD_OPAR TD(BRT_OPA)
#define TD_CPAR TD(BRT_CPA)
#define TD_OBR TD(BRT_OBR)
#define TD_CBR TD(BRT_CBR)
#define TD_DQUO TD(DQU_FIN)
#define TD_EXLM TD(EXL_EEX)
#define TD_AND TD(AND_EAN)
#define TD_OR TD(OR_EOR)
#ifdef DYNAMIC_MACRO_ENABLE
#define TD_MACR TD(REC_MAC)
#else
#define TD_MACR XXXXXXX
#endif
#define TD_COMM TD(COM_LEA)
#define TD_DOT TD(DOT_DOT)
#define TD_MINS TD(MIN_CUR)
#define TD_COLN TD(COL_ECO)
#define TD_PERC TD(PER_DEG)
#define TD_QUES TD(QUE_EXC)
#define TD_SLSH TD(SLS_BSL)
#define TD_EQL TD(EQL_EEQ)
#define TD_PLUS TD(PLU_EPL)
#define TD_LT TD(LET_ELT)
#define TD_GT TD(GRT_EGT)
#define TD_DCOL TD(DCO_EDC)
#define TD_SARR TD(SAR_ESA)
#define TD_HASH TD(HAS_SQO)
#define TD_ZJ TD(Z_J)
#define TD_PQ TD(P_Q)
#define TD_QUOT TD(SQO_DQO)

// Custom keycodes

enum {
    CUSTOM_KEYCODE_START = SAFE_RANGE,

    MC_SECRET_1,

    // Toggle codes
    OS_ACNT, TG_MAC, TG_WIN, TG_CASE, TG_ACNT, TG_CAPS,

    // Select Word/Line
    MC_SELW, MC_SELL,

    // Swapper
    MC_MODP, MC_MODM, MC_SWLE, MC_SWRI,

    // Begin macros that can be shifted
    SFT_MACRO_START,

    // Common shortcuts
    MC_SELC, MC_SAVE, MC_UNDO, MC_COPY, MC_SCOP, MC_CLOS,
    MC_PAST, MC_SPAS, MC_LOCK, MC_FULL, MC_FIND, MC_Z0R,

    // IDE shortcuts
    MC_QUIK, MC_AUCO,
    MC_QDOC, MC_FSYM, MC_RUN, MC_DBUG, MC_BUID,
    MC_PROJ, MC_RECE, MC_COMP, MC_FIUS, MC_REFC,
    MC_COMT, MC_JOIN,

    // Begin macros used to write text
    STR_MACRO_START,

    MC_BTIC, MC_DQUO, MC_SQUO, MC_CIRC, MC_TILD, REPEAT, MC_EUR,
    MC_ENT, MC_TAB, MC_ESC, MC_ESCC, MC_NSEN, MC_CANC, TG_NUMC, MC_EXLM, MC_QUES,
    MC_ESAV, MC_SENT, MC_CUR, MC_CURS, MC_DCOL, MC_SAR, MC_DEQ, MC_NEQ, MC_BRAC,
    MC_DAND, MC_DPIP, MC_OESC, MC_SOES, MC_LTGT, MC_VIS, MC_EPA, MC_SEC,

    // End macros that can be shifted
    SFT_MACRO_END,

    // Start macros for accented letters
    ALPHA_MACRO_START,

    MC_GV_A, MC_CR_A, MC_TL_A, MC_SQ_A,
    MC_SQ_U, MC_CR_O, MC_SQ_O, MC_SQ_I,
    MC_CR_E, MC_TL_O, MC_SQ_C, MC_SQ_E,
    MC_AO, MC_OE, MC_CAO, MC_COES,
    MC_QU, MC_JA, MC_LH,

    // End macros for accented letters
    ALPHA_MACRO_END,

    // End macros used to write text
    STR_MACRO_END,

    CUSTOM_KEYCODE_END
};

// Mod-taps

#define LSFTT_N LSFT_T(KC_N)
#define RSFTT_E RSFT_T(KC_E)
#define SF_FSYM LSFT_T(MC_FSYM)
#define SF_MODP RSFT_T(MC_MODP)
#define SF_F6 LSFT_T(KC_F6)
#define SF_6 RSFT_T(KC_6)

#define LCTLT_S LCTL_T(KC_S)
#define RCTLT_A RCTL_T(KC_A)
#define CT_F5 LCTL_T(KC_F5)
#define CT_5 RCTL_T(KC_5)

#define LALTT_P LALT_T(KC_P)
#define RALTT_H RALT_T(KC_H)
#define RALTT_F RALT_T(KC_F)
#define AL_F1 LALT_T(KC_F1)
#define AL_1 RALT_T(KC_1)
#define AL_F3 RALT_T(KC_F3)

#define LGUIT_T LGUI_T(KC_T)
#define RGUIT_R RGUI_T(KC_R)
#define GU_F4 LGUI_T(KC_F4)
#define GU_4 RGUI_T(KC_4)

// One-shot mods

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_LGUI OSM(MOD_LGUI)

// Custom Shortcuts

#define HYPR_D HYPR(KC_D)
#define HYPR_Z HYPR(KC_Z)
#define HYPR_R HYPR(KC_R)
#define HYPR_W HYPR(KC_W)
#define HYPR_G HYPR(KC_G)
#define HYPR_V HYPR(KC_V)
#define HYPR_C HYPR(KC_C)
#define HYPR_L HYPR(KC_L)
#define HYPR_M HYPR(KC_M)
#define HYPR_J HYPR(KC_J)
#define MEH_D  MEH(KC_D)
#define MEH_Z  MEH(KC_Z)
#define MEH_W  MEH(KC_W)
#define MEH_G  MEH(KC_G)
#define MEH_V  MEH(KC_V)
#define MEH_C  MEH(KC_C)
#define MEH_J  MEH(KC_J)
#define MEH_M  MEH(KC_M)

// Layer-taps

#define NAV_REP LT(_NAVIGATION, QK_REP)
#define NAV_F12 LT(_NAVIGATION, KC_F12)
#define NAV_AT  LT(_NAVIGATION, KC_AT)
#define NAV_PRJ LT(_NAVIGATION, MC_PROJ)
#define NAV_CAS LT(_NAVIGATION, TG_CASE)
#define NAV_CAN LT(_NAVIGATION, MC_CANC)

#define MED_CAS LT(_MEDIA, TG_CASE)
#define MED_A1  LT(_MEDIA, TO_A1)
#define MED_0   LT(_MEDIA, KC_0)

#define MAI_CAS LT(_SYSTEM, TG_CASE)

#define NMO_DOC LT(_NOMOD, MC_QDOC)
#define ACT_SPC LT(_FIXED_ALPHA2, KC_SPC)
#define LOW_SPC LT(_LOWER, KC_SPC)
#define LOW_NSE LT(_LOWER, MC_NSEN)
#define RAI_TA2 LT(_RAISE, TG_ACNT)
#define RAI_SPC LT(_RAISE, KC_SPC)
#define SYM_SPC LT(_SYMBOLS, KC_SPC)
#define RAI_A2  OSL(_ALPHA2) // Hold behavior is implemented in intercepted code

#define SHO_KCD LT(_SHORTCUTS, KC_D)
#define SHO_KCI LT(_SHORTCUTS, KC_I)
#define SHO_DOT LT(_SHORTCUTS, KC_DOT)

// Layer transitions
#define MO_A2   MO(_FIXED_ALPHA2)
#define MO_MED  MO(_MEDIA)
#define TO_A1   TO(_ALPHA1)
#define TT_NAV  TT(_FIXED_NAV)
#define TG_LOCK TG(_LOCK)
#define TG_NUM  TG(_NUMPAD)
#define OS_SYM  OSL(_SYMBOLS)

uint16_t extract_tapping_keycode(uint16_t keycode);
bool is_string_macro_keycode(uint16_t keycode);
bool is_shift_macro_keycode(uint16_t keycode);


// Hands Down Neu Vibranium P Keycodes

//Modtaps
#define LSFTT_S LSFT_T(KC_S)
#define RSFTT_I RSFT_T(KC_I)

#define LCTLT_N LCTL_T(KC_N)
#define RCTLT_E RCTL_T(KC_E)

#define LALTT_D LALT_T(KC_D)
#define RALTT_U RALT_T(KC_U)

#define LGUIT_T LGUI_T(KC_T)
#define RGUIT_A RGUI_T(KC_A)

//Shortcuts
#define SHO_KCC LT(_SHORTCUTS, KC_C)
#define SHO_KCH LT(_SHORTCUTS, KC_H)

#define SHO_KCH LT(_SHORTCUTS, KC_H)

// Layer-taps
#define LOW_R LT(_LOWER, KC_R)
#define RAI_SPC  LT(_ALPHA2, KC_SPC) // Hold behavior is implemented in intercepted code

// clang-format on
