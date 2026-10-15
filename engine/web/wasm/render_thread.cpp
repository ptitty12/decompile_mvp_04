// The threaded engine's render thread (P2): see render_thread.h.
#include "web/wasm/render_thread.h"

#include <emscripten.h>
#include <emscripten/console.h>
#include <emscripten/proxying.h>
#include <emscripten/threading.h>
#include <pthread.h>

#include <atomic>
#include <cstdio>
#include <cstring>
#include <memory>
#include <mutex>

#include "gfx/render_ring.h"
#include "web/wasm/render_side.h"

// ---- JavaScript glue ----

// On the render thread: take the canvas (or the page's frame port, then a
// canvas of its own of `w` x `h`) when the emulation thread posts it here,
// register it under `sel` (emdawnwebgpu finds canvases there) and tell the
// engine. Messages without a `cmd` are ignored by Emscripten's own handler.
EM_JS(void, mvp_js_render_listen, (const char* sel, int w, int h), {
  var s = UTF8ToString(sel);
  self.addEventListener('message', function(e) {
    var d = e.data;
    if (!d || !d.mvpRender) return;
    Module['specialHTMLTargets'][s] = d.canvas || new OffscreenCanvas(w, h);
    Module['mvpFrames'] = d.frames || null;
    Module['mvpVsync'] = d.vsync || null;
    Module['_mvp_render_canvas']();
  });
});

// On the emulation thread: hand the page's canvas (Module.mvpCanvas) or frame
// port (Module.mvpFrames) to the render thread's Worker. Returns 0 without
// either or without a thread.
EM_JS(int, mvp_js_render_send_canvas, (std::uintptr_t tid), {
  var w = PThread.pthreads[tid];
  var c = Module['mvpCanvas'], f = Module['mvpFrames'];
  if (!w || (!c && !f)) return 0;
  Module['mvpCanvas'] = null;
  Module['mvpFrames'] = null;
  var t = [];
  if (c) t.push(c);
  if (f) t.push(f);
  w.postMessage({ mvpRender: 1, canvas: c || null, frames: f || null, vsync: Module['mvpVsync'] || null }, t);
  return 1;
});

// On the render thread: run the task loop again in a new task, at once (a
// MessageChannel, not setTimeout: nested timeouts are clamped to 4 ms).
EM_JS(void, mvp_js_render_soon, (), {
  var c = Module['mvpRenderChan'];
  if (!c) {
    c = Module['mvpRenderChan'] = new MessageChannel();
    c.port1.onmessage = function() { Module['_mvp_render_task'](); };
  }
  c.port2.postMessage(0);
});

// On the render thread: the display's refresh count. A Worker started by a
// Worker (this pthread) has no requestAnimationFrame, so the page bumps a
// counter in shared memory at each of its animation frames (main.ts) and the
// render thread reads it. -1 without the counter.
EM_JS(int, mvp_js_render_vsync, (), {
  var v = Module['mvpVsyncView'];
  if (!v) {
    var sab = Module['mvpVsync'];
    if (!sab) return -1;
    v = Module['mvpVsyncView'] = new Int32Array(sab);
  }
  return Atomics.load(v, 0) & 0x3FFFFFFF;
});

namespace mvp::web {

namespace {

using u8 = std::uint8_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

// Record types in the ring.
enum : u32 {
  kGx = 1,      // a GX command's bytes
  kGxRef,       // {pointer, length}: a command too large for the ring (the emulation waits until it is done)
  kField,       // {field, xfb}
  kPresent,     // {frame polls}
  kResize,      // {width, height}
  kMemory,      // {pointer, size}: guest memory
  kTrace,       // {on}
  kDigest,      // {on}
  kFlush,
};

constexpr u32 kRingBytes = 16u << 20;
constexpr u32 kPublishBytes = 4u << 10;   // records become visible in batches of this size
constexpr double kSpinMs = 0.2;           // the render thread polls this long before it sleeps
constexpr double kVsyncPollMs = 1.0;      // with a frame due, it looks at the refresh count this often
constexpr double kVsyncStallMs = 50.0;    // a frame due this long shows even if the count did not move

struct Field {
  u64 field;
  u32 xfb, pad;
};
struct Ref {
  const u8* p;
  u32 n;
};
struct Pair {
  u32 a, b;
};

struct Shared {
  gfx::RenderRing ring{kRingBytes};
  pthread_t tid{};
  void (*on_gfx)(int, const char*) = nullptr;
  std::string selector;
  int width = 0, height = 0;

  // Between the threads.
  std::atomic<u32> idle{0};        // the render thread waits in its event loop for a kick
  std::atomic<u32> emu_active{0};  // a run batch is producing records
  std::atomic<int> gfx_state{0};   // 0 starting, 1 ready, 2 failed
  std::atomic<u64> presents{0};
  std::mutex mu;                   // guards the snapshot strings
  std::string trace, digest, status, gfx_message;

