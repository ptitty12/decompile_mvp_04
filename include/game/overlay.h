#ifndef GAME_OVERLAY_H
#define GAME_OVERLAY_H

/*
 * Code that retail links into the two code overlays. config/GV4E69/ldscript.ld
 * collects the input sections .feoverlay / .dboverlay into the retail output
 * sections .frontend_codeoverlay / .database_codeoverlay, and dtk splits those
 * overlays under the same input-section names. objdiff pairs functions only
 * within same-named sections, so every function defined in src/fe/ or src/db/
 * carries the matching macro (placement only; it changes no instruction).
 * See docs/DECISIONS.md (2026-10-11, overlay units).
 *
 * Usage:  FE_OVERLAY void fn_8043FE44(void) { ... }
 */
#define FE_OVERLAY __attribute__((section(".feoverlay")))
#define DB_OVERLAY __attribute__((section(".dboverlay")))

#endif
