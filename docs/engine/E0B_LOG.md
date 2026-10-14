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
| 4 | Semantics library and reference interpreter | Done | see git log |
| 5 | Functions and CFGs | Done | see git log |
| 6 | IR and C++ emitter | Done | see git log |
| 7 | Boot environment | Done | see git log |
| 8 | HLE boundary and SDK log | Done | see git log |
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
| `engine/ppc/` | Gekko ISA: opcode table (pattern + mask per opcode), decoder, disassembler (`isa.h`, `decode.cpp`, `disasm.cpp`); CPU state, guest memory page table, runtime hooks (`cpu.h`, `mem_access.h`); floating-point core (`fp.h/.cpp`); per-opcode semantics (`sem.h`); reference interpreter (`interp.h/.cpp`). Shared by translator and runtime, so it sits beside them (an addition to ARCHITECTURE §11) |
| `engine/translator/` | Symbol map parser (`symbols.h/.cpp`), function and CFG recovery (`cfg.h/.cpp`), input loading (`program.h/.cpp`), `mvp-xlat` CLI |
| `engine/runtime/` | `native.h/.cpp` (what translated code calls: entry hook, unwind, indirect calls, the entry table, the run loop), `machine.h/.cpp` (MEM1, DOL loading, real-mode mapping, the code-intact check), `boot.h/.cpp` (IPL/apploader environment), `hw.h/.cpp` (hardware registers and device models), `sys_hooks.h/.cpp` (CPU hooks), `lockstep.h/.cpp` (translated vs interpreter checker), `mvp-boot` CLI |
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

### 4. Semantics library and reference interpreter (done)

- **One definition per opcode.** `ppc/sem.h` has `void op(Cpu&, Insn)` for every
  non-branch opcode (branches compute only their condition). The interpreter calls
  them with decoded words; the C++ emitter (item 6) will call them with constant
  words, so both paths share one semantics by construction.
- **State** (`ppc/cpu.h`): GPRs, FPRs as two raw double halves (ps0/ps1), packed CR,
  XER as SO/OV/CA + the other bits, LR, CTR, FPSCR, MSR, SRs, and every other SPR
  by number (`spr[1024]`, GQRs at 912-919). Guest memory: 65,536 pages of 64 KiB,
  each a host pointer (big-endian bytes) or null for `Io` (MMIO). Time base,
  decrementer, MSR changes, `icbi` and `sc` go to `Hooks` (the runtime's virtual
  clock in item 9). Guest errors throw `GuestFault` with the PC.
