#include "gfx/wgpu/renderer.h"

#include <algorithm>
#include <cstdio>
#include <cstring>

#include "gfx/tev_wgsl.h"
#include "gfx/texture_decode.h"
#include "gfx/wgpu/gpu.h"

namespace mvp::gfx {

namespace {

constexpr std::uint32_t kUniformSlot = 512;              // DrawUniforms (416 bytes), 256-aligned
constexpr std::uint64_t kVertexCapacity = 16u << 20;     // per pass
constexpr std::uint64_t kUniformCapacity = 2u << 20;     // per pass (4,096 draws)

std::uint64_t mix64(std::uint64_t h) {
  h ^= h >> 33;
  h *= 0xFF51AFD7ED558CCDull;
  h ^= h >> 33;
  h *= 0xC4CEB9FE1A85EC53ull;
  return h ^ (h >> 33);
}

std::uint64_t hash_bytes(const std::uint8_t* p, std::size_t n, std::uint64_t seed = 0x9E3779B97F4A7C15ull) {
  std::uint64_t h = seed ^ (n * 0x100000001B3ull);
  std::size_t i = 0;
  for (; i + 8 <= n; i += 8) {
    std::uint64_t w;
    std::memcpy(&w, p + i, 8);
    h = (h ^ mix64(w)) * 0x9E3779B97F4A7C15ull;
  }
  std::uint64_t tail = 0;
  for (std::size_t k = 0; i + k < n; ++k) tail |= std::uint64_t(p[i + k]) << (8 * k);
  return mix64(h ^ tail);
}

wgpu::BlendFactor blend_factor(u8 f, bool is_dst, bool alpha_channel, bool efb_has_alpha) {
  switch (f) {
    case 0: return wgpu::BlendFactor::Zero;
    case 1: return wgpu::BlendFactor::One;
    case 2:  // src: dst color; dst: src color
      if (alpha_channel) return is_dst ? wgpu::BlendFactor::SrcAlpha : wgpu::BlendFactor::DstAlpha;
      return is_dst ? wgpu::BlendFactor::Src : wgpu::BlendFactor::Dst;
    case 3:
      if (alpha_channel) return is_dst ? wgpu::BlendFactor::OneMinusSrcAlpha : wgpu::BlendFactor::OneMinusDstAlpha;
      return is_dst ? wgpu::BlendFactor::OneMinusSrc : wgpu::BlendFactor::OneMinusDst;
    case 4: return wgpu::BlendFactor::SrcAlpha;
    case 5: return wgpu::BlendFactor::OneMinusSrcAlpha;
    case 6: return efb_has_alpha ? wgpu::BlendFactor::DstAlpha : wgpu::BlendFactor::One;
    default: return efb_has_alpha ? wgpu::BlendFactor::OneMinusDstAlpha : wgpu::BlendFactor::Zero;
  }
}

wgpu::CompareFunction compare(u8 f) {
  switch (f) {
    case 0: return wgpu::CompareFunction::Never;
    case 1: return wgpu::CompareFunction::Less;
    case 2: return wgpu::CompareFunction::Equal;
    case 3: return wgpu::CompareFunction::LessEqual;
    case 4: return wgpu::CompareFunction::Greater;
    case 5: return wgpu::CompareFunction::NotEqual;
    case 6: return wgpu::CompareFunction::GreaterEqual;
    default: return wgpu::CompareFunction::Always;
  }
}

wgpu::AddressMode address(u8 w) {
  return w == 1 ? wgpu::AddressMode::Repeat : w == 2 ? wgpu::AddressMode::MirrorRepeat : wgpu::AddressMode::ClampToEdge;
}

bool efb_has_alpha(u8 pixel_format) { return pixel_format == 1; }  // RGBA6_Z24

const char* kClearWgsl = R"(
struct C { color: vec4f, depth: vec4f };
@group(0) @binding(0) var<uniform> cu: C;
@vertex fn vs(@builtin(vertex_index) i: u32) -> @builtin(position) vec4f {
  var p = array<vec2f, 3>(vec2f(-1.0, -1.0), vec2f(3.0, -1.0), vec2f(-1.0, 3.0));
  return vec4f(p[i], cu.depth.x, 1.0);
}
@fragment fn fs() -> @location(0) vec4f { return cu.color; }
)";

// EFB -> texture copies: reads the source rectangle (box-filtered when halving)
// and converts it to what sampling the copy's format returns.
const char* kConvertWgsl = R"(
struct P { src: vec4i, mode: vec4i };  // src: x, y, half, from depth; mode: format, intensity
@group(0) @binding(0) var<uniform> p: P;
@group(0) @binding(1) var efb: texture_2d<f32>;
@group(0) @binding(2) var efbz: texture_depth_2d;
@vertex fn vs(@builtin(vertex_index) i: u32) -> @builtin(position) vec4f {
  var q = array<vec2f, 3>(vec2f(-1.0, -1.0), vec2f(3.0, -1.0), vec2f(-1.0, 3.0));
  return vec4f(q[i], 0.0, 1.0);
}
fn fetch(xy: vec2i) -> vec4f {
  if (p.src.w != 0) { let d = textureLoad(efbz, xy, 0); return vec4f(d, d, d, d); }
  return textureLoad(efb, xy, 0);
}
@fragment fn fs(@builtin(position) pos: vec4f) -> @location(0) vec4f {
  let o = vec2i(pos.xy);
  var c: vec4f;
  if (p.src.z != 0) {
    let b = p.src.xy + o * 2;
    c = (fetch(b) + fetch(b + vec2i(1, 0)) + fetch(b + vec2i(0, 1)) + fetch(b + vec2i(1, 1))) * 0.25;
  } else {
    c = fetch(p.src.xy + o);
  }
  let y = clamp(0.257 * c.r + 0.504 * c.g + 0.098 * c.b + 16.0 / 255.0, 0.0, 1.0);
  let i = select(c.r, y, p.mode.y != 0);
  switch (p.mode.x) {
    case 0, 1, 8: { return vec4f(i, i, i, i); }
    case 2, 3: { return vec4f(i, i, i, c.a); }
    case 4: { return vec4f(c.rgb, 1.0); }
    case 7: { return vec4f(c.a, c.a, c.a, c.a); }
    case 9: { return vec4f(c.g, c.g, c.g, c.g); }
    case 10: { return vec4f(c.b, c.b, c.b, c.b); }
    case 11: { return vec4f(c.r, c.r, c.r, c.g); }
    case 12: { return vec4f(c.g, c.g, c.g, c.b); }
    default: { return c; }
  }
}
)";

}  // namespace

