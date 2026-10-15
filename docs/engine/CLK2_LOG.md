# CLK2 log: the virtual clock and the in-game frame rate

Side session `claude-side-clk2`, branch `engine/clk2`. The owner plays in Chrome and
finds the game "entirely unplayable, way too choppy" although the host keeps up at
about 1.0x. E3c's reading (`E3C_LOG.md`, open decision CLK2) was that at E0b-CLK1's
2 cycles per instruction the game renders only ~38 frames per second in play, so the
task was to calibrate the virtual CPU clock. Builds and tests as in E1/E3a
(`engine/tools/msvc.cmd`, presets `msvc`/`emscripten`, `MVP_DISC` set). Newest state
first in "Status"; a later session resumes from "Next step".

## Status (2026-10-15)

| # | Task | State |
|---|---|---|
| 1 | Rendered fps, ticks per frame and host cost at CPI 2.0-0.5 in a match | Done, natively. CPI was not the cause: the game already rendered ~59 fps in play at CPI 2; **30% of play time was multi-second freezes**, from a bug in the idle skip (below), fixed |
| 2 | The console's frame rate from public sources | Done: 60 fps by design, dips in heavy scenes reported, no reviewer describes freezes |
| 3 | Choose CLK2 | **1.25 cycles per instruction** (with the idle-skip fix): the heaviest play fits a 60 Hz frame with ~20% to spare |
| 4 | Apply it; handshake; tests | Done: `ClockConfig::cpi_milli = 1250`, the HELLO carries thousandths (CLK1 peers refuse), `test_clock` updated; ctest msvc 44/44, emscripten 33/33 |
| 5 | Chrome, before and after | Done: 41.8 -> 59.5 rendered fps, new frames shown 32.8 -> 47.9 per second, no game freezes; but the Worker now needs 14.7-19.7 ms per field on this (loaded) machine: the host is at its limit, present p95 still 36-53 ms. P2's render thread is now the bottleneck to clear |

**In short:** the game was not slow, it froze. E0b's idle skip treated six list-walk
loops as waits and jumped virtual time at every node they visited, so freeing memory
or tearing down a UI screen took seconds of guest time with nothing on screen (30% of
play, up to 10 s at a time, and a 69 s match load). With that fixed the game renders
~58-60 fps in play at any CPI up to 2; CLK2 = 1.25 then removes the remaining
CPU-bound drops in heavy scenes.

## 1. What E3c's 38 fps was

E3c divided frame polls by VI fields over the whole game (0.63 per field) and the
instruction count by frame polls (~6.5 million per poll). Both averages hide the
shape. With `mvp-play --perf-every 1` (new: XFB copies, the frame loop's tick count
`n` per poll read from `lbl_8061B884`, the instructions actually run, DVD commands),
origin/main at CPI 2, CPU vs CPU, five minutes of play (fields 15,600-33,600):

| | share of time | rendered fps | ticks per frame | CPU busy |
|---|---:|---:|---:|---:|
| frame loop running | 70% (210.7 s) | 58.5 | 1.04 | 74% |
| no frame poll for >= 6 fields ("stalls") | 30% (89.6 s) | 0.4 | - | 7% |

- When the game runs, it renders ~59 fps with one logic tick per frame. The ~6.5 M
  "instructions per poll" counted `c.ticks`, which includes the instructions the idle
  skip jumps over: it is 1/38 s of virtual time, not work.
- The low average comes from **55 freezes in five minutes** (median 26 fields, the
  longest 488 fields without a poll); the longest frozen pictures lasted 604, 583,
  521 and 505 fields (8-10 s); 22 lasted 0.5 s or more. During them the CPU is
  idle (7%) and the drive only reads its 16 KB audio stream every ~26 fields.
- Logic ran at 42.8 ticks per second on average: the game also ran at ~71% speed.
- **Changing CPI does not change this** (`--cpi 2 --cpi-switch 5600:X`, E3c's script
  to the CPU-vs-CPU confirmation, then CPI X, same window, headless with the
  renderer, two runs at a time):

| CPI | rendered fps | logic ticks/s | ticks per frame | polls with n > 1 | CPU busy | host s per guest s |
|---:|---:|---:|---:|---:|---:|---:|
| 2.0 | 41.2 | 42.8 | 1.039 | 2.2% | 54% | 0.89 |
| 1.5 | 42.6 | 43.6 | 1.024 | 0.6% | 42% | 0.92 |
| 1.25 | 42.8 | 43.8 | 1.023 | 0.6% | 35% | 1.31* |
| 1.0 | 42.9 | 43.9 | 1.023 | 0.6% | 28% | 0.99 |
| 0.75 | 43.0 | 44.0 | 1.023 | 0.6% | 21% | 1.29* |
| 0.5 | 43.0 | 44.0 | 1.023 | 0.6% | 14% | 1.02 |

