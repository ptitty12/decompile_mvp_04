// What the renderer is given, as a running hash (P2, a validation tool): sits
// between the GX processor and a backend and folds into one 64-bit digest
// everything the backend's output depends on: each draw's transformed vertices
// and indices (so the vertex arrays and matrices the processor read from guest
// memory), its pipeline configuration, constants, scissor and texture
// descriptions (palettes and TMEM contents included), every EFB copy, and the
// guest memory of each texture the first time a draw samples it after a texture
// cache invalidation (when the WebGPU renderer reads it). Everything is
// forwarded unchanged.
//
// A renderer that runs on its own thread, behind the emulation, reads guest
// memory later than an inline one; the two see the same memory exactly when
// their digests agree field by field (docs/engine/P2_LOG.md). Costs a few
// milliseconds per heavy field: off unless asked for.
#pragma once

#include <cstdint>
#include <cstring>
#include <unordered_set>

#include "gfx/draw.h"
#include "gfx/texture_decode.h"

namespace mvp::gfx {

class DigestTap final : public Backend {
 public:
  Backend* next = nullptr;
  bool on = false;

  void set_memory(const std::uint8_t* mem, std::uint32_t size) {
    mem_ = mem;
    mem_size_ = size;
  }
  std::uint64_t digest() const { return h_; }
  std::uint64_t draws() const { return draws_; }

  void draw(const DrawCall& d) override {
    if (on) fold_draw(d);
    next->draw(d);
  }
  void efb_copy(const EfbCopy& c) override {
    if (on) {
      fold(&c.copy_value, sizeof c.copy_value);
      const std::uint32_t v[12] = {c.src_x, c.src_y, c.width, c.height, c.dest, c.dest_stride, c.to_xfb,
                                   c.tex_format, c.half_scale, c.clear, c.clear_z, c.gamma};
      fold(v, sizeof v);
      fold(c.clear_rgba, 4);
    }
    next->efb_copy(c);
  }
  void invalidate_textures() override {
    if (on) {
      seen_.clear();
      fold("inv", 3);
    }
    next->invalidate_textures();
  }

 private:
  static std::uint64_t key(std::uint32_t addr, std::uint32_t size) { return std::uint64_t(size) << 32 | addr; }

  void fold(const void* p, std::size_t n) {
    // FNV-1a style over 8-byte words, then a final mix (fast enough for MBs per field).
    const auto* b = static_cast<const std::uint8_t*>(p);
    std::uint64_t h = h_;
    std::size_t i = 0;
    for (; i + 8 <= n; i += 8) {
      std::uint64_t w;
      std::memcpy(&w, b + i, 8);
      h = (h ^ w) * 0x100000001B3ull;
      h ^= h >> 29;
    }
    for (; i < n; ++i) h = (h ^ b[i]) * 0x100000001B3ull;
    h_ = h ^ (h >> 31);
  }

  void fold_draw(const DrawCall& d) {
    ++draws_;
    fold(&d.cfg, sizeof d.cfg);
    fold(&d.u, sizeof d.u);
    fold(d.scissor, sizeof d.scissor);
    if (!d.verts.empty()) fold(d.verts.data(), d.verts.size() * sizeof(OutVertex));
    if (!d.index.empty()) fold(d.index.data(), d.index.size() * sizeof(std::uint32_t));
    for (const TextureDesc& t : d.tex) {
      if (!t.valid) continue;
      const std::uint32_t v[12] = {t.addr, t.format, t.width, t.height, t.levels, t.tlut_format, t.tlut_offset,
                                   t.tlut_entries, t.wrap_s, t.wrap_t, t.mag_linear, t.min_filter};
      fold(v, sizeof v);
      const float f[3] = {t.lod_bias, t.min_lod, t.max_lod};
      fold(f, sizeof f);
      if (t.tlut) fold(t.tlut, std::size_t(t.tlut_entries) * 2);
      if (!texture_format_known(t.format)) continue;
      if (t.tmem) {
        const std::uint32_t n = texture_level_size(t.format, t.width, t.height);
        if (t.tmem_even < (1u << 20) && n <= (1u << 20) - t.tmem_even) fold(t.tmem + t.tmem_even, n);
        continue;
      }
      // Guest memory, the first time this texture is used after an invalidation
      // (the renderer reads it then: to decode it or to check its cached copy).
      const std::uint32_t a = t.addr & 0x01FFFFFFu;
      const std::uint32_t size = texture_size(t.format, t.width, t.height, t.levels);
      if (!seen_.insert(key(a, size)).second) continue;
      if (mem_ && a <= mem_size_ && size <= mem_size_ - a) fold(mem_ + a, size);
    }
  }

  const std::uint8_t* mem_ = nullptr;
  std::uint32_t mem_size_ = 0;
  std::uint64_t h_ = 0xCBF29CE484222325ull, draws_ = 0;
  std::unordered_set<std::uint64_t> seen_;
};

}  // namespace mvp::gfx
