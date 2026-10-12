#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List

from tools.project import (
    Object,
    ProgressCategory,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "GV4E69",  # 0: MVP Baseball 2005 (USA, rev 0)
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--objdiff",
    metavar="BINARY | DIR",
    type=Path,
    help="path to objdiff-cli binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--ninja",
    metavar="BINARY",
    type=Path,
    help="path to ninja binary (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="builds equivalent (but non-matching) or modded objects",
)
parser.add_argument(
    "--warn",
    dest="warn",
    type=str,
    choices=["all", "off", "error"],
    help="how to handle warnings",
)
parser.add_argument(
    "--no-progress",
    dest="progress",
    action="store_false",
    help="disable progress calculation",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = str(args.version)
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.objdiff_path = args.objdiff
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.generate_map = args.map
config.non_matching = args.non_matching
config.sjiswrap_path = args.sjiswrap
config.ninja_path = args.ninja
config.progress = args.progress
if not is_windows():
    config.wrapper = args.wrapper
# Don't build asm unless we're --non-matching
if not config.non_matching:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-2"
config.compilers_tag = "20251118"  # files.decomp.dev; includes ProDG 3.5-3.9.3 and MWCC GC/*
config.dtk_tag = "v1.8.4"
config.objdiff_tag = "v3.8.2"
config.sjiswrap_tag = "v1.2.2"
config.wibo_tag = "1.0.3"

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"
config.asflags = [
    "-mgekko",
    "--strip-local-absolute",
    "-I include",
    f"-I build/{config.version}/include",
    f"--defsym BUILD_VERSION={version_num}",
]
# SN ngcld. The script and DOL packing are described in docs/DECISIONS.md.
config.ldflags = []
config.ldscript_path = Path("config") / config.version / "ldscript.ld"
config.dol_layout_path = Path("config") / config.version / "dol_layout.txt"

###
# Analysis input ("pre-split" steps)
#
# `dtk dol split` reads a DOL, but the retail main.dol merges sections into
# segments (.text + overlays, .ctors + .dtors), which hides the real section
# boundaries. The disc carries the stripped link output /mvp.elf (same bytes as
# main.dol), so we convert it to a one-section-per-ELF-section "analysis DOL"
# and split that. The final build is still verified against the retail
# main.dol hash in config/GV4E69/build.sha1.
###
orig_dir = Path("orig") / config.version
analysis_dir = config.build_dir / config.version / "orig"
analysis_elf = analysis_dir / "mvp.elf"
analysis_dol = analysis_dir / "main_sections.dol"
disc_exts = (".iso", ".gcm", ".ciso", ".rvz", ".wia", ".wbfs", ".gcz", ".nfs", ".tgc")
discs = sorted(p for p in orig_dir.glob("*") if p.suffix.lower() in disc_exts)
if args.dtk is not None and args.dtk.is_file():
    dtk_exe = args.dtk
else:
    dtk_exe = config.build_dir / "tools" / ("dtk.exe" if is_windows() else "dtk")
config.custom_build_rules = [
    {
        "name": "extract_disc_file",
        "command": f'{dtk_exe} vfs cp "$disc:$disc_path" $out',
        "description": "EXTRACT $disc_path",
    },
    {
        "name": "copy_file",
        "command": "$python -c \"import shutil,sys; shutil.copyfile(sys.argv[1], sys.argv[2])\" $in $out",
        "description": "COPY $out",
    },
    {
        "name": "mkdol_sections",
        "command": "$python tools/mkdol.py --per-section $in $out",
        "description": "ANALYSIS DOL $out",
    },
]
if (orig_dir / "mvp.elf").is_file():
    elf_step = {
        "outputs": analysis_elf,
        "rule": "copy_file",
        "inputs": orig_dir / "mvp.elf",
    }
elif len(discs) == 1:
    elf_step = {
        "outputs": analysis_elf,
        "rule": "extract_disc_file",
        "inputs": discs[0],
        "implicit": dtk_exe,
        "variables": {"disc": discs[0], "disc_path": "files/mvp.elf"},
    }
else:
    sys.exit(
        f"Expected exactly one disc image (or an extracted mvp.elf) in {orig_dir}, "
        f"found {[p.name for p in discs]}"
    )
config.custom_build_steps = {
    "pre-split": [
        elf_step,
        {
            "outputs": analysis_dol,
            "rule": "mkdol_sections",
            "inputs": analysis_elf,
            "implicit": Path("tools") / "mkdol.py",
        },
    ],
}
config.split_implicit = [analysis_dol]

# Use for any additional files that should cause a re-configure when modified
config.reconfig_deps = []

# Optional numeric ID for decomp.me preset
# Can be overridden in libraries or objects
config.scratch_preset_id = None

# Base flags, common to most GC/Wii games.
# Generally leave untouched, with overrides added below.
cflags_base = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    "-O4,p",
    "-inline auto",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-maxerrors 1",
    "-nosyspath",
    "-RTTI off",
    "-fp_contract on",
    "-str reuse",
    "-multibyte",  # For Wii compilers, replace with `-enc SJIS`
    "-i include",
    f"-i build/{config.version}/include",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
]

# Debug flags
if args.debug:
    # Or -sym dwarf-2 for Wii compilers
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

# Warning flags
if args.warn == "all":
    cflags_base.append("-W all")
elif args.warn == "off":
    cflags_base.append("-W off")
elif args.warn == "error":
    cflags_base.append("-W error")

# Metrowerks library flags
cflags_runtime = [
    *cflags_base,
    "-use_lmw_stmw on",
    "-str reuse,pool,readonly",
    "-gccinc",
    "-common off",
    "-inline auto",
]

# REL flags
cflags_rel = [
    *cflags_base,
    "-sdata 0",
    "-sdata2 0",
]

config.linker_version = "ProDG/3.9.3"  # SN ngcld 1.5.1.692; cc1plus = "2.95.3 SN BUILD v1.76"


# Helper function for Dolphin libraries
def DolphinLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_base,
        "progress_category": "sdk",
        "objects": objects,
    }


# Helper function for REL script objects
def Rel(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.3.2",
        "cflags": cflags_rel,
        "progress_category": "game",
        "objects": objects,
    }


Matching = True                   # Object matches and should be linked
NonMatching = False               # Object does not match and should not be linked
Equivalent = config.non_matching  # Object should be linked when configured with --non-matching


# Object is only matching for specific versions
def MatchingFor(*versions):
    return config.version in versions


config.warn_missing_config = True
config.warn_missing_source = False

# SN's libgcc (GCC 2.95.3 runtime as shipped with ProDG). See docs/DECISIONS.md.
cflags_libgcc = ["-O2", "-G0"]

# Game code (MVP Baseball 2005, EA Canada): ProDG 3.9.3. -G0: game .text never
# uses r13 small-data addressing. C++: no RTTI (empty vtable RTTI slots) and no
# exception tables in the binary. See docs/DECISIONS.md.
cflags_game = ["-Os", "-G0", "-ffloat-store", "-fno-rtti", "-fno-exceptions", "-Iinclude"]

# EA shared libraries (ProDG 3.9.3): -O2, unlike game code (-Os). See docs/DECISIONS.md.
cflags_ealib = ["-O2", "-G0", "-fno-rtti", "-fno-exceptions"]

# Dolphin SDK OS library (built May 21 2004, later than the other SDK libs).
cflags_dolphin_os = [*cflags_base, "-char unsigned", "-opt nopeephole"]

# Dolphin SDK AI library (built Apr 5 2004). Flags TBD; start from the OS ones.
cflags_dolphin_ai = [*cflags_base, "-char unsigned", "-opt nopeephole"]

# EA gamelib (C:/mvp2004/libraries/gamelib: memory, datafile, animlib; 0x80377048..0x8038BC58):
# built with the game flags. See docs/DECISIONS.md (tail split).
cflags_gamelib = cflags_game

# EA libraries that use small data (r13): VP6/MAD codecs + SPCH (0x8038EC58..0x803A4214) and
# RealCore (0x803EB2AC..0x80403E80). Same as cflags_ealib but with the default -G8.
cflags_ealib_sda = ["-O2", "-fno-rtti", "-fno-exceptions"]
# Part of the codec range (0x803912F8..0x803959D8) uses no small data and keeps
# per-iteration index math (no strength reduction); see docs/DECISIONS.md.
cflags_ealib_nsr = ["-O2", "-G0", "-fno-rtti", "-fno-exceptions", "-fno-strength-reduce"]
# RealCore units that keep per-iteration index math but use small data (default -G8).
cflags_ealib_sda_nsr = ["-O2", "-fno-rtti", "-fno-exceptions", "-fno-strength-reduce"]