(* overlapped a build.) Lowering the clock only removes the few heavy frames; the
freezes stay.

## 2. The freezes: the idle skip took list walks for waits

`mvp-play --threads-at` (new: the OS threads, the queue each sleeps on, PC, LR and
the stack's return addresses) during a freeze: the main thread is **running**, in
`MEM_free -> FREE_add`, from the UI teardown (`fn_800EC704`, under the process
update `fn_803289C0`). `FREE_add` inserts a block into EA's sorted free list with
two 3-instruction loops:

```
L1: lwz r8, 0x14(r8)   cmplw r4, r8   blt L1
L2: lwz r3, 0x10(r3)   cmplw r4, r3   bgt L2
```

The translator's CFG marked both as pure spins (at most 4 instructions, only loads
and compares; E0b item 9), so at every taken back edge the runtime jumped virtual
time to the next hardware event (VI line, audio, DVD, decrementer). A walk over N
free blocks cost N event jumps instead of 3N instructions: seconds of guest time with
the CPU idle.
Six of the 13 "idle spins" were such walks (FREE_add x2, a find-last-node loop at
0x80171704, three in the animation goals at 0x8027D2E8-0x8027D334).

**Fix** (`translator/cfg.cpp`): a spin also has to read the same addresses on every
pass (no load writes a register that a load addresses with). The 7 left are real
waits: SelectThread's idle loop, two in `__AI_SRC_INIT`, the AX init wait, EA's GX
ring `bne .` and two EA `b .` hangs. `test_translator_cfg` has a list walk (not
idle) and an indexed spin (idle).

Effect at CPI 2 (CPU vs CPU, fields 7,800-33,600, 430 s of play): **58.3 fps,
60.4 logic ticks per second**, one CPU-bound pause of 36 fields left (a scene
change at 100% busy), the longest frozen picture 43 fields. Power-on to the first
poll 409 fields (590 before), the **match load 510 fields (8.5 s) instead of
4,148 (69 s)**, power-on to the first pitch 6,424 fields instead of 12,870. Frame-keyed
input scripts need re-timing (they are in the session scratch: `game_fix.txt` at
CPI 2, `game_125.txt` at CPI 1.25; menu path below).

## 3. The CPI sweep with the fix

`--cpi 2 --cpi-switch 5600:X` with `game_fix.txt`, fields 7,800-33,600 (430 s of
CPU vs CPU), headless with the renderer, a perf line every field, three or four
runs at a time (host numbers are therefore noisy):

| CPI | rendered fps | logic ticks/s | ticks per frame | polls with n > 1 | seconds < 55 fps / < 50 | CPU busy p50 / p95 / max (per second) | longest frozen picture | host s per guest s |
|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| 2.0 | 58.3 | 60.4 | 1.035 | 2.03% | 57 / 29 | 74 / 91 / 97% | 43 fields | 1.27 |
| 1.5 | 59.5 | 60.5 | 1.017 | 0.37% | 14 / 2 | 56 / 80 / 98% | 31 | 1.29 |
| **1.25** | **59.6** | 60.6 | 1.016 | 0.30% | 12 / 1 | 46 / 67 / **81%** | 26 | 1.30 |
| 1.0 | 59.7 | 60.6 | 1.016 | 0.17% | 7 / 1 | 37 / 54 / 66% | 21 | 1.45 |
| 0.75 | 59.8 | 60.7 | 1.015 | 0.09% | 2 / 1 | 28 / 41 / 49% | 16 | 1.47 |
| 0.5 | 59.9 | 60.8 | 1.015 | 0.07% | 1 / 1 | 19 / 27 / 33% | 11 | 1.52 |

The same at the new default from power-on (`game_125.txt`, fields 6,900-33,600,
445 s of play): 59.6 fps, 60.6 ticks/s, 0.23% polls with n > 1, no second below
50 fps, busy max 85%. Two serial runs from the same state (60 s of play, fields
7,800-11,400, nothing else of this session running): host 1.24 s per guest second at
CPI 2 (59.3 fps) and 1.38 at 1.25 (59.7 fps); other agents loaded the machine
(~40% CPU), so the difference is within its noise. Host cost per guest second in play
is set by the frame and tick rates (now 60 and 60), not by the charge.

