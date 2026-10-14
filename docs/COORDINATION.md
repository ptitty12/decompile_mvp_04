# Coordination between agents (Claude and Codex)

Several agents work on this repo at once: Claude Code sessions (a lead, its
workers, side sessions) and Codex sessions (a coordinator, an integrator, swarm
workers). They can't message each other natively, so they coordinate through
`tools/coord.py`. It keeps a shared roster, unit claims, an integration lock
and an inbox in `<main repo>/.git/coord`. Every worktree and local clone on
this machine resolves to that same directory.

The project rules in `CLAUDE.md` apply to every agent, whichever tool runs it.

## Who is who

Names are `<tool>-<role>[-<n>]` and are unique while live:

| Name | Who |
|---|---|
| `claude-lead` | The Claude lead: assigns Claude workers, integrates their branches, arbitrates conflicts |
| `claude-w<N>`, `claude-side-<topic>` | Claude workers and side sessions |
| `codex-coordinator` | The Codex swarm coordinator |
| `codex-integrator` | Codex's integration clone (`decompile_mvp_04-SWINTEGRATE`) |
| `codex-sw<NN>` | Codex swarm workers |

`python tools/coord.py who` prints the live roster: name, tool, role,
worktree, branch, claimed units and who holds the integration lock. An agent
counts as live while it has run any coord command in the last 45 minutes.

## The protocol

1. **Start of a session or batch:** register, look around, read your messages.
   ```
   python tools/coord.py register codex-sw03 --tool codex --role worker --note "fe batch 21"
   python tools/coord.py who
   python tools/coord.py inbox codex-sw03
   ```
   A lead or coordinator may register its workers for them with
   `--worktree <path>`, and claim units on their behalf.
2. **Before editing a unit, claim it.** A unit another live agent holds is
   refused. Pick another unit or message the owner. `--steal "<reason>"`
   takes it anyway; that is logged and the owner gets a message, so use it
   only for abandoned work.
   ```
   python tools/coord.py claim codex-sw03 fe/tu_804FE34C fe/tu_80516990
   ```
   For a large edit to a shared file (a header layout change, a configure.py
   or splits.txt restructuring), claim `shared:<path>` too, e.g.
   `shared:include/game/fe_80471EBC.h`. Append-style edits don't need it:
   the merge drivers handle them.
3. **Every push to main holds the integration lock,** including docs-only and
   tools-only pushes. Wrap the whole gate and push in `run-locked`. It waits
   its turn, refreshes the lock while the gate runs and always releases it:
   ```
   python tools/coord.py run-locked claude-lead --purpose "merge nm-08" -- python tools/team/integrate.py --push
   ```
   Only one integrator verifies at a time, so a verified push no longer loses
   to someone else's push. The progress bot is exempt: it pushes only
   `docs/progress/`, which the gate already tolerates. A lock not refreshed
   for 45 minutes expires.
4. **When a unit is merged or abandoned, release it.**
   `python tools/coord.py release codex-sw03 fe/tu_804FE34C` (or `--all`).
5. **Talking:** `send <you> <to> "<text>"`, where `<to>` is an agent name or
   a group: `claude`, `codex` or `all`. Check `inbox` at the start of each
   batch and before each integration. Keep messages short and actionable
   (which unit, which commit, what you need).

Owner questions still go to `docs/DECISIONS.md` ("Open questions for
owner"), not to the inbox: the owner doesn't read it.

## Who decides

- Matching: objdiff and `tools/verify/verify.py`, never an agent.
- Conflicts between agents over units, shared files or integration order:
  `claude-lead` decides, and the owner can override. The Codex coordinator
  keeps running its own swarm; it just claims what it works on and takes the
  lock to push.

## Other commands

| Command | Use |
|---|---|
| `claims` / `claims --busy` | All claims; `--busy` prints live claimed units one per line (for scripts such as the permuter farm's skip list) |
| `lock <you> --purpose ...` / `unlock <you>` | The lock by hand, when the gate isn't a single command |
| `lock-status` | Who holds the lock and who is waiting |
| `log -n 30` | Recent registrations, claims, locks, steals |
| `where` | The shared state directory |
