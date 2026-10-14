"""rename_symbols.py on a synthetic repo in a temp dir (no game data, no dtk)."""
import os
import sys
import tempfile
import textwrap
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import rename_symbols as rs  # noqa: E402

SYMBOLS = (
    "fn_80001000 = .text:0x80001000; // type:function size:0x20\n"
    "fn_80001020__Fi = .text:0x80001020; // type:function size:0x20\n"
    "fn_80001040 = .text:0x80001040; // type:function size:0x20\n"
    "lbl_80002000 = .data:0x80002000; // type:object size:0x30\n"
    "lbl_80003000 = .sbss:0x80003000; // type:object size:0x4 data:4byte\n"
)

C_SOURCE = (
    '#include "x.h"\r\n'
    "/* fn_80001000 (OSGetTime), lbl_80003000 = Counter */\r\n"
    "#define OSGetTime fn_80001000\r\n"
    "extern long long fn_80001000(void); /* OSGetTime */\r\n"
    "extern int lbl_80003000;\r\n"
    'static const char* s = "fn_80001000 stays in strings";\r\n'
    "int f(void) { return (int)fn_80001000() + lbl_80003000 + fn_800010001; } // fn_80001000\r\n"
)


def make_repo(root):
    files = {
        "config/GV4E69/symbols.txt": SYMBOLS,
        "config/GV4E69/config.yml": "add_relocations:\n- source: .text:0x80001004\n  type: l\n  target: lbl_80003000\n",
        "tools/match/symbol_aliases.tsv": "# old placeholder name<TAB>current name\r\nfn_80000F00\tfn_80001040\r\n",
        "src/a.c": C_SOURCE,
        "src/b.cpp": "void fn_80001020(int x);\nvoid g() { fn_80001020(1); }\n",
        "include/x.h": "extern int lbl_80002000[12];\n",
    }
    for rel, text in files.items():
        p = Path(root, rel)
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_bytes(text.encode("latin-1"))


RENAMES = {
    "fn_80001000": "OSGetTime",
    "fn_80001020__Fi": "Mangled__Fi",
    "fn_80001040": "Target",
    "lbl_80003000": "Counter",
}


class ApplyTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = self.tmp.name
        make_repo(self.root)
        self.tsv = os.path.join(self.root, "renames.tsv")
        Path(self.tsv).write_text("".join(f"{o}\t{n}\n" for o, n in RENAMES.items()), encoding="utf-8")

    def tearDown(self):
        self.tmp.cleanup()

    def run_tool(self, *args):
        return rs.main(["--repo", self.root, "-q", *args])

    def read(self, rel):
        return Path(self.root, rel).read_bytes()

    def test_symbols_sources_aliases(self):
        self.assertEqual(self.run_tool(self.tsv), 0)
        syms = self.read("config/GV4E69/symbols.txt").decode()
        self.assertIn("OSGetTime = .text:0x80001000; // type:function size:0x20\n", syms)
        self.assertIn("Mangled__Fi = .text:0x80001020;", syms)
        self.assertIn("Counter = .sbss:0x80003000;", syms)
        self.assertIn("lbl_80002000 = .data", syms)

        a = self.read("src/a.c")
        self.assertEqual(a.count(b"\r\n"), a.count(b"\n"), "CRLF line endings kept")
        text = a.decode()
        self.assertIn("/* OSGetTime, Counter */", text)
        self.assertNotIn("#define", text)  # `#define OSGetTime OSGetTime` is dropped
        self.assertIn("extern long long OSGetTime(void);\r\n", text)  # echo comment dropped
        self.assertIn('"fn_80001000 stays in strings"', text)  # string literal untouched
        self.assertIn("fn_800010001", text)  # a longer token is not a match
        self.assertIn("return (int)OSGetTime() + Counter", text)
        self.assertTrue(text.endswith("+ fn_800010001; }\r\n"))  # the `// OSGetTime` echo is dropped

        self.assertEqual(self.read("src/b.cpp"), b"void Mangled(int x);\nvoid g() { Mangled(1); }\n")
        self.assertEqual(self.read("include/x.h"), b"extern int lbl_80002000[12];\n")
        self.assertIn(b"target: Counter\n", self.read("config/GV4E69/config.yml"))

        aliases = self.read("tools/match/symbol_aliases.tsv")
        self.assertIn(b"fn_80000F00\tTarget\r\n", aliases)  # re-pointed
        self.assertIn(b"fn_80001000\tOSGetTime\r\n", aliases)
        self.assertIn(b"lbl_80003000\tCounter\r\n", aliases)

    def test_idempotent(self):
        self.assertEqual(self.run_tool(self.tsv), 0)
        snap = {p: self.read(p) for p in ("config/GV4E69/symbols.txt", "src/a.c", "src/b.cpp",
                                          "tools/match/symbol_aliases.tsv", "config/GV4E69/config.yml")}
        self.assertEqual(self.run_tool(self.tsv), 0)
        for p, data in snap.items():
            self.assertEqual(self.read(p), data, p)

    def test_dry_run_changes_nothing(self):
        before = {p: self.read(p) for p in ("config/GV4E69/symbols.txt", "src/a.c", "tools/match/symbol_aliases.tsv")}
        self.assertEqual(self.run_tool("--dry-run", self.tsv), 0)
        for p, data in before.items():
            self.assertEqual(self.read(p), data, p)

    def test_non_identifier_name_is_blocked_in_sources(self):
        rc = self.run_tool("--pair", "lbl_80003000=@69")
        self.assertEqual(rc, 1)  # src/a.c still references it in code
        self.assertIn(b"@69 = .sbss:0x80003000", self.read("config/GV4E69/symbols.txt"))
        self.assertIn(b"lbl_80003000", self.read("src/a.c"))
        self.assertIn(b"lbl_80003000\t@69", self.read("tools/match/symbol_aliases.tsv"))

    def test_contradictions_are_refused(self):
        with self.assertRaises(SystemExit):
            self.run_tool("--pair", "fn_80001000=A", "--pair", "fn_80001000=B")
        with self.assertRaises(SystemExit):
            self.run_tool("--pair", "fn_80001000=fn_80001040")  # already a global symbol


FAKE_DTK = textwrap.dedent('''
    """Fake `dtk dol split`: names callees of OSGetTime the way a signature would."""
    import sys
    p = "config/GV4E69/symbols.txt"
    t = open(p, "rb").read()
    if b"FAIL" in t:
        sys.stderr.write("Symbol X overlaps with symbol Y\\n")
        sys.exit(1)
    if b"OSGetTime = " in t:
        t = t.replace(b"fn_80001040 = .text:0x80001040; // type:function size:0x20",
                      b"InsertAlarm = .text:0x80001040; // type:function size:0x20 scope:local")
        t = t.replace(b"lbl_80002000 = .data:0x80002000; // type:object size:0x30",
                      b"@69 = .data:0x80002000; // type:object size:0x10 scope:local data:string\\n"
                      b"lbl_80002010 = .data:0x80002010; // type:object size:0x20")
    if b"InsertAlarm = " in t:  # a second pass finds more
        t = t.replace(b"lbl_80003000 = .sbss", b"AlarmQueue = .sbss")
    open(p, "wb").write(t)
''')


class FromDtkTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = self.tmp.name
        make_repo(self.root)
        Path(self.root, "build/GV4E69/orig").mkdir(parents=True)
        Path(self.root, "build/GV4E69/orig/main_sections.dol").write_bytes(b"")
        self.dtk = os.path.join(self.root, "fake_dtk.py")
        Path(self.dtk).write_text(FAKE_DTK, encoding="utf-8")
        # x.h references lbl_80002000 (it becomes @69): drop it so the run is clean
        Path(self.root, "include/x.h").write_bytes(b"/* lbl_80002000 */\n")

    def tearDown(self):
        self.tmp.cleanup()

    def run_tool(self, *args):
        return rs.main(["--repo", self.root, "-q", "--dtk", self.dtk, *args])

    def test_cascade_is_propagated(self):
        report = os.path.join(self.root, "report.tsv")
        self.assertEqual(self.run_tool("--from-dtk", "--pair", "fn_80001000=OSGetTime", "--report", report), 0)
        syms = Path(self.root, "config/GV4E69/symbols.txt").read_text()
        self.assertIn("AlarmQueue = .sbss:0x80003000", syms)
        text = Path(self.root, "src/a.c").read_bytes().decode()
        self.assertIn("return (int)OSGetTime() + AlarmQueue", text)
        rows = {row.split("\t")[0]: row.split("\t")[1:] for row in Path(report).read_text().splitlines()}
        self.assertEqual(rows["fn_80001000"], ["OSGetTime", "explicit"])
        self.assertEqual(rows["fn_80001040"], ["InsertAlarm", "dtk"])
        self.assertEqual(rows["lbl_80003000"], ["AlarmQueue", "dtk"])
        self.assertEqual(rows["lbl_80002000"], ["@69", "dtk"])
        aliases = Path(self.root, "tools/match/symbol_aliases.tsv").read_bytes()
        self.assertIn(b"fn_80000F00\tInsertAlarm\r\n", aliases)
        # rerun: dtk is at its fixpoint, nothing changes
        snap = Path(self.root, "src/a.c").read_bytes(), Path(self.root, "config/GV4E69/symbols.txt").read_bytes()
        self.assertEqual(self.run_tool("--from-dtk"), 0)
        self.assertEqual(snap, (Path(self.root, "src/a.c").read_bytes(),
                                Path(self.root, "config/GV4E69/symbols.txt").read_bytes()))

    def test_failed_split_restores(self):
        before = Path(self.root, "config/GV4E69/symbols.txt").read_bytes()
        src = Path(self.root, "src/a.c").read_bytes()
        self.assertEqual(self.run_tool("--from-dtk", "--pair", "fn_80001000=FAIL"), 2)
        self.assertEqual(Path(self.root, "config/GV4E69/symbols.txt").read_bytes(), before)
        self.assertEqual(Path(self.root, "src/a.c").read_bytes(), src)


class DiffTests(unittest.TestCase):
    def test_diff_by_address(self):
        a = (b"fn_1 = .text:0x80000010; // type:function size:0x8\n"
             b"lbl_2 = .data:0x80000100; // type:object size:0x20\n"
             b"lbl_3 = .sbss:0x80000200; // type:object size:0x4\n"
             b"lbl_4 = .sbss:0x80000204; // type:object size:0x4\n")
        b = (b"Foo = .text:0x80000010; // type:function size:0x8 scope:global\n"
             b"lbl_2 = .data:0x80000100; // type:object size:0x10\n"
             b"lbl_5 = .data:0x80000110; // type:object size:0x10\n"
             b"Bar = .sbss:0x80000200; // type:object size:0x8\n")
        ren, added, removed, changed, ambiguous = rs.diff_symbols(a, b)
        self.assertEqual(ren, {"fn_1": "Foo", "lbl_3": "Bar"})
        self.assertEqual([x[0] for x in added], ["lbl_5"])
        self.assertEqual([x[0] for x in removed], ["lbl_4"])
        self.assertEqual(sorted(x[0] for x in changed), ["Bar", "Foo", "lbl_2"])
        self.assertEqual(ambiguous, [])

    def test_function_and_new_label_at_one_address(self):
        a = b"fn_80431FEC = .text:0x80431FEC; // type:function size:0x24\n"
        b = (b"__OSDBIntegrator = .text:0x80431FEC; // type:function size:0x24 scope:local\n"
             b"__OSDBINTSTART = .text:0x80431FEC; // type:label scope:global\n")
        ren, added, removed, changed, ambiguous = rs.diff_symbols(a, b)
        self.assertEqual(ren, {"fn_80431FEC": "__OSDBIntegrator"})
        self.assertEqual([x[0] for x in added], ["__OSDBINTSTART"])
        self.assertEqual(ambiguous, [])
        c = (b"A = .text:0x80431FEC; // type:function size:0x24\n"
             b"B = .text:0x80431FEC; // type:function size:0x24\n")
        self.assertEqual(rs.diff_symbols(a, c)[4], [(".text", 0x80431FEC, ["fn_80431FEC"], ["A", "B"])])


if __name__ == "__main__":
    unittest.main()