- At CPI 2 the heavy stretches (the between-innings defensive line-up over the
  stadium, some fielding plays) run at 100% busy and drop every 4th-5th frame for up
  to 8 s (60 n=2 polls in 474 fields at one inning break).
- At 1.5 three such episodes remain (5 drops each) and the busiest second is 98%.
- At 1.25 no second is CPU-bound (max 81%); the drops left are single frames at scene
  changes (more polls than copies: the game skips rendering a few frames after a
  load, by design), and one CPU-bound 22-field pause at a scene change (36 at CPI 2,
  16 at 0.75: real work that scales with the clock).
- Below 1.25 the gain is small (transition frames only) and the guest CPU gets
  faster than any plausible Gekko.

## 4. The console

- **The game's design** (DETERMINISM §1.1, §2.4-2.5): 60 Hz logic, one retrace wait per
  rendered frame, full-rate video modes, up to 3 catch-up ticks per frame. A game
  built this way is meant to render 60 fps and to degrade gracefully in heavy scenes.
- **Reviews** (paraphrased): Worth Playing's GameCube review (March 2005) calls the
  animation jumpy at times, mainly in some fielding sequences; a GameSpot user review
  (platform not stated) reports frame-rate drops with runners on base while pitching,
  rarely at bat, varying by stadium; GameSpot's review says the animation is smoother
  than MVP 2004 and that transitions to cutaways and replays no longer stutter;
  Nintendo World Report (GameCube) finds the players well animated in motion. No
  source describes multi-second freezes between plays or a game running generally
  near 40 fps. (worthplaying.com/article/2005/3/23/reviews/23378-gamecube-review-mvp-baseball-2005/,
  gamespot.com/mvp-baseball-2005/user-reviews/2200-220698/,
  nintendoworldreport.com/review/4371/mvp-baseball-2005-gamecube; IGN and GameSpot's
  review pages refused automated fetches.)
- **Emulation**: a Dolphin forum thread (forums.dolphin-emu.org/Thread-mvp-baseball-2005)
  reports 53-60 fps in emulation (weak evidence: settings and scenes unknown).
- **The CPU**: Gekko 486 MHz, two instructions per cycle at best; game code reaches
  roughly 0.7-1 instruction per cycle, so 1-1.5 cycles per instruction. 1.25 is in that
  range; 2 is pessimistic.
- Not modeled: the GPU's own time (GX1: infinitely fast). On the console heavy scenes
  may also have been GPU-bound, which fits the reviewers' dips. With 1.25 the emulated
  game is, if anything, a little smoother than the console in its heaviest scenes.

## 5. Decision CLK2

**The time base advances 1.25 CPU cycles per guest instruction**
(`rt::ClockConfig::cpi_milli = 1250`, 388.8 million instructions per guest second),
**together with the idle-skip fix** (§2), which is what removes the freezes.

- The smallest charge change that makes the heaviest play fit a 60 Hz frame with a
  margin (81% busy at worst in 430 s of play; 1.5 still reaches 98%).
- Within the Gekko's plausible range; 1.0 would buy only a few transition frames.
- The netplay HELLO's clock field carries thousandths of a cycle (1250). E0b-CLK1
  builds sent 2 in the same 4 bytes, so CLK1 and CLK2 builds refuse each other
  ("different engine timing constants (CLK2/DVD1)"); the web build ids differ anyway.

### What does not change with the charge

Every device event is scheduled in time-base ticks, so only the CPU's own work
speeds up:

- **Audio**: AI sample counting and the DSP's AX frames are time-base events. Two
  minutes at CPI 2 and 1.25: 23,974 and 23,977 AX frames mixed (199.5 per guest
  second), 32 kHz both.
- **DVD1**: 1 ms latency + 3 MiB/s, in time-base ticks (`HardwareConfig`), unchanged.
- **Decrementer, OS alarms, the 60 Hz EA timer**: the decrementer counts the time base;
  `test_clock` (decrementer delivery, the idle skip) passes at the new default with its
  expected counts updated (17 decrementer interrupts in 200,000 instructions instead
  of 27; three idle waits of 11,530 instructions instead of 7,206).
- **Loading**: CPU-bound parts get faster in guest time, DVD-bound parts do not.
  Power-on to the first frame poll: 590 fields before (CPI 2), 409 with the fix at
  CPI 2, 337 at 1.25. The match load (difficulty A to the pre-game): 4,148 fields
  before, 510 with the fix at CPI 2, **430 (7.2 s) at 1.25**. Only the intro's poll
  count depends on the charge (its movies decode at full rate at 1.25, not at 2):
  after the title the menu path keeps its spacing (§ Menu path).

