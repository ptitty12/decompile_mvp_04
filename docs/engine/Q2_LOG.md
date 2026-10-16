# Q2 log: sound without dropouts, and the game on weaker machines

Side session `claude-side-q2`, branch `engine/q2-perf` (from origin/main `1ab1dd27`, P2's
threaded engine; Q3's controllers `de8356c4` and Q1's visuals `f5837a4d` merged in). Chrome
155 headed on this PC (i7-14700K: 8 performance cores with two threads each and 12
efficiency cores; RTX 4070 SUPER; Windows 11), Playwright, the owner's CISO picked as a
file. Other sessions (Q1, Q3, with browser runs of their own) shared the machine; each run's
log has the CPU load at its start and end, and the comparisons that matter were rerun back
to back (section 6).

The owner, after the threaded engine's deploy: "it's still choppy when I am using it on
another computer"; "the audio is choppy on/off on/off"; "still not getting the best frame
rate".

## 1. Status

| # | Task | State |
|---|---|---|
| 1 | Audio dropouts: reproduce by scene, threaded and single-threaded, this PC and slower machines; find the cause; fix | **Done.** The cause: an emulation below real time emptied a 60 ms buffer the resampler could not stretch. Now a shared-memory ring, a time-stretch and an adaptive target: on the merged engine, in play: 0.7 underruns a minute on this PC threaded (was 7.2), none with a silence over 20 ms, and 1.3 single-threaded (was 30; 0.6 over 20 ms); 0.5 a minute at a simulated 2x slower machine (was 251; silent 0.0 % instead of 33 %), 0 on four efficiency cores (was 170) |
| 2 | Speed on weaker machines | **Partly.** The inline MEM1 path was built, exact, and measured slower (reverted, section 5); the GX FIFO parses bursts in place (small); write tracking and psq not changed (reasons in section 5). Degradation: even slow motion was built and measured; it shows 45 % more frames but slows the game 9 %, so it is opt-in (`slowMotion=1`); the default keeps the game's speed |
| 3 | Frame rate on this PC, P2's sessions | Done (section 7) |
| 4 | Exactness | Done (section 8) |

## 2. What the owner hears, and why

**How it was measured.** `browser_check.mjs --audio` with CLK2's CPU-vs-CPU script from
power-on to field 11,600, paced; scenes by the game's frame polls: intro (to the title at
frame 1,100), menus (to frame 5,200: title, dialogs, team select, the match load), in game
(after). The worklet reports, in every half-second window, its underruns and the silences
they made (from the underrun until the sound plays again), the time stretched, its buffer
target, and the transport. **Weaker machines, simulated:** Chrome's DevTools CPU throttling
slows only a page's main thread (checked: a Worker's loop ran at the same speed at rate 4,
and a Worker target answers "Operation is only supported for pages, not workers"), so the
engine simulates them itself: `hostSlow=N` makes the emulation spin N - 1 times the host
time each field worked (its waits for the render thread excluded), the inline present too,
and the render thread after each stretch of its work, while the check throttles the main
thread N times. Host timing only. Also: the browser on four efficiency cores
(`--affinity F000000`, a low-power quad core) and with 40 busy processes (`--load 40`).
Run names in the tables: `b_` origin/main, `m_` the merged engine, `e4_` four efficiency
cores; `mt` threaded, `st` single-threaded; `1x`, `2x`, `4x` the simulated slowdown. "New
frames/s" counts presents that showed a new picture; "Saturated" is the share of the time the
host needed a field or more per field (reported since Q2).

**Before** (origin/main `1ab1dd27`, the deployed engine, plus statistics only):

**This PC**

