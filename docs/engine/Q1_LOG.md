# Q1 log: the flashing in the front end, and the picture

Side session `claude-side-q1`, branch `engine/q1-visual` (from origin/main
`1ab1dd27`: the render thread, CLK2, P1-G1's scan-out; origin/main's Q3
controllers merged in at `755f6a8e`). After that deploy the owner reported "I
am still getting flashes when I am on the home page, or intro" and "graphics
aren't great". Chrome 155 headed on this PC (i7-14700K, RTX 4070 SUPER,
3440x1440 at 59 Hz), Playwright, the owner's CISO picked as a file; other
sessions shared the machine (load noted per run). Captures and screencasts
stay in the session scratch (never committed).

## 1. Status

| # | Task | State |
|---|---|---|
| 1 | Reproduce the flashing (both engines): boot, intro, licence, title, memory card, main menu, team select | Done: the title and the menus showed a different picture every field |
| 1b | Find each source | One source: the GP read vertex data the game had not handed it yet (the CPU's data cache, section 2). Presentation (incomplete frames, ImageBitmap timing, clears, field alternation) checked: not involved |
| 1c | Fix; zero A-B-A flicker on those screens | **Done**: 500 -> 0 (threaded), 588 -> 0 (single-threaded) flicker cells over the path to the team screen |
| 2a | 2x / 3x internal resolution, default by the canvas and the GPU, a setting | Done (the Picture setting; section 3) |
| 2b | Aspect ratio; good final scaling | Done: 4:3 (the game's cameras are 4:3); area filter / sharp bilinear |
| 2c | E1's renderer gaps where a screen shows them | LOD bias: used in play, done. Logic ops, destination alpha, fog, lines and points, z textures: not used on the screens looked at |
| 2d | Captures before and after | Section 5 |
| 3 | Guest state identical; frame time within P2's | Guest lines equal; per-scale costs in section 4 |

## 2. The flashing

### What the player saw

`browser_check --screencast` of the page (every frame Chrome composites, 550 x
600 JPEG) along the menus path (`front.txt`: CLK2's path, START x3 to skip the
movies, START at the title, the memory-card and profile dialogs, Play Now, the
team screen; 3,800 fields), and `flick.py` (new, scratch): a 16 x 12 grid over
the canvas, a cell flickers at frame k when it changes a lot from k-1 to k and
back at k+1 (A, B, A). Before: this branch with `gpview=0`, which draws as
origin/main does (origin/main's own build gave 513 cells in 61 frames on the
same path, over a slightly smaller crop):

| Stretch (VI fields) | frames | A-B-A cells (frames), threaded | single-threaded |
|---|---:|---:|---:|
| boot loading (0-700) | ~700 | 14 (1) | 0 |
| intro skipped, licence (700-1300) | ~600 | 0 | 7 (1) |
| title (1300-1700) | ~420 | 130 (12) | 127 (9) |
| memory card dialog (1700-2000) | ~280 | 118 (18) | 121 (21) |
| main menu, profile dialog (2000-2950) | ~970 | 238 (33) | 238 (33) |
| team select (2950-3800) | ~820 | 0 | 95 (2) |
| **all** | 3,769 / 3,755 | **500 (64)** | **588 (66)** |

The frames themselves: on the title (the Red Sox batter coming in on a ring)
and behind every menu, the picture changed completely from one frame to the
next: a black background, then the photo, a white background, a posterized
black-and-grey photo, a sharp photo, a blurred one, logos missing or doubled
(contact sheets `s1.png`, `s2.png`, `s3.png` in the scratch). Not a blink: a
jumble at 60 Hz. The intro movies themselves (no input, 4,200 fields) showed no
flicker before or after: the detector's few hits there (20 cells in 2 frames
before, 16 in 3 and 2 in 1 after) are fast motion in the EA ring animation.

### Not the presentation

The presentation trace (`--trace-present`) showed every present a complete XFB
copy at the VI's address, one copy per field with the EFB clear, no fallback,
no resize, threaded and not; and `mvp-play --capture-every 1` natively (no
browser, no threads) showed the same jumble in the XFB copies themselves. So
neither ImageBitmap timing, nor incomplete presents, nor clears, nor a field
alternation P1-G1 misses: the frames were drawn wrong.

### Why: what the GP reads

`mvp-play --draw-log` on consecutive main-menu fields: the same 78 draws with
the same textures in the same order every field, but each draw's geometry and
colors were those of another sprite, a different pairing each field (the
background photo's texture full screen and opaque in one field, a 3-pixel line
in the next). A temporary write watch on the sprites' vertex array
(`0x017DBFA0`, not committed) and an entry trace of the sprite functions gave
the order the game does things in, per sprite:

1. `DCStoreRangeNoSync` over the vertex arrays (positions 14,400 bytes,
   colors, texture coordinates), from `fn_803E6BE8`;
2. the draw, issued (`fn_803666EC`: GXBegin, a hand-written primitive, padding
   to 32 bytes);
3. `fn_80318F3C` writes the NEXT sprite's vertices into the same arrays;
4. GXDrawDone.

On the console the GP draws what step 1 wrote back to memory; step 3's stores
are still in the CPU's write-back data cache, and step 1 of the next sprite
flushes them for the next draw. Our GP model reads guest memory itself when it
executes the draw. When the draw's last bytes left the write-gather pipe in
step 2 (the padding completed a 32-byte burst) it drew the right sprite; when
they waited in the pipe until GXDrawDone's flush (step 4), it drew the next
sprite's geometry with this sprite's texture. Which case a sprite falls in
depends on how many state bytes preceded it, so the pairing changed every
field. E3c's "suspicious screens" (logos in the wrong slots, white squares,
black boxes) are the same thing, and so, probably, is the field-alternating
HUD panel P1-gfx found in play (the 8 x 8 panel-fill texture stretched over the
count box every other field): with the model below, native per-field captures
of 240 fields of human pitching (fields 7,000-7,240) have 1 A-B-A cell instead
of 61.

