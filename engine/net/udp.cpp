#include "net/udp.h"

#include <algorithm>
#include <chrono>
#include <cstring>
#include <thread>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
using socklen_type = int;
using native_socket = SOCKET;
#else
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
using socklen_type = socklen_t;
using native_socket = int;
#endif

namespace mvp::net {

namespace {

native_socket ns(std::intptr_t s) { return static_cast<native_socket>(s); }

#ifdef _WIN32
struct WinsockInit {
  bool ok = false;
  WinsockInit() {
    WSADATA d;
    ok = WSAStartup(MAKEWORD(2, 2), &d) == 0;
  }
  ~WinsockInit() {
    if (ok) WSACleanup();
  }
};
bool winsock() {
  static WinsockInit w;
  return w.ok;
}
void close_socket(std::intptr_t s) { closesocket(static_cast<SOCKET>(s)); }
bool set_nonblocking(std::intptr_t s) {
  u_long on = 1;
  return ioctlsocket(static_cast<SOCKET>(s), FIONBIO, &on) == 0;
}
#else
bool winsock() { return true; }
void close_socket(std::intptr_t s) { ::close(static_cast<int>(s)); }
bool set_nonblocking(std::intptr_t s) {
  int fl = fcntl(static_cast<int>(s), F_GETFL, 0);
  return fl >= 0 && fcntl(static_cast<int>(s), F_SETFL, fl | O_NONBLOCK) == 0;
}
#endif

bool parse_ipv4(const std::string& host, std::uint32_t* out) {
  in_addr a{};
  const std::string h = host == "localhost" ? "127.0.0.1" : host;
  if (inet_pton(AF_INET, h.c_str(), &a) != 1) return false;
  std::memcpy(out, &a, 4);
  return true;
}

}  // namespace

std::uint64_t host_ms() {
  return static_cast<std::uint64_t>(
      std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count());
}

std::unique_ptr<UdpTransport> UdpTransport::open(const std::string& host, std::uint16_t port, std::string* error) {
  auto fail = [&](const char* why) {
    if (error) *error = why;
    return std::unique_ptr<UdpTransport>();
  };
  if (!winsock()) return fail("cannot initialize sockets");
  std::uint32_t ip = 0;
  if (!parse_ipv4(host, &ip)) return fail("bad IPv4 address");
  auto s = static_cast<std::intptr_t>(::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP));
#ifdef _WIN32
  if (s == static_cast<std::intptr_t>(INVALID_SOCKET)) return fail("socket() failed");
#else
  if (s < 0) return fail("socket() failed");
#endif
  sockaddr_in a{};
  a.sin_family = AF_INET;
  a.sin_port = htons(port);
  std::memcpy(&a.sin_addr, &ip, 4);
  if (::bind(ns(s), reinterpret_cast<sockaddr*>(&a), sizeof a) != 0) {
    close_socket(s);
    return fail("bind() failed (port in use?)");
  }
  if (!set_nonblocking(s)) {
    close_socket(s);
    return fail("cannot make the socket non-blocking");
  }
  socklen_type len = sizeof a;
  getsockname(ns(s), reinterpret_cast<sockaddr*>(&a), &len);
  std::unique_ptr<UdpTransport> t(new UdpTransport());
  t->sock_ = s;
  t->port_ = ntohs(a.sin_port);
  return t;
}

UdpTransport::~UdpTransport() {
  if (sock_ != -1) close_socket(sock_);
}

bool UdpTransport::set_peer(const std::string& host, std::uint16_t port, std::string* error) {
  if (!parse_ipv4(host, &peer_ip_)) {
    if (error) *error = "bad IPv4 address";
    return false;
  }
  peer_port_ = htons(port);
  have_peer_ = true;
  return true;
}

