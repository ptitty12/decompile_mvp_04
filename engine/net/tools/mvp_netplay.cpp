// mvp-netplay: the retail DOL (translated C++) under lockstep netplay, natively,
// for local tests of engine/net (E5). Two instances on one machine talk over UDP
// on 127.0.0.1; each drives its own controller port from a script, exactly as a
// browser drives it from the player's pad.
//
//   mvp-netplay peer --player 1|2 --port LOCAL --peer-port REMOTE --input SCRIPT
//                    --frames N [--delay D] [--hash-every K] [--log FILE]
//                    [--loss P] [--latency MS] [--jitter MS] [--timeout MS]
//                    [--corrupt-window FRAME] [--diag FILE] [--report FILE]
//       Player P's controller (port P) follows the script's port-P events: the
//       state sampled at frame f becomes the input of frame f + D (the session's
//       delay rule); the other port comes from the peer. --loss/--latency/--jitter
//       impair this side's outgoing datagrams.
//   mvp-netplay solo --input SCRIPT --frames N [--delay D] [--hash-every K] [--log FILE]
//       The reference: no network; ports 1 and 2 follow the script shifted by D
//       frames, i.e. exactly the inputs two peers must agree on.
//
// The run loop is the browser's (engine/web): rt::run() returns at every VI
// field (runtime/host_yield.h) and early when the next frame's input is not
// known; the loop runs the guest only while net::NetplayDriver::may_run() says
// so. Both modes write the frame log (one line per frame poll: frame,
// instructions, time base, input in wire form) and print its SHA-1, the state
// hash of every window and the final guest line (instructions, time base,
// frame polls, MEM1 SHA-1). Two peers and the solo run of the same script must
// print the same three.
//
// Needs the disc (MVP_DISC) and a build with the translated code. The logs hold
// numbers and controller states only; keep them under build/ anyway.
#include <chrono>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <string>
#include <thread>

#include "common/file.h"
#include "common/sha1.h"
#include "net/driver.h"
#include "net/identity.h"
#include "net/session.h"
#include "net/state_hash.h"
#include "net/udp.h"
#include "runtime/boot.h"
#include "runtime/gx_fifo.h"
#include "runtime/hle.h"
#include "runtime/host_yield.h"
#include "runtime/hw.h"
#include "runtime/input.h"
#include "translator/program.h"

void mvp_register_game();

using namespace mvp;
using namespace mvp::rt;

