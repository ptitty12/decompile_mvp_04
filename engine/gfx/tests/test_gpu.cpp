// The WebGPU device, off-screen and data-free: a triangle rendered into a
// texture and read back. Needs a GPU adapter (a software one counts); exits 77
// (skipped) where there is none.
#include <doctest/doctest.h>

#include <cstdio>
#include <cstdlib>

#include "gfx/wgpu/gpu.h"

using namespace mvp::gfx;

namespace {

Gpu* gpu_or_skip() {
  static std::unique_ptr<Gpu> g;
  static bool tried = false;
  if (!tried) {
    tried = true;
    std::string err;
    g = Gpu::create(&err);
    if (!g) {
      std::printf("skipped: %s\n", err.c_str());
      std::exit(77);
    }
    std::printf("adapter: %s\n", g->adapter_name().c_str());
  }
  return g.get();
}

const char* kTriangle = R"(
@vertex fn vs(@builtin(vertex_index) i: u32) -> @builtin(position) vec4f {
  var p = array<vec2f, 3>(vec2f(-0.5, -0.5), vec2f(0.5, -0.5), vec2f(0.0, 0.5));
  return vec4f(p[i], 0.0, 1.0);
}
@fragment fn fs() -> @location(0) vec4f { return vec4f(1.0, 0.5, 0.0, 1.0); }
)";

}  // namespace

TEST_CASE("off-screen triangle") {
  Gpu& g = *gpu_or_skip();
  const std::uint32_t W = 64, H = 64;
  wgpu::TextureDescriptor td{};
  td.size = {W, H, 1};
  td.format = wgpu::TextureFormat::RGBA8Unorm;
  td.usage = wgpu::TextureUsage::RenderAttachment | wgpu::TextureUsage::CopySrc;
  wgpu::Texture tex = g.device().CreateTexture(&td);

  wgpu::ShaderModule sm = g.shader(kTriangle, "triangle");
  wgpu::ColorTargetState target{};
  target.format = td.format;
  wgpu::FragmentState fs{};
  fs.module = sm;
  fs.entryPoint = "fs";
  fs.targetCount = 1;
  fs.targets = &target;
  wgpu::RenderPipelineDescriptor pd{};
  pd.vertex.module = sm;
  pd.vertex.entryPoint = "vs";
  pd.fragment = &fs;
  wgpu::RenderPipeline pipe = g.device().CreateRenderPipeline(&pd);

  wgpu::RenderPassColorAttachment ca{};
  ca.view = tex.CreateView();
  ca.loadOp = wgpu::LoadOp::Clear;
  ca.storeOp = wgpu::StoreOp::Store;
  ca.clearValue = {0.0, 0.0, 1.0, 1.0};
  wgpu::RenderPassDescriptor rp{};
  rp.colorAttachmentCount = 1;
  rp.colorAttachments = &ca;
  wgpu::CommandEncoder enc = g.device().CreateCommandEncoder();
  wgpu::RenderPassEncoder pass = enc.BeginRenderPass(&rp);
  pass.SetPipeline(pipe);
  pass.Draw(3);
  pass.End();
  wgpu::CommandBuffer cb = enc.Finish();
  g.queue().Submit(1, &cb);

  auto px = g.read_texture(tex, W, H);
  REQUIRE(px.size() == W * H * 4);
  auto at = [&](std::uint32_t x, std::uint32_t y) { return px.data() + (y * W + x) * 4; };
  // Center: the triangle (255, 128, 0); corners: the clear color (0, 0, 255).
  const std::uint8_t* c = at(W / 2, H / 2);
  CHECK(c[0] == 255);
  CHECK((c[1] == 127 || c[1] == 128));
  CHECK(c[2] == 0);
  CHECK(c[3] == 255);
  const std::uint8_t* k = at(1, 1);
  CHECK(k[0] == 0);
  CHECK(k[1] == 0);
  CHECK(k[2] == 255);
  // Row 0 is the top: the apex (y = +0.5) is near the top, the base near the bottom.
  CHECK(at(W / 2, H / 4 + 2)[0] == 255);
  CHECK(at(W / 4 - 2, H * 3 / 4 - 2)[0] == 0);
  CHECK(g.errors() == 0);
}
