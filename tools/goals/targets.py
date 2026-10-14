#!/usr/bin/env python3
"""Knowledge targets: the decomp work the engine and the mods depend on.

The project's goals (docs/ROADMAP.md) need specific knowledge from the decomp,
not a match percentage. This script finds the functions behind each knowledge
target in a built tree and reports how far each target has come. The lead uses
it to pick worker batches; docs/ROADMAP.md explains each target.

  K1 sdk-boundary   SDK and runtime library functions (units under dolphin/,
                    sdk/, libc/, libm/, libgcc/, libsn/) that game or EA code
                    calls directly. The engine replaces these by name, so each
                    needs its real SDK name.
  K2 roster-data    The roster and team data path: functions that reference the
                    database files or database sources, plus their direct callees
                    outside the runtime libraries.
  K3 determinism    Everything that can make two runs differ: time-base reads
                    (mftb) and their callers, rand/srand callers, and callers of
                    callback/async registration functions.
  K4 main-loop      main and the non-library functions it calls, two levels deep.

"Named" means the symbol has no address in it (fn_8XXXXXXX, Unk8XXXXXXX, Tbl8XXXXXXX
and the like are placeholders). "Matched" is objdiff's 100%. For K1 the name is
what counts; for K2-K4 a target function is done when it is matched and named.

Usage:
  python tools/goals/targets.py                         # summary table
  python tools/goals/targets.py --build <dir>           # another build (default build/GV4E69)
  python tools/goals/targets.py --list K3               # every function in one target
  python tools/goals/targets.py --list K1 --todo        # only the ones not done yet
  python tools/goals/targets.py --units K2              # units holding unfinished K2 functions

Reads only: <build>/report.json and <build>/asm/. Needs a finished `ninja` build.
"""
import argparse
import collections
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
# Nintendo SDK and SN runtime units: the engine replaces these, it never runs them.
RUNTIME_DIRS = {"dolphin", "sdk", "libc", "libm", "libgcc", "libsn"}

FN = re.compile(r"^\.fn (\S+), \w+$(.*?)^\.endfn \1$", re.S | re.M)
OBJ = re.compile(r"^\.obj (\S+), \w+$(.*?)^\.endobj \1$", re.S | re.M)
ADDR = re.compile(r"/\* ([0-9A-F]{8}) ")
CALL = re.compile(r"\tbl (\S+)")
TAIL = re.compile(r"\tb (\S+)$", re.M)
REF = re.compile(r"([A-Za-z_][\w$.]*)@(?:ha|h|l|sda21)")
STRING = re.compile(r'^\t\.string "(.*)"$', re.M)
PLACEHOLDER = re.compile(r"8[0-9A-F]{7}")  # fn_8..., Unk8..., Tbl8..., lbl_8...: an address in the name

# K2 seeds: strings that mark the database code (file names on disc, source paths).
DB_STRINGS = re.compile(r"database[\\/]|tablemanager\.cpp|datalookup|ingamedata|hist\.dat|resign\.csv", re.I)
# K3: registration and async entry points (SDK names; missing ones are reported).
ASYNC_SDK = [
    "VISetPreRetraceCallback", "VISetPostRetraceCallback", "AIRegisterDMACallback",
    "AXRegisterCallback", "DSPAddTask", "DVDReadAsyncPrio", "DVDReadAsync",
    "OSSetAlarm", "OSSetPeriodicAlarm", "OSCreateThread", "ARQPostRequest",
    "CARDMountAsync", "CARDReadAsync", "CARDWriteAsync",
]
RNG = ["rand", "srand"]

# need: "name" (done when named) or "both" (done when matched and named).
# missing: entry points the target wants that symbols.txt doesn't name yet.
Target = collections.namedtuple("Target", "label what names need missing")


class Fn:
    __slots__ = ("name", "addr", "size", "pct", "unit", "calls", "refs", "mftb")

    def __init__(self, name):
        self.name, self.addr, self.size, self.pct, self.unit = name, 0, 0, 0.0, ""
        self.calls, self.refs, self.mftb = set(), set(), False

    @property
    def named(self):
        return not PLACEHOLDER.search(self.name)

    @property
    def matched(self):
        return self.pct >= 100.0

    @property
    def sdk(self):
        return self.unit.split("/", 1)[0] in RUNTIME_DIRS


def load(build):
    path = os.path.join(build, "report.json")
    if not os.path.isfile(path):
        sys.exit(f"targets.py: no {path}; run `python configure.py && ninja` first, or pass --build")
    report = json.load(open(path, encoding="utf-8"))
    fns, strings = {}, {}
    for unit in report["units"]:
        uname = unit["name"].split("/", 1)[1] if "/" in unit["name"] else unit["name"]
        for f in unit.get("functions", []) or []:
            fn = fns.setdefault(f["name"], Fn(f["name"]))
            fn.size, fn.pct, fn.unit = int(f["size"]), float(f.get("fuzzy_match_percent", 0.0)), uname
        # Only the asm of current units: build/asm also keeps files from older splits.
        path = os.path.join(build, "asm", *uname.split("/")) + ".s"
        if not os.path.isfile(path):
            continue
        text = open(path, encoding="utf-8", errors="replace").read()
        for m in OBJ.finditer(text):
            s = STRING.search(m.group(2))
            if s:
                strings[m.group(1)] = s.group(1)
        for m in FN.finditer(text):
            name, body = m.groups()
            fn = fns.setdefault(name, Fn(name))
            a = ADDR.search(body)
            fn.addr = int(a.group(1), 16) if a else 0
            fn.unit = fn.unit or uname
            fn.calls = set(CALL.findall(body)) | {t for t in TAIL.findall(body) if not t.startswith(".L")}
            fn.refs = set(REF.findall(body))
            fn.mftb = "\tmftb" in body
    return fns, strings


