// A read cache for a disc image that lives on a server (E2c): the owner's
// private deployment serves the image over HTTP Range requests, and every guest
// DVD read would otherwise cost a round trip. Reads are served from aligned
// blocks kept in memory (least recently used out); a miss fetches a run of
// missing blocks in one request, longer while the reads stay sequential (the
// game streams movies, audio and archives front to back). A sequential stream
// also asks for the blocks after it ahead of time (want()): the Worker fetches
// them asynchronously between VI fields and hands them back with insert(), so
// a stream rarely blocks on the network. Host-side only: what the guest reads is
// the image's bytes whichever way they arrived.
//
// The fetcher is synchronous (the guest's read must complete inside the call);
// in the browser it is a synchronous XMLHttpRequest in the engine Worker.
#pragma once

#include <cstdint>
#include <list>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "vfs/source.h"

namespace mvp::web {

class RangeFetcher {
 public:
  virtual ~RangeFetcher() = default;
  // Reads exactly n bytes at off into dst; false on failure (error() says why).
  virtual bool fetch(std::uint64_t off, std::uint8_t* dst, std::size_t n) = 0;
  virtual std::string error() const { return {}; }
};

class BlockCacheSource final : public vfs::Source {
 public:
  // The defaults were chosen with mvp-web-cache-sim (tools/cache_sim.cpp) on
  // the read trace of the first minute (boot, intro, title, menus: 1,150 reads,
  // 27 MB, a third of them scattered small reads): 256 KiB blocks fetch 41 MB
  // where 1 MiB blocks fetch 71 MB, and wait least or near least from 15 ms /
  // 300 Mbit/s to 50 ms / 100 Mbit/s (docs/engine/E2C_LOG.md).
  struct Options {
    std::uint32_t block = 256u << 10;      // bytes per block
    std::uint32_t max_blocks = 256;        // memory budget (blocks): 64 MiB
    std::uint32_t max_run = 4;             // blocks per request at most (sequential reads)
    std::uint32_t ahead = 8;               // blocks to ask for ahead of a sequential stream
  };
  struct Stats {
    std::uint64_t reads = 0, bytes = 0;            // what the guest asked for
    std::uint64_t hits = 0, misses = 0;            // per block touched
    std::uint64_t requests = 0, fetched = 0;       // synchronous requests and their bytes
    std::uint64_t prefetched = 0, prefetch_used = 0, prefetch_wasted = 0;  // blocks inserted ahead, later read, evicted unread
    std::uint64_t evicted = 0;
    double blocked_ms = 0;                          // time spent in synchronous requests
  };

  BlockCacheSource(std::unique_ptr<RangeFetcher> fetcher, std::uint64_t size, Options opt);
  BlockCacheSource(std::unique_ptr<RangeFetcher> fetcher, std::uint64_t size)
      : BlockCacheSource(std::move(fetcher), size, Options{}) {}

  std::uint64_t size() const override { return size_; }
  bool read(std::uint64_t off, void* dst, std::size_t n) override;

  // Read-ahead: the run of blocks a sequential stream will want next
  // (first, count), marked as in flight; count 0 if none.
  struct Want {
    std::uint64_t first = 0;
    std::uint32_t count = 0;
  };
  Want want();
  // The bytes of blocks [first, first + count) (the last one may be short at
  // the end of the image), fetched ahead; ok=false releases them unfetched.
  void insert(std::uint64_t first, std::uint32_t count, const std::uint8_t* data, std::size_t n, bool ok);

  const Stats& stats() const { return st_; }
  const Options& options() const { return opt_; }
  std::uint64_t blocks() const { return (size_ + opt_.block - 1) / opt_.block; }
  std::string error() const { return fetcher_->error(); }
  // Clock for blocked_ms (milliseconds; the browser's performance.now()).
  void set_clock(double (*now_ms)()) { now_ms_ = now_ms; }

 private:
  struct Block {
    std::vector<std::uint8_t> bytes;
    std::list<std::uint64_t>::iterator lru;
    bool ahead = false;  // inserted by read-ahead and not read yet
  };
  std::uint32_t block_len(std::uint64_t b) const;
  // Fetches on a miss: at least the blocks up to `last` (the rest of the read
  // that asked), at most kMaxReadRun of them.
  const Block* get(std::uint64_t b, std::uint64_t last);
  static constexpr std::uint32_t kMaxReadRun = 32;
  void put(std::uint64_t b, std::vector<std::uint8_t> bytes, bool ahead);
  void touch(Block& blk, std::uint64_t b);

  std::unique_ptr<RangeFetcher> fetcher_;
  std::uint64_t size_;
  Options opt_;
  std::unordered_map<std::uint64_t, Block> blocks_;
  std::list<std::uint64_t> lru_;  // front = most recent
  std::unordered_map<std::uint64_t, bool> in_flight_;
  std::uint64_t last_miss_ = ~0ull;  // the last block fetched synchronously
  std::uint64_t last_read_ = ~0ull;  // the last block read
  std::uint32_t run_ = 1;            // blocks the next sequential miss fetches
  std::uint32_t seq_ = 0;            // consecutive sequential block reads
  double (*now_ms_)() = nullptr;
  Stats st_;
};

}  // namespace mvp::web