struct Renderer::TexEntry {
  wgpu::Texture tex;
  wgpu::TextureView view;
  std::uint32_t w = 0, h = 0;
  std::uint64_t mem_hash = 0, epoch = 0;
  std::uint64_t pass = 0;  // the render pass that last sampled it
};

struct Renderer::CopyEntry {
  wgpu::Texture tex;
  wgpu::TextureView view;
  std::uint32_t w = 0, h = 0;
  std::uint32_t bytes = 0;
  std::uint64_t mem_hash = 0, epoch = 0;
};

std::size_t Renderer::CfgHash::operator()(const PipelineConfig& c) const {
  return static_cast<std::size_t>(hash_bytes(reinterpret_cast<const std::uint8_t*>(&c), sizeof c));
}

Renderer::Renderer(Gpu& gpu, const std::uint8_t* mem, std::uint32_t mem_size)
    : gpu_(gpu), mem_(mem), mem_size_(mem_size) {
  const wgpu::Device& dev = gpu.device();
  wgpu::TextureDescriptor td{};
  td.size = {kEfbWidth, kEfbHeight, 1};
  td.format = wgpu::TextureFormat::RGBA8Unorm;
  td.usage = wgpu::TextureUsage::RenderAttachment | wgpu::TextureUsage::CopySrc | wgpu::TextureUsage::TextureBinding;
  td.label = "efb color";
  efb_color_ = dev.CreateTexture(&td);
  efb_color_view_ = efb_color_.CreateView();
  td.format = wgpu::TextureFormat::Depth32Float;
  td.usage = wgpu::TextureUsage::RenderAttachment | wgpu::TextureUsage::TextureBinding;
  td.label = "efb depth";
  efb_depth_ = dev.CreateTexture(&td);
  efb_depth_view_ = efb_depth_.CreateView();

  // Uniforms: one slot per draw, dynamic offset.
  wgpu::BindGroupLayoutEntry ue{};
  ue.binding = 0;
  ue.visibility = wgpu::ShaderStage::Fragment | wgpu::ShaderStage::Vertex;
  ue.buffer.type = wgpu::BufferBindingType::Uniform;
  ue.buffer.hasDynamicOffset = true;
  ue.buffer.minBindingSize = kUniformSize;
  wgpu::BindGroupLayoutDescriptor bd{};
  bd.entryCount = 1;
  bd.entries = &ue;
  bgl_uniforms_ = dev.CreateBindGroupLayout(&bd);
  wgpu::BindGroupLayoutEntry te[16]{};
  for (int k = 0; k < 8; ++k) {
    te[k].binding = static_cast<std::uint32_t>(k);
    te[k].visibility = wgpu::ShaderStage::Fragment;
    te[k].texture.sampleType = wgpu::TextureSampleType::Float;
    te[k].texture.viewDimension = wgpu::TextureViewDimension::e2D;
    te[8 + k].binding = static_cast<std::uint32_t>(8 + k);
    te[8 + k].visibility = wgpu::ShaderStage::Fragment;
    te[8 + k].sampler.type = wgpu::SamplerBindingType::Filtering;
  }
  bd.entryCount = 16;
  bd.entries = te;
  bgl_textures_ = dev.CreateBindGroupLayout(&bd);
  wgpu::BindGroupLayout layouts[2] = {bgl_uniforms_, bgl_textures_};
  wgpu::PipelineLayoutDescriptor pl{};
  pl.bindGroupLayoutCount = 2;
  pl.bindGroupLayouts = layouts;
  layout_ = dev.CreatePipelineLayout(&pl);

  wgpu::BufferDescriptor b{};
  b.size = kVertexCapacity;
  b.usage = wgpu::BufferUsage::Vertex | wgpu::BufferUsage::CopyDst;
  b.label = "vertices";
  vbuf_ = dev.CreateBuffer(&b);
  b.size = kUniformCapacity;
  b.usage = wgpu::BufferUsage::Uniform | wgpu::BufferUsage::CopyDst;
  b.label = "uniforms";
  ubuf_ = dev.CreateBuffer(&b);
  wgpu::BindGroupEntry be{};
  be.binding = 0;
  be.buffer = ubuf_;
  be.size = kUniformSize;
  wgpu::BindGroupDescriptor bgd{};
  bgd.layout = bgl_uniforms_;
  bgd.entryCount = 1;
  bgd.entries = &be;
  uniform_group_ = dev.CreateBindGroup(&bgd);

  // A 1x1 texture and a sampler for unused bindings.
  td.size = {1, 1, 1};
  td.format = wgpu::TextureFormat::RGBA8Unorm;
  td.usage = wgpu::TextureUsage::TextureBinding | wgpu::TextureUsage::CopyDst;
  td.label = "dummy";
  dummy_tex_ = dev.CreateTexture(&td);
  dummy_view_ = dummy_tex_.CreateView();
  const std::uint8_t black[4] = {0, 0, 0, 0};
  wgpu::TexelCopyTextureInfo dst{};
  dst.texture = dummy_tex_;
  wgpu::TexelCopyBufferLayout lay{};
  lay.bytesPerRow = 4;
  wgpu::Extent3D one{1, 1, 1};
  gpu.queue().WriteTexture(&dst, black, 4, &lay, &one);
  wgpu::SamplerDescriptor sd{};
  dummy_sampler_ = dev.CreateSampler(&sd);
  point_sampler_ = dummy_sampler_;

  // Clear pipelines: one per (color, alpha, depth) write mask.
  {
    wgpu::BindGroupLayoutEntry ce{};
    ce.binding = 0;
    ce.visibility = wgpu::ShaderStage::Fragment | wgpu::ShaderStage::Vertex;
    ce.buffer.type = wgpu::BufferBindingType::Uniform;
    bd.entryCount = 1;
    bd.entries = &ce;
    bgl_clear_ = dev.CreateBindGroupLayout(&bd);
    wgpu::PipelineLayoutDescriptor cpl{};
    cpl.bindGroupLayoutCount = 1;
    cpl.bindGroupLayouts = &bgl_clear_;
    wgpu::PipelineLayout clayout = dev.CreatePipelineLayout(&cpl);
    wgpu::ShaderModule sm = gpu.shader(kClearWgsl, "clear");
    for (int m = 0; m < 8; ++m) {
      wgpu::ColorTargetState ct{};
      ct.format = wgpu::TextureFormat::RGBA8Unorm;
      ct.writeMask = ((m & 1) ? wgpu::ColorWriteMask::Red | wgpu::ColorWriteMask::Green | wgpu::ColorWriteMask::Blue
                              : wgpu::ColorWriteMask::None) |
                     ((m & 2) ? wgpu::ColorWriteMask::Alpha : wgpu::ColorWriteMask::None);
      wgpu::FragmentState fs{};
      fs.module = sm;
      fs.entryPoint = "fs";
      fs.targetCount = 1;
      fs.targets = &ct;
      wgpu::DepthStencilState ds{};
      ds.format = wgpu::TextureFormat::Depth32Float;
      ds.depthCompare = wgpu::CompareFunction::Always;
      ds.depthWriteEnabled = (m & 4) ? wgpu::OptionalBool::True : wgpu::OptionalBool::False;
      wgpu::RenderPipelineDescriptor pd{};
      pd.label = "clear";
      pd.layout = clayout;
      pd.vertex.module = sm;
      pd.vertex.entryPoint = "vs";
      pd.fragment = &fs;
      pd.depthStencil = &ds;
      clear_pipes_[m] = dev.CreateRenderPipeline(&pd);
    }
    b.size = 32;
    b.usage = wgpu::BufferUsage::Uniform | wgpu::BufferUsage::CopyDst;
    b.label = "clear";
    clear_buf_ = dev.CreateBuffer(&b);
  }
  // EFB -> texture conversion.
  {
    wgpu::BindGroupLayoutEntry ce[3]{};
    ce[0].binding = 0;
    ce[0].visibility = wgpu::ShaderStage::Fragment;
    ce[0].buffer.type = wgpu::BufferBindingType::Uniform;
    ce[1].binding = 1;
    ce[1].visibility = wgpu::ShaderStage::Fragment;
    ce[1].texture.sampleType = wgpu::TextureSampleType::UnfilterableFloat;
    ce[2].binding = 2;
    ce[2].visibility = wgpu::ShaderStage::Fragment;
    ce[2].texture.sampleType = wgpu::TextureSampleType::Depth;
    bd.entryCount = 3;
    bd.entries = ce;
    bgl_convert_ = dev.CreateBindGroupLayout(&bd);
    wgpu::PipelineLayoutDescriptor cpl{};
    cpl.bindGroupLayoutCount = 1;
    cpl.bindGroupLayouts = &bgl_convert_;
    wgpu::PipelineLayout clayout = dev.CreatePipelineLayout(&cpl);
    wgpu::ShaderModule sm = gpu.shader(kConvertWgsl, "efb convert");
    wgpu::ColorTargetState ct{};
    ct.format = wgpu::TextureFormat::RGBA8Unorm;
    wgpu::FragmentState fs{};
    fs.module = sm;
    fs.entryPoint = "fs";
    fs.targetCount = 1;
    fs.targets = &ct;
    wgpu::RenderPipelineDescriptor pd{};
    pd.label = "efb convert";
    pd.layout = clayout;
    pd.vertex.module = sm;
    pd.vertex.entryPoint = "vs";
    pd.fragment = &fs;
    convert_pipe_ = dev.CreateRenderPipeline(&pd);
    b.size = 32;
    b.label = "convert";
    convert_buf_ = dev.CreateBuffer(&b);
  }
  // The EFB starts cleared to black, depth far.
  EfbCopy c;
  c.width = kEfbWidth;
  c.height = kEfbHeight;
  c.clear_color = c.clear_alpha = c.clear_depth = true;
  c.clear_z = 0xFFFFFF;
  c.clear_rgba[3] = 255;
  clear_efb(c);
  flush();
}

