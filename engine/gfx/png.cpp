#include "gfx/png.h"

#include <array>

#include "common/bytes.h"
#include "common/file.h"

namespace mvp::gfx {

namespace {

const std::array<std::uint32_t, 256>& crc_table() {
  static const std::array<std::uint32_t, 256> table = [] {
    std::array<std::uint32_t, 256> t{};
    for (std::uint32_t n = 0; n < 256; ++n) {
      std::uint32_t c = n;
      for (int k = 0; k < 8; ++k) c = (c & 1) ? 0xEDB88320u ^ (c >> 1) : c >> 1;
      t[n] = c;
    }
    return t;
  }();
  return table;
}

void put_chunk(std::vector<std::uint8_t>& out, const char* type, const std::vector<std::uint8_t>& data) {
  std::uint8_t len[4];
  put_be32(len, static_cast<std::uint32_t>(data.size()));
  out.insert(out.end(), len, len + 4);
  std::size_t start = out.size();
  out.insert(out.end(), type, type + 4);
  out.insert(out.end(), data.begin(), data.end());
  std::uint8_t crc[4];
  put_be32(crc, crc32(out.data() + start, out.size() - start));
  out.insert(out.end(), crc, crc + 4);
}

}  // namespace

std::uint32_t crc32(const std::uint8_t* p, std::size_t n, std::uint32_t crc) {
  const auto& t = crc_table();
  crc = ~crc;
  for (std::size_t i = 0; i < n; ++i) crc = t[(crc ^ p[i]) & 0xFF] ^ (crc >> 8);
  return ~crc;
}

std::uint32_t adler32(const std::uint8_t* p, std::size_t n, std::uint32_t adler) {
  std::uint32_t a = adler & 0xFFFF, b = adler >> 16;
  for (std::size_t i = 0; i < n; ++i) {
    a = (a + p[i]) % 65521;
    b = (b + a) % 65521;
  }
  return b << 16 | a;
}

std::vector<std::uint8_t> encode_png_rgba(std::uint32_t width, std::uint32_t height, const std::uint8_t* rgba,
                                          std::uint32_t stride) {
  if (stride == 0) stride = width * 4;
  // Raw scanlines: filter byte 0, then the row.
  std::vector<std::uint8_t> raw;
  raw.reserve(static_cast<std::size_t>(height) * (width * 4 + 1));
  for (std::uint32_t y = 0; y < height; ++y) {
    raw.push_back(0);
    const std::uint8_t* row = rgba + static_cast<std::size_t>(y) * stride;
    raw.insert(raw.end(), row, row + static_cast<std::size_t>(width) * 4);
  }
  // zlib stream of stored deflate blocks (at most 65,535 bytes each).
  std::vector<std::uint8_t> z{0x78, 0x01};
  std::size_t at = 0;
  do {
    std::size_t n = raw.size() - at;
    if (n > 65535) n = 65535;
    bool last = at + n == raw.size();
    z.push_back(last ? 1 : 0);
    z.push_back(static_cast<std::uint8_t>(n));
    z.push_back(static_cast<std::uint8_t>(n >> 8));
    z.push_back(static_cast<std::uint8_t>(~n));
    z.push_back(static_cast<std::uint8_t>(~n >> 8));
    z.insert(z.end(), raw.begin() + static_cast<std::ptrdiff_t>(at), raw.begin() + static_cast<std::ptrdiff_t>(at + n));
    at += n;
  } while (at < raw.size());
  std::uint8_t ad[4];
  put_be32(ad, adler32(raw.data(), raw.size()));
  z.insert(z.end(), ad, ad + 4);

  std::vector<std::uint8_t> out{0x89, 'P', 'N', 'G', 0x0D, 0x0A, 0x1A, 0x0A};
  std::vector<std::uint8_t> ihdr(13);
  put_be32(ihdr.data(), width);
  put_be32(ihdr.data() + 4, height);
  ihdr[8] = 8;   // bit depth
  ihdr[9] = 6;   // RGBA
  ihdr[10] = 0;  // deflate
  ihdr[11] = 0;  // adaptive filtering
  ihdr[12] = 0;  // no interlace
  put_chunk(out, "IHDR", ihdr);
  put_chunk(out, "IDAT", z);
  put_chunk(out, "IEND", {});
  return out;
}

bool write_png_rgba(const std::string& path, std::uint32_t width, std::uint32_t height, const std::uint8_t* rgba,
                    std::uint32_t stride) {
  auto png = encode_png_rgba(width, height, rgba, stride);
  return write_file(path, png.data(), png.size());
}

}  // namespace mvp::gfx
