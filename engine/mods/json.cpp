#include "mods/json.h"

#include <algorithm>
#include <cstdio>

namespace mvp::mods {

namespace {

struct Fail {
  std::string msg;
};

void append_utf8(std::string& out, std::uint32_t c) {
  if (c < 0x80) {
    out += static_cast<char>(c);
  } else if (c < 0x800) {
    out += static_cast<char>(0xC0 | (c >> 6));
    out += static_cast<char>(0x80 | (c & 0x3F));
  } else if (c < 0x10000) {
    out += static_cast<char>(0xE0 | (c >> 12));
    out += static_cast<char>(0x80 | ((c >> 6) & 0x3F));
    out += static_cast<char>(0x80 | (c & 0x3F));
  } else {
    out += static_cast<char>(0xF0 | (c >> 18));
    out += static_cast<char>(0x80 | ((c >> 12) & 0x3F));
    out += static_cast<char>(0x80 | ((c >> 6) & 0x3F));
    out += static_cast<char>(0x80 | (c & 0x3F));
  }
}

// Python's strict UTF-8 decoder, with its error reasons.
bool decode_utf8(const std::uint8_t* d, std::size_t n, std::vector<std::uint32_t>* out, std::string* reason) {
  std::size_t i = 0;
  out->reserve(n);
  while (i < n) {
    const std::uint8_t c = d[i];
    if (c < 0x80) {
      out->push_back(c);
      ++i;
      continue;
    }
    int need;
    std::uint8_t lo = 0x80, hi = 0xBF;
    std::uint32_t cp;
    if (c >= 0xC2 && c <= 0xDF) {
      need = 1;
      cp = c & 0x1F;
    } else if (c >= 0xE0 && c <= 0xEF) {
      need = 2;
      cp = c & 0x0F;
      if (c == 0xE0) lo = 0xA0;
      if (c == 0xED) hi = 0x9F;
    } else if (c >= 0xF0 && c <= 0xF4) {
      need = 3;
      cp = c & 0x07;
      if (c == 0xF0) lo = 0x90;
      if (c == 0xF4) hi = 0x8F;
    } else {
      *reason = "invalid start byte";
      return false;
    }
    for (int k = 1; k <= need; ++k) {
      if (i + k >= n) {
        *reason = "unexpected end of data";
        return false;
      }
      const std::uint8_t b = d[i + k];
      const std::uint8_t l = k == 1 ? lo : 0x80, h = k == 1 ? hi : 0xBF;
      if (b < l || b > h) {
        *reason = "invalid continuation byte";
        return false;
      }
      cp = (cp << 6) | (b & 0x3F);
    }
    out->push_back(cp);
    i += static_cast<std::size_t>(need) + 1;
  }
  return true;
}

bool is_ws(std::uint32_t c) { return c == ' ' || c == '\t' || c == '\n' || c == '\r'; }
bool is_digit(std::uint32_t c) { return c >= '0' && c <= '9'; }

// Python's json C scanner (CPython 3.12 Modules/_json.c) over code points, with
// pack.py's hooks: duplicate keys, floats and NaN/Infinity are errors.
class Parser {
 public:
  explicit Parser(const std::vector<std::uint32_t>& s) : s_(s), n_(s.size()) {}

  Json parse_document() {
    if (n_ && s_[0] == 0xFEFF) fail_at("Unexpected UTF-8 BOM (decode using utf-8-sig)", 0);
    std::size_t idx = skip_ws(0);
    std::size_t end;
    Json v = scan_once(idx, &end, true);
    end = skip_ws(end);
    if (end != n_) fail_at("Extra data", end);
    return v;
  }

 private:
  const std::vector<std::uint32_t>& s_;
  std::size_t n_;

  [[noreturn]] void fail_at(const std::string& msg, std::size_t pos) {
    std::size_t line = 1, last_nl = static_cast<std::size_t>(-1);
    for (std::size_t k = 0; k < pos && k < n_; ++k)
      if (s_[k] == '\n') {
        ++line;
        last_nl = k;
      }
    const std::size_t col = last_nl == static_cast<std::size_t>(-1) ? pos + 1 : pos - last_nl;
    throw Fail{"line " + std::to_string(line) + " column " + std::to_string(col) + ": " + msg};
  }
  // StopIteration(idx) from scan_once: "Expecting value" at idx.
  [[noreturn]] void stop(std::size_t idx) { fail_at("Expecting value", idx); }

  std::size_t skip_ws(std::size_t i) const {
    while (i < n_ && is_ws(s_[i])) ++i;
    return i;
  }

