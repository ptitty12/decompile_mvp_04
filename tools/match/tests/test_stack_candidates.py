import importlib.util
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
MATCH = ROOT / "tools" / "match"
sys.path.insert(0, str(MATCH))
sys.path.insert(1, str(ROOT / "tools" / "match" / "tests"))
import test_clone_sections as section_tests

spec = importlib.util.spec_from_file_location(
    "stack_candidates", Path(__file__).resolve().parents[1] / "stack_candidates.py")
sc = importlib.util.module_from_spec(spec)
spec.loader.exec_module(sc)


def fixture(branch="far", call="callee_a", data="data_a", store=24, addroff=8, load=24):
    return f"""\
        .text
        .globl fn_text
        .type fn_text,@function
    fn_text:
        stw 3,{store}(1)
        lwz 4,{load}(1)
        bl {call}
        lis 9,{data}@ha
        addi 9,9,{data}@l
        beq .Ltext_end
        nop
    .Ltext_end:
        blr
        .size fn_text,.-fn_text

        .section .feoverlay,"ax",@progbits
        .globl fn_overlay
        .type fn_overlay,@function
    fn_overlay:
        stw 3,{store}(1)
        beq .Loverlay_{branch}
        nop
    .Loverlay_near:
        blr
    .Loverlay_far:
        blr
    .Loverlay_end:
        .size fn_overlay,.-fn_overlay

        .section .dboverlay,"ax",@progbits
        .globl fn_dboverlay
        .type fn_dboverlay,@function
    fn_dboverlay:
        stw 3,{store}(1)
        addi 3,1,{addroff}
        blr
        .size fn_dboverlay,.-fn_dboverlay
        .data
        .globl {data}
    {data}:
        .long 0
    """


class StackOperandGuardTests(unittest.TestCase):
    def test_same_frame_memory_and_address_slots(self):
        target = [0x9421FFD8, 0x90010018, 0x80610020, 0x38610008, 0x4E800020]
        source = [0x9421FFD8, 0x90010020, 0x80610018, 0x38610010, 0x4E800020]
        changes = sc.stack_differences(target, source)
        self.assertEqual([(c['kind'], c['target_displacement'], c['source_displacement'])
                          for c in changes], [('mem', 24, 32), ('mem', 32, 24), ('addi', 8, 16)])

    def test_rejects_register_opcode_base_and_length_changes(self):
        target = [0x90010018, 0x4E800020]
        for source in ([0x90210020, 0x4E800020], [0x80610020, 0x4E800020],
                       [0x90020020, 0x4E800020], [0x90010020]):
            self.assertIsNone(sc.stack_differences(target, source))

    def test_rejects_branch_condition_and_local_destination_changes(self):
        for source, edge in ((0x4082000C, 8), (0x4182000C, 12)):
            self.assertIsNone(sc.stack_differences([0x41820008, 0x90010018],
                [source, 0x90010020], target_edges=[8, None], source_edges=[edge, None]))

    def test_rejects_relocated_stack_displacement(self):
        self.assertIsNone(sc.stack_differences([0x90010018], [0x90010020],
                                               target_relocs={0}))


@unittest.skipUnless(section_tests.AS.is_file(), 'build/binutils required')
class StackCandidatePipelineTests(unittest.TestCase):
    def assemble_pair(self, root, target_text, source_text):
        assembler = section_tests.ExecutableSectionGuardTests().assemble
        for kind in ("obj", "src"):
            (root / kind).mkdir(parents=True, exist_ok=True)
        assembler(root / "obj", "demo", target_text)
        assembler(root / "src", "demo", source_text)

    def test_all_three_executable_sections_and_local_branch_guard(self):
        report = {"units": [{"name": "main/demo", "functions": [
            {"name": fn, "fuzzy_match_percent": 99.0}
            for fn in ("fn_text", "fn_overlay", "fn_dboverlay")]}]}
        with tempfile.TemporaryDirectory() as td:
            root = Path(td)
            self.assemble_pair(root, fixture("far"), fixture("far", store=32, addroff=16, load=40))
            rows = sc.candidates(report, build=root)
            self.assertEqual({row["function"] for row in rows},
                             {"fn_text", "fn_overlay", "fn_dboverlay"})
            self.assertTrue(all(row["bindings_status"] == "matching" for row in rows))
            self.assertTrue(all(row["unverified_binding_differences"] == [] for row in rows))
            self.assemble_pair(root, fixture("far"), fixture("near", store=32, addroff=16, load=40))
            self.assertEqual({row["function"] for row in sc.candidates(report, build=root)},
                             {"fn_text", "fn_dboverlay"})

    def test_call_and_data_relocation_diffs_are_only_provisional_with_flag(self):
        report = {"units": [{"name": "main/demo", "functions": [
            {"name": "fn_text", "fuzzy_match_percent": 99.0}]}]}
        with tempfile.TemporaryDirectory() as td:
            root = Path(td)
            self.assemble_pair(root, fixture(call="callee_a", data="data_a"),
                               fixture(call="callee_b", data="data_b", store=32, addroff=16, load=40))
            self.assertEqual(sc.candidates(report, build=root), [])
            rows = sc.candidates(report, build=root, unverified_bindings=True)
            self.assertEqual(len(rows), 1)
            row = rows[0]
            self.assertEqual(row["bindings_status"], "unverified")
            symbols = {
                binding[side]["symbol"]
                for binding in row["unverified_binding_differences"]
                for side in ("target", "source") if binding[side]
            }
            self.assertTrue({"callee_a", "callee_b", "data_a", "data_b"} <= symbols)
            self.assertGreaterEqual(len(row["unverified_binding_differences"]), 3)
            ambiguous = [m for m in row["offset_mapping"] if m["ambiguous"]]
            self.assertTrue(ambiguous)
            self.assertEqual(ambiguous[0]["target"], 24)
            self.assertEqual(ambiguous[0]["source_options"], [32, 40])


if __name__ == "__main__":
    unittest.main()

