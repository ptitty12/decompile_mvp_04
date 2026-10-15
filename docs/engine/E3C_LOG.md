# E3c log: a whole game, natively

Working log for the E3 exit, natively (`docs/ROADMAP.md`): a full 9-inning exhibition
against the CPU with no crash, sound playing and steady frame pacing. Newest state
first in "Status"; a later session resumes from "Next step". Builds and tests as in
E1/E3a (`engine/tools/msvc.cmd`, preset `msvc`, `MVP_DISC` set).

## Status (2026-10-15)

| # | Task | State |
|---|---|---|
| 1 | A whole game unattended | Done: 9 innings CPU vs CPU to "Game Over", no crash, deterministic |
| 2 | Fix what breaks | Nothing broke; the suspicious screens are not renderer bugs (traced below) |
| 3 | In-game speed | Done: 0.68x -> 1.12x over six minutes of play, 0.88x -> 1.41x on a lighter minute (headless, rendering) |
| 4 | Window mode | Done: keyboard on port 1, field pacing, statistics; heavy scenes still drop below 60 Hz |

### Exit evidence

- **A 9-inning game, to the end.** Power-on, menus by script, then CPU vs CPU from the
  first pitch: 193,020 frame polls, 5,173 s (86 min) of guest time, 310,069 VI fields,
  1.257 trillion guest instructions. The **Game Over** screen is captured at frame
  188,950 (field 306,000): Cardinals 18, Red Sox 11, "3 Out", line score STL
  0 0 5 0 0 0 4 8 1 - 18 R 30 H 1 E, BOS 0 0 0 0 4 2 0 0 5 - 11 R 16 H 0 E, WP M. Mulder,
  LP B. Arroyo, the menu Box Score / Rematch / Quit. 166 captures along the way
  (`build/engine/e3c/cap_game1/`, local only) show every inning: the score bug, the
  Green Monster scoreboard (inning 5 at frame 80,533), bullpen and batter intros,
  replays, the 8th (16-6) and the bottom of the 9th (18-9, 18-10, 18-11).
- **No crash**: the run ended by `--stop-file` at frame 193,020, after the game; 0
  WebGPU errors, 0 unknown GX commands.
- **Two identical runs**: the same script with the renderer (and audio) and without
  it: the MEM1 SHA-1, instruction count and time base agree at all **54 checkpoints**
  (`--hash-every 3600`, frames 0 to 190,800, the last one after Game Over; frame
  190,800: `a47ab3fb...`, 1,248,044,130,090 instructions, time base 208,007,355,015).
  A window session with live keyboard input replays headless from its recorded input
  to the same guest state (MEM1 `94f7d869...` at frame 9,800, below).
- **Audio active throughout**: 1,034,547 AX frames mixed, up to 24 voices; WAV of
  the whole run (5,172.7 s): every one of the 4,932 seconds from the first pitch on
  above -60 dBFS (median RMS -21.9 dBFS, 5th percentile -28.0, 95th -16.0), longest
  silent stretch in the game 0 s, per-minute medians -18 to -26 dBFS; 62 samples at
  full scale in 86 minutes.
- **Frame pacing** (window, `--pace`, mailbox present, sound on, in game): present
  intervals median 16.8-16.9 ms; mean 18.2-19.6 ms (51-55 presents per second);
  2-11% of intervals over 25 ms; 109 and 193 audio underruns in sessions of 4.9 and
  5.9 minutes. The host keeps the 59.94 Hz schedule whenever the emulation is ahead of
  it; in heavy stretches it is not (below).
- **Speed** (headless with rendering, in game): six minutes of play side by side
  0.68x -> **1.12x** (0.72x-2.04x per 20 s); one lighter minute 0.88x -> **1.41x**.

## 1. A whole game unattended

### CPU vs CPU: how

Play Now's team select does not advance with the controller in the middle (both
teams CPU: the "A Advance" prompt disappears). In the game, the pause menu's
**Select Controller** does: moving P1 to the middle and resuming asks "Are you sure
you want to change the Controller selection? You will not be able to earn MVP points
for this game if you continue." (Cancel / Ok); Ok gives a CPU vs CPU game that plays
itself with no more input (between-inning screens, replays and Game Over included).
Before that, a scripted human P1 (A every 20 frames) got stuck for 1,100 frames on a
ground ball (A throws home, X would throw to first) and gave up a run without an out,
so CPU vs CPU is the cheap way.

