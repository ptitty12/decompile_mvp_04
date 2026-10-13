"""Flatten a preprocessed C++ unit (ProDG g++ 2.95) into C that decomp-permuter can parse.

Used by permute.py for .cpp units. Heuristic text rewriting, made safe by permute.py's
check that the result, spliced back into the unit, compiles the target function to the
same instructions; anything it gets wrong shows up as a refusal, never as a wrong target.

- extern "C" and namespace wrappers are unwrapped; templates, using and friend dropped.
- class/struct/union definitions keep their data members (bases become a leading
  member, a class with virtual functions gets a trailing vtable pointer); methods,
  ctors/dtors, static members and access specifiers go. Every record name gets a
  `typedef struct X X;` so C++-style `X x;` still parses.
- References in declarations become pointers and default arguments go, so the other
  functions' prototypes parse. (A body that needs real C++ fails the compile check.)
- C++ casts and function-style primitive casts become C casts; bool/true/false become
  unsigned char/1/0.
- The C is only for the permuter to parse and mutate: permute.py compiles a candidate by
  splicing its function body back into the original C++ unit, so names (mangled ones
  spelled out in the source included) stay as written.
"""
import re

PRIMS = r"(?:int|unsigned|signed|float|double|char|short|long|u8|u16|u32|u64|s8|s16|s32|s64|f32|f64)"


def balanced(text, start, pairs={"(": ")", "{": "}", "<": ">", "[": "]"}):
    """Index just past the bracket group that opens at text[start]."""
    o, c, depth = text[start], pairs[text[start]], 0
    for i in range(start, len(text)):
        depth += (text[i] == o) - (text[i] == c)
        if depth == 0:
            return i + 1
    return len(text)


def definition_body(text, fn):
    """(start, end) of fn's body braces in text, or None."""
    for m in re.finditer(rf"\b{re.escape(fn)}\s*\(", text):
        close = balanced(text, m.end() - 1)
        b = re.match(r"\s*\{", text[close:])
        if b:
            start = close + b.end() - 1
            return start, balanced(text, start)
    return None


def base_name(sym):
    """g++ 2.95 mangled name -> the name C uses (foo__FPv -> foo). Leaves __ct, __dl... alone."""
    if sym.startswith("__"):
        return sym
    m = re.match(r"^(\w+?)__(?:F|C|Q|t|[0-9])\w*$", sym)
    return m.group(1) if m else sym


def unwrap(text, opener):
    """Remove `opener {` and its matching `}`, keeping what is inside."""
    while True:
        m = re.search(opener, text)
        if not m:
            return text
        end = balanced(text, m.end() - 1)
        text = text[:m.start()] + text[m.end():end - 1] + text[end:]


def skip_decl(text, i):
    """Index past the declaration starting at i: through `;`, or a `{...}` (plus `;`)."""
    depth = 0
    while i < len(text):
        ch = text[i]
        if ch in "([":
            i = balanced(text, i)
            continue
        if ch == "{":
            i = balanced(text, i)
            m = re.match(r"\s*;", text[i:])
            return i + (m.end() if m else 0)
        if ch == ";" and depth == 0:
            return i + 1
        i += 1
    return i


def drop_templates(text):
    out, pos = [], 0
    for m in re.finditer(r"\btemplate\s*<", text):
        if m.start() < pos:
            continue
        out.append(text[pos:m.start()])
        pos = skip_decl(text, balanced(text, m.end() - 1))
    return "".join(out) + text[pos:]


def member_segments(body):
    """Split a record body (without braces) into (text, kind) member segments."""
    segs, i, start = [], 0, 0
    while i < len(body):
        ch = body[i]
        if ch in "([":
            i = balanced(body, i)
            continue
        if ch == "{":
            head = body[start:i]
            end = balanced(body, i)
            if re.search(r"\b(struct|union|enum|class)\b[^;()]*$", head):  # nested record, ends with `;`
                semi = body.index(";", end) if ";" in body[end:] else len(body) - 1
                segs.append((body[start:semi + 1], "record"))
                i = start = semi + 1
            else:  # inline method body
                m = re.match(r"\s*;", body[end:])
                i = start = end + (m.end() if m else 0)
                segs.append((head, "method"))
            continue
        if ch == ";":
            segs.append((body[start:i + 1], "decl"))
            start = i + 1
        i += 1
    return segs


