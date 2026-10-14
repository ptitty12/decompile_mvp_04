#!/usr/bin/env python3
"""Goals view: engine milestones and knowledge targets, from git and the progress bot's build.

The project's goals (docs/ROADMAP.md, owner, 2026-10-14) are measured by the engine
milestones E0a-E7 and the knowledge targets K1-K4, not by match percent. This module
collects both and renders them for the top of the live dashboard
(tools/fleet_dashboard.py). Run alone, it prints the same summary as text:

  python tools/goals/goals_view.py

Sources (read only; nothing is built and no model is called):
  plan start  the commit that added docs/ROADMAP.md to origin/main.
  milestones  the engine track table in docs/ROADMAP.md on origin/main (id, name, exit),
              plus every docs/engine/E*_LOG.md on any ref (E0c is a log without a
              roadmap row: follow-up work, shown but not counted as a milestone).
  steps       the "## Status" table of the newest version of each log, on any ref.
              A step is done when its State cell starts with "Done".
  started     the first commit tagged with the milestone: a subject that ends in
              "(E1)" / "(E0b item 3)" or starts "docs(engine): E0a ...". The first
              roadmap milestone starts with the plan.
  closed      a "E0b closed" commit on origin/main, or a log on origin/main whose
              steps are all done (then the last commit to that log on main).
  branches    refs/heads/engine/* commits not on origin/main.
  knowledge   tools/goals/targets.py run on the progress bot's latest build of main
              (build/_progress/wt/build/GV4E69 in the main checkout), cached until
              that build changes. Exit thresholds come from the knowledge track table
              in docs/ROADMAP.md.
"""
import datetime
import json
import re
import subprocess
import sys
import time
from html import escape
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent.parent
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(ROOT / "tools"))
import targets  # noqa: E402  (tools/goals/targets.py)

REPO_URL = "https://github.com/ptitty12/mvp2005-decomp"
NO_WINDOW = getattr(subprocess, "CREATE_NO_WINDOW", 0)
ENGINE_EXCLUDE = ":(exclude)engine/third_party"

TAG_END = re.compile(r"\((E\d[a-z]?)\b[^()]*\)\s*$")         # "... (E0b item 3)", "... (E1)"
TAG_LEAD = re.compile(r"^[\w-]+(?:\([^)]*\))?: (E\d[a-z]?)\b")  # "docs(engine): E0a ...", "docs: E0c ..."
CLOSED = re.compile(r"\b(E\d[a-z]?) closed\b")
LOG_PATH = re.compile(r"^docs/engine/(E\d[a-zA-Z]?)_LOG\.md$")  # E0B_LOG.md is milestone E0b
THRESHOLD = re.compile(r"≥\s*(\d+)\s*%")

# Knowledge done percent when the plan was adopted (docs/ROADMAP.md §3 at d68734ec).
K_AT_PLAN_START = {"K1": 48, "K2": 7, "K3": 0, "K4": 1}
# Which engine milestones need each target (docs/ROADMAP.md §4, "Dependencies").
K_NEEDED_BY = {"K1": "E0b", "K2": "E6, E7", "K3": "E4", "K4": ""}
K_SHORT = {"K1": "SDK names", "K2": "Roster data path", "K3": "Determinism", "K4": "Main loop"}


