# Matching helpers

Developer tools for the inner loop. They are **not** verification: `tools/verify/verify.py`
and objdiff decide what counts as matched.

| Script | Use |
|---|---|
| `diff_unit.py <unit> [name-substr...]` | Rebuild one unit object with ninja, then compare every function to dtk's target object. Relocations are masked. Give a name substring for a side-by-side diff. One loop takes about 5â€“8 s. |
| `variants.py <prodg_dir> <objdump> <file.cpp> <target.o> <symbol> [flags...]` | Compile a scratch file of whole-function rewrites (any function whose name contains `_v<N>`) and score each against the target. Set `SHOW=<name-substr>` to list one variant's diffs. Good for register-allocation and scheduling near-misses. |
| `score_variants.py <unit> <function> <file.cpp>... [--relax] [--show]` | Compile scratch copies of a unit with its cflags from `build.ninja` and score one function against dtk's target object (differing slots plus an alignment-aware count). About 0.2 s per file, so scripted searches over hundreds of variants are cheap. `--relax` accepts a relocation against a raw immediate (e.g. `GXWGFifo@ha` vs `lis 0xcc01`). |
| `store_orders.py <unit> <function> --line N --count K` | Enumerate orders of 2-6 adjacent stores to distinct fields of one pointer, then compile/score scratch copies with the ProDG unit's flags. Constants and bare symbols only; default cap 120 variants. Leaves source unchanged. Useful when only constructor store scheduling differs; see the script's limits. |
| `frame_candidates.py [--limit 20] [--minimum 90] [--json]` | Shortlist equal-length near matches whose changes are only stack-relative offsets, with different stack frames and identical internal branch paths. Inspect the actual callee return layout before changing buffers; external bindings and normal acceptance checks remain required. |
| `stack_candidates.py [--limit 30] [--minimum 90] [--json] [--unverified-bindings]` | Find stack-slot differences even when frame sizes agree, preserving instruction/register fields and resolved local branches. Shows displacement mappings and one-to-many ambiguity. Default requires equal relocation signatures; the optional flag lists every binding difference as provisional. Confirm actual object layout and call/data bindings before changing source; this is read-only triage. |
| `link_candidates.py [--limit 30] [--json] [--all \| --footprint]` | Read-only shortlist of fully matched, unlinked units. Compares allocated object-section layouts; `--footprint` also shows equal names/types/sizes despite order, flags or alignment differences. Lists source imports missing from the current main.elf. Prefer zero-missing-import candidates, then prove each Object(Matching) change with the retail hash, literal check and verifier. `--all` also shows units whose extra data/sections block a simple replacement. |
| `data_candidates.py [unit ...] [--ready] [--json]` | Read-only shortlist of compiled data-section placements. Uses paired code relocations, canonical global objects, initialized pointers, or unique aligned whole-section bytes. Refuses ambiguous/zero-block searches and reports unresolved relocations. Check existing ownership and external users; each promotion still needs the retail hash, literal checks and official verifier. |
| `import_candidates.py [unit ...] [--limit 30] [--json]` | Read-only provider leads for missing imports in fully matched units. Pairs REL24 calls at the same function-relative offset, resolves retail destinations, and lists every exported function at each address. Reports conflicting destinations and unpaired imports. Confirm provider signatures from the binary and callers; address agreement alone does not establish ABI compatibility. |
| `literal_pair_map.py <unit ...> [--json] [--limit N]` | Map local source-data references to paired retail symbols across all executable sections in matched, equal-sized functions. Checks bytes and bounds; reports aliases, unpaired references and whether a checked extent is a load span, string, symbol or incomplete prefix. Helps recover original shared literals/tables before source linking. Ownership, ABI, retail hash and verifier checks remain separate. |
| `permute.py <unit> <fn> [--minutes 20] [-j 4] [--setup-only]` | Run decomp-permuter (external clone and venv, see the script) on one near-miss, unattended, and list the best candidates (`build/permute/<fn>/output-<score>-<n>/source.c`, 0 = match). The target is the function alone, assembled from dtk's split asm. C units: the base is the unit preprocessed with its own compiler and cflags, with helpers the compiler inlined kept `inline`; about 100 candidates/s with `-j 6`. C++ units: `cxx2c.py` renders the function and the declarations it uses as C for the permuter to mutate, and each candidate's body is spliced back into the original unit and compiled with g++, so codegen is exact; about 50/s with `-j 6`. Setup checks the base compiles to the real unit's code and refuses a C++ function otherwise (methods and `) return r` functions are refused). A candidate is a lead; confirm it with `score_variants.py` and verify. |
| `permute_farm.py --loop \| --status` | Runs `permute.py` over every near-miss on main (>= 95%, closest first), unattended, at idle CPU priority, in its own worktree (`decompile_mvp_04-farm`). A scheduled task ("MVP decomp permuter farm", every 10 min) keeps it running. Units in the lead's `busy_units.txt` are skipped. The ledger is `build/permute_farm/ledger.json` in that worktree, and the dashboard shows it. A score of 0 is confirmed by rebuilding the unit and saved as `match.patch` in the function's run directory. The farm never commits: apply the patch in a worktree and verify as for any match. |
| `cmp_objects.py <objdump> <compiled.o> <target.o> [name-substr...]` | The comparison step `diff_unit.py` uses. |
| `asm_show.py <asm_dir> show <fn...>` / `list ...` | Print functions from dtk's split asm (`build/GV4E69/asm`), compacted. |
| `m2c_draft.py <unit> <fn>` | First-draft C for one function via m2c (external venv, see the script). A starting point: m2c guesses types, `unk<off>` fields map to our `m<off>`. |
| `clone.py <unit> [--apply \| --write]` | Clone matched exact-shape twins (same masked asm) onto the unit's unmatched functions: remaps symbols, inline float/string literals and declarations, pre-checks by compiling against dtk's target object, and with `--apply` also runs diff_unit + check_literals and drops clones that fail. `--scan` counts candidates per unit; `--busy FILE` refuses units other workers own. Free functions only; C++ exports use `extern "C"`, explicitly C units use plain C declarations. Uses the actual unit compiler (ProDG or CodeWarrior). See the module docstring for limits. |
| `protolint.py [--apply] [--why fn_X]` | Find `fn_<addr>` prototypes whose declared return type disagrees with the original code (value vs void, from r3 dataflow plus caller evidence), with the number of matched/unmatched callers per finding. Also checks float results (f1). `--apply` rewrites the types in place (certain tier by default); follow with `tools/verify/verify.py` and keep only what does not regress. A wrong return type changes sched2 argument ordering in the callers. Known-unchangeable names live in `protolint_skip.txt`. See the module docstring for the evidence rules. |
| `sort_functions.py <file.cpp> [--check]` | Reorder function definitions into .text address order (rename.py pairs by object order). |
| `asm_summary.py <asm_dir> <lo_hex> <hi_hex>` | One line per function in an address range: size, calls, data refs, float/indirect-call hints. Useful for finding unit boundaries. |

