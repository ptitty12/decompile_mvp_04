// mvp-web-cache-sim (E2c, development): replays a disc read trace (the page's
// traceDisc=1, browser_check --trace-disc: "offset size" lines, "F field" where
// a run batch starts) through the server image's block cache (block_cache.h)
// over a modelled network, to choose the cache's settings. No disc needed.
//
//   node mvp-web-cache-sim.js TRACE [--block KIB] [--blocks N] [--run N] [--ahead N]
//        [--rtt MS] [--mbps MBIT] [--inflight N] [--field-ms MS]
//
// Model: the guest runs paced (field f starts at f x field-ms of wall time at
// the earliest); a miss blocks for the request's round trip plus its bytes at
// the link's rate, after whatever the link is still sending; read-ahead
// requests are issued at batch boundaries (at most --inflight at once) and
// their blocks arrive at the next boundary after they complete, as in the
// Worker. Prints requests, bytes, the time the guest waited and the stalls.
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "web/wasm/block_cache.h"

using namespace mvp::web;

namespace {

double g_now = 0, g_link_free = 0, g_rtt = 30, g_bytes_per_ms = 50e6 / 8 / 1000;

double transfer(std::size_t n) {
  const double start = std::max(g_now, g_link_free);
  const double done = start + g_rtt + static_cast<double>(n) / g_bytes_per_ms;
  g_link_free = done - g_rtt;  // the link is busy only while bytes flow
  return done;
}

struct SimFetcher final : RangeFetcher {
  bool fetch(std::uint64_t, std::uint8_t* dst, std::size_t n) override {
    std::memset(dst, 0, n);
    g_now = transfer(n);  // the guest waits
    return true;
  }
};

double now_ms() { return g_now; }

}  // namespace

int main(int argc, char** argv) {
  if (argc < 2) {
    std::fprintf(stderr, "usage: mvp-web-cache-sim TRACE [--block KIB] [--blocks N] [--run N] [--ahead N] "
                         "[--rtt MS] [--mbps MBIT] [--inflight N] [--field-ms MS]\n");
    return 2;
  }
  BlockCacheSource::Options opt;
  int inflight_max = 2;
  double field_ms = 1000.0 / 59.94, mbps = 50;
  for (int i = 2; i + 1 < argc; i += 2) {
    const std::string k = argv[i];
    const double v = std::atof(argv[i + 1]);
    if (k == "--block") opt.block = static_cast<std::uint32_t>(v) << 10;
    else if (k == "--blocks") opt.max_blocks = static_cast<std::uint32_t>(v);
    else if (k == "--run") opt.max_run = static_cast<std::uint32_t>(v);
    else if (k == "--ahead") opt.ahead = static_cast<std::uint32_t>(v);
    else if (k == "--rtt") g_rtt = v;
    else if (k == "--mbps") mbps = v;
    else if (k == "--inflight") inflight_max = static_cast<int>(v);
    else if (k == "--field-ms") field_ms = v;
  }
  g_bytes_per_ms = mbps * 1e6 / 8 / 1000;
  std::ifstream in(argv[1]);
  if (!in) {
    std::fprintf(stderr, "cannot read %s\n", argv[1]);
    return 1;
  }
  BlockCacheSource src(std::make_unique<SimFetcher>(), ~0ull >> 8, opt);
  src.set_clock(&now_ms);
  struct Flight {
    double done;
    std::uint64_t first;
    std::uint32_t count;
  };
  std::deque<Flight> flights;
  std::vector<std::uint8_t> buf;
  std::uint64_t ahead_requests = 0, ahead_bytes = 0, reads = 0;
  double max_stall = 0;
  std::uint64_t stalls_50 = 0, stalls_200 = 0;
  std::vector<double> by_field(64, 0);  // waited, per 300 VI fields
  double field_now = 0;
  std::string line;
  while (std::getline(in, line)) {
    if (line.empty()) continue;
    if (line[0] == 'F') {
      const double field = std::atof(line.c_str() + 2);
      field_now = field;
      g_now = std::max(g_now, field * field_ms);
      for (auto it = flights.begin(); it != flights.end();) {
        if (it->done <= g_now) {
          const std::size_t n = static_cast<std::size_t>(it->count) * src.options().block;
          buf.assign(n, 0);
          src.insert(it->first, it->count, buf.data(), n, true);
          it = flights.erase(it);
        } else {
          ++it;
        }
      }
      while (static_cast<int>(flights.size()) < inflight_max) {
        const auto w = src.want();
        if (!w.count) break;
        const std::size_t n = static_cast<std::size_t>(w.count) * src.options().block;
        flights.push_back({transfer(n), w.first, w.count});
        ++ahead_requests;
        ahead_bytes += n;
      }
      continue;
    }
    std::istringstream ls(line);
    std::uint64_t off = 0;
    std::size_t n = 0;
    ls >> off >> n;
    buf.resize(n);
    const double t0 = g_now;
    src.read(off, buf.data(), n);
    ++reads;
    const double stall = g_now - t0;
    by_field[std::min<std::size_t>(63, static_cast<std::size_t>(field_now / 300))] += stall;
    if (stall > max_stall) max_stall = stall;
    if (stall > 50) ++stalls_50;
    if (stall > 200) ++stalls_200;
  }
  const auto& s = src.stats();
  std::printf("block %u KiB, run %u, ahead %u, blocks %u | rtt %.0f ms, %.0f Mbit/s | %llu reads, %.1f MB | "
              "sync %llu requests %.1f MB, ahead %llu requests %.1f MB (used %llu, wasted %llu blocks) | "
              "waited %.0f ms, longest %.0f ms, %llu stalls > 50 ms, %llu > 200 ms\n",
              opt.block >> 10, opt.max_run, opt.ahead, src.options().max_blocks, g_rtt, mbps,
              static_cast<unsigned long long>(reads), static_cast<double>(s.bytes) / 1e6,
              static_cast<unsigned long long>(s.requests), static_cast<double>(s.fetched) / 1e6,
              static_cast<unsigned long long>(ahead_requests), static_cast<double>(ahead_bytes) / 1e6,
              static_cast<unsigned long long>(s.prefetch_used), static_cast<unsigned long long>(s.prefetch_wasted),
              s.blocked_ms, max_stall, static_cast<unsigned long long>(stalls_50),
              static_cast<unsigned long long>(stalls_200));
  std::printf("waited per 300 fields:");
  std::size_t last = 0;
  for (std::size_t k = 0; k < by_field.size(); ++k)
    if (by_field[k] > 0) last = k;
  for (std::size_t k = 0; k <= last; ++k) std::printf(" %zu:%.0f", k * 300, by_field[k]);
  std::putchar('\n');
  return 0;
}
