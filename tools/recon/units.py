"""Provisional translation-unit anchors for GV4E69 (no symbols/map exist).

Anchors:
  sdk      Dolphin SDK libraries: "<< Dolphin SDK - X ... >>" strings -> pointer
           variables holding them -> code loading those -> the library's init fn
  ctor     .ctors entries: GCC emits each TU's `_GLOBAL_.I.<file>` static-init
           function at the end of that TU's .text, so each entry marks a TU end
  dtor     .dtors entries (`_GLOBAL_.D.<file>`), usually next to the ctor
  srcpath  assert/__FILE__ strings naming a source file -> referencing functions

Usage: python -I tools/recon/units.py <main.dol> <symbols.txt> <out.json> [out.md]
Read-only on its inputs. Outputs contain addresses and names only, no game bytes.
"""
import bisect, json, os, re, struct, sys, collections
sys.path.insert(0, os.path.dirname(__file__))
from dol import DOL, sext

R13 = 0x806F69C0
CTORS, NCTORS = 0x805A2BC0, 0x164 // 4
DTORS, NDTORS = 0x805A2D40, 0x44 // 4
OVERLAYS = [(0x8043FDC0, 0x8052A208, "frontend overlay"), (0x8052A220, 0x805A2BB0, "database overlay")]


def load_funcs(path):
    funcs = []
    rx = re.compile(r"^(\S+) = \.(\w+):0x([0-9A-Fa-f]+); // type:function size:0x([0-9A-Fa-f]+)")
    for line in open(path, encoding="utf-8"):
        m = rx.match(line)
        if m:
            funcs.append((int(m.group(3), 16), int(m.group(4), 16), m.group(1)))
    funcs.sort()
    return funcs


def region(addr):
    for lo, hi, name in OVERLAYS:
        if lo <= addr < hi:
            return name
    if addr < 0x800034A0:
        return "init"
    if 0x80402000 <= addr < 0x8043FDC0:
        return "sdk/runtime area"
    if 0x80360000 <= addr < 0x80402000:
        return "EA libs (probable)"
    return "game .text"


