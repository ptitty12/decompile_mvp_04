# Speed-ups: a living log

Owner's request (2026-10-10): while matching gets going, record every chance to
go faster, so we can decide which ones to adopt.

**Agents: add to the observations log** whenever something costs you noticeable
time, repeats, or could be automated. One line each: what happened, the idea,
and a rough impact. Don't fix it on the spot if it's outside your unit. Ideas
move into the candidate list, and their results go under "Tried".

Status keys: `idea`, `trying`, `adopted`, `rejected`, `needs owner`.
Since 2026-10-12 the owner pre-approves downloads, persistent services and
cost (DECISIONS 2026-10-12). Only owner-held material, such as the owner's
own discs, still needs the owner.

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

1. **Near-miss queue and decomp-permuter.** `idea`, approved by the owner 2026-10-12 (download).
   Caveat: the permuter parses C only (docs/NEARMISS.md), so C++ game units need a C extraction of the function first.
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
7. **Symbols from other builds the owner owns.** `needs owner` (owner-held discs; asked 2026-10-12)
   Source paths read `C:/mvp2004/source/...`, so the code is shared with MVP
   2004. Other platform builds (PS2, Xbox, PSP) of MVP 2004/2005 sometimes
   shipped unstripped executables or map files. Any copy the owner owns that has
   symbols would give function names and unit boundaries, maybe types too. This
   could be the biggest single speed-up, but it's unknown until checked. The
   owner's own discs only, never downloaded.
8. **A first-draft decompiler (m2c, PowerPC).** `adopted` (tools/match/m2c_draft.py; m2c in an external venv)
   It produces starting C from the asm, which is faster than writing it by hand
   or cleaning up Ghidra output. Most useful on mid-size functions.
9. **Route work to different models and effort levels.** `idea`, approved by the owner 2026-10-12 (cost)
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

14. **Twin examples and callee prototypes for each function.** `adopted` (tools/match/twins.py, 2026-10-13)
    For any function: the matched functions that look most like it (opcode
    edit distance, shared callees, field offsets) with their source, plus every
    callee's prototype as already written in matched source. Basis: similarity-
    guided examples were the biggest long-tail gain in the Snowboard Kids decomp
    ("The Long Tail of LLM-Assisted Decompilation", blog.chrislewis.au). On
    main few close twins remain, but most callees of the big functions are
    already called from matched code, so the prototype part covers the tail.
    See "Tried".
15. **ProDG GCC 2.95.3 knowledge from the RE4 decomp.** `trying`
    adonis-singh/re4 (Resident Evil 4, GameCube debug build, byte-identical)
    uses our exact compilers: ProDG GCC 2.95.3 and CodeWarrior GC/1.2.5n. Its
    526 `COMPILER-DIFF` notes are a catalog of source tricks for this compiler,
    to be distilled into docs/PATTERNS.md. Also check its SDK/libsn sources
    against our remaining SDK functions.
16. **The strongest model on the big-function tail.** `trying` (owner 2026-10-13: a few test cases before any broad use)
    Melee's AI co-author lines were mostly Claude Fable 5 (per an analysis of
    its commits), and the RE4 author credits Fable 5.1. Test: three never-
    attempted 1.4-2.5 KB functions with Fable 5.1, plus a Sonnet 5.5 control on
    one of them, same brief and timebox. Results under "Tried".
17. **Melee's working rules.** `adopted` (prompts/11_TEAM_WORKER.md, 2026-10-13)
    From the Melee decomp's agent skill: about 10 minutes per small function,
    and at 95-99% fix headers and prototypes before the body. Permuter output is
    a lead, not a recipe: Snowboard Kids dropped the permuter because the model
    copied its artifacts, and the lead saw the same on 2026-10-13.
