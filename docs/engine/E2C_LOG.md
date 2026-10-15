# E2c log: the browser client (sound, gamepad, the disc from the server, caching, polish)

Working log for E2c (`claude-side-e2c`): make the browser build good to play. E2
(`docs/engine/E2_LOG.md`) booted the game in Chrome, Edge and Firefox; E3b
(`docs/engine/E3B_LOG.md`) added the AX mixer and native sound. The design and
the commands are in `docs/engine/WEB.md`; this log keeps the evidence.

## Status (2026-10-14): exit met

| # | Item | State |
|---|---|---|
| 1 | Browser audio: AudioWorklet fed by the engine Worker, drift resampler 32 -> 48 kHz, first-gesture start, guest unchanged | Done |
| 2 | Gamepad: standard layout -> GameCube pad, rebindable, stored per browser; unit tests; fake `getGamepads()` check | Done |
| 3 | The disc from the server: `/config.json`, same-origin Range reads with a block cache and read-ahead; picker otherwise; identity check kept | Done (mock server; E5 builds the real one) |
| 4 | Cache of the translated module in OPFS (DOL SHA-1 + engine build), re-translation as the fallback | Done |
| 5 | Polish: fullscreen, pause on a hidden tab (host loop only), status line and progress bar, clear errors | Done |

**Exit evidence** (all runs local; summaries and screenshots under `build/engine/web-check/e2c/`,
never committed):

- **Disc from the mock `/config.json`, no picker:** Chrome 155 (headless) and Firefox 157
  (headed; headless Firefox has no WebGPU) loaded the image from `/api/disc/image` of the mock
  deployment (`serve.mjs --disc`): `source: url`, the identity check passed (`main.dol
  da6becdb...`), and the run reached the title screen and the main menu. Requests: only the
  site's files, `/config.json`, `/build-id.json`, `/symbols.txt` (cold only) and
  `/api/disc/image`; nothing outside the origin.
- **Sound plays:** the page's AnalyserNode tap on the worklet's output, sampled by the browser
  check every 200 ms over the 3,600-field `menus` run: Chrome RMS up to 0.24 and peak 0.92
  (146 of 421 samples non-silent), Firefox RMS up to 0.26, peak 0.92 (149 of 423); first sound
  at field 623-626 (the EA SPORTS stinger). The worklet received 1,913,920 frames in both: every
  frame the mixer made over those 3,600 fields (the same count as E3b's native WAV), 0 dropped.
- **Gamepad:** `test_web_shell` (node --test): 17 of 17 (6 mapping, 6 resampler, 5 disc
  contract); with a fake `navigator.getGamepads()` (a standard pad the check presses), the page
  mapped Start to 0x1000, the left stick up to stickY 100, RT to R with trigger 255, A to 0x100;
  the game's frame polls returned them (`pad_polls` 9), and Start presses took the run through
  the intro (licence screen at field 1312), the title (2124) to the memory card dialog (2520).
- **Guest hash equals native with audio on:** the documented checkpoint (WEB.md §4: 3,600
  fields, the `menus` script) with the mixer attached at field 0 and the worklet playing:
  Chrome and Firefox `14,602,688,100 instructions, time base 2,433,781,350, 2,122 frame polls,
  MEM1 95f5c597...`, the native line. The same line with audio off (`audio=0`, paced and
  unpaced), with the audio buffer at 30 and 45 ms, and unpaced with the mixer on; 700 fields
  with a 3 s hidden-tab pause at field 304: `MEM1 eef70ba3...`, native. Over a slowed server
  link (30 ms, two cache settings) the line at 2,200 fields was the same in both runs.
- **Warm start faster than cold** (pick or page load -> first frame, ms; 4 runs in one profile,
  the first with the cache cleared):

  | | Chrome, picker | Chrome, server | Firefox, picker | Firefox, server |
  |---|---:|---:|---:|---:|
  | cold (translate) | 698 | 740 | 1,120 | 1,026 |
  | warm (cache) | 280-330 | 344-363 | 399-439 | 380-418 |
  | translate phase cold / warm | 491 / 76-114 | 514 / 103-116 | 641 / 174-182 | 658 / 172-189 |

- **Edge 155** (headless, the server image, sound, 800 fields): cold 1,073 ms, warm 312 ms,
  sound non-silent (RMS up to 0.17), the same guest line as Chrome and Firefox at 800 fields
  (`MEM1 41a3f60e...`).

- **E5's real server** (after merging origin/main with E5's netplay and `engine/server`; its
  built server from E5's worktree, run locally with a throwaway password and the disc
  configured): Chrome logged in through the form, pressed Play (the lobby is on the page), loaded
  the disc from `/config.json` and `/api/disc/image`, played sound; cold 728 ms, warm 329 ms;
  `MEM1 eef70ba3...` at 700 fields. E5's `netplay_check` on the merged shell: two pages, the
  `menus` script to frame 400, identical guest lines (`MEM1 92cab63f...`), no desync; and the
  same with the disc on the server instead of the file inputs (both engines started on joining
  the room): the same line, no desync.