Renderer::~Renderer() = default;

void Renderer::begin_pass() {
  if (pass_open_) return;
  encoder_ = gpu_.device().CreateCommandEncoder();
  wgpu::RenderPassColorAttachment ca{};
  ca.view = efb_color_view_;
  ca.loadOp = wgpu::LoadOp::Load;
  ca.storeOp = wgpu::StoreOp::Store;
  wgpu::RenderPassDepthStencilAttachment da{};
  da.view = efb_depth_view_;
  da.depthLoadOp = wgpu::LoadOp::Load;
  da.depthStoreOp = wgpu::StoreOp::Store;
  wgpu::RenderPassDescriptor rp{};
  rp.colorAttachmentCount = 1;
  rp.colorAttachments = &ca;
  rp.depthStencilAttachment = &da;
  pass_ = encoder_.BeginRenderPass(&rp);
  pass_open_ = true;
  ++pass_serial_;
  vdata_.clear();
  udata_.clear();
  ++stats_.passes;
}

void Renderer::flush() {
  if (!pass_open_) return;
  pass_.End();
  pass_ = nullptr;
  if (!vdata_.empty()) gpu_.queue().WriteBuffer(vbuf_, 0, vdata_.data(), vdata_.size());
  if (!udata_.empty()) gpu_.queue().WriteBuffer(ubuf_, 0, udata_.data(), udata_.size());
  wgpu::CommandBuffer cb = encoder_.Finish();
  gpu_.queue().Submit(1, &cb);
  encoder_ = nullptr;
  pass_open_ = false;
}

