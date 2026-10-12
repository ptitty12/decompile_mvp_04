# Speed-ups: a living log

Owner's request (2026-10-10): while matching gets going, record every chance to
go faster, so we can decide which ones to adopt.

**Agents: add to the observations log** whenever something costs you noticeable
time, repeats, or could be automated. One line each: what happened, the idea,
and a rough impact. Don't fix it on the spot if it's outside your unit. Ideas
move into the candidate list, and their results go under "Tried".

Status keys: `idea`, `trying`, `adopted`, `rejected`, `needs owner` (a
download, a persistent service, cost, or owner-held material).

## Where the work is

From objdiff's report of `main` on 2026-10-10 (24,158 functions, 5,896,176 bytes of code):

| Function size | Functions | Share of functions | Share of code |
|---|---|---|---|
| ≤ 32 B | 3,914 | 16.2% | 1.0% |
| 33–64 B | 4,345 | 18.0% | 3.7% |
| 65–256 B | 10,577 | 43.8% | 24.0% |
| 257 B – 1 KB | 4,348 | 18.0% | 36.0% |
| > 1 KB | 974 | 4.0% | 35.3% |

What this means:
- Function counts will rise quickly at first, because a third of all functions
  are 64 bytes or less, while percent-of-code will rise slowly.
- 71% of the code is in the 22% of functions over 256 bytes. The tools for hard
  functions (items 1, 8 and 9 below) matter most there.
- Rate estimates should be made per size tier, not as one average.

Unit issues on GitHub (126 provisional units): 54 `game`, 55 `ea-lib`, 13
`sdk`, 4 `runtime`. Nearly half the units are EA shared libraries, so item 6
matters a lot.

## Candidate speed-ups

Roughly ordered by expected payoff for the effort.

1. **Near-miss queue and decomp-permuter.** `idea`, `needs owner` (download).
   GCC 2.95 misses on register allocation and instruction scheduling are what
   the permuter is built for: it tries random source rewrites and keeps the
   ones that score better in the diff. It runs unattended on the CPU and uses no
   agent time. Matchers park anything at 95% or above in a queue instead of
   spending their 8 attempts on it. Needs a compile script that wraps
   `ngccc` with the unit's flags.
2. **A scout agent that prepares units before matchers start.** `adopted` (tools/scout: `packet.py`, `rename.py`)
   Most of the first game unit's hour went into finding its boundaries, proving
   class names from strings, and checking the C++ ABI. A scout can do this ahead
   of time for every unit and attach a "unit packet" to the unit's issue:
   - boundaries, from ctor anchors, source paths and alignment padding;
   - vtables and the class lists they imply;
   - names proven from strings;
   - the call graph;
   - struct-offset usage.
3. **Pattern cookbook and clustering.** `adopted` (docs/PATTERNS.md; shape clusters measured below)
   87 static-init units share the same chooser/class boilerplate (ctor, dtor,
   factory, attribute registration). Cluster functions by the shape of their
   normalized asm. When one function in a cluster matches, write its recipe into
   a cookbook (`docs/PATTERNS.md`) and apply it to the rest of the cluster, even
   semi-automatically.
4. **Parallel matchers, one unit each, assigned by a supervisor.** `adopted` (owner approved 2026-10-10: Opus lead + Sonnet workers, pilot of 3)
   Start with the 17 sdk and runtime units: they have public reference code and
   don't depend on game headers. Then the ea-lib units, then game code, which
   stays with one agent until the shared headers settle. The README advises 2–4 agents after a clean single-agent week.
5. **Make shared-file edits one at a time.** `adopted` (lead preps units on main; workers edit src/include only; tools/team/integrate.py)
   Every match edits `configure.py`, `config/GV4E69/splits.txt` and
   `symbols.txt`, and usually PROGRESS/UNITS too. Parallel agents would conflict
   on these constantly. A supervisor, or a merge bot, owns these files: matchers
   hand over their unit plus a config fragment, and the supervisor applies them
   in order, runs the verifier and pushes.
6. **Reuse public reference code; port instead of writing from scratch.** `idea`
   Candidates:
   - Dolphin SDK decomps of the matching SDK version;
   - libgcc 2.95 source;
   - newlib (libc is at about 0x80406000–0x80414000);
   - EA shared libraries: the nfsmw decomp is also EA code built with ProDG.
     These cover 55 of the 126 units, so this is the biggest reuse
     opportunity. Check which libraries (EAGL and others) and versions overlap.

   Record each source in DECISIONS.md, as CLAUDE.md requires.
