// A desktop window (SDL3) with a WebGPU surface, and a blit that shows a
// texture in it (E1). The browser build replaces this with a canvas (E2).
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
  // Opens a window of `width` x `height` (client area) and creates its surface.
  static std::unique_ptr<Window> open(const char* title, int width, int height, std::string* err);
  ~Window();

  // Creates and configures the surface for `gpu` and builds the blit
  // pipeline. Call once.
  bool attach(Gpu& gpu, std::string* err);

  // Handles pending window events; false once the user closed the window.
  bool pump();

  // Shows `src` (a 2D texture with TextureBinding usage) scaled to the window,
  // keeping its aspect ratio, then presents.
  void present(const wgpu::TextureView& src, std::uint32_t src_width, std::uint32_t src_height);

 private:
  Window() = default;
  void configure();

  SDL_Window* window_ = nullptr;
  Gpu* gpu_ = nullptr;
  wgpu::Surface surface_;
  wgpu::TextureFormat format_ = wgpu::TextureFormat::BGRA8Unorm;
  wgpu::RenderPipeline blit_;
  wgpu::Sampler sampler_;
  wgpu::Buffer params_;
  int width_ = 0, height_ = 0;
  bool configured_ = false;
};

}  // namespace mvp::gfx
