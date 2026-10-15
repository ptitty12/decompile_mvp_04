#include "runtime/wasm_host.h"

#include <emscripten.h>

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <vector>

#include "ppc/interp.h"
#include "ppc/mem_access.h"
#include "ppc/sem.h"
#include "runtime/hle.h"
#include "runtime/native.h"

using namespace mvp;
using namespace mvp::rt;
using ppc::Cpu;

namespace {

std::unordered_map<u32, u32> g_resume_index;  // resume label -> its function's dispatcher index

// Development (E2d): MVP_WASM_EXEC_STATS=1 counts rt.exec calls by opcode (the
// instructions, or slow paths, the module left to the interpreter's semantics)
// and prints them at exit.
std::uint64_t* g_exec_counts = nullptr;
void print_exec_counts() {
  std::uint64_t total = 0;
  for (std::size_t k = 0; k < static_cast<std::size_t>(ppc::Op::count); ++k) total += g_exec_counts[k];
  std::printf("rt.exec: %llu calls", static_cast<unsigned long long>(total));
  for (int n = 0; n < 24; ++n) {
    std::size_t best = 0;
    for (std::size_t k = 1; k < static_cast<std::size_t>(ppc::Op::count); ++k)
      if (g_exec_counts[k] > g_exec_counts[best]) best = k;
    if (!g_exec_counts[best]) break;
    std::printf(" %s %llu", ppc::op_name(static_cast<ppc::Op>(best)), static_cast<unsigned long long>(g_exec_counts[best]));
    g_exec_counts[best] = 0;
  }
  std::printf("\n");
}

GuestFn as_fn(u32 table_index) { return reinterpret_cast<GuestFn>(static_cast<std::uintptr_t>(table_index)); }

}  // namespace

// The "rt" imports (translator/wasm_emit.h, wasm_import_names()). Memory
// helpers and rt.exec receive the guest PC and the exact instruction count,
// which MMIO handlers, hooks and faults may read.
extern "C" {

EMSCRIPTEN_KEEPALIVE void mvp_rt_on_entry(Cpu* c, u32 a) { on_entry(*c, a); }
EMSCRIPTEN_KEEPALIVE void mvp_rt_safepoint(Cpu* c) { c->hooks->safepoint(*c); }
EMSCRIPTEN_KEEPALIVE u32 mvp_rt_read8(Cpu* c, u32 ea, u32 pc, std::uint64_t t) {
  c->pc = pc;
  c->ticks = t;
  return ppc::read8(*c, ea);
}
EMSCRIPTEN_KEEPALIVE u32 mvp_rt_read16(Cpu* c, u32 ea, u32 pc, std::uint64_t t) {
  c->pc = pc;
  c->ticks = t;
  return ppc::read16(*c, ea);
}
EMSCRIPTEN_KEEPALIVE u32 mvp_rt_read32(Cpu* c, u32 ea, u32 pc, std::uint64_t t) {
  c->pc = pc;
  c->ticks = t;
  return ppc::read32(*c, ea);
}
EMSCRIPTEN_KEEPALIVE void mvp_rt_write8(Cpu* c, u32 ea, u32 v, u32 pc, std::uint64_t t) {
  c->pc = pc;
  c->ticks = t;
  ppc::write8(*c, ea, v);
}
EMSCRIPTEN_KEEPALIVE void mvp_rt_write16(Cpu* c, u32 ea, u32 v, u32 pc, std::uint64_t t) {
  c->pc = pc;
  c->ticks = t;
  ppc::write16(*c, ea, v);
}
EMSCRIPTEN_KEEPALIVE void mvp_rt_write32(Cpu* c, u32 ea, u32 v, u32 pc, std::uint64_t t) {
  c->pc = pc;
  c->ticks = t;
  ppc::write32(*c, ea, v);
}
EMSCRIPTEN_KEEPALIVE void mvp_rt_exec(Cpu* c, u32 w, u32 pc, std::uint64_t t) {
  c->pc = pc;
  c->ticks = t;
  ppc::Op op = ppc::decode(w);
  if (g_exec_counts) ++g_exec_counts[static_cast<std::size_t>(op)];
  ppc::execute_plain(*c, op, ppc::Insn{w});
}
EMSCRIPTEN_KEEPALIVE void mvp_rt_call_indirect(Cpu* c, u32 target) { call_indirect(*c, target); }
EMSCRIPTEN_KEEPALIVE void mvp_rt_absolute_call(Cpu* c, u32 target) { absolute_call(*c, target); }
EMSCRIPTEN_KEEPALIVE u32 mvp_rt_resume(Cpu* c, u32 sp, u32 self) {
  u32 a = resume_target(*c, sp, as_fn(self));
  if (!a) return 0;
  auto it = g_resume_index.find(a);
  if (it == g_resume_index.end()) trap(*c, c->pc, "no resume label");
  return it->second;
}
EMSCRIPTEN_KEEPALIVE void mvp_rt_hle_call(Cpu* c, u32 index, u32 original) {
  hle_call(*c, static_cast<int>(index), as_fn(original));
}
EMSCRIPTEN_KEEPALIVE void mvp_rt_hle_before(Cpu* c, u32 index) { hle_before(*c, static_cast<int>(index)); }
EMSCRIPTEN_KEEPALIVE void mvp_rt_trap(Cpu* c, u32 a, u32 code) { trap(*c, a, xlat::wasm_trap_text(code)); }
EMSCRIPTEN_KEEPALIVE void mvp_rt_rfi(Cpu* c) { ppc::sem::rfi(*c); }
EMSCRIPTEN_KEEPALIVE void mvp_rt_system_call(Cpu* c) { c->hooks->system_call(*c); }
EMSCRIPTEN_KEEPALIVE void mvp_rt_fp_unavailable(Cpu* c, u32 at) { fp_unavailable(*c, at); }
EMSCRIPTEN_KEEPALIVE void mvp_rt_tw(Cpu* c, u32 w, u32 pc) {
  ppc::Insn i{w};
  bool is_tw = ppc::decode(w) == ppc::Op::tw;
  if (is_tw ? ppc::sem::tw_taken(*c, i) : ppc::sem::twi_taken(*c, i)) trap(*c, pc, is_tw ? "tw" : "twi");
}

}  // extern "C"

