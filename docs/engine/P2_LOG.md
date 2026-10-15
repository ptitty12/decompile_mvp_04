# P2 log: smooth 60 fps in the browser

Side session `claude-side-p2`, branch `engine/p2-thread` (from origin/main `05be18d1`,
CLK2 merged in at `6ed1c7a9`). Chrome 155 headed on this PC (i7-14700K, RTX 4070
SUPER, 3440x1440 at 59 Hz), Playwright, the owner's CISO picked as a file. Other
sessions shared the machine throughout; the CPU load at the start and the end of
each run is noted.

## 1. Status

| Step | What | State |
|---|---|---|
| 1 | Render thread: the GX processor and the WebGPU renderer on their own thread (wasm threads, shared memory, a command ring; the render thread owns the device and the canvas); COOP/COEP; single-thread fallback | **Done** (`mvp-web-mt`, the default where the page is cross-origin isolated) |
| 1b | Exactness of a renderer behind the emulation: guest writes wait for what the render thread still has to read (write tracking) | **Done**: renderer digests equal the inline renderer's in every field |
| 2 | Faster memory helpers (`h.rd32`, psq) | Not done: profiled and evaluated (section 6); the write-gather pipe's stores moved into the module instead |
| 3 | Vertex path: per-format loaders, SIMD | Not done: measured with `mvp-gx-bench` (section 6); with the render thread it no longer costs the emulation |
| 4 | Half-scale EFB copy at `0x01797180` (256 x 224) sampled as 256 x 256 | **Fixed** with a test (`e7fe6a11`) |

**Result** (section 4; Chrome 155, after CLK2, other sessions sharing the PC):

| | origin/main | this branch, threaded (default where isolated) |
|---|---:|---:|
| CPU vs CPU: speed | 0.971-0.974x | **1.000x** |
| CPU vs CPU: Worker / emulation thread ms per field | 14.70-14.79 | **11.41** |
| CPU vs CPU: composited p95 (> 25 ms) | 38.5-38.8 ms (8.9-11.0%) | **20.6 ms (0.5%)** |
| CPU vs CPU: new frames shown per s | 50.8-51.6 | **58.2-59.5** |
| Human pitching: speed | 0.982-0.984x | **1.000x** |
| Human pitching: ms per field | 13.65-13.70 | **10.93** |
| Human pitching: composited p95 (> 25 ms) | 43.3-49.6 ms (13.2-13.4%) | **20.2 ms (0.8%)** |
| Human pitching: new frames shown per s | 53.3-54.8 | **57.1-59.3** |

## 2. The threaded engine (step 1)

**Two builds, one page.** `mvp-web-mt.js/.wasm` is the same engine compiled for
wasm threads (`MVP_WEB_THREADS`: `-pthread`, a shared `WebAssembly.Memory`,
`PTHREAD_POOL_SIZE=1`), built by the main Emscripten tree as part of `mvp-web`
(an ExternalProject in `build/engine/emscripten/mt`, at most 8 jobs) and copied
into the site next to `mvp-web.js/.wasm`; `build-id.json` carries its hash as
`engine_mt` (the translation cache's key in that mode: the module then imports a
shared memory). The Worker (`src/worker.ts`) loads `mvp-web-mt.js` when the page
is `crossOriginIsolated` and `threads=0` is not set, else `mvp-web.js`, which
renders inline exactly as before (**the fallback**: no isolation, an old browser,
`?threads=0`, or the threaded module failing to load).

**The render thread** (`engine/web/wasm/render_thread.h/.cpp`, `render_side.h/.cpp`).
A pthread (its own Worker) owns the WebGPU device and the canvas and runs the GX
processor and the renderer. The emulation (the engine Worker) appends to a 16 MiB
single-producer, single-consumer ring in shared memory (`engine/gfx/render_ring.h`):
every GX command (copied), VI fields, presents, resizes, trace and digest
switches; records become visible in 4 KiB steps and at the end of each run batch.
The render thread waits for records in place (`Atomics.wait` through Emscripten's
futexes, after a 1 ms poll) while a batch runs and in its event loop between
batches (the emulation wakes it with a proxied call); a primitive too large for
the ring (over 8 MiB) is read where it is, behind a fence.