## 6. Exactness and tests

- `--cpi 2` reproduces E0b-CLK1 exactly: 700 fields MEM1 `73e856d4...` as in WEB.md,
  and E3c's game script gave the same `33f593e3...` at 33,600 fields in two runs.
- At the new default (`game_125.txt`, 33,600 fields, `--hash-every 3600`): the run
  with the renderer and the run without agree at all 10 checkpoints (frames 0 to
  32,400; frame 32,400: 215,696,322,669 instructions, time base 22,468,366,944, MEM1
  `dbfbc8ea...`); the game code at `/Od` agrees at the 6 checkpoints it reached
  (frames 0 to 18,000; stopped there for the Chrome runs).
- New guest lines for WEB.md's checkpoints (native `/O2`; the menus line also at
  `/Od` and with `--yield`; Chrome 155 equal at 700 and 3,600 fields):

| Run | Guest line |
|---|---|
| 700 fields, no input | 4,547,010,125 instructions, time base 473,646,888, 360 polls, MEM1 `53221c4a...` |
| 2,400 fields, START at 280/430/580/730 | 15,574,026,125, 1,622,294,388, 1,882 polls, MEM1 `4285f135...` |
| 3,600 fields, the `menus` script | 23,357,802,126, 2,433,104,388, 2,747 polls, MEM1 `40a7692d...` |

- The Chrome match session below ends where native `mvp-play --no-render` does
  (11,600 fields: 75,249,642,125 instructions, MEM1 `d8c30e9a...`); the "before"
  session twice gave the same line (`5ba8abf7...` at 19,600 fields).
- `ctest --preset msvc`: **44/44** (the local tests with the disc, none skipped);
  `local_netplay_lockstep`/`lossy` run both peers on the new clock.
  `ctest` for the Emscripten tree: **33/33** (`local_disasm` skipped as before).
  Unit tests: `test_clock` (a fractional charge, a change of charge mid-run, the
  default's decrementer and idle-skip counts), `test_net_protocol` (the identity
  follows `rt::ClockConfig`; a CLK1 value of 2 is refused both ways),
  `test_translator_cfg` (a list walk is not idle, an indexed spin is).

## 7. Chrome

Chrome 155 headed, Playwright, the owner's CISO picked as a file, paced from the
field the window starts (`browser_check --fast-until`), `--trace-present`,
`--screencast F:3000`. Before = origin/main `05be18d1` (CPI 2, old idle skip) with
E3c's CPU-vs-CPU script, fields 16,000-19,600; after = this branch with
`game_125.txt`, fields 8,000-11,600 (both 60 s of CPU-vs-CPU play). Other agents
loaded the machine throughout (30-46% CPU); the two pairs were taken under lighter
and heavier load. `chrome_measure.py` in the session scratch (P1-gfx's numbers
reproduced from its own summary: p95 27.5 ms, 7.5% over 25 ms).

| | speed | Worker ms per field (mean; p90 of 0.5 s windows) | rendered fps (XFB copies per guest s) | new frames shown per s | presents p95 | presents > 25 ms | new-frame gaps > 100 ms (longest) |
|---|---:|---:|---:|---:|---:|---:|---:|
| before, lighter load | 0.94x | 11.6; 20.0 | 41.8 | 32.8 | 38.6 ms | 20.9% | 9 (8.4 s) |
| after, lighter load | 0.98x | 14.7; 18.3 | **59.5** | **47.9** | 36.4 ms | 22.5% | 2 (3.6 s*) |
| before, heavier load | 0.84x | 14.5; 27.2 | 43.3 | 25.7 | 55.2 ms | 35.4% | 9 (8.4 s) |
| after, heavier load (fields 11,600-15,200) | 0.81x | 19.7; 24.0 | **59.6** | **31.9** | 53.1 ms | 62.2% | 3 (0.15 s) |

(* one 3.6 s pause with no presents *and* no stats from the page while the emulation
kept its speed: a browser-side stall. Such 2-3.6 s stalls showed up in the runs of
both builds, once each at most; they are not the game.)

- The game's freezes are gone in the browser too: before, nine gaps over 0.1 s per
  minute without a new picture, the longest 8.4 s; after, the longest gap the game
  makes is 0.15 s.
- Rendering 60 instead of ~42 frames a second, with logic at 60 instead of ~43 Hz,
  costs the Worker 27-36% more per field. On this machine, with other agents
  running, that puts it at its limit: 0.98x in the lighter pair (presents p95
  36 ms), 0.81x in the heavier one (two fields per present more than half the
  time). The old build only looked cheaper because it spent 30% of the time frozen.
