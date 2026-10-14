#include "translator/cfg.h"

#include <algorithm>
#include <cstdio>
#include <map>
#include <set>

#include "common/bytes.h"

namespace mvp::xlat {

using ppc::Insn;
using ppc::Op;

const char* flow_name(Flow f) {
  switch (f) {
    case Flow::Plain: return "plain";
    case Flow::Jump: return "jump";
    case Flow::CondJump: return "cond-jump";
    case Flow::Call: return "call";
    case Flow::TailCall: return "tail-call";
    case Flow::Return: return "return";
    case Flow::CondReturn: return "cond-return";
    case Flow::IndirectCall: return "indirect-call";
    case Flow::JumpTable: return "jump-table";
    case Flow::IndirectJump: return "indirect-jump";
    case Flow::AbsoluteCall: return "absolute-call";
    case Flow::Rfi: return "rfi";
    case Flow::Trap: return "trap";
  }
  return "?";
}

namespace {

std::string hex(u32 v) {
  char b[16];
  std::snprintf(b, sizeof b, "0x%08X", v);
  return b;
}

// The GPR an instruction writes (the first one, for update forms), or -1.
int gpr_dest(Op op, Insn i) {
  switch (op) {
    case Op::addi: case Op::addis: case Op::addic: case Op::addic_rc: case Op::mulli: case Op::subfic:
    case Op::add: case Op::addc: case Op::adde: case Op::addme: case Op::addze: case Op::divw: case Op::divwu:
    case Op::mulhw: case Op::mulhwu: case Op::mullw: case Op::neg: case Op::subf: case Op::subfc: case Op::subfe:
    case Op::subfme: case Op::subfze:
    case Op::lbz: case Op::lbzx: case Op::lha: case Op::lhax: case Op::lhbrx: case Op::lhz: case Op::lhzx: case Op::lwz:
    case Op::lwzx: case Op::lwbrx: case Op::lwarx:
    case Op::lbzu: case Op::lbzux: case Op::lhau: case Op::lhaux: case Op::lhzu: case Op::lhzux: case Op::lwzu:
    case Op::lwzux:
    case Op::mfspr: case Op::mftb: case Op::mfcr: case Op::mfmsr: case Op::mfsr: case Op::mfsrin:
      return static_cast<int>(i.rD());
    case Op::ori: case Op::oris: case Op::xori: case Op::xoris: case Op::andi_rc: case Op::andis_rc:
    case Op::and_: case Op::andc: case Op::or_: case Op::orc: case Op::xor_: case Op::nand: case Op::nor:
    case Op::eqv: case Op::extsb: case Op::extsh: case Op::cntlzw: case Op::rlwinm: case Op::rlwnm:
    case Op::rlwimi: case Op::slw: case Op::srw: case Op::sraw: case Op::srawi:
      return static_cast<int>(i.rA());
    default:
      return -1;
  }
}

// Second GPR written by update forms (rA), or -1.
int gpr_dest2(Op op, Insn i) {
  switch (op) {
    case Op::lbzu: case Op::lbzux: case Op::lhau: case Op::lhaux: case Op::lhzu: case Op::lhzux: case Op::lwzu:
    case Op::lwzux: case Op::stbu: case Op::stbux: case Op::sthu: case Op::sthux: case Op::stwu: case Op::stwux:
    case Op::lfsu: case Op::lfsux: case Op::lfdu: case Op::lfdux: case Op::stfsu: case Op::stfsux: case Op::stfdu:
    case Op::stfdux:
      return static_cast<int>(i.rA());
    default:
      return -1;
  }
}

bool writes(const InsnInfo& x, int reg) {
  Insn i{x.word};
  if (gpr_dest(x.op, i) == reg || gpr_dest2(x.op, i) == reg) return true;
  if (x.op == Op::lmw) return static_cast<int>(i.rD()) <= reg;
  return false;
}

// Nearest instruction before index `from` that writes `reg`, within `limit` words.
int find_def(const FunctionCfg& f, int from, int reg, int limit) {
  for (int k = from - 1; k >= 0 && k >= from - limit; --k)
    if (writes(f.insns[static_cast<std::size_t>(k)], reg)) return k;
  return -1;
}

// Constant value of `reg` just before index `from`: lis/addi, lis/ori, li.
bool const_value(const FunctionCfg& f, int from, int reg, u32* value) {
  int d = find_def(f, from, reg, 16);
  if (d < 0) return false;
  const InsnInfo& x = f.insns[static_cast<std::size_t>(d)];
  Insn i{x.word};
  if (x.op == Op::addis && i.rA() == 0) {
    *value = i.uimm() << 16;
    return true;
  }
  if (x.op == Op::addi && i.rA() == 0) {
    *value = static_cast<u32>(i.simm());
    return true;
  }
  if ((x.op == Op::addi || x.op == Op::ori) && i.rA() != 0) {
    u32 base;
    int src = static_cast<int>(x.op == Op::addi ? i.rA() : i.rS());
    if (!const_value(f, d, src, &base)) return false;
    *value = x.op == Op::addi ? base + static_cast<u32>(i.simm()) : base | i.uimm();
    return true;
  }
  return false;
}

// Recovers the jump table behind the bctr at index `site`:
//   lis rB, T@ha; addi rB, rB, T@l; ... lwzx rX, rB, rI; mtctr rX; bctr
bool recover_table(const FunctionCfg& f, int site, const vfs::Dol& dol, const SymbolTable& syms, JumpTable* out,
                   std::string* why) {
  int mt = -1;
  for (int k = site - 1; k >= 0 && k >= site - 8; --k) {
    const InsnInfo& x = f.insns[static_cast<std::size_t>(k)];
    if (x.op == Op::mtspr && Insn{x.word}.spr() == ppc::spr::CTR) {
      mt = k;
      break;
    }
  }
  if (mt < 0) {
    *why = "no mtctr before the bctr";
    return false;
  }
  int rx = static_cast<int>(Insn{f.insns[static_cast<std::size_t>(mt)].word}.rS());
  int ld = find_def(f, mt, rx, 12);
  if (ld < 0) {
    *why = "the CTR value is not loaded nearby";
    return false;
  }
  const InsnInfo& l = f.insns[static_cast<std::size_t>(ld)];
  Insn li{l.word};
  // The table base: a constant register (lis/addi) feeding the load.
  u32 table = 0;
  int index_reg = -1;
  bool found = false;
  if (l.op == Op::lwzx) {
    int regs[2] = {static_cast<int>(li.rA()), static_cast<int>(li.rB())};
    for (int k = 0; k < 2 && !found; ++k) {
      u32 v;
      if (regs[k] != 0 && const_value(f, ld, regs[k], &v) && dol.section_at(v, 4) && !dol.section_at(v, 4)->text) {
        table = v;
        index_reg = regs[1 - k];
        found = true;
      }
    }
  }
  if (!found) {
    *why = "no constant table base feeding the load";
    return false;
  }
  // The entry count: the data object at the base (symbols.txt), else the bounds
  // check `cmplwi rI, N` on the register the index was scaled from.
  u32 count = 0;
  if (const Symbol* obj = syms.object_at(table); obj && obj->size && obj->size % 4 == 0) {
    count = obj->size / 4;
  } else {
    int sc = find_def(f, ld, index_reg, 8);
    int src = sc >= 0 && f.insns[static_cast<std::size_t>(sc)].op == Op::rlwinm
                  ? static_cast<int>(Insn{f.insns[static_cast<std::size_t>(sc)].word}.rS())
                  : -1;
    for (int k = (sc >= 0 ? sc : ld) - 1; k >= 0 && k >= ld - 12 && src >= 0; --k) {
      const InsnInfo& x = f.insns[static_cast<std::size_t>(k)];
      Insn xi{x.word};
      if (x.op == Op::cmpli && static_cast<int>(xi.rA()) == src) {
        count = xi.uimm() + 1;
        break;
      }
    }
  }
  if (!count) {
    *why = "jump table size unknown (no data symbol, no bounds check)";
    return false;
  }
  out->site = f.insns[static_cast<std::size_t>(site)].addr;
  out->table = table;
  out->targets.clear();
  for (u32 k = 0; k < 4 * count; k += 4) {
    const u8* p = dol.at(table + k, 4);
    if (!p) {
      *why = "jump table outside the DOL";
      return false;
    }
    u32 t = be32(p);
    if (!f.contains(t) || (t & 3)) {
      *why = "jump table entry " + hex(t) + " is outside the function";
      return false;
    }
    out->targets.push_back(t);
  }
  return true;
}

// Is `t` somewhere a call may go: a function start, or inside a function body
// (a secondary entry point)? Sets *inner for the latter.
bool call_target_ok(const FunctionIndex& fx, u32 t, bool* inner) {
  *inner = false;
  if (t & 3) return false;
  if (fx.at(t)) return true;
  if (fx.containing(t)) {
    *inner = true;
    return true;
  }
  return false;
}

void classify(FunctionCfg& f, const vfs::Dol& dol, const SymbolTable& syms, const FunctionIndex& fx) {
  for (std::size_t idx = 0; idx < f.insns.size(); ++idx) {
    InsnInfo& x = f.insns[idx];
    Insn i{x.word};
    auto err = [&](const std::string& m) { f.errors.push_back(hex(x.addr) + ": " + m); };
    switch (x.op) {
      case Op::b:
      case Op::bc: {
        bool is_b = x.op == Op::b;
        s32 disp = is_b ? i.li() : i.bd();
        u32 t = i.aa() ? static_cast<u32>(disp) : x.addr + static_cast<u32>(disp);
        x.target = t;
        bool always = is_b || (i.bo() & 0x14) == 0x14;
        x.conditional = !always;
        if (i.lk()) {
          bool inner = false;
          if (call_target_ok(fx, t, &inner)) {
            x.flow = Flow::Call;
            x.inner_target = inner;
          } else if (i.aa() && !dol.section_at(t)) {
            x.flow = Flow::AbsoluteCall;
          } else {
            x.flow = Flow::Call;
            err("call to " + hex(t) + ", which is not code");
          }
        } else if (f.contains(t)) {
          x.flow = always ? Flow::Jump : Flow::CondJump;
        } else if (fx.at(t)) {
          x.flow = Flow::TailCall;
        } else {
          x.flow = always ? Flow::Jump : Flow::CondJump;
          err("branch to " + hex(t) + ", outside the function and not a function start");
        }
        break;
      }
      case Op::bclr: {
        bool always = (i.bo() & 0x14) == 0x14;
        x.conditional = !always;
        if (i.lk()) x.flow = Flow::IndirectCall;
        else x.flow = always ? Flow::Return : Flow::CondReturn;
        break;
      }
      case Op::bcctr: {
        bool always = (i.bo() & 0x14) == 0x14;
        x.conditional = !always;
        if (i.lk()) {
          x.flow = Flow::IndirectCall;
        } else {
          JumpTable jt;
          std::string why;
          if (always && recover_table(f, static_cast<int>(idx), dol, syms, &jt, &why)) {
            x.flow = Flow::JumpTable;
            f.tables.push_back(std::move(jt));
          } else {
            x.flow = Flow::IndirectJump;
          }
        }
        break;
      }
      case Op::rfi: x.flow = Flow::Rfi; break;
      case Op::invalid: x.flow = Flow::Trap; break;
      case Op::tw:
        if (i.to() == 31) x.flow = Flow::Trap;
        break;
      default: break;
    }
  }
}

bool is_call(Flow fl) { return fl == Flow::Call || fl == Flow::IndirectCall || fl == Flow::AbsoluteCall; }

void walk(FunctionCfg& f, const FunctionIndex& fx) {
  std::size_t n = f.insns.size();
  f.reachable.assign(n, false);
  std::vector<u32> work(f.entries.begin(), f.entries.end());
  std::set<u32> leaders(f.entries.begin(), f.entries.end());
  std::vector<bool> other_path(n, false);  // reached other than as a call's return point
  for (u32 e : f.entries) other_path[(e - f.start) / 4] = true;
  auto push = [&](u32 a, bool by_call_return) {
    if (!f.contains(a)) return;
    std::size_t k = (a - f.start) / 4;
    if (!by_call_return) other_path[k] = true;
    if (!f.reachable[k]) work.push_back(a);
  };
  while (!work.empty()) {
    u32 a = work.back();
    work.pop_back();
    std::size_t k = (a - f.start) / 4;
    if (f.reachable[k]) continue;
    f.reachable[k] = true;
    const InsnInfo& x = f.insns[k];
    u32 next = a + 4;
    bool falls = true;
    switch (x.flow) {
      case Flow::Jump:
      case Flow::CondJump:
        if (f.contains(x.target)) {
          leaders.insert(x.target);
          push(x.target, false);
        }
        falls = x.flow == Flow::CondJump;
        break;
      case Flow::TailCall:
      case Flow::IndirectJump:
      case Flow::Return:
      case Flow::CondReturn:
        falls = x.conditional;
        break;
      case Flow::JumpTable:
        for (const auto& jt : f.tables)
          if (jt.site == a)
            for (u32 t : jt.targets) {
              leaders.insert(t);
              push(t, false);
            }
        falls = false;
        break;
      case Flow::Rfi:
      case Flow::Trap:
        falls = false;
        break;
      default:
        break;
    }
    if (x.flow != Flow::Plain && !is_call(x.flow)) leaders.insert(next);
    if (falls) {
      if (next < f.end) {
        push(next, is_call(x.flow));
      } else if (fx.at(next)) {
        f.falls_into = next;  // runs into the next function: an implicit tail call
      } else {
        f.errors.push_back(hex(a) + ": execution runs past the end of the function");
      }
    }
  }
  // Invalid words: allowed only where nothing but a call's return leads.
  for (std::size_t k = 0; k < n; ++k) {
    if (!f.reachable[k] || f.insns[k].op != Op::invalid) continue;
    bool is_entry = std::find(f.entries.begin(), f.entries.end(), f.insns[k].addr) != f.entries.end();
    bool other = other_path[k] && !is_entry;
    if (other) f.errors.push_back(hex(f.insns[k].addr) + ": reachable invalid word");
    else f.expected_traps.push_back(f.insns[k].addr);
  }
  // Blocks over reachable code. Calls do not end blocks.
  f.blocks.clear();
  for (std::size_t k = 0; k < n;) {
    if (!f.reachable[k]) {
      ++k;
      continue;
    }
    Block b;
    b.start = f.start + static_cast<u32>(4 * k);
    std::size_t j = k;
    for (;;) {
      const InsnInfo& x = f.insns[j];
      ++j;
      bool ends = x.flow != Flow::Plain && !is_call(x.flow);
      if (ends || j >= n || !f.reachable[j] || leaders.count(f.start + static_cast<u32>(4 * j))) break;
    }
    b.end = f.start + static_cast<u32>(4 * j);
    const InsnInfo& last = f.insns[j - 1];
    switch (last.flow) {
      case Flow::Jump:
        if (f.contains(last.target)) b.succ.push_back(last.target);
        break;
      case Flow::CondJump:
        if (f.contains(last.target)) b.succ.push_back(last.target);
        if (b.end < f.end) b.succ.push_back(b.end);
        break;
      case Flow::JumpTable:
        for (const auto& jt : f.tables)
          if (jt.site == last.addr) b.succ.insert(b.succ.end(), jt.targets.begin(), jt.targets.end());
        break;
      case Flow::TailCall: case Flow::IndirectJump: case Flow::Return: case Flow::CondReturn:
        if (last.conditional && b.end < f.end) b.succ.push_back(b.end);
        break;
      case Flow::Rfi: case Flow::Trap: break;
      default:
        if (b.end < f.end) b.succ.push_back(b.end);
        break;
    }
    f.blocks.push_back(std::move(b));
    k = j;
  }
  // Resume points and back edges.
  for (std::size_t k = 0; k < n; ++k) {
    if (!f.reachable[k]) continue;
    const InsnInfo& x = f.insns[k];
    if (is_call(x.flow)) f.resume_points.push_back(x.addr + 4);
    if ((x.flow == Flow::Jump || x.flow == Flow::CondJump) && f.contains(x.target) && x.target <= x.addr) {
      f.back_edges.push_back(x.addr);
      // A pure spin: only loads and compares between the target and this branch,
      // which does not count down CTR (a bdnz loop ends by itself).
      if ((x.addr - x.target) / 4 + 1 <= 4 && (x.op == Op::b || (ppc::Insn{x.word}.bo() & 4))) {
        bool pure = true;
        for (u32 a = x.target; a < x.addr && pure; a += 4) {
          switch (f.at(a).op) {
            case Op::lbz: case Op::lhz: case Op::lha: case Op::lwz: case Op::lbzx: case Op::lhzx: case Op::lhax:
            case Op::lwzx: case Op::cmp: case Op::cmpi: case Op::cmpl: case Op::cmpli:
              break;
            default:
              pure = false;
          }
        }
        if (pure) f.idle_spins.push_back(x.addr);
      }
    }
    if (x.flow == Flow::JumpTable)
      for (const auto& jt : f.tables)
        if (jt.site == x.addr)
          for (u32 t : jt.targets)
            if (t <= x.addr) {
              f.back_edges.push_back(x.addr);
              break;
            }
  }
}

}  // namespace

ProgramCfg build_cfg(const vfs::Dol& dol, const SymbolTable& syms) {
  ProgramCfg p;
  for (const auto& [start, sym] : syms.functions()) p.index.add(sym);
  // Gap functions: direct branch targets outside every function that carry a
  // code label. Repeat until no new ones (a gap function may branch to another).
  for (bool added = true; added;) {
    added = false;
    std::vector<u32> targets;
    for (const auto& [start, sym] : p.index.all()) {
      const vfs::DolSection* sec = dol.section_at(start, sym->size ? sym->size : 4);
      if (!sec || !sec->text || !sym->size) continue;
      for (u32 a = start; a < start + sym->size; a += 4) {
        Insn i{be32(dol.at(a, 4))};
        Op op = ppc::decode(i.w);
        if (op != Op::b && op != Op::bc) continue;
        s32 disp = op == Op::b ? i.li() : i.bd();
        targets.push_back(i.aa() ? static_cast<u32>(disp) : a + static_cast<u32>(disp));
      }
    }
    for (u32 t : targets) {
      if (p.index.containing(t) || !syms.code_label_at(t)) continue;
      const vfs::DolSection* sec = dol.section_at(t, 4);
      auto next = p.index.all().upper_bound(t);
      if (!sec || !sec->text || next == p.index.all().end()) continue;
      Symbol g = *syms.code_label_at(t);
      g.type = Symbol::Type::Function;
      g.size = next->first - t;
      p.gap_symbols.push_back(std::move(g));
      p.index.add(&p.gap_symbols.back());
      added = true;
    }
  }
  p.gap_functions = p.gap_symbols.size();
  // Pass 1: decode and classify every function.
  for (const auto& [start, sym] : p.index.all()) {
    const vfs::DolSection* sec = dol.section_at(start, sym->size ? sym->size : 4);
    if (!sec || !sec->text) {
      p.error_list.push_back(sym->name + ": not inside a DOL text section");
      continue;
    }
    if (sym->size == 0 || (sym->size & 3) || (start & 3)) {
      p.error_list.push_back(sym->name + ": bad size or alignment");
      continue;
    }
    FunctionCfg f;
    f.sym = sym;
    f.start = start;
    f.end = start + sym->size;
    f.entries.push_back(start);
    f.insns.resize(sym->size / 4);
    for (u32 k = 0; k < sym->size / 4; ++k) {
      InsnInfo& x = f.insns[k];
      x.addr = start + 4 * k;
      x.word = be32(dol.at(x.addr, 4));
      x.op = ppc::decode(x.word);
    }
    classify(f, dol, syms, p.index);
    p.functions.push_back(std::move(f));
  }
  // Secondary entry points: calls into another function's body.
  std::map<u32, std::size_t> index;
  for (std::size_t k = 0; k < p.functions.size(); ++k) index[p.functions[k].start] = k;
  for (const auto& f : p.functions)
    for (const auto& x : f.insns)
      if (x.flow == Flow::Call && x.inner_target) {
        const Symbol* owner = p.index.containing(x.target);
        auto it = index.find(owner->address);
        if (it == index.end()) continue;
        auto& g = p.functions[it->second];
        if (std::find(g.entries.begin(), g.entries.end(), x.target) == g.entries.end()) g.entries.push_back(x.target);
      }
  // Pass 2: reachability, blocks, resume points.
  for (auto& f : p.functions) {
    std::sort(f.entries.begin() + 1, f.entries.end());
    walk(f, p.index);
    p.words += f.insns.size();
    for (bool r : f.reachable) p.reachable_words += r ? 1 : 0;
    p.blocks += f.blocks.size();
    for (std::size_t k = 0; k < f.insns.size(); ++k) {
      if (!f.reachable[k]) continue;
      switch (f.insns[k].flow) {
        case Flow::Call: ++p.calls; break;
        case Flow::TailCall: ++p.tail_calls; break;
        case Flow::IndirectCall: ++p.indirect_calls; break;
        case Flow::JumpTable: ++p.jump_tables; break;
        case Flow::IndirectJump: ++p.indirect_jumps; break;
        case Flow::AbsoluteCall: ++p.absolute_calls; break;
        default: break;
      }
    }
    p.resume_points += f.resume_points.size();
    p.back_edges += f.back_edges.size();
    p.idle_spins += f.idle_spins.size();
    p.secondary_entries += f.entries.size() - 1;
    p.falls_into_next += f.falls_into ? 1 : 0;
    p.expected_traps += f.expected_traps.size();
    for (const auto& e : f.errors) p.error_list.push_back(f.sym->name + ": " + e);
  }
  p.errors = p.error_list.size();
  return p;
}

}  // namespace mvp::xlat
