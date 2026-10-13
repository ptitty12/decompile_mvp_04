# Matching helpers

Developer tools for the inner loop. They are **not** verification: `tools/verify/verify.py`
and objdiff decide what counts as matched.

| Script | Use |
|---|---|
| `diff_unit.py <unit> [name-substr...]` | Rebuild one unit object with ninja, then compare every function to dtk's target object. Relocations are masked. Give a name substring for a side-by-side diff. One loop takes about 5–8 s. |
| `variants.py <prodg_dir> <objdump> <file.cpp> <target.o> <symbol> [flags...]` | Compile a scratch file of whole-function rewrites (any function whose name contains `_v<N>`) and score each against the target. Set `SHOW=<name-substr>` to list one variant's diffs. Good for register-allocation and scheduling near-misses. |
| `score_variants.py <unit> <function> <file.cpp>... [--relax] [--show]` | Compile scratch copies of a unit with its cflags from `build.ninja` and score one function against dtk's target object (differing slots plus an alignment-aware count). About 0.2 s per file, so scripted searches over hundreds of variants are cheap. `--relax` accepts a relocation against a raw immediate (e.g. `GXWGFifo@ha` vs `lis 0xcc01`). |
| `permute.py <unit> <fn> [--minutes 20] [-j 4] [--setup-only]` | Run decomp-permuter (external clone and venv, see the script) on one near-miss, unattended, and list the best candidates (`build/permute/<fn>/output-<score>-<n>/source.c`, 0 = match). The target is the function alone, assembled from dtk's split asm. C units: the base is the unit preprocessed with its own compiler and cflags, with helpers the compiler inlined kept `inline`; about 100 candidates/s with `-j 6`. C++ units: `cxx2c.py` renders the function and the declarations it uses as C for the permuter to mutate, and each candidate's body is spliced back into the original unit and compiled with g++, so codegen is exact; about 50/s with `-j 6`. Setup checks the base compiles to the real unit's code and refuses a C++ function otherwise (methods and `) return r` functions are refused). A candidate is a lead; confirm it with `score_variants.py` and verify. |
| `permute_farm.py --loop \| --status` | Runs `permute.py` over every near-miss on main (>= 95%, closest first), unattended, at idle CPU priority, in its own worktree (`decompile_mvp_04-farm`). A scheduled task ("MVP decomp permuter farm", every 10 min) keeps it running. Units in the lead's `busy_units.txt` are skipped. The ledger is `build/permute_farm/ledger.json` in that worktree, and the dashboard shows it. A score of 0 is confirmed by rebuilding the unit and saved as `match.patch` in the function's run directory. The farm never commits: apply the patch in a worktree and verify as for any match. |
| `cmp_objects.py <objdump> <compiled.o> <target.o> [name-substr...]` | The comparison step `diff_unit.py` uses. |
| `asm_show.py <asm_dir> show <fn...>` / `list ...` | Print functions from dtk's split asm (`build/GV4E69/asm`), compacted. |
| `m2c_draft.py <unit> <fn>` | First-draft C for one function via m2c (external venv, see the script). A starting point: m2c guesses types, `unk<off>` fields map to our `m<off>`. |
| `clone.py <unit> [--apply \| --write]` | Clone matched exact-shape twins (same masked asm) onto the unit's unmatched functions: remaps symbols, inline float/string literals and declarations, pre-checks by compiling against dtk's target object, and with `--apply` also runs diff_unit + check_literals and drops clones that fail. `--scan` counts candidates per unit; `--busy FILE` refuses units other workers own. Free functions only (always `extern "C"`). See the module docstring for limits. |
| `protolint.py [--apply] [--why fn_X]` | Find `fn_<addr>` prototypes whose declared return type disagrees with the original code (value vs void, from r3 dataflow plus caller evidence), with the number of matched/unmatched callers per finding. Also checks float results (f1). `--apply` rewrites the types in place (certain tier by default); follow with `tools/verify/verify.py` and keep only what does not regress. A wrong return type changes sched2 argument ordering in the callers. Known-unchangeable names live in `protolint_skip.txt`. See the module docstring for the evidence rules. |
| `sort_functions.py <file.cpp> [--check]` | Reorder function definitions into .text address order (rename.py pairs by object order). |
| `asm_summary.py <asm_dir> <lo_hex> <hi_hex>` | One line per function in an address range: size, calls, data refs, float/indirect-call hints. Useful for finding unit boundaries. |

Example near-miss session:

```bash
python tools/match/diff_unit.py animation/choosers/playeridchooser fn_80270D64
```

Recurring GCC 2.95 (ProDG, `-Os`) tells are collected in `docs/SPEEDUPS.md`.
