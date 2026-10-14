// Memory-mapped hardware (E0b items 7, 9 and 10): the Flipper register blocks at
// 0xCC000000. Registers without a model store what the guest writes and read it
// back; the models below answer what the boot polls. Time is the guest time base
// (advance(), and the CPU's clock between safe points):
// - VI: display interrupts DI0-DI3 at their programmed lines, every frame (R2);
//   the beam position follows the clock;
// - PI: the interrupt cause from the device states, and the mask;
// - EXI: immediate and DMA transfers complete at once; channel 0 device 1 is the
//   IPL chip's RTC and SRAM (fixed values, R12); every other device is absent;
// - DSP: reset and halt bits, the ARAM DMA (with 16 MiB of ARAM), the AI DMA
//   (a block every len x 32 bytes of 32 or 48 kHz stereo, AIDINT at each block
//   start), and the DSP side of the mailbox protocol, without running DSP code:
//   the IPL init microcode's answer, the boot ROM's task loader, and the AX
//   microcode's frame handshake (each command list is answered with a yield
//   after a fixed time; the voices advance through runtime/ax.h, the mix itself
//   is not computed, R8);
// - DI: the DVD drive reads the disc image (vfs::Source); a command completes
//   after a fixed latency plus its transfer time (R7), then raises TCINT;
// - AI: the streaming sample counter counts at 32 or 48 kHz of virtual time
//   while playing (the SDK times its edges in __AI_SRC_INIT);
// - GX FIFO: the write-gather pipe (0xCC008000) collects 32 bytes and writes
//   them to the CPU FIFO in memory at the PI write pointer, which wraps at the
//   FIFO end. With the CP linked to it, the graphics processor reads from its
//   read pointer up to that write pointer at once (it is infinitely fast), and
//   stops at an enabled breakpoint until software moves or disables it. The
//   commands it reads are parsed (gx_fifo.h): draw-done and token commands raise
//   the PE interrupts, a reached breakpoint the CP interrupt. The first bytes
//   read are kept for reports.
// Every access is logged (capped) and counted.
#pragma once

#include <array>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "ppc/cpu.h"
#include "runtime/gx_fifo.h"

namespace mvp::vfs {
class Source;
}

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
  // DVD timing (R7): every drive command completes this many time-base ticks
  // after it starts, plus its DMA length at this rate. Both are part of the
  // netplay handshake. 40,500 ticks = 1 ms; 13,184 ticks per KiB = 3 MiB/s.
  std::uint32_t di_latency_tb = 40500;
  std::uint32_t di_tb_per_kib = 13184;
  // AX voices (R8, runtime/ax.h): each audio frame advances the running voices'
  // parameter blocks (play position, loop, end). Off: they never move (E0b).
  bool ax_voices = true;
};

// What the AX voice model did (runtime/ax.h), summed over all frames.
struct AxStats {
  std::uint64_t voice_frames = 0, samples = 0, ended = 0, looped = 0, updates = 0, max_running = 0;
};

class Hardware : public ppc::Io {
 public:
  Hardware(ppc::Cpu* cpu, u8* mem1, u32 mem1_size, const HardwareConfig& cfg = {});

  u32 read(u32 addr, int size) override;
  void write(u32 addr, u32 value, int size) override;

  const std::vector<MmioAccess>& log() const { return log_; }
  const std::map<u32, std::uint64_t>& read_counts() const { return reads_; }
  const std::map<u32, std::uint64_t>& write_counts() const { return writes_; }
  const std::vector<u8>& fifo() const { return fifo_; }  // the first bytes written to the write-gather pipe
  std::uint64_t fifo_bytes() const { return fifo_bytes_; }
  const GxFifo& gx() const { return gx_; }
  // The renderer (E1): sees every executed GX command and every VI field.
  void set_gfx_observer(GfxObserver* o) {
    gfx_ = o;
    gx_.set_observer(o);
  }
  std::uint64_t draw_done_count() const { return draw_dones_; }
  std::uint64_t gp_bursts() const { return gp_bursts_; }
  const std::array<u8, 64>& sram() const { return sram_; }

  // ---- time and interrupts (E0b items 9 and 10) ----
  // Time is the guest time base (40.5 MHz), driven by the runtime's virtual clock.
  // Moves the devices to time `tb` (VI display interrupts so far).
  void advance(std::uint64_t tb);
  // The next time base at which advance() has something to do (~0 if none).
  std::uint64_t next_event_tb() const;
  // PI interrupt cause bits (0xCC003000) from the device states, and the mask.
  u32 pi_cause() const;
  u32 pi_mask() const { return reg(0xCC003004u); }
  bool interrupt_pending() const { return (pi_cause() & pi_mask() & 0xFFFFu) != 0; }
  std::uint64_t vi_fields() const { return vi_fields_; }

