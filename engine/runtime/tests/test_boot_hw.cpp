// Data-free tests for the boot environment and the hardware models: a synthetic
// disc for the low-memory layout; EXI (RTC, SRAM over imm and DMA), the DSP init
// handshake and the ARAM DMA driven through their registers as the SDK does.
#include <doctest/doctest.h>

#include <cstring>
#include <memory>

#include "common/bytes.h"
#include "runtime/boot.h"
#include "runtime/hw.h"
#include "runtime/sys_hooks.h"

using namespace mvp;
using namespace mvp::rt;

namespace {

// A minimal disc: header, BI2, a one-file FST, a one-section DOL.
std::unique_ptr<vfs::Source> synthetic_disc() {
  std::vector<u8> d(0x8000, 0);
  std::memcpy(&d[0], "GTST01", 6);
  put_be32(&d[0x1C], vfs::Gcm::kDiscMagic);
  for (u32 k = 0; k < 0x2000; ++k) d[0x440 + k] = static_cast<u8>(k);  // recognizable BI2
  // FST at 0x2440: root + one file "f" at 0x5000, 4 bytes.
  u32 fst = 0x2440;
  d[fst] = 1;
  put_be32(&d[fst + 8], 2);
  put_be32(&d[fst + 12], 0);
  put_be32(&d[fst + 16], 0x5000);
  put_be32(&d[fst + 20], 4);
  d[fst + 24] = 'f';
  put_be32(&d[0x424], fst);
  put_be32(&d[0x428], 26);
  put_be32(&d[0x42C], 64);
  // DOL at 0x6000: text at 0x80003100, 4 bytes (blr).
  u32 dol = 0x6000;
  put_be32(&d[0x420], dol);
  put_be32(&d[dol + 0], 0x100);
  put_be32(&d[dol + 0x48], 0x80003100);
  put_be32(&d[dol + 0x90], 4);
  put_be32(&d[dol + 0xE0], 0x80003100);
  put_be32(&d[dol + 0x100], 0x4E800020);
  return std::make_unique<vfs::MemorySource>(std::move(d));
}

u32 m32(Machine& m, u32 a) { return be32(m.mem1() + (a & 0x01FFFFFF)); }

}  // namespace

TEST_CASE("boot environment: low memory, FST and BI2 copies, CPU state") {
  std::string err;
  auto disc = vfs::open_disc(synthetic_disc(), false, &err);
  REQUIRE_MESSAGE(disc, err);
  Machine m;
  m.load_dol(disc->dol);
  BootLayout L = setup_boot_environment(m, *disc);
  CHECK(std::memcmp(m.mem1(), "GTST01", 6) == 0);
  CHECK(m32(m, 0x8000001C) == vfs::Gcm::kDiscMagic);
  CHECK(m32(m, 0x80000020) == 0x0D15EA5E);
  CHECK(m32(m, 0x80000028) == 0x01800000);
  CHECK(m32(m, 0x8000002C) == 3);
  CHECK(m32(m, 0x80000034) == L.arena_hi);
  CHECK(m32(m, 0x80000038) == L.fst);
  CHECK(m32(m, 0x8000003C) == 64);
  CHECK(m32(m, 0x800000F4) == L.bi2);
  CHECK(m32(m, 0x800000F8) == 162000000);
  CHECK(m32(m, 0x800000FC) == 486000000);
  CHECK(L.fst == 0x817FFFC0);  // 64-byte FST maximum, at the top of MEM1
  CHECK(L.bi2 == L.fst - 0x2000);
  CHECK(m.mem1()[(L.fst & 0x01FFFFFF) + 24] == 'f');
  CHECK(m.mem1()[(L.bi2 & 0x01FFFFFF) + 0x13] == 0x13);
  CHECK(m.cpu().pc == 0x80003100);
  CHECK((m.cpu().msr & (ppc::msr::IR | ppc::msr::DR)) == (ppc::msr::IR | ppc::msr::DR));
  CHECK(m.cpu().spr[536] == 0x80001FFF);
}