- **Floating point** (`ppc/fp.cpp`) is computed in integer arithmetic (128-bit
  products, jammed sticky bits, one rounding), so no host FPU, NaN payload or
  rounding-mode behaviour can leak in; the same code will run in WebAssembly.
  Model, all checked by tests:
  - single-precision results round once from the exact result; double results too;
  - `fmadd` family fused (one rounding), double and single;
  - single-precision instructions round frC to a 25-bit significand first (force25);
  - NaNs propagate in the order frA, frB, frC, quieted; invalid operations give
    0x7FF8000000000000; a NaN to a single result keeps the top 23 fraction bits;
    `fnmadd`/`fnmsub` never flip a NaN's sign;
  - NI (the game sets it in OSInit): single results whose exact value is below
    2^-126 flush to a signed zero; double results that round to a denormal flush;
    inputs are not flushed (Dolphin's measured model);
  - `lfs` fills both halves, single-precision results fill both halves, double
    results and moves set ps0; `stfs` uses the manual's store conversion
    (denormalizing, truncating); `fctiwz` sets bit 32 for negative zero results
    and saturates;
  - quantized `psq_l`/`psq_st` per GQR: integer types scale by 2^-S/2^S; stores
    round to single, scale, truncate toward zero, saturate; NaN saturates high;
    float-type stores flush single denormals to zero.
- **Not modeled (deliberate, deterministic):** FPSCR status bits (FX, FEX, VX*,
  OX, UX, ZX, XX, FR, FI, FPRF, FPCC) keep whatever the guest last wrote. The DOL
  reads FPSCR only through `mffs`: 4 sites (0x804335A8 in dolphin/os, 0x8041A630
  in dolphin/base, 0x80404FF8 and 0x80405A90 in libsn); none has been checked yet
  for status-bit use, so this needs revisiting if one feeds game logic. `fres`,
  `frsqrte`, `ps_res`, `ps_rsqrte` return correctly rounded values, not the
  hardware's table estimates. The DOL has no `fres` and 2 `frsqrte`: 0x8042FC50
  (GX) and 0x80438850 (PAD clamping, so it shapes stick input). That is a
  fidelity gap, not a determinism one; bit-exact estimates need the hardware
  tables from a permissive source or measurement.
  Rounding modes other than nearest are implemented but unused.
- **Undefined cases follow measured hardware** (as Dolphin's hardware tests
  report, read as reference only): `divw` overflow gives 0 or -1 (negative
  dividend), `divwu` by zero gives 0; `sraw` by 32 or more sets CA to the sign;
  `stwcx.` to an address other than the reservation's does not store.
- **Exit evidence (2026-10-14):**
  - `test_ppc_sem`: vectors for every opcode (424 assertions); its last case checks
    that every one of the 222 opcodes ran (only `eciwx`/`ecowx`, which fault by
    design, are covered by fault checks instead). Passes.
  - `test_ppc_fp`: 1,009,709 assertions, 0 failures: double add/sub/mul/div equal
    host IEEE results on 200,000 random pairs each (wide exponents, denormals,
    cancellation); single ops equal host float ops; double `madd` equals
    `std::fma`; single `madd` equals an independent round-to-odd reference;
    `round_to_single` equals host conversion; load/store conversions round-trip all
    sampled words; fixed vectors for force25, zero signs, rounding modes,
    `fctiw(z)`, estimates, quantization and NI.
  - `test_ppc_fuzz_pk`: 30,000 random programs (48 instructions, 111 integer,
    branch, CR, XER, SPR and load/store opcodes) on our interpreter and
    pureikyubu's (CC0, pinned 0c29dca5, vendored as a test-only oracle):
    **895,135 instructions compared after every step (GPRs, CR, XER, LR, CTR, PC)
    plus data memory per program: 0 differences.** 19,165 programs ended early by
    a fault in both (random pointers), 1,598 ended at an instruction excluded
    below.
  - Excluded from the fuzz comparison, each documented in the test and covered by
    vectors: pureikyubu bugs (`crorc` not masked to one bit; conditional branches
    with LK=1 that are not taken leave LR unchanged; `sraw` with rB[26:31]=0 and
    rB≠0 sets CA through an out-of-range C++ shift; `sraw` of 0x80000000 by ≥32
    clears CA), pureikyubu gaps (`divwo`, `divwuo`, `mullwo` halt; `icbi` takes a
    DSI where ours has no effect), and architecturally undefined cases (divide
    overflow, `stwcx.` with a reservation for another address).
  - **One bug of ours found by the fuzz and fixed:** `mcrxr` left XER bit 3 set;
    it now clears XER[0-3].
- Total `ctest`: 8 tests (6 data-free, 2 local), all pass.

### 5. Functions and CFGs (done)

- `xlat::build_cfg(dol, symbols)` decodes every function symbols.txt lists, classifies
  every branch (local jump, conditional jump, call, tail call, return, conditional
  return, indirect call through LR/CTR, jump table, absolute call), walks
  reachability from every entry point, and forms blocks (calls do not end blocks).
  Per function it records the resume points (each call's return address) and the
  back edges (safe points for interrupt delivery, D4).
- Jump tables: from the `bctr` back to `mtctr`, its `lwzx`, and the constant base
  (`lis`/`addi`); the entry count comes from the data symbol at the base (any name),
  else the `cmplwi` bound check. Every entry must land inside the function.
- Accepted without error because the hardware does the same (each counted and
  listed by `local_cfg`):
  - calls into another function's body: 8 secondary entry points (`_savegpr_23/24/27`
    and `_restgpr_23/24/27` in `__save_gpr`/`__restore_gpr`, 0x80404C00 in libsn,
    0x80414E64 in libgcc);
  - 1 gap function: libsn's `_exit` label at 0x80413F3C is outside every function
    symbol; it becomes a function up to the next one. Its first word is invalid (a
    deliberate trap);
  - 6 functions whose last instruction is a call that does not return
    (`__assert`, `exit`, `abort`, fn_80400678, fn_8040787C, and fn_80432010's
    `bla 0x60`): execution would run into the next function, so that is an implicit
    tail call;
  - 3 expected traps: `_exit`'s first word, and 2 invalid words right after calls
    that do not return (0x803D95AC, 0x80407AB8).
- Exit evidence (2026-10-14), `local_cfg` (needs the disc):
  - 24,159 functions (24,158 from symbols.txt + `_exit`), 1,474,046 words, 1,473,997
    reachable (49 unreachable: padding and data inside function bodies), 187,612
    blocks;
  - 92,977 calls, 55 tail calls, 22,170 indirect calls, 1 absolute call
    (`bla 0x60`, fn_80432010);
  - **22 of 22 `bctr` through recovered jump tables** (21 `jumptable_*` symbols plus
    `@740` at 0x80649204), no other indirect jump;
  - 115,148 resume points, 10,471 back edges;
  - **0 errors**: no unresolved branch target; every tail branch lands on a function
    start; every call on a function start or a listed secondary entry.
- CI: `test_translator_cfg` (synthetic DOLs: calls, loop, jump table, tail call,
  conditional return, stray branch error, unreachable padding, running off the end,
  secondary entries, gap function, expected traps; symbols.txt parsing).
- Counts differ slightly from the survey's §4 (it counted 46 cross-function `b`;
  the 55 tail calls here include conditional ones and those of the gap function).

