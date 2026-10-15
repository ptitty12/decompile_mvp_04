# Netplay (E5)

How two players on different networks play each other: each runs the game in
their own browser, the two engines exchange controller inputs in lockstep over
a WebRTC data channel, and the owner's VPS serves the site behind a password,
runs the lobby and signaling, and relays traffic for players whose networks
need it. Design: `docs/ARCHITECTURE.md` §8. Working log and evidence:
`docs/engine/E5_LOG.md`.

```
 player 1's browser                                         player 2's browser
 page: lobby UI, RTCPeerConnection  <--- WebRTC data channel --->  page
   | datagrams (postMessage)              (direct, or via TURN)      |
 Worker: engine (wasm) + engine/net session                       Worker
                         \                                    /
                          \--- WebSocket: lobby + signaling ---/
                                  owner's VPS (engine/server):
                                  Caddy (TLS) -> mvp-server (Node), coturn (TURN)
```

Only controller inputs, acknowledgements and state hashes cross the network.
Nothing game-derived does: each browser reads its own disc (or, on the owner's
private deployment only, the owner's image from the password-protected disc
route), translates the game itself, and keeps any diagnostic dump local.

## 1. Lockstep

- **Frames** are the game's frame polls (the entry of fn_8014865C, E0c-IN1),
  numbered from power-on. Both browsers boot the game identically and play from
  power-on: menus, intro and all.
- **Ports.** Player 1 drives controller port 1, player 2 port 2; ports 3 and 4 are
  empty. Both player ports are connected from power-on (the boot input is
  `neutral_input(0x3)` on both sides).
- **Input delay D.** The local pad sampled when the game reaches frame F becomes
  the input of frame F + D. Frames 0 .. D-1 have neutral input on both ports. Each
  player proposes D (2, 3 or 4 in the lobby; the creator's choice is shown to the
  joiner); the session uses the larger proposal.
- **The gate.** A frame runs only when both ports' inputs for it are known. The
  engine's run loop is unchanged except for this check (`net/driver.h`):
  `rt::run()` returns at every VI field (host yields, `runtime/host_yield.h`), and
  the host loop calls it only while `NetplayDriver::may_run()` is true. After each
  frame poll, if the next frame's input is still missing, the driver asks the run
  to yield at its next safe point, so the gate is checked before that poll. A poll
  that arrived without its input would stop the run ("gate missed") rather than
  guess; it has never happened (0 in every measured run).
- **Sampling.** With D > 0 the local input of frame F + D is sampled when frame F
  can run: a player who waits for the other samples the pad when the wait ends, so
  both players' input latency is D frames. With D = 0 the input is sampled before
  waiting (otherwise both would wait forever).
- **Bounded lead.** A peer at frame F has sent its inputs up to F + D - 1, so neither
  peer can get more than D frames ahead of the other, and they never deadlock.
- **Desync detection.** Each side hashes MEM1 in a striped way (`net/state_hash.h`):
  at frame f it hashes slice `f mod K` of MEM1 (K slices) with the frame number and
  the instruction count, chained into a window hash that closes at `f mod K = K - 1`
  (K = 60: one window per second of play, 400 KB of hashing per frame). Window
  hashes are exchanged and compared; a mismatch stops both games at once. Each side
  can then show (and save locally) a text diagnostic: the session state, the recent
  inputs, the window hashes and the 60 slice hashes of the last window (two players'
  diagnostics show which 400 KB of MEM1 differ). Diagnostics hold numbers only, never
  memory contents, and are never uploaded.
- **Disconnects.** A peer silent for 10 s ends the session ("stopped answering").
  Leaving the page sends a goodbye. A running game cannot be rejoined (that needs
  save states, K5).

Host time decides only *when* datagrams are sent and when a frame becomes ready,
never what a frame's input is: both peers' guests see exactly the same inputs at
the same frame polls, whatever the network does.

## 2. Wire protocol (version 1)

Datagrams over an unreliable, unordered channel (`RTCDataChannel` with
`ordered: false, maxRetransmits: 0`, negotiated id 0; UDP in native tests). All
integers big-endian. Every datagram starts with a 4-byte header:

| Offset | Size | Field |
|---:|---:|---|
| 0 | 1 | `0x4D` (`M`) |
| 1 | 1 | `0x4E` (`N`) |
| 2 | 1 | protocol major version: 1 |
| 3 | 1 | type: 1 HELLO, 2 INPUT, 3 BYE |

A datagram that does not parse exactly (wrong magic or major version, wrong
length, reserved bits set, an unknown button, a disconnected pad with controls,
hash records out of order) is dropped and counted; it never changes the session.
`engine/net/protocol.{h,cpp}` is the reference implementation.

