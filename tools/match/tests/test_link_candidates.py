"""Synthetic section and function-placement tests for link_candidates."""
import sys
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import link_candidates as link


def elf(sections, functions=(), symbols=()):
    """Build an Elf-like object; function rows are (name, section, off, size)."""
    names = [""] + [row[0] for row in sections]
    sec_rows = [(0, 0, 0, 0, 0, 0, 0, 0, 0, 0)]
    indices = {}
    for i, (name, kind, flags, size, alignment, address) in enumerate(sections, 1):
        indices[name] = i
        sec_rows.append((0, kind, flags, address, 0, size, 0, 0, alignment, 0))
    syms = [(name, sec_rows[indices[section]][3] + offset,
             size, 0x12, indices[section])
            for name, section, offset, size in functions]
    syms.extend(symbols)
    return SimpleNamespace(names=names, secs=sec_rows, syms=syms)


def code_elf(functions, *, extra_sections=(), symbols=()):
    sections = [('.text', 1, 6, 32, 4, 0x1000), *extra_sections]
    return elf(sections, functions, symbols)


class FunctionLayoutTests(unittest.TestCase):
    def test_reordered_functions_fail_even_when_section_layout_matches(self):
        target = code_elf([('first', '.text', 0, 8), ('second', '.text', 8, 8)])
        source = code_elf([('first', '.text', 8, 8), ('second', '.text', 0, 8)])
        self.assertEqual(link.allocated_layout(target), link.allocated_layout(source))
        result = link.compare_function_layout(target, source)
        self.assertFalse(result['same'])
        self.assertEqual(result['moved'], ['first', 'second'])
        self.assertEqual([f['target'][0]['offset'] for f in result['details']], [0, 8])

    def test_missing_and_extra_functions_are_reported(self):
        target = code_elf([('present', '.text', 0, 4), ('gone', '.text', 4, 4)])
        source = code_elf([('present', '.text', 0, 4), ('new', '.text', 4, 4)])
        result = link.compare_function_layout(target, source)
        self.assertEqual(result['missing'], ['gone'])
        self.assertEqual(result['extra'], ['new'])
        self.assertFalse(result['same'])

    def test_same_offset_in_different_overlay_section_is_moved(self):
        overlay = ('.feoverlay', 1, 6, 32, 4, 0x2000)
        target = code_elf([('fn', '.text', 0, 8)], extra_sections=[overlay])
        source = code_elf([('fn', '.feoverlay', 0, 8)], extra_sections=[overlay])
        self.assertEqual(link.allocated_layout(target), link.allocated_layout(source))
        result = link.compare_function_layout(target, source)
        self.assertEqual(result['moved'], ['fn'])
        self.assertNotEqual(result['details'][0]['target'][0]['section'],
                            result['details'][0]['source'][0]['section'])

    def test_section_index_order_does_not_affect_name_based_matching(self):
        target = elf([('.text', 1, 6, 32, 4, 0x1000),
                      ('.feoverlay', 1, 6, 32, 4, 0x2000)],
                     [('text_fn', '.text', 0, 8), ('overlay_fn', '.feoverlay', 4, 8)])
        source = elf([('.feoverlay', 1, 6, 32, 4, 0x2000),
                      ('.text', 1, 6, 32, 4, 0x1000)],
                     [('text_fn', '.text', 0, 8), ('overlay_fn', '.feoverlay', 4, 8)])
        self.assertNotEqual(link.allocated_layout(target), link.allocated_layout(source))
        self.assertTrue(link.compare_function_layout(target, source)['same'])

    def test_offsets_are_section_relative_and_section_moves_are_reported(self):
        target = code_elf([('fn', '.text', 12, 8)])
        source = code_elf([('fn', '.text', 16, 8)])
        result = link.compare_function_layout(target, source)
        self.assertEqual(result['details'][0]['target'][0]['offset'], 12)
        self.assertEqual(result['details'][0]['source'][0]['offset'], 16)
        self.assertEqual(result['moved'], ['fn'])

    def test_data_and_undefined_symbols_are_ignored(self):
        target = code_elf([('fn', '.text', 0, 8)], extra_sections=[('.data', 1, 3, 16, 4, 0x3000)],
                          symbols=[('object_in_text', 0x1004, 4, 0x11, 1),
                                   ('function_in_data', 0x3000, 4, 0x12, 2),
                                   ('undefined_fn', 0, 4, 0x12, 0)])
        source = code_elf([('fn', '.text', 0, 8)])
        result = link.compare_function_layout(target, source)
        self.assertTrue(result['same'])
        self.assertEqual([f['name'] for f in result['target']], ['fn'])

    def test_identical_duplicate_alias_symbols_are_preserved_safely(self):
        funcs = [('alias', '.text', 0, 8), ('alias', '.text', 0, 8)]
        result = link.compare_function_layout(code_elf(funcs), code_elf(funcs))
        self.assertTrue(result['same'])
        self.assertEqual(len(result['target']), 2)

    def test_conflicting_duplicate_names_are_ambiguous(self):
        target = code_elf([('alias', '.text', 0, 8), ('alias', '.text', 8, 8)])
        source = code_elf([('alias', '.text', 0, 8)])
        result = link.compare_function_layout(target, source)
        self.assertFalse(result['same'])
        self.assertEqual(result['ambiguous'], ['alias'])

    def test_identical_conflicting_duplicate_locations_remain_ambiguous(self):
        funcs = [('alias', '.text', 0, 8), ('alias', '.text', 8, 8)]
        result = link.compare_function_layout(code_elf(funcs), code_elf(funcs))
        self.assertFalse(result['same'])
        self.assertEqual(result['ambiguous'], ['alias'])

    def test_zero_sized_symbols_never_establish_ready_layout(self):
        result = link.compare_function_layout(code_elf([('empty', '.text', 0, 0)]),
                                              code_elf([('empty', '.text', 0, 0)]))
        self.assertFalse(result['same'])
        self.assertEqual(result['ambiguous'], ['empty'])

    def test_ready_requires_function_layout_even_if_section_layout_matches(self):
        row = {'same_layout': True, 'same_footprint': True,
               'same_function_layout': False, 'missing': []}
        self.assertFalse(link.candidate_ready(row))
        self.assertFalse(link.candidate_ready(row, allow_footprint=True))

    def test_candidate_row_exposes_moved_functions_additively(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            (root / 'obj').mkdir()
            (root / 'src').mkdir()
            (root / 'obj' / 'unit.o').touch()
            (root / 'src' / 'unit.o').touch()
            target = code_elf([('fn', '.text', 0, 8)])
            source = code_elf([('fn', '.text', 8, 8)])

            def choose_elf(path):
                return target if 'obj' in Path(path).parts else source

            report = {'units': [{
                'name': 'main/unit',
                'measures': {'total_code': '8', 'matched_code_percent': 100,
                             'matched_data_percent': 100},
                'metadata': {'source_path': 'src/unit.c', 'complete': False},
            }]}
            with patch.object(link, 'BUILD', root), patch.object(link, 'Elf', side_effect=choose_elf):
                row = link.candidates(report, SimpleNamespace(syms=[]))[0]

        self.assertTrue(row['same_layout'])
        self.assertFalse(row['same_function_layout'])
        self.assertEqual(row['function_layout']['moved'], ['fn'])


class FootprintTests(unittest.TestCase):
    def test_ctor_order_flags_and_alignment_are_distinct_from_footprint(self):
        target=elf([('.text',1,6,20,4,0),('.ctors',1,2,4,4,0),('.bss',8,3,20,8,0)])
        source=elf([('.text',1,6,20,4,0),('.bss',8,3,20,4,0),('.ctors',1,3,4,1,0)])
        self.assertNotEqual(link.allocated_layout(target),link.allocated_layout(source))
        self.assertEqual(link.allocated_footprint(target),link.allocated_footprint(source))
    def test_size_difference_is_not_equal_footprint(self):
        self.assertNotEqual(link.allocated_footprint(elf([('.text',1,6,20,4,0)])),link.allocated_footprint(elf([('.text',1,6,24,4,0)])))
    def test_section_type_difference_is_not_equal_footprint(self):
        self.assertNotEqual(link.allocated_footprint(elf([('.bss',8,3,20,4,0)])),link.allocated_footprint(elf([('.bss',1,3,20,4,0)])))
    def test_missing_data_section_is_not_equal_footprint(self):
        self.assertNotEqual(link.allocated_footprint(elf([('.text',1,6,20,4,0),('.data',1,3,4,4,0)])),link.allocated_footprint(elf([('.text',1,6,20,4,0)])))
    def test_nonallocated_debug_sections_are_ignored(self):
        self.assertEqual(link.allocated_footprint(elf([('.text',1,6,20,4,0)])),link.allocated_footprint(elf([('.text',1,6,20,4,0),('.debug',1,0,100,1,0)])))


if __name__ == '__main__':
    unittest.main(verbosity=2)
