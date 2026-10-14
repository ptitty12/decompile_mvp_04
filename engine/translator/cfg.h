// Function and control-flow recovery from the symbol map (E0b item 5).
//
// symbols.txt gives every function's start and size, so recovery needs no
// heuristics beyond the jump tables: each function is decoded, every branch is
// classified (local jump, call, tail call, return, indirect call, jump table),
// blocks are formed from what is reachable from the entry, and the resume
// points that the thread model (D4) needs are listed.
#pragma once

#include <cstdint>
#include <deque>
#include <map>
#include <string>
#include <vector>

#include "ppc/isa.h"
#include "translator/symbols.h"
#include "vfs/dol.h"

namespace mvp::xlat {

// Every function the translator knows: symbols.txt's functions, plus code labels
// outside every function that some branch targets (dtk lists them as gaps;
// libsn's _exit is one). A gap function reaches to the next function's start.
class FunctionIndex {
 public:
  void add(const Symbol* s) { map_.emplace(s->address, s); }
  const Symbol* at(std::uint32_t a) const {
    auto it = map_.find(a);
    return it == map_.end() ? nullptr : it->second;
  }
  const Symbol* containing(std::uint32_t a) const {
    auto it = map_.upper_bound(a);
    if (it == map_.begin()) return nullptr;
    --it;
    return a < it->second->address + it->second->size ? it->second : nullptr;
  }
  const std::map<std::uint32_t, const Symbol*>& all() const { return map_; }

 private:
  std::map<std::uint32_t, const Symbol*> map_;
};

enum class Flow : std::uint8_t {
  Plain,         // no control transfer
  Jump,          // b to a local address
  CondJump,      // bc to a local address (falls through otherwise)
  Call,          // bl / bcl to a function start (returns to the next word)
  TailCall,      // b / bc without LK to another function's start
  Return,        // blr (unconditional)
  CondReturn,    // bclr, conditional
  IndirectCall,  // blrl / bctrl (calls through LR / CTR)
  JumpTable,     // bctr through a recovered jump table
  IndirectJump,  // bctr / bcctr without LK and without a table (computed tail call)
  AbsoluteCall,  // bla to an address outside the DOL (code the OS installs in low memory)
  Rfi,           // rfi
  Trap,          // an invalid word or an unconditional trap
};

const char* flow_name(Flow f);

struct InsnInfo {
  std::uint32_t addr = 0;
  std::uint32_t word = 0;
  ppc::Op op = ppc::Op::invalid;
  Flow flow = Flow::Plain;
  bool conditional = false;  // conditional control transfer (falls through when not taken)
  bool inner_target = false; // a call into another function's body (a secondary entry point)
  std::uint32_t target = 0;  // direct target, when there is one
};

struct JumpTable {
  std::uint32_t site = 0;   // the bctr
  std::uint32_t table = 0;  // table address in data
  std::vector<std::uint32_t> targets;
};

struct Block {
  std::uint32_t start = 0, end = 0;  // [start, end)
  std::vector<std::uint32_t> succ;   // local successors
};

struct FunctionCfg {
  const Symbol* sym = nullptr;
  std::uint32_t start = 0, end = 0;
  std::vector<InsnInfo> insns;  // one per word of [start, end)
  std::vector<bool> reachable;  // per word
  std::vector<Block> blocks;    // reachable code, by address
  std::vector<JumpTable> tables;
  std::vector<std::uint32_t> resume_points;  // return address of every call site
  std::vector<std::uint32_t> back_edges;     // branches to an earlier local address (safe points)
  std::vector<std::uint32_t> entries;        // the start, plus secondary entry points other code calls
  std::uint32_t falls_into = 0;              // next function's start, when execution can run off the end
  // Invalid words that execution can reach only as a function's first word (a
  // deliberate trap, like libsn's _exit) or by returning from a call that is not
  // expected to return. Executing one is a guest trap at run time.
  std::vector<std::uint32_t> expected_traps;
  std::vector<std::string> errors;           // unresolved targets and malformed code

  const InsnInfo& at(std::uint32_t addr) const { return insns[(addr - start) / 4]; }
  bool contains(std::uint32_t addr) const { return addr >= start && addr < end; }
};

struct ProgramCfg {
  std::deque<Symbol> gap_symbols;  // functions made from code labels (see FunctionIndex)
  FunctionIndex index;
  std::vector<FunctionCfg> functions;
  // Summary counts.
  std::size_t words = 0, reachable_words = 0, blocks = 0, calls = 0, tail_calls = 0, indirect_calls = 0,
              jump_tables = 0, indirect_jumps = 0, absolute_calls = 0, resume_points = 0, back_edges = 0,
              secondary_entries = 0, falls_into_next = 0, expected_traps = 0, gap_functions = 0, errors = 0;
  std::vector<std::string> error_list;  // "function: message"
};

// Builds the CFG of every function the symbol map lists inside the DOL's text
// sections. Accepted without error, because the hardware does the same:
// - calls into another function's body (assembly helpers such as _savegpr_23 or
//   _exit): that function gets a secondary entry point;
// - execution running off a function's end into the next function's start (after
//   a call that does not return, such as abort): an implicit tail call;
// - an invalid word right after a call that does not return, or as the first
//   word of a function (a deliberate trap): a guest trap if it is ever executed.
ProgramCfg build_cfg(const vfs::Dol& dol, const SymbolTable& syms);

}  // namespace mvp::xlat