wgpu::RenderPipeline Renderer::pipeline(const PipelineConfig& c) {
  auto it = pipelines_.find(c);
  if (it != pipelines_.end()) return it->second;
  std::string wgsl = generate_wgsl(c);
  wgpu::ShaderModule& sm = modules_[wgsl];
  if (!sm) sm = gpu_.shader(wgsl, "tev");

  wgpu::VertexAttribute attrs[11]{};
  for (std::uint32_t k = 0; k < 11; ++k) {
    attrs[k].shaderLocation = k;
    if (k < 3) {
      attrs[k].format = wgpu::VertexFormat::Float32x4;
      attrs[k].offset = 16ull * k;
    } else {
      attrs[k].format = wgpu::VertexFormat::Float32x3;
      attrs[k].offset = 48ull + 12ull * (k - 3);
    }
  }
  wgpu::VertexBufferLayout vbl{};
  vbl.arrayStride = sizeof(OutVertex);
  vbl.attributeCount = 11;
  vbl.attributes = attrs;

  const bool has_alpha = efb_has_alpha(c.pixel_format);
  wgpu::BlendState blend{};
  wgpu::ColorTargetState ct{};
  ct.format = wgpu::TextureFormat::RGBA8Unorm;
  if (c.blend_enable) {
    if (c.blend_sub) {
      blend.color = {wgpu::BlendOperation::ReverseSubtract, wgpu::BlendFactor::One, wgpu::BlendFactor::One};
      blend.alpha = blend.color;
    } else {
      blend.color = {wgpu::BlendOperation::Add, blend_factor(c.blend_src, false, false, has_alpha),
                     blend_factor(c.blend_dst, true, false, has_alpha)};
      blend.alpha = {wgpu::BlendOperation::Add, blend_factor(c.blend_src, false, true, has_alpha),
                     blend_factor(c.blend_dst, true, true, has_alpha)};
    }
    ct.blend = &blend;
  }
  wgpu::ColorWriteMask mask = wgpu::ColorWriteMask::None;
  const bool noop = c.logic_enable && !c.blend_enable && c.logic_op == 5;
  if (c.color_update && !noop) mask = mask | wgpu::ColorWriteMask::Red | wgpu::ColorWriteMask::Green | wgpu::ColorWriteMask::Blue;
  if (c.alpha_update && has_alpha && !noop) mask = mask | wgpu::ColorWriteMask::Alpha;
  ct.writeMask = mask;

  wgpu::FragmentState fs{};
  fs.module = sm;
  fs.entryPoint = "fs_main";
  fs.targetCount = 1;
  fs.targets = &ct;
  wgpu::DepthStencilState ds{};
  ds.format = wgpu::TextureFormat::Depth32Float;
  ds.depthCompare = c.z_enable ? compare(c.z_func) : wgpu::CompareFunction::Always;
  ds.depthWriteEnabled = (c.z_enable && c.z_update) ? wgpu::OptionalBool::True : wgpu::OptionalBool::False;

  wgpu::RenderPipelineDescriptor pd{};
  pd.label = "tev";
  pd.layout = layout_;
  pd.vertex.module = sm;
  pd.vertex.entryPoint = "vs_main";
  pd.vertex.bufferCount = 1;
  pd.vertex.buffers = &vbl;
  pd.fragment = &fs;
  pd.depthStencil = &ds;
  const Topology topo = static_cast<Topology>(c.topology);
  pd.primitive.topology = topo == Topology::Lines    ? wgpu::PrimitiveTopology::LineList
                          : topo == Topology::Points ? wgpu::PrimitiveTopology::PointList
                                                     : wgpu::PrimitiveTopology::TriangleList;
  pd.primitive.frontFace = wgpu::FrontFace::CW;
  pd.primitive.cullMode = topo != Topology::Triangles ? wgpu::CullMode::None
                          : c.cull == 1               ? wgpu::CullMode::Back
                          : c.cull == 2               ? wgpu::CullMode::Front
                                                      : wgpu::CullMode::None;
  wgpu::RenderPipeline p = gpu_.device().CreateRenderPipeline(&pd);
  pipelines_.emplace(c, p);
  ++stats_.pipelines;
  return p;
}

