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
//   --present-every N show every Nth VI field (default 1)
//   --capture DIR     write the scanned-out frame as DIR/field_NNNNNN.png every
//                     --capture-every N fields (default 60) and at the --capture-at
//                     fields; only frames that changed since the last capture
//   --draw-log FILE   one line per draw and EFB copy (state, textures) from VI field
//                     --draw-log-from N (default 0) to --draw-log-to N
//
// Determinism: the renderer only reads guest state, and window events never
// reach the guest; with the same input script, the guest runs exactly as under
// mvp-boot. Captures are game-derived: they belong under build/ and are never
// committed.
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <string>

#include "common/file.h"
#include "gfx/gx_processor.h"
#include "gfx/png.h"
#include "gfx/wgpu/gpu.h"
#include "gfx/wgpu/renderer.h"
#include "gfx/wgpu/window.h"
#include "runtime/boot.h"
#include "runtime/hle.h"
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
  std::uint64_t from = 0, to = ~0ull;
  bool on() const { return f && *field >= from && *field <= to; }
  void draw(const gfx::DrawCall& d) override {
    if (on()) {
      const gfx::PipelineConfig& c = d.cfg;
      std::fprintf(f, "field %llu draw %zu verts topo %u stages %u texgens %u chans %u ind %u blend %u/%u/%u/%u z %u/%u/%u "
                   "cull %u fmt %u acmp %u/%u/%u ref %d/%d logic %u/%u fog %u scissor %u,%u-%u,%u\n",
                   static_cast<unsigned long long>(*field), d.verts.size(), c.topology, c.num_stages, c.num_texgens,
                   c.num_chans, c.num_ind, c.blend_enable, c.blend_src, c.blend_dst, c.blend_sub, c.z_enable, c.z_func,
                   c.z_update, c.cull, c.pixel_format, c.alpha_comp0, c.alpha_comp1, c.alpha_logic, d.u.alpha_ref[0],
                   d.u.alpha_ref[1], c.logic_enable, c.logic_op, c.fog_type, d.scissor[0], d.scissor[1], d.scissor[2],
                   d.scissor[3]);
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
  gfx::GxProcessor* proc = nullptr;
  gfx::Renderer* renderer = nullptr;
  gfx::Window* window = nullptr;
  std::uint64_t present_every = 1, max_fields = ~0ull;
  std::string capture_dir;
  std::uint64_t capture_every = 60;
  std::set<std::uint64_t> capture_at;
  std::uint64_t last_capture_serial = 0, captures = 0, fields = 0, presents = 0;
  std::uint64_t frames = 0, max_frames = ~0ull;

  void gx_command(const std::uint8_t* cmd, std::size_t len) override { proc->command(cmd, len); }

  void vi_field(std::uint64_t field, std::uint32_t xfb) override {
    fields = field;
    renderer->flush();
    const gfx::Renderer::Frame* f = renderer->xfb(xfb);
    if (!f) f = renderer->latest_xfb();
    if (window && field % present_every == 0) {
      if (!window->pump()) throw StopRun{"window closed"};
      if (f) {
        window->present(f->view, f->width, f->height);
        ++presents;
      }
    }
    if (!capture_dir.empty() && f && f->serial != last_capture_serial &&
        (field % capture_every == 0 || capture_at.count(field))) {
      auto px = renderer->read_frame(*f);
      char name[64];
      std::snprintf(name, sizeof name, "/field_%06llu.png", static_cast<unsigned long long>(field));
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

}  // namespace

int main(int argc, char** argv) {
  std::setvbuf(stdout, nullptr, _IOLBF, 1 << 16);
  std::string input_path, capture_at, draw_log_path;
  std::uint64_t draw_log_from = 0, draw_log_to = ~0ull;
  std::uint64_t max_ticks = ~0ull;
  u32 ports = 1;
  bool headless = false;
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
    else if (a == "--present-every") play.present_every = std::max<std::uint64_t>(1, std::strtoull(next().c_str(), nullptr, 10));
    else if (a == "--capture") play.capture_dir = next();
    else if (a == "--capture-every") play.capture_every = std::max<std::uint64_t>(1, std::strtoull(next().c_str(), nullptr, 10));
    else if (a == "--capture-at") capture_at = next();
    else if (a == "--draw-log") draw_log_path = next();
    else if (a == "--draw-log-from") draw_log_from = std::strtoull(next().c_str(), nullptr, 10);
    else if (a == "--draw-log-to") draw_log_to = std::strtoull(next().c_str(), nullptr, 10);
    else {
      std::fprintf(stderr,
                   "usage: mvp-play [--input SCRIPT] [--ports MASK] [--frames N] [--fields N] [--max-ticks N] "
                   "[--headless] [--present-every N] [--capture DIR] [--capture-every N] [--capture-at F1,F2,...]\n");
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
  auto gpu = gfx::Gpu::create(&err);
  if (!gpu) {
    std::fprintf(stderr, "mvp-play: %s\n", err.c_str());
    return 1;
  }
  std::printf("gpu: %s\n", gpu->adapter_name().c_str());
  if (window && !window->attach(*gpu, &err)) {
    std::fprintf(stderr, "mvp-play: %s\n", err.c_str());
    return 1;
  }

  Machine m;
  m.load_dol(in->disc.dol);
  setup_boot_environment(m, in->disc);
  Hardware hw(&m.cpu(), m.mem1(), Machine::kMem1Size);
  hw.set_disc(in->disc.image.get());
  SystemHooks hooks(&m, &hw);
  m.memory().io = &hw;
  m.cpu().hooks = &hooks;
  hooks.tick_limit = max_ticks;
  hooks.reschedule(m.cpu());
  mvp_register_game();

  gfx::Renderer renderer(*gpu, m.mem1(), Machine::kMem1Size);
  DrawLog draw_log;
  draw_log.next = &renderer;
  draw_log.field = &play.fields;
  draw_log.from = draw_log_from;
  draw_log.to = draw_log_to;
  if (!draw_log_path.empty()) draw_log.f = std::fopen(draw_log_path.c_str(), "w");
  gfx::GxProcessor proc(draw_log.f ? static_cast<gfx::Backend*>(&draw_log) : &renderer);
  proc.set_memory(m.mem1(), Machine::kMem1Size);
  play.proc = &proc;
  play.renderer = &renderer;
  play.window = window.get();
  hw.set_gfx_observer(&play);
  g_play = &play;
  rt::g_input = &input;
  rt::g_frame_hook = &frame_hook;

  const auto t0 = std::chrono::steady_clock::now();
  std::string why;
  int rc = 0;
  try {
    rt::run(m.cpu());
  } catch (const StopRun& s) {
    why = s.why;
  } catch (const ppc::GuestFault& f) {
    why = std::string("guest fault: ") + f.what();
    rc = 1;
  }
  const double secs = std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
  hw.set_gfx_observer(nullptr);
  rt::g_input = nullptr;
  rt::g_frame_hook = nullptr;
  renderer.flush();
  gpu->wait_idle();
  if (draw_log.f) std::fclose(draw_log.f);

  auto ull = [](std::uint64_t v) { return static_cast<unsigned long long>(v); };
  const double guest = static_cast<double>(hooks.time_base(m.cpu())) / 40500000.0;
  std::printf("stopped: %s\n", why.c_str());
  std::printf("time: %.3f s of guest time in %.1f s (%.2fx real time); %llu VI fields, %llu frame polls\n", guest, secs,
              secs > 0 ? guest / secs : 0.0, ull(hw.vi_fields()), ull(play.frames));
  const auto& ps = proc.stats();
  std::printf("gx: %llu commands, %llu draws, %llu vertices, %llu triangles, %llu EFB copies (%llu to the XFB), "
              "%llu TLUT loads, %llu unknown\n",
              ull(ps.commands), ull(ps.draws), ull(ps.vertices), ull(ps.triangles), ull(ps.copies), ull(ps.xfb_copies),
              ull(ps.tlut_loads), ull(ps.unknown));
  const auto& rs = renderer.stats();
  std::printf("renderer: %llu draws (%llu skipped), %llu passes, %llu pipelines, %llu textures decoded, %llu hits, "
              "%llu EFB-copy textures used, %llu texture copies, %llu clears; %llu unknown formats, "
              "%llu indirect draws, %llu fog draws\n",
              ull(rs.draws), ull(rs.skipped), ull(rs.passes), ull(rs.pipelines), ull(rs.textures_decoded),
              ull(rs.texture_hits), ull(rs.copy_textures_used), ull(rs.tex_copies), ull(rs.clears),
              ull(rs.unknown_formats), ull(rs.indirect_draws), ull(rs.fog_draws));
  std::printf("display: %llu presents, %llu captures%s%s; WebGPU errors %llu\n", ull(play.presents), ull(play.captures),
              play.capture_dir.empty() ? "" : " in ", play.capture_dir.c_str(), ull(gpu->errors()));
  return rc;
}