| Run | Scene | Speed | Host ms/field | Underruns/min | Silences > 20 ms /min (total) | Silent | New frames/s | New-frame interval p95 | Target at end | Saturated |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| b_mt_1x | intro | 1.000x | 5.0 | 0.0 | 0.0 (0.0 s) | 0.0% | 41.6 | 29 ms | 60 ms | - |
| b_mt_1x | menus | 1.000x | 6.6 | 0.0 | 0.0 (0.0 s) | 0.0% | 53.4 | 24 ms | 60 ms | - |
| b_mt_1x | in game | 0.995x | 11.4 | 7.2 | 7.2 (0.6 s) | 0.6% | 56.8 | 29 ms | 60 ms | - |
| b_st_1x | intro | 1.000x | 4.8 | 0.0 | 0.0 (0.0 s) | 0.0% | 41.8 | 33 ms | 60 ms | - |
| b_st_1x | menus | 0.988x | 7.8 | 16.5 | 16.5 (1.0 s) | 1.2% | 49.9 | 35 ms | 60 ms | - |
| b_st_1x | in game | 0.974x | 14.3 | 30.2 | 30.2 (2.7 s) | 2.8% | 52.1 | 36 ms | 60 ms | - |

**A machine 2x slower (simulated)**

| Run | Scene | Speed | Host ms/field | Underruns/min | Silences > 20 ms /min (total) | Silent | New frames/s | New-frame interval p95 | Target at end | Saturated |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| b_mt_2x | intro | 0.995x | 9.7 | 13.6 | 11.3 (0.3 s) | 1.3% | 37.4 | 38 ms | 60 ms | - |
| b_mt_2x | menus | 0.858x | 13.0 | 120.7 | 120.7 (12.5 s) | 14.3% | 39.1 | 53 ms | 60 ms | - |
| b_mt_2x | in game | 0.668x | 23.9 | 251.3 | 250.4 (45.5 s) | 33.3% | 25.8 | 65 ms | 60 ms | - |
| b_st_2x | intro | 0.995x | 9.5 | 13.6 | 13.6 (0.3 s) | 1.0% | 38.4 | 38 ms | 60 ms | - |
| b_st_2x | menus | 0.774x | 15.5 | 152.2 | 152.2 (22.2 s) | 22.7% | 36.7 | 68 ms | 60 ms | - |
| b_st_2x | in game | 0.557x | 28.8 | 285.4 | 285.0 (72.3 s) | 44.3% | 21.8 | 75 ms | 60 ms | - |

**4x slower (simulated), threaded**

| Run | Scene | Speed | Host ms/field | Underruns/min | Silences > 20 ms /min (total) | Silent | New frames/s | New-frame interval p95 | Target at end | Saturated |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| b_mt_4x | intro | 0.660x | 19.7 | 221.9 | 221.9 (13.5 s) | 33.9% | 21.6 | 80 ms | 60 ms | - |
| b_mt_4x | menus | 0.558x | 27.3 | 166.2 | 165.7 (60.1 s) | 44.3% | 23.1 | 107 ms | 60 ms | - |
| b_mt_4x | in game | 0.331x | 50.2 | 214.7 | 214.7 (183.9 s) | 67.0% | 13.2 | 130 ms | 60 ms | - |

**Four efficiency cores (the browser pinned to logical processors 24-27), threaded unless st, back to back**

| Run | Scene | Speed | Host ms/field | Underruns/min | Silences > 20 ms /min (total) | Silent | New frames/s | New-frame interval p95 | Target at end | Saturated |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| e4_before | intro | 1.001x | 8.4 | 0.0 | 0.0 (0.0 s) | 0.0% | 42.4 | 33 ms | 60 ms | - |
| e4_before | menus | 0.922x | 11.7 | 76.3 | 76.3 (6.4 s) | 7.8% | 41.8 | 45 ms | 60 ms | - |
| e4_before | in game | 0.831x | 19.0 | 170.2 | 170.2 (18.6 s) | 17.0% | 31.5 | 50 ms | 60 ms | - |

