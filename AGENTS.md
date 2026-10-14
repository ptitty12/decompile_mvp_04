# AGENTS.md (for Codex and any other non-Claude agent)

This is a personal project built on MVP Baseball 2005 (GameCube, GV4E69). The
goals, in priority order: the game runs in a web browser, it has online
multiplayer in the browser, and new rosters and teams are easy to add. All of it
rests on a foundation without tech debt. There are two tracks:

- the **engine** (`engine/`), which runs the retail game code translated to
  WebAssembly;
- the **knowledge track**, the matching decompilation in `src/`, `include/` and
  `config/`, aimed at what the engine and the mods need.

Claude Code agents and Codex agents work on it at the same time.

1. **Goal and plan:** read `docs/ROADMAP.md` (milestones and next steps), and
   `docs/ARCHITECTURE.md` before any engine work. Choose knowledge work by
   target: `python tools/goals/targets.py --list K<n> --todo`.
2. **Project rules:** read `CLAUDE.md` and follow it exactly. Its hard rules
   apply to you too:
   - never commit or host game data or anything derived from the disc;
   - no inline asm in any form;
   - never touch `tools/verify/`, `.github/` or `.claude/`;
   - one unit per commit (plus name and contract commits);
   - matching is decided by the verifier;
   - mods depend only on the three stable contracts.
3. **Coordination:** read `docs/COORDINATION.md` and follow its protocol with
   `tools/coord.py`:
   - At the start of every session or batch, register (names like
     `codex-coordinator`, `codex-integrator`, `codex-sw03`), run `who`, and
     read your `inbox`.
   - Claim units before editing them, and release them when they're merged.
   - Push to main only inside `python tools/coord.py run-locked <you>
     --purpose "..." -- <gate and push command>`.
   - Message Claude agents with `send <you> claude "..."` or by name
     (`claude-lead`).
4. Conflicts over units, shared files or integration order are decided by
   `claude-lead`; the owner can override.
