// What translated (native C++) guest code calls into, and how the runtime runs it.
//
// Calling convention of a translated function `void f_XXXXXXXX(Cpu&)`:
// - the caller sets LR (as the guest `bl` would) and calls;
// - the guest `blr` sets c.pc = LR & ~3 and returns;
// - after the call the caller checks c.pc against its own return address. Any
//   other value means guest code changed the return path (a context switch, a
//   longjmp): the caller calls unwind(), which throws Unwind to the dispatcher,
//   and the dispatcher resumes at c.pc in the reference interpreter (D4).
#pragma once

#include <cstdint>
#include <stdexcept>
#include <vector>

#include "ppc/cpu.h"

namespace mvp::rt {

using ppc::Cpu;
using u32 = std::uint32_t;
using GuestFn = void (*)(Cpu&);

// A translated entry point: guest address and its native function.
struct NativeEntry {
  u32 address;
  GuestFn fn;
};

// Thrown to abandon the native frames; the dispatcher resumes at c.pc.
struct Unwind {};

// Number of times run() resumed at c.pc after an Unwind (statistics).
extern std::uint64_t g_unwinds;

// Optional hook run at every translated function entry (tracing, lockstep).
using EntryHook = void (*)(Cpu&, u32 address);
extern EntryHook g_entry_hook;

inline void on_entry(Cpu& c, u32 address) {
  if (g_entry_hook) g_entry_hook(c, address);
}

[[noreturn]] void unwind(Cpu& c);
[[noreturn]] void trap(Cpu& c, u32 address, const char* why);

// Calls the guest function at `target` (LR already set): native if translated,
// otherwise in the interpreter until it returns to LR.
void call_indirect(Cpu& c, u32 target);
// bla to an address outside the DOL (code the OS installs in low memory).
void absolute_call(Cpu& c, u32 target);

// The table of translated entry points (set by the translated code's
// registration, see translator/emit_cpp.h).
class NativeTable {
 public:
  void set(const NativeEntry* entries, std::size_t count);
  GuestFn find(u32 address) const;
  bool empty() const { return dense_.empty(); }

 private:
  u32 base_ = 0;
  std::vector<GuestFn> dense_;  // (address - base) / 4
};
extern NativeTable g_native;

// Runs guest code from c.pc. Whenever c.pc is a translated entry point, the
// native function runs; anything else, and the frames left after an Unwind, run
// in the reference interpreter, which enters native code again as soon as it
// reaches a translated entry. Returns only by exception (GuestFault, or whatever
// an Io handler or hook throws to stop the run).
void run(Cpu& c);

}  // namespace mvp::rt
