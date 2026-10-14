#include "vfs/disc_check.h"

#include <sstream>

#include "common/sha1.h"

namespace mvp::vfs {

std::optional<Disc> open_disc(std::unique_ptr<Source> image, bool require_retail, std::string* error) {
  auto fail = [&](const std::string& why) -> std::optional<Disc> {
    if (error) *error = why;
    return std::nullopt;
  };
  if (!image) return fail("no disc image");
  std::string err;
  auto gcm = Gcm::open(*image, &err);
  if (!gcm) return fail(err);
  if (require_retail && gcm->game_id() != kGameId) return fail("not GV4E69: game id " + gcm->game_id());
  if (require_retail && gcm->revision() != 0) return fail("not revision 0");
  auto bytes = read_main_dol(*image, *gcm, &err);
  if (!bytes) return fail(err);
  std::string sha = Sha1::of(bytes->data(), bytes->size());
  if (require_retail && sha != kRetailDolSha1) return fail("main.dol SHA-1 " + sha + " is not GV4E69 rev 0");
  auto dol = Dol::parse(std::move(*bytes), &err);
  if (!dol) return fail(err);
  return Disc{std::move(image), std::move(*gcm), std::move(*dol), sha};
}

std::optional<Disc> open_disc(const std::string& path, bool require_retail, std::string* error) {
  return open_disc(open_disc_image(path, error), require_retail, error);
}

std::vector<std::string> normalized_layout(const std::string& text) {
  std::vector<std::string> out;
  std::istringstream in(text);
  std::string line;
  while (std::getline(in, line)) {
    auto hash = line.find('#');
    if (hash != std::string::npos) line.resize(hash);
    std::istringstream words(line);
    std::string w, norm;
    while (words >> w) norm += (norm.empty() ? "" : " ") + w;
    if (!norm.empty()) out.push_back(norm);
  }
  return out;
}

}  // namespace mvp::vfs
