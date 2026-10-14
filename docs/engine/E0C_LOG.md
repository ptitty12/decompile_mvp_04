# E0c log: unwinds, controller input, AX voices

Working log for the three follow-ups that `docs/engine/E0B_LOG.md` ("Next step")
recommended after E0b. Same build and test instructions as E0b (`engine/tools/msvc.cmd`,
presets `msvc`/`vs`, `ctest --preset msvc`; `MVP_DISC` and `MVP_DTK_ASM` for the
local tests).

## Status

| # | Item | State |
|---|---|---|
| 1 | Fewer unwinds per thread switch (D4, performance) | Done |
| 2 | Controller input (R14): per-frame input queue, scripted input | Done |
| 3 | AX voice state (R8) | |

## 1. Unwinds per thread switch (done)

**Cause.** 43,271 of E0b's 46,288 unwinds (measured by target address) went to
0x804378BC, the return address of SelectThread's `bl OSSaveContext` (fn_804336B4).
That is SelectThread loading the *current* thread again (OSYieldThread with no other
ready thread of its priority, or the idle loop waking the thread whose stack it runs
on): OSLoadContext's `rfi` lands in the SelectThread frame that called it. The
translated `rfi` threw `Unwind`, every native frame was abandoned, and the
interpreter ran the rest of SelectThread and all the frames above it until they
returned (11.75 % of all instructions run).

**Change: unwinding by return, resume labels** (`runtime/native.h`, the emitter):
- No C++ exception for control flow any more. A translated `rfi` sets
  `rt::g_unwinding` and returns; a call that comes back with another PC (or with
  the flag set) goes to its function's resume block.
- **Resume labels**: every call's return address and every loop back edge inside a
  function (125,559 in the DOL). The resume block continues in this frame when
  the PC is one of the function's resume labels *and* the stack pointer is the one
  the frame had at that call or safe point: the guest continues in this very
  activation (same function, same stack frame), so the native frame is still the
  right one ("in-frame resume"). Otherwise the frame returns with the flag set and
  the next frame up tries.
- The top-level dispatcher ends an unwind (counted as one unwind) and continues at
  the PC: a function entry runs natively, a resume label re-enters its function's
  body there (the function is called with `rt::g_resume` set and skips its
  prologue), anything else is interpreted. So after a real switch the new thread
  runs natively from its first instruction instead of in the interpreter.
- `run_handler` (exceptions): an unwind that reaches it ends the exception; back at
  the interrupted point and stack it returns normally, elsewhere it returns with
  the flag set and the interrupted frames unwind from their safe point.
  `call_indirect`'s nested interpreter loop returns as soon as an unwind passes.
- Exactness argument: translated frames keep no guest state on the C++ stack, so
  running a guest instruction in any frame, or in the interpreter, is the same.
  Safe points are unchanged (a back-edge label sits before its safe-point check;
  the prologue, with the entry hook, runs only on real entries). The stack-pointer
  test only decides *which* frame runs the code (it keeps guest code of another
  thread out of the exception handler's frames); behaviour does not depend on it.
- It also suits E2: WebAssembly needs no exception handling for thread switches.

**Exit evidence (2026-10-14)**, `mvp-boot run --until 0x8035A198` (the
`local_boot_twice` point, 9.796 s of guest time), before = origin/main aae61bb4, after
= this change, same machine, three runs each:

| | before | after |
|---|---:|---:|
| SDK call log | sha1 `db1dded...6e`, 203,393,662 bytes | **identical** |
| function entries, instructions, VI fields, interrupts, idle skips, DVD/DSP/GX counts | | **identical** |
| thread switches | 6,265 | 6,265 |
| unwinds | 46,288 (7.39 per switch) | **6,266 (1.000 per switch)** |
| in-frame resumes | - | 40,022 |
| resume entries (dispatcher re-enters a body) | - | 18,878 |
| interpreted instructions | 193,214,000 (11.75 %) | **190,262 (0.0116 %)** |
| host time (MSVC `/Od`, per-entry trace on) | 22.10 / 22.28 / 22.28 s | **18.05 / 18.12 / 18.26 s** |

The remaining interpreted instructions are the OS's exception vector code in low
memory (not DOL code, never translated). Host time is now dominated by the `/Od`
translated code and `mvp-boot`'s per-entry trace hook (30 M entries, each decoding
its call site; 5.9 M of them build and hash an SDK log line).

`local_boot_twice` passes (two runs byte-identical); `ctest --preset msvc`: 17/17.

**Tests (data-free)**: the synthetic program (`translator/tests/synth.h`) gained
`save_ctx`/`load_ctx` (OSSaveContext/OSLoadContext in miniature: r1, LR, MSR, `rfi`)
and three switches: `yield_self` reloads its own context (in-frame resume),
`rec(1)` loads `rec(2)`'s context (same function, other stack pointer: the inner
frame must not resume, the outer one does), and `b_fn` loads the context `a_fn`
saved after `a_fn` returned (an unwind to the top, then the dispatcher re-enters
`a_fn`'s body and `main`'s). `test_emit_lockstep` runs it against the interpreter
and checks the exact counts: 2 unwinds, 2 in-frame resumes, 3 resume entries, 2
interpreted instructions.

