# Worker prompt — one matching session

Paste this to start a session. Replace `<UNIT>` or leave it as "next".
For parallel agents: one agent per git worktree/branch, each claims a different unit.

---

Re-read `CLAUDE.md` now, in full. Then read `docs/DECISIONS.md` and the last
3 entries of `PROGRESS.md`.

Your assignment this session: translation unit `<UNIT>` (or, if "next", the
highest-priority open, unclaimed unit issue). Claim it by commenting on its
issue and assigning the `in-progress` label. Work on branch `match/<UNIT>`.

Loop, one function at a time, per the work loop in `CLAUDE.md`:
gather evidence → write source → build → objdiff → iterate → commit.

Discipline for this session:
- After every 5 functions (matched or abandoned), re-read the "Hard rules"
  section of `CLAUDE.md` before continuing.
- Max ~8 real attempts per function. Then record what you tried in the issue
  and move on.
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
1. Run the full build + match check from a clean state. It must pass with no
   regressions.
2. Push the branch and open a PR titled `match(<UNIT>): X/Y functions`.
   The PR description lists: matched functions, abandoned functions with a
   one-line reason each, any new/changed structs, and evidence for any names
   you assigned.
3. Append a session entry to `PROGRESS.md`.
4. Update the unit issue (progress, remaining work) and remove `in-progress`
   if you're not continuing.

Report back to me with: functions matched, % of unit done, blockers, and any
decision I need to make. Keep it short and honest.
