// Lockstep netplay session (E5, ARCHITECTURE §8): two peers, one controller port
// each, over an unreliable datagram transport (net/transport.h), with the wire
// protocol of net/protocol.h.
//
// Lockstep on inputs:
// - Frames are the game's frame polls (runtime/input.h), numbered from power-on.
//   Player 1 drives port 1, player 2 port 2; ports 3 and 4 are empty.
// - Input delay D: the local controller state sampled when the game reaches
//   frame F is the input of frame F + D. Frames 0..D-1 have neutral input on
//   both ports. D is the larger of the two players' proposals.
// - A frame may run only when both ports' inputs for it are known (ready()).
//   Since a peer at frame F has sent its inputs up to F + D, neither peer can get
//   more than D frames ahead of the other, and the two never deadlock.
// - Every datagram carries every input the peer has not acknowledged yet
//   (redundancy over loss), so a lost datagram costs at most one resend interval.
// - Desync detection: the game side submits a state hash at the frames where a
//   hash window closes (net/state_hash.h); peers exchange them and compare. A
//   mismatch stops the session on both sides (state Desynced) with a local
//   diagnostic.
// - The handshake (HELLO) refuses a match unless both peers have the same engine
//   build, disc identity, pack set, settings, CLK1/DVD1 constants and desync
//   interval, and complementary roles.
// - A peer silent for `timeout_ms` ends the session (Disconnected).
//
// Host time (the `now_ms` arguments) decides only *when* things are sent and
// when a frame becomes ready, never what a frame's input is: the guest sees the
// same inputs on both peers whatever the network did (CLAUDE.md, determinism).
#pragma once

#include <cstdint>
#include <deque>
#include <functional>
#include <map>
#include <optional>
#include <string>
#include <vector>

#include "net/protocol.h"
#include "net/transport.h"
#include "runtime/input.h"

namespace mvp::net {

enum class State { Handshake, Running, Desynced, Disconnected, Rejected, Ended };
const char* state_name(State s);

struct SessionConfig {
  int player = 1;             // 1 or 2
  u32 delay = 3;              // proposed input delay (frames); the larger proposal wins
  u32 hash_interval = 60;     // frames per hash window, the same on both peers (0: off)
  u32 max_inputs = 32;        // redundancy: at most this many inputs per datagram
  u32 resend_ms = 20;         // resend / keepalive after this long without a send (frames send anyway)
  u32 hello_ms = 100;         // HELLO repeat interval during the handshake
  u32 timeout_ms = 10000;     // peer silent this long: Disconnected
  u64 seed = 0;               // shared seed proposal (player 1's is used)
  u64 nonce = 0;              // random per instance
  Identity id;
};

struct SessionStats {
  u64 packets_sent = 0, packets_received = 0, bytes_sent = 0, bytes_received = 0;
  u64 bad_packets = 0;        // did not parse, or came from another session
  u64 inputs_sent = 0;        // pad states sent, resends included
  u64 inputs_new = 0;         // peer inputs that were new
  u64 inputs_redundant = 0;   // peer inputs already known
  u64 inputs_gap = 0;         // peer inputs beyond a gap (not stored)
  u64 hashes_compared = 0;
  u32 rtt_last = 0, rtt_min = 0, rtt_max = 0;
  u64 rtt_sum = 0, rtt_samples = 0;
  double rtt_avg() const { return rtt_samples ? static_cast<double>(rtt_sum) / static_cast<double>(rtt_samples) : 0.0; }
  // Input latency: host time from sampling the local pad (ready()) to the frame
  // poll that uses it (take() with a time). The delay's cost, stalls included.
  u64 latency_sum = 0, latency_samples = 0, latency_max = 0;
  double latency_avg() const {
    return latency_samples ? static_cast<double>(latency_sum) / static_cast<double>(latency_samples) : 0.0;
  }
};

struct Mismatch {
  u32 frame = 0;
  u64 local = 0, remote = 0;
};

class Session {
 public:
  // The local controller state to use for a new input, given the frame at which
  // it is sampled (the new input's frame minus the delay). Called once per frame,
  // in frame order.
  using LocalSource = std::function<PadState(u64 sample_frame)>;

  Session(Transport& t, SessionConfig cfg, LocalSource local);

