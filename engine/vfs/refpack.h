// EA RefPack (QFS): the compression of database.big's tables and of many other
// BIG payloads (docs/ROSTERS.md §2). The engine decompresses a payload only where
// a roster pack patches it (ARCHITECTURE.md §8), and compresses the patched text
// again before the virtual disc serves it.
//
// The compressor is the reference tool's greedy matcher (tools/rosters/refpack.py)
// instruction for instruction, so the engine and `pack.py apply` rebuild
// database.big byte for byte the same. Its streams are valid RefPack, about 5%
// larger than EA's; the game's loader reads both.
#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace mvp::vfs::refpack {

// A RefPack header: flags 0x10 (bit 0x80: 32-bit sizes, bit 0x01: a compressed
// size field), magic 0xFB, then the unpacked size.
bool is_refpack(const std::uint8_t* data, std::size_t size);
inline bool is_refpack(const std::vector<std::uint8_t>& v) { return is_refpack(v.data(), v.size()); }

// The unpacked bytes, or nullopt (with the reason) for a malformed stream.
std::optional<std::vector<std::uint8_t>> decompress(const std::uint8_t* data, std::size_t size,
                                                    std::string* error = nullptr);
inline std::optional<std::vector<std::uint8_t>> decompress(const std::vector<std::uint8_t>& v,
                                                           std::string* error = nullptr) {
  return decompress(v.data(), v.size(), error);
}

// Greedy LZ77 with 24-bit sizes (32-bit from 16 MiB), searching the 64 most
// recent earlier positions with the same three bytes (refpack.py compress()).
std::vector<std::uint8_t> compress(const std::uint8_t* data, std::size_t size);
inline std::vector<std::uint8_t> compress(const std::vector<std::uint8_t>& v) { return compress(v.data(), v.size()); }

}  // namespace mvp::vfs::refpack