- A 6 s V8 profile of the after build in play (`--trace 9000:6000`): the Worker is
  96% busy; mvp-web.wasm (runtime, GX processor, renderer) 45.6%, translated game
  code 42.8%, WebGPU calls from JS (`writeBuffer`, ...) 6.4%, idle 3.8%. P1-gfx's
  breakdown puts the GX path and WebGPU at about a third of the Worker; a render
  thread that takes them (P2) brings the emulation thread to ~10 ms per field here,
  which is what steady 60 Hz needs with margin.
- **The charge is not the lever for host smoothness**: with the fix, CPI 2 and 1.25
  render the same ~60 fps in play (CPI 2 only drops frames in the heaviest scenes),
  and the serial native runs cost the same within noise. Raising CPI to make the
  game render fewer frames would bring back the choppiness by design. So CLK2 = 1.25
  now; the host side is P2's render thread.

## Menu path at CPI 1.25 (frame = game frame poll)

The intro now polls up to 60 times a second, so the title comes at frame ~1,040
instead of ~730 (E3a/E3c's script presses START at 730 and misses it). All taps
`tap 3` on port 1:

| Frame | Button | Screen |
|---:|---|---|
| 280, 430, 580 | START | skip the intro movies |
| 1100 | START | title screen (up from frame ~1,040) |
| 1170, 1230 | DOWN, A | memory card dialog: Continue without saving |
| 1500, 1560 | DOWN, A | user profile dialog: No |
| 1700 | A | main menu: Play Now |
| 2100, 2900, 3100 | A | Select Team (Cardinals at Red Sox), uniforms, difficulty; then the match load |
| 5200 | START | Game Paused at the first pitch |
| 5260, 5320, 5380, 5440 | DOWN x3, A | Select Controller |
| 5520, 5600 | LEFT, START | P1 to the middle; the confirmation dialog |
| 5680, 5740 | DOWN, A | Ok: CPU vs CPU from here (field ~6,900) |

At CPI 2 with the fix the same path works with the title at 900 (everything after it
200 earlier).

## Commits (branch `engine/clk2`, on origin/main `05be18d1`, not pushed)

| Commit | What |
|---|---|
| `a93d0309` | engine(runtime,net): the clock charge in thousandths of a cycle; the handshake carries it |
| `229a0f07` | engine(gfx): mvp-play `--cpi X`, `--cpi-switch F:X`, frame statistics, `--threads-at` |
| `ef95b486` | engine(translator): a list walk is not an idle spin |
| `6b526bac` | engine(runtime,net): CLK2, 1.25 cycles per instruction |
| (this log) | engine(docs): CLK2 log; NETPLAY's HELLO table; WEB.md's checkpoints |

Files outside the clock model: `translator/cfg.cpp` (one hunk, the idle-spin rule),
`gfx/tools/mvp_play.cpp` (tooling), `net/protocol.*`, `net/identity.cpp`,
`net/session.h` (the clock field). Nothing in `web/`, `gfx/` proper or P2's files.

## For the lead (decisions to record; docs outside docs/engine/)

- **CLK2** (replaces E0b-CLK1): the time base advances 1.25 CPU cycles per guest
  instruction; `ClockConfig::cpi_milli` (thousandths) is part of the netplay
  handshake; CLK1 and CLK2 peers refuse each other.
- **E0b-IDLE2** (amends E0b item 9): an idle spin must read the same addresses on
  every pass; list walks run normally. It removed the multi-second freezes and most
  of the 69-second match load.
- DETERMINISM §1.1 stands (60 fps nominal); E3C_LOG's 38 fps observation was the
  freezes, not the clock.
- WEB.md's guest-line checkpoints change with both (new values in §6).

## Next step

1. **Merge before P2 measures.** P2's render-thread numbers should be taken on this
   branch: the old build's freezes made it look 30% cheaper per field than a game
   that actually runs. Input scripts keyed by frame need re-timing (the menu path
   above; E3c's and P1's scripts no longer reach a match).
2. **P2's render thread** is now what stands between the owner and smooth play in
   Chrome (target: the Worker under ~11 ms per field in heavy play).
3. The owner's deployment: rebuild and redeploy once merged; the translated-module
   cache key changes with the engine, so players translate once more.
4. Optional: re-run E3c's 9-inning game on the new clock (it should take far less
   than 86 minutes) and the human-pitching session; check Firefox.
