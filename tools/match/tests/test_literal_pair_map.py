import sys
import unittest
from pathlib import Path

here = Path(__file__).resolve()
tools_match = here.parents[1]
sys.path.insert(0, str(tools_match))
if not (tools_match / "check_literals.py").is_file():
    sys.path.insert(1, str(here.parents[5] / "tools" / "match"))
import literal_pair_map as mapper


class FakeElf:
    def __init__(self, sections, functions, relocations=None, symbols=None):
        self.names = list(sections)
        self.secs = [(0, 1, 4 if ('text' in n or 'overlay' in n) else 2, 0, 0, size, 0, 0, 4, 0) for n, size in sections.items()]
        self._functions = functions
        self._relocations = relocations or {}
        self.syms = symbols or []

    def funcs(self, idx):
        return self._functions.get(self.names[idx], {})

    def relocs(self, idx):
        return self._relocations.get(self.names[idx], {})


class PairingTests(unittest.TestCase):
    def test_pairs_all_corresponding_code_sections_by_name(self):
        source = FakeElf({'.text': 64, '.feoverlay': 64}, {
            '.text': {'text_fn': (0, 8)}, '.feoverlay': {'fe_fn': (16, 12)}})
        retail = FakeElf({'.text': 64, '.feoverlay': 64}, {
            '.text': {'text_fn': (8, 8)}, '.feoverlay': {'fe_fn': (24, 12)}})
        pairs, skipped, unpaired = mapper.matched_function_pairs(source, retail, {'text_fn', 'fe_fn'})
        self.assertEqual([(x[0], x[3], x[4], x[5]) for x in pairs], [('.feoverlay', 'fe_fn', 16, 24), ('.text', 'text_fn', 0, 8)])
        self.assertEqual(skipped, [])
        self.assertEqual(unpaired, [])

    def test_refuses_unequal_sizes_and_reports_missing_section(self):
        source = FakeElf({'.text': 64, '.dboverlay': 64}, {
            '.text': {'bad_size': (0, 16)}, '.dboverlay': {'unpaired': (0, 4)}})
        retail = FakeElf({'.text': 64}, {'.text': {'bad_size': (8, 20)}})
        pairs, skipped, unpaired = mapper.matched_function_pairs(source, retail, {'bad_size', 'unpaired'})
        self.assertEqual(pairs, [])
        self.assertIn('unequal function sizes 16 vs 20', skipped[0]['reason'])
        self.assertEqual(unpaired, ['.dboverlay'])

    def test_unpaired_data_relocation_is_reported(self):
        source = FakeElf({'.feoverlay': 32, '.rodata': 8}, {'.feoverlay': {}},
                         relocations={'.feoverlay': {4: (0, 4, 0)}},
                         symbols=[('pool', 0, 8, 0, 1)])
        retail = FakeElf({'.feoverlay': 32}, {'.feoverlay': {}}, relocations={'.feoverlay': {}})
        sites, skipped = mapper.paired_data_relocations(source, retail, 0, 0, 'fn', 0, 0, 8)
        self.assertEqual(sites, [])
        self.assertEqual(skipped[0]['reason'], 'unpaired data relocation')

    def test_mismatched_relocation_kind_is_skipped(self):
        source = FakeElf({'.text': 32, '.rodata': 8}, {'.text': {}},
                         relocations={'.text': {4: (0, 1, 0)}},
                         symbols=[('pool', 0, 8, 0, 1)])
        retail = FakeElf({'.text': 32}, {'.text': {}},
                         relocations={'.text': {4: (0, 4, 0)}},
                         symbols=[('pool', 0, 0, 0, 0)])
        sites, skipped = mapper.paired_data_relocations(source, retail, 0, 0, 'fn', 0, 0, 8)
        self.assertEqual(sites, [])
        self.assertEqual(skipped[0]['reason'], 'mismatched relocation kinds')

    def test_executable_source_symbol_is_skipped_even_in_another_section(self):
        source = FakeElf({'.text': 32, '.feoverlay': 32}, {'.text': {}},
                         relocations={'.text': {4: (0, 1, 0)}},
                         symbols=[('other_fn', 0, 8, 0, 1)])
        source.secs[1] = (0, 1, 4, 0, 0, 32, 0, 0, 4, 0)
        retail = FakeElf({'.text': 32}, {'.text': {}}, relocations={'.text': {}})
        sites, skipped = mapper.paired_data_relocations(source, retail, 0, 0, 'fn', 0, 0, 8)
        self.assertEqual((sites, skipped), ([], []))

    def test_byte_comparison_rejects_invalid_source_ranges(self):
        data = b'ABCD'
        self.assertIsNone(mapper.checked_range(data, -1, 2))
        self.assertIsNone(mapper.checked_range(data, 5, 2))
        self.assertEqual(mapper.checked_range(data, 1, 2), b'BC')

    def test_exact_comparison_rejects_short_buffers_and_keeps_ambiguous_names(self):
        names = [{'name': 'lbl_A', 'size': 4}, {'name': 'lbl_A_alias', 'size': None}]
        exact = mapper.byte_comparison(b'ABCD', b'ABCD', 0x80500000, names, 4, 'load_width', True)
        self.assertTrue(exact['bytes_equal'])
        self.assertTrue(exact['ambiguous_target_names'])
        short = mapper.byte_comparison(b'ABC', b'ABC', 0x80500000, names, 4, 'load_width', True)
        self.assertFalse(short['bytes_equal'])
        self.assertFalse(short['bounds_ok'])
        self.assertTrue(short['unresolved_bounds'])
        prefix = mapper.byte_comparison(b'ABCD', b'ABCD', 0x80500000, [], 4, 'fallback_prefix_4', False)
        self.assertTrue(prefix['bytes_equal'])
        self.assertFalse(prefix['extent_complete'])
        unresolved = mapper.byte_comparison(b'ABCD', None, None, [], 4, 'load_width', True)
        self.assertIsNone(unresolved['retail_address'])
        self.assertFalse(unresolved['bytes_equal'])


if __name__ == '__main__':
    unittest.main()
