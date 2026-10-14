#include <array>
#include <cstdio>
#include <cstdlib>

#include "ppc/isa.h"

namespace mvp::ppc {

namespace {

const OpInfo kInfo[] = {
    {".4byte", 0, 0},
#define MVP_X(name, pattern, mask) {#name, pattern, mask},
    MVP_PPC_OPS(MVP_X)
#undef MVP_X
};
static_assert(sizeof(kInfo) / sizeof(kInfo[0]) == static_cast<std::size_t>(Op::count));

// The C++ identifiers above carry `_rc` / trailing `_`; the ISA spellings differ.
const char* isa_spelling(Op op, const char* fallback) {
  switch (op) {
    case Op::addic_rc: return "addic.";
    case Op::andi_rc: return "andi.";
    case Op::andis_rc: return "andis.";
    case Op::stwcx_rc: return "stwcx.";
    case Op::and_: return "and";
    case Op::or_: return "or";
    case Op::xor_: return "xor";
    default: return fallback;
  }
}

// Two-level lookup: primary opcode, then (for primaries with extended opcodes)
// the 10-bit field at bits 21-30. A final pattern/mask test rejects words with
// reserved bits set. A table bug (two opcodes claiming one encoding) is fatal at
// startup.
[[noreturn]] void conflict(const char* a, const char* b) {
  std::fprintf(stderr, "ppc decoder: %s and %s overlap\n", a, b);
  std::abort();
}

struct Tables {
  std::array<OpInfo, static_cast<std::size_t>(Op::count)> info{};
  std::array<Op, 64> primary{};
  std::array<std::array<Op, 1024>, 64> ext{};
  std::array<bool, 64> has_ext{};

  Tables() {
    for (std::size_t i = 0; i < info.size(); ++i) {
      info[i] = kInfo[i];
      info[i].name = isa_spelling(static_cast<Op>(i), kInfo[i].name);
    }
    primary.fill(Op::invalid);
    for (auto& t : ext) t.fill(Op::invalid);
    for (std::size_t i = 1; i < info.size(); ++i) {
      const OpInfo& o = info[i];
      Op op = static_cast<Op>(i);
      u32 p = o.pattern >> 26;
      u32 xmask = o.mask & 0x7FE;
      if (xmask == 0) {
        if (primary[p] != Op::invalid) conflict(info[static_cast<std::size_t>(primary[p])].name, o.name);
        primary[p] = op;
        continue;
      }
      has_ext[p] = true;
      for (u32 x = 0; x < 1024; ++x) {
        if (((x << 1) & xmask) != (o.pattern & xmask)) continue;
        if (ext[p][x] != Op::invalid) conflict(info[static_cast<std::size_t>(ext[p][x])].name, o.name);
        ext[p][x] = op;
      }
    }
  }
};

const Tables& tables() {
  static const Tables t;
  return t;
}

}  // namespace

const OpInfo& op_info(Op op) { return tables().info[static_cast<std::size_t>(op)]; }

Op decode(u32 w) {
  const Tables& t = tables();
  u32 p = w >> 26;
  Op op = t.has_ext[p] ? t.ext[p][(w >> 1) & 0x3FF] : t.primary[p];
  if (op == Op::invalid) return op;
  const OpInfo& o = t.info[static_cast<std::size_t>(op)];
  return (w & o.mask) == o.pattern ? op : Op::invalid;
}

}  // namespace mvp::ppc
