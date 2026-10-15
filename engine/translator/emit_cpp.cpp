#include "translator/emit_cpp.h"

#include <algorithm>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <set>
#include <sstream>

#include "ppc/disasm.h"

namespace mvp::xlat {

using ppc::Insn;
using ppc::Op;

namespace {

std::string h8(u32 v) {
  char b[16];
  std::snprintf(b, sizeof b, "0x%08Xu", v);
  return b;
}
std::string fname(u32 entry) {
  char b[16];
  std::snprintf(b, sizeof b, "f_%08X", entry);
  return b;
}
std::string label(u32 a) {
  char b[16];
  std::snprintf(b, sizeof b, "L_%08X", a);
  return b;
}
std::string insn(u32 w) { return "Insn{" + h8(w) + "}"; }

// The sem:: function for a plain (non-control) instruction, or "" for no effect.
const char* sem_name(Op op) {
  switch (op) {
    case Op::dcbf: case Op::dcbi: case Op::dcbst: case Op::dcbt: case Op::dcbtst: case Op::eieio: case Op::isync:
    case Op::sync: case Op::tlbie: case Op::tlbsync:
      return "";
    case Op::dcbz_l:
      return "dcbz";
    default:
      return ppc::op_info(op).name;
  }
}

// C++ identifier of an Op (the sem:: functions use the enum's spelling).
std::string op_ident(Op op) {
  switch (op) {
#define MVP_X(name, pattern, mask) \
  case Op::name: return #name;
    MVP_PPC_OPS(MVP_X)
#undef MVP_X
    default: return "";
  }
}

// The replacement or hook for a function: by address when the spec has one, else by name.
const HleSpec* find_hle(const EmitOptions& o, const FunctionCfg& f) {
  for (const HleSpec& h : o.hle)
    if (h.address ? h.address == f.start : h.name == f.sym->name) return &h;
  return nullptr;
}

class Writer {
 public:
  explicit Writer(const EmitOptions& o) : opt_(o) {}