def git(*args: str, cwd: Path = ROOT, check: bool = True) -> str:
    r = subprocess.run(["git", *args], cwd=cwd, creationflags=NO_WINDOW,
                       stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if check and r.returncode:
        raise RuntimeError(f"git {' '.join(args[:2])} failed: {r.stderr.decode(errors='replace').strip()[:300]}")
    return r.stdout.decode("utf-8", "replace").replace("\r\n", "\n")


def show(spec: str) -> Optional[str]:
    try:
        return git("show", spec)
    except RuntimeError:
        return None


def mid_key(mid: str) -> Tuple[int, str]:
    return int(mid[1]), mid[2:]


# ----------------------------------------------------------------------------- parsing


def roadmap_tables(text: str) -> Tuple[List[Dict[str, str]], List[Dict[str, Any]]]:
    """(engine rows, knowledge rows) from the milestone tables in docs/ROADMAP.md."""
    engine: List[Dict[str, str]] = []
    knowledge: List[Dict[str, Any]] = []
    section = ""
    for line in text.splitlines():
        if line.startswith("### "):
            section = line[4:].strip().lower()
            continue
        if line.startswith("## "):
            section = ""
        if not line.startswith("| ") or section not in ("engine track", "knowledge track"):
            continue
        cells = [c.strip() for c in line.strip().strip("|").split("|")]
        if len(cells) < 3 or not re.fullmatch(r"[EK]\d[a-z]?", cells[0]):
            continue
        m = re.match(r"\*\*(.+?)\*\*", cells[1])
        name = (m.group(1) if m else cells[1]).rstrip(".")
        if section == "engine track":
            engine.append({"id": cells[0], "name": name, "exit": cells[2]})
        else:
            t = THRESHOLD.search(cells[2])
            knowledge.append({"id": cells[0], "name": name, "exit": cells[2], "threshold": int(t.group(1)) if t else None})
    return engine, knowledge


def log_steps(text: str) -> Optional[Tuple[int, int]]:
    """(done, total) from a log's "## Status" table."""
    m = re.search(r"^## Status[ \t]*$(.*?)(?=^## |\Z)", text, re.M | re.S)
    if not m:
        return None
    table = [[c.strip() for c in l.strip().strip("|").split("|")] for l in m.group(1).splitlines()
             if l.lstrip().startswith("|")]
    if len(table) < 3:
        return None
    head = [c.lower() for c in table[0]]
    col = head.index("state") if "state" in head else -1  # E0b's table has a Commit column after State
    states = [r[col] if len(r) > abs(col) else "" for r in table[2:]]
    return sum(1 for s in states if re.match(r"done\b", s, re.I)), len(states)


def log_title(text: str) -> str:
    first = text.splitlines()[0] if text else ""
    return first.split(":", 1)[1].strip() if ":" in first else ""


def milestone_tag(subject: str) -> Optional[str]:
    m = TAG_END.search(subject) or TAG_LEAD.match(subject)
    return m.group(1) if m else None


# ----------------------------------------------------------------------------- collect


def engine_lines(rev: str) -> Tuple[int, int]:
    """(lines of engine code, doctest cases) at rev, vendored third_party excluded."""
    lines = sum(int(l.rsplit(":", 1)[1]) for l in git("grep", "-c", "", rev, "--", "engine", ENGINE_EXCLUDE,
                                                        check=False).splitlines() if l.strip())
    tests = sum(int(l.rsplit(":", 1)[1]) for l in git("grep", "-c", "-E", r"^\s*TEST_CASE\(", rev, "--", "engine",
                                                        ENGINE_EXCLUDE, check=False).splitlines() if l.strip())
    return lines, tests


def knowledge(main_checkout: Optional[Path], state_dir: Path, rows: List[Dict[str, Any]]) -> Optional[Dict[str, Any]]:
    if not main_checkout:
        return None
    build = main_checkout / "build" / "_progress" / "wt" / "build" / "GV4E69"
    report = build / "report.json"
    if not report.is_file():
        return None
    st = report.stat()
    key = f"{st.st_mtime_ns}:{st.st_size}"
    cache_path = state_dir / "goals_targets.json"
    try:
        cache = json.loads(cache_path.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        cache = {}
    if cache.get("key") != key:
        fns, strings = targets.load(str(build))
        out = {}
        for k, t in targets.targets(fns, strings).items():
            fs = [fns[n] for n in t.names]
            done = sum(1 for f in fs if targets.done(f, t.need))
            out[k] = {"functions": len(fs), "named": sum(f.named for f in fs), "matched": sum(f.matched for f in fs),
                      "done": done, "pct": 100.0 * done / max(1, len(fs)), "need": t.need}
        cache = {"key": key, "time": st.st_mtime, "targets": out}
        state_dir.mkdir(parents=True, exist_ok=True)
        cache_path.write_text(json.dumps(cache, indent=1), encoding="utf-8")
    res = []
    for r in rows:
        t = cache["targets"].get(r["id"])
        if t:
            res.append({**r, **t, "short": K_SHORT.get(r["id"], r["name"]), "was": K_AT_PLAN_START.get(r["id"]),
                        "needed_by": K_NEEDED_BY.get(r["id"], "")})
    return {"time": cache["time"], "rows": res}


def collect(main_checkout: Optional[Path] = None, state_dir: Optional[Path] = None) -> Dict[str, Any]:
    now = time.time()
    state_dir = state_dir or ROOT / "build" / "_goals"
    added = git("log", "origin/main", "--diff-filter=A", "--format=%at", "--", "docs/ROADMAP.md").split()
    plan_start = float(added[-1]) if added else now
    roadmap = show("origin/main:docs/ROADMAP.md") or ""
    engine_rows, k_rows = roadmap_tables(roadmap)

    # Every commit since the plan, once (cherry-picked copies share subject and author time).
    seen, commits = set(), []
    for line in git("log", "--all", "--no-merges", f"--since={int(plan_start) - 3600}", "--format=%at %s").splitlines():
        t, _, subject = line.partition(" ")
        if (t, subject) in seen or not t.isdigit():
            continue
        seen.add((t, subject))
        commits.append((float(t), subject))
    commits.sort()
    on_main = [(float(t), s) for t, _, s in (l.partition(" ") for l in
               git("log", "origin/main", f"--since={int(plan_start) - 3600}", "--format=%at %s").splitlines()) if t.isdigit()]

    # Newest version of each log on any ref, and its version on main.
    newest: Dict[str, Tuple[float, str, str]] = {}
    first_log: Dict[str, float] = {}
    cur: Optional[Tuple[float, str]] = None
    for line in git("log", "--all", "--format=%x00%at %H", "--name-only", "--", "docs/engine").splitlines():
        if line.startswith("\0"):
            t, h = line[1:].split()
            cur = (float(t), h)
            continue
        m = LOG_PATH.match(line.strip())
        if m and cur:
            mid = m.group(1)[:2] + m.group(1)[2:].lower()
            if mid not in newest or cur[0] > newest[mid][0]:
                newest[mid] = (cur[0], cur[1], line.strip())
            first_log[mid] = min(first_log.get(mid, cur[0]), cur[0])

    # Engine branches: commits not on main, by milestone.
    branches: Dict[str, Dict[str, Any]] = {}
    for ref in git("for-each-ref", "--format=%(refname:short)", "refs/heads/engine/").split():
        ahead = git("log", "--no-merges", "--format=%at %s", ref, "--not", "origin/main").splitlines()
        if not ahead:
            continue
        ids = {milestone_tag(l.partition(" ")[2]) for l in ahead} - {None}
        stat = git("diff", "--shortstat", f"origin/main...{ref}", "--", "engine", ENGINE_EXCLUDE)
        ins = re.search(r"(\d+) insertion", stat)
        branches[ref] = {"ids": ids, "commits": len(ahead), "last": float(ahead[0].split()[0]),
                         "lines": int(ins.group(1)) if ins else 0}

    ids = sorted({r["id"] for r in engine_rows} | set(newest), key=mid_key)
    by_id = {r["id"]: r for r in engine_rows}
    milestones = []
    for i, mid in enumerate(ids):
        row = by_id.get(mid)
        tagged = [(t, s) for t, s in commits if milestone_tag(s) == mid]
        path = newest[mid][2] if mid in newest else None
        main_log = show(f"origin/main:{path}") if path else None
        log = show(f"{newest[mid][1]}:{path}") if path else None
        steps = log_steps(log) if log else None
        main_steps = log_steps(main_log) if main_log else None
        closed = next((t for t, s in on_main if (m := CLOSED.search(s)) and m.group(1) == mid), None)
        if closed is None and main_steps and main_steps[1] and main_steps[0] == main_steps[1]:
            last = git("log", "-1", "--format=%at", "origin/main", "--", path).strip()
            closed = float(last) if last else None
        starts = [t for t, _ in tagged] + ([first_log[mid]] if mid in first_log else [])
        started = min(starts) if starts else None
        if row and mid == engine_rows[0]["id"]:
            started = plan_start
        branch = next((b for b, v in branches.items() if mid in v["ids"]), None)
        state = "closed" if closed else "active" if (started or steps) else "todo"
        milestones.append({
            "id": mid,
            "name": row["name"] if row else (log_title(log or "")[:1].upper() + log_title(log or "")[1:]),
            "exit": row["exit"] if row else "",
            "roadmap": bool(row),
            "log": path,
            "log_on_main": main_log is not None,
            "log_title": log_title(log or ""),
            "state": state,
            "steps": steps,
            "started": started,
            "closed": closed,
            "commits": len(tagged),
            "branch": branch,
            "last": max([t for t, _ in tagged], default=None),
        })

    main_lines, tests = engine_lines("origin/main")
    engine_commits = [t for t, s in commits if s.startswith("engine(") or milestone_tag(s)]
    return {
        "now": now,
        "plan_start": plan_start,
        "milestones": milestones,
        "branches": branches,
        "engine_lines": main_lines,
        "engine_tests": tests,
        "engine_commits": len(engine_commits),
        "engine_commits_1h": sum(1 for t in engine_commits if t >= now - 3600),
        "knowledge": knowledge(main_checkout, state_dir, k_rows),
    }


# ----------------------------------------------------------------------------- formatting


def when(t: Optional[float], now: float) -> str:
    if not t:
        return "-"
    d = datetime.datetime.fromtimestamp(t)
    return d.strftime("%H:%M") if d.date() == datetime.datetime.fromtimestamp(now).date() else d.strftime("%a %b %d %H:%M")


def span(sec: float) -> str:
    if sec < 3600:
        return f"{sec / 60:.0f} min"
    if sec < 48 * 3600:
        return f"{sec / 3600:.1f} h"
    return f"{sec / 86400:.1f} days"


def steps_text(m: Dict[str, Any]) -> str:
    return f"{m['steps'][0]}/{m['steps'][1]}" if m["steps"] and m["steps"][1] else "-"


def headline(g: Dict[str, Any]) -> List[str]:
    now, ms = g["now"], g["milestones"]
    day = (datetime.datetime.fromtimestamp(now).date() - datetime.datetime.fromtimestamp(g["plan_start"]).date()).days + 1
    road = [m for m in ms if m["roadmap"]]
    closed = [m for m in road if m["state"] == "closed"]
    follow = [m for m in ms if not m["roadmap"] and m["state"] == "closed"]
    out = [f"**Day {day} of the browser plan** (adopted {when(g['plan_start'], now)}, {span(now - g['plan_start'])} ago)."]
    s = f"**Engine:** {len(closed)} of {len(road)} roadmap milestones closed"
    s += f" ({', '.join(m['id'] for m in closed)})" if closed else ""
    s += f", plus the {', '.join(m['id'] for m in follow)} follow-ups." if follow else "."
    active = [m for m in ms if m["state"] == "active"]
    if active:
        parts = []
        for m in active:
            where = f" on `{m['branch']}`" if m["branch"] else ""
            last = f", last commit {when(m['last'], now)}" if m["last"] else ""
            parts.append(f"{m['id']} {m['name']}: {steps_text(m)} steps{where}{last}")
        s += " In progress: " + "; ".join(parts) + "."
    out.append(s)
    nxt = next((m for m in ms if m["roadmap"] and m["state"] != "closed"), None)
    if nxt:
        out.append(f"**Next exit ({nxt['id']}):** {nxt['exit'].rstrip('.')}.")
    pending = sum(b["lines"] for b in g["branches"].values())
    s = (f"**Engine code:** {g['engine_lines']:,} lines on `main` with {g['engine_tests']} test cases")
    s += f", plus {pending:,} lines on engine branches not merged yet." if pending else "."
    s += f" {g['engine_commits']} engine commits since the plan started, {g['engine_commits_1h']} in the last hour."
    out.append(s)
    k = g["knowledge"]
    if k:
        parts = []
        for r in k["rows"]:
            met = r["threshold"] is not None and r["pct"] >= r["threshold"]
            parts.append(f"{r['id']} {r['short']} {r['pct']:.0f}%" + (" (exit met)" if met else ""))
        out.append("**Knowledge:** " + "; ".join(parts) + ".")
    return out


def render_md(g: Dict[str, Any], chart: Optional[str]) -> List[str]:
    now = g["now"]
    out = ["## Browser plan", ""]
    out += [f"- {line}" for line in headline(g)] + [""]
    if chart:
        out += [f"![Engine milestones on a timeline since the plan started, and knowledge targets as meters]({chart})", ""]
    out += ["### Engine milestones", "",
            f"From [`docs/ROADMAP.md`]({REPO_URL}/blob/main/docs/ROADMAP.md#4-milestones) and the logs in "
            f"[`docs/engine/`]({REPO_URL}/tree/main/docs/engine). Times are first tagged commit and close.", "",
            "| | Milestone | State | Steps | Started | Closed | Took | Exit |",
            "|---|---|---|---:|---:|---:|---:|---|"]
    for m in g["milestones"]:
        state = {"closed": "Closed", "active": "**In progress**", "todo": "Not started"}[m["state"]]
        if m["state"] == "active" and m["branch"]:
            state += f" (`{m['branch']}`)"
        name = m["name"] if m["roadmap"] else f"{m['name']} (E{m['id'][1]} follow-ups)"
        if m["log"] and m["log_on_main"]:
            name = f"[{name}]({REPO_URL}/blob/main/{m['log']})"
        took = span(m["closed"] - m["started"]) if m["closed"] and m["started"] else (
            f"{span(now - m['started'])} so far" if m["started"] else "-")
        out.append(f"| **{m['id']}** | {name} | {state} | {steps_text(m)} | {when(m['started'], now)} | "
                   f"{when(m['closed'], now)} | {took} | {m['exit'].replace('|', '/') or '-'} |")
    out.append("")
    k = g["knowledge"]
    if k:
        out += ["### Knowledge targets", "",
                f"From [`tools/goals/targets.py`]({REPO_URL}/blob/main/tools/goals/targets.py) on the progress bot's "
                f"build of `main` at {when(k['time'], now)}. K1 is done when named; K2-K4 when matched and named.", "",
                "| Target | Functions | Named | Matched | Done | At plan start | Exit | Needed by |",
                "|---|---:|---:|---:|---:|---:|---:|---|"]
        for r in k["rows"]:
            ex = f"≥ {r['threshold']}%" if r["threshold"] is not None else "-"
            if r["threshold"] is not None and r["pct"] >= r["threshold"]:
                ex += " (met)"
            was = f"{r['was']}%" if r["was"] is not None else "-"
            out.append(f"| {r['id']} {r['short']} | {r['functions']} | {r['named']} | {r['matched']} | "
                       f"{r['done']} ({r['pct']:.0f}%) | {was} | {ex} | {r['needed_by'] or '-'} |")
        out.append("")
    return out


def ticks(t0: float, t1: float) -> List[Tuple[float, str]]:
    total = max(1.0, t1 - t0)
    hours = next((h for h in (1, 2, 3, 6, 12, 24, 48, 96, 168, 336) if total / (h * 3600) <= 8), 720)
    d = datetime.datetime.fromtimestamp(t0)
    if hours < 24:
        d = d.replace(minute=0, second=0, microsecond=0) + datetime.timedelta(hours=1)
        while d.hour % hours:
            d += datetime.timedelta(hours=1)
    else:
        d = d.replace(hour=0, minute=0, second=0, microsecond=0) + datetime.timedelta(days=1)
    out, day = [], None
    while d.timestamp() <= t1:
        if hours < 24:
            label = d.strftime("%H:%M") if d.date() == day else d.strftime("%a %H:%M")
            day = d.date()
        else:
            label = d.strftime("%b %d")
        out.append((d.timestamp(), label))
        d += datetime.timedelta(hours=hours)
    return out


def render_svg(g: Dict[str, Any], style: str) -> str:
    W, PAD, ROW, KROW = 960, 24, 24, 26
    now, t0 = g["now"], g["plan_start"]
    ms, k = g["milestones"], g["knowledge"]
    lx, x0, x1 = PAD, PAD + 300, W - PAD - 96
    xs = lambda t: x0 + (x1 - x0) * (min(max(t, t0), now) - t0) / max(1.0, now - t0)  # noqa: E731
    body: List[str] = []

    # Panel 1: milestone timeline.
    y = PAD
    body.append(f'<text x="{PAD}" y="{y + 14}" class="t1" font-size="14" font-weight="600">Engine milestones since the plan started</text>')
    lg = W - PAD - 250
    body.append(f'<rect x="{lg}" y="{y + 4}" width="12" height="12" rx="3" class="b3"/>'
                f'<text x="{lg + 18}" y="{y + 14}" class="t2" font-size="12">Closed</text>'
                f'<rect x="{lg + 80}" y="{y + 4}" width="12" height="12" rx="3" class="b1"/>'
                f'<text x="{lg + 98}" y="{y + 14}" class="t2" font-size="12">In progress (to now)</text>')
    top = y + 30
    bottom = top + ROW * len(ms)
    for t, label in ticks(t0, now):
        x = xs(t)
        body.append(f'<line x1="{x:.1f}" y1="{top}" x2="{x:.1f}" y2="{bottom}" class="grid"/>')
        if x1 - x > 40:  # leave room for "now"
            body.append(f'<text x="{x:.1f}" y="{bottom + 16}" class="t3" font-size="11" text-anchor="middle">{escape(label)}</text>')
    body.append(f'<line x1="{x1 + 0.5}" y1="{top}" x2="{x1 + 0.5}" y2="{bottom}" class="axis"/>')
    body.append(f'<text x="{x1}" y="{bottom + 16}" class="t2" font-size="11" text-anchor="middle">now</text>')
    for i, m in enumerate(ms):
        cy = top + ROW * i + ROW / 2
        name = m["name"] if len(m["name"]) <= 34 else m["name"][:33] + "…"
        idcls = "t1" if m["state"] != "todo" else "t3"
        body.append(f'<text x="{lx}" y="{cy + 4}" class="{idcls}" font-size="12" font-weight="600">{m["id"]}</text>')
        body.append(f'<text x="{lx + 40}" y="{cy + 4}" class="{"t2" if m["state"] != "todo" else "t3"}" font-size="12">{escape(name)}</text>')
        if m["state"] == "todo" or not m["started"]:
            body.append(f'<text x="{x0 + 4}" y="{cy + 4}" class="t3" font-size="11">not started</text>')
            continue
        a, b = xs(m["started"]), xs(m["closed"] or now)
        w = max(4.0, b - a)
        cls = "b3" if m["state"] == "closed" else "b1"
        tip = (f"{m['id']} {m['name']}: {when(m['started'], now)} to {when(m['closed'], now) if m['closed'] else 'now'}"
               f", {steps_text(m)} steps, {m['commits']} commits")
        body.append(f'<rect x="{a:.1f}" y="{cy - 6}" width="{w:.1f}" height="12" rx="4" class="{cls}"><title>{escape(tip)}</title></rect>')
        right = span((m["closed"] or now) - m["started"])
        if m["state"] == "active":
            right = f"{steps_text(m)} steps, {right}"
        body.append(f'<text x="{a + w + 6:.1f}" y="{cy + 4}" class="t2" font-size="11">{escape(right)}</text>')
    y = bottom + 34

    # Panel 2: knowledge meters.
    if k:
        body.append(f'<text x="{PAD}" y="{y + 14}" class="t1" font-size="14" font-weight="600">Knowledge targets (done = named, and for K2-K4 also matched)</text>')
        body.append(f'<line x1="{lg + 6}" y1="{y + 3}" x2="{lg + 6}" y2="{y + 17}" class="tick"/>'
                    f'<text x="{lg + 14}" y="{y + 14}" class="t2" font-size="12">Exit threshold</text>')
        ktop = y + 30
        for i, r in enumerate(k["rows"]):
            cy = ktop + KROW * i + KROW / 2
            body.append(f'<text x="{lx}" y="{cy + 4}" class="t1" font-size="12" font-weight="600">{r["id"]}</text>')
            body.append(f'<text x="{lx + 40}" y="{cy + 4}" class="t2" font-size="12">{escape(r["short"])}</text>')
            body.append(f'<rect x="{x0}" y="{cy - 5}" width="{x1 - x0}" height="10" rx="4" class="b0"/>')
            fw = (x1 - x0) * r["pct"] / 100
            if fw > 0:
                body.append(f'<rect x="{x0}" y="{cy - 5}" width="{max(4.0, fw):.1f}" height="10" rx="4" class="b3">'
                            f'<title>{r["id"]}: {r["done"]} of {r["functions"]} done ({r["pct"]:.0f}%)</title></rect>')
            if r["threshold"] is not None:
                tx = x0 + (x1 - x0) * r["threshold"] / 100
                body.append(f'<line x1="{tx:.1f}" y1="{cy - 9}" x2="{tx:.1f}" y2="{cy + 9}" class="tick"/>')
            was = f" (was {r['was']}%)" if r["was"] is not None else ""
            body.append(f'<text x="{x1 + 8}" y="{cy + 4}" class="t1" font-size="11" font-weight="600">{r["pct"]:.0f}%'
                        f'<tspan class="t3" font-weight="400">{escape(was)}</tspan></text>')
        y = ktop + KROW * len(k["rows"]) + 10

    total = int(y + PAD - 10)
    road = [m for m in ms if m["roadmap"]]
    desc = (f"{sum(m['state'] == 'closed' for m in road)} of {len(road)} engine milestones closed; "
            + "; ".join(f"{m['id']} {m['state']}" for m in ms)
            + ("; " + "; ".join(f"{r['id']} {r['pct']:.0f}%" for r in k["rows"]) if k else ""))
    return "\n".join([
        f'<svg xmlns="http://www.w3.org/2000/svg" width="{W}" height="{total}" viewBox="0 0 {W} {total}" role="img" aria-labelledby="title desc">',
        '<title id="title">Browser plan progress: engine milestones and knowledge targets</title>',
        f'<desc id="desc">{escape(desc)}</desc>',
        f"<style>{style}\n.tick {{ stroke: #0b0b0b; stroke-width: 2; }}\n"
        "@media (prefers-color-scheme: dark) { .tick { stroke: #ffffff; } }</style>",
        f'<rect x="0.5" y="0.5" width="{W - 1}" height="{total - 1}" rx="8" class="surface"/>',
        f'<rect x="0.5" y="0.5" width="{W - 1}" height="{total - 1}" rx="8" class="border"/>',
        *body,
        "</svg>",
    ]) + "\n"


def fingerprint(g: Dict[str, Any]) -> str:
    """What changed, leaving out the clock: the publisher pushes when this does."""
    keep = {k: v for k, v in g.items() if k not in ("now", "engine_commits_1h")}
    keep["branches"] = {b: {**v, "ids": sorted(v["ids"])} for b, v in g["branches"].items()}
    return json.dumps(keep, sort_keys=True, default=str)


def main_checkout_path() -> Optional[Path]:
    common = git("rev-parse", "--path-format=absolute", "--git-common-dir", check=False).strip()
    return Path(common).parent if common else None


def main() -> None:
    try:
        sys.stdout.reconfigure(encoding="utf-8")
    except (AttributeError, ValueError):
        pass
    g = collect(main_checkout_path())
    print("\n".join(render_md(g, None)))


if __name__ == "__main__":
    main()