18. **Typed m2c drafts (`m2c --context`).** `idea` (blocked)
    m2c reads structs and prototypes from a context file, but only
    preprocessed plain C. Our headers are C++ (classes, methods, `extern "C"`),
    so tools/decompctx.py output doesn't parse. It needs a C-flattened header
    export. twins.py's callee prototypes cover part of the need.

19. **An integration lock shared by every integrator.** `needs owner` (Codex sessions are outside the Claude team)
    The lead, the Codex swarm's integrator and side sessions all push to main.
    The verify gate takes 6-20 min, so a gated push loses whenever someone else
    pushes in that window. On 2026-10-13 one batch passed verify three times
    before its push landed, and the lead reported the same. A cooperative lock
    (e.g. a ref or a file that an integrator claims before verifying and
    releases after pushing) would stop the wasted verifies. All three
    integrators have to honor it, so the owner would tell the Codex coordinator.

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
- 2026-10-12 | enablers (fleet dashboard) | Measure speed in code bytes per hour, not functions: verified code/h was flat from session 2 (about 63 KB/h) to session 3 (about 55-70 KB/h) while functions/h fell from about 170 to about 100-130, because the remaining 3,428 functions average about 860 B against about 140 B matched. The near-miss share of worker commits climbed through session 3 (about 4% at 18:00, about 22% at 19:00-20:30, 40-60% after 21:00), and the last main build has 263 functions at >= 99% (100 KB) and 345 at 95-99% (123 KB). `tools/fleet_dashboard.py` tracks all of this live | permuter queue (1), measure (13) | the >= 99% band is about 3.5% of the remaining code; a dedicated near-miss pass may beat fresh batches now

- 2026-10-13 | research (REA session) | How other decomps finished. Melee (19,828 functions) took six years with 155 contributors, and AI closed its tail. RE4 was possible because the debug build shipped symbol files naming every function. Mario Strikers Charged reused its predecessor's matched classes. Snowboard Kids 2 jumped from 25% to 58% with one-shot LLM matching, then stalled near 75%; human experts finished its last functions. Its author says Claude "more or less gives up immediately" above about 1,000 instructions. No public example found of a large retail game matched in days without symbols or a donor codebase | 7 (symbols), 14, 16 | sets expectations: the tail is slow everywhere
- 2026-10-13 | research (REA session) | Remaining work on main (report at 8fef9a8f): 3,165 functions, 2.88 MB. 85% of those bytes are in functions >= 0x200, and 1,600 of those were never attempted. Built from source: 6.5% of code, 234 of 845 units; 1.30 MB of data still sits in auto chunks | 13 (measure) | the progress card now shows built-from-source

- 2026-10-13 | REA session (model test) | Four agents worked on never-attempted big functions with twins.py and the same brief. The full build plus verify.py took 10-20 min per commit under load, longer than the matching (16-35 min). Main moves every 10-20 min (Codex batches, lead merges, progress card), so a 12-min verify often loses the push race. integrate.py --push then refuses ("origin/main moved") | 10 (tight loop), new: verify against the progress bot's report of origin/main instead of rebuilding the baseline | halves the gate; fewer lost races
- 2026-10-13 | REA session (model test) | rename.py needs the unit with its extension (`game/tu_800D4D0C.cpp`); without it, it reports "no .text range". Overlay units (fe/db) get that message either way, and their extern "C" symbols pair by name | 2 | small, recurring confusion

- 2026-10-13 | REA session | Push race: the twins1 batch passed verify.py 3 times (17:23, 17:29, 17:35) and lost each push to a newer main; it landed on attempt 4 (17:47). The lead saw the same on nm-08. Each lost round is a full build+verify | 19 | about 20 min and 3 full builds per batch at peak

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

