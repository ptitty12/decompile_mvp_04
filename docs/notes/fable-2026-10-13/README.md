# Fable hard-function pass, 2026-10-13 evening

On the owner's request, 11 Claude Fable 5.1 workers ran from 21:28 to about 22:15 CDT. Ten worked on parked near-misses and large unmatched functions in game/ and animation/, three units each. One gathered the declaration-contract evidence Codex asked for. The pass was spun down early because the weekly all-models limit reached 100%.

Each worker kept one notes file: what fixed each match, every approach that failed and why, and leads nobody tried. Read a function's entry here before you try it again. The general compiler rules that came out of the pass are in `docs/PATTERNS.md`, section "Fable hard-function pass (2026-10-13 evening)".

| Notes | Batch | Units | Result |
|---|---|---|---|
| [W1](W1.md) | hard-00 | animation/goals/tu_8029EE50, game/tu_80334AF0, game/tu_8021ADDC | fn_802A1790 matched (frame 304 vs 312: the inline frame-block rules) |
| [W2](W2.md) | hard-01 | game/tu_8021F080, game/tu_80313C14, game/tu_8022309C | no match. fn_80221A70 at 99.72%: the two-pseudo loop pointer probably comes from loop strength reduction |
| [W3](W3.md) | hard-02 | game/tu_801EE438, game/tu_801800FC, game/tu_8018C9C8 | no match. fn_801F0004 at 99.98%: the dying store of a cse-merged float constant is scheduled first |
| [W5](W5.md) | hard-03 | animation/goals/tu_802914C8, game/tu_80338ECC, game/tu_80246D04 | fn_80249D44 matched (switch case range) and fn_80248370 matched (float position in the callee prototype) |
| [W6](W6.md) | hard-04 | game/tu_8018423C, game/tu_802E22EC, game/tu_80212AC0 | fn_801852A4 matched (named `Sub` local plus `const Vec3&` moves the frame temps) |
| [W7](W7.md) | hard-05 | game/tu_80227564, game/tu_800E4234, animation/goals/tu_8028C6B8 | no match. Found the fn_8028C6B8 missing `case 1:` bug, the BASE_REGS regclass rule and the floor_log2 tie in fn_80227564 |
| [W8](W8.md) | hard-06 | game/tu_80216CF4, game/tu_80188698, game/tu_8023DB8C | no match. fn_802198AC at 99.84%: worked out the sched1 same-constant store-order rule and how to read store order from `-dS` |
| [W9](W9.md) | hard-07 | game/tu_802028E4, game/tu_8020ADC4, game/tu_802EFF28 | fn_802F35A4, fn_8020C5FC (85% -> 100%) and fn_8020C9CC matched |
| [W10](W10.md) | hard-08 | game/tu_802BF974, game/tu_801F263C, game/tu_80241C24 | fn_802C0050 matched (moving the float parameter flips a register tie) |
| [W11](W11.md) | hard-09 | game/tu_80194D44, game/tu_80190A00, game/tu_801C6D2C | fn_801971B8 matched (99.99%: an inline's whole frame is one block) |
| [W12](W12.md) | decl-02 | provider contracts (Codex request) | no commits. Evidence and exact edits for every contract. fn_803FFA60 waits on a Codex caller fix |

"Scratchpad" paths in the notes point to the lead session's temporary folder. They were not kept. The dump harnesses they mention (ngccc -E, then cc1plus -dg -dl or -dS -dR with the game flags) are short and are described in the notes.
