#include "common/file.h"

#include <cstdio>
#include <cstdlib>

namespace mvp {

std::optional<std::vector<std::uint8_t>> read_file(const std::string& path) {
  std::FILE* f = std::fopen(path.c_str(), "rb");
  if (!f) return std::nullopt;
  std::vector<std::uint8_t> out;
  if (std::fseek(f, 0, SEEK_END) == 0) {
    long n = std::ftell(f);
    if (n > 0) out.reserve(static_cast<std::size_t>(n));
    std::fseek(f, 0, SEEK_SET);
  }
  std::uint8_t buf[1 << 16];
  std::size_t got;
  while ((got = std::fread(buf, 1, sizeof buf, f)) > 0) out.insert(out.end(), buf, buf + got);
  std::fclose(f);
  return out;
}

bool write_file(const std::string& path, const void* data, std::size_t size) {
  std::FILE* f = std::fopen(path.c_str(), "wb");
  if (!f) return false;
  bool ok = std::fwrite(data, 1, size, f) == size;
  return std::fclose(f) == 0 && ok;
}

std::optional<std::string> read_text(const std::string& path) {
  auto bytes = read_file(path);
  if (!bytes) return std::nullopt;
  return std::string(bytes->begin(), bytes->end());
}

std::string env_or(const char* name, const std::string& fallback) {
  const char* v = std::getenv(name);
  return v && *v ? std::string(v) : fallback;
}

}  // namespace mvp
