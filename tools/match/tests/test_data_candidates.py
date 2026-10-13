"""Synthetic placement tests; no retail data or compiler is needed."""
import struct
import sys
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import data_candidates

class FixtureElf:
    def __init__(self,blobs=None,addresses=None,relocations=None,symbols=(),code_size=4):
        blobs=dict(blobs or {})
        blobs.setdefault('.text',bytes(code_size))
        addresses=addresses or {}
        self.names=['','.text','.rodata','.data','.bss']
        self.syms=list(symbols)
        self.secs=[(0,0,0,0,0,0,0,0,0,0)]
        self.data=b''
        self.blobs={}
        self.relocations=relocations or {}
        for name in self.names[1:]:
            blob=blobs.get(name,b'')
            kind=8 if name=='.bss' else 1
            flags=6 if name=='.text' else 2 if name=='.rodata' else 3
            self.secs.append((0,kind,flags,addresses.get(name,0),len(self.data),len(blob),0,0,4,0))
            self.blobs[name]=blob
            if kind!=8:self.data+=blob
        self.functions={'function':(0,code_size)}
    def text_index(self):
        return 1
    def funcs(self,index):
        return self.functions
    def relocs(self,index):
        return self.relocations.get(index,{})
    def sec_bytes(self,index):
        return self.blobs[self.names[index]]

class DataPlacementTests(unittest.TestCase):
    def main_image(self,rodata=b'ABCDWXYZ',data=b'',bss=b''):
        return FixtureElf({'.rodata':rodata,'.data':data,'.bss':bss},
            {'.text':0x1000,'.rodata':0x2000,'.data':0x3000,'.bss':0x4000})
    def locate(self,source,target=None,main=None,exports=None):
        target=target or FixtureElf()
        main=main or self.main_image()
        with patch.object(data_candidates,'Elf',side_effect=lambda path: target if 'obj' in Path(path).parts else source):
            result=data_candidates.proof('unit',main,{('unit','.text'):0x1000},exports or {})
        return {row['section']:row for row in result['sections']}
    def anchored(self,blob=b'ABCDWXYZ',source_offset=0,target_address=0x2000):
        source=FixtureElf({'.rodata':blob},
            relocations={1:{0:(0,4,0)}},symbols=[('',source_offset,0,3,2)])
        target=FixtureElf(relocations={1:{0:(0,4,0)}},symbols=[('constant',0,0,17,0)])
        return self.locate(source,target,exports={'constant':target_address})
    def test_code_relocation_includes_source_symbol_offset(self):
        row=self.anchored(source_offset=4,target_address=0x2004)['.rodata']
        self.assertEqual(row['base'],'0x2000')
        self.assertTrue(row['exact'])
    def test_unique_full_section_search(self):
        source=FixtureElf({'.rodata':b'ABCDWXYZ'})
        row=self.locate(source,main=self.main_image(b'----ABCDWXYZ'))['.rodata']
        self.assertEqual(row['base'],'0x2004')
        self.assertTrue(row['exact'])
    def test_ambiguous_identical_blobs_stay_unplaced(self):
        source=FixtureElf({'.rodata':b'ABCDWXYZ'})
        row=self.locate(source,main=self.main_image(b'ABCDWXYZABCDWXYZ'))['.rodata']
        self.assertIsNone(row['base'])
        self.assertFalse(row['exact'])
    def test_zero_block_is_never_placed_by_search(self):
        source=FixtureElf({'.rodata':bytes(8)})
        row=self.locate(source,main=self.main_image(bytes(8)))['.rodata']
        self.assertIsNone(row['base'])
    def test_wrong_bytes_do_not_override_code_anchor(self):
        row=self.anchored(blob=b'XXXXXXXX')['.rodata']
        self.assertEqual(row['base'],'0x2000')
        self.assertFalse(row['exact'])
    def test_conflicting_code_anchors_refuse_unique_fallback(self):
        source=FixtureElf({'.rodata':b'ABCDWXYZ'},code_size=8,
            relocations={1:{0:(0,4,0),4:(1,4,0)}},
            symbols=[('',0,0,3,2),('',4,0,3,2)])
        target=FixtureElf(code_size=8,relocations={1:{0:(0,4,0),4:(1,4,0)}},
            symbols=[('first',0,0,17,0),('second',0,0,17,0)])
        row=self.locate(source,target,exports={'first':0x2000,'second':0x2010})['.rodata']
        self.assertIsNone(row['base'])
        self.assertEqual(len(row['bases']),2)
        self.assertFalse(row['exact'])
    def test_initialized_pointer_anchors_bss(self):
        source=FixtureElf({'.data':bytes(4),'.bss':bytes(8)},
            relocations={1:{0:(0,4,0)},3:{0:(1,1,0)}},
            symbols=[('',0,0,3,3),('',0,0,3,4)])
        target=FixtureElf(relocations={1:{0:(0,4,0)}},symbols=[('pointer',0,0,17,0)])
        rows=self.locate(source,target,self.main_image(data=struct.pack('>I',0x4000),bss=bytes(8)),{'pointer':0x3000})
        self.assertEqual(rows['.bss']['base'],'0x4000')
        self.assertTrue(rows['.data']['exact'])
        self.assertTrue(rows['.bss']['exact'])
    def test_canonical_global_object_anchors_zero_bss(self):
        source=FixtureElf({'.bss':bytes(8)},symbols=[('errno',4,4,17,4)])
        row=self.locate(source,main=self.main_image(bss=bytes(8)),exports={'errno':0x4004})['.bss']
        self.assertEqual(row['base'],'0x4000')
        self.assertTrue(row['exact'])
    def test_sized_prodg_global_notype_anchors_zero_bss(self):
        source=FixtureElf({'.bss':bytes(4)},symbols=[('errno',0,4,16,4)])
        row=self.locate(source,main=self.main_image(bss=bytes(4)),exports={'errno':0x4000})['.bss']
        self.assertTrue(row['exact'])
    def test_local_object_name_cannot_anchor_zero_bss(self):
        source=FixtureElf({'.bss':bytes(8)},symbols=[('local',0,8,1,4)])
        row=self.locate(source,main=self.main_image(bss=bytes(8)),exports={'local':0x4000})['.bss']
        self.assertIsNone(row['base'])
    def test_global_object_anchor_must_be_in_same_section(self):
        source=FixtureElf({'.bss':bytes(8)},symbols=[('errno',0,8,17,4)])
        row=self.locate(source,main=self.main_image(bss=bytes(8)),exports={'errno':0x2000})['.bss']
        self.assertIsNone(row['base'])
    def test_unknown_data_relocation_blocks_exact_result(self):
        source=FixtureElf({'.data':bytes(4)},relocations={1:{0:(0,4,0)},3:{0:(1,26,0)}},
            symbols=[('',0,0,3,3),('missing',0,0,17,0)])
        target=FixtureElf(relocations={1:{0:(0,4,0)}},symbols=[('pointer',0,0,17,0)])
        row=self.locate(source,target,self.main_image(data=bytes(4)),{'pointer':0x3000})['.data']
        self.assertEqual(len(row['unresolved']),1)
        self.assertFalse(row['exact'])

if __name__=='__main__':
    unittest.main(verbosity=2)

