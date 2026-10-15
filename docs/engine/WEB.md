# The browser build (E2, E2c)

How the engine runs in a browser: the page gets the disc image (the player picks
their own, or, on the owner's private deployment, the server serves the owner's
image behind its login), translates the game to WebAssembly inside the browser
(or loads the translation it cached on an earlier visit), draws the frames on a
canvas through WebGPU, plays the sound through an AudioWorklet, and reads the
keyboard and a gamepad. Nothing game-derived is ever sent from the browser.
Working logs and evidence: `docs/engine/E2_LOG.md` (E2: browser boot) and
`docs/engine/E2C_LOG.md` (E2c: sound, gamepad, the disc from the server, caching,
polish). Toolchain versions: `docs/engine/TOOLCHAIN.md`.

## 1. Build and serve (agents)

Everything below is run by agents; the owner never runs commands.

1. **Tools once per checkout:** `npm ci` in `engine/web` (TypeScript and
   Playwright, pinned in `package.json` and `package-lock.json`; `node_modules/`
   is ignored by git), with the SDK's Node: `..\tools\emsdk.cmd npm ci` from
   `engine/web`. Browser builds for Firefox and WebKit:
   `node node_modules/playwright/cli.js install firefox webkit` with
   `PLAYWRIGHT_BROWSERS_PATH=%USERPROFILE%\tools-ext\playwright-browsers`.
   Chrome and Edge are the installed system browsers.
2. **Configure and build** (from `engine/`):
   `tools\emsdk.cmd cmake --preset emscripten`, then
   `tools\emsdk.cmd cmake --build --preset emscripten -j 8 --target mvp-web`
   (about 20 s; the whole preset builds the tests and, with `MVP_DISC`, the
   C++-emitted dev path too). The preset finds emdawnwebgpu under
   `%USERPROFILE%\tools-ext\emdawnwebgpu\<Dawn release>\emdawnwebgpu_pkg`
   (`MVP_EMDAWNWEBGPU_DIR` overrides it).
3. **The site** lands in `build/engine/emscripten/web/site/`:

   | File | What |
   |---|---|
   | `index.html`, `style.css` | the page (`engine/web/static/`) |
   | `main.js`, `worker.js`, `protocol.js`, `input.js`, `gamepad.js`, `gamepad-ui.js`, `audio.js`, `audio-worklet.js`, `resampler.js`, `disc.js`, `module-cache.js` | the shell, compiled from `engine/web/src/*.ts` by `tsc` |
   | `mvp-web.js`, `mvp-web.wasm` (0.6 MB) | the engine: translator, runtime, interpreter, renderer, mixer (`engine/web/wasm/`) |
   | `build-id.json` | the SHA-256 of `mvp-web.wasm` and of `symbols.txt` (the key of the browser's translation cache) |
   | `symbols.txt` | `config/GV4E69/symbols.txt`: repository metadata (function boundaries and names), not game data (ARCHITECTURE.md §4) |
   | `licenses/` | notices for the third-party code compiled into the engine (Emscripten, emdawnwebgpu) |

4. **Serve:** `node engine/web/tools/serve.mjs` (`--port N`, default 8000;
   `--root DIR`). It serves that directory only, on 127.0.0.1, GET and HEAD
   only, no listings, `Cache-Control: no-store`. No COOP/COEP headers: the
   engine needs no SharedArrayBuffer (§2, Sound). **`--disc PATH`** (local
   tests only) mocks the owner's deployment (E5 builds the real one in
   `engine/server/`): `GET /config.json` answers `{"disc": "/api/disc/image"}`,
   and `/api/disc/image` serves PATH to HEAD and to ranged GETs (206,
   `Cache-Control: private, no-store`); `--login` makes `/api/*` answer 401
   without the cookie `mvp_session=ok`; `--latency MS` and `--rate MB/S` slow it
   down.
