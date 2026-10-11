#!/usr/bin/env python3
"""Register tools/swarm/merge_dtk.py as git's merge driver for symbols.txt and splits.txt.

.gitattributes (committed) names the drivers. This sets the repo-level config
that defines them. The config lives in the shared .git/config, so every worktree
of this clone uses it. The command points at this checkout's copy of the script,
so branches cut before the script existed still merge correctly.

Usage: python tools/swarm/install_merge_drivers.py [--uninstall]
"""
import subprocess
import sys
from pathlib import Path

SCRIPT = Path(__file__).resolve().parent / "merge_dtk.py"
DRIVERS = {
    "dtk-symbols": ("dtk symbols.txt merge by address", "symbols"),
    "dtk-splits": ("dtk splits.txt merge by unit block", "splits"),
}


def git(*args: str) -> None:
    subprocess.run(["git", "-C", str(SCRIPT.parents[2]), *args], check=True)


def main() -> None:
    if "--uninstall" in sys.argv:
        for name in DRIVERS:
            git("config", "--remove-section", f"merge.{name}")
        print("merge drivers removed")
        return
    script = SCRIPT.as_posix()
    for name, (desc, kind) in DRIVERS.items():
        git("config", f"merge.{name}.name", desc)
        git("config", f"merge.{name}.driver", f'python "{script}" {kind} %O %A %B')
    print(f"merge drivers installed: {', '.join(DRIVERS)} -> {script}")


if __name__ == "__main__":
    main()
