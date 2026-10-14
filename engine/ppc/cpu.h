// Guest CPU state, guest memory and the runtime hooks the semantics library calls.
//
// Everything a guest thread needs to resume lives here or in guest memory (D4):
// no host pointers into translated code, no host stack state.
#pragma once

#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <string>

#include "common/bytes.h"

namespace mvp::ppc {

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using s32 = std::int32_t;
using s64 = std::int64_t;

// A guest error the runtime cannot continue from: unmapped access, an invalid or
// unsupported instruction, a guest trap. Carries the guest PC.
class GuestFault : public std::runtime_error {
 public:
  GuestFault(u32 pc, const std::string& what) : std::runtime_error(what), pc_(pc) {}
  u32 pc() const { return pc_; }

 private:
  u32 pc_;
};

// Memory-mapped I/O and anything else outside RAM. Implemented by the runtime.
class Io {
 public:
  virtual ~Io() = default;
  virtual u32 read(u32 addr, int size) = 0;               // size 1, 2 or 4; value right-aligned
  virtual void write(u32 addr, u32 value, int size) = 0;  // size 1, 2 or 4
};

// Guest address space: 65,536 pages of 64 KiB. A mapped page points at host bytes
// (big-endian guest data, D8); an unmapped page (null) goes to Io. Regions are
// mapped contiguously in host memory, so an access that crosses a page boundary
// inside one region is still a plain host access; region ends carry guard bytes.
struct Memory {
  static constexpr u32 kPageShift = 16;
  static constexpr u32 kPageSize = 1u << kPageShift;
  u8* page[1u << (32 - kPageShift)] = {};
  Io* io = nullptr;

  // Maps [guest, guest+size) to host bytes (size and guest are page multiples).
  void map(u32 guest, u8* host, u32 size) {
    for (u32 off = 0; off < size; off += kPageSize) page[(guest + off) >> kPageShift] = host + off;
  }
  u8* host(u32 ea) const {
    u8* p = page[ea >> kPageShift];
    return p ? p + (ea & (kPageSize - 1)) : nullptr;
  }
};

// Paired-single FPR: both halves as raw IEEE double bits. Scalar FP uses ps0.
struct Fpr {
  u64 ps0 = 0;
  u64 ps1 = 0;
};

struct Cpu;

// Runtime services the semantics library needs. The runtime implements them on
// the virtual clock (time base, decrementer); nothing here may read host time.
class Hooks {
 public:
  virtual ~Hooks() = default;
  virtual u64 time_base(Cpu& c) = 0;
  virtual void set_time_base(Cpu& c, u64 tb) = 0;
  virtual u32 decrementer(Cpu& c) = 0;
  virtual void set_decrementer(Cpu& c, u32 v) = 0;
  virtual void msr_changed(Cpu& c, u32 old_msr) = 0;  // after mtmsr / rfi
  virtual void icbi(Cpu& c, u32 ea) = 0;              // instruction-cache block invalidate
  virtual void system_call(Cpu& c) = 0;               // sc (PC already points past it)
};

struct Cpu {
  u32 gpr[32] = {};
  Fpr fpr[32] = {};
  u32 cr = 0;
  u32 lr = 0, ctr = 0;
  u32 xer_so = 0, xer_ov = 0, xer_ca = 0;  // each 0 or 1
  u32 xer_low = 0;                         // XER bits 3-31 (string byte count and reserved bits)
  u32 fpscr = 0;
  u32 msr = 0;
  u32 pc = 0;
  u32 reserve = 0, reserve_addr = 0;  // lwarx / stwcx.
  u32 sr[16] = {};
  u32 spr[1024] = {};  // every other SPR by number: GQRs (912-919), HID0-2, SRR0/1, SPRGs, BATs, ...

  Memory* mem = nullptr;
  Hooks* hooks = nullptr;

  u32 xer() const { return xer_so << 31 | xer_ov << 30 | xer_ca << 29 | (xer_low & 0x1FFFFFFF); }
  void set_xer(u32 v) {
    xer_so = v >> 31;
    xer_ov = (v >> 30) & 1;
    xer_ca = (v >> 29) & 1;
    xer_low = v & 0x1FFFFFFF;
  }
};

// FPSCR fields the semantics use. Status bits (FX, FEX, VX*, OX, UX, ZX, XX, FR,
// FI, FPRF) are not modeled: they stay as the guest last wrote them (E0B_LOG).
namespace fpscr {
inline constexpr u32 NI = 1u << 2;  // non-IEEE mode: denormal results flush to zero
inline constexpr u32 RN = 3u;       // rounding mode: 0 nearest, 1 zero, 2 +inf, 3 -inf
}  // namespace fpscr

// MSR bits the runtime cares about.
namespace msr {
inline constexpr u32 EE = 1u << 15;
inline constexpr u32 FP = 1u << 13;
inline constexpr u32 IR = 1u << 5;
inline constexpr u32 DR = 1u << 4;
inline constexpr u32 RI = 1u << 1;
}  // namespace msr

}  // namespace mvp::ppc
