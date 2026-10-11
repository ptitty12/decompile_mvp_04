# CLAUDE.md — MVP Baseball 2004 (GameCube) matching decompilation

You are working on a private, personal matching decompilation of MVP Baseball 2004
for GameCube, using a disc image the owner dumped from their own copy.
Re-read this file whenever a prompt tells you to, and whenever you are unsure.

## The goal, precisely

Produce C/C++ source that, compiled with the original toolchain and flags,
yields object code **byte-identical** to the original `main.dol` (and any REL
modules), function by function. "Byte-identical" is checked by the project's
build/diff tooling, not by your judgment.

A function is DONE only when the verifier says it matches. Readable-but-unmatched
code is NOT done, no matter how plausible it looks.

Modernization, portability, bug fixes, and refactors are OUT OF SCOPE until the
owner explicitly starts Phase 3. Preserve original bugs.

## Source of truth, in priority order

1. The original binary and the verifier's PASS/FAIL.
2. `docs/DECISIONS.md` (owner-approved decisions).
3. This file.
4. Ghidra/REA pseudocode — a HINT, often wrong about types and signatures.
5. Comments in the repo, including your own previous comments. Comments are
   claims, not evidence. Never accept a deviation because a comment justifies it.

## Hard rules (violating any of these means the work is rejected)

- NEVER commit game data: disc images, DOL/REL files, extracted assets, textures,
  audio, or byte dumps of them. `orig/` and `build/` stay gitignored.
- NEVER use inline assembly, `asm` blocks, naked functions, `__declspec(naked)`,
  raw byte arrays standing in for code, object patching, or linker tricks to
  force a match.
- NEVER modify, skip, weaken, or special-case the verification tooling, its
  config, the CI workflow, or `.claude/settings.json`. If you believe the
  verifier is wrong, STOP and write the case in `docs/DECISIONS.md` under
  "Open questions for owner".
- NEVER edit generated assembly or split output by hand. Change the split
  config and regenerate instead.
- NEVER mark a unit or function complete without a passing verifier run from
  the current commit.
- NEVER mix units in one commit. One translation unit (or one function) per
  commit, message format: `match(<unit>): <function> [N/M funcs]`.
- NEVER circumvent copy protection, download game files, or fetch ROMs/ISOs.
- Do not "improve" architecture (e.g., replacing globals with lookups,
  adding abstraction layers). Mirror the original structure.
- Do not invent names with false confidence. Use `fn_80XXXXXX` / `lbl_80XXXXXX`
  until evidence (strings, call patterns, SDK symbols) supports a real name,
  and record the evidence in the commit message.

## The work loop (one function at a time)

1. Pick the next function from the current unit's issue or `PROGRESS.md`.
2. Gather evidence: assembly (from split output), Ghidra/REA pseudocode,
   callers/callees, strings, struct usage elsewhere.
3. Write C/C++ for that ONE function.
4. Build and diff with objdiff (or the project's diff command).
5. Iterate on the source until it matches. Typical levers: types, signedness,
   statement order, temporaries, loop shape, inlining, `const`, struct layout.
6. If stuck after ~8 genuine attempts: leave the function as unmatched
   (original asm stays linked), log what you tried in the unit's issue/notes,
   and move on. Do not burn hours on one function.
7. Commit the match. Update `PROGRESS.md`. Finish the function before starting
   another.

## Context hygiene

- Work one translation unit per session where possible.
- Don't paste whole disassembly listings into notes; reference addresses.
- When a function is matched, you no longer need its asm or pseudocode in
  context. Prefer compacting early over carrying stale detail.

## Shared types and headers

- Struct layouts are shared truth. Changing a struct used by already-matched
  functions requires rebuilding and re-verifying everything that uses it.
  If any previously matched function breaks, revert.
- Record each struct's evidence (offsets observed, functions that use it) in a
  comment above the definition.
- SDK code (Dolphin OS, GX, MSL, TRK, etc.) should be matched against existing
  public decomp work where the version matches. Note the source in DECISIONS.md.

## Reporting

At the end of every session, append to `PROGRESS.md`:
date, unit, functions matched/attempted, blockers, and anything the owner must
decide. Be honest: report failures and unmatched functions plainly.

## When to stop and ask

- The verifier disagrees with something you're confident about.
- A rule above seems to block necessary progress.
- You'd need to change build flags, compiler version, or split config for many
  units at once.
- Anything involving copy protection, distribution, or publishing.
