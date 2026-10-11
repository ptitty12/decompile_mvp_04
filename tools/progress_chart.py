#!/usr/bin/env python3
"""Draw the decompilation progress card shown in README.md.

Reads objdiff's progress report (build/GV4E69/report.json, written by
`ninja progress`), records the day's totals in docs/progress/history.csv and
writes docs/progress/progress.svg:

  - headline: percent of code bytes matched, plus function/code/data counts;
  - treemap: one block per unit, sized by code bytes and shaded by objdiff's
    fuzzy match percent (gray = not started, darkest blue = fully matched).
    Blocks split as units are carved out of the auto-generated ones;
  - history: percent of code matched over time, one point per day the card
    is regenerated (re-running on the same day replaces that day's point).

With --if-changed nothing is written unless the totals or the treemap differ
from the current card, so a new date alone never produces a commit.
tools/progress_bot.py uses this to redraw the card automatically.

Units without code (data-only auto splits) are left out of the treemap:
objdiff scores them 100% because there is nothing to match.

The colors are the dataviz reference blue ramp (light and dark mode), checked
with its palette validator in --ordinal mode against the card surfaces.

Standard library only.

Usage: python tools/progress_chart.py [--report PATH] [--out-dir DIR] [--date YYYY-MM-DD] [--if-changed]
"""
import argparse
import csv
import datetime
import json
import re
from html import escape
from pathlib import Path
from typing import Any, Dict, List, Tuple

ROOT = Path(__file__).resolve().parent.parent

W = 960
PAD = 24
FONT = 'system-ui, -apple-system, "Segoe UI", sans-serif'

STYLE = """
text { font-family: %s; }
.surface { fill: #fcfcfb; }
.border { fill: none; stroke: rgba(11,11,11,0.10); }
.t1 { fill: #0b0b0b; } .t2 { fill: #52514e; } .t3 { fill: #898781; }
.grid { stroke: #e1e0d9; } .axis { stroke: #c3c2b7; }
.line { fill: none; stroke: #2a78d6; } .dot { fill: #2a78d6; stroke: #fcfcfb; }
.b0 { fill: #dcdbd4; } .b1 { fill: #86b6ef; } .b2 { fill: #5598e7; }
.b3 { fill: #2a78d6; } .b4 { fill: #1c5cab; } .b5 { fill: #0d366b; }
.l0, .l1, .l2, .l3 { fill: #0b0b0b; } .l4, .l5 { fill: #ffffff; }
@media (prefers-color-scheme: dark) {
  .surface { fill: #1a1a19; }
  .border { stroke: rgba(255,255,255,0.10); }
  .t1 { fill: #ffffff; } .t2 { fill: #c3c2b7; } .t3 { fill: #898781; }
  .grid { stroke: #2c2c2a; } .axis { stroke: #383835; }
  .line { stroke: #3987e5; } .dot { fill: #3987e5; stroke: #1a1a19; }
  .b0 { fill: #383835; } .b1 { fill: #184f95; } .b2 { fill: #256abf; }
  .b3 { fill: #3987e5; } .b4 { fill: #6da7ec; } .b5 { fill: #b7d3f6; }
  .l0 { fill: #c3c2b7; } .l1, .l2 { fill: #ffffff; } .l3, .l4, .l5 { fill: #0b0b0b; }
}
""" % FONT

# Shade buckets by fuzzy match percent: (label, lower bound inclusive).
BUCKETS = ["Not started", "< 25%", "25–50%", "50–75%", "75–99%", "Matched"]

HISTORY_FIELDS = [
    "date",
    "matched_code",
    "total_code",
    "matched_functions",
    "total_functions",
    "matched_data",
    "total_data",
]


