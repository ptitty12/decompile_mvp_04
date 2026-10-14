#include "runtime/boot.h"

#include <cstring>

#include "common/bytes.h"
#include "ppc/isa.h"

namespace mvp::rt {

namespace {
constexpr u32 kMem1Top = 0x81800000u;
u32 align_down(u32 v, u32 a) { return v & ~(a - 1); }
}  // namespace

BootLayout setup_boot_environment(Machine& m, const vfs::Disc& disc, const BootConfig& cfg) {
  u8* mem = m.mem1();
  auto w32 = [&](u32 addr, u32 v) { put_be32(mem + (addr & 0x01FFFFFFu), v); };
  BootLayout L;

  // FST and BI2 copies at the top of MEM1, as the apploader leaves them.
  const auto& fst = disc.gcm.fst_bytes();
  L.fst_size = static_cast<u32>(fst.size());
  u32 fst_max = disc.gcm.fst_max_size() > L.fst_size ? disc.gcm.fst_max_size() : L.fst_size;
  L.fst = align_down(kMem1Top - fst_max, 32);
  std::memcpy(mem + (L.fst & 0x01FFFFFFu), fst.data(), fst.size());
  const auto& bi2 = disc.gcm.bi2();
  L.bi2 = align_down(L.fst - static_cast<u32>(bi2.size()), 32);
  std::memcpy(mem + (L.bi2 & 0x01FFFFFFu), bi2.data(), bi2.size());
  L.arena_hi = L.bi2;

  // OSBootInfo at 0x80000000: disc id (the first 32 bytes of the disc header,
  // including the DVD magic at 0x1C), then the IPL's fields.
  std::memcpy(mem, disc.gcm.boot().data(), 0x20);
  w32(0x80000020, 0x0D15EA5E);  // boot magic: normal boot
  w32(0x80000024, 0x00000001);  // version
  w32(0x80000028, Machine::kMem1Size);  // memory size
  w32(0x8000002C, cfg.console_type);
  w32(0x80000030, 0);           // arena lo: the OS uses its linked default
  w32(0x80000034, L.arena_hi);  // arena hi
  w32(0x80000038, L.fst);       // FST location
  w32(0x8000003C, fst_max);     // FST max length
  // 0x80000040-0x8000005F: debugger monitor fields stay zero (no debugger).
  w32(0x800000CC, cfg.tv_mode);
  w32(0x800000D0, cfg.aram_size);
  w32(0x800000F0, Machine::kMem1Size);  // simulated memory size
  w32(0x800000F4, L.bi2);               // BI2 copy (debug flag 0: no debugger, no arguments)
  w32(0x800000F8, cfg.bus_clock);
  w32(0x800000FC, cfg.cpu_clock);
  // 0x800030xx (reset code, boot buttons, system time bias, ...) stay zero:
  // a cold boot with no buttons held.

  // CPU state the IPL leaves: translation on (BATs over MEM1 and the uncached
  // window), FP available, caches on, recoverable.
  ppc::Cpu& c = m.cpu();
  c.msr = ppc::msr::FP | ppc::msr::IR | ppc::msr::DR | ppc::msr::RI;
  c.spr[ppc::spr::HID0] = 0x0011C464;
  c.spr[528] = 0x80001FFF;  // IBAT0U: 0x80000000, 256 MiB
  c.spr[529] = 0x00000002;  // IBAT0L
  c.spr[530] = 0xC0001FFF;  // IBAT1U: 0xC0000000, 256 MiB
  c.spr[531] = 0x0000002A;  // IBAT1L: cache-inhibited, guarded
  c.spr[536] = 0x80001FFF;  // DBAT0U
  c.spr[537] = 0x00000002;  // DBAT0L
  c.spr[538] = 0xC0001FFF;  // DBAT1U
  c.spr[539] = 0x0000002A;  // DBAT1L
  for (u32& sr : c.sr) sr = 0x80000000;
  c.pc = disc.dol.entry();
  return L;
}

}  // namespace mvp::rt
