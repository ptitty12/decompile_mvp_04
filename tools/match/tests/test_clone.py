"""Dependency collection tests using synthetic C++ only."""
import sys
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from clone import Cloner, Ctx


class InlineMemberTests(unittest.TestCase):
    def collect(self, donor, code):
        with tempfile.TemporaryDirectory() as directory:
            donor_path = Path(directory) / "donor.cpp"
            target_path = Path(directory) / "target.cpp"
            donor_path.write_text(donor)
            target_path.write_text("")
            cloner = Cloner(None, None)
            declarations, includes = cloner.collect_decls(
                code, "fn_target", {}, SimpleNamespace(syms=[]),
                Ctx(donor_path), Ctx(target_path), False)
            self.assertEqual(includes, [])
            return "\n\n".join(declarations)

    def test_separate_inline_bodies_and_dependencies_are_copied(self):
        declarations = self.collect("""
struct Box { inline Box(int); inline int Read(); };
extern int values[];
void emit(int);
inline Box::Box(int value) { emit(value); }
inline int Box::Read() { return values[0]; }
""", 'extern "C" int fn_target() { Box b(7); return b.Read(); }')
        self.assertIn("inline Box::Box(int value)", declarations)
        self.assertIn("inline int Box::Read()", declarations)
        self.assertIn("extern int values[];", declarations)
        self.assertIn('extern "C" void emit(int);', declarations)
        self.assertLess(declarations.index("struct Box"), declarations.index("inline Box::Box"))
        self.assertLess(declarations.index("values[]"), declarations.index("inline int Box::Read"))

    def test_existing_inline_in_class_is_not_duplicated(self):
        declarations = self.collect("""
struct Box { int Read() { return 3; } };
""", 'extern "C" int fn_target(Box* b) { return b->Read(); }')
        self.assertEqual(declarations.count("return 3;"), 1)

    def test_unrelated_and_non_inline_methods_are_not_copied(self):
        declarations = self.collect("""
struct Box { inline int Read(); void Slow(); };
struct Other { inline int Read(); };
inline int Box::Read() { return 3; }
void Box::Slow() { }
inline int Other::Read() { return 9; }
""", 'extern "C" int fn_target(Box* b) { return b->Read(); }')
        self.assertIn("inline int Box::Read()", declarations)
        self.assertNotIn("void Box::Slow()", declarations)
        self.assertNotIn("Other::Read()", declarations)

    def test_multiple_uses_do_not_duplicate_member_bodies(self):
        declarations = self.collect("""
struct Box { inline int Read(); };
inline int Box::Read() { return 3; }
""", 'extern "C" int fn_target(Box* a, Box* b) { return a->Read() + b->Read(); }')
        self.assertEqual(declarations.count("inline int Box::Read()"), 1)


if __name__ == "__main__":
    unittest.main()

