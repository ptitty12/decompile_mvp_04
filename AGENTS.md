# AGENTS.md (for Codex and any other non-Claude agent)

This is a personal matching decompilation of MVP Baseball 2005 (GameCube,
GV4E69). Claude Code agents and Codex agents work on it at the same time.

1. **Project rules:** read `CLAUDE.md` and follow it exactly. Its hard rules
   apply to you too: no inline asm in any form, never touch `tools/verify/`,
   `.github/` or `.claude/`, never commit game data, one unit per commit, and
   matching is decided by the verifier.
2. **Coordination:** read `docs/COORDINATION.md` and follow its protocol with
   `tools/coord.py`:
   - At the start of every session or batch, register (names like
     `codex-coordinator`, `codex-integrator`, `codex-sw03`), run `who`, and
     read your `inbox`.
   - Claim units before editing them, and release them when they're merged.
   - Push to main only inside `python tools/coord.py run-locked <you>
     --purpose "..." -- <gate and push command>`.
   - Message Claude agents with `send <you> claude "..."` or by name
     (`claude-lead`).
3. Conflicts over units, shared files or integration order are decided by
   `claude-lead`; the owner can override.