### 6. IR and C++ emitter (done)

- **IR = the CFG of item 5 plus the semantics library.** `xlat::emit_cpp` writes one
  C++ function per entry point (`f_XXXXXXXX(Cpu&)`); every non-branch instruction
  becomes `sem::op(c, Insn{word});` with the constant word, so translated code and
  the interpreter share one definition of every instruction. Local branches are
  `goto`s, jump tables `switch`es on CTR, calls are C++ calls.
- **Call protocol** (`runtime/native.h`): the caller sets LR and calls; the guest
  `blr` sets `c.pc = LR & ~3` and returns; the caller then checks `c.pc` against
  its own return address and throws `rt::Unwind` on any other value (a context
  switch, a longjmp). `rt::run` catches it and resumes at `c.pc` in the reference
  interpreter, which enters translated code again at the next entry point it
  reaches (D4's resume path). Indirect calls go through a dense address -> function
  table; a target without translated code runs in the interpreter until it
  returns. Functions with secondary entries get one body with an entry `switch`.
  The guest PC is stored before every instruction (precise faults; to optimize
  later).
- **Build:** `mvp-xlat emit-cpp` writes `build/engine/<preset>/gen/` (48 shards plus
  a table and a declarations header), driven by a CMake custom command that exists
  only when the disc is configured. 24,159 functions, 24,167 entry points,
  1,473,997 instructions, 128 MB of C++ (with a disassembly comment per
  instruction). With MSVC `/Od` and `-j 8` the whole DOL compiles and links into
  `mvp-boot` in about 35 seconds.
- **Lockstep** (`runtime/lockstep.h`): two machines, one running translated code,
  one the interpreter. At every translated function entry the interpreter runs to
  its next function-entry event (control reaching an entry point other than by a
  branch inside the same function); every register (GPRs, both FPR halves, CR, XER,
  LR, CTR, FPSCR, MSR, SRs, all 1,024 SPRs) must match; all of MEM1 is compared
  every 16 events and at the end. Both stop at their first MMIO access, which must
  be the same access in the same state. The time base is a placeholder (+1000 per
  read) until item 9.
- **Exit evidence (2026-10-14):** `mvp-boot lockstep` (`local_lockstep`): 153
  function-entry events, 219,257 reference instructions, 10 full MEM1 comparisons,
  **0 divergences**; both stop at the first MMIO access, a 4-byte write to
  0xCC003004 (PI interrupt mask) from 0x8043504C in fn_80435004.
- **CI:** `test_emit_lockstep` translates a synthetic program at build time
  (`translator/tests/synth.h`: recursion, a jump table, a counted loop, calls
  through CTR and LR, a tail call, a conditional return, a secondary entry, a
  function running into the next, floating point, and a function that returns
  past its call) and runs it in lockstep with MEM1 compared at every entry: it
  must unwind exactly once and store 14 expected results.

### 7. Boot environment (done)

- `rt::setup_boot_environment` (runtime/boot.h) leaves what the IPL and apploader
  leave: the disc id and DVD magic at 0x80000000, boot magic 0x0D15EA5E, memory
  size, console type 3 (retail), arena hi, the FST copied to the top of MEM1
  (0x80000038/3C), the BI2 copy below it (0x800000F4; debug flag 0, no
  arguments), TV mode NTSC (0x800000CC), ARAM size, bus and CPU clocks
  162,000,000 and 486,000,000 (0x800000F8/FC, DETERMINISM R1). CPU: MSR
  FP|IR|DR|RI, HID0, the BATs over MEM1 (cached and uncached), SRs. All are
  configuration constants (R12), nothing from the host.
  - DETERMINISM.md R12 says the 0x800000F4 pointer "stays null"; the real
    apploader sets it to the BI2 copy (OSInit reads the debug flag and the PAD
    spec from it). With the retail BI2 (debug flag 0, argument offset 0) `argc` and
    `argv` are still 0, as R12 intends. Flagged for the lead.
- Real mode: when the guest clears MSR[IR]/[DR] (OSInit's memory-protection setup
  runs a stub through `rfi` at a physical address), MEM1 is also mapped at 0;
  setting translation again unmaps it.
- `icbi` checks that the invalidated block still holds the DOL's bytes (translated
  code is only valid for them); a mismatch is a hard error. Outside the DOL's text
  (the exception vectors OSInit copies to low memory) nothing is checked.
