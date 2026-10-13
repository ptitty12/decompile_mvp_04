"""Compile-only MMIO tests: synthetic code, no hardware access or game data."""
import os
import struct
import subprocess
import tempfile
import unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
COMPILER=ROOT/'build/compilers/ProDG/3.9.3/ngccc.exe'
HEADER_ROOT=ROOT/'include'
@unittest.skipUnless(os.name=='nt' and COMPILER.is_file(),'ProDG Windows compiler not installed')
class GxFifoCodegenTests(unittest.TestCase):
    def test_register_views_reproduce_signed_displacement(self):
        with tempfile.TemporaryDirectory() as tmp:
            source=Path(tmp)/'fifo.cpp';obj=source.with_suffix('.o')
            source.write_text('''#include "ealib/gx_fifo.h"
union Pipe4 { unsigned word; float value; };
union Pipe8 { unsigned word; double value; };
extern "C" void store4(unsigned value) { EALIB_GX_FIFO(Pipe4).word=value; }
extern "C" void store8(unsigned value) { EALIB_GX_FIFO(Pipe8).word=value; }
''')
            env=dict(os.environ,SN_NGC_PATH=str(COMPILER.parent))
            result=subprocess.run([str(COMPILER),'-O2','-G0','-fno-rtti','-fno-exceptions','-I'+str(HEADER_ROOT),'-c',str(source),'-o',str(obj)],capture_output=True,text=True,env=env)
            self.assertEqual(result.returncode,0,result.stdout+result.stderr)
            import sys
            sys.path.insert(0,str(ROOT/'tools/match'))
            from check_literals import Elf
            elf=Elf(obj);ti=elf.text_index();code=elf.sec_bytes(ti)
            for name in ('store4','store8'):
                offset,size=elf.funcs(ti)[name]
                self.assertEqual(size,12,name)
                high,store,ret=struct.unpack_from('>III',code,offset)
                self.assertEqual(high>>26,15) # lis
                self.assertEqual(high&0xffff,0xcc01)
                self.assertEqual(store>>26,36) # stw
                self.assertEqual(store&0xffff,0x8000)
                self.assertEqual((high>>21)&31,(store>>16)&31)
                self.assertEqual(ret,0x4e800020) # blr
            self.assertFalse(any(name=='GXWGFifo' and not section for name,_,_,_,section in elf.syms))
if __name__=='__main__':unittest.main(verbosity=2)
