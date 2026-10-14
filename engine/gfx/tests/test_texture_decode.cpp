// Texture decoders on synthetic textures (no game data): the tiling of every
// format against an independent texel-address reference, texel conversions at
// known values, palettes, CMPR blocks, odd sizes and mip level sizes.
#include <doctest/doctest.h>

#include <cstring>
#include <functional>
#include <vector>

#include "gfx/texture_decode.h"

using namespace mvp::gfx;
using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;

namespace {

// Stores raw texel value `v` (bpp bits) of texel (x, y) in tiled layout.
void store(std::vector<u8>& buf, u8 fmt, u32 w, u32 x, u32 y, u32 v) {
  TexBlock b = texture_block(fmt);
  u32 bpr = (w + b.w - 1) / b.w;
  u32 block = (y / b.h) * bpr + x / b.w;
  u32 in = (y % b.h) * b.w + x % b.w;
  u32 block_bytes = b.w * b.h * b.bpp / 8;
  u8* p = buf.data() + block * block_bytes;
  if (fmt == kTexRGBA8) {  // AR then GB
    p[2 * in] = static_cast<u8>(v >> 24);
    p[2 * in + 1] = static_cast<u8>(v >> 16);
    p[32 + 2 * in] = static_cast<u8>(v >> 8);
    p[32 + 2 * in + 1] = static_cast<u8>(v);
    return;
  }
  u32 bit = in * b.bpp;
  if (b.bpp == 4) {
    u8& q = p[bit / 8];
    if (bit % 8 == 0) q = static_cast<u8>((q & 0x0F) | (v << 4));
    else q = static_cast<u8>((q & 0xF0) | (v & 15));
  } else if (b.bpp == 8) {
    p[bit / 8] = static_cast<u8>(v);
  } else {
    p[bit / 8] = static_cast<u8>(v >> 8);
    p[bit / 8 + 1] = static_cast<u8>(v);
  }
}

void check_format(u8 fmt, u32 w, u32 h, std::function<u32(u32, u32)> raw,
                  std::function<void(u32, u8*)> expect, const u8* tlut = nullptr, u8 tlut_fmt = 0,
                  u32 entries = 0) {
  std::vector<u8> buf(texture_level_size(fmt, w, h), 0);
  for (u32 y = 0; y < h; ++y)
    for (u32 x = 0; x < w; ++x) store(buf, fmt, w, x, y, raw(x, y));
  std::vector<u8> out(w * h * 4, 0xCD);
  decode_texture(fmt, w, h, buf.data(), out.data(), tlut, tlut_fmt, entries);
  int bad = 0;
  for (u32 y = 0; y < h; ++y)
    for (u32 x = 0; x < w; ++x) {
      u8 e[4];
      expect(raw(x, y), e);
      if (std::memcmp(e, &out[(y * w + x) * 4], 4) != 0 && bad++ < 4)
        FAIL_CHECK("format " << int(fmt) << " texel (" << x << "," << y << ")");
    }
  CHECK(bad == 0);
}

u32 hash(u32 x, u32 y) {
  u32 v = x * 0x9E3779B1u ^ (y + 0x7F4A7C15u) * 0x85EBCA77u;
  v ^= v >> 15;
  v *= 0x2C1B3C6Du;
  return v ^ (v >> 12);
}

}  // namespace

TEST_CASE("texel conversions at known values") {
  u8 o[4];
  decode_tlut_entry(0xF800, kTlutRGB565, o);
  CHECK((o[0] == 255 && o[1] == 0 && o[2] == 0 && o[3] == 255));
  decode_tlut_entry(0x07E0, kTlutRGB565, o);
  CHECK((o[0] == 0 && o[1] == 255 && o[2] == 0));
  decode_tlut_entry(0x8000 | 31u << 10 | 16u << 5 | 1u, kTlutRGB5A3, o);  // opaque RGB555
  CHECK((o[0] == 255 && o[1] == 132 && o[2] == 8 && o[3] == 255));
  decode_tlut_entry(0x7F00 | 0x0F, kTlutRGB5A3, o);  // alpha 7 (255), r 15, g 0, b 15
  CHECK((o[0] == 255 && o[1] == 0 && o[2] == 255 && o[3] == 255));
  decode_tlut_entry(0x3123, kTlutRGB5A3, o);  // alpha 3 -> 0x6D, r 1, g 2, b 3
  CHECK((o[0] == 17 && o[1] == 34 && o[2] == 51 && o[3] == 0x6D));
  decode_tlut_entry(0x80C0, kTlutIA8, o);  // alpha 0x80, intensity 0xC0
  CHECK((o[0] == 0xC0 && o[1] == 0xC0 && o[2] == 0xC0 && o[3] == 0x80));
}