std::uint64_t Renderer::hash_memory(std::uint32_t addr, std::uint32_t size) const {
  addr &= 0x01FFFFFFu;
  if (!mem_ || addr > mem_size_ || size > mem_size_ - addr) return 0;
  return hash_bytes(mem_ + addr, size);
}

wgpu::Sampler Renderer::sampler(const TextureDesc& t) {
  const std::uint32_t mip = bits(t.min_filter, 0, 2);
  const std::uint32_t key = t.wrap_s | t.wrap_t << 2 | t.mag_linear << 4 | bits(t.min_filter, 2, 1) << 5 |
                            (mip == 2 ? 1u : 0u) << 6 | (mip ? 1u : 0u) << 7 |
                            static_cast<std::uint32_t>(std::clamp(t.max_lod, 0.0f, 15.0f) * 16) << 8 |
                            static_cast<std::uint32_t>(std::clamp(t.min_lod, 0.0f, 15.0f) * 16) << 16;
  wgpu::Sampler& s = samplers_[key];
  if (!s) {
    wgpu::SamplerDescriptor sd{};
    sd.addressModeU = address(t.wrap_s);
    sd.addressModeV = address(t.wrap_t);
    sd.magFilter = t.mag_linear ? wgpu::FilterMode::Linear : wgpu::FilterMode::Nearest;
    sd.minFilter = bits(t.min_filter, 2, 1) ? wgpu::FilterMode::Linear : wgpu::FilterMode::Nearest;
    sd.mipmapFilter = mip == 2 ? wgpu::MipmapFilterMode::Linear : wgpu::MipmapFilterMode::Nearest;
    sd.lodMinClamp = mip ? t.min_lod : 0.0f;
    sd.lodMaxClamp = mip ? std::max(t.min_lod, t.max_lod) : 0.0f;
    s = gpu_.device().CreateSampler(&sd);
  }
  return s;
}