  // Render thread only.
  RenderSide side;
  bool have_canvas = false, gpu_done = false;
  bool vsync = false;       // present once per display refresh (the page's count), else after each batch
  int shown_at = -1;        // the refresh count at the last present
  bool frame_due = false;   // a batch ended since the last present
  u64 due_polls = 0;
  double due_at = 0;        // when the frame became due
  u64 tasks = 0, held = 0;  // tasks run; presents held for the next refresh

  // Emulation thread only.
  u32 synced = 0;           // ring position of the last fence
  u32 present_pos[2] = {};  // ring positions after the last two presents
  u64 fences = 0, fence_waits = 0, lag_waits = 0, big = 0, resizes = 0;
  double fence_ms = 0, lag_ms = 0;
};

Shared* S = nullptr;

template <class T>
void put(u32 type, const T& v) {
  std::memcpy(S->ring.reserve(type, sizeof v), &v, sizeof v);
  S->ring.commit();
}

void render_task_cb(void*);

// Emulation thread: wake the render thread if it waits in its event loop (with
// nothing due, between batches).
void kick() {
  if (S->idle.load(std::memory_order_seq_cst) == 1 && S->idle.exchange(0) == 1)
    emscripten_proxy_async(emscripten_proxy_get_system_queue(), S->tid, render_task_cb, nullptr);
}

void publish_and_kick() {
  S->ring.publish();
  kick();
}

bool disabled() { return S->gfx_state.load(std::memory_order_relaxed) == 2; }

std::string json_escape(const std::string& in) {
  std::string o;
  for (char ch : in) {
    if (ch == '"' || ch == '\\') o += '\\', o += ch;
    else if (static_cast<unsigned char>(ch) < 0x20) o += ' ';
    else o += ch;
  }
  return o;
}

// ---- render thread ----

void snapshot() {
  std::string t = S->side.trace_take_raw(), d = S->side.digest_take(), s = S->side.status_json();
  char b[96];
  std::snprintf(b, sizeof b, ",\"render\":{\"tasks\":%llu,\"held\":%llu,\"vsync\":%s}",
                static_cast<unsigned long long>(S->tasks), static_cast<unsigned long long>(S->held),
                S->vsync ? "true" : "false");
  s += b;
  std::lock_guard<std::mutex> lock(S->mu);
  S->trace += t;
  S->digest += d;
  S->status = std::move(s);
}

// Runs on the emulation thread: the renderer is ready (or failed).
void gfx_done_main(void*) {
  std::string msg;
  {
    std::lock_guard<std::mutex> lock(S->mu);
    msg = S->gfx_message;
  }
  if (S->on_gfx) S->on_gfx(S->gfx_state.load() == 1 ? 1 : 0, msg.c_str());
}

// The renderer is ready or failed (once; from either thread).
void gfx_result(bool ok, const std::string& msg) {
  int expected = 0;
  {
    std::lock_guard<std::mutex> lock(S->mu);
    if (!S->gfx_state.compare_exchange_strong(expected, ok ? 1 : 2)) return;
    S->gfx_message = msg;
    if (!ok) S->status = ",\"gfx_error\":\"" + json_escape(msg) + "\"";
  }
  if (emscripten_is_main_runtime_thread()) gfx_done_main(nullptr);
  else
    emscripten_proxy_async(emscripten_proxy_get_system_queue(), emscripten_main_runtime_thread_id(), gfx_done_main,
                           nullptr);
}

// Both the device and the canvas are here: the surface, then the renderer.
void maybe_ready() {
  if (!S->gpu_done || !S->have_canvas || S->gfx_state.load() != 0) return;
  if (!S->side.gpu) {
    gfx_result(false, S->side.error);
    return;
  }
  std::string err;
  S->side.window = gfx::Window::open_canvas(S->selector.c_str(), S->width, S->height, &err);
  if (!S->side.window || !S->side.window->attach(*S->side.gpu, &err)) {
    S->side.error = err;
    S->side.window.reset();
    gfx_result(false, err);
    return;
  }
  S->side.attach();
  S->vsync = mvp_js_render_vsync() >= 0;
  gfx_result(true, S->side.gpu->adapter_name());
}

// Shows the latest batch's picture.
void show() {
  S->frame_due = false;
  if (S->side.present(S->due_polls, emscripten_get_now())) S->presents.fetch_add(1);
  snapshot();
}

// A frame is due and may be shown now: the first in this display refresh (a
// second one waits for the next refresh and shows the latest batch then, so the
// canvas changes once per refresh), or at once without the page's refresh count.
// If the count stops (a hidden page has no animation frames), the frame shows
// after kVsyncStallMs anyway.
bool may_show() {
  if (!S->frame_due) return false;
  if (!S->vsync) return true;
  const int v = mvp_js_render_vsync();
  if (v == S->shown_at && emscripten_get_now() - S->due_at < kVsyncStallMs) return false;
  S->shown_at = v;
  return true;
}

// Handles one record.
void handle(const gfx::RenderRing::Record& r) {
  switch (r.type) {
    case kGx:
      S->side.gx(r.data, r.len);
      return;
    case kGxRef: {
      Ref v;
      std::memcpy(&v, r.data, sizeof v);
      S->side.gx(v.p, v.n);
      return;
    }
    case kField: {
      Field v;
      std::memcpy(&v, r.data, sizeof v);
      S->side.vi_field(v.field, v.xfb);
      return;
    }
    case kPresent: {
      if (S->frame_due) ++S->held;  // the previous batch's frame was not shown: this one replaces it
      std::memcpy(&S->due_polls, r.data, sizeof S->due_polls);
      if (!S->frame_due) S->due_at = emscripten_get_now();
      S->frame_due = true;
      return;
    }
    case kResize: {
      Pair v;
      std::memcpy(&v, r.data, sizeof v);
      S->side.resize(static_cast<int>(v.a), static_cast<int>(v.b));
      return;
    }
    case kMemory: {
      Ref v;
      std::memcpy(&v, r.data, sizeof v);
      S->side.set_memory(v.p, v.n);
      return;
    }
    case kTrace:
    case kDigest: {
      u32 on;
      std::memcpy(&on, r.data, sizeof on);
      if (r.type == kTrace) S->side.set_trace(on != 0);
      else S->side.set_digest(on != 0);
      return;
    }
    case kFlush:
      S->side.flush();
      snapshot();
      return;
    default:
      return;
  }
}

// Polls up to kSpinMs for records while the emulation produces them.
bool spin_for_data() {
  const double t0 = emscripten_get_now();
  while (emscripten_get_now() - t0 < kSpinMs) {
    if (S->ring.has_data()) return true;
    if (!S->emu_active.load(std::memory_order_relaxed)) break;
  }
  return S->ring.has_data();
}

// The render thread's loop. It waits for records in place (Atomics.wait: the
// emulation's fences need it awake at once). With the page's refresh count it
// presents at most once per refresh: a frame due while records keep coming is
// shown as soon as the count moves. Each present ends the task and the loop
// continues in the next one: a frame drawn into the page's own canvas reaches
// the screen only between tasks, and the thread's event loop gets a turn (the
// page's frame port does not need it: the ImageBitmap is posted at once).
// Between batches, with nothing due, it waits in its event loop until the
// emulation kicks it.
void render_task() {
  ++S->tasks;
  S->idle.store(0, std::memory_order_seq_cst);
  for (;;) {
    if (may_show()) {
      show();
      mvp_js_render_soon();
      return;
    }
    gfx::RenderRing::Record r;
    if (S->ring.next(&r)) {
      handle(r);
      S->ring.done();
      continue;
    }
    const bool active = S->emu_active.load(std::memory_order_seq_cst) != 0;
    if (active && spin_for_data()) continue;
    if (active || S->frame_due) {
      S->ring.wait_data(S->frame_due ? kVsyncPollMs : 2.0);
      continue;
    }
    S->idle.store(1, std::memory_order_seq_cst);
    std::atomic_thread_fence(std::memory_order_seq_cst);
    if ((S->ring.has_data() || S->emu_active.load(std::memory_order_seq_cst)) && S->idle.exchange(0) == 1) continue;
    return;
  }
}

void render_task_cb(void*) { render_task(); }

void* render_main(void*) {
  mvp_js_render_listen(S->selector.c_str(), S->width, S->height);
  // The canvas: the emulation thread posts it to this Worker when asked.
  emscripten_proxy_async(
      emscripten_proxy_get_system_queue(), emscripten_main_runtime_thread_id(),
      [](void*) {
        if (!mvp_js_render_send_canvas(reinterpret_cast<std::uintptr_t>(S->tid))) gfx_result(false, "no canvas");
      },
      nullptr);
  gfx::Gpu::create_async([](std::unique_ptr<gfx::Gpu> gpu, std::string err) {
    if (!gpu) S->side.error = err;
    S->side.gpu = std::move(gpu);
    S->gpu_done = true;
    if (!S->side.gpu) gfx_result(false, S->side.error);
    else maybe_ready();
  });
  render_task();
  emscripten_exit_with_live_runtime();  // keep the thread for its event loop
}

}  // namespace

// ---- emulation thread ----

bool render_thread_start(const char* selector, int width, int height, void (*on_gfx)(int, const char*)) {
  if (S) return true;
  S = new Shared();
  S->selector = selector;
  S->width = width;
  S->height = height;
  S->on_gfx = on_gfx;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setstacksize(&attr, 2u << 20);
  const int rc = pthread_create(&S->tid, &attr, render_main, nullptr);
  pthread_attr_destroy(&attr);
  if (rc != 0) {
    delete S;
    S = nullptr;
    return false;
  }
  return true;
}

bool render_thread_running() { return S != nullptr; }

void render_memory(const std::uint8_t* mem, std::uint32_t size) {
  put(kMemory, Ref{mem, size});
  publish_and_kick();
}

void render_gx(const std::uint8_t* cmd, std::size_t len) {
  if (disabled()) return;
  const u32 n = static_cast<u32>(len);
  if (n <= S->ring.max_payload()) {
    std::memcpy(S->ring.reserve(kGx, n), cmd, n);
    S->ring.commit();
    S->ring.publish_if(kPublishBytes);
    return;
  }
  // Too large to copy (a primitive of several MB): the render thread reads it
  // where it is, and the emulation waits until it has.
  put(kGxRef, Ref{cmd, n});
  ++S->big;
  kick();
  S->fence_ms += S->ring.wait_read(S->ring.end());
  S->synced = S->ring.end();
}

void render_field(std::uint64_t field, std::uint32_t xfb) {
  if (disabled()) return;
  put(kField, Field{field, xfb, 0});
  S->ring.publish();
}

void render_sync() {
  const u32 end = S->ring.end();
  if (end == S->synced) return;  // nothing new since the last fence
  S->synced = end;
  ++S->fences;
  if (S->ring.finished(end)) return;
  kick();
  S->fence_ms += S->ring.wait_read(end);
  ++S->fence_waits;
}

void render_batch_begin() {
  // At most two batches in flight: the render thread must have finished the
  // batch before the last one.
  const u32 pos = S->present_pos[0];
  if (!S->ring.finished(pos)) {
    kick();
    S->lag_ms += S->ring.wait_read(pos);
    ++S->lag_waits;
  }
  S->emu_active.store(1, std::memory_order_seq_cst);
  kick();
}

bool render_present(std::uint64_t frame_polls) {
  if (!disabled()) {
    put(kPresent, frame_polls);
    S->present_pos[0] = S->present_pos[1];
    S->present_pos[1] = S->ring.end();
  }
  S->ring.publish();
  S->emu_active.store(0, std::memory_order_seq_cst);
  kick();
  return S->presents.load() > 0;
}

void render_flush() {
  put(kFlush, u32{0});
  publish_and_kick();
}

void render_resize(int width, int height) {
  ++S->resizes;
  put(kResize, Pair{static_cast<u32>(width), static_cast<u32>(height)});
  publish_and_kick();
}

void render_trace(bool on) {
  put(kTrace, u32{on ? 1u : 0u});
  publish_and_kick();
}

void render_digest(bool on) {
  put(kDigest, u32{on ? 1u : 0u});
  publish_and_kick();
}

std::string render_trace_take() {
  std::string l;
  {
    std::lock_guard<std::mutex> lock(S->mu);
    l.swap(S->trace);
  }
  if (!l.empty() && l.back() == ',') l.pop_back();
  return "[" + l + "]";
}

std::string render_digest_take() {
  std::lock_guard<std::mutex> lock(S->mu);
  std::string d;
  d.swap(S->digest);
  return d;
}

std::string render_status_json() {
  std::string s;
  {
    std::lock_guard<std::mutex> lock(S->mu);
    s = S->status;
  }
  char b[512];
  std::snprintf(b, sizeof b,
                ",\"resizes\":%llu,\"thread\":{\"fences\":%llu,\"fence_waits\":%llu,\"fence_ms\":%.1f,\"lag_waits\":%llu,"
                "\"lag_ms\":%.1f,\"records\":%llu,\"ring_mb\":%.1f,\"full_waits\":%llu,\"big\":%llu}",
                static_cast<unsigned long long>(S->resizes), static_cast<unsigned long long>(S->fences),
                static_cast<unsigned long long>(S->fence_waits), S->fence_ms,
                static_cast<unsigned long long>(S->lag_waits), S->lag_ms,
                static_cast<unsigned long long>(S->ring.records()), static_cast<double>(S->ring.bytes()) / (1 << 20),
                static_cast<unsigned long long>(S->ring.full_waits()), static_cast<unsigned long long>(S->big));
  return s + b;
}

std::uint64_t render_presents() { return S ? S->presents.load() : 0; }

}  // namespace mvp::web

// Called from JavaScript on the render thread.
extern "C" {

// The canvas arrived (mvp_js_render_listen).
EMSCRIPTEN_KEEPALIVE void mvp_render_canvas() {
  using namespace mvp::web;
  S->have_canvas = true;
  maybe_ready();
}

// The task loop, again (mvp_js_render_soon).
EMSCRIPTEN_KEEPALIVE void mvp_render_task() { mvp::web::render_task(); }

}  // extern "C"
