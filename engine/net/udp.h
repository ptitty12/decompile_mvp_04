// Native datagram transports (not in the browser build): UDP between two
// processes, and a wrapper that impairs any transport (loss, latency, jitter) on
// the real clock, for local netplay tests.
#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "net/transport.h"

namespace mvp::net {

class UdpTransport : public Transport {
 public:
  // Binds `host`:`port` (port 0: any free port). Null with a reason on failure.
  static std::unique_ptr<UdpTransport> open(const std::string& host, std::uint16_t port, std::string* error);
  ~UdpTransport() override;

  // Where datagrams go; only datagrams from this address are received.
  bool set_peer(const std::string& host, std::uint16_t port, std::string* error);
  std::uint16_t local_port() const { return port_; }

  void send(const std::uint8_t* data, std::size_t size) override;
  bool receive(std::vector<std::uint8_t>& out) override;
  void wait(std::uint32_t timeout_ms) override;  // select() on the socket

  std::uint64_t foreign = 0;  // datagrams from other addresses, dropped

 private:
  UdpTransport() = default;
  std::intptr_t sock_ = -1;
  std::uint16_t port_ = 0;
  std::uint32_t peer_ip_ = 0;  // network byte order
  std::uint16_t peer_port_ = 0;
  bool have_peer_ = false;
};

// Wraps a transport: each sent datagram is dropped with probability `loss`, or
// handed to the inner transport after `latency_ms` plus a uniform jitter in
// [0, jitter_ms] of real time (so datagrams can be reordered). Delayed datagrams
// go out from receive() and wait(), which the session calls often.
class ImpairedTransport : public Transport {
 public:
  struct Params {
    std::uint32_t latency_ms = 0, jitter_ms = 0;
    double loss = 0.0;
    std::uint64_t seed = 1;
  };
  ImpairedTransport(Transport& inner, Params p) : inner_(inner), p_(p), rng_(p.seed ? p.seed : 1) {}

  void send(const std::uint8_t* data, std::size_t size) override;
  bool receive(std::vector<std::uint8_t>& out) override;
  void wait(std::uint32_t timeout_ms) override;

  std::uint64_t dropped = 0, delayed = 0;

 private:
  void flush();
  double uniform();
  struct Held {
    std::uint64_t due_us;
    std::vector<std::uint8_t> data;
  };
  Transport& inner_;
  Params p_;
  std::uint64_t rng_;
  std::vector<Held> held_;
};

// Monotonic host time in milliseconds (for the session's timers only).
std::uint64_t host_ms();

}  // namespace mvp::net