wgpu::TextureView Renderer::texture(const TextureDesc& t, std::uint32_t* w, std::uint32_t* h) {
  *w = t.width;
  *h = t.height;
  // An EFB copy at this address (the copy lives only on the GPU).
  auto ci = copies_.find(t.addr & 0x01FFFFFFu);
  if (ci != copies_.end()) {
    CopyEntry& e = *ci->second;
    if (e.epoch != epoch_) {  // memory written there since the copy means the CPU replaced it
      if (hash_memory(t.addr, e.bytes) != e.mem_hash) {
        copies_.erase(ci);
        ci = copies_.end();
      } else {
        e.epoch = epoch_;
      }
    }
    if (ci != copies_.end() && e.w == t.width && e.h == t.height) {
      ++stats_.copy_textures_used;
      return e.view;
    }
  }
  if (!texture_format_known(t.format)) {
    ++stats_.unknown_formats;
    return dummy_view_;
  }
  const std::uint32_t bytes = texture_size(t.format, t.width, t.height, t.levels);
  std::uint64_t tlut_hash = 0;
  if (t.tlut) tlut_hash = hash_bytes(t.tlut, static_cast<std::size_t>(t.tlut_entries) * 2, t.tlut_format + 1u);
  const std::uint64_t key = mix64(t.addr ^ (std::uint64_t(t.format) << 32) ^ (std::uint64_t(t.width) << 36) ^
                                  (std::uint64_t(t.height) << 48) ^ (std::uint64_t(t.levels) << 60)) ^
                            tlut_hash;
  std::unique_ptr<TexEntry>& slot = textures_[key];
  if (slot && slot->epoch == epoch_) {
    ++stats_.texture_hits;
    slot->pass = pass_open_ ? pass_serial_ : pass_serial_ + 1;
    return slot->view;
  }
  const std::uint64_t mh = hash_memory(t.addr, bytes);
  if (slot && slot->mem_hash == mh) {
    slot->epoch = epoch_;
    slot->pass = pass_open_ ? pass_serial_ : pass_serial_ + 1;
    ++stats_.texture_hits;
    return slot->view;
  }
  const std::uint32_t a = t.addr & 0x01FFFFFFu;
  if (!mem_ || a > mem_size_ || bytes > mem_size_ - a) return dummy_view_;
  // The open pass may already sample this texture's old contents: submit it
  // before the upload replaces them.
  if (slot && pass_open_ && slot->pass == pass_serial_) flush();
  if (!slot) {
    slot = std::make_unique<TexEntry>();
    wgpu::TextureDescriptor td{};
    td.size = {t.width, t.height, 1};
    td.format = wgpu::TextureFormat::RGBA8Unorm;
    td.mipLevelCount = t.levels;
    td.usage = wgpu::TextureUsage::TextureBinding | wgpu::TextureUsage::CopyDst;
    slot->tex = gpu_.device().CreateTexture(&td);
    slot->view = slot->tex.CreateView();
    slot->w = t.width;
    slot->h = t.height;
  }
  // Decode and upload every level.
  std::uint32_t lw = t.width, lh = t.height, off = 0;
  std::vector<std::uint8_t> rgba;
  for (std::uint32_t l = 0; l < t.levels; ++l) {
    rgba.resize(static_cast<std::size_t>(lw) * lh * 4);
    decode_texture(t.format, lw, lh, mem_ + a + off, rgba.data(), t.tlut, t.tlut_format, t.tlut_entries);
    wgpu::TexelCopyTextureInfo dst{};
    dst.texture = slot->tex;
    dst.mipLevel = l;
    wgpu::TexelCopyBufferLayout lay{};
    lay.bytesPerRow = lw * 4;
    lay.rowsPerImage = lh;
    wgpu::Extent3D ext{lw, lh, 1};
    gpu_.queue().WriteTexture(&dst, rgba.data(), rgba.size(), &lay, &ext);
    off += texture_level_size(t.format, lw, lh);
    lw = lw > 1 ? lw / 2 : 1;
    lh = lh > 1 ? lh / 2 : 1;
  }
  slot->mem_hash = mh;
  slot->epoch = epoch_;
  slot->pass = pass_open_ ? pass_serial_ : pass_serial_ + 1;
  ++stats_.textures_decoded;
  return slot->view;
}

