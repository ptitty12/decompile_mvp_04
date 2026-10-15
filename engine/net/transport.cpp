#include "net/transport.h"

#include <algorithm>

namespace mvp::net {

double SimLink::uniform() {
  // xorshift64*: deterministic for a seed, the same on every host.
  rng_ ^= rng_ >> 12;
  rng_ ^= rng_ << 25;
  rng_ ^= rng_ >> 27;
  const std::uint64_t r = rng_ * 0x2545F4914F6CDD1Dull;
  return static_cast<double>(r >> 11) * (1.0 / 9007199254740992.0);
}

void SimLink::post(int to, const std::uint8_t* data, std::size_t size) {
  std::uint64_t delay = p_.latency_ms;
  if (p_.jitter_ms) delay += static_cast<std::uint64_t>(uniform() * (p_.jitter_ms + 1));
  ends_[to].inbox.push_back(Packet{now_ + delay, ++seq_, std::vector<std::uint8_t>(data, data + size)});
}

void SimLink::End::send(const std::uint8_t* data, std::size_t size) {
  SimLink& l = *link;
  ++l.sent;
  if (l.cut_ || l.uniform() < l.p_.loss) {
    ++l.dropped;
    return;
  }
  l.post(1 - index, data, size);
  if (l.p_.duplicate > 0 && l.uniform() < l.p_.duplicate) {
    ++l.duplicated;
    l.post(1 - index, data, size);
  }
}

bool SimLink::End::receive(std::vector<std::uint8_t>& out) {
  SimLink& l = *link;
  // The earliest due packet (ties: the one sent first).
  auto best = inbox.end();
  for (auto it = inbox.begin(); it != inbox.end(); ++it)
    if (it->due <= l.now_ && (best == inbox.end() || it->due < best->due || (it->due == best->due && it->seq < best->seq)))
      best = it;
  if (best == inbox.end()) return false;
  if (best->seq < last_seq) ++l.reordered;
  last_seq = std::max(last_seq, best->seq);
  out = std::move(best->data);
  inbox.erase(best);
  ++l.delivered;
  return true;
}

}  // namespace mvp::net
