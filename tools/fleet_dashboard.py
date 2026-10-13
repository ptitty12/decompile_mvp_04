#!/usr/bin/env python3
"""Live fleet dashboard: matching speed, near-misses and the merge backlog, from git alone.

Nothing is built and no model is called, so watching costs no tokens. Two views of
the same numbers:

  python tools/fleet_dashboard.py --watch [SECS]  terminal view, redrawn every SECS (default 5)
  python tools/fleet_dashboard.py --publish       push README.md + a chart to the `dashboard`
                                                  branch on GitHub if anything changed
                                                  (otherwise a heartbeat every 10 minutes)
  python tools/fleet_dashboard.py --install       register --publish as a scheduled task (every minute)
  python tools/fleet_dashboard.py --uninstall     remove it
  python tools/fleet_dashboard.py                 print the terminal view once

Sources (local refs and files; every worktree shares the refs):
  verified  each "docs: update progress card" commit on origin/main rewrites
            docs/progress/history.csv from a real build (tools/progress_bot.py). Its last row
            at each commit time is an intraday series of matched functions and code bytes.
            It lags merges by the bot's build, about 5-10 minutes.
  claimed   match( / wip( / near-miss( commits on any ref, by author time. Sizes come from
            config/GV4E69/symbols.txt on origin/main. A function is claimed once, at its first
            match commit; integration can still reject it.
  near-miss a subject that calls a function a near-miss. prep.sh rewords wip( to match(
            before merging, so the prefix alone is not enough.
  backlog   work/* commits not yet on origin/main.
  workers   each work/* worktree's HEAD reflog (commits) and .ninja_log mtime (last build).
  close     functions under 100% in the progress bot's last build of main
            (build/_progress/wt/build/GV4E69/report.json in the main checkout).

The `dashboard` branch is a single orphan commit, replaced on each push. It holds only
README.md and the chart: no source, no game data, and no local paths (worktrees appear
by slot name). It has no .github/, so pushing it starts no CI.
"""
import argparse
import csv
import datetime
import hashlib
import io
import json
import os
import re
import shutil
import subprocess
import sys
import time
import traceback
from html import escape
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from progress_chart import STYLE  # noqa: E402  (shared card look)

REPO_URL = "https://github.com/ptitty12/decompile_mvp_04"
BRANCH = "dashboard"
TASK_NAME = "MVP decomp live dashboard"
STATE_DIR = ROOT / "build" / "_dashboard"
CACHE = STATE_DIR / "verified_cache.json"
PUBLISHED = STATE_DIR / "published.json"
LOG = STATE_DIR / "publish.log"
LOCK = STATE_DIR / "lock"

HEARTBEAT = 10 * 60          # push at least this often even when nothing changed
LOOKBACK = 48 * 3600         # history read for sessions and charts
CHART_HOURS = 24
SESSION_GAP = 60 * 60        # a pause this long between worker commits ends a session
ACTIVE = 10 * 60             # a worker is active if it committed or built this recently
WINDOWS = [("15 min", 15 * 60), ("1 h", 3600), ("3 h", 3 * 3600)]

# Same sign-in as tools/progress_bot.py: the gh CLI's token, no config changes.
GIT_AUTH = ["-c", "credential.helper=", "-c", "credential.helper=!gh auth git-credential"]
ENV = dict(os.environ, GIT_TERMINAL_PROMPT="0", GCM_INTERACTIVE="never")
NO_WINDOW = getattr(subprocess, "CREATE_NO_WINDOW", 0)
PY = str(Path(sys.executable).with_name("python.exe")) if Path(sys.executable).name.lower() == "pythonw.exe" else sys.executable

SUBJECT = re.compile(r"^(match|wip|near-miss)\(([^)]*)\):\s*(.*)$")
FN = re.compile(r"\bfn_[0-9A-Fa-f]{8}")  # also the head of mangled names (fn_8028D200__16Unk...)
PAREN = re.compile(r"\([^()]*\)")
BRACKET = re.compile(r"\[[^\]]*\]")
SYMBOL = re.compile(r"^\S+ = [^:\n]*:0x([0-9A-Fa-f]{8});[^\n]*?\btype:function\b[^\n]*?\bsize:0x([0-9A-Fa-f]+)", re.M)

_mem: Dict[str, Any] = {}  # per-process caches (symbols, report) for --watch


# ----------------------------------------------------------------------------- git


def git(*args: str, cwd: Path = ROOT, check: bool = True, stdin: Optional[str] = None) -> str:
    # stdin goes in as bytes: a text-mode pipe on Windows would turn each \n into \r\n.
    r = subprocess.run(
        ["git", *args], cwd=cwd, env=ENV, input=stdin.encode() if stdin is not None else None,
        creationflags=NO_WINDOW, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    )
    if check and r.returncode:
        raise RuntimeError(f"git {' '.join(args[:2])} failed: {r.stderr.decode(errors='replace').strip()[:300]}")
    return r.stdout.decode("utf-8", "replace").replace("\r\n", "\n")


def cat_files(specs: List[str]) -> Dict[str, Optional[str]]:
    """`git cat-file --batch` for many rev:path specs in one process."""
    if not specs:
        return {}
    r = subprocess.run(
        ["git", "cat-file", "--batch"], cwd=ROOT, env=ENV, creationflags=NO_WINDOW,
        input=("\n".join(specs) + "\n").encode(), stdout=subprocess.PIPE, stderr=subprocess.DEVNULL,
    )
    out, pos, res = r.stdout, 0, {}
    for spec in specs:
        nl = out.index(b"\n", pos)
        header = out[pos:nl].decode()
        pos = nl + 1
        if header.endswith((" missing", " ambiguous")):
            res[spec] = None
            continue
        size = int(header.split()[2])
        res[spec] = out[pos:pos + size].decode("utf-8", "replace")
        pos += size + 1
    return res


