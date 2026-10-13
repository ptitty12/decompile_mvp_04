"""Synthetic allocated-section footprint tests."""
import sys
import unittest
from pathlib import Path
from types import SimpleNamespace
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import link_candidates as link
def elf(rows):
    return SimpleNamespace(names=[r[0] for r in rows],secs=[(0,r[1],r[2],0,0,r[3],0,0,r[4],0) for r in rows])
class FootprintTests(unittest.TestCase):
    def test_ctor_order_flags_and_alignment_are_distinct_from_footprint(self):
        target=elf([('.text',1,6,20,4),('.ctors',1,2,4,4),('.bss',8,3,20,8)])
        source=elf([('.text',1,6,20,4),('.bss',8,3,20,4),('.ctors',1,3,4,1)])
        self.assertNotEqual(link.allocated_layout(target),link.allocated_layout(source))
        self.assertEqual(link.allocated_footprint(target),link.allocated_footprint(source))
    def test_size_difference_is_not_equal_footprint(self):
        self.assertNotEqual(link.allocated_footprint(elf([('.text',1,6,20,4)])),link.allocated_footprint(elf([('.text',1,6,24,4)])))
    def test_section_type_difference_is_not_equal_footprint(self):
        self.assertNotEqual(link.allocated_footprint(elf([('.bss',8,3,20,4)])),link.allocated_footprint(elf([('.bss',1,3,20,4)])))
    def test_missing_data_section_is_not_equal_footprint(self):
        self.assertNotEqual(link.allocated_footprint(elf([('.text',1,6,20,4),('.data',1,3,4,4)])),link.allocated_footprint(elf([('.text',1,6,20,4)])))
    def test_nonallocated_debug_sections_are_ignored(self):
        self.assertEqual(link.allocated_footprint(elf([('.text',1,6,20,4)])),link.allocated_footprint(elf([('.text',1,6,20,4),('.debug',1,0,100,1)])))
if __name__=='__main__':unittest.main(verbosity=2)