5. **Check in real browsers** (local only: it needs the disc):
   `node engine/web/tools/browser_check.mjs --browser chrome|msedge|chromium|firefox|webkit`
   with `--disc PATH` (default `MVP_DISC`), `--script FILE` (an `mvp-input`
   script), `--fields N` / `--frames N` (stop there and print the guest line),
   `--fast` (unpaced), `--shots F1,F2` (canvas screenshots at those VI fields),
   `--keys F:KEY,...` (live key presses; `--hold MS`), `--headed`, `--js-flags`,
   `--tag`; and (E2c) `--server-disc` (the mock deployment instead of the file
   input; `--login`, `--latency`, `--rate`), `--audio` (click first, then sample
   the worklet's output through the page's analyser) or `--no-audio`,
   `--audio-latency MS`, `--pad F:button:I,F:axis:I:V` (a fake standard gamepad
   behind `navigator.getGamepads()`), `--runs N` with `--clear-cache` (cold and
   warm starts in one profile) or `--no-cache`, `--hide F:MS` (the tab hidden for
   MS ms), `--trace-disc` (the picked image's read offsets and sizes) and
   `--disc-cache PARAMS`. It starts the server, opens the page with Playwright,
   and writes `summary-BROWSER[-TAG].json` and the screenshots to `--out`
   (default `build/engine/web-check`; screenshots are game-derived and stay under
   `build/`). It lists every request the page made. Chrome and Edge run with
   `--mute-audio` and Firefox with its volume at 0 unless `--audible`.
6. **Unit tests** (data-free, in `ctest --preset emscripten`): `test_web_shell`
   runs `node --test` on `engine/web/tests/*.test.mjs` against the compiled
   shell (the gamepad mapping, the audio resampler, the disc's server
   contract); `test_web_cache` tests the server image's block cache and the
   translation cache's blob. `mvp-web-cache-sim TRACE` (development) replays a
   `--trace-disc` trace through the block cache over a modelled network.

## 2. Architecture

```
 page (main thread)                          engine Worker (module)
 ------------------                          ----------------------
 /config.json -> {"disc": url}, or a picked File -> Module.mvpDiscUrl (Range XHRs) / Module.mvpDisc (FileReaderSync)
 <canvas> -- transferControlToOffscreen ---> specialHTMLTargets['#mvp-canvas']
 keyboard, Gamepad API -- pad state -------> mvp_set_pad (latched until the next frame poll)
 requestAnimationFrame -- tick (fallback) --> paced loop: mvp_run_fields(n), mvp_present()
 status, progress, log, errors <-- messages - phases, stats, first frame, guest line
 AudioContext (after the first gesture)       OPFS: the translated module (DOL SHA-1 + build id)
   AudioWorkletNode <==== MessageChannel ==== each batch's mixed frames (Int16Array, transferred)
     drift resampler 32 -> 48 kHz
     -> gain -> speakers; -> AnalyserNode (level probe)
```

- **The page** (`src/main.ts`) holds no engine state. On load it asks for
  `/config.json` (`src/disc.ts`): with a `disc` URL it starts at once with the
  server's image; otherwise it shows the picker and hands the Worker the picked
  `File`. It also gives the Worker the canvas as an `OffscreenCanvas` and the
  controller state, shows the status line and a progress bar while loading
  (posted by the Worker, also from inside the translation), the phases, the
  frame statistics and errors, and publishes them as `window.mvp` for the
  browser check. URL parameters for tests: `script`, `fields`, `frames`,
  `fast=1`, `render=0`, `audio=0`, `cache=0`, `audioLatency=MS`, `traceDisc=1`,
  `discBlock`/`discBlocks`/`discRun`/`discAhead`.
- **The Worker** (`src/worker.ts`) loads `mvp-web.js` (an Emscripten ES module,
  `-sENVIRONMENT=worker -sMODULARIZE -sEXPORT_ES6`) and calls its exports in
  order:
  1. `mvp_gfx_init`: the WebGPU adapter and device are requested first
     (asynchronous, `Gpu::create_async`), so they arrive while the DOL is
     translated;
  2. the disc: `mvp_open_disc` for a picked file (a `vfs::Source` whose reads
     call `FileReaderSync.readAsArrayBuffer(file.slice(...))`), or
     `mvp_open_disc_url` for the server's image (below). Either way CISO or ISO,
     then the **identity check**: `vfs::open_disc(..., require_retail=true)`: game
     id GV4E69, revision 0, and the SHA-1 of `main.dol` (`da6becdb...`). Anything
     else stops here with "This image cannot be used. The engine runs MVP Baseball
     2005 for GameCube, USA (GV4E69), revision 0 only." and the reason (for
     example `main.dol SHA-1 056ef58c... is not GV4E69 rev 0`, or `GCM: bad disc
     magic at 0x1C`);
  3. the translation: from this browser's cache if it has one for this DOL and
     engine build (`mvp_translate_cached`, below), else `mvp_translate`:
     `symbols.txt` (fetched from the site) -> CFG -> one WebAssembly module
     (`translator/wasm_emit`) -> synchronous `new WebAssembly.Module` (allowed for
     any size in a Worker) -> instance in the runtime's own function table
     (`runtime/wasm_host`). The CFG is freed afterwards; the module is kept only
     until it is cached;
  4. `mvp_boot`: the machine, the IPL environment, the hardware model, the input
     queue (a script for tests, else live input), `YieldingHooks`;
  5. waits for the renderer (the GX processor must see the command stream from
     the first command), then runs.
