// Datagram transports for the netplay session (net/session.h).
//
// A transport moves whole datagrams between the two peers, unreliably: they may
// be lost, duplicated, delayed or reordered (a WebRTC data channel with
// maxRetransmits 0, UDP). The session copes with all of that.
//
// Implementations: SimLink (a simulated network for tests: latency, jitter,
// loss, duplication, reordering, on a virtual clock), UdpTransport (native,
// net/udp.h) and the browser's data channel bridge (engine/web).
#pragma once

#include <cstddef>
#include <cstdint>
#include <deque>
#include <vector>

namespace mvp::net {

class Transport {
 public:
  virtual ~Transport() = default;
  // Sends one datagram (best effort; never blocks).
  virtual void send(const std::uint8_t* data, std::size_t size) = 0;
  // Takes the next received datagram, if one is waiting (never blocks).
  virtual bool receive(std::vector<std::uint8_t>& out) = 0;
  // Blocks until a datagram may be waiting or `timeout_ms` passed. The default
  // returns at once; blocking transports override it.
  virtual void wait(std::uint32_t timeout_ms) { (void)timeout_ms; }
};

// A deterministic simulated network between two endpoints (0 and 1), on a
// virtual millisecond clock the test advances. Each datagram is dropped with
// probability `loss`, otherwise delivered after `latency_ms` plus a uniform
// jitter in [0, jitter_ms] (so later datagrams may overtake earlier ones), and
// duplicated with probability `duplicate`.
class SimLink {
 public:
  struct Params {
    std::uint32_t latency_ms = 20, jitter_ms = 0;
    double loss = 0.0, duplicate = 0.0;
    std::uint64_t seed = 1;
  };
  explicit SimLink(Params p) : p_(p), rng_(p.seed ? p.seed : 1) {
    for (int k = 0; k < 2; ++k) ends_[k].link = this, ends_[k].index = k;
  }
  SimLink(const SimLink&) = delete;
  SimLink& operator=(const SimLink&) = delete;

  std::uint64_t now() const { return now_; }
  void advance(std::uint64_t ms) { now_ += ms; }
  Transport& end(int k) { return ends_[k]; }
  // Changes the parameters from now on (in-flight datagrams keep their times).
  void set_params(const Params& p) {
    p_.latency_ms = p.latency_ms;
    p_.jitter_ms = p.jitter_ms;
    p_.loss = p.loss;
    p_.duplicate = p.duplicate;
  }
  // Cuts the link (every datagram is lost) or restores it.
  void set_cut(bool cut) { cut_ = cut; }

  std::uint64_t sent = 0, dropped = 0, duplicated = 0, delivered = 0, reordered = 0;

 private:
  struct Packet {
    std::uint64_t due;
    std::uint64_t seq;
    std::vector<std::uint8_t> data;
  };
  class End : public Transport {
   public:
    SimLink* link = nullptr;
    int index = 0;
    void send(const std::uint8_t* data, std::size_t size) override;
    bool receive(std::vector<std::uint8_t>& out) override;

    std::vector<Packet> inbox;  // packets on their way to this end
    std::uint64_t last_seq = 0;
  };
  double uniform();  // [0, 1)
  void post(int to, const std::uint8_t* data, std::size_t size);

  Params p_;
  std::uint64_t rng_;
  std::uint64_t now_ = 0, seq_ = 0;
  bool cut_ = false;
  End ends_[2];
};

}  // namespace mvp::net