  bool match_word(std::size_t idx, const char* w) const {
    std::size_t k = 0;
    for (; w[k]; ++k)
      if (idx + k >= n_ || s_[idx + k] != static_cast<unsigned char>(w[k])) return false;
    return true;
  }

  Json scan_once(std::size_t idx, std::size_t* next, bool) {
    if (idx >= n_) stop(idx);
    switch (s_[idx]) {
      case '"': {
        Json j;
        j.kind = Json::Kind::Str;
        j.s = scanstring(idx + 1, next);
        return j;
      }
      case '{':
        return parse_object(idx + 1, next);
      case '[':
        return parse_array(idx + 1, next);
      case 'n':
        if (match_word(idx, "null")) {
          *next = idx + 4;
          return Json{};
        }
        break;
      case 't':
        if (match_word(idx, "true")) {
          *next = idx + 4;
          Json j;
          j.kind = Json::Kind::Bool;
          j.b = true;
          return j;
        }
        break;
      case 'f':
        if (match_word(idx, "false")) {
          *next = idx + 5;
          Json j;
          j.kind = Json::Kind::Bool;
          return j;
        }
        break;
      case 'N':
        if (match_word(idx, "NaN")) throw Fail{"NaN is not allowed"};
        break;
      case 'I':
        if (match_word(idx, "Infinity")) throw Fail{"Infinity is not allowed"};
        break;
      case '-':
        if (match_word(idx, "-Infinity")) throw Fail{"-Infinity is not allowed"};
        break;
      default:
        break;
    }
    return match_number(idx, next);
  }

  Json match_number(std::size_t start, std::size_t* next) {
    std::size_t idx = start;
    const std::size_t end_idx = n_ - 1;
    if (s_[idx] == '-') {
      ++idx;
      if (idx > end_idx) stop(start);
    }
    if (s_[idx] >= '1' && s_[idx] <= '9') {
      ++idx;
      while (idx <= end_idx && is_digit(s_[idx])) ++idx;
    } else if (s_[idx] == '0') {
      ++idx;
    } else {
      stop(start);
    }
    bool is_float = false;
    if (idx < end_idx && s_[idx] == '.' && is_digit(s_[idx + 1])) {
      is_float = true;
      idx += 2;
      while (idx <= end_idx && is_digit(s_[idx])) ++idx;
    }
    if (idx < end_idx && (s_[idx] == 'e' || s_[idx] == 'E')) {
      const std::size_t e_start = idx;
      ++idx;
      if (idx < end_idx && (s_[idx] == '-' || s_[idx] == '+')) ++idx;
      while (idx <= end_idx && is_digit(s_[idx])) ++idx;
      if (is_digit(s_[idx - 1])) is_float = true;
      else idx = e_start;
    }
    std::string text;
    for (std::size_t k = start; k < idx; ++k) text += static_cast<char>(s_[k]);
    if (is_float) throw Fail{"non-integer number " + text + " (only integers are allowed)"};
    *next = idx;
    Json j;
    j.kind = Json::Kind::Int;
    const bool neg = text[0] == '-';
    const std::string digits = neg ? text.substr(1) : text;
    if (digits.size() <= 18) {
      std::int64_t v = 0;
      for (char c : digits) v = v * 10 + (c - '0');
      j.i = neg ? -v : v;
    } else {
      j.big = (neg && digits != "0" ? "-" : "") + digits;
      j.i = neg ? INT64_MIN : INT64_MAX;
    }
    return j;
  }

