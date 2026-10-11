/*
 * C:/mvp2004/source/common/animation/choosers/randomchooser.cpp
 * (path string at 0x805DC4AC, used by fn_8027011C's assert and the RNG call
 * in fn_802704E8). Part of the choosers/goals unity TU (docs/DECISIONS.md).
 *
 * .text 0x8026FEB8-0x80270730, .rodata 0x805DC4A4-0x805DC568,
 * .data 0x8061E644-0x8061E648.
 *
 * cRandom: vtable 0x80662538 slot 3 (0x802AC860) returns the pointer at
 * 0x8061E644 -> "cRandom". Its weights-list helper (vtable 0x806625D0: parse
 * 0x8027021C, dtor 0x8026FF08; ctor 0x8026FEB8) is also used by
 * randomloadedchooser.cpp. An assert names one of its members:
 * "value >= 0.0 && value <= mAssetWeights[top]...". "a" and "weights"
 * (0x805DC538, 0x805DC53C) are global arrays: other units pass them too.
 */
#include "game/chooser.h"
