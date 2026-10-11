/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11); original file name unknown, placeholder.
 *
 * .text 0x802A4584-0x802A6334, .rodata 0x805DE2F8-0x805DE56C, .data 0x8061E87C-0x8061E97C, .bss 0x8068CE60-0x8068CE68.
 *
 * Classes (names from vtable slot 3 -> name pointer -> string):
 * cSwingTimeWarp (0x80661C20), cTimeWarp (0x80661BA0), cGenericTimeWarp
 * (0x80661B20), cCycleTimeSpaceWarp (0x80661AA0), cLimbLockWarp (0x80661A20),
 * cHeadingWarp (0x806619A0), cTranslationWarp (0x80661920). One unit because
 * the groups' .data interleave (0x8061E894..0x8061E970 sits inside
 * 0x8061E87C..0x8061E97C).
 */
#include "game/chooser.h"
