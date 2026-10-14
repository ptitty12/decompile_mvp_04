#include "gfx/wgpu/window.h"

#include <SDL3/SDL.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include <algorithm>

#include "gfx/wgpu/gpu.h"

namespace mvp::gfx {

namespace {

// A full-window triangle that samples the source rectangle `rect` (x0, y0,
// x1, y1 in normalized window coordinates) and shows black outside it.
const char* kBlitWgsl = R"(
struct Params { rect: vec4f };
@group(0) @binding(0) var src: texture_2d<f32>;
@group(0) @binding(1) var samp: sampler;
@group(0) @binding(2) var<uniform> params: Params;

struct VsOut { @builtin(position) pos: vec4f, @location(0) uv: vec2f };

@vertex fn vs(@builtin(vertex_index) i: u32) -> VsOut {
  var p = array<vec2f, 3>(vec2f(-1.0, -1.0), vec2f(3.0, -1.0), vec2f(-1.0, 3.0));
  var o: VsOut;
  o.pos = vec4f(p[i], 0.0, 1.0);
  o.uv = vec2f(p[i].x * 0.5 + 0.5, 0.5 - p[i].y * 0.5);
  return o;
}

@fragment fn fs(in: VsOut) -> @location(0) vec4f {
  let r = params.rect;
  let uv = (in.uv - r.xy) / (r.zw - r.xy);
  let c = textureSampleLevel(src, samp, uv, 0.0);
  if (any(uv < vec2f(0.0)) || any(uv > vec2f(1.0))) { return vec4f(0.0, 0.0, 0.0, 1.0); }
  return vec4f(c.rgb, 1.0);
}
)";

}  // namespace

std::unique_ptr<Window> Window::open(const char* title, int width, int height, std::string* err) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    if (err) *err = std::string("SDL_Init: ") + SDL_GetError();
    return nullptr;
  }
  auto w = std::unique_ptr<Window>(new Window());
  w->window_ = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
  if (!w->window_) {
    if (err) *err = std::string("SDL_CreateWindow: ") + SDL_GetError();
    return nullptr;
  }
  w->width_ = width;
  w->height_ = height;
  return w;
}

Window::~Window() {
  if (configured_) surface_.Unconfigure();
  surface_ = nullptr;
  if (window_) SDL_DestroyWindow(window_);
  SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

bool Window::attach(Gpu& gpu, std::string* err) {
  gpu_ = &gpu;
  wgpu::SurfaceDescriptor sd{};
#ifdef _WIN32
  SDL_PropertiesID props = SDL_GetWindowProperties(window_);
  wgpu::SurfaceSourceWindowsHWND src{};
  src.hwnd = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr);
  if (!src.hwnd) {
    if (err) *err = "no HWND for the SDL window";
    return false;
  }
  src.hinstance = GetModuleHandleW(nullptr);
  sd.nextInChain = &src;
#else
  if (err) *err = "window surfaces are only implemented for Windows so far";
  return false;
#endif
  surface_ = gpu.instance().CreateSurface(&sd);
  if (!surface_) {
    if (err) *err = "CreateSurface failed";
    return false;
  }
  wgpu::SurfaceCapabilities caps{};
  surface_.GetCapabilities(gpu.adapter(), &caps);
  if (caps.formatCount == 0) {
    if (err) *err = "the surface supports no format on this adapter";
    return false;
  }
  format_ = caps.formats[0];
  for (std::size_t i = 0; i < caps.formatCount; ++i)
    if (caps.formats[i] == wgpu::TextureFormat::BGRA8Unorm) format_ = caps.formats[i];

  wgpu::ShaderModule sm = gpu.shader(kBlitWgsl, "blit");
  wgpu::ColorTargetState target{};
  target.format = format_;
  wgpu::FragmentState fs{};
  fs.module = sm;
  fs.entryPoint = "fs";
  fs.targetCount = 1;
  fs.targets = &target;
  wgpu::RenderPipelineDescriptor pd{};
  pd.label = "blit";
  pd.vertex.module = sm;
  pd.vertex.entryPoint = "vs";
  pd.fragment = &fs;
  pd.primitive.topology = wgpu::PrimitiveTopology::TriangleList;
  blit_ = gpu.device().CreateRenderPipeline(&pd);

  wgpu::SamplerDescriptor samp{};
  samp.magFilter = wgpu::FilterMode::Linear;
  samp.minFilter = wgpu::FilterMode::Linear;
  sampler_ = gpu.device().CreateSampler(&samp);
  wgpu::BufferDescriptor bd{};
  bd.size = 16;
  bd.usage = wgpu::BufferUsage::Uniform | wgpu::BufferUsage::CopyDst;
  params_ = gpu.device().CreateBuffer(&bd);
  configure();
  return true;
}