### The fix: `gfx/gp_memory.h`

What the GP reads is memory as the data cache has written it back:

- A flush (`DCFlushRange`, `DCStoreRange`, `DCFlushRangeNoSync`,
  `DCStoreRangeNoSync`: the game's only `dcbf`/`dcbst` are in these four)
  snapshots the 32-byte lines it covers. The runtime learns of them through
  four new HLE "Before" hooks (`rt::hle_table()`, appended; host side only,
  the guest functions run unchanged) and `rt::g_dc_flush_hook`.
- Until the next VI field the GP reads those lines from the snapshot; every
  other line it reads from memory as it is (stores the game never flushes count
  as written back at once, as before). The expiry stands for eviction: a
  frame's memory traffic turns the 32 KiB cache over many times. (Without
  expiry, a first try kept snapshots of lines flushed once at load time and
  broke play: the stadium drew from stale data. With expiry at the next field,
  play draws as before, minus the HUD alternation.)
- Memory written without the cache (DI, ARAM and EXI DMA; the write-gather
  pipe, also when the game redirects it to memory) ends the snapshots there
  (`GfxObserver::gp_write_through`).
- The GX processor (vertex arrays, indexed XF loads, TLUT loads, TMEM
  preloads), the renderer (textures, the tall copy) and the renderer digest
  read through `GpMemory::view()`: memory itself where no snapshot is active,
  else a copy with the snapshots laid over it.
- Threaded engine: the render thread keeps the GpMemory; the emulation thread
  mirrors which lines are snapshot and what each snapshot holds, and sends
  only the lines that changed since their last flush (`kGpLines` records,
  then `kGpActivate` for the range; `kGpDrop` for DMA over an active line). In
  60 s of CPU-vs-CPU play the game flushed 8.7 GB and 197 MB went through the
  ring. A guest write to a line the render thread reads from a snapshot need
  not wait for it, so P2's write tracking skips those lines (`gp_unmarked`):
  write waits fell from 7.1 to 0.9 per field in CPU-vs-CPU play.
- Native `mvp-play` the same (`--gp-live` turns it off); the page's
  `gpview=0` too (comparisons).

Guest state cannot depend on it (only the renderer reads through it): the
guest lines are unchanged (section 6).

### After

