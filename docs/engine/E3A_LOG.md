# E3a log: speed, the front end, the movie specks

Working log for the first half of milestone E3 (`docs/ROADMAP.md`): get from the title
screen into an exhibition game, fix what breaks on the way, and make it fast enough.
Newest state first in "Status"; a later session resumes from "Next step".

## Status (2026-10-14)

| # | Task | State |
|---|---|---|
| 1 | Speed: translated code optimized, exactness kept | Done: /O2 plus host-double FP shortcuts; renderer batching |
| 2 | Front end to an exhibition game | Done: power-on to the first pitch and the first play, by script |
| 3 | The movie specks | Done: root cause found and fixed (the floating-point unavailable exception) |

Exit evidence: captures (local, `build/engine/e3a/nav/cap11/`, never committed) of the
pre-game at Fenway Park (the line-up panel, the first batter walking up, the fielders
taking their positions), the first pitch (batter, pitcher, score bug "STL 0 / BOS 0,
0-0, 0 out", the pitch-type selector, then the pitch meter in the wind-up) and the
first ball in play (a fielder going for it, the base-runner inset). The input script
is `build/engine/e3a/nav/nav6.txt`; its button sequence is in "Menu path" below.

## How to build and run (agents)

Same as E1 (`docs/engine/E1_LOG.md`). Additions:
- The translated code builds at `/O2` by default. `MVP_GAME_OPT` overrides it
  (`-DMVP_GAME_OPT=-Od` for a one-minute build; from Git Bash write `-O2`/`-Od`, since
  its path conversion mangles `/O2`). A full `/O2` build of the 48 shards takes about
  5.5 minutes at `-j 8`.
- `mvp-play` options added here: `--perf-every N` (guest and host seconds every N
  fields), `--profile N [--profile-from F]` (guest-PC sampling by function),
  `--trace-entry HEX,...` with `--trace-from/--trace-to/--trace-file/--trace-peek`
  (registers, memory at r3/r4, words at r3+offset, r13 and the GQRs at function
  entries), `--dump-to M` (texture dumps over a range of fields). The report has a
  `runtime:` line (unwinds, interrupts, floating-point unavailable exceptions, idle
  skips, interpreted instructions) and merged/encoded draw counts.
- `mvp-boot` prints the last GX commands and the bytes at the lost position when the
  GX parser loses the stream.

## 1. Speed (done)

### What changed

1. **Translated code at `/O2`** (`runtime/CMakeLists.txt`, `MVP_GAME_OPT`).
2. **A pathological function left unoptimized** (`translator/emit_cpp`,
   `EmitOptions::max_optimized_run`, default 1024): MSVC's optimizer is quadratic in a
   basic block's length here (the per-instruction `++c.ticks` loads and stores
   interleave with guest stores that may alias them). fn_802D8B64, a
   3,130-instruction straight-line initializer, took over 30 minutes alone; the first
   `/O2` build took 33 minutes. Two functions in the DOL have a run over 1,024
   instructions (the next longest has 371); they get `#pragma optimize("", off)`
   under MSVC only. The build is now 5-5.5 minutes.
