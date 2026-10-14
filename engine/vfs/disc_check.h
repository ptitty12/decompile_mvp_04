// Opening and identifying the player's disc: the checks every entry point runs
// before anything else reads the game.
#pragma once

#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "vfs/dol.h"
#include "vfs/gcm.h"
#include "vfs/source.h"

namespace mvp::vfs {

struct Disc {
  std::unique_ptr<Source> image;
  Gcm gcm;
  Dol dol;
  std::string dol_sha1;
};

// Opens the image, parses the GCM and main.dol, and checks the game id and the
// DOL's SHA-1 against GV4E69 rev 0. With `require_retail` false the hash is only
// recorded (tests on synthetic images).
std::optional<Disc> open_disc(const std::string& path, bool require_retail, std::string* error);
std::optional<Disc> open_disc(std::unique_ptr<Source> image, bool require_retail, std::string* error);

// Non-comment, whitespace-normalized lines of a dol_layout.txt.
std::vector<std::string> normalized_layout(const std::string& text);

}  // namespace mvp::vfs