7. **Symbols from other builds the owner owns.** `needs owner`
   Source paths read `C:/mvp2004/source/...`, so the code is shared with MVP
   2004. Other platform builds (PS2, Xbox, PSP) of MVP 2004/2005 sometimes
   shipped unstripped executables or map files. Any copy the owner owns that has
   symbols would give function names and unit boundaries, maybe types too. This
   could be the biggest single speed-up, but it's unknown until checked. The
   owner's own discs only, never downloaded.
8. **A first-draft decompiler (m2c, PowerPC).** `adopted` (tools/match/m2c_draft.py; m2c in an external venv)
   It produces starting C from the asm, which is faster than writing it by hand
   or cleaning up Ghidra output. Most useful on mid-size functions.
9. **Route work to different models and effort levels.** `idea`, `needs owner` (cost)
   Small boilerplate goes to a faster model; large float-heavy functions and the
   near-miss queue go to a stronger model at high effort.
10. **A tighter build-and-diff loop.** `idea`
    A helper that compiles and diffs a single function (objdiff-cli on one
    object rather than a full ninja run), plus wrapper scripts so commands don't
    need Windows shell escaping. Measure how many seconds one loop takes. The
    saving per attempt is small, but it repeats across roughly 100k attempts.
11. **A self-hosted CI runner.** `needs owner` (installs a persistent service)
    It would verify every push and PR automatically, which enables a merge
    queue for parallel agents.
12. **A regular audit.** `idea`
    Since nothing gets human review, run `prompts/20_AUDIT.md` on a schedule,
    e.g. daily, so speed never quietly costs rule-following. It isn't a speed-up
    itself, but it keeps the speed honest.
13. **Measure what works.** `idea`
    Log time-to-match, attempts, size and pattern for each function.
    `docs/progress/history.csv` already records daily totals. This is how we'll
    tell which items above actually help.

## Observations log