**The cause.** The worklet's drift resampler could absorb only +-0.5 % between the guest's
clock and the device's. Any emulation below full speed (a heavy scene on this PC, nearly
every scene on a slower machine) emptied its 60 ms buffer, went silent until 60 ms were
buffered again at the emulation's slower rate, played, and emptied again: on, off, on, off.
At 2x slower in play that was about 250 silences a minute, a third of the time silent, and
the 2x machine runs most menus below real time too. On this PC the threaded engine still
underran about 7 times a minute in play (single fields of 47-60 ms on the shared machine
emptied the buffer) and the single-threaded one 30 times (it runs at 0.97x in play). The
transport was not the cause (a batch's frames arrived within a field of being mixed).

## 3. The sound path now

- **Time-stretch when the emulation runs behind** (`src/resampler.ts`). Once the buffer
  falls under 60 % of its target, the input is played slower with its pitch kept: it plays
  contiguous stretches of the input, and where its position runs ahead of the speed's ideal
  track (by up to 4 ms, less on a low buffer) it jumps back to the point near the ideal
  position that best matches what would have played next (both channels compared; the
  nearest of equally good matches), cross-faded over 4 ms. A PI controller on the fill sets
  the speed (down to a quarter): it settles at the emulation's own speed with the buffer at
  the target, and stops stretching once the input keeps up and the buffer is back. At full
  speed the input plays as is (no splices).
- **Underruns** (a real stall): fade out, play again once half the base target (30 ms) is
  back instead of the whole target, and let the stretch rebuild the rest; each underrun
  raises the target by 20 ms (up to 200 ms; not when the stretch was already at its slowest),
  and every 30 s without one lowers it by 10 ms. The first start waits for the whole 60 ms.
- **A ring in shared memory** (`wasm/web_audio.h` `AudioRing`, `src/audio-worklet.ts`,
  `src/worker.ts`). On a cross-origin isolated page the threaded engine's mixer writes into a
  ring in the engine's own (shared) memory as it mixes, inside the run, and the worklet drains
  it at every render quantum; the single-threaded engine on an isolated page copies each batch
  into a SharedArrayBuffer ring of the Worker's own; without isolation (or `audioRing=0`) each
  batch is still a message (E2c's path). The worklet reports which (`transport`): `ring` in
  Chrome and Firefox threaded and Chrome single-threaded on the isolated page, `port` without
  isolation (section 8).
- Unit tests (`tests/resampler.test.mjs`, 11 cases): the steady state, drift, bursts, an
  underrun, skipping, a rate change, as before; stretched playback at 0.97x, 0.8x, 0.6x and
  0.35x without underruns after the onset, at the input's pitch and without clicks; a jittery
  producer (batches of 1-4 fields) at full speed without underruns or stretching; a 300 ms
  stall (one underrun, sound again 30 ms after the stall, the target up 20 ms and back
  down); the ring's offset pushes. A parameter sweep (`HOP`, `SEEK`, crossfade, restart) on
  producers at 1.0x-0.3x with fixed and jittery batches chose the constants.

## 4. A machine that cannot keep up

What "keep 60 Hz guest time and drop presented frames" can and cannot do here: at 2x slower
the emulation thread needs 23-24 ms per field in play (11.4 on this PC) and the render
thread about 11 (it never held the emulation back: no lag waits at 2x or 4x), so no
presented-frame dropping can bring the guest back to 60 Hz: the game runs at about 0.69x
there whatever is shown. Presenting is already at most once per display refresh, and when
behind the paced loop (P1's chase) runs two-field batches and shows every other frame,
evenly (present intervals median 42 ms, p95 55 ms at 2x). Holding 60 Hz on such a machine
needs a faster emulation (section 5).

**Even slow motion (opt-in, `slowMotion=1`).** Built and measured: while the host time per
field, smoothed over about a second, is a whole field or more, every batch is one field with
its present, back to back, and the clock runs at most two fields ahead, so the game runs
evenly in slow motion with every frame shown. Threaded engine only (the single-threaded one
presents inline: a present per field cost it about 10 % of its speed). At a simulated 2x
slower machine, in play, two interleaved rounds (fields 7,000-9,500; the paced window
measured by `measure.py`):

| Build | Speed | Emulation ms per field | New frames shown /s | Present interval p95 | Underruns /min | Silent |
|---|---:|---:|---:|---:|---:|---:|
| origin/main, round 1 / 2 | 0.689x / 0.689x | 23.37 / 23.39 | 25.9 / 25.8 | 55.3 / 55.8 ms | 233 / 238 | 27.0 / 27.2 % |
| Q2 default, round 1 / 2 | 0.693x / 0.692x | 23.30 / 23.28 | 25.9 / 26.1 | 55.1 / 56.5 ms | 0.0 / 0.0 | 0.0 / 0.0 % |
| Q2 with `slowMotion=1`, round 1 / 2 | 0.631x / 0.629x | 23.41 / 23.46 | 37.7 / 37.6 | 45.1 / 45.6 ms | 0.8 / 0.0 | 0.0 / 0.0 % |

The emulation costs the same per field in all three; the sound no longer breaks up in either
Q2 mode; slow motion shows 45 % more frames with steadier intervals, but its one-field
batches cost the Worker about 2.4 ms a field outside the run and the game runs 9 % slower.
The owner asked for the game not to slow down, so the default keeps the chase.

## 5. Speed

**Profile** (a profiling build, `--profiling-funcs` and guest names, threaded, 6 s of paced
CPU vs CPU play from field 9,000, before the Q1 merge): the emulation thread is idle 22.6 %;
translated game code 51 % (the hottest functions `fn_803EB000` 4.6 %, `fn_803BD358` 3.6 %,
`fn_80369878` 2.3 %; `h.psq_l` 2.5 %, `h.wr32` 2.0 % (the write-gather pipe's stores),
`h.psq_st` 1.0 %); the GX FIFO path about 14 % (`GxFifo::execute` 3.1, `Hardware::write`
3.1, `gp_consume` 2.3, `mvp_rt_write32` 2.0, `command_length` 0.7, the parse buffer's insert
0.7, `pi_cause` 0.6, `wgp_burst` 0.5, `gp_run` 0.4); `GpReads::command` 2.9 % and its marking
2.0 %; write waits 0.3 %. The render thread: `GxProcessor::command` 17 %, `Renderer::draw`
5.7 %, `writeBuffer` 4 %, and about a quarter of its time polling for records.

**The inline MEM1 path (P2's step 2): built, exact, slower; not kept.** The emitter read and
wrote MEM1 inline (`(ea - 0x80000000) < 24 MiB - 7` -> one load or store at MEM1's address
plus the byte swap, the env.gp_pages check inline for stores in the threaded module; any other
address took the helper as before). MEM1's address was made fixed per engine build (a static
array; the engine build keys the translation cache) and the boot checked the linear mapping.
Exact: the same guest lines (Node `mvp-boot-wasm`, 12,000 M instructions; Chrome threaded,
10,000 fields) and a lockstep test with it passed. But the module grew from 62 to 90 MB
(45 %) and the emulation got slower. Unpaced CPU vs CPU, fields 8,000-10,000, threaded, ms
per field in `mvp_run_fields`:

| Module | Runs |
|---|---|
| helpers (origin/main) | 11.63, 11.66, 11.75 |
| loads and stores inline | 12.51, 12.18 |
| loads only inline | 11.36, 11.71 |

V8 runs the small helpers about as fast as the inline code, and the bigger code costs more
than the calls save. Reverted; the patch is kept in the session's scratch, not in the tree.

**GX FIFO: commands parsed in place** (`runtime/gx_fifo.cpp`). With nothing pending (a burst
of whole commands, perhaps the start of one more) the commands are parsed where the burst
is and only an incomplete tail is kept, instead of every 32-byte burst going through the
pending buffer (an insert and an erase); the recent-command record copies its head bytes at
once. Same guest lines; 11.59 ms per field in the run above (the helpers' 11.63-11.75): small.

**Not changed, with reasons.**
- GpReads's marking per batch instead of per primitive: an entry would have to carry the
  end of its publish step and a per-array cache be invalidated by every write wait and field
  sweep (subtle to get right) for at most the 2 % it costs.
- Copying small rewritten vertex arrays into the ring: the GX processor would have to read a
  primitive's arrays from the copy (a change in the renderer, Q1's area). Q1 has since cut
  the write waits from 7.1 to 0.9 a field another way (`gfx/gp_memory.h`).
- psq helpers inline: what the inline MEM1 path met applies (larger code, no measured gain).
- The GX FIFO path's per-burst cost (14 %) is the largest engine-side lever, but deferring the
  GP's work to a safe point changes when the renderer reads guest memory: it needs its own
  exactness design.
- The render thread's polling (about a quarter of a core on this PC) and the emulation's
  300 us spins: not tuned. On four pinned efficiency cores the merged engine runs as fast as
  origin/main within noise (section 6), so the spins do not starve the emulation there.
  (Runs before the `--affinity` fix were not pinned; they are not used.)

## 6. Results

On the merged engine (Q1 + Q2 + Q3), the same runs as section 2:

**This PC**

| Run | Scene | Speed | Host ms/field | Underruns/min | Silences > 20 ms /min (total) | Silent | New frames/s | New-frame interval p95 | Target at end | Saturated |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| m_mt_1x | intro | 1.000x | 4.9 | 0.0 | 0.0 (0.0 s) | 0.0% | 41.7 | 28 ms | 60 ms | 0% |
| m_mt_1x | menus | 1.000x | 6.7 | 0.0 | 0.0 (0.0 s) | 0.0% | 53.7 | 23 ms | 60 ms | 0% |
| m_mt_1x | in game | 0.995x | 11.3 | 0.7 | 0.0 (0.0 s) | 0.0% | 56.6 | 30 ms | 80 ms | 2% |
| m_st_1x | intro | 1.000x | 4.9 | 0.0 | 0.0 (0.0 s) | 0.0% | 41.7 | 33 ms | 60 ms | 0% |
| m_st_1x | menus | 0.982x | 8.0 | 0.8 | 0.8 (0.0 s) | 0.1% | 49.7 | 36 ms | 70 ms | 15% |
| m_st_1x | in game | 0.965x | 14.9 | 1.3 | 0.6 (0.0 s) | 0.0% | 50.1 | 38 ms | 90 ms | 22% |

**A machine 2x slower (simulated)**

| Run | Scene | Speed | Host ms/field | Underruns/min | Silences > 20 ms /min (total) | Silent | New frames/s | New-frame interval p95 | Target at end | Saturated |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| m_mt_2x | intro | 0.989x | 9.8 | 0.0 | 0.0 (0.0 s) | 0.1% | 36.6 | 39 ms | 60 ms | 3% |
| m_mt_2x | menus | 0.853x | 13.3 | 0.7 | 0.7 (0.0 s) | 0.1% | 39.8 | 53 ms | 70 ms | 41% |
| m_mt_2x | in game | 0.695x | 22.9 | 0.5 | 0.5 (0.0 s) | 0.0% | 26.6 | 61 ms | 60 ms | 96% |
| m_st_2x | intro | 0.989x | 9.6 | 2.3 | 0.0 (0.0 s) | 0.0% | 37.7 | 42 ms | 80 ms | 4% |
| m_st_2x | menus | 0.760x | 16.0 | 1.8 | 1.2 (0.1 s) | 0.1% | 36.0 | 71 ms | 120 ms | 48% |
| m_st_2x | in game | 0.539x | 29.8 | 0.0 | 0.0 (0.0 s) | 0.0% | 21.4 | 77 ms | 60 ms | 98% |

**4x slower (simulated), threaded**

| Run | Scene | Speed | Host ms/field | Underruns/min | Silences > 20 ms /min (total) | Silent | New frames/s | New-frame interval p95 | Target at end | Saturated |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| m_mt_4x | intro | 0.664x | 19.2 | 3.0 | 3.0 (0.1 s) | 0.8% | 22.2 | 79 ms | 100 ms | 76% |
| m_mt_4x | menus | 0.560x | 27.4 | 0.4 | 0.4 (0.0 s) | 0.0% | 24.2 | 106 ms | 80 ms | 75% |
| m_mt_4x | in game | 0.353x | 47.1 | 6.5 | 6.5 (2.9 s) | 1.1% | 14.0 | 122 ms | 60 ms | 100% |

**Four efficiency cores (the browser pinned to logical processors 24-27), threaded unless st, back to back**

| Run | Scene | Speed | Host ms/field | Underruns/min | Silences > 20 ms /min (total) | Silent | New frames/s | New-frame interval p95 | Target at end | Saturated |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| e4_before | intro | 1.001x | 8.4 | 0.0 | 0.0 (0.0 s) | 0.0% | 42.4 | 33 ms | 60 ms | - |
| e4_before | menus | 0.922x | 11.7 | 76.3 | 76.3 (6.4 s) | 7.8% | 41.8 | 45 ms | 60 ms | - |
| e4_before | in game | 0.831x | 19.0 | 170.2 | 170.2 (18.6 s) | 17.0% | 31.5 | 50 ms | 60 ms | - |
| e4_merged | intro | 1.000x | 8.6 | 0.0 | 0.0 (0.0 s) | 0.0% | 41.6 | 33 ms | 60 ms | 0% |
| e4_merged | menus | 0.907x | 12.1 | 0.7 | 0.7 (0.0 s) | 0.0% | 40.7 | 47 ms | 70 ms | 36% |
| e4_merged | in game | 0.804x | 19.7 | 0.0 | 0.0 (0.0 s) | 0.0% | 30.1 | 52 ms | 60 ms | 91% |
| e4_merged_st | intro | 1.000x | 8.4 | 0.0 | 0.0 (0.0 s) | 0.0% | 42.6 | 36 ms | 60 ms | 0% |
| e4_merged_st | menus | 0.792x | 14.7 | 1.3 | 0.6 (0.0 s) | 0.0% | 37.3 | 65 ms | 90 ms | 46% |
| e4_merged_st | in game | 0.590x | 26.8 | 0.0 | 0.0 (0.0 s) | 0.0% | 23.0 | 70 ms | 60 ms | 97% |

Isolating Q2 (before the Q1 merge), single-threaded on this PC, back to back:

**`b2_` origin/main, then `e_` Q2**

| Run | Scene | Speed | Host ms/field | Underruns/min | Silences > 20 ms /min (total) | Silent | New frames/s | New-frame interval p95 | Target at end | Saturated |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| b2_st_1x | intro | 1.001x | 4.8 | 0.0 | 0.0 (0.0 s) | 0.0% | 41.8 | 33 ms | 60 ms | - |
| b2_st_1x | menus | 0.990x | 7.7 | 13.4 | 13.4 (0.8 s) | 1.0% | 50.0 | 34 ms | 60 ms | - |
| b2_st_1x | in game | 0.973x | 14.3 | 31.5 | 31.5 (2.7 s) | 2.9% | 52.3 | 36 ms | 60 ms | - |
| e_st_1x | intro | 1.000x | 4.8 | 0.0 | 0.0 (0.0 s) | 0.0% | 41.8 | 32 ms | 60 ms | 0% |
| e_st_1x | menus | 0.990x | 7.8 | 0.8 | 0.8 (0.0 s) | 0.0% | 49.8 | 34 ms | 70 ms | 14% |
| e_st_1x | in game | 0.972x | 14.3 | 0.6 | 0.0 (0.0 s) | 0.0% | 52.3 | 36 ms | 70 ms | 19% |

What the game is like:

- **This PC:** unchanged speed (1.00x threaded in every scene, 0.97x single-threaded in play,
  as before); the sound no longer drops out (one short underrun in 95 s of play threaded,
  none over 20 ms).
- **Four efficiency cores** (a low-power quad core, real): the game itself as before (about
  0.8x in play threaded, 0.9x in the menus; the emulation is the limit), about 30 new frames a
  second, and the sound continuous where it was silent 17 % of the time in play (170 breaks
  a minute) and 8 % in the menus.
- **2x slower (simulated):** in play 0.69x threaded with about 27 new frames a second, evenly
  (every other frame; new-frame p95 61 ms), menus 0.85x, the intro at full speed; the sound
  continuous (0.5 underruns a minute, 0.0 % silent instead of 33 %), slowed with the game
  (time-stretched to about 0.7x, pitch kept). Single-threaded: 0.54x in play, the sound
  continuous. With `slowMotion=1`: 0.63x and every frame shown (37.7 a second, p95 45 ms).
- **4x slower (simulated):** in play 0.35x with 14 new frames a second (p95 122 ms), menus
  0.56x, intro 0.66x: not playable, as before; the sound now mostly continuous (6.5 breaks a
  minute, 1.1 % silent instead of 67 %) but stretched to a third of its speed, which sounds
  slurred.
- **40 busy processes:** origin/main's run overlapped a build of this session and is not a
  fair comparison (0.30x in play, 70 % silent); the merged engine's ran at 0.73x in play with
  no underruns. Not used for conclusions.


## 7. This PC: P2's sessions

P2's sessions (CLK2's scripts; paced over fields 8,000-11,600 of CPU vs CPU and 6,600-9,000
of human pitching; Chrome's screencast for what was composited), the merged engine, and
origin/main the same evening (the machine more loaded during the latter: 9-63 % and 53-15 %):

| Session, build | Speed | Rendered fps | New frames shown /s | Presents p95 (> 25 ms) | Composited p95 (> 25 ms) | Emulation ms/field | Write waits /field | Underruns /min |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| CPU vs CPU, merged, threaded | 1.000x | 59.5 | 58.9 | 24.8 ms (4.8 %) | **20.8 ms (1.1 %)** | 11.39 | 0.88 (0.21 ms) | 0 |
| CPU vs CPU, origin/main, threaded | 1.000x | 59.6 | 56.2 | 28.1 ms (8.4 %) | 29.9 ms (5.5 %) | 12.63 | 7.02 (0.37 ms) | 3.1 |
| Human pitching, merged, threaded | 1.000x | 59.6 | 59.6 | 25.4 ms (6.6 %) | **20.5 ms (0.5 %)** | 11.03 | 1.71 (0.45 ms) | 0 |
| Human pitching, origin/main, threaded | 0.981x | 59.6 | 55.3 | 28.6 ms (7.1 %) | 31.3 ms (6.0 %) | 12.93 | 3.89 (0.70 ms) | 16.8 |
| CPU vs CPU, merged, single-threaded | 0.967x | 59.5 | 50.3 | 38.6 ms (20.4 %) | 48.6 ms (10.9 %) | 14.95 | - | 0 |

The threaded engine shows 59-60 new frames a second at 1.000x with a composited p95 of
20.5-20.8 ms (P2 measured 20.0-20.7 ms), and the sound has no dropouts. The game renders 59.5
frames per guest second (CLK2). The write waits are Q1's (0.9 and 1.7 a field instead of 7.1
and 3.9). The single-threaded fallback is still CPU-bound on this PC in play (0.97x).

## 8. Exactness

Guest lines on the merged engine (Chrome 155; WEB.md's checkpoints after CLK2):

| Run | Guest line | Where |
|---|---|---|
| 700 fields, no input, with sound | 4,547,010,125 instructions, time base 473,646,888, 360 polls, MEM1 `53221c4a...` | threaded (sound through the engine's ring), single-threaded (the Worker's ring) |
| 2,400 fields, START x4 | 15,574,026,125, 1,622,294,388, 1,882 polls, MEM1 `4285f135...` | threaded, single-threaded |
| 3,600 fields, `menus` | 23,357,802,126, 2,433,104,388, 2,747 polls, MEM1 `40a7692d...` | threaded, single-threaded (unpaced); threaded paced with sound; without isolation with sound (the MessagePort); Firefox 157 threaded, paced, with sound (the ring; 0 underruns) |
| CPU vs CPU, 11,600 fields | 75,249,642,125, 7,838,504,388, 10,544 polls, MEM1 `d8c30e9a...` | every paced run of sections 2 and 6, threaded and single-threaded, at every simulated speed and pinning |
| human pitching, 9,000 fields | 58,384,794,125, 6,081,749,388, 8,054 polls, MEM1 `58631fe2...` | the sessions of section 7 |

The time-stretch, the ring and the pacing are host-side (the worklet's timing never reaches
the Worker; wall time decides only how many fields run per batch); the GX FIFO change parses
the same commands with the same effects; the simulated slowdown only spins.

**Netplay** (`netplay_check`, two headed Chrome pages through `engine/server`, both threaded,
E5c's exhibition script, delay 3, 3,300 frames): lockstep, no desync, both pages
`27,484,589,886` instructions, MEM1 `58f2ab77...`, equal to native `mvp-netplay solo` built
from this branch.

**Tests:** `ctest --preset msvc` 47 tests, 46 passed and `local_disasm` skipped as always
(the local tests with the disc included); `ctest --preset emscripten` 40 tests, 39 passed and `local_disasm` skipped (the whole preset rebuilt after the Q1 merge, the C++-emitted dev path included); `test_web_shell` (node) 63 of 63 with the
11 resampler cases.

## 9. Tools

- `browser_check.mjs`: `--host-slow N[@F]`, `--affinity HEXMASK`, `--load N`; the windows
  carry the frame poll count, the time, and the worklet's gap, stretch, splice, target and
  transport statistics, and the paced loop's saturation.
- Page parameters: `hostSlow=N`, `hostSlowFrom=F` (development), `audioRing=0`,
  `slowMotion=1`.
- Engine exports: `mvp_host_slow` (development), `mvp_audio_ring`.
- Session scratch (not committed): `audio.py`/`table.py` (sound and speed by scene),
  `measure.py`, `chrome_measure.py` (P2's and CLK2's), the sweep of the resampler's constants.

## 10. Commits (branch `engine/q2-perf`, not pushed)

| Commit | What |
|---|---|
| `b3a53838` | engine(web): simulated slower machines, CPU affinity and background load in the browser check (Q2) |
| `98af0be7` | engine(audio): sound through a shared-memory ring, time-stretched when the emulation runs behind, a target that grows after underruns (Q2) |
| `2ab9f743` | engine(web): a machine that cannot keep up runs evenly in slow motion, every frame shown (Q2) |
| `899e54b4` | Merge origin/main (Q3 controllers) into engine/q2-perf |
| `5f63fb88` | engine(web): even slow motion only in the threaded engine (Q2) |
| `05d9188e` | engine(audio): the stretch goes down to a quarter speed; its comments match the constants (Q2) |
| `05815e2f` | engine(runtime): the GX FIFO parses a burst's commands in place (Q2) |
| `a8c0a461` | engine(web): slowMotion=0 turns the even slow motion off, for comparisons (Q2) |
| `790331a1` | engine(web): even slow motion is opt-in (slowMotion=1) (Q2) |
| `a1063fa9` | engine(docs): WEB.md: the sound's ring in shared memory, the time-stretch, the browser check's slower machines (Q2) |
| `bcc13f89` | Merge origin/main (Q1 visuals) into engine/q2-perf |
| `5863f076` | engine(web): --affinity finds the browser's processes under the check's own (Q2) |
| (this log) | engine(docs): Q2 log |

## 11. For the lead (decisions to record; docs outside docs/engine/)

- **Q2-A1 (audio transport; amends E2c-A1):** where the page is cross-origin isolated the
  sound goes to the AudioWorklet through a ring in shared memory (the threaded engine's mixer
  writes into it inside the run; the single-threaded engine's Worker copies each batch); a
  MessagePort elsewhere.
- **Q2-A2 (behind and stalled):** the worklet time-stretches with the pitch kept (down to a
  quarter speed) when the emulation runs below real time instead of going silent; after an
  underrun it plays again at half the base target and raises its target 20 ms (200 ms at
  most, 10 ms back per quiet 30 s).
- **Q2-P1 (pacing):** the default stays P1's chase (the game's speed first); even slow motion
  is an option (`slowMotion=1`), measured 45 % more frames shown and 9 % slower.
- **Q2-S1:** the inline MEM1 path is not used (measured slower in V8).

## 12. Next step

1. **Deploy** (the owner, through Dokploy as before; nothing to configure). Players translate
   once more (Q1 changed the translation's key). On the other computer the sound should no
   longer break up; if the game itself is still slow there (it runs below real time when its
   emulation thread needs more than a field per field, about a third slower than this PC's
   performance cores), `slowMotion=1` trades 9 % of the game's speed for every frame shown.
2. **The emulation thread is the limit on weaker machines.** On four efficiency cores it needs
   about 20 ms a field in play (11.3 here). The levers, by the profile: the GX FIFO's
   per-burst path (about 14 %; batching it to safe points needs an exactness design for when
   the renderer reads memory), the hottest translated functions (`fn_803EB000`, `fn_803BD358`,
   `fn_80369878`: what they do and whether the emitter can do better there), and GpReads with
   its marking (about 5 %). Inlining the memory helpers did not pay in V8 (section 5).
3. Measure on a real low-end machine (a laptop) and in Safari when one is available; the
   efficiency-core pinning is the closest stand-in here.
