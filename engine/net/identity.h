// What the netplay handshake compares (net/protocol.h Identity), computed from
// the engine's own configuration and the player's disc.
#pragma once

#include <array>
#include <cstdint>
#include <string>

#include "net/protocol.h"
#include "runtime/boot.h"
#include "runtime/hw.h"
#include "runtime/sys_hooks.h"
#include "vfs/disc_check.h"

namespace mvp::net {

// Disc identity v1: SHA-1 of "mvp2005-disc-id/1\n", the disc header (boot.bin,
// 0x440 bytes: game id, revision), BI2 (0x2000 bytes), the FST bytes and the
// hex SHA-1 of main.dol. That is everything the boot environment copies into
// guest memory plus the code; different dump formats (ISO, CISO) of the same
// disc give the same identity. File contents beyond main.dol are not hashed
// (that would read the whole image); a damaged file shows up as a desync.
std::array<std::uint8_t, 20> disc_identity(const vfs::Disc& disc);

// The canonical settings string: every engine setting that changes guest
// behaviour and is not already a separate identity field, as sorted
// "key=value" pairs joined by ';'. Both peers must have the same string.
std::string settings_string(const rt::HardwareConfig& hw, const rt::BootConfig& boot, std::uint32_t port_mask);

// The SHA-256 set hash of the empty pack set (MODDING.md §10):
// SHA-256("mvp2005-packset-hash/1\n" + "{\"packs\":[]}").
std::array<std::uint8_t, 32> empty_packset_hash();

// Identity for this engine configuration (build id from the caller).
Identity make_identity(const std::string& build, const vfs::Disc& disc, const rt::HardwareConfig& hw,
                       const rt::BootConfig& boot, const rt::ClockConfig& clk, std::uint32_t port_mask);

// The port mask of a netplay match: players 1 and 2 on ports 1 and 2.
inline constexpr std::uint32_t kNetplayPorts = 0x3;

}  // namespace mvp::net