**Tests:** `ctest --preset emscripten -LE local`: 25 of 25 before the merge, 28 of 28 after (new: `test_web_cache`, 5 cases;
`test_web_shell`, 17 node tests). No native code changed (only `engine/web/`).

## What was built

Engine module (`engine/web/wasm/`, commit b82d3a1a, 9167072e):
- `web_disc.*`, `block_cache.*`: the server's image read by synchronous Range XHRs in the
  Worker through a block cache (256 KiB blocks, 64 MiB, LRU); a miss fetches all the blocks
  its read needs (up to 32) or a run that doubles on sequential misses (up to 4); a sequential
  stream asks for the next 8 blocks ahead (`mvp_disc_want`), which the Worker fetches
  asynchronously between batches and hands back (`mvp_disc_insert`). Retries network and
  server errors twice; 401/403 reads as "log in again".
- `module_cache.*`: the translator's whole output (`xlat::WasmModule`: the wasm bytes and the
  runtime's tables) as one blob; a `static_assert` on the struct sizes forces an update when
  E2d changes the module's fields. `build-id.json` (hashes of `mvp-web.wasm` and
  `symbols.txt`, written by the build) keys the cache.
- `web_audio.h`: the mixer's frames between run batches; `mvp_audio_enable` attaches a fresh
  `AxMixer` to `Hardware::set_ax_observer` (between batches only).