### Menu path and button script (frame = game frame poll, the number scripts use)

All taps are `tap 3` (held three frames) on port 1.

| Frame | Button | Screen |
|---:|---|---|
| 280, 430, 580 | START | skip the intro movie |
| 730 | START | title screen: PRESS START |
| 800, 860 | DOWN, A | memory card dialog: Continue without saving |
| 1300, 1360 | DOWN, A | user profile dialog: No; the main menu |
| 1500 | A | main menu: Play Now |
| 1900 | A | Select Team (Cardinals at Red Sox; P1 on the home team) |
| 2700 | A | uniforms |
| 2900 | A | difficulty (Pro); loading, then the pre-game |
| 5000 | START | Game Paused at the first pitch (cursor on Roster Options) |
| 5060, 5120, 5180 | DOWN x3 | Game Options, Box Score, Select Controller |
| 5240 | A | Select Controller (P1 under Red Sox) |
| 5320 | LEFT | P1 to the middle: both teams CPU |
| 5400 | START | resume: the confirmation dialog (cursor on Cancel) |
| 5480, 5540 | DOWN, A | Ok: CPU vs CPU from here, no more input |

The pause menu runs at 20 frames per second (three VI fields per frame poll).

### The run

`mvp-play --headless --input game.txt --frames 400000 --stop-file F --capture DIR
--capture-every 1800 --capture-from 12000 --perf-every 3600 --hash-every 3600
--audio-wav W` and, in parallel, the same with `--no-render` and no audio. New
`mvp-play` options for this: `--stop-file` (ends at a frame poll that `--frames`
reproduces), `--hash-every N` (guest checkpoints), `--capture-from N`; perf and hash
lines are flushed as they come so a long run can be watched.

Host time (the first speed-ups only, with up to two other `mvp-play` runs on the
machine): 4,161 s for the 5,173 s game with rendering (1.24x), 3,816 s for 8,626 s
without (2.26x).

### Observation: the game renders about 38 frames per second in play

From the first pitch to Game Over the game polls 183,172 frames in 291,600 VI fields
(0.63 per field). Game logic stays at 60 Hz (the frame loop runs up to three ticks
per frame, DETERMINISM §2.4), but each frame costs about 6.5 million guest
instructions, and E0b-CLK1 charges 2 cycles per instruction (243 million
instructions per guest second): about 27 ms per frame. Whether the console does
better is open (K4 asks whether gameplay renders at 30 or 60). `mvp-play --cpi N`
(new, experiments only) changes the charge; at 1 the menu script no longer fits
(the profile dialog is still up at frame 13,641), so the in-game rate at CPI 1 is not
measured yet. Changing CPI changes guest timing and the netplay contract: a decision
for the lead.

## 3. In-game speed

### Where the time went (host profile)

`mvp-play --host-profile N` (new, Windows) samples the emulation thread's instruction
pointer every millisecond and groups the samples by host function (translated guest
code as one bucket). In game (CPU vs CPU, fields 15000-19000, origin/main):

| Host function | Share |
|---|---:|
| `Hardware::reg` (CP/PI registers in a `std::map`) | 9.9% |
| translated guest code | 7.3% |
| `ppc::read32` | 6.3% |
| `std::map<u32,u64>::operator[]` (MMIO access counters) | 4.3% |
| `memmove` (vertex copies) | 4.3% |
| `GxProcessor::transform` | 4.2% |
| `fp::madd` | 3.8% |
| Dawn `RefCounted::Release`/`AddRef` (per-draw handle copies) | 4.9% |
| `GxProcessor::load_vertex`, `snapshot`, `primitive` | 4.9% |

Every 32-byte GX FIFO burst read and wrote several CP/PI registers through a map, and
every MMIO access counted itself in two more maps: 16% of the time.

### What changed

1. **Runtime: flat register arrays** (`runtime/hw.h/.cpp`): the registers
   0xCC000000-0xCC008FFF and the access counts are arrays; `write()` checks the
   write-gather pipe range first.
