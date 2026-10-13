"""Synthetic compiler selection and generated C linkage tests."""
import os
import tempfile
import unittest
from pathlib import Path
import sys
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
import score_variants as score
class CompilerSelectionTests(unittest.TestCase):
    def fixture(self,name):
        tmp=tempfile.TemporaryDirectory();self.addCleanup(tmp.cleanup)
        root=Path(tmp.name);tool=root/'build/compilers/test';tool.mkdir(parents=True)
        (tool/(name+score.EXE)).write_text('synthetic executable path only')
        return root,tool
    def test_prodg_uses_ngccc_with_its_runtime_path(self):
        root,tool=self.fixture('ngccc')
        command,env=score.compiler_command({'mw_version':'test'},root=root)
        self.assertEqual(command,[str(tool/('ngccc'+score.EXE))])
        self.assertEqual(env['SN_NGC_PATH'],str(tool))
    def test_codewarrior_uses_its_actual_compiler(self):
        root,tool=self.fixture('mwcceppc')
        command,env=score.compiler_command({'mw_version':'test'},root=root)
        self.assertEqual(command,[str(tool/('mwcceppc'+score.EXE))])
        self.assertEqual(env,dict(os.environ))
    def test_missing_compiler_is_a_clear_failure(self):
        with tempfile.TemporaryDirectory() as tmp:
            with self.assertRaisesRegex(FileNotFoundError,'no ngccc or mwcceppc'):
                score.compiler_command({'mw_version':'test'},root=tmp)
class CLinkageTests(unittest.TestCase):
    def test_explicit_c_flags_strip_generated_cpp_linkage(self):
        text='extern "C" int function(void);\n  extern "C" int body(void) {return 1;}\n'
        for flags in ('-O4,p -lang=c','-lang c','-x c'):
            with self.subTest(flags=flags):
                self.assertEqual(score.c_source_text(text,flags),'int function(void);\n  int body(void) {return 1;}\n')
    def test_cpp_flags_keep_c_abi_annotations(self):
        text='extern "C" int function(void);\n'
        for flags in ('-O2 -G0','-x c++','-lang=c++'):
            self.assertEqual(score.c_source_text(text,flags),text)
    def test_string_contents_and_other_externs_are_preserved(self):
        text='const char* text = "extern \\"C\\" int function";\nextern int object;\n'
        self.assertEqual(score.c_source_text(text,'-lang=c'),text)
if __name__=='__main__':unittest.main(verbosity=2)
