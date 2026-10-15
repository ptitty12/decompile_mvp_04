#include <doctest/doctest.h>

#include <string>
#include <vector>

#include "common/bytes.h"
#include "common/sha1.h"
#include "common/sha256.h"

using namespace mvp;

TEST_CASE("big-endian loads and stores") {
  u8 b[8] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0};
  CHECK(be16(b) == 0x1234);
  CHECK(be32(b) == 0x12345678u);
  CHECK(be64(b) == 0x123456789ABCDEF0ull);
  CHECK(le32(b) == 0x78563412u);
  u8 o[8] = {};
  put_be32(o, 0xCAFEBABEu);
  CHECK(o[0] == 0xCA);
  CHECK(o[3] == 0xBE);
  put_be16(o + 4, 0x0102);
  CHECK(be16(o + 4) == 0x0102);
  put_be64(o, 0x0011223344556677ull);
  CHECK(be64(o) == 0x0011223344556677ull);
}

TEST_CASE("sha1 FIPS 180 vectors") {
  CHECK(Sha1::of("", 0) == "da39a3ee5e6b4b0d3255bfef95601890afd80709");
  CHECK(Sha1::of("abc", 3) == "a9993e364706816aba3e25717850c26c9cd0d89d");
  std::string two = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
  CHECK(Sha1::of(two.data(), two.size()) == "84983e441c3bd26ebaae4aa1f95129e5e54670f1");
  // One million 'a', fed in uneven pieces to exercise buffering.
  Sha1 s;
  std::vector<char> a(1000, 'a');
  std::size_t left = 1000000, step = 1;
  while (left) {
    std::size_t n = step % a.size() + 1;
    if (n > left) n = left;
    s.update(a.data(), n);
    left -= n;
    step = step * 7 + 3;
  }
  auto d = s.finish();
  CHECK(Sha1::hex(d) == "34aa973cd4c4daa4f61eeb2bdbad27316534016f");
}

TEST_CASE("sha1 split updates equal one update") {
  std::vector<u8> data(1000);
  for (std::size_t i = 0; i < data.size(); ++i) data[i] = u8(i * 7 + 3);
  std::string whole = Sha1::of(data.data(), data.size());
  for (std::size_t cut : {1u, 55u, 56u, 63u, 64u, 65u, 500u, 999u}) {
    Sha1 s;
    s.update(data.data(), cut);
    s.update(data.data() + cut, data.size() - cut);
    auto d = s.finish();
    CHECK(Sha1::hex(d) == whole);
  }
}

TEST_CASE("sha256 FIPS 180 vectors") {
  CHECK(Sha256::of("", 0) == "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
  CHECK(Sha256::of("abc", 3) == "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad");
  std::string two = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
  CHECK(Sha256::of(two) == "248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1");
  Sha256 s;
  std::vector<char> a(1000, 'a');
  std::size_t left = 1000000, step = 1;
  while (left) {
    std::size_t n = step % a.size() + 1;
    if (n > left) n = left;
    s.update(a.data(), n);
    left -= n;
    step = step * 7 + 3;
  }
  CHECK(Sha256::hex(s.finish()) == "cdc76e5c9914fb9281a1c7e284d73e67f1809a48a497200e046d39ccc7112cd0");
  // The empty pack set (docs/MODDING.md §10).
  CHECK(Sha256::of(std::string("mvp2005-packset-hash/1\n{\"packs\":[]}")) ==
        "f5e1298911db13adf522a1b34d4d4f9291b42fa7a77f63a5f6f07bc322dcc66e");
}
