#include "runtime/hw.h"

#include <cstdio>
#include <cstring>

#include "common/bytes.h"

namespace mvp::rt {

namespace {

constexpr u32 kExiBase = 0xCC006800u, kExiStride = 0x14u;
constexpr u32 kDspBase = 0xCC005000u;

// EXI CSR bits.
constexpr u32 kExiIntW1C = 0x2 | 0x8 | 0x800;  // EXIINT, TCINT, EXTINT
constexpr u32 kExiTcint = 0x8;
// DSP control register bits.
constexpr u16 kDspRes = 0x0001, kDspHalt = 0x0004, kDspAidint = 0x0008, kDspArint = 0x0020, kDspDspint = 0x0080;
constexpr u16 kDspW1C = kDspAidint | kDspArint | kDspDspint;

}  // namespace

Hardware::Hardware(ppc::Cpu* cpu, u8* mem1, u32 mem1_size, const HardwareConfig& cfg)
    : cpu_(cpu), mem1_(mem1), mem1_size_(mem1_size), cfg_(cfg), aram_(0x01000000, 0) {
  rtc_ = cfg.rtc_seconds;
  // A valid SRAM image: OSSram (0x14 bytes) then OSSramEx. Checksums cover the
  // 16-bit words from counterBias (offset 0x0C) to the end of OSSram.
  sram_.fill(0);
  sram_[0x11] = 0;  // ntd: NTSC
  sram_[0x12] = cfg.sram_language;
  sram_[0x13] = cfg.sram_flags;
  u16 sum = 0, inv = 0;
  for (u32 k = 0x0C; k < 0x14; k += 2) {
    u16 w = static_cast<u16>(be16(&sram_[k]));
    sum = static_cast<u16>(sum + w);
    inv = static_cast<u16>(inv + static_cast<u16>(~w));
  }
  put_be16(&sram_[0], sum);
  put_be16(&sram_[2], inv);
}

const char* Hardware::block_name(u32 a) {
  if (a >= 0xCC000000u && a < 0xCC001000u) return "CP";
  if (a >= 0xCC001000u && a < 0xCC002000u) return "PE";
  if (a >= 0xCC002000u && a < 0xCC003000u) return "VI";
  if (a >= 0xCC003000u && a < 0xCC004000u) return "PI";
  if (a >= 0xCC004000u && a < 0xCC005000u) return "MI";
  if (a >= 0xCC005000u && a < 0xCC006000u) return "DSP";
  if (a >= 0xCC006000u && a < 0xCC006400u) return "DI";
  if (a >= 0xCC006400u && a < 0xCC006800u) return "SI";
  if (a >= 0xCC006800u && a < 0xCC006C00u) return "EXI";
  if (a >= 0xCC006C00u && a < 0xCC007000u) return "AI";
  if (a >= 0xCC008000u && a < 0xCC009000u) return "WGP";
  return nullptr;
}

u32 Hardware::reg(u32 addr) const {
  auto it = regs_.find(addr & ~3u);
  return it == regs_.end() ? 0 : it->second;
}

void Hardware::set_reg(u32 addr, u32 value, int size) {
  u32 a = addr & ~3u;
  u32 old = reg(a);
  u32 sh = (4 - (addr & 3) - static_cast<u32>(size)) * 8;
  u32 mask = size == 4 ? 0xFFFFFFFFu : ((1u << (8 * size)) - 1) << sh;
  regs_[a] = (old & ~mask) | ((value << sh) & mask);
}

// ---- EXI ----

int Hardware::exi_device(int ch) const {
  u32 cs = (exi_[ch].csr >> 7) & 7;
  if (cs & 1) return 0;
  if (cs & 2) return 1;
  if (cs & 4) return 2;
  return -1;
}

u8 Hardware::ipl_read_byte(ExiChannel& e) {
  u32 a = e.cmd & 0x7FFFFFFFu;
  u8 b = 0;
  if (a >= 0x20000100u && a < 0x20001100u) {  // SRAM: offset = (a - 0x100) >> 6, then sequential
    u32 off = ((a - 0x20000100u) >> 6) + e.offset;
    b = off < sram_.size() ? sram_[off] : 0;
  } else if (a >= 0x20000000u && a < 0x20000100u) {  // RTC counter, big-endian
    u32 off = e.offset;
    b = off < 4 ? static_cast<u8>(rtc_ >> (24 - 8 * off)) : 0;
  }  // IPL ROM (fonts) and the UART are not provided: zeros.
  ++e.offset;
  return b;
}

void Hardware::ipl_write_byte(ExiChannel& e, u8 b) {
  if (!e.have_cmd) {
    e.cmd = (e.cmd << 8) | b;
    if (++e.cmd_bytes == 4) {
      e.have_cmd = true;
      e.offset = 0;
    }
    return;
  }
  u32 a = e.cmd & 0x7FFFFFFFu;
  if (!(e.cmd & 0x80000000u)) return;  // data written during a read command
  if (a >= 0x20000100u && a < 0x20001100u) {
    u32 off = ((a - 0x20000100u) >> 6) + e.offset;
    if (off < sram_.size()) sram_[off] = b;
  } else if (a >= 0x20000000u && a < 0x20000100u) {
    if (e.offset < 4) rtc_ = (rtc_ & ~(0xFFu << (24 - 8 * e.offset))) | (u32(b) << (24 - 8 * e.offset));
  }
  ++e.offset;
}

void Hardware::exi_transfer(int ch) {
  ExiChannel& e = exi_[ch];
  int dev = exi_device(ch);
  bool ipl = ch == 0 && dev == 1;
  u32 rw = (e.cr >> 2) & 3;  // 0 read, 1 write, 2 read-write
  if (e.cr & 2) {  // DMA
    u32 pa = e.mar & 0x01FFFFE0u;
    for (u32 k = 0; k < e.len && pa + k < mem1_size_; ++k) {
      if (rw == 0) mem1_[pa + k] = ipl ? ipl_read_byte(e) : 0;
      else if (ipl) ipl_write_byte(e, mem1_[pa + k]);
    }
  } else {  // immediate: TLEN+1 bytes, most significant first
    u32 n = ((e.cr >> 4) & 3) + 1;
    if (rw == 1 || rw == 2) {
      for (u32 k = 0; k < n; ++k)
        if (ipl) ipl_write_byte(e, static_cast<u8>(e.data >> (24 - 8 * k)));
    }
    if (rw == 0 || rw == 2) {
      u32 d = 0;
      for (u32 k = 0; k < n; ++k) d |= u32(ipl ? ipl_read_byte(e) : 0) << (24 - 8 * k);
      e.data = d;
    }
  }
  e.cr &= ~1u;      // TSTART clears: the transfer is complete
  e.csr |= kExiTcint;
}

void Hardware::exi_write(int ch, u32 r, u32 v) {
  ExiChannel& e = exi_[ch];
  switch (r) {
    case 0x00: {
      u32 old_dev = (e.csr >> 7) & 7;
      e.csr = (e.csr & kExiIntW1C & ~v) | (v & ~kExiIntW1C & ~0x1000u);  // EXT is read-only (no card)
      if (((e.csr >> 7) & 7) != old_dev) {  // chip select changed: a new command starts
        e.have_cmd = false;
        e.cmd = 0;
        e.cmd_bytes = 0;
        e.offset = 0;
      }
      break;
    }
    case 0x04: e.mar = v; break;
    case 0x08: e.len = v; break;
    case 0x0C:
      e.cr = v;
      if (v & 1) exi_transfer(ch);
      break;
    case 0x10: e.data = v; break;
  }
}

// ---- DSP and ARAM ----

void Hardware::dsp_aram_dma() {
  u32 mm = ar_mm_ & 0x01FFFFE0u, ar = ar_ar_ & 0x00FFFFE0u, n = ar_cnt_ & 0x7FFFFFE0u;
  bool to_mem = (ar_cnt_ & 0x80000000u) != 0;
  for (u32 k = 0; k < n; ++k) {
    if (mm + k >= mem1_size_ || ar + k >= aram_.size()) break;
    if (to_mem) mem1_[mm + k] = aram_[ar + k];
    else aram_[ar + k] = mem1_[mm + k];
  }
  ar_cnt_ &= 0x80000000u;
  dsp_cr_ |= kDspArint;  // DMA complete
}

u16 Hardware::dsp_read16(u32 off) {
  switch (off) {
    case 0x00: return static_cast<u16>(dsp_mail_to_dsp_ >> 16);
    case 0x02: return static_cast<u16>(dsp_mail_to_dsp_);
    case 0x04: return static_cast<u16>(dsp_mail_to_cpu_ >> 16);
    case 0x06: {  // reading the low half takes the mail
      u16 lo = static_cast<u16>(dsp_mail_to_cpu_);
      dsp_mail_to_cpu_ &= 0x7FFFFFFFu;
      return lo;
    }
    case 0x0A: return dsp_cr_;
    case 0x20: return static_cast<u16>(ar_mm_ >> 16);
    case 0x22: return static_cast<u16>(ar_mm_);
    case 0x24: return static_cast<u16>(ar_ar_ >> 16);
    case 0x26: return static_cast<u16>(ar_ar_);
    case 0x28: return static_cast<u16>(ar_cnt_ >> 16);
    case 0x2A: return static_cast<u16>(ar_cnt_);
    default: {
      u32 w = reg(kDspBase + (off & ~3u));
      return static_cast<u16>((off & 2) ? w : w >> 16);
    }
  }
}

void Hardware::dsp_write16(u32 off, u16 v) {
  switch (off) {
    case 0x00: dsp_mail_to_dsp_ = (dsp_mail_to_dsp_ & 0xFFFFu) | (u32(v) << 16); return;
    case 0x02: dsp_mail_to_dsp_ = (dsp_mail_to_dsp_ & 0xFFFF0000u) | v; return;
    case 0x0A: {
      u16 old = dsp_cr_;
      dsp_cr_ = static_cast<u16>((dsp_cr_ & kDspW1C & ~v) | (v & ~kDspW1C & ~kDspRes));
      if (v & kDspRes) {  // reset completes at once; the DSP is halted and rebooting
        dsp_booting_ = true;
        dsp_mail_to_cpu_ = 0;
      }
      if ((old & kDspHalt) && !(dsp_cr_ & kDspHalt) && dsp_booting_) {
        // The IPL's DSP init microcode (uploaded by __OSInitAudioSystem) answers with
        // this mail when it starts.
        dsp_mail_to_cpu_ = 0x80544348u;
        dsp_booting_ = false;
      }
      return;
    }
    case 0x20: ar_mm_ = (ar_mm_ & 0xFFFFu) | (u32(v) << 16); return;
    case 0x22: ar_mm_ = (ar_mm_ & 0xFFFF0000u) | v; return;
    case 0x24: ar_ar_ = (ar_ar_ & 0xFFFFu) | (u32(v) << 16); return;
    case 0x26: ar_ar_ = (ar_ar_ & 0xFFFF0000u) | v; return;
    case 0x28: ar_cnt_ = (ar_cnt_ & 0xFFFFu) | (u32(v) << 16); return;
    case 0x2A:
      ar_cnt_ = (ar_cnt_ & 0xFFFF0000u) | v;
      dsp_aram_dma();
      return;
    default: set_reg(kDspBase + off, v, 2); return;
  }
}

// ---- dispatch ----

u32 Hardware::read(u32 addr, int size) {
  if (!block_name(addr)) {
    char b[96];
    std::snprintf(b, sizeof b, "read of %d bytes at 0x%08X, outside the hardware blocks", size, addr);
    throw StopRun{b};
  }
  ++reads_[addr];
  if (addr == last_read_) {
    if (++same_reads_ >= poll_limit) {
      char b[112];
      std::snprintf(b, sizeof b, "%s register 0x%08X polled %llu times in a row (from 0x%08X)", block_name(addr), addr,
                    static_cast<unsigned long long>(same_reads_), cpu_->pc);
      throw StopRun{b};
    }
  } else {
    last_read_ = addr;
    same_reads_ = 1;
  }
  u32 v;
  if (addr >= kDspBase && addr < kDspBase + 0x1000u) {
    u32 off = addr - kDspBase;
    if (size == 4) v = (u32(dsp_read16(off)) << 16) | dsp_read16(off + 2);
    else if (size == 2) v = dsp_read16(off);
    else v = static_cast<u8>(dsp_read16(off & ~1u) >> ((off & 1) ? 0 : 8));
  } else {
    u32 word;
    if (addr >= kExiBase && addr < kExiBase + 3 * kExiStride) {
      int ch = static_cast<int>((addr - kExiBase) / kExiStride);
      u32 r = (addr - kExiBase) % kExiStride & ~3u;
      const ExiChannel& e = exi_[ch];
      word = r == 0 ? e.csr : r == 4 ? e.mar : r == 8 ? e.len : r == 12 ? e.cr : e.data;
    } else {
      word = reg(addr);
    }
    u32 sh = (4 - (addr & 3) - static_cast<u32>(size)) * 8;
    v = size == 4 ? word : (word >> sh) & ((1u << (8 * size)) - 1);
  }
  if (log_.size() < 100000) log_.push_back({cpu_->pc, addr, v, size, false});
  return v;
}

void Hardware::write(u32 addr, u32 value, int size) {
  if (!block_name(addr)) {
    char b[96];
    std::snprintf(b, sizeof b, "write of %d bytes at 0x%08X, outside the hardware blocks", size, addr);
    throw StopRun{b};
  }
  ++writes_[addr];
  last_read_ = 0;
  if (log_.size() < 100000) log_.push_back({cpu_->pc, addr, value, size, true});
  if (addr >= 0xCC008000u && addr < 0xCC009000u) {  // write-gather pipe: the GX FIFO
    for (int k = size - 1; k >= 0; --k) fifo_.push_back(static_cast<u8>(value >> (8 * k)));
    return;
  }
  if (addr >= kDspBase && addr < kDspBase + 0x1000u) {
    u32 off = addr - kDspBase;
    if (size == 4) {
      dsp_write16(off, static_cast<u16>(value >> 16));
      dsp_write16(off + 2, static_cast<u16>(value));
    } else if (size == 2) {
      dsp_write16(off, static_cast<u16>(value));
    } else {
      set_reg(addr, value, size);
    }
    return;
  }
  if (addr >= kExiBase && addr < kExiBase + 3 * kExiStride && size == 4 && !(addr & 3)) {
    int ch = static_cast<int>((addr - kExiBase) / kExiStride);
    exi_write(ch, (addr - kExiBase) % kExiStride, value);
    return;
  }
  set_reg(addr, value, size);
}

}  // namespace mvp::rt