def callers_of(fns, names):
    names = set(names)
    return {f.name for f in fns.values() if f.addr and f.calls & names}


def game_callees(fns, name):
    return {c for c in fns[name].calls if c in fns and fns[c].addr and not fns[c].sdk}


def targets(fns, strings):
    out = collections.OrderedDict()
    called = collections.defaultdict(set)
    for f in fns.values():
        for c in f.calls:
            called[c].add(f.name)

    # K1: runtime-library functions with at least one caller outside the runtime libraries.
    k1 = {n for n, f in fns.items() if f.addr and f.sdk and any(not fns[c].sdk for c in called[n] if c in fns)}
    out["K1"] = Target("sdk-boundary", "SDK functions called from game/EA code; the engine replaces them by name",
                       k1, "name", [])

    # K2: functions referencing database strings, plus their callees outside the runtime libraries.
    seeds = {f.name for f in fns.values() if f.addr and any(DB_STRINGS.search(strings.get(r, "")) for r in f.refs)}
    k2 = set(seeds)
    for n in seeds:
        k2 |= game_callees(fns, n)
    out["K2"] = Target("roster-data", "database load/save path: seeds reference database files or sources, plus callees",
                       k2, "both", [])

    # K3: time-base readers and their callers, RNG users, async/callback registrars.
    time_fns = {f.name for f in fns.values() if f.mftb}
    k3 = set(time_fns) | {c for c in callers_of(fns, time_fns) if not fns[c].sdk}
    k3 |= {c for c in callers_of(fns, RNG) if not fns[c].sdk}
    k3 |= {c for c in callers_of(fns, [n for n in ASYNC_SDK if n in fns]) if not fns[c].sdk}
    out["K3"] = Target("determinism", "time-base reads, rand/srand users, async/callback registrars",
                       k3, "both", [n for n in ASYNC_SDK if n not in fns])

    # K4: main and two levels of callees outside the runtime libraries.
    main = "main" if "main" in fns else "fn_8014D63C"
    k4, frontier = {main}, {main}
    for _ in range(2):
        nxt = set()
        for n in frontier:
            nxt |= game_callees(fns, n)
        frontier = nxt - k4
        k4 |= nxt
    out["K4"] = Target("main-loop", "main and the non-SDK functions it calls, two levels deep", k4, "both", [])
    return out


def done(f, need):
    return f.named if need == "name" else (f.named and f.matched)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--build", default=os.path.join(ROOT, "build", "GV4E69"))
    ap.add_argument("--list", metavar="K", help="list the functions of one target (K1..K4)")
    ap.add_argument("--units", metavar="K", help="list units holding unfinished functions of one target")
    ap.add_argument("--todo", action="store_true", help="with --list: only unfinished functions")
    a = ap.parse_args()

    fns, strings = load(a.build)
    ts = targets(fns, strings)

    if a.list or a.units:
        key = (a.list or a.units).upper()
        if key not in ts:
            sys.exit(f"targets.py: unknown target {key}; use one of {', '.join(ts)}")
        t = ts[key]
        rows = sorted((fns[n] for n in t.names), key=lambda f: f.addr)
        if a.units:
            per = collections.Counter()
            for f in rows:
                if not done(f, t.need):
                    per[f.unit] += f.size
            for u, b in per.most_common():
                print(f"{b:7d} B  {u}")
            return
        for f in rows:
            if a.todo and done(f, t.need):
                continue
            flag = "done" if done(f, t.need) else "todo"
            print(f"{f.addr:08X} {f.size:6d} {f.pct:6.1f}% {'named' if f.named else 'fn_  '} {flag}  {f.name}  [{f.unit}]")
        if t.missing:
            print(f"# not in symbols.txt yet (K1 names them): {', '.join(t.missing)}")
        return

    print("| Target | What | Functions | Named | Matched | Done | Done bytes |")
    print("|---|---|---:|---:|---:|---:|---:|")
    for key, t in ts.items():
        fs = [fns[n] for n in t.names]
        n = len(fs)
        named = sum(f.named for f in fs)
        matched = sum(f.matched for f in fs)
        dn = [f for f in fs if done(f, t.need)]
        tb = sum(f.size for f in fs) or 1
        db = sum(f.size for f in dn)
        pct = 100 * len(dn) / max(1, n)
        print(f"| {key} {t.label} | {t.what} | {n} | {named} | {matched} | {len(dn)} ({pct:.0f}%) "
              f"| {100 * db / tb:.0f}% of {tb / 1024:.0f} KB |")
    for key, t in ts.items():
        if t.missing:
            print(f"\n{key} entry points not in symbols.txt yet (K1 names them): {', '.join(t.missing)}")


if __name__ == "__main__":
    sys.exit(main())
