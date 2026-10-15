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
