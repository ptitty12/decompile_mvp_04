#include "audio/wav.h"

#include <cmath>
#include <cstring>
#include <limits>

namespace mvp::audio {

namespace {

void le16(std::uint8_t* p, std::uint32_t v) {
  p[0] = static_cast<std::uint8_t>(v);
  p[1] = static_cast<std::uint8_t>(v >> 8);
}
void le32(std::uint8_t* p, std::uint32_t v) {
  le16(p, v & 0xFFFF);
  le16(p + 2, v >> 16);
}
std::uint32_t rd_le16(const std::uint8_t* p) { return p[0] | (std::uint32_t(p[1]) << 8); }
std::uint32_t rd_le32(const std::uint8_t* p) { return rd_le16(p) | (rd_le16(p + 2) << 16); }

double dbfs(double mean_square) {
  return mean_square > 0 ? 10 * std::log10(mean_square / (32768.0 * 32768.0))
                         : -std::numeric_limits<double>::infinity();
}

}  // namespace

bool WavWriter::open(const std::string& path) {
  close();
  f_ = std::fopen(path.c_str(), "wb");
  if (!f_) return false;
  frames_ = rate_changes_ = 0;
  rate_ = 0;
  error_ = false;
  return write_header();
}

bool WavWriter::write_header() {
  // RIFF/WAVE, "fmt " (PCM, 2 channels, 16 bits), "data".
  std::uint8_t h[44] = {};
  const std::uint64_t data = frames_ * 4;
  const std::uint32_t data32 = data > 0xFFFFFFD0ull ? 0xFFFFFFD0u : static_cast<std::uint32_t>(data);
  const std::uint32_t rate = rate_ ? rate_ : kDspRate;
  std::memcpy(h, "RIFF", 4);
  le32(h + 4, 36 + data32);
  std::memcpy(h + 8, "WAVEfmt ", 8);
  le32(h + 16, 16);
  le16(h + 20, 1);
  le16(h + 22, 2);
  le32(h + 24, rate);
  le32(h + 28, rate * 4);
  le16(h + 32, 4);
  le16(h + 34, 16);
  std::memcpy(h + 36, "data", 4);
  le32(h + 40, data32);
  if (std::fseek(f_, 0, SEEK_SET) != 0 || std::fwrite(h, 1, sizeof h, f_) != sizeof h) error_ = true;
  return !error_;
}

void WavWriter::audio_frames(const s16* lr, u32 frames, u32 rate) {
  if (!f_ || !frames) return;
  if (!rate_) rate_ = rate;
  else if (rate != rate_) ++rate_changes_;
  std::vector<std::uint8_t> b(4 * static_cast<std::size_t>(frames));
  for (std::size_t i = 0; i < 2 * static_cast<std::size_t>(frames); ++i) le16(&b[2 * i], static_cast<std::uint16_t>(lr[i]));
  if (std::fwrite(b.data(), 1, b.size(), f_) != b.size()) error_ = true;
  frames_ += frames;
}

bool WavWriter::close() {
  if (!f_) return !error_;
  write_header();
  if (std::fclose(f_) != 0) error_ = true;
  f_ = nullptr;
  return !error_;
}

bool read_wav(const std::string& path, std::vector<s16>* lr, u32* rate) {
  std::FILE* f = std::fopen(path.c_str(), "rb");
  if (!f) return false;
  std::vector<std::uint8_t> d;
  std::uint8_t buf[65536];
  for (std::size_t n; (n = std::fread(buf, 1, sizeof buf, f)) > 0;) d.insert(d.end(), buf, buf + n);
  std::fclose(f);
  if (d.size() < 12 || std::memcmp(d.data(), "RIFF", 4) != 0 || std::memcmp(d.data() + 8, "WAVE", 4) != 0) return false;
  std::uint32_t channels = 0, bits = 0;
  for (std::size_t at = 12; at + 8 <= d.size();) {
    const std::uint32_t len = rd_le32(&d[at + 4]);
    const std::uint8_t* body = &d[at + 8];
    const std::size_t avail = std::min<std::size_t>(len, d.size() - at - 8);
    if (std::memcmp(&d[at], "fmt ", 4) == 0 && avail >= 16) {
      if (rd_le16(body) != 1) return false;
      channels = rd_le16(body + 2);
      *rate = rd_le32(body + 4);
      bits = rd_le16(body + 14);
    } else if (std::memcmp(&d[at], "data", 4) == 0) {
      if (bits != 16 || (channels != 1 && channels != 2)) return false;
      lr->clear();
      for (std::size_t k = 0; k + 2 * channels <= avail; k += 2 * channels) {
        const s16 l = static_cast<s16>(rd_le16(body + k));
        const s16 r = channels == 2 ? static_cast<s16>(rd_le16(body + k + 2)) : l;
        lr->push_back(l);
        lr->push_back(r);
      }
      return true;
    }
    at += 8 + len + (len & 1);
  }
  return false;
}

void LevelMeter::audio_frames(const s16* lr, u32 frames, u32) {
  for (u32 i = 0; i < frames; ++i) {
    for (int c = 0; c < 2; ++c) {
      const s32 x = lr[2 * static_cast<std::size_t>(i) + static_cast<std::size_t>(c)];
      const s32 a = x < 0 ? -x : x;
      const double sq = double(x) * double(x);
      sum_ += sq;
      win_sum_ += sq;
      if (a > peak_) peak_ = a;
      if (a > win_peak_) win_peak_ = a;
    }
    ++frames_;
    if (++win_frames_ == window_) close_window();
  }
}

void LevelMeter::close_window() {
  windows_.push_back({dbfs(win_sum_ / (2.0 * win_frames_)), win_peak_});
  win_frames_ = 0;
  win_sum_ = 0;
  win_peak_ = 0;
}

double LevelMeter::rms_dbfs() const { return frames_ ? dbfs(sum_ / (2.0 * static_cast<double>(frames_))) : dbfs(0); }

u64 LevelMeter::windows_above(double level) const {
  u64 n = 0;
  for (const Window& w : windows_) n += w.rms_dbfs > level ? 1 : 0;
  return n;
}

std::string LevelMeter::summary() const {
  char b[200];
  std::snprintf(b, sizeof b, "%llu frames (%.2f s), peak %d (%.1f dBFS), RMS %.1f dBFS, %llu of %zu windows above -60 dBFS",
                static_cast<unsigned long long>(frames_), static_cast<double>(frames_) / kDspRate, peak_,
                peak_ ? 20 * std::log10(peak_ / 32768.0) : -std::numeric_limits<double>::infinity(), rms_dbfs(),
                static_cast<unsigned long long>(windows_above(-60)), windows_.size());
  return b;
}

}  // namespace mvp::audio
