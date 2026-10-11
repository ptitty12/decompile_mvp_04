# Phase 0 recon scripts

Small, dependency-free Python scripts used to produce `docs/RECON_REPORT.md`.
They only **read** the disc image / binaries. Write any outputs to `build/` or
somewhere outside the repo, never into tracked paths (outputs are derived from
game data).

| Script | What it does |
|---|---|
| `gcdisc.py` | CISO + GameCube GCM reader: header, FST listing, extract `main.dol` and named files to a directory |
| `junk.py` | Regenerates GameCube disc junk padding (lagged-Fibonacci, reseeded per 0x8000 sector), checks it against the junk still in the image (`validate`), and computes the full-image SHA-1 for redump comparison (`sha1`) |
| `elfinfo.py` | ELF32 (either endianness) section/symbol dump and `ar` archive member listing |
| `dol.py` | DOL loader + minimal PowerPC decoder (enough for crt0 and call graphs) |
| `shape.py` | Function-start estimate and prologue-style classification (GCC vs CodeWarrior) by address range |
| `xref.py` | String cross-references from code (`lis`/`addi` pairs and r13-relative) to build the subsystem map |
| `srcpaths.py` | Source-file path strings embedded in the DOL |

Examples (Git Bash; set `MSYS_NO_PATHCONV=1` when passing disc-internal paths like `/mvp.elf`):

```bash
python -I tools/recon/gcdisc.py "orig/GV4E69/MVP Baseball 2005 (USA).ciso" extract build/recon /mvp.elf
python -I tools/recon/junk.py "orig/GV4E69/MVP Baseball 2005 (USA).ciso" validate
python -I tools/recon/shape.py build/recon/main.dol 0x20000 build/recon/funcs.txt
python -I tools/recon/xref.py build/recon/main.dol build/recon/funcs.txt kw pitch umpire franchise
```