def main():
    d = DOL(sys.argv[1])
    funcs = load_funcs(sys.argv[2])
    starts = [f[0] for f in funcs]

    def func_at(a):
        i = bisect.bisect_right(starts, a) - 1
        if i >= 0 and funcs[i][0] <= a < funcs[i][0] + funcs[i][1]:
            return funcs[i]
        return None

    # strings
    strings = {}
    for k, i, a, s, o in d.secs:
        if k == "D":
            for m in re.finditer(rb"[\x09\x20-\x7e]{4,}\x00", d.raw[o:o + s]):  # \t: SDK version strings
                strings[a + m.start()] = m.group()[:-1].decode("latin1")
    # data words pointing at strings (pointer variables)
    ptr_to = collections.defaultdict(list)
    for k, i, a, s, o in d.secs:
        if k == "D":
            for j in range(0, s - 3, 4):
                v = struct.unpack(">I", d.raw[o + j:o + j + 4])[0]
                if v in strings:
                    ptr_to[v].append(a + j)
    # code references (lis/addi|load pairs, r13-relative)
    refs = collections.defaultdict(set)
    for sec in d.text():
        hi = {}
        for a, w in d.words(sec):
            op = w >> 26; rd = (w >> 21) & 31; ra = (w >> 16) & 31
            if op == 15 and ra == 0:
                hi[rd] = ((w & 0xFFFF) << 16, a); continue
            t = None
            if op in (14, 24) or 32 <= op <= 55:
                if ra == 13:
                    t = (R13 + sext(w & 0xFFFF, 16)) & 0xFFFFFFFF
                elif ra in hi and a - hi[ra][1] < 64:
                    lo = sext(w & 0xFFFF, 16) if op != 24 else (w & 0xFFFF)
                    t = (hi[ra][0] + lo) & 0xFFFFFFFF
            if t is not None:
                refs[t].add(a)
            if op == 18 or w == 0x4E800020:
                hi.clear()

    anchors = []
    # SDK version strings
    for sa, s in strings.items():
        m = re.match(r"<< Dolphin SDK - (\w+)\s+release build: (.+?) \((0x[0-9a-f]+)\) >>", s)
        if not m:
            continue
        users = set(refs.get(sa, set()))
        for p in ptr_to.get(sa, []):
            users |= refs.get(p, set())
        fs = sorted({func_at(u) for u in users if func_at(u)})
        anchors.append({
            "kind": "sdk", "name": f"dolphin/{m.group(1).lower()}", "sdk_lib": m.group(1),
            "build": m.group(2), "anchor_functions": [f"{f[2]}@0x{f[0]:08X}" for f in fs],
            "address": fs[0][0] if fs else None, "region": region(fs[0][0]) if fs else "?",
        })
    # ctors/dtors
    for kind, base, n in (("ctor", CTORS, NCTORS), ("dtor", DTORS, NDTORS)):
        for idx in range(1, n - 1):
            tgt = d.u32(base + 4 * idx)
            f = func_at(tgt)
            anchors.append({
                "kind": kind, "name": None, "entry": f"0x{base + 4 * idx:08X}",
                "address": tgt, "function": f"{f[2]}" if f else None,
                "tu_end_hint": f"0x{f[0] + f[1]:08X}" if f else None, "region": region(tgt),
            })
    # source path strings
    BS = chr(92)
    for sa, s in strings.items():
        m = re.search(r"[A-Za-z]:[/" + re.escape(BS) + r"]\S+?\.(cpp|c)\b", s)
        if not m:
            continue
        path = m.group().replace(BS, "/").lower().split("/mvp2004/", 1)[-1]
        users = set(refs.get(sa, set()))
        for p in ptr_to.get(sa, []):
            users |= refs.get(p, set())
        fs = sorted({func_at(u) for u in users if func_at(u)})
        if fs:
            anchors.append({
                "kind": "srcpath", "name": path, "address": fs[0][0],
                "anchor_functions": [f"{f[2]}@0x{f[0]:08X}" for f in fs[:6]],
                "span": f"0x{fs[0][0]:08X}-0x{fs[-1][0] + fs[-1][1]:08X}", "region": region(fs[0][0]),
            })
    anchors.sort(key=lambda x: (x["address"] or 0, x["kind"]))
    # attach nearest srcpath name to ctor anchors whose TU span covers it
    srcs = [a for a in anchors if a["kind"] == "srcpath"]
    ctors = [a for a in anchors if a["kind"] == "ctor"]
    prev_end = 0x800034A0
    for c in sorted(ctors, key=lambda x: x["address"]):
        end = int(c["tu_end_hint"], 16) if c["tu_end_hint"] else c["address"]
        names = sorted({s["name"] for s in srcs if prev_end <= s["address"] < end})
        c["srcpath_candidates"] = names[:4]
        prev_end = end
    json.dump(anchors, open(sys.argv[3], "w"), indent=1, default=str)
    counts = collections.Counter(a["kind"] for a in anchors)
    print("anchors:", dict(counts))
    if len(sys.argv) > 4:
        write_md(anchors, sys.argv[4])


def write_md(anchors, path):
    L = []
    L.append("| # | Kind | Address | Region | Unit (provisional) | Evidence |")
    L.append("|---|---|---|---|---|---|")
    for n, a in enumerate(anchors, 1):
        addr = f"0x{a['address']:08X}" if a["address"] else "?"
        if a["kind"] == "sdk":
            ev = f"`<< Dolphin SDK - {a['sdk_lib']} >>` ({a['build']}); used by {', '.join(a['anchor_functions'][:3]) or 'n/a'}"
            name = a["name"]
        elif a["kind"] in ("ctor", "dtor"):
            ev = f"{a['kind']} entry @{a['entry']} -> `{a['function']}` (TU ends ~{a['tu_end_hint']})"
            name = ", ".join(a.get("srcpath_candidates") or []) or "unknown TU"
        else:
            ev = f"source path string; refs {a['span']}"
            name = a["name"]
        L.append(f"| {n} | {a['kind']} | {addr} | {a['region']} | {name} | {ev} |")
    open(path, "w", encoding="utf-8").write("\n".join(L) + "\n")


if __name__ == "__main__":
    main()
