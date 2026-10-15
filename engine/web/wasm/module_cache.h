// The translated module as bytes (E2c): what the browser keeps in its own
// storage (OPFS) so a second visit skips the translation. The blob holds the
// emitter's whole output (xlat::WasmModule: the wasm binary and the tables the
// runtime fills from it), so loading it is exactly loading a fresh translation.
//
// The Worker stores it under a key made of the DOL's SHA-1 and the engine
// build's identity (the hashes of mvp-web.wasm and symbols.txt, written by the
// build next to the engine), so a different disc or a different engine never
// reads it. The blob is derived from the player's disc: it stays in the
// player's browser (ARCHITECTURE.md §3), never on a server.
#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "translator/wasm_emit.h"

namespace mvp::web {

// Format: "MVPXLAT\0", a version, the module's tables, then its bytes.
std::vector<std::uint8_t> serialize_module(const xlat::WasmModule& m);
bool deserialize_module(const std::uint8_t* p, std::size_t n, xlat::WasmModule* m, std::string* error);

}  // namespace mvp::web
