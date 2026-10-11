/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11); original file name unknown, placeholder.
 *
 * .text 0x8026DDE8-0x8026FEB8, .rodata 0x805DC360-0x805DC4A4,
 * .data 0x8061E640-0x8061E644.
 *
 * cMatrixChooser: vtable 0x806625F0 slot 3 (0x802AC838) returns the pointer at
 * 0x8061E640 -> "cMatrixChooser". Its helper class (vtable 0x80662688,
 * ctor 0x8026DDE8, dtor 0x8026DE5C, parse 0x8026DFE4) comes first. "type"
 * (0x805DC394), which other choosers' slot 2 also passes, is defined here
 * as a global array.
 */
#include "game/chooser.h"
