# Worker prompt — one matching session

Paste this to start a solo or side matching session. Replace `<UNIT>` or leave it as "next".
Workers on the lead's team get `prompts/11_TEAM_WORKER.md` instead; the lead integrates their branches.
For parallel agents: one agent per git worktree/branch, each claims a different unit.

(Updated 2026-10-13. The original kit version opened a PR and claimed GitHub unit issues. Since the
owner's "no human in the loop" decision, agents push straight to `main` after the verifier passes,
and units are claimed with `tools/coord.py`. The 126 provisional unit issues on GitHub are no longer
used for tracking.)

---

Re-read `CLAUDE.md` now, in full. Then read `docs/DECISIONS.md`, `docs/COORDINATION.md` and the
last 3 entries of `PROGRESS.md`.

Register and look around: `python tools/coord.py register <you> --tool claude --role side`
(`<you>` is `claude-side-<topic>`), then `who` and `inbox <you>`.

Your assignment this session: translation unit `<UNIT>` (or, if "next", an unclaimed unit with
unmatched functions; `python tools/match/twins.py rank` lists them, best first). Claim it with
`python tools/coord.py claim <you> <UNIT>`. Work in your own worktree on a branch made from
`origin/main` (`python tools/swarm/provision.py <NAME> <branch>` creates a ready-to-build one).

Loop, one function at a time, per the work loop in `CLAUDE.md`:
gather evidence → write source → build → objdiff → iterate → commit.
The helpers are listed in `tools/match/README.md`; start with `diff_unit.py` and `twins.py show`.

Discipline for this session:
- After every 5 functions (matched or abandoned), re-read the "Hard rules"
  section of `CLAUDE.md` before continuing.
- Max ~8 real attempts per function. Then park it: leave your best version with
  a short `/* near-miss: ... */` comment, add a line to `docs/NEARMISS.md`, and move on.
- Never touch the verifier, CI, split output, or `.claude/`.
- If you change a shared struct or header, run the full match check before
  committing. Any regression → revert your header change.
- Use REA/Ghidra for evidence (callers, xrefs, strings, data types). Treat its
  pseudocode as a hint only.

Stop the session when ANY of these is true:
- the unit is fully matched or every remaining function has hit the attempt cap
- you've matched 25 functions (keeps context and review manageable)
- you hit something that needs an owner decision (log it in DECISIONS.md)

Before stopping:
1. Run the full build + match check from a clean state:
   `python tools/verify/verify.py --baseline-ref origin/main` must print VERIFY PASS on the exact
   commit you push, and `python tools/match/check_literals.py <unit>` must report no new mismatches.
2. Push to `main` inside the integration lock, rebasing inside the locked command (main moves while
   you wait), and verify again if anything new came in:
   `python tools/coord.py run-locked <you> --purpose "match <UNIT>" -- <rebase, verify and push>`.
   Never force-push. Commit messages: `match(<UNIT>): <functions> [N/M funcs]`, with evidence for
   any names you assigned. If you can't integrate, send the branch to `claude-lead` instead
   (`python tools/coord.py send <you> claude-lead "..."`).
3. Append a session entry to `PROGRESS.md`.
4. Release the unit: `python tools/coord.py release <you> <UNIT>`.

Report back to me with: functions matched, % of unit done, blockers, and any
decision I need to make. Keep it short and honest.
