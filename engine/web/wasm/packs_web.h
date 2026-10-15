// Roster packs in the browser (E6): the pack set the player picked on the page,
// handed to the engine file by file (a picked folder) or as zips, checked,
// applied to the tables of the player's own disc and mounted on the virtual disc
// before the boot. The exports (packs_web.cpp) are shared by the engine module
// (mvp-web) and the page's small validation module (mvp-packs), so the page's
// panel, the engine and the netplay handshake all use the same code.
#pragma once

#include <array>
#include <cstdint>

#include "vfs/disc_check.h"

namespace mvp::web {

// The checked disc the packs are mounted on (mvp-web: set when the disc is opened).
void packs_set_disc(vfs::Disc* disc);
// The set hash of the packs given so far (the empty set's hash without packs):
// the netplay handshake's pack-set field.
std::array<std::uint8_t, 32> packs_set_hash();

}  // namespace mvp::web
