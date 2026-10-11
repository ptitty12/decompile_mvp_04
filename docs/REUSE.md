# Reuse map: public code we can port instead of writing

Researched 2026-10-10 for `docs/SPEEDUPS.md` item 6. **Verified** facts were
checked directly (gh api, the repo's README). Everything else was **reported**
by a research agent and must be checked before anyone relies on it. CLAUDE.md
still applies to anything ported: no `asm` bodies, our verifier decides, and
the source goes in DECISIONS.md.

> **Correction:** `docs/RECON_REPORT.md` §5 says no public decompilation of MVP
> exists. One does: see below.

## 1. A public decomp of this exact game: mitsevox/mvp2005

**Verified:**
- https://github.com/mitsevox/mvp2005: public, **CC0-1.0**, created
  2026-09-29, last push 2026-10-01.
- Targets `GV4E69` with the same retail `main.dol` SHA-1, `da6becdb…84dd`,
  and links with SN `ngcld` like we do. It has 262 C/C++ files under `src/`.
- Its README claims **1,127 / 24,150 functions (4.67%)** and **253,740 /
  5,896,192 code bytes (4.30%)**. 227 units are configured, 226 marked
  matching, and the build reproduces `main.dol` exactly.
- `orig/` holds only a placeholder; there's no game data in it.

**Reported (unverified):**
- What the matching units cover:

  | Area | Units | Location |
  |---|---|---|
  | Dolphin SDK | 96 | |
  | libc | 65 | |
  | libm | 33 | |
  | libgcc | 12 | |
  | libsn | 3 | |
  | EA SND | 16 | `src/snd/cmn/*` |
  | geomlib | 1 | `geomgroup.cpp` |
  | EAGL | 1 | `eagl/viewport.cpp` (2 functions) |

- It links SDK pieces our unit list lacks: vm, vmbase, DebuggerDriver and
  amcstubs.
- `config/GV4E69/filemap.tsv` gives TU boundaries and object names, built from
  FIFA05/UEFA SN link maps. It also has `symbols.txt`, `linked_names.tsv`,
  `name_sources.tsv` and `refnames/*.tsv`. The `refnames` tables were derived
  from other EA games' debug files (see its `docs/reference-builds/`).
- Its measured flags:

  | Code | Flags |
  |---|---|
  | game | `-O2 -G0 -ffloat-store -fno-strength-reduce` |
  | geomlib | `-Os -G0 -ffloat-store` |
  | EAGL | `-O2 -G0` |
  | SDK | `-char unsigned` throughout; signed char for dvd, mtx, CARDOpen and CARDRename; EXIBios `-O3,p`; `-opt nopeephole` only on `__ppc_eabi_init.c` |

  These differ from our DECISIONS, where game code is `-Os` and OS has
  `nopeephole` (resting on one function). Re-check per library.

**How to use it is the owner's decision** (open question):
- port its matched units into this repo,
- move our work onto a private copy of it,
- or work independently.

## 2. EA shared libraries (55 of our 126 units)

All reported. Libraries found in the DOL:

| Library | Approx. address range | Evidence |
|---|---|---|
| EAGL (`C:/mvp2004/libraries/GC/eagl`) | 0x803D5000–0x803EB2AC (17 ctor units) | Deprecation messages say "removed in EAGL 4.09.00", so ours is older than 4.09 |
| gamelib / animlib / corelib | 0x80364000–0x8038C000 (26+ units) | No version string |
| AV / rcmp, VP6, MAD codecs | 0x8038BC58–0x803A4094 | |
| EA SND V9.02.04 (Dec 23 2004) | 0x803A424C–0x803B9794 | Version string |
| SPCH V3.18.01 (Oct 13 2004); csis | | Version strings |
| RealCore (realmem, realfile, realsystem, realmath, realfont, realshape, realmemcard) | 0x803EB2AC–0x80402CAC | |
| SN libsn | | v62 |

Public sources:

| Source | Licence | Covers | Confidence |
|---|---|---|---|
| mitsevox/mvp2005 | CC0 | SND `src/snd/cmn/*` (16 units, matched), `eagl/viewport.cpp` | Very high (same DOL) |
| dbalatoni13/nfsmw | CC0, ProDG 3.9.3 | `src/Speed/Indep/Libs/snd/9/` (about 29 units matching for a later SND build); `src/Speed/Indep/Src/EAGL4Anim/` (16 of 46 files have content, not marked matching). realcore, csis and LibSN are empty stubs there. | High for SND, medium for EAGL anim |
| lifewillbeokay/moh-rising-sun | CC0, ProDG 3.8.1 | `src/eagl/` (state, tar, transform, tevstage) and `src/eagl_anim/`, older EAGL | Low to medium |

No public source was found for gamelib/animlib, the EAGL core render path,
VP6/MAD, SPCH, or the RealCore C bodies. cobanov/nfsu2-decomp is an empty
scaffold.

## 3. Dolphin SDK (13 units)

All reported. Build strings, all `(0x2301)`:

| Library | Build string |
|---|---|
| AI | Apr 5 2004 04:15:02 |
| AR | Apr 5 2004 04:15:03 |
| ARQ | Apr 5 2004 04:15:04 |
| AX | Apr 5 2004 04:15:05 |
| CARD | Apr 5 2004 04:15:35 |
| DSP | Apr 5 2004 04:15:32 |
| DVD | Apr 5 2004 04:14:51 |
| EXI | Apr 5 2004 04:14:14 |
| GX | Apr 5 2004 04:14:28 |
| PAD | Apr 5 2004 04:14:49 |
| SI | Apr 5 2004 04:14:16 |
| VI | Apr 7 2004 04:13:59 |
| OS | May 21 2004 09:28:09 (Patch 1) |

Best public matches:
- **mitsevox/mvp2005:** all 13, already matching on this exact DOL.
- **emoose/re4:** every date matches, 100% matched. The tools are CC0; the
  source is marked as the original owners' IP.
- **PrimeDecomp/echoes:** CC0. GX and OS have our exact dates; no AX.
- **doldecomp/dolsdk2004:** no licence. GX and VI are still in progress.

## 4. libc, libm, libgcc and libsn

All reported:
- mvp2005 has these adapted to MVP's libsn v62 (`src/libc`, `src/libm`,
  `src/libgcc`, `src/libsn`).
- emoose/re4 has newlib 1.8.2 and fdlibm, built with SN v1.79, but they match
  under v1.76.
- crt0, ppcdown, proview and tealeaf were original asm and stay as split asm,
  per DECISIONS.

## 5. Recommendations

1. **Port mvp2005's matched units:** runtime, SDK, SND and geomlib, about
   1,100 functions. Re-verify each with `tools/verify/verify.py`, and strip
   or exclude anything with `asm`. This is the fastest single gain available:
   about 16 of our unit issues almost outright, with the 4.7% that's already
   public.
2. **Use mvp2005's filemap for TU boundaries and EA object names**, recording
   the source as evidence. Whether names that came from other games' debug
   files count as acceptable evidence is the owner's call.
3. **Use nfsmw's EAGL4Anim and moh-rising-sun's EAGL as starting points** for
   the matching EAGL pieces. Expect version differences.
4. **Expect no outside help for gamelib (about 29 units) or game code.** That's
   where `tools/scout/` and the matching effort go.
5. **Check mvp2005's progress regularly** while the owner decides: it's active
   and ahead of us on infrastructure.
