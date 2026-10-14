#include "runtime/lockstep.h"

#include <algorithm>
#include <cstdio>
#include <cstring>

#include "ppc/interp.h"
#include "runtime/hle.h"

namespace mvp::rt {

void FixedHooks::system_call(ppc::Cpu& c) {
  throw ppc::GuestFault(c.pc, "sc (system call) before the runtime handles it");
}

std::string cpu_diff(const ppc::Cpu& a, const ppc::Cpu& b) {
  std::string out;
  char t[128];
  auto one = [&](const char* n, std::uint64_t x, std::uint64_t y) {
    if (x != y) {
      std::snprintf(t, sizeof t, " %s ref=%llX nat=%llX", n, static_cast<unsigned long long>(x),
                    static_cast<unsigned long long>(y));
      out += t;
    }
  };
  char n[16];
  for (int k = 0; k < 32; ++k) {
    std::snprintf(n, sizeof n, "r%d", k);
    one(n, a.gpr[k], b.gpr[k]);
    std::snprintf(n, sizeof n, "f%d", k);
    one(n, a.fpr[k].ps0, b.fpr[k].ps0);
    std::snprintf(n, sizeof n, "f%d.ps1", k);
    one(n, a.fpr[k].ps1, b.fpr[k].ps1);
  }
  one("pc", a.pc, b.pc);
  one("ticks", a.ticks, b.ticks);
  one("cr", a.cr, b.cr);
  one("xer", a.xer(), b.xer());
  one("lr", a.lr, b.lr);
  one("ctr", a.ctr, b.ctr);
  one("fpscr", a.fpscr, b.fpscr);
  one("msr", a.msr, b.msr);
  one("reserve", a.reserve, b.reserve);
  for (int k = 0; k < 16; ++k) {
    std::snprintf(n, sizeof n, "sr%d", k);
    one(n, a.sr[k], b.sr[k]);
  }
  for (int k = 0; k < 1024; ++k) {
    std::snprintf(n, sizeof n, "spr%d", k);
    one(n, a.spr[k], b.spr[k]);
  }
  return out;
}

namespace {

struct Divergence {
  std::string what;
};

// Per-address facts from the CFG for the reference machine's event detection.
struct CodeMap {
  u32 base = 0;
  std::vector<xlat::Flow> flow;
  std::vector<int> func;  // function index, -1 outside
  std::vector<bool> entry;
  void build(const xlat::ProgramCfg& p) {
    u32 lo = 0xFFFFFFFFu, hi = 0;
    for (const auto& f : p.functions) {
      lo = std::min(lo, f.start);
      hi = std::max(hi, f.end);
    }
    if (lo > hi) return;
    base = lo;
    std::size_t n = (hi - lo) / 4;
    flow.assign(n, xlat::Flow::Plain);
    func.assign(n, -1);
    entry.assign(n, false);
    for (std::size_t k = 0; k < p.functions.size(); ++k) {
      const auto& f = p.functions[k];
      for (const auto& x : f.insns) {
        flow[(x.addr - base) / 4] = x.flow;
        func[(x.addr - base) / 4] = static_cast<int>(k);
      }
      for (u32 e : f.entries) entry[(e - base) / 4] = true;
    }
  }
  bool in(u32 a) const { return a >= base && (a - base) / 4 < flow.size() && !(a & 3); }
  bool is_entry(u32 a) const { return in(a) && entry[(a - base) / 4]; }
};

struct State {
  Machine* ref = nullptr;
  Machine* nat = nullptr;
  CodeMap map;
  u32 mem_every = 16;
  bool first = true;
  LockstepResult r;

  // One reference step, with the same safe points and replacements as the
  // native side. Returns the flow of what ran.
  xlat::Flow ref_step() {
    ppc::Cpu& c = ref->cpu();
    u32 pc = c.pc;
    xlat::Flow fl = map.in(pc) ? map.flow[(pc - map.base) / 4] : xlat::Flow::Plain;
    if (c.ticks >= c.next_event && g_safe.has(pc)) c.hooks->safepoint(c);
    if (c.pc != pc) return xlat::Flow::Rfi;  // the safe point moved the PC (an interrupt)
    if (hle_interpret(c)) return xlat::Flow::Return;  // a replacement returns like a blr
    ppc::step(c);
    ++r.ref_steps;
    return fl;
  }

