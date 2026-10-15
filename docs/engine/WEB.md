# The browser build (E2)

How the engine runs in a browser: the player picks their own disc image, the
page translates the game to WebAssembly inside the browser, and the frames go
to a canvas through WebGPU. Nothing game-derived is fetched from a server or
sent to one. Working log and evidence: `docs/engine/E2_LOG.md` ("E2 browser
boot"). Toolchain versions: `docs/engine/TOOLCHAIN.md`.

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
   | `main.js`, `worker.js`, `input.js`, `protocol.js` | the shell, compiled from `engine/web/src/*.ts` by `tsc` |
   | `mvp-web.js`, `mvp-web.wasm` (0.6 MB) | the engine: translator, runtime, interpreter, renderer (`engine/web/wasm/mvp_web.cpp`) |
   | `symbols.txt` | `config/GV4E69/symbols.txt`: repository metadata (function boundaries and names), not game data (ARCHITECTURE.md §4) |
   | `licenses/` | notices for the third-party code compiled into the engine (Emscripten, emdawnwebgpu) |

4. **Serve:** `node engine/web/tools/serve.mjs` (`--port N`, default 8000;
   `--root DIR`). It serves that directory only, on 127.0.0.1, GET and HEAD
   only, no listings, `Cache-Control: no-store`. No COOP/COEP headers: the
   engine needs no SharedArrayBuffer.
5. **Check in real browsers** (local only: it needs the disc):
   `node engine/web/tools/browser_check.mjs --browser chrome|msedge|chromium|firefox|webkit`
   with `--disc PATH` (default `MVP_DISC`), `--script FILE` (an `mvp-input`
   script), `--fields N` / `--frames N` (stop there and print the guest line),
   `--fast` (unpaced), `--shots F1,F2` (canvas screenshots at those VI fields),
   `--keys F:KEY,...` (live key presses), `--headed`, `--js-flags`, `--tag`.
   It starts the server, opens the page with Playwright, sets the page's file
   input to the image, and writes `summary-BROWSER.json` and the screenshots to
   `--out` (default `build/engine/web-check`; screenshots are game-derived and
   stay under `build/`). It also lists every request the page made, to show that
   only the engine's own files were fetched.

## 2. Architecture

```
 page (main thread)                         engine Worker (module)
 ------------------                         ----------------------
 <input type=file>  -- File handle -------> Module.mvpDisc = file
 <canvas> -- transferControlToOffscreen --> specialHTMLTargets['#mvp-canvas']
 keyboard, Gamepad API -- pad state ------> mvp_set_pad (latched until the next frame poll)
 requestAnimationFrame -- tick (fallback) -> paced loop: mvp_run_fields(n), mvp_present()
 status, log, errors <-- messages --------- phases, stats, first frame, guest line
```

- **The page** (`src/main.ts`) holds no engine state. It hands the Worker the
  picked `File` (a handle; the browser reads the bytes locally), the canvas
  as an `OffscreenCanvas`, and the controller state. It shows the phases, the
  frame statistics and errors, and publishes them as `window.mvp` for the
  browser check. URL parameters for tests: `script`, `fields`, `frames`,
  `fast=1`, `render=0`.
- **The Worker** (`src/worker.ts`) loads `mvp-web.js` (an Emscripten ES module,
  `-sENVIRONMENT=worker -sMODULARIZE -sEXPORT_ES6`) and calls its exports in
  order:
  1. `mvp_gfx_init`: the WebGPU adapter and device are requested first
     (asynchronous, `Gpu::create_async`), so they arrive while the DOL is
     translated;
  2. `mvp_open_disc`: the image through a `vfs::Source` whose reads call
     `FileReaderSync.readAsArrayBuffer(file.slice(...))`, synchronous reads of
     only the bytes asked for (CISO or ISO; over the first 3,600 VI fields the
     game reads 27 MB of the 1.38 GB image in 1,150 reads). **Identity:**
     `vfs::open_disc(..., require_retail=true)`: game id GV4E69, revision 0, and
     the SHA-1 of `main.dol` (`da6becdb...`). Anything else stops here with "This
     image cannot be used. The engine runs MVP Baseball 2005 for GameCube, USA
     (GV4E69), revision 0 only." and the reason (for example `main.dol SHA-1
     056ef58c... is not GV4E69 rev 0`, or `GCM: bad disc magic at 0x1C`);
  3. `mvp_translate`: `symbols.txt` (fetched from the site) -> CFG -> one
     WebAssembly module (`translator/wasm_emit`, E2 groundwork) -> synchronous
     `new WebAssembly.Module` (allowed for any size in a Worker) -> instance in the
     runtime's own function table (`runtime/wasm_host`). The CFG and the 49.5 MB
     of module bytes are freed afterwards;
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
  more than 8 fields behind (the intro movie, a hidden tab) the debt is dropped
  instead of racing. Then `mvp_present()` draws the field's frame. `fast=1` runs
  fields back to back for 40 ms per task instead (measurements). **Wall time
  decides only how many fields run, never what happens inside one**: guest state
  depends on the disc and the per-frame pad inputs alone.
- **Input.** Keyboard (Enter = START, X = A, Z = B, C = X, V = Y, arrows = D-pad,
  I/J/K/L = stick, Q/E = L/R, Space = Z) and the first gamepad (standard mapping)
  merge into port 1 on the main thread (the Gamepad API is not available in
  Workers) and go to the Worker when they change. The engine applies them at the
  game's next frame poll (E0c's input queue); a button pressed since the previous
  poll counts as pressed at that poll even if already released, because the game
  polls once per frame of its own, which can be several fields apart (without
  the latch, quick taps during the intro movie were lost). Per-frame inputs are
  the only host input that reaches the guest.
- **Renderer.** The E1 renderer, unchanged, on emdawnwebgpu (Emscripten's
  `webgpu.h` from the same Dawn release as the native build). Only the edges
  differ: `Gpu::create_async` (no blocking `WaitAny` in the browser), `Window`
  on a canvas found by selector instead of an SDL window, no explicit `Present`
  (the browser shows the canvas when the task returns), and read-backs are
  native only. One renderer fix applied to both: the EFB pass's depth clear value
  is set (browsers reject webgpu.h's NaN default even when the load op is Load).
- **What the server sends:** `/`, `style.css`, `main.js`, `input.js`, `worker.js`,
  `mvp-web.js`, `mvp-web.wasm`, `symbols.txt`. The browser check records every
  request; no run made a request outside the local origin.

## 3. Measurements (2026-10-14)

Machine: Intel Core i7-14700K, 64 GB, NVIDIA GeForce RTX 4070 SUPER, Windows 11.
Other agents shared the machine. Disc: the owner's CISO (1.38 GB). Chrome and
Edge: the installed browsers, headless (Playwright `channel`). Firefox: Playwright's
build, **headed** (headless Firefox gets no WebGPU adapter). WebKit: Playwright's
Windows build, which has no `navigator.gpu` at all, so it ran without rendering.
Runs: the `menus` input script (START at frames 280, 430, 580, 730; DOWN at
1000; A at 1060: intro, licence screen, title, memory card dialog, main menu with
the profile dialog), 3,600 VI fields, paced (WebKit: unpaced).

**Startup** (ms; the page's clock):

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

The first frame is VI field 6 (the boot loading screen). The critical path is the
translation (about 0.5 s); the GPU requests finish while it runs, except on Edge
where the device came 89 ms after the boot.

**Frame time** (host milliseconds per VI field inside `rt::run` and the renderer,
averaged over half-second windows; achieved fields per second in brackets):

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

## 4. Determinism

The browser's guest line (`mvp_guest_line`: instructions, time base, frame
polls, SHA-1 of MEM1; the same line as `mvp-play`'s) after a fixed number of VI
fields equals the native one for the same input script:

| Run | Guest line | Matches |
|---|---|---|
| 700 fields, no input | 2,845,943,115 instructions, time base 474,323,852, 94 polls, MEM1 `eef70ba3...` | native `mvp-play` (with and without `--yield`), Chrome, Firefox, WebKit |
| 2,400 fields, START at 280/430/580/730 | 9,737,828,100, 1,622,971,350, 971 polls, MEM1 `4df06af1...` | native (with and without `--yield`), Chrome |
| 3,600 fields, the `menus` script | 14,602,688,100, 2,433,781,350, 2,122 polls, MEM1 `95f5c597...` | native, Chrome (paced, unpaced, Liftoff only, no rendering), Edge, Firefox, WebKit |

Three different WebAssembly engines (V8, SpiderMonkey, JavaScriptCore), paced
or not, with or without rendering, with yields at every field: the same guest
state as the native build that does not yield.

## 5. Limits and next steps

- **Safari is not measured.** Playwright's WebKit on Windows has no WebGPU; the
  engine itself runs there (same guest line). A Mac is needed for Safari with
  WebGPU.
- **Firefox headless** gets no WebGPU adapter; headed works.
- **Speed:** the intro movie runs at 20-30% of real time and the main menu uses
  half to three quarters of the frame budget. Inlining the FP and paired-single
  arithmetic (E2_SPIKE §6 item 3) is the lever; E3a owns runtime speed.
- **Not done (optional in E2):** caching the translated module and the picked
  image in OPFS. Re-translation costs 0.5 s, so it buys little on this machine.
- The gamepad path is written to the Gamepad API's standard mapping but was not
  tried with a real controller (Playwright cannot emulate one). Keyboard input
  was tested live (Enter skips the intro, passes PRESS START and opens the
  memory card dialog).
- **Audio** is not in the browser yet (E3b).
- Before hosting on the VPS: serve `licenses/` with the engine, and decide the
  production headers (a Content-Security-Policy, caching) and compression.
