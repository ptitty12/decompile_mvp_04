// mvp-web (E2): the engine in the player's browser. Emscripten builds this into
// mvp-web.js + mvp-web.wasm, which the web shell's Worker loads
// (engine/web/src/worker.ts). Everything game-derived stays inside that
// Worker: the disc is read from the File the player picked, the DOL is
// translated to WebAssembly here, and nothing is sent anywhere.
//
// The Worker calls the exports below in this order (docs/engine/WEB.md):
//   mvp_open_disc(size)          the picked image (ISO or CISO), read through
//                                Module.mvpDisc (a File) with FileReaderSync;
//                                checks GV4E69 rev 0 by the DOL's SHA-1
//   mvp_translate(text, len)     symbols.txt (repository metadata, served with
//                                the engine) -> CFG -> one wasm module ->
//                                compile -> instantiate into the runtime's table
//   mvp_boot(script, len, ...)   the machine, the hardware model, the input
//                                (an mvp-input script for tests, else live input)
//   mvp_gfx_init(sel, w, h)      asynchronous: adapter, device, the canvas the
//                                page registered as `sel`; calls
//                                Module.mvpOnGfx(ok, message) when done
//   mvp_run_fields(n)            runs n whole VI fields (rt::run returns at each
//                                field: runtime/host_yield.h)
//   mvp_present()                shows the frame the VI scans out
//   mvp_set_pad(...)             the host's controller state for the next frame polls
//   mvp_status() / mvp_guest_line()   JSON status, and the determinism line
//
// Determinism: guest state depends only on the disc and the per-frame inputs.
// Wall time never reaches it: the shell decides *how many* fields to run per
// animation frame, never what happens inside one; the renderer only reads guest
// memory; yields are invisible to the guest.
#include <emscripten.h>
#include <emscripten/heap.h>

#include <array>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "common/sha1.h"
#include "gfx/gx_processor.h"
#include "gfx/wgpu/gpu.h"
#include "gfx/wgpu/renderer.h"
#include "gfx/wgpu/window.h"
#include "runtime/boot.h"
#include "runtime/hle.h"
#include "runtime/host_yield.h"
#include "runtime/hw.h"
#include "runtime/input.h"
#include "runtime/machine.h"
#include "runtime/native.h"
#include "runtime/wasm_host.h"
#include "translator/cfg.h"
#include "translator/symbols.h"
#include "translator/wasm_emit.h"
#include "vfs/disc_check.h"
#include "vfs/source.h"

using namespace mvp;
using namespace mvp::rt;

// Reads the picked File synchronously (Workers only). Returns 1 on success.
EM_JS(int, mvp_js_disc_read, (double off, void* dst, double n), {
  try {
    var f = Module['mvpDisc'];
    var buf = new FileReaderSync().readAsArrayBuffer(f.slice(off, off + n));
    if (buf.byteLength != n) return 0;
    HEAPU8.set(new Uint8Array(buf), dst >>> 0);
    return 1;
  } catch (e) {
    err('mvp: disc read failed: ' + e);
    return 0;
  }
});

EM_JS(void, mvp_js_on_gfx, (int ok, const char* msg), {
  if (Module['mvpOnGfx']) Module['mvpOnGfx'](ok, UTF8ToString(msg));
});

namespace {

double now_ms() { return emscripten_get_now(); }

// The player's disc image, as the File the page handed to the Worker.
class JsFileSource final : public vfs::Source {
 public:
  explicit JsFileSource(std::uint64_t size) : size_(size) {}
  std::uint64_t size() const override { return size_; }
  bool read(std::uint64_t off, void* dst, std::size_t n) override {
    if (off > size_ || n > size_ - off) return false;
    if (n == 0) return true;
    ++reads;
    bytes += n;
    return mvp_js_disc_read(static_cast<double>(off), dst, static_cast<double>(n)) != 0;
  }
  std::uint64_t reads = 0, bytes = 0;

