// HLE: SDK functions the engine replaces with host code, by symbols.txt name
// (E0b item 8, ARCHITECTURE §5).
//
// The translator emits, for every function whose name is in hle_table(), a stub
// `f_X` that calls rt::hle_call with the table index and a pointer to the
// translated original (`f_X_orig`). Direct calls, indirect calls and the
// interpreter all reach the stub, so the replacement applies everywhere. After
// the replacement runs, hle_call returns as the guest `blr` would (c.pc = LR).
//
// Replacements read their arguments from the guest registers and memory and
// must change guest state only as the original would (determinism invariant).
#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "runtime/native.h"

namespace mvp::rt {

using HleFn = void (*)(Cpu& c, GuestFn original);

struct HleEntry {
  const char* name;  // symbols.txt name
  HleFn fn;
  const char* why;   // what the replacement does instead
};

// The registry. Its order is part of the translated code (indices are baked in),
// so entries are only ever appended.
const std::vector<HleEntry>& hle_table();
int hle_index(const std::string& name);  // -1 when not replaced

void hle_call(Cpu& c, int index, GuestFn original);

// Replaced functions by guest address (registered by the translated code's
// table), so the reference interpreter can apply the same replacements.
struct HleSite {
  u32 address;
  int index;
};
void set_hle_sites(const HleSite* sites, std::size_t count);
int hle_site(u32 address);  // index, or -1
// Runs the replacement at c.pc for the interpreter: as if called (LR already holds
// the return address), then returns to LR. Returns false when c.pc has none.
bool hle_interpret(Cpu& c);

// Where OSReport output goes (a log for the developer, never guest state).
extern void (*g_report)(const std::string& line);
extern std::uint64_t g_report_count;

// printf-style formatting of a guest format string with the PowerPC EABI
// variadic arguments of the current call (r3 = format when first_gpr = 3).
std::string format_guest(Cpu& c, u32 fmt, int first_gpr);

}  // namespace mvp::rt
