// End to end on the GPU, data-free: synthetic GX command streams through the
// state machine into the WebGPU backend, read back from the XFB. Covers the
// EFB clear, vertex colors through TEV, textures (decoded from synthetic
// memory), blending, EFB copies to textures sampled by a later draw, and that
// a wide range of generated TEV shaders compile. Exits 77 without a GPU.
#include <doctest/doctest.h>

#include <cstdio>
#include <cstdlib>
#include <random>

#include "common/bytes.h"
#include "gfx/gx_processor.h"
#include "gfx/png.h"
#include "gfx/tev_wgsl.h"
#include "gfx/wgpu/gpu.h"
#include "gfx/wgpu/renderer.h"
#include "tests/gx_stream.h"

using namespace mvp;
using namespace mvp::gfx;
using namespace mvp::gfx::test;

namespace {

Gpu& gpu() {
  static std::unique_ptr<Gpu> g;
  if (!g) {
    std::string err;
    g = Gpu::create(&err);
    if (!g) {
      std::printf("skipped: %s\n", err.c_str());
      std::exit(77);
    }
  }
  return *g;
}

// TEV environment words.
constexpr u32 kCPrev = 0, kTexC = 8, kRasC = 10, kKonstC = 14, kZeroC = 15;
constexpr u32 kTexA = 4, kRasA = 5, kKonstA = 6, kZeroA = 7;
u32 color_env(u32 a, u32 b, u32 c, u32 d) { return d | c << 4 | b << 8 | a << 12 | 1u << 19; }
u32 alpha_env(u32 a, u32 b, u32 c, u32 d) { return d << 4 | c << 7 | b << 10 | a << 13 | 1u << 19; }

struct Scene {
  std::vector<std::uint8_t> mem = std::vector<std::uint8_t>(0x100000, 0);
  Renderer r{gpu(), mem.data(), static_cast<u32>(mem.size())};
  GxProcessor p{&r};
  Scene() { p.set_memory(mem.data(), static_cast<u32>(mem.size())); }
};

// Common state: 2D projection, one color channel from the vertex, one TEV
// stage passing the rasterized color, opaque writes, no depth test.
Stream base() {
  Stream s = setup_2d();
  s.xf(xf::kNumColors, {1});
  s.xf(xf::kColor0Cntrl, {1});
  s.xf(xf::kColor0Cntrl + 2, {1});
  s.bp(bp::kGenMode, 1u << 4);
  s.bp(bp::kTref, 0u << 7);  // stage 0: color0, no texture
  s.bp(bp::kTevColorEnv, color_env(kZeroC, kZeroC, kZeroC, kRasC));
  s.bp(bp::kTevAlphaEnv, alpha_env(kZeroA, kZeroA, kZeroA, kRasA));
  s.bp(bp::kCMode0, 1u << 3 | 1u << 4);
  s.bp(bp::kZMode, 0);
  s.bp(bp::kZCompare, 0);  // RGB8_Z24
  s.bp(bp::kAlphaCompare, 7u << 16 | 7u << 19);
  // Identity swap tables, as GXInit leaves them: (r, g) in even KSEL registers, (b, a) in odd ones.
  for (int k = 0; k < 8; ++k) s.bp(static_cast<u8>(bp::kKsel + k), (k & 1) ? (2u | 3u << 2) : (0u | 1u << 2));
  return s;
}

// Copy the 640 x 480 EFB to the XFB at 0x80000, clearing to `clear` (RGBA).
void copy_xfb(Stream& s, u32 clear_rgba, bool do_clear = true) {
  s.bp(bp::kEfbTL, 0);
  s.bp(bp::kEfbWH, 639u | 479u << 10);
  s.bp(bp::kXfbAddr, 0x80000 >> 5);
  s.bp(bp::kClearAR, (clear_rgba >> 24) | (clear_rgba & 0xFF) << 8);
  s.bp(bp::kClearGB, ((clear_rgba >> 8) & 0xFF) | ((clear_rgba >> 16) & 0xFF) << 8);
  s.bp(bp::kClearZ, 0xFFFFFF);
  s.bp(bp::kTriggerCopy, 1u << 14 | (do_clear ? 1u << 11 : 0u));
}

// A quad from (x0, y0) to (x1, y1): position xy f32, color rgba8, tex0 st f32.
void quad(Stream& s, float x0, float y0, float x1, float y1, u32 rgba, float s0 = 0, float t0 = 0, float s1 = 1,
          float t1 = 1) {
  s.cp(cp::kVcdLo, 1u << 9 | 1u << 13);
  s.cp(cp::kVcdHi, 1u);
  s.cp(cp::kVatA, 0u | 4u << 1 | 1u << 13 | 5u << 14 | 1u << 21 | 4u << 22);
  std::vector<std::uint8_t> v;
  auto vert = [&](float x, float y, float ss, float tt) {
    f32(v, x);
    f32(v, y);
    Stream::put32(v, rgba);
    f32(v, ss);
    f32(v, tt);
  };
  vert(x0, y0, s0, t0);
  vert(x1, y0, s1, t0);
  vert(x1, y1, s1, t1);
  vert(x0, y1, s0, t1);
  s.prim(cmd::kQuads, 4, v);
}

const std::uint8_t* px(const std::vector<std::uint8_t>& img, u32 w, u32 x, u32 y) { return &img[(y * w + x) * 4]; }

bool near(const std::uint8_t* p, int r, int g, int b, int tol = 2) {
  return std::abs(p[0] - r) <= tol && std::abs(p[1] - g) <= tol && std::abs(p[2] - b) <= tol;
}

}  // namespace

