# PASS-6 worker prompt template (derived from worker_prompt_p5.md; batches from gen_p6.py)

Substitute `<N>`, `<NN>`, `<SCRATCH>` as for p4.

---

You are a matching worker on a private matching decompilation of MVP Baseball 2005 for GameCube. This is PASS 6, the sweep: the target is every function that has NO source yet (objdiff 0%), up to 0x800 bytes, smallest first. Some of these were never attempted (an earlier batch ran out of time); others were tried and dropped, so expect some hard shapes. Spend your time where a match is likely: skip a function after 10 minutes without clear progress. The unit's existing source, headers and near-miss notes are your best guide. In the worktree, first read `prompts/11_TEAM_WORKER.md` (including "Quick tips"), then `CLAUDE.md`, then `docs/PATTERNS.md` (skim; the newest sections at the end, including "Hard-case families 6" and "Pass 5", hold the most useful recipes), then the "Code overlay units" entry in docs/DECISIONS.md.

- WORKTREE: C:\Users\Patrick Taylor\decompile_mvp_04-W<N> (bash /c/Users/Patrick Taylor/decompile_mvp_04-W<N>), BRANCH work/p6-<NN> (already created at origin/main; stay on it). Run configure.py + ninja first. Work ONLY in this worktree; never touch another worktree or the owner checkout `decompile_mvp_04` except to read the tools below.
- UNITS: `C:\Users\Patrick Taylor\decompile_mvp_04\tools\team\lead\queue\p6_<NN>.txt`. Check configure.py for each unit's flags:
  - game units use game flags (a few game-dir units use EA-lib flags; check configure.py);
  - fe units: every definition carries `FE_OVERLAY`. db units: `extern "C"` + `DB_OVERLAY`. Two incompatible fe header families exist (tu_8043FDC0.h FeObj vs fe_80459228.h FeW); use whichever the unit already includes.
  - dolphin/sdk units: MWCC; no `#pragma`, no inline assembly; skip hand-written (original-code) functions such as PPCArch/mtspr users.
- `tools/match/m2c_draft.py` works on overlay units.
- Make a worklist from build/GV4E69/report.json: functions in your units with fuzzy_match_percent == 0 (or missing) and size <= 0x800, sorted by size. Write each from its m2c draft, typed with the unit's existing structs.
- Give each function at most about 20 minutes (30 for functions over 0x400). If it is not 100% by then, keep it only if it is at least 95% and builds (with a /* near-miss */ note); otherwise drop it and move on. Do NOT re-try existing near-misses.
- Identical masked instruction words do NOT mean a match: branch destinations count.
- Never write a symbol's address as an integer literal (in code or in a local table initializer): name the symbol (`extern char lbl_X[];` and use `lbl_X`). check_literals resolves pointers to externs (since 2026-10-12), so the symbolic form checks clean.
- Functions appended after a unit's `extern "C" {}` block need their own `extern "C" { }`.
- Recipes:
  - switch kind-checks written index-first keep the case value live;
  - compare operands loaded via inline accessors;
  - frames-to-seconds conversions via an inline `Secs(n)`;
  - a volatile field subset for callback structs;
  - pool floats as literals (verify every value with check_literals; strings too);
  - the last-written store is emitted first; hill-climb prologue stores with `Q12/hc12.py`;
  - the callee's TRUE return type (`W8o5/rettoggle.py`);
  - pass-through params;
  - base-first lwzx `char* b = (char*)x + K; int off = i*4; *(int*)(b + off)`;
  - a dummy `case 0: break;` for the switch root;
  - fe widget views (`Q16/mkcls.py`);
  - inline ctor chains for array-with-buffer objects;
  - a local holder pointer for +0xDC sub-object calls;
  - a goto chain to stop jump threading where retail keeps redundant tests.
- Tools: repo tools first (`python tools/match/clone.py <unit> --write` before anything else). Helper scripts are in `C:\Users\Patrick Taylor\decompile_mvp_04\tools\team\lead\worker_tools\` (bash: `T="/c/Users/Patrick Taylor/decompile_mvp_04/tools/team/lead/worker_tools"`). Run them with the worktree as the current directory and `export QDIR=<your scratch dir>`; they read and write the current worktree only. Read a script's docstring before using it.
  - `Q16/` (put.py, vt.py, vdir.py, perm.py, rd.py, mkcls.py);
  - `Q12/` (applyv.py, rmfn.py, hc12.py, ins.py);
  - `Q22/hill.py`;
  - variant scoring `Q27/rv.py`;
  - flag probe `TAIL/probe.py`.
  - decomp-permuter, standard for any near-miss (C and C++ units): `python tools/match/permute.py <unit> <fn> --setup-only` (1-3 s) tells whether the function is usable (it refuses ctors, methods, named-return functions); then `python tools/match/permute.py <unit> <fn> --minutes 15 -j 2` in the background. Port a 0-score candidate (build/permute/<fn>/output-0-*/source.c) into the source by hand and verify as usual. At most one permuter run at a time; the machine is shared.
- Installing code: `Q12/ins.py <unit> <fn> <file> --auto` inserts without re-sorting; `Q16/put.py` and plain ins.py re-sort via sort_functions, which can move a `static inline` helper below its users and break the build.
- A function with an unmangled symbol that another unit references can't be renamed by rename.py: define it `extern "C"`. A callee called with more arguments than its definition needs an `extern "C"` declaration under its exact mangled symbol name.
- Write Python helpers with the Write tool, not heredocs. Preserve line endings (never `sed -i` on sources: it strips CRLF). Never write the word "asm" in source, even in comments.
- Twelve other workers share this machine. Kill only processes you started yourself (by the PID your own command returned); never kill by name or command-line pattern.

Before each commit:
- Run a full `ninja`, then `python tools/match/check_literals.py <unit>`, which must report 0 mismatches.
- One unit per commit, message `match(<unit path>): <function> [N/M funcs]`, ending with the line `Co-Authored-By: Claude Sonnet 5.5 <noreply@anthropic.com>`. A kept near-miss uses `match(<unit path>): <function> near-miss NN.N% [N/M funcs]` (never `wip(`).

Scratch: `<SCRATCH>\Q6_<NN>\` (already exists; keep all scratch files there, never in the worktree). Verify with `python tools/verify/verify.py --baseline-ref $(git merge-base HEAD origin/main)`. If verify fails with an HTTP error during its baseline build, re-run it. Timebox: work until <END> CDT by the wall clock (check with `date`; don't estimate elapsed time). Stop early only if every function in your worklist is matched or parked. Commit locally; do not push, merge, rebase or reset. Before reporting, make sure none of your own background jobs are still running (wait for them or stop them by PID); a running job wakes you again after the report. Report per unit: before/after matched, what blocked the rest.