  void function(const FunctionCfg& f, const FunctionIndex& fx) {
    std::set<u32> labels;
    for (std::size_t k = 0; k < f.insns.size(); ++k) {
      if (!f.reachable[k]) continue;
      const InsnInfo& x = f.insns[k];
      if ((x.flow == Flow::Jump || x.flow == Flow::CondJump) && f.contains(x.target)) labels.insert(x.target);
    }
    for (const auto& t : f.tables) labels.insert(t.targets.begin(), t.targets.end());
    bool multi = f.entries.size() > 1;
    if (multi) labels.insert(f.entries.begin(), f.entries.end());

    const HleSpec* spec = find_hle(opt_, f);
    if (spec && multi) spec = nullptr;  // not supported on functions with secondary entries
    if (spec) stats_.hle_matched.push_back(spec->index);
    int hle_id = spec && !spec->before ? spec->index : -1;
    int hook_id = spec && spec->before ? spec->index : -1;
    // Resume labels (runtime/native.h): every call's return address and every
    // back edge inside the function, where an unwind may continue natively.
    resume_.clear();
    if (hle_id < 0) {
      std::set<u32> entries(f.entries.begin(), f.entries.end());
      auto add = [&](u32 a) {
        if (f.contains(a) && f.reachable[(a - f.start) / 4] && !entries.count(a)) resume_.insert(a);
      };
      for (u32 a : f.resume_points) add(a);
      for (u32 a : f.back_edges) add(a);
    }
    labels.insert(resume_.begin(), resume_.end());
    const std::string self = fname(f.start), body = "b_" + self.substr(2);
    // The longest straight-line run, for EmitOptions::max_optimized_run.
    std::size_t run = 0, longest = 0;
    for (std::size_t k = 0; k < f.insns.size(); ++k) {
      const InsnInfo& x = f.insns[k];
      if (!f.reachable[k] || labels.count(x.addr) || x.flow != Flow::Plain) {
        run = 0;
        continue;
      }
      longest = std::max(longest, ++run);
    }
    const bool unoptimized = opt_.max_optimized_run && longest > opt_.max_optimized_run;
    if (unoptimized) {
      out_ << "#if defined(_MSC_VER) && !defined(__clang__)\n#pragma optimize(\"\", off)  // a " << longest
           << "-instruction straight-line run (EmitOptions::max_optimized_run)\n#endif\n";
      ++stats_.unoptimized;
    }
    miss_ = resume_.empty() ? "{ rt::leave(); return; }" : "goto R_;";

    out_ << "// " << f.sym->name << (hle_id >= 0 ? " (replaced: runtime/hle.h)" : hook_id >= 0 ? " (hooked: runtime/hle.h)" : "")
         << "\n";
    if (hle_id >= 0) {
      out_ << "static void " << self << "_orig(Cpu& c) {\n  u32 sp = c.gpr[1];\n  (void)sp;\n";
    } else if (multi) {
      out_ << "static void " << body << "(Cpu& c, u32 entry) {\n  u32 sp = c.gpr[1];\n  (void)sp;\n";
      out_ << "  switch (entry) {\n";
      if (!resume_.empty()) out_ << "    case 0: goto R_;\n";
      for (u32 e : f.entries) out_ << "    case " << h8(e) << ": goto " << label(e) << ";\n";
      out_ << "    default: rt::trap(c, entry, \"bad entry\");\n  }\n";
    } else {
      out_ << "void " << self << "(Cpu& c) {\n  u32 sp = c.gpr[1];\n  (void)sp;\n";
      if (!resume_.empty()) out_ << "  if (rt::g_resume) goto R_;\n";
      out_ << entry_prologue(f.start, miss_);
      // A hook may stop the run before the function's first instruction (runtime/hle.h).
      if (hook_id >= 0) out_ << "  rt::hle_before(c, " << hook_id << ");\n  if (rt::g_unwinding) " << miss_ << "\n";
    }
    back_edges_.clear();
    back_edges_.insert(f.back_edges.begin(), f.back_edges.end());
    idle_.clear();
    idle_.insert(f.idle_spins.begin(), f.idle_spins.end());
    bool prev_falls = false;
    fpu_on_ = false;
    for (std::size_t k = 0; k < f.insns.size(); ++k) {
      if (!f.reachable[k]) {
        prev_falls = false;
        fpu_on_ = false;
        continue;
      }
      const InsnInfo& x = f.insns[k];
      if (labels.count(x.addr)) {
        out_ << label(x.addr) << ":\n";
        fpu_on_ = false;  // reached from elsewhere: MSR[FP] unknown
      }
      ++stats_.instructions;
      emit_insn(f, x, fx);
      prev_falls = falls_through(x);
    }
    if (prev_falls) {
      if (f.falls_into) {
        out_ << "  " << fname(f.falls_into) << "(c);\n  return;\n";
      } else {
        out_ << "  rt::trap(c, " << h8(f.end) << ", \"ran off the end of a function\");\n";
      }
    }
    if (!resume_.empty()) {
      // The resume block: an unwind arriving in this frame, or a dispatcher
      // re-entering the body at a resume label.
      out_ << "R_:\n  switch (rt::resume_target(c, sp, &" << self << ")) {\n";
      for (u32 a : resume_) out_ << "    case " << h8(a) << ": goto " << label(a) << ";\n";
      out_ << "    case 0: return;\n    default: rt::trap(c, c.pc, \"no resume label\");\n  }\n";
      for (u32 a : resume_) resume_table_.push_back({a, f.start});
      stats_.resume_labels += resume_.size();
    }
    out_ << "}\n";
    const std::string leave = "{ rt::leave(); return; }";
    if (hle_id >= 0) {
      out_ << "void " << self << "(Cpu& c) {\n" << entry_prologue(f.start, leave) << "  rt::hle_call(c, " << hle_id
           << ", &" << self << "_orig);\n}\n";
      ++stats_.hle_stubs;
    }
    if (multi) {
      for (u32 e : f.entries) {
        out_ << "void " << fname(e) << "(Cpu& c) {\n";
        if (e == f.start && !resume_.empty()) out_ << "  if (rt::g_resume) {\n    " << body << "(c, 0);\n    return;\n  }\n";
        out_ << entry_prologue(e, leave) << "  " << body << "(c, " << h8(e) << ");\n}\n";
      }
    }
    if (unoptimized) out_ << "#if defined(_MSC_VER) && !defined(__clang__)\n#pragma optimize(\"\", on)\n#endif\n";
    out_ << "\n";
    ++stats_.functions;
    stats_.entries += f.entries.size();
  }

  // (label, function start) for every resume label emitted so far.
  const std::vector<std::pair<u32, u32>>& resume_table() const { return resume_table_; }

  std::string take() {
    std::string s = out_.str();
    out_.str("");
    return s;
  }
  const EmitStats& stats() const { return stats_; }

 private:
  static bool falls_through(const InsnInfo& x) {
    switch (x.flow) {
      case Flow::Jump: case Flow::JumpTable: case Flow::Rfi: case Flow::Trap: return false;
      case Flow::TailCall: case Flow::IndirectJump: case Flow::Return: case Flow::CondReturn:
        return x.conditional;
      default: return true;
    }
  }

