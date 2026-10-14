// Data-free CFG tests on a synthetic DOL: calls, loops, a jump table, a tail
// call, a conditional return, and the errors for a stray branch.
#include <doctest/doctest.h>

#include <map>
#include <vector>

#include "../../ppc/tests/encode.h"
#include "common/bytes.h"
#include "translator/cfg.h"
#include "translator/units.h"

using namespace mvp;
using namespace mvp::xlat;
using namespace mvp::ppc::enc;

namespace {

constexpr u32 kText = 0x80003100, kData = 0x80005000;

struct Image {
  std::vector<u32> text, data;
  vfs::Dol dol() const {
    std::vector<u8> d(0x100 + 4 * (text.size() + data.size()), 0);
    auto set = [&](int slot, u32 off, u32 addr, u32 size) {
      put_be32(&d[4 * slot], off);
      put_be32(&d[0x48 + 4 * slot], addr);
      put_be32(&d[0x90 + 4 * slot], size);
    };
    set(0, 0x100, kText, static_cast<u32>(4 * text.size()));
    set(7, static_cast<u32>(0x100 + 4 * text.size()), kData, static_cast<u32>(4 * data.size()));
    for (std::size_t k = 0; k < text.size(); ++k) put_be32(&d[0x100 + 4 * k], text[k]);
    for (std::size_t k = 0; k < data.size(); ++k) put_be32(&d[0x100 + 4 * (text.size() + k)], data[k]);
    return *vfs::Dol::parse(d);
  }
};

u32 rel(u32 from, u32 to) { return to - from; }

}  // namespace

TEST_CASE("CFG of calls, loops, a jump table and a tail call") {
  // f1 @kText: loop calling f2, then return.
  //   0: li r3, 3          4: mtctr r3          8: bl f2
  //   c: bdnz 8            10: blr
  // f2 @kText+0x14: switch on r3 through jumptable_80005000 (3 cases), conditional return.
  //   14: cmplwi r3, 2     18: bgtlr            1c: lis r4, 0x8000
  //   20: addi r4, r4, 0x5000                   24: slwi r0, r3, 2
  //   28: lwzx r0, r4, r0  2c: mtctr r0         30: bctr
  //   34: li r3, 0         38: blr              3c: li r3, 1      40: blr
  //   44: b f1 (tail call)
  // f3 @kText+0x48: branch to a non-function address (error), then blr.
  //   48: b kText+0x4 (inside f1, not its start)
  Image im;
  im.text = {
      D(14, 3, 0, 3), SPR(467, 3, 9), 0, 0, X(19, 20, 0, 0, 16),
      D(10, 0, 3, 2), X(19, 12, 1, 0, 16), D(15, 4, 0, -0x8000), D(14, 4, 4, 0x5000), M(21, 3, 0, 2, 0, 29),
      X(31, 0, 4, 0, 23), SPR(467, 0, 9), X(19, 20, 0, 0, 528), D(14, 3, 0, 0), X(19, 20, 0, 0, 16),
      D(14, 3, 0, 1), X(19, 20, 0, 0, 16), 0, 0,
  };
  im.text[2] = I(static_cast<s32>(rel(kText + 8, kText + 0x14)), 0, 1);  // bl f2
  im.text[3] = B(16, 0, static_cast<s32>(rel(kText + 0xC, kText + 8)));  // bdnz
  im.text[17] = I(static_cast<s32>(rel(kText + 0x44, kText)));           // b f1
  im.text[18] = I(static_cast<s32>(rel(kText + 0x48, kText + 4)));       // b into f1
  im.data = {kText + 0x34, kText + 0x3C, kText + 0x44};
  std::string syms =
      "f1 = .text:0x80003100; // type:function size:0x14\n"
      "f2 = .text:0x80003114; // type:function size:0x34\n"
      "f3 = .text:0x80003148; // type:function size:0x4\n"
      "jumptable_80005000 = .data:0x80005000; // type:object size:0xC scope:local\n";
  SymbolTable st = SymbolTable::parse(syms);
  REQUIRE(st.functions().size() == 3);
  auto dol = im.dol();
  ProgramCfg p = build_cfg(dol, st);
  REQUIRE(p.functions.size() == 3);

  const FunctionCfg& f1 = p.functions[0];
  CHECK(f1.at(kText + 8).flow == Flow::Call);
  CHECK(f1.at(kText + 8).target == kText + 0x14);
  CHECK(f1.at(kText + 0xC).flow == Flow::CondJump);
  CHECK(f1.at(kText + 0x10).flow == Flow::Return);
  CHECK(f1.resume_points == std::vector<u32>{kText + 0xC});
  CHECK(f1.back_edges == std::vector<u32>{kText + 0xC});
  CHECK(f1.errors.empty());
  // Blocks: [0,0xC) ends at... the bdnz target 8 is a leader: [0,8) [8,0x10) [0x10,0x14).
  REQUIRE(f1.blocks.size() == 3);
  CHECK(f1.blocks[0].start == kText);
  CHECK(f1.blocks[0].end == kText + 8);
  CHECK(f1.blocks[1].succ == std::vector<u32>{kText + 8, kText + 0x10});

  const FunctionCfg& f2 = p.functions[1];
  CHECK(f2.at(kText + 0x18).flow == Flow::CondReturn);
  CHECK(f2.at(kText + 0x30).flow == Flow::JumpTable);
  REQUIRE(f2.tables.size() == 1);
  CHECK(f2.tables[0].table == kData);
  CHECK(f2.tables[0].targets == std::vector<u32>{kText + 0x34, kText + 0x3C, kText + 0x44});
  CHECK(f2.at(kText + 0x44).flow == Flow::TailCall);
  CHECK(f2.errors.empty());
  for (bool r : f2.reachable) CHECK(r);

  const FunctionCfg& f3 = p.functions[2];
  REQUIRE(f3.errors.size() == 1);
  CHECK(f3.errors[0].find("not a function start") != std::string::npos);
  CHECK(p.errors == 1);
  CHECK(p.jump_tables == 1);
  CHECK(p.calls == 1);
}

