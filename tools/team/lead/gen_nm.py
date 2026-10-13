"""gen_nm.py REPORT_JSON [--write] [--min 95]: build near-miss (permuter) batch lists from report.json.

A near-miss pass targets functions that have source and score MIN <= fuzzy < 100 (default 95), worked
with tools/match/permute.py (C and C++ units since 2026-10-12). Units are grouped so each batch holds
about TARGET such functions, at most MAXU units, ordered by the batch's mean score (closest first).
Busy units (state/busy_units.txt) are skipped. Writes queue/nm_NN.txt (space-separated dir/tu_X,
numbering after the existing nm files), appends to queue/nm_order.txt, and prints a summary.
"""
import json, os, re, sys
from collections import defaultdict

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET, MAXU = 25, 8
EXCLUDE = {"libsn/tu_80403E80", "dolphin/base/tu_8041A5A4"}


def main():
    rep = json.load(open(sys.argv[1]))
    write = "--write" in sys.argv
    lo = float(sys.argv[sys.argv.index("--min") + 1]) if "--min" in sys.argv else 95.0
    qdir = os.path.join(HERE, "queue")
    skip = set(open(os.path.join(HERE, "state", "busy_units.txt")).read().split())
    taken = set()
    for f in os.listdir(qdir):
        if re.fullmatch(r"nm_\d\d\.txt", f):
            taken |= set(open(os.path.join(qdir, f)).read().split())
    work = defaultdict(list)
    for u in rep["units"]:
        name = u["name"].split("/", 1)[1]
        if name in skip or name in EXCLUDE or name in taken:
            continue
        for f in u.get("functions", []):
            p = f.get("fuzzy_match_percent") or 0
            if lo <= p < 100:
                work[name].append(p)
    # Units with the most near-misses first, then fill batches greedily.
    units = sorted(work, key=lambda n: (-len(work[n]), n))
    batches = []
    for n in units:
        for b in batches:
            if len(b) < MAXU and sum(len(work[x]) for x in b) + len(work[n]) <= TARGET:
                b.append(n)
                break
        else:
            batches.append([n])
    batches.sort(key=lambda b: -sum(p for x in b for p in work[x]) / sum(len(work[x]) for x in b))
    start = len([f for f in os.listdir(qdir) if re.fullmatch(r"nm_\d\d\.txt", f)])
    names = []
    for i, b in enumerate(batches):
        nn = f"nm_{start + i:02d}"
        names.append(nn)
        fs = [p for x in b for p in work[x]]
        print(f"{nn} units={len(b):2d} fns={len(fs):3d} mean={sum(fs)/len(fs):5.2f} >=99: {sum(1 for p in fs if p >= 99):3d}  {b[0]}")
        if write:
            open(os.path.join(qdir, nn + ".txt"), "w").write(" ".join(b) + "\n")
    if write:
        with open(os.path.join(qdir, "nm_order.txt"), "a") as fh:
            fh.write(" ".join(names) + "\n")
    print(f"{len(batches)} batches, {sum(len(v) for v in work.values())} functions (>= {lo}%)")


if __name__ == "__main__":
    main()
