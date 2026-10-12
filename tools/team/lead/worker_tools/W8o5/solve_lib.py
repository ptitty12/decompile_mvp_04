import re, os


def norm(op, ops):
    ops = re.sub(r"\.L\w+", "L", ops)
    ops = re.sub(r"-0x([0-9a-fA-F]+)", lambda m: str(-int(m.group(1), 16)), ops)
    ops = re.sub(r"\b0x([0-9a-fA-F]+)", lambda m: str(int(m.group(1), 16)), ops)
    ops = ops.replace(" ", "")
    ops = re.sub(r"\br(\d+)", r"\1", ops)
    ops = re.sub(r"\bf(\d+)", r"\1", ops)
    ops = re.sub(r"\bcr(\d)", r"\1", ops)
    return op + " " + ops


def target(root, unit, fn):
    body = []
    cur = False
    for line in open(os.path.join(root, "build/GV4E69/asm", unit + ".s"), errors="replace"):
        if line.startswith(".fn " + fn):
            cur = True
            continue
        if cur and line.startswith(".endfn"):
            break
        if cur:
            m = re.match(r"/\*.*?\*/\s*(\S+)\s*(.*)$", line.strip())
            if m:
                op, ops = m.group(1), m.group(2)
                if op.startswith("b") and op not in ("blr", "bl", "bctr", "bctrl", "blrl") and not op.endswith("lr"):
                    ops = "L"
                if op == "bl":
                    ops = "F"
                body.append(norm(op, ops))
    return body


BC = {"12,2": "beq", "4,2": "bne", "12,1": "bgt", "4,1": "ble", "12,0": "blt", "4,0": "bge"}


def ours(s, name):
    m = re.search(r"^" + re.escape(name) + r"(__\w+)?:\n(.*?)\.Lfe", s, re.S | re.M)
    out = []
    for l in m.group(2).splitlines():
        l = l.split("#")[0].strip()
        if not l or l.startswith(".") or l.endswith(":"):
            continue
        op, _, ops = l.partition(" ")
        ops = ops.strip()
        if op.startswith("cmp"):
            ops = re.sub(r"^0,", "", ops)
        if op == "bc":
            a, b = ops.split(",")[:2]
            op = BC.get(f"{a},{b}", "bc")
            ops = "L"
        elif op == "bclr":
            a, b = ops.split(",")[:2]
            op = BC.get(f"{a},{b}", "bc") + "lr"
            ops = ""
        elif op == "bl":
            ops = "F"
        elif op.startswith("b") and op not in ("blr", "bctr", "bctrl", "blrl"):
            ops = "L"
        if op == "crxor" and ops.replace(" ", "") == "6,6,6":
            op, ops = "crclr", "cr1eq"
        if op == "rlwinm":
            pr = [x.strip() for x in ops.split(",")]
            if len(pr) == 5 and pr[4] == "31" and pr[2] != "0":
                sh, mb = int(pr[2]), int(pr[3])
                n = 32 - mb
                b = sh - n
                if b >= 0:
                    op, ops = "extrwi", f"{pr[0]},{pr[1]},{n},{b}"
        if op == "la":
            mm = re.match(r"(\w+),(-?[\w@.]+)\((\w+)\)", ops)
            if mm:
                op, ops = "addi", f"{mm.group(1)},{mm.group(3)},{mm.group(2)}"
        out.append(norm(op, ops))
    return out
