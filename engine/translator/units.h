// Translation units from decomp-toolkit's splits.txt (repository metadata): which
// unit each code address belongs to. The engine uses the unit's directory to
// tell the Nintendo SDK and runtime libraries (dolphin/, sdk/, libc/, libm/,
// libgcc/, libsn/: the K1 set) from game and EA code.
#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace mvp::xlat {

class UnitMap {
 public:
  static UnitMap parse(const std::string& splits_txt);

  // Unit name ("dolphin/os/OS.c") for an address, or "" outside every unit.
  const std::string& unit_at(std::uint32_t addr) const;
  // True for the runtime-library directories (K1's definition in tools/goals/targets.py).
  static bool is_runtime_unit(const std::string& unit);
  bool is_runtime(std::uint32_t addr) const { return is_runtime_unit(unit_at(addr)); }
  std::size_t size() const { return ranges_.size(); }

 private:
  struct Range {
    std::uint32_t end;
    std::size_t unit;
  };
  std::vector<std::string> names_;
  std::map<std::uint32_t, Range> ranges_;  // by start
};

}  // namespace mvp::xlat