TEST_CASE("tiling of every format, including sizes that are not whole blocks") {
  for (auto [w, h] : {std::pair<u32, u32>{16, 8}, {13, 7}, {32, 20}, {3, 1}}) {
    CAPTURE(w);
    CAPTURE(h);
    check_format(kTexI4, w, h, [](u32 x, u32 y) { return hash(x, y) & 15; },
                 [](u32 v, u8* e) { e[0] = e[1] = e[2] = e[3] = static_cast<u8>(v * 17); });
    check_format(kTexI8, w, h, [](u32 x, u32 y) { return hash(x, y) & 255; },
                 [](u32 v, u8* e) { e[0] = e[1] = e[2] = e[3] = static_cast<u8>(v); });
    check_format(kTexIA4, w, h, [](u32 x, u32 y) { return hash(x, y) & 255; },
                 [](u32 v, u8* e) {
                   e[0] = e[1] = e[2] = static_cast<u8>((v & 15) * 17);
                   e[3] = static_cast<u8>((v >> 4) * 17);
                 });
    check_format(kTexIA8, w, h, [](u32 x, u32 y) { return hash(x, y) & 0xFFFF; },
                 [](u32 v, u8* e) {
                   e[0] = e[1] = e[2] = static_cast<u8>(v);
                   e[3] = static_cast<u8>(v >> 8);
                 });
    check_format(kTexRGB565, w, h, [](u32 x, u32 y) { return hash(x, y) & 0xFFFF; },
                 [](u32 v, u8* e) { decode_tlut_entry(static_cast<u16>(v), kTlutRGB565, e); });
    check_format(kTexRGB5A3, w, h, [](u32 x, u32 y) { return hash(x, y) & 0xFFFF; },
                 [](u32 v, u8* e) { decode_tlut_entry(static_cast<u16>(v), kTlutRGB5A3, e); });
    check_format(kTexRGBA8, w, h, [](u32 x, u32 y) { return hash(x, y); },
                 [](u32 v, u8* e) {  // raw = A R G B
                   e[3] = static_cast<u8>(v >> 24);
                   e[0] = static_cast<u8>(v >> 16);
                   e[1] = static_cast<u8>(v >> 8);
                   e[2] = static_cast<u8>(v);
                 });
  }
}

TEST_CASE("indexed formats read the palette") {
  // 16384 entries: entry i = RGB565 value i * 7 (IA8 and RGB5A3 checked by the texel test).
  std::vector<u8> tlut(2 * 16384);
  for (u32 i = 0; i < 16384; ++i) {
    tlut[2 * i] = static_cast<u8>((i * 7) >> 8);
    tlut[2 * i + 1] = static_cast<u8>(i * 7);
  }
  auto expect = [&](u32 v, u8* e) { decode_tlut_entry(static_cast<u16>(v * 7), kTlutRGB565, e); };
  check_format(kTexC4, 24, 16, [](u32 x, u32 y) { return hash(x, y) & 15; }, expect, tlut.data(), kTlutRGB565, 16);
  check_format(kTexC8, 24, 12, [](u32 x, u32 y) { return hash(x, y) & 255; }, expect, tlut.data(), kTlutRGB565, 256);
  // C14X2: the top two bits of each 16-bit index are ignored.
  check_format(kTexC14X2, 12, 8, [](u32 x, u32 y) { return hash(x, y) & 0xFFFF; },
               [&](u32 v, u8* e) { expect(v & 0x3FFF, e); }, tlut.data(), kTlutRGB565, 16384);
  // Entries past the loaded palette read as transparent black.
  std::vector<u8> buf(texture_level_size(kTexC8, 8, 4), 200);
  std::vector<u8> out(8 * 4 * 4);
  decode_texture(kTexC8, 8, 4, buf.data(), out.data(), tlut.data(), kTlutRGB565, 100);
  CHECK((out[0] == 0 && out[3] == 0));
}

