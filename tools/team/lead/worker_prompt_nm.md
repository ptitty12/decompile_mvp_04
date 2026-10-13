# NEAR-MISS (permuter) worker prompt template (C and C++ units; batches queue/nm_NN.txt from gen_nm.py)

Substitute `<N>`, `<NN>`, `<SCRATCH>`, `<END>` as for p6 (prep.sh does it: `prep.sh W<n> nm <NN>`).

---

You are a matching worker on a private matching decompilation of MVP Baseball 2005 for GameCube. This is a NEAR-MISS pass: the target is functions that already have source and score 90-99.99% in objdiff. Most remaining differences are register allocation, scheduling or store order. The main tool is the decomp-permuter wrapper `tools/match/permute.py`, which handles C units and C++ units (it renders the function as C for mutation and splices candidates back into the real unit for compiling). In the worktree, first read `CLAUDE.md`, then the docstring of `tools/match/permute.py`, then skim `docs/PATTERNS.md` (the newest sections at the end) and the "Code overlay units" and SDK entries in docs/DECISIONS.md.

- WORKTREE: C:\Users\Patrick Taylor\decompile_mvp_04-W<N> (bash /c/Users/Patrick Taylor/decompile_mvp_04-W<N>), BRANCH work/nm-<NN> (already created at origin/main; stay on it). Run `python configure.py`, `ninja` and `ninja build/binutils` first. Work ONLY in this worktree.
- UNITS: `C:\Users\Patrick Taylor\decompile_mvp_04\tools\team\lead\queue\nm_<NN>.txt`. Worklist: from build/GV4E69/report.json, every function in these units with 90 <= fuzzy_match_percent < 100, highest first.
- Skip original hand-written code: functions whose retail code uses mfmsr/mtmsr, mfspr/mtspr, mftb, sync/isync, psq_l/psq_st or other instructions C cannot emit (the unit headers and DECISIONS list many of them). Read the diff first (`python tools/match/diff_unit.py <unit> <fn>`) and skip a function whose only difference is such an instruction.
- For each function:
  1. Look at the diff. If the fix is obvious (a type, signedness, statement order, a temporary), try it by hand first (5 minutes).
  2. Otherwise check it is usable with `python tools/match/permute.py <unit> <fn> --setup-only` (1-3 s; it refuses ctors, methods, named-return functions and bodies the C parser rejects; skip those). Then run `python tools/match/permute.py <unit> <fn> --minutes 15 -j 2` (in the background, output redirected to a file in your scratch dir). Run ONE permuter at a time: thirteen workers and an idle-priority permuter farm share this machine's 28 CPUs. While it runs, read the next function's diff or try hand fixes (but do not rebuild the unit the permuter is working on).
  3. A candidate (build/permute/<fn>/output-<score>-<n>/source.c) is a lead, not a result. Port the change into src/<unit>.c(pp) by hand (for C++ units, translate it back: pointers that were references, casts, member syntax), rebuild, and confirm with report.json (fuzzy == 100) or at least a higher score.
  4. Give each function at most about 25 minutes in total.
- Keep a change only if the function reaches 100%, or if it raises a kept near-miss by at least 0.5 points without lowering any other function (update its /* near-miss */ note).
- Never write the word "asm" in source, never use `#pragma`, inline assembly, or raw bytes. Preserve line endings (CRLF where the file has them; never `sed -i` on sources). Kill only processes you started (by PID); never by name or pattern.
- Before reporting, make sure none of your own background jobs (permuter runs) are still running: wait for them or stop them by PID.

Before each commit:
- Run a full `ninja`, then `python tools/match/check_literals.py <unit>`, which must report 0 mismatches.
- One unit per commit, message `match(<unit path>): <function> [N/M funcs]` (or `match(<unit path>): <function> near-miss NN.N% [N/M funcs]` for an improved near-miss; never `wip(`), ending with the line `Co-Authored-By: Claude Sonnet 5.5 <noreply@anthropic.com>`.

Scratch: `<SCRATCH>\Qnm_<NN>\` (already exists; keep all scratch files there). build/permute is gitignored. Verify with `python tools/verify/verify.py --baseline-ref $(git merge-base HEAD origin/main)`. Timebox: work until <END> CDT by the wall clock (check with `date`). Commit locally; do not push, merge, rebase or reset. Report per function: before/after %, whether the permuter helped, and what blocked the rest (also any permute.py problems, for its maintainer).