2. **Indexed draws** (`gfx/draw.h`, `gx_processor`, `wgpu/renderer`): each
   primitive's vertices are transformed once and sent with an index list; strips and
   quads no longer repeat vertices. The renderer draws with `DrawIndexed` from a
   per-pass index buffer (`baseVertex` places each run at a multiple of its stride).
3. **Packed vertices** (`tev_wgsl`): a pipeline's vertex holds only what its shader
   reads (`vertex_attrs`: the position, the colors the stages rasterize, the
   coordinates they sample, all coordinates when indirect stages run), 16-64 bytes
   instead of 144. Absent inputs are zero in the shader, as E1's zeroed `OutVertex`
   had them.
4. **Pixel-state reuse**: `GxProcessor` rebuilds the draw's pixel state (`snapshot`)
   only after a BP write (TLUT loads and preloads are BP writes); `DrawCall::state`
   names it. The renderer skips texture, sampler, pipeline and bind-group lookups for
   a draw with the previous draw's state in the same pass and texture epoch (93% of
   draws in game) and merges it without comparing the constants.
5. **Vertex formats unpacked once** per VCD/VAT change (attribute types, component
   formats, counts, fixed-point scales), the default matrix indices per primitive;
   the hot helpers are `inline` (MSVC's `/Ob1` inlines nothing else).

All of it keeps the same float operations in the same order: the in-game captures
are **byte-identical** before and after every step (10 captures, fields 13200-18600),
and the guest state is unchanged (MEM1 `d1847b23...` at frame 9000 every time). The
browser shares the renderer: `engine_gfx_wgpu` and the gfx tests build with the
Emscripten preset, and `test_gx_processor`/`test_tev_wgsl` pass under Node.

### Measurements

RTX 4070 SUPER, headless with the renderer, CPU vs CPU in game (fields 15000-18600,
60 s of guest time), with one other `mvp-play` running on the machine:

| Step | Host s | Real time |
|---|---:|---:|
| origin/main (E3a) | 68.0 | 0.88x |
| + flat hardware registers | 60.3 | 1.00x |
| + indexed draws, packed vertices, state reuse | 46.1 | 1.30x |
| + vertex formats unpacked once, inline helpers | 42.6 | **1.41x** |

Without the renderer the same build runs the game at 1.9-2.1x. Power-on to frame
9000 (title, menus, loading, 1.5 innings): 218.8 s -> 144.3 s of host time. The
mixer (`--audio-wav`) costs nothing measurable (1.41x with it).

A longer stretch, side by side (origin/main's renderer and runtime against this
session's, both running at once on the machine, headless with rendering, the same
script): six minutes of play (fields 14400-36000, 360 s of guest time) took 528.1 s
before and **320.5 s after: 0.68x -> 1.12x** (1.65 times faster). Per 20 s of guest
time the new build ranges from 0.72x to 2.04x (the old one 0.43x-1.35x): the average
clears 1.0x; the heavy stretches (many players and the crowd in view) do not.

What is left (profile after the changes): translated code and its memory and FP
helpers about 40% (`ppc::read32` alone 9.9%, not inlined under `/Ob1`; `fp::madd`
6.3%), the transform unit 5.7%, vertex loading 3.1%, the GX FIFO path in the runtime
about 6%, Dawn and the driver about 5%.

## 4. Window mode

`mvp-play` with a window now:
- reads the **keyboard** for port 1 with the browser's mapping (`web/src/input.ts`:
  Enter START, X A, Z B, C X, V Y, arrows D-pad, I/J/K/L main stick, Q L, E R, Space
  Z), merged with the script's input; it reaches the guest only at the frame poll;
- `--record-input FILE` writes port 1's input as the guest received it as an input
  script (the session replays headless);
- `--pace` shows each VI field at its own time (1001/60000 s apart, from a
  high-resolution waitable timer; Windows 11 ignores `timeBeginPeriod` for an
  occluded window and plain sleeps overshot by up to 15 ms) and presents in mailbox
  mode (never waits for the display); a late field runs at once, more than 100 ms late
  restarts the schedule;
- reports `pacing:` (present intervals, time waiting for the schedule and in
  present, late fields) from `--pacing-from FIELD`.