def convert_record(kind, name, bases, body, names):
    members, virtual = [], False
    for i, b in enumerate(re.findall(r"\b(?:public\s+|private\s+|protected\s+|virtual\s+)*(\w+)\s*(?:,|$)", bases or "")):
        members.append(f"struct {b} __base{i};")
    for seg, k in member_segments(body):
        seg = re.sub(r"\b(public|private|protected)\s*:", "", seg)
        if re.search(r"\bvirtual\b", seg):
            virtual = True
        if k == "method":
            continue
        if k == "record":
            members.append(convert_records(seg, names))
            continue
        s = seg.strip()
        if not s or s == ";" or re.match(r"(static|typedef|friend|using|enum\s+\w*\s*;)\b", s):
            continue
        if re.search(r"\boperator\b", s):
            continue
        if "(" in s and not re.search(r"\(\s*\*\s*\w+\s*\)\s*\(", s):  # a method, not a fn-pointer field
            continue
        members.append(s)
    if virtual:
        members.append("void *__vptr;")
    if not members:
        members.append("char __empty;")  # g++ gives an empty class size 1
    kw = "union" if kind == "union" else "struct"
    if name:
        names.add((kw, name))
    return f"{kw} {name or ''} {{\n" + "\n".join(members) + "\n}"


def convert_records(text, names):
    out, pos = [], 0
    pat = re.compile(r"\b(class|struct|union)\s+(\w*)\s*(:[^{;()]*)?\{")
    while True:
        m = pat.search(text, pos)
        if not m:
            break
        end = balanced(text, m.end() - 1)
        out.append(text[pos:m.start()] + convert_record(m.group(1), m.group(2), (m.group(3) or "")[1:],
                                                       text[m.end():end - 1], names))
        pos = end
    text = "".join(out) + text[pos:]
    for kw, n in re.findall(r"\b(class|struct|union)\s+(\w+)\s*;", text):  # forward declarations
        names.add(("union" if kw == "union" else "struct", n))
    return re.sub(r"\bclass\b", "struct", text)


def cxx_casts(text):
    out, pos = [], 0
    for m in re.finditer(r"\b(static|reinterpret|const)_cast\s*<", text):
        if m.start() < pos:
            continue
        lt = m.end() - 1
        gt = balanced(text, lt)
        paren = re.match(r"\s*\(", text[gt:])
        if not paren:
            continue
        p0 = gt + paren.end() - 1
        p1 = balanced(text, p0)
        out.append(text[pos:m.start()] + f"(({text[lt + 1:gt - 1]})({text[p0 + 1:p1 - 1]}))")
        pos = p1
    text = "".join(out) + text[pos:]
    # float(x) -> ((float)(x)); not `float (*fp)(...)` declarators
    out, pos = [], 0
    for m in re.finditer(rf"(?<![\w*])({PRIMS})\s*\((?!\s*\*)", text):
        if m.start() < pos:
            continue
        before = text[:m.start()].rstrip()
        if before.endswith((")", "]")) or re.search(r"\b(sizeof|return)$", before) is None and re.search(r"\w$", before):
            continue  # part of a declaration (`unsigned int(`) or a call result
        end = balanced(text, m.end() - 1)
        out.append(text[pos:m.start()] + f"(({m.group(1)})({text[m.end():end - 1]}))")
        pos = end
    return "".join(out) + text[pos:]


def declarations_c(text):
    """References -> pointers and no default arguments, in declarations outside bodies."""
    out, i, start, depth = [], 0, 0, 0
    while i < len(text):
        if text[i] == "{" and depth == 0:
            head = text[start:i]
            end = balanced(text, i)
            if head.rstrip().endswith(")"):  # function definition: fix its header only
                out.append(fix_params(head) + text[i:end])
            else:  # record/initializer
                out.append(head + text[i:end])
            i = start = end
            continue
        if text[i] == ";":
            seg = text[start:i + 1]
            # Declarations C can't express (template arguments, operators) are dropped.
            if not re.search(r"\w\s*<[^;<>]*>|\boperator\b", seg):
                out.append(fix_params(seg))
            start = i + 1
        i += 1
    return "".join(out) + fix_params(text[start:])


def fix_params(decl):
    """In each parameter list of a declaration: T& -> T *, and no default arguments."""
    out, pos = [], 0
    for m in re.finditer(r"\w\s*\(", decl):
        if m.start() < pos:
            continue
        end = balanced(decl, m.end() - 1)
        p = re.sub(r"(\w|\*)\s*&(?!&)", r"\1 *", decl[m.end() - 1:end])
        p = re.sub(r"\s*=\s*[^,()]+(?=[,)])", "", p)
        out.append(decl[pos:m.end() - 1] + p)
        pos = end
    return "".join(out) + decl[pos:]


C_WORDS = set("""auto break case char const continue default do double else enum extern float for goto if
inline int long register return short signed sizeof static struct switch typedef union unsigned void volatile
while""".split())