- **The run loop.** `rt::run()` returns at every VI field (a *host yield*,
  `runtime/host_yield.h`): the VI field observer asks for a yield, the end of
  that safe point unwinds every native frame the way a thread switch does, and
  the next `run()` continues at the guest PC, re-entering functions at their
  resume labels. The safe point the yield interrupted is not repeated (the first
  safe point after a yield at the same PC and instruction count returns at once),
  so the guest executes exactly the same instructions with and without yields.
  `mvp-play --yield` checks this natively, `local_play_determinism` runs it, and
  the browser's guest lines below match native ones.
- **Pacing.** Each animation frame (the Worker's own `requestAnimationFrame` where
  it exists, else a tick message from the page's) runs as many whole VI fields as
  the wall clock asks for at 59.94 fields/s, at most 4 per frame; if the game falls
  more than 8 fields behind (the intro movie, a slow stretch) the debt is dropped
  instead of racing. Then `mvp_present()` draws the field's frame. `fast=1` runs
  fields back to back for 40 ms per task instead (measurements). **Wall time
  decides only how many fields run, never what happens inside one**: guest state
  depends on the disc and the per-frame pad inputs alone.
- **Pause.** A hidden tab, the Pause button or P stops the Worker's loop and
  suspends the AudioContext; on return the pacing clock restarts from the field
  it stopped at. Only the host loop stops: the guest sees no wall time, so a run
  with a pause gives the same guest line as one without.
- **Input.** Keyboard (Enter = START, X = A, Z = B, C = X, V = Y, arrows = D-pad,
  I/J/K/L = stick, Q/E = L/R, Space = Z) and the first connected gamepad merge
  into port 1 on the main thread (the Gamepad API is not available in Workers)
  and go to the Worker when they change. The engine applies them at the game's
  next frame poll (E0c's input queue); a button pressed since the previous poll
  counts as pressed at that poll even if already released, because the game
  polls once per frame of its own, which can be several fields apart. Per-frame
  inputs are the only host input that reaches the guest.
- **Gamepad** (`src/gamepad.ts`, `src/gamepad-ui.ts`). The default mapping is for
  the Gamepad API's standard layout: bottom face button = A, right = B, left = X,
  top = Y, right or left bumper = Z, triggers = L/R (analog 0-255, the digital
  L/R click at 90 % of the travel; a trigger's `value` counts, not the browser's
  early `pressed`), Start = START, D-pad, left stick = main stick, right stick =
  C-stick (radial dead zone 15 %, scaled to +-100, clamped to the circle, up
  positive). The Controls panel shows the pad found and rebinds any control by
  pressing the wanted button or moving the wanted axis (a pad with a
  non-standard layout is bound this way); the mapping is stored per browser in
  `localStorage["mvp.gamepad.mapping.v1"]`, checked field by field when read.
- **Sound** (`src/audio.ts`, `src/audio-worklet.ts`, `src/resampler.ts`, engine
  `wasm/web_audio.h`). The AX mixer of E3b observes the DSP's frames in the
  Worker exactly as natively (read-only: E3b-MIX1). Browsers start audio only
  after a user gesture, so the page creates the AudioContext on the first
  pointer press, key press or touch (a hint says so; gamepad buttons do not
  count as a gesture), adds the worklet and gives one end of a MessageChannel to
  the worklet and the other to the Worker; the Worker then attaches the mixer
  and, after each run batch, posts the batch's frames (16-bit stereo at the AI's
  rate, 32 kHz; the buffer transferred) straight to the worklet. The worklet's
  drift resampler is the native one's design (`audio/drift.h`): it reads at
  32000 / the context's rate (usually 48 kHz) times a ratio within +-0.5 %,
  steered by its smoothed fill toward a 60 ms target, with cubic (Catmull-Rom)
  interpolation; dry, it fades out and waits for the target again; more than 4 x
  the target, it skips down to it; full, it drops. An AnalyserNode taps its
  output (`window.mvp.audioProbe()`); M or the Sound button mutes. **Why a
  MessagePort and no SharedArrayBuffer:** a SAB ring needs cross-origin isolation
  (COOP/COEP headers) on every server that serves the page, and would not lower
  the latency, which the Worker's batches (one animation frame) and the device
  set. Nothing goes back from the worklet to the Worker.
- **The disc from the server** (`src/disc.ts`, engine `wasm/web_disc.*`,
  `wasm/block_cache.*`). The deployment's contract (E5): `GET /config.json`
  `{"disc": "<url>"}`; the URL is on the same origin (anything else is refused)
  and answers HEAD with the size and a ranged GET with 206, both with
  `Cache-Control: private, no-store`; API calls without a login answer 401 (the
  page then says to log in). The Worker checks the image with a HEAD and a
  one-byte ranged GET (a server ignoring Range would send 1.4 GB per read), then
  the engine reads it by synchronous Range XHRs (a guest DVD read completes
  inside the call; the browser sends the login cookie with them) through a block
  cache: 256 KiB blocks, 64 MiB, least recently used out; a miss fetches all the
  blocks its read needs (up to 32) or, on sequential misses, a run growing to 4;
  a sequential stream also asks for the next 8 blocks ahead, which the Worker
  fetches asynchronously between batches. Failed reads retry twice; a read that
  still fails stops the run with the reason. Nothing is kept after the page
  closes.
- **The translation cache** (`src/module-cache.ts`, engine `wasm/module_cache.*`).
  After the first frame the Worker serializes the translator's output (the wasm
  binary and the tables the runtime fills from it, about 52 MB) and writes it to
  the origin private file system (`mvp-translated/<key>.bin`, then a `.ok`
  marker), keyed by the DOL's SHA-1 and `build-id.json`, removing older entries.
  The next visit reads it straight into the engine's heap and loads it with
  `mvp_translate_cached` instead of fetching `symbols.txt` and translating; a
  missing, incomplete or unloadable entry means translating as before. The entry
  is derived from the disc and stays in the player's browser (ARCHITECTURE.md §3).