| Stretch (VI fields) | threaded before -> after | single-threaded before -> after |
|---|---:|---:|
| boot loading (0-700) | 14 -> 0 | 0 -> 0 |
| licence (700-1300) | 0 -> 0 | 7 -> 0 |
| title (1300-1700) | 130 -> **0** | 127 -> **0** |
| memory card (1700-2000) | 118 -> **0** | 121 -> **0** |
| main menu (2000-2950) | 238 -> **0** | 238 -> **0** |
| team select (2950-3800) | 0 -> 0 | 95 -> **0** |
| all | **500 -> 0** (64 -> 0 frames) | **588 -> 0** (66 -> 0 frames) |

Same guest line in all four runs (`MEM1 9f60f693...`, 24,655,098,125
instructions at 3,800 fields). The title is the photo with its ring
animation, the main menu a steady blurred player photo behind the menu, the
team screen the Cardinals and Red Sox logos and the Red Sox home jersey where
they belong.

P1-G1's scan-out mix stays as a safety net for a real field alternation; it
now rarely has anything to mix.

## 3. The picture

### Internal resolution (`gfx/wgpu/renderer.h`)

The EFB, its copies to the XFB and its copies to textures can be 2x or 3x the
console's pixels in each direction (1280 x 1056 or 1920 x 1584 EFB).
Everything the GX state machine hands over stays in console pixels (scissors,
copy rectangles, texture sizes); the renderer multiplies at the GPU (scissor
rectangles, copy origins and extents, the conversion pass's source, the copy
textures). Draws that sample an EFB copy sample it by normalized coordinates,
so they see the same picture in more detail; the half-scale copy sampled as a
taller texture (P2's tall copy) gets memory's rows at the copy's scale. A
change applies at the next XFB copy that clears (the game's end of frame), so
no frame is drawn at two scales. Nothing is written to guest memory either
way. `test_gfx_render`: 2x and 3x frames, copies and tall copies against the
1x picture, and the switch.

### The setting

The page's toolbar has **Picture: Auto / 1x (console) / 2x / 3x**, kept in
`localStorage["mvp.picture.v1"]`. Auto draws at least as many pixels as the
canvas shows (the canvas's device-pixel height over 448, rounded up, at most
3x), so the page's 960 x 720 canvas gets 2x and a 1440p fullscreen 3x; it
follows a resize (fullscreen); a software (fallback) adapter stays at 1x.
`scale=N` in the URL overrides it (tests). The stats line shows the scale.
`mvp-play --scale N` natively.

### Aspect ratio

The frame buffer is 640 x 448. The game's 3D cameras use projection matrices
with yScale / xScale = 4/3 for that viewport (every perspective projection
loaded in fields 5,000-7,000 of play: 5.03/6.70, 2.07/2.76, 20.1/26.8,
114.6/152.8; the base-runner inset is the exception, for its own viewport): the
game draws for a 4:3 television, pixels 0.93 as wide as tall. The window and
the canvas now show the frame at 4:3 (before: at 640:448, 7% too wide, with
bars above and below inside the 4:3 canvas). The game has no 16:9 mode (no such
option in the DOL's strings; `WidescreenPos` is a replay-inset parameter).
`Window::set_display_aspect(0)` keeps the frame's own shape for tools.

### Scaling to the canvas (`gfx/wgpu/window.cpp`)

The blit chooses by the ratio of the frame to the picture area on screen:

- larger (2x, 3x, or 1x in a small window): an area filter, each pixel the
  mean of the frame over its footprint from an n x n grid of bilinear taps
  (n = ceil(ratio) + 1, 2-5), so 3x on a 960 x 720 canvas is supersampled
  anti-aliasing rather than skipped texels;
- smaller (1x on a large canvas): sharp bilinear, each frame pixel a block of
  whole screen pixels blended only at its edges (an integer nearest prescale,
  then bilinear), so a 1x picture stays crisp without uneven pixels.

### E1's gaps

Surveyed in the draw and GX logs of main-menu fields (2,100-2,104) and an
in-play field (7,000): no logic ops (enable 0 throughout), no fog, pixel format
RGB8_Z24 only (no destination alpha to keep), triangles only (no lines or
points), no z textures (BP 0xF4 not written). Other screens may use them; none
of the captures below shows a symptom of one. **The LOD bias is used**: in play most
mipmapped textures have -4 or -2 (TX_SETMODE0 bias 0x80 / 0xC0), so the
console samples their finest levels. WebGPU samplers have no bias, so the
shader now adds it (`textureSampleBias`, the bias per map in `DrawUniforms`,
whose slot grows from 416 to 448 bytes of 512): the outfield grass and the
warning track show their texture instead of a flat smooth green
(`lod_cmp.png`).

## 4. Cost per scale

P2's play windows and measurement (`measure.py` from P2's scratch): CLK2's
scripts, unpaced to the window, then paced; `--trace-present`, the composited
frames from a 320 x 240 JPEG screencast. The final build (all three Q1
commits). Other sessions loaded the machine; the load at the start and end of
each run is in brackets, and runs where it reached 100% in between (another
session's build) are left out (they ran at 0.34-0.93x).

**CPU vs CPU** (fields 8,000-11,600), threaded:

| Scale | run (load) | speed | emulation ms/field (window median; p90) | render thread busy, ms/field | new frames shown /s | composited p95 (> 25 ms) |
|---|---|---:|---:|---:|---:|---:|
| 1x | p_cpu1 (35-9%) | 1.000x | 11.70 (11.37; 15.08) | 5.53 | 58.9 | 20.5 ms (1.2%) |
| 2x | q_cpu2 (29-46%) | 1.000x | 11.58 (11.35; 14.91) | 5.57 | 57.7 | 20.3 ms (1.0%) |
| 3x | p_cpu3 (35-23%) | 1.000x | 11.62 (11.28; 14.95) | 5.54 | 58.4 | 21.2 ms (1.6%) |
| 3x | q_cpu3 (30-12%) | 1.000x | 11.58 (11.48; 14.96) | 5.62 | 58.6 | 20.6 ms (1.4%) |
| P2 final (1x, before Q1) | (4-6%) | 1.000x | 11.41 (11.14; 14.52) | 5.29 | 58.2 | 20.6 ms (0.5%) |

**Human pitching** (fields 6,600-9,000), threaded:

| Scale | run (load) | speed | emulation ms/field (median; p90) | render thread busy | new frames /s | composited p95 (> 25 ms) |
|---|---|---:|---:|---:|---:|---:|
| 1x | r_hum1 (13-23%) | 1.000x | 11.00 (10.71; 13.62) | 4.73 | 59.6 | 20.8 ms (0.7%) |
| 1x | p_hum1 (24-18%) | 1.000x | 11.11 (11.00; 13.85) | 4.80 | 59.4 | 20.3 ms (0.6%) |
| 2x | r_hum2 (33-1%) | 1.000x | 11.04 (10.91; 14.09) | 4.78 | 59.5 | 20.6 ms (1.2%) |
| 3x | r_hum3 (17-13%) | 1.000x | 10.91 (10.69; 13.63) | 4.73 | 59.0 | 20.4 ms (0.8%) |
| 3x | p_hum3 (22-12%) | 0.999x | 12.77 (12.76; 16.21) | 5.56 | 55.0 | 28.4 ms (5.3%) |
| P2 final (1x) | (2-8%) | 1.000x | 10.93 (10.67; 13.91) | 4.68 | 58.7 | 20.2 ms (0.8%) |

- **The threaded engine stays within P2's numbers at every scale**: 1.000x,
  11-11.7 ms per field on the emulation thread, composited p95 20-21 ms with
  about 1% of intervals over 25 ms. One 3x human run was worse (p95 28.4 ms) and
  its repeat was not; the emulation thread's own time was up too in that run
  (12.8 ms), which the scale does not touch, so it reads as load.
- On this GPU (RTX 4070 SUPER) 2x and 3x cost nothing visible: the GPU work
  is asynchronous and the render thread's CPU time (4.7-5.6 ms per field) does
  not grow with the scale. A weaker GPU would show its cost as fewer frames
  shown; Auto does not measure that yet (section 9).
- The emulation thread's cost of the GP view (comparing each flushed line with
  what its snapshot holds) is within the noise: 11.6-11.7 against P2's 11.4.
  Its write waits fell from 7.1 to 0.9 per field (0.22-0.26 ms), since lines
  read from snapshots need no tracking.

**The single-threaded engine** (the fallback without cross-origin isolation),
CPU vs CPU, emulation and rendering on one thread:

| Build | runs (load) | speed | ms/field |
|---|---|---:|---:|
| Q1, 1x | p_cpu1_st (11-17%), r_cpu1_st (28-9%) | 0.965x, 0.938x | 15.01, 15.73 |
| Q1, 1x, `gpview=0` | q_cpu1_st_off (29-6%), r_cpu1_st_off (24-20%) | 0.972x, 0.971x | 14.81, 14.80 |
| Q1, 3x | p_cpu3_st (2-15%), r_cpu3_st (19-11%) | 0.967x, 0.872x | 14.98, 17.86 |
| P2 final, 1x | (19-19%) | 0.986x | 14.09 |

The fallback was already slightly over budget in heavy play (P2); the GP view
adds about 0.2-0.9 ms per field to it (view checks on every vertex attribute,
the snapshots' copies: 0.75 MB per field in play); 3x is within the noise in
one pair and not in the other.

## 5. Captures before and after

Canvas screenshots along CLK2's path into the CPU-vs-CPU game (`game_125`,
unpaced, 1100 x 1200 viewport, the canvas 960 x 720), before = origin/main
`1ab1dd27` built in a scratch worktree (single-threaded), after = this branch at
Auto (2x on this canvas) and at 3x. Same guest line at 9,100 fields in all
(`MEM1 7ed924af...`). Looked at with the Read tool (`cmp_*.png` in the
scratch):

- **Main menu** (field ~2,180): before, a pale grey screen with the menu box,
  a black square at its corner, a grey slab below it and no photo (that
  field's jumble); after, the menu over a Red Sox batter photo with the EA
  SPORTS badge, the text crisp at 2x and 3x.
- **Team screen** (~3,050): before, logos misplaced; after, the Cardinals
  logo and bird, the Boston script and the Red Sox badge in their slots
  (3x: the "B BACK / Y RANDOM / X USER PROFILE / A ADVANCE" bar sharp).
- **Pre-game overview** (~5,000): the same scene; after, the grass has its
  mowing pattern and blade texture (LOD bias) where before it was a flat
  smooth green, and the frame fills the 4:3 canvas instead of a 1.43:1 strip
  with bars. (A thin black bar that opens into the line-up panel at fields
  5,028-5,036 is the game's: the old renderer draws it too.)
- **At bat** (~9,000): before, a light grey box over the score bug (the
  panel-fill sprite with the wrong sprite's geometry, P1-gfx's flashing HUD),
  the batter 7% too wide; after, the score bug's dark blue panels with
  "1 STL 0 / BOS 0 / 0-1 1 OUT", the stands, the Green Monster and the grass
  in detail, edges smooth at 2x and 3x (the area filter supersamples).

## 6. Exactness

The renderer still writes no guest memory; the GP view and the scale only
change what it draws.

**Guest lines** (`mvp_guest_line`), Chrome 155, unpaced, against WEB.md's
checkpoints (CLK2's lines):

| Run | Guest line | Where |
|---|---|---|
| 700 fields, no input | 4,547,010,125 instructions, time base 473,646,888, 360 polls, MEM1 `53221c4a...` | threaded with sound; single-threaded |
| 2,400 fields, START x4 | 15,574,026,125, 1,622,294,388, 1,882 polls, MEM1 `4285f135...` | threaded |
| 3,600 fields, `menus` | 23,357,802,126, 2,433,104,388, 2,747 polls, MEM1 `40a7692d...` | threaded, single-threaded, threaded at 3x |

and the match sessions equal P2's: CPU vs CPU at 11,600 fields `MEM1 d8c30e9a...`
in every run of section 4 (1x, 2x, 3x, threaded and not, `gpview=0`), human
pitching at 9,000 fields `58631fe2...`; the menus path to the team screen at
3,800 fields `9f60f693...` with and without the GP view, both engines;
origin/main's build and this branch at 9,100 fields of `game_125` both
`7ed924af...`.

**Renderer digests** (P2's `digest=1`), the threaded engine against the
single-threaded one, CPU vs CPU, every field: 0 of 11,600 differ. So the
snapshots that travel through the ring give the render thread exactly what the
inline renderer reads.

**Tests:** `ctest --preset msvc` 47 of 47 (new `test_gp_memory`; the local tests
with the disc, among them `local_play_determinism`: `mvp-play` with the
renderer and the GP view against `--no-render`; `local_disasm` skipped as
always), `ctest --preset emscripten` 40 of 40 (`local_disasm` skipped);
`test_gfx_render` has the scale case, `test_tev_wgsl` the biased sample.

## 7. Commits (branch `engine/q1-visual`, not pushed)

| Commit | What |
|---|---|
| `82d3e65a` | engine(gfx,web): the GP reads memory as the data cache wrote it back (`gfx/gp_memory.h`, HLE hooks, DMA/pipe notices, the ring's records, `test_gp_memory`, `mvp-play --gp-live`, `gpview=0`) |
| `40ef87f2` | engine(gfx,web): 2x/3x internal resolution, 4:3 picture, area and sharp-bilinear scaling; the Picture setting; `mvp-play --scale` |
| `755f6a8e` | merge of origin/main (Q3 controllers): `worker.ts` and `index.html` resolved as the union |
| `ef6d26d7` | engine(gfx): textures sampled with the game's LOD bias |
| (this log) | engine(docs): Q1 log; WEB.md's renderer paragraph |

Files outside `gfx/` and `web/`: `runtime/hle.h/.cpp` (four HLE "Before"
entries appended, `g_dc_flush_hook`), `runtime/gx_fifo.h`
(`GfxObserver::gp_write_through`), `runtime/hw.cpp` (the notices at DI, ARAM and
EXI DMA and at each write-gather burst; EXI DMA also gets P2's write check,
which it lacked).

### Tools (scratch, not committed)

`flick.py` (A-B-A cells in a screencast, per stretch of fields), `alt.py`
(field alternation in native per-field captures), `drawsum.py` (one line per
draw from `--draw-log`), `strip.py` / `sheet.py` (contact sheets),
`chrome.sh`, `perf.sh` (P2's play windows), `shots.sh`; a temporary write
watch in `mvp-play` (reverted).

## 8. For the lead (decisions to record; docs outside docs/engine/)

- **Q1-G1 (what the GP reads):** the renderer reads guest memory as the
  CPU's data cache has written it back: lines the game flushes
  (DCFlushRange, DCStoreRange and the NoSync forms, through host-only HLE
  "Before" hooks appended to `rt::hle_table()`) are read from a snapshot taken
  at the flush until the next VI field; DMA and the write-gather pipe end a
  snapshot; other lines are read as memory is. Guest state does not depend on
  it. It replaces "the GP reads memory when it executes the command" for
  rendering only; the runtime's GP model (E0b-GX1) is unchanged.
- **Q1-G2 (picture):** the frame is shown at 4:3 (the game's cameras are
  4:3); internal resolution 1-3x (the page's Picture setting, Auto by the
  canvas size); area filter or sharp bilinear to the canvas; textures with
  the game's LOD bias.
- The translated module changes (four more HLE hooks), so players translate
  once more after the deploy; netplay peers must run the same build anyway.

## 9. Next step

1. **Deploy** (owner, through Dokploy as before; nothing to configure). Then
   the menus and the title should be steady, the picture 4:3 and sharper; the
   Picture setting is in the toolbar.
2. **Auto by GPU speed.** Auto now picks by the canvas size (and 1x on a
   software adapter); on this RTX 4070 SUPER 3x costs nothing measurable, but a
   weak integrated GPU may not keep up at 2x/3x. Measure the GPU's frame time
   (timestamp queries, or the latency of `onSubmittedWorkDone`) and step Auto
   down when it passes a budget.
3. **The fallback engine's cost** of the GP view (0.2-0.9 ms per field in
   heavy play, where it was already over budget): check pages once per
   primitive instead of per vertex attribute.
4. **P1-G1's scan-out mix** now has almost nothing to mix; it can stay as a
   safety net, or go once the owner confirms the in-game HUD is steady.
5. Firefox and Safari with these changes (standard WGSL, `textureSampleBias`
   included) are not measured; anisotropic filtering for the field at 2x/3x is
   an optional extra.
