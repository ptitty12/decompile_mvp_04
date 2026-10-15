// State hashes for netplay desync detection (E5, ARCHITECTURE §8).
//
// xxh64: the XXH64 hash (Yann Collet's xxHash, 64-bit variant), implemented here
// from its published algorithm description; fast enough to hash guest memory in
// the browser. Not for security.
//
// StateHasher spreads the MEM1 hash over a window of K frame polls: at frame f
// it hashes slice (f mod K) of MEM1 (MEM1 split into K equal slices) and the
// instruction count, chained into the window's hash; the window that ends at a
// frame f with f mod K == K - 1 yields its hash. Both peers hash the same bytes
// at the same guest instants (the frame polls), so equal runs give equal hashes,
// at a cost of 1/K of MEM1 per frame instead of all of it once per window. A
// divergence that persists for a whole window is always caught.
#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <vector>

namespace mvp::net {

std::uint64_t xxh64(const void* data, std::size_t size, std::uint64_t seed = 0);

class StateHasher {
 public:
  explicit StateHasher(std::uint32_t interval) : k_(interval ? interval : 1) {}

  // Call at every frame poll, in order. Returns the window hash when `frame`
  // closes a window.
  std::optional<std::uint64_t> at_frame(std::uint64_t frame, const std::uint8_t* mem, std::size_t size,
                                        std::uint64_t ticks);

  std::uint32_t interval() const { return k_; }
  // The slice hashes of the last closed window (diagnostic: comparing two
  // players' lists shows which part of MEM1 differs).
  const std::vector<std::uint64_t>& last_slices() const { return last_; }
  // [begin, end) of slice `s` for a memory of `size` bytes.
  std::pair<std::size_t, std::size_t> slice(std::uint32_t s, std::size_t size) const;

 private:
  std::uint32_t k_;
  std::uint64_t h_ = 0;
  std::vector<std::uint64_t> cur_, last_;
};

}  // namespace mvp::net