TEST_CASE("real mode maps MEM1 at 0, and the icbi check guards the DOL's code") {
  std::string err;
  auto disc = vfs::open_disc(synthetic_disc(), false, &err);
  REQUIRE(disc);
  Machine m;
  m.load_dol(disc->dol);
  SystemHooks h(&m);
  m.cpu().hooks = &h;
  CHECK(m.memory().host(0x00003100) == nullptr);
  u32 old = m.cpu().msr = ppc::msr::IR | ppc::msr::DR;
  m.cpu().msr = 0;
  h.msr_changed(m.cpu(), old);
  REQUIRE(m.memory().host(0x00003100) != nullptr);
  CHECK(be32(m.memory().host(0x00003100)) == 0x4E800020);
  m.cpu().msr = ppc::msr::IR | ppc::msr::DR;
  h.msr_changed(m.cpu(), 0);
  CHECK(m.memory().host(0x00003100) == nullptr);
  h.icbi(m.cpu(), 0x80003100);  // unchanged: fine
  m.mem1()[0x3100] ^= 1;
  CHECK_THROWS_AS(h.icbi(m.cpu(), 0x80003104), ppc::GuestFault);
  h.icbi(m.cpu(), 0x80000100);  // outside the DOL's code: not checked
}

namespace {

struct Rig {
  std::vector<u8> mem = std::vector<u8>(0x01800000 + 64, 0);
  ppc::Cpu cpu;
  Hardware hw{&cpu, mem.data(), 0x01800000};
  void w(u32 a, u32 v, int size = 4) { hw.write(a, v, size); }
  u32 r(u32 a, int size = 4) { return hw.read(a, size); }
  // EXI channel 0 transfer as EXIImm/EXIDma do it: select device 1, start, wait.
  void exi_select(u32 dev) { w(0xCC006800, (1u << (7 + dev)) | (3u << 4)); }
  void exi_deselect() { w(0xCC006800, 0); }
  void exi_imm(u32 data, u32 len, u32 rw) {
    w(0xCC006810, data);
    w(0xCC00680C, ((len - 1) << 4) | (rw << 2) | 1);
  }
};

}  // namespace

TEST_CASE("EXI: the IPL chip's SRAM and RTC") {
  Rig g;
  // RTC read.
  g.exi_select(1);
  g.exi_imm(0x20000000, 4, 1);
  CHECK((g.r(0xCC00680C) & 1) == 0);  // transfer complete
  CHECK((g.r(0xCC006800) & 0x8) != 0);  // TCINT
  g.exi_imm(0, 4, 0);
  CHECK(g.r(0xCC006810) == HardwareConfig{}.rtc_seconds);
  g.exi_deselect();
  // SRAM read by DMA into MEM1 0x1000.
  g.exi_select(1);
  g.exi_imm(0x20000100, 4, 1);
  g.w(0xCC006804, 0x00001000);
  g.w(0xCC006808, 64);
  g.w(0xCC00680C, 2 | 1);  // DMA read
  g.exi_deselect();
  CHECK(std::memcmp(&g.mem[0x1000], g.hw.sram().data(), 64) == 0);
  // The checksums cover counterBias..flags.
  u16 sum = 0, inv = 0;
  for (u32 k = 0x0C; k < 0x14; k += 2) {
    u16 v = static_cast<u16>(be16(&g.mem[0x1000 + k]));
    sum = static_cast<u16>(sum + v);
    inv = static_cast<u16>(inv + static_cast<u16>(~v));
  }
  CHECK(be16(&g.mem[0x1000]) == sum);
  CHECK(be16(&g.mem[0x1002]) == inv);
  CHECK(g.mem[0x1013] == 0x2C);
  // SRAM write of one byte at offset 0x12 (language), as WriteSram encodes offsets.
  g.exi_select(1);
  g.exi_imm(0xA0000100 | (0x12 << 6), 4, 1);
  g.exi_imm(0x05000000, 1, 1);
  g.exi_deselect();
  CHECK(g.hw.sram()[0x12] == 5);
  // Another device on channel 0 (the memory card slot) is absent: reads are 0.
  g.exi_select(0);
  g.exi_imm(0, 4, 1);
  g.exi_imm(0, 4, 0);
  CHECK(g.r(0xCC006810) == 0);
  CHECK((g.r(0xCC006800) & 0x1000) == 0);  // EXT: no card
  // TCINT is write-one-to-clear.
  g.w(0xCC006800, 0x8);
  CHECK((g.r(0xCC006800) & 0x8) == 0);
}

