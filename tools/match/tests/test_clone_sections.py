import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "tools" / "match"))
from clone import Cloner

AS = ROOT / "build" / "binutils" / "powerpc-eabi-as.exe"
OBJDUMP = ROOT / "build" / "binutils" / "powerpc-eabi-objdump.exe"


def fixture(overlay_target):
    return f"""\
        .text
        .globl fn_text
        .type fn_text,@function
    fn_text:
        beq .Ltext_target
        nop
    .Ltext_target:
        blr
        .size fn_text,.-fn_text

        .section .feoverlay,\"ax\",@progbits
        .globl fn_overlay
        .type fn_overlay,@function
    fn_overlay:
        beq .Loverlay_{overlay_target}
        nop
    .Loverlay_near:
        blr
    .Loverlay_far:
        blr
    .Loverlay_end:
        .size fn_overlay,.-fn_overlay
    """


@unittest.skipUnless(AS.is_file() and OBJDUMP.is_file(), "build/binutils required")
class ExecutableSectionGuardTests(unittest.TestCase):
    def assemble(self, directory, name, text):
        source = Path(directory) / f"{name}.s"
        obj = Path(directory) / f"{name}.o"
        source.write_text(text)
        subprocess.run([str(AS), "-mgekko", "-o", str(obj), str(source)],
                       check=True, capture_output=True, text=True)
        return obj

    def test_text_and_overlay_edges_are_guarded(self):
        with tempfile.TemporaryDirectory() as td:
            ours = self.assemble(td, "ours", fixture("far"))
            same = self.assemble(td, "same", fixture("far"))
            changed = self.assemble(td, "changed", fixture("near"))
            cloner = Cloner(None, None)
            cloner.objdump = OBJDUMP
            functions = cloner.objfuncs(ours)
            self.assertEqual(functions["fn_text"][0][3], 8)
            self.assertEqual(functions["fn_overlay"][0][3], 12)
            self.assertIsNone(cloner.compare(functions["fn_text"], cloner.objfuncs(same)["fn_text"], "fn_text"))
            self.assertIsNone(cloner.compare(functions["fn_overlay"], cloner.objfuncs(same)["fn_overlay"], "fn_overlay"))
            changed_overlay = cloner.objfuncs(changed)["fn_overlay"]
            self.assertEqual(changed_overlay[0][3], 8)
            self.assertIn("branch 0", cloner.compare(functions["fn_overlay"], changed_overlay, "fn_overlay"))


if __name__ == "__main__":
    unittest.main()
