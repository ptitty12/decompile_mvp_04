#include "gfx/gp_reads.h"

#include <algorithm>

#include "gfx/texture_decode.h"

namespace mvp::gfx {

namespace {

inline u32 be32_at(const u8* p) { return u32(p[0]) << 24 | u32(p[1]) << 16 | u32(p[2]) << 8 | p[3]; }

// As gx_processor.cpp: bytes per component (u8, s8, u16, s16, f32) and per color.
inline u32 comp_size(u32 fmt) { return fmt <= 1 ? 1 : fmt <= 3 ? 2 : 4; }
inline u32 color_size(u32 fmt) {
  switch (fmt) {
    case 0: case 3: return 2;  // RGB565, RGBA4444
    case 1: case 4: return 3;  // RGB888, RGBA6666
    default: return 4;
  }
}
// Texture coordinate count bit and format position for coordinate k in VAT A/B/C.
constexpr int kTexVat[8][2] = {{0, 21}, {1, 0}, {1, 9}, {1, 18}, {1, 27}, {2, 5}, {2, 14}, {2, 23}};

}  // namespace

void GpReads::range(u32 addr, u32 size, ReadKind kind) {
  if (!size) return;
  ++stats_.ranges;
  mark_(addr & 0x01FFFFFFu, size, kind);
}

void GpReads::command(const u8* c, std::size_t len) {
  const u8 op = c[0];
  switch (op) {
    case cmd::kLoadCp:
      if (len >= 6) load_cp(c[1], be32_at(c + 2));
      return;
    case cmd::kLoadIndxA: case cmd::kLoadIndxB: case cmd::kLoadIndxC: case cmd::kLoadIndxD: {
      if (len < 5) return;
      const int array = 12 + ((op - cmd::kLoadIndxA) >> 3);
      const u32 v = be32_at(c + 1);
      range(array_base_[array] + (v >> 16) * array_stride_[array], 4 * (bits(v, 12, 4) + 1), ReadKind::kXf);
      return;
    }
    case cmd::kLoadBp:
      if (len >= 5) load_bp(be32_at(c + 1));
      return;
    default:
      break;
  }
  if (op >= 0x80 && op < 0xC0 && len >= 3) primitive(op, c + 3, u32(c[1]) << 8 | c[2]);
}

void GpReads::load_cp(u8 reg, u32 v) {
  if (reg == cp::kVcdLo || reg == cp::kVcdHi || (reg & 0xF8) == cp::kVatA || (reg & 0xF8) == cp::kVatB ||
      (reg & 0xF8) == cp::kVatC)
    for (Layout& l : layouts_) l.valid = false;  // Q4: the formats' layouts
  if (reg == cp::kVcdLo) vcd_lo_ = v;
  else if (reg == cp::kVcdHi) vcd_hi_ = v;
  else if ((reg & 0xF8) == cp::kVatA) vat_a_[reg & 7] = v;
  else if ((reg & 0xF8) == cp::kVatB) vat_b_[reg & 7] = v;
  else if ((reg & 0xF8) == cp::kVatC) vat_c_[reg & 7] = v;
  else if ((reg & 0xF0) == cp::kArrayBase) array_base_[reg & 15] = v & 0x03FFFFFFu;
  else if ((reg & 0xF0) == cp::kArrayStride) array_stride_[reg & 15] = v & 0xFF;
}

void GpReads::load_bp(u32 value) {
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
  // What textures() reads: the stage counts, the stages' and the indirect
  // stages' maps, the maps' registers (and seen_, below).
  if (reg == bp::kGenMode || (reg >= bp::kIref && reg <= bp::kTref + 7) || (reg >= bp::kTexMode0 && reg < 0xC0))
    tex_dirty_ = true;
  switch (reg) {
    case bp::kTriggerCopy: {
      if (bits(v, 14, 1)) return;  // to the XFB: the renderer keeps no hash of that memory
      // Renderer::copy_to_texture hashes what a texture of the copy's size and format covers.
      u32 w = bits(bp_[bp::kEfbWH], 0, 10) + 1, h = bits(bp_[bp::kEfbWH], 10, 10) + 1;
      if (bits(v, 9, 1)) {
        w = std::max(1u, w / 2);
        h = std::max(1u, h / 2);
      }
      const u32 fmt = bits(v, 3, 4);
      const u8 tex_format = static_cast<u8>((fmt >> 1) | ((fmt & 1) << 3));
      const u8 sample = tex_format <= 6 ? tex_format : 1;  // kTexI8
      range((bp_[bp::kXfbAddr] & 0xFFFFFF) << 5, texture_level_size(sample, w, h), ReadKind::kCopy);
      return;
    }
    case bp::kLoadTlut1:
      range((bp_[bp::kLoadTlut0] & 0x1FFFFF) << 5, bits(v, 10, 11) * 32, ReadKind::kTlut);
      seen_.clear();  // the palette is part of the renderer's texture key
      tex_dirty_ = true;
      return;
    case bp::kPreloadMode:
      if (v)
        range((bp_[bp::kPreloadAddr] & 0xFFFFFF) << 5, bits(v, 0, 15) * (bits(v, 15, 2) == 3 ? 64u : 32u),
              ReadKind::kPreload);
      return;
    case bp::kTexInvalidate:
      seen_.clear();
      tex_dirty_ = true;
      return;
    default:
      return;
  }
}

// The vertex layout of format `fmt`: where each indexed attribute's index is,
// and what an element of its array is (as GxProcessor::vertex_format /
// load_vertex read it). Q4: kept until the VCD or a VAT changes.
const GpReads::Layout& GpReads::layout(int fmt) {
  Layout& layout = layouts_[static_cast<std::size_t>(fmt)];
  if (layout.valid) return layout;
  const u32 a = vat_a_[fmt], b = vat_b_[fmt], c = vat_c_[fmt];
  Indexed* ix = layout.ix;
  u32 nix = 0;
  u32 at = 0;
  for (int k = 0; k < 9; ++k) at += bits(vcd_lo_, k, 1);
  auto attr = [&](u32 type, u32 array, u32 direct, u32 elem, u32 n) {
    if (type == 1) at += direct;
    else if (type >= 2) {
      const u32 is = type == 2 ? 1 : 2;
      ix[nix++] = {at, is, array, elem, n};
      at += is * n;
    }
  };
  {
    const u32 cs = comp_size(bits(a, 1, 3)), size = (bits(a, 0, 1) ? 3 : 2) * cs;
    attr(bits(vcd_lo_, 9, 2), 0, size, size, 1);
  }
  {
    const u32 type = bits(vcd_lo_, 11, 2), cs = comp_size(bits(a, 10, 3));
    const bool nbt = bits(a, 9, 1) != 0, nbt3 = type != 1 && nbt && bits(a, 31, 1);
    attr(type, 1, (nbt ? 9 : 3) * cs, nbt3 ? 3 * cs : (nbt ? 9 : 3) * cs, nbt3 ? 3 : 1);
  }
  for (int k = 0; k < 2; ++k) {
    const u32 cs = color_size(bits(a, 14 + 4 * k, 3));
    attr(bits(vcd_lo_, 13 + 2 * k, 2), 2 + k, cs, cs, 1);
  }
  for (int k = 0; k < 8; ++k) {
    const u32 reg = kTexVat[k][0] == 0 ? a : kTexVat[k][0] == 1 ? b : c;
    const int p = kTexVat[k][1];
    const u32 size = (bits(reg, p, 1) ? 2 : 1) * comp_size(bits(reg, p + 1, 3));
    attr(bits(vcd_hi_, 2 * k, 2), 4 + k, size, size, 1);
  }
  layout.vsize = at;
  layout.nix = nix;
  layout.valid = true;
  return layout;
}

void GpReads::primitive(u8 op, const u8* data, u32 count) {
  ++stats_.primitives;
  if (tex_dirty_) textures();
  if (!count) return;
  const Layout& layout = this->layout(op & 7);
  if (!layout.nix) return;
  ++stats_.indexed;
  const std::size_t vsize = layout.vsize;
  for (u32 k = 0; k < layout.nix; ++k) {  // each index of each vertex (attribute by attribute: the loops stay simple)
    const Indexed& x = layout.ix[k];
    u32 lo = ~0u, hi = 0;
    for (u32 j = 0; j < x.n; ++j) {
      const u8* q = data + x.at + j * x.isize;
      if (x.isize == 1) {
        for (u32 v = 0; v < count; ++v, q += vsize) {
          lo = std::min<u32>(lo, q[0]);
          hi = std::max<u32>(hi, q[0]);
        }
      } else {
        for (u32 v = 0; v < count; ++v, q += vsize) {
          const u32 i = u32(q[0]) << 8 | q[1];
          lo = std::min(lo, i);
          hi = std::max(hi, i);
        }
      }
    }
    vertex_range(x.array, lo, hi, x.elem);
  }
}

// Q4: the elements [lo, hi] of an array, unless this epoch has reported them
// already; only what is new when it reported some of them (a superset is fine:
// a mark only makes a write wait).
void GpReads::vertex_range(u32 array, u32 lo, u32 hi, u32 elem) {
  const u32 base = array_base_[array], stride = array_stride_[array];
  Reported& r = reported_[array];
  if (once_ && r.epoch == epoch_ && r.gen == gen_ && r.base == base && r.stride == stride && r.elem == elem &&
      lo <= r.hi + 1 && hi + 1 >= r.lo) {  // overlaps or adjoins what this epoch reported
    if (lo >= r.lo && hi <= r.hi) {
      ++stats_.skipped;
      return;
    }
    if (lo < r.lo) range(base + lo * stride, (r.lo - 1 - lo) * stride + elem, ReadKind::kVertex);
    if (hi > r.hi) range(base + (r.hi + 1) * stride, (hi - r.hi - 1) * stride + elem, ReadKind::kVertex);
    r.lo = std::min(lo, r.lo);
    r.hi = std::max(hi, r.hi);
    return;
  }
  range(base + lo * stride, (hi - lo) * stride + elem, ReadKind::kVertex);
  r = {epoch_, gen_, base, stride, elem, lo, hi};
}

// The textures the next draws sample, as GxProcessor::snapshot finds them: the
// maps of the TEV stages that sample one, and of the indirect stages.
void GpReads::textures() {
  tex_dirty_ = false;
  const u32 gen = bp_[bp::kGenMode];
  const u32 stages = bits(gen, 10, 4) + 1, ind = bits(gen, 16, 3);
  u32 used = 0;
  for (u32 s = 0; s < stages; ++s) {
    const u32 tref = bp_[bp::kTref + s / 2];
    const int sh = (s & 1) ? 12 : 0;
    if (bits(tref, sh + 6, 1)) used |= 1u << bits(tref, sh, 3);
  }
  for (u32 s = 0; s < ind && s < 4; ++s) used |= 1u << bits(bp_[bp::kIref], 6 * s, 3);
  for (int m = 0; m < 8; ++m) {
    if (!(used & (1u << m))) continue;
    if (bits(bp_[bp::tex_reg(bp::kTexImage1, m)], 21, 1)) continue;  // preloaded: TMEM, not memory
    const u32 img0 = bp_[bp::tex_reg(bp::kTexImage0, m)];
    const u32 w = bits(img0, 0, 10) + 1, h = bits(img0, 10, 10) + 1, format = bits(img0, 20, 4);
    if (!texture_format_known(static_cast<u8>(format))) continue;
    const u32 addr = (bp_[bp::tex_reg(bp::kTexImage3, m)] & 0xFFFFFF) << 5;
    const u32 mode0 = bp_[bp::tex_reg(bp::kTexMode0, m)], mode1 = bp_[bp::tex_reg(bp::kTexMode1, m)];
    u32 levels = 1;
    if (bits(mode0, 5, 2) != 0) {  // mipmapped: as snapshot()
      u32 max_levels = 1;
      for (u32 s = std::max(w, h); s > 1; s >>= 1) ++max_levels;
      levels = std::clamp<u32>(static_cast<u32>(static_cast<float>(bits(mode1, 8, 8)) / 16.0f) + 1, 1, max_levels);
    }
    const u32 tlut = bp_[bp::tex_reg(bp::kTexTlut, m)];
    // The renderer's cache key: address, format, size, levels, palette (offset and format).
    const std::uint64_t key = (std::uint64_t(addr) << 32) ^ (std::uint64_t(format) << 28) ^ (std::uint64_t(w) << 18) ^
                              (std::uint64_t(h) << 8) ^ (std::uint64_t(levels) << 4) ^
                              (std::uint64_t(tlut & 0xFFF) << 40);
    if (!seen_.insert(key).second) continue;
    ++stats_.textures;
    range(addr, texture_size(static_cast<u8>(format), w, h, levels), ReadKind::kTexture);
  }
}

}  // namespace mvp::gfx
