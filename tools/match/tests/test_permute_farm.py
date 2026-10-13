"""Farm input invalidation and source restoration; synthetic files only."""
import subprocess
import sys
import tempfile
import types
import unittest
from pathlib import Path
from unittest.mock import Mock,patch
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import permute_farm as farm
import score_variants as score
class FarmInputTests(unittest.TestCase):
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory();self.addCleanup(self.tmp.cleanup)
        self.root=Path(self.tmp.name);self.source=self.root/'src/unit.cpp'
        self.source.parent.mkdir();(self.root/'include').mkdir()
        self.source.write_text('#include "a.h"\nint function(void){return 1;}\n')
        (self.source.parent/'a.h').write_text('#include <b.h>\n')
        (self.root/'include/b.h').write_text('#include "../src/a.h"\n#define VALUE 1\n')
        helper=self.root/'tools/match';helper.mkdir(parents=True)
        for name in ('permute.py','cxx2c.py','score_variants.py'):(helper/name).write_text(name)
        self.flags={'cflags':'-Iinclude -O2','mw_version':'ProDG/3.9.3'}
        self.addCleanup(patch.stopall)
        patch.object(farm,'FARM',self.root).start()
        patch.object(farm,'ninja_vars',side_effect=lambda unit,root=None:dict(self.flags)).start()
    def key(self):return farm.input_fingerprint('unit',self.source,farm.helper_fingerprint())
    def test_recursive_header_and_cycle(self):
        first=self.key();(self.root/'include/b.h').write_text('#define VALUE 2\n')
        self.assertNotEqual(first,self.key())
    def test_helper_change_invalidates_unchanged_source(self):
        first=self.key();(self.root/'tools/match/permute.py').write_text('fixed extraction')
        self.assertNotEqual(first,self.key())
    def test_unit_flags_invalidate_unchanged_source(self):
        first=self.key();self.flags['cflags']+=' -fno-builtin'
        self.assertNotEqual(first,self.key())
    def test_unrelated_docs_do_not_invalidate(self):
        first=self.key();(self.root/'notes.md').write_text('a progress update')
        self.assertEqual(first,self.key())
    def test_newly_resolved_include_invalidates(self):
        self.source.write_text('#include "missing.h"\nint function(void){return 1;}')
        first=self.key();(self.root/'include/missing.h').write_text('/* now available */')
        self.assertNotEqual(first,self.key())
class FarmRestorationTests(unittest.TestCase):
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory();self.addCleanup(self.tmp.cleanup)
        self.root=Path(self.tmp.name);self.src=self.root/'src/unit.cpp';self.src.parent.mkdir()
        self.raw=b'int function(void)\r\n{\r\n    return 1;\r\n}\r\n';self.src.write_bytes(self.raw)
        self.cand=self.root/'candidate.c';self.cand.write_text('int function(void){return 2;}')
        self.run=self.root/'run';self.run.mkdir();(self.run/'settings.toml').write_text('func_name = "function"')
        self.commands=[];self.dirty=False;self.fail=False
        def shell(cmd,**kwargs):
            self.commands.append(cmd)
            if cmd[:2]==['git','diff'] and '--quiet' in cmd:return subprocess.CompletedProcess(cmd,int(self.dirty),'','')
            if 'ninja' in Path(str(cmd[0])).name and self.fail:raise RuntimeError('synthetic compiler error')
            return subprocess.CompletedProcess(cmd,0,'synthetic patch','')
        self.addCleanup(patch.stopall)
        patch.object(farm,'FARM',self.root).start();patch.object(farm,'unit_source',return_value=self.src).start()
        patch.object(farm,'sh',side_effect=shell).start();patch.object(farm,'log',Mock()).start()
        patch.dict(sys.modules,{'permute':types.SimpleNamespace(disasm=lambda *args:([1],{}))}).start()
    def apply(self):return farm.apply_match({'unit':'unit','fn':'function'},self.cand,self.run)
    def test_success_restores_original_crlf_bytes(self):
        self.assertEqual(self.apply()['status'],'matched');self.assertEqual(self.src.read_bytes(),self.raw)
        self.assertFalse(any(cmd[:2]==['git','checkout'] for cmd in self.commands))
    def test_compile_failure_restores_original_bytes(self):
        self.fail=True
        with self.assertRaisesRegex(RuntimeError,'synthetic'):self.apply()
        self.assertEqual(self.src.read_bytes(),self.raw)
    def test_dirty_source_is_refused_without_writing(self):
        self.dirty=True;self.assertEqual(self.apply()['status'],'mismatch')
        self.assertEqual(self.src.read_bytes(),self.raw)
        self.assertEqual(len(self.commands),1)
class NinjaRootTests(unittest.TestCase):
    def test_flags_can_be_read_from_another_farm_root(self):
        with tempfile.TemporaryDirectory() as tmp:
            root=Path(tmp);out=Path('build/GV4E69/src/unit.o')
            (root/'build.ninja').write_text('build '+str(out)+': cc src/unit.cpp\n  cflags = -O2 -Iinclude\n  mw_version = ProDG/3.9.3\n')
            self.assertEqual(score.ninja_vars('unit',root=root)['cflags'],'-O2 -Iinclude')
    def test_returned_variables_do_not_mutate_cached_flags(self):
        with tempfile.TemporaryDirectory() as tmp:
            root=Path(tmp);out=Path('build/GV4E69/src/unit.o')
            (root/'build.ninja').write_text('build '+str(out)+': cc src/unit.cpp\n  cflags = -O2\n')
            score.ninja_vars('unit',root=root)['cflags']='changed locally'
            self.assertEqual(score.ninja_vars('unit',root=root)['cflags'],'-O2')
    def test_changed_file_invalidates_parsed_variables(self):
        with tempfile.TemporaryDirectory() as tmp:
            root=Path(tmp);out=Path('build/GV4E69/src/unit.o');path=root/'build.ninja'
            path.write_text('build '+str(out)+': cc src/unit.cpp\n  cflags = -O2\n')
            score.ninja_vars('unit',root=root)
            path.write_text('build '+str(out)+': cc src/unit.cpp\n  cflags = -Os\n')
            self.assertEqual(score.ninja_vars('unit',root=root)['cflags'],'-Os')
if __name__=='__main__':unittest.main(verbosity=2)