void Window::configure() {
  int w = 0, h = 0;
  SDL_GetWindowSizeInPixels(window_, &w, &h);
  if (w <= 0 || h <= 0) return;
  width_ = w;
  height_ = h;
  wgpu::SurfaceConfiguration cfg{};
  cfg.device = gpu_->device();
  cfg.format = format_;
  cfg.usage = wgpu::TextureUsage::RenderAttachment;
  cfg.width = static_cast<std::uint32_t>(w);
  cfg.height = static_cast<std::uint32_t>(h);
  cfg.presentMode = wgpu::PresentMode::Fifo;
  cfg.alphaMode = wgpu::CompositeAlphaMode::Opaque;
  surface_.Configure(&cfg);
  configured_ = true;
}

bool Window::pump() {
  SDL_Event e;
  bool open = true;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_EVENT_QUIT || e.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) open = false;
    if (e.type == SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED && gpu_) configure();
  }
  return open;
}

void Window::present(const wgpu::TextureView& src, std::uint32_t src_width, std::uint32_t src_height) {
  if (!configured_ || src_width == 0 || src_height == 0) return;
  wgpu::SurfaceTexture st{};
  surface_.GetCurrentTexture(&st);
  if (st.status != wgpu::SurfaceGetCurrentTextureStatus::SuccessOptimal &&
      st.status != wgpu::SurfaceGetCurrentTextureStatus::SuccessSuboptimal) {
    configure();
    return;
  }
  // Fit the source into the window, centered, keeping its aspect ratio (4:3
  // for the 640-wide frame buffer).
  float sw = static_cast<float>(src_width), sh = static_cast<float>(src_height);
  float ww = static_cast<float>(width_), wh = static_cast<float>(height_);
  float scale = std::min(ww / sw, wh / sh);
  float x0 = (ww - sw * scale) * 0.5f / ww, y0 = (wh - sh * scale) * 0.5f / wh;
  float rect[4] = {x0, y0, 1.0f - x0, 1.0f - y0};
  gpu_->queue().WriteBuffer(params_, 0, rect, sizeof rect);

  wgpu::BindGroupEntry entries[3]{};
  entries[0].binding = 0;
  entries[0].textureView = src;
  entries[1].binding = 1;
  entries[1].sampler = sampler_;
  entries[2].binding = 2;
  entries[2].buffer = params_;
  entries[2].size = 16;
  wgpu::BindGroupDescriptor bgd{};
  bgd.layout = blit_.GetBindGroupLayout(0);
  bgd.entryCount = 3;
  bgd.entries = entries;
  wgpu::BindGroup bg = gpu_->device().CreateBindGroup(&bgd);

  wgpu::RenderPassColorAttachment ca{};
  ca.view = st.texture.CreateView();
  ca.loadOp = wgpu::LoadOp::Clear;
  ca.storeOp = wgpu::StoreOp::Store;
  ca.clearValue = {0, 0, 0, 1};
  wgpu::RenderPassDescriptor rp{};
  rp.colorAttachmentCount = 1;
  rp.colorAttachments = &ca;
  wgpu::CommandEncoder enc = gpu_->device().CreateCommandEncoder();
  wgpu::RenderPassEncoder pass = enc.BeginRenderPass(&rp);
  pass.SetPipeline(blit_);
  pass.SetBindGroup(0, bg);
  pass.Draw(3);
  pass.End();
  wgpu::CommandBuffer cb = enc.Finish();
  gpu_->queue().Submit(1, &cb);
  surface_.Present();
}

}  // namespace mvp::gfx