 private:
  std::uint64_t size_;
};

// Live controller input: what the page reports when the game polls. A button
// pressed since the previous poll counts as pressed at this one even if it was
// already released: the game polls once per frame of its own, which can be
// several VI fields apart (the intro movie runs below real time), and a quick
// tap would otherwise fall between two polls. Only what each poll returns
// reaches the guest.
struct LiveInput : InputSource {
  FrameInput state = neutral_input(1);
  std::array<u16, kPorts> latched{};
  void set(int port, const PadState& p) {
    const std::size_t k = static_cast<std::size_t>(port);
    latched[k] |= static_cast<u16>(p.buttons & ~state.pad[k].buttons);
    state.pad[k] = p;
  }
  FrameInput input_for(u64) override {
    FrameInput in = state;
    for (std::size_t k = 0; k < kPorts; ++k) {
      in.pad[k].buttons |= latched[k];
      if (latched[k] & pad::kA) in.pad[k].analog_a = 255;
      if (latched[k] & pad::kB) in.pad[k].analog_b = 255;
      latched[k] = 0;
    }
    return in;
  }
};

struct Engine;

// The renderer's view of the run, and the field boundary.
struct Observer : GfxObserver {
  Engine* e = nullptr;
  void gx_command(const std::uint8_t* cmd, std::size_t len) override;
  void vi_field(std::uint64_t field, std::uint32_t xfb) override;
};

struct Engine {
  std::string error;
  JsFileSource* file = nullptr;  // owned by disc
  std::optional<vfs::Disc> disc;
  std::string image_kind;

  // Translation.
  bool translated = false;
  double t_symbols = 0, t_cfg = 0, t_emit = 0;
  WasmLoadStats load;
  xlat::WasmEmitStats emit_stats;
  std::size_t module_bytes = 0;

  // The machine.
  std::unique_ptr<Machine> m;
  std::unique_ptr<Hardware> hw;
  std::unique_ptr<YieldingHooks> hooks;
  std::unique_ptr<InputQueue> input;
  std::unique_ptr<InputScript> script;
  LiveInput live;
  Observer obs;
  std::uint64_t stop_fields = ~0ull, stop_frames = ~0ull;
  std::uint64_t frames = 0;
  bool stopped = false;
  std::string why;

  // Rendering.
  std::unique_ptr<gfx::Gpu> gpu;
  std::unique_ptr<gfx::Window> window;
  std::unique_ptr<gfx::Renderer> renderer;
  std::unique_ptr<gfx::GxProcessor> proc;
  std::string gfx_error;
  std::uint32_t xfb = 0;
  std::uint64_t presents = 0, last_presented = 0;

  // Host time spent inside rt::run, for the frame-time numbers.
  double run_ms = 0, last_batch_ms = 0, max_field_ms = 0;
  std::uint64_t run_fields = 0;
};
Engine g;

void Observer::gx_command(const std::uint8_t* cmd, std::size_t len) {
  if (e->proc) e->proc->command(cmd, len);
}

void Observer::vi_field(std::uint64_t field, std::uint32_t xfb) {
  if (e->renderer) e->renderer->flush();
  e->xfb = xfb;
  if (field >= e->stop_fields) throw StopRun{"ran " + std::to_string(e->stop_fields) + " VI fields"};
  e->hooks->request_yield();  // run() returns after this field's safe point
}

void frame_hook(ppc::Cpu&, std::uint64_t frame) {
  g.frames = frame;
  if (frame >= g.stop_frames) throw StopRun{"ran " + std::to_string(frame) + " frames"};
}

std::string json_escape(const std::string& s) {
  std::string o;
  for (char ch : s) {
    if (ch == '"' || ch == '\\') o += '\\', o += ch;
    else if (static_cast<unsigned char>(ch) < 0x20) o += ' ';
    else o += ch;
  }
  return o;
}

std::string g_text;  // the last string handed to JS

// The renderer needs both the device and the machine's memory; whichever of
// mvp_gfx_init's callback and mvp_boot comes second attaches it.
void attach_renderer() {
  if (!g.gpu || !g.window || !g.m || g.renderer) return;
  g.renderer = std::make_unique<gfx::Renderer>(*g.gpu, g.m->mem1(), Machine::kMem1Size);
  g.proc = std::make_unique<gfx::GxProcessor>(g.renderer.get());
  g.proc->set_memory(g.m->mem1(), Machine::kMem1Size);
}

}  // namespace

