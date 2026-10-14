// Names for SDK functions that symbols.txt still lists as fn_ placeholders but
// whose identity is established (E0b item 8 routes and logs SDK calls by name).
// Only addresses with evidence belong here; when symbols.txt names one, its
// entry here becomes redundant and can go.
#pragma once

#include <cstdint>

namespace mvp::rt {

struct SdkAlias {
  std::uint32_t address;
  const char* name;
  const char* evidence;
};

inline constexpr SdkAlias kSdkAliases[] = {
    {0x8043188C, "OSInit", "body matches dolsdk2004 OSInit (src/dolphin/os/tu_80431828.c); K1b holds the rename for a data split"},
    {0x80422FD8, "DVDInit", "K1b (lead message 2026-10-14): held back for a data-split fix"},
    {0x80438704, "__init_user", "called by __start after OSInit; K1b (lead message 2026-10-14)"},
};

inline const char* sdk_alias(std::uint32_t address) {
  for (const auto& a : kSdkAliases)
    if (a.address == address) return a.name;
  return nullptr;
}

}  // namespace mvp::rt
