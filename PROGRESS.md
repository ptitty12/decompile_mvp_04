# PROGRESS

## Snapshot (update each session)
- Phase: **2 (matching decompilation), in progress**
- Target: MVP Baseball **2005**, GameCube `GV4E69` (USA, rev 0). `main.dol` SHA-1 `da6becdbea614d03c4b5eae9f8a0fb08e0a184dd`
- Build: `python configure.py && ninja` rebuilds a byte-identical `build/GV4E69/main.dol` from compiled source plus remaining dtk-split assembly (24,158 functions, 5,896,176 code bytes).
- Toolchain:
  - game + EA libs: SN ProDG 3.9.3, `GNU C++ 2.95.3 SN BUILD v1.76`. Flags by library/unit are recorded in `configure.py` and `docs/DECISIONS.md`.
  - Dolphin SDK: MWCC GC/1.2.5n and GC/2.0, with evidence-backed per-library/unit flags.
  - linker: SN ngcld 1.5.1.692 + `config/GV4E69/ldscript.ld`; DOL packed by `tools/mkdol.py --layout`
- Functions matched: **20,899 / 24,158 (86.51%)**; code matched: **3,000,204 / 5,896,176 bytes (50.88%)**.
- Source-linked: **212 units, 312,792 code bytes (5.30%)**, plus 8,234 data bytes. Matched functions in unlinked units still use extracted assembly in the final DOL.
- Last audit: 2026-10-13, retail DOL hash + literal checks + unmodified verifier PASS; per-commit integration gate required before push.

## Session log (newest last)
<!-- YYYY-MM-DD | agent/model | unit | matched N, abandoned M | blockers | owner decisions needed -->
- 2026-10-10 | Claude Opus 5.5 | Phase 0 recon (no unit) | matched 0, abandoned 0 | Blocked on owner approval. Disc is 2005, not 2004. Toolchain is ProDG GCC 2.95.3 rather than CodeWarrior. No symbols; `/mvp.elf` is stripped. Missing on host: ninja, Ghidra, JDK, REA; `gh` not logged in. | Decide: target game, path (`prodg-hybrid` recommended), host (native Windows recommended), Phase 1 tool downloads, GitHub remote
- 2026-10-10 | Claude Opus 5.5 | Phase 1 scaffold (no unit) | matched 0 committed (3 probe functions 100% in a scratch clone), abandoned 0 | None blocking. Notes:
  - Upstream dtk-template can't build this game, so a ProDG pipeline was added (analysis DOL from `/mvp.elf`, ngcld + static linker script, mkdol layout packing).
  - Verified from a clean clone of `f91c043`: `main.dol: OK`. Final check from a clean clone of `4a1d8de`, with the staged verifier installed as the owner would: `VERIFY PASS` (integrity, hard rules, retail hash, regressions vs HEAD~1).
  - The verifier/CI is staged in `proposed/`, because the agent is denied the target paths. It was tested with 6 pass/fail cases.
  - GitHub issues were not created; that needs the owner's OK.
  - Ghidra/JDK/REA are still not installed (not needed yet).
  | Decide:
  - install the verifier;
  - CI hosting (self-hosted runner recommended);
  - commit the probes?;
  - original-asm SDK functions policy;
  - push + create unit issues;
  - review the Phase 1 pipeline choices.