TEST_CASE("clear, vertex-colored quad, XFB copy") {
  Scene sc;
  Stream s = base();
  copy_xfb(s, 0x0000FFFF);  // clear the EFB to blue (copying the initial black)
  quad(s, 100, 50, 300, 250, 0xFF0000FF);
  copy_xfb(s, 0x000000FF, false);
  s.run(sc.p);
  const Renderer::Frame* f = sc.r.xfb(0x80000);
  REQUIRE(f != nullptr);
  CHECK(f->width == 640);
  CHECK(f->height == 480);
  auto img = sc.r.read_frame(*f);
  if (const char* dbg = std::getenv("MVP_GFX_TEST_PNG")) write_png_rgba(dbg, 640, 480, img.data());
  {
    const std::uint8_t* q = px(img, 640, 200, 150);
    INFO("pixel (200,150) = " << int(q[0]) << "," << int(q[1]) << "," << int(q[2]) << "," << int(q[3]));
    CHECK(near(q, 255, 0, 0));
  }
  CHECK(near(px(img, 640, 101, 51), 255, 0, 0));
  CHECK(near(px(img, 640, 98, 150), 0, 0, 255));
  CHECK(near(px(img, 640, 200, 252), 0, 0, 255));
  CHECK(near(px(img, 640, 639, 479), 0, 0, 255));
  CHECK(sc.r.stats().draws == 1);
  CHECK(gpu().errors() == 0);
}

TEST_CASE("textured quad from synthetic RGB565 memory, with konst modulation") {
  Scene sc;
  // An 8 x 8 RGB565 texture at 0x40000: left half red, right half green (4x4 tiles).
  for (u32 y = 0; y < 8; ++y)
    for (u32 x = 0; x < 8; ++x) {
      u32 tile = (y / 4) * 2 + x / 4, in = (y % 4) * 4 + x % 4;
      put_be16(&sc.mem[0x40000 + tile * 32 + in * 2], x < 4 ? 0xF800 : 0x07E0);
    }
  Stream s = base();
  s.xf(xf::kNumTexGens, {1});
  s.xf(xf::kTexGen, {5u << 7});  // regular, tex0, ST, AB11
  s.xff(60 * 4, {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0});  // GX_IDENTITY
  s.cp(cp::kMatIndexA, 60u << 6);
  s.bp(bp::kGenMode, 1u | 1u << 4);
  s.bp(bp::kTref, 0u | 0u << 3 | 1u << 6 | 0u << 7);  // map 0, coord 0, enabled
  // out = tex * konst (konst 0 = (255, 255, 128) via kcsel 12) ... a = 0, b = tex, c = konst, d = 0.
  s.bp(bp::kTevColorEnv, color_env(kZeroC, kTexC, kKonstC, kZeroC));
  s.bp(bp::kTevAlphaEnv, alpha_env(kZeroA, kZeroA, kZeroA, kTexA));
  s.bp(bp::kTevReg + 0, 1u << 23 | 255u | 255u << 12);  // konst 0 RA: r 255, a 255
  s.bp(bp::kTevReg + 1, 1u << 23 | 0u | 128u << 12);    // konst 0 BG: b 0, g 128
  s.bp(bp::kKsel, 12u << 4 | 1u << 2);  // stage 0 kcsel K0, swap table 0 (r, g) kept
  s.bp(bp::tex_reg(bp::kTexImage0, 0), 7u | 7u << 10 | 4u << 20);
  s.bp(bp::tex_reg(bp::kTexImage3, 0), 0x40000 >> 5);
  s.bp(bp::tex_reg(bp::kTexMode0, 0), 0);  // clamp, nearest
  for (int k = 0; k < 8; ++k) {  // texcoord sizes as GX sets them (the texture's size)
    s.bp(static_cast<u8>(bp::kSuSSize + 2 * k), 7);
    s.bp(static_cast<u8>(bp::kSuTSize + 2 * k), 7);
  }
  copy_xfb(s, 0x000000FF);
  quad(s, 0, 0, 320, 240, 0xFFFFFFFF);
  copy_xfb(s, 0x000000FF, false);
  s.run(sc.p);
  const Renderer::Frame* f = sc.r.xfb(0x80000);
  REQUIRE(f != nullptr);
  auto img = sc.r.read_frame(*f);
  CHECK(near(px(img, 640, 40, 100), 255, 0, 0));    // red * (1, 0.5, 0)
  CHECK(near(px(img, 640, 280, 100), 0, 128, 0));   // green * 0.5
  CHECK(near(px(img, 640, 400, 100), 0, 0, 0));     // outside: black
  CHECK(sc.r.stats().textures_decoded == 1);
  CHECK(gpu().errors() == 0);
}

