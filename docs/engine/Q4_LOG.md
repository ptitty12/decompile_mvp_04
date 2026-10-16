# Q4 log: a faster emulation thread

Side session `Q4`, branch `engine/q4-speed` (from origin/main `20e772c1`: P2's threaded
engine, CLK2, Q1's GP view, Q2's sound and simulated slower machines). Chrome 155 headed
on this PC (i7-14700K, RTX 4070 SUPER, Windows 11), Playwright, the owner's CISO picked as a
file; Node 24 (V8, the engine Chrome uses) for the translated code alone. Work in progress:
this file grows as the session goes; the results are at the end.

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

Exactness evidence: guest lines and renderer digests in section 7; a unit test runs a
translated program that writes bytes, halfwords, words, `psq_st` pairs and singles, `stfs`
and `stfd` to the pipe (straddling bursts, `0xCC008004` included) and compares the FIFO in
memory, its write pointer, the bursts and the store counts with the same values written
through `Hardware::write`; another checks that an observer gets each push's commands at
once and in order, the same as one that takes them one by one.