TEST_CASE("unreachable words and running off the end") {
  Image im;
  // g1: blr, then a zero word (padding: unreachable, not an error).
  // g2: li r3, 0 with no terminator: runs off the end.
  im.text = {X(19, 20, 0, 0, 16), 0, D(14, 3, 0, 0)};
  im.data = {0};
  SymbolTable st = SymbolTable::parse(
      "g1 = .text:0x80003100; // type:function size:0x8\n"
      "g2 = .text:0x80003108; // type:function size:0x4\n");
  auto dol = im.dol();
  ProgramCfg p = build_cfg(dol, st);
  REQUIRE(p.functions.size() == 2);
  CHECK(p.functions[0].errors.empty());
  CHECK_FALSE(p.functions[0].reachable[1]);
  REQUIRE(p.functions[1].errors.size() == 1);
  CHECK(p.functions[1].errors[0].find("past the end") != std::string::npos);
}

TEST_CASE("secondary entries, gap functions, running into the next function, expected traps") {
  // h1 @0: bl into h2's body (+8); bl gap (a code label outside every function);
  //        then a call to h3 that does not return, followed by an invalid word.
  // h2 @0x10: li; li; blr      (0x18 is the secondary entry)
  // gap @0x1C: invalid word (a deliberate trap), blr
  // h3 @0x24: bl h2, then runs into h4
  // h4 @0x28: blr
  Image im;
  im.text = {0, 0, 0, 0,  // h1: 0x00 bl h2+8, 0x04 bl gap, 0x08 bl h3, 0x0C invalid
             D(14, 3, 0, 1), D(14, 4, 0, 2), X(19, 20, 0, 0, 16),  // h2: 0x10..0x18
             0, X(19, 20, 0, 0, 16),                               // gap: 0x1C, 0x20
             0,                                                    // h3: 0x24
             X(19, 20, 0, 0, 16)};                                 // h4: 0x28
  im.text[0] = I(0x18, 0, 1);
  im.text[1] = I(0x1C - 0x4, 0, 1);
  im.text[2] = I(0x24 - 0x8, 0, 1);
  im.text[9] = I(static_cast<s32>(0x10 - 0x24), 0, 1);
  im.data = {0};
  SymbolTable st = SymbolTable::parse(
      "h1 = .text:0x80003100; // type:function size:0x10\n"
      "h2 = .text:0x80003110; // type:function size:0xC\n"
      "_gap = .text:0x8000311C; // type:label\n"
      "h3 = .text:0x80003124; // type:function size:0x4\n"
      "h4 = .text:0x80003128; // type:function size:0x4\n"
      "lbl_data = .text:0x8000312C; // type:label data:double\n");
  auto dol = im.dol();
  ProgramCfg p = build_cfg(dol, st);
  CHECK(p.errors == 0);
  for (const auto& e : p.error_list) MESSAGE(e);
  REQUIRE(p.gap_functions == 1);
  CHECK(p.gap_symbols[0].name == "_gap");
  CHECK(p.gap_symbols[0].size == 8);
  REQUIRE(p.functions.size() == 5);
  const FunctionCfg& h1 = p.functions[0];
  CHECK(h1.at(kText).inner_target);
  CHECK(h1.expected_traps == std::vector<u32>{kText + 0xC});
  const FunctionCfg& h2 = p.functions[1];
  CHECK(h2.entries == std::vector<u32>{kText + 0x10, kText + 0x18});
  const FunctionCfg& gap = p.functions[2];
  CHECK(gap.expected_traps == std::vector<u32>{kText + 0x1C});
  const FunctionCfg& h3 = p.functions[3];
  CHECK(h3.falls_into == kText + 0x28);
  CHECK(p.secondary_entries == 1);
  CHECK(p.falls_into_next == 1);
  CHECK(p.expected_traps == 2);
}

