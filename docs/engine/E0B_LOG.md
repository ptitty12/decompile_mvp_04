# E0b log: native boot spike

Working log for milestone E0b (`docs/ROADMAP.md`), following the 10-item plan in
`docs/engine/E0_SURVEY.md` §8. Newest state first in "Status"; per-item detail below.
A later session resumes from "Next step".

## Status

| # | Item | State | Commit |
|---|---|---|---|
| 1 | Skeleton (CMake, presets, doctest, ctest) | Done | see git log |
| 2 | Disc and DOL | Done | see git log |
| 3 | Decoder and disassembler | Done | see git log |
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
| `engine/vfs/` | Disc image sources (file, memory, CISO), GCM header + FST, DOL, ELF section headers, disc identity check; `mvp-disc` CLI |
| `engine/ppc/` | Gekko ISA: opcode table (pattern + mask per opcode), decoder, disassembler; later the semantics library and the interpreter. Shared by translator and runtime, so it sits beside them (an addition to ARCHITECTURE §11) |
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

### 2. Disc and DOL (done)

- `vfs::open_disc` opens an ISO or CISO, parses the GCM header and FST, reads
  `main.dol` (sized from its own header) and refuses anything but game id GV4E69,
  revision 0 and DOL SHA-1 `da6becdb...84dd` (`vfs::kRetailDolSha1`).
- CISO: unstored blocks read as zero up to a full GameCube disc (1,459,978,240 bytes).
- `dol_layout_lines` names each DOL slot by the allocated ELF sections of the
  disc's `/mvp.elf` that fall inside it, in `dol_layout.txt` format.
- Exit evidence (2026-10-14): `local_disc` passes: retail hash, and the 8 printed
  lines (7 DOL sections + bss) equal `config/GV4E69/dol_layout.txt`. CI test
  `test_vfs` (synthetic GCM with FST, DOL and ELF, plain and CISO) passes.
- `mvp-disc info|ls|sections|dol` prints identity, FST, section table; `dol`
  extracts `main.dol` (only ever into `build/`).

### 3. Decoder and disassembler (done)

- `ppc/isa.h`: every Gekko opcode (base PowerPC 750 user and supervisor set plus
  paired singles; 222 opcodes) as `X(name, pattern, mask)`. The mask covers the
  opcode fields and every reserved bit, so a word with reserved bits set is
  `Op::invalid`. `decode()` is a primary-opcode table plus a 10-bit extended-opcode
  table per primary, built at startup with an overlap check.
- `ppc/disasm.cpp` prints dtk's conventions: simplified mnemonics (li/lis/subi/
  subis/subic, mr, nop, slwi/srwi/clrlwi/clrrwi/extlwi/extrwi/clrlslwi/rotlwi,
  rotlw, cmpw/cmpwi/cmplw/cmplwi, crset/crclr/crmove/crnot, mtlr/mfsprg/mtibatu
  etc., beq/bne/.../bdnz/beqlr/bctr with optional crN), lowercase hex immediates,
  `addis` operands unsigned, cr bit names (`lt`, `cr1eq`), SPR names (`HID2`,
  `GQR0`). Branch targets print as absolute addresses. The text rules were taken
  from dtk's own listing; powerpc-rs's `isa.yaml` (MIT/Apache-2.0) was read to
  confirm the simplified-mnemonic conditions. Nothing was copied.
- Exit evidence (2026-10-14): `local_disasm` reads every `.s` file of dtk's split
  (1,064 files; an address listed twice, from stale files of an older split, takes
  the newest file), checks each listed word against the DOL bytes, and compares
  our text with dtk's: **1,474,207 / 1,474,207 code words match** (.init 227, .text
  1,110,598, .feoverlay 239,890, .dboverlay 123,492; 20 of them are zero words
  that both print as `.4byte 0x00000000 /* invalid */`). Of those:
  - 1,140,705 identical text;
  - 319,954 where dtk prints a relocation (`lbl_X@l(r11)`, `fn_X`, `.L_X`,
    `X@sda21(r0)`): evaluated with `symbols.txt` (plus `_SDA_BASE_` and
    `_SDA2_BASE_`, read from `__start`'s own lis/ori pairs) and equal by value;
  - 13,546 where dtk keeps the base mnemonic because the operand is relocated
    (`addi rD, rA, sym@l` for our `subi`, `li rD, sym@sda21` for our
    `addi/subi rD, r13, d`), checked by value;
  - 1 branch whose target dtk couldn't label (0x804052C8, target in .bss), which
    dtk prints as the raw displacement;
  - 1 dtk quirk: dtk prints `ori r0, r0, 0xf1e8` (0x80406274) as `nop`; ours keeps
    the `ori` because it changes r0.
- CI: `test_ppc_decode` (2,700+ assertions): every opcode's pattern decodes to
  itself with spare fields set, every masked bit flip leaves the opcode, reserved
  bits give `invalid`, and ~150 hand-built disassembly vectors.
- Survey §4 said 1,474,044 instructions; the listing's code sections hold 1,474,207
  words. The difference is not investigated; the check covers every listed word.

## Next step

Item 4: semantics library and reference interpreter.
