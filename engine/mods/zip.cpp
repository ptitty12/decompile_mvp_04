#include "mods/zip.h"

#include <array>
#include <cstring>

namespace mvp::mods {

std::uint32_t crc32(const std::uint8_t* d, std::size_t n, std::uint32_t crc) {
  static const std::array<std::uint32_t, 256> table = [] {
    std::array<std::uint32_t, 256> t{};
    for (std::uint32_t i = 0; i < 256; ++i) {
      std::uint32_t c = i;
      for (int k = 0; k < 8; ++k) c = (c & 1) ? 0xEDB88320u ^ (c >> 1) : c >> 1;
      t[i] = c;
    }
    return t;
  }();
  crc = ~crc;
  for (std::size_t i = 0; i < n; ++i) crc = table[(crc ^ d[i]) & 0xFF] ^ (crc >> 8);
  return ~crc;
}

namespace {

struct Bits {
  const std::uint8_t* d;
  std::size_t n, pos = 0;  // bit position
  int get(int count) {  // -1 past the end
    int v = 0;
    for (int k = 0; k < count; ++k) {
      if ((pos >> 3) >= n) return -1;
      v |= ((d[pos >> 3] >> (pos & 7)) & 1) << k;
      ++pos;
    }
    return v;
  }
};

// Canonical Huffman decoding (counts per length, symbols in code order).
struct Huffman {
  std::array<std::uint16_t, 16> count{};
  std::vector<std::uint16_t> symbol;
  bool build(const std::uint8_t* lengths, int n) {
    count.fill(0);
    for (int i = 0; i < n; ++i) ++count[lengths[i]];
    count[0] = 0;
    int left = 1;
    for (int len = 1; len < 16; ++len) {
      left <<= 1;
      left -= count[len];
      if (left < 0) return false;  // over-subscribed
    }
    std::array<std::uint16_t, 16> offs{};
    for (int len = 1; len < 15; ++len) offs[len + 1] = static_cast<std::uint16_t>(offs[len] + count[len]);
    symbol.assign(static_cast<std::size_t>(n), 0);
    for (int i = 0; i < n; ++i)
      if (lengths[i]) symbol[offs[lengths[i]]++] = static_cast<std::uint16_t>(i);
    return true;
  }
  int decode(Bits& b) const {
    int code = 0, first = 0, index = 0;
    for (int len = 1; len < 16; ++len) {
      const int bit = b.get(1);
      if (bit < 0) return -1;
      code |= bit;
      const int c = count[len];
      if (code - c < first) return symbol[static_cast<std::size_t>(index + (code - first))];
      index += c;
      first += c;
      first <<= 1;
      code <<= 1;
    }
    return -2;
  }
};

constexpr std::uint16_t kLenBase[29] = {3,  4,  5,  6,  7,  8,  9,  10, 11,  13,  15,  17,  19,  23, 27,
                                        31, 35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258};
constexpr std::uint8_t kLenExtra[29] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2,
                                        2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0};
constexpr std::uint16_t kDistBase[30] = {1,   2,   3,   4,   5,   7,    9,    13,   17,   25,
                                         33,  49,  65,  97,  129, 193,  257,  385,  513,  769,
                                         1025, 1537, 2049, 3073, 4097, 6145, 8193, 12289, 16385, 24577};
constexpr std::uint8_t kDistExtra[30] = {0, 0, 0, 0, 1, 1, 2, 2,  3,  3,  4,  4,  5,  5,  6,
                                         6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13};

std::uint16_t le16(const std::uint8_t* p) { return static_cast<std::uint16_t>(p[0] | (p[1] << 8)); }
std::uint32_t le32(const std::uint8_t* p) {
  return std::uint32_t(p[0]) | (std::uint32_t(p[1]) << 8) | (std::uint32_t(p[2]) << 16) | (std::uint32_t(p[3]) << 24);
}

}  // namespace

