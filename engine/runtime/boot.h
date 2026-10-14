// Boot environment (E0b item 7): what the IPL and the disc's apploader leave in
// memory and in the CPU before they jump to the DOL's entry point.
//
// Values are configuration fixed per match (DETERMINISM.md R12), never read from
// the host: console type, TV mode, memory sizes and clocks are constants here.
#pragma once

#include <cstdint>

#include "runtime/machine.h"
#include "vfs/disc_check.h"

namespace mvp::rt {

struct BootConfig {
  u32 console_type = 0x00000003;  // retail, latest production board
  u32 tv_mode = 0;                // 0 = NTSC (0x800000CC)
  u32 aram_size = 0x01000000;     // 16 MiB
  u32 bus_clock = 162000000;      // 0x800000F8 (R1)
  u32 cpu_clock = 486000000;      // 0x800000FC (R1)
};

// Where the boot environment put things, for logs and tests.
struct BootLayout {
  u32 fst = 0, fst_size = 0;  // FST copy at the top of MEM1
  u32 bi2 = 0;                // BI2 copy, just below the FST
  u32 arena_hi = 0;           // = bi2: the OS arena ends where the copies start
};

// Writes the low-memory globals (0x80000000-0x800000FF and 0x800030xx), copies
// the disc's FST and BI2 to the top of MEM1, and sets the CPU state the IPL
// leaves (MSR, HID0, BATs, SRs). Call after Machine::load_dol.
BootLayout setup_boot_environment(Machine& m, const vfs::Disc& disc, const BootConfig& cfg = {});

}  // namespace mvp::rt
