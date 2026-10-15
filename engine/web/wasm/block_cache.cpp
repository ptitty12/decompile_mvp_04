#include "web/wasm/block_cache.h"

#include <algorithm>
#include <cstring>

namespace mvp::web {

BlockCacheSource::BlockCacheSource(std::unique_ptr<RangeFetcher> fetcher, std::uint64_t size, Options opt)
    : fetcher_(std::move(fetcher)), size_(size), opt_(opt) {
  opt_.block = std::max<std::uint32_t>(opt_.block, 4096);
  opt_.max_run = std::max<std::uint32_t>(opt_.max_run, 1);
  // A whole run, plus the block being read, must fit.
  opt_.max_blocks = std::max(opt_.max_blocks, std::max(opt_.max_run, kMaxReadRun) + opt_.ahead + 2);
}

std::uint32_t BlockCacheSource::block_len(std::uint64_t b) const {
  const std::uint64_t start = b * opt_.block;
  return static_cast<std::uint32_t>(std::min<std::uint64_t>(opt_.block, size_ - start));
}

void BlockCacheSource::touch(Block& blk, std::uint64_t b) {
  lru_.erase(blk.lru);
  lru_.push_front(b);
  blk.lru = lru_.begin();
}

void BlockCacheSource::put(std::uint64_t b, std::vector<std::uint8_t> bytes, bool ahead) {
  while (blocks_.size() >= opt_.max_blocks && !lru_.empty()) {
    const std::uint64_t old = lru_.back();
    lru_.pop_back();
    auto it = blocks_.find(old);
    if (it != blocks_.end()) {
      if (it->second.ahead) ++st_.prefetch_wasted;
      blocks_.erase(it);
      ++st_.evicted;
    }
  }
  lru_.push_front(b);
  Block& blk = blocks_[b];
  blk.bytes = std::move(bytes);
  blk.lru = lru_.begin();
  blk.ahead = ahead;
}

const BlockCacheSource::Block* BlockCacheSource::get(std::uint64_t b, std::uint64_t last) {
  if (b != last_read_) {
    seq_ = (last_read_ != ~0ull && b == last_read_ + 1) ? seq_ + 1 : 0;
    last_read_ = b;
  }
  auto it = blocks_.find(b);
  if (it != blocks_.end()) {
    ++st_.hits;
    if (it->second.ahead) {
      it->second.ahead = false;
      ++st_.prefetch_used;
    }
    touch(it->second, b);
    return &it->second;
  }
  ++st_.misses;
  // Sequential misses fetch longer runs (1, 2, 4, ... max_run blocks).
  run_ = (last_miss_ != ~0ull && b == last_miss_) ? std::min(run_ * 2, opt_.max_run) : 1;
  // A large read takes all its missing blocks in one request.
  const std::uint32_t want = static_cast<std::uint32_t>(
      std::max<std::uint64_t>(run_, std::min<std::uint64_t>(last - b + 1, kMaxReadRun)));
  std::uint32_t count = 1;
  while (count < want && b + count < blocks() && !blocks_.count(b + count) && !in_flight_.count(b + count)) ++count;
  const std::uint64_t start = b * opt_.block;
  const std::uint64_t end = std::min<std::uint64_t>(size_, (b + count) * opt_.block);
  std::vector<std::uint8_t> buf(static_cast<std::size_t>(end - start));
  const double t0 = now_ms_ ? now_ms_() : 0;
  const bool ok = fetcher_->fetch(start, buf.data(), buf.size());
  if (now_ms_) st_.blocked_ms += now_ms_() - t0;
  ++st_.requests;
  if (!ok) return nullptr;
  st_.fetched += buf.size();
  last_miss_ = b + count;
  // Insert the last block first, so `b` is the most recently used.
  for (std::uint32_t k = count; k-- > 0;) {
    const std::size_t at = static_cast<std::size_t>(k) * opt_.block;
    const std::size_t len = block_len(b + k);
    put(b + k, std::vector<std::uint8_t>(buf.begin() + static_cast<std::ptrdiff_t>(at),
                                         buf.begin() + static_cast<std::ptrdiff_t>(at + len)),
        false);
  }
  return &blocks_.find(b)->second;
}

bool BlockCacheSource::read(std::uint64_t off, void* dst, std::size_t n) {
  if (off > size_ || n > size_ - off) return false;
  ++st_.reads;
  st_.bytes += n;
  std::uint8_t* out = static_cast<std::uint8_t*>(dst);
  while (n) {
    const std::uint64_t b = off / opt_.block;
    const std::uint32_t bo = static_cast<std::uint32_t>(off % opt_.block);
    const std::size_t take = std::min<std::size_t>(n, block_len(b) - bo);
    const Block* blk = get(b, (off + n - 1) / opt_.block);
    if (!blk) return false;
    std::memcpy(out, blk->bytes.data() + bo, take);
    out += take;
    off += take;
    n -= take;
  }
  return true;
}

BlockCacheSource::Want BlockCacheSource::want() {
  Want w;
  if (seq_ < 2 || last_read_ == ~0ull || !opt_.ahead) return w;  // not a stream (yet)
  const std::uint64_t lo = last_read_ + 1, hi = std::min<std::uint64_t>(blocks(), lo + opt_.ahead);
  std::uint64_t b = lo;
  while (b < hi && (blocks_.count(b) || in_flight_.count(b))) ++b;
  if (b >= hi) return w;
  w.first = b;
  while (b < hi && !blocks_.count(b) && !in_flight_.count(b)) {
    in_flight_[b] = true;
    ++b;
    ++w.count;
  }
  return w;
}

void BlockCacheSource::insert(std::uint64_t first, std::uint32_t count, const std::uint8_t* data, std::size_t n,
                              bool ok) {
  std::size_t expect = 0;
  for (std::uint32_t k = 0; k < count; ++k) {
    in_flight_.erase(first + k);
    if (first + k < blocks()) expect += block_len(first + k);
  }
  if (!ok || n != expect) return;
  std::size_t at = 0;
  for (std::uint32_t k = 0; k < count; ++k) {
    const std::size_t len = block_len(first + k);
    if (!blocks_.count(first + k)) {
      put(first + k, std::vector<std::uint8_t>(data + at, data + at + len), true);
      ++st_.prefetched;
    }
    at += len;
  }
}

}  // namespace mvp::web
