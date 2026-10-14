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

## Browser: Emscripten

Added by E2 (2026-10-14). Builds the engine for WebAssembly (wasm32) and runs its
tests under Node.

| Piece | Version | Where |
|---|---|---|
| emsdk (the installer) | tag `6.0.12`, commit `35ff8a6d150541276abbc6bae512ca90bcfbe220` (github.com/emscripten-core/emsdk) | `tools-ext\emsdk` |
| Emscripten SDK | **6.0.12** (`sdk-releases-6e9f6885cb17a3d6c8fd488a5cff730f50aba61d-64bit`; emscripten revision `5488e0871d46d19a3209988190fa6a653126256f`), released 2026-10-08, the emsdk "recommended" (`latest`) build on 2026-10-14 | `tools-ext\emsdk\upstream` |
| clang / wasm-ld (in the SDK) | clang 24.0.0git (llvm-project `55ea1f4ebea23d0355d5cdb075f1e12f28ab82d0`) | `upstream\bin` |
| Binaryen (in the SDK) | wasm-opt version 133 (`version_133-60-g93d6e9de7`) | `upstream\bin` |
| Node.js (in the SDK) | 24.19.0 | `tools-ext\emsdk\node\24.19.0_64bit` |
| Python (in the SDK, for emcc) | 3.13.3 | `tools-ext\emsdk\python\3.13.3_64bit` |

Installed with `emsdk install 6.0.12` and `emsdk activate 6.0.12` (not `--permanent`:
nothing is added to the user's environment). To reproduce on another machine, clone
emsdk, check out tag `6.0.12`, and run the same two commands.

**Use** (agents run these; the owner never does): `engine\tools\emsdk.cmd` sets
`EMSDK`, `EM_CONFIG` and `PATH` for one command, like `engine\tools\msvc.cmd` does
for MSVC:

- configure: `engine\tools\emsdk.cmd cmake --preset emscripten` (Ninja, CMake's
  Emscripten toolchain file from the SDK, `Release`);
- build: `engine\tools\emsdk.cmd cmake --build --preset emscripten -j 8`;
- test: `engine\tools\emsdk.cmd ctest --preset emscripten` (CMake runs each test's
  `.js` under the SDK's Node as the cross-compiling emulator; build-time tools such
  as `mvp-synth-emit` run the same way).

**Build settings** (`engine/CMakeLists.txt`, `if(EMSCRIPTEN)`): native WebAssembly
exceptions (`-fwasm-exceptions`, still used to end a run with `GuestFault` or
`StopRun`; thread switches need none since E0c), `NODERAWFS` (tools and local tests
read the host file system, as natively), memory growth up to 4 GB, a 16 MB stack,
and `EXIT_RUNTIME` so exit code 77 (skipped) reaches ctest.

**Notes:**
- The preset sets `MVP_GFX_WEBGPU=OFF`: the native Dawn + SDL3 backend above is a
  Windows package. The renderer's data-free core (`engine_gfx`) and its tests
  build and pass under Emscripten; the browser backend (emdawnwebgpu) comes later.
- CMake 4.3.0-rc1 (the machine's CMake) prints a warning that it cannot build
  Emscripten *shared* libraries. The engine builds none, so it doesn't matter.
- The pureikyubu test oracle reads the x86 cycle counter for optional profiling;
  under Emscripten `third_party/pureikyubu/pk_wasm_shim.h` stubs it (`docs/REUSE.md`).
