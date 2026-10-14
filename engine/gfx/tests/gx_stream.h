// Builds synthetic GX command streams for the renderer's data-free tests: the
// same bytes the game's GX macros write to the FIFO, made by hand.
#pragma once

#include <bit>
#include <cstdint>
#include <vector>

#include "gfx/gx_processor.h"

namespace mvp::gfx::test {

struct Stream {
  std::vector<std::vector<std::uint8_t>> cmds;

  static void put32(std::vector<std::uint8_t>& v, std::uint32_t x) {
    v.push_back(static_cast<std::uint8_t>(x >> 24));
    v.push_back(static_cast<std::uint8_t>(x >> 16));
    v.push_back(static_cast<std::uint8_t>(x >> 8));
    v.push_back(static_cast<std::uint8_t>(x));
  }
  Stream& cp(std::uint8_t reg, std::uint32_t v) {
    std::vector<std::uint8_t> c{0x08, reg};
    put32(c, v);
    cmds.push_back(c);
    return *this;
  }
  Stream& bp(std::uint8_t reg, std::uint32_t v) {
    std::vector<std::uint8_t> c{0x61};
    put32(c, std::uint32_t(reg) << 24 | (v & 0xFFFFFF));
    cmds.push_back(c);
    return *this;
  }
  Stream& xf(std::uint32_t addr, const std::vector<std::uint32_t>& words) {
    std::vector<std::uint8_t> c{0x10};
    put32(c, std::uint32_t(words.size() - 1) << 16 | addr);
    for (auto w : words) put32(c, w);
    cmds.push_back(c);
    return *this;
  }
  Stream& xff(std::uint32_t addr, const std::vector<float>& fs) {
    std::vector<std::uint32_t> w;
    for (float f : fs) w.push_back(std::bit_cast<std::uint32_t>(f));
    return xf(addr, w);
  }
  Stream& raw(std::vector<std::uint8_t> c) {
    cmds.push_back(std::move(c));
    return *this;
  }
  // A primitive: opcode | format, then the vertex bytes.
  Stream& prim(std::uint8_t op, std::uint16_t count, const std::vector<std::uint8_t>& data) {
    std::vector<std::uint8_t> c{op, static_cast<std::uint8_t>(count >> 8), static_cast<std::uint8_t>(count)};
    c.insert(c.end(), data.begin(), data.end());
    cmds.push_back(c);
    return *this;
  }
  void run(GxProcessor& p) const {
    for (const auto& c : cmds) p.command(c.data(), c.size());
  }
};

// Vertex byte helpers.
inline void f32(std::vector<std::uint8_t>& v, float f) { Stream::put32(v, std::bit_cast<std::uint32_t>(f)); }
inline void u16be(std::vector<std::uint8_t>& v, std::uint16_t x) {
  v.push_back(static_cast<std::uint8_t>(x >> 8));
  v.push_back(static_cast<std::uint8_t>(x));
}

// The usual 2D setup: identity position matrix 0, an orthographic projection
// of (0..640, 0..480) with y down, the viewport over 640 x 480, depth 0..1.
inline Stream setup_2d() {
  Stream s;
  s.xff(0x000, {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0});
  // C_MTXOrtho(t=0, b=480, l=0, r=640, n=0, f=1), as GXSetProjection writes it.
  s.xff(0x1020, {2.0f / 640, -1.0f, 2.0f / (0 - 480.0f), 1.0f, -1.0f, -1.0f});
  s.xf(0x1026, {1});
  s.xff(0x101A, {320.0f, -240.0f, 16777215.0f, 342.0f + 320, 342.0f + 240, 16777215.0f});
  return s;
}

class Capture : public Backend {
 public:
  std::vector<DrawCall> draws;
  std::vector<EfbCopy> copies;
  int invalidations = 0;
  void draw(const DrawCall& d) override { draws.push_back(d); }
  void efb_copy(const EfbCopy& c) override { copies.push_back(c); }
  void invalidate_textures() override { ++invalidations; }
};

}  // namespace mvp::gfx::test
