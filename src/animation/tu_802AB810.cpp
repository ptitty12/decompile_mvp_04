/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): unity-TU tail, first half: inline getters, implicit dtors (emitted at the end of the TU). Original file boundary unknown; placeholder.
 *
 * .text 0x802AB810-0x802AC2CC only: this region's data is interleaved with
 * other parts of the TU, so every data object it uses is declared extern by
 * its lbl_ name (no .rodata/.data split for this unit).
 */