Example near-miss session:

```bash
python tools/match/diff_unit.py animation/choosers/playeridchooser fn_80270D64
```

Recurring GCC 2.95 (ProDG, `-Os`) tells are collected in `docs/SPEEDUPS.md`.

For a small store-order difference, try a bounded `store_orders.py` search before
a long random permuter run. A four-store search has only 24 variants; this found
the exact order for `fe/tu_80488CDC`'s `fn_8048A2AC` (204 bytes). Search scores
still require a full rebuild, literal/target checking and the verifier.

`permute.py` preserves executable flags when extracting front-end/database
overlay targets and rejects empty target disassemblies before starting a search.
Earlier overlay runs could score every instruction as an insertion (e.g. 5100
instead of 10 for `fn_8048A2AC`); those old searches should not be used to judge
whether a function is hard. New farm processes fingerprint source, recursively resolved headers, unit flags
and matching helpers, so old attempts are retried when those inputs change.
Existing running loops keep their loaded Python code until they exit; the live
farm was not interrupted. Trials refuse local source edits and restore exact
prior bytes on success or failure.

Helper regression tests (synthetic inputs, no game data):
`python -m unittest discover -s tools/match/tests -v`. With build/binutils present,
these also assemble/disassemble synthetic functions in all three code sections.

The scorer, clone pre-check and permuter share compiler selection. SDK C units
keep their actual C flags; clone output drops C++ linkage annotations for them.
The Ninja flag parser caches identical input text and supports a separate farm
root. Data placement also checks existing exact-sized section ownership, useful
for one-pointer constructor sections too small for unique byte searching.

The typed volatile FIFO view in include/ealib/gx_fifo.h addresses 0xCC008000
relative to a 0xCC010000 base with a signed displacement. sizeof-based indexing
supports both 4-byte and 8-byte union views. Compile-only synthetic tests check
the actual generated address form without touching hardware.

Clone twin shapes retain function-relative local-label destinations. The compiled
pre-check also resolves local branch relocations from the ELF symbol table and
compares function-relative destinations, so relocation masking cannot hide a
changed conditional path. External call/data bindings still need literal checks;
all accepted source changes still need the unmodified verifier and retail hash.

The frame scanner checks every executable target section and pairs it by name
with the source section. Three exact matches came from replacing oversized
return buffers with the actual two-float or five-word callee result. Confirm
the callee layout from its implementation or retail accesses first; a smaller
frame alone does not establish the correct type. Clone branch checks also cover
objects that contain both ordinary text and overlay code.