extern "C" {

EMSCRIPTEN_KEEPALIVE const char* mvp_last_error() { return g.error.c_str(); }

// Opens the picked image (Module.mvpDisc, `size` bytes) and checks that it is
// GV4E69 rev 0. Returns 1, or 0 with mvp_last_error() set.
EMSCRIPTEN_KEEPALIVE int mvp_open_disc(double size) {
  g.error.clear();
  auto src = std::make_unique<JsFileSource>(static_cast<std::uint64_t>(size));
  JsFileSource* raw = src.get();
  std::unique_ptr<vfs::Source> image;
  char magic[4] = {};
  if (raw->size() >= 4 && raw->read(0, magic, 4) && std::string(magic, 4) == "CISO") {
    image = vfs::CisoSource::open(std::move(src), &g.error);
    g.image_kind = "CISO";
    if (!image) return 0;
  } else {
    image = std::move(src);
    g.image_kind = "ISO";
  }
  auto disc = vfs::open_disc(std::move(image), true, &g.error);
  if (!disc) return 0;
  g.file = raw;
  g.disc = std::move(*disc);
  return 1;
}

EMSCRIPTEN_KEEPALIVE const char* mvp_disc_info() {
  if (!g.disc) return "{}";
  g_text = "{\"game\":\"" + json_escape(g.disc->gcm.game_id()) + "\",\"revision\":" +
           std::to_string(g.disc->gcm.revision()) + ",\"title\":\"" + json_escape(g.disc->gcm.title()) +
           "\",\"dol_sha1\":\"" + g.disc->dol_sha1 + "\",\"image\":\"" + g.image_kind + "\"}";
  return g_text.c_str();
}

// Translates the DOL with the symbol map `text` (symbols.txt) into one module
// and loads it into the runtime. Returns 1, or 0 with mvp_last_error() set.
EMSCRIPTEN_KEEPALIVE int mvp_translate(const char* text, int len) {
  g.error.clear();
  if (!g.disc) {
    g.error = "no disc";
    return 0;
  }
  double t0 = now_ms();
  std::vector<std::string> errs;
  xlat::SymbolTable syms = xlat::SymbolTable::parse(std::string(text, static_cast<std::size_t>(len)), &errs);
  if (!errs.empty()) {
    g.error = "symbols.txt: " + errs.front() + " (" + std::to_string(errs.size()) + " errors)";
    return 0;
  }
  double t1 = now_ms();
  xlat::WasmModule mod;
  {
    xlat::ProgramCfg cfg = xlat::build_cfg(g.disc->dol, syms);
    double t2 = now_ms();
    xlat::WasmEmitOptions opt;
    const auto& table = hle_table();
    for (std::size_t k = 0; k < table.size(); ++k)
      opt.hle.push_back({table[k].name, table[k].address, static_cast<int>(k), table[k].kind == HleKind::Before});
    if (!xlat::emit_wasm(cfg, opt, &mod, &g.error)) return 0;
    double t3 = now_ms();
    g.t_symbols = t1 - t0;
    g.t_cfg = t2 - t1;
    g.t_emit = t3 - t2;
  }  // the CFG is freed here
  g.module_bytes = mod.bytes.size();
  g.emit_stats = mod.stats;
  if (!load_wasm_module(mod, &g.load, &g.error)) return 0;
  g.translated = true;
  return 1;
}

EMSCRIPTEN_KEEPALIVE const char* mvp_translate_info() {
  const auto& s = g.emit_stats;
  char b[640];
  std::snprintf(b, sizeof b,
                "{\"symbols_ms\":%.1f,\"cfg_ms\":%.1f,\"emit_ms\":%.1f,\"compile_ms\":%.1f,\"instantiate_ms\":%.1f,"
                "\"module_bytes\":%zu,\"functions\":%zu,\"wasm_functions\":%zu,\"instructions\":%zu,"
                "\"inline\":%zu,\"helper\":%zu,\"branch\":%zu}",
                g.t_symbols, g.t_cfg, g.t_emit, g.load.compile_ms, g.load.instantiate_ms, g.module_bytes, s.functions,
                s.wasm_functions, s.instructions, s.inline_insns, s.helper_insns, s.branch_insns);
  g_text = b;
  return g_text.c_str();
}

// Builds the machine. `script` (len > 0): an mvp-input script drives the pads
// (tests); otherwise live input from mvp_set_pad. Stops after `stop_fields` VI
// fields or at the poll of frame `stop_frames` (0: never).
EMSCRIPTEN_KEEPALIVE int mvp_boot(const char* script, int len, double stop_fields, double stop_frames) {
  g.error.clear();
  if (!g.translated) {
    g.error = "not translated";
    return 0;
  }
  FrameInput boot_input = neutral_input(1);
  g.input = std::make_unique<InputQueue>(boot_input);
  if (len > 0) {
    auto s = InputScript::parse(std::string(script, static_cast<std::size_t>(len)), &g.error, boot_input);
    if (!s) {
      g.error = "input script: " + g.error;
      return 0;
    }
    g.script = std::make_unique<InputScript>(std::move(*s));
    g.input->set_source(g.script.get());
  } else {
    g.input->set_source(&g.live);
  }
  if (stop_fields > 0) g.stop_fields = static_cast<std::uint64_t>(stop_fields);
  if (stop_frames > 0) g.stop_frames = static_cast<std::uint64_t>(stop_frames);

  g.m = std::make_unique<Machine>();
  g.m->load_dol(g.disc->dol);
  setup_boot_environment(*g.m, *g.disc);
  g.hw = std::make_unique<Hardware>(&g.m->cpu(), g.m->mem1(), Machine::kMem1Size);
  g.hw->set_disc(g.disc->image.get());
  g.hooks = std::make_unique<YieldingHooks>(g.m.get(), g.hw.get());
  g.m->memory().io = g.hw.get();
  g.m->cpu().hooks = g.hooks.get();
  g.hooks->reschedule(g.m->cpu());
  g.obs.e = &g;
  g.hw->set_gfx_observer(&g.obs);
  g_input = g.input.get();
  g_frame_hook = &frame_hook;
  attach_renderer();
  return 1;
}

// Starts the renderer on the canvas the page registered under `selector`
// (Module.specialHTMLTargets). Asynchronous; Module.mvpOnGfx(ok, message) runs
// when it is ready or has failed. It may start before mvp_boot (the requests
// overlap the translation). The game runs without a renderer until then (or
// for good if WebGPU is missing): rendering never changes guest state.
EMSCRIPTEN_KEEPALIVE void mvp_gfx_init(const char* selector, int width, int height) {
  std::string sel = selector;
  gfx::Gpu::create_async([sel, width, height](std::unique_ptr<gfx::Gpu> gpu, std::string err) {
    if (!gpu) {
      g.gfx_error = err;
      mvp_js_on_gfx(0, err.c_str());
      return;
    }
    g.gpu = std::move(gpu);
    g.window = gfx::Window::open_canvas(sel.c_str(), width, height, &err);
    if (!g.window || !g.window->attach(*g.gpu, &err)) {
      g.gfx_error = err;
      g.window.reset();
      mvp_js_on_gfx(0, err.c_str());
      return;
    }
    attach_renderer();
    std::string msg = g.gpu->adapter_name();
    mvp_js_on_gfx(1, msg.c_str());
  });
}

EMSCRIPTEN_KEEPALIVE void mvp_canvas_resize(int width, int height) {
  if (g.window) g.window->resize(width, height);
}

// Runs `n` VI fields (fewer if the run stops). Returns the fields run, or -1
// once stopped (mvp_status() says why).
EMSCRIPTEN_KEEPALIVE int mvp_run_fields(int n) {
  if (!g.m || g.stopped) return -1;
  const std::uint64_t start = g.hw->vi_fields(), target = start + static_cast<std::uint64_t>(n);
  double t0 = now_ms();
  try {
    while (g.hw->vi_fields() < target) {
      double f0 = now_ms();
      rt::run(g.m->cpu());
      double dt = now_ms() - f0;
      if (dt > g.max_field_ms) g.max_field_ms = dt;
    }
  } catch (const StopRun& s) {
    g.stopped = true;
    g.why = s.why;
  } catch (const ppc::GuestFault& f) {
    g.stopped = true;
    g.why = std::string("guest fault: ") + f.what();
  }
  g.last_batch_ms = now_ms() - t0;
  g.run_ms += g.last_batch_ms;
  const std::uint64_t ran = g.hw->vi_fields() - start;
  g.run_fields += ran;
  if (g.renderer && g.stopped) g.renderer->flush();
  return static_cast<int>(ran);
}

// Shows the frame the video interface scans out (the XFB copy at the VI's
// address, else the latest copy). Returns 1 if a frame was drawn.
EMSCRIPTEN_KEEPALIVE int mvp_present() {
  if (!g.renderer || !g.window) return 0;
  const gfx::Renderer::Frame* f = g.renderer->xfb(g.xfb);
  if (!f) f = g.renderer->latest_xfb();
  if (!f) return 0;
  g.window->present(f->view, f->width, f->height);
  ++g.presents;
  g.last_presented = f->serial;
  return 1;
}

// The host controller state for port `port` (0-3), used from the next frame
// poll on (live input only; scripts ignore it).
EMSCRIPTEN_KEEPALIVE void mvp_set_pad(int port, int connected, int buttons, int sx, int sy, int cx, int cy, int tl,
                                      int tr) {
  if (port < 0 || port >= kPorts) return;
  PadState p;
  p.connected = connected != 0;
  p.buttons = static_cast<u16>(buttons) & pad::kAll;
  auto s8c = [](int v) { return static_cast<s8>(v < -128 ? -128 : v > 127 ? 127 : v); };
  auto u8c = [](int v) { return static_cast<u8>(v < 0 ? 0 : v > 255 ? 255 : v); };
  p.stick_x = s8c(sx);
  p.stick_y = s8c(sy);
  p.substick_x = s8c(cx);
  p.substick_y = s8c(cy);
  p.trigger_l = u8c(tl);
  p.trigger_r = u8c(tr);
  p.analog_a = (p.buttons & pad::kA) ? 255 : 0;
  p.analog_b = (p.buttons & pad::kB) ? 255 : 0;
  g.live.set(port, p);
}

EMSCRIPTEN_KEEPALIVE const char* mvp_status() {
  if (!g.m) return "{}";
  ppc::Cpu& c = g.m->cpu();
  const double guest_s = static_cast<double>(g.hooks->time_base(c)) / 40500000.0;
  char b[1024];
  int n = std::snprintf(
      b, sizeof b,
      "{\"fields\":%llu,\"frames\":%llu,\"instructions\":%llu,\"guest_s\":%.4f,\"run_ms\":%.1f,\"run_fields\":%llu,"
      "\"last_batch_ms\":%.2f,\"max_field_ms\":%.2f,\"yields\":%llu,\"presents\":%llu,\"stopped\":%s",
      static_cast<unsigned long long>(g.hw->vi_fields()), static_cast<unsigned long long>(g_frame_polls),
      static_cast<unsigned long long>(c.ticks), guest_s, g.run_ms, static_cast<unsigned long long>(g.run_fields),
      g.last_batch_ms, g.max_field_ms, static_cast<unsigned long long>(g.hooks->yields),
      static_cast<unsigned long long>(g.presents), g.stopped ? "true" : "false");
  std::string s(b, static_cast<std::size_t>(n));
  s += ",\"heap_mb\":" + std::to_string(emscripten_get_heap_size() >> 20);
  if (g.stopped) s += ",\"why\":\"" + json_escape(g.why) + "\"";
  if (g.file)
    s += ",\"disc_reads\":" + std::to_string(g.file->reads) + ",\"disc_bytes\":" + std::to_string(g.file->bytes);
  if (g.renderer) {
    const auto& rs = g.renderer->stats();
    const auto& ps = g.proc->stats();
    std::snprintf(b, sizeof b,
                  ",\"draws\":%llu,\"xfb_copies\":%llu,\"pipelines\":%llu,\"textures\":%llu,\"gpu_errors\":%llu",
                  static_cast<unsigned long long>(rs.draws), static_cast<unsigned long long>(ps.xfb_copies),
                  static_cast<unsigned long long>(rs.pipelines), static_cast<unsigned long long>(rs.textures_decoded),
                  static_cast<unsigned long long>(g.gpu->errors()));
    s += b;
  }
  if (!g.gfx_error.empty()) s += ",\"gfx_error\":\"" + json_escape(g.gfx_error) + "\"";
  s += "}";
  g_text = s;
  return g_text.c_str();
}

// The determinism line, in mvp-play's format: instructions, time base, frame
// polls and the SHA-1 of MEM1 (compare with a native run of the same input).
EMSCRIPTEN_KEEPALIVE const char* mvp_guest_line() {
  if (!g.m) return "";
  Sha1 mem;
  mem.update(g.m->mem1(), Machine::kMem1Size);
  char b[256];
  std::snprintf(b, sizeof b, "guest: %llu instructions, time base %llu, %llu frame polls, MEM1 sha1 %s",
                static_cast<unsigned long long>(g.m->cpu().ticks),
                static_cast<unsigned long long>(g.hooks->time_base(g.m->cpu())),
                static_cast<unsigned long long>(g_frame_polls), Sha1::hex(mem.finish()).c_str());
  g_text = b;
  return g_text.c_str();
}

}  // extern "C"
