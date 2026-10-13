from pathlib import Path
import sys,unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import clone
class TwinTopologyTests(unittest.TestCase):
 def function(self,addr,raw):return clone.Fn('main/test',addr,'fn_%08X'%addr,raw)
 def test_equal_relative_targets_are_twins(self):
  a=self.function(0x1000,['beq .L_00001178','bl fn_80001234']);b=self.function(0x2000,['beq .L_00002178','bl fn_80005678']);self.assertEqual(a.shape,b.shape)
 def test_distinct_local_targets_are_not_twins(self):
  a=self.function(0x1000,['beq .L_00001178']);b=self.function(0x2000,['beq .L_00002158']);self.assertNotEqual(a.shape,b.shape)
 def test_backward_local_targets_preserve_offsets(self):
  a=self.function(0x1000,['b .L_00000FFC']);b=self.function(0x2000,['b .L_00001FFC']);self.assertEqual(a.shape,b.shape);self.assertIn('L-0x4',a.shape[0])
 def test_external_names_still_remap(self):
  a=self.function(0x1000,['lis r9,lbl_80001234@ha','bl fn_80005678']);b=self.function(0x2000,['lis r9,lbl_80004321@ha','bl fn_80008765']);self.assertEqual(a.shape,b.shape)
if __name__=='__main__':unittest.main()
