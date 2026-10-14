// TEV -> WGSL (E1): one WGSL module per pixel pipeline configuration, the way
// Aurora (MIT) builds its shaders from GX state, but written for this engine's
// PipelineConfig and computed in integers like the hardware: TEV inputs are
// 8-bit, registers 11-bit signed, the lerp uses c + (c >> 7), compare modes
// compare packed 8/16/24-bit values, and the alpha test runs on 8-bit alpha.
//
// Interface shared with the WebGPU backend:
// - vertex buffer: OutVertex (draw.h), 144-byte stride: @location(0) clip
//   position, (1) color0, (2) color1, (3..10) texture coordinates 0-7 (s, t, q);
// - @group(0) @binding(0): DrawUniforms (draw.h) as `U`, with a dynamic offset;
// - @group(1) @binding(0..7): texture maps 0-7, @binding(8..15): their samplers.
// Entry points: `vs_main`, `fs_main`.
#pragma once

#include <string>

#include "gfx/draw.h"

namespace mvp::gfx {

std::string generate_wgsl(const PipelineConfig& c);

// Size of DrawUniforms as WGSL lays out `U` (the buffer slot is rounded up to 256).
constexpr std::size_t kUniformSize = 416;
static_assert(sizeof(DrawUniforms) == kUniformSize);

}  // namespace mvp::gfx