// Compiles and instantiates the module into the runtime's own table. Returns
// the table base, or -1 with the message in the console.
EM_JS(int, mvp_js_instantiate,
      (const void* bytes, unsigned len, unsigned slots, unsigned unwinding, unsigned resume, unsigned hook,
       double* times),
      {
        var names = ["on_entry", "safepoint", "read8", "read16", "read32", "write8", "write16", "write32", "exec",
                     "call_indirect", "absolute_call", "resume", "hle_call", "hle_before", "trap", "rfi",
                     "system_call", "tw", "fp_unavailable"];
        try {
          var table = (typeof wasmTable != 'undefined') ? wasmTable : __indirect_function_table;
          var t0 = performance.now();
          var mod = new WebAssembly.Module(new Uint8Array(wasmMemory.buffer, bytes, len));
          var t1 = performance.now();
          var rt = {};
          for (var n of names) {
            var f = Module['_mvp_rt_' + n];
            if (!f) throw new Error('runtime export missing: mvp_rt_' + n);
            rt[n] = f;
          }
          var base = table.length;
          table.grow(slots);
          new WebAssembly.Instance(mod, {
            rt: rt,
            env: {
              memory: wasmMemory,
              table: table,
              table_base: base,
              unwinding: unwinding,
              resume: resume,
              entry_hook: hook
            }
          });
          var t2 = performance.now();
          var out = new Float64Array(wasmMemory.buffer, times, 2);
          out[0] = t1 - t0;
          out[1] = t2 - t1;
          return base;
        } catch (e) {
          console.error('mvp: loading the translated module failed: ' + e);
          return -1;
        }
      });

namespace mvp::rt {

bool load_wasm_module(const xlat::WasmModule& m, WasmLoadStats* stats, std::string* error) {
  static_assert(sizeof(GuestFn) == 4, "wasm32: a function pointer is a table index");
  alignas(8) double times[2] = {0, 0};
  int base = mvp_js_instantiate(m.bytes.data(), static_cast<unsigned>(m.bytes.size()), m.slots,
                                static_cast<unsigned>(reinterpret_cast<std::uintptr_t>(&g_unwinding)),
                                static_cast<unsigned>(reinterpret_cast<std::uintptr_t>(&g_resume)),
                                static_cast<unsigned>(reinterpret_cast<std::uintptr_t>(&g_entry_hook)), times);
  if (base < 0) {
    if (error) *error = "the translated module did not compile or instantiate (see the console)";
    return false;
  }
  const u32 b = static_cast<u32>(base);
  std::vector<NativeEntry> entries, resume;
  entries.reserve(m.entries.size());
  for (const auto& e : m.entries) entries.push_back({e.address, as_fn(b + e.slot)});
  resume.reserve(m.resume.size());
  for (const auto& r : m.resume) resume.push_back({r.address, as_fn(b + r.slot)});
  g_native.set(entries.data(), entries.size());
  g_resume_labels.set(resume.data(), resume.size());
  g_safe.set(m.safe.data(), m.safe.size());
  g_idle.set(m.idle.data(), m.idle.size());
  std::vector<HleSite> sites;
  for (const auto& [a, k] : m.hle_sites) sites.push_back({a, k});
  set_hle_sites(sites.data(), sites.size());
  g_resume_index.clear();
  for (const auto& [a, k] : m.resume_index) g_resume_index[a] = k;
  if (const char* v = std::getenv("MVP_WASM_EXEC_STATS"); v && *v == '1' && !g_exec_counts) {
    g_exec_counts = new std::uint64_t[static_cast<std::size_t>(ppc::Op::count)]();
    std::atexit(print_exec_counts);
  }
  if (stats) {
    stats->compile_ms = times[0];
    stats->instantiate_ms = times[1];
    stats->table_base = b;
  }
  return true;
}

}  // namespace mvp::rt