std::optional<std::vector<std::uint8_t>> inflate(const std::uint8_t* data, std::size_t size, std::size_t limit,
                                                 std::string* error) {
  auto fail = [&](const char* why) -> std::optional<std::vector<std::uint8_t>> {
    if (error) *error = std::string("deflate: ") + why;
    return std::nullopt;
  };
  Bits b{data, size};
  std::vector<std::uint8_t> out;
  int last;
  do {
    last = b.get(1);
    const int type = b.get(2);
    if (last < 0 || type < 0) return fail("truncated");
    if (type == 0) {
      b.pos = (b.pos + 7) & ~std::size_t(7);
      const std::size_t at = b.pos >> 3;
      if (at + 4 > size) return fail("truncated");
      const std::uint16_t len = le16(data + at), nlen = le16(data + at + 2);
      if (static_cast<std::uint16_t>(~nlen) != len) return fail("bad stored block");
      if (at + 4 + len > size) return fail("truncated");
      if (out.size() + len > limit) return fail("too large");
      out.insert(out.end(), data + at + 4, data + at + 4 + len);
      b.pos = (at + 4 + len) << 3;
      continue;
    }
    Huffman lit, dist;
    if (type == 1) {
      std::uint8_t l[288], dl[30];
      for (int i = 0; i < 144; ++i) l[i] = 8;
      for (int i = 144; i < 256; ++i) l[i] = 9;
      for (int i = 256; i < 280; ++i) l[i] = 7;
      for (int i = 280; i < 288; ++i) l[i] = 8;
      for (int i = 0; i < 30; ++i) dl[i] = 5;
      lit.build(l, 288);
      dist.build(dl, 30);
    } else if (type == 2) {
      const int hlit = b.get(5), hdist = b.get(5), hclen = b.get(4);
      if (hlit < 0 || hdist < 0 || hclen < 0) return fail("truncated");
      static const int order[19] = {16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};
      std::uint8_t cl[19] = {};
      for (int i = 0; i < hclen + 4; ++i) {
        const int v = b.get(3);
        if (v < 0) return fail("truncated");
        cl[order[i]] = static_cast<std::uint8_t>(v);
      }
      Huffman clh;
      if (!clh.build(cl, 19)) return fail("bad code lengths");
      std::uint8_t lens[320] = {};
      const int total = hlit + 257 + hdist + 1;
      for (int i = 0; i < total;) {
        const int sym = clh.decode(b);
        if (sym < 0) return fail("bad code length code");
        if (sym < 16) {
          lens[i++] = static_cast<std::uint8_t>(sym);
          continue;
        }
        int rep, val = 0;
        if (sym == 16) {
          if (i == 0) return fail("repeat without a length");
          val = lens[i - 1];
          rep = 3 + b.get(2);
        } else if (sym == 17) {
          rep = 3 + b.get(3);
        } else {
          rep = 11 + b.get(7);
        }
        if (rep < 3 || i + rep > total) return fail("bad repeat");
        while (rep--) lens[i++] = static_cast<std::uint8_t>(val);
      }
      if (!lit.build(lens, hlit + 257) || !dist.build(lens + hlit + 257, hdist + 1)) return fail("bad lengths");
    } else {
      return fail("bad block type");
    }
    for (;;) {
      const int sym = lit.decode(b);
      if (sym < 0) return fail("bad literal/length code");
      if (sym < 256) {
        if (out.size() >= limit) return fail("too large");
        out.push_back(static_cast<std::uint8_t>(sym));
        continue;
      }
      if (sym == 256) break;
      const int li = sym - 257;
      if (li >= 29) return fail("bad length code");
      const int le = b.get(kLenExtra[li]);
      if (le < 0) return fail("truncated");
      const std::size_t len = kLenBase[li] + static_cast<std::size_t>(le);
      const int ds = dist.decode(b);
      if (ds < 0 || ds >= 30) return fail("bad distance code");
      const int de = b.get(kDistExtra[ds]);
      if (de < 0) return fail("truncated");
      const std::size_t d = kDistBase[ds] + static_cast<std::size_t>(de);
      if (d > out.size()) return fail("distance too far back");
      if (out.size() + len > limit) return fail("too large");
      const std::size_t from = out.size() - d;
      for (std::size_t k = 0; k < len; ++k) out.push_back(out[from + k]);
    }
  } while (!last);
  return out;
}

bool ZipArchive::is_zip(const std::vector<std::uint8_t>& d) {
  if (d.size() < 22) return false;
  const std::size_t lo = d.size() > 22 + 65535 ? d.size() - 22 - 65535 : 0;
  for (std::size_t p = d.size() - 22 + 1; p-- > lo;)
    if (d[p] == 'P' && d[p + 1] == 'K' && d[p + 2] == 5 && d[p + 3] == 6) return true;
  return false;
}

