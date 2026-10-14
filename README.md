> this project is driven entirely by Claude, also known as 'Decomp-slop'\
> This project is purely output focused and cares not of the journey.\
> Thank you\
> -Human

# mvp2005-decomp: MVP Baseball 2005 (GameCube, GV4E69) matching decompilation

A matching decompilation of MVP Baseball 2005 for the Nintendo GameCube
(`GV4E69`, USA, rev 0). The goal is C/C++ source that the original compilers
turn back into a byte-identical `main.dol` (SHA-1
`da6becdbea614d03c4b5eae9f8a0fb08e0a184dd`). A native/WASM port for personal
play may follow later (Phase 3, not started).

This is a personal project, and the repository is public (owner, 2026-10-13).
It holds source, tooling and docs only, never game data. To build it you need
a disc image dumped from your own copy.

## Progress

![Decompilation progress: percent of code matched, a treemap of units shaded by match percent, and progress over time](docs/progress/progress.svg)

The card above is live. This table is a snapshot of `main` at `68d25430`
(2026-10-13 22:53 CDT):

| Measure | Done | Total | Share |
|---|---:|---:|---:|
| Functions matched | 21,104 | 24,158 | 87.4% |
| Code bytes matched | 3,073,968 | 5,896,176 | 52.1% |
| Code built from source (units linked from our C/C++) | 386,148 | 5,896,176 | 6.5% |
| Units built from source | 234 | 847 | 27.6% |
| Data bytes matched | 12,710 | 1,369,010 | 0.9% |

- **Matched** means objdiff scores the function 100% against the original
  object code. **Built from source** means the whole unit (every function
  and its data) links from our source and the final DOL still has the
  retail hash. Until then, a matched unit's code still comes from the split
  assembly.
- The function count runs ahead of the byte count because small functions
  went first. Of the 3,054 functions left, the 853 over 1 KB hold 1.86 MB of
  the 2.82 MB of unmatched code. 507 functions sit at 95-99.99%.

Each block in the treemap is one unit, sized by its code and shaded by
objdiff's fuzzy match percent (gray = not started, darkest blue = fully
matched). The daily numbers behind the line chart are in
[`docs/progress/history.csv`](docs/progress/history.csv).

The card updates itself. A scheduled task on the owner's PC runs
`tools/progress_bot.py` every 2 minutes. When `main` has changed, it builds
`main` in a private worktree (`build/_progress/wt`), redraws the card if the
numbers moved, runs `tools/verify/verify.py`, and pushes a
`docs: update progress card` commit. Before that push it uploads the build's
`report.json` to the `progress-report` release, and
`.github/workflows/decomp-dev.yml` republishes it in the artifact format
decomp.dev reads. The project is not listed on decomp.dev (owner,
2026-10-13).