# ----------------------------------------------------------------------------- sources


def verified_series(since: int) -> List[Tuple[int, int, int, int, int]]:
    """(time, matched_functions, matched_code, total_functions, total_code), oldest first."""
    try:
        cache = json.loads(CACHE.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        cache = {}
    log = git("log", "origin/main", f"--since={since}", "--format=%H %ct", "--", "docs/progress/history.csv")
    rows = [line.split() for line in log.splitlines() if line.strip()]
    need = [h for h, _ in rows if h not in cache]
    if need:
        blobs = cat_files([f"{h}:docs/progress/history.csv" for h in need])
        for h in need:
            text = blobs.get(f"{h}:docs/progress/history.csv")
            last = list(csv.DictReader(io.StringIO(text)))[-1] if text else None
            cache[h] = [int(last[k]) for k in ("matched_functions", "matched_code", "total_functions", "total_code")] if last else None
        STATE_DIR.mkdir(parents=True, exist_ok=True)
        CACHE.write_text(json.dumps(cache), encoding="utf-8")
    return sorted((int(t), *cache[h]) for h, t in rows if cache.get(h))


def symbol_sizes() -> Dict[str, int]:
    """Function size by "fn_<ADDRESS>", whatever the symbol is called now."""
    blob = git("rev-parse", "origin/main:config/GV4E69/symbols.txt", check=False).strip()
    if _mem.get("sym_blob") != blob:
        text = cat_files([blob]).get(blob) or ""
        _mem["sym"] = {f"fn_{m.group(1).upper()}": int(m.group(2), 16) for m in SYMBOL.finditer(text)}
        _mem["sym_blob"] = blob
    return _mem["sym"]


def parse_subject(subject: str) -> Optional[Dict[str, Any]]:
    m = SUBJECT.match(subject)
    if not m:
        return None
    kind, unit, rest = m.groups()
    rest = BRACKET.sub(" ", rest)
    near: List[str] = []

    def drop(g: "re.Match[str]") -> str:
        # "(+4 near-misses 98.3%: fn_a, fn_b)" names near-misses; other asides name callees.
        if "near-miss" in g.group(0):
            near.extend(FN.findall(g.group(0)))
        return " "

    text = PAREN.sub(drop, rest)
    matched: List[str] = []
    if kind != "match":
        near += FN.findall(text)
    elif "near-miss" in text:
        i = text.index("near-miss")
        before, after = FN.findall(text[:i]), FN.findall(text[i:])
        if before:
            near += before
            matched = after
        else:
            near += after
    else:
        matched = FN.findall(text)
    count = len(matched)
    if kind == "match" and not matched and not near:
        n = re.match(r"\s*(\d+)\s", text)  # "7 DVD async-command functions"
        count = int(n.group(1)) if n else 1
    close = None
    p = re.search(r"(\d{2,3}(?:\.\d+)?)\s*%", rest)
    if p:
        close = float(p.group(1))
    else:
        d = re.search(r"(\d+)\s*/\s*(\d+)\s*insns? differ", rest)
        f = re.search(r"near-miss,?\s*(\d+)\s*/\s*(\d+)\b", rest)
        if d and int(d.group(2)):
            close = 100.0 * (1 - int(d.group(1)) / int(d.group(2)))
        elif f and int(f.group(2)):
            close = 100.0 * int(f.group(1)) / int(f.group(2))
    return {"kind": kind, "unit": unit, "matched": matched, "count": count, "near": near, "close": close}


def claims(since: int) -> List[Dict[str, Any]]:
    """Worker commits on any ref, oldest first, each function claimed once."""
    out = git("log", "--all", "--no-merges", f"--since={since}", "--format=%at%x1f%s")
    sizes = symbol_sizes()
    seen, rows = set(), []
    for line in out.splitlines():
        at, _, subject = line.partition("\x1f")
        p = parse_subject(subject)
        if not p:
            continue
        key = (at, SUBJECT.sub(r"\2:\3", subject))  # a reworded wip( keeps its author time
        if key in seen:
            continue
        seen.add(key)
        p["t"] = int(at)
        p["subject"] = subject
        rows.append(p)
    rows.sort(key=lambda r: r["t"])
    first: set = set()
    for r in rows:
        new = [f for f in r["matched"] if f not in first]
        first.update(new)
        r["fns"] = len(new) if r["matched"] else r["count"]
        r["bytes"] = sum(sizes.get(f"fn_{f[3:].upper()}", 0) for f in new)
        r["is_near"] = bool(r["near"]) or r["kind"] != "match"
    return rows


def worktrees() -> Tuple[Optional[Path], List[Dict[str, Any]]]:
    """(main checkout, worker worktrees on work/* branches)."""
    main, workers, cur = None, [], {}
    for line in git("worktree", "list", "--porcelain").splitlines() + [""]:
        if not line:
            if cur:
                path = Path(cur["worktree"])
                if main is None:
                    main = path
                elif cur.get("branch", "").startswith("refs/heads/work/") and path.is_dir():
                    name = path.name
                    workers.append({
                        "path": path,
                        "slot": name.split("-", 1)[1] if "-" in name else name,
                        "branch": cur["branch"][len("refs/heads/"):],
                    })
            cur = {}
            continue
        k, _, v = line.partition(" ")
        cur[k] = v
    return main, workers


def head_reflog(path: Path) -> List[Tuple[int, str]]:
    """(time, subject) of each commit made in this worktree, from its HEAD reflog file."""
    try:
        gitfile = (path / ".git").read_text(encoding="utf-8").strip()
        gitdir = Path(gitfile.split("gitdir:", 1)[1].strip()) if gitfile.startswith("gitdir:") else path / ".git"
        lines = (gitdir / "logs" / "HEAD").read_text(encoding="utf-8", errors="replace").splitlines()
    except (OSError, IndexError):
        return []
    out = []
    for line in lines[-500:]:
        head, _, msg = line.partition("\t")
        if not msg.startswith("commit"):
            continue
        try:
            t = int(head.rsplit(" ", 2)[-2])
        except (ValueError, IndexError):
            continue
        out.append((t, msg.split(": ", 1)[-1]))
    return out


def close_to_matching(main: Optional[Path]) -> Optional[Dict[str, Any]]:
    """Functions under 100% in the progress bot's last build of main."""
    if main is None:
        return None
    path = main / "build" / "_progress" / "wt" / "build" / "GV4E69" / "report.json"
    try:
        mtime = path.stat().st_mtime
    except OSError:
        return None
    if _mem.get("report_mtime") != mtime:
        try:
            report = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, ValueError):
            return _mem.get("report")
        bands = {"99": [0, 0], "95": [0, 0], "80": [0, 0]}
        close = []
        for u in report.get("units", []):
            for f in u.get("functions") or []:
                pct = float(f.get("fuzzy_match_percent", 0.0))
                size = int(f.get("size", 0))
                if pct >= 100.0 or size == 0:
                    continue
                band = "99" if pct >= 99 else "95" if pct >= 95 else "80" if pct >= 80 else None
                if band:
                    bands[band][0] += 1
                    bands[band][1] += size
                    close.append((pct, size, f["name"], u["name"].split("/", 1)[-1]))
        close.sort(key=lambda c: (-c[0], -c[1]))
        _mem["report"] = {"time": mtime, "bands": bands, "top": close[:10]}
        _mem["report_mtime"] = mtime
    return _mem["report"]


