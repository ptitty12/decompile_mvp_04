# E1 log: first pixels (native)

Working log for milestone E1 (`docs/ROADMAP.md`): render the GX command stream with
WebGPU natively. **Exit:** the EA logo and the title screen render recognizably.
Newest state first in "Status"; a later session resumes from "Next step".

## Status

**E1's exit is met (2026-10-14):** the EA SPORTS logo (the intro movie) and the title
screen ("PRESS START") render recognizably, natively, through Dawn/WebGPU, in a window
and in off-screen captures. Details and evidence: step 6.

| # | Step | State |
|---|---|---|
| 1 | `engine/gfx/`: WebGPU device (Dawn) and window (SDL3); off-screen triangle test; CMake option | Done |
| 2 | GX state machine: CP/XF/BP registers, vertex loading, transform, draws | Done |
| 3 | Texture decoders (I4, I8, IA4, IA8, RGB565, RGB5A3, RGBA8, CMPR, C4/C8/C14X2) | Done |
| 4 | TEV -> WGSL generator and pipeline cache | Done (with indirect texturing and fog) |
| 5 | EFB and XFB: copies, present at each VI frame | Done |
| 6 | Run it: `mvp-play` window and frame captures | Done (exit evidence below) |

## How to build and test (agents)

- Same as E0b (`docs/engine/E0B_LOG.md`): `engine/tools/msvc.cmd` with the `msvc`
  preset. The WebGPU backend needs Dawn and SDL3 from `tools-ext` (pinned in
  `docs/engine/TOOLCHAIN.md`, "Native: Dawn + SDL3"); CMake finds them by default and
  prints `gfx: WebGPU renderer with Dawn ...`. Without them only the data-free core builds.
- Tests (all in `ctest`):
  - data-free: `test_gfx_png`, `test_gx_processor`, `test_gfx_hook`, `test_texture_decode`,
    `test_tev_wgsl`;
  - GPU, data-free (exit 77 without an adapter): `test_gfx_gpu`, `test_gfx_render`;
  - local (disc and GPU): `local_play_determinism`.
- Run the game with the renderer: `build/engine/msvc/gfx/mvp-play.exe` (needs `MVP_DISC`
  like `mvp-boot`). `--headless --fields N --capture DIR --capture-every N` writes frames
  as PNG under DIR (keep DIR under `build/`); without `--headless` a window shows the
  game. `--input SCRIPT` takes `mvp-input 1` scripts (E0c). `--draw-log FILE` and
  `--dump-textures DIR --dump-field N` dump draw state and decoded textures.

## Layout (`engine/gfx/`)

| Path | Contents |
|---|---|
| `png.h/.cpp` | Minimal PNG writer (stored zlib blocks) for captures and test images |
| `wgpu/gpu.h/.cpp` | Instance, adapter, device, queue; texture read-back; WGSL modules |
| `wgpu/window.h/.cpp` | SDL3 window, WebGPU surface (HWND on Windows), aspect-correct blit and present |
| `wgpu/msvc_stl_compat.cpp` | Link shim for the prebuilt Dawn on an older MSVC STL (TOOLCHAIN.md) |
| `gx_regs.h` | CP/XF/BP register numbers and field layouts |
| `draw.h` | What the processor hands a backend: `DrawCall` (transformed vertices, `PipelineConfig`, `DrawUniforms`, `TextureDesc`s, scissor), `EfbCopy`, the `Backend` interface |
| `gx_processor.h/.cpp` | The GX state machine: register loads (BP mask), indexed XF loads, TLUT loads, vertex loading, the transform unit on the CPU, primitive assembly, EFB copies |
| `tests/gx_stream.h` | Builds synthetic command streams for the tests |
| `texture_decode.h/.cpp` | GameCube texture formats to RGBA8; level sizes |
| `tev_wgsl.h/.cpp` | TEV -> WGSL: one module per `PipelineConfig` |
| `wgpu/renderer.h/.cpp` | The WebGPU backend: EFB, draws, pipeline/texture/sampler caches, EFB copies to XFB frames and to textures, clears |
| `tools/mvp_play.cpp` | `mvp-play`: the game with the renderer (window or headless), captures, draw logs, texture dumps |
| `tools/play_twice.cmake` | `local_play_determinism`: the guest state with and without the renderer |

