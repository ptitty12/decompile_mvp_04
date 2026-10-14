// WebGPU device (E1): instance, adapter, device and queue through webgpu.h's
// C++ wrapper. Natively this is Dawn; under Emscripten (E2) the same API comes
// from emdawnwebgpu, so nothing here may depend on Dawn-only entry points
// except where marked.
//
// The renderer only reads guest state. Nothing the GPU computes flows back
// into the guest (determinism: docs/engine/E1_LOG.md, "Determinism").
#pragma once

#include <webgpu/webgpu_cpp.h>

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace mvp::gfx {

class Gpu {
 public:
  // Creates a device on the default adapter (high performance). Returns null
  // with `err` set when there is no adapter or device.
  static std::unique_ptr<Gpu> create(std::string* err);

  const wgpu::Instance& instance() const { return instance_; }
  const wgpu::Adapter& adapter() const { return adapter_; }
  const wgpu::Device& device() const { return device_; }
  const wgpu::Queue& queue() const { return queue_; }
  const std::string& adapter_name() const { return adapter_name_; }

  // Validation errors reported by the device since creation (printed too).
  std::uint64_t errors() const { return *errors_; }

  // Blocks until the queue has finished all submitted work.
  void wait_idle();

  // Reads a whole RGBA8Unorm (or BGRA8Unorm) 2D texture back to host memory
  // as tightly packed rows (the texture needs CopySrc usage). Blocks.
  std::vector<std::uint8_t> read_texture(const wgpu::Texture& texture, std::uint32_t width, std::uint32_t height);

  // Compiles WGSL; a compile error is reported through errors().
  wgpu::ShaderModule shader(const std::string& wgsl, const char* label = nullptr);

 private:
  wgpu::Instance instance_;
  wgpu::Adapter adapter_;
  wgpu::Device device_;
  wgpu::Queue queue_;
  std::string adapter_name_;
  std::shared_ptr<std::uint64_t> errors_ = std::make_shared<std::uint64_t>(0);
};

}  // namespace mvp::gfx
