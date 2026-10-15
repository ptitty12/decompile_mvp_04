#include "net/session.h"

#include <algorithm>
#include <cstdio>

namespace mvp::net {

namespace {
constexpr std::size_t kRecentFrames = 120;
constexpr std::size_t kMaxPendingHashes = 64;
constexpr int kByeRepeats = 3;
}  // namespace

const char* state_name(State s) {
  switch (s) {
    case State::Handshake: return "handshake";
    case State::Running: return "running";
    case State::Desynced: return "desynced";
    case State::Disconnected: return "disconnected";
    case State::Rejected: return "rejected";
    case State::Ended: return "ended";
  }
  return "?";
}

PadState Session::neutral_pad() {
  PadState p;
  p.connected = true;
  return p;
}

Session::Session(Transport& t, SessionConfig cfg, LocalSource local)
    : t_(t), cfg_(std::move(cfg)), local_source_(std::move(local)) {
  if (cfg_.player != 1 && cfg_.player != 2) cfg_.player = 1;
  cfg_.max_inputs = std::clamp<u32>(cfg_.max_inputs, 1, static_cast<u32>(kMaxInputsPerPacket));
  mine_.player = static_cast<u8>(cfg_.player);
  mine_.delay = static_cast<u8>(std::min<u32>(cfg_.delay, 60));
  mine_.hash_interval = static_cast<u16>(std::min<u32>(cfg_.hash_interval, 0xFFFF));
  mine_.nonce = cfg_.nonce;
  mine_.seed = cfg_.seed;
  mine_.id = cfg_.id;
  if (mine_.id.build.size() > kMaxBuildId) mine_.id.build.resize(kMaxBuildId);
  if (mine_.id.settings.size() > kMaxSettings) mine_.id.settings.resize(kMaxSettings);
}

void Session::send_raw(const std::vector<u8>& d) {
  t_.send(d.data(), d.size());
  ++stats_.packets_sent;
  stats_.bytes_sent += d.size();
}

void Session::send_hello(u64 now_ms) {
  Hello h = mine_;
  h.seen_peer = have_peer_;
  send_raw(encode(h));
  last_hello_ms_ = now_ms;
  last_send_ms_ = now_ms;
  hello_sent_ = true;
}

void Session::send_input(u64 now_ms) {
  Input m;
  m.ack_frame = static_cast<u32>(remote_horizon());
  m.ack_hash = remote_hash_ack_;
  m.cur_frame = static_cast<u32>(next_take_);
  m.send_ms = static_cast<u32>(now_ms);
  if (have_peer_send_) {
    m.echo_ms = peer_send_ms_;
    m.echo_hold_ms = static_cast<u32>(now_ms - peer_send_rx_ms_);
  }
  // Every input the peer has not acknowledged, oldest first.
  const u64 from = std::max<u64>(peer_ack_frame_, local_base_);
  const u64 to = std::min<u64>(local_horizon(), from + cfg_.max_inputs);
  m.first_frame = static_cast<u32>(from);
  for (u64 f = from; f < to; ++f) m.pads.push_back(local_[static_cast<std::size_t>(f - local_base_)]);
  stats_.inputs_sent += m.pads.size();
  for (const HashRecord& h : unacked_hashes_) {
    if (m.hashes.size() >= kMaxHashesPerPacket) break;
    m.hashes.push_back(h);
  }
  send_raw(encode(m));
  last_send_ms_ = now_ms;
}

void Session::send_bye(ByeReason r, const std::string& text) {
  Bye b;
  b.reason = r;
  b.frame = static_cast<u32>(next_take_);
  b.text = text.substr(0, kMaxReason);
  const std::vector<u8> d = encode(b);
  for (int k = 0; k < kByeRepeats; ++k) send_raw(d);  // unreliable: a few copies
}

void Session::stop(State s, const std::string& why, ByeReason r, bool tell_peer) {
  if (ended()) return;
  state_ = s;
  reason_ = why;
  if (tell_peer) send_bye(r, why);
}

void Session::update(u64 now_ms) {
  if (!started_) {
    started_ = true;
    start_ms_ = last_recv_ms_ = now_ms;
  }
  while (t_.receive(rx_)) {
    if (ended()) continue;  // drain
    ++stats_.packets_received;
    stats_.bytes_received += rx_.size();
    auto type = peek_type(rx_.data(), rx_.size());
    bool ok = false;
    if (type == MsgType::Hello) {
      if (auto h = decode_hello(rx_.data(), rx_.size())) {
        ok = true;
        last_recv_ms_ = now_ms;
        on_hello(*h, now_ms);
      }
    } else if (type == MsgType::Input) {
      if (auto m = decode_input(rx_.data(), rx_.size())) {
        if (have_peer_) {
          ok = true;
          last_recv_ms_ = now_ms;
          on_input(*m, now_ms);
        }
      }
    } else if (type == MsgType::Bye) {
      if (auto b = decode_bye(rx_.data(), rx_.size())) {
        ok = true;
        on_bye(*b);
      }
    }
    if (!ok) ++stats_.bad_packets;
  }
  if (ended()) return;
  if (now_ms - last_recv_ms_ >= cfg_.timeout_ms) {
    stop(State::Disconnected,
         std::string(state_ == State::Handshake ? "the other player did not answer" : "the other player stopped answering") +
             " for " + std::to_string(cfg_.timeout_ms / 1000) + " s",
         ByeReason::Timeout, true);
    return;
  }
  if (state_ == State::Handshake) {
    if (!hello_sent_ || now_ms - last_hello_ms_ >= cfg_.hello_ms) send_hello(now_ms);
  } else if (now_ms - last_send_ms_ >= cfg_.resend_ms) {
    send_input(now_ms);
  }
}

void Session::on_hello(const Hello& h, u64 now_ms) {
  if (have_peer_) {
    if (h.nonce != peer_.nonce) {
      stop(State::Disconnected, "the other player restarted the game", ByeReason::Error, true);
      return;
    }
    if (state_ == State::Running) {
      // The peer has not seen our HELLO yet (ours was lost): answer, at most once
      // per HELLO interval.
      if (now_ms - last_hello_ms_ >= cfg_.hello_ms / 2) send_hello(now_ms);
      return;
    }
  } else {
    std::string why = incompatibility(mine_, h);
    if (!why.empty()) {
      stop(State::Rejected, "cannot play: " + why, ByeReason::Rejected, true);
      return;
    }
    peer_ = h;
    have_peer_ = true;
    delay_ = std::max<u32>(mine_.delay, h.delay);
    seed_ = cfg_.player == 1 ? mine_.seed : h.seed;
    // Frames before the delay have neutral input on both ports.
    local_base_ = remote_base_ = delay_;
    peer_ack_frame_ = delay_;
    send_hello(now_ms);  // tells the peer we have seen it
  }
  if (h.seen_peer) state_ = State::Running;
}

void Session::on_input(const Input& m, u64 now_ms) {
  if (state_ == State::Handshake) state_ = State::Running;  // the peer runs: it has seen our HELLO
  if (m.echo_ms != 0) {
    const u32 rtt = static_cast<u32>(now_ms) - m.echo_ms - m.echo_hold_ms;
    if (rtt < 60000) {
      stats_.rtt_last = rtt;
      stats_.rtt_min = stats_.rtt_samples ? std::min(stats_.rtt_min, rtt) : rtt;
      stats_.rtt_max = std::max(stats_.rtt_max, rtt);
      stats_.rtt_sum += rtt;
      ++stats_.rtt_samples;
    }
  }
  peer_send_ms_ = m.send_ms;
  peer_send_rx_ms_ = now_ms;
  have_peer_send_ = m.send_ms != 0 || have_peer_send_;
  peer_ack_frame_ = std::max<u32>(peer_ack_frame_, static_cast<u32>(std::min<u64>(m.ack_frame, local_horizon())));
  peer_ack_hash_ = std::max(peer_ack_hash_, m.ack_hash);
  peer_cur_frame_ = std::max(peer_cur_frame_, m.cur_frame);
  for (std::size_t k = 0; k < m.pads.size(); ++k) {
    const u64 f = static_cast<u64>(m.first_frame) + k;
    PadState p = m.pads[k];
    p.connected = true;
    if (f < remote_horizon()) {
      ++stats_.inputs_redundant;
      if (f >= remote_base_ && !(remote_[static_cast<std::size_t>(f - remote_base_)] == p)) {
        stop(State::Disconnected, "protocol error: the other player's input for frame " + std::to_string(f) + " changed",
             ByeReason::Error, true);
        return;
      }
    } else if (f == remote_horizon()) {
      remote_.push_back(p);
      ++stats_.inputs_new;
    } else {
      ++stats_.inputs_gap;
    }
  }
  while (!unacked_hashes_.empty() && unacked_hashes_.front().frame < peer_ack_hash_) unacked_hashes_.pop_front();
  for (const HashRecord& h : m.hashes) {
    if (h.frame < remote_hash_ack_) continue;
    remote_hash_ack_ = h.frame + 1;
    auto it = local_hashes_.find(h.frame);
    if (it != local_hashes_.end()) {
      const u64 local = it->second;
      local_hashes_.erase(it);
      compare(h.frame, local, h.hash);
      if (ended()) return;
    } else {
      remote_hashes_[h.frame] = h.hash;
      while (remote_hashes_.size() > kMaxPendingHashes) remote_hashes_.erase(remote_hashes_.begin());
    }
  }
  prune();
}

void Session::on_bye(const Bye& b) {
  const std::string text = b.text.empty() ? "" : ": " + b.text;
  switch (b.reason) {
    case ByeReason::Desync:
      if (!mismatch_) mismatch_ = Mismatch{b.frame, 0, 0};
      stop(State::Desynced, "the other player detected a desync at frame " + std::to_string(b.frame) + text,
           ByeReason::Desync, false);
      break;
    case ByeReason::Rejected:
      stop(State::Rejected, "the other player refused the match" + text, ByeReason::Rejected, false);
      break;
    case ByeReason::Quit: stop(State::Disconnected, "the other player left" + text, ByeReason::Quit, false); break;
    case ByeReason::Timeout:
    case ByeReason::Error: stop(State::Disconnected, "the other player stopped" + text, ByeReason::Error, false); break;
  }
}

void Session::compare(u32 frame, u64 local, u64 remote) {
  ++stats_.hashes_compared;
  if (local == remote) return;
  mismatch_ = Mismatch{frame, local, remote};
  char b[160];
  std::snprintf(b, sizeof b, "desync: state hash at frame %u is %016llx here and %016llx on the other side", frame,
                static_cast<unsigned long long>(local), static_cast<unsigned long long>(remote));
  stop(State::Desynced, b, ByeReason::Desync, true);
}

bool Session::ready(u64 frame, u64 now_ms) {
  if (state_ != State::Running) return false;
  bool fresh = false;
  while (local_horizon() <= frame + delay_) {
    PadState p = local_source_ ? local_source_(local_horizon() - delay_) : neutral_pad();
    p.connected = true;
    local_.push_back(p);
    fresh = true;
  }
  if (fresh) send_input(now_ms);
  return frame < remote_horizon();
}

rt::FrameInput Session::take(u64 frame) {
  rt::FrameInput in = rt::neutral_input(0x3);
  if (frame != next_take_ || frame >= remote_horizon() || frame >= local_horizon()) return in;  // misuse
  if (frame >= delay_) {
    in.pad[local_port()] = local_[static_cast<std::size_t>(frame - local_base_)];
    in.pad[remote_port()] = remote_[static_cast<std::size_t>(frame - remote_base_)];
  }
  ++next_take_;
  recent_.emplace_back(frame, in);
  if (recent_.size() > kRecentFrames) recent_.pop_front();
  prune();
  return in;
}

void Session::submit_hash(u32 frame, u64 hash, u64 now_ms) {
  if (state_ != State::Running) return;
  unacked_hashes_.push_back(HashRecord{frame, hash});
  auto it = remote_hashes_.find(frame);
  if (it != remote_hashes_.end()) {
    const u64 remote = it->second;
    remote_hashes_.erase(it);
    compare(frame, hash, remote);
  } else {
    local_hashes_[frame] = hash;
    while (local_hashes_.size() > kMaxPendingHashes) local_hashes_.erase(local_hashes_.begin());
  }
  (void)now_ms;
}

void Session::quit(u64 now_ms, const std::string& why) {
  (void)now_ms;
  stop(State::Ended, why, ByeReason::Quit, true);
}

void Session::prune() {
  // Local inputs: needed until both the peer acknowledged them and we took them.
  const u64 keep_local = std::min<u64>(peer_ack_frame_, next_take_);
  while (local_base_ < keep_local && !local_.empty()) {
    local_.pop_front();
    ++local_base_;
  }
  while (remote_base_ < next_take_ && !remote_.empty()) {
    remote_.pop_front();
    ++remote_base_;
  }
}

std::string Session::diagnostic() const {
  std::string s;
  char b[256];
  auto line = [&](const char* fmt, auto... args) {
    std::snprintf(b, sizeof b, fmt, args...);
    s += b;
    s += '\n';
  };
  auto ull = [](u64 v) { return static_cast<unsigned long long>(v); };
  line("mvp-netplay diagnostic, protocol %u.%u", static_cast<unsigned>(kProtocolMajor), static_cast<unsigned>(kProtocolMinor));
  line("state %s: %s", state_name(state_), reason_.c_str());
  line("player %d, delay %u, hash interval %u, seed %016llx", cfg_.player, delay_, static_cast<unsigned>(mine_.hash_interval),
       ull(seed_));
  line("next frame %llu, local inputs up to %llu, peer inputs up to %llu, peer at frame %u", ull(next_take_),
       ull(local_horizon()), ull(remote_horizon()), peer_cur_frame_);
  if (mismatch_)
    line("mismatch at frame %u: local %016llx remote %016llx", mismatch_->frame, ull(mismatch_->local),
         ull(mismatch_->remote));
  line("packets sent %llu (%llu bytes), received %llu (%llu bytes), bad %llu", ull(stats_.packets_sent),
       ull(stats_.bytes_sent), ull(stats_.packets_received), ull(stats_.bytes_received), ull(stats_.bad_packets));
  line("rtt ms: last %u min %u avg %.1f max %u (%llu samples)", stats_.rtt_last, stats_.rtt_min, stats_.rtt_avg(),
       stats_.rtt_max, ull(stats_.rtt_samples));
  line("identity: build %s, disc %s, packset %s, settings %s", mine_.id.build.c_str(), hex(mine_.id.disc.data(), 20).c_str(),
       hex(mine_.id.packset.data(), 32).c_str(), mine_.id.settings.c_str());
  for (const auto& [f, in] : recent_) {
    std::string w;
    for (u8 v : rt::encode_frame(in)) {
      std::snprintf(b, sizeof b, "%02x", v);
      w += b;
    }
    line("frame %llu input %s", ull(f), w.c_str());
  }
  return s;
}

}  // namespace mvp::net
