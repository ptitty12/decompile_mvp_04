#include "translator/units.h"

#include <cstdlib>
#include <sstream>

namespace mvp::xlat {

UnitMap UnitMap::parse(const std::string& text) {
  UnitMap m;
  std::istringstream in(text);
  std::string line;
  bool in_sections = false;
  std::size_t cur = static_cast<std::size_t>(-1);
  while (std::getline(in, line)) {
    if (!line.empty() && line.back() == '\r') line.pop_back();
    if (line.empty()) continue;
    if (line == "Sections:") {
      in_sections = true;
      continue;
    }
    if (line[0] != '\t' && line[0] != ' ') {
      in_sections = false;
      if (line.back() == ':') {
        m.names_.push_back(line.substr(0, line.size() - 1));
        cur = m.names_.size() - 1;
      }
      continue;
    }
    if (in_sections || cur == static_cast<std::size_t>(-1)) continue;
    // "\t.text       start:0x80003100 end:0x8000348C"
    auto s = line.find("start:0x"), e = line.find("end:0x");
    if (s == std::string::npos || e == std::string::npos) continue;
    std::uint32_t start = static_cast<std::uint32_t>(std::strtoul(line.c_str() + s + 8, nullptr, 16));
    std::uint32_t end = static_cast<std::uint32_t>(std::strtoul(line.c_str() + e + 6, nullptr, 16));
    m.ranges_[start] = Range{end, cur};
  }
  return m;
}

const std::string& UnitMap::unit_at(std::uint32_t addr) const {
  static const std::string none;
  auto it = ranges_.upper_bound(addr);
  if (it == ranges_.begin()) return none;
  --it;
  return addr < it->second.end ? names_[it->second.unit] : none;
}

bool UnitMap::is_runtime_unit(const std::string& u) {
  for (const char* d : {"dolphin/", "sdk/", "libc/", "libm/", "libgcc/", "libsn/"})
    if (u.rfind(d, 0) == 0) return true;
  return false;
}

}  // namespace mvp::xlat