TEST_CASE("symbols.txt parsing") {
  std::vector<std::string> errs;
  SymbolTable st = SymbolTable::parse(
      "fn_80003100 = .init:0x80003100; // type:function size:0x154\n"
      "lbl_80003328 = .init:0x80003328; // type:label align:8 data:double\n"
      "__static_initialization_and_destruction_0 = .text:0x800034A0; // type:function size:0xDE4 scope:local\n"
      "garbage line\n",
      &errs);
  CHECK(errs.size() == 1);
  REQUIRE(st.all().size() == 3);
  CHECK(st.all()[0].size == 0x154);
  CHECK(st.all()[1].type == Symbol::Type::Label);
  CHECK(st.all()[2].local);
  CHECK(st.function_containing(0x80003200)->name == "fn_80003100");
  CHECK(st.function_containing(0x80003300) == nullptr);
  CHECK(st.find("lbl_80003328")->address == 0x80003328);
}

TEST_CASE("splits.txt units and the runtime-library test") {
  UnitMap u = UnitMap::parse(
      "Sections:\n\t.init       type:code align:4\n\t.text       type:code align:16\n\n"
      "game/tu_80003100.cpp:\n\t.text       start:0x80003100 end:0x80003200\n\n"
      "dolphin/os/OS.c:\n\t.text       start:0x80003200 end:0x80003300\n\t.data       start:0x80200000 end:0x80200010\n\n"
      "libc/string.c:\n\t.text       start:0x80003300 end:0x80003400\n");
  CHECK(u.size() == 4);
  CHECK(u.unit_at(0x80003100) == "game/tu_80003100.cpp");
  CHECK(u.unit_at(0x800031FC) == "game/tu_80003100.cpp");
  CHECK(u.unit_at(0x80003200) == "dolphin/os/OS.c");
  CHECK(u.unit_at(0x80200004) == "dolphin/os/OS.c");
  CHECK(u.unit_at(0x80003400).empty());
  CHECK_FALSE(u.is_runtime(0x80003150));
  CHECK(u.is_runtime(0x80003250));
  CHECK(u.is_runtime(0x80003350));
  CHECK(UnitMap::is_runtime_unit("sdk/tu_8043E344.c"));
  CHECK(UnitMap::is_runtime_unit("libsn/tu_80403E80.c"));
  CHECK_FALSE(UnitMap::is_runtime_unit("ealib/tu_803FEB34.cpp"));
}
