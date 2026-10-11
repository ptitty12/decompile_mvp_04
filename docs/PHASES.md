# Phases and exit criteria

Each phase has a hard, checkable exit. Don't advance on vibes.

## Phase 0 — Recon
Answer everything in `RECON_CHECKLIST.md`; write `docs/RECON_REPORT.md`.
**Exit:** owner approves a path (CodeWarrior matching / GCC matching / functional).

## Phase 1 — Scaffold
dtk-template (or equivalent) set up; DOL split into objects; CI in place.
**Exit:** `ninja` (or the build command) produces a DOL whose SHA-1 equals the
original, built entirely from split assembly. objdiff confirms at least one small
SDK function matches with the chosen compiler + flags.

## Phase 2a — Toolchain lock-in (SDK and small units)
Match small SDK/runtime units first. They have public reference decomps and
pin down compiler version and flags.
**Exit:** ≥10 SDK units fully matched with one consistent compiler/flag set
(or documented per-unit flag differences in DECISIONS.md).

## Phase 2b — Game code
Work outward from the code you care about most. Suggested order:
1. Small leaf utilities (math, string, containers) — they teach the codebase.
2. Data loading / file formats (roster, ratings, save data).
3. Sim and gameplay logic: pitch/bat/ball physics, ratings → outcomes,
   franchise/dynasty sim. (This is the "interesting part.")
4. Rendering, audio, UI — largest and least interesting; last.
**Milestones:** 25% / 50% / 75% / 90% of game functions matched.
**Exit:** game logic needed for a playable game is matched or semantically
verified; remaining unmatched functions documented with reasons.

## Phase 3 — Port (optional, separate branch/repo)
Only after Phase 2 exit. The matching tree stays pristine; the port lives in a
fork that may change anything.
1. Abstraction layer for GX graphics, audio, input, file I/O, memory card.
2. Native PC build (SDL + a GX→modern graphics translation layer).
3. WebAssembly build via Emscripten.
4. Private hosting: static files on your own server, behind real auth
   (e.g., Cloudflare Access or Tailscale-only). The game's assets load from the
   player's own disc image at runtime; never host the assets.
**Exit:** you can play a full game in a browser tab, privately.

## Scaling agents
- Phase 0–2a: one agent, interactive. You watch.
- Phase 2b: 2–4 agents on separate units/branches after a week of clean audits.
- Only add cheaper/faster models once the verifier is solid; strict PASS/FAIL
  makes weaker models usable, loose criteria makes them dangerous.