def bucket(fuzzy: float) -> int:
    if fuzzy >= 100.0:
        return 5
    if fuzzy <= 0.0:
        return 0
    return 1 + min(3, int(fuzzy // 25))


def num(measures: Dict[str, Any], key: str) -> int:
    # objdiff writes u64 measures as JSON strings and omits zero values.
    return int(measures.get(key, 0))


def fmt_bytes(n: int) -> str:
    if n >= 1_000_000:
        return f"{n / 1_000_000:.2f} MB"
    if n >= 1_000:
        return f"{n / 1_000:.1f} KB"
    return f"{n} B"


def worst(row: List[float], side: float) -> float:
    s = sum(row)
    return max(side * side * max(row) / (s * s), (s * s) / (side * side * min(row)))


def squarify(
    values: List[float], x: float, y: float, w: float, h: float
) -> List[Tuple[float, float, float, float]]:
    """Squarified treemap (Bruls et al.); values sorted descending, all > 0."""
    scale = w * h / sum(values)
    areas = [v * scale for v in values]
    rects: List[Tuple[float, float, float, float]] = []
    i = 0
    while i < len(areas):
        side = max(min(w, h), 1e-9)
        row = [areas[i]]
        i += 1
        while i < len(areas) and worst(row + [areas[i]], side) <= worst(row, side):
            row.append(areas[i])
            i += 1
        s = sum(row)
        if w >= h:
            cw = s / h
            yy = y
            for a in row:
                rects.append((x, yy, cw, a / cw))
                yy += a / cw
            x, w = x + cw, max(w - cw, 0.0)
        else:
            rh = s / w
            xx = x
            for a in row:
                rects.append((xx, y, a / rh, rh))
                xx += a / rh
            y, h = y + rh, max(h - rh, 0.0)
    return rects


def read_history(path: Path) -> List[Dict[str, Any]]:
    if not path.is_file():
        return []
    with open(path, newline="", encoding="utf-8") as f:
        return list(csv.DictReader(f))


def write_history(path: Path, rows: List[Dict[str, Any]]) -> None:
    with open(path, "w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=HISTORY_FIELDS, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)


def treemap_part(svg: str) -> str:
    m = re.search(r'<g id="treemap">.*?</g>', svg, re.S)
    return m.group(0) if m else ""


def text(x: float, y: float, s: str, cls: str, size: int, anchor: str = "start", weight: int = 400) -> str:
    return (
        f'<text x="{x:.1f}" y="{y:.1f}" class="{cls}" font-size="{size}" '
        f'font-weight="{weight}" text-anchor="{anchor}">{escape(s)}</text>'
    )


def draw_header(out: List[str], m: Dict[str, Any], date: str) -> float:
    mc, tc = num(m, "matched_code"), num(m, "total_code")
    mf, tf = num(m, "matched_functions"), num(m, "total_functions")
    md, td = num(m, "matched_data"), num(m, "total_data")
    pct = 100.0 * mc / tc if tc else 0.0

    out.append(text(PAD, 40, "MVP Baseball 2005 (GV4E69) decompilation", "t2", 14, weight=600))
    out.append(text(W - PAD, 40, f"as of {date}", "t3", 12, anchor="end"))
    out.append(text(PAD, 96, f"{pct:.2f}%", "t1", 44, weight=600))
    out.append(text(PAD + 2, 118, "of code matched", "t2", 13))

    stats = [
        ("Functions matched", f"{mf:,} / {tf:,}"),
        ("Code matched", f"{fmt_bytes(mc)} / {fmt_bytes(tc)}"),
        ("Data matched", f"{fmt_bytes(md)} / {fmt_bytes(td)}"),
    ]
    col_w = (W - PAD - 300) / len(stats)
    for i, (label, value) in enumerate(stats):
        x = 300 + i * col_w
        out.append(text(x, 72, label, "t3", 12))
        out.append(text(x, 96, value, "t1", 18, weight=600))

    y, bw, bh = 140, W - 2 * PAD, 12
    out.append(f'<clipPath id="bar"><rect x="{PAD}" y="{y}" width="{bw}" height="{bh}" rx="{bh / 2}"/></clipPath>')
    out.append(f'<rect x="{PAD}" y="{y}" width="{bw}" height="{bh}" rx="{bh / 2}" class="b0"/>')
    if mc:
        fw = max(bw * mc / tc, 2.0)
        out.append(f'<rect x="{PAD}" y="{y}" width="{fw:.1f}" height="{bh}" class="b5" clip-path="url(#bar)"/>')
    return y + bh


def draw_treemap(out: List[str], units: List[Dict[str, Any]], top: float) -> float:
    out.append(text(PAD, top + 32, "Code by unit", "t1", 14, weight=600))
    out.append(text(PAD + 98, top + 32, "area = code size, shade = fuzzy match", "t3", 12))

    # Legend, right-aligned on the heading row.
    items = [(i, label) for i, label in enumerate(BUCKETS)]
    widths = [12 + 6 + len(label) * 6.6 + 14 for _, label in items]
    x = W - PAD - sum(widths) + 14
    for (i, label), iw in zip(items, widths):
        out.append(f'<rect x="{x:.1f}" y="{top + 22}" width="12" height="12" rx="2" class="b{i}"/>')
        out.append(text(x + 18, top + 32, label, "t2", 12))
        x += iw

    y0, h = top + 48, 340.0
    rects = squarify([float(u["code"]) for u in units], PAD, y0, W - 2 * PAD, h)
    out.append('<g id="treemap">')
    for u, (rx, ry, rw, rh) in zip(units, rects):
        # 2px surface gap between neighbours; blocks too small to see are left out.
        rx, ry, rw, rh = rx + 1, ry + 1, rw - 2, rh - 2
        if rw < 1 or rh < 1:
            continue
        b = bucket(u["fuzzy"])
        out.append(
            f'<rect x="{rx:.1f}" y="{ry:.1f}" width="{rw:.1f}" height="{rh:.1f}" rx="2" class="b{b}">'
            f'<title>{escape(u["name"])}: {u["code"]:,} bytes of code, {u["fuzzy"]:.1f}% fuzzy match</title></rect>'
        )
        if rw < 48 or rh < 18:
            continue
        name = u["name"]
        fit = int((rw - 10) / 6.4)
        if len(name) > fit:
            name = name[: fit - 1] + "…"
        out.append(text(rx + 5, ry + 14, name, f"l{b}", 11))
        # Percent only on partly matched units; the shade already says 0% / 100%.
        if rh >= 34 and 0 < b < 5:
            out.append(text(rx + 5, ry + 28, f"{u['fuzzy']:.1f}%", f"l{b}", 11))
    out.append("</g>")
    return y0 + h


def nice_scale(vmax: float) -> Tuple[float, float]:
    for top, step in [(1, 0.25), (2, 0.5), (5, 1), (10, 2.5), (20, 5), (50, 10), (100, 25)]:
        if vmax <= top:
            return top, step
    return 100, 25


def draw_history(out: List[str], rows: List[Dict[str, Any]], top: float) -> float:
    out.append(text(PAD, top + 32, "Code matched over time", "t1", 14, weight=600))

    dates = [datetime.date.fromisoformat(r["date"]) for r in rows]
    vals = [100.0 * int(r["matched_code"]) / int(r["total_code"]) if int(r["total_code"]) else 0.0 for r in rows]
    ymax, step = nice_scale(max(vals))

    x0, x1 = PAD + 44, W - PAD
    y0, y1 = top + 52, top + 192  # plot top, plot bottom (baseline)

    def py(v: float) -> float:
        return y1 - (y1 - y0) * v / ymax

    span = (dates[-1] - dates[0]).days

    def px(d: datetime.date) -> float:
        return x0 + (x1 - x0) * ((d - dates[0]).days / span if span else 0.0)

    t = 0.0
    while t <= ymax + 1e-9:
        y = py(t)
        out.append(f'<line x1="{x0}" y1="{y:.1f}" x2="{x1}" y2="{y:.1f}" class="{"axis" if t == 0 else "grid"}" stroke-width="1"/>')
        out.append(text(x0 - 8, y + 4, f"{t:g}%", "t3", 11, anchor="end"))
        t += step

    pts = [(px(d), py(v)) for d, v in zip(dates, vals)]
    if len(pts) > 1:
        path = " ".join(f"{x:.1f},{y:.1f}" for x, y in pts)
        out.append(f'<polyline points="{path}" class="line" stroke-width="2" stroke-linejoin="round" stroke-linecap="round"/>')
    marked = range(len(pts)) if len(pts) <= 30 else [len(pts) - 1]
    for i in marked:
        r = rows[i]
        out.append(
            f'<circle cx="{pts[i][0]:.1f}" cy="{pts[i][1]:.1f}" r="4" class="dot" stroke-width="2">'
            f'<title>{r["date"]}: {vals[i]:.2f}% of code, {int(r["matched_functions"]):,} / '
            f'{int(r["total_functions"]):,} functions</title></circle>'
        )

    # Direct label on the latest point only.
    lx, ly = pts[-1]
    if len(pts) == 1:
        out.append(text(lx + 10, ly - 8, f"{vals[-1]:.2f}% on {rows[-1]['date']}; a point is added each day the numbers change", "t2", 12))
    else:
        out.append(text(lx, ly - 10, f"{vals[-1]:.2f}%", "t1", 12, anchor="end", weight=600))
        out.append(text(x0, y1 + 18, rows[0]["date"], "t3", 11))
        out.append(text(x1, y1 + 18, rows[-1]["date"], "t3", 11, anchor="end"))
    return y1 + 18


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--report", type=Path, default=ROOT / "build" / "GV4E69" / "report.json")
    parser.add_argument("--out-dir", type=Path, default=ROOT / "docs" / "progress")
    parser.add_argument("--date", default=datetime.date.today().isoformat())
    parser.add_argument("--if-changed", action="store_true", help="write nothing unless the totals or the treemap changed")
    args = parser.parse_args()

    with open(args.report, encoding="utf-8") as f:
        report = json.load(f)
    m = report["measures"]

    units = [
        {
            "name": u["name"].split("/", 1)[-1],
            "code": num(u["measures"], "total_code"),
            "fuzzy": float(u["measures"].get("fuzzy_match_percent", 0.0)),
        }
        for u in report["units"]
    ]
    units = sorted((u for u in units if u["code"] > 0), key=lambda u: (-u["code"], u["name"]))

    args.out_dir.mkdir(parents=True, exist_ok=True)
    hist_path = args.out_dir / "history.csv"
    out_svg = args.out_dir / "progress.svg"
    row = {
        "date": args.date,
        "matched_code": num(m, "matched_code"),
        "total_code": num(m, "total_code"),
        "matched_functions": num(m, "matched_functions"),
        "total_functions": num(m, "total_functions"),
        "matched_data": num(m, "matched_data"),
        "total_data": num(m, "total_data"),
    }
    old_rows = read_history(hist_path)
    rows = sorted([r for r in old_rows if r["date"] != args.date] + [row], key=lambda r: r["date"])

    body: List[str] = []
    bottom = draw_header(body, m, args.date)
    bottom = draw_treemap(body, units, bottom)
    bottom = draw_history(body, rows, bottom + 8)
    h = int(bottom + PAD)

    mc, tc = num(m, "matched_code"), num(m, "total_code")
    summary = (
        f"{100.0 * mc / tc if tc else 0.0:.2f}% of code matched as of {args.date}: "
        f"{num(m, 'matched_functions'):,} of {num(m, 'total_functions'):,} functions, "
        f"{mc:,} of {tc:,} code bytes, {len(units)} units with code."
    )
    svg = [
        f'<svg xmlns="http://www.w3.org/2000/svg" width="{W}" height="{h}" viewBox="0 0 {W} {h}" role="img" aria-labelledby="title desc">',
        '<title id="title">Decompilation progress</title>',
        f'<desc id="desc">{escape(summary)}</desc>',
        f"<style>{STYLE}</style>",
        f'<rect x="0.5" y="0.5" width="{W - 1}" height="{h - 1}" rx="8" class="surface"/>',
        f'<rect x="0.5" y="0.5" width="{W - 1}" height="{h - 1}" rx="8" class="border"/>',
        *body,
        "</svg>",
    ]
    content = "\n".join(svg) + "\n"

    if args.if_changed and old_rows and out_svg.is_file():
        same_totals = all(str(old_rows[-1][k]) == str(row[k]) for k in HISTORY_FIELDS if k != "date")
        old_svg = out_svg.read_text(encoding="utf-8")
        if same_totals and treemap_part(old_svg) == treemap_part(content):
            print(f"No change since {old_rows[-1]['date']}; card left as is.")
            return

    write_history(hist_path, rows)
    with open(out_svg, "w", newline="\n", encoding="utf-8") as f:
        f.write(content)
    print(summary)
    print(f"Wrote {out_svg}")


if __name__ == "__main__":
    main()
