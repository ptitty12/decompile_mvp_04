"""gen_p5.py REPORT_JSON [--write]: build pass-5 batch lists from report.json.

Pass 5 targets functions that have no source yet (fuzzy 0 / None):
  - every 0 % function of 0x400 < size <= 0x800, in any unit;
  - 0 % functions <= 0x400 in units that no p4 batch covered (p4 took units with >= 3 of them).
Units that are busy (state/busy_units.txt) or still queued in an unassigned p4 batch are skipped.
Batches: units in address order within each directory, filled to about TARGET functions, at most
MAXU units. Writes queue/p5_NN.txt (space-separated dir/tu_X) and prints a summary.
"""
import json, os, re, sys
from collections import defaultdict

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET, MAXU = 40, 10
# Original hand-written code (must stay split; CLAUDE.md / DECISIONS 2026-10-10).
EXCLUDE = {"libsn/tu_80403E80", "dolphin/base/tu_8041A5A4"}
DIR_ORDER = ["game", "fe", "db", "ealib", "gamelib", "animation", "snd", "dolphin", "sdk", "libsn"]


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
    p4 = sorted(f for f in os.listdir(qdir) if re.fullmatch(r"p4_\d\d\.txt", f))
    p4_units = units_in(p4)
    # p4 batches never handed out yet (not in assignments.txt at all)
    hist = open(os.path.join(HERE, "state", "assignments.txt")).read()
    pending = [f for f in p4 if f not in hist and f not in DONE_P4]
    skip = set(open(os.path.join(HERE, "state", "busy_units.txt")).read().split()) | units_in(pending)

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
            if 0x400 < s <= 0x800 or (s <= 0x400 and name not in p4_units):
                work[name].append((s, f["name"]))
    units = sorted(work, key=lambda n: (DIR_ORDER.index(n.split("/")[0]), n))
    batches, cur, cnt = [], [], 0
    for n in units:
        if cur and (cnt + len(work[n]) > TARGET * 1.3 or len(cur) >= MAXU
                    or n.split("/")[0] != cur[0].split("/")[0] and cnt >= TARGET / 2):
            batches.append((cur, cnt))
            cur, cnt = [], 0
        cur.append(n)
        cnt += len(work[n])
        if cnt >= TARGET:
            batches.append((cur, cnt))
            cur, cnt = [], 0
    if cur:
        batches.append((cur, cnt))
    tot = 0
    for i, (us, c) in enumerate(batches):
        tot += c
        big = sum(1 for n in us for s, _ in work[n] if s > 0x400)
        print(f"p5_{i:02d} units={len(us):2d} fns={c:3d} (>0x400: {big:3d})  {us[0]} .. {us[-1]}")
        if write:
            open(os.path.join(qdir, f"p5_{i:02d}.txt"), "w").write(" ".join(us) + "\n")
    print(f"{len(batches)} batches, {tot} functions; skipped units: {len(skip)}")


# p4 batches already handed out in the first lead session (their slots were reassigned since).
DONE_P4 = {f"p4_{i:02d}.txt" for i in range(22, 34)} - {"p4_32.txt"}  # p4-32 made no commits; re-queued

if __name__ == "__main__":
    main()