- **Renderer.** The E1 renderer, unchanged, on emdawnwebgpu (Emscripten's
  `webgpu.h` from the same Dawn release as the native build). Only the edges
  differ: `Gpu::create_async` (no blocking `WaitAny` in the browser), `Window`
  on a canvas found by selector instead of an SDL window, no explicit `Present`
  (the browser shows the canvas when the task returns), and read-backs are
  native only. One renderer fix applied to both: the EFB pass's depth clear value
  is set (browsers reject webgpu.h's NaN default even when the load op is Load).
  Fullscreen (the button, F, or a double click) shows the canvas at 4:3 on black.
- **Errors** say what to do: no WebGPU (which browsers have it), a GPU that
  cannot be used, the wrong disc (above), not logged in, a server that does not
  answer Range requests, a failed engine Worker.
- **What the server sends:** the files of §1 (the page, the shell, the engine,
  `build-id.json`, `symbols.txt`; `symbols.txt` not on a warm start), and on the
  owner's deployment `/config.json` and the image. The browser check records
  every request; no run made a request outside the local origin.

## 3. Measurements

Machine: Intel Core i7-14700K, 64 GB, NVIDIA GeForce RTX 4070 SUPER, Windows 11.
Other agents shared the machine. Disc: the owner's CISO (1.38 GB). Chrome and
Edge: the installed browsers, headless (Playwright `channel`). Firefox: Playwright's
build, **headed** (headless Firefox gets no WebGPU adapter). WebKit: Playwright's
Windows build, which has no `navigator.gpu` at all, so it ran without rendering.

**Startup, E2** (2026-10-14; ms, the page's clock; a picked file, no cache). Runs:
the `menus` input script (START at frames 280, 430, 580, 730; DOWN at 1000; A at
1060: intro, licence screen, title, memory card dialog, main menu with the
profile dialog), 3,600 VI fields, paced (WebKit: unpaced).

| Phase | Chrome 155 | Edge 155 | Firefox 157 | WebKit 27.2 |
|---|---:|---:|---:|---:|
| engine module (fetch, compile, instantiate 0.6 MB) | 6 | 8 | 8 | 10 |
| disc check (CISO index, FST, DOL + SHA-1) | 27-30 | 32 | 25 | 36 |
| `symbols.txt` fetch (3.9 MB, localhost) | 14-17 | 15 | 13 | 14 |
| parse symbols | 40-52 | 42 | 40 | 46 |
| CFG | 145-158 | 159 | 139 | 157 |
| emit (49.5 MB module) | 274-293 | 284 | 323 | 273 |
| compile (`new WebAssembly.Module`) | 16-21 | 17 | 149-157 | 42-45 |
| instantiate | 1 | 1 | 0-1 | 2 |
| boot | 4 | 4 | 4 | 5 |
| WebGPU adapter + device (overlaps translation) | 571-599 | 658 | 715 | none |
| **cold start: pick -> first frame on the canvas** | **668-792** | **1,085** | **823-860** | (game code runs 0.6 s after the pick) |

**Cold and warm start, E2c** (start -> first frame, ms; 4 runs in one profile, the
cache cleared before the first; "server": the mock deployment on localhost):

| | Chrome, picker | Chrome, server | Firefox, picker | Firefox, server |
|---|---:|---:|---:|---:|
| cold (translated) | 698 | 740 | 1,120 | 1,026 |
| warm (from the cache) | 280-330 | 344-363 | 399-439 | 380-418 |
| translation phase, cold / warm | 491 / 76-114 | 514 / 103-116 | 641 / 174-182 | 658 / 172-189 |

Warm, the translation phase is reading the 52 MB entry, unpacking it and compiling
(Firefox's compile alone is 122-133 ms); the first frame then waits for the WebGPU
device. Writing the entry after the first frame takes 110-410 ms. A warm start also
leaves the engine's memory at 146-155 MB instead of 213-220 MB (no translator peak).

**Frame time** (host milliseconds per VI field inside `rt::run` and the renderer,
averaged over half-second windows; achieved fields per second in brackets; E2):

| Scene (VI fields) | Chrome | Edge | Firefox | WebKit (no rendering, unpaced) |
|---|---:|---:|---:|---:|
| boot loading screen (0-580) | 5.8 (59.9/s) | 5.4 (58.1/s) | 3.4 (59.8/s) | 3.5 |
| intro movie (600-1270) | 79 (12/s) | 79 (12/s) | 54 (18/s) | 96 |
| licence screen (1300-1660) | 0.6 (60/s) | 0.4 (60/s) | 0.3 (60/s) | |
| title, "PRESS START" (1940-2150) | 1.4 (60/s) | 1.2 (60/s) | 1.2 (60/s) | |
| memory card dialog (2180-2500) | 3.9 (60/s) | 3.6 (60/s) | 2.8 (60/s) | 2.9 |
| main menu + profile dialog (2730-3600) | 12.9 (60/s) | 12.9 (60/s) | 8.1 (60/s) | 11.3 |

- Everything but the intro movie runs at full speed (59.94 fields/s) in every
  browser with WebGPU. The movie is decoded by game code on the CPU, mostly FP and
  paired-single work that still goes through the interpreter (`rt.exec`, E2_SPIKE
  §6 item 3); it runs at 20-30% of real time, as natively (`/Od`: 18%).
- The main menu costs 12.9 ms per field in Chrome, 11.6 ms of it in game code
  (the same run with `render=0`): the renderer adds about 1.3 ms there. Chrome
  with V8's tier-up off (`--js-flags --no-wasm-tier-up`, Liftoff only) gives the
  same numbers, so TurboFan is not the difference to Firefox, whose code is
  30-35% faster on the movie and the menu.
- Unpaced (Chrome): the loading screen runs at 3.4 ms per field, about 5x real time.
- The engine's WebAssembly memory is 213 MB once running (`heap_mb` in the
  status, Chrome). Memory never shrinks, so this is the translator's peak (the CFG
  and the 49.5 MB module, freed after instantiation and reused by the heap) plus
  the machine (24 MB MEM1, 16 MB ARAM). The compiled code lives outside it, in
  the browser's own memory.

**Sound** (E2c; details in E2C_LOG.md): sound trails the picture by about
80-115 ms (the worklet's 60 ms target, its fill averaging 60-74 ms at full speed;
the context's 10 ms base latency in Chrome and 32 ms output latency in Firefox;
up to one field of batching). Over the `menus` run: no underruns after the intro
movie in Chrome, one in Firefox; 112-114 during the movie, which decodes below
real time. A 45 or 30 ms target underruns in the menus (16 and 21 times). The
mixer costs about 2 % of `rt::run` time.

**The server image** (E2c): on localhost the first 800 fields fetch 35 MB for
16.7 MB of guest reads and wait 165 ms. Simulated links (the first minute's read
trace through the block cache): the guest waits 1.8 s in all at 15 ms / 300
Mbit/s, 3.5 s at 30 ms / 200 Mbit/s (the longest stall 124 ms), 8 s at 50 ms /
100 Mbit/s, almost all of it during the boot loading screen and the load before
the licence screen.

## 4. Determinism

The browser's guest line (`mvp_guest_line`: instructions, time base, frame
polls, SHA-1 of MEM1; the same line as `mvp-play`'s) after a fixed number of VI
fields equals the native one for the same input script:

| Run | Guest line | Matches |
|---|---|---|
| 700 fields, no input | 2,845,943,115 instructions, time base 474,323,852, 94 polls, MEM1 `eef70ba3...` | native `mvp-play` (with and without `--yield`), Chrome, Firefox, WebKit; Chrome from the server image with sound and a 3 s hidden-tab pause at field 304 (E2c) |
| 2,400 fields, START at 280/430/580/730 | 9,737,828,100, 1,622,971,350, 971 polls, MEM1 `4df06af1...` | native (with and without `--yield`), Chrome |
| 3,600 fields, the `menus` script | 14,602,688,100, 2,433,781,350, 2,122 polls, MEM1 `95f5c597...` | native, Chrome (paced, unpaced, Liftoff only, no rendering), Edge, Firefox, WebKit; **with sound playing** (the mixer attached at field 0, the worklet consuming), Chrome and Firefox from the server image, Chrome with 30 and 45 ms audio buffers and unpaced; Chrome without the mixer (E2c) |

Three different WebAssembly engines (V8, SpiderMonkey, JavaScriptCore), paced
or not, with or without rendering, with or without sound, read from a file or a
server, paused or not, with yields at every field: the same guest state as the
native build that does not yield.

## 5. Limits and next steps

- **Safari is not measured.** Playwright's WebKit on Windows has no WebGPU; the
  engine itself runs there (same guest line), and the page now says the browser
  has no WebGPU. A Mac is needed for Safari with WebGPU.
- **Firefox headless** gets no WebGPU adapter; headed works.
- **Speed:** the intro movie runs at 20-30% of real time (its sound plays in
  pieces) and the main menu uses half to three quarters of the frame budget.
  Inlining the FP and paired-single arithmetic (E2_SPIKE §6 item 3) is the lever;
  E3a owns runtime speed.
- **Remote play:** each missed block of the server image costs a round trip; the
  boot waits about 2 s at 30 ms. Next: keep the boot's read plan (offsets only)
  in the browser after the first visit and prefetch it in parallel during the
  translation. Keeping the image's bytes in the browser would remove the wait on
  later visits, but the server says `no-store`: an owner decision (E2C_LOG.md).
- **Gamepads** were tested with unit tests and a fake `getGamepads()`, not yet
  with a real controller.
- **The real server** (E5, `engine/server/`) is not tested yet; the page follows
  the contract in §2 and was tested against the mock.
- Before hosting on the VPS: serve `licenses/` with the engine, and decide the
  production headers (a Content-Security-Policy, caching) and compression.