**[Live fleet dashboard](https://github.com/ptitty12/mvp2005-decomp/tree/dashboard)**:
matching speed (verified on `main` and claimed by workers, per hour), the
near-miss share, each worker's activity, the merge backlog and the functions
closest to matching. `tools/fleet_dashboard.py --publish` builds it from git
history alone, with no build and no model calls. A scheduled task runs it every
minute and replaces the single commit on the `dashboard` branch, so `main`
gets no extra commits.

### Where the code is

| Source folder | What it is | Functions matched | Code matched |
|---|---|---:|---:|
| `src/game/` | Game code in main `.text` | 12,446 / 14,246 | 49.7% of 3.31 MB |
| `src/fe/` | Front-end / franchise UI (`.frontend_codeoverlay`) | 3,132 / 3,408 | 55.2% of 960 KB |
| `src/db/` | Database / roster / trade (`.database_codeoverlay`) | 1,520 / 1,779 | 50.2% of 494 KB |
| `src/ealib/`, `src/ealibs/` | EA shared libraries (EAGL, RealCore, AV/VP6, ...) | 1,368 / 1,665 | 50.4% of 469 KB |
| `src/animation/` | Animation choosers and goals (one retail unity TU) | 967 / 1,057 | 46.6% of 239 KB |
| `src/dolphin/`, `src/sdk/` | Nintendo Dolphin SDK | 696 / 839 | 79.8% of 175 KB |
| `src/snd/` | EA SND 9.02.04 + csis | 437 / 480 | 69.6% of 92 KB |
| `src/gamelib/` | EA gamelib (allocator, datafile, animlib) | 359 / 402 | 49.4% of 85 KB |
| `src/libc/`, `src/libm/`, `src/libgcc/`, `src/libsn/` | SN runtime: newlib, fdlibm, libgcc, libsn | 179 / 273 | 82.0% of 70 KB |

The address ranges and flags for each library are in `docs/DECISIONS.md`.

## How it works

### Toolchain

The game was built with a hybrid toolchain, found in Phase 0
(`docs/RECON_REPORT.md`):

- **Game code and EA libraries:** SN Systems ProDG 3.9.3 (`GNU C++ 2.95.3 SN
  BUILD v1.76`). Game code uses `-Os -G0 -fno-rtti -fno-exceptions
  -ffloat-store`, and the EA libraries mostly use `-O2`. Flags are pinned per
  library, and sometimes per unit, with evidence in `docs/DECISIONS.md`.
- **Dolphin SDK:** Metrowerks CodeWarrior GC/1.2.5n (GC/2.0 for VM and the
  debugger driver), with per-file flags such as `-opt nopeephole`.
- **Link:** SN `ngcld` 1.5.1.692 with a static linker script
  (`config/GV4E69/ldscript.ld`). `tools/mkdol.py` packs the DOL, because
  retail `main.dol` has one DOL section per program segment.

The project is built on dtk-template, decomp-toolkit and objdiff, patched for
ProDG (`tools/project.py`). The game has no symbols or map. The disc's
`/mvp.elf` is the stripped link output, and the build splits it into one
section per ELF section, so the real section boundaries stay visible.

### Building

Put a disc image (`.iso`, `.ciso`, `.rvz`, ...) or the extracted `mvp.elf` in
`orig/GV4E69/` (gitignored), then:

```sh
python configure.py
ninja
```

`configure.py` downloads the toolchain (dtk, objdiff, binutils and the
compilers package from files.decomp.dev). `ninja` rebuilds
`build/GV4E69/main.dol` from compiled source plus the remaining split
assembly, checks it against `config/GV4E69/build.sha1`, and writes the
objdiff report `build/GV4E69/report.json`. The host is native Windows: ProDG
and MWCC are Win32 programs.

### What counts as matched

The verifier decides, not any agent:

- `tools/verify/verify.py` checks four things: protected-file integrity
  (`protected.sha256`); that the build succeeds with the retail SHA-1;
  the hard rules (no inline asm, naked functions or `.incbin`, and only
  approved pragmas); and no unit or function score drops against a
  baseline. `--baseline-ref origin/main` must pass on the exact commit
  being pushed.
- `tools/match/check_literals.py` covers what objdiff's score ignores. It
  catches a "100%" function that loads the wrong float, string, global or
  call target. `tools/team/integrate.py` refuses commits that add such
  mismatches.
- A unit becomes built-from-source (`Object(Matching)`) only after a
  full-DOL trial keeps the retail hash.
- CI (`.github/workflows/build.yml`) runs the integrity check on GitHub's
  runners. The full build runs only on the owner's machine, because game
  files never leave it.

## Who does the work

AI agents write every line of code and docs. The owner dumped the disc,
approves the decisions that are theirs to make (`docs/DECISIONS.md`), and
never runs commands.

- **Claude Code:**
  - An Opus 5.5 **lead** prepares units, owns shared headers and config, and
    merges and verifies worker branches.
  - Sonnet 5.5 **workers** match one unit at a time in their own worktrees
    (`prompts/11_TEAM_WORKER.md`).
  - Fable 5.1 takes big or parked functions "when needed".
  - **Side sessions** build tools and do research.
- **Codex** agents (a coordinator, an integrator and swarm workers) work
  under the same rules. `AGENTS.md` points them at `CLAUDE.md`.
- **Coordination:** `tools/coord.py` keeps a shared roster, unit claims, an
  inbox and one integration lock. Every push to `main` holds the lock
  (`docs/COORDINATION.md`). `claude-lead` settles conflicts, and the owner
  can override.
- **Background jobs** run as scheduled tasks on the owner's PC:
  - the progress bot (every 2 minutes);
  - the dashboard (every minute);
  - the permuter farm (`tools/match/permute_farm.py`, every 10 minutes). It
    runs decomp-permuter over near-misses and saves patches but never
    commits.

## Rules, in short

The full rules are in [`CLAUDE.md`](CLAUDE.md). The most important:

- Never commit game data: disc images, DOL/REL files, assets or byte dumps.
  `orig/` and `build/` are gitignored.
- No inline asm in any form, including codeless `asm("")` and register pins.
  No naked functions, byte arrays standing in for code, object patching or
  linker tricks. Hand-written original assembly stays as split assembly.
- Agents never change the verifier, CI or `.claude/` without the owner's
  explicit approval.
- One unit per commit: `match(<unit>): <functions> [N/M funcs]`.
- Use placeholder names (`fn_80XXXXXX`, `lbl_80XXXXXX`, `Unk<addr>`,
  `m<offset>`) until a string, an SDK symbol or a related EA build proves the
  real name.
- Mirror the original, bugs included. Refactoring waits for Phase 3.

## Phases

| Phase | Status |
|---|---|
| 0: Recon | Done 2026-10-10 (`docs/RECON_REPORT.md`) |
| 1: Scaffold, byte-identical DOL from split assembly | Done 2026-10-10 |
| 2a: Toolchain lock-in on SDK and runtime units | Done: compilers and flags pinned per library; 40 Dolphin SDK units and most libc/libm units build from source |
| 2b: Game code | In progress: the 25/50/75% function milestones are passed; about half the game code bytes are matched |
| 3: Port (native, then WASM) | Not started |

Exit criteria are in [`docs/PHASES.md`](docs/PHASES.md).

## Repository layout

| Path | Contents |
|---|---|
| `src/` | Decompiled C/C++, one file per split unit (`game/tu_<addr>.cpp` until the original file name is known) |
| `include/` | Shared headers. Struct comments record their evidence |
| `config/GV4E69/` | dtk config (`splits.txt`, `symbols.txt`), linker script, DOL layout, retail hash, EA reference names (`refnames/`) and datafile schemas |
| `configure.py`, `tools/project.py` | Build generator (dtk-template with the ProDG pipeline) |
| `tools/verify/` | The verifier and its protected-file hashes. Owner-only |
| `tools/match/` | Matching helpers: diff, variants, twins, clone, permuter, link/import/literal checks ([README](tools/match/README.md)) |
| `tools/scout/` | Unit packets and symbol renaming ([README](tools/scout/README.md)) |
| `tools/swarm/` | Merge drivers, link-order check, worktree provisioning ([README](tools/swarm/README.md)) |
| `tools/team/` | `integrate.py` (merge, verify, push), `merge_structs.py`, and the lead's batch scripts in `lead/` |
| `tools/recon/` | Phase 0 disc and binary analysis ([README](tools/recon/README.md)) |
| `tools/*.py` | `coord.py`, `progress_bot.py`, `progress_chart.py`, `fleet_dashboard.py`, `mkdol.py`, and dtk-template helpers |
| `docs/` | Decisions, patterns, logs and research (below) |
| `prompts/` | Agent briefs: kickoff, solo worker, team worker, audit |
| `templates/` | Blank PROGRESS/DECISIONS templates from the original kit |
| `orig/`, `build/` | Disc files and build output. Gitignored, never committed |

## Docs

| File | What's in it |
|---|---|
| [`CLAUDE.md`](CLAUDE.md) | The rules every agent follows |
| [`AGENTS.md`](AGENTS.md) | Entry point for Codex and other non-Claude agents |
| [`PROGRESS.md`](PROGRESS.md) | Snapshot and session log, newest last |
| [`HANDOFF.md`](HANDOFF.md) | The lead's hand-off: state, how to resume, queues, scripts |
| [`docs/DECISIONS.md`](docs/DECISIONS.md) | Owner-approved decisions (toolchain, flags, splits, policy) and open questions for the owner |
| [`docs/COORDINATION.md`](docs/COORDINATION.md) | The Claude/Codex coordination protocol (`tools/coord.py`) |
| [`docs/PATTERNS.md`](docs/PATTERNS.md) | Source patterns that produced byte-identical matches with ProDG/g++ 2.95 |
| [`docs/NEARMISS.md`](docs/NEARMISS.md) | Parked near-misses and what was tried |
| [`docs/SPEEDUPS.md`](docs/SPEEDUPS.md) | Speed-up ideas, observations and what was tried |
| [`docs/REUSE.md`](docs/REUSE.md), [`docs/REFERENCE_SOURCES.md`](docs/REFERENCE_SOURCES.md) | Public code we can port, and every outside source checked, with verdicts |
| [`docs/GAME_DATA.md`](docs/GAME_DATA.md) | EA datafile, database tables, schedules and archive formats, for naming |
| [`docs/PHASES.md`](docs/PHASES.md), [`docs/RECON_CHECKLIST.md`](docs/RECON_CHECKLIST.md) | Phase plan and the Phase 0 checklist |
| [`docs/RECON_REPORT.md`](docs/RECON_REPORT.md) | Phase 0 report: disc, sections, toolchain evidence, subsystems (2026-10-10 snapshot) |
| [`docs/UNITS.md`](docs/UNITS.md) | First-pass unit anchors (2026-10-10 snapshot; the live split is `config/GV4E69/splits.txt`) |
| [`docs/SWARM_SESSION_2026-10-13.md`](docs/SWARM_SESSION_2026-10-13.md), [`docs/audits/`](docs/audits/) | A Codex swarm session report, and audit reports |
| [`docs/dtk/`](docs/dtk/) | decomp-toolkit / dtk-template reference docs |

## Credits and references

- [decomp-toolkit](https://github.com/encounter/decomp-toolkit),
  [dtk-template](https://github.com/encounter/dtk-template) and
  [objdiff](https://github.com/encounter/objdiff) by encounter. The template's
  license is in `docs/dtk/LICENSE-dtk-template`.
- [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) and
  [m2c](https://github.com/matt-kempster/m2c), used from external clones.
- [mitsevox/mvp2005](https://github.com/mitsevox/mvp2005) (CC0): ported
  Dolphin SDK, libc, libm, libsn and SND sources, and EA reference names
  (`config/GV4E69/refnames/`).
- [adonis-singh/re4](https://github.com/adonis-singh/re4): Dolphin SDK
  bodies (dolsdk2004) and ProDG compiler notes.
- [dbalatoni13/nfsmw](https://github.com/dbalatoni13/nfsmw): prior art for
  ProDG matching on an EA GameCube title.

MVP Baseball 2005 is a trademark of its owners. This project is not
affiliated with EA, Nintendo or MLB, and it contains no game data.
