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
cflags_game = ["-Os", "-G0", "-fno-rtti", "-fno-exceptions", "-Iinclude"]

# EA shared libraries (ProDG 3.9.3). Unlike game code they use r13 small data, so no -G0.
cflags_ealib = ["-Os", "-fno-rtti", "-fno-exceptions", "-Iinclude"]

# Dolphin SDK OS library (built May 21 2004, later than the other SDK libs).
cflags_dolphin_os = [*cflags_base, "-char unsigned", "-opt nopeephole"]

# Units not listed here are linked from the dtk split (assembly).
config.libs = [
    {
        "lib": "libgcc",
        "mw_version": "ProDG/3.9.3",
        "cflags": cflags_libgcc,
        "progress_category": "sdk",
        "objects": [
            Object(Matching, "libgcc/_main.c"),
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
        "lib": "game",
        "mw_version": "ProDG/3.9.3",
        "cflags": cflags_game,
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "animation/choosers/playeridchooser.cpp"),
        ],
    },
    {
        "lib": "ealib",
        "mw_version": "ProDG/3.9.3",
        "cflags": cflags_ealib,
        "progress_category": "game",
        "objects": [
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
