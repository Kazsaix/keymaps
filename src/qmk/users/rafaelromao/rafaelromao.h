#include QMK_KEYBOARD_H

#include "secret.h"
#include "definitions/layers.h"
#include "definitions/keycodes.h"
#include "definitions/keymap_blocks.h"
#include "definitions/keymap_blocks_kazsaix.h"
#include "features/taphold.h"
#include "features/tapdance.h"
#include "features/smart_case.h"
#include "features/os_toggle.h"
#include "features/macros.h"
#include "features/accents.h"
#include "features/custom_oneshot.h"
#include "features/common_shortcuts.h"
#include "features/select_word.h"
#include "features/custom_shift.h"
#include "features/repeat.h"
#include "features/sentence_case.h"
#include "features/swapper.h"
#include "features/leader.h"

#ifdef DYNAMIC_MACRO_ENABLE
#    include "features/dynamic_macro.h"
#endif

void matrix_scan_keymap(void);