## Step notes

### 1. Device and window (done)

- `Gpu::create` requests a high-performance adapter and a device with
  `TimedWaitAny`, so native code can block on futures; uncaptured errors are counted
  and printed. `Gpu::read_texture` copies a texture into a mappable buffer (rows
  padded to 256 bytes) and returns packed RGBA rows.
- `Window` (SDL3) creates the surface from the window's HWND, picks BGRA8Unorm,
  configures FIFO presentation and draws a source texture with a full-window
  triangle, letterboxed to the source's aspect ratio.
- Exit evidence (2026-10-14): `test_gfx_gpu` renders a triangle into a 64x64
  RGBA8 texture and reads it back: center (255, 128, 0), corners the clear color,
  apex up; 0 WebGPU errors. Adapter: NVIDIA GeForce RTX 4070 SUPER, D3D12.
  `ctest --preset msvc`: 22 tests, all pass (local_disasm skipped: no dtk listing here).
- Problems met: the prebuilt Dawn references `__std_min_element_4u` and friends from
  a newer MSVC STL (shim, TOOLCHAIN.md); Dawn's D3D12 backend needs
  `dxcompiler.dll`/`dxil.dll` next to the executable (copied from the Windows SDK).

### 2. GX state machine (done)

- **Hook** (the only runtime change): `rt::GfxObserver` (`runtime/gx_fifo.h`) receives
  every command the GP executes, complete with its payload; display lists arrive as
  their contents. `Hardware::set_gfx_observer` also reports each VI field with the
  top-field frame buffer address (VI TFBL). With no observer nothing changes.
- **`GxProcessor`** keeps the BP, CP and XF state:
  - BP writes honour the write mask (BP 0xFE); TEV color registers and konst colors
    are decoded at write time (11-bit signed, bit 23 selects konst);
  - indexed XF loads and TLUT loads read guest memory when the command executes;
    TLUTs land in a 512 KiB copy of TMEM's palette half;
  - BP 0x52 produces an `EfbCopy`; BP 0x66 tells the backend to revalidate textures.
- **Vertices**: decoded from VCD/VAT and the CP arrays (direct, 8- and 16-bit indices,
  u8/s8/u16/s16/f32 with their shifts, normals with fixed fractions, NBT with one or
  three indices, all six color formats, per-vertex matrix indices or MATINDEX_A/B).
