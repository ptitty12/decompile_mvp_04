#include "vfs/overlay.h"

#include <algorithm>
#include <cctype>
#include <cstring>

#include "common/bytes.h"

namespace mvp::vfs {

OverlaySource::OverlaySource(std::unique_ptr<Source> base, std::vector<Patch> patches)
    : base_(std::move(base)), patches_(std::move(patches)) {
  std::sort(patches_.begin(), patches_.end(), [](const Patch& a, const Patch& b) { return a.offset < b.offset; });
  size_ = base_->size();
  for (const auto& p : patches_) size_ = std::max<std::uint64_t>(size_, p.offset + p.bytes.size());
}

bool OverlaySource::read(std::uint64_t off, void* dst, std::size_t n) {
  if (off > size_ || n > size_ - off) return false;
  std::uint8_t* out = static_cast<std::uint8_t*>(dst);
  const std::uint64_t end = off + n;
  std::uint64_t pos = off;
  // The first patch that ends after `pos`.
  auto it = std::upper_bound(patches_.begin(), patches_.end(), pos,
                             [](std::uint64_t v, const Patch& p) { return v < p.offset + p.bytes.size(); });
  while (pos < end) {
    const bool inside = it != patches_.end() && it->offset <= pos;
    if (inside) {
      const std::uint64_t stop = std::min<std::uint64_t>(end, it->offset + it->bytes.size());
      std::memcpy(out + (pos - off), it->bytes.data() + (pos - it->offset), static_cast<std::size_t>(stop - pos));
      pos = stop;
      ++it;
      continue;
    }
    const std::uint64_t stop = std::min<std::uint64_t>(end, it != patches_.end() ? it->offset : end);
    // From the base up to its end, zeros after it.
    const std::uint64_t base_end = base_->size();
    if (pos < base_end) {
      const std::uint64_t s = std::min(stop, base_end);
      if (!base_->read(pos, out + (pos - off), static_cast<std::size_t>(s - pos))) return false;
      pos = s;
    }
    if (pos < stop) {
      std::memset(out + (pos - off), 0, static_cast<std::size_t>(stop - pos));
      pos = stop;
    }
  }
  return true;
}

bool mount_overlay(Disc& disc, std::vector<OverlayFile> files, std::string* error) {
  auto fail = [&](const std::string& why) {
    if (error) *error = "overlay: " + why;
    return false;
  };
  if (files.empty()) return true;
  auto lower = [](std::string s) {
    for (char& c : s) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return s;
  };
  const auto& entries = disc.gcm.entries();
  std::vector<std::uint8_t> fst = disc.gcm.fst_bytes();
  std::vector<OverlaySource::Patch> patches;
  std::vector<std::string> seen;
  std::uint64_t pos = disc.image->size();
  for (const auto& e : entries)
    if (!e.is_dir) pos = std::max<std::uint64_t>(pos, std::uint64_t(e.offset) + e.size);
  for (auto& f : files) {
    const std::string key = lower(f.path);
    if (std::find(seen.begin(), seen.end(), key) != seen.end()) return fail(f.path + " is replaced twice");
    seen.push_back(key);
    std::size_t index = entries.size();
    for (std::size_t j = 0; j < entries.size(); ++j)
      if (!entries[j].is_dir && lower(entries[j].path) == key) {
        index = j;
        break;
      }
    if (index == entries.size()) return fail("the disc has no file " + f.path);
    pos = (pos + kOverlayAlign - 1) & ~std::uint64_t(kOverlayAlign - 1);
    if (pos + f.bytes.size() > 0xFFFFFFFFull) return fail("the patched disc would be larger than 4 GiB");
    // Entries are the FST's entries after the root: entry j is FST record j + 1.
    std::uint8_t* rec = fst.data() + (index + 1) * 12;
    put_be32(rec + 4, static_cast<std::uint32_t>(pos));
    put_be32(rec + 8, static_cast<std::uint32_t>(f.bytes.size()));
    const std::uint64_t at = pos;
    pos += f.bytes.size();
    patches.push_back({at, std::move(f.bytes)});
  }
  patches.push_back({disc.gcm.fst_offset(), std::move(fst)});
  auto image = std::make_unique<OverlaySource>(std::move(disc.image), std::move(patches));
  std::string err;
  auto gcm = Gcm::open(*image, &err);
  if (!gcm) {
    disc.image = image->take_base();
    return fail(err);
  }
  disc.gcm = std::move(*gcm);
  disc.image = std::move(image);
  return true;
}

}  // namespace mvp::vfs
