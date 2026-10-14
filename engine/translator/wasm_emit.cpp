#include "translator/wasm_emit.h"

#include <algorithm>
#include <cstddef>
#include <functional>
#include <unordered_map>

#include "ppc/cpu.h"
#include "ppc/effects.h"
#include "translator/wasm_binary.h"

namespace mvp::xlat {

using namespace wasm;
using ppc::Effects;
using ppc::Insn;
using ppc::Op;
using ppc::RegSet;
namespace reg = ppc::reg;

namespace {

// ---- the runtime's Cpu layout (wasm32) ----
// Every field before the pointers is laid out identically on x64 and wasm32, so
// a native build of the emitter (the CLI) writes the same module.
constexpr u32 kGpr = offsetof(ppc::Cpu, gpr);
constexpr u32 kCr = offsetof(ppc::Cpu, cr);
constexpr u32 kLr = offsetof(ppc::Cpu, lr);
constexpr u32 kCtr = offsetof(ppc::Cpu, ctr);
constexpr u32 kSo = offsetof(ppc::Cpu, xer_so);
constexpr u32 kCa = offsetof(ppc::Cpu, xer_ca);
constexpr u32 kPc = offsetof(ppc::Cpu, pc);
constexpr u32 kTicks = offsetof(ppc::Cpu, ticks);
constexpr u32 kNextEvent = offsetof(ppc::Cpu, next_event);
// Cpu::mem, the Memory whose first member is the page table.
constexpr u32 kMem = offsetof(ppc::Cpu, spr) + sizeof(ppc::Cpu::spr);
static_assert(kMem % 8 == 0, "Cpu::mem must sit at the same offset on 32- and 64-bit hosts");
#if defined(__EMSCRIPTEN__)
static_assert(offsetof(ppc::Cpu, mem) == kMem);
#endif
static_assert(offsetof(ppc::Memory, page) == 0);

u32 reg_offset(int r) {
  if (r < 32) return kGpr + 4 * static_cast<u32>(r);
  switch (r) {
    case reg::CR: return kCr;
    case reg::LR: return kLr;
    case reg::CTR: return kCtr;
    case reg::CA: return kCa;
    default: return kSo;
  }
}

// ---- module interface ----
enum Ty : u32 { tV_I, tV_II, tI_IIIL, tV_IIIIL, tV_IIIL, tI_III, tV_III, tI_II, kTypes };
enum Imp : u32 {
  iOnEntry, iSafepoint, iRead8, iRead16, iRead32, iWrite8, iWrite16, iWrite32, iExec, iCallIndirect,
  iAbsoluteCall, iResume, iHleCall, iHleBefore, iTrap, iRfi, iSystemCall, iTw, kImports
};
constexpr Ty kImportType[kImports] = {tV_II,   tV_I,  tI_IIIL, tI_IIIL, tI_IIIL, tV_IIIIL, tV_IIIIL, tV_IIIIL, tV_IIIL,
                                      tV_II,   tV_II, tI_III,  tV_III,  tV_II,   tV_III,   tV_I,     tV_I,     tV_III};
// Helpers defined in every module, after the imports.
enum Hlp : u32 { hRd8 = kImports, hRd16, hRd32, hWr8, hWr16, hWr32, hCmps, hCmpu, hDivw, hDivwu, kFirstGuest };
constexpr u32 kHelperCount = static_cast<u32>(kFirstGuest) - static_cast<u32>(kImports);
constexpr Ty kHelperType[kHelperCount] = {tI_IIIL, tI_IIIL, tI_IIIL, tV_IIIIL, tV_IIIIL,
                                                    tV_IIIIL, tI_III,  tI_III,  tI_II,    tI_II};
// Imported globals (immutable i32): the table base and three runtime addresses.
enum Glb : u32 { gTableBase, gUnwinding, gResume, gHook, kGlobals };

// ---- per-instruction classification ----
enum Kind : u8 { kInline, kHelper, kNop, kSc, kTw, kTrapOp, kJump, kCJump, kCall, kTail, kRet, kIJump, kJTab, kRfi, kTrap };
enum Grp : u8 { gInline, gHelper, gCall, gExit, gEnd, gFall };
enum Pre : u8 { pNone, pBack, pIdle };

bool is_inline(Op op, Insn i) {
  switch (op) {
    case Op::add: case Op::addc: case Op::adde: case Op::addme: case Op::addze: case Op::divw: case Op::divwu:
    case Op::mullw: case Op::neg: case Op::subf: case Op::subfc: case Op::subfe: case Op::subfme: case Op::subfze:
      return !i.oe();
    case Op::addi: case Op::addis: case Op::addic: case Op::addic_rc: case Op::subfic: case Op::mulli: case Op::mulhw:
    case Op::mulhwu: case Op::cmp: case Op::cmpi: case Op::cmpl: case Op::cmpli: case Op::and_: case Op::andc:
    case Op::eqv: case Op::nand: case Op::nor: case Op::or_: case Op::orc: case Op::xor_: case Op::extsb:
    case Op::extsh: case Op::cntlzw: case Op::ori: case Op::oris: case Op::xori: case Op::xoris: case Op::andi_rc:
    case Op::andis_rc: case Op::rlwinm: case Op::rlwnm: case Op::rlwimi: case Op::slw: case Op::srw: case Op::srawi:
    case Op::crand: case Op::crandc: case Op::creqv: case Op::crnand: case Op::crnor: case Op::cror: case Op::crorc:
    case Op::crxor: case Op::mcrf: case Op::mfcr: case Op::mtcrf:
    case Op::lbz: case Op::lbzu: case Op::lbzx: case Op::lbzux: case Op::lhz: case Op::lhzu: case Op::lhzx:
    case Op::lhzux: case Op::lha: case Op::lhau: case Op::lhax: case Op::lhaux: case Op::lwz: case Op::lwzu:
    case Op::lwzx: case Op::lwzux: case Op::stb: case Op::stbu: case Op::stbx: case Op::stbux: case Op::sth:
    case Op::sthu: case Op::sthx: case Op::sthux: case Op::stw: case Op::stwu: case Op::stwx: case Op::stwux:
      return true;
    case Op::mfspr: case Op::mtspr:
      return i.spr() == ppc::spr::LR || i.spr() == ppc::spr::CTR;
    default:
      return false;
  }
}

bool is_nop(Op op) {
  switch (op) {
    case Op::dcbf: case Op::dcbi: case Op::dcbst: case Op::dcbt: case Op::dcbtst: case Op::eieio: case Op::isync:
    case Op::sync: case Op::tlbie: case Op::tlbsync:
      return true;
    default:
      return false;
  }
}

bool is_memory(Op op) {
  switch (op) {
    case Op::lbz: case Op::lbzu: case Op::lbzx: case Op::lbzux: case Op::lhz: case Op::lhzu: case Op::lhzx:
    case Op::lhzux: case Op::lha: case Op::lhau: case Op::lhax: case Op::lhaux: case Op::lwz: case Op::lwzu:
    case Op::lwzx: case Op::lwzux: case Op::stb: case Op::stbu: case Op::stbx: case Op::stbux: case Op::sth:
    case Op::sthu: case Op::sthx: case Op::sthux: case Op::stw: case Op::stwu: case Op::stwx: case Op::stwux:
      return true;
    default:
      return false;
  }
}

const HleSpec* find_spec(const WasmEmitOptions& o, const FunctionCfg& f) {
  for (const HleSpec& h : o.hle)
    if (h.address ? h.address == f.start : h.name == f.sym->name) return &h;
  return nullptr;
}

// A wasm function of the module.
enum class WKind : u8 { Plain, Body, Stub, HleStub, Orig };
struct WFunc {
  WKind kind;
  std::size_t cfg;   // index in ProgramCfg::functions
  u32 entry = 0;     // Stub, HleStub, Plain: the entry address
  int slot = -1;     // table slot, for the callable ones
  int hle = -1;      // HleStub: replacement index; Plain: hook index (with `hook`)
  bool hook = false;
  u32 target = 0;    // Stub: its Body's function index; HleStub: its Orig's
};

struct Ctx {
  const ProgramCfg& p;
  const WasmEmitOptions& opt;
  std::unordered_map<u32, u32> callable;  // entry address -> function index (what a direct call calls)
  std::vector<int> start_slot;            // per cfg function: slot of its first entry's callable function
  WasmModule* out;
};

// ---- one translated function body ----
class FuncGen {
 public:
  enum class Mode { Plain, Body, Orig };

  FuncGen(Ctx& ctx, std::size_t cfg_index, Mode mode, int hook)
      : ctx_(ctx), f_(ctx.p.functions[cfg_index]), mode_(mode), hook_(hook), self_slot_(ctx.start_slot[cfg_index]) {}