def segments(text):
    """Top-level declarations as (start, end); a function definition ends with its body."""
    segs, start, i = [], 0, 0
    while i < len(text):
        ch = text[i]
        if ch == "{":
            end = balanced(text, i)
            if text[start:i].rstrip().endswith(")"):
                segs.append((start, end))
                start = end
            i = end
            continue
        if ch == ";":
            segs.append((start, i + 1))
            start = i + 1
        i += 1
    if text[start:].strip():
        segs.append((start, len(text)))
    return segs


def is_definition_of(seg, fn):
    """True if this top-level segment is fn's definition (fn named in the header, not a call in a body)."""
    if not seg.rstrip().endswith("}") or "{" not in seg:
        return False
    return re.search(rf"\b{re.escape(fn)}\s*\(", seg[:seg.index("{")]) is not None


def declared(seg):
    """Names a declaration may introduce (over-approximated; extra names only keep extra lines)."""
    seg = re.sub(r"^\s*#.*$", "", seg, flags=re.M)
    names = set(re.findall(r"\b(?:struct|union|enum)\s+(\w+)", seg))
    for body in re.findall(r"\benum\b[^{;]*\{([^}]*)\}", seg):
        names |= set(re.findall(r"(?:^|,)\s*(\w+)", body))
    outer, depth = [], 0
    for ch in seg:  # text outside braces: declarators, not members
        depth += (ch == "{") - (ch == "}")
        if depth == 0 and ch != "}":
            outer.append(ch)
    outer = "".join(outer)
    names |= set(re.findall(r"(\w+)\s*(?:\[[^\]]*\]\s*)*(?:=|;|,|$)", outer))
    names |= set(re.findall(r"(\w+)\s*\(", outer))
    names |= set(re.findall(r"\(\s*\*\s*(\w+)\s*\)", outer))
    return names - C_WORDS


def needed_only(text, fn):
    """Keep only the top-level declarations the definition of fn depends on, in order."""
    segs = segments(text)
    target = next((s for s in segs if is_definition_of(text[s[0]:s[1]], fn)), None)
    if target is None:
        return None
    decl = [declared(text[a:b]) for a, b in segs]
    keep, need = {target}, set(re.findall(r"\b[A-Za-z_]\w*\b", text[target[0]:target[1]])) - C_WORDS
    changed = True
    while changed:
        changed = False
        for s, names in zip(segs, decl):
            if s not in keep and names & need:
                keep.add(s)
                need |= set(re.findall(r"\b[A-Za-z_]\w*\b", text[s[0]:s[1]])) - C_WORDS
                changed = True
    parts = []
    for s in segs:
        if s in keep:
            part = re.sub(r"^\s*#.*$", "", text[s[0]:s[1]], flags=re.M)
            if s != target and part.rstrip().endswith("}") and re.search(r"\)\s*\{", part):
                part = part[:part.index("{")].rstrip() + ";"  # other functions: prototypes
            parts.append(part)
    return "\n".join(parts) + "\n"


def cxx_to_c(text):
    text = unwrap(text, r'extern\s+"C"\s*\{')
    text = re.sub(r'\bextern\s+"C(\+\+)?"\s*', "", text)
    text = unwrap(text, r"\bnamespace\s*\w*\s*\{")
    text = re.sub(r"^\s*using\b[^;]*;", "", text, flags=re.M)
    text = drop_templates(text)
    names = set()
    text = convert_records(text, names)
    text = re.sub(r"\benum\s+(\w+)\s*(\{)", r"enum \1 \2", text)
    enums = set(re.findall(r"\benum\s+(\w+)\s*\{", text))
    text = cxx_casts(text)
    text = declarations_c(text)
    text = re.sub(r"\btrue\b", "1", text)
    text = re.sub(r"\bfalse\b", "0", text)
    existing = set(re.findall(r"typedef\b[^;{]*?\b(\w+)\s*;", text))
    head = ["typedef unsigned char bool;"] if re.search(r"\bbool\b", text) and "bool" not in existing else []
    head += [f"typedef {kw} {n} {n};" for kw, n in sorted(names) if n not in existing]
    for e in sorted(enums - existing):  # after the enum's definition (no forward enums in C)
        text = re.sub(rf"(\benum\s+{e}\s*\{{)", lambda m: "\x00" + m.group(1), text, count=1)
        i = text.index("\x00")
        end = balanced(text, text.index("{", i))
        semi = text.index(";", end) + 1
        text = text[:i] + text[i + 1:semi] + f"\ntypedef enum {e} {e};" + text[semi:]
    return "\n".join(head) + "\n" + text
