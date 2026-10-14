# E1 log: first pixels (native)

Working log for milestone E1 (`docs/ROADMAP.md`): render the GX command stream with
WebGPU natively. **Exit:** the EA logo and the title screen render recognizably.
Newest state first in "Status"; a later session resumes from "Next step".

## Status

| # | Step | State |
|---|---|---|
| 1 | `engine/gfx/`: WebGPU device (Dawn) and window (SDL3); off-screen triangle test; CMake option | Done |
| 2 | GX state machine: CP/XF/BP registers, vertex loading, transform, draws | Done |
| 3 | Texture decoders (I4, I8, IA4, IA8, RGB565, RGB5A3, RGBA8, CMPR, C4/C8/C14X2) | To do |
| 4 | TEV -> WGSL generator and pipeline cache | To do |
| 5 | EFB and XFB: copies, present at each VI frame | To do |
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

## Determinism

The renderer reads guest state and never writes it. The only GPU-side values the
guest reads (PE tokens, draw-done, the CP FIFO state) stay on E0b's deterministic
model (GX1) in `runtime/hw.cpp`; the renderer is an observer of the same command
stream.

## Next step

Step 3: texture decoders (data-free, synthetic textures), then step 4 (TEV -> WGSL).