void UdpTransport::send(const std::uint8_t* data, std::size_t size) {
  if (!have_peer_) return;
  sockaddr_in a{};
  a.sin_family = AF_INET;
  a.sin_port = peer_port_;
  std::memcpy(&a.sin_addr, &peer_ip_, 4);
  ::sendto(ns(sock_), reinterpret_cast<const char*>(data),
           static_cast<int>(size), 0, reinterpret_cast<sockaddr*>(&a), sizeof a);
}

bool UdpTransport::receive(std::vector<std::uint8_t>& out) {
  std::uint8_t buf[2048];
  for (;;) {
    sockaddr_in from{};
    socklen_type len = sizeof from;
    const auto n = ::recvfrom(ns(sock_), reinterpret_cast<char*>(buf), sizeof buf,
                              0, reinterpret_cast<sockaddr*>(&from), &len);
    if (n < 0) {
#ifdef _WIN32
      // WSAECONNRESET: an earlier datagram hit a closed port (ICMP); keep going.
      if (WSAGetLastError() == WSAECONNRESET) continue;
#endif
      return false;
    }
    std::uint32_t ip;
    std::memcpy(&ip, &from.sin_addr, 4);
    if (!have_peer_ || ip != peer_ip_ || from.sin_port != peer_port_) {
      ++foreign;
      continue;
    }
    out.assign(buf, buf + n);
    return true;
  }
}

void UdpTransport::wait(std::uint32_t timeout_ms) {
  fd_set r;
  FD_ZERO(&r);
  FD_SET(ns(sock_), &r);
  timeval tv{};
  tv.tv_sec = static_cast<long>(timeout_ms / 1000);
  tv.tv_usec = static_cast<long>((timeout_ms % 1000) * 1000);
  ::select(static_cast<int>(sock_ + 1), &r, nullptr, nullptr, &tv);
}

// ---- impairment ----

namespace {
std::uint64_t host_us() {
  return static_cast<std::uint64_t>(
      std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count());
}
}  // namespace

double ImpairedTransport::uniform() {
  rng_ ^= rng_ >> 12;
  rng_ ^= rng_ << 25;
  rng_ ^= rng_ >> 27;
  return static_cast<double>((rng_ * 0x2545F4914F6CDD1Dull) >> 11) * (1.0 / 9007199254740992.0);
}

void ImpairedTransport::send(const std::uint8_t* data, std::size_t size) {
  if (p_.loss > 0 && uniform() < p_.loss) {
    ++dropped;
    return;
  }
  std::uint64_t delay_us = static_cast<std::uint64_t>(p_.latency_ms) * 1000;
  if (p_.jitter_ms) delay_us += static_cast<std::uint64_t>(uniform() * p_.jitter_ms * 1000.0);
  if (delay_us == 0) {
    inner_.send(data, size);
    return;
  }
  ++delayed;
  held_.push_back(Held{host_us() + delay_us, std::vector<std::uint8_t>(data, data + size)});
}

void ImpairedTransport::flush() {
  if (held_.empty()) return;
  const std::uint64_t now = host_us();
  std::stable_sort(held_.begin(), held_.end(), [](const Held& a, const Held& b) { return a.due_us < b.due_us; });
  std::size_t k = 0;
  while (k < held_.size() && held_[k].due_us <= now) {
    inner_.send(held_[k].data.data(), held_[k].data.size());
    ++k;
  }
  held_.erase(held_.begin(), held_.begin() + static_cast<std::ptrdiff_t>(k));
}

bool ImpairedTransport::receive(std::vector<std::uint8_t>& out) {
  flush();
  return inner_.receive(out);
}

void ImpairedTransport::wait(std::uint32_t timeout_ms) {
  flush();
  if (!held_.empty()) {
    const std::uint64_t now = host_us();
    std::uint64_t next = held_.front().due_us;
    for (const Held& h : held_) next = std::min(next, h.due_us);
    const std::uint64_t until_ms = next > now ? (next - now + 999) / 1000 : 0;
    timeout_ms = static_cast<std::uint32_t>(std::min<std::uint64_t>(timeout_ms, until_ms));
  }
  inner_.wait(timeout_ms);
  flush();
}

}  // namespace mvp::net
