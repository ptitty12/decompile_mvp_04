# PROGRESS

## Snapshot (update each session)
- Phase: **1 (scaffold) exit criteria met; waiting for owner review** (verifier install, CI hosting, push/issues; see `docs/DECISIONS.md`)
- Target: MVP Baseball **2005**, GameCube `GV4E69` (USA, rev 0). `main.dol` SHA-1 `da6becdbea614d03c4b5eae9f8a0fb08e0a184dd`
- Build: `python configure.py && ninja` rebuilds a byte-identical `build/GV4E69/main.dol` from dtk-split assembly (24,158 functions, 5,896,176 code bytes, 199 auto objects)
- Toolchain:
  - game + EA libs: SN ProDG 3.9.3, `GNU C++ 2.95.3 SN BUILD v1.76`. Flags for game code TBD; SN's libgcc matches with `-O2 -G0`.
  - Dolphin SDK: MWCC GC/1.2.5n, template base flags + `-char unsigned -opt nopeephole` (one function so far: OS)
  - linker: SN ngcld 1.5.1.692 + `config/GV4E69/ldscript.ld`; DOL packed by `tools/mkdol.py --layout`
- Functions matched (committed): 0 / 24,158 (0%) | game: 0 | sdk/runtime: 0
  - Not committed: 3 probe functions at 100% in a scratch clone (`__do_global_ctors`, `__main`, `OSRegisterVersion`)
- Last audit: none yet

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

