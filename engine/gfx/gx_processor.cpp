#include "gfx/gx_processor.h"

#include <algorithm>
#include <bit>
#include <cmath>
#include <cstring>

namespace mvp::gfx {

namespace {

u32 be32_at(const u8* p) { return u32(p[0]) << 24 | u32(p[1]) << 16 | u32(p[2]) << 8 | p[3]; }
u16 be16_at(const u8* p) { return static_cast<u16>(p[0] << 8 | p[1]); }

std::int32_t sext11(u32 v) { return static_cast<std::int32_t>(v << 21) >> 21; }

u32 comp_size(u32 fmt) {
  switch (fmt) {
    case kU8: case kS8: return 1;
    case kU16: case kS16: return 2;
    default: return 4;
  }
}

u32 color_size(u32 fmt) {
  switch (fmt) {
    case kRgb565: case kRgba4444: return 2;
    case kRgb888: case kRgba6666: return 3;
    default: return 4;
  }
}

u32 index_size(u32 type) { return type == 2 ? 1u : type == 3 ? 2u : 0u; }

float read_comp(const u8* p, u32 fmt, float scale) {
  switch (fmt) {
    case kU8: return static_cast<float>(p[0]) * scale;
    case kS8: return static_cast<float>(static_cast<std::int8_t>(p[0])) * scale;
    case kU16: return static_cast<float>(be16_at(p)) * scale;
    case kS16: return static_cast<float>(static_cast<std::int16_t>(be16_at(p))) * scale;
    default: return std::bit_cast<float>(be32_at(p));
  }
}

void read_color(const u8* p, u32 fmt, float out[4]) {
  u32 r = 0, g = 0, b = 0, a = 255;
  switch (fmt) {
    case kRgb565: {
      u32 v = be16_at(p);
      r = (v >> 11) & 31; g = (v >> 5) & 63; b = v & 31;
      r = (r << 3) | (r >> 2); g = (g << 2) | (g >> 4); b = (b << 3) | (b >> 2);
      break;
    }
    case kRgb888: case kRgb888x:
      r = p[0]; g = p[1]; b = p[2];
      break;
    case kRgba4444: {
      u32 v = be16_at(p);
      r = ((v >> 12) & 15) * 17; g = ((v >> 8) & 15) * 17; b = ((v >> 4) & 15) * 17; a = (v & 15) * 17;
      break;
    }
    case kRgba6666: {
      u32 v = u32(p[0]) << 16 | u32(p[1]) << 8 | p[2];
      r = (v >> 18) & 63; g = (v >> 12) & 63; b = (v >> 6) & 63; a = v & 63;
      r = (r << 2) | (r >> 4); g = (g << 2) | (g >> 4); b = (b << 2) | (b >> 4); a = (a << 2) | (a >> 4);
      break;
    }
    default:
      r = p[0]; g = p[1]; b = p[2]; a = p[3];
      break;
  }
  out[0] = static_cast<float>(r) / 255.0f;
  out[1] = static_cast<float>(g) / 255.0f;
  out[2] = static_cast<float>(b) / 255.0f;
  out[3] = static_cast<float>(a) / 255.0f;
}

void unpack_rgba8(u32 v, float out[4]) {
  out[0] = static_cast<float>(v >> 24) / 255.0f;
  out[1] = static_cast<float>((v >> 16) & 0xFF) / 255.0f;
  out[2] = static_cast<float>((v >> 8) & 0xFF) / 255.0f;
  out[3] = static_cast<float>(v & 0xFF) / 255.0f;
}

// Texture coordinate count bit and format position for coordinate k in VAT A/B/C.
struct TexVatField {
  int reg, at;
};
constexpr TexVatField kTexVat[8] = {{0, 21}, {1, 0}, {1, 9}, {1, 18}, {1, 27}, {2, 5}, {2, 14}, {2, 23}};

float dot3(const float* a, const float* b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }

void normalize3(float* v) {
  float l = std::sqrt(dot3(v, v));
  if (l > 0) {
    v[0] /= l;
    v[1] /= l;
    v[2] /= l;
  }
}

}  // namespace

void GxProcessor::reset() {
  bp_.fill(0);
  bp_mask_ = 0xFFFFFF;
  vcd_lo_ = vcd_hi_ = 0;
  vat_a_.fill(0);
  vat_b_.fill(0);
  vat_c_.fill(0);
  array_base_.fill(0);
  array_stride_.fill(0);
  matidx_a_ = matidx_b_ = 0;
  xf_mem_.fill(0);
  xf_regs_.fill(0);
  std::memset(tev_regs_, 0, sizeof tev_regs_);
  std::memset(konst_, 0, sizeof konst_);
  tlut_.assign(512 * 1024, 0);
  stats_ = {};
  // Power-on state that matters before the game's GXInit: one TEV stage,
  // scissor and alpha compare open.
  bp_[bp::kScissorBR] = (342u + kEfbHeight - 1) | (342u + kEfbWidth - 1) << 12;
  bp_[bp::kScissorTL] = 342u | 342u << 12;
  bp_[bp::kScissorOffset] = 171u | 171u << 10;
  bp_[bp::kAlphaCompare] = 7u << 16 | 7u << 19;
}

u32 GxProcessor::xf_word(u32 addr) const {
  if (addr < xf::kMemSize) return xf_mem_[addr];
  if (addr >= xf::kRegBase && addr < xf::kRegBase + xf::kRegCount) return xf_regs_[addr - xf::kRegBase];
  return 0;
}

float GxProcessor::xf_float(u32 addr) const { return std::bit_cast<float>(xf_word(addr)); }

const u8* GxProcessor::phys(u32 addr, u32 len) const {
  addr &= 0x01FFFFFFu;
  if (!mem_ || addr > mem_size_ || len > mem_size_ - addr) return nullptr;
  return mem_ + addr;
}

void GxProcessor::command(const u8* c, std::size_t len) {
  ++stats_.commands;
  const u8 op = c[0];
  switch (op) {
    case cmd::kNop:
    case cmd::kInvalVtx:
      return;
    case cmd::kLoadCp:
      if (len >= 6) load_cp(c[1], be32_at(c + 2));
      return;
    case cmd::kLoadXf: {
      if (len < 5) return;
      u32 w = be32_at(c + 1);
      u32 count = (w >> 16) + 1;
      if (len < 5 + 4 * static_cast<std::size_t>(count)) return;
      load_xf(w & 0xFFFF, count, c + 5);
      return;
    }
    case cmd::kLoadIndxA: case cmd::kLoadIndxB: case cmd::kLoadIndxC: case cmd::kLoadIndxD:
      if (len >= 5) load_xf_indexed(12 + ((op - cmd::kLoadIndxA) >> 3), be32_at(c + 1));
      return;
    case cmd::kLoadBp:
      if (len >= 5) load_bp(be32_at(c + 1));
      return;
    default:
      break;
  }
  if (op >= 0x80 && op < 0xC0 && len >= 3) {
    u32 count = u32(c[1]) << 8 | c[2];
    primitive(op, c + 3, count);
    return;
  }
  ++stats_.unknown;
}

void GxProcessor::load_cp(u8 reg, u32 v) {
  if (reg == cp::kMatIndexA) matidx_a_ = v;
  else if (reg == cp::kMatIndexB) matidx_b_ = v;
  else if (reg == cp::kVcdLo) vcd_lo_ = v;
  else if (reg == cp::kVcdHi) vcd_hi_ = v;
  else if ((reg & 0xF8) == cp::kVatA) vat_a_[reg & 7] = v;
  else if ((reg & 0xF8) == cp::kVatB) vat_b_[reg & 7] = v;
  else if ((reg & 0xF8) == cp::kVatC) vat_c_[reg & 7] = v;
  else if ((reg & 0xF0) == cp::kArrayBase) array_base_[reg & 15] = v & 0x03FFFFFFu;
  else if ((reg & 0xF0) == cp::kArrayStride) array_stride_[reg & 15] = v & 0xFF;
}

void GxProcessor::load_xf(u32 addr, u32 count, const u8* data) {
  for (u32 k = 0; k < count; ++k) {
    u32 a = addr + k;
    u32 v = be32_at(data + 4 * k);
    if (a < xf::kMemSize) xf_mem_[a] = v;
    else if (a >= xf::kRegBase && a < xf::kRegBase + xf::kRegCount) xf_regs_[a - xf::kRegBase] = v;
  }
}

void GxProcessor::load_xf_indexed(int array, u32 v) {
  ++stats_.xf_indexed;
  u32 addr = v & 0xFFF;
  u32 count = ((v >> 12) & 0xF) + 1;
  u32 index = v >> 16;
  const u8* p = phys(array_base_[array] + index * array_stride_[array], 4 * count);
  if (!p) return;
  for (u32 k = 0; k < count; ++k)
    if (addr + k < xf::kMemSize) xf_mem_[addr + k] = be32_at(p + 4 * k);
}

void GxProcessor::load_bp(u32 value) {
  const u8 reg = static_cast<u8>(value >> 24);
  u32 v = value & 0xFFFFFF;
  if (reg == bp::kMask) {
    bp_mask_ = v;
    bp_[reg] = v;
    return;
  }
  v = (bp_[reg] & ~bp_mask_) | (v & bp_mask_);
  bp_mask_ = 0xFFFFFF;
  bp_[reg] = v;
  if (reg >= bp::kTevReg && reg < bp::kTevReg + 8) {
    int r = (reg - bp::kTevReg) >> 1;
    bool konst = (v >> 23) & 1;
    std::int32_t lo = konst ? static_cast<std::int32_t>(v & 0xFF) : sext11(v & 0x7FF);
    std::int32_t hi = konst ? static_cast<std::int32_t>((v >> 12) & 0xFF) : sext11((v >> 12) & 0x7FF);
    std::int32_t(*dst)[4] = konst ? konst_ : tev_regs_;
    if ((reg & 1) == 0) {  // RA
      dst[r][0] = lo;
      dst[r][3] = hi;
    } else {  // BG
      dst[r][2] = lo;
      dst[r][1] = hi;
    }
    return;
  }
  switch (reg) {
    case bp::kTriggerCopy:
      efb_copy();
      break;
    case bp::kLoadTlut1:
      load_tlut();
      break;
    case bp::kTexInvalidate:
      if (backend_) backend_->invalidate_textures();
      break;
    default:
      break;
  }
}

void GxProcessor::load_tlut() {
  ++stats_.tlut_loads;
  u32 src = (bp_[bp::kLoadTlut0] & 0x1FFFFF) << 5;
  u32 v = bp_[bp::kLoadTlut1];
  u32 dst = (v & 0x3FF) << 9;
  u32 bytes = ((v >> 10) & 0x7FF) * 32;
  if (dst >= tlut_.size()) return;
  bytes = std::min<u32>(bytes, static_cast<u32>(tlut_.size()) - dst);
  const u8* p = phys(src, bytes);
  if (p) std::memcpy(tlut_.data() + dst, p, bytes);
}

void GxProcessor::efb_copy() {
  ++stats_.copies;
  const u32 v = bp_[bp::kTriggerCopy];
  EfbCopy c;
  c.copy_value = v;
  c.src_x = bits(bp_[bp::kEfbTL], 0, 10);
  c.src_y = bits(bp_[bp::kEfbTL], 10, 10);
  c.width = bits(bp_[bp::kEfbWH], 0, 10) + 1;
  c.height = bits(bp_[bp::kEfbWH], 10, 10) + 1;
  c.dest = (bp_[bp::kXfbAddr] & 0xFFFFFF) << 5;
  c.dest_stride = bits(bp_[bp::kMipmapStride], 0, 10);
  c.clamp_top = bits(v, 0, 1);
  c.clamp_bottom = bits(v, 1, 1);
  u32 fmt = bits(v, 3, 4);
  c.tex_format = static_cast<u8>((fmt >> 1) | ((fmt & 1) << 3));
  c.gamma = bits(v, 7, 2);
  c.half_scale = bits(v, 9, 1);
  c.clear = bits(v, 11, 1);
  c.to_xfb = bits(v, 14, 1);
  c.intensity = bits(v, 15, 1);
  u32 ys = bits(bp_[bp::kDispCopyYScale], 0, 9);
  c.y_scale = (bits(v, 10, 1) && ys) ? 256.0f / static_cast<float>(ys) : 1.0f;
  u32 ar = bp_[bp::kClearAR], gb = bp_[bp::kClearGB];
  c.clear_rgba[0] = static_cast<u8>(ar & 0xFF);
  c.clear_rgba[1] = static_cast<u8>((gb >> 8) & 0xFF);
  c.clear_rgba[2] = static_cast<u8>(gb & 0xFF);
  c.clear_rgba[3] = static_cast<u8>((ar >> 8) & 0xFF);
  c.clear_z = bp_[bp::kClearZ] & 0xFFFFFF;
  c.clear_color = bits(bp_[bp::kCMode0], 3, 1);
  c.clear_alpha = bits(bp_[bp::kCMode0], 4, 1);
  c.clear_depth = bits(bp_[bp::kZMode], 4, 1);
  c.pixel_format = static_cast<u8>(bits(bp_[bp::kZCompare], 0, 3));
  if (c.to_xfb) ++stats_.xfb_copies;
  if (backend_) backend_->efb_copy(c);
}

u32 GxProcessor::vertex_size(int fmt) const {
  const u32 a = vat_a_[fmt], b = vat_b_[fmt], c = vat_c_[fmt];
  u32 size = 0;
  for (int k = 0; k < 9; ++k) size += bits(vcd_lo_, k, 1);
  u32 t = bits(vcd_lo_, 9, 2);
  if (t == 1) size += (bits(a, 0, 1) ? 3 : 2) * comp_size(bits(a, 1, 3));
  else size += index_size(t);
  t = bits(vcd_lo_, 11, 2);
  bool nbt = bits(a, 9, 1);
  if (t == 1) size += (nbt ? 9 : 3) * comp_size(bits(a, 10, 3));
  else size += index_size(t) * (nbt && bits(a, 31, 1) ? 3 : 1);
  for (int k = 0; k < 2; ++k) {
    t = bits(vcd_lo_, 13 + 2 * k, 2);
    if (t == 1) size += color_size(bits(a, 14 + 4 * k, 3));
    else size += index_size(t);
  }
  for (int k = 0; k < 8; ++k) {
    t = bits(vcd_hi_, 2 * k, 2);
    u32 reg = kTexVat[k].reg == 0 ? a : kTexVat[k].reg == 1 ? b : c;
    int at = kTexVat[k].at;
    if (t == 1) size += (bits(reg, at, 1) ? 2 : 1) * comp_size(bits(reg, at + 1, 3));
    else size += index_size(t);
  }
  return size;
}

InVertex GxProcessor::load_vertex(int fmt, const u8* p) const {
  const u32 a = vat_a_[fmt], b = vat_b_[fmt], c = vat_c_[fmt];
  InVertex v;
  v.pnmtx = static_cast<u8>(bits(matidx_a_, 0, 6));
  for (int k = 0; k < 8; ++k) {
    u32 src = k < 4 ? matidx_a_ : matidx_b_;
    v.texmtx[k] = static_cast<u8>(bits(src, k < 4 ? 6 + 6 * k : 6 * (k - 4), 6));
  }
  if (bits(vcd_lo_, 0, 1)) v.pnmtx = *p++ & 0x3F;
  for (int k = 0; k < 8; ++k)
    if (bits(vcd_lo_, 1 + k, 1)) v.texmtx[k] = *p++ & 0x3F;

  // Where an attribute's data is: inline, or in its array.
  auto source = [&](u32 type, int array, u32 inline_size) -> const u8* {
    if (type == 1) {
      const u8* q = p;
      p += inline_size;
      return q;
    }
    u32 idx;
    if (type == 2) idx = *p++;
    else {
      idx = be16_at(p);
      p += 2;
    }
    return phys(array_base_[array] + idx * array_stride_[array], inline_size);
  };

  // Position.
  u32 t = bits(vcd_lo_, 9, 2);
  if (t) {
    u32 cnt = bits(a, 0, 1) ? 3 : 2, f = bits(a, 1, 3);
    float scale = 1.0f / static_cast<float>(1u << bits(a, 4, 5));
    const u8* q = source(t, 0, cnt * comp_size(f));
    if (q)
      for (u32 k = 0; k < cnt; ++k) v.pos[k] = read_comp(q + k * comp_size(f), f, scale);
  }
  // Normal, binormal, tangent.
  t = bits(vcd_lo_, 11, 2);
  if (t) {
    bool nbt = bits(a, 9, 1);
    u32 f = bits(a, 10, 3);
    float scale = f == kU8 ? 1.0f / 128 : f == kS8 ? 1.0f / 64 : f == kU16 ? 1.0f / 32768 : 1.0f / 16384;
    u32 vec = 3 * comp_size(f);
    float* dst[3] = {v.nrm, v.bin, v.tan};
    if (t != 1 && nbt && bits(a, 31, 1)) {  // three indices, one per vector
      for (int n = 0; n < 3; ++n) {
        const u8* q = source(t, 1, vec);
        if (q)
          for (u32 k = 0; k < 3; ++k) dst[n][k] = read_comp(q + k * comp_size(f), f, scale);
      }
    } else {
      const u8* q = source(t, 1, (nbt ? 3 : 1) * vec);
      if (q)
        for (int n = 0; n < (nbt ? 3 : 1); ++n)
          for (u32 k = 0; k < 3; ++k) dst[n][k] = read_comp(q + n * vec + k * comp_size(f), f, scale);
    }
  }
  // Colors.
  for (int k = 0; k < 2; ++k) {
    t = bits(vcd_lo_, 13 + 2 * k, 2);
    if (!t) continue;
    u32 f = bits(a, 14 + 4 * k, 3);
    const u8* q = source(t, 2 + k, color_size(f));
    if (q) read_color(q, f, v.color[k]);
  }
  // Texture coordinates.
  for (int k = 0; k < 8; ++k) {
    t = bits(vcd_hi_, 2 * k, 2);
    if (!t) continue;
    u32 reg = kTexVat[k].reg == 0 ? a : kTexVat[k].reg == 1 ? b : c;
    int at = kTexVat[k].at;
    u32 cnt = bits(reg, at, 1) ? 2 : 1, f = bits(reg, at + 1, 3);
    float scale = 1.0f / static_cast<float>(1u << bits(reg, at + 4, 5));
    const u8* q = source(t, 4 + k, cnt * comp_size(f));
    if (q)
      for (u32 n = 0; n < cnt; ++n) v.tex[k][n] = read_comp(q + n * comp_size(f), f, scale);
  }
  return v;
}

OutVertex GxProcessor::transform(const InVertex& v) const {
  OutVertex o{};
  // Position: model-view (3x4 at index * 4), projection, viewport, then the
  // EFB's clip space.
  const u32 pm = (v.pnmtx & 0x3F) * 4u;
  float m[12];
  for (int k = 0; k < 12; ++k) m[k] = xf_float(xf::kPosMtx + ((pm + static_cast<u32>(k)) & 0xFF));
  const float* p = v.pos;
  float view[3];
  for (int r = 0; r < 3; ++r) view[r] = m[4 * r] * p[0] + m[4 * r + 1] * p[1] + m[4 * r + 2] * p[2] + m[4 * r + 3];

  float pr[6];
  for (int k = 0; k < 6; ++k) pr[k] = xf_float(xf::kProjection + static_cast<u32>(k));
  bool ortho = xf_word(xf::kProjection + 6) != 0;
  float cx, cy, cz, cw;
  if (ortho) {
    cx = pr[0] * view[0] + pr[1];
    cy = pr[2] * view[1] + pr[3];
    cz = pr[4] * view[2] + pr[5];
    cw = 1.0f;
  } else {
    cx = pr[0] * view[0] + pr[1] * view[2];
    cy = pr[2] * view[1] + pr[3] * view[2];
    cz = pr[4] * view[2] + pr[5];
    cw = -view[2];
  }
  const float wd = xf_float(xf::kViewport), ht = xf_float(xf::kViewport + 1), zr = xf_float(xf::kViewport + 2);
  const float xo = xf_float(xf::kViewport + 3), yo = xf_float(xf::kViewport + 4), zf = xf_float(xf::kViewport + 5);
  const float ox = static_cast<float>(bits(bp_[bp::kScissorOffset], 0, 10) * 2);
  const float oy = static_cast<float>(bits(bp_[bp::kScissorOffset], 10, 10) * 2);
  const float hw = static_cast<float>(kEfbWidth) / 2, hh = static_cast<float>(kEfbHeight) / 2;
  // Window x = cx / cw * wd + xo - ox; EFB clip x = (window x / hw - 1) * cw.
  o.pos[0] = (cx * wd + cw * (xo - ox)) / hw - cw;
  // Window y grows downwards; the EFB clip space's y grows upwards.
  o.pos[1] = cw - (cy * ht + cw * (yo - oy)) / hh;
  // Depth: window z = cz / cw * zrange + zfar, in 24-bit units.
  o.pos[2] = (cz * zr + cw * zf) / 16777215.0f;
  o.pos[3] = cw;

  // Normal (3x3 at 0x400 + (index & 31) * 3).
  float n[3] = {v.nrm[0], v.nrm[1], v.nrm[2]};
  {
    const u32 nm = xf::kNrmMtx + (v.pnmtx & 31u) * 3u;
    float q[9];
    for (int k = 0; k < 9; ++k) q[k] = xf_float(nm + static_cast<u32>(k));
    float t[3];
    for (int r = 0; r < 3; ++r) t[r] = q[3 * r] * v.nrm[0] + q[3 * r + 1] * v.nrm[1] + q[3 * r + 2] * v.nrm[2];
    n[0] = t[0];
    n[1] = t[1];
    n[2] = t[2];
    normalize3(n);
  }

  // Lighting: color channels 0 and 1, color and alpha separately.
  const u32 nchan = xf_word(xf::kNumColors) & 3;
  for (u32 ch = 0; ch < 2 && ch < nchan; ++ch) {
    for (int is_alpha = 0; is_alpha < 2; ++is_alpha) {
      const u32 ctl = xf_word(xf::kColor0Cntrl + ch + (is_alpha ? 2u : 0u));
      float mat[4], amb[4];
      if (bits(ctl, 0, 1)) std::memcpy(mat, v.color[ch], sizeof mat);
      else unpack_rgba8(xf_word(xf::kMaterial0 + ch), mat);
      float out[4];
      std::memcpy(out, mat, sizeof out);
      if (bits(ctl, 1, 1)) {
        if (bits(ctl, 6, 1)) std::memcpy(amb, v.color[ch], sizeof amb);
        else unpack_rgba8(xf_word(xf::kAmbient0 + ch), amb);
        float acc[4];
        std::memcpy(acc, amb, sizeof acc);
        const u32 mask = bits(ctl, 2, 4) | bits(ctl, 11, 4) << 4;
        const u32 diffuse = bits(ctl, 7, 2), attn_fn = bits(ctl, 9, 2);
        for (u32 l = 0; l < 8; ++l) {
          if (!(mask & (1u << l))) continue;
          const u32 base = xf::kLights + l * 16;
          float lcol[4];
          unpack_rgba8(xf_word(base + 3), lcol);
          float cosatt[3], distatt[3], lpos[3], ldir_l[3];
          for (u32 k = 0; k < 3; ++k) {
            cosatt[k] = xf_float(base + 4 + k);
            distatt[k] = xf_float(base + 7 + k);
            lpos[k] = xf_float(base + 10 + k);
            ldir_l[k] = xf_float(base + 13 + k);
          }
          float ldir[3] = {lpos[0] - view[0], lpos[1] - view[1], lpos[2] - view[2]};
          float attn = 1.0f;
          if (attn_fn == 3) {  // spot
            float dist2 = dot3(ldir, ldir), dist = std::sqrt(dist2);
            if (dist > 0) {
              ldir[0] /= dist;
              ldir[1] /= dist;
              ldir[2] /= dist;
            }
            float c = std::max(0.0f, dot3(ldir, ldir_l));
            float num = std::max(0.0f, cosatt[0] + cosatt[1] * c + cosatt[2] * c * c);
            float den = distatt[0] + distatt[1] * dist + distatt[2] * dist2;
            attn = den != 0 ? num / den : 0.0f;
          } else if (attn_fn == 1) {  // specular
            normalize3(ldir);
            float c = dot3(n, ldir) >= 0 ? std::max(0.0f, dot3(n, ldir_l)) : 0.0f;
            float da[3] = {distatt[0], distatt[1], distatt[2]};
            if (diffuse != 0) normalize3(da);
            float num = std::max(0.0f, cosatt[0] + cosatt[1] * c + cosatt[2] * c * c);
            float den = da[0] + da[1] * c + da[2] * c * c;
            attn = den != 0 ? num / den : 0.0f;
          } else {
            normalize3(ldir);
          }
          float d = 1.0f;
          if (diffuse == 1) d = dot3(ldir, n);
          else if (diffuse == 2) d = std::max(0.0f, dot3(ldir, n));
          for (int k = 0; k < 4; ++k) acc[k] += attn * d * lcol[k];
        }
        for (int k = 0; k < 4; ++k) out[k] = mat[k] * std::clamp(acc[k], 0.0f, 1.0f);
      }
      if (is_alpha) o.color[ch][3] = out[3];
      else {
        o.color[ch][0] = out[0];
        o.color[ch][1] = out[1];
        o.color[ch][2] = out[2];
      }
    }
  }

  // Texture coordinate generation.
  const u32 ngen = xf_word(xf::kNumTexGens) & 15;
  const bool dual = xf_word(xf::kDualTex) & 1;
  for (u32 i = 0; i < ngen && i < 8; ++i) {
    const u32 info = xf_word(xf::kTexGen + i);
    const u32 type = bits(info, 4, 3), row = bits(info, 7, 5);
    float out[3] = {0, 0, 1};
    if (type == 0) {
      float src[4] = {0, 0, 1, 1};
      switch (row) {
        case 0: src[0] = v.pos[0]; src[1] = v.pos[1]; src[2] = v.pos[2]; break;
        case 1: src[0] = v.nrm[0]; src[1] = v.nrm[1]; src[2] = v.nrm[2]; break;
        case 2: src[0] = o.color[0][0]; src[1] = o.color[0][1]; src[2] = o.color[0][2]; break;
        case 3: src[0] = v.tan[0]; src[1] = v.tan[1]; src[2] = v.tan[2]; break;
        case 4: src[0] = v.bin[0]; src[1] = v.bin[1]; src[2] = v.bin[2]; break;
        default:
          if (row >= 5 && row <= 12) {
            src[0] = v.tex[row - 5][0];
            src[1] = v.tex[row - 5][1];
          }
          break;
      }
      if (!bits(info, 2, 1)) src[2] = 1.0f;  // AB11
      const u32 tm = (v.texmtx[i] & 0x3F) * 4u;
      float mtx[12];
      for (int k = 0; k < 12; ++k) mtx[k] = xf_float(xf::kPosMtx + ((tm + static_cast<u32>(k)) & 0xFF));
      bool stq = bits(info, 1, 1);
      for (int r = 0; r < (stq ? 3 : 2); ++r)
        out[r] = mtx[4 * r] * src[0] + mtx[4 * r + 1] * src[1] + mtx[4 * r + 2] * src[2] + mtx[4 * r + 3] * src[3];
    } else if (type == 1) {  // emboss: the source coordinate (the light offset is not modeled yet)
      u32 s = bits(info, 12, 3);
      if (s < i) std::memcpy(out, o.tex[s], sizeof out);
    } else {  // color strgb
      const float* col = o.color[type == 2 ? 0 : 1];
      out[0] = col[0];
      out[1] = col[1];
      out[2] = 1.0f;
    }
    if (dual && type == 0) {
      const u32 post = xf_word(xf::kPostInfo + i);
      if (bits(post, 8, 1)) normalize3(out);
      const u32 pm2 = xf::kPostMtx + (bits(post, 0, 6) * 4u);
      float mtx[12];
      for (int k = 0; k < 12; ++k) mtx[k] = xf_float(pm2 + static_cast<u32>(k));
      float r3[3];
      for (int r = 0; r < 3; ++r)
        r3[r] = mtx[4 * r] * out[0] + mtx[4 * r + 1] * out[1] + mtx[4 * r + 2] * out[2] + mtx[4 * r + 3];
      std::memcpy(out, r3, sizeof out);
    }
    std::memcpy(o.tex[i], out, sizeof out);
  }
  return o;
}

void GxProcessor::snapshot(DrawCall& d) const {
  PipelineConfig& c = d.cfg;
  c = PipelineConfig{};
  std::memset(&c, 0, sizeof c);
  const u32 gen = bp_[bp::kGenMode];
  c.num_texgens = static_cast<u8>(bits(gen, 0, 4));
  c.num_chans = static_cast<u8>(bits(gen, 4, 3));
  c.num_stages = static_cast<u8>(bits(gen, 10, 4) + 1);
  c.cull = static_cast<u8>(bits(gen, 14, 2));
  c.num_ind = static_cast<u8>(bits(gen, 16, 3));
  std::array<bool, 8> map_used{};
  for (int i = 0; i < c.num_stages; ++i) {
    TevStage& s = c.stages[i];
    s.color_env = bp_[bp::kTevColorEnv + 2 * i];
    s.alpha_env = bp_[bp::kTevAlphaEnv + 2 * i];
    s.ind_cmd = bp_[bp::kIndCmd + i];
    const u32 tref = bp_[bp::kTref + i / 2];
    const int sh = (i & 1) ? 12 : 0;
    s.tex_enable = static_cast<u8>(bits(tref, sh + 6, 1));
    s.texmap = static_cast<u8>(bits(tref, sh, 3));
    s.texcoord = static_cast<u8>(bits(tref, sh + 3, 3));
    s.ras_chan = static_cast<u8>(bits(tref, sh + 7, 3));
    if (!s.tex_enable && !s.ind_cmd) s.texmap = s.texcoord = 0;
    if (s.tex_enable) map_used[s.texmap] = true;
    const u32 ksel = bp_[bp::kKsel + i / 2];
    s.kcsel = static_cast<u8>(bits(ksel, (i & 1) ? 14 : 4, 5));
    s.kasel = static_cast<u8>(bits(ksel, (i & 1) ? 19 : 9, 5));
  }
  for (int t = 0; t < 4; ++t) {
    const u32 s0 = bp_[bp::kKsel + 2 * t], s1 = bp_[bp::kKsel + 2 * t + 1];
    c.swap[t][0] = static_cast<u8>(bits(s0, 0, 2));
    c.swap[t][1] = static_cast<u8>(bits(s0, 2, 2));
    c.swap[t][2] = static_cast<u8>(bits(s1, 0, 2));
    c.swap[t][3] = static_cast<u8>(bits(s1, 2, 2));
  }
  const u32 ac = bp_[bp::kAlphaCompare];
  c.alpha_comp0 = static_cast<u8>(bits(ac, 16, 3));
  c.alpha_comp1 = static_cast<u8>(bits(ac, 19, 3));
  c.alpha_logic = static_cast<u8>(bits(ac, 22, 2));
  const u32 cm = bp_[bp::kCMode0];
  c.blend_enable = static_cast<u8>(bits(cm, 0, 1));
  c.logic_enable = static_cast<u8>(bits(cm, 1, 1));
  c.color_update = static_cast<u8>(bits(cm, 3, 1));
  c.alpha_update = static_cast<u8>(bits(cm, 4, 1));
  c.blend_dst = static_cast<u8>(bits(cm, 5, 3));
  c.blend_src = static_cast<u8>(bits(cm, 8, 3));
  c.blend_sub = static_cast<u8>(bits(cm, 11, 1));
  c.logic_op = static_cast<u8>(bits(cm, 12, 4));
  const u32 zm = bp_[bp::kZMode];
  c.z_enable = static_cast<u8>(bits(zm, 0, 1));
  c.z_func = static_cast<u8>(bits(zm, 1, 3));
  c.z_update = static_cast<u8>(bits(zm, 4, 1));
  c.pixel_format = static_cast<u8>(bits(bp_[bp::kZCompare], 0, 3));
  c.fog_type = static_cast<u8>(bits(bp_[bp::kFog3], 21, 3));
  c.fog_proj = static_cast<u8>(bits(bp_[bp::kFog3], 20, 1));
  if (c.num_ind) {
    const u32 iref = bp_[bp::kIref];
    for (int s = 0; s < 4 && s < c.num_ind; ++s) {
      c.iref_map[s] = static_cast<u8>(bits(iref, 6 * s, 3));
      c.iref_coord[s] = static_cast<u8>(bits(iref, 6 * s + 3, 3));
      const u32 sc = bp_[s < 2 ? bp::kIndScale0 : bp::kIndScale1];
      c.ind_scale[s] = static_cast<u8>(bits(sc, (s & 1) * 8, 8));
      map_used[c.iref_map[s]] = true;
    }
  }

  DrawUniforms& u = d.u;
  std::memcpy(u.tev_regs, tev_regs_, sizeof u.tev_regs);
  std::memcpy(u.konst, konst_, sizeof u.konst);
  u.alpha_ref[0] = static_cast<std::int32_t>(bits(ac, 0, 8));
  u.alpha_ref[1] = static_cast<std::int32_t>(bits(ac, 8, 8));
  const u32 cm1 = bp_[bp::kCMode1];
  u.dst_alpha[0] = static_cast<std::int32_t>(bits(cm1, 8, 1));
  u.dst_alpha[1] = static_cast<std::int32_t>(bits(cm1, 0, 8));
  for (int m = 0; m < 3; ++m) {
    u32 r0 = bp_[bp::kIndMtx + 3 * m], r1 = bp_[bp::kIndMtx + 3 * m + 1], r2 = bp_[bp::kIndMtx + 3 * m + 2];
    int scale = static_cast<int>(bits(r0, 22, 2) | bits(r1, 22, 2) << 2 | bits(r2, 22, 2) << 4) - 17;
    float f = std::ldexp(1.0f / 1024.0f, scale);
    // Rows: (ma, mc, me), (mb, md, mf); elements are 11-bit signed.
    u.ind_mtx[m][0] = static_cast<float>(sext11(bits(r0, 0, 11))) * f;
    u.ind_mtx[m][1] = static_cast<float>(sext11(bits(r1, 0, 11))) * f;
    u.ind_mtx[m][2] = static_cast<float>(sext11(bits(r2, 0, 11))) * f;
    u.ind_mtx[m][4] = static_cast<float>(sext11(bits(r0, 11, 11))) * f;
    u.ind_mtx[m][5] = static_cast<float>(sext11(bits(r1, 11, 11))) * f;
    u.ind_mtx[m][6] = static_cast<float>(sext11(bits(r2, 11, 11))) * f;
  }

  for (int m = 0; m < 8; ++m) {
    TextureDesc& t = d.tex[static_cast<std::size_t>(m)];
    t = TextureDesc{};
    const u32 img0 = bp_[bp::tex_reg(bp::kTexImage0, m)];
    t.width = static_cast<u16>(bits(img0, 0, 10) + 1);
    t.height = static_cast<u16>(bits(img0, 10, 10) + 1);
    u.tex_scale[m][2] = t.width;
    u.tex_scale[m][3] = t.height;
    u.tex_scale[m][0] = static_cast<float>(bits(bp_[bp::kSuSSize + 2 * m], 0, 16) + 1);
    u.tex_scale[m][1] = static_cast<float>(bits(bp_[bp::kSuTSize + 2 * m], 0, 16) + 1);
    if (!map_used[static_cast<std::size_t>(m)]) continue;
    t.valid = true;
    t.format = static_cast<u8>(bits(img0, 20, 4));
    t.addr = (bp_[bp::tex_reg(bp::kTexImage3, m)] & 0xFFFFFF) << 5;
    const u32 mode0 = bp_[bp::tex_reg(bp::kTexMode0, m)], mode1 = bp_[bp::tex_reg(bp::kTexMode1, m)];
    t.wrap_s = static_cast<u8>(bits(mode0, 0, 2));
    t.wrap_t = static_cast<u8>(bits(mode0, 2, 2));
    t.mag_linear = static_cast<u8>(bits(mode0, 4, 1));
    t.min_filter = static_cast<u8>(bits(mode0, 5, 3));
    t.lod_bias = static_cast<float>(static_cast<std::int8_t>(bits(mode0, 9, 8))) / 32.0f;
    t.min_lod = static_cast<float>(bits(mode1, 0, 8)) / 16.0f;
    t.max_lod = static_cast<float>(bits(mode1, 8, 8)) / 16.0f;
    t.levels = 1;
    if (bits(t.min_filter, 0, 2) != 0) {
      u32 max_levels = 1;
      for (u32 s = std::max(t.width, t.height); s > 1; s >>= 1) ++max_levels;
      t.levels = static_cast<u8>(std::clamp<u32>(static_cast<u32>(t.max_lod) + 1, 1, max_levels));
    }
    if (t.format == 8 || t.format == 9 || t.format == 10) {
      const u32 tl = bp_[bp::tex_reg(bp::kTexTlut, m)];
      t.tlut_offset = (tl & 0x3FF) << 9;
      t.tlut_format = static_cast<u8>(bits(tl, 10, 2));
      t.tlut_entries = t.format == 8 ? 16 : t.format == 9 ? 256 : 16384;
      u32 room = static_cast<u32>(tlut_.size()) - std::min<u32>(t.tlut_offset, static_cast<u32>(tlut_.size()));
      t.tlut_entries = std::min(t.tlut_entries, room / 2);
      t.tlut = tlut_.data() + std::min<u32>(t.tlut_offset, static_cast<u32>(tlut_.size()));
    }
  }

  // Scissor, in EFB pixels (the offset moves it with the primitives).
  const int ox = static_cast<int>(bits(bp_[bp::kScissorOffset], 0, 10) * 2);
  const int oy = static_cast<int>(bits(bp_[bp::kScissorOffset], 10, 10) * 2);
  int x0 = static_cast<int>(bits(bp_[bp::kScissorTL], 12, 11)) - ox;
  int y0 = static_cast<int>(bits(bp_[bp::kScissorTL], 0, 11)) - oy;
  int x1 = static_cast<int>(bits(bp_[bp::kScissorBR], 12, 11)) - ox + 1;
  int y1 = static_cast<int>(bits(bp_[bp::kScissorBR], 0, 11)) - oy + 1;
  d.scissor[0] = static_cast<u32>(std::clamp(x0, 0, static_cast<int>(kEfbWidth)));
  d.scissor[1] = static_cast<u32>(std::clamp(y0, 0, static_cast<int>(kEfbHeight)));
  d.scissor[2] = static_cast<u32>(std::clamp(x1, static_cast<int>(d.scissor[0]), static_cast<int>(kEfbWidth)));
  d.scissor[3] = static_cast<u32>(std::clamp(y1, static_cast<int>(d.scissor[1]), static_cast<int>(kEfbHeight)));
}

void GxProcessor::primitive(u8 op, const u8* data, u32 count) {
  const int fmt = op & 7;
  const u8 kind = op & 0xF8;
  const u32 vsize = vertex_size(fmt);
  stats_.vertices += count;
  if (count == 0) return;
  std::vector<OutVertex> vs;
  vs.reserve(count);
  for (u32 k = 0; k < count; ++k) vs.push_back(transform(load_vertex(fmt, data + static_cast<std::size_t>(k) * vsize)));

  DrawCall d;
  snapshot(d);
  auto tri = [&](u32 a, u32 b, u32 c) {
    d.verts.push_back(vs[a]);
    d.verts.push_back(vs[b]);
    d.verts.push_back(vs[c]);
  };
  Topology topo = Topology::Triangles;
  switch (kind) {
    case cmd::kQuads: case cmd::kQuads2:
      for (u32 k = 0; k + 3 < count; k += 4) {
        tri(k, k + 1, k + 2);
        tri(k, k + 2, k + 3);
      }
      break;
    case cmd::kTriangles:
      for (u32 k = 0; k + 2 < count; k += 3) tri(k, k + 1, k + 2);
      break;
    case cmd::kTriStrip:
      for (u32 k = 2; k < count; ++k) {
        if (k & 1) tri(k - 1, k - 2, k);
        else tri(k - 2, k - 1, k);
      }
      break;
    case cmd::kTriFan:
      for (u32 k = 2; k < count; ++k) tri(0, k - 1, k);
      break;
    case cmd::kLines:
      topo = Topology::Lines;
      for (u32 k = 0; k + 1 < count; k += 2) {
        d.verts.push_back(vs[k]);
        d.verts.push_back(vs[k + 1]);
      }
      break;
    case cmd::kLineStrip:
      topo = Topology::Lines;
      for (u32 k = 1; k < count; ++k) {
        d.verts.push_back(vs[k - 1]);
        d.verts.push_back(vs[k]);
      }
      break;
    default:  // points
      topo = Topology::Points;
      d.verts = vs;
      break;
  }
  d.cfg.topology = static_cast<u8>(topo);
  if (topo == Topology::Triangles) stats_.triangles += d.verts.size() / 3;
  ++stats_.draws;
  if (backend_ && !d.verts.empty()) backend_->draw(d);
}

}  // namespace mvp::gfx
