// The engine's rendering side in the browser (P2): the GX processor, the WebGPU
// renderer and the canvas, and what the page's tools read of them (the
// presentation trace, the renderer digest, statistics). The single-threaded
// engine drives it inline from the emulation (mvp_web.cpp); the threaded engine
// drives it on the render thread from the command ring (render_thread.cpp).
// Either way it sees the same calls in the same order. It only reads guest
// memory.
#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include "gfx/digest_tap.h"
#include "gfx/draw.h"
#include "gfx/gx_processor.h"
#include "gfx/wgpu/gpu.h"
#include "gfx/wgpu/renderer.h"
#include "gfx/wgpu/window.h"

namespace mvp::web {

// Presentation trace (P1, development): every VI field's frame buffer address,
// every XFB copy and what each present showed, as JSON records. The tap sits
// between the GX processor and the renderer and forwards everything unchanged.
struct XfbTap : gfx::Backend {
  gfx::Backend* next = nullptr;
  bool on = false;
  std::string log;
  std::uint64_t copies = 0;     // XFB copies seen
  std::uint64_t field = 0;      // VI fields so far (the last field seen)
  void draw(const gfx::DrawCall& d) override { next->draw(d); }
  void efb_copy(const gfx::EfbCopy& c) override;
  void invalidate_textures() override { next->invalidate_textures(); }
};

class RenderSide {
 public:
  // The device and the canvas (set by whoever created them), and why not.
  std::unique_ptr<gfx::Gpu> gpu;
  std::unique_ptr<gfx::Window> window;
  std::string error;

  // Guest memory; the GX processor and the renderer are created once the device,
  // the canvas and memory are all there (attach()).
  void set_memory(const std::uint8_t* mem, std::uint32_t size);
  void attach();
  bool attached() const { return renderer_ != nullptr; }

  void gx(const std::uint8_t* cmd, std::size_t len) {
    if (proc_) proc_->command(cmd, len);
  }
  // A VI field ended; `xfb` is the frame buffer the VI scans.
  void vi_field(std::uint64_t field, std::uint32_t xfb);
  // Shows the frame the VI scans out. `frame_polls` is for the trace. True if drawn.
  bool present(std::uint64_t frame_polls, double now_ms);
  void flush() {
    if (renderer_) renderer_->flush();
  }
  void resize(int width, int height);

  void set_trace(bool on) { tap_.on = on; }
  std::string trace_take();      // the records since the last call, as a JSON array
  std::string trace_take_raw();  // the same records, comma-terminated, without the brackets
  // The renderer digest (gfx/digest_tap.h): on from the next command; one
  // "field digest draws" line per VI field.
  void set_digest(bool on) { digest_.on = on; }
  std::string digest_take();

  // ",\"draws\":..." members for mvp_status (empty without a renderer).
  std::string status_json() const;
  std::uint64_t presents() const { return presents_; }
  std::uint64_t resizes() const { return resizes_; }

 private:
  const std::uint8_t* mem_ = nullptr;
  std::uint32_t mem_size_ = 0;
  std::unique_ptr<gfx::Renderer> renderer_;
  std::unique_ptr<gfx::GxProcessor> proc_;
  gfx::DigestTap digest_;
  XfbTap tap_;
  std::string digest_log_;
  std::uint32_t xfb_ = 0;
  std::uint64_t presents_ = 0, last_presented_ = 0, copies_at_present_ = 0, resizes_ = 0;
};

}  // namespace mvp::web