  std::string scanstring(std::size_t end, std::size_t* next_end) {
    const std::size_t begin = end - 1;
    std::vector<std::uint32_t> chunk;
    for (;;) {
      std::size_t nx = end;
      std::uint32_t c = 0;
      for (; nx < n_; ++nx) {
        c = s_[nx];
        if (c == '"' || c == '\\') break;
        if (c <= 0x1F) fail_at("Invalid control character at", nx);
      }
      if (nx >= n_ || !(c == '"' || c == '\\')) fail_at("Unterminated string starting at", begin);
      for (std::size_t k = end; k < nx; ++k) chunk.push_back(s_[k]);
      if (c == '"') {
        end = nx + 1;
        break;
      }
      ++nx;  // the backslash
      if (nx >= n_) fail_at("Unterminated string starting at", begin);
      c = s_[nx];
      if (c != 'u') {
        end = nx + 1;
        switch (c) {
          case '"': break;
          case '\\': break;
          case '/': break;
          case 'b': c = '\b'; break;
          case 'f': c = '\f'; break;
          case 'n': c = '\n'; break;
          case 'r': c = '\r'; break;
          case 't': c = '\t'; break;
          default: c = 0;
        }
        if (c == 0) fail_at("Invalid \\escape", end - 2);
      } else {
        c = 0;
        ++nx;
        end = nx + 4;
        if (end >= n_) fail_at("Invalid \\uXXXX escape", nx - 1);
        auto hex4 = [&](std::size_t from, std::size_t to, std::uint32_t* out) {
          std::uint32_t v = 0;
          for (std::size_t k = from; k < to; ++k) {
            const std::uint32_t dg = s_[k];
            v <<= 4;
            if (dg >= '0' && dg <= '9') v |= dg - '0';
            else if (dg >= 'a' && dg <= 'f') v |= dg - 'a' + 10;
            else if (dg >= 'A' && dg <= 'F') v |= dg - 'A' + 10;
            else return false;
          }
          *out = v;
          return true;
        };
        if (!hex4(nx, end, &c)) fail_at("Invalid \\uXXXX escape", end - 5);
        nx = end;
        if (c >= 0xD800 && c <= 0xDBFF && end + 6 < n_ && s_[nx] == '\\' && s_[nx + 1] == 'u') {
          std::uint32_t c2 = 0;
          end += 6;
          if (!hex4(nx + 2, end, &c2)) fail_at("Invalid \\uXXXX escape", end - 5);
          if (c2 >= 0xDC00 && c2 <= 0xDFFF) c = 0x10000 + ((c - 0xD800) << 10) + (c2 - 0xDC00);
          else end -= 6;
        }
      }
      chunk.push_back(c);
    }
    *next_end = end;
    std::string out;
    for (std::uint32_t c : chunk) append_utf8(out, c);
    return out;
  }

  Json parse_object(std::size_t idx, std::size_t* next) {
    Json obj = Json::object();
    const std::size_t end_idx = n_ - 1;
    idx = skip_ws(idx);
    if (idx > end_idx || n_ == 0 || s_[idx] != '}') {
      for (;;) {
        if (idx >= n_ || s_[idx] != '"') fail_at("Expecting property name enclosed in double quotes", idx);
        std::size_t nx;
        std::string key = scanstring(idx + 1, &nx);
        idx = skip_ws(nx);
        if (idx >= n_ || s_[idx] != ':') fail_at("Expecting ':' delimiter", idx);
        idx = skip_ws(idx + 1);
        Json val = scan_once(idx, &nx, false);
        obj.obj.emplace_back(std::move(key), std::move(val));
        idx = skip_ws(nx);
        if (idx < n_ && s_[idx] == '}') break;
        if (idx >= n_ || s_[idx] != ',') fail_at("Expecting ',' delimiter", idx);
        idx = skip_ws(idx + 1);
      }
    }
    *next = idx + 1;
    // pack.py's object_pairs_hook: duplicate keys are an error.
    for (std::size_t a = 0; a < obj.obj.size(); ++a)
      for (std::size_t b = 0; b < a; ++b)
        if (obj.obj[a].first == obj.obj[b].first) throw Fail{"duplicate key " + py_repr(obj.obj[a].first)};
    return obj;
  }

