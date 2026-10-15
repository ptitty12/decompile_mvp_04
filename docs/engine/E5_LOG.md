# E5 log: lockstep netplay and the server

Working log for the E5 session (`claude-side-e5`, branch `engine/e5`). The goal
(owner's goal #2): two players on different networks finish an exhibition game,
each game running in its own browser, with matchmaking and signaling on the
owner's VPS. The local equivalent comes first: two browser instances on one
machine stay in lockstep through the menus with identical per-frame hashes.
Design: `docs/ARCHITECTURE.md` §8. Protocol and deployment: `docs/engine/NETPLAY.md`.

## Status

| # | Step | State |
|---|---|---|
| 1 | `engine/net/`: session, protocol v1, state hashes, transports, data-free tests | Done |
| 2 | Netplay in the run loop; two native peers over UDP agree with the solo run | Done |
| 3 | `engine/server/` (TypeScript): password gate, disc route, lobby, signaling, TURN config | Done |
| 4 | Browser: data channel transport, lobby UI, two-browser lockstep test, latency and bandwidth | Done (local) |
| 5 | `docs/engine/NETPLAY.md`; deploy package | Done; deployment waits for VPS access |
| 6 | First-run password setup (E5b): the owner creates the site password in the browser, agents never handle it | Done |
| 7 | Into the match (E5c): E6's "gate missed" at the match's loading; the run now waits at every frame poll whose input is missing | Done: native (also lossy) and two Chrome pages (also with the example pack) into a two-player game (§5) |

## How to build and run (agents)

- Native (`msvc` preset, `engine/tools/msvc.cmd`, as in E0B_LOG): `cmake --build --preset msvc -j 8`
  builds `engine_net` and its tests (`test_net_protocol`, `test_net_session`, `test_net_udp`;
  data-free, in `ctest`). With `MVP_DISC` set at configure time it also builds `mvp-netplay`
  and the local tests `local_netplay_lockstep` and `local_netplay_lossy` (label `local`).
- `engine/net/tools/lockstep.cmake` runs two `mvp-netplay` peers at once plus the solo
  reference: `-DFRAMES=N -DDELAY=D -DIMPAIR="--loss P --latency MS --jitter MS" -DPORT=N`
  (`-DSTALL="--stall-from F --stall-to G --stall-ms MS"`: player 2's host sleeps after
  those polls; `-DEXPECT_STOPS=1`: a run must have stopped at a poll), or `-DDESYNC=1`
  for the desync path. Logs and reports stay under `build/`.
- Server: `npm ci` then `npm test` (or `npm run build`) in `engine/server`; ctest runs
  the same tests as `server_node_tests` when `node_modules` is installed.
- Browser: build `mvp-web` (`engine/tools/emsdk.cmd cmake --build --preset emscripten -j 8
  --target mvp-web`, after `npm ci` in `engine/web`), `npm run build` in `engine/server`,
  then `node engine/web/tools/netplay_check.mjs --script FILE --frames N --delay D`
  (`--browser`, `--browser2` for a mixed pair, `--netsim L,J,P` for a slow network,
  `--expect` a native guest line, `--no-render`). Summaries go to `build/engine/web-check/`.
- Deploy package: `node engine/server/tools/package.mjs` (NETPLAY.md §6).

## 1. `engine/net` (done)

- `protocol.h`: wire protocol v1. Datagrams start with `'M' 'N'`, the major version and a
  type; big-endian. HELLO carries the identity (engine build id, disc identity SHA-1,
  pack-set SHA-256, canonical settings, CLK1 cycles per instruction, DVD1 latency and
  rate), the role (player 1 or 2), the proposed delay, the desync interval, a nonce
  and a seed. INPUT carries every input the peer has not acknowledged (oldest first,
  at most 32; a pad equal to the previous one is one byte), the unacknowledged state
  hashes, two acknowledgements, the sender's next frame and an RTT echo. BYE carries a
  reason (quit, desync, rejected, timeout, error), a frame and a short text.
- `session.h`: the lockstep session. The local pad sampled at frame F becomes the
  input of frame F + D; frames 0..D-1 are neutral on both ports; D is the larger of
  the two proposals; player 1's seed is used. `ready(F)` generates local inputs up to
  F + D (each new one is sent at once) and is true when both ports' inputs for F are
  known. A peer can never be more than D frames ahead, and with the sampling done at
  the gate, D = 0 cannot deadlock. Resends: every datagram repeats all unacknowledged
  inputs; a keepalive goes out after 20 ms without a send. Desync: hash records are
  compared when both sides have them; a mismatch stops both sides (BYE desync names the
  window). Refusal: any identity difference, equal roles or a different desync interval
  stops the handshake with the reason on both sides. Timeout: 10 s of silence.
- `state_hash.h`: XXH64 (from the published algorithm; four reference vectors pass,
  including the 32-byte stripe path) and `StateHasher`: MEM1 in K slices, slice
  `f mod K` hashed at frame poll f together with the frame number and the instruction
  count, chained into the window hash, which closes at `f mod K = K - 1`. 1/K of MEM1
  per frame instead of 24 MB at once: cheap in the browser, and any divergence that
  lasts a whole window is caught. The slice hashes of the last window go into the
  diagnostic, so two players' diagnostics show which MEM1 range differs.
- `identity.h`: disc identity v1 = SHA-1(`"mvp2005-disc-id/1\n"` + boot.bin + BI2 + FST +
  the DOL's SHA-1): what the boot environment copies into memory plus the code, the same
  for ISO and CISO dumps of the disc. The settings string (sorted `key=value`: AX voices,
  RTC, SRAM, console type, TV mode, ARAM size, clocks, ports, PadState version). The
  empty pack set's hash `f5e12989...` (MODDING.md §10, same as `pack.py set_hash([])`).
- `transport.h`: `SimLink` (virtual clock; latency, jitter, loss, duplication, cut) for
  tests; `udp.h`: native UDP and `ImpairedTransport` (loss, latency, jitter on the real
  clock).

Tests (data-free, in `ctest`): `test_net_protocol` (8 cases: round trips, every
truncation, 2,000 random bodies, compatibility rules, XXH64 vectors, the hasher's
windows and slices, identity helpers); `test_net_session` (11 cases: delay and seed
negotiation; clean link without stalls; D = 0..4 over 25% loss, 0-60 ms jitter and 5%
duplicates; 60% loss; uneven speeds and 400 ms hitches; desync stops both at the bad
window; refusals; HELLO under 70% loss; a cut link times out on both sides; quit;
bandwidth). Every case checks that both peers take exactly the stream the delay rule
defines and that no peer ever takes a frame the other has not produced. Payload:
3.9 KB/s per direction at 30 ms latency and D = 3 (63 datagrams/s).

## 2. Netplay in the run loop (done)

`net/driver.h` (`NetplayDriver`): the session is the input queue's source (E0c-IN1);
the run loop is the browser's, unchanged except for a gate:

```
for (;;) { if (driver.may_run(now)) rt::run(cpu); else wait for datagrams; }
```

`rt::run()` returns at every VI field (host yields, `runtime/host_yield.h`). `may_run()`
pumps the session and is true when the next frame poll's input is known. After each
poll, `after_poll()` feeds the state hasher and, if the following frame's input is not
known yet, asks the run to yield at its next safe point, so the gate is checked before
that poll. If a poll ever arrived without that chance, the input source stops the run
("gate missed") instead of guessing; it never happened (0 in every run below). No
runtime file changed. (It did happen at the match's loading, found by E6: a requested
yield waits for a safe point where an event is due, and there frames come faster than
events. E5c makes the run stop at the poll itself: §5.)

`mvp-netplay` (`net/tools/mvp_netplay.cpp`, local only): `peer` mode runs the
translated DOL with the session over UDP on 127.0.0.1, its controller port driven by
the script's events for that port; `solo` mode runs the script shifted by D with no
network, which is exactly the input stream the two peers must agree on. Each prints
the frame log's SHA-1 (per poll: frame, instructions, time base, input), the list of
window hashes and the final guest line.

**Exit evidence (2026-10-14)**, `local_netplay_lockstep` (1,200 frames: intro, licence
screen, title, first menus; START, DOWN, R on port 1, START, stick, A on port 2), D = 3,
K = 60, both peers and the solo run:

| | player 1 | player 2 | solo |
|---|---|---|---|
| frame log (1,200 lines) | `e6b9e9f2...` | `e6b9e9f2...` | `e6b9e9f2...` |
| window hashes (20) | `83d567b0...` | `83d567b0...` | `83d567b0...` |
| guest: instructions, time base, polls | 10,836,931,415, 1,806,155,235, 1,201 | same | same |
| MEM1 SHA-1 | `520439ba...` | `520439ba...` | `520439ba...` |
| hashes compared, desyncs, gate misses | 20, 0, 0 | 20, 0, 0 | |
| stalls | 28 (158 ms) | 35 (111 ms) | |

The test passes in 136 s (`/Od` translation, three instances).
- Impaired (25% loss each way, 40 ms latency, 0-30 ms jitter, D = 2, 900 frames): same
  frame log, windows and guest line as the solo run (`fbbc3f9a...`, `fc0cab6c...`,
  `12f22252...`); 15 windows compared; 0 gate misses; 554 datagrams dropped on one
  side; about 16 s of stalls (latency above D frames).
- Desync path (`-DDESYNC=1`, player 2 corrupts the window closing at frame 599): both
  peers stop at that window with the reason, and write their diagnostics.

The RTT the session reports includes the time a datagram waits while the guest runs a
field (the loop reads the network between fields), about 60 ms average on localhost at
`/Od` speed.

## 3. The server (done)

`engine/server/` (TypeScript on Node 24, `ws` 8.22.0; NETPLAY.md §5): the password
gate (login form, HttpOnly cookie, in-memory sessions, per-address login limit, no
open redirects; page loads go to the form, API calls get 401), the disc route exactly
as agreed with E2c (`/config.json` gives `{"disc":"/api/disc/image"}` or `{}`;
`GET`/`HEAD /api/disc/image` with ranges and `Cache-Control: private, no-store`), the
static site with a CSP, the lobby and WebRTC signaling over `/ws` (session and Origin
checked), and coturn REST-API credentials. Templates for coturn, Caddy, systemd and the
configuration, and `deploy/install.sh` (Debian 12 / Ubuntu 24.04). 19 Node tests (47 with E5b, below).

### First-run password setup (E5b, `claude-side-e5b`, branch `engine/e5b`)

The owner will deploy to a private VPS and the agents must never handle the site
password, so the password is no longer an install input. Behavior and the security
reasoning: NETPLAY.md §5 ("First-run password setup"); deployment: §6.

- **Code** (`engine/server/src`): `password.ts` (scrypt N=2^17, r=8, p=1, 64-byte key,
  32-byte salt; records carry their parameters and are validated on read), `state.ts`
  (the state file: atomic write, 0600/0700, the window start), `setup.ts` (the gate:
  env > stored > setup/closed; CSRF tokens, limiters, one-at-a-time scrypt queue, the
  form and message pages), `server.ts` (`/setup` before the session check, so it is 404
  once a password exists even for logged-out visitors; setup mode redirects pages
  and answers API calls 503), `config.ts` (`stateFile`, `setupHours`; password optional).
- **Tests** (`test/setup.test.ts`, 28 new, data-free, a temporary state file each; the
  clock and the log are injected): setup mode redirects; mismatched confirmation,
  short and long passwords fail; forged CSRF / foreign Origin / cross-site fail; the
  token expires; a good setup stores a scrypt hash with the documented parameters,
  logs in, leaves no plaintext in the file or the log and no temp file, mode 0600;
  a second setup is 404 (also with a form fetched earlier); two simultaneous
  submissions have one winner; a failed write keeps setup open; the window refuses
  setup (also while hashing), is not extended by restarts, and reopens fresh after
  the state file is deleted; restart with a stored hash requires login and keeps the
  login limit; the environment password wins and leaves the file alone; a damaged
  state file stops the server; request, submission and queue limits; NFKC and
  character counting; `loadConfig` precedence. `npm test`: 47/47.
- **By hand in a browser** (Chromium, a throwaway local server): the redirect to
  `/setup`, the strength hint (the hash-pinned inline script runs under the CSP), a
  mismatch error, then a good submission landed on the engine page logged in;
  `/setup` was then 404; the state file and the log held no plaintext. That check
  also showed the browser's form POST passes the Origin check under the setup pages'
  `Referrer-Policy: same-origin`.
- **Deploy**: `install.sh` refuses `MVP_PASSWORD`, no longer writes `/etc/mvp/password`
  (an older install's file is kept as `MVP_PASSWORD_FILE` rather than silently opening
  setup), reports the first-visit state at the end; the unit has
  `StateDirectory=mvp` (`/var/lib/mvp`, 0700) and `UMask=0077`; `server.json.example`
  has `stateFile` and `setupHours`. `node engine/server/tools/package.mjs` still
  builds (checked with a stub site and the output under the scratchpad; the real
  `mvp-web` site is not built in this worktree). `install.sh` itself was syntax-checked
  and its argument/`MVP_PASSWORD` refusals run, but not run end to end (it needs a root
  Debian VPS).
- **Not done / for the lead**: nothing was run on a VPS; `engine/web/tools/netplay_check.mjs`
  keeps working unchanged (it uses `MVP_PASSWORD`). Residual risk (first come, first
  served during the window; the host name is public through certificate transparency)
  is in NETPLAY.md; the install order puts the disc image after the first visit.

## 4. The browser (done locally)

`engine/web`: `wasm/net_web.cpp` runs the session in the Worker; the page
(`src/netplay.ts`) owns the RTCPeerConnection and its negotiated, unordered,
unreliable data channel and relays datagrams to the Worker; the lobby panel appears
only when the page comes from the netplay server. The Worker boots the game after the
handshake, pumps the session every 4 ms, and runs the due fields at once when a
datagram ends a wait. `mvp_web.cpp` changed in five small places (all marked E5).

**Exit evidence, local equivalent (2026-10-14).** `netplay_check.mjs`: the server with
a throwaway password, two isolated browser contexts (two players with their own
cookies) log in through the form, player 1 creates a game, player 2 opens the invite
link, both pick the disc, both play the same script (each drives its own port) to
frame 1,200 (boot, intro, licence screen, title, first menus), paced at 59.94 fields/s,
connected directly (no relay on one machine):

| Run | Guest line at frame 1,200 (both pages) | Native solo (`mvp-netplay`) | Windows | Desyncs | Gate misses |
|---|---|---|---|---|---|
| Chrome 155 x2, D = 2 | `1b4a083f...`, 10,528,857,285 instructions | identical | 20 equal | 0 | 0 |
| Chrome 155 x2, D = 3 | `520439ba...`, 10,836,931,415 instructions | identical | 20 equal | 0 | 0 |
| Chrome 155 x2, D = 4 | `009fa27d...`, 10,484,236,787 instructions | identical | 20 equal | 0 | 0 |
| Chrome 155 + Firefox 157 (no rendering), D = 3 | `520439ba...` | identical | 20 equal | 0 | 0 |

**Latency and bandwidth** (steady state, frames 600-1,200: the title and the menus,
where the game itself polls 55.4 times per guest second; per player, per direction):

| D | frames/s | input latency (sampling to use) | payload | WebRTC transport (DTLS + SCTP) | datagrams/s | RTT |
|---:|---:|---:|---:|---:|---:|---:|
| 2 | 54.5 | 38.5 / 39.2 ms | 2.6 KB/s | 6.5 KB/s | 58 | 35 ms |
| 3 | 54.2 | 57.7 / 56.5 ms | 2.6 KB/s | 5.5-6.5 KB/s | 49-58 | 41 ms |
| 4 | 54.6-57.5 | 75.4 / 74.6 ms | 2.6-2.7 KB/s | 6.6-6.9 KB/s | 58-61 | 37 ms |

- The input latency is D frames of the game's own pace (18.4 ms per poll there) plus
  about 1.5 ms: the netplay cost is D frames, the same for both players since the waiting
  side samples its pad when the wait ends (commit 443e4f72; before that change the side
  that waits had 72 ms at D = 3 against 56 ms).
- On the wire, add IP and UDP headers (28 bytes per datagram, about 1.6 KB/s): about
  8 KB/s per direction in total.
- RTT on one machine is 35-41 ms average: it counts the time a datagram waits in the
  Worker while a field runs and the page-to-Worker hop, not only the network.
- One side shows "stall" time (about 0.8 s per second): that is the side ahead in phase
  idling until the other side's input arrives, not lost frames (both run at the same
  rate, 98% of the game's own).
- Startup: translation 0.51-0.53 s as in E2; the handshake 13-61 ms.

**A slow network, simulated** (`--netsim 40,10,0.02`: each page delays its outgoing
datagrams by 40-50 ms and drops 2%; RTT as measured 119-139 ms), same script and frames:

| D | Guest line = native | frames/s | input latency | payload | transport | datagrams/s |
|---:|---|---:|---:|---:|---:|---:|
| 2 | yes (`1b4a083f...`) | **36.8** (both wait: the delay is shorter than the latency) | 57.8 / 58.1 ms | 3.3 KB/s | 7.4 KB/s | 58 |
| 3 | yes (`520439ba...`) | 55.0-58.0 (full speed) | 56.8 / 62.3 ms | 3.9-4.1 KB/s | 9.5 KB/s | 58 |
| 4 | yes (`009fa27d...`) | 57.6-57.7 (full speed, 10-19 ms of waiting per second) | 75.6 / 76.3 ms | 3.4 KB/s | 7.5-8.0 KB/s | 77-80 |

Rule of thumb: D x 18 ms must cover the one-way latency plus about 10 ms (the Worker
hop and a field's run). D = 3 (the default) suits a round trip up to about 90 ms; the
lobby offers 2 to 6.

All runs: 20 windows compared, 0 desyncs, 0 gate misses, no console errors, no request
outside the server. Data-free tests: `test_net_protocol`, `test_net_session`,
`test_net_driver` (native and under Emscripten/Node), `test_net_udp` (native),
`server_node_tests`; `ctest -LE local`: 30/30.

## 5. Into the match (E5c, `claude-side-e5c`, branch `engine/e5c`)

E6 found that two pages in lockstep through the menus stopped when the match started
loading: "frame N was polled before its input arrived (gate missed)", with or without
roster packs (`E6_LOG.md` §5). E5's own runs had ended at frame 1,200, in the menus.

**Reproduced natively.** `mvp-netplay` peers with E3a's path into an exhibition game
(D = 3, no impairment): player 2 stopped with the gate miss at frame 2,908 (first run),
both players at frame 2,910 (second run), right after the difficulty screen's A (frame
2,903). The two frame logs up to there equal the solo run's.

**Instrumented** (a counting `YieldingHooks` and a tracing input source in `mvp-netplay`,
removed afterwards), at the poll of frame 2,910 that found no input: the same thread as
every poll (OS thread 0x806DF830, the main thread), exception depth 0, called from the
frame loop (LR 0x801489F4 in fn_80148930), MSR[EE] set; the yield `after_poll()` had
requested at frame 2,909 was still pending, and **the runtime had not called its safe
point hook once since that poll**: 129,453 instructions between the two polls, with the
next scheduled event 232,003 instructions away. Not a thread, not an interrupt.

**Root cause.** A requested yield (`YieldingHooks::request_yield`) is taken at the end of
a safe point the runtime stops at, one where an event is due (`c.ticks >= c.next_event`:
a VI line, the audio sample counter, a DVD or DSP completion, the decrementer). The guest
passes safe points all the time, but the runtime looks at them only when an event is
due. Through the menus a frame waits for the retrace (a field, 4.05 million
instructions, with VI events in it), so an event falls between two polls. When the
match loads, the frame loop runs frames without rendering (the loaders' render-skip
countdown, DETERMINISM §2.4): frames 2,906-2,911 of that path came 0.13 to 0.75 million
instructions apart, and the audio counter, whose changes are events every 5,000-7,600
instructions while it runs, was stopped (the next event was 232,003 instructions away).
So a poll could follow the previous one with no point where the run returned to the
host loop.

**Fix: the run waits at the poll itself.** The frame poll's hook (`hle_frame_poll`) first
asks the input queue whether it may poll (`InputQueue::may_begin_frame` ->
`InputSource::before_poll`). `NetplayDriver::before_poll` answers yes when the frame's
input is known; otherwise it stops the run right there with
`YieldingHooks::stop_before`, before the poll consumes anything, and the host loop waits
in `may_run()` as before. The stop is an unwind like a host yield's: the translated
fn_8014865C returns at once (the C++ and wasm emitters now check `g_unwinding` after a
Before hook: one line each), every native frame returns, and the next `rt::run()` enters
fn_8014865C afresh at c.pc. Its entry safe point at the same PC and instruction count is
skipped as the repeat of the one the stopped call passed (the E2 mechanism), the hook
runs again, now with the input, and the guest goes on exactly as if it had never
stopped. While the game waits the guest does not run, so the virtual clock stands still.
A poll that cannot stop (inside an interrupt handler, never seen) still reports the gate
miss; native blocking mode still waits inside `input_for()`. `after_poll()`'s early
yield stays as §4 measured it: it lets the host loop pump the network during the
frame, and the stop only acts where that yield did not come in time. The per-field
host yield (E2-W3), live input at the polls (E2-W5) and the D4 thread model are
untouched; nothing in the guest's timeline depends on where the run stops.

Not chosen: forcing a safe point to fire right after the poll (lowering `c.next_event`).
An extra call of the runtime's safe point when no event is due is not provably invisible
(the hardware model keeps the time of its last update: the next audio-counter change and
the VI interrupt-register write path read it, and register writes and DSP mail arm the
next look through `kick()`), and the peers would make that call at different, host-timed
moments.

**Evidence, native** (`mvp-netplay`, two processes over UDP on 127.0.0.1, D = 3, K = 60):

| Run | Frames | Frame log | Windows | MEM1 at the end | Poll stops (P1/P2) | Gate misses |
|---|---:|---|---|---|---:|---:|
| E3a's path (port 1 only), into the first pitch | 5,400 | `6de8f6f5...` | 90, `e12223e0...` | `0b7d1d1c...` | 0 / 4 | 0 |
| Two players (P2 takes the away team), pitch cycles, 25% loss, 40 ms + 0-30 ms jitter | 5,600 | `6bc617bf...` | 93, `1c0391d4...` | `618ce8bc...` | 3 / 3 | 0 |
| Same script, local link, to frame 60,000 (pitch cycles until frame 40,100) | 60,000 | `cf1b7442...` | 1,000, `07744a7b...` | `93f8cf51...` | 18 / 30 | 0 |

Each row equals the solo reference of the same script and delay (and the first equals the
solo run of E6's build, before this change, and `mvp-play` with the same input stream:
the solo guest line is unchanged). `mvp-play` with the same stream and captures shows
where the peers are (captures local, `build/engine/e5c/`): a ball in play at Fenway at
frame 5,316 (first row); in the two-player game, frame 4,799 is player 1 pitching to D.
Eckstein, frame 19,837 the bottom of the first (2 out, 0-0), frame 22,690 the top of the
second, frame 31,942 the bottom of the second and frame 42,293 the top of the third (0-0,
1 out), where the game waits at the pitch menu once the script's pitch cycles end: two
full innings and part of a third in lockstep. The impaired run
(2,490 and 2,503 datagrams dropped, RTT 127 ms average) took 2 min 36 s for 5,600 frames,
70 s of it waiting.

**Evidence, browser** (`netplay_check.mjs`, two Chrome 155 pages through the local
server, D = 3, `--fast`; each page drives its own port from the script):

| Run | Frames | Guest line (both pages) = native | Windows equal | Desyncs | Gate misses | Poll stops (P1/P2) |
|---|---:|---|---:|---:|---:|---:|
| Two-player game, the first at-bat | 5,600 | `618ce8bc...` | 93 | 0 | 0 | 1 / 3 |
| Same, `--netsim 40,10,0.02` | 5,600 | `618ce8bc...` | 93 | 0 | 0 | 3 / 3 |
| Example pack on both pages (`--packs docs/examples/packs/fictional-league`); P1 picks the Lanterns | 4,420 | `a4b09126...` (= `mvp-play --pack`) | 73 | 0 | 0 | 1 / 0 |

Both pages' last frames: the first run shows the first at-bat (St. Louis at Boston, count
0-1, the pitch menu); the pack run shows the **Harbor City Lanterns' Defensive Lineup**
(J. Falkenrath CF ... D. Arkwright C) on both screens, as E6 saw natively.

**Tests.**
- Data-free: the synthetic program (`translator/tests/synth.h`) gained a function at the
  frame poll's address, called four times in a row with no stopping safe point between
  the calls; `test_emit_lockstep` (C++ emitter) and `test_wasm_lockstep` (wasm emitter,
  under Node) run it with an input source that makes every poll wait once: four stops,
  and the same polls (frame, instruction count, input), registers, instruction count and
  results as without stops (`runtime/tests/poll_stop.h`). Without the emitter's check the
  native case fails (two polls lost). `test_input`: a refused poll consumes nothing.
  `test_net_driver`: `before_poll` stops the run when the input is missing, not inside an
  interrupt handler, and goes on once it arrived.
- Local (the disc): `local_netplay_lockstep` now plays the two-player path into the
  match's loading, to frame 3,050, with player 2's host sleeping 20 ms after each poll
  of frames 2,905-3,045 (`mvp-netplay --stall-*`, a slow machine; the guest cannot
  tell): player 1 then waits at every one of those frames, so its run must stop at the
  loading's fast poll, and the test requires it (one stop in each of three runs; 48 s).
  `local_netplay_lossy` plays the same over a slow, lossy link (10% loss, 20 ms + 0-10
  ms; 73 s). Before the fix, the same path missed the gate in both runs tried.
- `ctest` natively, the local tests included: 44 tests, 43 passed, `local_disasm` skipped
  (no dtk listing); under Emscripten (Node): 33 tests, 30 passed, 3 local ones skipped.

## Next step

1. **Deploy on the owner's VPS** (the two-network exit). Ready: `build/engine/deploy/
   mvp-netplay.tar.gz` (from `node engine/server/tools/package.mjs`) and
   `deploy/install.sh` (NETPLAY.md §6). Access needed, all of it from the owner:
   - SSH to the VPS as root (or a sudo user): host name or IP, user, and a key or password
     for the agent's session; Debian 12 or Ubuntu 24.04, with ports 80, 443, 3478 (UDP
     and TCP) and 49160-49200/UDP reachable (the provider's firewall too);
   - a domain or subdomain with an A record pointing at the VPS (or the DNS login to
     create one);
   - nothing about the site password: the owner creates it in the browser on the first
     visit (E5b; NETPLAY.md §6 step 3), so the agent never handles it;
   - consent to copy the owner's disc image to `/srv/mvp/disc/` on that VPS (the
     2026-10-14 hosting rule allows it on the private deployment), done after the owner
     has created the password; the brother can instead pick his own image.
2. Then: the owner and his brother open the site, log in, one creates a game and sends
   the link, both pick the disc; netplay starts at power-on and, since E5c, plays into
   the match (Select Team: player 2 moves its controller to the other side; both advance
   their sides). Playing a whole game well needs the in-game speed in the browser (E3's
   area); netplay itself has no game-specific code.
3. Later: suggest the delay from the measured round trip before the game starts;
   rollback after K5.

## Decisions to record (for the lead)

- **E5-N1, netplay protocol v1** (`docs/engine/NETPLAY.md` §2, `engine/net/protocol.h`):
  HELLO/INPUT/BYE datagrams with the `MN` header and a major version; inputs are
  PadState v1 per port; every datagram repeats all unacknowledged inputs; the handshake
  refuses any difference in engine build, disc identity v1, pack-set hash, settings
  string, CLK1/DVD1 constants or desync window. A versioned engine API.
- **E5-N2, lockstep rules:** frames are frame polls; input delay D (2-4, the larger
  proposal wins); the local pad is sampled when the frame can run (D > 0); the run loop
  gates `rt::run()` on the next poll's input and yields early after a poll whose
  successor is missing; a poll without its input stops the run (never happened).
  Amended by E5c: a poll whose input is missing stops the run right there, before it
  consumes anything, and the host loop waits (`NetplayDriver::before_poll`,
  `YieldingHooks::stop_before`); "gate missed" remains only for a poll that cannot stop
  (inside an interrupt handler; never seen).
- **E5-N4 (E5c), stopping at a hook:** a Before hook (`runtime/hle.h`) may stop the run:
  the C++ and wasm emitters check `g_unwinding` right after it, the function returns
  unwinding, and the next `rt::run()` enters it afresh with the repeated entry safe
  point skipped (as for E2's host yields). The input source API gains `before_poll`
  (`runtime/input.h`). The guest runs the same instructions with or without stops
  (data-free: `poll_stop.h` in `test_emit_lockstep` and `test_wasm_lockstep`). The
  netplay wire protocol is unchanged (version 1).
- **E5-N3, desync detection:** striped XXH64 of MEM1 over K = 60 frame windows (1/60 of
  MEM1 per frame), window hashes exchanged; a mismatch stops both sides; local text
  diagnostics only (slice hashes, never memory).
- **E5-S1, VPS stack:** Node 24 + `ws` behind Caddy (TLS), coturn with time-limited
  REST-API credentials; one shared password, HttpOnly session cookie; the disc route
  `/config.json` + `/api/disc/image` as agreed with E2c.
- **E5-S2, first-run password setup (E5b):** the site password is created by the owner in
  the browser (`/setup`), never passed to install or handled by an agent. Salted scrypt
  (N=2^17, r=8, p=1) in a state file; open for 48 h (configurable) after the server first
  starts without a password, then closed until an operator deletes the state file; 404 for
  ever once a password exists; `MVP_PASSWORD` still wins (tests, CI). Residual risk:
  first come, first served in the window (NETPLAY.md §5).
