#include "gfx/texture_decode.h"

#include <cstring>

namespace mvp::gfx {

namespace {

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;

u16 be16(const u8* p) { return static_cast<u16>(p[0] << 8 | p[1]); }

u8 x4(u32 v) { return static_cast<u8>(v * 17); }
u8 x5(u32 v) { return static_cast<u8>((v << 3) | (v >> 2)); }
u8 x6(u32 v) { return static_cast<u8>((v << 2) | (v >> 4)); }
u8 x3(u32 v) { return static_cast<u8>((v << 5) | (v << 2) | (v >> 1)); }

void rgb565(u16 v, u8* o) {
  o[0] = x5(v >> 11);
  o[1] = x6((v >> 5) & 63);
  o[2] = x5(v & 31);
  o[3] = 255;
}

void rgb5a3(u16 v, u8* o) {
  if (v & 0x8000) {
    o[0] = x5((v >> 10) & 31);
    o[1] = x5((v >> 5) & 31);
    o[2] = x5(v & 31);
    o[3] = 255;
  } else {
    o[0] = x4((v >> 8) & 15);
    o[1] = x4((v >> 4) & 15);
    o[2] = x4(v & 15);
    o[3] = x3((v >> 12) & 7);
  }
}

// CMPR's interpolated colors: 5/8 of a + 3/8 of b.
u8 blend38(u32 a, u32 b) { return static_cast<u8>((a * 5 + b * 3) >> 3); }

}  // namespace

void decode_tlut_entry(u16 v, u8 tlut_format, u8 out[4]) {
  switch (tlut_format) {
    case kTlutIA8:
      out[0] = out[1] = out[2] = static_cast<u8>(v & 0xFF);
      out[3] = static_cast<u8>(v >> 8);
      break;
    case kTlutRGB565:
      rgb565(v, out);
      break;
    default:
      rgb5a3(v, out);
      break;
  }
}

bool texture_format_known(u8 format) {
  switch (format) {
    case kTexI4: case kTexI8: case kTexIA4: case kTexIA8: case kTexRGB565: case kTexRGB5A3: case kTexRGBA8:
    case kTexC4: case kTexC8: case kTexC14X2: case kTexCMPR:
      return true;
    default:
      return false;
  }
}

TexBlock texture_block(u8 format) {
  switch (format) {
    case kTexI4: case kTexC4: case kTexCMPR: return {8, 8, 4};
    case kTexI8: case kTexIA4: case kTexC8: return {8, 4, 8};
    case kTexRGBA8: return {4, 4, 32};
    default: return {4, 4, 16};  // IA8, RGB565, RGB5A3, C14X2
  }
}

u32 texture_level_size(u8 format, u32 w, u32 h) {
  TexBlock b = texture_block(format);
  u32 bw = (w + b.w - 1) / b.w, bh = (h + b.h - 1) / b.h;
  return bw * bh * (b.w * b.h * b.bpp / 8);
}

u32 texture_size(u8 format, u32 w, u32 h, u32 levels) {
  u32 total = 0;
  for (u32 l = 0; l < levels; ++l) {
    total += texture_level_size(format, w, h);
    w = w > 1 ? w / 2 : 1;
    h = h > 1 ? h / 2 : 1;
  }
  return total;
}

void decode_texture(u8 format, u32 w, u32 h, const u8* src, u8* out, const u8* tlut, u8 tlut_format,
                    u32 tlut_entries) {
  const TexBlock b = texture_block(format);
  const u32 bw = (w + b.w - 1) / b.w, bh = (h + b.h - 1) / b.h;
  const u32 block_bytes = b.w * b.h * b.bpp / 8;
  auto put = [&](u32 x, u32 y, const u8* rgba) {
    if (x < w && y < h) std::memcpy(out + (static_cast<std::size_t>(y) * w + x) * 4, rgba, 4);
  };
  auto palette = [&](u32 index, u8* o) {
    if (tlut && index < tlut_entries) decode_tlut_entry(be16(tlut + 2 * index), tlut_format, o);
    else o[0] = o[1] = o[2] = o[3] = 0;
  };
  for (u32 by = 0; by < bh; ++by) {
    for (u32 bx = 0; bx < bw; ++bx) {
      const u8* blk = src + (static_cast<std::size_t>(by) * bw + bx) * block_bytes;
      const u32 x0 = bx * b.w, y0 = by * b.h;
      u8 px[4];
      switch (format) {
        case kTexI4: case kTexC4:
          for (u32 k = 0; k < 64; ++k) {
            u32 v = (blk[k / 2] >> ((k & 1) ? 0 : 4)) & 15;
            if (format == kTexI4) px[0] = px[1] = px[2] = px[3] = x4(v);
            else palette(v, px);
            put(x0 + k % 8, y0 + k / 8, px);
          }
          break;
        case kTexI8: case kTexC8:
          for (u32 k = 0; k < 32; ++k) {
            if (format == kTexI8) px[0] = px[1] = px[2] = px[3] = blk[k];
            else palette(blk[k], px);
            put(x0 + k % 8, y0 + k / 8, px);
          }
          break;
        case kTexIA4:
          for (u32 k = 0; k < 32; ++k) {
            px[0] = px[1] = px[2] = x4(blk[k] & 15);
            px[3] = x4(blk[k] >> 4);
            put(x0 + k % 8, y0 + k / 8, px);
          }
          break;
        case kTexIA8:
          for (u32 k = 0; k < 16; ++k) {
            px[3] = blk[2 * k];
            px[0] = px[1] = px[2] = blk[2 * k + 1];
            put(x0 + k % 4, y0 + k / 4, px);
          }
          break;
        case kTexRGB565:
          for (u32 k = 0; k < 16; ++k) {
            rgb565(be16(blk + 2 * k), px);
            put(x0 + k % 4, y0 + k / 4, px);
          }
          break;
        case kTexRGB5A3:
          for (u32 k = 0; k < 16; ++k) {
            rgb5a3(be16(blk + 2 * k), px);
            put(x0 + k % 4, y0 + k / 4, px);
          }
          break;
        case kTexC14X2:
          for (u32 k = 0; k < 16; ++k) {
            palette(be16(blk + 2 * k) & 0x3FFF, px);
            put(x0 + k % 4, y0 + k / 4, px);
          }
          break;
        case kTexRGBA8:
          for (u32 k = 0; k < 16; ++k) {
            px[3] = blk[2 * k];
            px[0] = blk[2 * k + 1];
            px[1] = blk[32 + 2 * k];
            px[2] = blk[32 + 2 * k + 1];
            put(x0 + k % 4, y0 + k / 4, px);
          }
          break;
        case kTexCMPR:
          for (u32 sb = 0; sb < 4; ++sb) {
            const u8* s = blk + 8 * sb;
            const u16 c0 = be16(s), c1 = be16(s + 2);
            u8 pal[4][4];
            rgb565(c0, pal[0]);
            rgb565(c1, pal[1]);
            if (c0 > c1) {
              for (int c = 0; c < 3; ++c) {
                pal[2][c] = blend38(pal[0][c], pal[1][c]);
                pal[3][c] = blend38(pal[1][c], pal[0][c]);
              }
              pal[2][3] = pal[3][3] = 255;
            } else {
              for (int c = 0; c < 3; ++c) {
                pal[2][c] = static_cast<u8>((pal[0][c] + pal[1][c]) >> 1);
                pal[3][c] = pal[2][c];  // the transparent entry keeps the average's color
              }
              pal[2][3] = 255;
              pal[3][3] = 0;
            }
            const u32 sx = x0 + (sb & 1) * 4, sy = y0 + (sb >> 1) * 4;
            for (u32 r = 0; r < 4; ++r)
              for (u32 c = 0; c < 4; ++c) put(sx + c, sy + r, pal[(s[4 + r] >> (6 - 2 * c)) & 3]);
          }
          break;
        default:
          for (u32 k = 0; k < b.w * b.h; ++k) {
            px[0] = 255; px[1] = 0; px[2] = 255; px[3] = 255;  // unknown format: magenta
            put(x0 + k % b.w, y0 + k / b.w, px);
          }
          break;
      }
    }
  }
}

bool gather_tmem_texture(const std::uint8_t* tmem, std::uint32_t even, std::uint32_t odd, std::uint8_t format,
                         std::uint32_t w, std::uint32_t h, std::uint32_t levels, std::vector<std::uint8_t>& out) {
  out.clear();
  std::uint64_t pe = even, po = odd;
  for (std::uint32_t l = 0; l < levels; ++l) {
    const std::uint32_t size = texture_level_size(format, w, h);
    const std::size_t at = out.size();
    out.resize(at + size);
    if (format == kTexRGBA8) {  // 64-byte tiles: 32 bytes of AR, then 32 of GB
      const std::uint32_t tiles = size / 64;
      if (pe + 32ull * tiles > kTmemSize || po + 32ull * tiles > kTmemSize) return false;
      for (std::uint32_t k = 0; k < tiles; ++k) {
        std::memcpy(out.data() + at + 64 * k, tmem + pe + 32 * k, 32);
        std::memcpy(out.data() + at + 64 * k + 32, tmem + po + 32 * k, 32);
      }
      pe += 32ull * tiles;
      po += 32ull * tiles;
    } else {
      std::uint64_t& p = (l & 1) ? po : pe;
      if (p + size > kTmemSize) return false;
      std::memcpy(out.data() + at, tmem + p, size);
      p += size;
    }
    w = w > 1 ? w / 2 : 1;
    h = h > 1 ? h / 2 : 1;
  }
  return true;
}

}  // namespace mvp::gfx
