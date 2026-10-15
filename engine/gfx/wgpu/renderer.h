// The WebGPU backend (E1): draws the GX state machine's DrawCalls into an
// emulated EFB (640 x 528 RGBA8 + 32-bit float depth), performs EFB copies
// (to XFB frames kept per address, or to textures that later draws sample in
// place of guest memory), and keeps the decoded-texture, sampler and pipeline
// caches. Only reads guest memory.
//
// Draws are recorded into one render pass on the EFB until something needs
// the result (an EFB copy, a read-back, the end of a frame): flush() uploads
// the pass's vertices and uniforms and submits.
#pragma once

#include <webgpu/webgpu_cpp.h>

#include <array>
#include <cstdint>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "gfx/draw.h"

namespace mvp::gfx {

class Gpu;

class Renderer : public Backend {
 public:
  Renderer(Gpu& gpu, const std::uint8_t* mem, std::uint32_t mem_size);
  ~Renderer() override;

  void draw(const DrawCall& d) override;
  void efb_copy(const EfbCopy& c) override;
  void invalidate_textures() override { ++epoch_; }

  // Ends the open render pass (if any) and submits it.
  void flush();

  // An XFB copy: the frame the video interface shows when it scans `addr`.
  struct Frame {
    wgpu::Texture tex;
    wgpu::TextureView view;
    std::uint32_t width = 0, height = 0, addr = 0;
    std::uint64_t serial = 0;
  };
  // The frame last copied to `addr`, else null.
  const Frame* xfb(std::uint32_t addr) const;
  // The most recent XFB copy, else null.
  const Frame* latest_xfb() const { return latest_; }
  // Reads a frame back as RGBA8 rows (blocks; flushes first).
  std::vector<std::uint8_t> read_frame(const Frame& f);
  // Reads the EFB color back (640 x 528 RGBA8).
  std::vector<std::uint8_t> read_efb();

  struct Stats {
    std::uint64_t draws = 0, skipped = 0, passes = 0, pipelines = 0, textures_decoded = 0, texture_hits = 0;
    std::uint64_t copy_textures_used = 0, xfb_copies = 0, tex_copies = 0, clears = 0;
    std::uint64_t unknown_formats = 0, indirect_draws = 0, fog_draws = 0;
    std::uint64_t merged = 0, encoded = 0;  // draws appended to the previous one; WebGPU draws encoded
    std::uint64_t same_state = 0;           // draws that reused the previous draw's resolved state
    std::uint64_t tmem_textures = 0;        // preloaded (TMEM) textures decoded
    std::uint64_t vertex_bytes = 0, index_bytes = 0;  // uploaded
  };
  const Stats& stats() const { return stats_; }

 private:
  // A pipeline and its vertex layout (which attributes, the stride).
  struct Pipeline {
    wgpu::RenderPipeline pipe;
    std::uint32_t attrs = 0, stride = 16;
  };
  struct TexEntry;
  struct CopyEntry;
  struct CfgHash {
    std::size_t operator()(const PipelineConfig& c) const;
  };

  void begin_pass();
  void emit_pending();
  const Pipeline& pipeline(const PipelineConfig& c);
  wgpu::TextureView texture(const TextureDesc& t, std::uint32_t* w, std::uint32_t* h);
  wgpu::Sampler sampler(const TextureDesc& t);
  wgpu::TextureView tmem_texture(const TextureDesc& t);
  void clear_efb(const EfbCopy& c);
  void copy_to_texture(const EfbCopy& c);
  std::uint64_t hash_memory(std::uint32_t addr, std::uint32_t size) const;

  Gpu& gpu_;
  const std::uint8_t* mem_;
  std::uint32_t mem_size_;

  wgpu::Texture efb_color_, efb_depth_;
  wgpu::TextureView efb_color_view_, efb_depth_view_;
  wgpu::BindGroupLayout bgl_uniforms_, bgl_textures_;
  wgpu::PipelineLayout layout_;
  wgpu::Buffer vbuf_, ubuf_, ibuf_;
  wgpu::BindGroup uniform_group_;
  wgpu::Texture dummy_tex_;
  wgpu::TextureView dummy_view_;
  wgpu::Sampler dummy_sampler_;

  // The open pass.
  wgpu::CommandEncoder encoder_;
  wgpu::RenderPassEncoder pass_;
  bool pass_open_ = false;
  std::uint64_t pass_serial_ = 0;
  std::vector<std::uint8_t> vdata_, udata_;
  std::vector<std::uint32_t> idata_;
  // The last draw, recorded but not encoded yet: a next draw with the same
  // pipeline, textures, constants and scissor appends its vertices and indices
  // to it (the game sends thousands of small primitives with one state). Its
  // vertices start at `base` (in strides) in the pass's vertex buffer.
  struct Pending {
    bool active = false;
    wgpu::RenderPipeline pipeline;
    wgpu::BindGroup textures;
    std::uint32_t uoff = 0, first_index = 0, index_count = 0, base = 0, vertices = 0, stride = 0;
    std::uint32_t scissor[4] = {};
    std::uint64_t state = 0;
    DrawUniforms u;
  } pending_;
  // The previous draw's resolved state (E3c): a draw with the same nonzero
  // DrawCall::state and topology, in the same open pass and texture epoch,
  // samples the same textures with the same pipeline and constants.
  struct Last {
    std::uint64_t state = 0, pass = 0, epoch = 0;
    std::uint8_t topology = 0xFF;
    const Pipeline* pipe = nullptr;
    wgpu::BindGroup textures;
    bool indirect = false, fog = false;
  } last_;
  // What the open pass has bound, to skip repeated state.
  const void* bound_pipeline_ = nullptr;
  const void* bound_textures_ = nullptr;
  std::uint32_t bound_uoff_ = ~0u;
  std::uint32_t bound_scissor_[4] = {};
  bool bound_vbuf_ = false;
  bool bound_ibuf_ = false;

  std::unordered_map<PipelineConfig, Pipeline, CfgHash> pipelines_;
  std::unordered_map<std::string, wgpu::ShaderModule> modules_;
  std::map<std::uint64_t, std::unique_ptr<TexEntry>> textures_;
  std::map<std::uint32_t, std::unique_ptr<CopyEntry>> copies_;  // EFB copies to textures, by address
  std::map<std::uint64_t, std::unique_ptr<TexEntry>> tmem_textures_;  // preloaded textures, by content
  std::vector<std::uint8_t> tmem_buf_;
  std::map<std::uint32_t, wgpu::Sampler> samplers_;
  std::map<std::array<const void*, 16>, wgpu::BindGroup> bind_groups_;
  std::uint64_t epoch_ = 1;

  // Clears and EFB-to-texture conversion.
  wgpu::RenderPipeline clear_pipes_[8];
  wgpu::BindGroupLayout bgl_clear_;
  wgpu::Buffer clear_buf_;
  wgpu::RenderPipeline convert_pipe_;
  wgpu::BindGroupLayout bgl_convert_;
  wgpu::Buffer convert_buf_;
  wgpu::Sampler point_sampler_;

  std::map<std::uint32_t, Frame> frames_;
  const Frame* latest_ = nullptr;
  std::uint64_t serial_ = 0;
  Stats stats_;
};

}  // namespace mvp::gfx