  // Function entry: the PC, the entry hook, then the entry safe point (before the
  // first instruction runs). An interrupt there that switches threads unwinds.
  static std::string entry_prologue(u32 e, const std::string& miss) {
    return "  c.pc = " + h8(e) + ";\n  rt::on_entry(c, " + h8(e) + ");\n  rt::safepoint_check(c);\n  if (c.pc != " +
           h8(e) + " || rt::g_unwinding) " + miss + "\n";
  }

  // A call: the frame's stack pointer for the resume check, the call, and the
  // return check (runtime/native.h).
  void call_and_check(u32 ret, const std::string& call, const std::string& indent) {
    out_ << indent << "sp = c.gpr[1];\n" << indent << call << "\n" << indent << "if (c.pc != " << h8(ret)
         << " || rt::g_unwinding) " << miss_ << "\n";
  }

  void emit_insn(const FunctionCfg& f, const InsnInfo& x, const FunctionIndex& fx) {
    (void)f;
    (void)fx;
    const u32 a = x.addr, w = x.word, ret = a + 4;
    out_ << "  // " << ppc::disasm(w, a) << "\n";
    // The PC, the back-edge safe point (before the branch runs), and the virtual clock.
    if (opt_.pc_per_insn || back_edges_.count(a)) out_ << "  c.pc = " << h8(a) << ";\n";
    if (idle_.count(a))
      out_ << "  sp = c.gpr[1];\n  c.hooks->safepoint(c);\n  if (c.pc != " << h8(a) << " || rt::g_unwinding) " << miss_
           << "\n";
    else if (back_edges_.count(a))
      out_ << "  sp = c.gpr[1];\n  rt::safepoint_check(c);\n  if (c.pc != " << h8(a) << " || rt::g_unwinding) "
           << miss_ << "\n";
    // Floating-point unavailable (E3a): an FPU instruction with MSR[FP] clear does
    // not start; the OS handler switches the FPU context and returns to it. Once
    // checked, MSR[FP] stays set until a label, a branch or call, a safe point,
    // mtmsr or sc, so the following FPU instructions of the block skip the check.
    if (back_edges_.count(a) || idle_.count(a)) fpu_on_ = false;
    if (x.flow == Flow::Plain && ppc::uses_fpu(x.op) && !fpu_on_) {
      out_ << "  if (!(c.msr & 0x2000u)) {\n    sp = c.gpr[1];\n    rt::fp_unavailable(c, " << h8(a) << ");\n    if (c.pc != "
           << h8(a) << " || rt::g_unwinding) " << miss_ << "\n  }\n";
      ++stats_.fpu_checks;
      fpu_on_ = true;
    }
    if (x.flow != Flow::Plain || x.op == Op::mtmsr || x.op == Op::sc) fpu_on_ = false;
    out_ << "  ++c.ticks;\n";
    const std::string cond = "sem::branch_cond(c, " + insn(w) + ")";
    switch (x.flow) {
      case Flow::Plain: {
        switch (x.op) {
          case Op::sc:
            out_ << "  c.pc = " << h8(ret) << ";\n  c.hooks->system_call(c);\n  if (c.pc != " << h8(ret)
                 << " || rt::g_unwinding) " << miss_ << "\n";
            return;
          case Op::tw:
            out_ << "  if (sem::tw_taken(c, " << insn(w) << ")) rt::trap(c, " << h8(a) << ", \"tw\");\n";
            return;
          case Op::twi:
            out_ << "  if (sem::twi_taken(c, " << insn(w) << ")) rt::trap(c, " << h8(a) << ", \"twi\");\n";
            return;
          case Op::eciwx: case Op::ecowx:
            out_ << "  rt::trap(c, " << h8(a) << ", \"external control instruction\");\n";
            return;
          default: break;
        }
        std::string n = sem_name(x.op);
        if (n.empty()) return;
        out_ << "  sem::" << (x.op == Op::dcbz_l ? std::string("dcbz") : op_ident(x.op)) << "(c, " << insn(w)
             << ");\n";
        return;
      }
      case Flow::Jump:
        out_ << "  goto " << label(x.target) << ";\n";
        return;
      case Flow::CondJump:
        out_ << "  if (" << cond << ") goto " << label(x.target) << ";\n";
        return;
      case Flow::Call: {
        std::string call = fname(x.target) + "(c);";
        if (x.conditional) {
          out_ << "  {\n    bool t = " << cond << ";\n    c.lr = " << h8(ret) << ";\n    if (t) {\n";
          call_and_check(ret, call, "      ");
          out_ << "    }\n  }\n";
        } else {
          out_ << "  c.lr = " << h8(ret) << ";\n";
          call_and_check(ret, call, "  ");
        }
        return;
      }
      case Flow::TailCall:
        if (x.conditional)
          out_ << "  if (" << cond << ") {\n    " << fname(x.target) << "(c);\n    return;\n  }\n";
        else
          out_ << "  " << fname(x.target) << "(c);\n  return;\n";
        return;
      case Flow::Return:
        out_ << "  c.pc = c.lr & ~3u;\n  return;\n";
        return;
      case Flow::CondReturn:
        out_ << "  if (" << cond << ") {\n    c.pc = c.lr & ~3u;\n    return;\n  }\n";
        return;
      case Flow::IndirectCall: {
        const char* reg = x.op == Op::bclr ? "c.lr" : "c.ctr";
        out_ << "  {\n    bool t = " << cond << ";\n    u32 target = " << reg << " & ~3u;\n    c.lr = " << h8(ret)
             << ";\n    if (t) {\n";
        call_and_check(ret, "rt::call_indirect(c, target);", "      ");
        out_ << "    }\n  }\n";
        return;
      }
      case Flow::JumpTable: {
        out_ << "  switch (c.ctr & ~3u) {\n";
        std::set<u32> seen;
        for (const auto& jt : f.tables)
          if (jt.site == a)
            for (u32 t : jt.targets)
              if (seen.insert(t).second) out_ << "    case " << h8(t) << ": goto " << label(t) << ";\n";
        out_ << "    default: rt::trap(c, " << h8(a) << ", \"jump outside its table\");\n  }\n";
        return;
      }
      case Flow::IndirectJump:
        out_ << "  if (" << cond << ") {\n    rt::call_indirect(c, c.ctr & ~3u);\n    return;\n  }\n";
        return;
      case Flow::AbsoluteCall:
        out_ << "  c.lr = " << h8(ret) << ";\n";
        call_and_check(ret, "rt::absolute_call(c, " + h8(x.target) + ");", "  ");
        return;
      case Flow::Rfi:  // the guest continues at SRR0: unwind (runtime/native.h)
        out_ << "  sem::rfi(c);\n  rt::leave();\n  return;\n";
        return;
      case Flow::Trap:
        out_ << "  rt::trap(c, " << h8(a) << ", \""
             << (x.op == Op::invalid ? "invalid instruction" : "unconditional trap") << "\");\n";
        return;
    }
  }

