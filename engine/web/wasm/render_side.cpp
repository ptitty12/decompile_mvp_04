#include "web/wasm/render_side.h"

#include <emscripten.h>

#include <cstdio>

// P2: with a frame port from the page (Module.mvpFrames), the canvas `sel` is
// the engine's own: its picture goes to the page as an ImageBitmap, which the
// page shows (main.ts). Without one the canvas is the page's and shows itself.
// Returns 1 if the canvas must be configured again (Firefox unconfigures a
// WebGPU canvas when its bitmap is taken; Chrome keeps it).
EM_JS(int, mvp_js_send_frame, (const char* sel), {
  var p = Module['mvpFrames'];
  if (!p) return 0;
  var c = Module['specialHTMLTargets'][UTF8ToString(sel)];
  if (!c || !c.transferToImageBitmap) return 0;
  var b = c.transferToImageBitmap();
  p.postMessage(b, [b]);
  var ctx = c.getContext('webgpu');
  return ctx && ctx.getConfiguration && !ctx.getConfiguration() ? 1 : 0;
});

namespace mvp::web {

void XfbTap::efb_copy(const gfx::EfbCopy& c) {
  if (c.to_xfb) {
    ++copies;
    if (on) {
      char b[200];
      std::snprintf(b, sizeof b,
                    "{\"k\":\"c\",\"f\":%llu,\"d\":%u,\"x\":%u,\"y\":%u,\"w\":%u,\"h\":%u,\"ys\":%.4f,\"clr\":%d},",
                    static_cast<unsigned long long>(field), c.dest, c.src_x, c.src_y, c.width, c.height,
                    static_cast<double>(c.y_scale), c.clear ? 1 : 0);
      log += b;
    }
  }
  next->efb_copy(c);
}

void RenderSide::set_memory(const std::uint8_t* mem, std::uint32_t size) {
  mem_ = mem;
  mem_size_ = size;
  gp_.attach(mem, size);
  attach();
}

void RenderSide::attach() {
  if (!gpu || !window || !mem_ || renderer_) return;
  renderer_ = std::make_unique<gfx::Renderer>(*gpu, mem_, mem_size_);
  renderer_->set_gp_memory(&gp_);
  tap_.next = renderer_.get();
  digest_.next = &tap_;
  digest_.set_memory(mem_, mem_size_);
  digest_.set_gp_memory(&gp_);
  proc_ = std::make_unique<gfx::GxProcessor>(&digest_);
  proc_->set_memory(mem_, mem_size_);
  proc_->set_gp_memory(&gp_);
}

void RenderSide::vi_field(std::uint64_t field, std::uint32_t xfb) {
  gp_.field();  // Q1: snapshots of the game's cache write-backs expire
  if (renderer_) {
    renderer_->flush();
    renderer_->scan_field(xfb);  // what the VI scans out at this field (P1)
  }
  if (tap_.on && xfb != xfb_) {
    char b[80];
    std::snprintf(b, sizeof b, "{\"k\":\"v\",\"f\":%llu,\"t\":%u},", static_cast<unsigned long long>(field), xfb);
    tap_.log += b;
  }
  if (digest_.on) {
    using D = gfx::DigestTap;
    char b[200];
    std::snprintf(b, sizeof b, "%llu %016llx %016llx %016llx %016llx %016llx %016llx %llu\n",
                  static_cast<unsigned long long>(field), static_cast<unsigned long long>(digest_.digest()),
                  static_cast<unsigned long long>(digest_.part(D::kState)),
                  static_cast<unsigned long long>(digest_.part(D::kVerts)),
                  static_cast<unsigned long long>(digest_.part(D::kTex)),
                  static_cast<unsigned long long>(digest_.part(D::kTexMem)),
                  static_cast<unsigned long long>(digest_.part(D::kCopies)),
                  static_cast<unsigned long long>(digest_.draws()));
    digest_log_ += digest_.detail_log;
    digest_.detail_log.clear();
    digest_log_ += b;
    digest_.detail = detail_from_ <= field + 1 && field + 1 <= detail_to_;  // the draws of the next field
    digest_.reset();  // one digest per field
  }
  xfb_ = xfb;
  tap_.field = field;
}

bool RenderSide::present(std::uint64_t frame_polls, double now_ms) {
  if (!renderer_ || !window) return false;
  // The picture the VI scanned out at the last fields (P1: field-alternating
  // pixels mixed, as an interlaced display shows them), else the XFB copy at the
  // VI's address, else the latest copy.
  const gfx::Renderer::Frame* f = renderer_->scanout();
  const bool mixed = renderer_->is_mixed(f);
  const bool fallback = !f && !renderer_->xfb(xfb_);
  if (!f) f = renderer_->xfb(xfb_);
  if (!f) f = renderer_->latest_xfb();
  if (!f) return false;
  if (tap_.on) {
    char b[200];
    std::snprintf(b, sizeof b,
                  "{\"k\":\"p\",\"f\":%llu,\"fr\":%llu,\"t\":%u,\"a\":%u,\"s\":%llu,\"new\":%d,\"fb\":%d,"
                  "\"n\":%llu,\"w\":%u,\"h\":%u,\"mix\":%d,\"ms\":%.2f},",
                  static_cast<unsigned long long>(tap_.field), static_cast<unsigned long long>(frame_polls), xfb_,
                  f->addr, static_cast<unsigned long long>(f->serial), f->serial != last_presented_ ? 1 : 0,
                  fallback ? 1 : 0, static_cast<unsigned long long>(tap_.copies - copies_at_present_), f->width,
                  f->height, mixed ? 1 : 0, now_ms);
    tap_.log += b;
  }
  copies_at_present_ = tap_.copies;
  window->present(f->view, f->width, f->height);
  if (mvp_js_send_frame("#mvp-canvas")) window->reconfigure();
  ++presents_;
  last_presented_ = f->serial;
  return true;
}

void RenderSide::resize(int width, int height) {
  ++resizes_;
  if (window) window->resize(width, height);
}

std::string RenderSide::trace_take() {
  std::string l = trace_take_raw();
  if (!l.empty() && l.back() == ',') l.pop_back();
  return "[" + l + "]";
}

std::string RenderSide::trace_take_raw() {
  std::string out;
  out.swap(tap_.log);
  return out;
}

std::string RenderSide::digest_take() {
  std::string out;
  out.swap(digest_log_);
  return out;
}

std::string RenderSide::status_json() const {
  std::string s;
  if (renderer_) {
    const auto& rs = renderer_->stats();
    const auto& ps = proc_->stats();
    char b[512];
    std::snprintf(b, sizeof b,
                  ",\"draws\":%llu,\"xfb_copies\":%llu,\"pipelines\":%llu,\"textures\":%llu,\"gpu_errors\":%llu,"
                  "\"copies_dropped\":%llu,\"copy_size_misses\":%llu,\"copy_tall\":%llu,\"scan_mixed\":%llu",
                  static_cast<unsigned long long>(rs.draws), static_cast<unsigned long long>(ps.xfb_copies),
                  static_cast<unsigned long long>(rs.pipelines), static_cast<unsigned long long>(rs.textures_decoded),
                  static_cast<unsigned long long>(gpu->errors()), static_cast<unsigned long long>(rs.copies_dropped),
                  static_cast<unsigned long long>(rs.copy_size_misses), static_cast<unsigned long long>(rs.copy_tall),
                  static_cast<unsigned long long>(renderer_->scan_stats().mixed));
    s += b;
    const auto& gs = gp_.stats();  // Q1: the GP's view of memory
    std::snprintf(b, sizeof b, ",\"gp_memory\":{\"flushes\":%llu,\"flushed_mb\":%.1f,\"overlays\":%llu,\"lines\":%llu,\"drops\":%llu}",
                  static_cast<unsigned long long>(gs.flushes), static_cast<double>(gs.flushed_bytes) / 1e6,
                  static_cast<unsigned long long>(gs.overlays), static_cast<unsigned long long>(gs.overlaid_lines),
                  static_cast<unsigned long long>(gs.drops));
    s += b;
  }
  if (!error.empty()) {
    s += ",\"gfx_error\":\"";
    for (char ch : error) {
      if (ch == '"' || ch == '\\') s += '\\', s += ch;
      else if (static_cast<unsigned char>(ch) < 0x20) s += ' ';
      else s += ch;
    }
    s += '"';
  }
  return s;
}

}  // namespace mvp::web
