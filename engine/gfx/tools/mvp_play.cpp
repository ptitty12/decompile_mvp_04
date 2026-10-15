// mvp-play (E1): runs the retail game natively (translated code, as mvp-boot)
// and renders its GX command stream with WebGPU: a window shows the frame the
// video interface scans out at every VI field. For development.
//
//   mvp-play [--input SCRIPT] [--ports MASK] [--frames N] [--fields N] [--max-ticks N]
//            [--headless] [--present-every N]
//            [--capture DIR] [--capture-every N] [--capture-at F1,F2,...]
//
//   --input, --ports  controller input, as mvp-boot (runtime/input.h scripts)
//   --frames N        stop at the frame poll of frame N; --fields N: after N VI fields
//   --max-ticks N     instruction budget (default: none)
//   --headless        no window: render off-screen only (captures still work)
//   --no-render       no renderer at all (the guest runs alone; for the determinism check)
//   --yield           return from rt::run() at every VI field and call it again, as
//                     the browser does (runtime/host_yield.h); the guest must run
//                     the same (compare the "guest:" line with a run without it)
//   --present-every N show every Nth VI field (default 1)
//   --capture DIR     write the scanned-out frame as DIR/field_N_frame_F.png (VI field N,
//                     game frame poll F, the number input scripts use) every
//                     --capture-every N fields (default 60) and at the --capture-at
//                     fields (--capture-from N: periodic captures from VI field N on);
//                     only frames that changed since the last capture
//   --draw-log FILE   one line per draw and EFB copy (state, textures) from VI field
//                     --draw-log-from N (default 0) to --draw-log-to N
//   --dump-textures DIR at VI field --dump-field N: every texture each draw
//                     samples, decoded from guest memory, as DIR/tex_F_D_M.png
//                     (--dump-to M: every field from N to M)
//   --perf-every N    print guest and host seconds every N VI fields (speed per stretch)
//   --profile N       sample the guest PC (a host thread); print the N busiest functions
//                     (--profile-from F: from VI field F on)
//   --host-profile N  (Windows) sample the host thread's instruction pointer; print the N
//                     busiest host functions (translated guest code as one bucket),
//                     from --profile-from on
//   --trace-entry A,B registers and memory at r3/r4 at each entry of those functions (hex
//                     addresses), from VI field --trace-from to --trace-to, to --trace-file;
//                     --trace-peek O1,O2: also the words at r3 + those (hex) offsets
//   --audio-wav FILE  (E3b) the AX mix as a 16-bit stereo WAV, exactly as virtual
//                     time produced it (keep it under build/; never commit it)
//   --no-audio        no playback (default: SDL3 playback when a window is open)
//   --audio-latency MS buffering between the mixer and the device (default 100)
//   --pack PATH       (E6) a roster pack (directory or .zip), repeatable, in set order:
//                     applied to the disc's tables and mounted on the virtual disc
//                     before boot (docs/MODDING.md, mods/mount.h)
//
// Determinism: the renderer and the mixer only read guest state, audio and
// window events never reach the guest (playback throttles the host, not the
// guest); with the same input script, the guest runs exactly as under
// mvp-boot. The report's "guest:" line (instructions, time base, SHA-1 of MEM1)
// is the same with and without --no-render (local test local_play_determinism).
// Captures are game-derived: they belong under build/ and are never committed.
//
// Exit status: 0 when the run ended by its budget with frames shown and no
// WebGPU errors (or with --no-render), 1 otherwise, 77 without the disc.
#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <thread>
#include <vector>

#include "audio/mixer.h"
#include "audio/sdl_out.h"
#include "audio/wav.h"
#include "common/file.h"
#include "common/sha1.h"
#include "gfx/gx_processor.h"
#include "gfx/png.h"
#include "gfx/texture_decode.h"
#include "gfx/wgpu/gpu.h"
#include "gfx/wgpu/renderer.h"
#include "gfx/wgpu/window.h"
#include "host_profiler.h"
#include "mods/mount.h"
#include "runtime/boot.h"
#include "runtime/hle.h"
#include "runtime/host_yield.h"
#include "runtime/hw.h"
#include "runtime/input.h"
#include "runtime/native.h"
#include "runtime/sys_hooks.h"
#include "translator/program.h"

void mvp_register_game();

using namespace mvp;
using namespace mvp::rt;