3. **Floating-point shortcuts** (`ppc/fp.cpp`): at `/O2` the intro movie still ran at
   0.23x, bound by the integer FP model (the VP6 decoder's paired-single loops).
   add/sub/mul/div/madd/frsp/quantize/dequantize now try host IEEE double arithmetic
   and keep it only where it provably equals the exact model, which stays as
   `fp::ref::` (round to nearest, finite operands, normal or exactly-zero results,
   never a single-precision midpoint, madd only with an exact product). `test_fp`
   compares the two on 21 million operand sets per run (a one-off run of 638 million
   also passed).
4. **Renderer batching** (`gfx/wgpu/renderer`, `gfx/gx_processor`): in game the
   renderer was the bottleneck (about 7,000 GX primitives per frame). Consecutive
   draws with the same pipeline, textures, constants and scissor merge (20.7 of 21.6
   million in the run to the first pitch; 0.9 million WebGPU draws encoded);
   encoding skips repeated state; the transform unit's XF state is unpacked once per
   primitive and matrices fetched once per index; no allocation per draw. The run's
   115 captures are pixel-identical before and after.

### Exactness

Guest floating point is integer code or provably-equal host arithmetic, and host FP
keeps `/fp:precise` without contraction. The guest state is the same at `/Od` and
`/O2`, and with and without the shortcuts:
- `local_boot_twice`: SDK call log sha1 `6841fdf4...` at both levels;
- `local_input_start`: the same logs and frame logs (`8c1e5a94...`, `e68558c6...`);
- `local_play_determinism`: MEM1 `73e856d4...` at both levels;
- 1,800 fields of the intro: MEM1 `380e7326...` (/Od and /O2, each with and without
  the shortcuts);
- the menu path to team select (frame 1,900): MEM1 `768b36a8...` (/Od and /O2 without
  the shortcuts, /O2 with them);
- the path to the first pitch (frame 5,400): MEM1 `7d8b2516...` at /O2 with the
  renderer, twice without it, and at /Od.
(These hashes changed once, with the floating-point unavailable exception of task 3,
which is a semantics change; they did not change with optimization.)

### Measurements

RTX 4070 SUPER, headless with the renderer, guest seconds per host second (higher is
faster), on a quiet machine (other sessions' builds move these by up to 30%):

| Stretch | /Od (E1) | /O2 | /O2 + FP shortcuts | + renderer batching |
|---|---:|---:|---:|---:|
| Loading screen (fields 30-570) | 1.66x | 6.55x | 6.7x | 6.7x |
| Intro movie (fields 600-1800, no input) | 0.19x | 0.23x | **1.21x** | 1.21x |
| Menus (title to team select, fields 1800-3780) | 2.0x | 4.4x | **5.8x** | 5.8x |
| In game (pre-game to first pitch, fields 9600-12000) | | | 0.5x | **0.9x** |
| Whole path, power-on to the first pitch (frame 5,000) | | | | 2.2x (97 s) |

Without the renderer the in-game stretch runs at 1.4x. Where the in-game time goes
now (instrumented run, then removed): the transform unit on the CPU and the
per-primitive draw assembly, then the WebGPU encoding.

## 2. Front end to an exhibition game (done)

### Menu path (frame numbers are game frame polls, the numbers input scripts use)

| Frame | Button | Screen |
|---:|---|---|
| 280, 430, 580 | START | skip the intro movie |
| 730 | START | title screen: PRESS START |
| 800 | DOWN | memory card dialog: from "Retry" to "Continue without saving" |
| 860 | A | continue without saving |
| 1300 | DOWN | user profile dialog: from "Yes" to "No" |
| 1360 | A | no profile; the main menu |
| 1500 | A | main menu: Play Now |
| 1900 | A | Select Team (Cardinals at Red Sox; P1 on the home team): advance |
| 2700 | A | uniforms: advance |
| 2900 | A | difficulty (Rookie / Pro / All-Star / MVP): advance; loading screen |
| (none) | | about 4,000 fields of loading, then the pre-game (frames 2,991-4,970) |
| 5000 | A | pitch type: four-seam fastball |
| 5060, 5100 | A | the pitch meter; the pitch, put in play |

Pressing A during the pre-game is fine now; before the write-gather fix below, the
game crashed there either way.

### What broke on the way, and the fixes

1. **The game hung after the loading screen** (`runtime/hw.cpp`): the GX parser lost
   the stream ("byte 0x53 starts no command": RGBA texels). The game calls
   GXRedirectWriteGatherPipe/GXRestoreWriteGatherPipe 42 times as the match starts,
   to write data to memory through the pipe. The redirect sets the PI FIFO end to
   0x04000000; the model masked bit 26 off, took end 0 for "no CPU FIFO yet" and fed
   the data to the GP. The end now keeps bit 26 (test: `test_devices`, a redirected
   burst lands in memory and the GP reads nothing).
2. **Then it crashed in GXLoadTexObjPreLoaded or SHAPE_clut** (a TLUT region of 0,
   or a pointer made of palette bytes): EA's texture records were shifted by 0x18
   bytes. The redirect and the restore write WPAR, and writing WPAR empties the
   write-gather pipe; without that, 24 bytes left from GX commands prefixed the
   redirected data. `mtspr WPAR` now calls `ppc::Hooks::write_pipe_reset`
   (`SystemHooks` -> `Hardware::wgp_reset`); `mfspr WPAR` reads the buffer empty
   (tests: `test_sem`, `test_devices`).

### Rendering seen (unverified against hardware)

Loading screens, menus, Fenway at dusk with shadows, crowds, the score bug, the pitch
meter and the fielder insets look right. Suspicious, not investigated yet: a light
grey panel on the right of the main menu and of the profile dialog (the menu's
preview movie?), white home-plate shapes and black boxes on the uniform screen, part
of the pre-game line-up panel missing, and the first batter turning pink for a few
frames at the plate. None blocked the path. The renderer gaps listed in E1 remain
(VI scan-out geometry, destination alpha, other logic ops, z textures, LOD bias, line
widths, EFB peeks, fog range, emboss); no screen so far needed one to proceed.

## 3. The movie specks (done)

**Root cause: the floating-point unavailable exception was not modeled**, so the
OS's lazy FPU context switch never happened and every thread shared one FPU
register file. Dolphin OS clears MSR[FP] for a thread that does not own the FPU
(OSSetCurrentContext, 0x8043364C); the first FPU instruction it runs traps to 0x800,
whose handler saves the owner's FPRs and loads the thread's own. The VP6 decoder
thread runs its paired-single IDCT with MSR 0x8032 (FP clear) and keeps constants in
f0-f7 across preemptions; other threads' FP code overwrote them, so isolated 8x8
blocks came out wrong and persisted through inter prediction.

**How it was found**: the movie is `easports.vp6`/`mvpintro.vp6` (VP6, 640x448). The
game's Y plane is a linear frame buffer (stride 736, bottom-up) that the game samples
as a C8 texture through indirect maps; re-tiling a `--dump-textures` dump gives it
back. Compared with an independent VP6 decode of the same file (FFmpeg, local, used
as a reference only), the first keyframe had one wrong block (column 5 about 90 too
dark, the rest 220 instead of 219) at the place of a visible speck. `--trace-entry`
on the IDCT showed its input: a DC-only block (242 x 12) decoded by the float IDCT
(fn_803A3998), and MSR[FP] clear at every IDCT entry.

**Fix** (`ppc`, `runtime`, `translator`): FPU instructions (`ppc::uses_fpu`: lfd
through ps_sum1) with MSR[FP] clear raise 0x800 before they start (no tick). The
interpreter calls `Hooks::exception`; translated code checks MSR[FP] before the first
FPU instruction of each block (31,135 checks in the DOL) and calls
`rt::fp_unavailable`, which runs the OS handler to its rfi and continues in the
frame. 1,301 FPU switches happen in the first 700 fields, about 20,000 to the first
pitch. Test vectors: `test_sem` (entry state, no tick, retry with FP set; the FPU
class checked by mnemonic) and `test_emit_lockstep` (the synthetic program starts
with MSR 0 and a handler at 0x800; translated and interpreted runs stay in
lockstep).

**Result**: the keyframe and the first nine frames decode bit-exactly against the
reference decoder (64 wrong pixels before); the specks are gone from the EA logo
(field 720) and the later shots. Left: in inter frames, blocks rebuilt through the
game's full paired-single IDCT (fn_803A32CC/fn_803A34E0, with ps_madd/ps_nmsub and
s16 truncating stores between passes) differ from the reference by up to about 50
levels at block seams, invisible in the captures. The partial IDCT and the DC paths
match exactly. Whether the hardware matches us there is open: that IDCT is not the
integer reference, so FFmpeg is no oracle for those blocks, and no hardware capture
exists.

## Merged with origin/main (2026-10-14, `claude-side-e3amerge`)

`engine/e3a` merged origin/main at `45de368e` (E2 wasm emitter and Emscripten
preset, E2b/E2c browser client, E3b audio, E5/E5b netplay and server). Two files
conflicted; both were resolved as the union:
- `runtime/CMakeLists.txt`, **`MVP_GAME_OPT`**: one option, one meaning. It sets
  the optimization level of the translated game code only; empty means `/O2` on
  MSVC (E3a-B1) and `-O1` elsewhere (clang, Emscripten, as E2 had it). The `msvc`
  preset is therefore `/O2` by default; E2's `/Od` comparison build is the same
  preset with `-DMVP_GAME_OPT=-Od` (E2_LOG updated). E3a's `/fp:precise` and
  `-ffp-contract=off -fno-fast-math` on the game code are kept.
- `gfx/tools/mvp_play.cpp`: E3a's options (`--perf-every`, `--profile`,
  `--profile-from`, `--trace-*`, `--dump-to`) and E3b/E2's (`--audio-wav`,
  `--no-audio`, `--audio-latency`, `--yield`) all kept; the VI-field observer
  prints perf lines and requests the host yield; the report has both the
  `runtime:` line and the audio lines.
