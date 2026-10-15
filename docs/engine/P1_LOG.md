# P1 log: playable on the owner's deployment

The owner played solo in Chrome on this PC against the deployed site
(https://mvp.ptaylor.dev, Dokploy on his VPS) and found the game "so slow that it's
entirely unplayable ... and will hang for entire seconds at a time". Two side
sessions work on it; each keeps its own section here:

- **P1-disc** (`claude-side-p1disc`, branch `engine/p1-disc`): the disc image read
  over the network, and keeping the uploaded disc on the server. `engine/web`,
  `engine/server`, `deploy/`.
- **P1-gfx** (branch `engine/p1-gfx`): rendering speed and flashing (`engine/gfx`,
  `runtime`).

## P1-disc: the disc downloaded once into the browser

### Status (2026-10-15)

| # | Task | State |
|---|---|---|
| 1 | Measure: the real server, Chrome with network conditions, into a match, every guest DVD read timed | Done: remote reads cause the hangs (below) |
| 2 | Fix: download the server's image once into OPFS, verified, resumable; every read local | Done |
| 3 | UI: no picker or upload in the main flow; the Server disc page only as a small operator link; a note when the server has no disc | Done |
| 4 | The uploaded disc survives redeploys | Checked: it does; documented (DEPLOY_DOKPLOY.md); the volume is deliberately not pinned |
| 5 | Check: the same session after the fix; download time; determinism | Done: no read over 16.7 ms; guest lines equal native |

### The cause, measured

**Setup.** The real server (`engine/server`, built) with the Docker deployment's
disc directory (`MVP_DISC_DIR` holding the owner's CISO as `GV4E69.img`, as the
upload leaves it), Chrome 155 headless through Playwright, Chrome's own network
conditions set through CDP on the page (checked first: they also slow the page's
dedicated Workers' synchronous XHRs, which is how the engine reads the server's
image). The session is E3a's path into an exhibition game as an input script
(E3A_LOG.md §2, "Menu path": START x4,
the memory-card and profile dialogs, Play Now, Cardinals at Red Sox, the uniforms,
the difficulty, the match loading, the pre-game, the first pitch), paced at
59.94 fields/s with sound on, stopped at the poll of frame 5,200 (13,071 VI
fields, about 3.6 minutes of game). The engine now times every read the drive
model makes (`TimedSource`, `wasm/mvp_web.cpp`) and logs field, time, offset,
size and wait (`browser_check.mjs --io-log`).

The game made 2,094 DVD reads, 31.2 MB, in that session; every one of them waited
on the network:

| Link | read wait in all | reads > 50 ms | > 100 ms | longest read | longest field | audio underruns |
|---|---:|---:|---:|---:|---:|---:|
| 60 ms / 100 Mbit/s | 18.6 s | 169 | 126 | 209 ms | 517 ms | 222 |
| 80 ms / 50 Mbit/s | 27.3 s | 173 | 173 | 352 ms | 704 ms | 219 |
| 60 ms / 100 Mbit/s, machine loaded (below) | 20.4 s | 170 | 127 | **1,416 ms** | 1,425 ms | 445 |

By stretch of the session (60 ms / 100 Mbit/s, unloaded; fields):

| Stretch | reads | wait | > 50 ms | longest |
|---|---:|---:|---:|---:|
| boot loading (0-600) | 547 | 4.1 s | 37 | 208 ms |
| intro movie (600-1300) | 30 | 0.5 s | 4 | 125 ms |
| title, menus (1300-3000) | 540 | 3.2 s | 27 | 209 ms |
| menus (3000-6500) | 63 | 0.1 s | 1 | 96 ms |
| match loading (6500-10500) | 725 | 7.8 s | 71 | 200 ms |
| pre-game and play (10500-13071) | 189 | 2.9 s | 29 | 110 ms |

- **The hangs are the reads.** The reads come in bursts: sequential 512 KiB reads
  of the game's archives, each a cache miss of the in-memory block cache, each
  waiting one round trip plus the transfer. In the worst seconds the game spent
  the whole second inside reads (1,047 ms of read wait inside one second of wall
  time at fields 18-31, 1,040 ms at 8,778-8,790 in the match loading, 967 ms at
  1,712-1,726), and the frame rate fell to 7-10 fields/s. During play (the
  pre-game and the first at-bat) a 16-32 KB read stalled the game for 50-110 ms
  29 times in 2,570 fields (43 s of game time), and 717 ms of reads fell into one
  second at field 11,045.
- **Under load it gets worse in exactly the owner's way.** With 20 busy CPU threads
  and a disk writer running (as other agents' builds and tests on this PC), one
  59 KB read at field 546 took 1,416 ms: a hang of a second and a half. The read
  waits themselves are network-bound (20.4 s against 18.6 s); the host's own work
  slowed too (`rt::run` 143 s against 81 s), which is P1-gfx's side.
- The disc check before the boot (the CISO index, the FST, the DOL and its SHA-1)
  took 1,240 ms over the link instead of 24 ms.
- The owner's real link to the VPS adds TLS, HTTP/2 through Traefik and real
  jitter on top of these simulated conditions.

### The fix

The DECISIONS entry of 2026-10-14 allows keeping the server's disc in the player's
own browser storage. So the page now downloads the whole image once and the engine
reads it locally:

- **Server** (`engine/server/src/disc_hash.ts`, `server.ts`): the image's
  manifest, the SHA-256 of each 8 MiB piece and the image hash (SHA-256 over the
  piece digests, in order). `/config.json` adds `discHash`, `discSize` and
  `discManifest` (`/api/disc/manifest?v=<version>`, behind the login, `private,
  no-store`), or `discPreparing` while the server hashes. The server hashes the
  image in the background at start and after an upload, and keeps the result next
  to the image (`GV4E69.manifest.json`, keyed by size and modification time), so
  a restart or a redeploy does not hash it again.
- **Page** (`src/disc-store.ts`, `src/disc-download.ts`, `src/main.ts`): with an
  offer in `/config.json` the page looks for a complete copy in the origin private
  file system (`mvp-disc/<hash>.ok` and `.img`); if there is none, a dedicated
  Worker downloads it: the manifest checked against the advertised hash; a Web
  Lock (a second tab waits); `navigator.storage.estimate()` and the file sized to
  the whole image before any fetch (quota problems show at once); 4 pieces in
  flight by Range GETs; each piece's SHA-256 checked before it is written in place
  through a synchronous OPFS handle; the written pieces flushed and recorded in
  `<hash>.part.json` about once a second (a reload resumes there); `<hash>.ok`
  last. The status line shows "Downloading the game data from the server, once:
  34% (470 of 1,316 MB, 11.8 MB/s, about 72 s left). Later visits start at once."
  with the progress bar.
- **Engine**: the stored image is handed to the engine Worker as a `File` and read
  exactly as a picked file (FileReaderSync), so every guest DVD read is local and
  synchronous; nothing in the engine changed for it. The identity check (GV4E69 rev
  0 by the DOL's SHA-1) runs on every start, as before.
- **Later visits** find `<hash>.ok` and start at once with no disc traffic at all
  (the requests: the site's files and `/config.json`). A new image hash (the
  operator uploaded another image) removes the old copy and downloads the new one;
  re-uploading the same file gives the same hash, so nothing is downloaded again
  (by construction; not run).
- **Errors** say what to do: the quota ("This browser cannot keep the game data
  (1,316 MB): the browser lets this site store N MB more ... Free some disk space,
  and use a normal window (not a private or incognito one), then reload the
  page."), a lost connection (retries each piece 6 times with backoff, then
  "Reload the page: the download continues where it stopped"), the login, a piece
  that does not match, an image replaced during the download. Except for the login
  and a replaced image, the page then offers **Play without keeping the game data**
  (the old network reads).
- **Not done: starting while the download runs.** The game reads across the whole
  disc within minutes (offsets from 7 MB to 1.28 GB by the first pitch), and a
  read of a piece not yet stored would wait behind the bulk download on the same
  link: worse stalls than before. The page shows the download's progress instead;
  the lobby opens only when the copy is complete (a player who joined a game while
  downloading would leave the other player's engine waiting past the session's
  10 s timeout).
- **Instrumentation kept**: `io` in `mvp_status` (reads, host ms, the longest, how
  many over a field, 50 ms and 100 ms), shown on the page's stats line;
  `ioLog=1` for the per-read log; `browser_check.mjs` `--throttle`, `--io-log`,
  `--disc-dir`, `--clear-disc`, `--store-off`, `--interrupt-download`,
  `--fallback`, `--params`, `--profile`, `--site`.

### After the fix

The same session, the same link, the image downloaded first:

| Link | read wait in all | reads > 16.7 ms | > 50 ms | longest read | longest field | audio underruns |
|---|---:|---:|---:|---:|---:|---:|
| 60 ms / 100 Mbit/s | 0.86 s | 0 | 0 | 1.7 ms | 73 ms | 130 |
| 60 ms / 100 Mbit/s, machine loaded | 1.90 s | 0 | 0 | 5.0 ms | 122 ms | 378 |
| 80 ms / 50 Mbit/s, to field 2,000 only (1,086 reads) | 0.44 s | 0 | 0 | 2.0 ms | 63 ms | 1 |

- **Zero reads over 50 ms** (none even over a field) after the download, loaded
  or not. The disc check before the boot took 24 ms.
- What remains slow is host work, not the disc: in the pre-game the page still
  ran 31-40 fields/s in some half-seconds (20-30 ms per field in `rt::run` and
  the renderer; 20 fields/s with the machine loaded, whose longest field, 122 ms,
  had no read in it over 5 ms), and the remaining audio underruns come from those
  fields; that is P1-gfx's side.
- **Background load** (as other agents' builds and tests on this PC: 20 threads of
  busy CPU work and a disk writing 64 MB files, through the whole run, before and
  after): before, one read took 1.4 s; after, the longest read was 5 ms.

**The download** (1,379,959,360 bytes, 165 pieces):

| Link | time | rate |
|---|---:|---:|
| localhost (in-memory profile) | 4.8 s | 285 MB/s |
| localhost (a profile on disk) | 20-22 s | 63-67 MB/s |
| 60 ms / 100 Mbit/s | 112 s | 12.3 MB/s (the link) |
| 60 ms / 100 Mbit/s, machine loaded | 114 s | 12.1 MB/s |
| 40 ms / 200 Mbit/s | 57 s | 24.3 MB/s |
| 80 ms / 50 Mbit/s | 223 s | 6.2 MB/s |

- **Resume:** reloading the page at 40% of a download (562 MB written) resumed at
  545 MB (the last record; pieces in flight are fetched again) and finished; the
  game then started from the copy.
- **Quota:** with `storeSpare` asking for more room than the browser allows, the
  page showed the quota message at once (nothing downloaded), and **Play without
  keeping the game data** played from the server.
- **Online:** `netplay_check.mjs --server-disc` (new): two Chrome pages in separate
  profiles each downloaded the image (4.6 and 5.3 s on localhost), then opened the
  lobby, created and joined the game, and ran the `menus` script to frame 400 in
  lockstep: both `MEM1 12f6c71b...`, the same line as the same check with picked
  files.
- **Determinism unchanged:** with the stored image, Chrome's guest lines equal
  native at the WEB.md checkpoints: 700 fields `MEM1 73e856d4...`, 2,400 fields
  (START x4) `c70ca6c5...`, 3,600 fields (`menus`) `5e150b6c...`. The match
  session above ends with the same guest line (`MEM1 8d79a7b5...` at frame 5,200)
  in all four runs: network or stored image, loaded or not.

### Keeping the uploaded disc on the server

`deploy/docker-compose.yml` keeps the disc, the password and the TURN secret in
the named volume `mvp-data`. Dokploy deploys a compose app with
`docker compose -p <app name> -f <compose path> up -d --build --remove-orphans`
(Dokploy's `packages/server/src/utils/builders/compose.ts`); the app name is fixed
when the app is created, so every deploy mounts the same `<app name>_mvp-data`, and
`up` never removes a named volume (Dokploy's docs: named volumes persist across
deployments; only paths in the cloned repository do not). The name therefore does
not change between deploys, and it is **not pinned**: a `name:` now would move
the owner's deployment to a new, empty volume and lose the disc he uploaded. What
does lose it: deleting the app with its volumes, creating a new app, or Dokploy's
"Randomize Compose" (it renames volumes). DEPLOY_DOKPLOY.md says so in the UI's
words. After the first deploy with this change the server hashes the uploaded
image once (`discPreparing` for those seconds) and keeps the manifest in the
volume.

### Decisions to record (for the lead)

- **P1-D1, the disc in the browser:** on the deployment the page downloads the
  server's image once into OPFS (`mvp-disc/`) and the engine reads it locally; the
  network reads stay only as the fallback (no OPFS, `store=0`, or the player's
  choice after a download error). Under DECISIONS 2026-10-14 (the disc may be cached
  in the player's own browser storage); the server keeps `no-store`.
- **P1-D2, verification:** the image hash is SHA-256 over the SHA-256 digests of
  the image's 8 MiB pieces; the page checks the manifest against the hash from
  `/config.json` and every piece before writing it; the engine's identity check
  (DOL SHA-1) still runs at every start.
- **P1-D3, no start during the download;** the lobby opens only with a complete
  copy.
- **P1-D4, the volume stays `mvp-data` without a pinned name** (above).

### Open

- Firefox and Edge with the stored image are not measured yet (both have OPFS with
  synchronous handles in Workers; the shell code is the same).
- Not run against the real VPS link; the numbers use Chrome's simulated conditions
  on localhost.
- Starting while the download runs (with a read plan fetched first) is possible
  later, but any read of a piece not yet stored would stall.

### Tests

`npm test` in `engine/server`: 64 of 64. `test_web_shell`: 26 of 26 (new
`tests/disc-store.test.mjs`); `test_web_cache` passes. Browser runs (local, the
owner's disc, results and screenshots in the session's scratch, never committed):
the before/after sessions above, the three WEB.md determinism checkpoints, a resumed
download, the quota error with the fallback, a later visit with no disc traffic,
and page screenshots of the no-disc note, the download progress and the ready page.

## P1-gfx: the flashing, and speed in play

Side session `claude-side-p1gfx`, branch `engine/p1-gfx`. Chrome 155 headed on this
PC (i7-14700K, RTX 4070 SUPER, 3440x1440 at 59 Hz), Playwright, the owner's CISO
picked as a file (the disc path is P1-disc's). Two sessions into a match, both by
input script: **CPU vs CPU** (E3c's path; play from field ~14,900) measured over
fields 16,000-18,400 (40 s of play), and **human pitching** (E3a's path, then A every
100 frames from frame 5,200) over fields 12,900-14,600. Each run goes unpaced to a
field before the window, then paced (`browser_check --fast-until`). Other sessions
shared the machine (CPU load 5-40 % during the runs; P1-disc's load generator ran
during some earlier ones).

### Status (2026-10-15)

| # | Task | State |
|---|---|---|
| 1 | Reproduce the flashing in a real browser; record every present | Done: the game's field-alternating HUD pictures shown as whole frames (below) |
| 1b | Fix | Done: the picture the VI scans out, alternating pixels mixed; flicker events in human play 41 -> 2 (Chrome); the same fix natively |
| 2 | Speed in Chrome in a match: >= 1.0x, present p95 < 25 ms | Partly: 1.0x held; present p95 64 -> 27.5 ms (CPU vs CPU), 60 -> 33 ms (human); heavy fields still ~16.5 ms |
| 3 | Exactness | Kept: guest lines unchanged (700 and 3,600 fields equal to native and WEB.md; both match sessions equal before and after); 672 in-game captures pixel-identical after the GX changes; ctest msvc 44/44, emscripten 38/38 |

### 1. The flashing

**What each present shows.** `mvp_web` now keeps a presentation trace
(`tracePresent=1`; `browser_check --trace-present`): the VI's TFBL at every field,
every XFB copy, and what each present showed. In both sessions: one XFB
(0x00888080, 640x448) from field 5 on, at most one XFB copy per field (always with
the EFB clear), every present a complete copy at the VI's address (no fallback to
another copy, no canvas resize). The presenter never showed a partial frame, the
EFB or a stale buffer.

**What the page showed.** `browser_check --screencast F:N` records every frame
Chrome composites (CDP), and a grid test finds cells that go A, B, A on consecutive
frames. CPU vs CPU: 3 events in 600 frames (the base-runner inset blinking twice).
Human pitching: 41 events in 16 of 1,100 frames: a light grey box (222,222,222)
over the count box and the base inset in the top left, the score bug dark for a
frame. Natively, with every XFB copy captured (`mvp-play --capture-every 1`), the same
(deterministic): 434 events in 83 of 782 frames.

**Why.** `--draw-log` on two neighbouring fields: in one the game draws an 8x8 C8
panel fill stretched over the HUD box (blended, an opaque palette entry) and HUD
pieces in other places; in the next it does not. For about 30 frames after each A
press the HUD alternates every field (W . W . ...) while the game renders at a full
60 fps (one copy per field): a field-locked 30 Hz alternation. On the console's 480i
output each field shows every other line, the white panel always on the same field
parity, so an interlaced TV shows a steady translucent highlight. Shown as whole
frames one after the other it flashes; and when the browser ran two to four fields
per present (heavy scenes, before the pacing change below) it became an irregular
strobe.

**Fix** (`gfx/wgpu/renderer`, `af98a732`). `Renderer::scan_field(addr)` records at
every VI field the XFB the VI scans (a GPU copy only when it changed), and
`scanout()` is what is shown: the last field's frame, except that pixels that
alternate over the last three fields (|a - c| small, |a - b| large) show the mean of
the last two. Frames that do not alternate are shown exactly as copied (camera
motion shows no ghosting); captures still read the XFB itself. The browser
(`mvp_present`) and the `mvp-play` window both use it. After: human pitching in
Chrome, 2 flicker events in 1,426 composited frames (41 in 1,100 before), the HUD box
a steady translucent panel; the native window presents through it (395 presents,
0 WebGPU errors).

### 2. Speed in play

**Profile** (a Chrome trace through CDP, V8's sampler in the Worker, a profiling
build with names; `browser_check --trace F:MS`, `tools/trace_summary.mjs`), 7 s of CPU
vs CPU play (fields 16,150-16,600, mostly heavy), paced, 13 ms per field on average:

| Where | Share of the Worker | ms per field |
|---|---:|---:|
| translated game code (a third of it the memory, psq and FP helpers `h.*`) | 40 % | 6.4 |
| GX path: `Observer::gx_command` (the GX processor, inlined) 14 % self, `Renderer::draw` 4 %, EFB copies 4 % | 24 % | 3.8 |
| write-gather pipe and GX FIFO: `Hardware::write`, `mvp_rt_write32`, `GxFifo::push`/`execute`/`command_length` | 9 % | 1.5 |
| WebGPU calls from JS (`writeBuffer` 3 %, `submit`, `setBindGroup`, `beginRenderPass`) | 5 % | 0.75 |
| rest of the runtime (indirect calls, safe points, the interpreter) | 4 % | 0.6 |
| idle (waiting for the clock) | 17 % | |

The GPU process's main thread was busy 21 % of the time: the GPU is not the limit.
A heavy field (many players and the crowd in view) has ~8,400 GX primitives and
~52,000 vertices (6.3 per primitive: skinned triangle strips with indexed
attributes, a CPU matrix load every two primitives).

**What changed** (each kept the same guest state and the same pictures):

- Pacing (`web/src/worker.ts`, `521444fa`): **chase**. A field slower than the
  refresh used to wait for the animation frame after the next, and that one then ran
  two to four fields: steps of 33-67 ms. Now a batch is one field (two when three or
  more are due) and, while behind, the next batch runs at once in its own task
  (MessageChannel); each batch's frame is presented when its task ends.
  `pacing=raf` keeps the old loop. Same build, CPU vs CPU: present p95 38.7 -> 29.3
  ms, over 25 ms 20 % -> 9 %, fields per present 1.25 -> 1.04.
- GX processor (`63e1e3ec`, `da2dacdf`): the transform setup kept across primitives
  (rebuilt on XF register, light or post-matrix writes or a scissor offset write;
  matrix writes drop only the cached matrices they touch); each light's factor
  computed once per vertex instead of again for the alpha pass, each pass computing
  only the components it writes; n/255 by table; OutVertex written in place.
  `mvp-gx-bench` (new, data-free, the game's VCD/VAT values): 4.22 -> 3.84 ms per
  8,000 primitives under Node (5.6 -> 4.3 ms with alpha lit too). 672 in-game
  captures pixel-identical.
- Runtime (`63e1e3ec`, `fdde80a3`): write-gather stores in one step; the GX FIFO
  measures a command that arrives over many bursts once and caches vertex sizes; the
  wasm write32 import sends WGP stores straight to the hardware model.
- Tried and dropped: `-msimd128` for the GX processor (no gain in the bench; about
  5 % on the whole engine in one unpaced pair, within noise, not kept); running the
  next field up to a quarter field early (worse: p95 33 ms).

**Before and after in Chrome** (paced, headed; before = origin/main's engine with
only the trace tooling; after = this branch):

| Session | | speed | host ms/field (mean; p90 of 0.5 s windows) | presents p95 | presents > 25 ms | composited p95 |
|---|---|---:|---:|---:|---:|---:|
| CPU vs CPU, fields 16,000-18,400 | before | 0.99x | 9.81; 17.1 | 64.1 ms | 23.5 % | 62.7 ms |
| | after | **1.00x** | 9.57; 16.5 | **27.5 ms** | 7.5 % | 29.1 ms |
| human pitching, fields 12,900-14,600 | before | 0.99x | 9.69; 17.8 | 60.2 ms | 25.9 % | 65.4 ms |
| | after | **1.00x** | 9.04; 16.7 | **32.9 ms** | 10.9 % | 33.4 ms |

Unpaced, the same CPU vs CPU window runs at 1.59-1.60x (9.4-9.5 ms per field).
**The target (p95 under 25 ms) is not met**: the heavy stretches still cost about
16.5 ms per field in the Worker, at the edge of the 16.7 ms field, so some batches
still run two fields. The averages are far below the budget; the heavy stretches
are not.

### Exactness

- Guest lines: 700 fields `73e856d4...` and the menus script at 3,600 fields
  `5e150b6c...` (14,602,688,100 instructions, 2,117 polls) in Chrome, equal to native
  `mvp-play --no-render` and WEB.md §4; CPU vs CPU at 18,400 fields (`ccd3f48c...`,
  8,442 polls) and human pitching at 14,600 fields (`03213cde...`) identical before and
  after every change, paced and unpaced, raf and chase.
- The renderer still never writes guest state (the scan-out keeps its own textures).
- `ctest --preset msvc` 44/44 (local tests with the disc; `local_disasm` and
  `server_node_tests` skipped as before); `ctest --preset emscripten` 38/38;
  `test_gx_processor` has a new case: the cached transform setup equals a fresh
  processor's after every kind of write.

### Tools added (development)

`browser_check.mjs`: `--trace-present`, `--fast-until F`, `--screencast F:N`,
`--trace F:MS`, `--site DIR`, `--viewport WxH`, `--chrome-args`;
`tools/trace_summary.mjs` (V8 samples by bucket and function, inclusive times, the GPU
process's busy time); status fields `resizes`, `copies_dropped`, `copy_size_misses`,
`scan_mixed`; `mvp-play` prints EFB-copy drops and size misses; `mvp-gx-bench`.

### Commits

| Commit | What |
|---|---|
| `af98a732` | engine(gfx): the VI scan-out with field-alternating pixels mixed; presentation trace and browser-check tooling |
| `63e1e3ec` | engine(gfx): transform setup kept across primitives; write-gather stores in one step |
| `6803974b` | merge of origin/main (P1-disc); conflicts resolved as the union |
| `da2dacdf` | engine(gfx): light factors once per vertex, colors by table; mvp-gx-bench |
| `fdde80a3` | engine(runtime): GX FIFO pending length and vertex sizes cached; WGP stores straight to the hardware |
| `521444fa` | engine(web): chase pacing |

### Decisions to record (for the lead)

- **P1-G1** (presentation): what is shown is the VI's scan-out over the last fields,
  with pixels that alternate field to field (A, B, A) shown as the mean of the last
  two, as an interlaced display shows them; everything else exactly as copied.
  Captures and tests keep reading the XFB itself.
- **P1-G2** (pacing): the browser's paced loop chases (one field per batch, two when
  three or more are due, the next batch at once while behind); `pacing=raf` keeps
  the old loop.

### Open

- **Heavy stretches** (~16.5 ms per field in the Worker) keep p95 above 25 ms. Next
  steps, in order of expected gain:
  1. A render thread: the GX processor and the renderer (about 30 % of a heavy
     field) in a second Worker. It needs shared memory (wasm threads, so
     cross-origin isolation: COOP/COEP headers on `serve.mjs` and `engine/server`),
     the WebGPU device and the canvas owned by that thread, a command ring in shared
     memory, and the emulation waiting for the render thread at the guest's GP sync
     points (draw done, tokens: before the CPU rewrites vertex arrays). Guest state
     cannot change (the renderer only reads).
  2. The vertex path itself: per-format vertex loaders, SIMD for the matrix and
     lighting math (lane-wise, same operation order), packing straight into the
     pipeline's layout instead of OutVertex and then the renderer's copy.
  3. The translated code's memory helpers (`h.rd32` alone ~6 % in play) and psq
     (E2D_LOG §5, "What is left").
- **EFB-copy size misses**: the half-scale 512x448 copy at 0x01797180 is sampled as a
  256x256 texture (once per field in play), so the renderer decodes stale memory
  instead of using the copy for the 224 rows it covers. Constant from frame to
  frame (not part of the flashing); use the copy for the rows it covers.
