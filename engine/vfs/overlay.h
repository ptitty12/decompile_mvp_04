// The virtual disc's mod overlay (ARCHITECTURE.md §8, E6): files replaced by
// roster packs (database.big, the LOC files, rebuilt asset archives) are served
// from memory, and every other byte of the image is read from the player's disc
// unchanged.
//
// How: each replaced file's bytes are placed past the end of the image, each on
// a 32 KiB boundary, in the order given, and its FST entry is patched to point
// there (offset and size; the FST keeps its size and its names). The game finds
// files only through the FST (the boot environment copies it into MEM1), so it
// reads the new bytes wherever it would have read the old ones. The same image
// and the same replacements always give the same virtual disc, byte for byte.
//
// The disc identity of the netplay handshake (net/identity.h) is computed from
// the disc before mounting; the packs are compared by their own hash.
#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "vfs/disc_check.h"
#include "vfs/source.h"

namespace mvp::vfs {

// A source with byte ranges replaced: reads inside a patch come from memory,
// reads elsewhere from the base; past the base's end and between patches the
// source reads zeros up to its size (the end of the last patch).
class OverlaySource final : public Source {
 public:
  struct Patch {
    std::uint64_t offset = 0;
    std::vector<std::uint8_t> bytes;
  };
  // Patches must not overlap each other.
  OverlaySource(std::unique_ptr<Source> base, std::vector<Patch> patches);
  std::uint64_t size() const override { return size_; }
  bool read(std::uint64_t off, void* dst, std::size_t n) override;
  Source& base() { return *base_; }
  std::unique_ptr<Source> take_base() { return std::move(base_); }

 private:
  std::unique_ptr<Source> base_;
  std::vector<Patch> patches_;  // sorted by offset
  std::uint64_t size_ = 0;
};

// One replaced file: its disc path (matched ignoring ASCII case, as the SDK
// does) and its new bytes.
struct OverlayFile {
  std::string path;
  std::vector<std::uint8_t> bytes;
};

inline constexpr std::uint32_t kOverlayAlign = 0x8000;

// Replaces `files` on `disc`: its image becomes an OverlaySource over the old
// one and its GCM is parsed again from the patched FST. Returns false with the
// reason (a path that is not a file on the disc, a path given twice, or a disc
// that would grow past 4 GiB), leaving `disc` unchanged.
bool mount_overlay(Disc& disc, std::vector<OverlayFile> files, std::string* error = nullptr);

}  // namespace mvp::vfs
