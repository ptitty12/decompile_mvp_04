// Memory-mapped hardware (E0b items 7 and 10): the Flipper register blocks at
// 0xCC000000. Registers without a model store what the guest writes and read it
// back; the models below answer what the boot polls:
// - EXI: immediate and DMA transfers complete at once; channel 0 device 1 is the
//   IPL chip's RTC and SRAM (fixed values, R12); every other device is absent;
// - DSP: reset and halt bits, the ARAM DMA (with 16 MiB of ARAM), and the mailbox
//   answer of the IPL's DSP init microcode;
// - the write-gather pipe (0xCC008000) is captured to a buffer (the GX stream).
// Every access is logged (capped) and counted.
#pragma once

#include <array>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "ppc/cpu.h"

namespace mvp::rt {

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;

struct MmioAccess {
  u32 pc, addr, value;
  int size;
  bool write;
};

struct HardwareConfig {
  u32 rtc_seconds = 0x0D6C5A00;  // RTC counter (seconds since 2000-01-01): a fixed date, R12
  u8 sram_language = 0;          // English
  u8 sram_flags = 0x2C;          // sound mode and boot flags as a fresh console's SRAM; not progressive
};

class Hardware : public ppc::Io {
 public:
  Hardware(ppc::Cpu* cpu, u8* mem1, u32 mem1_size, const HardwareConfig& cfg = {});

  u32 read(u32 addr, int size) override;
  void write(u32 addr, u32 value, int size) override;

  const std::vector<MmioAccess>& log() const { return log_; }
  const std::map<u32, std::uint64_t>& read_counts() const { return reads_; }
  const std::map<u32, std::uint64_t>& write_counts() const { return writes_; }
  const std::vector<u8>& fifo() const { return fifo_; }  // bytes written to the write-gather pipe
  const std::array<u8, 64>& sram() const { return sram_; }

  // A read of one register this many times in a row stops the run (a poll that
  // the device model does not answer).
  std::uint64_t poll_limit = 1000000;

  static const char* block_name(u32 addr);

 private:
  u32 reg(u32 addr) const;
  void set_reg(u32 addr, u32 value, int size);
  u32 read_word(u32 a);               // 4-byte-aligned register read, with device behaviour
  void write_reg(u32 addr, u32 value, int size);

  // EXI
  struct ExiChannel {
    u32 csr = 0, mar = 0, len = 0, cr = 0, data = 0;
    // The selected device's transfer state (IPL chip on channel 0 device 1).
    bool have_cmd = false;
    u32 cmd = 0, cmd_bytes = 0, offset = 0;
  };
  void exi_write(int ch, u32 reg, u32 v);
  void exi_transfer(int ch);
  int exi_device(int ch) const;  // selected device index, or -1
  u8 ipl_read_byte(ExiChannel& e);
  void ipl_write_byte(ExiChannel& e, u8 b);

  // DSP
  void dsp_write16(u32 off, u16 v);
  u16 dsp_read16(u32 off);
  void dsp_aram_dma();

  ppc::Cpu* cpu_;
  u8* mem1_;
  u32 mem1_size_;
  HardwareConfig cfg_;
  std::map<u32, u32> regs_;
  std::vector<MmioAccess> log_;
  std::map<u32, std::uint64_t> reads_, writes_;
  std::vector<u8> fifo_;
  u32 last_read_ = 0;
  std::uint64_t same_reads_ = 0;

  ExiChannel exi_[3];
  std::array<u8, 64> sram_{};
  u32 rtc_ = 0;

  u16 dsp_cr_ = 0;
  u32 dsp_mail_to_cpu_ = 0;  // bit 31 = valid
  u32 dsp_mail_to_dsp_ = 0;
  u32 ar_mm_ = 0, ar_ar_ = 0, ar_cnt_ = 0;
  bool dsp_booting_ = false;  // reset and halted since the last reset: the IPL init ucode runs on unhalt
  std::vector<u8> aram_;
};

// Thrown when the run must stop: an unanswered poll, an access outside the
// register blocks, or a stop requested by a tool.
struct StopRun {
  std::string why;
};

}  // namespace mvp::rt
