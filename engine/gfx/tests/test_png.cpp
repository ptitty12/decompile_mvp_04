// The PNG writer: known checksums, and the stored zlib stream decodes back to
// the filtered scanlines.
#include <doctest/doctest.h>

#include <cstring>
#include <vector>

#include "common/bytes.h"
#include "gfx/png.h"

using namespace mvp;
using namespace mvp::gfx;

TEST_CASE("crc32 and adler32 known values") {
  const char* s = "123456789";
  CHECK(crc32(reinterpret_cast<const std::uint8_t*>(s), 9) == 0xCBF43926u);
  const char* w = "Wikipedia";
  CHECK(adler32(reinterpret_cast<const std::uint8_t*>(w), 9) == 0x11E60398u);
}

TEST_CASE("PNG structure and stored payload") {
  const std::uint32_t w = 300, h = 250;  // more than one 64 KiB stored block
  std::vector<std::uint8_t> px(w * h * 4);
  for (std::size_t i = 0; i < px.size(); ++i) px[i] = static_cast<std::uint8_t>(i * 7 + 3);
  auto png = encode_png_rgba(w, h, px.data());
  REQUIRE(png.size() > 8);
  CHECK(std::memcmp(png.data(), "\x89PNG\r\n\x1a\n", 8) == 0);

  // Walk the chunks, checking each CRC; collect IDAT.
  std::size_t at = 8;
  std::vector<std::uint8_t> idat;
  std::vector<std::string> types;
  while (at + 12 <= png.size()) {
    std::uint32_t len = be32(png.data() + at);
    std::string type(reinterpret_cast<const char*>(png.data() + at + 4), 4);
    types.push_back(type);
    CHECK(crc32(png.data() + at + 4, len + 4) == be32(png.data() + at + 8 + len));
    if (type == "IHDR") {
      CHECK(be32(png.data() + at + 8) == w);
      CHECK(be32(png.data() + at + 12) == h);
    }
    if (type == "IDAT") idat.insert(idat.end(), png.begin() + static_cast<std::ptrdiff_t>(at + 8),
                                    png.begin() + static_cast<std::ptrdiff_t>(at + 8 + len));
    at += 12 + len;
  }
  CHECK(at == png.size());
  REQUIRE(types.size() == 3);
  CHECK(types[0] == "IHDR");
  CHECK(types[2] == "IEND");

  // Inflate the stored blocks.
  REQUIRE(idat.size() > 6);
  CHECK(idat[0] == 0x78);
  CHECK((idat[0] * 256 + idat[1]) % 31 == 0);
  std::vector<std::uint8_t> raw;
  std::size_t p = 2;
  bool last = false;
  while (!last) {
    last = idat[p] & 1;
    CHECK((idat[p] >> 1) == 0);  // stored
    std::uint32_t n = idat[p + 1] | idat[p + 2] << 8;
    std::uint32_t nn = idat[p + 3] | idat[p + 4] << 8;
    CHECK((n ^ 0xFFFF) == nn);
    raw.insert(raw.end(), idat.begin() + static_cast<std::ptrdiff_t>(p + 5),
               idat.begin() + static_cast<std::ptrdiff_t>(p + 5 + n));
    p += 5 + n;
  }
  CHECK(be32(idat.data() + p) == adler32(raw.data(), raw.size()));
  REQUIRE(raw.size() == h * (w * 4 + 1));
  for (std::uint32_t y = 0; y < h; ++y) {
    CHECK(raw[y * (w * 4 + 1)] == 0);
    CHECK(std::memcmp(raw.data() + y * (w * 4 + 1) + 1, px.data() + y * w * 4, w * 4) == 0);
  }
}