Everything else merged cleanly. E2's per-field yield, E3b's audio observer and
E5's netplay input source work unchanged with the floating-point unavailable
exception: a 0x800 handler runs inside `deliver` (exception depth > 0), where
`YieldingHooks` never yields.

**Native** (`msvc` preset, `/O2` default, `MVP_DISC` and `MVP_DTK_ASM` set): 40 of
40 tests pass, none skipped. The guest state is identical in a second tree at
`-DMVP_GAME_OPT=-Od` (all 10 local tests pass there with the same hashes):
`local_boot_twice` SDK log `6841fdf4...`, `local_input_start` `8c1e5a94...` and
`e68558c6...`, `local_play_determinism` (rendered, alone and yielding) MEM1
`73e856d4...` (2,845,943,121 instructions at 700 fields), `local_audio_determinism`
SDK log `5d46aca3...`, `local_netplay_lockstep` (solo and both peers) MEM1
`e46c01ed...`, 10,857,210,189 instructions, window list `9c27f789...`. These are
E3a's values; E3b's audio log (`09cfc165...`) and E5's netplay state
(`520439ba...`, 10,836,931,415 instructions) changed with the floating-point
unavailable exception. No test hard-codes them, so no expectation changed;
`test_ppc_digest`'s constants hold natively and under Node, so the host-double
shortcuts leave every digest operand set unchanged.

