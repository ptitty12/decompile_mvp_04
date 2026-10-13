import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from frame_candidates import candidates, frame_differences, frame_size
import test_clone_sections as section_tests
from test_clone_sections import AS, fixture


class FrameCandidateTests(unittest.TestCase):
    target = [0x9421FFD8, 0x7C0802A6, 0xBF610014, 0x9001002C, 0x4E800020]
    source = [0x9421FFD0, 0x7C0802A6, 0xBF61001C, 0x90010034, 0x4E800020]

    def test_recognizes_frame_and_save_offset_changes(self):
        self.assertEqual(frame_size(self.target), 40)
        self.assertEqual(frame_size(self.source), 48)
        self.assertEqual([r[0] for r in frame_differences(self.target, self.source)], [0, 8, 12])
        self.assertEqual(frame_size([self.target[1], self.target[0]]), 40)

    def test_rejects_length_register_and_nonstack_changes(self):
        self.assertIsNone(frame_differences(self.target, self.source[:-1]))
        for replacement in (0xBF81001C, 0xBF62001C):
            source = list(self.source)
            source[2] = replacement
            self.assertIsNone(frame_differences(self.target, source))

    def test_requires_a_different_valid_frame(self):
        self.assertIsNone(frame_differences(self.target, self.target))
        self.assertIsNone(frame_size([0x94210010]))
        self.assertIsNone(frame_size([0x9400FFD8]))

    def test_preserves_sp_relative_slot_address_changes(self):
        target = self.target[:-1] + [0x38610008, 0x4E800020]
        source = self.source[:-1] + [0x38610010, 0x4E800020]
        self.assertEqual(frame_differences(target, source)[-1][0], 16)
        source[-2] = 0x38620010
        self.assertIsNone(frame_differences(target, source))

    def test_accepts_byte_halfword_and_float_update_stack_slots(self):
        for prefix in (0x88610000, 0xA0610000, 0x98610000, 0xB0610000, 0xC4610000):
            with self.subTest(prefix=hex(prefix)):
                target = self.target[:-1] + [prefix | 8, 0x4E800020]
                source = self.source[:-1] + [prefix | 16, 0x4E800020]
                self.assertIsNotNone(frame_differences(target, source))


@unittest.skipUnless(AS.is_file(), 'build/binutils required')
class FrameSectionTests(unittest.TestCase):
    def test_pairs_all_sections_and_rejects_changed_overlay_path(self):
        report = {'units': [{'name': 'main/demo', 'functions': [
            {'name': fn, 'fuzzy_match_percent': 99}
            for fn in ('fn_text', 'fn_overlay')]}]}
        assembler = section_tests.ExecutableSectionGuardTests().assemble
        with tempfile.TemporaryDirectory() as directory:
            build = Path(directory)
            for kind in ('obj', 'src'):
                (build / kind).mkdir()
            def compile_at(kind, frame, target):
                text = fixture(target).replace('        beq ',
                    f'        stwu 1,-{frame}(1)\n        beq ')
                assembler(build / kind, 'demo', text)
            compile_at('obj', 40, 'far')
            compile_at('src', 48, 'far')
            self.assertEqual({r['function'] for r in candidates(report, build)},
                             {'fn_text', 'fn_overlay'})
            compile_at('src', 48, 'near')
            self.assertEqual([r['function'] for r in candidates(report, build)],
                             ['fn_text'])


if __name__ == '__main__':
    unittest.main()
