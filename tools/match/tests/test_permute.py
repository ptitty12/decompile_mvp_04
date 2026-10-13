"""Synthetic extraction regressions; optional real PowerPC binutils smoke tests.

Run: python -m unittest discover -s tools/match/tests -v
No retail bytes or installed permuter are needed.
"""
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import permute


class TargetExtractionTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.root_patch = patch.object(permute, "ROOT", self.root)
        self.root_patch.start()
        self.addCleanup(self.root_patch.stop)
        self.split = self.root / "build" / permute.VERSION / "asm" / "test.s"
        self.split.parent.mkdir(parents=True)

    def extract(self, section):
        self.split.write_text(
            section + '\n.fn synthetic, global\naddi 3, 3, 1\nblr\n.endfn synthetic\n',
            encoding="utf-8",
        )
        return permute.target_asm("test", "synthetic")

    def test_bare_overlays_are_executable(self):
        for section in (".feoverlay", ".dboverlay"):
            with self.subTest(section=section):
                self.assertIn(f'.section {section}, "ax"\n', self.extract(f".section {section}"))

    def test_text_and_explicit_flags_preserved(self):
        for section in (".text", '.section .feoverlay, "ax", @progbits'):
            with self.subTest(section=section):
                self.assertIn(section + "\n", self.extract(section))

    def test_empty_target_refused(self):
        with patch.object(permute, "disasm", return_value=([], set())):
            with self.assertRaisesRegex(SystemExit, "REFUSED.*no disassembled target"):
                permute.require_target(Path("target.o"), "synthetic")

    def test_objdump_error_is_not_empty_success(self):
        failed = subprocess.CompletedProcess([], 1, "", "bad object")
        with patch.object(permute.subprocess, "run", return_value=failed):
            with self.assertRaisesRegex(RuntimeError, "objdump failed.*bad object"):
                permute.disasm(Path("target.o"), "synthetic")

    @unittest.skipUnless((permute.BINUTILS / f"powerpc-eabi-as{permute.EXE}").exists(), "binutils not installed")
    def test_extracted_targets_have_real_instructions(self):
        # Reproduce the full split's section declaration followed by a bare
        # switch, using synthetic instructions and minimal assembler macros.
        (self.root / "macros.inc").write_text(
            '.macro .fn name, scope\n.global \\name\n.type \\name, @function\n\\name:\n.endm\n'
            '.macro .endfn name\n.size \\name, .-\\name\n.endm\n', encoding="utf-8")
        for section in (".text", ".section .feoverlay", ".section .dboverlay"):
            with self.subTest(section=section):
                source, obj = self.root / "target.s", self.root / "target.o"
                source.write_text(self.extract(section), encoding="utf-8")
                subprocess.run([str(permute.BINUTILS / f"powerpc-eabi-as{permute.EXE}"),
                                "-mgekko", "-I", str(self.root), "-o", str(obj), str(source)],
                               check=True, capture_output=True)
                self.assertEqual(len(permute.require_target(obj, "synthetic")), 2)


if __name__ == "__main__":
    unittest.main()
