# Q4 log: a faster emulation thread

Side session `Q4`, branch `engine/q4-speed` (from origin/main `20e772c1`: P2's threaded
engine, CLK2, Q1's GP view, Q2's sound and simulated slower machines). Chrome 155 headed
on this PC (i7-14700K, RTX 4070 SUPER, Windows 11), Playwright, the owner's CISO picked as a
file; Node 24 (V8, the engine Chrome uses) for the translated code alone. Owner decision F1
(2026-10-16, during the session) relaxed "bit-exact to the Gekko" to "the same on every host";
sections 7 and 8 use it. The results (section 10) are on the merged engine (`3aa0d921`: this
branch with origin/main `ad92bce1`, Q5) against origin/main.

## 1. Where the emulation thread's time went (before)

A profiling build (guest names in the module, `--profiling-funcs`), threaded, 6 s of paced
CPU vs CPU play from field 9,000: the emulation thread idle 26.6 %, translated code 48.4 %,
the engine 23.4 %. Inclusive, `Hardware::write` (the write-gather pipe's path into the
runtime) was 15 % of the thread's time and `GpReads` with its marking about 5 %; the
hottest translated functions `fn_803EB000` (skinning: three matrices blended with
paired-single multiply-adds and written to the GX FIFO with `psq_st`), `fn_803BD358` (a 4x4
matrix product in singles) and `fn_80369878` (mixed integer and floating point, many calls).

Elimination runs (unpaced CPU vs CPU, fields 8,000-11,600, ms per field in
`mvp_run_fields`, the threaded engine): everything 11.1; without `GpReads` and its marks (and
so without write waits) 9.9; without any GX command sent to the render thread 9.1; without
the render thread 9.0. So the render-side bookkeeping on the emulation thread cost about 2
ms of its 11 ms per field, half of it the marks for write tracking.

Per field of play (Node, `mvp-boot-wasm`): 510 KB through the write-gather pipe (15,900
bursts), 45,700 GX commands, 8,780 primitives (99 % with indexed attributes), 52,000
vertices, 620 display list calls; 3.3 million instructions run (another 3.2 million skipped
by the idle skip).

## 2. Lever 1: the GX FIFO's per-burst path

### What a burst does, and what the guest can see of it

A store to the write-gather pipe that completes 32 bytes writes them to the CPU FIFO in
MEM1 at the PI write pointer, moves that pointer (wrapping at the FIFO's end), moves the CP
write pointer with it when linked, and lets the GP (infinitely fast, E0b-GX1) read up to it:
the GP parses the commands, a draw-done or token command sets the PE state and asks for an
interrupt check (`kick`: the next safe point runs), and the read pointer moves, which also
asks for one. The guest can see all of that: the FIFO's bytes in memory, the PI and CP
pointers and the CP status (MMIO reads), the PE token and finish bits, the interrupts at the
next safe point. The renderer, a host-side observer, gets every command; the threaded
engine copies it into the render ring and marks what the render thread will read of guest
memory, so that guest writes there wait (P2-T2).

### What was slow

- The game writes its matrices with `psq_st`, whose second word goes to `0xCC008004`. The
  module's own append path (P2) took only `0xCC008000`, so about 40,000 stores per field
  (both words of every `psq_st` to the pipe, and every store that completes a burst) went
  `h.wr32` -> `rt.write32` -> `Hardware::write` (its MMIO bookkeeping) -> `wgp_write`.
- Per command, the GX FIFO copied 24 head bytes and cleared the rest of a report record
  (two `memory.copy`/`memory.fill` calls in WebAssembly, each a call out of the module);
  the observer got one virtual call per command, and the threaded engine one ring record.

### The design (exact by construction)

Every guest-visible step stays where it was: each burst is written, pointed to, parsed and
its effects applied at the store that completes it, in the same order as before. What
changes is only how the host gets there:

1. **The module takes the pipe's whole 4 KiB block** (as `Hardware::write` does: its address
   bits there are ignored), appends a store that leaves the burst unfinished itself (as P2
   did), and sends one that completes it or reaches into the next burst to a new import,
   `rt.wgp_store`, which runs `Hardware::wgp_write` for it: the same appending and the same
   burst. What `Hardware::write` did besides for such a store (count it, end the poll
   detector's run, keep its access log, which is full by then: `fast` is only set once it
   is) the module does before the call. Counted per address, these stores now show under
   `0xCC008000` (`write_counts`, statistics).
