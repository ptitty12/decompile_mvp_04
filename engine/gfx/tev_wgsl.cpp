#include "gfx/tev_wgsl.h"

#include <cstdarg>
#include <cstdio>

namespace mvp::gfx {

namespace {

const char* kCommon = R"(
struct U {
  tev_regs: array<vec4i, 4>,
  konst: array<vec4i, 4>,
  alpha_ref: vec4i,
  tex_scale: array<vec4f, 8>,
  ind_mtx: array<vec4i, 6>,
  fog: array<vec4f, 2>,
  dst_alpha: vec4i,
};
@group(0) @binding(0) var<uniform> u: U;
@group(1) @binding(0) var tex0: texture_2d<f32>;
@group(1) @binding(1) var tex1: texture_2d<f32>;
@group(1) @binding(2) var tex2: texture_2d<f32>;
@group(1) @binding(3) var tex3: texture_2d<f32>;
@group(1) @binding(4) var tex4: texture_2d<f32>;
@group(1) @binding(5) var tex5: texture_2d<f32>;
@group(1) @binding(6) var tex6: texture_2d<f32>;
@group(1) @binding(7) var tex7: texture_2d<f32>;
@group(1) @binding(8) var samp0: sampler;
@group(1) @binding(9) var samp1: sampler;
@group(1) @binding(10) var samp2: sampler;
@group(1) @binding(11) var samp3: sampler;
@group(1) @binding(12) var samp4: sampler;
@group(1) @binding(13) var samp5: sampler;
@group(1) @binding(14) var samp6: sampler;
@group(1) @binding(15) var samp7: sampler;

struct VIn {
  @location(0) pos: vec4f,
  @location(1) c0: vec4f,
  @location(2) c1: vec4f,
  @location(3) t0: vec3f,
  @location(4) t1: vec3f,
  @location(5) t2: vec3f,
  @location(6) t3: vec3f,
  @location(7) t4: vec3f,
  @location(8) t5: vec3f,
  @location(9) t6: vec3f,
  @location(10) t7: vec3f,
};
struct VOut {
  @builtin(position) pos: vec4f,
  @location(0) c0: vec4f,
  @location(1) c1: vec4f,
  @location(2) t0: vec3f,
  @location(3) t1: vec3f,
  @location(4) t2: vec3f,
  @location(5) t3: vec3f,
  @location(6) t4: vec3f,
  @location(7) t5: vec3f,
  @location(8) t6: vec3f,
  @location(9) t7: vec3f,
};

@vertex fn vs_main(v: VIn) -> VOut {
  var o: VOut;
  o.pos = v.pos;
  o.c0 = v.c0;
  o.c1 = v.c1;
  o.t0 = v.t0; o.t1 = v.t1; o.t2 = v.t2; o.t3 = v.t3;
  o.t4 = v.t4; o.t5 = v.t5; o.t6 = v.t6; o.t7 = v.t7;
  return o;
}

// Texture coordinate (s/q, t/q) of `t`, scaled from the rasterizer's size for
// its coordinate to the sampled map's size.
fn tc(t: vec3f, coord: u32, map: u32) -> vec2f {
  let q = select(t.z, 1.0, t.z == 0.0);
  return t.xy / q * u.tex_scale[coord].xy / u.tex_scale[map].zw;
}

fn to8(c: vec4f) -> vec4i { return vec4i(round(clamp(c, vec4f(0.0), vec4f(1.0)) * 255.0)); }

// One TEV color or alpha operation (regular: d + lerp(a, b, c) + bias, scaled),
// in the hardware's fixed point: inputs a, b, c are 8-bit, d 11-bit signed.
fn tev3(a: vec3i, b: vec3i, c: vec3i, d: vec3i, sub: bool, bias: i32, shift: u32, clampv: bool) -> vec3i {
  let cc = c + (c >> vec3u(7u));
  var l = a * (vec3i(256) - cc) + b * cc;
  if (sub) { l = -l; }
  var v = d * 256 + l + vec3i(bias * 256);
  var r: vec3i;
  if (shift == 3u) {
    r = (v + vec3i(256)) >> vec3u(9u);
  } else {
    v = v * i32(1u << shift);
    r = (v + vec3i(select(128, 127, sub))) >> vec3u(8u);
  }
  if (clampv) { return clamp(r, vec3i(0), vec3i(255)); }
  return clamp(r, vec3i(-1024), vec3i(1023));
}

fn tev1(a: i32, b: i32, c: i32, d: i32, sub: bool, bias: i32, shift: u32, clampv: bool) -> i32 {
  return tev3(vec3i(a), vec3i(b), vec3i(c), vec3i(d), sub, bias, shift, clampv).x;
}

// Texture coordinate in the rasterizer's fixed point (1/128 texel of its size).
fn fixuv(t: vec3f, coord: u32) -> vec2i {
  let q = select(t.z, 1.0, t.z == 0.0);
  return vec2i(t.xy / q * u.tex_scale[coord].xy * 128.0);
}
// Normalized sampling coordinate of a fixed-point coordinate on map `map`
// (half a unit in, so nearest sampling lands on the texel the hardware takes).
fn fixst(c: vec2i, map: u32) -> vec2f { return (vec2f(c) + 0.5) / 128.0 / u.tex_scale[map].zw; }
// Indirect matrix scale: the shift held in the row's w (17 - exponent).
fn indshift(v: vec2i, w: i32) -> vec2i {
  if (w >= 0) { return v >> vec2u(u32(min(w, 31))); }
  return v << vec2u(u32(min(-w, 31)));
}

fn pack16(v: vec3i) -> i32 { return (v.g << 8u) | v.r; }
fn pack24(v: vec3i) -> i32 { return (v.b << 16u) | (v.g << 8u) | v.r; }

fn acmp(f: u32, a: i32, r: i32) -> bool {
  switch (f) {
    case 0u: { return false; }
    case 1u: { return a < r; }
    case 2u: { return a == r; }
    case 3u: { return a <= r; }
    case 4u: { return a > r; }
    case 5u: { return a != r; }
    case 6u: { return a >= r; }
    default: { return true; }
  }
}
)";

std::string str(const char* fmt, ...) {
  char buf[512];
  va_list ap;
  va_start(ap, fmt);
  std::vsnprintf(buf, sizeof buf, fmt, ap);
  va_end(ap);
  return buf;
}

const char* kRegNames[4] = {"prev", "r0", "r1", "r2"};

std::string swizzle(const u8 sw[4]) {
  static const char comp[4] = {'r', 'g', 'b', 'a'};
  std::string s = ".";
  for (int k = 0; k < 4; ++k) s += comp[sw[k] & 3];
  return s;
}

const char* kKonstFrac[8] = {"255", "223", "191", "159", "128", "96", "64", "32"};

std::string konst_color(u8 sel) {
  if (sel < 8) return str("vec3i(%s)", kKonstFrac[sel]);
  if (sel >= 12 && sel < 16) return str("u.konst[%d].rgb", sel - 12);
  if (sel >= 16) {
    static const char comp[4] = {'r', 'g', 'b', 'a'};
    return str("vec3i(u.konst[%d].%c)", sel & 3, comp[(sel - 16) / 4]);
  }
  return "vec3i(0)";
}

std::string konst_alpha(u8 sel) {
  if (sel < 8) return kKonstFrac[sel];
  if (sel >= 16) {
    static const char comp[4] = {'r', 'g', 'b', 'a'};
    return str("u.konst[%d].%c", sel & 3, comp[(sel - 16) / 4]);
  }
  return "0";
}

std::string color_arg(u32 arg) {
  switch (arg) {
    case 0: return "prev.rgb";
    case 1: return "vec3i(prev.a)";
    case 2: return "r0.rgb";
    case 3: return "vec3i(r0.a)";
    case 4: return "r1.rgb";
    case 5: return "vec3i(r1.a)";
    case 6: return "r2.rgb";
    case 7: return "vec3i(r2.a)";
    case 8: return "tex.rgb";
    case 9: return "vec3i(tex.a)";
    case 10: return "ras.rgb";
    case 11: return "vec3i(ras.a)";
    case 12: return "vec3i(255)";
    case 13: return "vec3i(128)";
    case 14: return "kc";
    default: return "vec3i(0)";
  }
}

std::string alpha_arg(u32 arg) {
  switch (arg) {
    case 0: return "prev.a";
    case 1: return "r0.a";
    case 2: return "r1.a";
    case 3: return "r2.a";
    case 4: return "tex.a";
    case 5: return "ras.a";
    case 6: return "ka";
    default: return "0";
  }
}

const char* kBias[4] = {"0", "128", "-128", "0"};

}  // namespace