namespace {

// Logs every draw and copy, then hands it on (--draw-log).
struct DrawLog : gfx::Backend {
  gfx::Backend* next = nullptr;
  std::FILE* f = nullptr;
  const std::uint64_t* field = nullptr;
  const gfx::GxProcessor* proc = nullptr;
  std::uint64_t from = 0, to = ~0ull;
  bool on() const { return f && *field >= from && *field <= to; }
  // Texture dumps (--dump-textures).
  const std::uint8_t* mem = nullptr;
  std::uint32_t mem_size = 0;
  std::string dump_dir;
  std::uint64_t dump_field = ~0ull, dump_to = 0, dump_draw = 0;
  void dump(const gfx::DrawCall& d) {
    for (int m = 0; m < 8; ++m) {
      const gfx::TextureDesc& t = d.tex[static_cast<std::size_t>(m)];
      if (!t.valid || !gfx::texture_format_known(t.format)) continue;
      const std::uint32_t a = t.addr & 0x01FFFFFFu;
      const std::uint32_t bytes = gfx::texture_level_size(t.format, t.width, t.height);
      if (a > mem_size || bytes > mem_size - a) continue;
      std::vector<std::uint8_t> rgba(static_cast<std::size_t>(t.width) * t.height * 4);
      gfx::decode_texture(t.format, t.width, t.height, mem + a, rgba.data(), t.tlut, t.tlut_format, t.tlut_entries);
      char name[96];
      std::snprintf(name, sizeof name, "/tex_%llu_%llu_%d.png", static_cast<unsigned long long>(*field),
                    static_cast<unsigned long long>(dump_draw), m);
      gfx::write_png_rgba(dump_dir + name, t.width, t.height, rgba.data());
    }
    ++dump_draw;
  }
  void draw(const gfx::DrawCall& d) override {
    if (on()) {
      const gfx::PipelineConfig& c = d.cfg;
      std::fprintf(f, "field %llu draw %zu verts %zu indices topo %u stages %u texgens %u chans %u ind %u blend %u/%u/%u/%u z %u/%u/%u "
                   "cull %u fmt %u acmp %u/%u/%u ref %d/%d logic %u/%u fog %u scissor %u,%u-%u,%u\n",
                   static_cast<unsigned long long>(*field), d.verts.size(), d.index.size(), c.topology, c.num_stages, c.num_texgens,
                   c.num_chans, c.num_ind, c.blend_enable, c.blend_src, c.blend_dst, c.blend_sub, c.z_enable, c.z_func,
                   c.z_update, c.cull, c.pixel_format, c.alpha_comp0, c.alpha_comp1, c.alpha_logic, d.u.alpha_ref[0],
                   d.u.alpha_ref[1], c.logic_enable, c.logic_op, c.fog_type, d.scissor[0], d.scissor[1], d.scissor[2],
                   d.scissor[3]);
      if (proc) {
        const auto& pi = proc->last_primitive();
        std::fprintf(f, "  prim %02X x%u size %u vcd %08X %08X vat %08X %08X %08X matidx %08X %08X texgen %08X %08X n %u dual %u vtx",
                     pi.op, pi.count, pi.vertex_size, pi.vcd_lo, pi.vcd_hi, pi.vat[0], pi.vat[1], pi.vat[2],
                     pi.matidx[0], pi.matidx[1], pi.texgen[0], pi.texgen[1], pi.num_texgens, pi.dual_tex);
        for (auto b : pi.first_vertex) std::fprintf(f, " %02X", b);
        std::fprintf(f, "\n  arrays");
        for (int k = 0; k < 6; ++k) std::fprintf(f, " %08X/%u", pi.array_base[k], pi.array_stride[k]);
        std::fprintf(f, "\n");
      }
      for (int i = 0; i < c.num_stages; ++i) {
        const gfx::TevStage& t = c.stages[i];
        std::fprintf(f, "  stage %d color %06X alpha %06X ind %06X tex %u map %u coord %u ras %u kc %u ka %u\n", i,
                     t.color_env, t.alpha_env, t.ind_cmd, t.tex_enable, t.texmap, t.texcoord, t.ras_chan, t.kcsel,
                     t.kasel);
      }
      for (int i = 0; i < c.num_ind; ++i)
        std::fprintf(f, "  ind %d map %u coord %u scale %02X\n", i, c.iref_map[i], c.iref_coord[i], c.ind_scale[i]);
      for (int m = 0; m < 8; ++m) {
        const gfx::TextureDesc& t = d.tex[static_cast<std::size_t>(m)];
        if (!t.valid) continue;
        std::fprintf(f, "  map %d addr %08X fmt %u %ux%u levels %u wrap %u/%u filter %u/%u tlut %u@%X\n", m, t.addr,
                     t.format, t.width, t.height, t.levels, t.wrap_s, t.wrap_t, t.mag_linear, t.min_filter,
                     t.tlut_format, t.tlut_offset);
      }
      for (int r = 0; r < 4; ++r)
        std::fprintf(f, "  reg%d %d %d %d %d konst %d %d %d %d\n", r, d.u.tev_regs[r][0], d.u.tev_regs[r][1],
                     d.u.tev_regs[r][2], d.u.tev_regs[r][3], d.u.konst[r][0], d.u.konst[r][1], d.u.konst[r][2],
                     d.u.konst[r][3]);
      for (std::size_t k = 0; k < d.verts.size() && k < 4; ++k) {
        const gfx::OutVertex& v = d.verts[k];
        std::fprintf(f, "  v%zu pos %.3f %.3f %.3f %.3f c0 %.3f %.3f %.3f %.3f t0 %.3f %.3f %.3f t1 %.3f %.3f %.3f\n", k,
                     v.pos[0], v.pos[1], v.pos[2], v.pos[3], v.color[0][0], v.color[0][1], v.color[0][2],
                     v.color[0][3], v.tex[0][0], v.tex[0][1], v.tex[0][2], v.tex[1][0], v.tex[1][1], v.tex[1][2]);
      }
    }
    if (!dump_dir.empty() && *field >= dump_field && *field <= std::max(dump_field, dump_to)) dump(d);
    next->draw(d);
  }
  void efb_copy(const gfx::EfbCopy& c) override {
    if (on())
      std::fprintf(f, "field %llu copy %s %u,%u %ux%u -> %08X fmt %u%s half %u clear %u rgba %02X%02X%02X%02X z %06X\n",
                   static_cast<unsigned long long>(*field), c.to_xfb ? "xfb" : "tex", c.src_x, c.src_y, c.width,
                   c.height, c.dest, c.tex_format, c.intensity ? "i" : "", c.half_scale, c.clear, c.clear_rgba[0],
                   c.clear_rgba[1], c.clear_rgba[2], c.clear_rgba[3], c.clear_z);
    next->efb_copy(c);
  }
  void invalidate_textures() override { next->invalidate_textures(); }
};

struct Play : GfxObserver {
  YieldingHooks* yield_hooks = nullptr;  // --yield
  gfx::GxProcessor* proc = nullptr;
  gfx::Renderer* renderer = nullptr;
  gfx::Window* window = nullptr;
  audio::SdlAudioOut* audio_out = nullptr;
  std::uint64_t present_every = 1, max_fields = ~0ull;
  std::string capture_dir;
  std::uint64_t capture_every = 60, capture_from = 0;
  std::set<std::uint64_t> capture_at;
  std::uint64_t last_capture_serial = 0, captures = 0, fields = 0, presents = 0;
  std::uint64_t frames = 0, max_frames = ~0ull;
  // --perf-every N: host and guest seconds every N fields (speed per stretch).
  std::uint64_t perf_every = 0;
  std::chrono::steady_clock::time_point t0;
  rt::SystemHooks* hooks = nullptr;
  ppc::Cpu* cpu = nullptr;

