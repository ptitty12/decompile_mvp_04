// The runtime side of the WebAssembly emitter (E2; translator/wasm_emit.h):
// the "rt" functions a translated module imports, and loading a module into
// the running engine. Emscripten builds only.
//
// Loading compiles the module, grows the runtime's own function table by the
// module's slots and instantiates it there, so translated functions are plain
// `void (*)(Cpu&)` pointers: rt::run, call_indirect and the C++ runtime call
// them exactly like C++-emitted ones. Then it fills the same tables the C++
// emitter's registration fills (entry points, resume labels, safe points, idle
// spins, replaced functions).
#pragma once

#include <string>

#include "translator/wasm_emit.h"

namespace mvp::rt {

struct WasmLoadStats {
  double compile_ms = 0;      // new WebAssembly.Module (synchronous)
  double instantiate_ms = 0;  // new WebAssembly.Instance
  std::uint32_t table_base = 0;
};

bool load_wasm_module(const xlat::WasmModule& m, WasmLoadStats* stats, std::string* error);

}  // namespace mvp::rt
