// The GX state machine (E1): executes the command stream the graphics
// processor reads (runtime/gx_fifo.h hands it every command, display-list
// contents included) the way Flipper would, as far as rendering goes:
// - CP, XF and BP register loads, with the BP write mask;
// - indexed XF loads and TLUT loads, read from guest memory at the moment the
//   command executes (as the hardware does);
// - primitives: vertices decoded from the current VCD/VAT and arrays, then the
//   transform unit (position, normal, lighting, texture coordinate generation)
//   on the CPU, assembled into triangle lists;
// - EFB copies.
// The result goes to a Backend (draw.h). Guest memory is only read.
//
// GPU-side values the guest reads (PE tokens, draw-done, FIFO state) are not
// computed here: they stay on the runtime's deterministic model (E0b-GX1).
#pragma once

#include <array>
#include <cstdint>
#include <vector>

#include "gfx/draw.h"
#include "gfx/gx_regs.h"

namespace mvp::gfx {

// A vertex as the CP loads it, before the transform unit.
struct InVertex {
  u8 pnmtx = 0;
  u8 texmtx[8] = {};
  float pos[3] = {};
  float nrm[3] = {}, bin[3] = {}, tan[3] = {};
  float color[2][4] = {};
  float tex[8][2] = {};
};

class GxProcessor {
 public:
  explicit GxProcessor(Backend* backend) : backend_(backend) { reset(); }

  // Guest memory (MEM1) that addresses in the stream point into (physical).
  void set_memory(const u8* mem, u32 size) {
    mem_ = mem;
    mem_size_ = size;
  }

  void reset();

  // Executes one complete command (opcode and payload).
  void command(const u8* cmd, std::size_t len);

  // ---- state, for tests and debugging ----
  u32 bp(u8 reg) const { return bp_[reg]; }
  u32 cp_vcd_lo() const { return vcd_lo_; }
  u32 cp_vcd_hi() const { return vcd_hi_; }
  u32 xf_word(u32 addr) const;
  float xf_float(u32 addr) const;
  const u8* tlut_memory() const { return tlut_.data(); }

  // Vertex size in bytes for format `fmt` under the current VCD/VAT.
  u32 vertex_size(int fmt) const;
  // Decodes one vertex of format `fmt` from `p` (vertex_size bytes).
  InVertex load_vertex(int fmt, const u8* p) const;
  // The transform unit for one vertex.
  OutVertex transform(const InVertex& v) const;
  // The pipeline configuration, uniforms and textures for a draw now.
  void snapshot(DrawCall& d) const;

  struct Stats {
    std::uint64_t commands = 0, draws = 0, vertices = 0, triangles = 0, copies = 0, xfb_copies = 0;
    std::uint64_t tlut_loads = 0, xf_indexed = 0, unknown = 0;
  };
  const Stats& stats() const { return stats_; }

 private:
  void load_bp(u32 value);
  void load_cp(u8 reg, u32 value);
  void load_xf(u32 addr, u32 count, const u8* data);
  void load_xf_indexed(int array, u32 value);
  void primitive(u8 op, const u8* data, u32 count);
  void efb_copy();
  void load_tlut();
  const u8* phys(u32 addr, u32 len) const;  // null if outside memory

  Backend* backend_;
  const u8* mem_ = nullptr;
  u32 mem_size_ = 0;

  std::array<u32, 256> bp_{};
  u32 bp_mask_ = 0xFFFFFF;
  u32 vcd_lo_ = 0, vcd_hi_ = 0;
  std::array<u32, 8> vat_a_{}, vat_b_{}, vat_c_{};
  std::array<u32, 16> array_base_{}, array_stride_{};
  u32 matidx_a_ = 0, matidx_b_ = 0;
  std::array<u32, xf::kMemSize> xf_mem_{};
  std::array<u32, xf::kRegCount> xf_regs_{};
  // TEV color registers (PREV, REG0-2) and konst colors as written (11-bit signed).
  std::int32_t tev_regs_[4][4] = {};
  std::int32_t konst_[4][4] = {};
  std::vector<u8> tlut_;  // TMEM's palette half: 512 KiB
  Stats stats_;
};

}  // namespace mvp::gfx
