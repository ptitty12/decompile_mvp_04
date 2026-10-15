// Which guest memory the renderer will read for each GX command (P2). The
// emulation feeds it the command stream (as the GX processor sees it) and it
// reports, command by command, the physical ranges that the GX processor and
// the WebGPU renderer read when they execute that command later on the render
// thread: the vertex array elements a primitive's indices select, the
// matrices of indexed XF loads, TLUT loads and TMEM preloads, the textures a
// draw samples the first time after a texture cache invalidation (when the
// renderer reads them: to decode them or to check its cached copy; a TLUT load
// starts that over, since the palette is part of the renderer's key), and the
// memory under an EFB copy to a texture (whose hash the renderer keeps). The
// emulation then makes every guest write to such a range wait until the render
// thread has finished the command (web/wasm/render_thread.cpp): the render
// thread reads memory as it was when the command was issued, as the inline
// renderer does. Reads nothing itself; only the command bytes.
#pragma once

#include <array>
#include <cstdint>
#include <functional>
#include <unordered_set>

#include "gfx/gx_regs.h"

namespace mvp::gfx {

// What a range is (statistics: which reads guest writes wait for).
enum class ReadKind : u8 { kVertex = 1, kXf, kTlut, kPreload, kCopy, kTexture };
constexpr int kReadKinds = 7;  // 0 unused

class GpReads {
 public:
  // Called with each range [addr, addr + size) (physical) a command reads.
  using Mark = std::function<void(u32 addr, u32 size, ReadKind kind)>;
  explicit GpReads(Mark mark) : mark_(std::move(mark)) {}

  void command(const u8* c, std::size_t len);

  struct Stats {
    std::uint64_t primitives = 0, indexed = 0, ranges = 0, textures = 0;
  };
  const Stats& stats() const { return stats_; }

 private:
  void load_cp(u8 reg, u32 v);
  void load_bp(u32 value);
  void primitive(u8 op, const u8* data, u32 count);
  void textures();
  void range(u32 addr, u32 size, ReadKind kind);

  Mark mark_;
  u32 vcd_lo_ = 0, vcd_hi_ = 0;
  std::array<u32, 8> vat_a_{}, vat_b_{}, vat_c_{};
  std::array<u32, 16> array_base_{}, array_stride_{};
  std::array<u32, 256> bp_{};
  u32 bp_mask_ = 0xFFFFFF;
  bool tex_dirty_ = true;  // texture state written since the textures were last looked at
  std::unordered_set<std::uint64_t> seen_;  // textures read since the last invalidation (or TLUT load)
  Stats stats_;
};

}  // namespace mvp::gfx