# EA SND 9.02.04 + csis (0x803A4214..0x803BA9DC), compiled as C++. Flags from mitsevox/mvp2005
# (port/mvp2005 branch); saems.c 74/74, smemman.c 5/5, salloc.c 4/4 at 100% with them.
cflags_snd = [
    "-O2",
    "-G0",
    "-fno-strength-reduce",
    "-fno-strict-aliasing",
    "-ffast-math",
    "-mps-float",
    "-x c++",
    "-Iinclude",
    "-Iinclude/libc",
    "-Isrc",
    "-DEA_PLATFORM_GAMECUBE",
    "-DGEKKO",
]

# SN ProDG runtime libraries (flags from mitsevox/mvp2005 via port/mvp2005, re-measured).
cflags_libsn = ["-O2", "-G0", "-fno-common"]
cflags_libc = ["-O2", "-fno-common", "-isystem include/prodg"]
cflags_libm = ["-O2", "-mfast-cast", "-msafe-sda", "-G 1024", "-fno-builtin", "-mstrict-align"]

# Dolphin SDK libraries other than the existing OS/AI units: dolsdk2004 release flags (as used by
# mitsevox/mvp2005 and W2). CARDBlock.c, GXTev.c, dvdqueue.c and OSMessage.c match 100% with them.
cflags_dolphin_sdk = [
    "-nodefaults",
    "-proc gekko",
    "-fp hard",
    "-Cpp_exceptions off",
    "-enum int",
    "-char unsigned",
    "-warn pragmas",
    "-requireprotos",
    '-pragma "cats off"',
    "-O4,p",
    "-inline auto",
    "-I-",
    "-i include",
    "-i include/libc",
    "-i src/dolphin",
    "-D__GEKKO__",
    "-DSDK_REVISION=1",
    "-DNDEBUG=1",
]
# Per-library deviations reported by mitsevox/mvp2005 (unverified here).
cflags_dolphin_dvd = [f if f != "-char unsigned" else "-char signed" for f in cflags_dolphin_sdk]
cflags_dolphin_mtx = cflags_dolphin_dvd
cflags_dolphin_exi = [f if f != "-O4,p" else "-O3,p" for f in cflags_dolphin_sdk]


