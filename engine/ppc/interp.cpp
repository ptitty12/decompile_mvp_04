#include "ppc/interp.h"

#include <cstdio>

#include "ppc/sem.h"

namespace mvp::ppc {

std::uint32_t g_gp_pages[kGpEntries] = {};  // P2: see mem_access.h
void (*g_gp_wait_hook)(u32 first, u32 last) = nullptr;

namespace {

[[noreturn]] void fault(Cpu& c, const char* what, u32 word) {
  char b[96];
  std::snprintf(b, sizeof b, "%s (word 0x%08X at 0x%08X)", what, word, c.pc);
  throw GuestFault(c.pc, b);
}

}  // namespace

void Hooks::safepoint(Cpu& c) { c.next_event = ~0ull; }
void Hooks::exception(Cpu& c, u32 vector) { sem::enter_exception(c, vector); }

u32 slow_read(Cpu& c, u32 ea, int size) {
  // Entirely inside one unmapped page: an I/O access.
  u32 off = ea & (Memory::kPageSize - 1);
  if (!c.mem->page[ea >> Memory::kPageShift] && off + static_cast<u32>(size) <= Memory::kPageSize) {
    if (!c.mem->io) fault_unmapped(c, ea, false, size);
    return c.mem->io->read(ea, size);
  }
  // Crossing into another region: byte by byte.
  u32 v = 0;
  for (int k = 0; k < size; ++k) v = (v << 8) | read8(c, ea + static_cast<u32>(k));
  return v;
}

void slow_write(Cpu& c, u32 ea, u32 v, int size) {
  u32 off = ea & (Memory::kPageSize - 1);
  if (!c.mem->page[ea >> Memory::kPageShift] && off + static_cast<u32>(size) <= Memory::kPageSize) {
    if (!c.mem->io) fault_unmapped(c, ea, true, size);
    c.mem->io->write(ea, v, size);
    return;
  }
  for (int k = 0; k < size; ++k) write8(c, ea + static_cast<u32>(k), v >> (8 * (size - 1 - k)));
}

void fault_unmapped(Cpu& c, u32 ea, bool write, int size) {
  char b[96];
  std::snprintf(b, sizeof b, "unmapped %d-byte %s at 0x%08X", size, write ? "write" : "read", ea);
  throw GuestFault(c.pc, b);
}

bool execute_plain(Cpu& c, Op op, Insn i) {
  switch (op) {
#define MVP_SEM(name) \
  case Op::name: sem::name(c, i); return true;
    MVP_SEM(add) MVP_SEM(addc) MVP_SEM(adde) MVP_SEM(addi) MVP_SEM(addic) MVP_SEM(addic_rc) MVP_SEM(addis)
    MVP_SEM(addme) MVP_SEM(addze) MVP_SEM(divw) MVP_SEM(divwu) MVP_SEM(mulhw) MVP_SEM(mulhwu) MVP_SEM(mulli)
    MVP_SEM(mullw) MVP_SEM(neg) MVP_SEM(subf) MVP_SEM(subfc) MVP_SEM(subfe) MVP_SEM(subfic) MVP_SEM(subfme)
    MVP_SEM(subfze)
    MVP_SEM(cmp) MVP_SEM(cmpi) MVP_SEM(cmpl) MVP_SEM(cmpli)
    MVP_SEM(and_) MVP_SEM(andc) MVP_SEM(andi_rc) MVP_SEM(andis_rc) MVP_SEM(cntlzw) MVP_SEM(eqv) MVP_SEM(extsb)
    MVP_SEM(extsh) MVP_SEM(nand) MVP_SEM(nor) MVP_SEM(or_) MVP_SEM(orc) MVP_SEM(ori) MVP_SEM(oris) MVP_SEM(xor_)
    MVP_SEM(xori) MVP_SEM(xoris)
    MVP_SEM(rlwimi) MVP_SEM(rlwinm) MVP_SEM(rlwnm) MVP_SEM(slw) MVP_SEM(sraw) MVP_SEM(srawi) MVP_SEM(srw)
    MVP_SEM(crand) MVP_SEM(crandc) MVP_SEM(creqv) MVP_SEM(crnand) MVP_SEM(crnor) MVP_SEM(cror) MVP_SEM(crorc)
    MVP_SEM(crxor) MVP_SEM(mcrf) MVP_SEM(mcrxr) MVP_SEM(mfcr) MVP_SEM(mtcrf)
    MVP_SEM(mfmsr) MVP_SEM(mtmsr) MVP_SEM(mfspr) MVP_SEM(mtspr) MVP_SEM(mftb) MVP_SEM(mfsr) MVP_SEM(mfsrin)
    MVP_SEM(mtsr) MVP_SEM(mtsrin)
    MVP_SEM(icbi) MVP_SEM(dcbz)
    MVP_SEM(lbz) MVP_SEM(lbzu) MVP_SEM(lbzux) MVP_SEM(lbzx) MVP_SEM(lha) MVP_SEM(lhau) MVP_SEM(lhaux) MVP_SEM(lhax)
    MVP_SEM(lhbrx) MVP_SEM(lhz) MVP_SEM(lhzu) MVP_SEM(lhzux) MVP_SEM(lhzx) MVP_SEM(lmw) MVP_SEM(lswi) MVP_SEM(lswx)
    MVP_SEM(lwarx) MVP_SEM(lwbrx) MVP_SEM(lwz) MVP_SEM(lwzu) MVP_SEM(lwzux) MVP_SEM(lwzx)
    MVP_SEM(stb) MVP_SEM(stbu) MVP_SEM(stbux) MVP_SEM(stbx) MVP_SEM(sth) MVP_SEM(sthbrx) MVP_SEM(sthu)
    MVP_SEM(sthux) MVP_SEM(sthx) MVP_SEM(stmw) MVP_SEM(stswi) MVP_SEM(stswx) MVP_SEM(stw) MVP_SEM(stwbrx)
    MVP_SEM(stwcx_rc) MVP_SEM(stwu) MVP_SEM(stwux) MVP_SEM(stwx)
    MVP_SEM(lfd) MVP_SEM(lfdu) MVP_SEM(lfdux) MVP_SEM(lfdx) MVP_SEM(lfs) MVP_SEM(lfsu) MVP_SEM(lfsux) MVP_SEM(lfsx)
    MVP_SEM(stfd) MVP_SEM(stfdu) MVP_SEM(stfdux) MVP_SEM(stfdx) MVP_SEM(stfiwx) MVP_SEM(stfs) MVP_SEM(stfsu)
    MVP_SEM(stfsux) MVP_SEM(stfsx)
    MVP_SEM(fabs) MVP_SEM(fadd) MVP_SEM(fadds) MVP_SEM(fcmpo) MVP_SEM(fcmpu) MVP_SEM(fctiw) MVP_SEM(fctiwz)
    MVP_SEM(fdiv) MVP_SEM(fdivs) MVP_SEM(fmadd) MVP_SEM(fmadds) MVP_SEM(fmr) MVP_SEM(fmsub) MVP_SEM(fmsubs)
    MVP_SEM(fmul) MVP_SEM(fmuls) MVP_SEM(fnabs) MVP_SEM(fneg) MVP_SEM(fnmadd) MVP_SEM(fnmadds) MVP_SEM(fnmsub)
    MVP_SEM(fnmsubs) MVP_SEM(fres) MVP_SEM(frsp) MVP_SEM(frsqrte) MVP_SEM(fsel) MVP_SEM(fsub) MVP_SEM(fsubs)
    MVP_SEM(mcrfs) MVP_SEM(mffs) MVP_SEM(mtfsb0) MVP_SEM(mtfsb1) MVP_SEM(mtfsf) MVP_SEM(mtfsfi)
    MVP_SEM(psq_l) MVP_SEM(psq_lu) MVP_SEM(psq_lux) MVP_SEM(psq_lx) MVP_SEM(psq_st) MVP_SEM(psq_stu)
    MVP_SEM(psq_stux) MVP_SEM(psq_stx)
    MVP_SEM(ps_abs) MVP_SEM(ps_add) MVP_SEM(ps_cmpo0) MVP_SEM(ps_cmpo1) MVP_SEM(ps_cmpu0) MVP_SEM(ps_cmpu1)
    MVP_SEM(ps_div) MVP_SEM(ps_madd) MVP_SEM(ps_madds0) MVP_SEM(ps_madds1) MVP_SEM(ps_merge00)
    MVP_SEM(ps_merge01) MVP_SEM(ps_merge10) MVP_SEM(ps_merge11) MVP_SEM(ps_mr) MVP_SEM(ps_msub) MVP_SEM(ps_mul)
    MVP_SEM(ps_muls0) MVP_SEM(ps_muls1) MVP_SEM(ps_nabs) MVP_SEM(ps_neg) MVP_SEM(ps_nmadd) MVP_SEM(ps_nmsub)
    MVP_SEM(ps_res) MVP_SEM(ps_rsqrte) MVP_SEM(ps_sel) MVP_SEM(ps_sub) MVP_SEM(ps_sum0) MVP_SEM(ps_sum1)
#undef MVP_SEM
    // No architectural effect in this machine model.
    case Op::dcbf: case Op::dcbi: case Op::dcbst: case Op::dcbt: case Op::dcbtst: case Op::eieio: case Op::isync:
    case Op::sync: case Op::tlbie: case Op::tlbsync:
      return true;
    case Op::dcbz_l:
      sem::dcbz(c, i);
      return true;
    default:
      return false;
  }
}

Op execute(Cpu& c, u32 w) {
  Insn i{w};
  Op op = decode(w);
  // An FPU instruction with MSR[FP] clear does not start: floating-point
  // unavailable (isa.h, uses_fpu). The hooks take the exception; the instruction
  // runs when the handler returns to it.
  if (uses_fpu(op) && !(c.msr & msr::FP)) {
    c.hooks->exception(c, 0x800);
    return op;
  }
  ++c.ticks;  // counts instructions started, as translated code does
  if (execute_plain(c, op, i)) {
    c.pc += 4;
    return op;
  }
  u32 next = c.pc + 4;
  switch (op) {
    case Op::b: {
      u32 target = i.aa() ? static_cast<u32>(i.li()) : c.pc + static_cast<u32>(i.li());
      if (i.lk()) c.lr = next;
      c.pc = target;
      return op;
    }
    case Op::bc: {
      bool taken = sem::branch_cond(c, i);
      u32 target = i.aa() ? static_cast<u32>(i.bd()) : c.pc + static_cast<u32>(i.bd());
      if (i.lk()) c.lr = next;
      c.pc = taken ? target : next;
      return op;
    }
    case Op::bclr: {
      u32 target = c.lr & ~3u;
      bool taken = sem::branch_cond(c, i);
      if (i.lk()) c.lr = next;
      c.pc = taken ? target : next;
      return op;
    }
    case Op::bcctr: {
      if (!(i.bo() & 4)) fault(c, "bcctr that decrements CTR (invalid form)", w);
      bool taken = sem::branch_cond(c, i);
      u32 target = c.ctr & ~3u;
      if (i.lk()) c.lr = next;
      c.pc = taken ? target : next;
      return op;
    }
    case Op::sc:
      c.pc = next;
      c.hooks->system_call(c);
      return op;
    case Op::rfi:
      sem::rfi(c);
      return op;
    case Op::tw:
      if (sem::tw_taken(c, i)) fault(c, "guest trap (tw)", w);
      c.pc = next;
      return op;
    case Op::twi:
      if (sem::twi_taken(c, i)) fault(c, "guest trap (twi)", w);
      c.pc = next;
      return op;
    case Op::eciwx:
    case Op::ecowx:
      fault(c, "external control instructions are not supported", w);
    default:
      fault(c, "invalid instruction", w);
  }
}

Op step(Cpu& c) {
  if (c.pc & 3) fault(c, "misaligned PC", 0);
  return execute(c, read32(c, c.pc));
}

}  // namespace mvp::ppc
