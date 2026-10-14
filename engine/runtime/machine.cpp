#include "runtime/machine.h"

#include <cstring>

namespace mvp::rt {

Machine::Machine() : mem1_(kMem1Size + kGuard, 0), mem_(std::make_unique<ppc::Memory>()) {
  // MEM1 through the cached (0x80000000) and uncached (0xC0000000) windows.
  mem_->map(0x80000000u, mem1_.data(), kMem1Size);
  mem_->map(0xC0000000u, mem1_.data(), kMem1Size);
  cpu_.mem = mem_.get();
}

void Machine::load_dol(const vfs::Dol& dol) {
  for (const auto& s : dol.sections()) {
    u32 off = s.address & 0x3FFFFFFFu;
    if (off + s.size <= kMem1Size) std::memcpy(&mem1_[off], dol.bytes().data() + s.offset, s.size);
  }
  u32 bss = dol.bss_address() & 0x3FFFFFFFu;
  if (bss + dol.bss_size() <= kMem1Size) {
    // The bss range covers small-data sections that the DOL also loads; zero only
    // the bytes no loaded section supplies.
    for (u32 a = 0; a < dol.bss_size(); ++a) {
      u32 addr = dol.bss_address() + a;
      if (!dol.section_at(addr)) mem1_[bss + a] = 0;
    }
  }
  cpu_.pc = dol.entry();
}

}  // namespace mvp::rt
