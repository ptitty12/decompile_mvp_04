// Loads what the translator works from: the retail DOL (from the player's disc)
// and the symbol map (repository metadata).
#pragma once

#include <memory>
#include <optional>
#include <string>

#include "translator/cfg.h"
#include "translator/symbols.h"
#include "vfs/disc_check.h"

namespace mvp::xlat {

struct Inputs {
  vfs::Disc disc;
  SymbolTable symbols;
};

// Opens the disc (retail GV4E69 only) and parses symbols.txt.
std::optional<Inputs> load_inputs(const std::string& disc_path, const std::string& symbols_path, std::string* error);

// Default locations for development tools, from the environment or the build.
std::string default_disc_path();
std::string default_symbols_path();
std::string default_splits_path();

}  // namespace mvp::xlat