- Progress messages from inside `mvp_translate`; `pad_last`, `pad_polls`, `net`, `audio` in
  `mvp_status`; `mvp_disc_trace` (development: the picked image's read offsets and sizes).
- `mvp-web-cache-sim` (development): replays a read trace through the block cache over a
  modelled network.

Web shell (`engine/web/src/`, commit 959ba36c): `audio.ts`, `audio-worklet.ts`,
`resampler.ts`, `gamepad.ts`, `gamepad-ui.ts`, `disc.ts`, `module-cache.ts`, new modules;
`main.ts`, `worker.ts`, `input.ts`, `protocol.ts` changed. Tools: `serve.mjs --disc` (the mock
deployment), `browser_check.mjs` (`--server-disc`, `--audio`, `--pad`, `--runs`, `--hide`,
`--trace-disc`, `--hold`, ...). Unit tests: `engine/web/tests/*.test.mjs`.

## Measurements

Machine as in WEB.md §3 (i7-14700K, RTX 4070 SUPER, Windows 11; other agents shared it).

**The engine's memory:** 220 MB of WebAssembly memory after a cold start that fills the
cache (213 MB without the cache: the kept module reuses the translator's peak; the entry is
copied out in two pieces, header and bytes, so no second copy enters the heap), 146-155 MB
after a warm start (no translator peak at all).

**Audio latency** (from the mixer to the speaker):
- the worklet's buffer target is 60 ms; at full speed its smoothed fill averaged 1,930-2,360
  frames (60-74 ms);
- the context: Chrome `baseLatency` 10 ms, `outputLatency` 0 (Chrome does not report it here);
  Firefox (headed, the real headset) `outputLatency` 32 ms;
- the Worker posts once per animation frame: up to one field (16.7 ms) more.

  Sound trails the picture by about 80-115 ms. Smaller targets underrun in the menus (Chrome,
  after the intro movie, 2,300 fields): 60 ms 0, 45 ms 16, 30 ms 21 underruns. 60 ms stays.
- **Underruns during the intro movie** (fields 600-1270): 112-114 in both browsers; the movie
  decodes at 10-20 fields/s (E2's measurement), so its sound plays in pieces, as natively. After
  it: Chrome 0, Firefox 1 (a load at field 1825).
- **The mixer's cost:** 3,600 unpaced fields with and without it, twice each: 48.1 and 49.2 s
  against 47.7 and 47.6 s of `rt::run` time (about 2 %, within the machine's noise).

**The server image:**
- Localhost, 800 fields: 45 synchronous requests and 55 read-ahead requests, 35 MB fetched for
  16.7 MB of guest reads, 165 ms spent waiting. The identity check takes 52-80 ms (25-40 ms from
  a picked file).
- The game's reads over its first minute (boot, intro, title, menus; `--trace-disc`): 1,150
  reads, 27 MB, 812 of them continuing the previous one, a third of them scattered small reads
  (322 of at most 64 bytes, 438 of 16-32 KB). Blocks touched: 71 MB at 1 MiB, 41 MB at
  256 KiB, 31 MB at 64 KiB.
- `mvp-web-cache-sim` on that trace (the guest paced; misses wait a round trip plus their bytes
  behind whatever the link still sends):

  | Link | 1 MiB blocks (first version) | 256 KiB (default) | longest stall (256 KiB) |
  |---|---:|---:|---:|
  | 1 ms, 1 Gbit/s | 0.64 s waited | 0.29 s | 18 ms |
  | 15 ms, 300 Mbit/s | 2.95 s | 1.84 s | 78 ms |
  | 30 ms, 200 Mbit/s | 4.84 s | 3.55 s | 124 ms |
  | 50 ms, 100 Mbit/s | 9.13 s | 8.02 s | 310 ms |
  | 30 ms, 50 Mbit/s | 14.4 s | 11.3 s | 479 ms |

  At 30 ms / 200 Mbit/s the wait falls in loading screens: 1.9 s during the boot loading screen
  (fields 0-300, the identity check included), 1.0 s at the load before the licence screen
  (fields 1500-1800), 40-50 ms per 300 fields in the menus. Chrome against the mock with
  `--latency 30 --rate 25` (its throttle is coarse on Windows) waited 9.5 s with the default and
  18.5 s with the first version, over 2,200 fields; the guest line was the same in both.

## Decisions to record (for the lead)

- **E2c-A1, audio transport:** the AudioWorklet is fed by the engine Worker through a
  MessageChannel (one port in the Worker, one in the worklet; each run batch's frames are a
  transferred `Int16Array`), not a SharedArrayBuffer ring. A SAB needs cross-origin isolation
  (COOP/COEP) on every server (the dev server, E5's deployment), which also constrains every
  other resource the page loads; it would not lower the latency, which is set by the Worker's
  batches (one animation frame) and the device. The drift resampler runs in the worklet (the
  native design, `audio/drift.h`, with the 32 -> 48 kHz step and cubic interpolation).
- **E2c-A2, audio start:** the AudioContext is created on the first pointer press, key press or
  touch (the autoplay policy; gamepad buttons do not count as a gesture in browsers). The Worker
  attaches the mixer when the worklet's port arrives; before it, nothing is mixed. Guest state is
  the same either way (E3b-MIX1); the checks above attached it at field 0.
- **E2c-D1, the server image:** read by synchronous Range requests in the engine Worker (a guest
  DVD read completes inside the call) through an in-memory block cache with read-ahead. The
  bytes are not kept after the page closes (the server sends `Cache-Control: private,
  no-store`).
- **E2c-C1, the translation cache:** OPFS directory `mvp-translated`, one entry (about 52 MB)
  keyed by the DOL's SHA-1 and the engine build (hashes of `mvp-web.wasm` and `symbols.txt`),
  written after the first frame, completed by a `.ok` marker; any failure re-translates.
- **E2c-G1, gamepad:** default mapping for the standard layout as in WEB.md §2 (Z on both
  bumpers, the triggers analog with the digital click at 90 % of their travel, sticks with a
  radial dead zone of 15 % scaled to +-100, clamped to the circle), stored per browser under
  `localStorage["mvp.gamepad.mapping.v1"]`; keyboard unchanged; the pad still reaches the guest
  only at frame polls (E0c-IN1, E2-W5).
- **Open question for the owner:** keeping the server image's blocks in the player's browser
  (OPFS) after the first visit would make later boots read locally. The server's `no-store`
  says the bytes should not persist, so this is not done; it needs the owner's decision.

## Notes

- E2's log says Enter at fields 803 and 1000 skipped the intro movie. In these runs presses
  before field ~1100 (keyboard or gamepad, held 150 or 600 ms) did not: the game ignores START
  during the first part of the intro (the EA SPORTS logo); a press at field ~1200 skips it
  (licence screen at 1312).
- The mock's `--rate` throttle waits a timer per 64 KB chunk; Windows timers make it slower
  than asked at high rates. The simulator is the better guide for tuning.

## Next step

1. **Remote boots:** learn the boot's read plan. After the first visit the browser keeps the
   list of blocks the boot read (offsets only, in its own storage) and fetches them in parallel
   from the start of the next visit, during the translation; most of the 1.9 s boot wait at
   30 ms would go. Persisting the blocks themselves needs the owner (above).
2. **The real server (E5):** tested locally (above); next on the VPS. E5's lobby text says "Then
   pick your disc", which on the deployment (disc on the server) should say that the game starts
   when both have joined (netplay.ts is E5's). The deployment must be HTTPS (WebGPU, AudioWorklet and OPFS need a secure context) and serve
   `.js` as `text/javascript`. The Worker's `start` message now carries `disc` (a `File` or a
   URL) instead of `file`: shell changes on other branches merge against that.
3. **A real controller:** try an Xbox and a PlayStation pad in Chrome and Firefox (the
   standard mapping is the browsers' job); the mapping UI covers the rest.
4. **Speed (E3a):** the intro movie's sound underruns until the movie decodes at full speed.