  // Receives every waiting datagram, sends what is due (HELLO, resends,
  // keepalives), checks the timeout.
  void update(u64 now_ms);

  State state() const { return state_; }
  bool running() const { return state_ == State::Running; }
  bool ended() const { return state_ != State::Handshake && state_ != State::Running; }
  const std::string& reason() const { return reason_; }

  // Negotiated values (valid once running).
  u32 delay() const { return delay_; }
  u64 seed() const { return seed_; }
  const Hello& peer_hello() const { return peer_; }
  int local_port() const { return cfg_.player - 1; }
  int remote_port() const { return 2 - cfg_.player; }
  const SessionConfig& config() const { return cfg_; }

  // Whether both ports' inputs for `frame` are known; when they are, the local
  // inputs up to frame + delay are generated (sampled from the LocalSource) and
  // each new one is sent at once. With delay 0 the local input of `frame` is
  // generated before the check. False while not running.
  bool ready(u64 frame, u64 now_ms);
  // The input of frame `frame`, which must be next_frame() and ready. With
  // `now_ms`, the input latency statistics are updated.
  rt::FrameInput take(u64 frame, std::optional<u64> now_ms = std::nullopt);
  u64 next_frame() const { return next_take_; }

  // The local state hash of a window that closed at `frame` (same frames on both
  // peers). Compared with the peer's when both are known.
  void submit_hash(u32 frame, u64 hash, u64 now_ms);

  // Ends the session (tells the peer).
  void quit(u64 now_ms, const std::string& why = "quit");

  // Diagnostics.
  u64 local_horizon() const { return local_base_ + local_.size(); }   // next local input to generate
  u64 remote_horizon() const { return remote_base_ + remote_.size(); } // every peer input before it is known
  u32 peer_frame() const { return peer_cur_frame_; }                   // the peer's next frame poll, as last reported
  const std::optional<Mismatch>& mismatch() const { return mismatch_; }
  const SessionStats& stats() const { return stats_; }
  // A text report for the local diagnostic: state, horizons, the mismatch, the
  // statistics and the last taken frames' inputs (wire form). No game data.
  std::string diagnostic() const;

  // The neutral input of a player port (connected, nothing pressed).
  static PadState neutral_pad();

 private:
  void send_raw(const std::vector<u8>& d);
  void send_hello(u64 now_ms);
  void send_input(u64 now_ms);
  void send_bye(ByeReason r, const std::string& text);
  void stop(State s, const std::string& why, ByeReason r, bool tell_peer);
  void on_hello(const Hello& h, u64 now_ms);
  void on_input(const Input& m, u64 now_ms);
  void on_bye(const Bye& b);
  void compare(u32 frame, u64 local, u64 remote);
  void prune();

  Transport& t_;
  SessionConfig cfg_;
  LocalSource local_source_;
  State state_ = State::Handshake;
  std::string reason_;

  Hello mine_, peer_;
  bool have_peer_ = false;
  u32 delay_ = 0;
  u64 seed_ = 0;

  // Local inputs local_base_ .. local_horizon()-1; peer inputs remote_base_ ..
  // remote_horizon()-1.
  std::deque<PadState> local_, remote_;
  std::deque<u64> local_ms_;  // when each local input was sampled
  u64 local_base_ = 0, remote_base_ = 0;
  u64 next_take_ = 0;
  u32 peer_ack_frame_ = 0;  // the peer has our inputs before this
  u32 peer_ack_hash_ = 0;   // the peer has our hash records before this
  u32 remote_hash_ack_ = 0; // we have the peer's hash records before this
  u32 peer_cur_frame_ = 0;

  std::deque<HashRecord> unacked_hashes_;
  std::map<u32, u64> local_hashes_, remote_hashes_;  // waiting for the other side's
  std::optional<Mismatch> mismatch_;

  bool started_ = false;
  u64 start_ms_ = 0, last_recv_ms_ = 0, last_send_ms_ = 0, last_hello_ms_ = 0;
  bool hello_sent_ = false;
  u32 peer_send_ms_ = 0;
  u64 peer_send_rx_ms_ = 0;
  bool have_peer_send_ = false;

  std::deque<std::pair<u64, rt::FrameInput>> recent_;  // last taken frames, for diagnostic()
  SessionStats stats_;
  std::vector<u8> rx_;
};

}  // namespace mvp::net
