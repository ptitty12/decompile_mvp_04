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
| 3 | `engine/server/` (TypeScript): password gate, disc route, lobby, signaling, TURN config | |
| 4 | Browser: data channel transport, lobby UI, two-browser lockstep test, latency and bandwidth | |
| 5 | `docs/engine/NETPLAY.md` | |

## How to build and run (agents)

- Native (`msvc` preset, `engine/tools/msvc.cmd`, as in E0B_LOG): `cmake --build --preset msvc -j 8`
  builds `engine_net` and its tests (`test_net_protocol`, `test_net_session`, `test_net_udp`;
  data-free, in `ctest`). With `MVP_DISC` set at configure time it also builds `mvp-netplay`
  and the local test `local_netplay_lockstep` (label `local`).
- `engine/net/tools/lockstep.cmake` runs two `mvp-netplay` peers at once plus the solo
  reference: `-DFRAMES=N -DDELAY=D -DIMPAIR="--loss P --latency MS --jitter MS" -DPORT=N`,
  or `-DDESYNC=1` for the desync path. Logs and reports stay under `build/`.

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
