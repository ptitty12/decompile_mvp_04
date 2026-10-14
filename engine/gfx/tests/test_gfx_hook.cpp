// The runtime's renderer hook (runtime/gx_fifo.h GfxObserver) feeding the GX
// state machine: commands split across pushes arrive whole, display lists
// arrive as their contents, and the draw comes out of the processor.
#include <doctest/doctest.h>

#include <vector>

#include "common/bytes.h"
#include "gfx/gx_processor.h"
#include "runtime/gx_fifo.h"
#include "tests/gx_stream.h"

using namespace mvp;
using namespace mvp::gfx;
using namespace mvp::gfx::test;

namespace {

struct Forward : rt::GfxObserver {
  GxProcessor* p = nullptr;
  std::vector<std::vector<std::uint8_t>> seen;
  std::uint64_t fields = 0;
  void gx_command(const std::uint8_t* c, std::size_t n) override {
    seen.emplace_back(c, c + n);
    p->command(c, n);
  }
  void vi_field(std::uint64_t, std::uint32_t) override { ++fields; }
};

}  // namespace

TEST_CASE("FIFO bytes and display lists reach the processor as whole commands") {
  std::vector<std::uint8_t> mem(0x10000, 0);
  // A display list at 0x8000: a CP load (VCD: position direct) and a BP load, padded with NOPs.
  Stream dl;
  dl.cp(cp::kVcdLo, 1u << 9);
  dl.bp(bp::kGenMode, 0x400);  // 2 TEV stages
  std::vector<std::uint8_t> list;
  for (const auto& c : dl.cmds) list.insert(list.end(), c.begin(), c.end());
  while (list.size() % 32) list.push_back(0);
  std::copy(list.begin(), list.end(), mem.begin() + 0x8000);

  Stream s = setup_2d();
  s.cp(cp::kVatA, 0u | 4u << 1);  // xy f32
  std::vector<std::uint8_t> call{cmd::kCallDl};
  Stream::put32(call, 0x80008000u);
  Stream::put32(call, static_cast<std::uint32_t>(list.size()));
  s.raw(call);
  std::vector<std::uint8_t> v;
  for (float f : {0.f, 0.f, 100.f, 0.f, 0.f, 100.f}) f32(v, f);
  s.prim(cmd::kTriangles, 3, v);
  std::vector<std::uint8_t> bytes;
  for (const auto& c : s.cmds) bytes.insert(bytes.end(), c.begin(), c.end());

  Capture cap;
  GxProcessor proc(&cap);
  proc.set_memory(mem.data(), static_cast<std::uint32_t>(mem.size()));
  Forward fwd;
  fwd.p = &proc;
  rt::GxFifo fifo;
  fifo.set_memory(mem.data(), static_cast<std::uint32_t>(mem.size()));
  fifo.set_observer(&fwd);
  // Feed in 7-byte pieces, so commands straddle pushes.
  for (std::size_t at = 0; at < bytes.size(); at += 7)
    fifo.push(bytes.data() + at, std::min<std::size_t>(7, bytes.size() - at));

  REQUIRE(cap.draws.size() == 1);
  CHECK(cap.draws[0].verts.size() == 3);
  CHECK(cap.draws[0].cfg.num_stages == 2);
  // The call itself is not forwarded; its two commands and the padding NOPs are.
  for (const auto& c : fwd.seen) CHECK(c[0] != cmd::kCallDl);
  std::size_t nops = 0;
  for (const auto& c : fwd.seen) nops += c[0] == 0;
  CHECK(nops == list.size() - 6 - 5);
  CHECK(fwd.seen.size() == s.cmds.size() - 1 + 2 + nops);
}