- **Transform unit on the CPU** (simple to test, deterministic, cheap at these vertex
  counts): position matrix, perspective/orthographic projection, viewport and scissor
  offset folded into a clip space that covers the whole 640 x 528 EFB (so the GPU
  viewport is the EFB and GX's guard-band behaviour falls out of the scissor); depth
  mapped to [0, 1] from the 24-bit range; normal matrix; both color channels with
  material/ambient sources and up to 8 lights (diffuse none/sign/clamp; specular and
  spot attenuation); texgens (regular with AB11/ABC1 and ST/STQ, color, emboss as a
  copy of its source for now) and dual-texture post matrices with normalization.
- **Assembly**: quads, triangles, strips (winding kept), fans into triangle lists;
  lines and line strips into line lists; points (1-pixel lines and points for now).
- `snapshot()` builds the `PipelineConfig` (TEV stages with order, konst selects and
  indirect commands, swap tables, alpha compare, blend/logic, color/alpha update,
  depth, cull, pixel format, fog type, indirect stages), `DrawUniforms` (TEV registers,
  konst, alpha refs, texcoord and texture sizes, indirect matrices, destination
  alpha) and the `TextureDesc` of every map a stage samples.
- Exit evidence (2026-10-14): `test_gx_processor` (10 cases, 149 assertions) and
  `test_gfx_hook` (the runtime hook: commands split over 7-byte pushes, a display list,
  a draw out of the processor) pass. All engine tests pass; `local_boot_twice`
  unchanged (no observer in `mvp-boot`).

### 3. Texture decoders (done)

- Our own decoders (Aurora's `texture_convert.cpp` was read; it is tied to its
  buffers, logging and GPU palette path, so vendoring it would cost more than the
  ~250 lines here). Every format the hardware samples: I4, I8, IA4, IA8, RGB565,
  RGB5A3, RGBA8 (AR/GB halves), C4, C8, C14X2 with IA8/RGB565/RGB5A3 palettes, CMPR
  (four 4x4 DXT1-like sub-blocks per 8x8 tile, big-endian colors, the hardware's
  5/8-3/8 interpolation, three-color mode with a transparent fourth entry).
  Unknown formats decode to magenta so they stand out.
- Exit evidence (2026-10-14): `test_texture_decode` (5 cases): every format's tiling
  against an independent texel-address reference at four sizes (whole and partial
  blocks), texel conversions at known values, palettes (C4/C8/C14X2, out-of-range
  entries), a CMPR block in both modes, level and mip-chain sizes.

### 4. TEV -> WGSL (done; indirect texturing and fog not yet)

- `generate_wgsl(PipelineConfig)`: a pass-through vertex stage (the transform ran on
  the CPU) and a fragment stage computing the TEV in integers as the hardware does:
  8-bit a/b/c (masked), 11-bit signed d and registers, lerp with c + (c >> 7), bias
  +-128, scale x1/x2/x4 (rounding +128, +127 when subtracting) and /2, clamp to 0..255
  or -1024..1023; all 16 stages; texture and rasterized-color swap tables; konst
  selection (fractions and K0-K3 components); the eight compare modes for color and
  alpha (alpha modes 0-5 compare the color operands); the pixel takes the last
  stage's destination registers; the alpha test (two references, and/or/xor/xnor);
  logic ops clear, inverted copy and set without blending (no-op becomes a write mask).
- Pipeline state from the same config: blend factors (destination alpha reads as 1 on
  EFB formats without alpha), subtractive blending, color/alpha write masks (alpha only
  on RGBA6_Z24), depth compare and update (no update when the test is off), cull mode
  (hardware 1 = back, 2 = front, front face clockwise), triangle/line/point lists.
- Caches: pipelines by `PipelineConfig` bytes; shader modules by WGSL text.

### 4b. Indirect texturing and fog (done)

- The intro movie needs indirect texturing: EA's video player draws one quad with five
  TEV stages that sample the Y (736x448), U and V (368x224) planes as C8 textures with
  IA8 palettes, and four indirect stages that look coordinates up in 368x4 and 736x4 IA8
  tables (wrap repeat in t), with regular coordinates wrapped to 0 and
  add-previous-coordinate chains.
- When any stage has an indirect command, every stage's coordinate goes through the
  hardware's fixed-point path in the shader (`fixuv`: s, t times the rasterizer size
  times 128): indirect stages sample their map at their coordinate shifted by the
  indirect scale and give (s, t, u) = texel (a, b, g); each stage masks them by format
  (8/5/4/3 bits), adds the bias (-128 for 8-bit, else +1), multiplies by a static
  matrix ((M x crd) >> 3, then the exponent's shift) or a dynamic s/t matrix, wraps the
  regular coordinate (off, 256..16 texels, or 0), adds the previous stage's coordinate
  if asked, and wraps to 24 bits. Bump alpha feeds the rasterized selects 5 and 6.
- Fixed-point samples are taken half a unit (1/256 texel) in: without that, nearest
  sampling at exact texel edges picked the neighbour and the movie showed vertical
  stripes.
- Fog: perspective ze = A / (B magnitude - (24-bit z >> B shift)) or orthographic A * z,
  minus C, clamped, through the linear/exp/exp2/backexp/backexp2 curve, blended in 8-bit
  fixed point. Range adjustment (BP 0xE8-0xED) is not applied yet.

### 5. EFB, copies and clears (done)

- EFB: 640 x 528 RGBA8 color plus Depth32Float. Draws go into one open render pass;
  each draw appends its vertices and a 512-byte uniform slot (dynamic offset) to
  per-pass arrays that `flush()` uploads before submitting. A texture re-upload while
  the open pass still samples the old contents submits the pass first.
- Textures: decoded from guest memory (`texture_decode`), all mip levels, keyed by
  address, format, size, levels and palette contents; revalidated by a hash of their
  memory once per texture-cache epoch (BP 0x66). Samplers by wrap/filter/LOD state.
- EFB copies: to the XFB, a copy of the source rectangle into a frame texture kept per
  destination address (`Renderer::xfb(addr)`); to a texture, a conversion pass (box
  filter when halving, intensity through BT.601 luma, A8/R8/G8/B8/RG8/GB8 channel
  selects, depth when the EFB format is Z24) into a GPU texture kept per destination
  address. A later draw that samples that address and size gets the GPU copy instead
  of decoding memory, as long as the guest memory there is unchanged since the copy
  (the copy is never written back to guest memory: rendering does not write guest state).
- Clears (the copy's clear bit): a full-screen triangle scissored to the copy rectangle
  with the color/alpha/depth write masks of the moment; formats without alpha keep
  alpha at 1.
- Exit evidence (2026-10-14): `test_gfx_render` (GPU, data-free): a vertex-colored quad
  over a cleared EFB copied to the XFB; a textured quad from synthetic RGB565 memory
  modulated by a konst color; alpha blending (white at alpha 128 over black reads back
  128) and an alpha-test rejection; an EFB copy to a texture sampled by a later draw
  (no memory decode); 200 random TEV configurations (1-16 stages) compile with 0
  WebGPU errors. `test_tev_wgsl` checks the generated text without a GPU.

### 6. Running the game (done): exit evidence

- `mvp-play` (built when the disc and Dawn/SDL3 are configured) boots like `mvp-boot`
  without the per-entry trace, attaches the state machine and the renderer to the
  runtime's `GfxObserver`, and at every VI field shows the XFB copy at the VI's TFBL
  address in the window (falling back to the latest copy).
- **Frames seen (captures under `build/engine/msvc/captures/`, never committed; looked at
  with the Read tool), 2026-10-14:**
  - fields 30-570, no input: the boot loading screen, correct: a baseball photo (base,
    cleats, grass), the EA SPORTS MVP Baseball 2005 badge, "Loading..." with a blue
    progress bar that fills from field 60 to 570, "(c) 2005 Electronic Arts Inc. All
    rights reserved."; 640 x 448 XFB;
  - fields 600-720: the intro movie's **EA SPORTS logo**: the red "EA" over the blue
    "SPORTS" in the silver ring on a light grey background, clean after the half-unit
    sampling fix (before it, vertical stripes);
  - fields 1080-3600: the rest of the intro movie (a Cardinals fan, Red Sox batters,
    Fenway at night with fireworks, "The Donots - We Got the Noise",
    "MAKE THE BIG PLAY ON DEFENSE");
  - with `starts4.txt` (START taps at frames 280, 430, 580, 730): field 1800 (frame 443)
    onwards the **title screen**: the Red Sox batter photo full screen, "MVP Baseball
    2005" and "(c) 2005 Electronic Arts Inc. All rights reserved." along the bottom, and
    the blinking **"PRESS START"** box (field 2160, frame 730); after the START at frame
    730, the "No Memory Card found in Slot A." dialog with "Retry" / "Continue without
    saving" over the title (fields 2400-6000; the panel's frame pieces and the dimming
    look plausible but are unverified against hardware).
- Measurements (RTX 4070 SUPER, MSVC `/Od` translated code):
  - loading screen: 1.41x real time headless; 0.98x with the window (FIFO present paces
    to the display);
  - intro movie: 0.18x real time (the CPU decodes the video in translated code);
  - title and menus: 6,000 fields (100 s of guest time) in 88 s headless; 86,149 draws,
    1,372,262 vertices, 634,982 triangles, 4,587 XFB copies, 5 pipelines, 931 textures
    decoded, 0 WebGPU errors.
- Determinism: `local_play_determinism` passes: 700 fields with and without the
  renderer give the same guest state (2,845,943,115 instructions, time base 474,323,852,
  94 frame polls, MEM1 sha1 `eef70ba3...`).
- Window: 400 fields shown in an SDL3 window, 395 presents, 0 WebGPU errors.

## Open issues

- **Small block artifacts in the intro movie** (isolated light or dark specks and small
  rectangles that persist and accumulate over several frames, e.g. around the EA logo
  and on the night-time Fenway shots). The movie's planes are decoded by the game on the
  CPU. They look like decoder errors that persist through inter-frame prediction (a CPU
  semantics or timing issue in the runtime) rather than renderer errors (those would be
  systematic: whole columns or rows). Not proven yet: the planes are stored interleaved
  (the 736 x 448 Y texture holds four column strips that the indirect tables put back in
  order), so `--dump-textures` output has to be de-interleaved before it can be compared
  with the capture.
- Not implemented: fog range adjustment; line and point widths (1-pixel lines and points);
  destination alpha (BP 0x42) and logic ops other than clear/copy/inverted copy/set/no-op;
  z textures; texture LOD bias (the sampler has no bias); emboss texgens (copy of their
  source); EFB peeks/pokes by the CPU; the XFB's vertical scale and VI scan-out
  geometry (the frame is shown letterboxed at its own size); EFB-to-texture copies are
  implemented and tested but no screen seen so far uses them.
- Draws are one WebGPU draw per GX primitive command (texture bind groups are cached by
  their views and samplers); batching comes when in-game scenes need it.

## Determinism

The renderer reads guest state and never writes it. The only GPU-side values the
guest reads (PE tokens, draw-done, the CP FIFO state) stay on E0b's deterministic
model (GX1) in `runtime/hw.cpp`; the renderer is an observer of the same command
stream. EFB copies are never written back to guest memory (a later draw that samples
the copy's address gets the GPU copy). Window events can only stop the run.

Checked by `local_play_determinism` (`gfx/tools/play_twice.cmake`): `mvp-play` runs 700
VI fields with the renderer and again with `--no-render`; the "guest:" lines
(instructions, time base, frame polls, SHA-1 of MEM1) must be identical, and the
rendered run must show frames with no WebGPU errors. `local_boot_twice` (E0b) is
unchanged: `mvp-boot` attaches no observer.

## Next step

E1 is done. Suggested follow-ups:

1. The movie specks: de-interleave the decoded Y/U/V planes (`--dump-textures DIR
   --dump-field N` at a field with specks, e.g. field 2040 with `280 1 tap 3 START`) and
   compare them with the capture; if the planes have the specks, hand it to the runtime
   (the video decoder runs on the CPU: paired singles, quantized loads, the movie's
   DMA/ARAM timing).
2. Go further into the front end with input scripts (`--capture` names files by game
   frame, the number scripts use) and fix what the menus and the first match need
   (in-game: fog range, line widths, z textures, EFB copies).
3. E2: the same renderer in the browser through emdawnwebgpu (same Dawn release; see
   TOOLCHAIN.md). `Window` is the only Windows-specific part (HWND surface); the browser
   needs a canvas surface and an async device request instead of `WaitAny`.
