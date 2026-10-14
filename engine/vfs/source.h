// Random-access byte sources: the player's disc image and its containers.
//
// The disc is read through this interface only. In the browser it will be backed
// by the File the player picked; natively by a host file. Reads are synchronous
// here; the runtime decides when a guest-visible read completes (virtual time).
#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace mvp::vfs {

class Source {
 public:
  virtual ~Source() = default;
  virtual std::uint64_t size() const = 0;
  // Reads exactly n bytes at off. Returns false (and leaves dst unspecified) if
  // the range is outside the source or the host read fails.
  virtual bool read(std::uint64_t off, void* dst, std::size_t n) = 0;

  std::vector<std::uint8_t> read_vec(std::uint64_t off, std::size_t n, bool* ok = nullptr);
};

// A host file (64-bit offsets).
class FileSource final : public Source {
 public:
  static std::unique_ptr<FileSource> open(const std::string& path);
  ~FileSource() override;
  std::uint64_t size() const override { return size_; }
  bool read(std::uint64_t off, void* dst, std::size_t n) override;

 private:
  FileSource() = default;
  void* f_ = nullptr;
  std::uint64_t size_ = 0;
};

// Bytes held in memory (tests, synthetic images).
class MemorySource final : public Source {
 public:
  explicit MemorySource(std::vector<std::uint8_t> bytes) : bytes_(std::move(bytes)) {}
  std::uint64_t size() const override { return bytes_.size(); }
  bool read(std::uint64_t off, void* dst, std::size_t n) override;
  const std::vector<std::uint8_t>& bytes() const { return bytes_; }

 private:
  std::vector<std::uint8_t> bytes_;
};

// CISO container: a 0x8000-byte header ("CISO", little-endian block size, then one
// byte per block: 1 = stored, 0 = all zero), followed by the stored blocks in order.
class CisoSource final : public Source {
 public:
  // Returns null if `inner` is not a well-formed CISO.
  static std::unique_ptr<CisoSource> open(std::unique_ptr<Source> inner, std::string* error = nullptr);
  std::uint64_t size() const override { return size_; }
  bool read(std::uint64_t off, void* dst, std::size_t n) override;
  std::uint32_t block_size() const { return block_size_; }

 private:
  CisoSource() = default;
  std::unique_ptr<Source> inner_;
  std::uint32_t block_size_ = 0;
  std::vector<std::int64_t> block_off_;  // -1 = zero block
  std::uint64_t size_ = 0;
};

// Opens a disc image: CISO if the file starts with "CISO", otherwise a plain ISO/GCM.
std::unique_ptr<Source> open_disc_image(const std::string& path, std::string* error = nullptr);

}  // namespace mvp::vfs
