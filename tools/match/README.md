# Matching helpers

Developer tools for the inner loop. They are **not** verification: `tools/verify/verify.py`
and objdiff decide what counts as matched.

| Script | Use |
|---|---|
| `diff_unit.py <unit> [name-substr...]` | Rebuild one unit object with ninja, then compare every function to dtk's target object. Relocations are masked. Give a name substring for a side-by-side diff. One loop takes about 5–8 s. |
| `variants.py <prodg_dir> <objdump> <file.cpp> <target.o> <symbol> [flags...]` | Compile a scratch file of whole-function rewrites (any function whose name contains `_v<N>`) and score each against the target. Set `SHOW=<name-substr>` to list one variant's diffs. Good for register-allocation and scheduling near-misses. |
| `cmp_objects.py <objdump> <compiled.o> <target.o> [name-substr...]` | The comparison step `diff_unit.py` uses. |
| `asm_show.py <asm_dir> show <fn...>` / `list ...` | Print functions from dtk's split asm (`build/GV4E69/asm`), compacted. |
| `m2c_draft.py <unit> <fn>` | First-draft C for one function via m2c (external venv, see the script). A starting point: m2c guesses types, `unk<off>` fields map to our `m<off>`. |
| `asm_summary.py <asm_dir> <lo_hex> <hi_hex>` | One line per function in an address range: size, calls, data refs, float/indirect-call hints. Useful for finding unit boundaries. |

Example near-miss session:

```bash
python tools/match/diff_unit.py animation/choosers/playeridchooser fn_80270D64
```

Recurring GCC 2.95 (ProDG, `-Os`) tells are collected in `docs/SPEEDUPS.md`.
