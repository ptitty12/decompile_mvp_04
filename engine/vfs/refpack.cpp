#include "vfs/refpack.h"

#include <unordered_map>

namespace mvp::vfs::refpack {

bool is_refpack(const std::uint8_t* d, std::size_t n) { return n >= 5 && d[1] == 0xFB && (d[0] & 0x7E) == 0x10; }

std::optional<std::vector<std::uint8_t>> decompress(const std::uint8_t* d, std::size_t n, std::string* error) {
  auto fail = [&](const char* why) -> std::optional<std::vector<std::uint8_t>> {
    if (error) *error = std::string("RefPack: ") + why;
    return std::nullopt;
  };
  if (n < 5) return fail("truncated header");
  const std::uint8_t flags = d[0];
  if (d[1] != 0xFB || (flags & 0x7E) != 0x10) return fail("not a RefPack stream");
  std::size_t p = 2;
  if (flags & 0x01) p += (flags & 0x80) ? 4 : 3;
  std::uint64_t size;
  if (flags & 0x80) {
    if (p + 4 > n) return fail("truncated header");
    size = (std::uint64_t(d[p]) << 24) | (std::uint64_t(d[p + 1]) << 16) | (std::uint64_t(d[p + 2]) << 8) | d[p + 3];
    p += 4;
  } else {
    if (p + 3 > n) return fail("truncated header");
    size = (std::uint64_t(d[p]) << 16) | (std::uint64_t(d[p + 1]) << 8) | d[p + 2];
    p += 3;
  }
  if (size > (std::uint64_t(1) << 31)) return fail("unpacked size too large");
  std::vector<std::uint8_t> out;
  out.reserve(static_cast<std::size_t>(size));
  for (;;) {
    if (p >= n) return fail("stream ended without a stop command");
    const std::uint32_t a = d[p];
    std::size_t lit, ref = 0, dist = 0;
    bool stop = false;
    if (a < 0x80) {
      if (p + 2 > n) return fail("truncated command");
      const std::uint32_t b = d[p + 1];
      lit = a & 3;
      ref = ((a >> 2) & 7) + 3;
      dist = ((a & 0x60) << 3) + b + 1;
      p += 2;
    } else if (a < 0xC0) {
      if (p + 3 > n) return fail("truncated command");
      const std::uint32_t b = d[p + 1], c = d[p + 2];
      lit = b >> 6;
      ref = (a & 0x3F) + 4;
      dist = ((b & 0x3F) << 8) + c + 1;
      p += 3;
    } else if (a < 0xE0) {
      if (p + 4 > n) return fail("truncated command");
      const std::uint32_t b = d[p + 1], c = d[p + 2], e = d[p + 3];
      lit = a & 3;
      ref = ((a & 0x0C) << 6) + e + 5;
      dist = ((a & 0x10) << 12) + (b << 8) + c + 1;
      p += 4;
    } else if (a < 0xFC) {
      lit = ((a & 0x1F) << 2) + 4;
      p += 1;
    } else {
      lit = a & 3;
      p += 1;
      stop = true;
    }
    if (p + lit > n) return fail("literals run past the end");
    out.insert(out.end(), d + p, d + p + lit);
    p += lit;
    if (stop) break;
    if (ref) {
      if (dist > out.size()) return fail("back-reference before start of output");
      const std::size_t s = out.size() - dist;
      for (std::size_t i = 0; i < ref; ++i) out.push_back(out[s + i]);
    }
    if (out.size() > size) return fail("output longer than the header says");
  }
  if (out.size() != size) return fail("size mismatch");
  return out;
}

namespace {

// Emits literal runs of 4..112 (multiples of 4) with 0xE0 commands and returns
// how many literals (0-3) are left to ride on the next command.
std::size_t emit_literals(std::vector<std::uint8_t>& out, const std::uint8_t* lits, std::size_t n) {
  std::size_t i = 0;
  while (n - i >= 4) {
    const std::size_t run = std::min<std::size_t>(112, (n - i) & ~std::size_t(3));
    out.push_back(static_cast<std::uint8_t>(0xE0 | ((run - 4) >> 2)));
    out.insert(out.end(), lits + i, lits + i + run);
    i += run;
  }
  return i;  // index of the first leftover literal
}

}  // namespace

std::vector<std::uint8_t> compress(const std::uint8_t* data, std::size_t n) {
  constexpr std::size_t kMaxChain = 64;
  std::vector<std::uint8_t> out;
  out.reserve(n / 2 + 16);
  if (n >= (std::size_t(1) << 24)) {
    out.insert(out.end(), {0x90, 0xFB, std::uint8_t(n >> 24), std::uint8_t(n >> 16), std::uint8_t(n >> 8),
                           std::uint8_t(n)});
  } else {
    out.insert(out.end(), {0x10, 0xFB, std::uint8_t(n >> 16), std::uint8_t(n >> 8), std::uint8_t(n)});
  }
  // Every earlier position with the same three bytes, most recent first: the
  // newest one per key, and for each position the previous one with its key.
  std::unordered_map<std::uint32_t, std::int64_t> head;
  std::vector<std::int64_t> prev(n, -1);
  auto key = [&](std::size_t pos) {
    return (std::uint32_t(data[pos]) << 16) | (std::uint32_t(data[pos + 1]) << 8) | data[pos + 2];
  };
  auto insert = [&](std::size_t pos) {
    if (pos + 3 <= n) {
      auto [it, fresh] = head.try_emplace(key(pos), static_cast<std::int64_t>(pos));
      if (!fresh) {
        prev[pos] = it->second;
        it->second = static_cast<std::int64_t>(pos);
      }
    }
  };
  std::vector<std::uint8_t> lits;
  std::size_t i = 0;
  while (i < n) {
    std::size_t best_len = 0, best_dist = 0;
    if (i + 3 <= n) {
      auto it = head.find(key(i));
      if (it != head.end()) {
        std::int64_t q = it->second;
        for (std::size_t steps = 0; q >= 0 && steps < kMaxChain; ++steps, q = prev[static_cast<std::size_t>(q)]) {
          const std::size_t dist = i - static_cast<std::size_t>(q);
          if (dist > 131072) break;
          std::size_t ln = 3;
          const std::size_t lim = std::min<std::size_t>(1028, n - i);
          while (ln < lim && data[static_cast<std::size_t>(q) + ln] == data[i + ln]) ++ln;
          if (ln > best_len) {
            best_len = ln;
            best_dist = dist;
            if (ln == lim) break;
          }
        }
      }
    }
    int form = 0;
    if (best_len >= 3) {
      if (best_len <= 10 && best_dist <= 1024) form = 2;
      else if (best_len <= 67 && best_dist <= 16384 && best_len >= 4) form = 3;
      else if (best_len >= 5) form = 4;
      if (form == 0) best_len = 0;
    }
    if (form == 0) {
      lits.push_back(data[i]);
      insert(i);
      ++i;
      continue;
    }
    const std::size_t first_rest = emit_literals(out, lits.data(), lits.size());
    const std::size_t nl = lits.size() - first_rest;
    const std::size_t dd = best_dist - 1, ln = best_len;
    if (form == 2) {
      out.push_back(static_cast<std::uint8_t>(((dd >> 8) << 5) | ((ln - 3) << 2) | nl));
      out.push_back(static_cast<std::uint8_t>(dd & 255));
    } else if (form == 3) {
      out.push_back(static_cast<std::uint8_t>(0x80 | (ln - 4)));
      out.push_back(static_cast<std::uint8_t>((nl << 6) | (dd >> 8)));
      out.push_back(static_cast<std::uint8_t>(dd & 255));
    } else {
      out.push_back(static_cast<std::uint8_t>(0xC0 | ((dd >> 16) << 4) | (((ln - 5) >> 8) << 2) | nl));
      out.push_back(static_cast<std::uint8_t>((dd >> 8) & 255));
      out.push_back(static_cast<std::uint8_t>(dd & 255));
      out.push_back(static_cast<std::uint8_t>((ln - 5) & 255));
    }
    out.insert(out.end(), lits.begin() + static_cast<std::ptrdiff_t>(first_rest), lits.end());
    lits.clear();
    for (std::size_t k = 0; k < ln; ++k) insert(i + k);
    i += ln;
  }
  const std::size_t first_rest = emit_literals(out, lits.data(), lits.size());
  out.push_back(static_cast<std::uint8_t>(0xFC | (lits.size() - first_rest)));
  out.insert(out.end(), lits.begin() + static_cast<std::ptrdiff_t>(first_rest), lits.end());
  return out;
}

}  // namespace mvp::vfs::refpack