void Renderer::draw(const DrawCall& d) {
  const PipelineConfig& c = d.cfg;
  if (c.cull == 3 && static_cast<Topology>(c.topology) == Topology::Triangles) {
    ++stats_.skipped;
    return;
  }
  if (d.scissor[2] <= d.scissor[0] || d.scissor[3] <= d.scissor[1]) {
    ++stats_.skipped;
    return;
  }
  const std::size_t vbytes = d.verts.size() * sizeof(OutVertex);
  if (vbytes > kVertexCapacity) {
    ++stats_.skipped;
    return;
  }
  if (pass_open_ && (vdata_.size() + vbytes > kVertexCapacity || udata_.size() + kUniformSlot > kUniformCapacity))
    flush();
  // Textures first: decoding uploads with the queue, which must precede the pass's submit (it does).
  wgpu::BindGroupEntry te[16]{};
  for (int k = 0; k < 8; ++k) {
    te[k].binding = static_cast<std::uint32_t>(k);
    te[k].textureView = dummy_view_;
    te[8 + k].binding = static_cast<std::uint32_t>(8 + k);
    te[8 + k].sampler = dummy_sampler_;
  }
  DrawUniforms u = d.u;
  for (int k = 0; k < 8; ++k) {
    const TextureDesc& t = d.tex[static_cast<std::size_t>(k)];
    if (!t.valid) continue;
    std::uint32_t w = 0, h = 0;
    te[k].textureView = texture(t, &w, &h);
    te[8 + k].sampler = sampler(t);
  }
  for (int s = 0; s < c.num_stages; ++s)
    if (c.stages[s].ind_cmd) {
      ++stats_.indirect_draws;
      break;
    }
  if (c.fog_type) ++stats_.fog_draws;
  wgpu::RenderPipeline p = pipeline(c);
  wgpu::BindGroupDescriptor bgd{};
  bgd.layout = bgl_textures_;
  bgd.entryCount = 16;
  bgd.entries = te;
  wgpu::BindGroup tg = gpu_.device().CreateBindGroup(&bgd);

  begin_pass();
  const std::uint32_t uoff = static_cast<std::uint32_t>(udata_.size());
  udata_.resize(udata_.size() + kUniformSlot, 0);
  std::memcpy(udata_.data() + uoff, &u, sizeof u);
  const std::uint64_t voff = vdata_.size();
  vdata_.resize(vdata_.size() + vbytes);
  std::memcpy(vdata_.data() + voff, d.verts.data(), vbytes);

  pass_.SetPipeline(p);
  pass_.SetBindGroup(0, uniform_group_, 1, &uoff);
  pass_.SetBindGroup(1, tg);
  pass_.SetVertexBuffer(0, vbuf_, voff, vbytes);
  pass_.SetScissorRect(d.scissor[0], d.scissor[1], d.scissor[2] - d.scissor[0], d.scissor[3] - d.scissor[1]);
  pass_.Draw(static_cast<std::uint32_t>(d.verts.size()));
  ++stats_.draws;
}

void Renderer::clear_efb(const EfbCopy& c) {
  ++stats_.clears;
  const bool has_alpha = efb_has_alpha(c.pixel_format);
  // Formats without alpha keep the EFB's alpha at 1 (written with the color).
  const bool alpha = has_alpha ? c.clear_alpha : c.clear_color;
  const int m = (c.clear_color ? 1 : 0) | (alpha ? 2 : 0) | (c.clear_depth ? 4 : 0);
  if (m == 0) return;
  float data[8] = {c.clear_rgba[0] / 255.0f, c.clear_rgba[1] / 255.0f, c.clear_rgba[2] / 255.0f,
                   has_alpha ? c.clear_rgba[3] / 255.0f : 1.0f, static_cast<float>(c.clear_z) / 16777215.0f, 0, 0, 0};
  flush();
  gpu_.queue().WriteBuffer(clear_buf_, 0, data, sizeof data);
  wgpu::BindGroupEntry be{};
  be.binding = 0;
  be.buffer = clear_buf_;
  be.size = 32;
  wgpu::BindGroupDescriptor bgd{};
  bgd.layout = bgl_clear_;
  bgd.entryCount = 1;
  bgd.entries = &be;
  wgpu::BindGroup bg = gpu_.device().CreateBindGroup(&bgd);
  begin_pass();
  pass_.SetPipeline(clear_pipes_[m]);
  pass_.SetBindGroup(0, bg);
  std::uint32_t x0 = std::min(c.src_x, kEfbWidth), y0 = std::min(c.src_y, kEfbHeight);
  std::uint32_t x1 = std::min(c.src_x + c.width, kEfbWidth), y1 = std::min(c.src_y + c.height, kEfbHeight);
  if (x1 <= x0 || y1 <= y0) return;
  pass_.SetScissorRect(x0, y0, x1 - x0, y1 - y0);
  pass_.Draw(3);
  // The clear must land before the next clear rewrites its buffer.
  flush();
}