- `sc` is a no-op (the OS system call only toggles HID0[ABE] and returns).
- Hardware (runtime/hw.h), first part of item 10, as far as the boot needs:
  - EXI: transfers complete at once with TCINT; channel 0 device 1 is the IPL
    chip's RTC (a fixed date) and SRAM (a valid default image: checksums,
    language English, flags 0x2C, not progressive); all other devices are absent
    (no memory cards);
  - DSP: reset and halt bits, the ARAM DMA with 16 MiB of ARAM, and the mail
    0x80544348 that the IPL's DSP init microcode sends when unhalted;
  - other registers store and read back what the guest writes; the write-gather
    pipe is captured; every access is logged and counted; a register read a
    million times in a row stops the run (an unanswered poll).
- Exit evidence (2026-10-14), `mvp-boot run --until main` (`local_boot_main`):
  `__start` calls fn_80003300, fn_80003334, fn_80003468, memset (x2),
  fn_80003254, **DBInit**, **fn_8043188C (OSInit)**, fn_800032C0, fn_80003464
  (x2), **fn_80438704 (__init_user)** and **reaches main (fn_8014D63C)** after 841
  translated function entries, 102 MMIO accesses, 1 unwind (OSInit's real-mode
  stub returns through `rfi`), 1 `sc`, 85 `icbi` blocks checked.
