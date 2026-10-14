#include "gfx/wgpu/gpu.h"

#include <cstdio>
#include <cstring>

namespace mvp::gfx {

namespace {

std::string to_string(wgpu::StringView s) {
  if (!s.data) return {};
  if (s.length == wgpu::kStrlen) return std::string(s.data);
  return std::string(s.data, s.length);
}

}  // namespace

std::unique_ptr<Gpu> Gpu::create(std::string* err) {
  auto g = std::unique_ptr<Gpu>(new Gpu());
  static const wgpu::InstanceFeatureName kFeatures[] = {wgpu::InstanceFeatureName::TimedWaitAny};
  wgpu::InstanceDescriptor idesc{};
  idesc.requiredFeatureCount = 1;
  idesc.requiredFeatures = kFeatures;
  g->instance_ = wgpu::CreateInstance(&idesc);
  if (!g->instance_) {
    if (err) *err = "wgpuCreateInstance failed";
    return nullptr;
  }

  wgpu::RequestAdapterOptions opts{};
  opts.powerPreference = wgpu::PowerPreference::HighPerformance;
  std::string adapter_error;
  wgpu::Future f = g->instance_.RequestAdapter(
      &opts, wgpu::CallbackMode::WaitAnyOnly,
      [&](wgpu::RequestAdapterStatus status, wgpu::Adapter adapter, wgpu::StringView message) {
        if (status == wgpu::RequestAdapterStatus::Success) g->adapter_ = std::move(adapter);
        else adapter_error = to_string(message);
      });
  g->instance_.WaitAny(f, UINT64_MAX);
  if (!g->adapter_) {
    if (err) *err = "no WebGPU adapter: " + adapter_error;
    return nullptr;
  }
  wgpu::AdapterInfo info{};
  g->adapter_.GetInfo(&info);
  g->adapter_name_ = to_string(info.device) + " (" + to_string(info.description) + ")";

  wgpu::DeviceDescriptor ddesc{};
  ddesc.label = "mvp";
  ddesc.SetUncapturedErrorCallback(
      [](const wgpu::Device&, wgpu::ErrorType type, wgpu::StringView message, std::uint64_t* errors) {
        ++*errors;
        std::fprintf(stderr, "gfx: WebGPU error %d: %s\n", static_cast<int>(type), to_string(message).c_str());
      },
      g->errors_.get());
  ddesc.SetDeviceLostCallback(wgpu::CallbackMode::AllowSpontaneous,
                              [](const wgpu::Device&, wgpu::DeviceLostReason reason, wgpu::StringView message) {
                                if (reason == wgpu::DeviceLostReason::Destroyed) return;
                                std::fprintf(stderr, "gfx: WebGPU device lost (%d): %s\n", static_cast<int>(reason),
                                             to_string(message).c_str());
                              });
  std::string device_error;
  f = g->adapter_.RequestDevice(&ddesc, wgpu::CallbackMode::WaitAnyOnly,
                                [&](wgpu::RequestDeviceStatus status, wgpu::Device device, wgpu::StringView message) {
                                  if (status == wgpu::RequestDeviceStatus::Success) g->device_ = std::move(device);
                                  else device_error = to_string(message);
                                });
  g->instance_.WaitAny(f, UINT64_MAX);
  if (!g->device_) {
    if (err) *err = "no WebGPU device: " + device_error;
    return nullptr;
  }
  g->queue_ = g->device_.GetQueue();
  return g;
}

void Gpu::wait_idle() {
  bool done = false;
  wgpu::Future f = queue_.OnSubmittedWorkDone(wgpu::CallbackMode::WaitAnyOnly,
                                              [&](wgpu::QueueWorkDoneStatus, wgpu::StringView) { done = true; });
  instance_.WaitAny(f, UINT64_MAX);
  (void)done;
}

std::vector<std::uint8_t> Gpu::read_texture(const wgpu::Texture& texture, std::uint32_t width, std::uint32_t height) {
  const std::uint32_t row = width * 4;
  const std::uint32_t padded = (row + 255) & ~255u;
  wgpu::BufferDescriptor bd{};
  bd.size = static_cast<std::uint64_t>(padded) * height;
  bd.usage = wgpu::BufferUsage::CopyDst | wgpu::BufferUsage::MapRead;
  wgpu::Buffer buf = device_.CreateBuffer(&bd);
  wgpu::CommandEncoder enc = device_.CreateCommandEncoder();
  wgpu::TexelCopyTextureInfo src{};
  src.texture = texture;
  wgpu::TexelCopyBufferInfo dst{};
  dst.buffer = buf;
  dst.layout.bytesPerRow = padded;
  dst.layout.rowsPerImage = height;
  wgpu::Extent3D size{width, height, 1};
  enc.CopyTextureToBuffer(&src, &dst, &size);
  wgpu::CommandBuffer cb = enc.Finish();
  queue_.Submit(1, &cb);
  bool ok = false;
  wgpu::Future f = buf.MapAsync(wgpu::MapMode::Read, 0, bd.size, wgpu::CallbackMode::WaitAnyOnly,
                                [&](wgpu::MapAsyncStatus status, wgpu::StringView) {
                                  ok = status == wgpu::MapAsyncStatus::Success;
                                });
  instance_.WaitAny(f, UINT64_MAX);
  std::vector<std::uint8_t> out(static_cast<std::size_t>(row) * height);
  if (!ok) return {};
  const auto* p = static_cast<const std::uint8_t*>(buf.GetConstMappedRange(0, bd.size));
  for (std::uint32_t y = 0; y < height; ++y) std::memcpy(out.data() + y * row, p + y * padded, row);
  buf.Unmap();
  return out;
}

wgpu::ShaderModule Gpu::shader(const std::string& wgsl, const char* label) {
  wgpu::ShaderSourceWGSL src{};
  src.code = wgpu::StringView(wgsl.data(), wgsl.size());
  wgpu::ShaderModuleDescriptor desc{};
  desc.nextInChain = &src;
  if (label) desc.label = label;
  return device_.CreateShaderModule(&desc);
}

}  // namespace mvp::gfx
