// A synthetic guest program for data-free tests of the translator and runtime:
// recursion, a jump table, a counted loop, calls through CTR and LR, a tail call,
// a conditional return, a secondary entry point, a function that runs into the
// next one, a function that returns past its call (forcing an unwind), context
// switches through rfi (E0c), floating point, and four calls in a row of a
// function at the frame poll's address, which the runtime hooks (E5c). It ends
// with a store to MMIO, which stops a lockstep run.
// Built from instruction fields (ppc/tests/encode.h); no game bytes.
#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace mvp::xlat::synth {

struct Program {
  std::vector<std::uint8_t> dol;  // a DOL image: one text and one data section
  std::string symbols;            // symbols.txt for it
  std::uint32_t results = 0;      // where main stores its results
};

Program make();

// Values main stores at results + 4*k, k = 0..18, in a correct run.
std::vector<std::uint32_t> expected_results();

}  // namespace mvp::xlat::synth