  // The disc the DVD drive reads (no disc: every DI command stops the run).
  void set_disc(vfs::Source* disc) { disc_ = disc; }
  std::uint64_t di_commands() const { return di_commands_; }
  std::uint64_t dsp_frames() const { return dsp_frames_; }
  const AxStats& ax_stats() const { return ax_; }
  int dsp_state() const { return static_cast<int>(dsp_state_); }
  std::size_t dsp_mails_waiting() const { return dsp_out_.size(); }
  u32 dsp_control() const { return dsp_cr_; }
  u32 dsp_mail_to_cpu() const { return dsp_mail_to_cpu_; }
  std::uint64_t ai_dma_blocks() const { return aid_interrupts_; }
  std::uint64_t di_bytes() const { return di_bytes_; }

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

  // VI: display interrupts DI0-DI3 at their programmed lines, every frame.
  static constexpr std::uint64_t kFrameTb = 1351350;  // 2 fields of 675,675 (NTSC 59.94 Hz, R2)
  static constexpr std::uint64_t kLines = 525;
  std::uint64_t line_tb() const { return kFrameTb / kLines; }
  void vi_schedule_frame();
  u32 vi_current_line() const;
  std::uint64_t now_tb_ = 0, frame_start_tb_ = 0, vi_fields_ = 0;
  std::vector<std::pair<std::uint64_t, int>> vi_events_;  // (tb, DI index) this frame, sorted

  // The current time base: from the CPU's clock when there is one (MMIO happens
  // between safe points), else the last advance().
  std::uint64_t now() const;

  // AI: control (play 0x1, 48 kHz 0x2, counter reset 0x20) and the sample
  // counter, which runs from `ai_count_base_` at time `ai_t0_` while playing.
  void ai_write(u32 reg, u32 v);
  u32 ai_count(std::uint64_t tb) const;
  std::uint64_t ai_next_change_tb() const;
  u32 ai_cr_ = 0, ai_count_base_ = 0;
  std::uint64_t ai_t0_ = 0;

  // DSP mailbox HLE. Mails to the CPU wait in time order; one is in the mailbox
  // at a time.
  enum class DspState { Off, IplInit, RomReady, Loading, Running };
  struct DspMail {
    std::uint64_t tb;
    u32 mail;
    bool irq;
  };
  void dsp_receive(u32 mail);
  void dsp_post(std::uint64_t delay_tb, u32 mail, bool irq);
  void dsp_deliver();
  DspState dsp_state_ = DspState::Off;
  u32 dsp_boots_ = 0, dsp_load_n_ = 0;
  bool dsp_cmdlist_next_ = false;
  std::vector<DspMail> dsp_out_;
  std::uint64_t dsp_frames_ = 0;
  AxStats ax_;

  // AI DMA (DSP registers 0x30-0x3A): the block being played and its end.
  void aid_start_block(std::uint64_t tb);
  std::uint64_t aid_block_tb(u32 blocks) const;
  bool aid_on_ = false;
  u32 aid_blocks_ = 0;
  std::uint64_t aid_start_tb_ = 0, aid_end_tb_ = ~0ull;
  std::uint64_t aid_interrupts_ = 0;

  // DI
  void di_write(u32 reg, u32 v);
  u32 di_read(u32 reg) const;
  void di_complete();
  vfs::Source* disc_ = nullptr;
  u32 di_sr_ = 0, di_cvr_ = 0, di_mar_ = 0, di_len_ = 0, di_cr_ = 0, di_imm_ = 0, di_cfg_ = 0;
  u32 di_cmd_[3] = {};
  std::uint64_t di_done_tb_ = ~0ull;
  std::uint64_t di_commands_ = 0, di_bytes_ = 0;

  // DSP
  void dsp_write16(u32 off, u16 v);
  u16 dsp_read16(u32 off);
  void dsp_aram_dma();

  // An interrupt cause may have appeared outside advance(): have the CPU check
  // at its next safe point (deterministic: the point is fixed by the code).
  void kick();

  // PE: interrupt control (enables in bits 0-1, token and finish status in
  // bits 2-3, write 1 to clear) and the last token.
  u16 pe_ctrl_ = 0, pe_token_ = 0;
  GxFifo gx_;
  GfxObserver* gfx_ = nullptr;

  // GX FIFO: the write-gather buffer, and the CP registers (16-bit, kept in
  // regs_; 32-bit values are lo/hi pairs).
  void wgp_write(u32 value, int size);
  void wgp_burst();
  void gp_run();
  void gp_consume(const u8* bytes, std::size_t n);
  u16 cp16(u32 off) const;
  u32 cp32(u32 lo_off) const { return cp16(lo_off) | u32(cp16(lo_off + 2)) << 16; }
  void set_cp32(u32 lo_off, u32 v);
  u32 cp_status() const;
  u32 gp_distance() const;
  bool gp_at_breakpoint() const;
  u8 gather_[32] = {};
  u32 gather_n_ = 0;
  std::uint64_t gp_bursts_ = 0;
  std::uint64_t fifo_bytes_ = 0, draw_dones_ = 0;
  static constexpr std::size_t kFifoKeep = 1u << 20;

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