**Emscripten** (Node, no disc at configure time): 30 of 30 run tests pass
(27 data-free; `local_disc`, `local_cfg` and `local_disasm` pass with the disc at
test time). **Known gap, tracked by E2d:** the wasm emitter does not take the
floating-point unavailable exception yet, so `test_wasm_lockstep` (all three
cases: the reference interpreter enters 0x800 at the first FPU instruction, the
wasm code runs it) is `DISABLED` in `runtime/CMakeLists.txt` with a comment until
E2d lands. For the same reason the browser's guest lines (WEB.md §4) no longer
equal native ones at in-game checkpoints; native and browser netplay peers never
pair (different build ids), so this cannot cause a mixed desync. The WPAR pipe
reset already reaches wasm-emitted code on main: its `mtspr` to any SPR other
than LR/CTR runs `sem::write_spr` through `rt.exec`. E2d's inline SPR moves must
keep that (call `Hooks::write_pipe_reset` for WPAR).

## For the lead (decisions to record; docs outside docs/engine/)

- **E3a-FP1** (semantics): the floating-point unavailable exception (0x800) is part
  of the CPU model; FPU instructions with MSR[FP] clear do not start. Every executor
  (interpreter, C++ emitter, E2's wasm emitter) must implement it. ARCHITECTURE/
  DETERMINISM: threads no longer share FP registers.
- **E3a-FP2** (model): `ppc/fp` may take host-double shortcuts only where they
  provably equal the integer model (`fp::ref`), checked by `test_fp`; NaNs never come
  from the host.
- **E3a-WG1** (hardware model): writing WPAR empties the write-gather pipe; the PI
  FIFO end keeps bit 26.
- **E3a-B1** (build): the translated code builds at `/O2`; functions with a
  straight-line run over 1,024 instructions build unoptimized under MSVC.
- ROADMAP §3/§5: E3's first half (front end to an exhibition, speed) is done; the
  in-game rate is 0.9x headless on the dev machine.
- PROGRESS.md was not touched (this session's scope is `engine/` and `docs/engine/`).

## Next step

1. **In-game speed to 1x and beyond**: the CPU transform and the per-primitive draw
   assembly dominate. Options: an index buffer for strips/quads (vertices are
   duplicated today), a smaller vertex (only the texcoords in use), skipping the
   snapshot when no state changed, the transform on the GPU.
2. **The window** at 60 fields per second with FIFO presentation, then input from
   the keyboard and a gamepad (SDL3), so a person can play the match.
3. **The rendering questions above** (main-menu panel, uniform screen, line-up panel,
   the pink batter), with draw logs at those fields.
4. **The full IDCT question**: compare fn_803A34E0 against an exact transcription of
   its float arithmetic for the traced block, to tell an FP-semantics difference
   (ps_madd rounding, quantized-store rounding) from the game's own design.
5. Play a full 9-inning game by script and watch for crashes (E3's exit).