namespace {

using ull = unsigned long long;

// The report: stdout, and the --report file.
std::string g_report_text;
void say(const char* fmt, ...) {
  char b[1024];
  va_list ap;
  va_start(ap, fmt);
  int n = std::vsnprintf(b, sizeof b, fmt, ap);
  va_end(ap);
  if (n < 0) return;
  std::string line(b, static_cast<std::size_t>(std::min(n, static_cast<int>(sizeof b) - 1)));
  std::fputs(line.c_str(), stdout);
  g_report_text += line;
}

struct Args {
  std::string mode, input, log = "netplay-frames.log", diag, report;
  int player = 1;
  unsigned port = 0, peer_port = 0;
  std::uint64_t frames = 600, corrupt = ~0ull;
  std::uint32_t delay = 3, hash_every = 60, latency = 0, jitter = 0, timeout = 15000;
  double loss = 0;
};

// The yield at every VI field (as the browser's renderer observer asks for it).
struct FieldYield : GfxObserver {
  YieldingHooks* hooks = nullptr;
  void gx_command(const std::uint8_t*, std::size_t) override {}
  void vi_field(std::uint64_t, std::uint32_t) override { hooks->request_yield(); }
};

// solo: the script shifted by the delay, ports 1 and 2 always connected.
struct ShiftedScript : InputSource {
  InputScript* script = nullptr;
  std::uint32_t delay = 0;
  FrameInput input_for(std::uint64_t frame) override {
    FrameInput in = neutral_input(net::kNetplayPorts);
    if (frame < delay) return in;
    FrameInput s = script->input_for(frame - delay);
    for (int k = 0; k < 2; ++k) {
      in.pad[k] = s.pad[k];
      in.pad[k].connected = true;
    }
    return in;
  }
};

struct Run {
  Machine* m = nullptr;
  SystemHooks* hooks = nullptr;
  InputQueue* queue = nullptr;
  net::NetplayDriver* driver = nullptr;  // peer mode
  net::StateHasher* hasher = nullptr;    // solo mode
  std::vector<net::HashRecord> solo_windows;
  std::uint64_t stop_at = 0;
  std::FILE* log = nullptr;
  Sha1 log_sha;
  std::uint64_t log_bytes = 0;
};
Run* g_run = nullptr;

void frame_hook(ppc::Cpu& c, std::uint64_t frame) {
  Run& r = *g_run;
  if (frame >= r.stop_at) throw StopRun{"ran " + std::to_string(r.stop_at) + " frames"};
  char b[128];
  int n = std::snprintf(b, sizeof b, "frame %llu ticks %llu tb %llu in ", static_cast<ull>(frame),
                        static_cast<ull>(c.ticks), static_cast<ull>(r.hooks->time_base(c)));
  std::string line(b, static_cast<std::size_t>(n));
  for (u8 v : encode_frame(r.queue->current())) {
    std::snprintf(b, sizeof b, "%02x", v);
    line += b;
  }
  line += '\n';
  r.log_sha.update(line.data(), line.size());
  r.log_bytes += line.size();
  if (r.log) std::fwrite(line.data(), 1, line.size(), r.log);
  if (r.driver) {
    r.driver->after_poll(frame);
  } else if (r.hasher) {
    if (auto h = r.hasher->at_frame(frame, r.m->mem1(), Machine::kMem1Size, c.ticks))
      r.solo_windows.push_back({static_cast<std::uint32_t>(frame), *h});
  }
}

std::string windows_sha(const std::vector<net::HashRecord>& w) {
  Sha1 s;
  for (const auto& r : w) {
    char b[48];
    int n = std::snprintf(b, sizeof b, "%u %016llx\n", r.frame, static_cast<ull>(r.hash));
    s.update(b, static_cast<std::size_t>(n));
  }
  return Sha1::hex(s.finish());
}

int run(const xlat::Inputs& in, const Args& a) {
  std::string err;
  auto text = read_text(a.input);
  if (!text) {
    std::fprintf(stderr, "mvp-netplay: cannot read %s\n", a.input.c_str());
    return 2;
  }
  const FrameInput boot_input = neutral_input(net::kNetplayPorts);
  auto script = InputScript::parse(*text, &err, boot_input);
  if (!script) {
    std::fprintf(stderr, "mvp-netplay: %s: %s\n", a.input.c_str(), err.c_str());
    return 2;
  }
  const bool peer = a.mode == "peer";

  Machine m;
  m.load_dol(in.disc.dol);
  BootConfig boot_cfg;
  setup_boot_environment(m, in.disc, boot_cfg);
  HardwareConfig hw_cfg;
  Hardware hw(&m.cpu(), m.mem1(), Machine::kMem1Size, hw_cfg);
  hw.set_disc(in.disc.image.get());
  ClockConfig clk;
  YieldingHooks hooks(&m, &hw, clk);
  m.memory().io = &hw;
  m.cpu().hooks = &hooks;
  hooks.reschedule(m.cpu());
  mvp_register_game();
  FieldYield fy;
  fy.hooks = &hooks;
  hw.set_gfx_observer(&fy);

  InputQueue queue(boot_input);
  Run r;
  r.m = &m;
  r.hooks = &hooks;
  r.queue = &queue;
  r.stop_at = a.frames;
  r.log = std::fopen(a.log.c_str(), "wb");
  g_run = &r;

  // peer: the session over UDP (optionally impaired).
  std::unique_ptr<net::UdpTransport> udp;
  std::unique_ptr<net::ImpairedTransport> impaired;
  std::unique_ptr<net::Session> session;
  std::unique_ptr<net::NetplayDriver> driver;
  ShiftedScript shifted;
  net::StateHasher solo_hasher(a.hash_every ? a.hash_every : 1);
  const std::uint64_t t_start = net::host_ms();
  if (peer) {
    udp = net::UdpTransport::open("127.0.0.1", static_cast<std::uint16_t>(a.port), &err);
    if (!udp || !udp->set_peer("127.0.0.1", static_cast<std::uint16_t>(a.peer_port), &err)) {
      std::fprintf(stderr, "mvp-netplay: udp: %s\n", err.c_str());
      return 2;
    }
    net::Transport* t = udp.get();
    if (a.loss > 0 || a.latency || a.jitter) {
      impaired = std::make_unique<net::ImpairedTransport>(
          *udp, net::ImpairedTransport::Params{a.latency, a.jitter, a.loss, 1000u + static_cast<unsigned>(a.player)});
      t = impaired.get();
    }
    net::SessionConfig cfg;
    cfg.player = a.player;
    cfg.delay = a.delay;
    cfg.hash_interval = a.hash_every;
    cfg.timeout_ms = a.timeout;
    cfg.nonce = (static_cast<std::uint64_t>(a.player) << 32) ^ t_start;
    cfg.id = net::make_identity("native-mvp-netplay", in.disc, hw_cfg, boot_cfg, clk, net::kNetplayPorts);
    InputScript* sc = &*script;
    const int port = a.player - 1;
    session = std::make_unique<net::Session>(*t, cfg, [sc, port](std::uint64_t f) { return sc->input_for(f).pad[port]; });
    driver = std::make_unique<net::NetplayDriver>(*session, *t, m, &hooks, &net::host_ms);
    driver->corrupt_window_at = a.corrupt;
    queue.set_source(driver.get());
    r.driver = driver.get();
    // The handshake before power-on.
    while (!session->running() && !session->ended()) {
      session->update(net::host_ms());
      t->wait(5);
    }
    if (!session->running()) {
      say("netplay: %s: %s\n", net::state_name(session->state()), session->reason().c_str());
      return 1;
    }
    say("netplay: player %d, delay %u (negotiated), hash interval %u, handshake %llu ms\n", a.player,
                session->delay(), a.hash_every, static_cast<ull>(net::host_ms() - t_start));
  } else {
    shifted.script = &*script;
    shifted.delay = a.delay;
    queue.set_source(&shifted);
    r.hasher = a.hash_every ? &solo_hasher : nullptr;
    say("netplay: solo reference, delay %u, hash interval %u\n", a.delay, a.hash_every);
  }
  rt::g_input = &queue;
  rt::g_frame_hook = &frame_hook;

  std::string why;
  int rc = 0;
  const auto t0 = std::chrono::steady_clock::now();
  try {
    for (;;) {
      if (driver && !driver->may_run(net::host_ms())) {
        if (session->ended()) throw StopRun{std::string("netplay: ") + net::state_name(session->state()) + ": " + session->reason()};
        (impaired ? static_cast<net::Transport&>(*impaired) : *udp).wait(1);
        continue;
      }
      rt::run(m.cpu());
    }
  } catch (const StopRun& s) {
    why = s.why;
    rc = s.why.rfind("ran ", 0) == 0 ? 0 : 1;
  } catch (const ppc::GuestFault& f) {
    why = std::string("guest fault: ") + f.what();
    rc = 1;
  }
  const double secs = std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
  rt::g_input = nullptr;
  rt::g_frame_hook = nullptr;
  hw.set_gfx_observer(nullptr);
  if (r.log) std::fclose(r.log);

  if (session) {
    // Keep answering until the peer has run the same frames too (its last
    // inputs may need resending), then say goodbye.
    const std::uint64_t until = net::host_ms() + 10000;
    net::Transport& t = impaired ? static_cast<net::Transport&>(*impaired) : *udp;
    while (rc == 0 && !session->ended() && session->peer_frame() <= a.frames && net::host_ms() < until) {
      session->update(net::host_ms());
      t.wait(2);
    }
    if (rc == 0 && session->peer_frame() <= a.frames) why += "; the peer did not finish";
    session->quit(net::host_ms(), "finished");
  }

  say("stopped: %s\n", why.c_str());
  say("frames: %llu polls; frame log %s, %llu bytes, sha1 %s\n", static_cast<ull>(g_frame_polls),
              a.log.c_str(), static_cast<ull>(r.log_bytes), Sha1::hex(r.log_sha.finish()).c_str());
  const auto& windows = driver ? driver->windows() : r.solo_windows;
  say("windows: %zu state hashes (every %u frames), list sha1 %s, last %016llx\n", windows.size(),
              a.hash_every, windows_sha(windows).c_str(), windows.empty() ? 0ull : static_cast<ull>(windows.back().hash));
  {
    Sha1 mem;
    mem.update(m.mem1(), Machine::kMem1Size);
    say("guest: %llu instructions, time base %llu, %llu frame polls, MEM1 sha1 %s\n", static_cast<ull>(m.cpu().ticks),
                static_cast<ull>(hooks.time_base(m.cpu())), static_cast<ull>(g_frame_polls), Sha1::hex(mem.finish()).c_str());
  }
  if (session) {
    const net::SessionStats& s = session->stats();
    const double wall = static_cast<double>(net::host_ms() - t_start) / 1000.0;
    say("session: %s (%s); %llu hashes compared; sent %llu packets / %llu bytes, received %llu / %llu, "
                "%.0f B/s out; rtt %u..%u ms avg %.1f\n",
                net::state_name(session->state()), session->reason().c_str(), static_cast<ull>(s.hashes_compared),
                static_cast<ull>(s.packets_sent), static_cast<ull>(s.bytes_sent), static_cast<ull>(s.packets_received),
                static_cast<ull>(s.bytes_received), static_cast<double>(s.bytes_sent) / wall, s.rtt_min, s.rtt_max,
                s.rtt_avg());
    say("lockstep: %llu stalls, %llu ms stalled (longest %llu), %llu early yields, %llu gate misses; "
                "%llu yields\n",
                static_cast<ull>(driver->stalls), static_cast<ull>(driver->stall_ms),
                static_cast<ull>(driver->longest_stall_ms), static_cast<ull>(driver->early_yields),
                static_cast<ull>(driver->gate_misses), static_cast<ull>(hooks.yields));
    if (impaired)
      say("impaired: %llu dropped, %llu delayed\n", static_cast<ull>(impaired->dropped),
                  static_cast<ull>(impaired->delayed));
    if (session->state() == net::State::Desynced) rc = 3;
    if (!a.diag.empty() && (rc != 0 || session->mismatch())) {
      const std::string d = driver->diagnostic();
      write_file(a.diag, d.data(), d.size());
      say("diagnostic: %s\n", a.diag.c_str());
    }
  }
  std::fprintf(stderr, "host: %.1f s running the guest\n", secs);
  if (!a.report.empty()) write_file(a.report, g_report_text.data(), g_report_text.size());
  return rc;
}

}  // namespace

