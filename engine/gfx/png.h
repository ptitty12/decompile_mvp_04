// Minimal PNG writer for development captures and test images (E1). RGBA8,
// no compression (zlib stored blocks), so it needs no library. Captures of the
// game are game-derived: they go under build/ and are never committed.
#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace mvp::gfx {

// Encodes `width` x `height` RGBA8 pixels (rows top to bottom, `stride` bytes
// apart; 0 means width * 4) as a PNG file image.
std::vector<std::uint8_t> encode_png_rgba(std::uint32_t width, std::uint32_t height, const std::uint8_t* rgba,
                                          std::uint32_t stride = 0);

bool write_png_rgba(const std::string& path, std::uint32_t width, std::uint32_t height, const std::uint8_t* rgba,
                    std::uint32_t stride = 0);

// CRC-32 (PNG/zlib polynomial) and Adler-32, exposed for tests.
std::uint32_t crc32(const std::uint8_t* p, std::size_t n, std::uint32_t crc = 0);
std::uint32_t adler32(const std::uint8_t* p, std::size_t n, std::uint32_t adler = 1);

}  // namespace mvp::gfx
