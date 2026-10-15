// WebAssembly emitter (E2, D2): translates the recovered functions straight to a
// wasm32 binary module, with no C compiler in the loop, so the player's browser
// can translate the game itself.
//
// The module imports the runtime's linear memory and function table, a few
// addresses (g_unwinding, g_resume, g_entry_hook) and the runtime services it
// calls ("rt" imports; runtime/wasm_host.h implements them). Guest memory stays
// big-endian (D8): in-module helpers byte-swap through the 64 KiB page table,
// and anything off the fast path (MMIO, page-crossing, unmapped) goes to the
// runtime. The calling convention, safe points, unwinding and resume labels
// are those of the C++ emitter (runtime/native.h, E0c), so translated
// functions of either kind are interchangeable `void f(Cpu&)` table entries.
//
// Code shape:
// - GPRs, CR, LR, CTR, XER[CA] and XER[SO] live in wasm locals; FPRs and
//   everything else stay in the Cpu struct. Dataflow over each function decides
//   which locals are spilled before a call, a helper or a return ("dirty") and
//   which are reloaded after one ("live"), using ppc::effects();
// - instructions the emitter knows (integer ALU, compares, rotates, CR logic,
//   loads and stores, branches, SPR moves) are inline; every other one calls the
//   runtime's semantics (rt.exec: the interpreter's execute_plain), with only its
//   own registers spilled and reloaded;
// - floating point (E2d): FPRs stay in the Cpu struct as raw bits; arithmetic,
//   compares, conversions and paired singles have an inline fast path on IEEE
//   f64 arithmetic, used only where it provably equals the exact model
//   (ppc/fp.h), else the whole instruction goes to rt.exec (rules: wasm_emit.cpp,
//   "floating point"); quantized loads and stores, lmw and stmw are in-module
//   helpers with a one-page fast path;
// - control flow: one block per label, nested so forward branches are direct
//   `br`s; backward branches, jump tables, resume labels and secondary entries
//   go through a loop with a br_table dispatcher;
// - the virtual clock (c.ticks) is a local, stored exactly where the runtime
//   can observe it; `return_call` is used only for guest tail calls.
//
// The output is derived from the player's disc: it is never written outside
// build/ (or the browser's own storage).
#pragma once

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

#include "translator/cfg.h"
#include "translator/emit_cpp.h"

namespace mvp::xlat {

struct WasmEmitOptions {
  std::vector<HleSpec> hle;  // replacements and hooks, as for emit_cpp
  // Spill dirty registers before every guest memory access too, so the CPU
  // state is exact when an MMIO handler stops the run (lockstep tests).
  bool precise_io = false;
  // Run every non-branch instruction through the runtime (rt.exec): for tests
  // of the helper path and for measuring what inlining buys.
  bool inline_ops = true;
  // Add a "name" custom section (function names: the guest symbol, the helpers
  // and imports), for profilers. Off by default: it only costs bytes.
  bool names = false;
  // Check MSR[FP] before FPU instructions (floating-point unavailable, E3a): the
  // first of each block, as the C++ emitter does. Off only for tests that compare
  // single instructions with execute_plain(), which has no such check.
  bool fpu_checks = true;
  // Import the memory as shared, with a maximum of 4 GiB (P2: the threaded
  // browser engine, whose memory is a SharedArrayBuffer). The code is the same.
  bool shared_memory = false;
};

// A guest address and the table slot (relative to the module's table base) of
// the function it belongs to.
struct WasmSlot {
  std::uint32_t address = 0;
  std::uint32_t slot = 0;
};

struct WasmEmitStats {
  std::size_t functions = 0, wasm_functions = 0, entries = 0, instructions = 0, inline_insns = 0, helper_insns = 0,
              branch_insns = 0, resume_labels = 0, dispatch_functions = 0, spills = 0, reloads = 0, hle_stubs = 0;
  std::size_t code_bytes = 0;
  std::vector<std::size_t> helper_by_op;  // per ppc::Op: instructions that go through rt.exec
};

struct WasmModule {
  std::vector<std::uint8_t> bytes;  // the binary module
  std::uint32_t slots = 0;          // table entries it fills, from its imported table base
  std::vector<WasmSlot> entries;    // every entry point -> its function's slot (rt::g_native)
  std::vector<WasmSlot> resume;     // resume labels -> the slot of their function's first entry (rt::g_resume_labels)
  // Resume labels -> the dispatcher index rt.resume returns for them.
  std::vector<std::pair<std::uint32_t, std::uint32_t>> resume_index;
  std::vector<std::uint32_t> safe, idle;            // safe points and idle spins (as emit_cpp's table)
  std::vector<std::pair<std::uint32_t, int>> hle_sites;  // replaced functions for the interpreter
  std::vector<int> hle_matched;                    // HleSpec::index of every spec that found its function
  WasmEmitStats stats;
};

// Import names, in import order ("rt" module). The host must provide each one.
const std::vector<std::string>& wasm_import_names();

// P2: the write-gather pipe's state the module's store helpers append to
// directly (env.wgp, the address of runtime/hw.h's WgpState): a store of 1, 2
// or 4 bytes to 0xCC008000 that leaves fewer than 32 bytes gathered, while
// `fast` is set, is appended big-endian at buf + n without calling the runtime,
// which then counts it (fast_stores) and ends the poll detector's run
// (last_read = 0), as Hardware::write would. Offsets (the runtime checks them):
struct WasmWgpLayout {
  static constexpr std::uint32_t kBuf = 0, kN = 32, kFast = 36, kLastRead = 40, kFastStores = 48;
};

// Trap codes passed to rt.trap.
enum class WasmTrap : std::uint32_t {
  InvalidInstruction = 0,
  UnconditionalTrap = 1,
  RanOffEnd = 2,
  JumpOutsideTable = 3,
  ExternalControl = 4,
  BadEntry = 5,
};
const char* wasm_trap_text(std::uint32_t code);

bool emit_wasm(const ProgramCfg& p, const WasmEmitOptions& opt, WasmModule* out, std::string* error);

}  // namespace mvp::xlat
