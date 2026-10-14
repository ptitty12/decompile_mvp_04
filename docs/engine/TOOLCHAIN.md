# Engine toolchain

External SDKs and tools the engine builds with. The owner approved these downloads on
2026-10-14 (`docs/DECISIONS.md`). Everything lives outside the repository under
`C:\Users\Patrick Taylor\tools-ext\`; nothing here is game-related, and nothing here is
vendored into `engine/` (vendored code is listed in `docs/REUSE.md` §6).

## Native: Dawn + SDL3

The native renderer (E1, `engine/gfx/`) uses WebGPU through Dawn's `webgpu.h` and
its C++ wrapper `webgpu/webgpu_cpp.h`, the same API that Emscripten's `emdawnwebgpu`
port provides in the browser (E2). SDL3 opens the window and, later, reads gamepads.

| Component | Version | Source | License | Local path |
|---|---|---|---|---|
| Dawn (prebuilt, Windows x64, Release, static `webgpu_dawn.lib`) | release `v20261013.193955`, commit `f63db59722e8c1c0da9a3bcea0e40fb5c817a059` | https://github.com/google/dawn/releases/download/v20261013.193955/Dawn-f63db59722e8c1c0da9a3bcea0e40fb5c817a059-windows-latest-Release.tar.gz (119,283,353 bytes, SHA-256 `5e6a5c6f05069bec6f77cf326e47af21a138bfaf283a8ea79602466b7c2bcea7`) | BSD-3-Clause (Dawn & Tint authors) | `tools-ext\dawn\v20261013.193955\Dawn-f63db597...-windows-latest-Release\` |
| SDL3 (VC development package: headers, `SDL3.lib`, `SDL3.dll`) | 3.4.18 (git `829a65d769d935c4852f8159e964312c0957260a`) | https://github.com/libsdl-org/SDL/releases/download/release-3.4.18/SDL3-devel-3.4.18-VC.zip (16,902,234 bytes, SHA-256 `78d84602ae616cfe26b33a73b7d3b9b6b56e8a6650e53d92c9c6ca938f747acd`) | zlib | `tools-ext\sdl3\3.4.18\SDL3-3.4.18\` |
| DirectX shader compiler (`dxcompiler.dll`, `dxil.dll`), needed by Dawn's D3D12 backend | 1.8.2502.11 | Not downloaded: the Windows SDK 10.0.26100.0 that the MSVC toolchain already uses ships both (`Windows Kits\10\bin\10.0.26100.0\x64\`) | Windows SDK terms (redistributable DLLs) | found by CMake |

Browser builds must use the **same Dawn release's** `emdawnwebgpu_pkg-v20261013.193955.zip`
(same release page) so that `webgpu.h` matches on both sides.

**How CMake finds them** (`engine/gfx/CMakeLists.txt`):
- `MVP_DAWN_DIR` (cache variable or environment variable): the directory holding
  `lib/cmake/Dawn/DawnConfig.cmake`. Default: `%USERPROFILE%\tools-ext\dawn\<release>\Dawn-<commit>-windows-latest-Release`,
  with the pinned release and commit written in the CMake file.
- `MVP_SDL3_DIR`: the directory holding `cmake/SDL3Config.cmake`. Default:
  `%USERPROFILE%\tools-ext\sdl3\<version>\SDL3-<version>`.
- `MVP_DXC_DIR`: the directory holding `dxcompiler.dll` and `dxil.dll`. Default: the
  Windows SDK's `bin\<version>\x64` from the vcvars environment (`WindowsSdkVerBinPath`),
  else the newest SDK under `Program Files (x86)\Windows Kits\10\bin`.
- `MVP_GFX_WEBGPU` (option, default ON): build the WebGPU backend when Dawn and SDL3 are
  found. If either is missing, CMake prints a status line and builds everything else; the
  data-free renderer core (`engine_gfx`) and its tests never need them.
- The executables that use the backend get `SDL3.dll`, `dxcompiler.dll` and `dxil.dll`
  copied next to them after linking.

**Notes:**
- The prebuilt Dawn is a Release build (`/MD`): use the `RelWithDebInfo` or `Release`
  configuration (the presets' default). A Debug configuration would mismatch its runtime.
- Dawn's release was compiled with a newer MSVC STL than the installed toolset (MSVC
  14.50.35717): it references the split vectorized `__std_min_element_4u`/`_8u` and
  `__std_max_element_4u` that this toolset's `msvcprt.lib` lacks. A configure-time probe
  (`MVP_MSVC_HAS_SPLIT_MINMAX`) adds `engine/gfx/wgpu/msvc_stl_compat.cpp`, which forwards
  them to the combined `__std_min_element_4(first, last, is_signed)` forms. A newer toolset
  passes the probe and compiles no shim.
- Adapter on the owner's machine (2026-10-14): NVIDIA GeForce RTX 4070 SUPER, D3D12 backend.
- To update: download the new release's `windows-latest-Release` archive into
  `tools-ext\dawn\<release>\`, change `MVP_DAWN_RELEASE`/`MVP_DAWN_COMMIT` in
  `engine/gfx/CMakeLists.txt`, update this table, rebuild and run `ctest`.