void Renderer::copy_to_texture(const EfbCopy& c) {
  ++stats_.tex_copies;
  const std::uint32_t w = c.half_scale ? std::max(1u, c.width / 2) : c.width;
  const std::uint32_t h = c.half_scale ? std::max(1u, c.height / 2) : c.height;
  const std::uint32_t addr = c.dest & 0x01FFFFFFu;
  std::unique_ptr<CopyEntry>& e = copies_[addr];
  if (!e || e->w != w || e->h != h) {
    e = std::make_unique<CopyEntry>();
    wgpu::TextureDescriptor td{};
    td.size = {w, h, 1};
    td.format = wgpu::TextureFormat::RGBA8Unorm;
    td.usage = wgpu::TextureUsage::TextureBinding | wgpu::TextureUsage::RenderAttachment | wgpu::TextureUsage::CopySrc;
    td.label = "efb copy";
    e->tex = gpu_.device().CreateTexture(&td);
    e->view = e->tex.CreateView();
    e->w = w;
    e->h = h;
  }
  // What a texture of this format and size covers in memory; the copy stays
  // valid while those bytes are unchanged.
  const std::uint8_t sample_fmt = c.tex_format <= 6 ? c.tex_format : kTexI8;
  e->bytes = texture_level_size(sample_fmt, w, h);
  e->mem_hash = hash_memory(addr, e->bytes);
  e->epoch = epoch_;

  std::int32_t params[8] = {static_cast<std::int32_t>(c.src_x), static_cast<std::int32_t>(c.src_y),
                            c.half_scale ? 1 : 0, c.pixel_format == 3 ? 1 : 0,
                            static_cast<std::int32_t>(c.tex_format), c.intensity ? 1 : 0, 0, 0};
  gpu_.queue().WriteBuffer(convert_buf_, 0, params, sizeof params);
  wgpu::BindGroupEntry be[3]{};
  be[0].binding = 0;
  be[0].buffer = convert_buf_;
  be[0].size = 32;
  be[1].binding = 1;
  be[1].textureView = efb_color_view_;
  be[2].binding = 2;
  be[2].textureView = efb_depth_view_;
  wgpu::BindGroupDescriptor bgd{};
  bgd.layout = bgl_convert_;
  bgd.entryCount = 3;
  bgd.entries = be;
  wgpu::BindGroup bg = gpu_.device().CreateBindGroup(&bgd);
  wgpu::CommandEncoder enc = gpu_.device().CreateCommandEncoder();
  wgpu::RenderPassColorAttachment ca{};
  ca.view = e->view;
  ca.loadOp = wgpu::LoadOp::Clear;
  ca.storeOp = wgpu::StoreOp::Store;
  wgpu::RenderPassDescriptor rp{};
  rp.colorAttachmentCount = 1;
  rp.colorAttachments = &ca;
  wgpu::RenderPassEncoder pass = enc.BeginRenderPass(&rp);
  pass.SetPipeline(convert_pipe_);
  pass.SetBindGroup(0, bg);
  pass.Draw(3);
  pass.End();
  wgpu::CommandBuffer cb = enc.Finish();
  gpu_.queue().Submit(1, &cb);
}

void Renderer::efb_copy(const EfbCopy& c) {
  flush();
  const std::uint32_t x0 = std::min(c.src_x, kEfbWidth), y0 = std::min(c.src_y, kEfbHeight);
  const std::uint32_t w = std::min(c.width, kEfbWidth - x0), h = std::min(c.height, kEfbHeight - y0);
  if (w && h) {
    if (c.to_xfb) {
      ++stats_.xfb_copies;
      Frame& f = frames_[c.dest & 0x01FFFFFFu];
      if (!f.tex || f.width != w || f.height != h) {
        wgpu::TextureDescriptor td{};
        td.size = {w, h, 1};
        td.format = wgpu::TextureFormat::RGBA8Unorm;
        td.usage = wgpu::TextureUsage::TextureBinding | wgpu::TextureUsage::CopyDst | wgpu::TextureUsage::CopySrc;
        td.label = "xfb";
        f.tex = gpu_.device().CreateTexture(&td);
        f.view = f.tex.CreateView();
        f.width = w;
        f.height = h;
      }
      f.addr = c.dest & 0x01FFFFFFu;
      f.serial = ++serial_;
      latest_ = &f;
      wgpu::CommandEncoder enc = gpu_.device().CreateCommandEncoder();
      wgpu::TexelCopyTextureInfo src{};
      src.texture = efb_color_;
      src.origin = {x0, y0, 0};
      wgpu::TexelCopyTextureInfo dst{};
      dst.texture = f.tex;
      wgpu::Extent3D ext{w, h, 1};
      enc.CopyTextureToTexture(&src, &dst, &ext);
      wgpu::CommandBuffer cb = enc.Finish();
      gpu_.queue().Submit(1, &cb);
    } else {
      EfbCopy cc = c;
      cc.src_x = x0;
      cc.src_y = y0;
      cc.width = w;
      cc.height = h;
      copy_to_texture(cc);
    }
  }
  if (c.clear) clear_efb(c);
}

const Renderer::Frame* Renderer::xfb(std::uint32_t addr) const {
  auto it = frames_.find(addr & 0x01FFFFFFu);
  return it == frames_.end() ? nullptr : &it->second;
}

std::vector<std::uint8_t> Renderer::read_frame(const Frame& f) {
  flush();
  auto px = gpu_.read_texture(f.tex, f.width, f.height);
  for (std::size_t i = 3; i < px.size(); i += 4) px[i] = 255;  // the XFB has no alpha
  return px;
}

std::vector<std::uint8_t> Renderer::read_efb() {
  flush();
  return gpu_.read_texture(efb_color_, kEfbWidth, kEfbHeight);
}

}  // namespace mvp::gfx
