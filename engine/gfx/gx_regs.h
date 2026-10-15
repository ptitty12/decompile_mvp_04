// GX register numbers and field layouts (E1), as the graphics processor sees
// them in the command stream: CP (command processor: vertex formats, arrays),
// XF (transform unit: matrices, lights, channels, texgens, viewport,
// projection) and BP (rasterizer, TEV, textures, pixel engine).
//
// Sources: the public GX documentation (YAGCD), the Dolphin SDK's GX macro
// layouts as used by the game, pureikyubu's GX notes (CC0) and Aurora's
// register decoding (MIT), read for reference. Field positions are facts about
// the hardware; nothing here is copied code.
#pragma once

#include <cstdint>

namespace mvp::gfx {

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;

constexpr u32 bits(u32 v, int lo, int n) { return (v >> lo) & ((1u << n) - 1); }

// ---- command opcodes ----
namespace cmd {
constexpr u8 kNop = 0x00;
constexpr u8 kLoadCp = 0x08;
constexpr u8 kLoadXf = 0x10;
constexpr u8 kLoadIndxA = 0x20;  // position matrices
constexpr u8 kLoadIndxB = 0x28;  // normal matrices
constexpr u8 kLoadIndxC = 0x30;  // texture / post matrices
constexpr u8 kLoadIndxD = 0x38;  // lights
constexpr u8 kCallDl = 0x40;
constexpr u8 kInvalVtx = 0x48;
constexpr u8 kLoadBp = 0x61;
// Primitives: opcode | vertex format (0-7).
constexpr u8 kQuads = 0x80;
constexpr u8 kQuads2 = 0x88;
constexpr u8 kTriangles = 0x90;
constexpr u8 kTriStrip = 0x98;
constexpr u8 kTriFan = 0xA0;
constexpr u8 kLines = 0xA8;
constexpr u8 kLineStrip = 0xB0;
constexpr u8 kPoints = 0xB8;
}  // namespace cmd

// ---- CP registers ----
namespace cp {
constexpr u8 kMatIndexA = 0x30;  // pos/nrm 0-5, tex0 6-11, tex1 12-17, tex2 18-23, tex3 24-29
constexpr u8 kMatIndexB = 0x40;  // tex4 0-5, tex5 6-11, tex6 12-17, tex7 18-23
constexpr u8 kVcdLo = 0x50;      // pnmtx 0, texNmtx 1-8, pos 9-10, nrm 11-12, col0 13-14, col1 15-16
constexpr u8 kVcdHi = 0x60;      // tex0..7 in 2-bit fields
constexpr u8 kVatA = 0x70;
constexpr u8 kVatB = 0x80;
constexpr u8 kVatC = 0x90;
constexpr u8 kArrayBase = 0xA0;    // + array (0 pos, 1 nrm, 2-3 col, 4-11 tex, 12-15 XF indexed loads A-D)
constexpr u8 kArrayStride = 0xB0;  // + array
}  // namespace cp

// VCD attribute types.
enum class AttrType : u8 { None = 0, Direct = 1, Index8 = 2, Index16 = 3 };

// Component formats (position, normal, texture coordinates).
enum CompFmt : u8 { kU8 = 0, kS8 = 1, kU16 = 2, kS16 = 3, kF32 = 4 };
// Color formats.
enum ColorFmt : u8 { kRgb565 = 0, kRgb888 = 1, kRgb888x = 2, kRgba4444 = 3, kRgba6666 = 4, kRgba8888 = 5 };

// ---- XF memory and registers (word addresses) ----
namespace xf {
constexpr u32 kPosMtx = 0x000;     // 64 rows of 4: matrix index i at i * 4 (3x4 or 2x4)
constexpr u32 kNrmMtx = 0x400;     // 3x3 normal matrices: for position index p, at (p & 31) * 3
constexpr u32 kPostMtx = 0x500;    // 64 rows of 4: dual-texture (post) matrices, index i at i * 4
constexpr u32 kLights = 0x600;     // 8 lights x 16 words
constexpr u32 kMemSize = 0x800;
constexpr u32 kRegBase = 0x1000;
constexpr u32 kInVertexSpec = 0x1008;
constexpr u32 kNumColors = 0x1009;
constexpr u32 kAmbient0 = 0x100A;  // +1 for channel 1 (RGBA8)
constexpr u32 kMaterial0 = 0x100C;
constexpr u32 kColor0Cntrl = 0x100E;  // color0, color1, alpha0, alpha1
constexpr u32 kDualTex = 0x1012;
constexpr u32 kMatIndexA = 0x1018;
constexpr u32 kMatIndexB = 0x1019;
constexpr u32 kViewport = 0x101A;     // 6 floats: wd, -ht, zrange, xorig+342, yorig+342, zfar
constexpr u32 kProjection = 0x1020;   // 6 floats + type (0 perspective, 1 orthographic)
constexpr u32 kNumTexGens = 0x103F;
constexpr u32 kTexGen = 0x1040;       // + texgen 0-7
constexpr u32 kPostInfo = 0x1050;     // + texgen 0-7
constexpr u32 kRegCount = 0x60;
}  // namespace xf

// ---- BP registers ----
namespace bp {
constexpr u8 kGenMode = 0x00;     // ntex 0-3, ncol 4-6, ntev-1 10-13, cull 14-15, nind 16-18
constexpr u8 kIndMtx = 0x06;      // 9 registers: 3 matrices x 3
constexpr u8 kIndImask = 0x0F;
constexpr u8 kIndCmd = 0x10;      // + TEV stage 0-15
constexpr u8 kScissorTL = 0x20;   // y 0-10, x 12-22 (+342)
constexpr u8 kScissorBR = 0x21;
constexpr u8 kLinePtWidth = 0x22; // line width 0-7, point size 8-15 (1/6 pixel), offsets 16-21
constexpr u8 kIndScale0 = 0x25;
constexpr u8 kIndScale1 = 0x26;
constexpr u8 kIref = 0x27;
constexpr u8 kTref = 0x28;        // + stage pair 0-7
constexpr u8 kSuSSize = 0x30;     // + 2 x texcoord (s size - 1 in 0-15)
constexpr u8 kSuTSize = 0x31;
constexpr u8 kZMode = 0x40;       // enable 0, func 1-3, update 4
constexpr u8 kCMode0 = 0x41;      // blend 0, logic 1, dither 2, color 3, alpha 4, dst 5-7, src 8-10, sub 11, logicop 12-15
constexpr u8 kCMode1 = 0x42;      // constant alpha 0-7, enable 8
constexpr u8 kZCompare = 0x43;    // pixel format 0-2, z format 3-5, early z 6
constexpr u8 kFieldMask = 0x44;
constexpr u8 kDrawDone = 0x45;
constexpr u8 kPeToken = 0x47;
constexpr u8 kPeTokenInt = 0x48;
constexpr u8 kEfbTL = 0x49;       // x 0-9, y 10-19
constexpr u8 kEfbWH = 0x4A;       // w-1 0-9, h-1 10-19
constexpr u8 kXfbAddr = 0x4B;     // destination >> 5
constexpr u8 kMipmapStride = 0x4D;
constexpr u8 kDispCopyYScale = 0x4E;
constexpr u8 kClearAR = 0x4F;     // alpha 8-15, red 0-7
constexpr u8 kClearGB = 0x50;     // green 8-15, blue 0-7
constexpr u8 kClearZ = 0x51;
constexpr u8 kTriggerCopy = 0x52;
constexpr u8 kCopyFilter0 = 0x53;
constexpr u8 kCopyFilter1 = 0x54;
constexpr u8 kBoundingBox0 = 0x55;
constexpr u8 kBoundingBox1 = 0x56;
constexpr u8 kScissorOffset = 0x59;  // x 0-9, y 10-19 (units of 2 pixels, +342)
constexpr u8 kPreloadAddr = 0x60;      // TMEM preload: source >> 5
constexpr u8 kPreloadTmemEven = 0x61;  // TMEM line (32 bytes) of the even bank
constexpr u8 kPreloadTmemOdd = 0x62;   // TMEM line of the odd bank (RGBA8's GB tiles)
constexpr u8 kPreloadMode = 0x63;      // lines 0-14, type 15-16 (3: RGBA8); writing it loads
constexpr u8 kLoadTlut0 = 0x64;   // source >> 5
constexpr u8 kLoadTlut1 = 0x65;   // tmem >> 9 in 0-9, count / 16 in 10-20
constexpr u8 kTexInvalidate = 0x66;
constexpr u8 kTexMode0 = 0x80;    // maps 0-3 at 0x80, maps 4-7 at 0xA0 (+ map & 3)
constexpr u8 kTexMode1 = 0x84;
constexpr u8 kTexImage0 = 0x88;   // w-1 0-9, h-1 10-19, format 20-23
constexpr u8 kTexImage1 = 0x8C;   // TMEM even line 0-14, bit 21: preloaded (manually managed TMEM)
constexpr u8 kTexImage2 = 0x90;   // TMEM odd line 0-14
constexpr u8 kTexImage3 = 0x94;   // address >> 5
constexpr u8 kTexTlut = 0x98;     // tmem offset >> 9 in 0-9, format 10-11
constexpr u8 kTevColorEnv = 0xC0; // + 2 x stage
constexpr u8 kTevAlphaEnv = 0xC1;
constexpr u8 kTevReg = 0xE0;      // RA at 0xE0 + 2r, BG at 0xE1 + 2r; bit 23: konst
constexpr u8 kFogRangeBase = 0xE8;
constexpr u8 kFog0 = 0xEE;
constexpr u8 kFog1 = 0xEF;
constexpr u8 kFog2 = 0xF0;
constexpr u8 kFog3 = 0xF1;
constexpr u8 kFogColor = 0xF2;
constexpr u8 kAlphaCompare = 0xF3;  // ref0 0-7, ref1 8-15, comp0 16-18, comp1 19-21, logic 22-23
constexpr u8 kZTexBias = 0xF4;
constexpr u8 kZTex2 = 0xF5;
constexpr u8 kKsel = 0xF6;        // 8 registers
constexpr u8 kMask = 0xFE;

// Texture map m's register for the group at base (kTexMode0, kTexImage0, ...).
constexpr u8 tex_reg(u8 base, int map) {
  return static_cast<u8>(base + (map & 3) + (map >= 4 ? 0x20 : 0));
}
}  // namespace bp

// EFB size (the embedded frame buffer): 640 x 528 pixels.
constexpr u32 kEfbWidth = 640;
constexpr u32 kEfbHeight = 528;

}  // namespace mvp::gfx
