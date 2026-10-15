// Where frames are shown, with a WebGPU surface and a blit that shows a
// texture in it (E1, E2). Natively a desktop window (SDL3); in the browser a
// canvas (an OffscreenCanvas when the engine runs in a Worker), found by its
// CSS selector through emdawnwebgpu (the page registers it). The blit and the
// presentation logic are the same code on both.
//
// Window events (close, resize) are host input. They may stop the run or
// change how frames are shown; they never reach guest state (determinism).
#pragma once

#include <webgpu/webgpu_cpp.h>

#include <cstdint>
#include <memory>
#include <string>

struct SDL_Window;

namespace mvp::gfx {

class Gpu;

class Window {
 public:
#ifndef __EMSCRIPTEN__
  // Opens a window of `width` x `height` (client area) and creates its surface.
  static std::unique_ptr<Window> open(const char* title, int width, int height, std::string* err);
#else
  // Browser: the canvas `selector` names (emdawnwebgpu looks it up in the
  // module's specialHTMLTargets first, then in the document), drawn at
  // `width` x `height` pixels.
  static std::unique_ptr<Window> open_canvas(const char* selector, int width, int height, std::string* err);
  // The canvas's drawing buffer size changed (the page's layout or zoom).
  void resize(int width, int height);
#endif
  ~Window();

  // Creates and configures the surface for `gpu` and builds the blit
  // pipeline. Call once.
  bool attach(Gpu& gpu, std::string* err);

  // Present without waiting for the display when the surface supports it
  // (mailbox: the newest frame is shown at each refresh; E3c). The caller then
  // paces the frames itself. Call before attach(). Default: FIFO.
  void prefer_mailbox(bool on) { want_mailbox_ = on; }
  const char* present_mode_name() const;

  // Handles pending window events; false once the user closed the window.
  // (The browser's page handles its own events: always true there.)
  bool pump();

  // Shows `src` (a 2D texture with TextureBinding usage) scaled to the window
  // at the display's aspect ratio (below), centered on black, then presents. In
  // the browser the frame goes to the canvas when the current task returns to
  // the event loop.
  //
  // Q1: the scaling. Larger than the window (2x and 3x internal resolution, or
  // a small window): an area filter (each pixel the mean of the source over its
  // footprint), so nothing shimmers. Smaller: sharp bilinear (each source pixel
  // a block of whole window pixels, blended only along the block edges), so a
  // 1x picture stays crisp at any size without uneven pixels.
  void present(const wgpu::TextureView& src, std::uint32_t src_width, std::uint32_t src_height);

  // Q1: the picture's aspect ratio on screen. The game draws a 640 x 448 frame
  // for a 4:3 television (its 3D cameras use a 4:3 aspect), so 4:3 by default;
  // 0 shows the frame's own pixel shape (square pixels, as before).
  void set_display_aspect(float a) { display_aspect_ = a; }

  // Configures the surface again (P2: a canvas whose picture was taken as an
  // ImageBitmap may have lost its configuration).
  void reconfigure() {
    if (gpu_) configure();
  }

 private:
  Window() = default;
  void configure();

#ifndef __EMSCRIPTEN__
  SDL_Window* window_ = nullptr;
#else
  std::string selector_;
#endif
  Gpu* gpu_ = nullptr;
  wgpu::Surface surface_;
  wgpu::TextureFormat format_ = wgpu::TextureFormat::BGRA8Unorm;
  wgpu::RenderPipeline blit_;
  wgpu::Sampler sampler_;
  wgpu::Buffer params_;
  int width_ = 0, height_ = 0;
  float display_aspect_ = 4.0f / 3.0f;
  bool configured_ = false;
  bool want_mailbox_ = false, have_mailbox_ = false;
  wgpu::PresentMode mode_ = wgpu::PresentMode::Fifo;
};

}  // namespace mvp::gfx
