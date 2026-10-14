// TEV -> WGSL without a GPU: the generated text has the stages, inputs, swaps,
// compare modes and alpha test the configuration asks for (test_gfx_render
// compiles generated shaders on a GPU and checks what they draw).
#include <doctest/doctest.h>

#include <cstring>
#include <string>

#include "gfx/tev_wgsl.h"

using namespace mvp::gfx;

namespace {

bool has(const std::string& s, const char* what) { return s.find(what) != std::string::npos; }

PipelineConfig blank() {
  PipelineConfig c{};
  std::memset(&c, 0, sizeof c);
  c.num_stages = 1;
  for (auto& t : c.swap) {
    t[0] = 0;
    t[1] = 1;
    t[2] = 2;
    t[3] = 3;
  }
  c.alpha_comp0 = c.alpha_comp1 = 7;
  return c;
}

}  // namespace

TEST_CASE("one textured stage modulated by the rasterized color") {
  PipelineConfig c = blank();
  // color: a = 0, b = TEXC, c = RASC, d = 0; alpha: d = TEXA; dest PREV, clamp.
  c.stages[0].color_env = 15u | 10u << 4 | 8u << 8 | 15u << 12 | 1u << 19;
  c.stages[0].alpha_env = 4u << 4 | 7u << 7 | 7u << 10 | 7u << 13 | 1u << 19;
  c.stages[0].tex_enable = 1;
  c.stages[0].texmap = 3;
  c.stages[0].texcoord = 2;
  c.stages[0].ras_chan = 0;
  std::string w = generate_wgsl(c);
  CHECK(has(w, "let tex = to8(textureSample(tex3, samp3, tc(in.t2, 2u, 3u))).rgba"));
  CHECK(has(w, "let ras = to8(in.c0).rgba"));
  CHECK(has(w, "let cb = tex.rgb & vec3i(255)"));
  CHECK(has(w, "let cc = ras.rgb & vec3i(255)"));
  CHECK(has(w, "let ad = tex.a"));
  CHECK(has(w, "tev3(ca, cb, cc, cd, false, 0, 0u, true)"));
  CHECK(!has(w, "discard"));  // the alpha test always passes
  CHECK(has(w, "@vertex fn vs_main"));
  CHECK(has(w, "@fragment fn fs_main"));
}

TEST_CASE("swap tables, konst selection, registers, compare modes and the alpha test") {
  PipelineConfig c = blank();
  c.num_stages = 2;
  c.swap[1][0] = 2;
  c.swap[1][2] = 0;  // table 1: b, g, r, a
  // Stage 0: color d = KONST (kcsel 13: K1 rgb), dest REG0, bias +0.5, scale 2, subtract.
  c.stages[0].color_env = 14u | 15u << 4 | 15u << 8 | 15u << 12 | 1u << 16 | 1u << 18 | 1u << 20 | 1u << 22;
  c.stages[0].alpha_env = 6u << 4 | 7u << 7 | 7u << 10 | 7u << 13 | 1u << 22 | 1u << 0;  // ras swap table 1
  c.stages[0].kcsel = 13;
  c.stages[0].kasel = 30;  // K2 alpha
  c.stages[0].ras_chan = 1;
  // Stage 1: color compare GR16_GT (bias 3, shift 1, sub 0): d = C0, a = CPREV, b = A0, c = ONE.
  c.stages[1].color_env = 2u | 12u << 4 | 3u << 8 | 0u << 12 | 3u << 16 | 1u << 20;
  // alpha compare A8_EQ (shift 3, sub 1).
  c.stages[1].alpha_env = 1u << 4 | 7u << 7 | 1u << 10 | 0u << 13 | 3u << 16 | 1u << 18 | 3u << 20;
  c.alpha_comp0 = 4;  // greater
  c.alpha_comp1 = 1;  // less
  c.alpha_logic = 0;  // and
  std::string w = generate_wgsl(c);
  CHECK(has(w, "let kc = u.konst[1].rgb"));
  CHECK(has(w, "let ka = i32(u.konst[2].a)"));
  CHECK(has(w, "let ras = to8(in.c1).bgra"));
  CHECK(has(w, "tev3(ca, cb, cc, cd, true, 128, 1u, false)"));
  CHECK(has(w, "r0 = vec4i(co, r0.a)"));
  CHECK(has(w, "r0.a = ao"));
  CHECK(has(w, "pack16(ca) > pack16(cb)"));
  CHECK(has(w, "aa == ab"));
  CHECK(has(w, "acmp(4u, outc.a, u.alpha_ref.x)"));
  CHECK(has(w, "acmp(1u, outc.a, u.alpha_ref.y)"));
  CHECK(has(w, "if (!(a0 && a1)) { discard; }"));
  // The pixel takes the last stage's destinations.
  CHECK(has(w, "var outc = clamp(vec4i(prev.rgb, prev.a)"));
}

TEST_CASE("logic ops without blending") {
  PipelineConfig c = blank();
  c.logic_enable = 1;
  c.logic_op = 12;
  CHECK(has(generate_wgsl(c), "vec4i(255) - outc"));
  c.logic_op = 0;
  CHECK(has(generate_wgsl(c), "return vec4f(0.0);"));
}

TEST_CASE("fog: perspective and orthographic depth, the curves") {
  PipelineConfig c = blank();
  c.fog_type = 2;
  std::string w = generate_wgsl(c);
  CHECK(has(w, "u.fog[0].x / (u.fog[0].y - f32(z24 >> u32(u.fog[0].z)))"));
  CHECK(has(w, "clamp(ze - u.fog[0].w, 0.0, 1.0)"));
  CHECK(!has(w, "exp2"));
  c.fog_proj = 1;
  c.fog_type = 5;
  w = generate_wgsl(c);
  CHECK(has(w, "var ze = u.fog[0].x * in.pos.z"));
  CHECK(has(w, "1.0 - exp2(-8.0 * fog * fog)"));
  c.fog_type = 0;
  CHECK(!has(generate_wgsl(c), "ifog"));
}