  void perf(std::uint64_t field) {
    if (!perf_every || field % perf_every) return;
    const double host = std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
    const double guest = static_cast<double>(hooks->time_base(*cpu)) / 40500000.0;
    std::printf("perf: field %llu frame %llu guest %.3f s host %.3f s\n", static_cast<unsigned long long>(field),
                static_cast<unsigned long long>(frames), guest, host);
  }

  // Without a renderer (--no-render) the observer only counts fields.
  void gx_command(const std::uint8_t* cmd, std::size_t len) override {
    if (proc) proc->command(cmd, len);
  }

  void vi_field(std::uint64_t field, std::uint32_t xfb) override {
    fields = field;
    perf(field);
    if (yield_hooks) yield_hooks->request_yield();
    if (!renderer) {
      if (field >= max_fields) throw StopRun{"ran " + std::to_string(max_fields) + " VI fields (--fields)"};
      return;
    }
    renderer->flush();
    const gfx::Renderer::Frame* f = renderer->xfb(xfb);
    if (!f) f = renderer->latest_xfb();
    if (window && field % present_every == 0) {
      if (audio_out) audio_out->throttle();  // keep the host near real time (host pacing only)
      if (!window->pump()) throw StopRun{"window closed"};
      if (f) {
        window->present(f->view, f->width, f->height);
        ++presents;
      }
    }
    if (!capture_dir.empty() && f && f->serial != last_capture_serial &&
        ((field >= capture_from && field % capture_every == 0) || capture_at.count(field))) {
      auto px = renderer->read_frame(*f);
      char name[64];
      std::snprintf(name, sizeof name, "/field_%06llu_frame_%06llu.png", static_cast<unsigned long long>(field),
                    static_cast<unsigned long long>(frames));
      if (gfx::write_png_rgba(capture_dir + name, f->width, f->height, px.data())) ++captures;
      last_capture_serial = f->serial;
    }
    if (field >= max_fields) throw StopRun{"ran " + std::to_string(max_fields) + " VI fields (--fields)"};
  }
};
Play* g_play = nullptr;

void frame_hook(ppc::Cpu&, std::uint64_t frame) {
  g_play->frames = frame;
  if (frame >= g_play->max_frames) throw StopRun{"ran " + std::to_string(frame) + " frames (--frames)"};
}

// --trace-entry ADDR[,ADDR...] (debugging): at each translated entry of those
// functions, one line with the VI field, LR, MSR and r3-r8, then 128 bytes at r3
// and at r4, the words at r3 + each --trace-peek offset, r13 and the GQRs, to
// --trace-file (default stdout). Read-only.
struct EntryTrace {
  std::set<std::uint32_t> addrs;
  std::vector<std::uint32_t> peeks;
  std::FILE* f = stdout;
  const std::uint64_t* field = nullptr;
  std::uint64_t from = 0, to = ~0ull;
  std::uint64_t max_lines = 100000, lines = 0;
};
EntryTrace g_trace;

std::vector<std::uint32_t> parse_hex_list(const std::string& s) {
  std::vector<std::uint32_t> v;
  for (std::size_t at = 0; at < s.size();) {
    std::size_t comma = s.find(',', at);
    if (comma == std::string::npos) comma = s.size();
    v.push_back(static_cast<std::uint32_t>(std::strtoul(s.substr(at, comma - at).c_str(), nullptr, 16)));
    at = comma + 1;
  }
  return v;
}

void trace_hook(ppc::Cpu& c, std::uint32_t address) {
  if (!g_trace.addrs.count(address) || *g_trace.field < g_trace.from || *g_trace.field > g_trace.to) return;
  if (g_trace.lines++ >= g_trace.max_lines) return;
  std::fprintf(g_trace.f, "field %llu entry %08X lr %08X msr %08X r3 %08X r4 %08X r5 %08X r6 %08X r7 %08X r8 %08X\n",
               static_cast<unsigned long long>(*g_trace.field), address, c.lr, c.msr, c.gpr[3], c.gpr[4], c.gpr[5],
               c.gpr[6], c.gpr[7], c.gpr[8]);
  auto byte = [&](std::uint32_t a) -> unsigned {
    const std::uint8_t* p = c.mem->host(a);
    return p ? *p : 0u;
  };
  for (int r = 3; r <= 4; ++r) {
    std::fprintf(g_trace.f, "  [r%d]", r);
    for (std::uint32_t k = 0; k < 128; ++k) std::fprintf(g_trace.f, k % 32 == 0 ? "\n   %02X" : " %02X", byte(c.gpr[r] + k));
    std::fprintf(g_trace.f, "\n");
  }
  for (std::uint32_t off : g_trace.peeks) {
    const std::uint32_t a = c.gpr[3] + off;
    std::fprintf(g_trace.f, "  [r3+%X] %02X%02X%02X%02X\n", off, byte(a), byte(a + 1), byte(a + 2), byte(a + 3));
  }
  std::fprintf(g_trace.f, "  r13 %08X gqr", c.gpr[13]);
  for (int q = 0; q < 8; ++q) std::fprintf(g_trace.f, " %08X", c.spr[ppc::spr::GQR0 + q]);
  std::fprintf(g_trace.f, "\n");
}

// --profile N: a host thread samples the guest PC (c.pc, stored before every
// translated instruction) at the host timer's pace (a sleep of 1 ms: about 15 ms
// on Windows) and prints the N functions with the most samples. Read-only: a
// racy read of one u32 the guest never sees.
struct GuestProfiler {
  std::atomic<bool> stop{false};
  std::thread thread;
  std::map<std::uint32_t, std::uint64_t> pcs;
  std::uint64_t samples = 0;
  // Samples from VI field `from` on (--profile-from).
  void start(const ppc::Cpu* cpu, const std::uint64_t* field, std::uint64_t from) {
    thread = std::thread([this, cpu, field, from] {
      while (!stop.load(std::memory_order_relaxed)) {
        if (reinterpret_cast<const volatile std::uint64_t&>(*field) >= from) {
          const std::uint32_t pc = reinterpret_cast<const volatile std::uint32_t&>(cpu->pc);
          ++pcs[pc];
          ++samples;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
      }
    });
  }
  void finish(const xlat::SymbolTable& syms, int top) {
    stop = true;
    if (thread.joinable()) thread.join();
    std::map<std::string, std::uint64_t> by_fn;
    for (const auto& [pc, n] : pcs) {
      const xlat::Symbol* f = syms.function_containing(pc);
      char b[32];
      std::snprintf(b, sizeof b, "?%08X", pc & ~0xFFFu);
      by_fn[f ? f->name : std::string(b)] += n;
    }
    std::vector<std::pair<std::uint64_t, std::string>> v;
    for (const auto& [name, n] : by_fn) v.push_back({n, name});
    std::sort(v.rbegin(), v.rend());
    std::printf("profile: %llu samples\n", static_cast<unsigned long long>(samples));
    for (int k = 0; k < top && k < static_cast<int>(v.size()); ++k) {
      const auto& [n, name] = v[static_cast<std::size_t>(k)];
      std::printf("  %6.2f%%  %s\n", samples ? 100.0 * static_cast<double>(n) / static_cast<double>(samples) : 0.0,
                  name.c_str());
    }
  }
};

}  // namespace

int main(int argc, char** argv) {
  std::setvbuf(stdout, nullptr, _IOLBF, 1 << 16);
  std::string input_path, capture_at, draw_log_path;
  std::uint64_t draw_log_from = 0, draw_log_to = ~0ull, dump_field = ~0ull, dump_to = 0;
  std::string dump_dir, audio_wav;
  bool no_audio = false;
  std::uint32_t audio_latency = 100;
  std::uint64_t max_ticks = ~0ull;
  u32 ports = 1;
  bool headless = false, no_render = false, yield = false;
  int profile_top = 0, host_profile_top = 0;
  std::uint64_t profile_from = 0;
  std::string trace_entry, trace_file;
  std::vector<std::string> packs;
  Play play;
  for (int k = 1; k < argc; ++k) {
    std::string a = argv[k];
    auto next = [&]() -> std::string { return k + 1 < argc ? argv[++k] : std::string(); };
    if (a == "--input") input_path = next();
    else if (a == "--ports") ports = static_cast<u32>(std::strtoul(next().c_str(), nullptr, 0)) & 0xF;
    else if (a == "--frames") play.max_frames = std::strtoull(next().c_str(), nullptr, 10);
    else if (a == "--fields") play.max_fields = std::strtoull(next().c_str(), nullptr, 10);
    else if (a == "--max-ticks") max_ticks = std::strtoull(next().c_str(), nullptr, 10);
    else if (a == "--headless") headless = true;
    else if (a == "--no-render") no_render = headless = true;
    else if (a == "--yield") yield = true;
    else if (a == "--present-every") play.present_every = std::max<std::uint64_t>(1, std::strtoull(next().c_str(), nullptr, 10));
    else if (a == "--capture") play.capture_dir = next();
    else if (a == "--capture-every") play.capture_every = std::max<std::uint64_t>(1, std::strtoull(next().c_str(), nullptr, 10));
    else if (a == "--capture-at") capture_at = next();
    else if (a == "--capture-from") play.capture_from = std::strtoull(next().c_str(), nullptr, 10);
    else if (a == "--draw-log") draw_log_path = next();
    else if (a == "--draw-log-from") draw_log_from = std::strtoull(next().c_str(), nullptr, 10);
    else if (a == "--draw-log-to") draw_log_to = std::strtoull(next().c_str(), nullptr, 10);
    else if (a == "--dump-textures") dump_dir = next();
    else if (a == "--dump-field") dump_field = std::strtoull(next().c_str(), nullptr, 10);
    else if (a == "--dump-to") dump_to = std::strtoull(next().c_str(), nullptr, 10);
    else if (a == "--perf-every") play.perf_every = std::strtoull(next().c_str(), nullptr, 10);
    else if (a == "--profile") profile_top = std::atoi(next().c_str());
    else if (a == "--profile-from") profile_from = std::strtoull(next().c_str(), nullptr, 10);
    else if (a == "--host-profile") host_profile_top = std::atoi(next().c_str());
    else if (a == "--trace-entry") trace_entry = next();
    else if (a == "--trace-file") trace_file = next();
    else if (a == "--trace-from") g_trace.from = std::strtoull(next().c_str(), nullptr, 10);
    else if (a == "--trace-to") g_trace.to = std::strtoull(next().c_str(), nullptr, 10);
    else if (a == "--trace-peek") g_trace.peeks = parse_hex_list(next());
    else if (a == "--audio-wav") audio_wav = next();
    else if (a == "--no-audio") no_audio = true;
    else if (a == "--audio-latency") audio_latency = static_cast<std::uint32_t>(std::strtoul(next().c_str(), nullptr, 10));
    else if (a == "--pack") packs.push_back(next());
    else {
      std::fprintf(stderr,
                   "usage: mvp-play [--input SCRIPT] [--ports MASK] [--frames N] [--fields N] [--max-ticks N] "
                   "[--headless] [--no-render] [--yield] [--present-every N] [--capture DIR] [--capture-every N] [--capture-from N] [--capture-at F1,F2,...] "
                   "[--draw-log FILE] [--draw-log-from N] [--draw-log-to N] [--dump-textures DIR --dump-field N [--dump-to M]] "
                   "[--perf-every N] [--profile N] [--host-profile N] [--profile-from F] [--trace-entry HEX,... [--trace-file F] [--trace-from N] "
                   "[--trace-to N] [--trace-peek HEX,...]] [--audio-wav FILE] [--no-audio] [--audio-latency MS] [--pack PATH]...\n");
      return 2;
    }
  }
  for (std::size_t at = 0; at < capture_at.size();) {
    std::size_t comma = capture_at.find(',', at);
    if (comma == std::string::npos) comma = capture_at.size();
    play.capture_at.insert(std::strtoull(capture_at.substr(at, comma - at).c_str(), nullptr, 10));
    at = comma + 1;
  }

  std::string err;
  auto in = xlat::load_inputs(xlat::default_disc_path(), xlat::default_symbols_path(), &err);
  if (!in) {
    std::fprintf(stderr, "mvp-play: %s\n", err.c_str());
    return 77;
  }
  if (!packs.empty()) {  // E6: roster packs on the virtual disc, before boot
    std::string log;
    const auto mounted = mods::mount_pack_paths(in->disc, packs, &log);
    std::printf("%s", log.c_str());
    if (!mounted.ok) {
      std::fprintf(stderr, "mvp-play: the roster packs cannot be used\n");
      return 1;
    }
  }
  std::string script_text = "mvp-input 1\n";
  if (!input_path.empty()) {
    auto text = read_text(input_path);
    if (!text) {
      std::fprintf(stderr, "mvp-play: cannot read %s\n", input_path.c_str());
      return 2;
    }
    script_text = *text;
  }
  FrameInput boot_input = neutral_input(ports);
  auto script = InputScript::parse(script_text, &err, boot_input);
  if (!script) {
    std::fprintf(stderr, "mvp-play: %s: %s\n", input_path.c_str(), err.c_str());
    return 2;
  }
  InputQueue input(boot_input);
  input.set_source(&*script);

  // Renderer.
  std::unique_ptr<gfx::Window> window;
  if (!headless) {
    window = gfx::Window::open("MVP Baseball 2005 (mvp-play)", 1280, 960, &err);
    if (!window) {
      std::fprintf(stderr, "mvp-play: %s\n", err.c_str());
      return 1;
    }
  }
  std::unique_ptr<gfx::Gpu> gpu;
  if (!no_render) {
    gpu = gfx::Gpu::create(&err);
    if (!gpu) {
      std::fprintf(stderr, "mvp-play: %s\n", err.c_str());
      return 1;
    }
    std::printf("gpu: %s\n", gpu->adapter_name().c_str());
  }
  if (window && !window->attach(*gpu, &err)) {
    std::fprintf(stderr, "mvp-play: %s\n", err.c_str());
    return 1;
  }

  Machine m;
  m.load_dol(in->disc.dol);
  setup_boot_environment(m, in->disc);
  Hardware hw(&m.cpu(), m.mem1(), Machine::kMem1Size);
  hw.set_disc(in->disc.image.get());
  YieldingHooks hooks(&m, &hw);
  m.memory().io = &hw;
  m.cpu().hooks = &hooks;
  hooks.tick_limit = max_ticks;
  hooks.reschedule(m.cpu());
  mvp_register_game();

  std::unique_ptr<gfx::Renderer> renderer_owner;
  if (gpu) renderer_owner = std::make_unique<gfx::Renderer>(*gpu, m.mem1(), Machine::kMem1Size);
  gfx::Renderer* renderer = renderer_owner.get();
  DrawLog draw_log;
  draw_log.next = renderer;
  draw_log.field = &play.fields;
  draw_log.from = draw_log_from;
  draw_log.to = draw_log_to;
  draw_log.mem = m.mem1();
  draw_log.mem_size = Machine::kMem1Size;
  draw_log.dump_dir = dump_dir;
  draw_log.dump_field = dump_field;
  draw_log.dump_to = dump_to;
  if (!draw_log_path.empty()) draw_log.f = std::fopen(draw_log_path.c_str(), "w");
  const bool wrap = draw_log.f || !dump_dir.empty();
  gfx::GxProcessor proc(wrap ? static_cast<gfx::Backend*>(&draw_log) : renderer);
  draw_log.proc = &proc;
  proc.set_keep_primitive_info(draw_log.f != nullptr);
  proc.set_memory(m.mem1(), Machine::kMem1Size);
  play.proc = &proc;
  play.renderer = renderer;
  play.window = window.get();
  if (yield) play.yield_hooks = &hooks;
  if (!renderer) play.proc = nullptr;
  hw.set_gfx_observer(&play);
  g_play = &play;

  // Audio (E3b): the mixer observes the DSP's frames; it feeds a WAV, a level
  // meter and, with a window, SDL3 playback.
  audio::AxMixer mixer;
  audio::TeeSink tee;
  audio::WavWriter wav;
  audio::LevelMeter levels;
  std::unique_ptr<audio::SdlAudioOut> audio_out;
  if (!audio_wav.empty()) {
    if (!wav.open(audio_wav)) {
      std::fprintf(stderr, "mvp-play: cannot write %s\n", audio_wav.c_str());
      return 2;
    }
    tee.add(&wav);
  }
  if (window && !no_audio) {
    audio_out = audio::SdlAudioOut::open(audio::kDspRate, audio_latency, &err);
    if (audio_out) {
      std::printf("audio: SDL %s, device \"%s\" at %u Hz, %u ms buffer\n", audio_out->driver().c_str(),
                  audio_out->device().c_str(), audio_out->device_rate(), audio_latency);
      tee.add(audio_out.get());
      play.audio_out = audio_out.get();
    } else {
      std::fprintf(stderr, "mvp-play: no audio: %s\n", err.c_str());
    }
  }
  if (!audio_wav.empty() || audio_out) {
    tee.add(&levels);
    mixer.set_sink(&tee);
    mixer.set_rate([&hw] { return hw.ai_dsp_rate(); });
    hw.set_ax_observer(&mixer);
  }
  rt::g_input = &input;
  rt::g_frame_hook = &frame_hook;
  if (!trace_entry.empty()) {
    for (std::uint32_t a : parse_hex_list(trace_entry)) g_trace.addrs.insert(a);
    if (!trace_file.empty()) g_trace.f = std::fopen(trace_file.c_str(), "w");
    if (!g_trace.f) g_trace.f = stdout;
    g_trace.field = &play.fields;
    rt::g_entry_hook = &trace_hook;
  }

  const auto t0 = std::chrono::steady_clock::now();
  play.t0 = t0;
  play.hooks = &hooks;
  play.cpu = &m.cpu();
  std::string why;
  int rc = 0;
  GuestProfiler profiler;
  if (profile_top > 0) profiler.start(&m.cpu(), &play.fields, profile_from);
  tools::HostProfiler host_profiler;
  if (host_profile_top > 0) host_profiler.start(&play.fields, profile_from);
  try {
    for (;;) rt::run(m.cpu());  // returns at each VI field with --yield
  } catch (const StopRun& s) {
    why = s.why;
  } catch (const ppc::GuestFault& f) {
    why = std::string("guest fault: ") + f.what();
    rc = 1;
  }
  const double secs = std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
  if (profile_top > 0) profiler.finish(in->symbols, profile_top);
  if (host_profile_top > 0) host_profiler.finish(host_profile_top);
  hw.set_gfx_observer(nullptr);
  hw.set_ax_observer(nullptr);
  rt::g_input = nullptr;
  rt::g_frame_hook = nullptr;
  rt::g_entry_hook = nullptr;
  if (g_trace.f && g_trace.f != stdout) std::fclose(g_trace.f);
  if (renderer) {
    renderer->flush();
    gpu->wait_idle();
  }
  if (draw_log.f) std::fclose(draw_log.f);

  auto ull = [](std::uint64_t v) { return static_cast<unsigned long long>(v); };
  const double guest = static_cast<double>(hooks.time_base(m.cpu())) / 40500000.0;
  std::printf("stopped: %s\n", why.c_str());
  {
    Sha1 mem;
    mem.update(m.mem1(), Machine::kMem1Size);
    std::printf("guest: %llu instructions, time base %llu, %llu frame polls, MEM1 sha1 %s\n", ull(m.cpu().ticks),
                ull(hooks.time_base(m.cpu())), ull(rt::g_frame_polls), Sha1::hex(mem.finish()).c_str());
  }
  if (yield)
    std::printf("yield: %llu host yields, %llu repeated safe points skipped\n", ull(hooks.yields),
                ull(hooks.repeats_skipped));
  std::printf("time: %.3f s of guest time in %.1f s (%.2fx real time); %llu VI fields, %llu frame polls\n", guest, secs,
              secs > 0 ? guest / secs : 0.0, ull(hw.vi_fields()), ull(play.frames));
  std::printf("runtime: %llu unwinds, %llu in-frame resumes, %llu resume entries; %llu external and %llu decrementer "
              "interrupts, %llu floating-point unavailable; idle skips %llu (%llu instructions skipped); interpreted %llu "
              "instructions\n",
              ull(rt::g_unwinds), ull(rt::g_inframe_resumes), ull(rt::g_resume_entries), ull(hooks.external_interrupts),
              ull(hooks.decrementer_interrupts), ull(hooks.fp_unavailable), ull(hooks.idle_skips),
              ull(hooks.idle_ticks_skipped), ull(rt::g_interpreted));
  if (!audio_wav.empty() || audio_out) {
    const audio::MixerStats& ms = mixer.stats();
    std::printf("audio: %llu frames mixed (%u Hz), %llu voice-ms, at most %u voices, aux A returns in %llu frames; %s\n",
                ull(ms.frames), hw.ai_dsp_rate(), ull(ms.voice_ms), ms.max_voices, ull(ms.aux_return_frames[0]),
                levels.summary().c_str());
    if (!audio_wav.empty()) std::printf("audio: WAV %s%s\n", audio_wav.c_str(), wav.close() ? "" : " (WRITE FAILED)");
    if (audio_out) {
      audio_out->close();
      const audio::SdlAudioOut::Stats as = audio_out->stats();
      std::printf("audio: played %llu frames (%llu non-silent, peak %d), %llu silent, %llu underruns, %llu skipped, "
                  "%llu dropped (ring full), ratio %.4f..%.4f, throttled %llu ms\n",
                  ull(as.drift.out_frames), ull(as.played_nonsilent), as.played_peak, ull(as.drift.silent_frames),
                  ull(as.drift.underruns), ull(as.drift.skipped_frames), ull(as.ring_full), as.drift.min_ratio,
                  as.drift.max_ratio, ull(as.throttle_waits));
    }
  }
  if (!renderer) return rc;
  const auto& ps = proc.stats();
  std::printf("gx: %llu commands, %llu draws, %llu vertices, %llu triangles, %llu EFB copies (%llu to the XFB), "
              "%llu TLUT loads, %llu unknown; %llu state snapshots\n",
              ull(ps.commands), ull(ps.draws), ull(ps.vertices), ull(ps.triangles), ull(ps.copies), ull(ps.xfb_copies),
              ull(ps.tlut_loads), ull(ps.unknown), ull(ps.snapshots));
  const auto& rs = renderer->stats();
  std::printf("renderer: %llu draws (%llu skipped, %llu merged into the one before; %llu encoded), %llu passes, "
              "%llu pipelines, %llu textures decoded, %llu hits, "
              "%llu EFB-copy textures used, %llu texture copies, %llu clears; %llu unknown formats, "
              "%llu indirect draws, %llu fog draws; %llu with the previous draw's state; uploaded %.1f MB of vertices, "
              "%.1f MB of indices\n",
              ull(rs.draws), ull(rs.skipped), ull(rs.merged), ull(rs.encoded), ull(rs.passes), ull(rs.pipelines),
              ull(rs.textures_decoded), ull(rs.texture_hits), ull(rs.copy_textures_used), ull(rs.tex_copies),
              ull(rs.clears), ull(rs.unknown_formats), ull(rs.indirect_draws), ull(rs.fog_draws), ull(rs.same_state),
              static_cast<double>(rs.vertex_bytes) / 1e6, static_cast<double>(rs.index_bytes) / 1e6);
  std::printf("display: %llu presents, %llu captures%s%s; WebGPU errors %llu\n", ull(play.presents), ull(play.captures),
              play.capture_dir.empty() ? "" : " in ", play.capture_dir.c_str(), ull(gpu->errors()));
  if (gpu->errors() || ps.xfb_copies == 0) rc = 1;
  return rc;
}
