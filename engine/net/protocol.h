// Netplay wire protocol, version 1 (E5; docs/engine/NETPLAY.md is the normative
// description, this header the reference implementation).
//
// Peers exchange datagrams over an unreliable, unordered channel (a WebRTC data
// channel with maxRetransmits 0; UDP natively). Every datagram starts with a
// 4-byte header: 'M' 'N' (0x4D 0x4E), the protocol major version, the message
// type. Multi-byte integers are big-endian. A datagram that does not parse is
// dropped and counted; it never changes session state.
//
// Messages:
//   HELLO  the handshake: identity, settings, role and proposed input delay,
//          repeated until the peer has seen it (net/session.h);
//   INPUT  the sender's controller state for a contiguous range of frames
//          (every frame the peer has not acknowledged yet, oldest first, at most
//          kMaxInputsPerPacket; a pad equal to the previous one is one byte), the
//          sender's unacknowledged state hashes, and acknowledgements and
//          timestamps (round-trip time);
//   BYE    the session ends: quit, desync, rejected handshake or timeout.
//
// The protocol is a versioned engine API (CLAUDE.md): a change that an older
// peer cannot parse needs a new major version.
#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

#include "runtime/input.h"

namespace mvp::net {

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using rt::PadState;

inline constexpr u8 kMagic0 = 0x4D, kMagic1 = 0x4E;  // "MN"
inline constexpr u8 kProtocolMajor = 1;
inline constexpr u8 kProtocolMinor = 0;

enum class MsgType : u8 { Hello = 1, Input = 2, Bye = 3 };

inline constexpr std::size_t kHeaderSize = 4;
inline constexpr std::size_t kPadWireSize = 11;  // one port of runtime/input.h's wire form
inline constexpr u8 kPadRepeat = 0x80;  // INPUT: "same pad as the previous one" (a flags byte never has bit 7)
inline constexpr std::size_t kMaxInputsPerPacket = 64;
inline constexpr std::size_t kMaxHashesPerPacket = 8;
inline constexpr std::size_t kMaxBuildId = 64;
inline constexpr std::size_t kMaxSettings = 512;
inline constexpr std::size_t kMaxReason = 200;

// What both peers must have identical before a match starts (ARCHITECTURE §8).
struct Identity {
  std::string build;            // engine build id (the web shell: SHA-256 of the engine files)
  std::array<u8, 20> disc{};    // disc identity (net/identity.h: GV4E69 rev 0, main.dol, FST)
  std::array<u8, 32> packset{}; // ordered pack-set hash (MODDING.md §10)
  std::string settings;         // canonical engine settings, "key=value;..." (net/identity.h)
  u32 cpi_milli = 1250;         // CLK2: CPU cycles per guest instruction, in thousandths (rt::ClockConfig;
                                // E0b-CLK1 builds sent whole cycles, 2, so they refuse these)
  u32 di_latency_tb = 40500;    // DVD1: command latency, time-base ticks
  u32 di_tb_per_kib = 13184;    // DVD1: transfer time, time-base ticks per KiB
  bool operator==(const Identity&) const = default;
};

struct Hello {
  u8 minor = kProtocolMinor;
  u8 player = 1;           // 1 or 2: drives controller port 1 or 2
  bool seen_peer = false;  // the sender has received the peer's HELLO
  u8 delay = 3;            // proposed input delay in frames (the session uses the larger)
  u16 hash_interval = 60;  // frames per state-hash window (0: no desync check); must match
  u64 nonce = 0;           // random per session instance (tells restarts apart)
  u64 seed = 0;            // shared seed; player 1's value is used
  Identity id;
  bool operator==(const Hello&) const = default;
};

struct HashRecord {
  u32 frame = 0;  // the frame poll at which the hash window closed
  u64 hash = 0;
  bool operator==(const HashRecord&) const = default;
};

struct Input {
  u32 ack_frame = 0;   // the sender has every peer input before this frame
  u32 ack_hash = 0;    // the sender has every peer hash record before this frame
  u32 cur_frame = 0;   // the sender's next frame poll (diagnostics: who waits for whom)
  u32 send_ms = 0;     // sender's clock when sent (wraps)
  u32 echo_ms = 0;     // the latest send_ms received from the peer (0: none yet)
  u32 echo_hold_ms = 0;  // how long the sender held echo_ms before this send
  u32 first_frame = 0;   // frame of pads[0]
  std::vector<PadState> pads;      // the sender's port, frames first_frame..
  std::vector<HashRecord> hashes;  // ascending frames
  bool operator==(const Input&) const = default;
};

enum class ByeReason : u8 { Quit = 0, Desync = 1, Rejected = 2, Timeout = 3, Error = 4 };

struct Bye {
  ByeReason reason = ByeReason::Quit;
  u32 frame = 0;     // Desync: the window that differed; otherwise the sender's next frame
  std::string text;  // short reason for the other player (at most kMaxReason bytes)
  bool operator==(const Bye&) const = default;
};

// One port's controller state, 11 bytes (the per-port part of rt::encode_frame).
void put_pad(std::vector<u8>& out, const PadState& p);
std::optional<PadState> get_pad(const u8* q);

std::vector<u8> encode(const Hello& m);
std::vector<u8> encode(const Input& m);
std::vector<u8> encode(const Bye& m);

// The type of a datagram with a valid header, else nullopt (wrong magic or major
// version, too short).
std::optional<MsgType> peek_type(const u8* data, std::size_t size);
std::optional<Hello> decode_hello(const u8* data, std::size_t size);
std::optional<Input> decode_input(const u8* data, std::size_t size);
std::optional<Bye> decode_bye(const u8* data, std::size_t size);

// Why two HELLOs cannot play together, or "" when they can. Checks roles, the
// hash interval and every identity field; the delay is negotiated, not checked.
std::string incompatibility(const Hello& mine, const Hello& theirs);

std::string hex(const u8* data, std::size_t size);

}  // namespace mvp::net
