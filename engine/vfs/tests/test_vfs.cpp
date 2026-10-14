// Data-free tests for the disc layer: a synthetic GCM with an FST and a DOL, read
// directly and through a CISO container.
#include <doctest/doctest.h>

#include <cstring>
#include <string>
#include <vector>

#include "common/bytes.h"
#include "common/sha1.h"
#include "vfs/disc_check.h"

using namespace mvp;
using namespace mvp::vfs;

namespace {

std::vector<u8> make_dol() {
  // text0 @0x80003100 (0x40 bytes), data0 @0x80005000 (0x20), data1 @0x80006000 (0x20)
  std::vector<u8> d(0x100 + 0x40 + 0x20 + 0x20, 0);
  auto set = [&](int slot, u32 off, u32 addr, u32 size) {
    put_be32(&d[4 * slot], off);
    put_be32(&d[0x48 + 4 * slot], addr);
    put_be32(&d[0x90 + 4 * slot], size);
  };
  set(0, 0x100, 0x80003100, 0x40);
  set(7, 0x140, 0x80005000, 0x20);
  set(8, 0x160, 0x80006000, 0x20);
  put_be32(&d[0xD8], 0x80007000);
  put_be32(&d[0xDC], 0x1000);
  put_be32(&d[0xE0], 0x80003100);
  for (u32 i = 0x100; i < d.size(); ++i) d[i] = u8(i);
  return d;
}

struct File {
  std::string name;
  std::vector<u8> data;
};

// Disc: header, BI2, FST at 0x2440, files after it, DOL last.
std::vector<u8> make_gcm(const std::vector<u8>& dol, std::vector<File> root_files, std::vector<File> sub_files) {
  std::vector<u8> disc(0x10000, 0);
  std::memcpy(&disc[0], "GTST01", 6);
  put_be32(&disc[0x1C], Gcm::kDiscMagic);
  std::strcpy(reinterpret_cast<char*>(&disc[0x20]), "Synthetic Test Disc");
  // FST: root, root files, dir "sub", sub files.
  u32 count = 1 + u32(root_files.size()) + 1 + u32(sub_files.size());
  std::vector<u8> fst(count * 12, 0), strtab;
  auto add_name = [&](const std::string& n) {
    u32 o = u32(strtab.size());
    strtab.insert(strtab.end(), n.begin(), n.end());
    strtab.push_back(0);
    return o;
  };
  u32 data_at = 0x4000;
  std::vector<std::pair<u32, const File*>> placed;
  u32 idx = 1;
  fst[0] = 1;
  put_be32(&fst[8], count);
  auto file_entry = [&](const File& f) {
    put_be32(&fst[idx * 12], add_name(f.name));
    put_be32(&fst[idx * 12 + 4], data_at);
    put_be32(&fst[idx * 12 + 8], u32(f.data.size()));
    placed.emplace_back(data_at, &f);
    data_at += (u32(f.data.size()) + 31) & ~31u;
    ++idx;
  };
  for (const auto& f : root_files) file_entry(f);
  u32 dir_idx = idx++;
  put_be32(&fst[dir_idx * 12], add_name("sub"));
  fst[dir_idx * 12] = 1;
  put_be32(&fst[dir_idx * 12 + 4], 0);
  put_be32(&fst[dir_idx * 12 + 8], count);
  for (const auto& f : sub_files) file_entry(f);
  fst.insert(fst.end(), strtab.begin(), strtab.end());
  u32 fst_off = 0x2440;
  std::memcpy(&disc[fst_off], fst.data(), fst.size());
  for (auto& [at, f] : placed) std::memcpy(&disc[at], f->data.data(), f->data.size());
  u32 dol_off = (data_at + 0xFF) & ~0xFFu;
  std::memcpy(&disc[dol_off], dol.data(), dol.size());
  put_be32(&disc[0x420], dol_off);
  put_be32(&disc[0x424], fst_off);
  put_be32(&disc[0x428], u32(fst.size()));
  put_be32(&disc[0x42C], u32(fst.size()));
  return disc;
}

std::vector<u8> to_ciso(const std::vector<u8>& raw, u32 bs) {
  std::vector<u8> out(0x8000, 0);
  std::memcpy(&out[0], "CISO", 4);
  out[4] = u8(bs);
  out[5] = u8(bs >> 8);
  out[6] = u8(bs >> 16);
  out[7] = u8(bs >> 24);
  for (std::size_t b = 0; b * bs < raw.size(); ++b) {
    bool zero = true;
    std::size_t end = std::min(raw.size(), (b + 1) * bs);
    for (std::size_t i = b * bs; i < end; ++i) zero &= raw[i] == 0;
    if (zero) continue;
    out[8 + b] = 1;
    std::vector<u8> blk(bs, 0);
    std::memcpy(blk.data(), &raw[b * bs], end - b * bs);
    out.insert(out.end(), blk.begin(), blk.end());
  }
  return out;
}

std::vector<File> root_files() { return {{"a.bin", {1, 2, 3, 4, 5}}, {"mvp.elf", {}}}; }
std::vector<File> sub_files() {
  std::vector<u8> big(3000);
  for (std::size_t i = 0; i < big.size(); ++i) big[i] = u8(i * 13 + 1);
  return {{"Big.dat", big}};
}

}  // namespace

