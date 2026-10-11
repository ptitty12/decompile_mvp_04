# Swarm tools

Infrastructure for running several matching agents at once, built for the
benchmark/orchestration session's top requests (2026-10-10). None of these
verifies anything: `tools/verify/verify.py` and objdiff decide what counts as
matched.

| Script | Use |
|---|---|
| `merge_dtk.py` | Git merge driver for `config/GV4E69/symbols.txt` (3-way per section+address entry, name and attributes merged separately) and `splits.txt` (3-way per unit block, output sorted by address). Only real conflicts get markers. Wired through `.gitattributes`. |
| `install_merge_drivers.py` | Registers the drivers in the repo's shared git config, once per clone; all worktrees inherit it. `--uninstall` removes them. |
| `check_order.py [splits.txt]` | Checks that the splits allow one link order. Prints each cycle with the section ranges causing it, plus overlapping ranges. Run it before pushing a merge. |
| `provision.py NAME BRANCH` | Creates `../decompile_mvp_04-NAME` on a new branch with orig/ (extracted files and `mvp.elf`, no disc images) and the toolchain copied in, ready for `configure.py && ninja`. `--dry-run` shows the plan. |

`.gitattributes` also gives `PROGRESS.md` and `docs/SPEEDUPS.md` git's
built-in `union` merge: both are append-only logs, so parallel appends keep
both sides instead of conflicting.

## Measured on the five swarm branches (W1–W5)

- Git's default merge stops at the first branch on a `splits.txt` conflict.
  With the drivers, all four merges completed with zero conflicts in
  `symbols.txt` and `splits.txt`. Only `configure.py`, `PROGRESS.md` and
  `SPEEDUPS.md` still conflicted, and the last two are now union-merged.
- `check_order.py` on the combined splits finds the cycle the swarm hit. It is
  closed by one edge: the EA-lib units' `.sbss` at 0x806EFB34..0x806EFC10
  (0x14 bytes per unit) sits after the SDK's `.sbss`, while EA code sits
  before SDK code. That is the signature of common symbols, which the linker
  allocates after every regular `.sbss`; see `docs/dtk/common_bss.md`.
  Marking those 11 ranges `common` in splits.txt gives "link order OK: 41
  units". Still to confirm with a build: that `main.dol` stays identical, and
  that ProDG emits those variables as small commons (`.scommon`; our linker
  script already places `*(.scommon)` after `*(.sbss)`).

## Next candidates

- `configure.py` still merges by text, and parallel `Object(...)` additions at
  the end of the same list conflict. A per-unit registry file that
  `configure.py` reads would make those line additions.
- Unit-assignment queue (claim and release GitHub unit issues), and a
  near-miss queue.
