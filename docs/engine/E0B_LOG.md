# E0b log: native boot spike

Working log for milestone E0b (`docs/ROADMAP.md`), following the 10-item plan in
`docs/engine/E0_SURVEY.md` §8. Newest state first in "Status"; per-item detail below.
A later session resumes from "Next step".

## Status

| # | Item | State | Commit |
|---|---|---|---|
| 1 | Skeleton (CMake, presets, doctest, ctest) | Done | see git log |
| 2 | Disc and DOL | | |
| 3 | Decoder and disassembler | | |
| 4 | Semantics library and reference interpreter | | |
| 5 | Functions and CFGs | | |
| 6 | IR and C++ emitter | | |
| 7 | Boot environment | | |
| 8 | HLE boundary and SDK log | | |
| 9 | Virtual clock, interrupts, threads (D4) | | |
| 10 | Devices to the first retrace | | |

## How to build and test (agents)

- Configure, build and test with the `msvc` preset inside a vcvars environment:
  `engine/tools/msvc.cmd` finds Visual Studio with vswhere and runs its arguments
  (`cmake --preset msvc`, `cmake --build --preset msvc -j 8`, `ctest --preset msvc`).
  From Git Bash: `cd engine && cmd //c "tools\\msvc.cmd cmake --preset msvc"`.
  The `vs` preset (Visual Studio generator) needs no vcvars.
- Build trees go to `build/engine/<preset>/` (gitignored).
- Local data for the tests that need it, read at configure time and at test time:
  - `MVP_DISC`: the disc image (here `orig/GV4E69/MVP Baseball 2005 (USA).ciso` in the
    main checkout);
  - `MVP_DTK_ASM`: dtk's split assembly (`build/GV4E69/asm` of a dtk build).
  Without them those tests exit 77 and ctest reports them as skipped.
- CI: `.github/` is owner-only, so there is no workflow yet (open question in
  `docs/DECISIONS.md`, 2026-10-14).

## Layout

| Path | Contents |
|---|---|
| `engine/common/` | Byte order, SHA-1, host file helpers |
| `engine/third_party/` | Vendored code (`docs/REUSE.md` §6) |
| `engine/tools/` | Build helpers |

## Item notes

### 1. Skeleton (done)

- `engine/CMakeLists.txt` (C++20, `/fp:precise` on MSVC and `-ffp-contract=off` on
  clang: no host FMA contraction), `engine/CMakePresets.json` (`msvc`, `vs`, `clang`;
  Emscripten comes in E2), doctest 2.5.3 vendored (MIT).
- `engine_test()` registers a doctest executable with ctest; `SKIP_RETURN_CODE 77`
  marks data-dependent tests as skipped when the data is missing.
- Exit: `ctest --preset msvc` passes locally (1/1).

## Next step

Item 2: disc and DOL.
