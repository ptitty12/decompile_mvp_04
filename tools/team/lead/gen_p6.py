"""gen_p6.py REPORT_JSON [--write]: build pass-6 batch lists from report.json.

Pass 6 is the sweep after p4/p5: every function with no source yet (fuzzy 0 / None) of size <= 0x800,
in any unit that is not busy (state/busy_units.txt) and not queued in a p5 batch that was never handed
out. Units of the p4 batches that were cut short by the usage limit (p4-13..21, p4-32) come first,
since many of their small functions were never attempted; the rest follow in directory/address order.
Batches: filled to about TARGET functions, at most MAXU units, one directory per batch where possible.
Writes queue/p6_NN.txt (space-separated dir/tu_X), queue/p6_order.txt, and prints a summary.
"""
import json, os, re, sys
from collections import defaultdict

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET, MAXU = 35, 10
# Original hand-written code (must stay split; CLAUDE.md / DECISIONS 2026-10-10).
EXCLUDE = {"libsn/tu_80403E80", "dolphin/base/tu_8041A5A4"}
DIR_ORDER = ["game", "fe", "db", "ealib", "gamelib", "animation", "snd", "dolphin", "sdk", "libsn"]
CUT_P4 = [f"p4_{i:02d}.txt" for i in range(13, 22)] + ["p4_32.txt"]


def units_in(names):
    out = set()
    for n in names:
        p = os.path.join(HERE, "queue", n)
        if os.path.exists(p):
            out |= set(open(p).read().split())
    return out


def main():
    rep = json.load(open(sys.argv[1]))
    write = "--write" in sys.argv
    qdir = os.path.join(HERE, "queue")
    hist = open(os.path.join(HERE, "state", "assignments.txt")).read() + \
        open(os.path.join(HERE, "state", "agents_session2.txt")).read()
    # Batches whose branch was merged count as handed out even if the state files missed them.
    import subprocess
    hist += subprocess.run(["git", "log", "--merges", "--format=%s", "origin/main"], cwd=HERE,
                           capture_output=True, text=True).stdout
    p5 = sorted(f for f in os.listdir(qdir) if re.fullmatch(r"p5_\d\d\.txt", f))
    pending = [f for f in p5 if f[:-4].replace("_", "-") not in hist]
    skip = set(open(os.path.join(HERE, "state", "busy_units.txt")).read().split()) | units_in(pending)
    cut = units_in(CUT_P4)

    work = defaultdict(list)
    for u in rep["units"]:
        name = u["name"].split("/", 1)[1]
        d = name.split("/")[0]
        if d not in DIR_ORDER or name in skip or name in EXCLUDE:
            continue
        for f in u.get("functions", []):
            if f.get("fuzzy_match_percent"):
                continue
            s = int(f["size"])
            if s <= 0x800:
                work[name].append((s, f["name"]))

    def batch(units):
        out, cur, cnt = [], [], 0
        for n in units:
            if cur and (cnt + len(work[n]) > TARGET * 1.3 or len(cur) >= MAXU
                        or n.split("/")[0] != cur[0].split("/")[0] and cnt >= TARGET / 2):
                out.append((cur, cnt))
                cur, cnt = [], 0
            cur.append(n)
            cnt += len(work[n])
            if cnt >= TARGET:
                out.append((cur, cnt))
                cur, cnt = [], 0
        if cur:
            out.append((cur, cnt))
        return out

    key = lambda n: (DIR_ORDER.index(n.split("/")[0]), n)
    first = sorted((n for n in work if n in cut), key=key)
    rest = sorted((n for n in work if n not in cut), key=key)
    batches = batch(first) + batch(rest)
    tot = 0
    for i, (us, c) in enumerate(batches):
        tot += c
        small = sum(1 for n in us for s, _ in work[n] if s <= 0x400)
        tag = "cut-p4" if us[0] in cut else ""
        print(f"p6_{i:02d} units={len(us):2d} fns={c:3d} (<=0x400: {small:3d})  {us[0]} .. {us[-1]} {tag}")
        if write:
            open(os.path.join(qdir, f"p6_{i:02d}.txt"), "w").write(" ".join(us) + "\n")
    if write:
        open(os.path.join(qdir, "p6_order.txt"), "w").write(
            " ".join(f"p6_{i:02d}" for i in range(len(batches))) + "\n")
    print(f"{len(batches)} batches, {tot} functions; skipped units: {len(skip)} (pending p5: {', '.join(pending)})")


if __name__ == "__main__":
    main()
