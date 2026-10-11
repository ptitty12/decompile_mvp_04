"""Resolve git conflicts inside padded struct layouts by merging fields by offset.

Workers expose struct members by splitting padding, e.g.

    char pad8C8[0x8E8 - 0x8C8];
    float m8E8;
    char pad8EC[0xB4C - 0x8EC];

Two workers splitting the same padding conflict textually although their
fields don't overlap. For each conflict hunk whose sides contain only field,
padding and comment lines, this tool places every field at its offset (from its
`m<hex>` name), keeps the union of both sides, and regenerates padding between
them. Padding may be written `padX[0xEND - 0xX]` or `padX[0xSIZE]`. A field
whose extent would overlap another field with different text leaves the hunk
as a conflict for a human.

    python tools/team/merge_structs.py include/game/chooser.h

Afterwards rebuild and diff every unit that includes the header.
"""
import re
import sys
from pathlib import Path

PAD_RANGE = re.compile(r"^\s*char\s+pad([0-9A-Fa-f]+)\s*\[\s*0x([0-9A-Fa-f]+)\s*-\s*0x([0-9A-Fa-f]+)\s*\]\s*;")
PAD_SIZE = re.compile(r"^\s*char\s+pad([0-9A-Fa-f]+)\s*\[\s*(0x[0-9A-Fa-f]+|\d+)\s*\]\s*;")
FIELD = re.compile(r"^\s*[A-Za-z_][\w\s\*:<>,]*?\b(m([0-9A-Fa-f]+))\s*(\[[^\]]*\])?\s*;")
COMMENT = re.compile(r"^\s*(/\*|\*|//)|^\s*$")


def pad_span(ln):
    m = PAD_RANGE.match(ln)
    if m:
        # Trust the range expression, not the name (names can be stale).
        return int(m.group(3), 16), int(m.group(2), 16)
    m = PAD_SIZE.match(ln)
    if m:
        a = int(m.group(1), 16)
        return a, a + int(m.group(2), 0)
    return None


def item_start(ln):
    p = pad_span(ln)
    if p:
        return p[0]
    f = FIELD.match(ln)
    return int(f.group(2), 16) if f else None


def parse(lines):
    """[(offset, text)] for fields and the side's (start, end) from pads; None if not a layout."""
    fields, starts, ends, pending = [], [], [], ""
    for ln in lines:
        if COMMENT.match(ln):
            if fields:
                fields[-1] = (fields[-1][0], fields[-1][1] + ln)
            else:
                pending += ln
            continue
        p = pad_span(ln)
        if p:
            starts.append(p[0]); ends.append(p[1])
            continue
        f = FIELD.match(ln)
        if not f:
            return None
        off = int(f.group(2), 16)
        starts.append(off)
        fields.append((off, pending + ln)); pending = ""
    return fields, (min(starts) if starts else None), ends


def resolve(text):
    lines = text.splitlines(keepends=True)
    out, i, n_ok, n_left = [], 0, 0, 0
    while i < len(lines):
        if not lines[i].startswith("<<<<<<< "):
            out.append(lines[i]); i += 1
            continue
        j, side = i + 1, "ours"
        parts = {"ours": [], "theirs": [], "base": []}
        while not lines[j].startswith(">>>>>>> "):
            if lines[j].startswith("||||||| "):
                side = "base"
            elif lines[j].startswith("======="):
                side = "theirs"
            else:
                parts[side].append(lines[j])
            j += 1
        hunk = lines[i:j + 1]
        after = next((item_start(x) for x in lines[j + 1:] if item_start(x) is not None or x.strip() == "};"), None)
        merged = None
        po, pt = parse(parts["ours"]), parse(parts["theirs"])
        if po and pt and po[1] is not None and pt[1] is not None:
            start = min(po[1], pt[1])
            hunk_end = after if after is not None else max(po[2] + pt[2] + [0]) or None
            fields = {}
            ok = hunk_end is not None
            for off, txt in po[0] + pt[0]:
                key = re.sub(r"/\*.*?\*/|//.*|\s", "", txt)
                if off in fields and re.sub(r"/\*.*?\*/|//.*|\s", "", fields[off]) != key:
                    ok = False
                if off not in fields or len(txt) > len(fields[off]):
                    fields[off] = txt
            offs = sorted(fields)
            if ok and offs and offs[0] >= start and offs[-1] < hunk_end:
                indent = re.match(r"^(\s*)", (parts["ours"] + parts["theirs"])[0]).group(1)
                merged, pos = [], start
                for k, off in enumerate(offs):
                    if off > pos:
                        merged.append(f"{indent}char pad{pos:X}[0x{off:X} - 0x{pos:X}];\n")
                    merged.append(fields[off])
                    # The field runs to the next field, or to where a pad on either side begins.
                    nxt = offs[k + 1] if k + 1 < len(offs) else hunk_end
                    pad_after = [pad_span(x)[0] for x in parts["ours"] + parts["theirs"] if pad_span(x) and off < pad_span(x)[0] <= nxt]
                    pos = min(pad_after + [nxt])
                if pos < hunk_end:
                    merged.append(f"{indent}char pad{pos:X}[0x{hunk_end:X} - 0x{pos:X}];\n")
        if merged is not None:
            out += merged; n_ok += 1
        else:
            out += hunk; n_left += 1
        i = j + 1
    return "".join(out), n_ok, n_left


def main():
    p = Path(sys.argv[1])
    text, ok, left = resolve(p.read_text())
    p.write_text(text)
    print(f"{p}: merged {ok} hunk(s), left {left} for manual resolution")
    sys.exit(1 if left else 0)


if __name__ == "__main__":
    main()