TEST_CASE("DOL header parse") {
  auto bytes = make_dol();
  CHECK(Dol::size_from_header(bytes) == u32(bytes.size()));
  std::string err;
  auto dol = Dol::parse(bytes, &err);
  REQUIRE(dol);
  REQUIRE(dol->sections().size() == 3);
  CHECK(dol->sections()[0].text);
  CHECK(dol->sections()[1].slot == 7);
  CHECK(dol->entry() == 0x80003100);
  CHECK(dol->bss_address() == 0x80007000);
  CHECK(dol->at(0x80003100)[0] == u8(0x100));
  CHECK(dol->at(0x80005004)[0] == u8(0x144));
  CHECK(dol->at(0x80003140) == nullptr);       // one past the text section
  CHECK(dol->at(0x8000313E, 4) == nullptr);    // straddles the end
}

TEST_CASE("DOL rejects bad headers") {
  auto bytes = make_dol();
  put_be32(&bytes[0x90], 0x10000);  // text0 runs past the file
  CHECK_FALSE(Dol::parse(bytes));
  bytes = make_dol();
  put_be32(&bytes[0x48 + 4 * 7], 0x80003120);  // data0 overlaps text0
  CHECK_FALSE(Dol::parse(bytes));
  CHECK_FALSE(Dol::parse(std::vector<u8>(0x80)));
}

TEST_CASE("GCM FST and files, plain and CISO") {
  auto dol = make_dol();
  auto raw = make_gcm(dol, root_files(), sub_files());
  for (int pass = 0; pass < 2; ++pass) {
    std::unique_ptr<Source> src;
    if (pass == 0) {
      src = std::make_unique<MemorySource>(raw);
    } else {
      std::string err;
      src = CisoSource::open(std::make_unique<MemorySource>(to_ciso(raw, 0x800)), &err);
      REQUIRE_MESSAGE(src, err);
      // Unstored blocks read as zero, up to a full GameCube disc.
      CHECK(src->size() == std::min<u64>(1459978240ull, u64(0x8000 - 8) * 0x800));
      u8 z[16];
      CHECK(src->read(0x9000, z, 16));
      CHECK(z[0] == 0);
      std::vector<u8> back(raw.size());
      CHECK(src->read(0, back.data(), back.size()));
      CHECK(back == raw);
    }
    std::string err;
    auto disc = open_disc(std::move(src), false, &err);
    REQUIRE_MESSAGE(disc, err);
    CHECK(disc->gcm.game_id() == "GTST01");
    CHECK(disc->gcm.title() == "Synthetic Test Disc");
    REQUIRE(disc->gcm.entries().size() == 4);
    CHECK(disc->gcm.entries()[2].path == "/sub");
    CHECK(disc->gcm.entries()[2].is_dir);
    CHECK(disc->gcm.entries()[3].path == "/sub/Big.dat");
    auto big = disc->gcm.read_file(*disc->image, "/SUB/big.DAT");  // case-insensitive
    REQUIRE(big);
    CHECK(*big == sub_files()[0].data);
    CHECK(disc->dol.bytes() == dol);
    CHECK(disc->dol_sha1 == Sha1::of(dol.data(), dol.size()));
    CHECK_FALSE(disc->gcm.read_file(*disc->image, "/missing"));
  }
}

