# E1 log: first pixels (native)

Working log for milestone E1 (`docs/ROADMAP.md`): render the GX command stream with
WebGPU natively. **Exit:** the EA logo and the title screen render recognizably.
Newest state first in "Status"; a later session resumes from "Next step".

## Status

| # | Step | State |
|---|---|---|
| 1 | `engine/gfx/`: WebGPU device (Dawn) and window (SDL3); off-screen triangle test; CMake option | Done |
| 2 | GX state machine: CP/XF/BP registers, vertex loading, transform, draws | In progress |
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

## Determinism

The renderer reads guest state and never writes it. The only GPU-side values the
guest reads (PE tokens, draw-done, the CP FIFO state) stay on E0b's deterministic
model (GX1) in `runtime/hw.cpp`; the renderer is an observer of the same command
stream.

## Next step

Step 2: the GX state machine in `engine/gfx/` (data-free), fed by a minimal hook in
`runtime/` that hands every executed GX command to an observer.