**For the lead (docs outside `docs/engine/`):** ARCHITECTURE §9 D4 says the
interpreter runs what is left of the suspended frames; with this change it is
native code re-entered at resume labels, and same-activation reloads do not unwind
at all.

## 2. Controller input (done)

**Design** (`runtime/input.h`, `runtime/hle.h`):
- **Frame poll** = one pass of the frame loop (fn_80148930), at the entry of
  fn_8014865C (DETERMINISM §2.3), numbered 0, 1, 2, ... from power-on. A new kind of
  HLE entry, a *hook* (`HleKind::Before`), runs host code right after a translated
  function's entry and before its body (not on resumes inside it). Game functions
  are keyed by retail address (0x8014865C), not by placeholder name; `mvp-xlat
  emit-cpp` now fails if any replacement or hook matches no function (a rename in
  symbols.txt can no longer drop one silently).
- **Input queue** (`InputQueue`): at each frame poll it consumes exactly one
  frame's `FrameInput` (four `PadState`s): a pushed one, else its source's (a
  script, later the netplay peer), else the previous frame's again. Before the
  first poll it returns the boot input.
- **PadState v1** (versioned API): connected, the SDK's button bits, the two
  sticks, triggers, analog A/B, as PADRead reports them after origin correction.
  Wire form: 1 version byte + 11 bytes per port (45 bytes per frame);
  `decode_frame` rejects other versions, reserved bits and controls on a missing
  pad.
- **PADRead is replaced** (by name): it writes the current frame's input into the
  game's PADStatus[4] (err 0, or -1 = no controller with zeros; the padding byte is
  untouched) and returns the connected channels' bits. Every PADRead between two
  polls returns the same frame's input, so a frame's input is part of the
  deterministic state wherever it comes from. PADInit/PADReset/PADRecalibrate stay
  SDK code (they only program SI; nothing reads their results any more).
- **Scripts** (`InputScript`): `mvp-input 1` header, then `<frame> <port> <command>`
  lines: `press`/`release` buttons, `tap N` buttons, `stick`, `cstick`, `trigger`,
  `analog`, `connect`, `disconnect`; state holds until changed; errors name the line.
- **`mvp-boot run`**: `--input SCRIPT`, `--frames N` (stop at the poll of frame N,
  after frames 0..N-1), `--ports MASK` (default port 1 connected, nothing pressed),
  `--frame-log FILE` (one line per poll: frame, time base, SDK calls so far, the
  frame's input in wire form; hashed in the report).

**Who consumes input, and how often** (measured with a back-chain at PADRead,
2026-10-14): PADRead's only caller is fn_8000A44C (the PAD object's poll,
`Unk800085B0::vslot42`; the port-0 object reads all four ports into lbl_806E0240
and calls PADClampCircle, the others use that array). It runs from the *per-tick*
pad update: fn_80148698 (one logic tick) -> fn_802D75D4 -> fn_8035F3A0 ->
`Unk802D73B4_Mgr::s13` -> fn_8000A44C -> PADRead, i.e. **once per logic tick, 1 to 3
times per frame**, plus once at boot (fn_8014BEB8 -> fn_802D75D4). fn_802D7588 (`s6`,
called by fn_8014865C) does not reach PADRead. 0 to 700 frames: 701 polls and 1,190
PADReads; the first poll is at 9.80 s of guest time, frame 700 at 33.1 s (frames
take 1 to 4.3 sixtieths while loading and playing the intro movie). With the queue
all ticks of a frame see that frame's input. **For the lead:** DETERMINISM §2.3
(and R14) say PADRead runs once per pass through `fn_802D7588 -> s6`; in this run
it runs per tick through `fn_802D75D4 -> s13` (the tagged-I link is wrong).

**Exit evidence (2026-10-14):**
- `test_input` (data-free, 6 cases, ~100 assertions): one input consumed per poll
  in order, hold and source fallbacks, the boot input; wire round trip and
  rejections; scripts (events, tap, sticks, connect/disconnect, going back, errors
  by line); PADRead and the frame poll hook on a bare machine (bytes written, error
  codes, padding untouched, return mask, same input for two reads in a frame).
- START-press experiments to frame 700 (one run each, no input = reference): a
  `tap 3 START` at frame 150 changes the time base from frame 152 and the SDK call
  count from frame 211; at 280, 450 and 570 the SDK call count changes at the very
  next poll (281, 451, 571), and the runs with the press at 280 and 450 reach frame
  700 about 2.6 s of guest time earlier (the press skips something in the intro).
- `local_input_start` (new ctest, 176 s): `280 1 tap 3 START`, 290 frames, three
  runs: the two runs with the script are byte-identical (report, SDK log sha1
  `c6d85264...`, frame log); the run without differs (`e652d99f...`); the frame logs
  are identical through frame 280 and first differ at frame 281.
- `local_boot_twice` still passes; its SDK log hash changed to `0054fb22...` (the
  boot-time PADRead now sees a connected controller: 36 more function entries).