**HELLO** (handshake), repeated every 100 ms until the peer has seen it:

| Size | Field |
|---:|---|
| 1 | minor version (0) |
| 1 | player: 1 or 2 |
| 1 | flags: bit 0 = "I have received your HELLO"; other bits 0 |
| 1 | proposed input delay D |
| 2 | hash window K in frames (0: no desync check) |
| 2 | reserved, 0 |
| 8 | nonce (random per game instance) |
| 8 | seed proposal (player 1's is used; reserved for engine-side randomness, unused today) |
| 20 | disc identity (SHA-1, §3) |
| 32 | pack-set hash (SHA-256, `docs/MODDING.md` §10) |
| 4 | CLK1: CPU cycles per guest instruction (2) |
| 4 | DVD1: command latency in time-base ticks (40,500) |
| 4 | DVD1: transfer time in time-base ticks per KiB (13,184) |
| 1 + n | engine build id (n <= 64 bytes) |
| 2 + n | canonical settings string (n <= 512 bytes) |

The game starts only if the two HELLOs agree on the build id, disc identity,
pack-set hash, CLK1/DVD1 constants, settings string and K, and the players are 1
and 2. Otherwise both sides stop with the reason (for example "different disc
identities" or "both players chose player 1"). A side is running once it has the
peer's HELLO with flag bit 0 set, or any INPUT from it. A second HELLO with another
nonce means the peer restarted: the session ends.

**INPUT**, sent when a new local input is sampled, and after 20 ms without any send
(retransmission and keepalive):

| Size | Field |
|---:|---|
| 4 | ack_frame: the sender has every peer input before this frame |
| 4 | ack_hash: the sender has every peer hash record before this frame |
| 4 | cur_frame: the sender's next frame poll |
| 4 | send_ms: the sender's clock (wraps) |
| 4 | echo_ms: the latest send_ms received from the peer (0: none yet) |
| 4 | echo_hold_ms: how long the sender held echo_ms before this send |
| 4 | first_frame: frame of the first pad below |
| 1 | pad count n (<= 64; the sender uses at most 32) |
| ... | n pads: 11 bytes each (flags: bit 0 connected; buttons 2; stick x, y; C-stick x, y; trigger L, R; analog A, B: `runtime/input.h` PadState v1), or the single byte `0x80` when equal to the previous pad of this datagram (never for the first) |
| 1 | hash record count m (<= 8) |
| 12 m | records, ascending frames: frame (4), window hash (8) |

The pads are every input the peer has not acknowledged, oldest first, so a lost
datagram costs at most one resend interval. Round-trip time = now - echo_ms -
echo_hold_ms (it includes the time a datagram waits while the guest runs a field).

**BYE**, sent three times when a side stops:

| Size | Field |
|---:|---|
| 1 | reason: 0 quit, 1 desync, 2 rejected, 3 timeout, 4 error |
| 4 | desync: the window that differed; otherwise the sender's next frame |
| 1 + n | short text for the other player (n <= 200) |

**Versioning.** The protocol is a versioned engine API (CLAUDE.md). A change an
older peer cannot parse gets a new major version (and a migration note in
DECISIONS); minor versions may only add what older peers can ignore. Since the
build ids must match anyway, peers always run the same version today.

## 3. Identity

- **Engine build id** (browser): `web-` + the first 12 bytes (hex) of SHA-256 over
  `mvp-web.wasm`, `mvp-web.js` and `symbols.txt` as served (function boundaries are
  safe points, so the symbol map is part of the build). Native tools use their own
  id, so a native peer never matches a browser peer.
- **Disc identity v1**: SHA-1(`"mvp2005-disc-id/1\n"` + boot.bin (0x440 bytes: game id,
  revision) + BI2 (0x2000 bytes) + the FST bytes + the hex SHA-1 of `main.dol`). That
  is everything the boot environment copies into memory plus the code, and the same
  for ISO and CISO dumps of the disc. Other file contents are not hashed (that would
  read the whole 1.4 GB image); a damaged file would show up as a desync.
- **Pack set**: the ordered pack-set hash of `docs/MODDING.md` §10. The engine has no
  pack loader yet, so both sides send the empty set's hash
  (`f5e1298911db13adf522a1b34d4d4f9291b42fa7a77f63a5f6f07bc322dcc66e`).
- **Settings**: sorted `key=value` pairs joined by `;`: `aram_size`, `ax_voices`,
  `bus_clock`, `console_type`, `cpu_clock`, `pad` (PadState version), `ports`,
  `rtc_seconds`, `sram_flags`, `sram_language`, `tv_mode` (`net/identity.cpp`).

## 4. Lobby and signaling (JSON over WebSocket, version 1)

The page opens `wss://<site>/ws` (the session cookie and the site's Origin are
required). Types: `engine/server/src/lobby_protocol.d.ts` (shared with the page).

| Direction | Message |
|---|---|
| server -> page | `{t:"welcome", v:1, iceServers:[{urls:[...]}, {urls:[...], username, credential}]}` |
| page -> server | `{t:"create", name?, delay?}`: a new room, the creator is player 1 |
| page -> server | `{t:"join", room}`: join as player 2 (the invite link is `/?room=<id>`) |
| server -> page | `{t:"room", room, player, invite, delay, peer}` |
| server -> page | `{t:"peer", present}`: the other player joined or left the lobby |
| both | `{t:"signal", data}`: offer, answer or ICE candidate, relayed to the other player |
| page -> server | `{t:"list"}` / `{t:"leave"}`; server -> page `{t:"rooms", rooms}`, `{t:"error", code, message}` |

Player 1 makes the WebRTC offer when player 2 is present; both create the same
negotiated data channel. Once the channel is open the lobby is no longer needed.

## 5. The server (`engine/server/`)

TypeScript on Node 24 (D3), one dependency (`ws`), pinned in `package-lock.json`.

| Route | |
|---|---|
| `GET /login`, `POST /login`, `POST /logout` | the password gate: one shared password, an HttpOnly `SameSite=Lax` session cookie (`Secure` behind TLS), in-memory sessions (30 days), failed logins limited per address (10 per 15 min), no open redirects |
| `GET /healthz` | `ok`, without a login (monitoring) |
| `GET /config.json` | `{"disc":"/api/disc/image"}` when a disc image is configured, else `{}` |
| `GET`/`HEAD /api/disc/image` | the owner's image: `Accept-Ranges: bytes`, single ranges (206, or 416), `Cache-Control: private, no-store` |
| `GET /api/rooms` | open rooms |
| `/ws` | lobby and signaling (above) |
| anything else | the engine site (static, `Cache-Control: private, no-cache` + ETag) |

Without a session, a page load is sent to the login form and anything else gets
401. Every response has `X-Content-Type-Options`, `Referrer-Policy: no-referrer`
(invite links never leak through referrers) and `X-Frame-Options: DENY`; engine
pages have a Content-Security-Policy (same origin only, plus `wasm-unsafe-eval` to
compile the translated game). Secrets come only from the environment:
`MVP_PASSWORD`/`MVP_PASSWORD_FILE` and `MVP_TURN_SECRET`/`MVP_TURN_SECRET_FILE`.
Everything else: `MVP_SERVER_CONFIG` (JSON, `deploy/server.json.example`) or
`MVP_*` variables (`src/config.ts`).

**TURN.** coturn runs in its "TURN REST API" mode (`use-auth-secret`): the server
hands each page credentials derived from the shared secret (username
`<expiry>:mvp`, password base64 HMAC-SHA1), valid for 24 hours. No accounts are
stored, and leaked credentials expire.

Tests: `npm test` in `engine/server` (19 tests: the gate, sessions and limits, the
static site, the disc route, the lobby, signaling, TURN credentials), also run by
ctest as `server_node_tests`.

## 6. Deploying on a VPS

**Package.** `node engine/server/tools/package.mjs` (after building `mvp-web` and
`npm ci && npm run build` in `engine/server`) writes
`build/engine/deploy/mvp-netplay/` and `mvp-netplay.tar.gz`: `site/` (the engine:
no game data, the script refuses other file types), `server/` (compiled, with
`ws`), `deploy/` (install script and templates) and `MANIFEST.txt` (SHA-256 of
every file).

**Requirements.** A VPS with Debian 12 or Ubuntu 24.04, a public IPv4 address, root
SSH access, and a domain name (or subdomain) whose A record points to it. Open
ports: 80/tcp and 443/tcp (Caddy, HTTPS), 3478/udp and 3478/tcp (TURN), 49160-49200/udp
(TURN relay ports).

**Install** (an agent with SSH access does this; the owner runs nothing):
1. Copy `mvp-netplay.tar.gz` to the VPS and unpack it.
2. Copy the owner's disc image to `/srv/mvp/disc/GV4E69.ciso` (private deployment only).
3. `MVP_PASSWORD='<the password the owner chose>' ./deploy/install.sh <domain>` as root.
   It installs Caddy and coturn (distribution packages) and Node.js 24.18.0 (the
   official build, checksum verified), creates the `mvp` user and
   `/opt/mvp/{site,server}`, writes `/etc/mvp/{password,turn-secret,server.json,server.env}`
   (mode 0640, root:mvp), `/etc/caddy/Caddyfile`, `/etc/turnserver.conf` and the
   `mvp-server` systemd unit, opens the ports with ufw when present, and starts
   everything. Running it again updates the engine and keeps the secrets.
4. Check: `https://<domain>/` shows the login form; after logging in, "Create a
   game" gives an invite link; `curl https://<domain>/healthz` says `ok`.

**Updating the engine** later: build, package, copy, run `install.sh` again (both
players must reload the page: the build id changes).

## 7. Measurements (2026-10-14, one machine)

Details and the commands: `docs/engine/E5_LOG.md` §2 and §4.

- **Native, two processes over UDP** (`local_netplay_lockstep`, 1,200 frames, D = 3):
  both peers and the solo reference agree on every frame's input, all 20 window
  hashes and the final MEM1 SHA-1; also under 25% loss, 40 ms latency and 30 ms jitter.
- **Two browsers** through the server (two isolated profiles, login, lobby, invite
  link, direct connection), 1,200 frames: identical guest lines, equal to the native
  build's, and identical window hashes, zero desyncs and zero gate misses, for Chrome
  x2 at D = 2, 3 and 4 and for Chrome + Firefox at D = 3.
- **Input latency** (sampling the pad to the frame that uses it, menus, steady state):
  D frames of the game's pace plus about 1.5 ms, the same for both players:

  | D | local link | 40-50 ms one way, 2% loss (simulated) |
  |---:|---|---|
  | 2 | 38.5-39.2 ms, full speed | 57.8-58.1 ms, **36.8 frames/s**: the delay is shorter than the latency, both games wait |
  | 3 | 56.5-57.7 ms, full speed | 56.8-62.3 ms, full speed |
  | 4 | 74.6-75.4 ms, full speed | 75.6-76.3 ms, full speed, almost no waiting |

  "Full speed" is 54-58 frame polls per second, the game's own rate there (55.4 per
  guest second). Rule of thumb: D x 18 ms must cover the one-way latency plus about
  10 ms. D = 3 suits a round trip up to about 90 ms; longer distances need 4 or more.
- **Bandwidth per direction**: 2.6 KB/s of netplay payload on a local link, about
  4 KB/s at a 45 ms one-way latency (more unacknowledged inputs per datagram);
  5.5-9.5 KB/s through WebRTC's DTLS and SCTP; plus 28 bytes of IP/UDP per datagram
  (50-60 datagrams/s). A TURN relay carries the same.

## 8. What netplay relies on (DETERMINISM.md §6)

Lockstep is correct only if the same inputs at the same frame polls give the same
guest state on every machine and browser. It relies on:

- **R1** (virtual time base: no host clock in guest state), **R2** (VI retrace
  schedule), **R4** (interrupts at safe points, counted in instructions), **R5**
  (deterministic scheduler), **R6** (EA tick from the virtual clock): the guest's
  timeline is a function of the instruction count only. **R3**: the RNG seeds come
  from the virtual time base, so they are equal on both sides without a handshake
  seed.
- **R7** (DVD completes after a virtual delay) and the disc identity: both sides read
  the same bytes at the same virtual times. The DVD1 constants are in the handshake.
- **R8** (audio never feeds back: E3b's mixer is a read-only observer) and **R11**
  (GX events at defined points; the renderer only reads memory): rendering and audio
  output differ freely between machines.
- **R9**: no memory card is present (every EXI device but the IPL chip is absent), the
  same on both sides. **R10**, **R12**, **R16**: the VM region, the environment
  constants (in the settings string) and the power-on memory image are fixed.
- **R14** (E0c-IN1): input enters only at the frame poll, so only the per-frame input
  stream has to be agreed on. **R15**: exact arithmetic, identical in native code and
  in V8, SpiderMonkey and JavaScriptCore (E2: identical guest lines across browsers).
- E2's host yields are invisible to the guest; netplay's early yields are the same
  mechanism.

## 9. Limits and next steps

- **Rollback** (hiding the delay) needs fast save states (K5); lockstep pays D frames
  of input latency (D x 16.7 ms when a frame is one field).
- **No rejoin** after a disconnect, and no jump into a match from a save state (K5).
- **Pacing:** a player whose browser cannot keep up slows both games to its speed
  (lockstep). The intro movie runs below real time in every browser today (E2).
- **Browsers:** Chrome x2 and Chrome + Firefox (headless, so without rendering) were
  run; Edge is Chromium; Safari is untested (no Mac).
- **Not yet over the internet:** the server, TURN and the two-network exit need the
  VPS (E5_LOG, "Next step").
- **Memory card:** absent on both sides; saves in netplay come with K5 or later.
