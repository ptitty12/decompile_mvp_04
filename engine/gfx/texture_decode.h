// GameCube texture formats decoded to RGBA8 (E1): I4, I8, IA4, IA8, RGB565,
// RGB5A3, RGBA8, C4, C8, C14X2 (with an IA8, RGB565 or RGB5A3 palette) and
// CMPR. Texels are stored in tiles (blocks) of 8x8, 8x4 or 4x4 texels, blocks
// row by row; mip levels follow each other, each padded to whole blocks.
//
// Written from the public format descriptions (YAGCD); CMPR's 3/8-5/8 color
// interpolation is the hardware's as Dolphin documents it (read, not copied).
#pragma once

#include <cstdint>
#include <vector>

namespace mvp::gfx {

enum TexFormat : std::uint8_t {
  kTexI4 = 0,
  kTexI8 = 1,
  kTexIA4 = 2,
  kTexIA8 = 3,
  kTexRGB565 = 4,
  kTexRGB5A3 = 5,
  kTexRGBA8 = 6,
  kTexC4 = 8,
  kTexC8 = 9,
  kTexC14X2 = 10,
  kTexCMPR = 14,
};

enum TlutFormat : std::uint8_t { kTlutIA8 = 0, kTlutRGB565 = 1, kTlutRGB5A3 = 2 };

// Block size in texels, and bits per texel.
struct TexBlock {
  std::uint32_t w, h, bpp;
};
TexBlock texture_block(std::uint8_t format);
bool texture_format_known(std::uint8_t format);

// Bytes of one level of w x h texels, padded to whole blocks.
std::uint32_t texture_level_size(std::uint8_t format, std::uint32_t w, std::uint32_t h);
// Bytes of `levels` levels starting at w x h.
std::uint32_t texture_size(std::uint8_t format, std::uint32_t w, std::uint32_t h, std::uint32_t levels);

// Decodes one level into `out` (w * h * 4 bytes, RGBA rows top to bottom).
// `src` holds texture_level_size bytes. Indexed formats read `tlut` (big-endian
// 16-bit entries, `tlut_entries` of them; indices beyond read as 0).
void decode_texture(std::uint8_t format, std::uint32_t w, std::uint32_t h, const std::uint8_t* src,
                    std::uint8_t* out, const std::uint8_t* tlut = nullptr, std::uint8_t tlut_format = 0,
                    std::uint32_t tlut_entries = 0);

// A preloaded texture's levels gathered from TMEM (1 MiB at `tmem`) into the
// main-memory layout (texture_size bytes), as GXPreLoadEntireTexture placed them:
// levels alternate between the even bank (level 0, 2, ...) and the odd bank
// (1, 3, ...), each bank's levels back to back; RGBA8 keeps its AR tiles in the
// even bank and its GB tiles in the odd bank. False if it runs past TMEM.
bool gather_tmem_texture(const std::uint8_t* tmem, std::uint32_t even, std::uint32_t odd, std::uint8_t format,
                         std::uint32_t w, std::uint32_t h, std::uint32_t levels, std::vector<std::uint8_t>& out);
constexpr std::uint32_t kTmemSize = 1u << 20;

// One 16-bit color of the given palette format as RGBA8.
void decode_tlut_entry(std::uint16_t v, std::uint8_t tlut_format, std::uint8_t out[4]);

}  // namespace mvp::gfx
