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
// E2c adds: mvp_open_disc_url (the image from the server, web_disc.h), the
// translated module's cache (mvp_keep_module, mvp_module_blob,
// mvp_translate_cached: module_cache.h), audio (mvp_audio_*: web_audio.h) and
// read-ahead for the server's image (mvp_disc_want / mvp_disc_insert).
// E6 adds roster packs (packs_web.h: mvp_pack_*, mvp_packs_mount), mounted on the
// virtual disc between mvp_open_disc and mvp_boot.
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

#include "audio/mixer.h"
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
#include "web/wasm/module_cache.h"
#include "web/wasm/web_audio.h"
#include "web/wasm/web_disc.h"
#include "web/wasm/net_web.h"
#include "web/wasm/packs_web.h"

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

// Loading progress for the page's status line (posted while the Worker is
// still busy: the page shows it at once).
EM_JS(void, mvp_js_progress, (const char* what, int step, int steps), {
  if (Module['mvpOnProgress']) Module['mvpOnProgress'](UTF8ToString(what), step, steps);
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
    if (trace) trace->push_back({off, static_cast<std::uint32_t>(n)});
    return mvp_js_disc_read(static_cast<double>(off), dst, static_cast<double>(n)) != 0;
  }
  std::uint64_t reads = 0, bytes = 0;
  // Development: every read's offset and size (mvp_disc_trace), to tune the
  // server image's block cache (block_cache.h) offline. Offsets only, no data.
  std::vector<std::pair<std::uint64_t, std::uint32_t>>* trace = nullptr;

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
  u16 last_buttons = 0;        // port 1's buttons at the last poll
  u64 polls_with_buttons = 0;  // polls that returned a pressed button on any port
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
    last_buttons = in.pad[0].buttons;
    for (const PadState& p : in.pad)
      if (p.buttons) {
        ++polls_with_buttons;
        break;
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
  JsFileSource* file = nullptr;  // owned by disc (a picked File)
  web::BlockCacheSource* http = nullptr;  // owned by disc (the server's image)
  std::uint64_t want_first = 0;           // mvp_disc_want's run
  std::optional<vfs::Disc> disc;
  std::string image_kind;

  // Translation.
  bool translated = false;
  double t_symbols = 0, t_cfg = 0, t_emit = 0;
  WasmLoadStats load;
  xlat::WasmEmitStats emit_stats;
  std::size_t module_bytes = 0;
  bool keep_module = false;      // keep the module for the cache (mvp_module_blob)
  bool from_cache = false;
  xlat::WasmModule kept;
  std::vector<std::uint8_t> blob;

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

  // Audio (E2c): the mixer observes the DSP; its frames wait in `audio` for the Worker.
  bool audio_on = false;
  std::unique_ptr<audio::AxMixer> mixer;
  web::PendingAudio audio;

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
  if (web::net_active()) web::net_after_poll(frame);  // netplay (E5): state hash, early yield
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

// Attaches or detaches the mixer (a fresh one each time: its per-voice state
// starts over). Between run batches only, never inside an AX frame.
void apply_audio() {
  if (!g.hw) return;
  if (g.audio_on && !g.mixer) {
    g.mixer = std::make_unique<audio::AxMixer>(&g.audio);
    Hardware* hw = g.hw.get();
    g.mixer->set_rate([hw] { return hw->ai_dsp_rate(); });
    g.hw->set_ax_observer(g.mixer.get());
  } else if (!g.audio_on && g.mixer) {
    g.hw->set_ax_observer(nullptr);
    g.mixer.reset();
    g.audio.clear();
  }
}

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

}  // extern "C"

namespace {

// CISO or ISO, then the identity check (GV4E69 rev 0, by the DOL's SHA-1).
bool open_image(std::unique_ptr<vfs::Source> src) {
  vfs::Source* raw = src.get();
  std::unique_ptr<vfs::Source> image;
  char magic[4] = {};
  if (raw->size() >= 4 && raw->read(0, magic, 4) && std::string(magic, 4) == "CISO") {
    image = vfs::CisoSource::open(std::move(src), &g.error);
    g.image_kind = "CISO";
    if (!image) return false;
  } else {
    image = std::move(src);
    g.image_kind = "ISO";
  }
  mvp_js_progress("Checking the disc (main.dol SHA-1)", 0, 0);
  auto disc = vfs::open_disc(std::move(image), true, &g.error);
  if (!disc) return false;
  g.disc = std::move(*disc);
  web::net_set_disc(&*g.disc);    // the netplay handshake's disc identity (E5), before any pack is mounted
  web::packs_set_disc(&*g.disc);  // roster packs are mounted on it (E6, mvp_packs_mount)
  return true;
}

}  // namespace

extern "C" {

std::vector<std::pair<std::uint64_t, std::uint32_t>> g_trace;
bool g_tracing = false;

// Opens the picked image (Module.mvpDisc, `size` bytes) and checks that it is
// GV4E69 rev 0. Returns 1, or 0 with mvp_last_error() set.
EMSCRIPTEN_KEEPALIVE int mvp_open_disc(double size) {
  g.error.clear();
  auto src = std::make_unique<JsFileSource>(static_cast<std::uint64_t>(size));
  JsFileSource* raw = src.get();
  if (g_tracing) raw->trace = &g_trace;
  if (!open_image(std::move(src))) return 0;
  g.file = raw;
  return 1;
}

// Development: record the picked image's reads (call before mvp_open_disc),
// and return them as "offset size" lines, with "F field" lines where a run
// batch starts (the image's offsets and sizes, no data).
EMSCRIPTEN_KEEPALIVE void mvp_disc_trace_enable() { g_tracing = true; }
EMSCRIPTEN_KEEPALIVE const char* mvp_disc_trace() {
  g_text.clear();
  for (const auto& [off, n] : g_trace)
    g_text += (off == ~0ull ? "F " + std::to_string(n) : std::to_string(off) + " " + std::to_string(n)) + '\n';
  return g_text.c_str();
}

// The same for the server's image (Module.mvpDiscUrl, `size` bytes), read by
// Range requests through a block cache (block_cache.h): `block_kib` KiB
// blocks, at most `max_blocks` of them, runs of at most `max_run` blocks per
// request, `ahead` blocks of read-ahead (0 or less: the defaults, 256 KiB x
// 256, runs of 4, 8 ahead; ahead < 0: the default, 0: none).
EMSCRIPTEN_KEEPALIVE int mvp_open_disc_url(double size, int block_kib, int max_blocks, int max_run, int ahead) {
  g.error.clear();
  web::BlockCacheSource::Options opt;
  if (block_kib > 0) opt.block = static_cast<std::uint32_t>(block_kib) << 10;
  if (max_blocks > 0) opt.max_blocks = static_cast<std::uint32_t>(max_blocks);
  if (max_run > 0) opt.max_run = static_cast<std::uint32_t>(max_run);
  if (ahead >= 0) opt.ahead = static_cast<std::uint32_t>(ahead);
  auto src = web::open_http_disc(static_cast<std::uint64_t>(size), opt);
  web::BlockCacheSource* raw = src.get();
  if (!open_image(std::move(src))) {
    if (!web::last_http_error().empty()) g.error += " (" + web::last_http_error() + ")";
    return 0;
  }
  g.http = raw;
  return 1;
}

// Read-ahead for the server's image: the run of blocks a sequential stream
// wants next (0: none). mvp_disc_want_first() and mvp_disc_block() give the
// first block and the block size; mvp_disc_insert() hands the bytes back
// (ok = 0: the fetch failed, the blocks are released).
EMSCRIPTEN_KEEPALIVE int mvp_disc_want() {
  if (!g.http) return 0;
  const auto w = g.http->want();
  g.want_first = w.first;
  return static_cast<int>(w.count);
}
EMSCRIPTEN_KEEPALIVE double mvp_disc_want_first() { return static_cast<double>(g.want_first); }
EMSCRIPTEN_KEEPALIVE double mvp_disc_block() { return g.http ? g.http->options().block : 0; }
EMSCRIPTEN_KEEPALIVE void mvp_disc_insert(double first, int count, const std::uint8_t* data, double n, int ok) {
  if (g.http)
    g.http->insert(static_cast<std::uint64_t>(first), static_cast<std::uint32_t>(count), data,
                   static_cast<std::size_t>(n), ok != 0);
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
  mvp_js_progress("Translating: reading the symbol map", 1, 5);
  std::vector<std::string> errs;
  xlat::SymbolTable syms = xlat::SymbolTable::parse(std::string(text, static_cast<std::size_t>(len)), &errs);
  if (!errs.empty()) {
    g.error = "symbols.txt: " + errs.front() + " (" + std::to_string(errs.size()) + " errors)";
    return 0;
  }
  double t1 = now_ms();
  xlat::WasmModule mod;
  {
    mvp_js_progress("Translating: finding the control flow of every function", 2, 5);
    xlat::ProgramCfg cfg = xlat::build_cfg(g.disc->dol, syms);
    double t2 = now_ms();
    mvp_js_progress("Translating: emitting WebAssembly", 3, 5);
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
  mvp_js_progress("Translating: compiling the module", 4, 5);
  if (!load_wasm_module(mod, &g.load, &g.error)) return 0;
  g.translated = true;
  if (g.keep_module) g.kept = std::move(mod);  // serialized later, off the critical path
  return 1;
}

// Keep the translated module after mvp_translate, for the browser's cache.
EMSCRIPTEN_KEEPALIVE void mvp_keep_module(int keep) { g.keep_module = keep != 0; }

// The kept module for the cache (module_cache.h), in two pieces the Worker
// writes one after the other: the header (its tables; mvp_module_blob returns
// its size, mvp_module_blob_ptr its address) and the wasm bytes
// (mvp_module_bytes_ptr, mvp_module_bytes_len); valid until mvp_module_release().
EMSCRIPTEN_KEEPALIVE double mvp_module_blob() {
  if (g.kept.bytes.empty()) return 0;
  g.blob = web::serialize_module_header(g.kept);
  return static_cast<double>(g.blob.size());
}
EMSCRIPTEN_KEEPALIVE const std::uint8_t* mvp_module_blob_ptr() { return g.blob.data(); }
EMSCRIPTEN_KEEPALIVE const std::uint8_t* mvp_module_bytes_ptr() { return g.kept.bytes.data(); }
EMSCRIPTEN_KEEPALIVE double mvp_module_bytes_len() { return static_cast<double>(g.kept.bytes.size()); }
EMSCRIPTEN_KEEPALIVE void mvp_module_release() {
  g.kept = xlat::WasmModule{};
  std::vector<std::uint8_t>().swap(g.blob);
}

// Loads a module from the browser's cache (a blob mvp_module_blob made for a
// disc with the same DOL, by the same engine build) instead of translating.
// Returns 1, or 0 with mvp_last_error() set (the Worker then translates).
EMSCRIPTEN_KEEPALIVE int mvp_translate_cached(const std::uint8_t* blob, double len) {
  g.error.clear();
  if (!g.disc) {
    g.error = "no disc";
    return 0;
  }
  xlat::WasmModule mod;
  const double t0 = now_ms();
  if (!web::deserialize_module(blob, static_cast<std::size_t>(len), &mod, &g.error)) return 0;
  g.t_symbols = g.t_cfg = 0;
  g.t_emit = now_ms() - t0;  // unpacking the blob stands in for the emitter
  g.module_bytes = mod.bytes.size();
  g.emit_stats = mod.stats;
  mvp_js_progress("Loading the cached translation: compiling", 4, 5);
  if (!load_wasm_module(mod, &g.load, &g.error)) return 0;
  g.translated = true;
  g.from_cache = true;
  return 1;
}

EMSCRIPTEN_KEEPALIVE const char* mvp_translate_info() {
  const auto& s = g.emit_stats;
  char b[640];
  std::snprintf(b, sizeof b,
                "{\"symbols_ms\":%.1f,\"cfg_ms\":%.1f,\"emit_ms\":%.1f,\"compile_ms\":%.1f,\"instantiate_ms\":%.1f,"
                "\"module_bytes\":%zu,\"functions\":%zu,\"wasm_functions\":%zu,\"instructions\":%zu,"
                "\"inline\":%zu,\"helper\":%zu,\"branch\":%zu,\"cached\":%s}",
                g.t_symbols, g.t_cfg, g.t_emit, g.load.compile_ms, g.load.instantiate_ms, g.module_bytes, s.functions,
                s.wasm_functions, s.instructions, s.inline_insns, s.helper_insns, s.branch_insns,
                g.from_cache ? "true" : "false");
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
  // Netplay (E5): players 1 and 2 on ports 1 and 2, once the handshake is done.
  const bool net = web::net_active();
  if (net && !web::net_running()) {
    g.error = "the netplay session is not running";
    return 0;
  }
  FrameInput boot_input = neutral_input(net ? 0x3 : 1);
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
  if (net) {
    // This side's controller: the script's port for this player, or the live pad (port 1 on the page).
    InputSource* local = g.script ? static_cast<InputSource*>(g.script.get()) : &g.live;
    g.input->set_source(web::net_attach(*g.m, *g.hooks, local, g.script ? web::net_player() - 1 : 0));
  }
  g_input = g.input.get();
  g_frame_hook = &frame_hook;
  attach_renderer();
  apply_audio();
  return 1;
}

// Audio on or off (the mixer attached or not), before or after mvp_boot.
// Guest state is the same either way (E3b-MIX1).
EMSCRIPTEN_KEEPALIVE void mvp_audio_enable(int on) {
  g.audio_on = on != 0;
  apply_audio();
}

// The frames mixed since the last call (interleaved 16-bit stereo at
// mvp_audio_rate() Hz); mvp_audio_ptr() is valid until the next call.
EMSCRIPTEN_KEEPALIVE int mvp_audio_take() { return static_cast<int>(g.audio.take()); }
EMSCRIPTEN_KEEPALIVE const std::int16_t* mvp_audio_ptr() { return g.audio.taken(); }
EMSCRIPTEN_KEEPALIVE int mvp_audio_rate() { return static_cast<int>(g.audio.rate()); }

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
  if (g_tracing) g_trace.push_back({~0ull, static_cast<std::uint32_t>(start)});
  double t0 = now_ms();
  try {
    while (g.hw->vi_fields() < target) {
      if (web::net_active() && !web::net_may_run()) break;  // netplay: the next frame's input is not here yet
      double f0 = now_ms();
      rt::run(g.m->cpu());
      double dt = now_ms() - f0;
      if (dt > g.max_field_ms) g.max_field_ms = dt;
    }
  } catch (const StopRun& s) {
    g.stopped = true;
    g.why = s.why;
    if (g.http && !g.http->error().empty()) g.why += ": " + g.http->error();
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
  if (g.http) {
    const auto& h = g.http->stats();
    std::snprintf(b, sizeof b,
                  ",\"disc_reads\":%llu,\"disc_bytes\":%llu,\"net\":{\"requests\":%llu,\"fetched\":%llu,\"hits\":%llu,"
                  "\"misses\":%llu,\"prefetched\":%llu,\"prefetch_used\":%llu,\"prefetch_wasted\":%llu,"
                  "\"blocked_ms\":%.1f}",
                  static_cast<unsigned long long>(h.reads), static_cast<unsigned long long>(h.bytes),
                  static_cast<unsigned long long>(h.requests), static_cast<unsigned long long>(h.fetched),
                  static_cast<unsigned long long>(h.hits), static_cast<unsigned long long>(h.misses),
                  static_cast<unsigned long long>(h.prefetched), static_cast<unsigned long long>(h.prefetch_used),
                  static_cast<unsigned long long>(h.prefetch_wasted), h.blocked_ms);
    s += b;
  }
  if (g.mixer) {
    const auto& ms = g.mixer->stats();
    std::snprintf(b, sizeof b,
                  ",\"audio\":{\"frames\":%llu,\"rate\":%u,\"voice_ms\":%llu,\"aux_returns\":%llu,\"nonsilent\":%llu,"
                  "\"peak\":%d,\"dropped\":%llu}",
                  static_cast<unsigned long long>(ms.frames), g.audio.rate(),
                  static_cast<unsigned long long>(ms.voice_ms),
                  static_cast<unsigned long long>(ms.aux_return_frames[0]),
                  static_cast<unsigned long long>(ms.nonsilent_frames), ms.peak,
                  static_cast<unsigned long long>(g.audio.dropped()));
    s += b;
  }
  s += ",\"pad_last\":" + std::to_string(g.live.last_buttons) +
       ",\"pad_polls\":" + std::to_string(g.live.polls_with_buttons);
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