TEST_CASE("open_disc refuses a non-retail image when retail is required") {
  auto raw = make_gcm(make_dol(), root_files(), sub_files());
  std::string err;
  CHECK_FALSE(open_disc(std::make_unique<MemorySource>(raw), true, &err));
  CHECK(err.find("GV4E69") != std::string::npos);
}

TEST_CASE("CISO rejects malformed headers") {
  std::vector<u8> h(0x8000, 0);
  std::memcpy(&h[0], "CISO", 4);
  h[4] = 0x00;
  h[5] = 0x03;  // 0x300: not a power of two
  CHECK_FALSE(CisoSource::open(std::make_unique<MemorySource>(h)));
  h[5] = 0x02;
  h[8] = 1;  // claims one stored block, but the file has none
  CHECK_FALSE(CisoSource::open(std::make_unique<MemorySource>(h)));
}

TEST_CASE("layout lines name the ELF sections inside each DOL slot") {
  auto dol = Dol::parse(make_dol());
  REQUIRE(dol);
  std::vector<ElfSection> elf = {
      {"", 0, 0, 0, 0, 0},
      {".init", 1, 6, 0x80003100, 0, 0x20},
      {".text", 1, 6, 0x80003120, 0, 0x20},
      {".ctors", 1, 2, 0x80005000, 0, 0x10},
      {".dtors", 1, 2, 0x80005010, 0, 0x10},
      {".data", 1, 3, 0x80006000, 0, 0x20},
      {".bss", 8, 3, 0x80007000, 0, 0x800},
      {".sbss", 8, 3, 0x80007800, 0, 0x800},
      {".comment", 1, 0, 0, 0, 0x40},  // not allocated
  };
  auto lines = dol_layout_lines(*dol, elf);
  std::vector<std::string> want = {"text .init .text", "data .ctors .dtors", "data .data", "bss .bss .sbss"};
  CHECK(lines == want);
  CHECK(normalized_layout("# comment\ntext  .init\t.text\n\n  data .ctors  # x\n") ==
        std::vector<std::string>{"text .init .text", "data .ctors"});
}

TEST_CASE("ELF section header parse") {
  // Minimal ELF: null section, one named section, and the section-name table.
  std::vector<u8> e(0x200, 0);
  e[0] = 0x7F; e[1] = 'E'; e[2] = 'L'; e[3] = 'F'; e[4] = 1; e[5] = 2;
  const char names[] = "\0.text\0.shstrtab\0";
  std::memcpy(&e[0x100], names, sizeof names);
  put_be32(&e[32], 0x40);  // shoff
  put_be16(&e[46], 40);    // shentsize
  put_be16(&e[48], 3);     // shnum
  put_be16(&e[50], 2);     // shstrndx
  u8* s1 = &e[0x40 + 40];
  put_be32(s1, 1);
  put_be32(s1 + 4, 1);
  put_be32(s1 + 8, 6);
  put_be32(s1 + 12, 0x80003100);
  put_be32(s1 + 20, 0x80);
  u8* s2 = &e[0x40 + 80];
  put_be32(s2, 7);
  put_be32(s2 + 4, 3);
  put_be32(s2 + 16, 0x100);
  put_be32(s2 + 20, sizeof names);
  auto secs = parse_elf_sections(e);
  REQUIRE(secs);
  REQUIRE(secs->size() == 3);
  CHECK((*secs)[1].name == ".text");
  CHECK((*secs)[1].alloc());
  CHECK((*secs)[1].addr == 0x80003100);
  CHECK((*secs)[2].name == ".shstrtab");
  CHECK_FALSE((*secs)[2].alloc());
}