# Units not listed here are linked from the dtk split (assembly).
config.libs = [
    {
        "lib": "libgcc",
        "mw_version": "ProDG/3.9.3",
        "cflags": cflags_libgcc,
        "progress_category": "sdk",
        "objects": [
            Object(Matching, "libgcc/_main.c"),
            Object(NonMatching, "libgcc/tu_80413940.c", cflags=["-O2", "-G 1024"]),
        ],
    },
    {
        "lib": "dolphin_os",
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_dolphin_os,
        "progress_category": "sdk",
        "objects": [
            # Code-matched, not linkable: OS.c's .sdata/.data (__OSVersion, OSInit strings)
            # and original-assembly functions must be reproduced before it can link.
            Object(NonMatching, "dolphin/os/OS.c"),
        ],
    },
    {
        "lib": "dolphin_ai",
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_dolphin_ai,
        "progress_category": "sdk",
        "objects": [
            Object(NonMatching, "dolphin/ai/AI.c"),
        ],
    },
    {
        "lib": "game",
        "mw_version": "ProDG/3.9.3",
        "cflags": cflags_game,
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "game/tu_800034A0.cpp"),
            Object(NonMatching, "game/tu_800042B0.cpp"),
            Object(NonMatching, "game/tu_800057D8.cpp"),
            Object(NonMatching, "game/tu_80008540.cpp"),
            Object(NonMatching, "game/tu_8000C2C4.cpp"),
            Object(NonMatching, "game/tu_8000D650.cpp"),
            Object(NonMatching, "game/tu_8000E618.cpp"),
            Object(NonMatching, "game/tu_8000F598.cpp"),
            Object(NonMatching, "game/tu_800101C0.cpp"),
            Object(NonMatching, "game/tu_80010E38.cpp"),
            Object(NonMatching, "game/tu_80011950.cpp"),
            Object(NonMatching, "game/tu_800124C0.cpp"),
            Object(NonMatching, "game/tu_80013078.cpp"),
            Object(NonMatching, "game/tu_80013C88.cpp"),
            Object(NonMatching, "game/tu_800147D8.cpp"),
            Object(NonMatching, "game/tu_80015388.cpp"),
            Object(NonMatching, "game/tu_80015E58.cpp"),
            Object(NonMatching, "game/tu_80016B40.cpp"),
            Object(NonMatching, "game/tu_800175F8.cpp"),
            Object(NonMatching, "game/tu_80018310.cpp"),
            Object(NonMatching, "game/tu_80018E98.cpp"),
            Object(NonMatching, "game/tu_80019B30.cpp"),
            Object(NonMatching, "game/tu_8001A6B8.cpp"),
            Object(NonMatching, "game/tu_8001B190.cpp"),
            Object(NonMatching, "game/tu_8001BA78.cpp"),
            Object(NonMatching, "game/tu_8001CACC.cpp"),
            Object(NonMatching, "game/tu_8001D7F8.cpp"),
            Object(NonMatching, "game/tu_8001E444.cpp"),
            Object(NonMatching, "game/tu_8001F64C.cpp"),
            Object(NonMatching, "game/tu_8001FDA8.cpp"),
            Object(NonMatching, "game/tu_80021BE8.cpp"),
            Object(NonMatching, "game/tu_800239F4.cpp"),
            Object(NonMatching, "game/tu_80026A48.cpp"),
            Object(NonMatching, "game/tu_80029000.cpp"),
            Object(NonMatching, "game/tu_8002B430.cpp"),
            Object(NonMatching, "game/tu_8002D15C.cpp"),
            Object(NonMatching, "game/tu_8002EB80.cpp"),
            Object(NonMatching, "game/tu_80030778.cpp"),
            Object(NonMatching, "game/tu_800320B8.cpp"),
            Object(NonMatching, "game/tu_80033BC8.cpp"),
            Object(NonMatching, "game/tu_80034BBC.cpp"),
            Object(NonMatching, "game/tu_80035DF0.cpp"),
            Object(NonMatching, "game/tu_80037250.cpp"),
            Object(NonMatching, "game/tu_80039B04.cpp"),
            Object(NonMatching, "game/tu_8003AEE4.cpp"),
            Object(NonMatching, "game/tu_8003C9A0.cpp"),
            Object(NonMatching, "game/tu_8003DF80.cpp"),
            Object(NonMatching, "game/tu_8003EF18.cpp"),
            Object(NonMatching, "game/tu_800401E4.cpp"),
            Object(NonMatching, "game/tu_80042DBC.cpp"),
            Object(NonMatching, "game/tu_800437AC.cpp"),
            Object(NonMatching, "game/tu_80044C10.cpp"),
            Object(NonMatching, "game/tu_80045C8C.cpp"),
            Object(NonMatching, "game/tu_80046964.cpp"),
            Object(NonMatching, "game/tu_80047B08.cpp"),
            Object(NonMatching, "game/tu_800493D4.cpp"),
            Object(NonMatching, "game/tu_8004B6BC.cpp"),
            Object(NonMatching, "game/tu_8004E364.cpp"),
            Object(NonMatching, "game/tu_80050A68.cpp"),
            Object(NonMatching, "game/tu_80052794.cpp"),
            Object(NonMatching, "game/tu_8005371C.cpp"),
            Object(NonMatching, "game/tu_80054874.cpp"),
            Object(NonMatching, "game/tu_80056A08.cpp"),
            Object(NonMatching, "game/tu_80058060.cpp"),
            Object(NonMatching, "game/tu_8005ADD0.cpp"),
            Object(NonMatching, "game/tu_8005C514.cpp"),
            Object(NonMatching, "game/tu_8005D268.cpp"),
            Object(NonMatching, "game/tu_8005DF2C.cpp"),
            Object(NonMatching, "game/tu_8005EDCC.cpp"),
            Object(NonMatching, "game/tu_8005F4E4.cpp"),
            Object(NonMatching, "game/tu_80060250.cpp"),
            Object(NonMatching, "game/tu_80060F94.cpp"),
            Object(NonMatching, "game/tu_80061C6C.cpp"),
            Object(NonMatching, "game/tu_80063648.cpp"),
            Object(NonMatching, "game/tu_80064D48.cpp"),
            Object(NonMatching, "game/tu_80067A20.cpp"),
            Object(NonMatching, "game/tu_80068380.cpp"),
            Object(NonMatching, "game/tu_80068CE0.cpp"),
            Object(NonMatching, "game/tu_8006902C.cpp"),
            Object(NonMatching, "game/tu_8006D05C.cpp"),
            Object(NonMatching, "game/tu_80070DDC.cpp"),
            Object(NonMatching, "game/tu_80073914.cpp"),
            Object(NonMatching, "game/tu_80077238.cpp"),
            Object(NonMatching, "game/tu_8007A4DC.cpp"),
            Object(NonMatching, "game/tu_8007B714.cpp"),
            Object(NonMatching, "game/tu_8007CAC4.cpp"),
            Object(NonMatching, "game/tu_8007DB74.cpp"),
            Object(NonMatching, "game/tu_8007F198.cpp"),
            Object(NonMatching, "game/tu_8007FF8C.cpp"),
            Object(NonMatching, "game/tu_80082248.cpp"),
            Object(NonMatching, "game/tu_80084910.cpp"),
            Object(NonMatching, "game/tu_80087A58.cpp"),
            Object(NonMatching, "game/tu_80089894.cpp"),
            Object(NonMatching, "game/tu_8008CE64.cpp"),
            Object(NonMatching, "game/tu_80090880.cpp"),
            Object(NonMatching, "game/tu_800928B0.cpp"),
            Object(NonMatching, "game/tu_80094578.cpp"),
            Object(NonMatching, "game/tu_800975A8.cpp"),
            Object(NonMatching, "game/tu_8009BC3C.cpp"),
            Object(NonMatching, "game/tu_8009FC5C.cpp"),
            Object(NonMatching, "game/tu_800A23F4.cpp"),
            Object(NonMatching, "game/tu_800A4668.cpp"),
            Object(NonMatching, "game/tu_800A8684.cpp"),
            Object(NonMatching, "game/tu_800A9858.cpp"),
            Object(NonMatching, "game/tu_800AB0E8.cpp"),
            Object(NonMatching, "game/tu_800ACDA0.cpp"),
            Object(NonMatching, "game/tu_800AF248.cpp"),
            Object(NonMatching, "game/tu_800B2AAC.cpp"),
            Object(NonMatching, "game/tu_800B5C68.cpp"),
            Object(NonMatching, "game/tu_800B8AF0.cpp"),
            Object(NonMatching, "game/tu_800BCD38.cpp"),
            Object(NonMatching, "game/tu_800C1438.cpp"),
            Object(NonMatching, "game/tu_800C2F90.cpp"),
            Object(NonMatching, "game/tu_800C5158.cpp"),
            Object(NonMatching, "game/tu_800C7A4C.cpp"),
            Object(NonMatching, "game/tu_800CB3A8.cpp"),
            Object(NonMatching, "game/tu_800CF178.cpp"),
            Object(NonMatching, "game/tu_800D1758.cpp"),
            Object(NonMatching, "game/tu_800D4D0C.cpp"),
            Object(NonMatching, "game/tu_800D833C.cpp"),
            Object(NonMatching, "game/tu_800DC0F4.cpp"),
            Object(NonMatching, "game/tu_800E0164.cpp"),
            Object(NonMatching, "game/tu_800E4234.cpp"),
            Object(NonMatching, "game/tu_800E8890.cpp"),
            Object(NonMatching, "game/tu_800EBF2C.cpp"),
            Object(NonMatching, "game/tu_800EE048.cpp"),
            Object(NonMatching, "game/tu_800F1AEC.cpp"),
            Object(NonMatching, "game/tu_800F56B4.cpp"),
            Object(NonMatching, "game/tu_800F92DC.cpp"),
            Object(NonMatching, "game/tu_800FD438.cpp"),
            Object(NonMatching, "game/tu_80101254.cpp"),
            Object(NonMatching, "game/tu_80104E24.cpp"),
            Object(NonMatching, "game/tu_80107F74.cpp"),
            Object(NonMatching, "game/tu_8010A0A4.cpp"),
            Object(NonMatching, "game/tu_8010E0F4.cpp"),
            Object(NonMatching, "game/tu_8011243C.cpp"),
            Object(NonMatching, "game/tu_801164AC.cpp"),
            Object(NonMatching, "game/tu_8011A518.cpp"),
            Object(NonMatching, "game/tu_8011C5E8.cpp"),
            Object(NonMatching, "game/tu_8012068C.cpp"),
            Object(NonMatching, "game/tu_80124738.cpp"),
            Object(NonMatching, "game/tu_801287AC.cpp"),
            Object(NonMatching, "game/tu_8012C8CC.cpp"),
            Object(NonMatching, "game/tu_80130DFC.cpp"),
            Object(NonMatching, "game/tu_80134A60.cpp"),
            Object(NonMatching, "game/tu_80137FFC.cpp"),
            Object(NonMatching, "game/tu_8013BE4C.cpp"),
            Object(NonMatching, "game/tu_8014013C.cpp"),
            Object(NonMatching, "game/tu_80144190.cpp"),
            Object(NonMatching, "game/tu_801445F4.cpp"),
            Object(NonMatching, "game/tu_80144CF0.cpp"),
            Object(NonMatching, "game/tu_80145858.cpp"),
            Object(NonMatching, "game/tu_80145ECC.cpp"),
            Object(NonMatching, "game/tu_801465AC.cpp"),
            Object(NonMatching, "game/tu_80147748.cpp"),
            Object(NonMatching, "game/tu_801498C0.cpp"),
            Object(NonMatching, "game/tu_8014BEA4.cpp"),
            Object(NonMatching, "game/tu_8014F47C.cpp"),
            Object(NonMatching, "game/tu_801527C8.cpp"),
            Object(NonMatching, "game/tu_801547AC.cpp"),
            Object(NonMatching, "game/tu_80156714.cpp"),
            Object(NonMatching, "game/tu_8015AA94.cpp"),
            Object(NonMatching, "game/tu_8015F164.cpp"),
            Object(NonMatching, "game/tu_80163390.cpp"),
            Object(NonMatching, "game/tu_80167DCC.cpp"),
            Object(NonMatching, "game/tu_8016BF30.cpp"),
            Object(NonMatching, "game/tu_8016F45C.cpp"),
            Object(NonMatching, "game/tu_8016F9A8.cpp"),
            Object(NonMatching, "game/tu_80170044.cpp"),
            Object(NonMatching, "game/tu_80171A10.cpp"),
            Object(NonMatching, "game/tu_80174318.cpp"),
            Object(NonMatching, "game/tu_80177C34.cpp"),
            Object(NonMatching, "game/tu_8017A930.cpp"),
            Object(NonMatching, "game/tu_8017D640.cpp"),
            Object(NonMatching, "game/tu_801800FC.cpp"),
            Object(NonMatching, "game/tu_8018423C.cpp"),
            Object(NonMatching, "game/tu_80188698.cpp"),
            Object(NonMatching, "game/tu_8018C9C8.cpp"),
            Object(NonMatching, "game/tu_80190A00.cpp"),
            Object(NonMatching, "game/tu_80194D44.cpp"),
            Object(NonMatching, "game/tu_80198DB8.cpp"),
            Object(NonMatching, "game/tu_8019C1F8.cpp"),
            Object(NonMatching, "game/tu_8019F8C0.cpp"),
            Object(NonMatching, "game/tu_801A22F4.cpp"),
            Object(NonMatching, "game/tu_801A57C8.cpp"),
            Object(NonMatching, "game/tu_801A96E0.cpp"),
            Object(NonMatching, "game/tu_801AB63C.cpp"),
            Object(NonMatching, "game/tu_801AE30C.cpp"),
            Object(NonMatching, "game/tu_801B23A8.cpp"),
            Object(NonMatching, "game/tu_801B460C.cpp"),
            Object(NonMatching, "game/tu_801B7FB0.cpp"),
            Object(NonMatching, "game/tu_801BAC74.cpp"),
            Object(NonMatching, "game/tu_801BDD60.cpp"),
            Object(NonMatching, "game/tu_801C16B0.cpp"),
            Object(NonMatching, "game/tu_801C2C64.cpp"),
            Object(NonMatching, "game/tu_801C6D2C.cpp"),
            Object(NonMatching, "game/tu_801CAFA0.cpp"),
            Object(NonMatching, "game/tu_801CF054.cpp"),
            Object(NonMatching, "game/tu_801D31D8.cpp"),
            Object(NonMatching, "game/tu_801D771C.cpp"),
            Object(NonMatching, "game/tu_801DB948.cpp"),
            Object(NonMatching, "game/tu_801DC918.cpp"),
            Object(NonMatching, "game/tu_801DEC20.cpp"),
            Object(NonMatching, "game/tu_801E2D84.cpp"),
            Object(NonMatching, "game/tu_801E6D88.cpp"),
            Object(NonMatching, "game/tu_801EA36C.cpp"),
            Object(NonMatching, "game/tu_801EE438.cpp"),
            Object(NonMatching, "game/tu_801F263C.cpp"),
            Object(NonMatching, "game/tu_801F6680.cpp"),
            Object(NonMatching, "game/tu_801FA73C.cpp"),
            Object(NonMatching, "game/tu_801FE850.cpp"),
            Object(NonMatching, "game/tu_802028E4.cpp"),
            Object(NonMatching, "game/tu_80206B08.cpp"),
            Object(NonMatching, "game/tu_8020ADC4.cpp"),
            Object(NonMatching, "game/tu_8020EE9C.cpp"),
            Object(NonMatching, "game/tu_80212AC0.cpp"),
            Object(NonMatching, "game/tu_80216CF4.cpp"),
            Object(NonMatching, "game/tu_8021ADDC.cpp"),
            Object(NonMatching, "game/tu_8021F080.cpp"),
            Object(NonMatching, "game/tu_8022309C.cpp"),
            Object(NonMatching, "game/tu_80227564.cpp"),
            Object(NonMatching, "game/tu_8022BB90.cpp"),
            Object(NonMatching, "game/tu_8022FE34.cpp"),
            Object(NonMatching, "game/tu_80233F08.cpp"),
            Object(NonMatching, "game/tu_802362A8.cpp"),
            Object(NonMatching, "game/tu_8023A6C8.cpp"),
            Object(NonMatching, "game/tu_8023DB8C.cpp"),
            Object(NonMatching, "game/tu_80241C24.cpp"),
            Object(NonMatching, "game/tu_80246D04.cpp"),
            Object(NonMatching, "game/tu_8024B99C.cpp"),
            Object(NonMatching, "game/tu_8024EF40.cpp"),
            Object(NonMatching, "game/tu_802520F8.cpp"),
            Object(NonMatching, "game/tu_802547C0.cpp"),
            Object(NonMatching, "game/tu_80256C80.cpp"),
            Object(NonMatching, "game/tu_8025877C.cpp"),
            Object(NonMatching, "game/tu_8025B59C.cpp"),
            Object(NonMatching, "game/tu_8025F708.cpp"),
            Object(NonMatching, "game/tu_80264378.cpp"),
            Object(NonMatching, "game/tu_80268190.cpp"),
            Object(NonMatching, "game/tu_8026C414.cpp"),
            Object(NonMatching, "game/tu_80275F24.cpp"),
            Object(NonMatching, "game/tu_8029B6C8.cpp"),
            Object(NonMatching, "game/tu_802AA7A4.cpp"),
            Object(NonMatching, "game/tu_802ACD88.cpp"),
            Object(NonMatching, "game/tu_802B0ACC.cpp"),
            Object(NonMatching, "game/tu_802B5234.cpp"),
            Object(NonMatching, "game/tu_802B9218.cpp"),
            Object(NonMatching, "game/tu_802BB4BC.cpp"),
            Object(NonMatching, "game/tu_802BF974.cpp"),
            Object(NonMatching, "game/tu_802C3974.cpp"),
            Object(NonMatching, "game/tu_802C79F0.cpp"),
            Object(NonMatching, "game/tu_802CBD04.cpp"),
            Object(NonMatching, "game/tu_802CFED4.cpp"),
            Object(NonMatching, "game/tu_802D3E44.cpp"),
            Object(NonMatching, "game/tu_802D73B4.cpp"),
            Object(NonMatching, "game/tu_802DBCB8.cpp"),
            Object(NonMatching, "game/tu_802DE2C8.cpp"),
            Object(NonMatching, "game/tu_802E22EC.cpp"),
            Object(NonMatching, "game/tu_802E6464.cpp"),
            Object(NonMatching, "game/tu_802EBA64.cpp"),
            Object(NonMatching, "game/tu_802EFF28.cpp"),
            Object(NonMatching, "game/tu_802F42A4.cpp"),
            Object(NonMatching, "game/tu_802F8324.cpp"),
            Object(NonMatching, "game/tu_802FCAC0.cpp"),
            Object(NonMatching, "game/tu_80300848.cpp"),
            Object(NonMatching, "game/tu_80304858.cpp"),
            Object(NonMatching, "game/tu_80308874.cpp"),
            Object(NonMatching, "game/tu_8030C5D8.cpp"),
            Object(NonMatching, "game/tu_80310934.cpp"),
            Object(NonMatching, "game/tu_80313C14.cpp"),
            Object(NonMatching, "game/tu_80317B88.cpp"),
            Object(NonMatching, "game/tu_8031B354.cpp"),
            Object(NonMatching, "game/tu_8031D988.cpp"),
            Object(NonMatching, "game/tu_80321A78.cpp"),
            Object(NonMatching, "game/tu_80324A48.cpp"),
            Object(NonMatching, "game/tu_80327214.cpp"),
            Object(NonMatching, "game/tu_8032AC58.cpp"),
            Object(NonMatching, "game/tu_8032ECD8.cpp"),
            Object(NonMatching, "game/tu_80331C60.cpp"),
            Object(NonMatching, "game/tu_80334AF0.cpp"),
            Object(NonMatching, "game/tu_80338ECC.cpp"),
            Object(NonMatching, "game/tu_8033CED8.cpp"),
            Object(NonMatching, "game/tu_8033FAFC.cpp"),
            Object(NonMatching, "game/tu_803401A8.cpp"),
            Object(NonMatching, "game/tu_803414A4.cpp"),
            Object(NonMatching, "game/tu_80341B78.cpp"),
            Object(NonMatching, "game/tu_80344180.cpp"),
            Object(NonMatching, "game/tu_80344E90.cpp"),
            Object(NonMatching, "game/tu_8034699C.cpp"),
            Object(NonMatching, "game/tu_80347F7C.cpp"),
            Object(NonMatching, "game/tu_80349880.cpp"),
            Object(NonMatching, "game/tu_8034B370.cpp"),
            Object(NonMatching, "game/tu_8034B8C0.cpp"),
            Object(NonMatching, "game/tu_8034D550.cpp"),
            Object(NonMatching, "game/tu_8034F350.cpp"),
            Object(NonMatching, "game/tu_80351150.cpp"),
            Object(NonMatching, "game/tu_80352E64.cpp"),
            Object(NonMatching, "game/tu_80353930.cpp"),
            Object(NonMatching, "game/tu_803543FC.cpp"),
            Object(NonMatching, "game/tu_80355A6C.cpp"),
            Object(NonMatching, "game/tu_803560F8.cpp"),
            Object(NonMatching, "game/tu_8035688C.cpp"),
            Object(NonMatching, "game/tu_8035726C.cpp"),
            Object(NonMatching, "game/tu_80357A70.cpp"),
            Object(NonMatching, "game/tu_803597C4.cpp"),
            Object(NonMatching, "game/tu_8035A2D0.cpp"),
            Object(NonMatching, "game/tu_8035AB44.cpp"),
            Object(NonMatching, "game/tu_8035B60C.cpp"),
            Object(NonMatching, "game/tu_8035BF0C.cpp"),
            Object(NonMatching, "game/tu_8035DA48.cpp"),
            Object(NonMatching, "game/tu_8035E50C.cpp"),
            Object(NonMatching, "game/tu_8035ECE4.cpp"),
            Object(NonMatching, "game/tu_8035F63C.cpp"),
            Object(NonMatching, "game/tu_80360168.cpp"),
            Object(NonMatching, "game/tu_803606B0.cpp"),
            Object(NonMatching, "game/tu_80360C18.cpp"),
            Object(NonMatching, "game/tu_80361580.cpp"),
            Object(NonMatching, "game/tu_80361F98.cpp"),
            Object(NonMatching, "game/tu_80362A30.cpp"),
            # EA-lib flags, not game flags: see DECISIONS (fn_8036344C matches only at -O2 without -ffloat-store).
            Object(NonMatching, "game/tu_80362FB4.cpp", cflags=[*cflags_ealib, "-Iinclude"]),
            Object(NonMatching, "game/tu_80365C10.cpp", cflags=[*cflags_ealib, "-Iinclude"]),
            Object(NonMatching, "animation/choosers/tu_8026DDE8.cpp"),
            Object(NonMatching, "animation/choosers/randomchooser.cpp"),
            Object(NonMatching, "animation/choosers/playeridchooser.cpp"),
            Object(Matching, "animation/choosers/tu_80271748.cpp"),
            Object(Matching, "animation/choosers/tu_80271940.cpp"),
            Object(Matching, "animation/choosers/tu_80271C64.cpp"),
            Object(NonMatching, "animation/choosers/tu_80271F14.cpp"),
            Object(NonMatching, "animation/choosers/tu_80272B20.cpp"),
            Object(NonMatching, "animation/choosers/randomloadedchooser.cpp"),
            Object(NonMatching, "animation/choosers/tu_80279AE4.cpp"),
            Object(NonMatching, "animation/goals/tu_8027A84C.cpp"),
            Object(NonMatching, "animation/goals/tu_8027C728.cpp"),
            Object(NonMatching, "animation/goals/tu_8027DE3C.cpp"),
            Object(NonMatching, "animation/goals/tu_8027FD64.cpp"),
            Object(NonMatching, "animation/goals/tu_80283934.cpp"),
            Object(NonMatching, "animation/goals/tu_80287600.cpp"),
            Object(NonMatching, "animation/goals/tu_8028989C.cpp"),
            Object(NonMatching, "animation/goals/tu_8028B194.cpp"),
            Object(NonMatching, "animation/goals/tu_8028C6B8.cpp"),
            Object(NonMatching, "animation/goals/tu_8028F178.cpp"),
            Object(NonMatching, "animation/goals/tu_802914C8.cpp"),
            Object(NonMatching, "animation/goals/tu_80296C78.cpp"),
            Object(NonMatching, "animation/goals/tu_80299920.cpp"),
            Object(NonMatching, "animation/goals/tu_8029B70C.cpp"),
            Object(NonMatching, "animation/goals/tu_8029EE50.cpp"),
            Object(NonMatching, "animation/warps/tu_802A3704.cpp"),
            Object(NonMatching, "animation/warps/tu_802A4584.cpp"),
            Object(NonMatching, "animation/tu_802AC2CC.cpp"),
            Object(NonMatching, "animation/tu_802AB810.cpp"),
            Object(NonMatching, "animation/tu_802A9A04.cpp"),
            Object(NonMatching, "animation/events/tu_802A89C8.cpp"),
            Object(NonMatching, "animation/events/tu_802A79BC.cpp"),
            Object(NonMatching, "animation/tu_802A6334.cpp"),
        ],
    },
    {
        # .frontend_codeoverlay (split as .feoverlay). Game code; see docs/DECISIONS.md.
        "lib": "fe_overlay",
        "mw_version": "ProDG/3.9.3",
        "cflags": cflags_game,
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "fe/tu_8043FDC0.cpp"),
            Object(NonMatching, "fe/tu_804439E4.cpp"),
            Object(NonMatching, "fe/tu_80446CE8.cpp"),
            Object(NonMatching, "fe/tu_80448E18.cpp"),
            Object(NonMatching, "fe/tu_8044C508.cpp"),
            Object(NonMatching, "fe/tu_8044F550.cpp"),
            Object(NonMatching, "fe/tu_80452120.cpp"),
            Object(NonMatching, "fe/tu_80455038.cpp"),
            Object(NonMatching, "fe/tu_80459228.cpp"),
            Object(NonMatching, "fe/tu_8045B134.cpp"),
            Object(NonMatching, "fe/tu_8045EDDC.cpp"),
            Object(NonMatching, "fe/tu_80462504.cpp"),
            Object(NonMatching, "fe/tu_80464090.cpp"),
            Object(NonMatching, "fe/tu_804654A0.cpp"),
            Object(NonMatching, "fe/tu_8046C6F8.cpp"),
            Object(NonMatching, "fe/tu_8046F770.cpp"),
            Object(NonMatching, "fe/tu_80471EBC.cpp"),
            Object(NonMatching, "fe/tu_804740A8.cpp"),
            Object(NonMatching, "fe/tu_80477068.cpp"),
            Object(NonMatching, "fe/tu_8047BB8C.cpp"),
            Object(NonMatching, "fe/tu_8047D454.cpp"),
            Object(NonMatching, "fe/tu_80481634.cpp"),
            Object(NonMatching, "fe/tu_8048511C.cpp"),
            Object(NonMatching, "fe/tu_80488CDC.cpp"),
            Object(NonMatching, "fe/tu_8048E6A0.cpp"),
            Object(NonMatching, "fe/tu_80492680.cpp"),
            Object(NonMatching, "fe/tu_804987EC.cpp"),
            Object(NonMatching, "fe/tu_8049B0CC.cpp"),
            Object(NonMatching, "fe/tu_8049E0BC.cpp"),
            Object(NonMatching, "fe/tu_804A2AB4.cpp"),
            Object(NonMatching, "fe/tu_804A721C.cpp"),
            Object(NonMatching, "fe/tu_804AA58C.cpp"),
            Object(NonMatching, "fe/tu_804ABCBC.cpp"),
            Object(NonMatching, "fe/tu_804AECD0.cpp"),
            Object(NonMatching, "fe/tu_804B13FC.cpp"),
            Object(NonMatching, "fe/tu_804B38C4.cpp"),
            Object(NonMatching, "fe/tu_804B4908.cpp"),
            Object(NonMatching, "fe/tu_804B7C98.cpp"),
            Object(NonMatching, "fe/tu_804B985C.cpp"),
            Object(NonMatching, "fe/tu_804BB110.cpp"),
            Object(NonMatching, "fe/tu_804BE560.cpp"),
            Object(NonMatching, "fe/tu_804BFB3C.cpp"),
            Object(NonMatching, "fe/tu_804C19EC.cpp"),
            Object(NonMatching, "fe/tu_804C3ECC.cpp"),
            Object(NonMatching, "fe/tu_804C713C.cpp"),
            Object(NonMatching, "fe/tu_804C931C.cpp"),
            Object(NonMatching, "fe/tu_804CB430.cpp"),
            Object(NonMatching, "fe/tu_804CE408.cpp"),
            Object(NonMatching, "fe/tu_804D08D0.cpp"),
            Object(NonMatching, "fe/tu_804D2AC0.cpp"),
            Object(NonMatching, "fe/tu_804D3E00.cpp"),
            Object(NonMatching, "fe/tu_804D6180.cpp"),
            Object(NonMatching, "fe/tu_804DA10C.cpp"),
            Object(NonMatching, "fe/tu_804DC128.cpp"),
            Object(NonMatching, "fe/tu_804DDAB4.cpp"),
            Object(NonMatching, "fe/tu_804DE730.cpp"),
            Object(NonMatching, "fe/tu_804E02E0.cpp"),
            Object(NonMatching, "fe/tu_804E1A6C.cpp"),
            Object(NonMatching, "fe/tu_804E5180.cpp"),
            Object(NonMatching, "fe/tu_804E750C.cpp"),
            Object(NonMatching, "fe/tu_804EA2E4.cpp"),
            Object(NonMatching, "fe/tu_804ECDE0.cpp"),
            Object(NonMatching, "fe/tu_804F81E0.cpp"),
            Object(NonMatching, "fe/tu_804FE34C.cpp"),
            Object(NonMatching, "fe/tu_804FF6B4.cpp"),
            Object(NonMatching, "fe/tu_805002DC.cpp"),
            Object(NonMatching, "fe/tu_80505484.cpp"),
            Object(NonMatching, "fe/tu_80508C98.cpp"),
            Object(NonMatching, "fe/tu_8050C9DC.cpp"),
            Object(NonMatching, "fe/tu_80512D10.cpp"),
            Object(NonMatching, "fe/tu_80516990.cpp"),
            Object(NonMatching, "fe/tu_80519600.cpp"),
            Object(NonMatching, "fe/tu_8051E878.cpp"),
            Object(NonMatching, "fe/tu_80520BE0.cpp"),
            Object(NonMatching, "fe/tu_805283C4.cpp"),
            Object(NonMatching, "fe/tu_80528B78.cpp"),
            Object(NonMatching, "fe/tu_80529364.cpp"),
        ],
    },
    {
        # .database_codeoverlay (split as .dboverlay). Game code; see docs/DECISIONS.md.
        "lib": "db_overlay",
        "mw_version": "ProDG/3.9.3",
        "cflags": cflags_game,
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "db/tu_8052A220.cpp"),
            Object(NonMatching, "db/tu_8052CA60.cpp"),
            Object(NonMatching, "db/tu_8052E4C0.cpp"),
            Object(NonMatching, "db/tu_8052FF10.cpp"),
            Object(NonMatching, "db/tu_80531A20.cpp"),
            Object(NonMatching, "db/tu_80534078.cpp"),
            Object(NonMatching, "db/tu_80535360.cpp"),
            Object(NonMatching, "db/tu_8053967C.cpp"),
            Object(NonMatching, "db/tu_8053CC9C.cpp"),
            Object(NonMatching, "db/tu_8053E240.cpp"),
            Object(NonMatching, "db/tu_80541F40.cpp"),
            Object(NonMatching, "db/tu_805467E0.cpp"),
            Object(NonMatching, "db/tu_805495DC.cpp"),
            Object(NonMatching, "db/tu_8054CBBC.cpp"),
            Object(NonMatching, "db/tu_8054FA04.cpp"),
            Object(NonMatching, "db/tu_80554628.cpp"),
            Object(NonMatching, "db/tu_8055A3B0.cpp"),
            Object(NonMatching, "db/tu_8055F730.cpp"),
            Object(NonMatching, "db/tu_80563954.cpp"),
            Object(NonMatching, "db/tu_80565FD4.cpp"),
            Object(NonMatching, "db/tu_8056A248.cpp"),
            Object(NonMatching, "db/tu_8056BAEC.cpp"),
            Object(NonMatching, "db/tu_8056EC68.cpp"),
            Object(NonMatching, "db/tu_805721F8.cpp"),
            Object(NonMatching, "db/tu_80574AE4.cpp"),
            Object(NonMatching, "db/tu_8057CDB8.cpp"),
            Object(NonMatching, "db/tu_8058154C.cpp"),
            Object(NonMatching, "db/tu_80582578.cpp"),
            Object(NonMatching, "db/tu_80584CBC.cpp"),
            Object(NonMatching, "db/tu_805881E4.cpp"),
            Object(NonMatching, "db/tu_8058BF2C.cpp"),
            Object(NonMatching, "db/tu_8058E5B8.cpp"),
            Object(NonMatching, "db/tu_805902E0.cpp"),
            Object(NonMatching, "db/tu_8059377C.cpp"),
            Object(NonMatching, "db/tu_805942E0.cpp"),
            Object(NonMatching, "db/tu_80596D88.cpp"),
            Object(NonMatching, "db/tu_80599594.cpp"),
            Object(NonMatching, "db/tu_8059A728.cpp"),
            Object(NonMatching, "db/tu_8059FE24.cpp"),
            Object(NonMatching, "db/tu_805A1A9C.cpp"),
            Object(NonMatching, "db/tu_805A2604.cpp"),
        ],
    },
    {
        "lib": "ealib",
        "mw_version": "ProDG/3.9.3",
        "cflags": cflags_ealib,
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "ealib/tu_803663B0.cpp"),
            Object(NonMatching, "ealib/tu_803666EC.cpp"),
            Object(NonMatching, "ealib/tu_80367140.cpp"),
            Object(NonMatching, "ealib/tu_80367658.cpp"),
            Object(NonMatching, "ealib/tu_803682A8.cpp"),
            Object(NonMatching, "ealib/tu_80368E64.cpp"),
            Object(NonMatching, "ealib/tu_80369878.cpp"),
            Object(NonMatching, "ealib/tu_8036A490.cpp"),
            Object(NonMatching, "ealib/tu_8036AEE4.cpp"),
            Object(NonMatching, "ealib/tu_8036BECC.cpp"),
            Object(NonMatching, "ealib/tu_8036CC08.cpp"),
            Object(NonMatching, "ealib/tu_8036D8AC.cpp"),
            Object(NonMatching, "ealib/tu_8036E65C.cpp"),
            Object(NonMatching, "ealib/tu_8036FEA0.cpp"),
            Object(NonMatching, "ealib/tu_803708F4.cpp"),
            Object(NonMatching, "ealib/tu_80371348.cpp"),
            Object(NonMatching, "ealib/tu_80371D9C.cpp"),
            Object(NonMatching, "ealib/tu_803728E8.cpp"),
            Object(NonMatching, "ealib/tu_80372F60.cpp"),
            Object(NonMatching, "ealib/tu_80373AD8.cpp"),
            Object(NonMatching, "ealib/tu_80374588.cpp"),
            Object(NonMatching, "ealib/tu_80375038.cpp"),
            Object(NonMatching, "ealib/tu_80375AE8.cpp"),
            Object(NonMatching, "ealib/tu_80376598.cpp"),
            Object(NonMatching, "ealib/tu_8036F44C.cpp"),
            Object(NonMatching, "ealib/tu_8038BC58.cpp"),
            Object(NonMatching, "ealib/tu_803BA9DC.cpp"),
            Object(NonMatching, "ealib/tu_803BD944.cpp"),
            Object(NonMatching, "ealib/tu_803BE8BC.cpp"),
            Object(NonMatching, "ealib/tu_803C1DD0.cpp"),
            Object(NonMatching, "ealib/tu_803CB728.cpp"),
            Object(NonMatching, "ealib/tu_803CECA4.cpp"),
            Object(NonMatching, "ealib/tu_803D2B20.cpp"),
            Object(NonMatching, "ealib/tu_803D50E4.cpp"),
            Object(NonMatching, "ealib/tu_803D7830.cpp"),
            Object(NonMatching, "ealib/tu_803D8234.cpp"),
            Object(NonMatching, "ealib/tu_803D9C34.cpp"),
            Object(NonMatching, "ealib/tu_803DA188.cpp"),
            Object(NonMatching, "ealib/tu_803DA4EC.cpp"),
            Object(NonMatching, "ealib/tu_803DBFF4.cpp"),
            Object(NonMatching, "ealib/tu_803DDCD4.cpp"),
            Object(NonMatching, "ealib/tu_803DE414.cpp"),
            Object(NonMatching, "ealib/tu_803E097C.cpp"),
            Object(NonMatching, "ealib/tu_803E0ACC.cpp"),
            Object(NonMatching, "ealib/tu_803E1F98.cpp"),
            Object(NonMatching, "ealib/tu_803E2248.cpp"),
            Object(NonMatching, "ealib/tu_803E3280.cpp"),
            Object(NonMatching, "ealib/tu_803E3C08.cpp"),
            Object(NonMatching, "ealib/tu_803E6FB8.cpp"),
            Object(NonMatching, "ealib/tu_803E9C20.cpp"),
            Object(NonMatching, "ealib/tu_803EAF50.cpp"),
        ],
    },
    {
        "lib": "ealibs",
        "mw_version": "ProDG/3.9.3",
        "cflags": cflags_ealib,
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "ealibs/tu_803D7ED4.cpp"),
            Object(NonMatching, "ealibs/tu_803D9FE8.cpp"),
        ],
    },
    {
        "lib": "gamelib",
        "mw_version": "ProDG/3.9.3",
        "cflags": cflags_gamelib,
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "gamelib/tu_80377048.cpp"),
            Object(NonMatching, "gamelib/tu_80377CD4.cpp"),
            Object(NonMatching, "gamelib/tu_80378D70.cpp"),
            Object(NonMatching, "gamelib/tu_8037B3AC.cpp"),
            Object(NonMatching, "gamelib/tu_8037C764.cpp"),
            Object(NonMatching, "gamelib/tu_8037E64C.cpp"),
            Object(NonMatching, "gamelib/tu_80382BB8.cpp"),
            Object(NonMatching, "gamelib/tu_80383E00.cpp"),
            Object(NonMatching, "gamelib/tu_80387E28.cpp"),
            Object(NonMatching, "gamelib/tu_8038B938.cpp"),
        ],
    },
    {
        "lib": "ealib_sda",
        "mw_version": "ProDG/3.9.3",
        "cflags": cflags_ealib_sda,
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "ealib/tu_8038EC58.cpp"),
            Object(NonMatching, "ealib/tu_8038F73C.cpp"),
            Object(NonMatching, "ealib/tu_803912F8.cpp", cflags=cflags_ealib_nsr),
            Object(NonMatching, "ealib/tu_803927E4.cpp", cflags=cflags_ealib_nsr),
            Object(NonMatching, "ealib/tu_80394744.cpp"),
            Object(NonMatching, "ealib/tu_803959E0.cpp"),
            Object(NonMatching, "ealib/tu_80397CAC.cpp"),
            Object(NonMatching, "ealib/tu_8039B3E4.cpp"),
            Object(NonMatching, "ealib/tu_803A0310.cpp"),
            Object(NonMatching, "ealib/tu_803EB2AC.cpp", cflags=cflags_ealib_sda_nsr),
            Object(NonMatching, "ealib/tu_803EBF90.cpp"),
            Object(NonMatching, "ealib/tu_803ED700.cpp"),
            Object(NonMatching, "ealib/tu_803EE8F8.cpp"),
            Object(NonMatching, "ealib/tu_803F00FC.cpp"),
            Object(NonMatching, "ealib/tu_803F2000.cpp"),
            Object(NonMatching, "ealib/tu_803F73B0.cpp"),
            Object(NonMatching, "ealib/tu_803F9350.cpp"),
            Object(NonMatching, "ealib/tu_803FAE94.cpp"),
            Object(NonMatching, "ealib/tu_803FBF54.cpp"),
            Object(NonMatching, "ealib/tu_803FEB34.cpp"),
            Object(NonMatching, "ealib/tu_803FFD9C.cpp"),
            Object(NonMatching, "ealib/tu_80400DA4.cpp"),
            Object(NonMatching, "ealib/tu_804027DC.cpp"),
        ],
    },
    {
        "lib": "snd",
        "mw_version": "ProDG/3.9.3",
        "cflags": cflags_snd,
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "snd/cmn/saems.c"),
            Object(NonMatching, "snd/tu_803A6B64.cpp"),
            Object(NonMatching, "snd/tu_803A6D80.cpp"),
            Object(NonMatching, "snd/cmn/salloc.c"),
            Object(NonMatching, "snd/tu_803A81E0.cpp"),
            Object(Matching, "snd/cmn/sballoc.c"),
            Object(Matching, "snd/cmn/sbhdrcpy.c"),
            Object(Matching, "snd/cmn/sbhdrsze.c"),
            Object(NonMatching, "snd/tu_803A8548.cpp"),
            Object(Matching, "snd/cmn/sbplay.c"),
            Object(NonMatching, "snd/tu_803A8648.cpp"),
            Object(Matching, "snd/cmn/sbvalid.c"),
            Object(Matching, "snd/cmn/scheckpo.c"),
            Object(NonMatching, "snd/tu_803A8860.cpp"),
            Object(Matching, "snd/cmn/smemcpy.c"),
            Object(Matching, "snd/cmn/smemman.c"),
            Object(NonMatching, "snd/tu_803A914C.cpp"),
            Object(Matching, "snd/cmn/spitch.c"),
            Object(NonMatching, "snd/tu_803A9204.cpp"),
            Object(NonMatching, "snd/tu_803A9830.cpp"),
            Object(NonMatching, "snd/cmn/sstgetpv.c"),
            Object(NonMatching, "snd/tu_803AB310.cpp"),
            Object(NonMatching, "snd/tu_803AC88C.cpp"),
            Object(NonMatching, "snd/tu_803AFDC0.cpp"),
            Object(NonMatching, "snd/tu_803B21AC.cpp"),
            Object(Matching, "snd/cmn/sctrldry.cpp"),
            Object(NonMatching, "snd/tu_803B3E18.cpp"),
            Object(NonMatching, "snd/cmn/sgetpvol.c"),
            Object(NonMatching, "snd/tu_803B4074.cpp"),
            Object(Matching, "snd/cmn/spatkey.c"),
            Object(NonMatching, "snd/tu_803B4BEC.cpp"),
            Object(NonMatching, "snd/tu_803B6AF8.cpp"),
            Object(Matching, "snd/cmn/sattrdef.c"),
            Object(NonMatching, "snd/tu_803B7DA0.cpp"),
            Object(NonMatching, "snd/tu_803B998C.cpp"),
        ],
    },
    {
        "lib": "libsn",
        "mw_version": "ProDG/3.9.3",
        "cflags": cflags_libsn,
        "progress_category": "sdk",
        "objects": [
            Object(NonMatching, "libsn/tu_80403E80.c"),
            Object(NonMatching, "libsn/FSasync.c"),
            Object(NonMatching, "libsn/tu_80407604.c"),
            Object(NonMatching, "libsn/dummy.c"),
        ],
    },
    {
        "lib": "libc",
        "mw_version": "ProDG/3.9.3",
        "cflags": cflags_libc,
        "progress_category": "sdk",
        "objects": [
            Object(Matching, "libc/fclose.c"),
            Object(Matching, "libc/fflush.c"),
            Object(NonMatching, "libc/fopen.c"),
            Object(Matching, "libc/fprintf.c"),
            Object(Matching, "libc/fseek.c"),
            Object(Matching, "libc/fwalk.c"),
            Object(Matching, "libc/makebuf.c"),
            Object(NonMatching, "libc/printf.c"),
            Object(Matching, "libc/refill.c"),
            Object(Matching, "libc/sprintf.c"),
            Object(Matching, "libc/sscanf.c"),
            Object(Matching, "libc/stdio.c"),
            Object(NonMatching, "libc/vfscanf.c"),
            Object(Matching, "libc/vprintf.c"),
            Object(Matching, "libc/vsprintf.c"),
            Object(NonMatching, "libc/assert.c"),
            Object(NonMatching, "libc/atexit.c"),
            Object(Matching, "libc/atof.c"),
            Object(Matching, "libc/atoi.c"),
            Object(Matching, "libc/bsearch.c"),
            Object(NonMatching, "libc/exit.c"),
            Object(NonMatching, "libc/mbtowc_r.c"),
            Object(Matching, "libc/qsort.c"),
            Object(Matching, "libc/rand.c"),
            Object(NonMatching, "libc/tu_8040ABC4.c"),
            Object(NonMatching, "libc/strtod2.c"),
            Object(NonMatching, "libc/strtoul.c"),
            Object(Matching, "libc/memcmp.c"),
            Object(Matching, "libc/memcpy.c"),
            Object(Matching, "libc/memmove.c"),
            Object(Matching, "libc/memset.c"),
            Object(NonMatching, "libc/strcasecmp.c"),
            Object(Matching, "libc/strcat.c"),
            Object(Matching, "libc/strchr.c"),
            Object(Matching, "libc/strcmp.c"),
            Object(Matching, "libc/strcpy.c"),
            Object(Matching, "libc/strlen.c"),
            Object(NonMatching, "libc/strlwr.c"),
            Object(Matching, "libc/strncmp.c"),
            Object(Matching, "libc/strncpy.c"),
            Object(Matching, "libc/strrchr.c"),
            Object(Matching, "libc/strstr.c"),
            Object(Matching, "libc/strtok.c"),
            Object(Matching, "libc/strtok_r.c"),
            Object(NonMatching, "libc/vfprintf.c"),
            Object(NonMatching, "libc/vfiprintf.c"),
            Object(NonMatching, "libc/strtol.c"),
            Object(NonMatching, "libc/isdigit.c"),
            Object(NonMatching, "libc/isspace.c"),
            Object(NonMatching, "libc/errno.c"),
            Object(NonMatching, "libc/locale.c"),
            Object(NonMatching, "libc/math_support.c"),
            Object(Matching, "libc/closer.c"),
            Object(Matching, "libc/fstatr.c"),
            Object(Matching, "libc/lseekr.c"),
            Object(Matching, "libc/openr.c"),
            Object(Matching, "libc/readr.c"),
            Object(Matching, "libc/writer.c"),
            Object(Matching, "libc/fiprintf.c"),
            Object(Matching, "libc/flags.c"),
            Object(Matching, "libc/fread.c"),
            Object(NonMatching, "libc/ungetc.c"),
            Object(NonMatching, "libc/abort.c"),
            Object(Matching, "libc/memchr.c"),
            Object(NonMatching, "libc/tolower.c"),
        ],
    },
    {
        "lib": "libm",
        "mw_version": "ProDG/3.9.3",
        "cflags": cflags_libm,
        "progress_category": "sdk",
        "objects": [
            Object(NonMatching, "libm/e_exp.c"),
            Object(NonMatching, "libm/e_log.cpp"),
            Object(Matching, "libm/e_sqrt.cpp"),
            Object(NonMatching, "libm/s_ceil.c"),
            Object(NonMatching, "libm/s_cos.cpp"),
            Object(Matching, "libm/s_fabs.cpp"),
            Object(NonMatching, "libm/s_floor.cpp"),
            Object(NonMatching, "libm/s_sin.c"),
            Object(NonMatching, "libm/ef_acos.cpp"),
            Object(NonMatching, "libm/ef_asin.cpp"),
            Object(NonMatching, "libm/ef_atan2.cpp"),
            Object(NonMatching, "libm/ef_log.c"),
            Object(Matching, "libm/ef_sqrt.cpp"),
            Object(NonMatching, "libm/sf_atan.cpp"),
            Object(NonMatching, "libm/sf_ceil.c"),
            Object(NonMatching, "libm/sf_cos.cpp"),
            Object(Matching, "libm/sf_fabs.cpp"),
            Object(NonMatching, "libm/sf_floor.cpp"),
            Object(NonMatching, "libm/sf_sin.cpp"),
            Object(NonMatching, "libm/sf_tan.cpp"),
            Object(NonMatching, "libm/k_cos.cpp"),
            Object(NonMatching, "libm/k_sin.cpp"),
            Object(NonMatching, "libm/e_rem_pio2.cpp"),
            Object(NonMatching, "libm/kf_cos.cpp"),
            Object(NonMatching, "libm/kf_sin.cpp"),
            Object(NonMatching, "libm/kf_tan.cpp"),
            Object(NonMatching, "libm/ef_rem_pio2.cpp"),
            Object(NonMatching, "libm/k_rem_pio2.cpp"),
            Object(NonMatching, "libm/kf_rem_pio2.cpp"),
            Object(NonMatching, "libm/s_scalbn.cpp"),
            Object(NonMatching, "libm/sf_scalbn.cpp"),
            Object(Matching, "libm/s_copysign.cpp"),
            Object(Matching, "libm/sf_copysign.cpp"),
        ],
    },
    {
        "lib": "dolphin_sdk",
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_dolphin_sdk,
        "progress_category": "sdk",
        "objects": [
            Object(NonMatching, "dolphin/amcstubs/AmcExi2Stubs.c"),
            Object(NonMatching, "dolphin/ar/ar.c"),
            Object(NonMatching, "dolphin/ar/arq.c"),
            Object(NonMatching, "dolphin/ax/AX.c"),
            Object(NonMatching, "dolphin/ax/tu_8041783C.c"),
            Object(NonMatching, "dolphin/base/tu_8041A5A4.c"),
            Object(NonMatching, "dolphin/card/tu_8041A6C4.c"),
            Object(NonMatching, "dolphin/card/CARDBlock.c"),
            Object(NonMatching, "dolphin/card/CARDDir.c"),
            Object(NonMatching, "dolphin/card/tu_8041C2D8.c"),
            Object(NonMatching, "dolphin/card/CARDOpen.c", cflags=cflags_dolphin_dvd),
            Object(NonMatching, "dolphin/card/CARDCreate.c"),
            Object(NonMatching, "dolphin/card/CARDRead.c"),
            Object(NonMatching, "dolphin/card/CARDWrite.c"),
            Object(NonMatching, "dolphin/card/CARDDelete.c"),
            Object(NonMatching, "dolphin/card/CARDStat.c"),
            Object(NonMatching, "dolphin/card/CARDRename.c", cflags=cflags_dolphin_dvd),
            Object(NonMatching, "dolphin/card/tu_80420228.c"),
            Object(NonMatching, "dolphin/card/CARDUnlock.c"),
            Object(NonMatching, "dolphin/card/CARDRdwr.c"),
            Object(NonMatching, "dolphin/card/CARDStatEx.c"),
            Object(NonMatching, "dolphin/db/db.c"),
            Object(NonMatching, "dolphin/dsp/dsp.c"),
            Object(NonMatching, "dolphin/dsp/dsp_debug.c"),
            Object(NonMatching, "dolphin/dsp/dsp_task.c"),
            Object(NonMatching, "dolphin/gx/tu_80428F14.c"),
            Object(NonMatching, "dolphin/gx/GXAttr.c"),
            Object(NonMatching, "dolphin/gx/tu_8042BF8C.c"),
            Object(NonMatching, "dolphin/gx/GXGeometry.c"),
            Object(NonMatching, "dolphin/gx/GXFrameBuf.c"),
            Object(NonMatching, "dolphin/gx/tu_8042D84C.c"),
            Object(NonMatching, "dolphin/gx/GXTexture.c"),
            Object(NonMatching, "dolphin/gx/GXBump.c"),
            Object(NonMatching, "dolphin/gx/GXTev.c"),
            Object(NonMatching, "dolphin/gx/tu_8042F93C.c"),
            Object(NonMatching, "dolphin/os/tu_80431828.c", cflags=[*cflags_dolphin_sdk, "-opt nopeephole"]),
            Object(NonMatching, "dolphin/os/tu_804321CC.c"),
            Object(NonMatching, "dolphin/os/tu_804330D0.c"),
            Object(NonMatching, "dolphin/os/OSMessage.c"),
            Object(NonMatching, "dolphin/os/tu_80435A10.c"),
            Object(NonMatching, "dolphin/os/tu_80437444.c"),
            Object(NonMatching, "dolphin/pad/Padclamp.c"),
            Object(NonMatching, "dolphin/pad/Pad.c"),
            Object(NonMatching, "dolphin/si/SIBios.c"),
            Object(NonMatching, "dolphin/si/SISamplingRate.c"),
            Object(NonMatching, "dolphin/vi/vi.c"),
            Object(NonMatching, "sdk/tu_8043E344.c"),
        ],
    },
    {
        "lib": "dolphin_dvd",
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_dolphin_dvd,
        "progress_category": "sdk",
        "objects": [
            Object(NonMatching, "dolphin/dvd/tu_804227D4.c"),
            Object(NonMatching, "dolphin/dvd/dvdqueue.c"),
            Object(NonMatching, "dolphin/dvd/tu_80425954.c", cflags=[f if f != "-inline auto" else "-inline noauto" for f in cflags_dolphin_dvd]),  # dvderror.c: ErrorCode2Num stays out of line
            Object(NonMatching, "dolphin/dvd/dvdidutils.c"),
            Object(NonMatching, "dolphin/dvd/tu_80425BE4.c"),
        ],
    },
    {
        "lib": "dolphin_exi",
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_dolphin_exi,
        "progress_category": "sdk",
        "objects": [
            Object(NonMatching, "dolphin/exi/tu_80425E54.c", cflags=cflags_dolphin_sdk),  # dvdlow.c: -O4,p (docs/DECISIONS.md 2026-10-12)
            Object(NonMatching, "dolphin/exi/tu_80426CD0.c"),
        ],
    },
    {
        "lib": "dolphin_mtx",
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_dolphin_mtx,
        "progress_category": "sdk",
        "objects": [
            Object(NonMatching, "dolphin/mtx/tu_804310E0.c"),
        ],
    },
    {
        "lib": "dolphin_vm",
        "mw_version": "GC/2.0",
        "cflags": cflags_dolphin_sdk,
        "progress_category": "sdk",
        "objects": [
            Object(NonMatching, "dolphin/vm/tu_8043D960.c"),
        ],
    },
    {
        "lib": "dolphin_dbg",
        "mw_version": "GC/2.0",
        "cflags": cflags_dolphin_sdk,
        "progress_category": "sdk",
        "objects": [
            Object(NonMatching, "sdk/tu_8043F058.c"),
        ],
    },
]


# Optional callback to adjust link order. This can be used to add, remove, or reorder objects.
# This is called once per module, with the module ID and the current link order.
#
# For example, this adds "dummy.c" to the end of the DOL link order if configured with --non-matching.
# "dummy.c" *must* be configured as a Matching (or Equivalent) object in order to be linked.
def link_order_callback(module_id: int, objects: List[str]) -> List[str]:
    # Don't modify the link order for matching builds
    if not config.non_matching:
        return objects
    if module_id == 0:  # DOL
        return objects + ["dummy.c"]
    return objects


# Uncomment to enable the link order callback.
# config.link_order_callback = link_order_callback


# Optional extra categories for progress tracking
# Adjust as desired for your project
config.progress_categories = [
    ProgressCategory("game", "Game Code"),
    ProgressCategory("sdk", "SDK Code"),
]
config.progress_each_module = args.verbose
# Optional extra arguments to `objdiff-cli report generate`
config.progress_report_args = [
    # Marks relocations as mismatching if the target value is different
    # Default is "functionRelocDiffs=none", which is most lenient
    # "--config functionRelocDiffs=data_value",
]

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress information
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