### Sessions (2026-10-15, keys posted to the window's handle by a helper script, held 120 ms)

- **Keyboard through the menus**: intro skipped by script, then Enter at the title,
  Down and X at the memory-card dialog; recorded as `808 press START`, `987 press
  DOWN`, `1107 press A` (7 frames each); the game went on to the profile screen.
- **A human-pitched game** (P1 = Red Sox, menus by script to the difficulty screen,
  then the keyboard: X every second from 230 s to 344 s, Enter at 300 s and 306 s to
  pause and resume): 89 A presses and two START presses reached the guest; the
  Cardinals scored twice in the 1st (Green Monster at frame 9,694; J. Damon fielding
  with the RELAY prompt). 327 s of guest time in 355 s; sound through SDL (WASAPI,
  44.1 kHz device), every second of play above -60 dBFS (median -24.0 dBFS), 193
  underruns. In game (fields 13000-19600): **6,606 present intervals, median 16.89
  ms, mean 19.60 ms (51.0 per second), sd 5.8 ms, p99 41.2 ms, 11% over 25 ms**;
  32.7 s spent waiting for the schedule, 2.8 s in present. The recorded input
  replays headless with no renderer to the same guest state (MEM1 `94f7d869...`,
  79,488,972,926 instructions at frame 9,800).
- CPU vs CPU, fields 14400-16725 (sound on): median 16.80 ms, mean 18.26 ms (54.8
  per second), 2.4% over 25 ms, 12.4 s waiting for the schedule.

Before `--pace` (FIFO present, the emulation blocking in present): CPU vs CPU 54 per
second without sound (29% of the thread in `ZwWaitForMultipleObjects`); the
human-pitched session 41 per second with sound and 349 underruns.

So the schedule holds whenever the emulation is ahead of it (half the in-game
fields wait), and heavy stretches fall behind: on average the thread needs about
12.6 ms per field in game, but not evenly. Steady 60 Hz everywhere needs more
speed in the heavy scenes (or a render thread, below).

## Suspicious screens

- **Logos, icons, white squares and black boxes in menus** (Select Controller: a
  black "home plate" over the Red Sox slot and two logos overlapping in the Cardinals
  slot; the pre-game matchup panel's logo slots; white or black squares in place of
  arrows and button icons; the defensive line-up, where six of nine plates show the
  player's photo stretched over the whole plate; team logos on grey boxes in the
  bullpen, Due Up and replay-wipe screens). **Not renderer bugs**: the GX stream
  itself pairs those textures with those positions and colors.
  - `--gx-log` (new) shows each UI quad as GXSetArray (the same vertex array,
    rewritten per quad) / XF matrix / BP texture (TexImage0/3 and a TLUT load from
    right after the texels) / draw / GXDrawDone.
  - `--trace-entry` on GXSetArray shows the positions the CPU wrote before each draw:
    the 16x16 C8 "up arrow" shape at 0x013D0440 is drawn at the Red Sox logo slot
    (387,119)-(521,208), the Boston logo (0x0144CBC0, 128x64 RGBA8) at the Cardinals
    slot; in the line-up the 128x128 CMPR photos get the whole plate's rectangle.
  - The white squares are an 8x8 C8 panel-fill texture that decodes to opaque
    (222,222,222); the black boxes are quads whose vertex colors are black, opaque.
  - So the game's own UI code picks those shapes, rectangles and colors: either the
    console does the same (an animation caught mid-way: the line-up plates fill in
    one by one) or guest state is off (EA's FE shape lookup, a CPU-semantics or data
    issue). The team-select screen before the game shows both logos correctly. Next
    step: trace EA's FE shape lookup (`SHAPE_*`, `ealib`) for the Select Controller
    logo slots, where the wrong shapes stay for seconds.
- **TMEM preloads** (GXPreLoadEntireTexture, BP 0x60-0x63) are now modeled: the
  game issues none up to the first pitch (nor in the sessions above), so they explain
  nothing here; the model is checked by `test_gx_processor`.
- Shadows: the game saves the EFB's top-left 128x128 to a texture, draws player
  shadows there, copies them to another texture and restores the corner from the
  first copy; EFB-copy textures handle it (seen in the Select Controller draw log).