TEST_CASE("DSP: the init handshake of __OSInitAudioSystem and the ARAM DMA") {
  Rig g;
  for (u32 k = 0; k < 0x20; ++k) g.mem[0x01000000 + k] = static_cast<u8>(0xA0 + k);
  g.w(0xCC00500A, 0x8AC, 2);
  g.w(0xCC00500A, 0x8AD, 2);  // reset
  CHECK((g.r(0xCC00500A, 2) & 1) == 0);
  CHECK((g.r(0xCC005004, 2) & 0x8000) == 0);  // no mail yet
  g.w(0xCC005020, 0x01000000);                 // ARAM DMA: MEM1 0x01000000 -> ARAM 0, 0x20 bytes
  g.w(0xCC005024, 0);
  g.w(0xCC005028, 0x20);
  u16 cr = static_cast<u16>(g.r(0xCC00500A, 2));
  CHECK((cr & 0x20) != 0);  // ARINT
  g.w(0xCC00500A, cr, 2);  // acknowledge
  CHECK((g.r(0xCC00500A, 2) & 0x20) == 0);
  // DMA back from ARAM to MEM1 0x2000.
  g.w(0xCC005020, 0x2000);
  g.w(0xCC005024, 0);
  g.w(0xCC005028, 0x80000020u);
  CHECK(g.mem[0x2000] == 0xA0);
  CHECK(g.mem[0x201F] == 0xBF);
  // Unhalt: the init microcode's mail arrives.
  u16 c2 = static_cast<u16>(g.r(0xCC00500A, 2) & ~0x800 & ~0x4);
  g.w(0xCC00500A, c2, 2);
  u32 hi = g.r(0xCC005004, 2), lo = g.r(0xCC005006, 2);
  CHECK(((hi << 16) | lo) == 0x80544348u);
  CHECK((g.r(0xCC005004, 2) & 0x8000) == 0);  // taken
}

TEST_CASE("hardware log, write-gather pipe and the poll limit") {
  Rig g;
  // The write-gather pipe passes data on in 32-byte bursts.
  g.w(0xCC008000, 0x61, 1);
  g.w(0xCC008000, 0x12345678);
  CHECK(g.hw.fifo().empty());
  for (int k = 0; k < 6; ++k) g.w(0xCC008000, 0);
  for (int k = 0; k < 3; ++k) g.w(0xCC008000, 0, 1);
  REQUIRE(g.hw.fifo().size() == 32);
  CHECK(std::vector<u8>(g.hw.fifo().begin(), g.hw.fifo().begin() + 5) == std::vector<u8>{0x61, 0x12, 0x34, 0x56, 0x78});
  CHECK(g.hw.gx().bp_loads() == 1);
  g.w(0xCC003004, 0xF0);
  CHECK(g.r(0xCC003004) == 0xF0);
  CHECK(g.r(0xCC003006, 2) == 0xF0);
  g.hw.poll_limit = 10;
  for (int k = 0; k < 9; ++k) g.r(0xCC002000, 2);
  CHECK_THROWS_AS(g.r(0xCC002000, 2), StopRun);
  CHECK_THROWS_AS(g.r(0xCD000000), StopRun);
  CHECK(g.hw.log().size() > 10);
}
