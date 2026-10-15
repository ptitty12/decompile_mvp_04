#include "net/identity.h"

#include <cstdio>
#include <map>

#include "common/sha1.h"

namespace mvp::net {

std::array<std::uint8_t, 20> disc_identity(const vfs::Disc& disc) {
  Sha1 h;
  static const char kPrefix[] = "mvp2005-disc-id/1\n";
  h.update(kPrefix, sizeof kPrefix - 1);
  h.update(disc.gcm.boot().data(), disc.gcm.boot().size());
  h.update(disc.gcm.bi2().data(), disc.gcm.bi2().size());
  h.update(disc.gcm.fst_bytes().data(), disc.gcm.fst_bytes().size());
  h.update(disc.dol_sha1.data(), disc.dol_sha1.size());
  return h.finish();
}

std::string settings_string(const rt::HardwareConfig& hw, const rt::BootConfig& boot, std::uint32_t port_mask) {
  std::map<std::string, std::string> kv;
  auto num = [](unsigned long long v, bool hexa = false) {
    char b[32];
    std::snprintf(b, sizeof b, hexa ? "0x%llx" : "%llu", v);
    return std::string(b);
  };
  kv["ax_voices"] = hw.ax_voices ? "1" : "0";
  kv["rtc_seconds"] = num(hw.rtc_seconds, true);
  kv["sram_language"] = num(hw.sram_language);
  kv["sram_flags"] = num(hw.sram_flags, true);
  kv["console_type"] = num(boot.console_type, true);
  kv["tv_mode"] = num(boot.tv_mode);
  kv["aram_size"] = num(boot.aram_size, true);
  kv["bus_clock"] = num(boot.bus_clock);
  kv["cpu_clock"] = num(boot.cpu_clock);
  kv["ports"] = num(port_mask, true);
  kv["pad"] = "v" + std::to_string(rt::PadState::kVersion);
  std::string s;
  for (const auto& [k, v] : kv) {
    if (!s.empty()) s += ';';
    s += k + "=" + v;
  }
  return s;
}

std::array<std::uint8_t, 32> empty_packset_hash() {
  // SHA-256("mvp2005-packset-hash/1\n{\"packs\":[]}"), as tools/rosters/pack.py set_hash([]).
  static const char kHex[] = "f5e1298911db13adf522a1b34d4d4f9291b42fa7a77f63a5f6f07bc322dcc66e";
  auto nib = [](char c) { return static_cast<std::uint8_t>(c <= '9' ? c - '0' : c - 'a' + 10); };
  std::array<std::uint8_t, 32> a{};
  for (int i = 0; i < 32; ++i) a[i] = static_cast<std::uint8_t>(nib(kHex[2 * i]) << 4 | nib(kHex[2 * i + 1]));
  return a;
}

Identity make_identity(const std::string& build, const vfs::Disc& disc, const rt::HardwareConfig& hw,
                       const rt::BootConfig& boot, const rt::ClockConfig& clk, std::uint32_t port_mask) {
  Identity id;
  id.build = build;
  id.disc = disc_identity(disc);
  id.packset = empty_packset_hash();
  id.settings = settings_string(hw, boot, port_mask);
  id.cpi = clk.cpi;
  id.di_latency_tb = hw.di_latency_tb;
  id.di_tb_per_kib = hw.di_tb_per_kib;
  return id;
}

}  // namespace mvp::net