- CI: `test_boot_hw` (synthetic disc: the low-memory layout, FST/BI2 copies and
  CPU state; real-mode mapping; the icbi check; EXI RTC/SRAM by imm and DMA and an
  SRAM write; absent devices; the DSP init handshake and ARAM DMA both ways; the
  write-gather capture and the poll limit).

### 8. HLE boundary and SDK log (done)

- **Replacement by name** (`runtime/hle.h`): a registry of symbols.txt names and
  host functions, append-only because the translated code bakes in the indices.
  For each listed function the emitter writes a stub `f_X` (entry hook, entry
  safe point, `rt::hle_call`) and keeps the translation as `f_X_orig`, so direct
  calls, indirect calls and the interpreter all get the replacement; the stub
  returns as the guest `blr` would. The generated table also lists the replaced
  addresses so the lockstep reference interpreter applies the same replacements.
  Replacements today:
  - `OSReport`: formats the guest's printf arguments (PowerPC EABI varargs:
    r3-r10, f1-f8, then the parameter area) and prints to the developer log
    (never guest state);
  - `VMInit`, `VMAlloc`, `VMStoreAllPages`, `VMSetLogStatsCallback`
    (DETERMINISM R10): 0x7E000000 becomes 8 MiB of plain RAM owned by the machine;
    no DSI paging. Without this the VM library patches its exception stubs into
    the DOL's code (fn_8043F8FC), which the icbi check rightly stops.
- **SDK call log** (`mvp-boot run`): at every translated function entry, a call
  whose call site (LR - 4) holds a call to this entry, from a unit outside the
  runtime libraries (`translator/units.h`: splits.txt; dolphin/, sdk/, libc/, libm/,
  libgcc/, libsn/, as K1 counts them), into one of them, is logged by name. A call
  into an SDK function whose symbols.txt name is still `fn_` stops the run with its
  address and unit. `runtime/sdk_names.h` names the three placeholders the K1b
  session identified (OSInit 0x8043188C, DVDInit 0x80422FD8, __init_user
  0x80438704); fn_8040405C (libsn, unknown) is only reached with a debugger.
  - The first run stopped at fn_804061C4 (libsn) "called" from the EA file thread:
    a false positive, since PCinit (named) is a single `b` into it, and the entry
    hook attributed the tail call to PCinit's caller. Fixed by checking that the
    word at LR - 4 is a call to this entry.
- Exit evidence (2026-10-14): `mvp-boot run --until none --max-ticks 200000000`
  reaches `VIWaitForRetrace` (through OSInit, DVDInit, VIInit, PADInit, VM, the
  heap, the EA threads and periodic alarm, GXInit and the first `GXCopyDisp` and
  `VIFlush`), then idles in SelectThread (no interrupts until item 9): **840
  boundary calls into 66 SDK functions, all named**; 14 OSReport lines
  (Dolphin OS banner, SDK build strings, "File server function not available in
  non debug mode" from libsn); 1,027 MMIO accesses; 2,167 bytes written to the
  write-gather pipe. Two runs give byte-identical logs (sha1 77bee50b...,
  18,932 bytes; the log stays in build/).
- **No unnamed SDK function is reached on this path**, so there is no new K1
  input yet.
- `local_disasm` now also reads the symbol names from dtk's listing itself (the
  `# .sec:0xOFF | 0xADDR` header before each `.fn`/`.obj`/`.sym`): renames that
  land on main between the listing build and this worktree no longer break the
  check.

## Decisions to record (for the lead)

- E0b-FP1: the FP model above (exact integer softfloat as the single source of
  truth; fast paths later only behind a differential test against it).
- E0b-FP2: FPSCR status bits are not modeled; estimates are correctly rounded.
  Both are deterministic. Revisit if a game path reads FPSCR status or if a
  hardware table for the estimates becomes available under a permissive license.

## Next step

Item 9: virtual clock (time base and decrementer from `c.ticks`), DEC and PI
interrupts delivered at safe points, idle skip in SelectThread. The counters and
safe points are already emitted (see item 9 notes when written).
