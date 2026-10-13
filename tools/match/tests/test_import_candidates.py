import sys, unittest
from pathlib import Path
here = Path(__file__).resolve()
tools_match = here.parents[1]
if not (tools_match / "check_literals.py").is_file():
    tools_match = here.parents[2] / "tools" / "match"
sys.path.insert(0, str(tools_match))
import import_candidates as ic

class MiniElf:
    def __init__(self, names, funcs, relocs, syms):
        self.names, self.func_map, self.reloc_map, self.syms = names, funcs, relocs, syms
        self.secs = [(0,1,6,0,0,0x400,0,0,4,0) for _ in names]
    def funcs(self, i): return self.func_map.get(i,{})
    def relocs(self, i): return self.reloc_map.get(i,{})

class Tests(unittest.TestCase):
    def setUp(self):
        self.main=MiniElf([".text"],{}, {}, [
            ("providerA",0x80001000,32,0x12,1),
            ("providerA_alias",0x80001000,32,0x12,1),
            ("providerB",0x80002000,32,0x12,1)])
    def test_function_relative_offsets_and_conflicting_targets(self):
        s=MiniElf([".text"],{0:{"f1":(0x100,12),"f2":(0x220,12)}},
                  {0:{0x104:(0,10,0),0x228:(0,10,0)}},
                  [("old",0,0,0x12,0)])
        r=MiniElf([".text"],{0:{"f1":(0x40,12),"f2":(0x90,12)}},
                  {0:{0x44:(0,10,0),0x98:(1,10,0)}},
                  [("providerA",0,0,0x12,0),("providerB",0,0,0x12,0)])
        got=ic.paired_imports(s,r,self.main,{"old"},["f1","f2"],
                              {"providerA":0x80001000,"providerB":0x80002000})["old"]
        self.assertTrue(got["ambiguous"])
        self.assertEqual({x["address"] for x in got["retail_targets"]},{"0x80001000","0x80002000"})
        self.assertEqual({c["function"] for x in got["retail_targets"] for c in x["call_sites"]},{"f1","f2"})
    def test_unresolved_target_name(self):
        s=MiniElf([".text"],{0:{"f":(0,8)}},{0:{4:(0,10,0)}},[("old",0,0,0x12,0)])
        r=MiniElf([".text"],{0:{"f":(0,8)}},{0:{4:(0,10,0)}},[("unknown",0,0,0x12,0)])
        x=ic.paired_imports(s,r,self.main,{"old"},["f"],{})["old"]["retail_targets"][0]
        self.assertIsNone(x["address"]); self.assertEqual(x["retail_symbols"],["unknown"])
    def test_already_resolved_import_ignored(self):
        s=MiniElf([".text"],{0:{"f":(0,8)}},{0:{4:(0,10,0)}},[("present",0,0,0x12,0)])
        r=MiniElf([".text"],{0:{"f":(0,8)}},{0:{4:(0,10,0)}},[("providerA",0,0,0x12,0)])
        self.assertEqual(ic.paired_imports(s,r,self.main,set(),["f"],{"providerA":0x80001000}),{})
    def test_overlay_and_all_alias_names_preserved(self):
        s=MiniElf([".text",".feoverlay"],{1:{"over":(0x80,8)}},{},[("old",0,0,0x12,0)])
        r=MiniElf([".text",".feoverlay"],{1:{"over":(0x20,8)}},{},[("providerA",0,0,0x12,0)])
        s.reloc_map={1:{0x84:(0,10,0)}}; r.reloc_map={1:{0x24:(0,10,0)}}
        x=ic.paired_imports(s,r,self.main,{"old"},["over"],{"providerA":0x80001000})["old"]["retail_targets"][0]
        self.assertEqual(x["names"],["providerA","providerA_alias"])
        self.assertEqual(x["call_sites"],[{"function":"over","offset":4}])
    def test_unequal_function_sizes_are_not_paired(self):
        s=MiniElf([".text"],{0:{"f":(0,12)}},{0:{4:(0,10,0)}},["old",0,0,0x12,0])
        r=MiniElf([".text"],{0:{"f":(0,8)}},{0:{4:(0,10,0)}},[("providerA",0,0,0x12,0)])
        self.assertEqual(ic.paired_imports(s,r,self.main,{"old"},["f"],{"providerA":0x80001000}),{})
    def test_defined_same_section_target_resolves_with_addend(self):
        s=MiniElf([".text"],{0:{"caller":(0x100,8)}},{0:{0x104:(0,10,0)}},[("old",0,0,0x12,0)])
        r=MiniElf([".text"],{0:{"caller":(0x40,8),"providerLocal":(0x150,8)}},
                  {0:{0x44:(1,10,4)}},[("caller",0x40,8,0x12,0),("providerLocal",0x150,8,0x12,0)])
        main=MiniElf([".text"],{}, {},[("providerInterior",0x80000154,4,0x12,1)])
        got=ic.paired_imports(s,r,main,{"old"},["caller"],
                              {"caller":0x80000040,"providerLocal":0x80000150})
        target=got["old"]["retail_targets"][0]
        self.assertEqual(target["address"],"0x80000154")
        self.assertEqual(target["names"],["providerInterior"])
    def test_non_rel24_is_ignored(self):
        s=MiniElf([".text"],{0:{"f":(0,8)}},{0:{4:(0,4,0)}},[("old",0,0,0x12,0)])
        r=MiniElf([".text"],{0:{"f":(0,8)}},{0:{4:(0,10,0)}},[("providerA",0,0,0x12,0)])
        self.assertEqual(ic.paired_imports(s,r,self.main,{"old"},["f"],{"providerA":0x80001000}),{})

if __name__=="__main__": unittest.main(verbosity=2)




