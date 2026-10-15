#include "audio/sdl_out.h"

#include <SDL3/SDL.h>

#include <algorithm>

namespace mvp::audio {

SdlAudioOut::SdlAudioOut(std::uint32_t rate, std::uint32_t target)
    : ring_(std::max<std::uint32_t>(8 * target, 16384)), drift_(ring_, target), rate_(rate) {}

std::unique_ptr<SdlAudioOut> SdlAudioOut::open(std::uint32_t rate, std::uint32_t latency_ms, std::string* err) {
  if (!SDL_InitSubSystem(SDL_INIT_AUDIO)) {
    if (err) *err = std::string("SDL audio: ") + SDL_GetError();
    return nullptr;
  }
  const std::uint32_t target = std::max<std::uint32_t>(rate * latency_ms / 1000, 256);
  std::unique_ptr<SdlAudioOut> out(new SdlAudioOut(rate, target));
  SDL_AudioSpec spec{SDL_AUDIO_S16, 2, static_cast<int>(rate)};
  out->stream_ = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, &SdlAudioOut::pull, out.get());
  if (!out->stream_) {
    if (err) *err = std::string("SDL audio: cannot open the playback device: ") + SDL_GetError();
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
    return nullptr;
  }
  if (const char* d = SDL_GetCurrentAudioDriver()) out->driver_ = d;
  const SDL_AudioDeviceID dev = SDL_GetAudioStreamDevice(out->stream_);
  if (const char* n = SDL_GetAudioDeviceName(dev)) out->device_ = n;
  SDL_AudioSpec dspec{};
  int dframes = 0;
  if (SDL_GetAudioDeviceFormat(dev, &dspec, &dframes)) out->device_rate_ = static_cast<std::uint32_t>(dspec.freq);
  SDL_ResumeAudioStreamDevice(out->stream_);
  return out;
}

SdlAudioOut::~SdlAudioOut() { close(); }

void SdlAudioOut::close() {
  if (!stream_) return;
  SDL_DestroyAudioStream(stream_);  // stops the device and its callbacks
  stream_ = nullptr;
  SDL_QuitSubSystem(SDL_INIT_AUDIO);
}

void SdlAudioOut::pull(void* self, SDL_AudioStream* stream, int additional, int) {
  auto* o = static_cast<SdlAudioOut*>(self);
  if (additional <= 0) return;
  const std::uint32_t frames = static_cast<std::uint32_t>((additional + 3) / 4);
  o->tmp_.resize(2 * static_cast<std::size_t>(frames));
  o->drift_.pull(o->tmp_.data(), frames);
  for (std::uint32_t i = 0; i < frames; ++i) {
    const std::int32_t l = o->tmp_[2 * static_cast<std::size_t>(i)], r = o->tmp_[2 * static_cast<std::size_t>(i) + 1];
    if (l || r) ++o->played_nonsilent_;
    o->played_peak_ = std::max({o->played_peak_, l < 0 ? -l : l, r < 0 ? -r : r});
  }
  SDL_PutAudioStreamData(stream, o->tmp_.data(), static_cast<int>(4 * frames));
}

void SdlAudioOut::audio_frames(const s16* lr, u32 frames, u32 rate) {
  if (!stream_) return;
  if (rate != rate_ && rate) {  // the AI's rate changed: tell the stream
    SDL_AudioSpec spec{SDL_AUDIO_S16, 2, static_cast<int>(rate)};
    SDL_SetAudioStreamFormat(stream_, &spec, nullptr);
    rate_ = rate;
  }
  ring_.write(lr, frames);
}

void SdlAudioOut::throttle(double factor, std::uint32_t max_ms) {
  if (!stream_) return;
  const auto limit = static_cast<std::uint32_t>(factor * drift_.target());
  for (std::uint32_t waited = 0; waited < max_ms && ring_.available() > limit; ++waited) {
    SDL_Delay(1);
    ++throttle_waits_;
  }
}

SdlAudioOut::Stats SdlAudioOut::stats() const {
  Stats s;
  s.written = ring_.written();
  s.ring_full = ring_.dropped();
  s.throttle_waits = throttle_waits_;
  s.played_nonsilent = played_nonsilent_;
  s.played_peak = played_peak_;
  s.drift = drift_.stats();  // exact once closed
  return s;
}

}  // namespace mvp::audio