2. **One observer call per push**: the GX FIFO collects the commands a push executes
   (display lists' included, in order) and hands them over before it returns, while the
   bytes they point at (the burst, the pending buffer, guest memory for lists) cannot have
   changed: no guest code runs in between. The default `gx_commands` passes them one by
   one, so other observers see exactly what they saw.
3. **One ring record per push** in the threaded engine (`kGxBatch`: the count, the lengths,
   the bytes), handed to the renderer command by command on the render thread. Marks for
   write tracking use the position after the record: the render thread finishes a record
   as a whole, so a write waits for the same commands as before, or also for the few after
   them in the same burst (later, never earlier).
4. The report kept for a lost stream takes its commands' first bytes from a 4 KiB history
   of the stream (one copy per burst) instead of a copy per command.

Exactness evidence: guest lines and renderer digests in section 11; a unit test runs a
translated program that writes bytes, halfwords, words, `psq_st` pairs and singles, `stfs`
and `stfd` to the pipe (straddling bursts, `0xCC008004` included) and compares the FIFO in
memory, its write pointer, the bursts and the store counts with the same values written
through `Hardware::write`; another checks that an observer gets each push's commands at
once and in order, the same as one that takes them one by one.

## 3. Lever 3: write tracking's marks, once per epoch

### What was slow

`GpReads` reports, for every command, the guest memory the render thread will read for it,
and the emulation thread marks those bytes (`ppc::g_gp_pages`, one entry per 64 bytes) with
the ring position after the command, so that a guest write there waits until the render
thread has finished that command. In play 99 % of the primitives use indexed attributes;
each one reported its arrays' element ranges (3.2 a primitive) and each range was marked
entry by entry: 1.17 billion entries over the CPU-vs-CPU session (about 100,000 a field),
most of them static arrays the game never writes. With the format's layout worked out again
for every primitive, `GpReads` and its marks cost about 1 ms of the 11 ms field.

### The design

- **Entries hold an epoch, not a position.** The epoch is the number of ring publishes so
  far; it ends at the next publish, which makes every record committed during it visible.
  The ring keeps the position each of its last 65,536 publishes made visible
  (`RenderRing::publishes`, `published_at`). A guest write that meets a marked entry waits
  until the render thread has finished every record up to the end of that entry's epoch
  (for the epoch still open: up to everything committed so far). That end is at or after
  the command that marked the entry: the write waits for that command, or also for the
  few after it in the same epoch (a publish comes every 4 KiB of records, about 1/270 of a
  field of play). The sweep at each VI field forgets entries whose epoch the render thread
  has finished.
- **Within an epoch, an array's elements are reported once.** Since every command of the
  epoch is covered by the epoch's end, an entry marked once in an epoch stays good for the
  epoch's later commands. `GpReads` keeps, per CP array, the element range it reported in the
  current epoch (with the array's base, stride and element size); a primitive whose range
  lies inside it reports nothing, one that overlaps or adjoins it reports only the new
  elements. The owner starts a new epoch whenever a mark could have gone away: every
  publish (the epoch changes), every write wait and sweep that clears entries
  (`GpReads::forget`), and every snapshot a DMA or the pipe ends (Q1's GP view: those
  lines are read from memory again and need marks). Without `set_epoch` (the unit tests'
  default), every range is reported as before.
- The format layouts are kept until a VCD or VAT write; the per-entry check for Q1's
  snapshots is made only in 4 KiB pages that have a snapshot this field.

Exactness: guest state cannot depend on it (waits change only host timing). The render
thread still reads guest memory as the inline renderer does: every write to memory a
command still has to read waits for that command, as before (renderer digests, section 11).
Unit tests: a range reported once per epoch, only the new elements of an overlapping one,
everything again after `forget` or in a new epoch; the ring's publish history.

## 4. Levers 2 and 4: floating-point loads and stores, psq

The hot functions are paired-single and single-precision matrix code: `lfs`/`stfs`,
`lfd`/`stfd` (the FPR saves of every prologue and epilogue), `psq_l`/`psq_st` with GQR 0
(float), and `ps_madds0`/`fmadds`. Node A/B (CPU vs CPU, the stretch of play from frame
7,300 to 10,544, ms per field; parallel pairs, so about 1 % noise):

| Variant | ms/field |
|---|---:|
| before (after lever 1) | 8.58-8.68 |
| `lfd`/`stfd` through one 64-bit helper each (`h.rd64`, `h.wr64`) | 8.53 |
| + `lfs`'s conversion inline at each site | 8.62 |
| + `stfs`'s conversion inline at each site | 8.44 |
| + float `psq_l`/`psq_st` inline at each site (GQR type tested in the code) | 8.76 |
| all of them inline (module 62.7 -> 66.6 MB) | 8.88-8.92 |
| **fat helpers instead** (below; module 62.1 MB) | **8.10-8.16** |

Inline expansion at the call sites made V8's code slower, as Q2 found for the MEM1 path
(Q2-S1): bigger functions with more branches cost more than the calls save. What paid was
the opposite: fewer, fuller helper calls, each with its common case first.

- `lfd`, `stfd`: `h.rd64` / `h.wr64`, one page check for both words (plain loads or stores,
  the threaded engine's write check over the 8 bytes), else the two 32-bit helpers, high
  word first, as before.
- `lfs`: `h.lfs`, read32 and `fp::single_to_double` in one call (`f64.promote_f32`, exact for
  every non-NaN single; a NaN takes `h.s2d`'s bit formula).
- `stfs`: `h.stfs`, `fp::double_to_single` (the bit formula; `h.d2s` where the result is a
  single denormal, exponents 874-896) and write32 in one call.
- `psq_l`: the helper first tries a float pair (load type 0-3, W clear) in one mapped page:
  both words read, both converted as `lfs` does, both halves written; anything else as
  before.
- `psq_st`: the helper first tries a float pair (store type 0-3, W clear): both words
  (`fp::double_to_single_ftz`) to one mapped page, or appended to the write-gather pipe
  while they leave its burst unfinished (as two `h.wr32` would), else through `h.wr32`.

Exactness: `test_wasm_digest` (every GQR type and scale, NaNs, infinities, denormals, the
flush boundary, page-crossing accesses: translated code against the interpreter, state and
RAM after every execution) and `test_wasm_lockstep` (the FP moves and conversions on edge
cases; the pipe test of section 2) pass; guest lines in section 11.

## 5. The runtime's own per-field work

Two small changes in what the emulation thread runs around the translated code
(Node: about 1 %, `8.10-8.17` -> `8.00-8.13` ms per field of play):

- A safe point that delivers nothing reschedules with the interrupt state it has just
  worked out (one `pi_cause` per safe point a register write asked for, not two);
  `pi_cause` reads the CP status only when a CP interrupt is enabled.
- `GxFifo` keeps the bytes of an incomplete command in a buffer with a start offset
  (no vector insert and erase per burst); the report ring has 32 entries (a mask).

Pure functions of the same state: the guest cannot tell.

## 6. Lever 2: the emitter (FPR cache, compare and branch)

**FPR halves in f64 locals** within straight-line code: every FPR write goes to the
`Cpu` struct and to a local; reads come from the local while it is known to hold the
value. FP instructions load their sources into locals first (on every path) and reload
what `rt.exec` wrote after a slow path, so memory is always current and nothing has to
be written back at a call or exit. The cache ends at labels, calls, safe points, the
MSR[FP] check, `rt.exec` and `psq_l`'s helper; FPSCR[RN, NI] is checked once per run of
such code. Node: `8.00-8.13` -> `7.69-7.77` ms per field.

**Compare and branch:** a backward liveness of the eight CR fields (calls, returns,
helpers, safe points and the MSR[FP] check read them all) finds compares whose field
nothing but the next conditional branch reads; those set no CR bits and the branch
tests the operands directly. The module is 0.55 MB smaller; Node play within noise
(`7.64-7.74`), intro -2.6 %, menus -1 %.

Both: same results by construction (the Cpu struct holds every value at every point
where anything else can read it); `test_wasm_digest` and `test_wasm_lockstep` pass;
guest lines in section 11.

## 7. F1: the fast floating-point model

Owner decision F1 (2026-10-16) lets the engine differ from the Gekko as long as every
host computes the same. The **fast model** (`ppc/fp.h`, the default) applies whenever
FPSCR[RN] = 0 and NI = 1 (the game's setting; anything else keeps the exact model):

- one IEEE double operation per step in a fixed order: a*c, then +-b (no fused
  multiply-add, which hosts do differently), then the negation of the nm forms; no
  `force25`;
- a single-precision result is that double rounded to f32 and back; a result below the
  normal range of its precision (2^-126 single, 2^-1022 double) becomes a signed zero
  (NI);
- every NaN result is the default NaN `0x7FF8000000000000`: hosts disagree about NaN
  signs and payloads (x86 makes them negative, ARM positive, WebAssembly leaves it
  open), so no host's NaN bits ever reach a register;
- the estimates: 1/b rounded to single (`fres`), 1/sqrt(b) in double (`frsqrte`);
- `fctiw`/`fctiwz`, conversions, moves, compares and selects are exact integer code as
  before (the same on every host anyway).

Every step is IEEE round to nearest with no flush to zero on input or output, which
WebAssembly guarantees and native builds get with `/fp:precise` (MSVC) or
`-ffp-contract=off -fno-fast-math` (clang, gcc: no contraction into FMA on ARM). The
semantics library (`fp.cpp`, `fp::fast_result`) and the WebAssembly emitter
(`emit_fp_fast`: one `select` chain per result, no branches) compute the same rules;
`test_wasm_digest` runs its FP edge cases in both models against the interpreter
(3.54 million executions each, no difference) and `test_fp` checks the fast model's
rules on 200,000 random operations.

**The exact model stays** as a test and fallback option: `fp::g_model = Model::Exact`
for the semantics library (`test_fp`, `test_digest` and the exact half of
`test_wasm_digest` set it) and `WasmEmitOptions::fp_exact` for the emitter. Nothing in
the engine sets either by default; a build or debug option would only have to set both.

Node: `7.64-7.74` -> `6.71-6.73` ms per field of play (-13 %), menus -10 %. The guest
lines did not change (CPU vs CPU to 11,600 fields, human pitching to 9,000, WEB.md's
700/2,400/3,600 checkpoints): the game's values never reach the cases where the two
models differ (single products are exact in double, so a*c+b rounds the same but for
rare double-rounding midpoints), so WEB.md's reference lines stay as they are.

## 8. Native implementations of hot game functions

F1 also allows native implementations of the hottest game functions if they are ours
and deterministic. A new HLE kind, `Native` (`runtime/hle.h`, `runtime/hle_game.h`):
host code for a game function, keyed by its retail address, **equal to the original in
everything the guest can see**: the same registers, memory and hardware stores, each at
the guest PC and ticks the original's instruction has, and the same instruction count
at the end. It runs only when the state it is written for holds (MSR[FP] set, the fast
FP model, a float GQR0, every load from plain memory) and calls the translated
original otherwise. The interpreter (`hle_interpret`) always runs the original, so the
lockstep checker compares the two.

`fn_803EB000` (skinning: three bone matrices, indexed by the low bytes of their
weights, blended by weight, combined with a view matrix and sent down the write-gather
pipe as an XF load; 112 or 66 instructions, 20 million calls in the CPU vs CPU run, 3 %
of the guest's instructions but 13 % of the emulation thread's time with its helper
calls) is the first one. Its arithmetic is `fp::fast_result` (shared with `fp.cpp`), its
loads read guest memory directly once the spans are known to be plain memory (reads
there have no effects, so their order before the first store does not matter; the one
load after a store is made where the original makes it), and its stores go straight
into the pipe's model (`Hardware::wgp_store`: what `write()` does, inline while nothing
is logged and the store leaves the burst unfinished; the guest PC and ticks are set
where a burst completes).

Exactness: `local_hle_native` (needs the disc) runs the original from `main.dol` in the
interpreter against the native code on random operands (zeros, denormals, infinities,
NaNs, overflow and underflow, both paths, the pipe and memory as destinations, and the
fallback states): 200,000 trials, no difference in registers, ticks, memory or the
stores' address, value, size, PC and ticks; a deliberately broken variant fails it at
once. `test_devices` checks `wgp_store` against `write()` (before and after the access
log fills). The guest lines are unchanged, native and WebAssembly.

Speed: about 3 % (Node, two runs at once pinned to two E-core clusters so the
machine's other load hits both alike: play `12.17/12.46` vs `12.44/13.26` ms per field,
thread CPU `11.47/12.17` vs `11.92/12.55`). Less than the profile promised: the native
code does the same floating-point work (two `fast_result` per paired-single operation,
about a hundred per call), only without the helper calls, so it still takes 7 % of the
thread. Its arithmetic in f64x2 SIMD would roughly halve that, but would make the page
require WebAssembly SIMD (not done; section 12).

## 9. Tried and dropped

| What | Result | Why dropped |
|---|---|---|
| `lfs`/`stfs`/`psq` conversions inline at each site (section 4) | 1-9 % slower | bigger functions cost V8 more than the calls save |
| Coarse 4 KiB page marks for write tracking | fewer entries, slower | extra loads on the store side |
| Per-page dirty lists, unconditional marks ("marks2") | inconclusive under load | no clear gain |
| Stack (r1-relative) accesses through their own helpers | 2 % at most (a diagnostic split) | stack accesses are 4 % of the helper calls |
| Indirect calls (`bctrl`, `blrl`, `bctr`) looked up in the module: the runtime's entry table as `env.native`, a `call_indirect` instead of `rt.call_indirect` | Node pinned pairs `11.61/11.44` vs `11.54/11.56` ms per field | no gain for a wider module interface |

## 10. Results (the merged engine against origin/main)

**Emulation alone.** Node (`mvp-boot-wasm`, CPU vs CPU from power-on to the poll of frame
10,544, translation included), two runs at once pinned to two E-core clusters, twice with
the clusters swapped: origin/main 136.6 / 138.2 s, merged 112.1 / 110.2 s (-19 %). Per
lever (the stretch of play, frames 7,300 to 10,544, ms per field; run on a quieter machine
earlier in the session, so comparable within the column only):

| After | Node play, ms/field |
|---|---:|
| origin/main | 8.92-9.41 |
| lever 1 (the GX pipe path; lever 3 is on the render side, not in Node) | 8.58-8.68 |
| lever 4 (fuller FP load/store helpers) | 8.10-8.17 |
| runtime safe points, GX parse buffers | 8.00-8.13 |
| FPR cache | 7.69-7.77 |
| compare and branch | 7.64-7.74 |
| the fast FP model (F1) | 6.71-6.73 |
| `fn_803EB000` natively | about 3 % less (pinned pairs, section 8) |

Chrome, threaded, unpaced CPU vs CPU (fields 8,000-11,600, ms per field inside
`mvp_run_fields`, interleaved): origin/main 12.79 / 11.43, merged 10.73 / 9.83 (-15 %).
Earlier in the session, on a quieter machine: 11.13-11.57 before, 9.19-9.44 with the
fast FP model (before the native function).

**Match sessions.** Chrome 155 headed with sound, the match scripts (CPU vs CPU: unpaced to
field 8,000, measured paced 8,000-11,600; human pitching: 6,600-9,000), interleaved
before/after, two rounds where there are two values. "hostSlow N" is Q2's simulated slower
machine (each engine thread spins N - 1 times its working time, plus Chrome's CPU
throttling) from the measured stretch on; hostSlow 1.3 stands in for the owner's ThinkPad
(Ryzen 7 PRO 7840U). "4 E-cores": Chrome pinned to four efficiency cores
(`--affinity F000000`). Emulation ms/field is the host time per field inside
`mvp_run_fields` (with hostSlow, the simulated machine's: the spin included); rendered fps
is presents per second, new frames/s the presents that showed a new game frame; p95 and
"> 25 ms" are over the intervals between presents and between composited frames (the
screencast). Other sessions loaded this PC during every run (CPU load 0-58 % at the run
edges, up to 100 % at times in between), so single values move by several percent.

| Config | Match | Build | Game speed | Emulation ms/field | New frames/s | Rendered fps | Present p95 ms | Presents > 25 ms | Composited p95 ms | Composited > 25 ms | Underruns/min |
|---|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| this PC | CPU vs CPU | before | 1.000 / 1.000 | 11.8 / 12.5 | 58.9 / 57.6 | 59.8 / 58.9 | 26 / 26 | 5.4 % / 5.9 % | 20.5 / 20.7 | 0.6 % / 2.8 % | 0.0 / 0.0 |
| this PC | CPU vs CPU | after | 1.000 / 1.000 | 9.4 / 10.0 | 59.0 / 58.4 | 59.9 / 59.8 | 25 / 25 | 6.0 % / 5.5 % | 21.5 / 21.4 | 1.6 % / 1.6 % | 0.0 / 0.0 |
| this PC | human pitching | before | 1.000 / 1.000 | 11.4 / 12.0 | 59.4 / 58.8 | 59.9 / 59.2 | 24 / 25 | 3.0 % / 6.2 % | 21.0 / 20.6 | 0.7 % / 1.7 % | 0.0 / 0.0 |
| this PC | human pitching | after | 1.000 / 1.000 | 9.2 / 10.3 | 58.9 / 59.1 | 59.9 / 59.9 | 25 / 25 | 5.5 % / 5.0 % | 22.3 / 20.9 | 2.5 % / 1.4 % | 0.0 / 0.0 |
| hostSlow 1.3 | CPU vs CPU | before | 0.954 / 0.935 | 15.8 / 16.4 | 47.5 / 45.9 | 47.9 / 46.3 | 41 / 44 | 21.5 % / 23.4 % | 34.8 / 35.0 | 14.0 % / 14.4 % | 0.0 / 0.0 |
| hostSlow 1.3 | CPU vs CPU | after | 1.000 / 1.000 | 12.3 / 12.4 | 56.7 / 57.9 | 58.0 / 58.9 | 27 / 26 | 9.7 % / 6.7 % | 20.8 / 21.4 | 1.4 % / 2.5 % | 0.0 / 0.0 |
| hostSlow 1.3 | human pitching | before | 0.976 / 0.931 | 14.6 / 16.4 | 52.0 / 44.9 | 52.9 / 45.9 | 36 / 42 | 12.0 % / 23.7 % | 34.3 / 49.8 | 11.5 % / 22.3 % | 0.0 / 0.0 |
| hostSlow 1.3 | human pitching | after | 1.000 / 1.000 | 12.4 / 11.8 | 58.4 / 58.0 | 59.1 / 58.7 | 25 / 25 | 4.9 % / 4.5 % | 21.7 / 21.7 | 2.9 % / 2.9 % | 0.0 / 0.0 |
| hostSlow 2 | CPU vs CPU | before | 0.670 / 0.608 | 24.5 / 27.1 | 25.7 / 24.1 | 26.6 / 24.2 | 64 / 74 | 69.0 % / 76.0 % | 79.2 / 93.7 | 69.9 % / 74.3 % | 0.0 / 0.6 |
| hostSlow 2 | CPU vs CPU | after | 0.832 / 0.819 | 19.5 / 19.8 | 33.1 / 33.9 | 33.4 / 34.5 | 49 / 54 | 53.4 % / 48.2 % | 57.3 / 63.0 | 56.3 % / 50.1 % | 0.0 / 0.8 |
| hostSlow 2 | human pitching | before | 0.695 / 0.695 | 23.9 / 23.7 | 27.0 / 28.0 | 27.2 / 28.1 | 63 / 66 | 71.5 % / 63.9 % | 75.5 / 80.1 | 70.2 % / 63.6 % | 0.0 / 0.0 |
| hostSlow 2 | human pitching | after | 0.860 / 0.775 | 18.9 / 21.0 | 36.3 / 32.0 | 36.5 / 32.3 | 49 / 56 | 45.5 % / 53.4 % | 55.1 / 67.4 | 43.7 % / 55.1 % | 0.0 / 0.0 |
| hostSlow 4 | CPU vs CPU | before | 0.311 | 53.5 | 11.9 | 12.0 | 141 | 98.3 % | 148.3 | 97.6 % | 10.8 |
| hostSlow 4 | CPU vs CPU | after | 0.380 | 43.8 | 14.6 | 14.7 | 121 | 97.6 % | 135.7 | 96.3 % | 0.4 |
| hostSlow 4 | human pitching | before | 0.328 | 50.7 | 12.6 | 12.7 | 135 | 100.0 % | 143.1 | 98.5 % | 2.6 |
| hostSlow 4 | human pitching | after | 0.397 | 41.9 | 15.2 | 15.3 | 109 | 99.2 % | 133.6 | 96.1 % | 0.0 |
| 4 E-cores | CPU vs CPU | before | 0.834 / 0.830 | 19.5 / 19.6 | 32.9 / 32.4 | 33.1 / 32.5 | 50 / 50 | 54.4 % / 59.1 % | 53.8 / 53.3 | 58.5 % / 60.7 % | 0.0 / 0.0 |
| 4 E-cores | CPU vs CPU | after | 0.933 / 0.949 | 16.9 / 16.3 | 43.6 / 46.2 | 44.1 / 46.7 | 42 / 41 | 27.7 % / 21.9 % | 49.2 / 36.2 | 24.5 % / 17.0 % | 0.0 / 0.0 |
| 4 E-cores | human pitching | before | 0.860 / 0.840 | 19.1 / 19.6 | 35.0 / 31.8 | 35.2 / 31.9 | 48 / 50 | 48.6 % / 62.2 % | 52.4 / 52.6 | 51.7 % / 64.0 % | 0.0 / 0.0 |
| 4 E-cores | human pitching | after | 0.931 / 0.943 | 16.9 / 16.4 | 42.9 / 45.8 | 43.1 / 46.0 | 42 / 41 | 29.8 % / 22.9 % | 49.1 / 47.5 | 31.0 % / 23.8 % | 0.0 / 0.0 |

Reading it:

- **hostSlow 1.3 (the laptop): full speed now**, 1.000 in all four sessions (before
  0.93-0.98), 57-58 new frames per second (before 45-52), composited p95 21-22 ms (before
  34-50), composited frames over 25 ms 1.4-2.9 % (before 11-22 %), no underruns. The
  emulation takes 12 ms of the 16.7 ms field budget (with the simulated slowdown), against
  15-16 before. Presents over 25 ms are still 4.5-9.7 % there: stretches where a field's
  work runs past the budget (the windows' p90 is close to it).
- **This PC:** full speed before and after; emulation 9.2-10.3 ms per field instead of
  11.4-12.5; rendered fps 59.8-59.9, composited p95 20.9-22.3 ms (before 20.5-21.0) and
  composited frames over 25 ms 1.4-2.5 % (before 0.6-2.8 %): no regression beyond the
  run-to-run spread.
- **hostSlow 2: 0.78-0.86** (before 0.61-0.70), 32-36 new frames per second (before 24-28):
  better, not the 0.95 stretch goal.
- **4 E-cores: 0.93-0.95** (before 0.83-0.86), 43-46 new frames per second (before 32-35):
  not yet full speed.
- **hostSlow 4: 0.38-0.40** (before 0.31-0.33); the underruns in CPU vs CPU went from 10.8
  to 0.4 per minute.

**A whole game.** Native `mvp-play --headless` (this branch before the merge, which leaves
the guest unchanged: section 11) with `cpu125.txt` from power-on: CPU vs CPU from the first
pitch, played to **Game Over** (Cardinals 12, Red Sox 10 in 10 innings) by field 295,200,
no crash; the frames captured every 7,200 fields look as they should (skinned players
included).

## 11. Exactness (the merged engine, `3aa0d921`)

**Guest lines.** WEB.md's checkpoints in Chrome 155 on the merged engine, all equal to
WEB.md's CLK2 lines (unchanged, so not re-recorded):

| Run | Guest line | Where |
|---|---|---|
| 700 fields, sound | 4,547,010,125, 473,646,888, 360 polls, MEM1 `53221c4a...` | threaded, single-threaded |
| 2,400 fields, START x4 | 15,574,026,125, 1,622,294,388, 1,882 polls, MEM1 `4285f135...` | threaded, single-threaded |
| 3,600 fields, `menus` | 23,357,802,126, 2,433,104,388, 2,747 polls, MEM1 `40a7692d...` | threaded (unpaced and paced with sound), single-threaded, single-threaded without isolation |
| CPU vs CPU, 11,600 fields | 75,249,642,125, 7,838,504,388, 10,544 polls, MEM1 `d8c30e9a...` | every session below (threaded, paced), threaded and single-threaded unpaced, native `mvp-play --no-render` |
| human pitching, 9,000 fields | 58,384,794,125, 6,081,749,388, 8,054 polls, MEM1 `58631fe2...` | every session below, threaded and single-threaded unpaced, native `mvp-play --no-render` |

Node (`mvp-boot-wasm`) and native `mvp-boot` to the poll of frame 10,544: 75,251,612,406
instructions, MEM1 `5725e2e2...` before every lever and after each one.

**Renderer digests** (`--digest`, every VI field): the merged engine threaded, the
merged engine single-threaded and origin/main agree in all 11,600 fields of CPU vs CPU
(the threaded run stops two fields before its render thread reports the last two);
threaded and single-threaded agree in all 9,000 fields of human pitching.

**Netplay.** `netplay_check` (two Chrome pages through the server, 3,200 frames, delay
3, the E5c script): both pages equal native `mvp-netplay solo` (26,835,905,005
instructions, MEM1 `2a8de818...`), no desync, before and after the merge with Q5.

**Tests.** MSVC: 35 tests plus the local ones (disc): `local_hle_native` (new),
`local_lockstep`, `local_boot_twice`, `local_input_start`, `local_play_determinism`,
`local_audio_determinism`, `local_netplay_lockstep`, `local_netplay_lossy`,
`local_cfg`, `local_disc`, `local_boot_main` pass, `local_disasm` skips (no dtk
listing here). Emscripten: 32 plus 8 local pass (`local_disasm` skips). The web shell:
87 tests pass (63 before Q5's).

**A whole game.** Native `mvp-play --headless` with `cpu125.txt` (CPU vs CPU after the
first pitch) to field 330,000, frames captured every 2 minutes of game time: see the
results section for how it ended.

## 12. Commits, proposals, what is left

Commits on `engine/q4-speed` (not pushed):

| Commit | What |
|---|---|
| `037dddb1` | tools: `mvp-xlat emit-wasm --names --shared`, `mvp-boot --time-at` |
| `e85236d6` | lever 1: the GX FIFO's per-burst path (section 2) |
| `e0818884` | lever 3: write tracking by epoch (section 3) |
| `6868b7f1` | lever 4: `lfs`, `stfs`, `lfd`, `stfd`, float `psq` pairs through fuller helpers (section 4) |
| `12c136c5` | the runtime: cheaper safe points, GX parse buffers (section 5) |
| `360ad17a` | lever 2: FPR halves cached in f64 locals (section 6) |
| `8ed7f1fd` | lever 2: compare and branch fused when only the branch reads the CR field (section 6) |
| `d350f482` | merge origin/main (F1) |
| `1901beb1` | the fast floating-point model, F1 (section 7) |
| `5d7d2ec0` | tools: `mvp-boot --time-at` with the thread's CPU time |
| `29d3ee6a` | `fn_803EB000` natively, the `Native` HLE kind (section 8) |
| `3aa0d921` | merge origin/main (Q5) |

Translation cache keys change with every engine build (the build id), so browsers
retranslate once. The module's imports gained `rt.wgp_store` (lever 1).

Proposed DECISIONS entries:

- **Q4-G1** The write-gather pipe's per-burst path: translated code appends every store to
  the pipe's 4 KiB block itself and calls the runtime only for a store that completes a
  burst; the GX FIFO hands its observer each push's commands at once (one ring record per
  push). `Hardware::write` stays the reference (`test_wasm_lockstep`, `test_devices`).
- **Q4-W1** Write tracking by epoch: the render thread reports each vertex array range at
  most once per ring epoch and tags its marks with the epoch; a store waits only while its
  epoch is unread. Accepted: slightly more waits (about 0.9 -> 1.2 per field, 0.1 ms).
- **Q4-H1** In translated WebAssembly, fewer and fuller in-module helpers with the common
  case first, not inline expansion at the call sites (V8 runs bigger functions slower;
  Q2-S1 again).
- **Q4-F1** The fast floating-point model (section 7) is the engine's default; the exact
  Gekko model stays selectable for tests (`fp::g_model`, `WasmEmitOptions::fp_exact`).
  Native builds keep `/fp:precise` or `-ffp-contract=off -fno-fast-math` (needed on ARM).
- **Q4-N1** Native implementations of game functions (`HleKind::Native`) are allowed when
  equal to the original in all guest state (registers, memory, hardware accesses with
  their guest PC and ticks, the instruction count), with the original as the fallback
  outside the state they are written for, the interpreter always running the original, and
  a disc test against the interpreter for each (`local_hle_native`).
- **Q4-M1** On a shared PC, A/B the translated code with two Node runs at once pinned to
  separate E-core clusters (with the thread CPU time `mvp-boot --time-at` prints),
  swapping the clusters between pairs.

What is left (largest first, by the last profile: Node, CPU vs CPU play):

1. **The fast model's per-result work.** Every FP result pays a NaN check, the f32 round
   trip and the flush test (`fast_result`, the emitter's `select` chain). Canonicalizing
   NaNs only where FP bits leave the registers (stores, `stfiwx`, the state hash) and
   dropping the NI flush would make FP-heavy code (about a third of the thread) cheaper,
   but changes guest results in rare cases: a further F1 step with WEB.md's lines
   re-recorded, for the lead to decide.
2. **Paired singles as f64x2** (WebAssembly SIMD, which every current browser has) in the
   emitter and in native functions: about half the FP instructions. Makes SIMD a
   requirement of the page.
3. **The memory helpers** (`h.wr32`, `h.rd32`, `h.lfs`: about 18 % of the thread). A fixed
   placement of MEM1 in the module's memory would make most guest loads and stores a mask
   and a plain access, without the page-table load or the call.
4. **More native functions:** `fn_80369878` (7 % with its callees), `fn_803E3C08`,
   `fn_803BD358`, `PSMTXMultVec`; each with its own disc test.
5. **The GX parse on the emulation thread** (`gp_consume`, `command_length`,
   `GxFifo::execute`: about 7 %).
6. **Presents over 25 ms at hostSlow 1.3** (4.5-9.7 %) come from fields whose work runs
   past the budget; a field of run-ahead in the pacing would hide them at one field of
   latency (Q5's area).
