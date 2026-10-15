// Guest memory accesses for the semantics library: big-endian, through the
// 64 KiB page table, falling back to Io for MMIO and unmapped pages.
#pragma once

#include "ppc/cpu.h"

namespace mvp::ppc {

[[noreturn]] void fault_unmapped(Cpu& c, u32 ea, bool write, int size);

// P2 (the browser's threaded engine): guest memory a GX command already issued
// will still read on the render thread, per 2^kGpShift bytes of the 32 MiB
// physical space (entry gp_entry(ea); nonzero: pending). A write there first waits for the
// render thread (gp_write_wait, through the hook the runtime sets), so the
// render thread reads what the command saw. The translated module checks its
// own stores (env.gp_pages); these are the semantics library's and the
// hardware model's. Natively nothing is ever pending.
constexpr u32 kGpShift = 6;  // the translated module's checks use the same (xlat::WasmGpLayout)
constexpr u32 kGpEntries = 1u << (25 - kGpShift);
inline u32 gp_entry(u32 ea) { return (ea >> kGpShift) & (kGpEntries - 1); }
extern std::uint32_t g_gp_pages[kGpEntries];
extern void (*g_gp_wait_hook)(u32 first, u32 last);
inline void gp_check(u32 ea, u32 n) {
#ifdef __EMSCRIPTEN__
  if (!n) return;
  const u32 last = ea + n - 1;
  if (n <= (1u << kGpShift)) {
    if (!(g_gp_pages[gp_entry(ea)] | g_gp_pages[gp_entry(last)])) return;
  }
  if (g_gp_wait_hook) g_gp_wait_hook(ea, last);
#else
  (void)ea, (void)n;
#endif
}

inline u8* host_span(Cpu& c, u32 ea, u32 n) {
  u32 off = ea & (Memory::kPageSize - 1);
  u8* p = c.mem->page[ea >> Memory::kPageShift];
  // An access that runs past the page end is only a plain host access if the
  // next page continues the same host region.
  if (p && off + n > Memory::kPageSize) {
    u8* next = c.mem->page[((ea >> Memory::kPageShift) + 1) & 0xFFFF];
    if (next != p + Memory::kPageSize) return nullptr;
  }
  return p ? p + off : nullptr;
}

u32 slow_read(Cpu& c, u32 ea, int size);
void slow_write(Cpu& c, u32 ea, u32 v, int size);

inline u32 read8(Cpu& c, u32 ea) {
  u8* p = host_span(c, ea, 1);
  return p ? *p : slow_read(c, ea, 1);
}
inline u32 read16(Cpu& c, u32 ea) {
  u8* p = host_span(c, ea, 2);
  return p ? be16(p) : slow_read(c, ea, 2);
}
inline u32 read32(Cpu& c, u32 ea) {
  u8* p = host_span(c, ea, 4);
  return p ? be32(p) : slow_read(c, ea, 4);
}
inline u64 read64(Cpu& c, u32 ea) {
  u8* p = host_span(c, ea, 8);
  if (p) return be64(p);
  u64 hi = slow_read(c, ea, 4);
  return hi << 32 | slow_read(c, ea + 4, 4);
}
inline void write8(Cpu& c, u32 ea, u32 v) {
  u8* p = host_span(c, ea, 1);
  if (p) {
    gp_check(ea, 1);
    *p = static_cast<u8>(v);
  } else {
    slow_write(c, ea, v & 0xFF, 1);
  }
}
inline void write16(Cpu& c, u32 ea, u32 v) {
  u8* p = host_span(c, ea, 2);
  if (p) {
    gp_check(ea, 2);
    put_be16(p, static_cast<u16>(v));
  } else {
    slow_write(c, ea, v & 0xFFFF, 2);
  }
}
inline void write32(Cpu& c, u32 ea, u32 v) {
  u8* p = host_span(c, ea, 4);
  if (p) {
    gp_check(ea, 4);
    put_be32(p, v);
  } else {
    slow_write(c, ea, v, 4);
  }
}
inline void write64(Cpu& c, u32 ea, u64 v) {
  u8* p = host_span(c, ea, 8);
  if (p) {
    gp_check(ea, 8);
    put_be64(p, v);
  } else {
    slow_write(c, ea, static_cast<u32>(v >> 32), 4);
    slow_write(c, ea + 4, static_cast<u32>(v), 4);
  }
}

}  // namespace mvp::ppc
