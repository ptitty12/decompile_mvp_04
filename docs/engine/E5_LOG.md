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

## How to build and run (agents)

- Native (`msvc` preset, `engine/tools/msvc.cmd`, as in E0B_LOG): `cmake --build --preset msvc -j 8`
  builds `engine_net` and its tests (`test_net_protocol`, `test_net_session`, `test_net_udp`;
  data-free, in `ctest`). With `MVP_DISC` set at configure time it also builds `mvp-netplay`
  and the local test `local_netplay_lockstep` (label `local`).
- `engine/net/tools/lockstep.cmake` runs two `mvp-netplay` peers at once plus the solo
  reference: `-DFRAMES=N -DDELAY=D -DIMPAIR="--loss P --latency MS --jitter MS" -DPORT=N`,
  or `-DDESYNC=1` for the desync path. Logs and reports stay under `build/`.
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
runtime file changed.

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
configuration, and `deploy/install.sh` (Debian 12 / Ubuntu 24.04). 19 Node tests.

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

## Next step

1. **Deploy on the owner's VPS** (the two-network exit). Ready: `build/engine/deploy/
   mvp-netplay.tar.gz` (from `node engine/server/tools/package.mjs`) and
   `deploy/install.sh` (NETPLAY.md §6). Access needed, all of it from the owner:
   - SSH to the VPS as root (or a sudo user): host name or IP, user, and a key or password
     for the agent's session; Debian 12 or Ubuntu 24.04, with ports 80, 443, 3478 (UDP
     and TCP) and 49160-49200/UDP reachable (the provider's firewall too);
   - a domain or subdomain with an A record pointing at the VPS (or the DNS login to
     create one);
   - the site password the owner wants the two players to type (or accept a generated
     one, which the agent hands over);
   - consent to copy the owner's disc image to `/srv/mvp/disc/` on that VPS (the
     2026-10-14 hosting rule allows it on the private deployment); the brother can
     instead pick his own image.
2. Then: the owner and his brother open the site, log in, one creates a game and sends
   the link, both pick the disc; netplay starts at power-on. To finish an exhibition game
   the engine must first reach and run one at full speed in the browser (E3a: speed and
   the front end to exhibition); netplay itself has no game-specific code.
3. Later: suggest the delay from the measured round trip before the game starts; a
   longer native lockstep run into gameplay when an exhibition script exists (E3a);
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
- **E5-N3, desync detection:** striped XXH64 of MEM1 over K = 60 frame windows (1/60 of
  MEM1 per frame), window hashes exchanged; a mismatch stops both sides; local text
  diagnostics only (slice hashes, never memory).
- **E5-S1, VPS stack:** Node 24 + `ws` behind Caddy (TLS), coturn with time-limited
  REST-API credentials; one shared password, HttpOnly session cookie; the disc route
  `/config.json` + `/api/disc/image` as agreed with E2c.