TEST_CASE("CMPR blocks: four-color and three-color-plus-transparent modes") {
  // One 8x8 block: sub-block 0 four-color (c0 > c1), sub-block 1 three-color, 2 and 3 solid.
  std::vector<u8> blk(32, 0);
  auto put16 = [&](int at, u16 v) {
    blk[at] = static_cast<u8>(v >> 8);
    blk[at + 1] = static_cast<u8>(v);
  };
  put16(0, 0xF800);  // red
  put16(2, 0x001F);  // blue
  blk[4] = 0x1B;     // row 0: indices 0, 1, 2, 3
  blk[5] = 0xE4;     // row 1: 3, 2, 1, 0
  put16(8, 0x001F);  // c0 < c1: three-color mode
  put16(10, 0xF800);
  blk[12] = 0x1B;
  put16(16, 0x07E0);
  put16(18, 0x07E0);
  put16(24, 0xFFFF);
  put16(26, 0x0000);
  std::vector<u8> out(8 * 8 * 4);
  decode_texture(kTexCMPR, 8, 8, blk.data(), out.data());
  auto px = [&](u32 x, u32 y) { return &out[(y * 8 + x) * 4]; };
  CHECK((px(0, 0)[0] == 255 && px(0, 0)[2] == 0 && px(0, 0)[3] == 255));
  CHECK((px(1, 0)[0] == 0 && px(1, 0)[2] == 255));
  CHECK(px(2, 0)[0] == (255 * 5) >> 3);  // 5/8 red + 3/8 blue
  CHECK(px(2, 0)[2] == (255 * 3) >> 3);
  CHECK(px(3, 0)[0] == (255 * 3) >> 3);
  CHECK(px(3, 0)[2] == (255 * 5) >> 3);
  CHECK(px(0, 1)[0] == (255 * 3) >> 3);
  // Sub-block 1 (x 4-7, y 0-3): blue, red, average, transparent.
  CHECK((px(4, 0)[2] == 255 && px(4, 0)[0] == 0));
  CHECK((px(5, 0)[0] == 255 && px(5, 0)[2] == 0));
  CHECK((px(6, 0)[0] == 127 && px(6, 0)[2] == 127 && px(6, 0)[3] == 255));
  CHECK(px(7, 0)[3] == 0);
  // Sub-block 2 (x 0-3, y 4-7) solid green; sub-block 3 white (index 0).
  CHECK((px(0, 4)[1] == 255 && px(0, 4)[0] == 0));
  CHECK((px(7, 7)[0] == 255 && px(7, 7)[1] == 255 && px(7, 7)[2] == 255));
}

TEST_CASE("level sizes") {
  CHECK(texture_level_size(kTexI4, 8, 8) == 32);
  CHECK(texture_level_size(kTexI4, 9, 8) == 64);
  CHECK(texture_level_size(kTexRGBA8, 4, 4) == 64);
  CHECK(texture_level_size(kTexCMPR, 640, 480) == 640 * 480 / 2);
  CHECK(texture_level_size(kTexRGB5A3, 1, 1) == 32);
  // 64x64 RGB565 with 7 levels: 8192 + 2048 + 512 + 128 + 32 + 32 (2x2) + 32 (1x1).
  CHECK(texture_size(kTexRGB565, 64, 64, 7) == 8192 + 2048 + 512 + 128 + 32 + 32 + 32);
  CHECK(texture_format_known(kTexCMPR));
  CHECK(!texture_format_known(7));
}
