# DECISIONS (owner-approved only)

Agents may propose entries under "Open questions"; only the owner moves them to "Decided".

## Decided
<!-- YYYY-MM-DD | decision | why | evidence -->

- 2026-10-10 | **Target is MVP Baseball 2005, GameCube `GV4E69` (USA, rev 0).** Owner said in chat: "yes we are using 2005, you can edit all of that yourself"; the agent updated the game name in CLAUDE.md, README.md and prompts/00_KICKOFF.md. | The owner's disc is 2005. | `docs/RECON_REPORT.md` §1
- 2026-10-10 | **Path: `prodg-hybrid`.** Game code and EA libraries are matched with SN ProDG (GCC 2.95.3 "SN BUILD v1.76", exact build to be located). The Dolphin SDK is matched with Metrowerks CodeWarrior. There is a compiler gate after the Phase 1 scaffold: if no available ProDG build reproduces game codegen, stop and ask the owner. | Toolchain evidence | `docs/RECON_REPORT.md` §2, §7
- 2026-10-10 | **Host: native Windows** (owner: "use whatever"; agent's recommendation). | ProDG `ngccc`/`ngcld` and MWCC are Win32 executables and run natively; no wine/wibo needed. | `docs/RECON_REPORT.md` §6
- 2026-10-10 | **Phase 1 tool downloads approved** (no game data): dtk-template, decomp-toolkit, objdiff, binutils, community compilers package, ninja. Ghidra/JDK/REA were not part of this approval. | Needed for the scaffold | owner reply in chat
- 2026-10-10 | **GitHub remote deferred.** The owner will log in to GitHub later. Until then the repo stays local; GitHub issues, CI runs and pushes wait. | — | owner reply in chat

## Open questions for owner
<!-- YYYY-MM-DD | question | context | options -->

- 2026-10-10 | **Review: Phase 1 build pipeline (implemented, verified; the owner may veto)** | Upstream dtk-template assumes CodeWarrior (mwld + dtk's ldscript.lcf + `dtk elf2dol`). None of that reproduces this game's DOL. What was done instead:
  1. **Split input = "analysis DOL"** built from the disc's stripped `/mvp.elf` by `tools/mkdol.py --per-section`. It has the same bytes at every address as retail main.dol but keeps the real section boundaries. Retail main.dol merges .text+overlays and .ctors+.dtors, so dtk can't recover the sections from it.
  2. **Link with SN `ngcld` 1.5.1.692 (ProDG 3.9.3)** and a static GNU-style script, `config/GV4E69/ldscript.ld`. Upstream's mwld path isn't used.
  3. **DOL packing by `tools/mkdol.py --layout config/GV4E69/dol_layout.txt`**, which groups sections into DOL slots exactly as the retail program segments do. Validation: converting the retail `/mvp.elf` with `--segments` or `--layout` reproduces retail main.dol byte-for-byte (SHA-1 `da6becdb…84dd`). `ngcld`'s own PHDRS support crashes, hence the layout file.
  4. **Overlay input sections are renamed** `.feoverlay`/`.dboverlay`, because dtk's symbols.txt grammar rejects `_` in section names. The script maps them back to the retail output names. This affects no bytes.
  5. **`LONG(0)` terminators for .ctors/.dtors** in the script, because dtk omits them (CodeWarrior's linker adds them; `ngcld` doesn't).
  6. **`add_relocations` overrides** in config.yml, each documented. They change only symbol+addend form, never bytes.
  7. A small, marked patch to `tools/project.py`: a `pre-split` step category, ProDG link/compile rules (`ngcld`/`ngccc`) and an optional mkdol DOL step. Default behaviour is unchanged when `linker_version` isn't `ProDG/*`.
  | approve as-is / request changes
- 2026-10-10 | **Finding: the exact compiler is available** (informational) | `build/compilers/ProDG/3.9.3/cc1plus.exe` contains `2.95.3 SN BUILD v1.76 for Nintendo Gamecube`, the banner found in the on-disc EAGL objects. The other packaged ProDG builds are v1.40 (3.5b140), v1.46 (3.7) and v1.54/v1.55 (3.8.1). Codegen equivalence still has to be confirmed with objdiff. | —
- 2026-10-10 | **Finding: small-data bases follow SN's convention** (informational) | `_SDA_BASE_` = .sdata + 0x8000 (r13 = 0x806F69C0) and `_SDA2_BASE_` = .sdata + 0x18000 (r2 = 0x807069C0, so r2 is unusable and .sdata2 is reached via r13). nfsmw's SN script uses the same. Encoded in ldscript.ld. | —