# ----------------------------------------------------------------------------- stats


def value_at(series: List[Tuple[int, ...]], t: float) -> Optional[Tuple[int, ...]]:
    best = None
    for p in series:
        if p[0] <= t:
            best = p
        else:
            break
    return best or (series[0] if series else None)


def collect() -> Dict[str, Any]:
    now = time.time()
    since = int(now - LOOKBACK)
    main, workers = worktrees()
    series = verified_series(since)
    rows = claims(since)

    ahead = {}
    for line in git("for-each-ref", "--format=%(refname:short) %(ahead-behind:origin/main)", "refs/heads/work/").splitlines():
        parts = line.split()
        if len(parts) == 3:
            ahead[parts[0]] = int(parts[1])
    pending_branches = [b for b, n in ahead.items() if n > 0]
    oldest = None
    if pending_branches:
        ts = git("log", "--no-merges", "--format=%at", *pending_branches, "--not", "origin/main").split()
        oldest = min(map(int, ts)) if ts else None
    last_merge = git("log", "-1", "--merges", "--format=%ct", "origin/main", check=False).strip()

    # Per worker slot: commits from its HEAD reflog, builds from .ninja_log.
    activity: List[Tuple[int, str]] = []  # (time, slot) of each worker commit
    wk = []
    for w in workers:
        commits = [(t, s) for t, s in head_reflog(w["path"]) if t >= since]
        activity += [(t, w["slot"]) for t, _ in commits]
        try:
            built = (w["path"] / ".ninja_log").stat().st_mtime
        except OSError:
            built = None
        last_commit = commits[-1][0] if commits else None
        last_any = max([x for x in (built, last_commit) if x] or [0])
        hour = [s for t, s in commits if t >= now - 3600]
        wk.append({
            "slot": w["slot"],
            "branch": w["branch"],
            "built": built,
            "last_commit": last_commit,
            "last_subject": commits[-1][1] if commits else "",
            "state": "active" if now - last_any < ACTIVE else "quiet" if now - last_any < 3600 else "idle",
            "commits_1h": len(hour),
            "near_1h": sum(1 for s in hour if (p := parse_subject(s)) and (p["near"] or p["kind"] != "match")),
            "pending": ahead.get(w["branch"], 0),
        })
    wk.sort(key=lambda w: ({"active": 0, "quiet": 1, "idle": 2}[w["state"]], w["slot"]))

    def workers_in(t0: float, t1: float) -> int:
        slots = {s for t, s in activity if t0 <= t < t1}
        if t1 >= now:
            slots |= {w["slot"] for w in wk if w["built"] and w["built"] >= t0}
        return len(slots)

    def window(t0: float, t1: float) -> Dict[str, Any]:
        rs = [r for r in rows if t0 <= r["t"] < t1]
        hours = max((t1 - t0) / 3600, 1e-9)
        a, b = value_at(series, t0), value_at(series, t1)
        n_workers = workers_in(t0, t1)
        claimed_b = sum(r["bytes"] for r in rs)
        return {
            "hours": hours,
            "commits": len(rs),
            "near": sum(1 for r in rs if r["is_near"]),
            "fns": sum(r["fns"] for r in rs),
            "bytes": claimed_b,
            "workers": n_workers,
            "v_fns": (b[1] - a[1]) if a and b else None,
            "v_bytes": (b[2] - a[2]) if a and b else None,
            "per_worker": claimed_b / hours / n_workers if n_workers else None,
        }

    windows = [(label, window(now - secs, now)) for label, secs in WINDOWS]

    # Session: worker commits with no pause longer than SESSION_GAP.
    session = None
    if rows:
        start = end = rows[-1]["t"]
        for r in reversed(rows):
            if start - r["t"] > SESSION_GAP:
                break
            start = r["t"]
        live = now - end <= SESSION_GAP
        session = window(start, now if live else end + 1)
        session.update(start=start, end=end, live=live)
        if not live:  # verified gains land after the last commit, once it is merged
            a, b = value_at(series, start), value_at(series, now)
            session.update(v_fns=b[1] - a[1], v_bytes=b[2] - a[2])

    hour0 = int(now // 3600 * 3600)
    hourly = []
    for i in range(CHART_HOURS - 1, -1, -1):
        t0 = hour0 - i * 3600
        w = window(t0, min(t0 + 3600, now))
        w["t0"] = t0
        w["kb_per_h"] = w["bytes"] / 1024 / w["hours"] if w["hours"] > 0 else 0
        hourly.append(w)

    near_recent = [r for r in rows if r["is_near"]][-8:][::-1]
    return {
        "now": now,
        "latest": series[-1] if series else None,
        "verified_at": series[-1][0] if series else None,
        "windows": windows,
        "session": session,
        "hourly": hourly,
        "workers": wk,
        "pending": sum(ahead.values()),
        "pending_branches": len(pending_branches),
        "oldest_pending": oldest,
        "last_merge": int(last_merge) if last_merge else None,
        "close": close_to_matching(main),
        "near_recent": near_recent,
        "farm": farm_status(),
    }


FARM_LEDGER = Path(os.environ.get("FARM_DIR", r"C:\Users\Patrick Taylor\decompile_mvp_04-farm")) / "build" / "permute_farm" / "ledger.json"


def farm_status() -> Optional[Dict[str, Any]]:
    """tools/match/permute_farm.py's ledger: queue, current function, outcomes."""
    try:
        db = json.loads(FARM_LEDGER.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return None
    fns = list(db.get("functions", {}).values())
    counts: Dict[str, int] = {}
    for e in fns:
        counts[e["status"]] = counts.get(e["status"], 0) + 1
    st = db.get("state", {})
    return {
        "queue": st.get("queue"), "current": st.get("current"), "unit": st.get("current_unit"),
        "since": st.get("current_since"), "counts": counts,
        "improved": sum(1 for e in fns if e.get("best") is not None and e.get("base") and e["best"] < e["base"]),
        "matched": sorted((e for e in fns if e["status"] == "matched"), key=lambda e: -e.get("time", 0)),
    }


def farm_line(f: Dict[str, Any], now: float) -> str:
    c = f["counts"]
    tried = sum(c.values())
    cur = f"now {f['current'].split('__')[0]} ({f['unit']}, {ago(f['since'], now)})" if f.get("current") else "idle"
    return (f"{cur}; queue {f['queue']}; tried {tried}: {c.get('matched', 0)} match candidates, "
            f"{f['improved']} improved, {c.get('refused', 0)} refused")


# ----------------------------------------------------------------------------- formatting


def tzname() -> str:
    name = datetime.datetime.now().astimezone().tzname() or ""
    return "".join(w[0] for w in name.split()) if " " in name else name


def hm(t: Optional[float]) -> str:
    return datetime.datetime.fromtimestamp(t).strftime("%H:%M") if t else "-"


def ago(t: Optional[float], now: float) -> str:
    if not t:
        return "-"
    s = max(0, int(now - t))
    if s < 90:
        return f"{s}s"
    if s < 90 * 60:
        return f"{s // 60}m"
    return f"{s // 3600}h{s % 3600 // 60:02d}m"


def kb(n: Optional[float]) -> str:
    return "-" if n is None else f"{n / 1024:,.1f} KB" if n < 1024 * 1024 else f"{n / 1024 / 1024:,.2f} MB"


def pct(a: float, b: float) -> str:
    return f"{100.0 * a / b:.0f}%" if b else "-"


def rate(n: Optional[float], hours: float, unit: str = "") -> str:
    if n is None:
        return "-"
    v = n / hours
    if unit == "B":
        return kb(v)
    return f"{v:,.0f}"


def speed_rows(st: Dict[str, Any]) -> Tuple[List[str], List[List[str]]]:
    cols = [label for label, _ in st["windows"]]
    ws = [w for _, w in st["windows"]]
    if st["session"]:
        cols.append("session")
        ws.append(st["session"])
    table = [
        ["Code verified on main / h"] + [rate(w["v_bytes"], w["hours"], "B") for w in ws],
        ["Functions verified / h"] + [rate(w["v_fns"], w["hours"]) for w in ws],
        ["Code claimed by workers / h"] + [rate(w["bytes"], w["hours"], "B") for w in ws],
        ["Functions claimed / h"] + [rate(w["fns"], w["hours"]) for w in ws],
        ["Near-miss share of commits"] + [pct(w["near"], w["commits"]) for w in ws],
        ["Commits / h"] + [rate(w["commits"], w["hours"]) for w in ws],
        ["Workers active"] + [str(w["workers"]) for w in ws],
        ["Code claimed / h per worker"] + [kb(w["per_worker"]) if w["per_worker"] else "-" for w in ws],
    ]
    return cols, table


def headline(st: Dict[str, Any]) -> List[str]:
    lt = st["latest"]
    if not lt:
        return ["No verified progress in the last 48 h."]
    _, mf, mc, tf, tc = lt
    rem_f, rem_c = tf - mf, tc - mc
    lines = [
        f"Verified on main: {mf:,} / {tf:,} functions ({100 * mf / tf:.2f}%), "
        f"{kb(mc)} / {kb(tc)} code ({100 * mc / tc:.2f}%)",
        f"Remaining: {rem_f:,} functions, {kb(rem_c)}, avg {rem_c / max(rem_f, 1):,.0f} B each "
        f"(matched ones avg {mc / max(mf, 1):,.0f} B)",
    ]
    w3 = dict(st["windows"])["3 h"]
    if w3["v_bytes"] and w3["v_bytes"] > 0:
        lines.append(f"At the 3 h verified rate the remaining code is ~{rem_c / (w3['v_bytes'] / w3['hours']):,.0f} hours of fleet time")
    return lines


def session_line(st: Dict[str, Any]) -> str:
    s = st["session"]
    if not s:
        return "No worker commits in the last 48 h."
    dur = ago(s["start"], s["end"] if not s["live"] else st["now"])
    state = "running" if s["live"] else f"ended {hm(s['end'])}"
    v = f"+{s['v_fns']:,} functions / +{kb(s['v_bytes'])} verified" if s["v_fns"] is not None else "nothing verified yet"
    return (f"Session: started {hm(s['start'])}, {state}, {dur}. {v}; "
            f"{s['fns']:,} functions / {kb(s['bytes'])} claimed; "
            f"{s['near']} near-miss commits of {s['commits']} ({pct(s['near'], s['commits'])}).")


SPARK = " ▁▂▃▄▅▆▇█"


def spark(vals: List[float]) -> str:
    """Two characters per value; any nonzero value shows at least the lowest block."""
    top = max(vals) if vals else 0
    return "".join(2 * (SPARK[max(1, min(8, round(8 * v / top)))] if top and v > 0 else "·") for v in vals)


# ----------------------------------------------------------------------------- terminal


TERM_LABELS = ["Code verified/h", "Fns verified/h", "Code claimed/h", "Fns claimed/h",
               "Near-miss share", "Commits/h", "Workers active", "Code/h per worker"]


def render_terminal(st: Dict[str, Any], every: Optional[int], width: int = 120) -> str:
    """The same numbers as the GitHub page, laid out for a terminal `width` columns wide."""
    now = st["now"]
    B, D, R = "\x1b[1m", "\x1b[2m", "\x1b[0m"
    out = [f"{B}MVP decomp fleet{R}  {datetime.datetime.fromtimestamp(now):%H:%M:%S} {tzname()}"
           + (f"  {D}every {every}s, Ctrl-C stops{R}" if every else ""), ""]
    lt = st["latest"]
    if lt:
        _, mf, mc, tf, tc = lt
        w3 = dict(st["windows"])["3 h"]
        out += [f"Verified   {mf:,} / {tf:,} fn ({100 * mf / tf:.2f}%)  {kb(mc)} / {kb(tc)} ({100 * mc / tc:.2f}%)",
                f"Remaining  {tf - mf:,} fn, {kb(tc - mc)}, avg {(tc - mc) / max(tf - mf, 1):,.0f} B "
                f"(matched avg {mc / max(mf, 1):,.0f} B)"]
        if w3["v_bytes"] and w3["v_bytes"] > 0:
            out.append(f"At the 3 h verified rate: ~{(tc - mc) / (w3['v_bytes'] / w3['hours']):,.0f} h of fleet time left")
    s = st["session"]
    if s:
        state = "running" if s["live"] else f"ended {hm(s['end'])}"
        v = f"+{s['v_fns']:,} fn / +{kb(s['v_bytes'])}" if s["v_fns"] is not None else "-"
        out += ["", f"{B}Session{R} {hm(s['start'])}, {state}, {ago(s['start'], s['end'] if not s['live'] else now)}",
                f"  verified {v}   claimed {s['fns']:,} fn / {kb(s['bytes'])}",
                f"  near-miss {s['near']} of {s['commits']} commits ({pct(s['near'], s['commits'])})"]
    out.append(f"{D}verified = bot build of main ({ago(st['verified_at'], now)} ago); claimed = worker commits{R}")

    cols, table = speed_rows(st)
    cw = 10 if width < 100 else 11
    out += ["", f"{B}{'SPEED':<18}" + "".join(f"{c:>{cw}}" for c in cols) + R]
    for label, row in zip(TERM_LABELS, table):
        out.append(f"{label:<18}" + "".join(f"{c:>{cw}}" for c in row[1:]))

    h = st["hourly"]
    per = 2 if width >= 20 + 2 * len(h) + 12 else 1  # columns per hour
    step = 3 if per == 2 else 6
    labels = "".join((hm(x["t0"])[:2] + " " * (per * step - 2)) if i % step == 0 else "" for i, x in enumerate(h))
    near = [100 * x["near"] / x["commits"] if x["commits"] else 0 for x in h]
    sp = (lambda v: spark(v)) if per == 2 else (lambda v: spark(v)[::2])
    out += ["", f"{B}LAST {CHART_HOURS} H{R}  {D}by hour; the last is this hour so far{R}",
            f"  code claimed  {sp([x['kb_per_h'] for x in h])} {max(x['kb_per_h'] for x in h):,.0f} KB",
            f"  near-miss     {sp(near)} {max(near):.0f}%",
            f"  workers       {sp([x['workers'] for x in h])} {max(x['workers'] for x in h)}",
            f"  {D}hour          {labels.rstrip()}{R}"]

    out += ["", f"{B}{'WORKER':<7}{'batch':<9}{'commit':>7}{'build':>7}{'1h':>4}{'near':>5}{'wait':>5}  last commit{R}"
            f"  {D}(dim: quiet 10m+){R}"]
    idle = [w["slot"] for w in st["workers"] if w["state"] == "idle"]
    for w in st["workers"]:
        if w["state"] == "idle":
            continue
        color = "" if w["state"] == "active" else D
        last = w["last_subject"]
        p = parse_subject(last) if width < 100 else None
        if p and (p["near"] or p["matched"]):
            near = p["near"] or p["kind"] != "match"
            last = (p["near"] or p["matched"])[0] + (f" near {p['close']:.1f}%" if near and p["close"] else " near" if near else "")
        out.append(f"{color}{w['slot']:<7}{w['branch'].replace('work/', '')[:8]:<9}"
                   f"{ago(w['last_commit'], now):>7}{ago(w['built'], now):>7}{w['commits_1h']:>4}{w['near_1h']:>5}"
                   f"{w['pending']:>5}  {last}{R}")
    if idle:
        out.append(f"{D}idle, nothing for 1 h+: {' '.join(idle)}{R}")
    backlog = (f"{st['pending']} commits on {st['pending_branches']} branches, oldest {ago(st['oldest_pending'], now)}"
               if st["pending"] else "nothing waiting")
    out += ["", f"{B}MERGE BACKLOG{R}  {backlog}; last merge into main {ago(st['last_merge'], now)} ago"]

    c = st["close"]
    if c:
        b = c["bands"]
        out += ["", f"{B}CLOSE TO MATCHING{R} {D}fn (code), main build {ago(c['time'], now)} ago{R}",
                f"  >=99% {b['99'][0]} ({b['99'][1] / 1024:.0f} KB)   95-99% {b['95'][0]} ({b['95'][1] / 1024:.0f} KB)"
                f"   80-95% {b['80'][0]} ({b['80'][1] / 1024:.0f} KB)"]
        for p, size, name, unit in c["top"][:3]:
            out.append(f"  {p:6.2f}%  {size:>6,} B  {name.split('__')[0]:<14} {unit}")
    if st["near_recent"]:
        out += ["", f"{B}RECENT NEAR-MISS COMMITS{R}"]
        for r in st["near_recent"][:4]:
            close = f"{r['close']:.1f}%" if r["close"] else "  ?  "
            fns = (r["near"][0] + (f" +{len(r['near']) - 1}" if len(r["near"]) > 1 else "")) if r["near"] else "-"
            out.append(f"  {hm(r['t'])}  {close:>6}  {fns:<15} {r['unit']}")
    if st["farm"]:
        out += ["", f"{B}PERMUTER FARM{R}  {farm_line(st['farm'], now)}"]
        for e in st["farm"]["matched"][:4]:
            out.append(f"  MATCH  {e['fn'].split('__')[0]:<14} {e['unit']}  (was {e['pct']:.2f}%; patch in ledger)")
    return "\n".join(out)


ANSI = re.compile(r"\x1b\[[0-9;?]*[A-Za-z]")


def fit(screen: str, cols: int, rows: int) -> List[str]:
    """Clip to the terminal so a redraw never scrolls (a scrolled screen smears on the next one)."""
    out = []
    for line in screen.split("\n")[:max(1, rows - 1)]:
        clipped, width, pos = [], 0, 0
        for m in ANSI.finditer(line):
            text = line[pos:m.start()][:max(0, cols - 1 - width)]
            clipped.append(text)
            width += len(text)
            clipped.append(m.group(0))
            pos = m.end()
        clipped.append(line[pos:][:max(0, cols - 1 - width)])
        out.append("".join(clipped) + "\x1b[0m")
    return out


def watch(every: int) -> None:
    if os.name == "nt":
        os.system("")  # turn on ANSI escapes in the Windows console
    try:
        sys.stdout.reconfigure(encoding="utf-8")
    except (AttributeError, ValueError):
        pass
    sys.stdout.write("\x1b[?25l\x1b[2J")
    try:
        while True:
            size = shutil.get_terminal_size()
            try:
                screen = render_terminal(collect(), every, size.columns)
            except Exception as e:  # keep watching through a transient git error
                screen = f"dashboard error (retrying): {e}"
            sys.stdout.write("\x1b[H" + "\x1b[K\n".join(fit(screen, size.columns, size.lines)) + "\x1b[K\x1b[J")
            sys.stdout.flush()
            time.sleep(every)
    except KeyboardInterrupt:
        pass
    finally:
        sys.stdout.write("\x1b[?25h\n")


# ----------------------------------------------------------------------------- GitHub


def md_table(head: List[str], rows: List[List[str]], align: str = "") -> List[str]:
    align = align or "l" + "r" * (len(head) - 1)
    sep = ["---:" if a == "r" else "---" for a in align]
    return ["| " + " | ".join(head) + " |", "| " + " | ".join(sep) + " |"] + ["| " + " | ".join(r) + " |" for r in rows]


def render_md(st: Dict[str, Any], chart: str) -> str:
    now = st["now"]
    stamp = datetime.datetime.fromtimestamp(now).strftime(f"%a %b %d, %H:%M {tzname()}")
    out = [
        "# MVP Baseball 2005 decomp: live fleet dashboard",
        "",
        f"**Updated {stamp}.** Refreshed about every minute while the owner's PC is on, by "
        f"[`tools/fleet_dashboard.py`]({REPO_URL}/blob/main/tools/fleet_dashboard.py) reading git history. "
        f"*Verified* numbers come from the progress bot's build of `main` (last one at {hm(st['verified_at'])}). "
        "*Claimed* numbers are worker commits that may not be merged or verified yet. "
        f"The overall progress card is on the [main README]({REPO_URL}#progress).",
        "",
    ]
    out += [f"- {line}" for line in headline(st)] + [f"- {session_line(st)}", ""]

    cols, table = speed_rows(st)
    out += ["## Speed", ""] + md_table([""] + cols, table) + [""]
    out += [f"![Last {CHART_HOURS} hours: code claimed per hour, near-miss share of commits, and workers active, one bar per hour]({chart})", ""]

    out += ["## Workers", ""]
    rows = [[w["slot"], f"`{w['branch'].replace('work/', '')}`", w["state"], hm(w["last_commit"]), hm(w["built"]),
             str(w["commits_1h"]), str(w["near_1h"]), str(w["pending"]), escape(w["last_subject"][:70]).replace("|", "\\|")]
            for w in st["workers"]]
    out += md_table(["Slot", "Batch", "State", "Last commit", "Last build", "Commits (1 h)", "Near-miss (1 h)",
                     "Waiting to merge", "Last commit subject"], rows, "lllrrrrrl") + [""]
    backlog = (f"{st['pending']} commits on {st['pending_branches']} branches, oldest from {hm(st['oldest_pending'])}"
               if st["pending"] else "nothing waiting")
    out += [f"**Merge backlog:** {backlog}. Last merge into `main` at {hm(st['last_merge'])}.", ""]

    c = st["close"]
    if c:
        b = c["bands"]
        out += ["## Close to matching", "", f"Functions below 100% in the build of `main` at {hm(c['time'])}.", ""]
        out += md_table(["Match", "Functions", "Code"], [
            [">= 99%", str(b["99"][0]), kb(b["99"][1])],
            ["95-99%", str(b["95"][0]), kb(b["95"][1])],
            ["80-95%", str(b["80"][0]), kb(b["80"][1])],
        ]) + [""]
        out += md_table(["Closest", "Match", "Size", "Unit"],
                        [[f"`{n.split('__')[0]}`", f"{p:.2f}%", f"{s:,} B", f"`{u}`"] for p, s, n, u in c["top"]], "lrrl") + [""]
    if st["near_recent"]:
        out += ["## Recent near-miss commits", ""]
        out += md_table(["Time", "Closest", "Functions", "Unit"], [
            [hm(r["t"]), f"{r['close']:.1f}%" if r["close"] else "-", ", ".join(f"`{f}`" for f in r["near"][:4]) or "-",
             f"`{r['unit']}`"] for r in st["near_recent"]], "lrll") + [""]
    if st["farm"]:
        out += ["## Permuter farm", "", "Unattended decomp-permuter runs over main's near-misses at idle CPU priority "
                "(`tools/match/permute_farm.py`). A match candidate is confirmed by rebuilding its unit and "
                "waits as a patch for a worker to apply and verify.", "", farm_line(st["farm"], now), ""]
        if st["farm"]["matched"]:
            out += md_table(["Match candidate", "Unit", "Was"], [
                [f"`{e['fn'].split('__')[0]}`", f"`{e['unit']}`", f"{e['pct']:.2f}%"] for e in st["farm"]["matched"][:20]],
                "llr") + [""]
    hours =", ".join(f"{hm(x['t0'])} {x['kb_per_h']:.0f} KB" for x in st["hourly"] if x["commits"])
    out += [f"<sub>Code claimed per hour behind the chart: {hours}</sub>", ""]
    return "\n".join(out)


def render_svg(st: Dict[str, Any]) -> str:
    W, PAD, PH, GAP = 960, 24, 92, 34
    h = st["hourly"]
    panels = [
        ("Code claimed per hour", [x["kb_per_h"] for x in h], lambda v: f"{v:,.0f} KB"),
        ("Near-miss share of commits", [100 * x["near"] / x["commits"] if x["commits"] else 0 for x in h], lambda v: f"{v:.0f}%"),
        ("Workers active", [float(x["workers"]) for x in h], lambda v: f"{v:.0f}"),
    ]
    left, right = PAD + 8, W - PAD - 8
    slot = (right - left) / len(h)
    bw = max(2.0, slot - 2)  # 2px surface gap between bars
    body: List[str] = []
    y = PAD
    for title, vals, fmt in panels:
        body.append(f'<text x="{PAD}" y="{y + 14}" class="t1" font-size="14" font-weight="600">{escape(title)}</text>')
        top = max(vals) or 1.0
        base = y + 34 + PH
        body.append(f'<line x1="{left}" y1="{base + 0.5}" x2="{right}" y2="{base + 0.5}" class="axis"/>')
        peak = max(range(len(vals)), key=lambda i: vals[i])
        for i, v in enumerate(vals):
            x = left + i * slot + 1
            bh = PH * v / top
            if bh <= 0:
                continue
            r = min(4.0, bw / 2, bh)
            cls = "b1" if i == len(vals) - 1 else "b3"  # the current, partial hour is lighter
            body.append(
                f'<path class="{cls}" d="M{x:.1f},{base} V{base - bh + r:.1f} Q{x:.1f},{base - bh:.1f} {x + r:.1f},{base - bh:.1f} '
                f'H{x + bw - r:.1f} Q{x + bw:.1f},{base - bh:.1f} {x + bw:.1f},{base - bh + r:.1f} V{base} Z">'
                f'<title>{hm(h[i]["t0"])}: {escape(fmt(v))}</title></path>')
            if i in (peak, len(vals) - 1) and v > 0:
                body.append(f'<text x="{x + bw / 2:.1f}" y="{base - bh - 5:.1f}" class="t2" font-size="11" text-anchor="middle">{escape(fmt(v))}</text>')
        y = base + GAP
    for i, x in enumerate(h):
        if i % 3 == 0:
            body.append(f'<text x="{left + i * slot + slot / 2:.1f}" y="{y - GAP + 16}" class="t3" font-size="11" text-anchor="middle">{hm(x["t0"])}</text>')
    total = int(y - GAP + 30)
    desc = "; ".join(f"{hm(x['t0'])} {x['kb_per_h']:.0f} KB/h, {x['workers']} workers" for x in h if x["commits"])
    return "\n".join([
        f'<svg xmlns="http://www.w3.org/2000/svg" width="{W}" height="{total}" viewBox="0 0 {W} {total}" role="img" aria-labelledby="title desc">',
        f'<title id="title">Fleet activity, last {CHART_HOURS} hours</title>',
        f'<desc id="desc">{escape(desc)}</desc>',
        f"<style>{STYLE}</style>",
        f'<rect x="0.5" y="0.5" width="{W - 1}" height="{total - 1}" rx="8" class="surface"/>',
        f'<rect x="0.5" y="0.5" width="{W - 1}" height="{total - 1}" rx="8" class="border"/>',
        *body,
        "</svg>",
    ]) + "\n"


def log(msg: str) -> None:
    STATE_DIR.mkdir(parents=True, exist_ok=True)
    if LOG.is_file() and LOG.stat().st_size > 1_000_000:
        os.replace(LOG, LOG.with_suffix(".log.1"))
    with open(LOG, "a", encoding="utf-8") as f:
        f.write(f"{datetime.datetime.now():%Y-%m-%d %H:%M:%S}  {msg}\n")
    if sys.stdout is not None:
        print(msg, flush=True)


def publish(force: bool, push: bool) -> None:
    st = collect()
    svg = render_svg(st)
    chart = f"chart-{hashlib.sha1(svg.encode()).hexdigest()[:10]}.svg"  # new name defeats image caches
    md = render_md(st, chart)
    digest = hashlib.sha1(re.sub(r"\*\*Updated [^*]*\*\*", "", md).encode() + svg.encode()).hexdigest()
    try:
        last = json.loads(PUBLISHED.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        last = {}
    if not force and last.get("digest") == digest and time.time() - last.get("time", 0) < HEARTBEAT:
        return
    if not push:
        out = STATE_DIR / "preview"
        out.mkdir(parents=True, exist_ok=True)
        for old in out.glob("chart-*.svg"):
            old.unlink()
        (out / "README.md").write_text(md, encoding="utf-8")
        (out / chart).write_text(svg, encoding="utf-8")
        log(f"--no-push: wrote {out}")
        return
    blobs = [git("hash-object", "-w", "--stdin", stdin=text).strip() for text in (md, svg)]
    tree = git("mktree", stdin=f"100644 blob {blobs[0]}\tREADME.md\n100644 blob {blobs[1]}\t{chart}\n").strip()
    lt = st["latest"]
    msg = f"dashboard: {lt[1]:,} functions verified, {st['pending']} commits waiting" if lt else "dashboard"
    commit = git("commit-tree", tree, "-m", msg).strip()
    git(*GIT_AUTH, "push", "--quiet", "--force", "origin", f"{commit}:refs/heads/{BRANCH}")
    PUBLISHED.write_text(json.dumps({"digest": digest, "time": time.time(), "commit": commit}), encoding="utf-8")
    log(f"pushed {commit[:10]}: {msg}")


def acquire_lock() -> bool:
    STATE_DIR.mkdir(parents=True, exist_ok=True)
    try:
        if LOCK.is_file() and time.time() - LOCK.stat().st_mtime > 600:
            LOCK.unlink()  # left behind by a run that died
        fd = os.open(LOCK, os.O_CREAT | os.O_EXCL | os.O_WRONLY)
    except FileExistsError:
        return False
    os.write(fd, str(os.getpid()).encode())
    os.close(fd)
    return True


def install(every: int) -> None:
    pythonw = Path(PY).with_name("pythonw.exe")
    tr = f'"{pythonw}" "{Path(__file__).resolve()}" --publish'
    subprocess.run(["schtasks", "/Create", "/F", "/TN", TASK_NAME, "/SC", "MINUTE", "/MO", str(every), "/TR", tr], check=True)
    print(f"Scheduled '{TASK_NAME}' every {every} minute(s): {tr}")


def main(argv: Optional[List[str]] = None) -> None:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--watch", nargs="?", const=5, type=int, metavar="SECS", help="redraw the terminal view every SECS")
    ap.add_argument("--publish", action="store_true", help="push the dashboard branch if anything changed")
    ap.add_argument("--force", action="store_true", help="with --publish: push even if nothing changed")
    ap.add_argument("--no-push", action="store_true", help="with --publish: write build/_dashboard/preview instead")
    ap.add_argument("--install", action="store_true", help="register the --publish scheduled task")
    ap.add_argument("--every", type=int, default=1, help="minutes between runs (with --install)")
    ap.add_argument("--uninstall", action="store_true", help="remove the scheduled task")
    args = ap.parse_args(argv)

    if args.install:
        install(args.every)
    elif args.uninstall:
        subprocess.run(["schtasks", "/Delete", "/F", "/TN", TASK_NAME], check=True)
    elif args.watch:
        watch(max(1, args.watch))
    elif args.publish:
        if not acquire_lock():
            return
        try:
            publish(args.force, not args.no_push)
        except Exception:
            log("ERROR\n" + traceback.format_exc())
            sys.exit(1)
        finally:
            LOCK.unlink(missing_ok=True)
    else:
        try:
            sys.stdout.reconfigure(encoding="utf-8")
        except (AttributeError, ValueError):
            pass
        print(re.sub(r"\x1b\[[0-9;]*m", "", render_terminal(collect(), None)))


if __name__ == "__main__":
    main()
