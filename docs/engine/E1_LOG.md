# E1 log: first pixels (native)

Working log for milestone E1 (`docs/ROADMAP.md`): render the GX command stream with
WebGPU natively. **Exit:** the EA logo and the title screen render recognizably.
Newest state first in "Status"; a later session resumes from "Next step".

## Status

| # | Step | State |
|---|---|---|
| 1 | `engine/gfx/`: WebGPU device (Dawn) and window (SDL3); off-screen triangle test; CMake option | Done |
| 2 | GX state machine: CP/XF/BP registers, vertex loading, transform, draws | Done |
| 3 | Texture decoders (I4, I8, IA4, IA8, RGB565, RGB5A3, RGBA8, CMPR, C4/C8/C14X2) | Done |
| 4 | TEV -> WGSL generator and pipeline cache | Done (indirect texturing and fog: not yet) |
| 5 | EFB and XFB: copies, present at each VI frame | Done (backend side; presenting is in step 6) |
| 6 | Run it: `mvp-play` window and frame captures | To do |

## How to build and test (agents)

- Same as E0b (`docs/engine/E0B_LOG.md`): `engine/tools/msvc.cmd` with the `msvc`
  preset. The WebGPU backend needs Dawn and SDL3 from `tools-ext` (pinned in
  `docs/engine/TOOLCHAIN.md`, "Native: Dawn + SDL3"); CMake finds them by default and
  prints `gfx: WebGPU renderer with Dawn ...`. Without them only the data-free core builds.
- Tests: `test_gfx_png` (data-free), `test_gfx_gpu` (off-screen WebGPU; exits 77 when
  there is no adapter).

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

## Determinism

The renderer reads guest state and never writes it. The only GPU-side values the
guest reads (PE tokens, draw-done, the CP FIFO state) stay on E0b's deterministic
model (GX1) in `runtime/hw.cpp`; the renderer is an observer of the same command
stream.

## Next step

Step 6: `mvp-play` (window, present at each VI field, captures), then look at the
game's frames and fill in what they need (indirect texturing, fog, ...).