TEST_CASE("alpha blending and the alpha test") {
  Scene sc;
  Stream s = base();
  copy_xfb(s, 0x000000FF);
  // White at alpha 128 over black: src alpha / inverse src alpha.
  s.bp(bp::kCMode0, 1u | 1u << 3 | 1u << 4 | 5u << 5 | 4u << 8);
  quad(s, 0, 0, 100, 100, 0xFFFFFF80);
  // The alpha test drops this one (alpha 64 must be > 100).
  s.bp(bp::kCMode0, 1u << 3 | 1u << 4);
  s.bp(bp::kAlphaCompare, 100u | 4u << 16 | 7u << 19 | 0u << 22);
  quad(s, 200, 0, 300, 100, 0x00FF0040);
  copy_xfb(s, 0x000000FF, false);
  s.run(sc.p);
  auto img = sc.r.read_frame(*sc.r.xfb(0x80000));
  CHECK(near(px(img, 640, 50, 50), 128, 128, 128, 3));
  CHECK(near(px(img, 640, 250, 50), 0, 0, 0));
  CHECK(gpu().errors() == 0);
}

TEST_CASE("an EFB copy to a texture is sampled by a later draw") {
  Scene sc;
  Stream s = base();
  copy_xfb(s, 0x000000FF);
  // Draw a 64 x 64 yellow square at (0, 0), copy it (RGBA8) to 0x60000.
  quad(s, 0, 0, 64, 64, 0xFFFF00FF);
  s.bp(bp::kEfbTL, 0);
  s.bp(bp::kEfbWH, 63u | 63u << 10);
  s.bp(bp::kXfbAddr, 0x60000 >> 5);
  s.bp(bp::kTriggerCopy, ((6u & 7) << 1 | 6u >> 3) << 3);  // RGBA8 (the field holds the format rotated left by one)
  // Clear, then draw a quad sampling that texture at (300, 200)-(428, 328).
  copy_xfb(s, 0x000000FF);
  s.xf(xf::kNumTexGens, {1});
  s.xf(xf::kTexGen, {5u << 7});
  s.xff(60 * 4, {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0});
  s.cp(cp::kMatIndexA, 60u << 6);
  s.bp(bp::kGenMode, 1u | 1u << 4);
  s.bp(bp::kTref, 1u << 6);
  s.bp(bp::kTevColorEnv, color_env(kZeroC, kZeroC, kZeroC, kTexC));
  s.bp(bp::tex_reg(bp::kTexImage0, 0), 63u | 63u << 10 | 6u << 20);
  s.bp(bp::tex_reg(bp::kTexImage3, 0), 0x60000 >> 5);
  for (int k = 0; k < 2; ++k) {
    s.bp(static_cast<u8>(bp::kSuSSize + 2 * k), 63);
    s.bp(static_cast<u8>(bp::kSuTSize + 2 * k), 63);
  }
  quad(s, 300, 200, 428, 328, 0xFFFFFFFF);
  copy_xfb(s, 0x000000FF, false);
  s.run(sc.p);
  auto img = sc.r.read_frame(*sc.r.xfb(0x80000));
  CHECK(near(px(img, 640, 360, 260), 255, 255, 0));
  CHECK(near(px(img, 640, 30, 30), 0, 0, 0));  // the original square was cleared
  CHECK(sc.r.stats().copy_textures_used == 1);
  CHECK(sc.r.stats().textures_decoded == 0);
  CHECK(gpu().errors() == 0);
}

TEST_CASE("generated TEV shaders compile for many configurations") {
  std::mt19937 rng(1234);
  int made = 0;
  for (int n = 0; n < 200; ++n) {
    PipelineConfig c{};
    std::memset(&c, 0, sizeof c);
    c.num_stages = static_cast<u8>(1 + rng() % 16);
    for (int i = 0; i < c.num_stages; ++i) {
      TevStage& st = c.stages[i];
      st.color_env = rng() & 0xFFFFFF;
      st.alpha_env = rng() & 0xFFFFFF;
      st.tex_enable = rng() & 1;
      st.texmap = static_cast<u8>(rng() % 8);
      st.texcoord = static_cast<u8>(rng() % 8);
      st.ras_chan = static_cast<u8>(rng() % 8);
      st.kcsel = static_cast<u8>(rng() % 32);
      st.kasel = static_cast<u8>(rng() % 32);
    }
    for (auto& t : c.swap)
      for (auto& k : t) k = static_cast<u8>(rng() % 4);
    c.alpha_comp0 = static_cast<u8>(rng() % 8);
    c.alpha_comp1 = static_cast<u8>(rng() % 8);
    c.alpha_logic = static_cast<u8>(rng() % 4);
    c.logic_enable = rng() & 1;
    c.logic_op = static_cast<u8>(rng() % 16);
    std::string w = generate_wgsl(c);
    gpu().shader(w, "fuzz");
    ++made;
  }
  gpu().wait_idle();
  CHECK(made == 200);
  CHECK(gpu().errors() == 0);
}