<!-- YYYY-MM-DD | who | observation | idea (item #) | rough impact -->
- 2026-10-10 | matcher (first game unit) | About 1 h on `animation/choosers/playeridchooser.cpp`, mostly finding its boundaries (no symbols), proving class names from strings, and checking the g++ 2.95 ABI | scout pre-pass (2) | high: this is per-unit setup that repeats for every unit
- 2026-10-10 | matcher | 6 functions at 100%; 5 near-misses on register allocation and instruction order | permuter queue (1) | high on the hard tail
- 2026-10-10 | matcher | Class boilerplate (ctor/dtor/factory/attribute registration) reproduced exactly once the flags were known | cookbook and clustering (3) | high on function count
- 2026-10-10 | matcher | SDK units can't be linked piecemeal (data alignment), so they count as code-matched only | — | affects how SDK progress is measured
- 2026-10-10 | matcher | Windows shell escaping slows commands down | wrapper scripts (10) | small but constant
- 2026-10-10 | progress session | Every match edits configure.py, splits.txt and symbols.txt | serialize shared-file edits (5) | blocks parallel work until solved
- 2026-10-10 | matcher (playeridchooser) | The first game unit was compiled at -O2, which is wrong. Sweeping 14 flag sets on one near-miss found **-Os** in under a minute and fixed about 6 near-misses at once. Rule of thumb: when 2+ functions in a new library miss on register allocation, sweep flags before rewriting source | measure (13), permuter queue (1) | high, once per library
- 2026-10-10 | matcher | Near-misses solved by compiling many whole-function rewrites per run (`tools/match/variants.py`). The three hard ones (an initializer-list member, a local `const char*` for `__FILE__`, a temp for a call result) each took 1–2 runs | permuter (1), tight loop (10) | medium: about 2–5 min per near-miss
- 2026-10-10 | matcher | Recurring GCC 2.95 `-Os` clues, worth a cookbook (`docs/PATTERNS.md`):
  - an arg register (r4) loaded and never reloaded means the value is a call argument (e.g. `hash(token, len)`);
  - `lis r5` scheduled before `lwz r3` means r3 is a method's object pointer;
  - a second `li rX,0` used for only one field means that field is in the ctor initializer list;
  - the field written last in source is hoisted above the vptr store;
  - a value recomputed inside a loop means it was a loop-local pointer in source.

  | cookbook (3) | medium
- 2026-10-10 | matcher | Timing for playeridchooser.cpp: 19/26 functions in about 80 min, including about 35 min of unit setup (boundaries, names, ABI). Boilerplate took about 1–2 min per function once the first of its kind matched. Loops of 0x100–0x1AC bytes took about 5–10 min each | measure (13), scout (2) | baseline for per-tier rates
- 2026-10-10 | matcher | g++ 2.95 emits vtables in `.gnu.linkonce.d._vt.*` sections. The ldscript has no rule for them yet, so the first C++ unit to link (Matching) will need one | — | one-off, blocks linking C++ units
- 2026-10-10 | matcher | A partial MWCC SDK unit can't link: its .sdata is 8-aligned, and OS.c's data must be complete first. SDK progress therefore counts code only until whole units are done | — | affects SDK planning
- 2026-10-10 | matcher | Near-miss queue entry: `ICommonPlayerID::fn_vslot17` (0x80270BA0, 0x13C) has exact logic/blocks/length, but `this`/`out` are swapped between r29 and r28. 14 variants failed. Parked | permuter (1) | first queue entry
- 2026-10-10 | matcher | Two identical source clamps (`key = v; if (v < 0) key = 0;`) get cross-jumped by GCC into one shared block. When retail keeps them apart, one of them was written differently (here a ternary select) | cookbook (3) | saved about 15 min once known
- 2026-10-10 | matcher | g++ 2.95 places the vptr after the data of the class that introduces virtuals. A vptr at +0x98 in a big object means a data-less intermediate class; getting this wrong shifts every field by 4 | cookbook (3) | medium, recurs for every class hierarchy
- 2026-10-10 | matcher | ProDG's plain `char` is **signed** (callers `extsb`). A `clrlwi rX,rY,24` at a call site means the parameter is `unsigned char` | cookbook (3) | small, recurs
- 2026-10-10 | matcher | Positional diff counts mislead on big functions: one inserted instruction looks like 100 differences. An alignment-aware score (LCS) made variant ranking usable on a 0x290 function (71 → 8 → MATCH) | tight loop (10) | high on functions > 256 B
- 2026-10-10 | matcher | Timing for playeridchooser.cpp overall: 25/26 in about 2 h 15 min of matching, including about 35 min of setup. Rough per-size rate: ≤64 B about 1–2 min; 65–256 B about 5–10 min; 0x290 about 25 min; one 0x13C near-miss parked after about 15 min | measure (13) | baseline
- 2026-10-11 | W4 (near-miss sweep) | A recipe-first pass over parked near-misses matched 18 of ~30 in about 75 min (after the >?/Vec3-copy recipes; most fixes were new mechanisms: temp-slot reuse needs the same machine mode, inline parameters are not pointer-flagged, jump2 cross-jumps after sched2). Reading the RTL dumps (-da: sched, sched2, lreg, greg) before searching found each mechanism in 1-3 variant runs; a 20-line Python helper that writes variant files from (old, new) substitutions and scores the directory with score_variants.py kept each run under a minute | tight loop (10), cookbook (3) | high on parked near-misses
- 2026-10-11 | Opus (families) | Two near-miss families were one-line fixes once the mechanism was known. (a) Pass-through arguments: the callee reads an argument register the caller never set, so the call passes the caller's parameter (13 functions). (b) Pointer locals for &n/&cur used in a loop (12 CSV loaders). A 120-line asm scanner (scratchpad W7s3/passthru.py) lists every unmatched function with a pass-through call in about 3 s. Families tagged "only callee-saved registers permuted" are worth running it on first | cookbook (3), scout (2) | 25 functions in about 2 h, mostly mechanism-hunting

## Tried

<!-- YYYY-MM-DD | item # | what was done | measured effect -->
- 2026-10-10 | 4 | Pilot worker (Sonnet) on cLinearChooser: 12/13 functions (the 10.5 KB slot 17 skipped by design) in 28.5 min, 425k tokens, 125 tool calls: about 35k tokens and 2.4 min per function, including a 0x44C float function | first measured worker rate
- 2026-10-10 | 3 | Shape clusters (relocatable immediates masked) over .text: game code (<0x80340000) 13,625 functions, 32.0% repeat another function's shape but only 8.6% of bytes; libraries (>=0x80340000) 5,339 functions, 37.1% / 14.5%. Two EA-lib families are exact clones across 5 units each (0x704+0x320 and 0x6A8+0x320 bytes): 20 functions from matching 4 | measured, not yet applied
- 2026-10-10 | 8 | m2c (`--target ppc-gcc-c++`) on dtk asm: reproduced cCircleChooser's helper dtor and id-resolve loop logic exactly on first try | first-draft quality good on small/mid functions; to be measured on workers
- 2026-10-10 | 5 | Lead integrated swarm branches W1/W3/W4/W5 with the merge drivers + a union resolver for configure.py: 46 -> 120 functions at 100%, every first-parent commit verified; scripted as tools/team/integrate.py | one integration ~10 min
- 2026-10-10 | 10 | `tools/match/` helpers: `diff_unit.py` (rebuild one unit and diff each function), `variants.py` (score N rewrites per compile), and asm show/summary scripts | rebuild+diff loop **1.9 s**; a variants run takes about 5 s for 7–10 variants
- 2026-10-10 | 3 | Reused the chooser "quartet" recipe (ctor / attribute registration / dtor / factory) from ICommonPlayerID on cSignatureChooser | 4/4 matched on the first compile, about 1 min per function
- 2026-10-10 | 2 | `tools/scout/packet.py` on 0x80270730..0x80271748 reproduced the hand-made split, the class names and the object sizes in **about 4 s, vs about 35 min by hand** (built by the progress session). Minutes actually saved on the next unit: to be filled in after the next unit | per-unit setup cut by roughly 30 min
- 2026-10-10 | 2 | `tools/scout/rename.py` (dry run) caught a function-order mismatch between source and retail (0x8027101C must precede 0x8027107C) that would have broken linking later | prevents a link-order bug
- 2026-10-10 | 10 | `tools/match/variants.py` alignment-aware scoring | made variant search work on the 0x290 function: 3 runs to MATCH
- 2026-10-10 | W3 | EA static-init TUs (#52-#71 range): each TU = one big setup fn + 0x60 `__static_initialization_and_destruction_0` + 0x2c `_GLOBAL_.I.<first global>`. A `static` global gives a random `_GLOBAL_.I.<file>gZj..` name per compile; make the object non-static (external linkage) and the name becomes `_GLOBAL_.I.<symbol>`, deterministic | cookbook (3) | 12 units generated by one script in ~3 min
- 2026-10-10 | W3 | `__static_initialization_and_destruction_0` repeats across units: rename.py refuses duplicates; mark each `scope:local` in symbols.txt (works with dtk/diff_unit). rename.py could do this automatically | scout (2) | small
- 2026-10-10 | W4 | EA-lib static-init TUs (#66-#76) all share one shape: `__static_initialization_and_destruction_0` (0x60, ctor call of a 5-word list node at 0x803DA440) + `_GLOBAL_.I.*` wrapper (0x2c). A ~40-line generator (parse init fn's lis/addi, packet.py splits block) produced 11 units; 22 functions matched at first compile. Flags `-Os` without `-G0` (ealib) matched. | cookbook/generator (3) | high for the ~87 static-init units
- 2026-10-10 | W4 | Gotchas: (a) packet's unit start may be the previous TU's `_GLOBAL_.I` wrapper (#66 really starts 0x8036FEA0); (b) `__static_initialization_and_destruction_0` repeats per TU, so symbols.txt needs `scope:local` on all but one or rename.py SKIPs; (c) last rodata end 0x80605477 is unaligned, round up; (d) rename.py needs the .o built first; (e) `extern "C" void f();` needs `(void)` under 2.95 | scout fixes | ~10 min saved next time
- 2026-10-10 | W5 (ealibs) | EA lib TUs compile with `-Os -G0 -fno-rtti -fno-exceptions` (no r13 use in static-init TUs; SDA21 relocs appear without -G0). Static-init pair: `__static_initialization_and_destruction_0` sits FIRST in retail, then the TU's functions, then `_GLOBAL_.I.<first fn mangled>`; objects named by file order | cookbook (3) | saves a flag sweep per ea-lib TU
- 2026-10-10 | W5 (ealibs) | `rename.py` refuses members named `fn_<addr>` ("still used in src") and cannot pair sti/_GLOBAL_ names; hand-edit symbols.txt and mark those two `scope:local` or the DOL hash breaks (duplicate global names across units) | scout (2) | ~5 min per unit until fixed
- 2026-10-10 | W5 (ealibs) | A `.bss` split starting at a non-32-aligned address (`.bss align:32`) breaks the DOL hash; omit .bss from the split for such units | scout packet could warn | ~5 min
- 2026-10-10 | W5 (ealibs) | EA lib TUs in this range are `lbl_8062C668`-allocator pool/list code; the "small boilerplate" tier is mostly 3-instruction accessors that match first try | cookbook (3) | high on counts
- 2026-10-10 | W1 | SDK AI: a read-only register getter folds `lis` + offset and matches; every read-modify-write on a constant register base (`lis`+`addi` base in target) did not, under 6 source shapes and 10 flag/compiler combos. Tell: target has `addi rX,rY,0` for arg copies and a materialised base. Likely needs the original macro/inline shape | cookbook (3) | parked 6 AI functions
- 2026-10-10 | W1 | Verifier's hard-rule scan flags the word "asm" in comments (even "original asm"); avoid it in source comments | — | cost one verify loop
- 2026-10-10 | W1 | rename.py cannot pair a partially-written source; renaming by a small script over symbols.txt was faster | — | small
- 2026-10-11 | W9 (sweep-5) | g++ 2.95 switch balancing: a switch whose index has an ENUM type skips the ASCII cost table and bisects by node count; an int index with all cases in 0..127 uses the cost table. Tell: target root/pivot is the middle by count (here 0x42 of 0x2A..0x5A) but your tree's root is off. Declare `enum E { E_Neg = -1, E_Lo = lo, E_Hi = hi }` and `switch ((E)kind)` (negative enumerator keeps cmpwi signed) | cookbook (3) | fn_80059BDC (0x390, 49 cases) matched on the first try after the finding; would otherwise have been parked
- 2026-10-11 | W9 (sweep-5) | Empty `return;`/`break;` cases and consecutive case values that share a body are merged into range tests by group_case_nodes; retail kept one compare node per kind. Give every case a non-jump first insn (an unused `T* q = &r->field;` in each empty case) and do not let consecutive values share a label (duplicate the body) | cookbook (3) | fn_80055204 (736 ins) tree matched in 3 edits
- 2026-10-11 | W9 (sweep-5) | When the target keeps the switch index in r4 (the dead arg register) but you get r0 (first in rs6000 REG_ALLOC_ORDER), the original passes the index to a call in the default branch (here a vararg diagnostic `fn_8033E958(fmt, kind)`); global-alloc prefers r4 for the copy. The call shows no `mr r4` in the target | cookbook (3) | last 640 mismatching slots of fn_80055204 fixed by one argument
- 2026-10-11 | W9 (sweep-5) | ngccc compiler dumps: `python cc.py file.cpp -dg -dl -dr -ds -dR` (flags passed straight to cc1plus) writes `<tmp>.greg/.lreg/.rtl/.sched2` into %TEMP%; `.lreg` lists pseudo numbers, uses and live length, `.greg` ends with "Register dispositions". Use it before guessing at register-allocation near-misses | tooling (2) | saves guesswork; script is 10 lines (subprocess with SN_NGC_PATH set to the compiler dir)
- 2026-10-11 | W9 (sweep-5) | Set difference of `cmpwi` immediates in the target vs `case` values in the source (10-line script) tells at once whether a switch near-miss is a case-set problem or a tree/pivot problem | tooling (2) | 2 min per switch near-miss
- 2026-10-12 | Opus (families 6) | Score-gated recipe appliers: once a recipe is a mechanical source rewrite (here: route `(float)n * (1/60)` through an inline), a script that rewrites one function at a time, compiles the unit copy and keeps only rewrites that reach MATCH found 11 extra functions in 6 units in about 10 minutes (two also needed a store-order permutation) (`scratchpad/W8o6/fam3gen.py`, `fam3gapply.py`). Applying the rewrite unit-wide made 2 functions worse | tooling (2) | high for any recipe that is a regex rewrite
