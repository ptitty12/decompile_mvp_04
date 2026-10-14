// Host file helpers for development tools. The browser build replaces these
// with OPFS access; nothing here may feed guest state outside the virtual disc.
#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace mvp {

std::optional<std::vector<std::uint8_t>> read_file(const std::string& path);
bool write_file(const std::string& path, const void* data, std::size_t size);
std::optional<std::string> read_text(const std::string& path);

// Value of an environment variable, or the fallback when unset or empty.
std::string env_or(const char* name, const std::string& fallback);

}  // namespace mvp
