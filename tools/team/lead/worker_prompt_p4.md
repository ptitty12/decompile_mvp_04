# PASS-4 worker prompt template (as sent to p4_22..p4_33 workers)

Substitute `<N>` (worktree number, e.g. 5 or 7s3), `<NN>` (batch, e.g. 22), and the per-unit flag notes.
UNITS/scratch paths: the old session used `...\scratchpad\p4_NN.txt` and `...\scratchpad\Q4_NN\`;
a new lead should point at `C:\Users\Patrick Taylor\decompile_mvp_04\tools\team\lead\queue\p4_NN.txt`
and give a scratch dir in its own scratchpad. The helper tools named below were copied to
`tools/team/lead/worker_tools/<same subdir>/` (some hardcode a worktree path near the top; edit before use).

---

You are a matching worker on a private matching decompilation of MVP Baseball 2005 for GameCube. This is PASS 4: the target is functions that have NO source yet (objdiff 0%), up to 0x400 bytes, smallest first. Earlier passes covered these units. In the worktree, first read `prompts/11_TEAM_WORKER.md` (including "Quick tips"), then `CLAUDE.md`, then `docs/PATTERNS.md` (skim; the newest sections at the end, including "Hard-case families 6", hold the most useful recipes), then the "Code overlay units" entry in docs/DECISIONS.md.

- WORKTREE: C:\Users\Patrick Taylor\decompile_mvp_04-W<N> (bash /c/Users/Patrick Taylor/decompile_mvp_04-W<N>), BRANCH work/p4-<NN> (at origin/main). Run configure.py + ninja first.
- UNITS: `C:\Users\Patrick Taylor\decompile_mvp_04\tools\team\lead\queue\p4_<NN>.txt`. Check configure.py for each unit's flags:
  - game units use game flags (a few game-dir units use EA-lib flags; check configure.py);
  - fe units: every definition carries `FE_OVERLAY`. db units: `extern "C"` + `DB_OVERLAY`. Two incompatible fe header families exist (tu_8043FDC0.h FeObj vs fe_80459228.h FeW); use whichever the unit already includes.
  - dolphin/sdk units: MWCC; no `#pragma`, no inline assembly; skip hand-written (original-code) functions such as PPCArch/mtspr users.
- `tools/match/m2c_draft.py` works on overlay units.
- Make a worklist from build/GV4E69/report.json: functions in your units with fuzzy_match_percent == 0 and size <= 0x400, sorted by size. Write each from its m2c draft, typed with the unit's existing structs.
- Give each function at most about 20 minutes. If it is not 100% by then, keep it only if it is at least 95% and builds (with a /* near-miss */ note); otherwise drop it and move on. Do NOT re-try existing near-misses.
- Identical masked instruction words do NOT mean a match: branch destinations count.
- Functions appended after a unit's `extern "C" {}` block need their own `extern "C" { }`.
- Recipes:
  - switch kind-checks written index-first keep the case value live;
  - compare operands loaded via inline accessors;
  - frames-to-seconds conversions via an inline `Secs(n)`;
  - a volatile field subset for callback structs;
  - pool floats as literals (verify every value with check_literals; strings too);
  - the last-written store is emitted first; hill-climb prologue stores with `worker_tools/Q12/hc12.py`;
  - the callee's TRUE return type (`worker_tools/W8o5/rettoggle.py`);
  - pass-through params;
  - base-first lwzx `char* b = (char*)x + K; int off = i*4; *(int*)(b + off)`;
  - a dummy `case 0: break;` for the switch root;
  - fe widget views (`worker_tools/Q16/mkcls.py`);
  - inline ctor chains for array-with-buffer objects;
  - a local holder pointer for +0xDC sub-object calls;
  - a goto chain to stop jump threading where retail keeps redundant tests.
- Tools:
  - `python tools/match/clone.py <unit> --write` first;
  - `worker_tools/Q16/` (put.py, vt.py, vdir.py, perm.py, rd.py);
  - `worker_tools/Q12/` (applyv.py, rmfn.py);
  - `worker_tools/Q22/hill.py`;
  - variant scoring `worker_tools/Q27/rv.py`;
  - flag probe `worker_tools/TAIL/probe.py`.
- Write Python helpers with the Write tool, not heredocs. Preserve line endings (never `sed -i` on sources: it strips CRLF). Never write the word "asm" in source, even in comments.

Before each commit:
- Run a full `ninja`, then `python tools/match/check_literals.py <unit>`, which must report 0 mismatches.
- One unit per commit, message `match(<unit path>): <function> [N/M funcs]`.

Scratch: `<your scratch dir>\Q4_<NN>\`. Verify with `python tools/verify/verify.py --baseline-ref $(git merge-base HEAD origin/main)`. If verify fails with an HTTP error during its baseline build, re-run it. Timebox about 2.5 hours. Do not push. Report per unit: before/after matched, what blocked the rest.
