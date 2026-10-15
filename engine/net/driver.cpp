#include "net/driver.h"

#include <cstdio>

#include "runtime/hle.h"
#include "runtime/hw.h"

namespace mvp::net {

NetplayDriver::NetplayDriver(Session& s, Transport& t, rt::Machine& m, rt::YieldingHooks* yield_hooks, Clock clock,
                             bool blocking)
    : s_(s), t_(t), m_(m), yh_(yield_hooks), clock_(clock), blocking_(blocking),
      hasher_(s.config().hash_interval ? s.config().hash_interval : 1) {}

void NetplayDriver::end_stall(std::uint64_t now_ms) {
  if (!stalled_) return;
  stalled_ = false;
  const std::uint64_t d = now_ms - stall_start_;
  stall_ms += d;
  if (d > longest_stall_ms) longest_stall_ms = d;
}

bool NetplayDriver::may_run(std::uint64_t now_ms) {
  s_.update(now_ms);
  if (s_.ended() || !s_.running()) return false;
  if (s_.ready(rt::g_frame_polls, now_ms)) {
    end_stall(now_ms);
    return true;
  }
  if (!stalled_) {
    stalled_ = true;
    stall_start_ = now_ms;
    ++stalls;
  }
  return false;
}

rt::FrameInput NetplayDriver::input_for(std::uint64_t frame) {
  std::uint64_t now = clock_();
  if (!s_.ready(frame, now)) {
    if (!blocking_) {
      ++gate_misses;
      throw rt::StopRun{"netplay: frame " + std::to_string(frame) + " was polled before its input arrived (gate missed)"};
    }
    // Blocking mode: wait here, pumping the transport.
    stalled_ = true;
    stall_start_ = now;
    ++stalls;
    for (;;) {
      t_.wait(2);
      now = clock_();
      s_.update(now);
      if (s_.ended()) {
        end_stall(now);
        throw rt::StopRun{std::string("netplay: ") + state_name(s_.state()) + ": " + s_.reason()};
      }
      if (s_.ready(frame, now)) break;
    }
    end_stall(now);
  }
  return s_.take(frame, now);
}

void NetplayDriver::after_poll(std::uint64_t frame) {
  const std::uint64_t now = clock_();
  if (s_.config().hash_interval) {
    if (auto h = hasher_.at_frame(frame, m_.mem1(), rt::Machine::kMem1Size, m_.cpu().ticks)) {
      std::uint64_t v = *h;
      if (frame == corrupt_window_at) v ^= 0x1;
      windows_.push_back(HashRecord{static_cast<std::uint32_t>(frame), v});
      s_.submit_hash(static_cast<std::uint32_t>(frame), v, now);
    }
  }
  if (s_.ended()) throw rt::StopRun{std::string("netplay: ") + state_name(s_.state()) + ": " + s_.reason()};
  // The next poll's input is not known yet: return from rt::run() at the next
  // safe point, so the host loop checks may_run() before that poll.
  if (yh_ && !(s_.remote_horizon() > frame + 1 && s_.local_horizon() > frame + 1)) {
    yh_->request_yield();
    ++early_yields;
  }
}

std::string NetplayDriver::diagnostic() const {
  std::string d = s_.diagnostic();
  char b[96];
  std::snprintf(b, sizeof b, "stalls %llu (%llu ms, longest %llu ms), gate misses %llu\n",
                static_cast<unsigned long long>(stalls), static_cast<unsigned long long>(stall_ms),
                static_cast<unsigned long long>(longest_stall_ms), static_cast<unsigned long long>(gate_misses));
  d += b;
  for (std::size_t k = windows_.size() > 20 ? windows_.size() - 20 : 0; k < windows_.size(); ++k) {
    const HashRecord& w = windows_[k];
    std::snprintf(b, sizeof b, "window %u hash %016llx\n", w.frame, static_cast<unsigned long long>(w.hash));
    d += b;
  }
  const auto& sl = hasher_.last_slices();
  for (std::size_t k = 0; k < sl.size(); ++k) {
    const auto [lo, hi] = hasher_.slice(static_cast<std::uint32_t>(k), rt::Machine::kMem1Size);
    std::snprintf(b, sizeof b, "last window slice %zu [0x%06zx, 0x%06zx) %016llx\n", k, lo, hi,
                  static_cast<unsigned long long>(sl[k]));
    d += b;
  }
  return d;
}

}  // namespace mvp::net