**What the emulation waits for: write tracking.** The renderer only reads guest
memory, but it reads it later than the inline renderer did. The renderer digest
(below) showed that this mattered: in about a third of the fields of both match
sessions the game rewrites a vertex array right after a draw that used it (before
its next draw-done), and a render thread behind by part of a field drew the new
contents. Fences at the guest's GPU sync points (draw done, PE tokens, CP status
reads, a breakpoint: `GfxObserver::gp_sync`, the first design) do not cover that,
and cost ~13 fences and up to 2 ms per field. The design kept:

- As each GX command is appended, `gfx::GpReads` (`engine/gfx/gp_reads.h`) works
  out, from the command bytes and the CP/BP registers it tracks, the guest memory
  the GX processor and the renderer will read for it: the elements each indexed
  attribute's indices select (NBT with three indices too), indexed XF loads, TLUT
  loads, TMEM preloads, what an EFB copy's texture covers (the renderer hashes
  it), and each texture the first time a draw samples it after an invalidation or
  a TLUT load (when the renderer's cache reads memory). It marks those bytes in
  `ppc::g_gp_pages` (one entry per 64 bytes of the 32 MiB physical space: the
  ring position after the command, plus one).
- Every guest write path checks the table before storing: the translated
  module's store helpers (`env.gp_pages`; stmw's and psq_st's direct paths too),
  the semantics library (`ppc/mem_access.h`: the interpreter, dcbz, HLE), the
  write-gather pipe's bursts, DI and ARAM DMA. A marked entry whose command the
  render thread has not finished makes the write wait for it
  (`RenderRing::wait_read`, 300 us of polling, then a futex wait). Entries are
  dropped as the render thread passes them (checked at each VI field).
- Natively, and in `mvp-web.wasm`, nothing is ever marked; natively `gp_check`
  compiles to nothing.
- The GPU sync-point fences remain as an option (`?rtTune=0,0,0,1`), off.

Granularity: 4 KiB entries gave 65.7 waits per field in the human session
(1.75 ms per field), 256 B 3.6 (1.09 ms), 64 B 2.4 (0.61 ms): **64 B** kept
(a 2 MiB table).

**Presentation.** The render thread shows at most one frame per display refresh.
A Worker started by a Worker has no `requestAnimationFrame`, so the page bumps a
counter in a SharedArrayBuffer at each of its animation frames and the render
thread reads it (presents at most once per increment; after 50 ms without one it
presents anyway). Drawing into the page's transferred OffscreenCanvas from the
render thread reached the screen irregularly (an OffscreenCanvas's frame is
committed between tasks, and the render thread works inside long tasks):
composited p95 45 ms. So where the page is isolated it keeps its canvas as a
`bitmaprenderer`, hands the engine a MessagePort, and the render thread draws into
an OffscreenCanvas of its own, takes `transferToImageBitmap()` after each present
and posts it; the page's idle main thread shows it. Firefox unconfigures a WebGPU
canvas when its bitmap is taken: the render thread reconfigures it then
(`Window::reconfigure`). `?bitmaps=0` keeps the transferred-canvas path.

**Other parts.** The translated module is compiled from a copy of its bytes (no
`WebAssembly.Module` from a shared view); the Worker re-reads heap views after
another thread grew the memory; the audio batch and the cache's reads are copied
out of shared memory where the browser needs plain buffers. Stores to the
write-gather pipe (the GX FIFO, ~1.3 MB per heavy field) that do not complete a
32-byte burst are appended by the translated module itself into the runtime's
pipe state (`WgpState`, `env.wgp`) once the hardware's access log is full,
instead of a call into the runtime per store.

**Headers.** `engine/server` (the deployment) and `engine/web/tools/serve.mjs`
send `Cross-Origin-Opener-Policy: same-origin`, `Cross-Origin-Embedder-Policy:
require-corp` and `Cross-Origin-Resource-Policy: same-origin` on every response.
The site loads only its own resources (every browser check lists the requests;
none left the origin), so `require-corp` blocks nothing. `serve.mjs --no-isolation`
serves without them (the fallback).

## 3. Exactness

The render thread only reads guest memory; guest state cannot depend on it
except through what the emulation waits for, and those waits change only host
timing. Checked on the merged engine (CLK2):

**Guest lines** (`mvp_guest_line`) equal native's at WEB.md's checkpoints:

| Run | Guest line | Where |
|---|---|---|
| 700 fields, no input | 4,547,010,125 instructions, time base 473,646,888, 360 polls, MEM1 `53221c4a...` | Chrome threaded with sound; Firefox 157 threaded |
| 2,400 fields, START x4 | 15,574,026,125, 1,622,294,388, 1,882 polls, MEM1 `4285f135...` | Chrome threaded and single-threaded |
| 3,600 fields, `menus` | 23,357,802,126, 2,433,104,388, 2,747 polls, MEM1 `40a7692d...` | Chrome threaded (unpaced and paced), single-threaded on an isolated page, without isolation (the fallback); Firefox threaded |
| CPU vs CPU, 11,600 fields | 75,249,642,125, 7,838,504,388, 10,544 polls, MEM1 `d8c30e9a...` | main, st and mt in every paced run of section 4, and the digest runs |
| human pitching, 9,000 fields | 58,384,794,125, 6,081,749,388, 8,054 polls, MEM1 `58631fe2...` | main, st and mt in every paced run, and the digest runs |

**Renderer digests** (`gfx/digest_tap.h`: per VI field, five digests of what the
renderer is given: pipeline state, transformed vertices, textures, texture
memory, EFB copies), single-threaded against threaded, unpaced, every field:
CPU vs CPU 0 of 11,600 fields differ, human pitching 0 of 9,000 (also after the
last changes: 8be881bc, c21e910c); before CLK2, 0 of 18,400 and 0 of 14,600 in
P1-gfx's sessions. Before write tracking, with fences at the GPU sync points
only, a third of the fields differed (vertices): the reason for P2-T2.

**Netplay** (`netplay_check`, two headed Chrome pages through `engine/server`,
both threaded, E5c's exhibition script, delay 3, 3,300 frames): lockstep, no
desync, both pages `27,484,589,886` instructions, MEM1 `58f2ab77...`, equal to
native `mvp-netplay solo` with the same script (and before CLK2: `fb7aa479...`,
equal to that build's solo run). One console line on player 1's page, a 404
for some resource: origin/main's site shows the same line on player 1's page
(checked), so it predates P2.

**Tests:** `ctest --preset msvc` 46 of 46 (with the new `test_render_ring` and
`test_gp_reads`; `local_disasm` skipped as always without its local inputs),
`ctest --preset emscripten` 39 of 39 (`test_gp_reads` added; `local_disasm`
skipped), `engine/server` `npm test` 65 of 65 (the isolation headers' test
added); `mvp-gx-bench` now prints a hash of its output (section 6).

The renderer still writes no guest state (the deterministic model of GX1); the
tall-copy fix (section 5) changes what is drawn, not guest state.

## 4. Measurements

**Sessions** (after CLK2; its re-timed input scripts, `game_125` and `human_125`
from CLK2's session): **CPU vs CPU**, unpaced to field 8,000 and measured paced
over fields 8,000-11,600 (60 s of play, as CLK2_LOG section 7); **human
pitching**, unpaced to 6,600 and measured over 6,600-9,000 (40 s; the A button
pitches every 100 frames). `browser_check --fast-until --trace-present
--screencast F:2400 --cast-size 320x240`, Chrome 155 headed. Host ms per field is
the Worker's time inside `mvp_run_fields` (for the threaded engine: the
emulation thread's, including its write waits); presents are the engine's (the
render thread's clock when threaded); composited frames are Chrome's screencast
of the page, i.e. what reaches the screen. Builds: **main** = origin/main
`6ed1c7a9` (CLK2), built from a clean worktree; **st** = this branch with
`--threads 0` (the fallback engine, isolated page); **mt** = this branch threaded.
Two rounds each, in opposite orders; CPU load of the whole machine (other
sessions) at the start and end of each run in brackets.

**CPU vs CPU** (fields 8,000-11,600):

| Build (load) | speed | host ms/field (window median; p90) | new frames shown /s | presents p95 (> 25 ms) | composited p95 (> 25 ms) | render thread busy | write waits /field (ms) |
|---|---:|---:|---:|---:|---:|---:|---:|
| main r1 (16-17%) | 0.971x | 14.79 (14.60; 19.21) | 50.8 | 38.2 ms (20.0%) | 38.8 ms (11.0%) | - | - |
| main r2 (7-10%) | 0.974x | 14.70 (14.62; 19.20) | 51.6 | 37.9 ms (18.8%) | 38.5 ms (8.9%) | - | - |
| st r1 (13-8%) | 0.977x | 14.53 (14.39; 18.88) | 51.4 | 37.4 ms (18.7%) | 32.6 ms (9.1%) | - | - |
| st r2 (10-12%) | 0.981x | 14.39 (14.29; 18.56) | 51.6 | 36.6 ms (19.1%) | 30.1 ms (11.1%) | - | - |
| mt r1 (14-6%) | **1.000x** | **11.75** (11.78; 15.62) | **59.4** | 24.5 ms (4.1%) | **20.5 ms (0.2%)** | 6.01 ms | 7.07 (0.85 ms) |
| mt r2 (10-12%) | **1.000x** | **11.56** (11.36; 15.50) | **59.5** | 24.3 ms (4.1%) | **20.7 ms (0.4%)** | 5.87 ms | 7.08 (0.71 ms) |
| mt final, 8be881bc + c21e910c (4-6%) | **1.000x** | **11.41** (11.14; 14.52) | 58.2 | 23.3 ms (3.0%) | **20.6 ms (0.5%)** | 5.29 ms | 7.07 (0.32 ms) |
| st final (19-19%) | 0.986x | 14.09 (14.03; 17.99) | 53.2 | 35.6 ms (17.2%) | 27.3 ms (7.8%) | - | - |

**Human pitching** (fields 6,600-9,000):

| Build (load) | speed | host ms/field (window median; p90) | new frames shown /s | presents p95 (> 25 ms) | composited p95 (> 25 ms) | render thread busy | write waits /field (ms) |
|---|---:|---:|---:|---:|---:|---:|---:|
| main r1 (7-14%) | 0.984x | 13.65 (13.46; 18.78) | 54.8 | 33.6 ms (21.7%) | 43.3 ms (13.2%) | - | - |
| main r2 (23-20%) | 0.982x | 13.70 (13.58; 18.82) | 53.3 | 35.3 ms (16.9%) | 49.6 ms (13.4%) | - | - |
| st r1 (18-16%) | 0.988x | 13.37 (13.21; 18.25) | 55.9 | 32.6 ms (7.4%) | 34.2 ms (9.1%) | - | - |
| st r2 (0-14%) | 0.991x | 13.35 (13.29; 17.74) | 55.6 | 32.5 ms (7.6%) | 41.3 ms (7.3%) | - | - |
| mt r1 (22-22%) | **1.000x** | **11.50** (11.24; 16.56) | **59.3** | 23.4 ms (3.8%) | **20.3 ms (0.4%)** | 5.51 ms | 3.86 (1.13 ms) |
| mt r2 (20-10%) | **1.000x** | **11.47** (11.74; 14.74) | 57.1 | 24.8 ms (4.0%) | **20.0 ms (0.3%)** | 5.38 ms | 3.88 (1.12 ms) |
| mt final, 8be881bc + c21e910c (2-8%) | **1.000x** | **10.93** (10.67; 13.91) | 58.7 | 25.0 ms (4.9%) | **20.2 ms (0.8%)** | 4.68 ms | 3.88 (0.43 ms) |
| st final (9-29%) | 0.990x | 13.18 (12.96; 18.24) | 55.6 | 33.0 ms (21.9%) | 32.2 ms (10.6%) | - | - |

- **The threaded engine holds full speed with a steady picture**: 1.000x in both
  sessions, 57-59.5 new frames a second, and what Chrome composites has a p95
  interval of 20-21 ms with 0.2-0.5% of intervals over 25 ms, against 30-50 ms
  and 7-13% for main and the fallback, which run at 0.97-0.99x (the Worker is
  saturated: 14.4-14.8 ms per field in CPU vs CPU, with p90 windows over 18 ms).
- The emulation thread's time per field drops by 3.3-3.4 ms (CPU vs CPU: 14.7-14.8
  to 11.4) and 2.7 ms (human: 13.7 to 10.9) against main: the GX processor and the
  renderer (4.7-6.0 ms per field on the render thread) leave it, minus what the
  threading adds (the command copy, GpReads and its marking ~1 ms, the write
  checks, the write waits 0.3-0.4 ms per field: 7.1 and 3.9 a field, 95% of them
  for vertex arrays the game rewrites right after drawing them, the rest palettes).
  8be881bc and c21e910c took 0.15-0.55 ms off the threaded engine's field and
  0.3 ms off the fallback's.
- The engine's presents p95 (24-27 ms) is the render thread's own clock and
  includes its present-at-the-next-refresh rule; the composited intervals are the
  ones a player sees.
- The fallback (st) is cheaper than main by 0.3-0.6 ms per field at the end:
  the write-gather pipe's stores in the module, and no write checks in its
  module (c21e910c).
- CLK2's target for the Worker in heavy play was about 11 ms per field or
  less: the emulation thread is at 11.4 (CPU vs CPU) and 10.9 (human) on
  average, with half-second windows at 14-15 ms at p90, on this machine with
  other sessions running (load 2-22%).

**Before CLK2** (the first half of the session, P1-gfx's scripts and windows:
CPU vs CPU fields 16,000-18,400, human 12,900-14,600; skewed by the game's
freezes, which CLK2 removed, so not comparable with the tables above):

| Build | session | host ms/field | presents p95 (> 25 ms) | composited p95 (> 25 ms) | notes |
|---|---|---:|---:|---:|---|
| origin/main `05be18d1` | CPU | 9.62 | 30.8 ms (9.1%) | 32.5 ms (13.2%) | PNG screencast |
| st | CPU / human | 9.56 / 9.20 | - / 32.9 ms (11.1%) | 26.2 ms (9.2%) / 34.2 ms (14.4%) | |
| mt, the page's canvas drawn from the render thread | CPU | 8.40 | 23.9 ms | 45 ms | frames reached the screen irregularly |
| mt, ImageBitmaps to the page, GPU sync-point fences | CPU / human | 8.80 / 8.48 | - / 19.1 ms (1.5%) | 20.3 ms (0.7%) / 20.1 ms (0.6%) | ~13.5 fences a field, up to 2 ms a field waiting; digests differed in ~1/3 of the fields |
| mt, write tracking per 4 KiB | human | 0.967x | | | 65.7 waits a field, 1.75 ms |
| mt, write tracking per 256 B | human | 8.12 | | 19.8 ms (0.6%) | 3.6 waits, 1.09 ms |
| mt, write tracking per 64 B | CPU / human | 7.85 / 7.71 | 19.0 ms (1.4%) / 25.7 ms (5.9%) | 20.1 ms (0.5%) / 21.0 ms (1.5%) | 3.0 / 2.4 waits, 0.48 / 0.61 ms |


## 5. Step 4: the half-scale EFB copy

The game copies 512 x 448 of the EFB at half scale to `0x01797180` (256 x 224) and
samples that address as a 256 x 256 texture once per field in play. The renderer
used a copy only for a texture of exactly its size, so it decoded stale memory
there (`copy_size_misses`). The hardware reads the rows the copy wrote and, below
them, whatever memory holds: `Renderer::tall_copy` builds that texture from the
copy's rows (a GPU copy) and the memory after the copy's bytes (decoded), and
rebuilds it when the copy is redone or that memory changes (hashed once per
texture-cache epoch). Same width only; other size mismatches still count as
misses. `test_gfx_render`: a half-scale RGBA8 copy of 64 x 48 sampled as 64 x 64
shows the copy in rows 0-47 and memory below (`copy_tall` 1, no misses). In play
the status shows `copy_tall` instead of a size miss each field.

## 6. Steps 2 and 3: evaluated, not done

**Where the emulation thread's time goes** (a profiling build of the threaded
engine, `--profiling-funcs`, Chrome's sampling profiler over 6 s of paced CPU vs CPU
play from field 9,000, after CLK2, with 8be881bc's ring and GpReads changes
except the index scan): idle 23.6% (the pacing's headroom); translated game code
49.2%, of which the store helper `h.wr32` 6.5% (it holds the write checks and the
pipe appends), the load helper `h.rd32` 5.4%, `h.psq_l` 2.8%; the engine 25.0%:
GpReads 3.9% plus its marking 1.9%, the GX FIFO path (`Hardware::write` 3.6%,
`mvp_rt_write32` 2.2%, `GxFifo::execute` 2.6%, `gp_consume` 1.8%,
`command_length` 0.8%, `wgp_burst` 0.6%), write waits 1.0%. The render thread:
`GxProcessor::command` 18.1%, `Renderer::draw` 5.8%, `writeBuffer` 4.1%, waiting
for records 38.9%. (The first profile, before CLK2 and with the sync-point fences:
fence waits 12.7%, `h.rd32` 9.2%, `h.wr32` 4.4%, `Hardware::write` 4.0%,
`mvp_rt_write32` 2.7%; the render thread's `GxProcessor::command` 27.8% inclusive.)

- **Write-gather pipe (done instead):** the pipe's stores were a call from the
  module into the runtime each (`mvp_rt_write32` -> `Hardware::write`). The
  module now appends a store that does not complete a 32-byte burst straight
  into the runtime's pipe state (`env.wgp`, `xlat::WasmWgpLayout`, checked by a
  `static_assert`), counting it as `Hardware::write` would; a store that
  completes a burst, and every store while the hardware's access log is still
  being kept (its first 100,000 entries), takes the runtime's path as before.
  `mvp-boot-wasm` keeps its boot and movie lines (`5d329cb4`, `11f597ad`). Its
  gain is inside the single-threaded rows of section 4 (this branch's
  single-threaded engine against origin/main).
- **`h.rd32` / psq (step 2, not done).** The helper is already a fast path (the
  64 KiB page table, a page-crossing check, a load and a byte swap); what is left
  is the call itself and the page-table load. Inlining a MEM1 special case at
  each load site (`(ea - 0x80000000) < 24 MiB` -> one load from a MEM1 base)
  is exact only while the runtime maps those pages linearly, which nothing
  enforces today, and grows the module (a longer first translation). Not
  attempted: the render thread took the larger share first; it is the next lever
  on the emulation thread (section 11).
- **Vertex path (step 3, not done).** `mvp-gx-bench` (8,000 primitives of the
  game's formats, 3.83 ms; output hashes `34cc0ea9fe288a0f` default,
  `43b07a43647c4c7c` `--alpha-lit`, `9fdf6d06781f9f48` `--no-skin`,
  `d33a1eed9cd0e077` `--no-light`, so a faster loader can be checked bit for bit):
  of ~68 ns per vertex, lighting is ~22 ns and texture coordinates ~7 ns; the
  loading itself is the smaller part. With the render thread, the whole GX path
  runs off the emulation thread (4.7-6.0 ms per field on the render thread in heavy
  play, inside a 16.7 ms field), so per-format loaders or SIMD would no longer
  shorten the emulation's field; they matter only for the fallback engine.

## 7. Deployment

- **Headers:** `engine/server` now sends COEP `require-corp` and CORP
  `same-origin` (COOP `same-origin` it already sent) on every response; Traefik
  in Dokploy passes them through, nothing to set in the Dokploy UI. The pages
  load only same-origin resources, the CSP is unchanged (`worker-src 'self'`
  covers the render thread's Worker), and `netplay_check` against the built
  server ran both pages threaded (section 3).
- **Build:** the Docker build's `cmake --build --preset emscripten --target
  mvp-web` now also builds the threaded engine (a second tree, after the first
  tree's libraries, with the same job count), so the first deploy takes roughly
  twice as long (DEPLOY_DOKPLOY.md now says 20 to 40 minutes on a small VPS; no
  other change for the owner). The image's site gains `mvp-web-mt.js/.wasm`
  (allowed types). The Linux Docker build itself was not run here (Docker's
  daemon is not running on this PC); the same CMake path builds on Windows.
- **Players:** the translation cache key changes (`engine_mt`), so every player
  translates once more on the first visit after the deploy (as after any engine
  change). A browser without cross-origin isolation support, or a page served
  without the headers, runs the single-threaded engine as before.
- **Netplay:** the protocol is unchanged. Both pages ran threaded in
  `netplay_check` (section 3). A threaded and a single-threaded page compute the
  same guest state and send the same build id (the handshake hashes
  `mvp-web.wasm`, `mvp-web.js` and `symbols.txt`), so they can play each other;
  that mixed pairing was not run as a game.

## 8. Tools

All in `engine/web/tools/` unless noted (scratch scripts stay out of the repo):

- `browser_check.mjs`: `--threads 0`, `--no-isolation`, `--digest` (per-field
  renderer digest to `digest-BROWSER-rN.txt`), `--cast-size WxH` (JPEG screencast
  frames acknowledged at once: the PNG capture dropped frames at 60 fps), the
  render thread's busy time, fence and write-wait counters per stats window,
  `crossOriginIsolated` and `threaded` in the summary.
- `serve.mjs`: the isolation headers; `--no-isolation`.
- `netplay_check.mjs`: `pages[].threaded`.
- `trace_summary.mjs`: `mvp-web-mt.wasm` as its own bucket.
- `engine/gfx/digest_tap.h`: five digests per field (pipeline state, vertices,
  textures, texture memory, EFB copies) and per-draw lines for chosen fields;
  the page exports it (`digest=1`, `digestDetail=F1-F2`).
- `engine/gfx/tools/gx_bench.cpp`: an output hash, to keep a faster vertex path
  bit-exact.
- Tests: `test_render_ring` (native: order, wrap-around, a producer and a
  consumer thread with 200,000 records and fences), `test_gp_reads` (indexed
  attributes incl. NBT3, XF indexed loads, TLUT loads, preloads, EFB copies,
  textures per epoch), `test_gfx_render`'s tall-copy case, a server test of the
  isolation headers.

## 9. Commits (branch `engine/p2-thread`, not pushed)

| Commit | What |
|---|---|
| `ef710e9f` | engine(gfx): the render thread's command ring (RenderRing), the renderer digest (DigestTap) |
| `71c0e574` | engine(runtime): GPU sync points (GfxObserver::gp_sync); the module compiled from a copy with a shared memory |
| `104c039f` | engine(translator): the wasm emitter can import a shared memory |
| `93eb7189` | engine(server): COEP/CORP (cross-origin isolation) on every response, with a test |
| `da1d32f8` | engine(web): the threaded engine `mvp-web-mt` (render thread, ring, ImageBitmap presentation, vsync count), single-threaded fallback, serve.mjs headers, browser_check/netplay_check/trace_summary options |
| `e7fe6a11` | engine(gfx): step 4, the tall EFB copy (`0x01797180`), with a test |
| `8adb9674` | engine(runtime): the write-gather pipe's stores in the module; the write checks on every guest write path |
| `21395f6d` | engine(gfx): GpReads with test_gp_reads; digests by part and field; gx-bench output hash |
| `71e8ae89` | engine(web): write tracking on, sync fences off; status counters |
| `324bbd5a` | engine(runtime): write tracking per 64 bytes |
| `59a17f04` | merge of origin/main (CLK2, `6ed1c7a9`) |
| `7fbaada1` | engine(web): `bitmaps=0`; render_thread.h describes write tracking |
| `8be881bc` | engine(gfx,web): fewer render-thread wakeups and clock reads; GpReads cheaper; write waits by kind |
| `c21e910c` | engine(translator): write checks only in the threaded engine's module |
| (this log) | docs: P2_LOG.md; WEB.md, NETPLAY.md, DEPLOY_DOKPLOY.md |

## 10. For the lead (decisions to record; docs outside docs/engine/)

- **P2-T1 (the threaded browser engine):** where the page is cross-origin
  isolated the Worker runs `mvp-web-mt` (the GX processor and the WebGPU renderer
  on a pthread, a command ring in shared memory); elsewhere `mvp-web` renders
  inline as before. Both builds ship; the translation cache is keyed per build.
- **P2-T2 (exactness of a renderer behind the emulation):** the renderer reads
  guest memory later than the emulation writes it, so every guest write first
  checks a table of the bytes issued GX commands still have to read (per 64
  bytes) and waits for the render thread there. Fences at GPU sync points alone
  were not enough (the game rewrites vertex arrays between a draw and its draw
  done). The renderer never writes guest state; the per-field renderer digests
  of the threaded engine equal the inline engine's.
- **P2-T3 (presentation):** the render thread shows at most one frame per display
  refresh, counted by the page in shared memory, and sends it to the page as an
  ImageBitmap (the page's canvas is a `bitmaprenderer`).
- **P2-H1 (headers):** the server and `serve.mjs` send COOP `same-origin`, COEP
  `require-corp` and CORP `same-origin`. Anything the page loads from another
  origin later would need CORP/CORS (none does today).

## 11. Next step

1. **Deploy** (owner, through Dokploy as before: a rebuild; nothing to configure).
   Then check once on the VPS that the page is cross-origin isolated (the
   status shows `threaded`) and that a remote two-player game runs threaded.
2. **The emulation thread** is now the whole Worker budget: translated code
   ~49% of it, the GX FIFO path ~12%, GpReads ~6%. The next levers, in order:
   step 2 (an inline MEM1 path for loads/stores where the runtime can promise a
   linear MEM1 mapping; `h.rd32` + `h.wr32` ~12%), GpReads's marking (mark a
   range once per publish batch instead of once per primitive), and the write
   waits for vertex arrays (copying small, freshly written arrays into the ring
   instead of waiting; 0.3-0.4 ms per field).
3. **Firefox and Safari:** Firefox 157 runs the threaded engine with equal
   guest lines (section 3) but was not measured for smoothness here; Safari
   is still unmeasured (WEB.md section 5).
4. Step 3 (vertex loaders, SIMD) only for the fallback engine, if it matters.
