# Kickoff prompt — paste this into Claude Code in the empty private repo

---

Read `CLAUDE.md` fully before doing anything else. Then read `docs/RECON_CHECKLIST.md`
and `docs/PHASES.md`.

We are starting a private matching decompilation of **MVP Baseball 2005 for
Nintendo GameCube** (`GV4E69`). I dumped the disc from my own copy. The image is at:

`orig/<GAME_ID>/<filename>`   ← I will fill this in / tell you the path

This session covers **Phase 0 (recon)** and, only after I approve, **Phase 1
(scaffold)**. Do not write any decompiled C/C++ in this session.

## Phase 0 — Recon (report, then STOP)

1. **Environment check.** Confirm the host OS and which of these are installed
   and working: git, Python 3, ninja, Ghidra + JDK, Node, REA (`rea-agents doctor`),
   and GitHub CLI. List anything missing with install commands; don't install
   system packages without asking me.

2. **Verify the dump.** Compute SHA-1 of the disc image. Read the game ID and
   region from the disc header. Tell me what you found; I'll compare against
   redump.org myself. Do not download anything game-related.

3. **Inventory the disc.** List the filesystem: `main.dol` (or equivalent),
   any `.rel`/`.rso` modules, `.map` files, debug leftovers, and the top-level
   asset layout (archive formats only — don't extract assets into the repo).
   **Check specifically for any linker map, symbol file, or unstripped ELF** —
   these are gold and change the whole plan.

4. **Identify the toolchain. This is the most important question.**
   Gather evidence for CodeWarrior vs. SN Systems ProDG (GCC-based) vs. other:
   - compiler/library version strings in the DOL
   - presence and style of CodeWarrior runtime/MSL/`__init_cpp_exceptions`/
     `__destroy_global_chain` patterns vs. GCC/ProDG runtime patterns
   - prologue/epilogue idioms (e.g., `_savegpr_`/`_restgpr_` helpers), small-data
     register usage (r2/r13), section layout (`.ctors`, `.dtors`, `extab`, `extabindex`)
   - C++ name mangling style if any symbols exist
   - Dolphin SDK build date strings (to pin SDK/library versions)
   Give a verdict with confidence and the evidence for it.
   If CodeWarrior, estimate the version range from known SDK date strings.

5. **Size the job.** Code size of `.text`, approximate function count (from
   Ghidra auto-analysis or dtk analysis), share that looks like SDK/library vs.
   game code, and whether there's C++ (vtables, RTTI, exceptions).

6. **Use REA/Ghidra for a first look.** Open the DOL (Ghidra with a GameCube/
   PowerPC loader if available), run auto-analysis, and identify:
   - `main` and the top-level game loop
   - the 10 most-referenced strings that hint at subsystem names
     (e.g., franchise, pitch, batter, fielding, crowd, audio, file I/O)
   - any obviously EA-shared engine code (common EA Canada libraries)
   Record a short "subsystem map": address ranges → probable subsystem.

7. **Write `docs/RECON_REPORT.md`** with all of the above, plus:
   - your recommended path (dtk-template matching / GCC matching / functional mode)
   - the top 5 risks
   - the exact compiler(s) and flags you'll need to find, and how we'd confirm them

Then **STOP** and wait for my approval. Do not scaffold yet.

## Phase 1 — Scaffold (only after I reply "approved: <path>")

Follow the approved path. For the standard CodeWarrior path:

1. Set up the project from **dtk-template** (decomp-toolkit's template). Follow
   its README and config docs exactly; read them rather than guessing flags.
2. Configure `config/<GAME_ID>/config.yml` for our DOL (and RELs if present).
   Disc image stays in `orig/` (gitignored).
3. Get the build to produce a DOL **byte-identical to the original from split
   assembly alone**. This is the Phase 1 exit criterion; nothing else counts.
4. Identify candidate compiler versions; set up `objdiff` and confirm a trivial
   known function (e.g., a tiny SDK routine) matches with the chosen compiler.
5. Generate the unit list: one GitHub issue per translation unit (via `gh`),
   labeled `sdk`, `game`, `size:S/M/L`, and `subsystem:<name>`. Prioritize:
   small SDK units first (good for confirming toolchain), then small game units.
6. Add CI (GitHub Actions) that builds, runs the full match check, and fails on
   any regression of a previously matched function. Store a hash of the
   verification config/scripts and fail CI if they change without my approval.
7. Copy `templates/PROGRESS.md` and `templates/DECISIONS.md` to the repo root /
   `docs/` and fill in the initial state.
8. Commit in small steps. Report the Phase 1 exit check result and STOP.

Throughout: obey every hard rule in `CLAUDE.md`. If anything here conflicts with
`CLAUDE.md`, `CLAUDE.md` wins; tell me about the conflict.
