#include "mods/tables.h"

#include <cstdio>
#include <cstring>

#include "mods/json.h"

namespace mvp::mods {

std::uint32_t djb2(const std::string& text) {
  std::uint32_t h = 5381;
  for (unsigned char c : text) h = h * 33 + c;
  return h;
}

std::string key_of(const std::string& text) {
  char b[16];
  std::snprintf(b, sizeof b, "%09x", djb2(text));
  return b;
}

std::string latin1_to_utf8(const std::string& s) {
  std::string out;
  out.reserve(s.size());
  for (unsigned char c : s) {
    if (c < 0x80) {
      out += static_cast<char>(c);
    } else {
      out += static_cast<char>(0xC0 | (c >> 6));
      out += static_cast<char>(0x80 | (c & 0x3F));
    }
  }
  return out;
}

namespace {

std::vector<std::string> split(const std::string& s, const std::string& sep) {
  std::vector<std::string> out;
  std::size_t at = 0;
  for (;;) {
    std::size_t k = s.find(sep, at);
    if (k == std::string::npos) {
      out.push_back(s.substr(at));
      return out;
    }
    out.push_back(s.substr(at, k - at));
    at = k + sep.size();
  }
}

bool ends_with(const std::string& s, const char* t) {
  const std::size_t n = std::strlen(t);
  return s.size() >= n && s.compare(s.size() - n, n, t) == 0;
}

}  // namespace

std::optional<Table> Table::parse(const std::string& name, const std::vector<std::uint8_t>& data,
                                  std::string* error) {
  auto fail = [&](const std::string& why) -> std::optional<Table> {
    if (error) *error = why;
    return std::nullopt;
  };
  std::string text(data.begin(), data.end());
  if (!ends_with(text, "\r\n")) return fail(name + ": missing final CR LF");
  text.resize(text.size() - 2);
  std::vector<std::string> lines = split(text, "\r\n");
  Table t;
  t.name = name;
  const std::string& header = lines[0];
  if (!ends_with(header, ",;")) return fail(name + ": header has no ',;' terminator");
  std::vector<std::string> hp = split(header.substr(0, header.size() - 2), ",");
  for (std::size_t i = 0; i < hp.size(); ++i) {
    const std::size_t sp = hp[i].find(' ');
    const std::string head = sp == std::string::npos ? hp[i] : hp[i].substr(0, sp);
    const std::string val = sp == std::string::npos ? "" : hp[i].substr(sp + 1);
    if (head != std::to_string(i) || sp == std::string::npos || val.empty())
      return fail(name + ": bad header field " + py_repr(latin1_to_utf8(hp[i])));
    t.fields.push_back(val);
  }
  const std::size_t n = t.fields.size();
  for (std::size_t ln = 1; ln < lines.size(); ++ln) {
    const std::string& line = lines[ln];
    if (!ends_with(line, ",;")) return fail(name + " line " + std::to_string(ln + 1) + ": no ',;' terminator");
    std::vector<std::string> parts = split(line.substr(0, line.size() - 2), ",");
    if (parts.size() != n + 1)
      return fail(name + " line " + std::to_string(ln + 1) + ": " + std::to_string(parts.size() - 1) +
                  " values, expected " + std::to_string(n));
    std::vector<std::string> row;
    row.reserve(n + 1);
    row.push_back(parts[0]);
    for (std::size_t i = 1; i < parts.size(); ++i) {
      const std::string& p = parts[i];
      const std::size_t sp = p.find(' ');
      const std::string head = sp == std::string::npos ? p : p.substr(0, sp);
      if (head != std::to_string(i - 1))
        return fail(name + " line " + std::to_string(ln + 1) + ": field " + latin1_to_utf8(head) +
                    " out of order (want " + std::to_string(i - 1) + ")");
      row.push_back(sp == std::string::npos ? std::string() : p.substr(sp + 1));
    }
    t.rows.push_back(std::move(row));
  }
  return t;
}

std::optional<std::string> Table::serialize(std::string* error) const {
  const std::size_t n = fields.size();
  std::string out;
  out.reserve(64 * (rows.size() + 1) * (n + 1));
  for (std::size_t i = 0; i < n; ++i) {
    if (i) out += ',';
    out += std::to_string(i);
    out += ' ';
    out += fields[i];
  }
  out += ",;\r\n";
  for (const auto& row : rows) {
    if (row.size() != n + 1) {
      if (error) *error = name + ": row has " + std::to_string(row.size() - 1) + " values";
      return std::nullopt;
    }
    for (const auto& v : row)
      if (v.find_first_of(",;\r\n") != std::string::npos) {
        if (error) *error = name + ": value " + py_repr(latin1_to_utf8(v)) + " contains a separator";
        return std::nullopt;
      }
    out += row[0];
    out += ',';
    for (std::size_t i = 1; i <= n; ++i) {
      if (i > 1) out += ',';
      out += std::to_string(i - 1);
      out += ' ';
      out += row[i];
    }
    out += ",;\r\n";
  }
  return out;
}

std::optional<std::int64_t> canon_int(const std::string& s) {
  if (s.empty()) return std::nullopt;
  const bool neg = s[0] == '-';
  const std::size_t from = neg ? 1 : 0;
  if (from >= s.size() || s.size() - from > 18) return std::nullopt;
  std::int64_t v = 0;
  for (std::size_t i = from; i < s.size(); ++i) {
    if (s[i] < '0' || s[i] > '9') return std::nullopt;
    v = v * 10 + (s[i] - '0');
  }
  if (neg) v = -v;
  if (std::to_string(v) != s) return std::nullopt;
  return v;
}

namespace {
std::uint32_t rd32(const std::vector<std::uint8_t>& d, std::size_t p) {
  return std::uint32_t(d[p]) | (std::uint32_t(d[p + 1]) << 8) | (std::uint32_t(d[p + 2]) << 16) |
         (std::uint32_t(d[p + 3]) << 24);
}
std::uint16_t rd16(const std::vector<std::uint8_t>& d, std::size_t p) {
  return static_cast<std::uint16_t>(d[p] | (d[p + 1] << 8));
}
void wr32(std::vector<std::uint8_t>& o, std::uint32_t v) {
  for (int k = 0; k < 4; ++k) o.push_back(static_cast<std::uint8_t>(v >> (8 * k)));
}
void wr16(std::vector<std::uint8_t>& o, std::uint16_t v) {
  o.push_back(static_cast<std::uint8_t>(v));
  o.push_back(static_cast<std::uint8_t>(v >> 8));
}
}  // namespace

std::optional<Loc> Loc::parse(const std::vector<std::uint8_t>& d, std::string* error) {
  auto fail = [&](const char* why) -> std::optional<Loc> {
    if (error) *error = why;
    return std::nullopt;
  };
  if (d.size() < 0x14 + 16 || std::memcmp(d.data(), "LOCH", 4) != 0 || rd32(d, 4) != 0x14)
    return fail("not a LOC file");
  if (rd32(d, 8) != 1 || rd32(d, 12) != 1) return fail("unexpected LOCH version fields");
  const std::size_t p = 0x14;
  if (std::memcmp(d.data() + p, "LOCI", 4) != 0) return fail("missing LOCI block");
  const std::uint32_t isize = rd32(d, p + 4), count = rd32(d, p + 8), z = rd32(d, p + 12);
  if (isize != 16 + 4ull * count || z != 0) return fail("odd LOCI header");
  const std::size_t q = p + isize;
  if (q + 16 > d.size() || std::memcmp(d.data() + q, "LOCL", 4) != 0) return fail("missing LOCL block");
  const std::uint32_t lsize = rd32(d, q + 4), z2 = rd32(d, q + 8), lcount = rd32(d, q + 12);
  if (lcount != count || z2 != 0 || q + lsize != d.size()) return fail("odd LOCL header");
  if (q + 16 + 4ull * count > d.size()) return fail("odd LOCL header");
  Loc loc;
  for (std::uint32_t n = 0; n < count; ++n) {
    if (rd16(d, p + 16 + 4 * n + 2) != n) return fail("string index out of order");
    const std::size_t s = q + rd32(d, q + 16 + 4 * n);
    std::size_t e = s;
    while (e + 1 < d.size() && !(d[e] == 0 && d[e + 1] == 0)) e += 2;
    if (e + 1 >= d.size()) return fail("unterminated string");
    std::string text;
    for (std::size_t k = s; k < e; k += 2) {
      std::uint32_t c = rd16(d, k);
      if (c >= 0xD800 && c <= 0xDBFF) {
        if (k + 3 >= e) return fail("bad UTF-16");
        const std::uint32_t c2 = rd16(d, k + 2);
        if (c2 < 0xDC00 || c2 > 0xDFFF) return fail("bad UTF-16");
        c = 0x10000 + ((c - 0xD800) << 10) + (c2 - 0xDC00);
        k += 2;
      } else if (c >= 0xDC00 && c <= 0xDFFF) {
        return fail("bad UTF-16");
      }
      if (c < 0x80) {
        text += static_cast<char>(c);
      } else if (c < 0x800) {
        text += static_cast<char>(0xC0 | (c >> 6));
        text += static_cast<char>(0x80 | (c & 0x3F));
      } else if (c < 0x10000) {
        text += static_cast<char>(0xE0 | (c >> 12));
        text += static_cast<char>(0x80 | ((c >> 6) & 0x3F));
        text += static_cast<char>(0x80 | (c & 0x3F));
      } else {
        text += static_cast<char>(0xF0 | (c >> 18));
        text += static_cast<char>(0x80 | ((c >> 12) & 0x3F));
        text += static_cast<char>(0x80 | ((c >> 6) & 0x3F));
        text += static_cast<char>(0x80 | (c & 0x3F));
      }
    }
    loc.entries.emplace_back(rd16(d, p + 16 + 4 * n), std::move(text));
  }
  return loc;
}

std::vector<std::uint8_t> Loc::serialize() const {
  const std::uint32_t n = static_cast<std::uint32_t>(entries.size());
  const std::uint32_t loci_size = 16 + 4 * n;
  std::vector<std::vector<std::uint8_t>> blobs;
  for (const auto& [sid, text] : entries) {
    std::vector<std::uint8_t> b;
    for (std::uint32_t c : utf8_decode(text)) {
      if (c >= 0x10000) {
        c -= 0x10000;
        wr16(b, static_cast<std::uint16_t>(0xD800 + (c >> 10)));
        wr16(b, static_cast<std::uint16_t>(0xDC00 + (c & 0x3FF)));
      } else {
        wr16(b, static_cast<std::uint16_t>(c));
      }
    }
    b.insert(b.end(), 4, 0);
    blobs.push_back(std::move(b));
  }
  std::vector<std::uint32_t> offs;
  std::uint32_t pos = 16 + 4 * n;
  for (const auto& b : blobs) {
    offs.push_back(pos);
    pos += static_cast<std::uint32_t>(b.size());
  }
  const std::uint32_t pad = (4 - pos % 4) % 4;
  pos += pad;
  std::vector<std::uint8_t> out;
  out.insert(out.end(), {'L', 'O', 'C', 'H'});
  wr32(out, 0x14);
  wr32(out, 1);
  wr32(out, 1);
  wr32(out, 0x14 + loci_size);
  out.insert(out.end(), {'L', 'O', 'C', 'I'});
  wr32(out, loci_size);
  wr32(out, n);
  wr32(out, 0);
  for (std::uint32_t i = 0; i < n; ++i) {
    wr16(out, entries[i].first);
    wr16(out, static_cast<std::uint16_t>(i));
  }
  out.insert(out.end(), {'L', 'O', 'C', 'L'});
  wr32(out, pos);
  wr32(out, 0);
  wr32(out, n);
  for (std::uint32_t o : offs) wr32(out, o);
  for (const auto& b : blobs) out.insert(out.end(), b.begin(), b.end());
  out.insert(out.end(), pad, 0);
  return out;
}

}  // namespace mvp::mods