  bool run(Fn& body, std::string* error);
  // Resume labels and their dispatcher index (valid after run).
  const std::vector<std::pair<u32, u32>>& resume() const { return resume_out_; }
  // The dispatcher index of an entry point (Body mode).
  u32 entry_segment(u32 e) const { return static_cast<u32>(seg_at_[(e - f_.start) / 4]); }

 private:
  struct Node {
    u8 kind = kNop, grp = gInline, pre = pNone;
    bool cond = false, mem = false;
    RegSet R = 0, W = 0;
    RegSet Din = 0, Lm = 0, Lin = 0, Lout = 0;
    int s0 = -1, s1 = -1, jt = -1;
  };

  // locals
  static constexpr u32 kCpu = 0;
  u32 L_label = 0, L_sp = 0, L_tc = 0, L_tgt = 0, L_tmp = 0, L_t = 0, L_w = 0;
  int regloc_[reg::kCount];

  bool classify(std::string* error);
  void dataflow();
  RegSet dm(const Node& n) const { return n.pre == pIdle ? 0 : n.Din; }

  // emission helpers
  void reg_get(int r) { body_->get(static_cast<u32>(regloc_[r])); }
  void reg_set(int r) { body_->set(static_cast<u32>(regloc_[r])); }
  void flush(RegSet s);
  void reload(RegSet s);
  void materialize() {
    if (!p_) return;
    body_->get(L_t);
    body_->i64c(p_);
    body_->op(op::i64_add);
    body_->set(L_t);
    p_ = 0;
  }
  void ticks_expr() {
    body_->get(L_t);
    if (p_) {
      body_->i64c(p_);
      body_->op(op::i64_add);
    }
  }
  void store_ticks() {  // after materialize()
    body_->get(kCpu);
    body_->get(L_t);
    body_->mem(op::i64_store, 3, kTicks);
  }
  void load_ticks() {
    body_->get(kCpu);
    body_->mem(op::i64_load, 3, kTicks);
    body_->set(L_t);
  }
  void store_pc(u32 a) {
    body_->get(kCpu);
    body_->i32c(a);
    body_->mem(op::i32_store, 2, kPc);
  }
  void load_sp() {
    body_->get(kCpu);
    body_->mem(op::i32_load, 2, kGpr + 4);
    body_->set(L_sp);
  }
  void leave() {  // rt::leave(); return;
    body_->global(gUnwinding);
    body_->i32c(1);
    body_->mem(op::i32_store8, 0, 0);
    body_->op(op::return_);
  }
  void miss();               // an unwinding return arrived: resume block, or leave
  void check(u32 expect);    // if (c.pc != expect || g_unwinding) miss
  void jump(int seg);        // to a code segment, from the current position
  void cond_expr(const InsnInfo& x);
  void cr0_from(int r);      // CR0 from the value in register local r (record forms)
  void set_cr_field(u32 field, const std::function<void()>& bits);
  void ea_d(Insn i);         // (rA|0) + d
  void ea_x(Insn i);         // (rA|0) + rB
  void emit_inline(const InsnInfo& x);
  void emit_node(std::size_t k);
  void emit_fall();
  void emit_resume_block();
  void prologue(u32 e);