- The pink batter (E3a) was not seen in this session's captures.

## Tests

- `test_gx_processor` (13 cases): indices and the pixel-state identity
  (`DrawCall::state` equal across CP/XF writes, new after a BP write, the rebuilt
  state equal to the reused one), TMEM preloads (I8 and RGBA8 banks, mip banks,
  out-of-range).
- `test_tev_wgsl`: the vertex layout (which attributes, the stride, the declared
  inputs, zeros for the others, indirect stages).
- `test_gfx_render` (GPU): two vertex-colored quads and a strip merged into one run
  of 32-byte vertices, a textured quad (28-byte vertices), another vertex-colored
  quad: pixels, merge and state-reuse counts, alignment padding, uploaded bytes.
- `ctest --preset msvc`: **43 of 43 pass** (rebased on origin/main `cebeac45`, E6
  included), the local ones with the disc and none skipped. The guest hashes are E3a's: `local_play_determinism` MEM1 `73e856d4...`
  (alone, rendered, yielding; 2,845,943,121 instructions), `local_netplay_lockstep`
  MEM1 `e46c01ed...` (10,857,210,189 instructions).
- Emscripten: `engine_gfx_wgpu`, `test_gx_processor` and `test_tev_wgsl` build;
  both tests pass under Node.

## Commits (branch `engine/e3c` on origin/main `cebeac45`, not pushed)

| Commit | What |
|---|---|
| `fb96296e` | engine(runtime): hardware registers in flat arrays |
| `4a303dfd` | engine(gfx): indexed draws, packed vertices, pixel-state reuse; `--host-profile` |
| `422062c8` | engine(gfx): TMEM preloads; `--gx-log`, `--stop-file`, `--hash-every` |
| `e73a4314` | engine(gfx): vertex formats unpacked once; small helpers inline |
| `a52cabd3` | engine(gfx): window keyboard on port 1, `--record-input`, pacing statistics |
| `da9b7790` | engine(gfx): GPU test for indexed draws, merged runs, mixed strides |
| `cd84c9e8` | engine(gfx): window field pacing (`--pace`, mailbox), pacing report, `--cpi` |
| (this log) | engine(docs): E3c log |

Rebasing onto E6 conflicted only in `mvp_play.cpp` (includes and the usage line:
E6's `--pack` and this session's options, both kept).

## For the lead (decisions to record; docs outside docs/engine/)

- **E3c-R1** (renderer contract): `DrawCall` carries each vertex once plus an index
  list and a pixel-state identity (`state`); backends may skip lookups for equal
  states. Vertex buffers hold only the attributes the shader reads
  (`vertex_attrs`/`vertex_stride` in `tev_wgsl.h`).
- **E3c-HW1** (runtime): hardware registers and MMIO counts in flat arrays; no
  behavior change.
- **E3c-CLK** (open question): with E0b-CLK1's 2 cycles per instruction the game renders
  about 38 frames per second in play (logic at 60 Hz). Measuring the console's rate
  (K4) and, if it is higher, lowering CPI would change guest timing and the netplay
  handshake.
- **E3 exit**: met natively for "9 innings, no crash, sound": CPU vs CPU after the
  first pitch (the game's own Select Controller; "against the CPU" with a human
  needs a player), and a keyboard-played window session. "Steady frame pacing" holds
  at the median (16.8-16.9 ms) but not in heavy stretches (mean 18-20 ms in game):
  record it as partially met.
- ROADMAP §3: E3's native exit evidence is in this log.

## Next step

1. **Steady 60 Hz in heavy scenes**: a render thread (the GX processor and the
   renderer behind a queue; the guest's GP sync points — draw done, PE tokens, FIFO
   reads — must wait for it, since the guest overwrites vertex arrays and textures
   right after its GXDrawDone), or inlining `ppc::read32`/the FP helpers in the
   translated code (`/Ob2` for `mvp_game_native`, measured against build time).
2. **The UI shape question**: trace EA's FE shape lookup for one wrong slot.
3. **CPI** (the 38 frames per second): a decision first.
4. The browser: the renderer changes apply there as is; measure its in-game rate.
