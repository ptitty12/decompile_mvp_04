# E0c log: unwinds, controller input, AX voices

Working log for the three follow-ups that `docs/engine/E0B_LOG.md` ("Next step")
recommended after E0b. Same build and test instructions as E0b (`engine/tools/msvc.cmd`,
presets `msvc`/`vs`, `ctest --preset msvc`; `MVP_DISC` and `MVP_DTK_ASM` for the
local tests).

## Status

| # | Item | State |
|---|---|---|
| 1 | Fewer unwinds per thread switch (D4, performance) | Done |
| 2 | Controller input (R14): per-frame input queue, scripted input | |
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