- 2026-10-13 | Return-layout shortlist | Stack-frame-only differences can expose oversized reconstructed return buffers. New tools/match/frame_candidates.py found three exact fixes (792 B) by checking actual callee layouts: two floats, two floats, five words. Equal instruction count and branch paths filter the search; a smaller frame alone is not evidence. Another 820 B candidate remains parked because its callee still establishes a real twelve-byte Vec3. | bounded search / ABI evidence | Three accepted matches, one rejected lead; no speculative buffer shrinkage.
- 2026-10-13 | 14 | `twins.py rank` over all 3,165 unmatched functions (2.5 min). Best-twin score >= 0.9: 5 functions; 0.7-0.9: 108; below 0.6: 2,953 (2.80 MB). Exact-shape clones: 8 (380 B). The bulk sweeps already took the look-alikes. For the 1,762 functions >= 0x200: 72% of their callees are already called from matched code, 432 have every callee covered, and 571 share at least half their callees with one matched function. Example: fn_800D69E8 (0x5B4, twin score 0.57) surfaced two same-family vslot2 functions and all 8 callee prototypes | close twins are rare now; callee context is the part that helps the tail
- 2026-10-13 | 18 | `m2c --context` with decompctx.py output for game/tu_800D4D0C: "Syntax error when parsing C context. Directives not supported yet" (it needs preprocessed input), and the context holds C++ classes that pycparser can't read | deferred
- 2026-10-13 | 16 | Fable 5.1 on three never-attempted big functions (same brief, twins.py, 80-min timebox): game fn_800D69E8 (1,460 B, tweaker registration) matched on its first source version in 35 min, 147k tokens; fe fn_8048C9F4 (2,460 B, widget/frame-layout heavy) matched in 34 min, 3 iterations, 218k tokens; db fn_8059E708 (2,360 B, 119-case bit getter) matched on the first build in 16 min, 92k tokens. Sonnet 5.5 control on fn_8048C9F4: also matched, about 24 min to the match, ~14 iterations, 227k tokens | 3/3 matched (6.3 KB). The big functions were mostly never attempted because batches capped size at 0x400-0x800, not because they're too hard. With twins.py both models match 2.5 KB functions in under 40 min; Fable needed fewer iterations, but on the one A/B the token cost was the same. Next: lift the size cap for Sonnet batches and keep Fable for functions that fail twice
- 2026-10-13 | 14 | What the agents said twins.py gave them: the "matched functions sharing the most callees" line was the most useful in all four runs. It led to fn_80147F00's declaration block (extern "C" with explicit self), fn_8046F510's record-loop idiom and fn_8059F18C's bit-getter expressions. Callee prototypes exposed headers with the wrong arity (fn_8056A2F8 takes 10 args; fn_800D7008). Missing: string contents of the target's .rodata, and stack-slot reuse rules (PATTERNS covers those) | adopted; consider printing referenced string literals
- 2026-10-13 | 6, 15 | RE4 SDK reuse. Two Sonnet workers ported dolsdk2004 bodies from adonis-singh/re4 into our SDK units: 10 functions, 8.9 KB (__ARChecksize 6,132 B, PackArgs, GetFontCode, ParseStringS, __OSModuleInit, DVDGetCurrentDir, __OSInitAudioSystem, __OSStopAudioSystem, __GXAbort, GXAbortFrame), merged in aa9bfc7b. Another ~12 KB match exactly but only per original file with `-opt nopeephole`. Our merged code-only units mix files with different flags (tu_804330D0 is 7-8 files; GXInit.c, OSTime.c, OSRtc.c and OSReset tails are the others). The splits and per-section drafts were handed to the lead, who started with OSTime.c | reuse works; unit splits along the original files are the remaining SDK lever
- 2026-10-13 | 14 | twins1 worker, three never-attempted mid-size functions with strong twins (0x27C-0x288): 3/3 matched, 1.9 KB, in 3, 5 and 29 min (6330ed05). The 29-min one was a loop strength-reduction decision; recipe in PATTERNS "Loop dumps". Its requests went into twins.py --diff: callee/offset/constant substitution tables, a shorter/longer note, and a stale near-miss comment flag | twins with score >= 0.85 are near-mechanical