  Ctx& ctx_;
  const FunctionCfg& f_;
  Mode mode_;
  int hook_;
  int self_slot_;
  Fn* body_ = nullptr;
  std::vector<Node> nodes_;              // per word, plus the fall-off-the-end node
  std::vector<std::vector<int>> jt_succ_;
  std::vector<int> seg_at_;              // per word: its code segment
  std::vector<u32> seg_start_;           // per segment: first address (index 0 = resume block when present)
  std::vector<int> level_;               // per segment: the level of its block
  std::vector<std::pair<u32, u32>> resume_out_;
  std::vector<u32> resume_labels_;
  bool has_resume_ = false, dispatch_ = false;
  int loop_level_ = -1, pre_level_ = -1;
  int cur_seg_ = 0;
  s64 p_ = 0;  // instructions started since the ticks local was last updated
  RegSet used_ = 0;
};


bool falls_through(const InsnInfo& x) {
  switch (x.flow) {
    case Flow::Jump: case Flow::JumpTable: case Flow::Rfi: case Flow::Trap: return false;
    case Flow::TailCall: case Flow::IndirectJump: case Flow::Return: case Flow::CondReturn: return x.conditional;
    default: return true;
  }
}

// rt::on_entry, the entry safe point, and the return-path check of a function
// entry (runtime/native.h), on the in-memory state. `miss` runs when an
// interrupt at the entry safe point moved the guest elsewhere.
void emit_prologue(Fn& b, u32 e, const std::function<void()>& miss) {
  b.get(0);
  b.i32c(e);
  b.mem(op::i32_store, 2, kPc);
  b.global(gHook);
  b.mem(op::i32_load, 2, 0);
  b.if_();
  b.get(0);
  b.i32c(e);
  b.call(iOnEntry);
  b.end();
  b.get(0);
  b.mem(op::i64_load, 3, kTicks);
  b.get(0);
  b.mem(op::i64_load, 3, kNextEvent);
  b.op(op::i64_ge_u);
  b.if_();
  b.get(0);
  b.call(iSafepoint);
  b.end();
  b.get(0);
  b.mem(op::i32_load, 2, kPc);
  b.i32c(e);
  b.op(op::i32_ne);
  b.global(gUnwinding);
  b.mem(op::i32_load8_u, 0, 0);
  b.op(op::i32_or);
  b.if_();
  miss();
  b.end();
}

void emit_leave(Fn& b) {
  b.global(gUnwinding);
  b.i32c(1);
  b.mem(op::i32_store8, 0, 0);
  b.op(op::return_);
}

// ---- FuncGen ----

bool FuncGen::classify(std::string* error) {
  const std::size_t n = f_.insns.size();
  nodes_.assign(n + 1, Node{});
  nodes_[n].grp = gFall;
  std::vector<bool> back(n, false), idle(n, false);
  for (u32 a : f_.back_edges) back[(a - f_.start) / 4] = true;
  for (u32 a : f_.idle_spins) idle[(a - f_.start) / 4] = true;
  auto local = [&](u32 target, int* out) {
    if (!f_.contains(target) || !f_.reachable[(target - f_.start) / 4]) return false;
    *out = static_cast<int>((target - f_.start) / 4);
    return true;
  };
  for (std::size_t k = 0; k < n; ++k) {
    if (!f_.reachable[k]) continue;
    const InsnInfo& x = f_.insns[k];
    Node& N = nodes_[k];
    Insn i{x.word};
    Effects e = ppc::effects(x.op, i);
    N.cond = x.conditional;
    N.pre = idle[k] ? pIdle : back[k] ? pBack : pNone;
    int next = static_cast<int>(k + 1);
    if (k + 1 < n && !f_.reachable[k + 1] && falls_through(x)) {
      if (error) *error = f_.sym->name + ": falls through into unreachable code";
      return false;
    }
    auto set = [&](u8 kind, u8 grp, bool with_effects) {
      N.kind = kind;
      N.grp = grp;
      if (with_effects) {
        N.R = e.reads;
        N.W = e.writes;
      }
    };
    switch (x.flow) {
      case Flow::Plain:
        if (x.op == Op::sc) {
          set(kSc, gCall, false);
          N.cond = false;
        } else if (x.op == Op::tw || x.op == Op::twi) {
          set(kTw, gHelper, true);
        } else if (x.op == Op::eciwx || x.op == Op::ecowx) {
          set(kTrapOp, gEnd, false);
        } else if (is_nop(x.op)) {
          set(kNop, gInline, false);
        } else if (ctx_.opt.inline_ops && is_inline(x.op, i)) {
          set(kInline, gInline, true);
          N.mem = is_memory(x.op);
        } else {
          set(kHelper, gHelper, true);
        }
        N.s0 = next;
        break;
      case Flow::Jump:
      case Flow::CondJump:
        set(x.flow == Flow::Jump ? kJump : kCJump, gInline, true);
        if (!local(x.target, &N.s0)) {
          if (error) *error = f_.sym->name + ": jump outside the function";
          return false;
        }
        if (x.flow == Flow::CondJump) N.s1 = next;
        break;
      case Flow::Call: case Flow::IndirectCall: case Flow::AbsoluteCall:
        set(kCall, gCall, true);
        N.s0 = next;
        break;
      case Flow::TailCall: case Flow::Return: case Flow::CondReturn: case Flow::IndirectJump:
        set(x.flow == Flow::TailCall ? kTail : x.flow == Flow::IndirectJump ? kIJump : kRet, gExit, true);
        if (N.cond) N.s0 = next;
        break;
      case Flow::JumpTable: {
        set(kJTab, gInline, true);
        N.jt = static_cast<int>(jt_succ_.size());
        jt_succ_.emplace_back();
        for (const auto& t : f_.tables)
          if (t.site == x.addr)
            for (u32 a : t.targets) {
              int s;
              if (!local(a, &s)) {
                if (error) *error = f_.sym->name + ": jump table target outside the function";
                return false;
              }
              jt_succ_.back().push_back(s);
            }
        break;
      }
      case Flow::Rfi:
        set(kRfi, gEnd, false);
        break;
      case Flow::Trap:
        set(kTrap, gEnd, false);
        break;
    }
    used_ |= N.R | N.W;
  }
  return true;
}

void FuncGen::dataflow() {
  const std::size_t n = f_.insns.size();
  auto each_succ = [&](const Node& N, auto&& fn) {
    if (N.s0 >= 0) fn(N.s0);
    if (N.s1 >= 0) fn(N.s1);
    if (N.jt >= 0)
      for (int s : jt_succ_[static_cast<std::size_t>(N.jt)]) fn(s);
  };
  // Forward: the registers whose local may differ from memory ("dirty").
  for (bool changed = true; changed;) {
    changed = false;
    for (std::size_t k = 0; k < n; ++k) {
      if (!f_.reachable[k]) continue;
      Node& N = nodes_[k];
      RegSet D = dm(N);
      switch (N.grp) {
        case gInline: D |= N.W; break;
        case gHelper: D &= ~(N.W | N.R); break;
        case gCall: D = N.cond ? (D | N.W) : 0; break;
        case gExit: D |= N.W; break;  // only the not-taken path continues
        default: break;
      }
      each_succ(N, [&](int s) {
        RegSet& in = nodes_[static_cast<std::size_t>(s)].Din;
        if ((in | D) != in) {
          in |= D;
          changed = true;
        }
      });
    }
  }
  // Backward: the registers whose local must hold the guest value ("live").
  // Spilling reads a local, so a register that may be dirty at a spill is live
  // there: every path to the spill then loads or writes it.
  const bool precise = ctx_.opt.precise_io;
  nodes_[n].Lin = nodes_[n].Din;
  for (bool changed = true; changed;) {
    changed = false;
    for (std::size_t kk = n; kk-- > 0;) {
      if (!f_.reachable[kk]) continue;
      Node& N = nodes_[kk];
      RegSet out = 0;
      each_succ(N, [&](int s) { out |= nodes_[static_cast<std::size_t>(s)].Lin; });
      RegSet D = dm(N), L;
      switch (N.grp) {
        case gInline: L = (out & ~N.W) | N.R | (precise && N.mem ? D : 0); break;
        case gHelper: L = (out & ~N.W) | (N.R & D); break;
        case gCall: case gExit: L = N.cond ? (((out | D) & ~N.W) | N.R) : ((D & ~N.W) | N.R); break;
        default: L = D; break;
      }
      RegSet in = N.pre == pBack ? (L | N.Din) : N.pre == pIdle ? N.Din : L;
      if (in != N.Lin) changed = true;
      N.Lin = in;
      N.Lout = out;
      N.Lm = L;
    }
  }
}

void FuncGen::flush(RegSet s) {
  for (int r = 0; r < reg::kCount; ++r) {
    if (!(s & ppc::bit(r)) || regloc_[r] < 0) continue;
    body_->get(kCpu);
    reg_get(r);
    body_->mem(op::i32_store, 2, reg_offset(r));
    ++ctx_.out->stats.spills;
  }
}

void FuncGen::reload(RegSet s) {
  for (int r = 0; r < reg::kCount; ++r) {
    if (!(s & ppc::bit(r)) || regloc_[r] < 0) continue;
    body_->get(kCpu);
    body_->mem(op::i32_load, 2, reg_offset(r));
    reg_set(r);
    ++ctx_.out->stats.reloads;
  }
}

void FuncGen::miss() {
  if (has_resume_) {
    body_->i32c(0);
    body_->set(L_label);
    body_->br(loop_level_);
  } else {
    leave();
  }
}

void FuncGen::check(u32 expect) {
  body_->get(kCpu);
  body_->mem(op::i32_load, 2, kPc);
  body_->i32c(expect);
  body_->op(op::i32_ne);
  body_->global(gUnwinding);
  body_->mem(op::i32_load8_u, 0, 0);
  body_->op(op::i32_or);
  body_->if_();
  miss();
  body_->end();
}

void FuncGen::jump(int seg) {
  if (seg > cur_seg_) {
    body_->br(level_[static_cast<std::size_t>(seg)]);
  } else {
    body_->i32c(seg);
    body_->set(L_label);
    body_->br(loop_level_);
  }
}

void FuncGen::cond_expr(const InsnInfo& x) {
  Insn i{x.word};
  if (x.op == Op::b) {
    body_->i32c(1);
    return;
  }
  u32 bo = i.bo();
  bool dec = !(bo & 4), test = !(bo & 16);
  if (dec) {
    reg_get(reg::CTR);
    body_->i32c(1);
    body_->op(op::i32_sub);
    body_->tee(static_cast<u32>(regloc_[reg::CTR]));
    if (bo & 2) {
      body_->op(op::i32_eqz);
    } else {
      body_->i32c(0);
      body_->op(op::i32_ne);
    }
  }
  if (test) {
    reg_get(reg::CR);
    u32 sh = 31 - i.bi();
    if (sh) {
      body_->i32c(sh);
      body_->op(op::i32_shr_u);
    }
    body_->i32c(1);
    body_->op(op::i32_and);
    if (!((bo >> 3) & 1)) body_->op(op::i32_eqz);
  }
  if (dec && test) body_->op(op::i32_and);
  if (!dec && !test) body_->i32c(1);
}

void FuncGen::cr0_from(int r) {
  reg_get(reg::CR);
  body_->i32c(0x0FFFFFFFu);
  body_->op(op::i32_and);
  reg_get(r);
  body_->i32c(0);
  reg_get(reg::SO);
  body_->call(hCmps);
  body_->i32c(28);
  body_->op(op::i32_shl);
  body_->op(op::i32_or);
  reg_set(reg::CR);
}

void FuncGen::set_cr_field(u32 field, const std::function<void()>& bits) {
  u32 sh = 28 - 4 * field;
  reg_get(reg::CR);
  body_->i32c(~(0xFu << sh));
  body_->op(op::i32_and);
  bits();
  if (sh) {
    body_->i32c(sh);
    body_->op(op::i32_shl);
  }
  body_->op(op::i32_or);
  reg_set(reg::CR);
}

void FuncGen::ea_d(Insn i) {
  if (i.rA()) {
    reg_get(static_cast<int>(i.rA()));
    if (i.simm()) {
      body_->i32c(i.simm());
      body_->op(op::i32_add);
    }
  } else {
    body_->i32c(i.simm());
  }
}

void FuncGen::ea_x(Insn i) {
  if (i.rA()) {
    reg_get(static_cast<int>(i.rA()));
    reg_get(static_cast<int>(i.rB()));
    body_->op(op::i32_add);
  } else {
    reg_get(static_cast<int>(i.rB()));
  }
}

void FuncGen::emit_inline(const InsnInfo& x) {
  Fn& b = *body_;
  const Insn i{x.word};
  const Op o = x.op;
  const u32 a = x.addr;
  const int rD = static_cast<int>(i.rD()), rA = static_cast<int>(i.rA()), rB = static_cast<int>(i.rB()),
            rS = static_cast<int>(i.rS());
  auto G = [&](int r) { reg_get(r); };
  auto S = [&](int r) { reg_set(r); };
  auto rc = [&](int r) {
    if (i.rc()) cr0_from(r);
  };
  auto bin = [&](u8 opcode) { b.op(opcode); };
  auto not_ = [&] {
    b.i32c(-1);
    b.op(op::i32_xor);
  };
  // rD = A + B + carry-in, XER[CA] = the carry out (sem::add_with).
  auto wide = [&](const std::function<void()>& A, const std::function<void()>& B, int cin /*0, 1, -1 = CA*/) {
    A();
    b.op(op::i64_extend_i32_u);
    B();
    b.op(op::i64_extend_i32_u);
    b.op(op::i64_add);
    if (cin == 1) {
      b.i64c(1);
      b.op(op::i64_add);
    } else if (cin < 0) {
      G(reg::CA);
      b.op(op::i64_extend_i32_u);
      b.op(op::i64_add);
    }
    b.tee(L_w);
    b.op(op::i32_wrap_i64);
    b.set(L_tmp);
    b.get(L_w);
    b.i64c(32);
    b.op(op::i64_shr_u);
    b.op(op::i32_wrap_i64);
    S(reg::CA);
    b.get(L_tmp);
    S(rD);
  };
  auto rA_ = [&] { G(rA); };
  auto rB_ = [&] { G(rB); };
  auto nrA = [&] {
    G(rA);
    not_();
  };
  auto zero = [&] { b.i32c(0); };
  auto ones = [&] { b.i32c(-1); };
  auto simm = [&] { b.i32c(i.simm()); };
  // Effective address on the stack after the cpu argument. Update forms keep
  // it in L_tmp for the base register write that follows the access.
  auto address = [&](int mode /*0 d, 1 du, 2 x, 3 xu*/) {
    if (mode == 1 || mode == 3) {
      G(rA);
      if (mode == 1) b.i32c(i.simm());
      else G(rB);
      b.op(op::i32_add);
      b.set(L_tmp);
      b.get(kCpu);
      b.get(L_tmp);
    } else {
      b.get(kCpu);
      if (mode == 0) ea_d(i);
      else ea_x(i);
    }
  };
  auto update = [&](int mode) {
    if (mode == 1 || mode == 3) {
      b.get(L_tmp);
      S(rA);
    }
  };
  auto load = [&](u32 helper, bool sext16, int mode) {
    address(mode);
    b.i32c(a);
    ticks_expr();
    b.call(helper);
    if (sext16) b.op(op::i32_extend16_s);
    S(rD);
    update(mode);
  };
  auto store = [&](u32 helper, int mode) {
    address(mode);
    G(rS);
    b.i32c(a);
    ticks_expr();
    b.call(helper);
    update(mode);
  };
  auto cr_bit = [&](u32 bit) {
    G(reg::CR);
    if (31 - bit) {
      b.i32c(31 - bit);
      b.op(op::i32_shr_u);
    }
    b.i32c(1);
    b.op(op::i32_and);
  };
  switch (o) {
    case Op::addi: case Op::addis: {
      s32 v = o == Op::addi ? i.simm() : static_cast<s32>(i.uimm() << 16);
      if (rA) {
        G(rA);
        if (v) {
          b.i32c(v);
          bin(op::i32_add);
        }
      } else {
        b.i32c(v);
      }
      S(rD);
      return;
    }
    case Op::add: G(rA); G(rB); bin(op::i32_add); S(rD); rc(rD); return;
    case Op::subf: G(rB); G(rA); bin(op::i32_sub); S(rD); rc(rD); return;
    case Op::neg: b.i32c(0); G(rA); bin(op::i32_sub); S(rD); rc(rD); return;
    case Op::mullw: G(rA); G(rB); bin(op::i32_mul); S(rD); rc(rD); return;
    case Op::mulli: G(rA); b.i32c(i.simm()); bin(op::i32_mul); S(rD); return;
    case Op::mulhw: case Op::mulhwu: {
      u8 ext = o == Op::mulhw ? op::i64_extend_i32_s : op::i64_extend_i32_u;
      G(rA);
      bin(ext);
      G(rB);
      bin(ext);
      bin(op::i64_mul);
      b.i64c(32);
      bin(op::i64_shr_u);
      bin(op::i32_wrap_i64);
      S(rD);
      rc(rD);
      return;
    }
    case Op::divw: G(rA); G(rB); b.call(hDivw); S(rD); rc(rD); return;
    case Op::divwu: G(rA); G(rB); b.call(hDivwu); S(rD); rc(rD); return;
    case Op::addc: wide(rA_, rB_, 0); rc(rD); return;
    case Op::adde: wide(rA_, rB_, -1); rc(rD); return;
    case Op::addze: wide(rA_, zero, -1); rc(rD); return;
    case Op::addme: wide(rA_, ones, -1); rc(rD); return;
    case Op::subfc: wide(nrA, rB_, 1); rc(rD); return;
    case Op::subfe: wide(nrA, rB_, -1); rc(rD); return;
    case Op::subfze: wide(nrA, zero, -1); rc(rD); return;
    case Op::subfme: wide(nrA, ones, -1); rc(rD); return;
    case Op::addic: wide(rA_, simm, 0); return;
    case Op::addic_rc: wide(rA_, simm, 0); cr0_from(rD); return;
    case Op::subfic: wide(nrA, simm, 1); return;
    case Op::cmp:
      set_cr_field(i.crfD(), [&] { G(rA); G(rB); G(reg::SO); b.call(hCmps); });
      return;
    case Op::cmpi:
      set_cr_field(i.crfD(), [&] { G(rA); b.i32c(i.simm()); G(reg::SO); b.call(hCmps); });
      return;
    case Op::cmpl:
      set_cr_field(i.crfD(), [&] { G(rA); G(rB); G(reg::SO); b.call(hCmpu); });
      return;
    case Op::cmpli:
      set_cr_field(i.crfD(), [&] { G(rA); b.i32c(i.uimm()); G(reg::SO); b.call(hCmpu); });
      return;
    case Op::and_: G(rS); G(rB); bin(op::i32_and); S(rA); rc(rA); return;
    case Op::andc: G(rS); G(rB); not_(); bin(op::i32_and); S(rA); rc(rA); return;
    case Op::or_: G(rS); G(rB); bin(op::i32_or); S(rA); rc(rA); return;
    case Op::orc: G(rS); G(rB); not_(); bin(op::i32_or); S(rA); rc(rA); return;
    case Op::xor_: G(rS); G(rB); bin(op::i32_xor); S(rA); rc(rA); return;
    case Op::nand: G(rS); G(rB); bin(op::i32_and); not_(); S(rA); rc(rA); return;
    case Op::nor: G(rS); G(rB); bin(op::i32_or); not_(); S(rA); rc(rA); return;
    case Op::eqv: G(rS); G(rB); bin(op::i32_xor); not_(); S(rA); rc(rA); return;
    case Op::extsb: G(rS); bin(op::i32_extend8_s); S(rA); rc(rA); return;
    case Op::extsh: G(rS); bin(op::i32_extend16_s); S(rA); rc(rA); return;
    case Op::cntlzw: G(rS); bin(op::i32_clz); S(rA); rc(rA); return;
    case Op::ori: case Op::oris: case Op::xori: case Op::xoris: {
      u32 v = (o == Op::oris || o == Op::xoris) ? i.uimm() << 16 : i.uimm();
      G(rS);
      if (v) {
        b.i32c(v);
        bin(o == Op::ori || o == Op::oris ? op::i32_or : op::i32_xor);
      }
      S(rA);
      return;
    }
    case Op::andi_rc: case Op::andis_rc:
      G(rS);
      b.i32c(o == Op::andi_rc ? i.uimm() : i.uimm() << 16);
      bin(op::i32_and);
      S(rA);
      cr0_from(rA);
      return;
    case Op::rlwinm: case Op::rlwnm: case Op::rlwimi: {
      u32 m = ppc::rot_mask(i.mb(), i.me());
      G(rS);
      if (o == Op::rlwnm) {
        G(rB);  // wasm rotates modulo 32, like the & 31
        bin(op::i32_rotl);
      } else if (i.sh()) {
        b.i32c(i.sh());
        bin(op::i32_rotl);
      }
      if (m != 0xFFFFFFFFu) {
        b.i32c(m);
        bin(op::i32_and);
      }
      if (o == Op::rlwimi) {
        G(rA);
        b.i32c(~m);
        bin(op::i32_and);
        bin(op::i32_or);
      }
      S(rA);
      rc(rA);
      return;
    }
    case Op::slw: case Op::srw:
      // n = rB & 63: 0 when n > 31, else rS shifted by n (wasm shifts modulo 32).
      b.i32c(0);
      G(rS);
      G(rB);
      bin(o == Op::slw ? op::i32_shl : op::i32_shr_u);
      G(rB);
      b.i32c(32);
      bin(op::i32_and);
      bin(op::select);
      S(rA);
      rc(rA);
      return;
    case Op::srawi: {
      u32 n = i.sh();
      if (n == 0) {
        b.i32c(0);
        S(reg::CA);
        G(rS);
      } else {
        G(rS);
        b.i32c(0);
        bin(op::i32_lt_s);
        G(rS);
        b.i32c((1u << n) - 1);
        bin(op::i32_and);
        b.i32c(0);
        bin(op::i32_ne);
        bin(op::i32_and);
        S(reg::CA);
        G(rS);
        b.i32c(n);
        bin(op::i32_shr_s);
      }
      S(rA);
      rc(rA);
      return;
    }
    case Op::crand: case Op::crandc: case Op::creqv: case Op::crnand: case Op::crnor: case Op::cror:
    case Op::crorc: case Op::crxor: {
      cr_bit(i.crbA());
      cr_bit(i.crbB());
      auto flip = [&] {
        b.i32c(1);
        bin(op::i32_xor);
      };
      switch (o) {
        case Op::crand: bin(op::i32_and); break;
        case Op::crandc: flip(); bin(op::i32_and); break;
        case Op::creqv: bin(op::i32_xor); flip(); break;
        case Op::crnand: bin(op::i32_and); flip(); break;
        case Op::crnor: bin(op::i32_or); flip(); break;
        case Op::cror: bin(op::i32_or); break;
        case Op::crorc: flip(); bin(op::i32_or); break;
        default: bin(op::i32_xor); break;
      }
      b.set(L_tmp);
      u32 sh = 31 - i.crbD();
      G(reg::CR);
      b.i32c(~(1u << sh));
      bin(op::i32_and);
      b.get(L_tmp);
      if (sh) {
        b.i32c(sh);
        bin(op::i32_shl);
      }
      bin(op::i32_or);
      S(reg::CR);
      return;
    }
    case Op::mcrf:
      set_cr_field(i.crfD(), [&] {
        G(reg::CR);
        u32 sh = 28 - 4 * i.crfS();
        if (sh) {
          b.i32c(sh);
          bin(op::i32_shr_u);
        }
        b.i32c(0xF);
        bin(op::i32_and);
      });
      return;
    case Op::mfcr: G(reg::CR); S(rD); return;
    case Op::mtcrf: {
      u32 m = 0;
      for (u32 f = 0; f < 8; ++f)
        if (i.crm() & (0x80u >> f)) m |= 0xF0000000u >> (4 * f);
      G(reg::CR);
      b.i32c(~m);
      bin(op::i32_and);
      G(rS);
      b.i32c(m);
      bin(op::i32_and);
      bin(op::i32_or);
      S(reg::CR);
      return;
    }
    case Op::mfspr: G(i.spr() == ppc::spr::LR ? reg::LR : reg::CTR); S(rD); return;
    case Op::mtspr: G(rS); S(i.spr() == ppc::spr::LR ? reg::LR : reg::CTR); return;
    case Op::lbz: load(hRd8, false, 0); return;
    case Op::lbzu: load(hRd8, false, 1); return;
    case Op::lbzx: load(hRd8, false, 2); return;
    case Op::lbzux: load(hRd8, false, 3); return;
    case Op::lhz: load(hRd16, false, 0); return;
    case Op::lhzu: load(hRd16, false, 1); return;
    case Op::lhzx: load(hRd16, false, 2); return;
    case Op::lhzux: load(hRd16, false, 3); return;
    case Op::lha: load(hRd16, true, 0); return;
    case Op::lhau: load(hRd16, true, 1); return;
    case Op::lhax: load(hRd16, true, 2); return;
    case Op::lhaux: load(hRd16, true, 3); return;
    case Op::lwz: load(hRd32, false, 0); return;
    case Op::lwzu: load(hRd32, false, 1); return;
    case Op::lwzx: load(hRd32, false, 2); return;
    case Op::lwzux: load(hRd32, false, 3); return;
    case Op::stb: store(hWr8, 0); return;
    case Op::stbu: store(hWr8, 1); return;
    case Op::stbx: store(hWr8, 2); return;
    case Op::stbux: store(hWr8, 3); return;
    case Op::sth: store(hWr16, 0); return;
    case Op::sthu: store(hWr16, 1); return;
    case Op::sthx: store(hWr16, 2); return;
    case Op::sthux: store(hWr16, 3); return;
    case Op::stw: store(hWr32, 0); return;
    case Op::stwu: store(hWr32, 1); return;
    case Op::stwx: store(hWr32, 2); return;
    case Op::stwux: store(hWr32, 3); return;
    default:
      return;  // is_inline() and this switch list the same opcodes
  }
}

void FuncGen::emit_resume_block() {
  // rt.resume: resume_target(), then the dispatcher index of the label; 0 = keep unwinding.
  body_->get(kCpu);
  body_->get(L_sp);
  body_->global(gTableBase);
  body_->i32c(self_slot_);
  body_->op(op::i32_add);
  body_->call(iResume);
  body_->tee(L_label);
  body_->op(op::i32_eqz);
  body_->if_();
  body_->op(op::return_);
  body_->end();
  RegSet ru = 0;
  for (u32 a : resume_labels_) ru |= nodes_[(a - f_.start) / 4].Lin;
  reload(ru);
  load_ticks();
  body_->br(loop_level_);
}

void FuncGen::emit_fall() {
  const Node& F = nodes_[f_.insns.size()];
  materialize();
  flush(F.Din);
  store_ticks();
  body_->get(kCpu);
  if (f_.falls_into) {
    body_->call(ctx_.callable.at(f_.falls_into));
    body_->op(op::return_);
  } else {
    body_->i32c(f_.end);
    body_->i32c(static_cast<u32>(WasmTrap::RanOffEnd));
    body_->call(iTrap);
    body_->op(op::unreachable);
  }
}

void FuncGen::emit_node(std::size_t k) {
  Fn& b = *body_;
  const InsnInfo& x = f_.insns[k];
  const Node& N = nodes_[k];
  const u32 a = x.addr, ret = a + 4;
  auto safepoint = [&] {
    flush(N.Din);
    store_pc(a);
    store_ticks();
    load_sp();
    b.get(kCpu);
    b.call(iSafepoint);
    check(a);
    reload(N.Lm);
    load_ticks();
  };
  if (N.pre == pIdle) {
    materialize();
    safepoint();
  } else if (N.pre == pBack) {
    materialize();
    b.get(L_t);
    b.get(kCpu);
    b.mem(op::i64_load, 3, kNextEvent);
    b.op(op::i64_ge_u);
    b.if_();
    safepoint();
    b.end();
  }
  ++p_;  // ++c.ticks: this instruction has started
  ++ctx_.out->stats.instructions;
  const RegSet D = dm(N);
  switch (N.kind) {
    case kNop:
      ++ctx_.out->stats.inline_insns;
      return;
    case kInline:
      ++ctx_.out->stats.inline_insns;
      if (ctx_.opt.precise_io && N.mem) flush(D);
      emit_inline(x);
      return;
    case kHelper:
      ++ctx_.out->stats.helper_insns;
      flush(N.R & D);
      b.get(kCpu);
      b.i32c(x.word);
      b.i32c(a);
      ticks_expr();
      b.call(iExec);
      reload(N.W & N.Lout);
      return;
    case kTw:
      ++ctx_.out->stats.helper_insns;
      flush(N.R & D);
      b.get(kCpu);
      b.i32c(x.word);
      b.i32c(a);
      b.call(iTw);
      return;
    case kTrapOp: case kTrap:
      ++ctx_.out->stats.branch_insns;
      materialize();
      flush(D);
      store_ticks();
      b.get(kCpu);
      b.i32c(a);
      b.i32c(static_cast<u32>(N.kind == kTrapOp     ? WasmTrap::ExternalControl
                              : x.op == Op::invalid ? WasmTrap::InvalidInstruction
                                                    : WasmTrap::UnconditionalTrap));
      b.call(iTrap);
      b.op(op::unreachable);
      return;
    case kSc:
      ++ctx_.out->stats.helper_insns;
      materialize();
      flush(D);
      store_pc(ret);
      store_ticks();
      b.get(kCpu);
      b.call(iSystemCall);
      check(ret);
      reload(N.Lout);
      load_ticks();
      return;
    case kRfi:
      ++ctx_.out->stats.branch_insns;
      materialize();
      flush(D);
      store_ticks();
      b.get(kCpu);
      b.call(iRfi);
      leave();
      return;
    default:
      break;
  }
  ++ctx_.out->stats.branch_insns;
  materialize();
  switch (N.kind) {
    case kJump:
      jump(seg_at_[static_cast<std::size_t>(N.s0)]);
      return;
    case kCJump: {
      int t = seg_at_[static_cast<std::size_t>(N.s0)];
      cond_expr(x);
      if (t > cur_seg_) {
        b.br_if(level_[static_cast<std::size_t>(t)]);
      } else {
        b.if_();
        jump(t);
        b.end();
      }
      return;
    }
    case kJTab: {
      const auto& targets = jt_succ_[static_cast<std::size_t>(N.jt)];
      u32 lo = 0xFFFFFFFFu, hi = 0;
      std::vector<int> distinct;
      for (int s : targets) {
        u32 t = f_.start + 4 * static_cast<u32>(s);
        lo = std::min(lo, t);
        hi = std::max(hi, t);
        if (std::find(distinct.begin(), distinct.end(), s) == distinct.end()) distinct.push_back(s);
      }
      int dflt = b.block();
      std::vector<int> lv(distinct.size());
      for (std::size_t d = distinct.size(); d-- > 0;) lv[d] = b.block();
      std::vector<int> table((hi - lo) / 4 + 1, dflt);
      for (std::size_t d = 0; d < distinct.size(); ++d)
        table[(f_.start + 4 * static_cast<u32>(distinct[d]) - lo) / 4] = lv[d];
      reg_get(reg::CTR);
      b.i32c(~3u);
      b.op(op::i32_and);
      b.i32c(lo);
      b.op(op::i32_sub);
      b.i32c(2);
      b.op(op::i32_shr_u);
      b.br_table(table, dflt);
      for (std::size_t d = 0; d < distinct.size(); ++d) {
        b.end();
        jump(seg_at_[static_cast<std::size_t>(distinct[d])]);
      }
      b.end();
      b.get(kCpu);
      b.i32c(a);
      b.i32c(static_cast<u32>(WasmTrap::JumpOutsideTable));
      b.call(iTrap);
      b.op(op::unreachable);
      return;
    }
    case kCall: {
      const bool indirect = x.flow == Flow::IndirectCall;
      if (N.cond) {
        cond_expr(x);
        b.set(L_tc);
      }
      if (indirect) {
        reg_get(x.op == Op::bclr ? reg::LR : reg::CTR);
        b.i32c(~3u);
        b.op(op::i32_and);
        b.set(L_tgt);
      }
      if (N.W & ppc::bit(reg::LR)) {
        b.i32c(ret);
        reg_set(reg::LR);
      }
      if (N.cond) {
        b.get(L_tc);
        b.if_();
      }
      flush(D | N.W);
      store_ticks();
      load_sp();
      b.get(kCpu);
      if (x.flow == Flow::Call) {
        b.call(ctx_.callable.at(x.target));
      } else if (indirect) {
        b.get(L_tgt);
        b.call(iCallIndirect);
      } else {
        b.i32c(x.target);
        b.call(iAbsoluteCall);
      }
      check(ret);
      reload(N.Lout);
      load_ticks();
      if (N.cond) b.end();
      return;
    }
    case kTail: case kRet: case kIJump: {
      if (N.cond) {
        cond_expr(x);
        b.if_();
      }
      flush(D | N.W);
      if (N.kind == kTail) {
        store_ticks();
        b.get(kCpu);
        b.return_call(ctx_.callable.at(x.target));
      } else if (N.kind == kRet) {
        b.get(kCpu);
        reg_get(reg::LR);
        b.i32c(~3u);
        b.op(op::i32_and);
        b.mem(op::i32_store, 2, kPc);
        store_ticks();
        b.op(op::return_);
      } else {
        store_ticks();
        b.get(kCpu);
        reg_get(reg::CTR);
        b.i32c(~3u);
        b.op(op::i32_and);
        b.call(iCallIndirect);
        b.op(op::return_);
      }
      if (N.cond) b.end();
      return;
    }
    default:
      return;
  }
}

bool FuncGen::run(Fn& body, std::string* error) {
  body_ = &body;
  if (!classify(error)) return false;
  const std::size_t n = f_.insns.size();
  // Resume labels (runtime/native.h): every call's return address and every
  // back edge, except entries; none in a replaced function's original.
  std::vector<u32> entries = mode_ == Mode::Body ? f_.entries : std::vector<u32>{f_.start};
  if (mode_ != Mode::Orig) {
    auto add = [&](u32 a) {
      if (f_.contains(a) && f_.reachable[(a - f_.start) / 4] &&
          std::find(f_.entries.begin(), f_.entries.end(), a) == f_.entries.end())
        resume_labels_.push_back(a);
    };
    for (u32 a : f_.resume_points) add(a);
    for (u32 a : f_.back_edges) add(a);
    std::sort(resume_labels_.begin(), resume_labels_.end());
    resume_labels_.erase(std::unique(resume_labels_.begin(), resume_labels_.end()), resume_labels_.end());
  }
  has_resume_ = !resume_labels_.empty();
  dataflow();

  // Code segments: one per label.
  std::vector<u32> labels(entries.begin(), entries.end());
  for (std::size_t k = 0; k < n; ++k) {
    if (!f_.reachable[k]) continue;
    const Node& N = nodes_[k];
    if (N.kind == kJump || N.kind == kCJump) labels.push_back(f_.start + 4 * static_cast<u32>(N.s0));
    if (N.jt >= 0)
      for (int s : jt_succ_[static_cast<std::size_t>(N.jt)]) labels.push_back(f_.start + 4 * static_cast<u32>(s));
  }
  labels.insert(labels.end(), resume_labels_.begin(), resume_labels_.end());
  std::sort(labels.begin(), labels.end());
  labels.erase(std::unique(labels.begin(), labels.end()), labels.end());
  if (labels.empty() || labels.front() != f_.start) {
    if (error) *error = f_.sym->name + ": the entry is not the first label";
    return false;
  }
  const int first = has_resume_ ? 1 : 0;
  seg_start_.clear();
  if (has_resume_) seg_start_.push_back(0);
  seg_start_.insert(seg_start_.end(), labels.begin(), labels.end());
  seg_at_.assign(n, -1);
  for (std::size_t k = 0, l = 0; k < n; ++k) {
    u32 a = f_.start + 4 * static_cast<u32>(k);
    while (l + 1 < labels.size() && labels[l + 1] <= a) ++l;
    seg_at_[k] = first + static_cast<int>(l);
  }
  dispatch_ = has_resume_ || mode_ == Mode::Body || !f_.tables.empty();
  for (std::size_t k = 0; k < n && !dispatch_; ++k) {
    if (!f_.reachable[k]) continue;
    const Node& N = nodes_[k];
    if ((N.kind == kJump || N.kind == kCJump) && seg_at_[static_cast<std::size_t>(N.s0)] <= seg_at_[k]) dispatch_ = true;
  }
  if (dispatch_) ++ctx_.out->stats.dispatch_functions;
  for (u32 a : resume_labels_) resume_out_.push_back({a, static_cast<u32>(seg_at_[(a - f_.start) / 4])});
  ctx_.out->stats.resume_labels += resume_labels_.size();

  // Locals: cpu [, entry], i32 temporaries and the register locals, then the i64s.
  u32 next = mode_ == Mode::Body ? 2 : 1;
  const u32 params = next;
  L_label = next++;
  L_sp = next++;
  L_tc = next++;
  L_tgt = next++;
  L_tmp = next++;
  for (int r = 0; r < reg::kCount; ++r) regloc_[r] = (used_ & ppc::bit(r)) ? static_cast<int>(next++) : -1;
  const u32 n_i32 = next - params;
  L_t = next++;
  L_w = next++;
  body.uleb(2);
  body.uleb(n_i32);
  body.byte(kI32);
  body.uleb(2);
  body.byte(kI64);

  // Preamble.
  load_sp();
  if (mode_ == Mode::Body) {
    body.get(1);
    body.set(L_label);
    RegSet live = 0;
    for (u32 e : f_.entries) live |= nodes_[(e - f_.start) / 4].Lin;
    reload(live);
    load_ticks();
  } else {
    if (has_resume_) {
      body.i32c(0);
      body.set(L_label);
      pre_level_ = body.block();
      body.global(gResume);
      body.mem(op::i32_load8_u, 0, 0);
      body.br_if(pre_level_);
    }
    if (mode_ == Mode::Plain) {
      emit_prologue(body, f_.start, [&] {
        if (has_resume_) body.br(pre_level_);
        else leave();
      });
      if (hook_ >= 0) {
        body.get(kCpu);
        body.i32c(hook_);
        body.call(iHleBefore);
      }
    }
    reload(nodes_[0].Lin);
    load_ticks();
    if (dispatch_) {
      body.i32c(seg_at_[0]);
      body.set(L_label);
    }
    if (has_resume_) body.end();
  }

  // Segments.
  const int nseg = static_cast<int>(seg_start_.size());
  level_.assign(static_cast<std::size_t>(nseg), -1);
  auto emit_segment = [&](int s) {
    cur_seg_ = s;
    if (has_resume_ && s == 0) {
      emit_resume_block();
      return;
    }
    p_ = 0;
    std::size_t k = (seg_start_[static_cast<std::size_t>(s)] - f_.start) / 4;
    std::size_t end = s + 1 < nseg ? (seg_start_[static_cast<std::size_t>(s) + 1] - f_.start) / 4 : n;
    bool falls = false;
    std::size_t last = k;
    for (; k < end; ++k) {
      if (!f_.reachable[k]) continue;
      emit_node(k);
      falls = falls_through(f_.insns[k]);
      last = k;
    }
    if (falls) {
      if (last + 1 >= n) emit_fall();
      else materialize();
    }
  };
  if (dispatch_) {
    loop_level_ = body.loop();
    for (int s = nseg - 1; s >= 0; --s) level_[static_cast<std::size_t>(s)] = body.block();
    body.get(L_label);
    body.br_table(level_, level_[static_cast<std::size_t>(nseg - 1)]);
    for (int s = 0; s < nseg; ++s) {
      body.end();
      emit_segment(s);
    }
    body.end();
  } else {
    for (int s = nseg - 1; s >= 1; --s) level_[static_cast<std::size_t>(s)] = body.block();
    emit_segment(0);
    for (int s = 1; s < nseg; ++s) {
      body.end();
      emit_segment(s);
    }
  }
  body.byte(op::end);
  if (body.depth != 0) {
    if (error) *error = f_.sym->name + ": unbalanced blocks";
    return false;
  }
  return true;
}

// ---- in-module helpers ----

void swap32_from_local(Fn& h, u32 local) {  // stack: x (also in `local`) -> bswap(x)
  h.i32c(8);
  h.op(op::i32_rotl);
  h.i32c(0x00FF00FFu);
  h.op(op::i32_and);
  h.get(local);
  h.i32c(8);
  h.op(op::i32_rotr);
  h.i32c(0xFF00FF00u);
  h.op(op::i32_and);
  h.op(op::i32_or);
}

// The host pointer of the 64 KiB page holding `ea` (param 1), teed into `p_local`.
void page_ptr(Fn& h, u32 p_local) {
  h.get(0);
  h.mem(op::i32_load, 2, kMem);
  h.get(1);
  h.i32c(16);
  h.op(op::i32_shr_u);
  h.i32c(2);
  h.op(op::i32_shl);
  h.op(op::i32_add);
  h.mem(op::i32_load, 2, 0);
  h.tee(p_local);
}

void host_addr(Fn& h, u32 p_local) {
  h.get(p_local);
  h.get(1);
  h.i32c(0xFFFF);
  h.op(op::i32_and);
  h.op(op::i32_add);
}

// (cpu, ea, pc, ticks) -> value: a mapped page and no page crossing read the
// big-endian bytes directly; anything else is ppc::readN in the runtime.
Fn helper_read(int bytes, u32 slow) {
  Fn h;
  h.uleb(1);
  h.uleb(1);
  h.byte(kI32);  // local 4: the page pointer, then the loaded value
  auto slow_call = [&] {
    h.get(0);
    h.get(1);
    h.get(2);
    h.get(3);
    h.call(slow);
  };
  page_ptr(h, 4);
  h.if_i32();
  if (bytes == 1) {
    host_addr(h, 4);
    h.mem(op::i32_load8_u, 0, 0);
  } else {
    h.get(1);
    h.i32c(0xFFFF);
    h.op(op::i32_and);
    h.i32c(0x10000 - bytes);
    h.op(op::i32_le_u);
    h.if_i32();
    host_addr(h, 4);
    if (bytes == 2) {
      h.mem(op::i32_load16_u, 0, 0);
      h.tee(4);
      h.i32c(8);
      h.op(op::i32_shl);
      h.get(4);
      h.i32c(8);
      h.op(op::i32_shr_u);
      h.op(op::i32_or);
      h.i32c(0xFFFF);
      h.op(op::i32_and);
    } else {
      h.mem(op::i32_load, 0, 0);
      h.tee(4);
      swap32_from_local(h, 4);
    }
    h.else_();
    slow_call();
    h.end();
  }
  h.else_();
  slow_call();
  h.end();
  h.byte(op::end);
  return h;
}

// (cpu, ea, value, pc, ticks), as helper_read.
Fn helper_write(int bytes, u32 slow) {
  Fn h;
  h.uleb(1);
  h.uleb(1);
  h.byte(kI32);  // local 5: the page pointer
  page_ptr(h, 5);
  h.if_();
  if (bytes != 1) {
    h.get(1);
    h.i32c(0xFFFF);
    h.op(op::i32_and);
    h.i32c(0x10000 - bytes);
    h.op(op::i32_le_u);
    h.if_();
  }
  host_addr(h, 5);
  if (bytes == 1) {
    h.get(2);
    h.mem(op::i32_store8, 0, 0);
  } else if (bytes == 2) {
    h.get(2);
    h.i32c(8);
    h.op(op::i32_shl);
    h.get(2);
    h.i32c(8);
    h.op(op::i32_shr_u);
    h.i32c(0xFF);
    h.op(op::i32_and);
    h.op(op::i32_or);
    h.mem(op::i32_store16, 0, 0);
  } else {
    h.get(2);
    swap32_from_local(h, 2);
    h.mem(op::i32_store, 0, 0);
  }
  h.op(op::return_);
  if (bytes != 1) h.end();
  h.end();
  h.get(0);
  h.get(1);
  h.get(2);
  h.get(3);
  h.get(4);
  h.call(slow);
  h.byte(op::end);
  return h;
}

Fn helper_cmp(bool is_signed) {  // (a, b, so) -> LT GT EQ SO bits
  Fn h;
  h.uleb(0);
  auto rel = [&](u8 opc, int sh) {
    h.get(0);
    h.get(1);
    h.op(opc);
    if (sh) {
      h.i32c(sh);
      h.op(op::i32_shl);
    }
  };
  rel(is_signed ? op::i32_lt_s : op::i32_lt_u, 3);
  rel(is_signed ? op::i32_gt_s : op::i32_gt_u, 2);
  h.op(op::i32_or);
  rel(op::i32_eq, 1);
  h.op(op::i32_or);
  h.get(2);
  h.op(op::i32_or);
  h.byte(op::end);
  return h;
}

Fn helper_div(bool is_signed) {  // sem::divw / divwu, the hardware's overflow results included
  Fn h;
  h.uleb(0);
  if (is_signed) {
    h.get(1);
    h.op(op::i32_eqz);
    h.get(0);
    h.i32c(static_cast<s32>(0x80000000u));
    h.op(op::i32_eq);
    h.get(1);
    h.i32c(-1);
    h.op(op::i32_eq);
    h.op(op::i32_and);
    h.op(op::i32_or);
    h.if_i32();
    h.get(0);
    h.i32c(31);
    h.op(op::i32_shr_s);
    h.else_();
    h.get(0);
    h.get(1);
    h.op(op::i32_div_s);
    h.end();
  } else {
    h.get(1);
    h.op(op::i32_eqz);
    h.if_i32();
    h.i32c(0);
    h.else_();
    h.get(0);
    h.get(1);
    h.op(op::i32_div_u);
    h.end();
  }
  h.byte(op::end);
  return h;
}

void functype(Buf& b, const std::vector<u8>& params, const std::vector<u8>& results) {
  b.byte(0x60);
  b.uleb(params.size());
  for (u8 t : params) b.byte(t);
  b.uleb(results.size());
  for (u8 t : results) b.byte(t);
}

}  // namespace

const std::vector<std::string>& wasm_import_names() {
  static const std::vector<std::string> names = {
      "on_entry", "safepoint", "read8",    "read16",     "read32", "write8", "write16",     "write32", "exec",
      "call_indirect", "absolute_call", "resume", "hle_call", "hle_before", "trap",   "rfi",    "system_call", "tw"};
  return names;
}

const char* wasm_trap_text(std::uint32_t code) {
  switch (static_cast<WasmTrap>(code)) {
    case WasmTrap::InvalidInstruction: return "invalid instruction";
    case WasmTrap::UnconditionalTrap: return "unconditional trap";
    case WasmTrap::RanOffEnd: return "ran off the end of a function";
    case WasmTrap::JumpOutsideTable: return "jump outside its table";
    case WasmTrap::ExternalControl: return "external control instruction";
    case WasmTrap::BadEntry: return "bad entry";
  }
  return "trap";
}

bool emit_wasm(const ProgramCfg& p, const WasmEmitOptions& opt, WasmModule* out, std::string* error) {
  *out = WasmModule{};
  if (p.errors) {
    if (error) *error = "the CFG has errors";
    return false;
  }
  if (wasm_import_names().size() != kImports) {
    if (error) *error = "import table mismatch";
    return false;
  }
  Ctx ctx{p, opt, {}, {}, out};
  ctx.start_slot.assign(p.functions.size(), -1);
  std::vector<WFunc> funcs;
  u32 slot = 0;
  auto index_of = [&](std::size_t k) { return kFirstGuest + static_cast<u32>(k); };
  // Plan every wasm function first: direct calls need their indices.
  for (std::size_t fi = 0; fi < p.functions.size(); ++fi) {
    const FunctionCfg& f = p.functions[fi];
    bool multi = f.entries.size() > 1;
    const HleSpec* spec = find_spec(opt, f);
    if (spec && multi) spec = nullptr;  // as emit_cpp: not with secondary entries
    if (spec) out->hle_matched.push_back(spec->index);
    if (spec && !spec->before) {
      u32 orig = index_of(funcs.size());
      funcs.push_back({WKind::Orig, fi, f.start, static_cast<int>(slot++)});
      ctx.callable[f.start] = index_of(funcs.size());
      ctx.start_slot[fi] = static_cast<int>(slot);
      funcs.push_back({WKind::HleStub, fi, f.start, static_cast<int>(slot++), spec->index, false, orig});
      out->hle_sites.push_back({f.start, spec->index});
    } else if (multi) {
      u32 body = index_of(funcs.size());
      funcs.push_back({WKind::Body, fi});
      for (u32 e : f.entries) {
        ctx.callable[e] = index_of(funcs.size());
        if (e == f.start) ctx.start_slot[fi] = static_cast<int>(slot);
        funcs.push_back({WKind::Stub, fi, e, static_cast<int>(slot++), -1, false, body});
      }
    } else {
      ctx.callable[f.start] = index_of(funcs.size());
      ctx.start_slot[fi] = static_cast<int>(slot);
      funcs.push_back(
          {WKind::Plain, fi, f.start, static_cast<int>(slot++), spec ? spec->index : -1, spec && spec->before});
    }
  }
  out->slots = slot;

  // Bodies.
  Buf code;
  code.uleb(kHelperCount + funcs.size());
  auto put = [&](const Fn& fn) {
    code.uleb(fn.b.size());
    code.append(fn.b);
  };
  put(helper_read(1, iRead8));
  put(helper_read(2, iRead16));
  put(helper_read(4, iRead32));
  put(helper_write(1, iWrite8));
  put(helper_write(2, iWrite16));
  put(helper_write(4, iWrite32));
  put(helper_cmp(true));
  put(helper_cmp(false));
  put(helper_div(true));
  put(helper_div(false));
  struct BodyInfo {  // per Body: its entries' dispatcher indices, and whether it has resume labels
    std::vector<std::pair<u32, u32>> entry_seg;
    bool resume = false;
  };
  std::unordered_map<u32, BodyInfo> bodies;
  for (std::size_t k = 0; k < funcs.size(); ++k) {
    const WFunc& w = funcs[k];
    const FunctionCfg& f = p.functions[w.cfg];
    Fn fn;
    if (w.kind == WKind::Plain || w.kind == WKind::Body || w.kind == WKind::Orig) {
      FuncGen::Mode mode = w.kind == WKind::Plain  ? FuncGen::Mode::Plain
                           : w.kind == WKind::Body ? FuncGen::Mode::Body
                                                   : FuncGen::Mode::Orig;
      FuncGen g(ctx, w.cfg, mode, w.hook ? w.hle : -1);
      if (!g.run(fn, error)) return false;
      if (w.kind != WKind::Orig) {
        for (const auto& [a, seg] : g.resume()) {
          out->resume.push_back({a, static_cast<u32>(ctx.start_slot[w.cfg])});
          out->resume_index.push_back({a, seg});
        }
        ++out->stats.functions;
      }
      if (w.kind == WKind::Body) {
        BodyInfo info;
        info.resume = !g.resume().empty();
        for (u32 e : f.entries) info.entry_seg.push_back({e, g.entry_segment(e)});
        bodies[index_of(k)] = info;
      }
    } else if (w.kind == WKind::Stub) {
      const BodyInfo& info = bodies.at(w.target);
      fn.uleb(0);
      if (w.entry == f.start && info.resume) {
        fn.global(gResume);
        fn.mem(op::i32_load8_u, 0, 0);
        fn.if_();
        fn.get(0);
        fn.i32c(0);
        fn.call(w.target);
        fn.op(op::return_);
        fn.end();
      }
      emit_prologue(fn, w.entry, [&] { emit_leave(fn); });
      u32 seg = 0;
      for (const auto& [e, s] : info.entry_seg)
        if (e == w.entry) seg = s;
      fn.get(0);
      fn.i32c(seg);
      fn.call(w.target);
      fn.byte(op::end);
    } else {  // HleStub
      fn.uleb(0);
      emit_prologue(fn, w.entry, [&] { emit_leave(fn); });
      fn.get(0);
      fn.i32c(w.hle);
      fn.global(gTableBase);
      fn.i32c(funcs[w.target - kFirstGuest].slot);
      fn.op(op::i32_add);
      fn.call(iHleCall);
      fn.byte(op::end);
      ++out->stats.hle_stubs;
    }
    put(fn);
    if (w.slot >= 0 && w.kind != WKind::Orig) {
      out->entries.push_back({w.entry, static_cast<u32>(w.slot)});
      ++out->stats.entries;
    }
  }
  out->stats.wasm_functions = funcs.size();
  out->stats.code_bytes = code.b.size();

  // Safe points and idle spins, as the C++ emitter's table lists them.
  for (const auto& f : p.functions) {
    out->safe.insert(out->safe.end(), f.entries.begin(), f.entries.end());
    out->safe.insert(out->safe.end(), f.back_edges.begin(), f.back_edges.end());
    out->idle.insert(out->idle.end(), f.idle_spins.begin(), f.idle_spins.end());
  }
  std::sort(out->safe.begin(), out->safe.end());
  std::sort(out->idle.begin(), out->idle.end());

  // The module.
  Buf m;
  const u8 header[] = {0x00, 0x61, 0x73, 0x6D, 0x01, 0x00, 0x00, 0x00};  //  asm, version 1
  for (u8 c : header) m.byte(c);
  {
    Buf t;
    t.uleb(kTypes);
    functype(t, {kI32}, {});                          // tV_I
    functype(t, {kI32, kI32}, {});                    // tV_II
    functype(t, {kI32, kI32, kI32, kI64}, {kI32});    // tI_IIIL
    functype(t, {kI32, kI32, kI32, kI32, kI64}, {});  // tV_IIIIL
    functype(t, {kI32, kI32, kI32, kI64}, {});        // tV_IIIL
    functype(t, {kI32, kI32, kI32}, {kI32});          // tI_III
    functype(t, {kI32, kI32, kI32}, {});              // tV_III
    functype(t, {kI32, kI32}, {kI32});                // tI_II
    m.section(1, t);
  }
  {
    Buf im;
    const auto& names = wasm_import_names();
    im.uleb(kImports + 2 + kGlobals);
    for (u32 k = 0; k < kImports; ++k) {
      im.name("rt");
      im.name(names[k]);
      im.byte(0x00);
      im.uleb(kImportType[k]);
    }
    im.name("env");
    im.name("memory");
    im.byte(0x02);
    im.byte(0x00);
    im.uleb(1);
    im.name("env");
    im.name("table");
    im.byte(0x01);
    im.byte(kFuncRef);
    im.byte(0x00);
    im.uleb(1);
    for (const char* g : {"table_base", "unwinding", "resume", "entry_hook"}) {
      im.name("env");
      im.name(g);
      im.byte(0x03);
      im.byte(kI32);
      im.byte(0x00);
    }
    m.section(2, im);
  }
  {
    Buf fs;
    fs.uleb(kHelperCount + funcs.size());
    for (Ty t : kHelperType) fs.uleb(t);
    for (const WFunc& w : funcs) fs.uleb(w.kind == WKind::Body ? tV_II : tV_I);
    m.section(3, fs);
  }
  {
    Buf el;
    el.uleb(1);
    el.uleb(0);  // active, table 0, funcref
    el.byte(op::global_get);
    el.uleb(gTableBase);
    el.byte(op::end);
    std::vector<u32> by_slot(slot);
    for (std::size_t k = 0; k < funcs.size(); ++k)
      if (funcs[k].slot >= 0) by_slot[static_cast<std::size_t>(funcs[k].slot)] = index_of(k);
    el.uleb(by_slot.size());
    for (u32 fidx : by_slot) el.uleb(fidx);
    m.section(9, el);
  }
  m.section(10, code);
  out->bytes = std::move(m.b);
  return true;
}

}  // namespace mvp::xlat
