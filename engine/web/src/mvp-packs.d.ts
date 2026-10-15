// The page's small validation module (mvp-packs.js): the engine's roster-pack code
// (engine/mods, wasm/packs_web.cpp) without the rest of the engine, so the Roster
// packs panel can check packs and show their hashes before a game starts.

import type { PacksModule } from './packs-core.js';

export default function createMvpPacks(options?: { print?: (t: string) => void; printErr?: (t: string) => void }):
  Promise<PacksModule>;