  // Runs the reference machine to its next function-entry event: control
  // arriving at an entry point other than by a branch inside the same function.
  void advance() {
    ppc::Cpu& c = ref->cpu();
    for (;;) {
      u32 pc = c.pc;
      int fn = map.in(pc) ? map.func[(pc - map.base) / 4] : -1;
      xlat::Flow fl = ref_step();
      if (!map.is_entry(c.pc)) continue;
      bool local = (fl == xlat::Flow::Plain || fl == xlat::Flow::Jump || fl == xlat::Flow::CondJump ||
                    fl == xlat::Flow::JumpTable) &&
                   fn == map.func[(c.pc - map.base) / 4];
      if (!local) return;
    }
  }

  void check_memory() {
    ++r.mem_checks;
    const u8* a = ref->mem1();
    const u8* b = nat->mem1();
    if (std::memcmp(a, b, Machine::kMem1Size) == 0) return;
    for (u32 k = 0; k < Machine::kMem1Size; ++k)
      if (a[k] != b[k]) {
        char t[96];
        std::snprintf(t, sizeof t, "MEM1 differs first at 0x%08X", 0x80000000u + k);
        throw Divergence{t};
      }
  }

  void on_entry(ppc::Cpu& c, u32 addr) {
    if (!first) advance();
    first = false;
    ++r.events;
    r.recent.push_back(addr);
    if (r.recent.size() > 16) r.recent.erase(r.recent.begin());
    std::string d = cpu_diff(ref->cpu(), c);
    if (!d.empty()) {
      char t[64];
      std::snprintf(t, sizeof t, "at entry 0x%08X (event %llu):", addr, static_cast<unsigned long long>(r.events));
      throw Divergence{t + d};
    }
    if (mem_every && r.events % mem_every == 0) check_memory();
  }
};

State* g_state = nullptr;
void hook(ppc::Cpu& c, u32 addr) { g_state->on_entry(c, addr); }

}  // namespace

LockstepResult run_lockstep(Machine& ref, Machine& nat, const xlat::ProgramCfg& cfg, u32 mem_every) {
  State st;
  st.ref = &ref;
  st.nat = &nat;
  st.map.build(cfg);
  st.mem_every = mem_every;
  g_state = &st;
  EntryHook saved = g_entry_hook;
  g_entry_hook = &hook;
  auto done = [&](bool pass, const std::string& msg) {
    g_entry_hook = saved;
    g_state = nullptr;
    st.r.pass = pass;
    st.r.message = msg;
    return st.r;
  };
  StopAtMmio nat_stop{}, ref_stop{};
  try {
    run(nat.cpu());
  } catch (const StopAtMmio& s) {
    nat_stop = s;
  } catch (const Divergence& d) {
    return done(false, "divergence " + d.what);
  } catch (const ppc::GuestFault& f) {
    char t[64];
    std::snprintf(t, sizeof t, "native side faulted at 0x%08X: ", f.pc());
    return done(false, t + std::string(f.what()));
  }
  g_entry_hook = saved;
  st.r.stop = nat_stop;
  // The reference machine catches up to its own first MMIO access.
  try {
    for (;;) st.ref_step();
  } catch (const StopAtMmio& s) {
    ref_stop = s;
  } catch (const ppc::GuestFault& f) {
    char t[64];
    std::snprintf(t, sizeof t, "reference faulted at 0x%08X: ", f.pc());
    return done(false, t + std::string(f.what()));
  }
  bool same_stop = nat_stop.addr == ref_stop.addr && nat_stop.pc == ref_stop.pc && nat_stop.write == ref_stop.write &&
                   nat_stop.size == ref_stop.size && nat_stop.value == ref_stop.value;
  std::string d = cpu_diff(ref.cpu(), nat.cpu());
  try {
    st.check_memory();
  } catch (const Divergence& dv) {
    d += " " + dv.what;
  }
  if (!same_stop) {
    char t[128];
    std::snprintf(t, sizeof t, "stops differ: native at 0x%08X (pc 0x%08X), reference at 0x%08X (pc 0x%08X)",
                  nat_stop.addr, nat_stop.pc, ref_stop.addr, ref_stop.pc);
    return done(false, t + d);
  }
  if (!d.empty()) return done(false, "final state differs:" + d);
  return done(true, "");
}

}  // namespace mvp::rt