int main(int argc, char** argv) {
  std::setvbuf(stdout, nullptr, _IOLBF, 1 << 16);
  Args a;
  a.mode = argc > 1 ? argv[1] : "";
  for (int k = 2; k + 1 < argc; ++k) {
    std::string s = argv[k];
    const char* v = argv[k + 1];
    if (s == "--player") a.player = std::atoi(v);
    if (s == "--port") a.port = static_cast<unsigned>(std::atoi(v));
    if (s == "--peer-port") a.peer_port = static_cast<unsigned>(std::atoi(v));
    if (s == "--input") a.input = v;
    if (s == "--frames") a.frames = std::strtoull(v, nullptr, 10);
    if (s == "--delay") a.delay = static_cast<std::uint32_t>(std::atoi(v));
    if (s == "--hash-every") a.hash_every = static_cast<std::uint32_t>(std::atoi(v));
    if (s == "--log") a.log = v;
    if (s == "--diag") a.diag = v;
    if (s == "--report") a.report = v;
    if (s == "--loss") a.loss = std::atof(v);
    if (s == "--latency") a.latency = static_cast<std::uint32_t>(std::atoi(v));
    if (s == "--jitter") a.jitter = static_cast<std::uint32_t>(std::atoi(v));
    if (s == "--timeout") a.timeout = static_cast<std::uint32_t>(std::atoi(v));
    if (s == "--corrupt-window") a.corrupt = std::strtoull(v, nullptr, 10);
  }
  if ((a.mode != "peer" && a.mode != "solo") || a.input.empty() || (a.mode == "peer" && (!a.port || !a.peer_port))) {
    std::fprintf(stderr,
                 "usage: mvp-netplay peer --player 1|2 --port LOCAL --peer-port REMOTE --input SCRIPT --frames N "
                 "[--delay D] [--hash-every K] [--log FILE] [--loss P] [--latency MS] [--jitter MS] [--timeout MS] "
                 "[--corrupt-window FRAME] [--diag FILE]\n"
                 "       mvp-netplay solo --input SCRIPT --frames N [--delay D] [--hash-every K] [--log FILE]\n");
    return 2;
  }
  std::string err;
  auto in = xlat::load_inputs(xlat::default_disc_path(), xlat::default_symbols_path(), &err);
  if (!in) {
    std::fprintf(stderr, "mvp-netplay: %s\n", err.c_str());
    return 77;
  }
  return run(*in, a);
}