- 2026-10-10 | Claude Sonnet 5.5 (W3) | ealib/tu_803663B0, 803666EC ... 8036E65C (12 units) | matched 24 funcs (12x __static_initialization_and_destruction_0 + 12x _GLOBAL_.I), setup fns (0x2b0-0xc40) not attempted | none | none
- 2026-10-10 | W4 (Sonnet 5.5) | ealib/tu_8036FEA0 .. tu_80376598 (issues #66-#76) | matched 22 funcs (11x static-init pair), 0 abandoned; 44 large funcs (0x224-0x8x0 param-table ctors/creators) not attempted | none | none
- 2026-10-10 | W5 (Claude Sonnet 5.5) | ealibs/tu_803D9FE8.cpp (#91), ealibs/tu_803D7ED4.cpp (#88/#89 range) | matched 20 (5/6 and 15/16), parked 2 (fn_803DA038 mr r11 near-miss after 6 variants; fn_803D8094 not attempted) | none | EA lib flags -Os -G0 provisional
- 2026-10-10 | Claude Sonnet 5.5 (W1) | dolphin/ai/AI.c (#108) | matched 6 (152 B), attempted 12, parked 6 (AIInitDMA, AIStartDMA, AIStopDMA, AISetStreamPlayState, AISetStreamVolLeft/Right: RMW on constant register base does not reproduce lis+addi base) | unmatched also: AIInit, AISetDSPSampleRate, AISetStreamSampleRate, __AI_SRC_INIT (large), 3 handlers (not attempted) | none
- 2026-10-11 | Claude Opus 5.5 (lead) + Sonnet workers | choosers (tu_80271748/940/C64 linked; tu_80271F14, tu_80272B20), swarm integration, team pipeline | main: 46 -> 142 functions at 100% (W1/W3/W4/W5 merged 74; cCircleChooser 10/11; cLinearChooser 12/13; cEvent/cHand/cPitch 18 linked earlier), every pushed merge verified per commit | Notes:
  - Owner approved the team plan (Opus lead, Sonnet workers; 7 running at session end) and gave the lead full authority; CLAUDE.md now says the owner never runs commands.
  - Flags: game code += -ffloat-store; EA libs switched -Os -> -O2 on W4's evidence (DECISIONS).
  - Found: the animation choosers/goals region is one unity TU (DECISIONS); helper-class units are code-matched but can't link standalone.
  - MISTAKE: cc5d94b (cMatrixChooser setup) reached main with a failing build: the push was gated on a pipe's exit code, not verify.py's. Fixed forward in 9f743e2 (verified against f065b4a). Since then every lead push goes through `tools/team/integrate.py --push` (lead mode), which gates on verify.py per commit.
  - Parked: see docs/NEARMISS.md (cCircleChooser slot 17 at 97.9%, others).
  | Owner: verify.py reads every `#pragma` allowlist entry as a comment (DECISIONS open question). That one-line fix is in tools/verify, which only the owner can edit; W2's 80 SDK functions wait on it.
- 2026-10-11 | Claude Opus 5.5 (lead) + up to 12 Sonnet/Opus workers | checkpoint | main: 341 -> 2052 functions at 100% since the last entry; every merge verified per commit (skeleton-only setup batches verified at HEAD) | Notes:
  - All main game .text (0x80003100..0x80340000) is now in units: real TUs where boundaries are known (7 early TUs), code-only units elsewhere (data extern). Unity-TU regions (animation choosers/goals, 0x8000F598..0x8006902C) are split per placeholder file.
  - Families found: trace wrappers (2 families, ~800 functions, generated), event/chooser/warp class boilerplate, static-dtor (__tcf_N) stubs, setter families. Recipes in docs/PATTERNS.md.
  - Hard idioms cracked: `>?` clamps, Vec3 copies inside inlines, global/local-alloc priority (docs/PATTERNS.md).
  - Incidents: a merge tool bug (stale pad name) and duplicate global __tcf_N names each broke the link checksum before push; both caught by the gate, fixed (tools updated), nothing bad reached main.
  - Not linkable yet: unity-TU parts; real TUs pending linkonce/rodata-pool questions (DECISIONS).
  | Owner: verify.py allowlist bug still open (DECISIONS); W2 (80 SDK functions) waits on it.
- 2026-10-11 | Claude Opus 5.5 (hard-case matcher, work/opus-families) | game/tu_8007FF8C, tu_80084910, tu_80089894, tu_8008CE64, tu_80037250 | matched 25: the vcall family (10, pass-through arguments to fn_80071E2C), fn_80080374, fn_800393B0 and fn_80081BA8 (same mechanism), and the CSV loader family (12, pointer locals) | Trace wrappers family B with K != 0 and N == 0 (17 functions) stay open: mechanism found (sched1 adjust_priority), but no zero-cost source; see docs/NEARMISS.md | none
- 2026-10-11 | Claude Opus 5.5 (lead) + 12 Sonnet + up to 3 Opus workers | checkpoint | main: 3,507 -> 7,750 functions at 100% (32% of all 24,158; 13.7% of code bytes) since the last checkpoint. Ranges 00-18 integrated; 19-25 running; second passes of 03/04/05/13 started.
  - Opus families rounds 1-2: vcall family, CSV loaders, roster walk, passthrough args, callee return type and sched2, cr7 scc (docs/PATTERNS.md "Hard-case families" 1 and 2).
  - Found a verifier gap: function scores ignore relocation targets (DECISIONS open question). New `tools/match/check_literals.py` and an integrate.py gate; 104 false matches on main are being fixed (work/false-matches).
  - New lead tools: tools/match/passthru.py and check_literals.py; worker brief has quick tips.
  - Next: ~10,400 functions sit in unsplit regions (0x803401A8-0x803663B0, .feoverlay, .dboverlay, EA/SDK tail). An Opus setup delegate is splitting them into code-only units.
  - Incidents: a usage limit cut off all workers once (resumed from their transcripts, nothing lost); the progress bot races lead doc pushes (rebase and rerun).
  | Owner: two open questions in DECISIONS (verify.py pragma allowlist; relocation-target checking). Neither blocks the team.

### 2026-10-11 checkpoint (lead, after range-33 / Opus families 3)
- main: 13,362 functions at 100% (of 24,158; 55%); code bytes about 23%. The remaining work is dominated by large functions.
- Merged this stretch:
  - game ranges 28, 29, 30 and pass2-04;
  - fe ranges 33-36;
  - db ranges 41 and 42 (first 3 units);
  - clone.py (repo-wide twin cloner, about 150 clones);
  - Opus families 3: two-vptr widget ctors solved, plus the callee `void*` return rule.
- Running:
  - fe ranges 37-40;
  - db ranges 42 (units 4-7) and 43-46;
  - pass-2 groups g16 and g17;
  - Opus families 4 (dead-compare switches, frame-offset locals, callee-saved permutations);
  - Opus tail setup (split about 3,500 EA-lib/SDK functions; flags survey; tu_80362FB4 -ffloat-store question).
- Queued: 31 pass-2 groups (about 120 small unmatched functions each), then large-function strategy, then the tail ranges.
- Blockers, owner-only (recorded in DECISIONS): the verify.py `#pragma` allowlist bug, which blocks W2's SDK branch; relocation-blind scoring, covered by the check_literals gate.
- Known unresolved names, not mismatches:
  - fn_803567AC: tu_80134A60 declares it as a free function; it is now `__11Unk803567AC`.
  - fn_8037B424, now `_._11Unk8037B3E8`.
  - fn_80090880: callers pass 2 arguments; use the cast recipe.
- 2026-10-11 | Claude Opus 5.5 (tail-setup delegate, work/tail-setup) | main .text tail 0x8036F44C..0x8043FDB8 | setup only: 254 code-only units (95 EA-lib, 103 runtime, 56 SDK), 0 functions matched; tu_80362FB4/tu_80365C10 moved to cflags_ealib (fn_8036344C exact there) | none | Flags per library in DECISIONS (tail entry); unconfirmed: AV, libgcc DI helpers, sdk/ pieces, dvd/mtx/exi deviations. 503 functions are port jobs from port/mvp2005 and match/W2-pad.
- 2026-10-12 | Claude Opus 5.5 (scheduled audit) | audit of origin/main `a45298cc` | read-only. **19,329 / 24,158 functions at 100%**: 80.0% of functions, 39.83% of code bytes. `verify.py --baseline-ref 5cb09b2b` gave VERIFY PASS. Full report: `docs/audits/2026-10-12.md`.
  - Clean: no cheating hits, no verifier or settings changes since the owner's installs, no game data in git history.
  - Checks passed: 10/10 random matched functions byte-identical with relocations masked; 25/25 commit `[N/M]` claims equal objdiff; `check_literals.py` found 0 mismatches over 69,494 references (1,348 unresolved names).
  - Issues:
    - Only 64/786 units are linked, and the verifier's score ignores relocations.
    - 3 owner-only verifier questions are pending.
    - 39 match commits mix units.
    - The PROGRESS snapshot above is stale.
    - The main checkout's `main` has diverged, with 2 unpushed progress-bot commits.
  - Progress bot: healthy since 2026-10-11 12:20 (7 checkout failures before that); history.csv is current.
- 2026-10-12 | Claude Opus 5.5 (lead session 2, from 10:28 CDT) | fleet coordination | **19,329 -> 19,681 functions at 100%** by 11:00 (81.5%; 41.8% of code bytes).
  - The first lead session ended at 10:20 and its 12 workers died with it. Their committed branches (p3-28, p4-22..30, p4-33) were all integrated (+345 functions, verify PASS each). Uncommitted leftovers are kept as `git stash` entries named `leftover work/<batch>`.
  - Lead kit committed (`tools/team/lead/`). Worker helper scripts made portable: they hardcoded other worktrees' paths and could have edited the wrong worktree. integ.sh no longer reports a `[remote rejected]` push as merged.
  - EXI split: EXIUart.c (`dolphin/exi/tu_804286AC.c`, 4/4) and the GXInit.c head (`dolphin/gx/tu_80428C64.c`, 3/3) were split off EXIBios.c.
  - `ealib/tu_80394744`: moved to cflags_ealib_sda_nsr instead of a re-split. Its last function is already matched there, so a split would be a verify regression.
  - HANDOFF section 7 items 6 (OSExceptionVector labels: none are mis-typed in symbols.txt) and 7 (relocname fixes: all 19 already 100%) needed no change. 228 merged stale branches were deleted.
  - Running: 13 Sonnet workers on p4_00..p4_12; 1 Opus worker on hard-case families 5, 7, 8, 9 (round 7). Queued: p4_13..p4_21, p4_32 (no commits last time), then p5 (`tools/team/lead/gen_p5.py`: 0% functions of 0x400-0x800, plus small ones in units no p4 batch covered).
  - Blockers: none new. The owner-only questions in DECISIONS are unchanged.
- 2026-10-12 | Claude Opus 5.5 (lead session 2, update 15:10 CDT) | fleet | **19,681 -> 20,118 functions at 100%** (83.3%) since the 11:00 entry; +789 this session.
  - All 13 p4 batches p4-00..p4-12 merged: 18-46 functions each (median about 30). A usage-limit cutoff at 10:55 stopped every worker; they were resumed at 13:15 with SendMessage and kept their context.
  - Lead fixes:
    - **p4-00 header merge:** two batches added the same three method declarations, and the build failed; fixed on the branch.
    - **p4-06 address literals:** two string-address tables were written as integer literals, because check_literals compared unrelocated pointer words. The functions now name the symbols, and check_literals resolves pointers to externs (repo-wide still 0 mismatches). The worker prompt forbids address literals.
    - **Worker helpers:** several (hill.py, rv.py, Q21, perm.py) wrote variants into the shared tools folder, and 295 such files were committed by mistake, then removed. They now write to $QDIR, and rv.py --apply keeps CRLF.
  - Running (13 Sonnet workers): p4-13..p4-21, p4-32b (Dolphin OS/VM, a rerun), p5-18, p5-19, p5-22. The Opus hard-case round 7 is held. The pass-5 queue (28 batches, 0% functions up to 0x800) is ordered in tools/team/lead/queue/p5_order.txt.
  - Open families from reports:
    - SumRow byte-sum loop temp registers (fn_80166E40, fn_800493D4, fn_80118770, fn_801609EC);
    - the inlined stack Unk803597C4 record ctor prologue (fn_80163390 and 3 more);
    - fn_80097318 plus 4 siblings (one shape).
  - Blockers: none new. Functions that need `mftb` stay unmatched (inline-asm-only, existing rule).
- 2026-10-12 | Claude Opus 5.5 (lead session 2, evening, 17:52-20:15 CDT) | fleet | **20,341 -> 20,582 functions at 100%** (85.2%); +241 since the 16:00 stop.
  - The fleet restarted at 17:52 when the usage window reset: 13 fresh Sonnet workers on p5 batches (0% functions up to 0x800). Every branch was merged with VERIFY PASS: p5-02 (+14), 03 (+11), 04 (+4), 08 (+19), 09 (+36), 11 (+30), 13 (+21), 14 (+20), 16 (+11), 17 (+19), 20 (+10), 21 (+13), 23 (+12), 24 (+13), 26 (+8). About 40 near-misses (95-99.99%) were committed with notes.
  - Pass 6 (`tools/team/lead/gen_p6.py`, 46 batches): every 0% function up to 0x800 in free units. Units of the p4 batches cut short at 16:00 come first. Running: p5-00/01/05/06/07/10/12/25/27 and p6-00..03.
  - Patterns: PATTERNS.md "Pass 5" section. Notably, an object with an empty inline destructor reserves an unreferenced stack slot, which explains many spare-frame-byte near-misses.
  - Incident: one worker killed every python.exe on the machine (taskkill /IM). Workers re-ran their jobs; the prompts forbid it now.
  - Walls (unchanged rules): `mftb`/`mtspr`, paired-single (psq_) kernels, a literal data word after `bl`, and g++ virtual-base destructor machinery are not attempted.
  - Blockers: none new. The owner-only questions in DECISIONS are unchanged.
- 2026-10-12 | Claude Opus 5.5 (lead session 2, update 21:40 CDT) | fleet | **20,582 -> 20,703 functions at 100%** (85.7%); +362 since 17:52.
  - p5 is finished: every p5 batch has been worked once and merged. Late merges: p5-00 (+7), 01 (+5), 05 (+5), 06 (+7), 07 (+9), 10 (+8), 12 (+11), 25 (+4), 27 (+36, the dvd.c state machine).
  - p6 so far: p6-00 (+4), 01 (+1), 02 (+4), 03 (+1), 04 (+2), 05 (+4), 06 (+8), 35 (+7). The first p6 batches (the cut-p4 game units around 0x801C-0x8022) are Vec/float-temporary heavy, with few small functions. `queue/p6_order.txt` is now ranked by the count of functions <= 0x200. The dolphin p6 batches (mostly hand-written code) are last.
  - New owner question in DECISIONS: dolphin/dvd/tu_804227D4 merges dvdfs.c and dvd.c, and fn_804227D4 is defined at the end of the file to stop inlining.
  - Tooling:
    - integ.sh rewords `wip(` near-miss commits to `match(` on the worker branch before merging (31 older `wip(` commits are already on main).
    - rv.py scores a directory, so there is no command-line length limit.
    - The p6 prompt has the near-miss commit format and the background-job rule.
  - Recurring unsolved shapes:
    - `slwi r0` vs `r11` index temps in `in->m8[id]` loops;
    - `cmpwi` before `li r3,4` in `c ? k : 4`;
    - goal-pointer copies (`mr r28,r27`) removed by cse-skip-blocks;
    - `mr r0,r3` before `cmpwi` on a call result.
  - Usage: the 5 h window was 92% used at 21:36 and the weekly limit 77%. The fleet restarts at the 22:50 window reset.

### 2026-10-12 evening (enablers: fleet dashboard, tooling only)

- Unit: none. Functions matched: 0 (tooling session).
- Added `tools/fleet_dashboard.py`. It reads git only (no build, no model calls) and reports:
  - verified and worker-claimed code and functions per hour;
  - near-miss share of commits;
  - per-worker activity, the merge backlog and sessions;
  - the functions closest to 100% in the progress bot's last build.
- `--watch` runs in a terminal. `--publish` replaces the single orphan commit on the `dashboard` branch.
  - A new scheduled task, "MVP decomp live dashboard", runs it every minute from the worktree `decompile_mvp_04-dash`. That worktree must stay.
- Pushed the two progress-bot commits that were only on the local `main` checkout (2-minute poll, rebase on a push race).
- Verify: PASS at 3738240c (20,730 functions, no regressions).
- Reading of session 3 (17:57 onward):
  - Verified code per hour held steady against session 2 (about 55-70 KB/h vs about 63 KB/h).
  - Functions per hour fell, because the remaining functions average about 860 B against about 140 B for matched ones.
  - The near-miss share of commits rose from about 4% at 18:00 to 40-60% after 21:00.
- Owner question added to DECISIONS: the GitHub repo is public.
- Later the same evening (owner approved tool downloads; lead request):
  - Added `tools/match/permute.py` and `tools/match/cxx2c.py`, which run decomp-permuter on one near-miss.
    - decomp-permuter lives at github.com/simonlindholm/decomp-permuter @8556c81, cloned in tools-ext. Its venv has toml and Levenshtein.
    - C units run on the trimmed unit.
    - C++ units run on a C rendering. Each candidate's body is spliced back into the original unit and compiled with g++.
    - Setup refuses any function whose base does not compile to the unit's own code.
  - Coverage: 51 of 60 random C++ near-misses at >= 95% set up. The refusals were constructors, static initializers and bodies the C parser can't read.
  - The lead runs a near-miss batch (queue nm_00) with it.
  - Verify: PASS at e2f3bda2 and 7dce9440.
  - Owner decisions passed on, not decided here:
    - extra usage (a cost decision);
    - a verify rule that keys regressions by address (behind the verifier lock).
- 2026-10-13 | Claude Opus 5.5 (lead session 2, final, 22:50-00:25 CDT) | fleet | **20,740 -> 20,869 functions at 100%** (86.4%). Session 2 total: 19,329 -> 20,869 (+1,540).
  - New near-miss pass with decomp-permuter tooling (tools/match/permute.py, from the enablers session, now for C and C++):
    - 7 batches in about 75 minutes: nm-00 +23 (includes the AI.c flags fix below), nm-01 +7, nm-02 +7, nm-03 +10, nm-04 +16, nm-05 +7, nm-06 +7;
    - the best yield per agent-hour of the session.
    - Nearly every match came from hand edits guided by compiler dumps (`cc1plus -dg -dl` register priorities, `-fno-gcse` A/B); permuter candidates mostly cheated (dropped calls). See PATTERNS "Near-miss pass".
  - Pass 6 final round: p6-07 +7, p6-10 +9, p6-13 +14, p6-14 +12, p6-26 +3, p6-28 +7.
  - dolphin/ai/AI: `cflags_dolphin_ai` no longer has `-opt nopeephole`, which makes every compiled AI.c function byte-identical (DECISIONS 2026-10-13).
  - Process: p6-10's branch had worker scratch files committed; the lead removed them from the branch history before merging. integ.sh now rewords `wip(` commits.
  - Stopped at 00:10 on the owner's instruction:
    - all agents stopped; leftovers stashed; orphaned permuter runs killed;
    - session crons deleted and the `mvp-decomp-lead-resume` scheduled task disabled;
    - the permuter farm, dashboard and progress bot (no tokens) keep running.
    - Resume steps are in the HANDOFF "Session 2 status" block.
  - Blockers: none new. Owner questions are unchanged (verify keyed by unit name blocks splits; public repo; extra usage; other-platform discs).


- 2026-10-13 | Codex + one focused lightweight audit | fe/tu_80488CDC.cpp; matching helpers | fn_8048A2AC matched (204 bytes), unit 42 -> 43/55; local baseline 20,794 -> 20,795/24,158 functions | Full verifier PASS against the pre-change build, retail main.dol hash unchanged, no regressions; check_literals: 261 references, 0 mismatches/unresolved. A bounded 24-order search found the final four-store ordering. Added reusable store_orders.py (scratch-only, bounded search) and fixed permute.py's missing executable flags on standalone overlay targets: fn_8048A2AC's baseline search score was 5100 against an empty target, now 10 against 51 instructions. Added empty-target/error guards and 8 synthetic helper tests, including real PowerPC assembly/disassembly. Existing fleet integration and farm were active; work stayed in an isolated Codex worktree. No owner action needed. Remaining efficiency findings: farm ledger invalidation depends only on unit source, and original-code/linking issues remain as documented.

- 2026-10-13 | Codex | matched-twin follow-up: snd/tu_803A9204, fe/tu_8051E878, ealib/tu_803D2B20, game/tu_8011243C, game/tu_801A57C8 | Five further verified matches after fn_8048A2AC: iSNDrandom (264 B), fn_8051F784 (196 B), fn_803D2B64 (92 B), fn_8011489C (208 B), fn_801A7CBC (128 B). Session total: 6 functions / 1,092 bytes. Each source commit: retail SHA1 retained, no regressions, no literal/target mismatches. game/tu_801A57C8 retains six unresolved names in other existing functions. | Shortcut: clone --scan also finds existing near-misses, although normal clone mode skips their definitions; manually adapt those matched twins before random searches. Tried 8 bounded search-loop variants for fn_80097380; none matched, no speculative source retained. Also tried volatile zero-pool declarations for fn_803A94BC; worse, discarded. No owner action needed.

- 2026-10-13 | Codex + focused lightweight linking audit | Source-link promotion / helpers | 18 fully matched units now source-linked locally: complete units 64 -> 82; complete code 15,464 -> 39,664 bytes (+24,200). All promotions retain retail SHA1 and pass the unmodified verifier without regressions, one unit per commit. Includes EXIBios (6,620 B), game/tu_80144CF0 (2,920 B), db/tu_805A1A9C (2,920 B), fe/tu_80528B78 (2,028 B), and fourteen smaller units. | Added read-only link_candidates.py: allocated section layout plus real linked-symbol imports, not fuzzy score alone. A larger game/tu_800C2F90 source-link trial failed on unresolved canonical/mangled call names; reverted its config, no speculative source kept. Source naming established _exit at 0x80413F3C and __div2i at 0x80406CC0 from observed runtime calls/stub destinations; their original code remains untouched. No owner action needed.

- 2026-10-13 | Codex | Vector norm | fn_80402A90 matched (60 B), unit ealib/tu_804027DC 29 -> 30/34. Session matching total: 7 functions / 1,152 bytes. A reused float temporary reproduced the target load/operation schedule; direct expression and six load-order probes did not. Full verifier PASS, no regressions or literal/target discrepancies.
- 2026-10-13 | Codex | Source-link follow-up | 18 further units, +58,988 linked code bytes: packed-tag helper correction unlocked 15 trace-wrapper units (+45,344 B); canonical strncpy unlocked fe/tu_80464090 (+5,136 B); canonical memcpy plus per-unit -fno-builtin unlocked game/tu_803543FC (+5,744 B) and game/tu_80353930 (+2,764 B). Session source-link gains: 36 units / 83,188 B; complete units 64 -> 100, code 15,464 -> 98,652 B. Every promotion retained retail SHA1, passed the unmodified verifier without regressions and passed literal/target checks. The shared packed-tag header correction rebuilt all seven users before promotion. Source changes and config remain one unit per commit; final per-commit integration gate also required. | Shortcut: fix one evidence-backed declaration shared by many exact objects before spending time on isolated near-misses. No owner action needed.

- 2026-10-13 | Codex | Matched twins and C import follow-up | Three further exact functions: fe/tu_804C931C fn_804CA2F0 (56 B, switch cases 4/5), ealib/tu_80394744 fn_80394CE0 (264 B, additive generator twin with unsigned state view), game/tu_800034A0 static initializer (3,556 B, 13 normalized global vectors). Session matching gains: 10 functions / 5,028 code bytes, plus 156 B matched BSS. Initializer names corrected to the compiler-generated static initializer and wrapper; verifier accepts same-unit/address/size renames without regressions. Actual target point values retained; plain explicit assignments failed, genuine C++ global initialization matched all 889 instructions.
- 2026-10-13 | Codex | Csis/allocator source-link sweep | 13 more verified source-linked units (+65,808 B): two shared C linkage fixes unlock ten units; three local deallocator-call repairs unlock another three. Every source-linked promotion retains retail DOL SHA1 and passes literal checks and the unmodified verifier. Session source-link gains: 49 units / 148,996 B; complete units 64 -> 113, linked code 15,464 -> 164,460 B. New clone.py fix also copies separate inline member definitions when it copies the declaring class, including their dependencies; 4 new synthetic tests, 12 helper tests pass. Large renderer fn_803EA500 now reaches the correct 426 instructions in scratch but still fails the strict pre-check on its unresolved GXWGFifo address; left unapplied. Two multi-initializer functions in game/tu_80174318 remain parked after a bounded scratch probe. No owner action needed.

- 2026-10-13 | Codex | newlib ctype data identity | Identified _ctype_ at 0x8060E9F0 (257 bytes, including the EOF sentinel), replacing the previous interior label at 0x8060E9F1. Confirmed zero sentinel and ASCII control/space/digit/uppercase/lowercase/hex masks in retail data. Three non-libc consumers now address masks through _ctype_ + 1; all passed the unmodified verifier without regressions. A trial retaining an overlapping interior label was rejected by the splitter and reverted; the final table has one proper object name and no alias. All 531 checked references across affected consumers resolve with 0 mismatches. Seven libc units now source-link (+1,236 B): strtol, strtoul, strcasecmp, strlwr, tolower, isdigit, isspace. Session source-link gains: 56 units / 150,232 B; complete units 64 -> 120, linked code 15,464 -> 165,696 B. Final batch integration required. Unused old declarations in two game headers remain; the three actual consumers use the canonical table. No owner action needed.

- 2026-10-13 | Codex | Data ownership and unused SDK bodies | 49 more verified source-linked units / 51,144 code bytes since db183aa6. Complete units 120 -> 169; linked code 165,696 -> 216,840. Read-only data_candidates.py locates complete compiled sections using code relocation pairs, canonical sized global objects, initialized pointers and unique aligned whole-section matches. No zero-block or ambiguous search guesses. Synthetic helper suite: 27 tests PASS. Both ProDG halfword relocations and MWCC SDA21 halfword-vs-word locations are handled without changing target addresses or relocation kinds.
  - Proper section ownership unlocks private libm/newlib constants and BSS, including vfprintf, vfscanf, vfiprintf, fopen and errno. Several old anonymous pool extents crossed proven boundaries and were corrected with compiled/retail-byte evidence. DVD's 11-byte pool includes five actual zero padding bytes in its split. ef_log remains blocked by a shared/external pool reference and stays extracted.
  - Removed unused SDK definitions outside assigned target ranges, or made required private helpers static inline: GXTexture, GXTev, GXGeometry, GXBump, Padclamp, dvdidutils, EXIUart and ARQ. Every retained target function is unchanged. No target functions moved between units.
  - atexit now compiles as C++ with a C ABI export and calls the existing GC allocation wrapper fn_8000E5BC(int), whose mangled name is the retail call target. FSasync's globals received canonical reference-backed names at relocation-proven addresses, resolving other extracted callers without aliases.
  - Accepted two farm matches after scratch confirmation and the full acceptance gates: fe/tu_8046F770 fn_804707B8 (132 B, zero/one scheduling), db/tu_805721F8 fn_80573FB8 (548 B, weighted-sum operand order). Session gains now 12 functions / 5,708 code bytes; source-link gains from original session baseline: 105 units / 201,376 code bytes. Total source-linked units 64 -> 169. No owner action needed; final per-commit integration gate follows.

- 2026-10-13 | Codex + bounded Luna scratch audits | compiler-aware clones, GX FIFO family, canonical calls | matched 4 new functions / 1,976 B; source-linked 17 more units / 47,116 code B; 15 partial units retain prior scores | Each source commit passed retail hash, literal checks and unmodified verifier. New functions: OS fn_80438704 (32 B), DB fn_80594810 (112 B), FE fn_80463C64 (128 B), renderer fn_803EA500 (1,704 B). Source promotions: game/tu_80344180, game/tu_80042DBC, dolphin/vm/tu_8043D960, snd/cmn/salloc, game/tu_80360C18, and 12 GX setup units from 803666EC through 8036F44C. The shared typed FIFO view reproduces lis 0xCC01 with signed displacement for both 4- and 8-byte register unions. Retail control flow proved two calls belonged inside the mB0 condition in seven related renderer sources; whole-DOL trials caught the masked branch error. Natural global construction recovers F44C's 20-byte BSS node and ctor entry; two compiler initializer names were corrected at unchanged addresses/sizes. The clone search now preserves local-label topology and compares resolved internal branch destinations; bad/fixed real controls and 69 synthetic helper tests pass. Compiler selection is shared with MWCC C handling; farm fingerprints now include headers, flags and helper code on future starts, with exact trial restoration. Existing farm was not restarted. Parked: D9C34 cannot source-link alone because its hand-coded startup wrapper lacks the owned ctor entry and its initialization body lies in the preceding placeholder unit. DB's two remaining near misses did not improve in bounded probes. D8234's nearer fn_803D83BC keeps its old symbol view; DA4EC's helper change regressed fn_803DBBE0 and was rejected. No owner decision needed. Per-commit integration gate pending before push.


- 2026-10-13 | Codex + bounded Luna scratch audits | ABI/import recovery and near misses | Seven new exact functions / 2,992 code bytes since 88de073d; fifteen more source-linked units / 24,960 code bytes. Complete units 186 -> 201, linked code 263,956 -> 288,916 B; exact functions 20,885 -> 20,892 and matched code 2,995,596 -> 2,998,588 B. All source commits pass retail SHA1, literal checks and the unmodified verifier without regressions; per-commit integration follows.
  - New functions: game fn_8012C2BC (508 B), fn_8022A71C (536 B), fn_8001DEC0 (404 B), Cpu::fn_80238934 (268 B), fn_80245730 (248 B), ealib fn_803F28A4 (460 B) and fn_803F2A70 (568 B). The three control-flow repairs retain retail null handling and branch destinations. The last two reproduce load-before-store ordering with explicit real-value locals.
  - Six fully matched game units source-link after actual runtime/C++ declarations replace unresolved placeholders: 803414A4, 803560F8, 80360168, 8035688C, 80352E64 and 8035726C. Typed placement construction and existing deallocators preserve destructor work. Eight text-only CARD consumers source-link using existing exported fn_/lbl_ symbols and proper SDK parameter types; no provider aliases or metadata renames were needed.
  - game/tu_8007A4DC now source-links 4,664 B. Retail callers establish float results and incoming arguments omitted from three wrapper declarations; all sixty functions keep their offsets, sizes, instruction words and local branch destinations. Three method manglings were corrected at unchanged addresses/sizes. Provider-specific C overloads and pointer casts stay local, preserving other header users. Shared header changes are limited to the corrected wrapper methods.
  - fn_80090880 explicitly forwards the incoming localization ID to fn_80402CAC. First migrated the already-linked FE caller onto the table-manager header, then corrected the provider signature and symbol metadata in its own commit, then removed the temporary function-pointer cast. Every intermediate commit passed. This unlocked tu_8035726C without mixed-unit commits or aliases.
  - Store-order helper now accepts decimal/exponent float literals while rejecting expressions and repeated fields; 70 helper tests PASS. A read-only scratch scan found 100 near misses within two instruction words with identical local branch paths. Parked after bounded probes: CARDInit extra instruction; tu_8007DB74 still needs argument tracing; fn_802B2C98's 120 float-store orders did not match; reciprocal stack-slot and several index/minimum forms did not improve. Existing farm remains running. Session gains from the original baseline: +23 exact functions / 10,676 code B; +137 source-linked units / 273,452 code B. No owner action needed.

- 2026-10-13 | Codex + two bounded Luna audits | Return layouts, wrapper ABI and helper checks | Four further exact functions / 1,004 B; two source-linked units / 9,940 B since 48722645. Exact functions 20,892 -> 20,896, matched code 2,998,588 -> 2,999,592 B; source-linked units 201 -> 203 and code 288,916 -> 298,856 B. All source changes retain retail SHA1, pass literal/target checks and the unmodified verifier without regressions. Per-commit integration required before push.
  - fn_8001EE28 (396 B) uses the callee's actual eight-byte pair instead of a twelve-byte buffer; Unk80159F28::fn_801653B0 (320 B) uses the actual Pair8 return; fn_803D74A0 (76 B) uses the actual five-word result. Callee definitions/retail accesses establish each extent; every instruction and local branch matches, with actual objdiff 100%.
  - game/tu_8007DB74 source-links 5,668 B after canonical provider imports and explicit incoming arguments omitted from six reconstructed signatures. Metadata renames preserve addresses/sizes; no aliases. game/tu_8007CAC4 source-links 4,272 B after real provider types and nine void setter return corrections. Both current shared declaration views were corrected; all users rebuilt. This also makes the existing caller fn_800E25E0 (212 B) exact. Status-returning providers remain int.
  - New read-only frame_candidates.py narrows searches to equal-length instruction streams with only stack-relative offset changes, different frames and equal internal branch paths. Clone checks now cover all executable sections, including objects with both text and overlays. 77 helper tests PASS; synthetic fixtures prove mixed-section scanning and reject changed overlay branches. Current game objects had no mixed-section gap.
  - Parked without source edits: fn_cslot11 has no evidence for changing its Vec3 extent; fn_8058C3C4's seven bounded signature/local/known-zero variants did not improve its seven-slot schedule mismatch. The fn_8035AB44 destructor in-charge forwarding issue remains parked. Existing farm continues. Session gains from original baseline: +27 exact functions / 11,680 matched code B; +139 source-linked units / 283,392 code B. No owner action needed.

- 2026-10-13 | Codex + three bounded Luna workers | Farm matches and final near-miss audit | fn_803F1204 (208 B) and fn_803F113C (200 B) from the running farm, plus same-family fn_803F12D4 (204 B), now match exactly. Replaced arbitrary permuter names with initialized active state locals; storing -active and active retains retail constant scheduling and the original values. Word streams, branch paths and named imports were checked before full hash/literal/unmodified-verifier acceptance. Session gains: +30 exact functions / 12,292 matched code B; +139 source-linked units / 283,392 compiled code B. Total exact functions 20,899 / 24,158; matched code 3,000,204 / 5,896,176 B. Source linking remains 203 units / 298,856 code B / 8,062 data B.
  - Expanded to three lightweight agents at the owner's request; tasks use disjoint functions and scratch candidates. fn_803F0FCC improved five -> three differing words with the same new mechanism, still unmatched. Three fn_803F108C variants regressed. No new evidence supports the unusual absolute constant forms in fn_803F13A0. Shared docs/NEARMISS.md now consolidates failed bounded probes to prevent repeated work across agents. 77 helper tests PASS; protected verification files untouched. Final per-commit integration remains required before push.

- 2026-10-13 | Codex + three bounded Luna workers, resumed at owner's request | Seven more source-linked units, +10,184 code B / +56 data B since 9ff739dd. Complete units 203 -> 210; compiled code 298,856 -> 309,040 B; compiled data 8,062 -> 8,118 B. Exact-function count remains 20,899; these are source-link gains in already-matched functions. Every accepted change passes retail SHA1, literal checking and the unmodified verifier; per-commit integration follows.
  - DVD error code unit (408 B): use the RTC type header instead of internal __os.h, eliminating five irrelevant startup declarations. AMC stubs (40 B): omit the out-of-split AMC_IsStub definition. OSRegisterVersion (44 B): reference the existing four-byte format object, preserving the target's small-data reference without claiming ownership at a misaligned new allocation.
  - DVD queue (504 B + 32 B BSS): omit the two out-of-split diagnostic/queue functions and their private debug table, and mark the internal pop helper inline. All five retail function streams and local branches stay exact; paired relocations anchor the real queue array at 0x806DE1F8.
  - Double/float ceil (344/196 B + 16/8 B data): mutable huge objects and x+huge arithmetic reproduce the exact instructions and writable small-data blocks. The former const definition produced an unreferenced read-only duplicate with ambiguous ownership; no pool was placed by guessing. Public reference licenses preserved.
  - game/tu_800C2F90 (8,648 B): canonical C/C++ import types plus guarded real deallocation retain all sixty functions and 152 branch edges. Before linking it, corrected fn_802B96A4's actual three-integer arguments and result in its provider TU; its 32-byte code is unchanged. Metadata rename Fv -> Fiii preserves address and size, with no aliases or final mismatched function-pointer call. All 334 consumer references resolve and compare exactly.
  - New compiler lead: -mps-float enables ProDG __ps_t and paired-single builtins. Native lvalues fold offsets, but fn_803A3D4C remains seven words off because quantization/register encodings differ; no flags or unmatched SIMD source were accepted. Indexed builtin probes returned success without producing ELF, so their API acceptance is unproven. Scratch remains under build/agent-event.

- 2026-10-13 | Codex + three Luna workers, continued | libm/ef_log source-linked (640 code B / 116 data B): export its existing first coefficient as lbl_806F0000, which an external extracted table already references. Other coefficients remain private and unchanged. Source/target code, 20 local branch destinations and both data blocks are exact; full retail hash, literals and verifier pass. The initial wrong scratch path was rejected and restored before the correct reference was used.
  - fe/tu_804FF6B4 source-linked (3,112 code B): bind string calls to the actual strcpy/strncpy providers and TEAMNAME/TEAMCITY to their existing data symbols. All 27 functions and local edges match; 129 references check with zero mismatches/unresolved names. Full hash and verifier pass. Two independent worker audits agreed on the import addresses.
  - Read-only import_candidates.py pairs matched source/retail REL24 call sites and lists canonical exported provider names. It distinguishes conflicting destinations and unresolved imports, preserving all aliases as leads rather than selecting a guessed ABI. Seven new synthetic regression tests pass; matching-helper suite is 84/84.
  - Source-linked totals are now 212 units / 312,792 code B / 8,234 data B; exact functions remain 20,899. The table v4 argument repair is parked under the one-TU commit rule; no conditional class definitions or mismatched function-pointer calls were accepted.
