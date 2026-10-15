// What the graphics processor reads of guest memory (Q1): memory as the CPU's
// data cache has written it back.
//
// The GP reads main memory, and the CPU's stores go to its write-back data
// cache: a store reaches the GP only when its line is written back, when the
// game flushes it (DCFlushRange, DCStoreRange and their NoSync forms, the SDK's
// way to hand data to the GP) or when the cache evicts it. Games can depend on
// that. MVP's front end draws each sprite as: flush the vertex arrays, issue the
// draw, write the NEXT sprite's vertices into the same arrays, wait for the
// draw. The GP draws the vertices flushed before the draw; the new ones are
// still in the cache. Read from guest memory itself, the draw took the next
// sprite's geometry whenever the GP model ran it after those stores (its last
// bytes had waited in the write-gather pipe until the draw-done flush), and the
// menus, the title and the team screens showed a different jumble every field.
//
// The model: a flush snapshots the 32-byte lines it covers, and the GP reads
// those lines from the snapshot until it expires; every other line it reads
// from memory as it is (stores the game never flushes count as written back at
// once, as before). A snapshot expires at the next VI field (eviction: a frame's
// memory traffic turns the 32 KiB cache over many times), and when memory under
// it is written without the cache (DMA, the write-gather pipe). Only the
// renderer reads through this: guest state never depends on it.
#pragma once

#include <cstdint>
#include <cstring>
#include <vector>

namespace mvp::gfx {

class GpMemory {
 public:
  static constexpr std::uint32_t kLineShift = 5;   // the cache's 32-byte lines
  static constexpr std::uint32_t kPageShift = 12;  // a summary per 4 KiB

  // Guest memory (MEM1), physical addresses from 0.
  void attach(const std::uint8_t* live, std::uint32_t size);
  const std::uint8_t* live() const { return live_; }
  std::uint32_t size() const { return size_; }

  // [addr, addr + len) was written back from the cache: the GP sees what memory
  // holds there now, until the snapshot expires.
  void flush(std::uint32_t addr, std::uint32_t len);
  // The same, with the contents given (the render thread: the emulation thread
  // took them when the game flushed). `activate` covers the flushed range;
  // `set_lines` gives new contents for some of its lines (the others keep what
  // their snapshot held, which the sender knows to be current).
  void activate(std::uint32_t addr, std::uint32_t len);
  void set_lines(std::uint32_t first_line, std::uint32_t lines, const std::uint8_t* data);
  // Memory in [addr, addr + len) was written without the cache: snapshots there end.
  void write_through(std::uint32_t addr, std::uint32_t len);
  // A VI field: the snapshots expire.
  void field() { ++gen_; }

  bool active_line(std::uint32_t line) const { return line < lines_ && gen_of_[line] == gen_; }

  // The GP's view of [addr, addr + len) (physical; null if outside memory):
  // memory itself where no snapshot covers it, else a copy with the snapshots
  // laid over it, valid until the next view() of the same slot.
  const std::uint8_t* view(std::uint32_t addr, std::uint32_t len, int slot = 0) {
    addr &= 0x01FFFFFFu;
    if (!live_ || addr > size_ || len > size_ - addr) return nullptr;
    if (!len || !any_active_) return live_ + addr;
    for (std::uint32_t p = addr >> kPageShift, e = (addr + len - 1) >> kPageShift; p <= e; ++p)
      if (page_gen_[p] == gen_) return overlay(addr, len, slot);
    return live_ + addr;
  }

  struct Stats {
    std::uint64_t flushes = 0, flushed_bytes = 0;  // flushes (and the bytes they snapshot)
    std::uint64_t overlays = 0;                     // views that laid snapshots over memory
    std::uint64_t overlaid_lines = 0;               // lines those views took from snapshots
    std::uint64_t drops = 0;                        // snapshots ended by writes without the cache
  };
  const Stats& stats() const { return stats_; }

 private:
  const std::uint8_t* overlay(std::uint32_t addr, std::uint32_t len, int slot);
  void mark(std::uint32_t first_line, std::uint32_t last_line);

  const std::uint8_t* live_ = nullptr;
  std::uint32_t size_ = 0, lines_ = 0;
  std::uint32_t gen_ = 2;                  // the field generation (0: never flushed)
  bool any_active_ = false;                // a flush has happened (the fast path until then)
  std::vector<std::uint8_t> snap_;         // the snapshot contents, per line
  std::vector<std::uint32_t> gen_of_;      // per line: the generation of its last flush, 0 none
  std::vector<std::uint32_t> page_gen_;    // per 4 KiB: the latest generation of a flush in it
  std::vector<std::uint8_t> scratch_[2];
  Stats stats_;
};

}  // namespace mvp::gfx
