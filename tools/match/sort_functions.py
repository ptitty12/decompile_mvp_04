"""Reorder a unit's function definitions into .text address order.

    python tools/match/sort_functions.py src/game/tu_80044C10.cpp [--check]

tools/scout/rename.py pairs compiled functions with symbols.txt by object
order, so the source must define functions in address order.

A function definition is a top-level chunk that starts at column 0, contains
a `(`, and opens a `{` before any `;`. It ends where the brace depth returns
to 0, so one-line definitions (`int f() { return 1; }`) are handled. Its
address comes from a `fn_<ADDR>` in its name (free function or method), or
else from an address marker in the comment lines directly above it
(`//@801A7394` or `/* 801A7394 */`). Comment lines directly above a
definition move with it.

Everything before the first definition (includes, declarations, types)
stays in front. Other top-level chunks between definitions (types, globals,
inline helpers) travel with the definition after them. Definitions without an
address keep their place after the addressed definition before them.
--check only reports whether the file is already sorted.
"""
import re
import sys
from pathlib import Path

NAME_ADDR = re.compile(r"\bfn_([0-9A-Fa-f]{8})\w*\s*\(")
MARK_ADDR = re.compile(r"^\s*(?://@\s*(?:0x)?([0-9A-Fa-f]{8})|/\*\s*(?:0x)?([0-9A-Fa-f]{8})\s*\*/)\s*$")


def strip_code(line, in_comment):
    """Line text with comments and string/char literals removed; carries /* */ state."""
    out, i, n = [], 0, len(line)
    while i < n:
        if in_comment:
            j = line.find("*/", i)
            if j < 0:
                return "".join(out), True
            i, in_comment = j + 2, False
        elif line.startswith("//", i):
            break
        elif line.startswith("/*", i):
            in_comment, i = True, i + 2
        elif line[i] in "\"'":
            q, i = line[i], i + 1
            while i < n and line[i] != q:
                i += 2 if line[i] == "\\" else 1
            i += 1
        else:
            out.append(line[i])
            i += 1
    return "".join(out), in_comment


def chunks(lines):
    """[(kind, start, end)] top-level chunks; kind 'def' for function definitions."""
    res, i, n, in_c = [], 0, len(lines), False
    while i < n:
        code, in_c2 = strip_code(lines[i], in_c)
        starts_def = (not in_c and lines[i][:1] not in ("", " ", "\t", "#", "/", "}")
                      and "(" in code)
        if starts_def:
            # find '{' before ';' scanning forward, then the matching close
            depth, j, seen_open, c_state, is_def = 0, i, False, in_c, False
            while j < n:
                code_j, c_state = strip_code(lines[j], c_state)
                for ch in code_j:
                    if ch == "{":
                        depth += 1
                        if not seen_open:
                            seen_open, is_def = True, True
                    elif ch == "}":
                        depth -= 1
                    elif ch == ";" and not seen_open:
                        is_def = False
                        break
                if not is_def and not seen_open and ";" in code_j:
                    break
                if seen_open and depth <= 0:
                    break
                j += 1
            if is_def and j < n:
                res.append(("def", i, j + 1))
                i, in_c = j + 1, c_state
                continue
        res.append(("other", i, i + 1))
        in_c = in_c2
        i += 1
    return res


def main():
    path = Path(sys.argv[1])
    check = "--check" in sys.argv[2:]
    text = path.read_text()
    lines = text.split("\n")
    parts = chunks(lines)
    # Attach comment lines directly above a definition (and its markers) to it.
    defs = []
    for k, (kind, s, e) in enumerate(parts):
        if kind != "def":
            continue
        cs = s
        while cs > 0 and lines[cs - 1].strip().startswith(("//", "/*", "*")) and \
                not any(ds <= cs - 1 < de for _, ds, de in defs):
            cs -= 1
        head = " ".join(lines[s:min(e, s + 3)])
        m = NAME_ADDR.search(head)
        addr = int(m.group(1), 16) if m else None
        if addr is None:
            for ln in lines[cs:s]:
                mm = MARK_ADDR.match(ln)
                if mm:
                    addr = int(mm.group(1) or mm.group(2), 16)
        defs.append((addr, cs, e))
    if not defs:
        print(f"{path}: no function definitions")
        return
    prefix_end = defs[0][1]
    items, last_addr, pos = [], 0, prefix_end
    for idx, (addr, cs, e) in enumerate(defs):
        body = "\n".join(lines[pos:e])  # leading non-def chunks travel with this def
        if addr is None:
            addr = last_addr
        else:
            last_addr = addr
        items.append((addr, idx, body))
        pos = e
    tail = "\n".join(lines[pos:])
    order = sorted(items, key=lambda t: (t[0], t[1]))
    if check:
        ok = [t[1] for t in order] == list(range(len(items)))
        print(f"{path}: {'sorted' if ok else 'NOT sorted'} ({len(items)} functions)")
        sys.exit(0 if ok else 1)
    out = "\n".join(lines[:prefix_end])
    for t in order:
        body = t[2].strip("\n")
        out = out.rstrip("\n") + "\n\n" + body if out.strip() else body
    if tail.strip():
        out = out.rstrip("\n") + "\n\n" + tail.strip("\n")
    path.write_text(out.rstrip("\n") + "\n")
    print(f"{path}: {len(items)} functions in address order")


if __name__ == "__main__":
    main()