std::string generate_wgsl(const PipelineConfig& c) {
  std::string s = kCommon;
  s += "\n@fragment fn fs_main(in: VOut) -> @location(0) vec4f {\n";
  s += "  var prev = u.tev_regs[0];\n  var r0 = u.tev_regs[1];\n  var r1 = u.tev_regs[2];\n  var r2 = u.tev_regs[3];\n";
  const int n = c.num_stages < 1 ? 1 : c.num_stages > 16 ? 16 : c.num_stages;
  // Indirect texturing: when any stage uses it, every stage's coordinate goes
  // through the hardware's fixed-point path (1/128 texel, 24-bit wrap).
  bool indirect = false;
  for (int i = 0; i < n; ++i) indirect = indirect || c.stages[i].ind_cmd != 0;
  const int nind = c.num_ind > 4 ? 4 : c.num_ind;
  if (indirect) {
    s += "  var tevcoord = vec2i(0);\n  var alphabump = 0;\n";
    for (int k = 0; k < nind; ++k) {
      // The indirect texture's (a, b, g) as (s, t, u), sampled at its coordinate scaled down.
      const u32 ss = bits(c.ind_scale[k], 0, 4), st = bits(c.ind_scale[k], 4, 4);
      s += str("  let ic%d = fixuv(in.t%u, %uu);\n", k, c.iref_coord[k], c.iref_coord[k]);
      s += str("  let ind%d = vec3i(round(textureSample(tex%u, samp%u, fixst(vec2i(ic%d.x >> %uu, ic%d.y >> %uu), %uu)).abg "
               "* 255.0));\n",
               k, c.iref_map[k], c.iref_map[k], k, ss, k, st, c.iref_map[k]);
    }
  }
  u32 last_color_dest = 0, last_alpha_dest = 0;
  for (int i = 0; i < n; ++i) {
    const TevStage& st = c.stages[i];
    const u32 ce = st.color_env, ae = st.alpha_env;
    s += str("  // stage %d\n  {\n", i);
    if (indirect) {
      const u32 ic = st.ind_cmd;
      s += str("    let fp = fixuv(in.t%u, %uu);\n", st.texcoord, st.texcoord);
      if (ic == 0) {
        s += "    tevcoord = fp;\n";
      } else {
        const u32 bt = bits(ic, 0, 2), fmt = bits(ic, 2, 2), bias = bits(ic, 4, 3), bs = bits(ic, 7, 2);
        const u32 mid = bits(ic, 9, 4), sw = bits(ic, 13, 3), tw = bits(ic, 16, 3), fb = bits(ic, 20, 1);
        static const char* kMask[4] = {"255", "31", "15", "7"};
        static const char* kBumpMask[4] = {"248", "224", "240", "248"};
        if (static_cast<int>(bt) < nind) s += str("    var crd = ind%u & vec3i(%s);\n", bt, kMask[fmt]);
        else s += "    var crd = vec3i(0);\n";
        const char* b = fmt == 0 ? "-128" : "1";
        if (bias & 1) s += str("    crd.x += %s;\n", b);
        if (bias & 2) s += str("    crd.y += %s;\n", b);
        if (bias & 4) s += str("    crd.z += %s;\n", b);
        if (bs && static_cast<int>(bt) < nind)
          s += str("    alphabump = ind%u.%c & %s;\n", bt, "xyz"[bs - 1], kBumpMask[fmt]);
        if (mid >= 1 && mid <= 3) {
          const u32 m = 2 * (mid - 1);
          s += str("    let tr = indshift(vec2i(dot(u.ind_mtx[%u].xyz, crd), dot(u.ind_mtx[%u].xyz, crd)) >> vec2u(3u), "
                   "u.ind_mtx[%u].w);\n",
                   m, m + 1, m);
        } else if (mid >= 5 && mid <= 7) {
          s += str("    let tr = indshift((fp * crd.xx) >> vec2u(8u), u.ind_mtx[%u].w);\n", 2 * (mid - 5));
        } else if (mid >= 9 && mid <= 11) {
          s += str("    let tr = indshift((fp * crd.yy) >> vec2u(8u), u.ind_mtx[%u].w);\n", 2 * (mid - 9));
        } else {
          s += "    let tr = vec2i(0);\n";
        }
        auto wrap = [&](u32 w, char comp) -> std::string {
          if (w == 0) return str("fp.%c", comp);
          if (w >= 6) return "0";
          return str("(fp.%c & %d)", comp, ((256 >> (w - 1)) << 7) - 1);
        };
        s += "    let wrapped = vec2i(" + wrap(sw, 'x') + ", " + wrap(tw, 'y') + ");\n";
        if (fb) s += "    tevcoord = tevcoord + wrapped + tr;\n";
        else s += "    tevcoord = wrapped + tr;\n";
        s += "    tevcoord = (tevcoord << vec2u(8u)) >> vec2u(8u);\n";
      }
    }
    if (st.tex_enable) {
      if (indirect)
        s += str("    let tex = to8(textureSample(tex%u, samp%u, fixst(tevcoord, %uu)))%s;\n", st.texmap, st.texmap,
                 st.texmap, swizzle(c.swap[bits(ae, 2, 2)]).c_str());
      else
        s += str("    let tex = to8(textureSample(tex%u, samp%u, tc(in.t%u, %uu, %uu)))%s;\n", st.texmap, st.texmap,
                 st.texcoord, st.texcoord, st.texmap, swizzle(c.swap[bits(ae, 2, 2)]).c_str());
    } else {
      s += "    let tex = vec4i(0);\n";
    }
    if (st.ras_chan == 0 || st.ras_chan == 1) {
      s += str("    let ras = to8(in.c%u)%s;\n", st.ras_chan, swizzle(c.swap[bits(ae, 0, 2)]).c_str());
    } else if (indirect && st.ras_chan == 5) {
      s += "    let ras = vec4i(alphabump);\n";
    } else if (indirect && st.ras_chan == 6) {
      s += "    let ras = vec4i(alphabump | (alphabump >> 5u));\n";
    } else {
      s += "    let ras = vec4i(0);\n";
    }
    s += "    let kc = " + konst_color(st.kcsel) + ";\n";
    s += "    let ka = i32(" + konst_alpha(st.kasel) + ");\n";
    // Color operation.
    s += "    let ca = " + color_arg(bits(ce, 12, 4)) + " & vec3i(255);\n";
    s += "    let cb = " + color_arg(bits(ce, 8, 4)) + " & vec3i(255);\n";
    s += "    let cc = " + color_arg(bits(ce, 4, 4)) + " & vec3i(255);\n";
    s += "    let cd = " + color_arg(bits(ce, 0, 4)) + ";\n";
    const bool cclamp = bits(ce, 19, 1);
    const char* cmin = cclamp ? "vec3i(0)" : "vec3i(-1024)";
    const char* cmax = cclamp ? "vec3i(255)" : "vec3i(1023)";
    if (bits(ce, 16, 2) != 3) {
      s += str("    let co = tev3(ca, cb, cc, cd, %s, %s, %uu, %s);\n", bits(ce, 18, 1) ? "true" : "false",
               kBias[bits(ce, 16, 2)], bits(ce, 20, 2), cclamp ? "true" : "false");
    } else {
      const u32 mode = bits(ce, 20, 2) << 1 | bits(ce, 18, 1);
      std::string cond;
      switch (mode) {
        case 0: cond = "vec3<bool>(ca.r > cb.r)"; break;
        case 1: cond = "vec3<bool>(ca.r == cb.r)"; break;
        case 2: cond = "vec3<bool>(pack16(ca) > pack16(cb))"; break;
        case 3: cond = "vec3<bool>(pack16(ca) == pack16(cb))"; break;
        case 4: cond = "vec3<bool>(pack24(ca) > pack24(cb))"; break;
        case 5: cond = "vec3<bool>(pack24(ca) == pack24(cb))"; break;
        case 6: cond = "ca > cb"; break;
        default: cond = "ca == cb"; break;
      }
      s += str("    let co = clamp(cd + select(vec3i(0), cc, %s), %s, %s);\n", cond.c_str(), cmin, cmax);
    }
    // Alpha operation.
    s += "    let aa = " + alpha_arg(bits(ae, 13, 3)) + " & 255;\n";
    s += "    let ab = " + alpha_arg(bits(ae, 10, 3)) + " & 255;\n";
    s += "    let ac = " + alpha_arg(bits(ae, 7, 3)) + " & 255;\n";
    s += "    let ad = " + alpha_arg(bits(ae, 4, 3)) + ";\n";
    const bool aclamp = bits(ae, 19, 1);
    if (bits(ae, 16, 2) != 3) {
      s += str("    let ao = tev1(aa, ab, ac, ad, %s, %s, %uu, %s);\n", bits(ae, 18, 1) ? "true" : "false",
               kBias[bits(ae, 16, 2)], bits(ae, 20, 2), aclamp ? "true" : "false");
    } else {
      const u32 mode = bits(ae, 20, 2) << 1 | bits(ae, 18, 1);
      std::string cond;
      switch (mode) {  // modes 0-5 compare the color operands' channels
        case 0: cond = "ca.r > cb.r"; break;
        case 1: cond = "ca.r == cb.r"; break;
        case 2: cond = "pack16(ca) > pack16(cb)"; break;
        case 3: cond = "pack16(ca) == pack16(cb)"; break;
        case 4: cond = "pack24(ca) > pack24(cb)"; break;
        case 5: cond = "pack24(ca) == pack24(cb)"; break;
        case 6: cond = "aa > ab"; break;
        default: cond = "aa == ab"; break;
      }
      s += str("    let ao = clamp(ad + select(0, ac, %s), %s, %s);\n", cond.c_str(), aclamp ? "0" : "-1024",
               aclamp ? "255" : "1023");
    }
    last_color_dest = bits(ce, 22, 2);
    last_alpha_dest = bits(ae, 22, 2);
    s += str("    %s = vec4i(co, %s.a);\n", kRegNames[last_color_dest], kRegNames[last_color_dest]);
    s += str("    %s.a = ao;\n", kRegNames[last_alpha_dest]);
    s += "  }\n";
  }
  s += str("  let outc = clamp(vec4i(%s.rgb, %s.a), vec4i(0), vec4i(255));\n", kRegNames[last_color_dest],
           kRegNames[last_alpha_dest]);
  // Alpha test.
  const bool trivially_passes = (c.alpha_comp0 == 7 && c.alpha_comp1 == 7 && c.alpha_logic <= 1) ||
                                (c.alpha_logic == 1 && (c.alpha_comp0 == 7 || c.alpha_comp1 == 7));
  if (!trivially_passes) {
    s += str("  let a0 = acmp(%uu, outc.a, u.alpha_ref.x);\n  let a1 = acmp(%uu, outc.a, u.alpha_ref.y);\n",
             c.alpha_comp0, c.alpha_comp1);
    const char* logic[4] = {"a0 && a1", "a0 || a1", "a0 != a1", "a0 == a1"};
    s += str("  if (!(%s)) { discard; }\n", logic[c.alpha_logic & 3]);
  }
  // Logic ops without blending: the common ones.
  if (c.logic_enable && !c.blend_enable) {
    switch (c.logic_op) {
      case 0: s += "  return vec4f(0.0);\n}\n"; return s;          // clear
      case 12: s += "  return vec4f(vec4i(255) - outc) / 255.0;\n}\n"; return s;  // inverted copy
      case 15: s += "  return vec4f(1.0);\n}\n"; return s;         // set
      default: break;
    }
  }
  s += "  return vec4f(outc) / 255.0;\n}\n";
  return s;
}

}  // namespace mvp::gfx
