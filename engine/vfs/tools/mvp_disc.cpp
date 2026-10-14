// mvp-disc: inspect the player's disc image (development tool).
//
//   mvp-disc info     <image>            identity, header fields, DOL hash
//   mvp-disc ls       <image>            FST listing
//   mvp-disc sections <image>            DOL section table, named from /mvp.elf
//   mvp-disc dol      <image> <out.dol>  extract main.dol (write it under build/ only)
//
// Everything this prints or writes is derived from the player's disc: keep the
// outputs in build/, never in the repository.
#include <cstdio>
#include <string>

#include "common/file.h"
#include "vfs/disc_check.h"

using namespace mvp;
using namespace mvp::vfs;

static int usage() {
  std::fprintf(stderr, "usage: mvp-disc info|ls|sections <image> | dol <image> <out.dol>\n");
  return 2;
}

int main(int argc, char** argv) {
  if (argc < 3) return usage();
  std::string cmd = argv[1];
  std::string err;
  // Only `info` accepts a non-retail image, so it can describe what it found.
  auto disc = open_disc(argv[2], cmd != "info", &err);
  if (!disc) {
    std::fprintf(stderr, "mvp-disc: %s\n", err.c_str());
    return 1;
  }
  if (cmd == "info") {
    std::printf("game id   %s (disc %u, revision %u)\n", disc->gcm.game_id().c_str(), disc->gcm.disc_number(),
                disc->gcm.revision());
    std::printf("title     %s\n", disc->gcm.title().c_str());
    std::printf("image     %llu bytes\n", static_cast<unsigned long long>(disc->image->size()));
    std::printf("main.dol  offset 0x%08X, %zu bytes, sha1 %s (%s)\n", disc->gcm.dol_offset(),
                disc->dol.bytes().size(), disc->dol_sha1.c_str(),
                disc->dol_sha1 == kRetailDolSha1 ? "GV4E69 rev 0" : "NOT the retail DOL");
    std::printf("entry     0x%08X\n", disc->dol.entry());
    std::printf("fst       offset 0x%08X, %u bytes, %zu entries\n", disc->gcm.fst_offset(), disc->gcm.fst_size(),
                disc->gcm.entries().size());
    return 0;
  }
  if (cmd == "ls") {
    for (const auto& e : disc->gcm.entries()) {
      if (e.is_dir)
        std::printf("%-10s %10s %s/\n", "", "", e.path.c_str());
      else
        std::printf("0x%08X %10u %s\n", e.offset, e.size, e.path.c_str());
    }
    return 0;
  }
  if (cmd == "sections") {
    std::printf("slot kind  offset      address     size\n");
    for (const auto& s : disc->dol.sections())
      std::printf("%4d %-5s 0x%08X  0x%08X  0x%08X\n", s.slot, s.text ? "text" : "data", s.offset, s.address, s.size);
    std::printf("     bss   %10s  0x%08X  0x%08X\n", "", disc->dol.bss_address(), disc->dol.bss_size());
    std::printf("entry 0x%08X\n\n", disc->dol.entry());
    auto elf = disc->gcm.read_file(*disc->image, "/mvp.elf");
    if (!elf) {
      std::fprintf(stderr, "mvp-disc: /mvp.elf not on the disc; cannot name sections\n");
      return 1;
    }
    auto secs = parse_elf_sections(*elf, &err);
    if (!secs) {
      std::fprintf(stderr, "mvp-disc: %s\n", err.c_str());
      return 1;
    }
    for (const auto& l : dol_layout_lines(disc->dol, *secs)) std::printf("%s\n", l.c_str());
    return 0;
  }
  if (cmd == "dol") {
    if (argc < 4) return usage();
    if (!write_file(argv[3], disc->dol.bytes().data(), disc->dol.bytes().size())) {
      std::fprintf(stderr, "mvp-disc: cannot write %s\n", argv[3]);
      return 1;
    }
    std::printf("wrote %s (%zu bytes, sha1 %s)\n", argv[3], disc->dol.bytes().size(), disc->dol_sha1.c_str());
    return 0;
  }
  return usage();
}