std::optional<ZipArchive> ZipArchive::open(std::vector<std::uint8_t> bytes, std::string* error) {
  auto fail = [&](const char* why) -> std::optional<ZipArchive> {
    if (error) *error = std::string("zip: ") + why;
    return std::nullopt;
  };
  ZipArchive z;
  z.bytes_ = std::move(bytes);
  const auto& d = z.bytes_;
  if (d.size() < 22) return fail("not a zip file");
  std::size_t eocd = std::string::npos;
  const std::size_t lo = d.size() > 22 + 65535 ? d.size() - 22 - 65535 : 0;
  for (std::size_t p = d.size() - 22 + 1; p-- > lo;)
    if (d[p] == 'P' && d[p + 1] == 'K' && d[p + 2] == 5 && d[p + 3] == 6) {
      eocd = p;
      break;
    }
  if (eocd == std::string::npos) return fail("not a zip file");
  const std::uint16_t count = le16(&d[eocd + 10]);
  const std::uint32_t cd_size = le32(&d[eocd + 12]), cd_off = le32(&d[eocd + 16]);
  if (count == 0xFFFF || cd_size == 0xFFFFFFFFu || cd_off == 0xFFFFFFFFu) return fail("zip64 is not supported");
  if (std::uint64_t(cd_size) + cd_off > eocd) return fail("bad central directory");
  z.concat_ = eocd - cd_size - cd_off;
  std::size_t p = static_cast<std::size_t>(z.concat_ + cd_off);
  for (std::uint16_t i = 0; i < count; ++i) {
    if (p + 46 > eocd || le32(&d[p]) != 0x02014b50u) return fail("bad central directory entry");
    ZipEntry e;
    const std::uint16_t flags = le16(&d[p + 8]);
    e.method = le16(&d[p + 10]);
    e.crc = le32(&d[p + 16]);
    e.compressed = le32(&d[p + 20]);
    e.size = le32(&d[p + 24]);
    const std::uint16_t nlen = le16(&d[p + 28]), xlen = le16(&d[p + 30]), clen = le16(&d[p + 32]);
    e.local_offset = le32(&d[p + 42]);
    if (p + 46 + nlen > eocd) return fail("bad central directory entry");
    e.name.assign(reinterpret_cast<const char*>(&d[p + 46]), nlen);
    if (flags & 1) e.method = 0xFFFF;  // encrypted: refused when read
    p += 46 + nlen + xlen + clen;
    z.entries_.push_back(std::move(e));
  }
  return z;
}

std::optional<std::vector<std::uint8_t>> ZipArchive::read(const ZipEntry& e, std::string* error) const {
  auto fail = [&](const std::string& why) -> std::optional<std::vector<std::uint8_t>> {
    if (error) *error = "zip: " + e.name + ": " + why;
    return std::nullopt;
  };
  const auto& d = bytes_;
  const std::uint64_t h = concat_ + e.local_offset;
  if (h + 30 > d.size() || le32(&d[static_cast<std::size_t>(h)]) != 0x04034b50u) return fail("bad local header");
  const std::uint64_t start = h + 30 + le16(&d[static_cast<std::size_t>(h + 26)]) + le16(&d[static_cast<std::size_t>(h + 28)]);
  if (start + e.compressed > d.size()) return fail("data outside the file");
  const std::uint8_t* p = d.data() + start;
  std::vector<std::uint8_t> out;
  if (e.method == 0) {
    if (e.compressed != e.size) return fail("stored sizes differ");
    out.assign(p, p + e.size);
  } else if (e.method == 8) {
    std::string err;
    auto v = inflate(p, static_cast<std::size_t>(e.compressed), static_cast<std::size_t>(e.size), &err);
    if (!v) return fail(err);
    out = std::move(*v);
  } else if (e.method == 0xFFFF) {
    return fail("encrypted entries are not supported");
  } else {
    return fail("compression method " + std::to_string(e.method) + " is not supported (use deflate)");
  }
  if (out.size() != e.size) return fail("size mismatch");
  if (crc32(out.data(), out.size()) != e.crc) return fail("CRC mismatch");
  return out;
}

}  // namespace mvp::mods
