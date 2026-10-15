// WAV files and level measurement for the mix (E3b).
//
// WavWriter is a FrameSink that writes the mixer's output, exactly as the
// guest's virtual clock produced it (no drift correction), as 16-bit stereo
// PCM. Dumps of the game's audio are game-derived: they belong under build/
// and are never committed.
#pragma once

#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

#include "audio/mixer.h"

namespace mvp::audio {

class WavWriter : public FrameSink {
 public:
  WavWriter() = default;
  WavWriter(const WavWriter&) = delete;
  WavWriter& operator=(const WavWriter&) = delete;
  ~WavWriter() override { close(); }

  bool open(const std::string& path);
  // The sample rate is the first frames' rate; frames at another rate later are
  // still written and counted in rate_changes().
  void audio_frames(const s16* lr, u32 frames, u32 rate) override;
  // Writes the final header. False if anything failed.
  bool close();

  bool is_open() const { return f_ != nullptr; }
  u64 frames() const { return frames_; }
  u32 rate() const { return rate_; }
  u64 rate_changes() const { return rate_changes_; }

 private:
  bool write_header();
  std::FILE* f_ = nullptr;
  u64 frames_ = 0, rate_changes_ = 0;
  u32 rate_ = 0;
  bool error_ = false;
};

// Reads a 16-bit PCM WAV (mono or stereo; mono is duplicated to stereo).
bool read_wav(const std::string& path, std::vector<s16>* lr, u32* rate);

// Levels over consecutive windows of the mix, for reports and tests.
class LevelMeter : public FrameSink {
 public:
  struct Window {
    double rms_dbfs;  // -inf for silence
    s32 peak;
  };
  explicit LevelMeter(u32 window_frames = kDspRate) : window_(window_frames) {}
  void audio_frames(const s16* lr, u32 frames, u32 rate) override;

  const std::vector<Window>& windows() const { return windows_; }
  u64 frames() const { return frames_; }
  s32 peak() const { return peak_; }
  double rms_dbfs() const;  // over everything
  // Windows louder than `dbfs`.
  u64 windows_above(double dbfs) const;
  // "N frames (S s), peak P (D dBFS), RMS R dBFS, W of N windows above -60 dBFS".
  std::string summary() const;

 private:
  void close_window();
  u32 window_;
  u64 frames_ = 0;
  s32 peak_ = 0;
  double sum_ = 0;
  u32 win_frames_ = 0;
  double win_sum_ = 0;
  s32 win_peak_ = 0;
  std::vector<Window> windows_;
};

}  // namespace mvp::audio
