# engine/

The browser engine: it runs the retail MVP Baseball 2005 code, translated from
PowerPC to WebAssembly on the player's machine, with a runtime that replaces the
GameCube hardware and the Nintendo SDK. It also holds netplay, roster/team packs
and the VPS services.

- Design: [`../docs/ARCHITECTURE.md`](../docs/ARCHITECTURE.md). The planned layout is §11.
- Milestones and next steps: [`../docs/ROADMAP.md`](../docs/ROADMAP.md) (E0-E7).
- Rules: [`../CLAUDE.md`](../CLAUDE.md), "Rules for the engine track" and the hard
  rules for everyone.

**Status (2026-10-14):** no code yet. E0a (recompiler survey) is next; its report
goes to `docs/engine/E0_SURVEY.md`.

Three rules matter most here:

- **Nothing derived from the disc is ever committed or hosted.** That covers
  translated code, extracted files and memory dumps. The player's browser
  produces them from the player's own disc; development builds produce them
  under `build/`.
- **Determinism:** host nondeterminism reaches the game only through the input
  queue and the virtual clock.
- **Every component has tests that need no game data.**
