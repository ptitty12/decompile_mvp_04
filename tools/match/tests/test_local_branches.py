import struct,sys,unittest
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import branch_targets as branch
import clone
class Fixture:
 def __init__(self,word,offset=0,relocation=None,symbol=None,address=0):
  self.code=bytes(offset)+struct.pack('>II',word,0x4e800020);self.offset=offset;self.address=address
  self.secs=[None,(None,None,None,address)];self.syms=[symbol or ('.text',address,0,3,1)];self.relocation=relocation
 def sec_bytes(self,index):return self.code
 def funcs(self,index):return {'fn_test':(self.offset+self.address,8)}
 def relocs(self,index):return {} if self.relocation is None else {self.offset:self.relocation}
class LocalBranchTests(unittest.TestCase):
 def targets(self,fixture):return branch.local_branch_destinations(fixture,1)['fn_test']
 def test_raw_forward_branch(self):self.assertEqual(self.targets(Fixture(0x41820004)),[4,None])
 def test_raw_backward_branch(self):
  fixture=Fixture(0x4bfffffc,offset=4);fixture.funcs=lambda index:{'fn_test':(0,12)};fixture.code=struct.pack('>III',0x60000000,0x4bfffffc,0x4e800020);self.assertEqual(self.targets(fixture),[None,0,None])
 def test_section_relocation_matches_resolved_word(self):self.assertEqual(self.targets(Fixture(0x41820000,offset=0x80,relocation=(0,11,0x84))),[4,None])
 def test_self_symbol_relocation_matches_resolved_word(self):self.assertEqual(self.targets(Fixture(0x48000000,offset=0x80,relocation=(0,10,4),symbol=('fn_test',0x80,8,2,1))),[4,None])
 def test_function_offset_is_not_added_twice(self):self.assertEqual(self.targets(Fixture(0x41820004,offset=0x80)),[4,None])
 def test_external_call_is_not_local(self):self.assertEqual(self.targets(Fixture(0x48000001,relocation=(0,10,0),symbol=('external',0,0,0,0))),[None,None])
 def test_outside_function_branch_is_not_local(self):self.assertEqual(self.targets(Fixture(0x41820008)),[None,None])
 def test_nonbranch_relocation_is_not_an_edge(self):self.assertEqual(self.targets(Fixture(0x38800000,relocation=(0,11,4))),[None,None])
 def test_nonzero_section_address(self):self.assertEqual(self.targets(Fixture(0x48000000,offset=0x80,relocation=(0,10,4),symbol=('fn_test',0x1080,8,2,1),address=0x1000)),[4,None])
 def test_absolute_branch(self):self.assertEqual(self.targets(Fixture(0x48000006)),[4,None])
 def test_different_local_edges_are_rejected(self):
  ours=[[0x41820000,'beq','fn_test',4]];theirs=[[0x41820004,'beq','',0]];self.assertIn('destination',clone.Cloner(None,None).compare(ours,theirs,'fn_test'))
 def test_relocation_and_resolved_edge_are_equal(self):
  ours=[[0x41820000,'beq','fn_test',4]];theirs=[[0x41820004,'beq','',4]];self.assertIsNone(clone.Cloner(None,None).compare(ours,theirs,'fn_test'))
if __name__=='__main__':unittest.main()