  Json parse_array(std::size_t idx, std::size_t* next) {
    Json arr = Json::array();
    idx = skip_ws(idx);
    if (idx >= n_ || s_[idx] != ']') {
      for (;;) {
        std::size_t nx;
        arr.arr.push_back(scan_once(idx, &nx, false));
        idx = skip_ws(nx);
        if (idx < n_ && s_[idx] == ']') break;
        if (idx >= n_ || s_[idx] != ',') fail_at("Expecting ',' delimiter", idx);
        idx = skip_ws(idx + 1);
      }
    }
    *next = idx + 1;
    return arr;
  }
};

// pack.py's _check_json.
void check_json(const Json& v, const std::string& path) {
  switch (v.kind) {
    case Json::Kind::Null:
    case Json::Kind::Bool:
      return;
    case Json::Kind::Int:
      if (!v.big.empty() || v.i < INT32_MIN || v.i > INT32_MAX)
        throw Fail{path + ": integer " + (v.big.empty() ? std::to_string(v.i) : v.big) +
                   " outside the signed 32-bit range"};
      return;
    case Json::Kind::Str:
      for (std::uint32_t c : utf8_decode(v.s))
        if (c >= 0xD800 && c <= 0xDFFF) throw Fail{path + ": string holds a lone surrogate"};
      return;
    case Json::Kind::Arr:
      for (std::size_t k = 0; k < v.arr.size(); ++k) check_json(v.arr[k], path + "[" + std::to_string(k) + "]");
      return;
    case Json::Kind::Obj:
      for (const auto& [k, x] : v.obj) {
        bool bad = k.empty();
        for (unsigned char ch : k)
          if (ch < 0x20 || ch >= 0x7F) bad = true;
        if (bad) throw Fail{path + ": object key " + py_repr(k) + " must be printable ASCII"};
        check_json(x, path + "." + k);
      }
      return;
  }
}

void canon(const Json& v, std::string& out) {
  switch (v.kind) {
    case Json::Kind::Null: out += "null"; return;
    case Json::Kind::Bool: out += v.b ? "true" : "false"; return;
    case Json::Kind::Int: out += v.big.empty() ? std::to_string(v.i) : v.big; return;
    case Json::Kind::Str: {
      out += '"';
      for (unsigned char c : v.s) {
        switch (c) {
          case '"': out += "\\\""; break;
          case '\\': out += "\\\\"; break;
          case '\n': out += "\\n"; break;
          case '\r': out += "\\r"; break;
          case '\t': out += "\\t"; break;
          case '\b': out += "\\b"; break;
          case '\f': out += "\\f"; break;
          default:
            if (c < 0x20) {
              char b[8];
              std::snprintf(b, sizeof b, "\\u%04x", c);
              out += b;
            } else {
              out += static_cast<char>(c);
            }
        }
      }
      out += '"';
      return;
    }
    case Json::Kind::Arr:
      out += '[';
      for (std::size_t k = 0; k < v.arr.size(); ++k) {
        if (k) out += ',';
        canon(v.arr[k], out);
      }
      out += ']';
      return;
    case Json::Kind::Obj: {
      std::vector<const std::pair<std::string, Json>*> m;
      for (const auto& p : v.obj) m.push_back(&p);
      // Code-point order equals UTF-8 byte order.
      std::sort(m.begin(), m.end(), [](auto* a, auto* b) { return a->first < b->first; });
      out += '{';
      for (std::size_t k = 0; k < m.size(); ++k) {
        if (k) out += ',';
        canon(Json::string(m[k]->first), out);
        out += ':';
        canon(m[k]->second, out);
      }
      out += '}';
      return;
    }
  }
}

// Python's str.isprintable() for one code point, close enough for messages:
// control and format characters, separators other than the space, surrogates,
// private-use and a few unassigned blocks are not printable.
bool printable(std::uint32_t c) {
  if (c < 0x20 || (c >= 0x7F && c <= 0xA0) || c == 0xAD) return false;
  if ((c >= 0x2000 && c <= 0x200F) || (c >= 0x2028 && c <= 0x202F) || (c >= 0x205F && c <= 0x206F)) return false;
  if (c == 0x1680 || c == 0x3000 || c == 0xFEFF || (c >= 0xFFF0 && c <= 0xFFFB) || c == 0xFFFE || c == 0xFFFF)
    return false;
  if ((c >= 0xD800 && c <= 0xF8FF) || c >= 0xF0000) return false;
  if (c == 0x061C || c == 0x180E || (c >= 0x0600 && c <= 0x0605) || c == 0x06DD || c == 0x070F) return false;
  return true;
}

}  // namespace

const Json* Json::get(const std::string& key) const {
  if (kind != Kind::Obj) return nullptr;
  for (const auto& [k, v] : obj)
    if (k == key) return &v;
  return nullptr;
}

bool Json::truthy() const {
  switch (kind) {
    case Kind::Null: return false;
    case Kind::Bool: return b;
    case Kind::Int: return i != 0;
    case Kind::Str: return !s.empty();
    case Kind::Arr: return !arr.empty();
    case Kind::Obj: return !obj.empty();
  }
  return false;
}

Json& Json::set(const std::string& key, Json v) {
  for (auto& [k, x] : obj)
    if (k == key) {
      x = std::move(v);
      return x;
    }
  obj.emplace_back(key, std::move(v));
  return obj.back().second;
}

bool operator==(const Json& a, const Json& b) {
  auto num = [](const Json& j, std::int64_t* v) {
    if (j.kind == Json::Kind::Bool) *v = j.b ? 1 : 0;
    else if (j.kind == Json::Kind::Int && j.big.empty()) *v = j.i;
    else return false;
    return true;
  };
  std::int64_t x, y;
  if (num(a, &x) && num(b, &y)) return x == y;
  if (a.kind != b.kind) return false;
  switch (a.kind) {
    case Json::Kind::Null: return true;
    case Json::Kind::Int: return a.big == b.big && a.i == b.i;
    case Json::Kind::Str: return a.s == b.s;
    case Json::Kind::Arr: return a.arr == b.arr;
    case Json::Kind::Obj:
      if (a.obj.size() != b.obj.size()) return false;
      for (const auto& [k, v] : a.obj) {
        const Json* o = b.get(k);
        if (!o || !(*o == v)) return false;
      }
      return true;
    default: return false;
  }
}

std::optional<Json> parse_json(const std::uint8_t* data, std::size_t size, std::string* error) {
  if (size >= 3 && data[0] == 0xEF && data[1] == 0xBB && data[2] == 0xBF) {
    data += 3;
    size -= 3;
  }
  std::vector<std::uint32_t> cps;
  std::string reason;
  if (!decode_utf8(data, size, &cps, &reason)) {
    if (error) *error = "not UTF-8 (" + reason + ")";
    return std::nullopt;
  }
  try {
    Parser p(cps);
    Json v = p.parse_document();
    check_json(v, "$");
    return v;
  } catch (const Fail& f) {
    if (error) *error = f.msg;
    return std::nullopt;
  }
}

std::string canonical_json(const Json& v) {
  std::string out;
  canon(v, out);
  return out;
}

std::vector<std::uint32_t> utf8_decode(const std::string& s) {
  std::vector<std::uint32_t> out;
  const auto* d = reinterpret_cast<const std::uint8_t*>(s.data());
  std::size_t i = 0, n = s.size();
  while (i < n) {
    std::uint8_t c = d[i];
    int need = c < 0x80 ? 0 : c < 0xE0 ? 1 : c < 0xF0 ? 2 : 3;
    std::uint32_t cp = need == 0 ? c : need == 1 ? (c & 0x1F) : need == 2 ? (c & 0x0F) : (c & 0x07);
    for (int k = 1; k <= need && i + k < n; ++k) cp = (cp << 6) | (d[i + k] & 0x3F);
    out.push_back(cp);
    i += static_cast<std::size_t>(need) + 1;
  }
  return out;
}

std::size_t utf8_length(const std::string& s) {
  std::size_t n = 0;
  for (unsigned char c : s)
    if ((c & 0xC0) != 0x80) ++n;
  return n;
}

std::string py_repr(const std::string& utf8) {
  const auto cps = utf8_decode(utf8);
  bool has_sq = false, has_dq = false;
  for (std::uint32_t c : cps) {
    if (c == '\'') has_sq = true;
    if (c == '"') has_dq = true;
  }
  const char q = has_sq && !has_dq ? '"' : '\'';
  std::string out(1, q);
  for (std::uint32_t c : cps) {
    char b[16];
    if (c == static_cast<std::uint32_t>(q) || c == '\\') {
      out += '\\';
      out += static_cast<char>(c);
    } else if (c == '\t') {
      out += "\\t";
    } else if (c == '\n') {
      out += "\\n";
    } else if (c == '\r') {
      out += "\\r";
    } else if (!printable(c)) {
      if (c < 0x100) std::snprintf(b, sizeof b, "\\x%02x", c);
      else if (c < 0x10000) std::snprintf(b, sizeof b, "\\u%04x", c);
      else std::snprintf(b, sizeof b, "\\U%08x", c);
      out += b;
    } else {
      append_utf8(out, c);
    }
  }
  out += q;
  return out;
}

std::string py_repr(const Json& v) {
  switch (v.kind) {
    case Json::Kind::Null: return "None";
    case Json::Kind::Bool: return v.b ? "True" : "False";
    case Json::Kind::Int: return v.big.empty() ? std::to_string(v.i) : v.big;
    case Json::Kind::Str: return py_repr(v.s);
    case Json::Kind::Arr: {
      std::string out = "[";
      for (std::size_t k = 0; k < v.arr.size(); ++k) out += (k ? ", " : "") + py_repr(v.arr[k]);
      return out + "]";
    }
    case Json::Kind::Obj: {
      std::string out = "{";
      for (std::size_t k = 0; k < v.obj.size(); ++k)
        out += (k ? ", " : "") + py_repr(v.obj[k].first) + ": " + py_repr(v.obj[k].second);
      return out + "}";
    }
  }
  return "";
}

}  // namespace mvp::mods
