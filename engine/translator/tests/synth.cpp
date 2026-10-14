#include "synth.h"

#include <cstring>
#include <map>

#include "../../ppc/tests/encode.h"
#include "common/bytes.h"

namespace mvp::xlat::synth {

using namespace mvp::ppc::enc;
using u32 = std::uint32_t;
using s32 = std::int32_t;

namespace {

constexpr u32 kText = 0x80003100;
constexpr u32 kTable = 0x80200000;   // data section: the jump table
constexpr u32 kResults = 0x80300000;  // plain RAM

// A tiny assembler with label fixups.
struct Asm {
  std::vector<u32> words;
  std::map<std::string, u32> labels;
  struct Fix {
    std::size_t idx;
    std::string label;
    int kind;  // 0 b/bl, 1 bc, 2 @h (lis), 3 @l (ori)
  };
  std::vector<Fix> fixes;
  std::vector<std::pair<std::string, u32>> functions;  // name, start (in order)
  std::vector<std::pair<std::string, u32>> code_labels;

  u32 here() const { return kText + 4 * static_cast<u32>(words.size()); }
  void fn(const std::string& n) {
    labels[n] = here();
    functions.emplace_back(n, here());
  }
  void L(const std::string& n) { labels[n] = here(); }
  void entry_label(const std::string& n) {  // a symbol-visible code label inside a function
    labels[n] = here();
    code_labels.emplace_back(n, here());
  }
  void w(u32 x) { words.push_back(x); }
  void bl(const std::string& n) {
    fixes.push_back({words.size(), n, 0});
    w(I(0, 0, 1));
  }
  void b(const std::string& n) {
    fixes.push_back({words.size(), n, 0});
    w(I(0, 0, 0));
  }
  void bc(u32 bo, u32 bi, const std::string& n) {
    fixes.push_back({words.size(), n, 1});
    w(B(bo, bi, 0));
  }
  void la(u32 reg, const std::string& n) {  // lis reg, n@h; ori reg, reg, n@l
    fixes.push_back({words.size(), n, 2});
    w(D(15, reg, 0, 0));
    fixes.push_back({words.size(), n, 3});
    w(D(24, reg, reg, 0));
  }
  void resolve() {
    for (const auto& f : fixes) {
      u32 t = labels.at(f.label);
      u32 at = kText + 4 * static_cast<u32>(f.idx);
      u32& x = words[f.idx];
      switch (f.kind) {
        case 0: x = (x & ~0x03FFFFFCu) | ((t - at) & 0x03FFFFFCu); break;
        case 1: x = (x & ~0xFFFCu) | ((t - at) & 0xFFFCu); break;
        case 2: x = (x & ~0xFFFFu) | (t >> 16); break;
        case 3: x = (x & ~0xFFFFu) | (t & 0xFFFF); break;
      }
    }
  }
};

void store_result(Asm& a, int k) { a.w(D(36, 3, 20, 4 * k)); }  // stw r3, 4k(r20)

}  // namespace

Program make() {
  Asm a;
  // ---- main ----
  a.fn("main");
  a.w(D(15, 1, 0, 0x8040));                      // lis r1, 0x8040 (stack)
  a.w(D(15, 20, 0, static_cast<s32>(kResults >> 16)));  // lis r20, results
  a.w(D(14, 3, 0, 5));                           // li r3, 5
  a.bl("fact");
  store_result(a, 0);
  a.w(D(14, 3, 0, 2));
  a.bl("sw");
  store_result(a, 1);
  a.bl("loop");
  store_result(a, 2);
  a.la(11, "leaf");                    // function pointer through memory, then bctrl
  a.w(D(36, 11, 20, 0x100));
  a.w(D(32, 12, 20, 0x100));
  a.w(SPR(467, 12, 9));                // mtctr r12
  a.w(X(19, 20, 0, 0, 528, 1));        // bctrl
  store_result(a, 3);
  a.la(11, "leaf");
  a.w(SPR(467, 11, 8));                // mtlr r11
  a.w(X(19, 20, 0, 0, 16, 1));         // blrl
  store_result(a, 4);
  a.bl("fpwork");
  store_result(a, 5);
  a.w(D(52, 1, 20, 0x18));             // stfs f1, 24(r20)
  a.bl("tail_caller");
  store_result(a, 7);
  a.w(D(14, 3, 0, 0));
  a.bl("condret");
  store_result(a, 8);
  a.w(D(14, 3, 0, 5));
  a.bl("multi_e2");                    // a call into multi's body
  store_result(a, 9);
  a.bl("runs");
  store_result(a, 10);
  a.bl("jumper");                      // returns 8 bytes past its call: unwind
  a.w(D(14, 3, 0, 99));                // skipped
  a.w(D(14, 3, 0, 98));                // skipped
  store_result(a, 11);
  a.bl("leaf");                        // from here main runs in the interpreter
  store_result(a, 12);
  a.w(D(14, 3, 0, 10));
  a.bl("fact");
  store_result(a, 13);
  a.w(D(15, 3, 0, static_cast<s32>(kTable >> 16)));      // r3 = the format string (data + 0x10)
  a.w(D(14, 3, 3, static_cast<s32>((kTable + 0x10) & 0xFFFF)));
  a.w(D(14, 4, 0, 42));
  a.w(X(19, 6, 6, 6, 193));            // crclr cr1eq: no FP arguments
  a.bl("OSReport");                    // replaced by the HLE (runtime/hle.h)
  a.w(D(15, 4, 0, 0xCC00));            // lis r4, 0xCC00
  a.w(D(36, 3, 4, 0));                 // stw r3, 0(r4): MMIO, stops the run
  a.L("main_spin");
  a.b("main_spin");

  // ---- fact: r3 = r3! (recursive) ----
  a.fn("fact");
  a.w(D(37, 1, 1, -16));               // stwu r1, -16(r1)
  a.w(SPR(339, 0, 8));                 // mflr r0
  a.w(D(36, 0, 1, 20));                // stw r0, 20(r1)
  a.w(D(36, 31, 1, 12));               // stw r31, 12(r1)
  a.w(X(31, 3, 31, 3, 444));           // mr r31, r3
  a.w(D(11, 0, 3, 1));                 // cmpwi r3, 1
  a.bc(4, 1, "fact_base");             // ble
  a.w(D(14, 3, 3, -1));                // subi r3, r3, 1
  a.bl("fact");
  a.w(XO(3, 3, 31, 0, 235));           // mullw r3, r3, r31
  a.b("fact_out");
  a.L("fact_base");
  a.w(D(14, 3, 0, 1));
  a.L("fact_out");
  a.w(D(32, 0, 1, 20));                // lwz r0, 20(r1)
  a.w(D(32, 31, 1, 12));
  a.w(D(14, 1, 1, 16));                // addi r1, r1, 16
  a.w(SPR(467, 0, 8));                 // mtlr r0
  a.w(X(19, 20, 0, 0, 16));            // blr

  // ---- sw: switch through a jump table ----
  a.fn("sw");
  a.w(D(10, 0, 3, 3));                 // cmplwi r3, 3
  a.bc(12, 1, "sw_default");           // bgt
  a.w(D(15, 4, 0, static_cast<s32>(kTable >> 16)));  // lis r4, table@h
  a.w(D(14, 4, 4, static_cast<s32>(kTable & 0xFFFF)));  // addi r4, r4, table@l
  a.w(M(21, 3, 0, 2, 0, 29));          // slwi r0, r3, 2
  a.w(X(31, 0, 4, 0, 23));             // lwzx r0, r4, r0
  a.w(SPR(467, 0, 9));                 // mtctr r0
  a.w(X(19, 20, 0, 0, 528));           // bctr
  for (int k = 0; k < 4; ++k) {
    a.L("case" + std::to_string(k));
    a.w(D(14, 3, 0, 10 + k));
    a.w(X(19, 20, 0, 0, 16));
  }
  a.L("sw_default");
  a.w(D(14, 3, 0, -1));
  a.w(X(19, 20, 0, 0, 16));

  // ---- loop: r3 = 1 + 2 + ... + 10 ----
  a.fn("loop");
  a.w(D(14, 3, 0, 0));
  a.w(D(14, 4, 0, 10));
  a.w(SPR(467, 4, 9));
  a.w(D(14, 5, 0, 1));
  a.L("loop_top");
  a.w(XO(3, 3, 5, 0, 266));            // add r3, r3, r5
  a.w(D(14, 5, 5, 1));
  a.bc(16, 0, "loop_top");             // bdnz
  a.w(X(19, 20, 0, 0, 16));

  // ---- leaf ----
  a.fn("leaf");
  a.w(D(14, 3, 0, 7));
  a.w(X(19, 20, 0, 0, 16));

  // ---- fpwork: single-precision arithmetic, fused multiply-add, conversion ----
  a.fn("fpwork");
  a.w(D(15, 4, 0, 0x3FC0));            // lis r4, 0x3FC0 (1.5f)
  a.w(D(36, 4, 20, 0x200));
  a.w(D(48, 1, 20, 0x200));            // lfs f1
  a.w(A(59, 1, 1, 1, 0, 21));          // fadds f1, f1, f1   -> 3
  a.w(A(59, 2, 1, 0, 1, 25));          // fmuls f2, f1, f1   -> 9
  a.w(A(59, 3, 1, 1, 2, 29));          // fmadds f3, f1, f2, f1 -> 3*9+3 = 30
  a.w(A(59, 1, 3, 2, 0, 18));          // fdivs f1, f3, f2   -> 30/9
  a.w(X(63, 4, 0, 3, 15));             // fctiwz f4, f3      -> 30
  a.w(D(54, 4, 20, 0x208));            // stfd f4
  a.w(D(32, 3, 20, 0x20C));            // lwz r3 (low word)
  a.w(X(19, 20, 0, 0, 16));

  // ---- tail_caller: tail call to leaf ----
  a.fn("tail_caller");
  a.w(D(14, 3, 0, 1));
  a.b("leaf");

  // ---- condret: returns 0x11 if r3 == 0 (beqlr), else 0x22 ----
  a.fn("condret");
  a.w(D(11, 0, 3, 0));
  a.w(D(14, 3, 0, 0x11));
  a.w(X(19, 12, 2, 0, 16));            // beqlr
  a.w(D(14, 3, 0, 0x22));
  a.w(X(19, 20, 0, 0, 16));

  // ---- multi: a second entry point inside the body ----
  a.fn("multi");
  a.w(D(14, 3, 0, 1));
  a.entry_label("multi_e2");
  a.w(D(14, 3, 3, 0x40));
  a.w(X(19, 20, 0, 0, 16));

  // ---- runs: no terminator, runs into runs_next ----
  a.fn("runs");
  a.w(D(14, 5, 0, 0x55));
  a.fn("runs_next");
  a.w(D(14, 3, 5, 1));
  a.w(X(19, 20, 0, 0, 16));

  // ---- jumper: returns 8 bytes past the return address ----
  a.fn("jumper");
  a.w(SPR(339, 11, 8));                // mflr r11
  a.w(D(14, 11, 11, 8));               // addi r11, r11, 8 (rA = 0 would mean literal zero)
  a.w(SPR(467, 11, 8));                // mtlr r11
  a.w(D(14, 3, 0, 0x77));
  a.w(X(19, 20, 0, 0, 16));
  // ---- OSReport: the original does nothing here; the HLE logs ----
  a.fn("OSReport");
  a.w(X(19, 20, 0, 0, 16));
  a.fn("end");  // marks the end of the text

  a.resolve();

  // DOL: text at kText, data (the jump table) at kTable.
  std::vector<u32> data;
  for (int k = 0; k < 4; ++k) data.push_back(a.labels.at("case" + std::to_string(k)));
  data.push_back(0x783D2564);  // "x=%d", then a newline and NUL
  data.push_back(0x0A000000);
  std::size_t text_bytes = 4 * a.words.size(), data_bytes = 4 * data.size();
  std::vector<std::uint8_t> d(0x100 + text_bytes + data_bytes, 0);
  auto set = [&](int slot, u32 off, u32 addr, u32 size) {
    put_be32(&d[4 * slot], off);
    put_be32(&d[0x48 + 4 * slot], addr);
    put_be32(&d[0x90 + 4 * slot], size);
  };
  set(0, 0x100, kText, static_cast<u32>(text_bytes));
  set(7, static_cast<u32>(0x100 + text_bytes), kTable, static_cast<u32>(data_bytes));
  put_be32(&d[0xE0], kText);  // entry
  for (std::size_t k = 0; k < a.words.size(); ++k) put_be32(&d[0x100 + 4 * k], a.words[k]);
  for (std::size_t k = 0; k < data.size(); ++k) put_be32(&d[0x100 + text_bytes + 4 * k], data[k]);

  std::string syms;
  char line[160];
  for (std::size_t k = 0; k + 1 < a.functions.size(); ++k) {
    std::snprintf(line, sizeof line, "%s = .text:0x%08X; // type:function size:0x%X\n", a.functions[k].first.c_str(),
                  a.functions[k].second, a.functions[k + 1].second - a.functions[k].second);
    syms += line;
  }
  for (const auto& [n, at] : a.code_labels) {
    std::snprintf(line, sizeof line, "%s = .text:0x%08X; // type:label\n", n.c_str(), at);
    syms += line;
  }
  std::snprintf(line, sizeof line, "jumptable_%08X = .data:0x%08X; // type:object size:0x10 scope:local\n", kTable,
                kTable);
  syms += line;
  return Program{std::move(d), std::move(syms), kResults};
}

std::vector<std::uint32_t> expected_results() {
  float q = 30.0f / 9.0f;
  u32 qbits;
  std::memcpy(&qbits, &q, 4);
  return {120, 12, 55, 7, 7, 30, qbits, 7, 0x11, 0x45, 0x56, 0x77, 7, 3628800};
}

}  // namespace mvp::xlat::synth
