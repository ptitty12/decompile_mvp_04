#include "runtime/native.h"

#include <algorithm>
#include <cstdio>

#include "ppc/interp.h"

namespace mvp::rt {

EntryHook g_entry_hook = nullptr;
std::uint64_t g_unwinds = 0;
std::uint64_t g_interpreted = 0;
int g_exception_depth = 0;
u32 g_exception_lr = 0;
NativeTable g_native;
SafeSet g_safe;
SafeSet g_idle;

void SafeSet::set(const u32* addrs, std::size_t count) {
  bits_.clear();
  if (!count) return;
  u32 lo = addrs[0], hi = addrs[0];
  for (std::size_t k = 0; k < count; ++k) {
    lo = std::min(lo, addrs[k]);
    hi = std::max(hi, addrs[k]);
  }
  base_ = lo;
  bits_.assign((hi - lo) / 4 + 1, false);
  for (std::size_t k = 0; k < count; ++k) bits_[(addrs[k] - lo) / 4] = true;
}

void unwind(Cpu&) { throw Unwind{}; }

void trap(Cpu& c, u32 address, const char* why) {
  char b[128];
  std::snprintf(b, sizeof b, "guest trap at 0x%08X: %s", address, why);
  c.pc = address;
  throw ppc::GuestFault(address, b);
}

void NativeTable::set(const NativeEntry* entries, std::size_t count) {
  dense_.clear();
  if (!count) return;
  u32 lo = entries[0].address, hi = entries[0].address;
  for (std::size_t k = 0; k < count; ++k) {
    lo = std::min(lo, entries[k].address);
    hi = std::max(hi, entries[k].address);
  }
  base_ = lo;
  dense_.assign((hi - lo) / 4 + 1, nullptr);
  for (std::size_t k = 0; k < count; ++k) dense_[(entries[k].address - lo) / 4] = entries[k].fn;
}

GuestFn NativeTable::find(u32 address) const {
  if (address < base_ || (address & 3)) return nullptr;
  std::size_t k = (address - base_) / 4;
  return k < dense_.size() ? dense_[k] : nullptr;
}

namespace {

// Runs from c.pc, entering native code at translated entries, until c.pc == stop
// (when `has_stop`) at an instruction boundary.
void dispatch(Cpu& c, bool has_stop, u32 stop) {
  for (;;) {
    if (has_stop && c.pc == stop) return;
    if (GuestFn fn = g_native.find(c.pc)) {
      fn(c);
      continue;
    }
    if ((c.ticks >= c.next_event && g_safe.has(c.pc)) || g_idle.has(c.pc)) {
      u32 at = c.pc;
      c.hooks->safepoint(c);
      if (c.pc != at) continue;  // an interrupt moved on to other code
    }
    ppc::step(c);
    ++g_interpreted;
  }
}

}  // namespace

void call_indirect(Cpu& c, u32 target) {
  u32 ret = c.lr;
  c.pc = target;
  if (GuestFn fn = g_native.find(target)) {
    fn(c);
    return;
  }
  dispatch(c, true, ret & ~3u);
}

void absolute_call(Cpu& c, u32 target) {
  // Code the OS copies into low memory at run time. Not translated: interpret it.
  call_indirect(c, target < 0x01800000u ? target | 0x80000000u : target);
}

void run_handler(Cpu& c, u32 resume_pc, u32 sp) {
  // The OS's exception code itself uses rfi (from the real-mode vector into the
  // handler), always with MSR[EE] clear. An rfi that sets EE ends the exception:
  // back to the interrupted point, or into another thread. An rfi into a thread
  // that runs with EE clear keeps running here, in the interpreter, until that
  // thread's own rfi or a translated OSLoadContext (Unwind) settles it.
  try {
    for (;;) {
      if (GuestFn fn = g_native.find(c.pc)) {
        fn(c);
        if (c.pc == resume_pc && c.gpr[1] == sp) return;
        continue;
      }
      ppc::Op op = ppc::step(c);
      ++g_interpreted;
      if (op == ppc::Op::rfi && (c.msr & ppc::msr::EE)) {
        if (c.pc == resume_pc && c.gpr[1] == sp) return;
        throw Unwind{};  // another thread resumes
      }
    }
  } catch (const Unwind&) {
    if (c.pc == resume_pc && c.gpr[1] == sp) return;
    throw;
  }
}

void run(Cpu& c) {
  for (;;) {
    try {
      dispatch(c, false, 0);
    } catch (const Unwind&) {
      ++g_unwinds;  // native frames are gone; continue at c.pc
    }
  }
}

}  // namespace mvp::rt
