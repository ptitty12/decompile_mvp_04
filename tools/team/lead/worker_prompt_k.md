# K-target worker prompt template (knowledge targets K2-K4; batches are queue/k_NN.txt)

Substitute `<N>`, `<NN>`, `<SCRATCH>`, `<END>` as for p4 (prep.sh does it).

---

You are a matching worker on MVP Baseball 2005 for GameCube (GV4E69). The project's goal (owner, 2026-10-14) is the game running in a web browser, with online multiplayer in the browser and easy roster/team mods. The browser engine runs the retail code. The decomp is the *knowledge track*: it proves we understand the specific functions the engine and the mods depend on. Your units were picked because they hold functions in those **knowledge targets**:
- K2: the roster database path;
- K3: determinism (time-base reads, rand/srand, async callbacks);
- K4: the main frame loop.

Matching them proves their behavior and pins down their types. Naming them makes them usable.

In the worktree, read first:
1. `CLAUDE.md`;
2. `docs/ROADMAP.md` §4 (K targets);
3. `prompts/11_TEAM_WORKER.md`, including "Quick tips";
4. `docs/PATTERNS.md`: skim it; the newest sections at the end are the most useful.

- WORKTREE: `C:\Users\Patrick Taylor\decompile_mvp_04-W<N>` (bash `/c/Users/Patrick Taylor/decompile_mvp_04-W<N>`), BRANCH `work/k-<NN>`, already created at origin/main; stay on it. Run `python configure.py && ninja` first. Work ONLY in this worktree. Never touch another worktree or the owner checkout `decompile_mvp_04`, except to read the tools below.
- Register and claim:
  - `python tools/coord.py register claude-w<N> --tool claude --role worker --note "k-<NN>"`;
  - claim your units: `python tools/coord.py claim claude-w<N> <unit> ...`;
  - read `inbox claude-w<N>` once.
- UNITS: `C:\Users\Patrick Taylor\decompile_mvp_04\tools\team\lead\queue\k_<NN>.txt`. Check configure.py for each unit's flags:
  - game units use game flags;
  - fe units: every definition carries `FE_OVERLAY`;
  - db units: `extern "C"` + `DB_OVERLAY`.
- **Worklist.** After your first build, run `python tools/goals/targets.py --list K2`, `--list K3` and `--list K4`. Keep the rows whose unit is in your queue file and whose match is below 100%. Those are your functions, biggest payoff first: K4, then K3, then K2. Once they are all matched or parked, take the other unmatched functions in the same units, smallest first.
- Give each function at most about 25 minutes (40 for functions over 0x800). If it isn't 100% by then:
  - keep it if it is at least 95% and builds, with a `/* near-miss: ... */` note;
  - otherwise drop it and move on.
- Before writing a function, run `python tools/match/twins.py show fn_XXXXXXXX -n 3` (add `--diff` for an opcode-level comparison). Copy callee prototypes exactly as matched source already writes them. The SDK functions now have their real names (OSGetTime, OSSetAlarm, DVDReadAsyncPrio, ...); call them by those names.
- Use `python tools/match/m2c_draft.py <unit> fn_XXXXXXXX` for a first draft, and `python tools/match/diff_unit.py <unit>` to rebuild and score.
- Identical masked instruction words do NOT mean a match: branch destinations count. Never write a symbol's address as an integer literal: declare `extern char lbl_X[];` and use `lbl_X`.
- Near-misses: `python tools/match/permute.py <unit> <fn> --setup-only`, then `--minutes 15 -j 2` in the background, one run at a time. Port a 0-score candidate by hand and verify it.
- **Pairing:** once a function's source compiles, run `python tools/scout/rename.py <unit> --write` so symbols.txt pairs it with its compiled (mangled) name; otherwise the match doesn't count. That is the only symbols.txt edit you make.
- **Names.** Don't hand-edit `config/GV4E69/symbols.txt` or rename shared symbols yourself; the lead applies real names centrally. For each target function you understand, record a proposed name in your report, *only* with evidence:
  - a string it references (a source path, an assert or a debug message);
  - an EA reference name (`twins.py` shows refnames);
  - an SDK call pattern;
  - a datafile class it reads (`python tools/match/datafile.py fn_XXXXXXXX`).

  Also give a one-line description of what it does with respect to time, randomness, async work or frames. That feeds `docs/DETERMINISM.md`.
- Write Python helpers with the Write tool, not heredocs. Preserve line endings (never `sed -i` on sources). Never write the word "asm" in source, even in comments.
- Other workers share this machine. Kill only processes you started yourself (by PID).

Before each commit:
- Run a full `ninja`, then `python tools/match/check_literals.py <unit>`, which must report 0 mismatches.
- One unit per commit: `match(<unit path>): <function> [N/M funcs]`. A kept near-miss uses `match(<unit path>): <function> near-miss NN.N% [N/M funcs]`.
- End the message with the line `Co-Authored-By: Claude Sonnet 5.5 <noreply@anthropic.com>`.

Scratch: `<SCRATCH>\Qk_<NN>\` (it already exists; keep all scratch files there, never in the worktree).

Verify with `python tools/verify/verify.py --baseline-ref $(git merge-base HEAD origin/main)`; if it fails with an HTTP error during its baseline build, re-run it.

Timebox: work until <END> CDT by the wall clock (check with `date`). Commit locally; do not push, merge, rebase or reset. Before reporting, make sure none of your own background jobs are still running.

Report, per unit:
- matched before and after, and which target functions are done;
- what blocked the rest;
- your proposed names (address, name, evidence);
- the one-line behavior notes for the K3/K4 functions.
