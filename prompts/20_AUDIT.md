# Audit prompt — run every few days, in a fresh session

---

You are auditing this repository, not adding to it. Do not match new functions.
Read `CLAUDE.md` in full first.

Check and report on each of the following. Cite file paths and commits.

1. **Cheating scan.** Search all source for: `asm`, `__asm`, `naked`,
   `__declspec(naked)`, `#pragma` directives that weren't approved in
   DECISIONS.md, large hex/byte arrays in code files, `.incbin` used for code,
   and anything that bypasses compilation. List every hit.
2. **Verifier integrity.** Confirm the verification scripts/config hash matches
   the value CI expects, and that no commit since the last audit touched them
   (`git log` on those paths). Confirm `.claude/settings.json` is unchanged.
3. **Game data leak check.** Confirm no disc images, DOL/REL, assets, or byte
   dumps are tracked in git or present in history since the last audit. Check
   `.gitignore` still covers `orig/` and `build/`.
4. **Regression check.** Clean build + full match check. Compare matched-function
   count to the last audit's number in PROGRESS.md. Any decrease must be explained.
5. **Claims vs. reality.** Pick 10 random functions marked matched and confirm
   each passes the verifier on its own. Pick 5 PRs and check their descriptions
   match what was actually committed.
6. **Naming hygiene.** Sample 20 non-placeholder names; flag any without
   recorded evidence.
7. **Drift.** Any architectural "improvements," refactors, or modernization
   that sneaked in? Any comments justifying deviations from the original?
8. **Stuck list.** Functions abandoned at the attempt cap, grouped by likely
   cause (e.g., compiler flag mismatch, inlining, register allocation). Suggest
   which might be solvable with a project-wide decision (flag/version change).

Write findings to `docs/audits/<date>.md`, append a one-paragraph summary to
PROGRESS.md, and give me the top 3 issues needing my attention.
