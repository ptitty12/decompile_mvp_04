#include "web/wasm/web_disc.h"

#include <emscripten.h>

// One Range request, synchronous (Workers only), with up to three attempts on
// network errors and server errors. Returns 1, 0 after a network error, or
// -status for an HTTP status that retrying does not fix.
EM_JS(int, mvp_js_http_read, (double off, void* dst, double n), {
  var url = Module['mvpDiscUrl'];
  var last = 0;
  for (var attempt = 0; attempt < 3; ++attempt) {
    try {
      var x = new XMLHttpRequest();
      x.open('GET', url, false);
      x.responseType = 'arraybuffer';
      x.setRequestHeader('Range', 'bytes=' + off + '-' + (off + n - 1));
      x.send();
      if (x.status == 206 && x.response && x.response.byteLength == n) {
        HEAPU8.set(new Uint8Array(x.response), dst >>> 0);
        return 1;
      }
      last = x.status;
      if (x.status == 401 || x.status == 403 || x.status == 404 || x.status == 416 || x.status == 200) break;
    } catch (e) {
      last = 0;
    }
  }
  return last ? -last : 0;
});

namespace mvp::web {

namespace {

std::string g_last_error;

class HttpFetcher final : public RangeFetcher {
 public:
  bool fetch(std::uint64_t off, std::uint8_t* dst, std::size_t n) override {
    const int r = mvp_js_http_read(static_cast<double>(off), dst, static_cast<double>(n));
    if (r == 1) return true;
    if (r == 0)
      error_ = "the disc image could not be read from the server (network error)";
    else if (r == -401 || r == -403)
      error_ = "the server refused the disc image (HTTP " + std::to_string(-r) + "): log in again";
    else if (r == -200)
      error_ = "the server ignored the Range request (HTTP 200)";
    else
      error_ = "the server answered HTTP " + std::to_string(-r) + " for the disc image";
    g_last_error = error_;
    return false;
  }
  std::string error() const override { return error_; }

 private:
  std::string error_;
};

}  // namespace

const std::string& last_http_error() { return g_last_error; }

std::unique_ptr<BlockCacheSource> open_http_disc(std::uint64_t size, BlockCacheSource::Options opt) {
  auto src = std::make_unique<BlockCacheSource>(std::make_unique<HttpFetcher>(), size, opt);
  src->set_clock(&emscripten_get_now);
  return src;
}

}  // namespace mvp::web