  const EmitOptions& opt_;
  std::ostringstream out_;
  EmitStats stats_;
  std::set<u32> back_edges_;  // of the function being emitted
  std::set<u32> idle_;        // its pure spin back edges
  std::set<u32> resume_;      // its resume labels
  std::string miss_;          // what an unwinding return does in it
  bool fpu_on_ = false;       // MSR[FP] already checked in this block
  std::vector<std::pair<u32, u32>> resume_table_;
};

const char* kPrelude =
    "// Generated by mvp-xlat from the player's disc. Do not commit (CLAUDE.md).\n"
    "#include \"game_decls.h\"\n"
    "#include \"ppc/sem.h\"\n"
    "#include \"runtime/hle.h\"\n"
    "#include \"runtime/native.h\"\n\n"
    "using namespace mvp;\n"
    "using namespace mvp::ppc;\n"
    "using u32 = std::uint32_t;\n\n";

bool write(const std::filesystem::path& p, const std::string& text, std::string* error) {
  // Leave an identical file alone so the build does not recompile it.
  std::ifstream in(p, std::ios::binary);
  if (in) {
    std::ostringstream old;
    old << in.rdbuf();
    if (old.str() == text) return true;
  }
  std::ofstream out(p, std::ios::binary);
  out << text;
  if (!out) {
    if (error) *error = "cannot write " + p.string();
    return false;
  }
  return true;
}

}  // namespace

bool emit_cpp(const ProgramCfg& p, const std::string& dir, const EmitOptions& opt, EmitStats* stats,
              std::string* error) {
  namespace fs = std::filesystem;
  std::error_code ec;
  fs::create_directories(dir, ec);
  // Declarations of every entry function.
  std::ostringstream decls;
  decls << "// Generated by mvp-xlat. Do not commit.\n#pragma once\n#include \"ppc/cpu.h\"\n\n";
  std::vector<u32> all_entries;
  for (const auto& f : p.functions)
    for (u32 e : f.entries) {
      decls << "void " << fname(e) << "(mvp::ppc::Cpu& c);\n";
      all_entries.push_back(e);
    }
  if (!write(fs::path(dir) / "game_decls.h", decls.str(), error)) return false;

  // Shards balanced by instruction count, functions in address order.
  std::size_t total = 0;
  for (const auto& f : p.functions)
    for (bool r : f.reachable) total += r ? 1 : 0;
  std::size_t per = total / static_cast<std::size_t>(opt.shards) + 1;
  Writer w(opt);
  int shard = 0;
  std::size_t in_shard = 0, bytes = 0;
  std::string body = kPrelude;
  auto flush = [&]() -> bool {
    char name[32];
    std::snprintf(name, sizeof name, "game_%02d.cpp", shard);
    bytes += body.size();
    if (!write(fs::path(dir) / name, body, error)) return false;
    body = kPrelude;
    in_shard = 0;
    ++shard;
    return true;
  };
  for (const auto& f : p.functions) {
    w.function(f, p.index);
    body += w.take();
    for (bool r : f.reachable) in_shard += r ? 1 : 0;
    if (in_shard >= per && shard < opt.shards - 1 && !flush()) return false;
  }
  while (shard < opt.shards)
    if (!flush()) return false;

  // Entry table.
  std::sort(all_entries.begin(), all_entries.end());
  std::ostringstream table;
  table << "// Generated by mvp-xlat. Do not commit.\n#include <cstdint>\n#include \"game_decls.h\"\n"
        << "#include \"runtime/hle.h\"\n#include \"runtime/native.h\"\n\n"
        << "static const mvp::rt::NativeEntry kEntries[] = {\n";
  for (u32 e : all_entries) table << "  {" << h8(e) << ", &" << fname(e) << "},\n";
  // Safe points: every entry and every back edge (the interpreter checks the same).
  std::vector<u32> safe(all_entries.begin(), all_entries.end());
  for (const auto& f : p.functions) safe.insert(safe.end(), f.back_edges.begin(), f.back_edges.end());
  std::sort(safe.begin(), safe.end());
  table << "};\n\nstatic const std::uint32_t kSafe[] = {\n";
  for (std::size_t k = 0; k < safe.size(); ++k) table << (k % 8 ? " " : "  ") << h8(safe[k]) << (k % 8 == 7 ? ",\n" : ",");
  // Replaced functions by address, so the reference interpreter can run the same replacement.
  table << "\n};\n\nstatic const mvp::rt::HleSite kHle[] = {\n";
  std::size_t hle_sites = 0;
  for (const auto& f : p.functions) {
    const HleSpec* spec = find_hle(opt, f);
    if (!spec || spec->before || f.entries.size() > 1) continue;
    table << "  {" << h8(f.start) << ", " << spec->index << "},\n";
    ++hle_sites;
  }
  if (!hle_sites) table << "  {0, -1},\n";
  // Pure spin back edges (the idle skip).
  std::vector<u32> idle;
  for (const auto& f : p.functions) idle.insert(idle.end(), f.idle_spins.begin(), f.idle_spins.end());
  std::sort(idle.begin(), idle.end());
  table << "};\n\nstatic const std::uint32_t kIdle[] = {\n";
  for (u32 a : idle) table << "  " << h8(a) << ",\n";
  if (idle.empty()) table << "  0,\n";
  // Resume labels (runtime/native.h): address -> the function whose body has it.
  table << "};\n\nstatic const mvp::rt::NativeEntry kResume[] = {\n";
  std::vector<std::pair<u32, u32>> resume = w.resume_table();
  std::sort(resume.begin(), resume.end());
  for (const auto& [a, fs] : resume) table << "  {" << h8(a) << ", &" << fname(fs) << "},\n";
  if (resume.empty()) table << "  {0, nullptr},\n";
  table << "};\n\nvoid mvp_register_game() {\n"
        << "  mvp::rt::g_native.set(kEntries, sizeof kEntries / sizeof kEntries[0]);\n"
        << "  mvp::rt::g_safe.set(kSafe, sizeof kSafe / sizeof kSafe[0]);\n"
        << "  mvp::rt::g_idle.set(kIdle, " << idle.size() << ");\n"
        << "  mvp::rt::g_resume_labels.set(kResume, " << resume.size() << ");\n"
        << "  mvp::rt::set_hle_sites(kHle, " << hle_sites << ");\n}\n";
  bytes += table.str().size();
  if (!write(fs::path(dir) / "game_table.cpp", table.str(), error)) return false;

  if (stats) {
    *stats = w.stats();
    stats->bytes = bytes;
  }
  return true;
}

}  // namespace mvp::xlat
