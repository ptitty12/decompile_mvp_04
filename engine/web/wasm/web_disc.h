// The disc image from the server (E2c): on the owner's private deployment the
// page finds {"disc": "<url>"} in /config.json and the engine Worker reads the
// image from that same-origin URL with HTTP Range requests (synchronous
// XMLHttpRequests: a guest DVD read completes inside the call), through the
// block cache in block_cache.h. The Worker has checked beforehand that the URL
// answers HEAD with the size and a ranged GET with 206.
#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include "web/wasm/block_cache.h"

namespace mvp::web {

// Reads Module.mvpDiscUrl (set by the Worker) by Range requests.
std::unique_ptr<BlockCacheSource> open_http_disc(std::uint64_t size, BlockCacheSource::Options opt);

// Why the last failed request failed ("" if none failed yet).
const std::string& last_http_error();

}  // namespace mvp::web
