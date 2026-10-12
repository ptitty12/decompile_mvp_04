import sys, os, re, subprocess, tempfile
WT = (os.environ.get('WT') or os.getcwd())
objdump = WT + '/build/binutils/powerpc-eabi-objdump.exe'
ngccc = WT + '/build/compilers/ProDG/3.9.3/ngccc.exe'
env = dict(os.environ); env['SN_NGC_PATH'] = (WT + '/build/compilers/ProDG/3.9.3').replace('/', chr(92))
FLAGS = '-O2 -G0 -fno-strength-reduce -fno-strict-aliasing -ffast-math -mps-float -x c++ -Iinclude -Iinclude/libc -Isrc -DEA_PLATFORM_GAMECUBE -DGEKKO'.split()
def funcs(obj):
    out = subprocess.run([objdump, '-d', '-r', obj], capture_output=True, text=True).stdout
    res, cur = {}, None
    for line in out.splitlines():
        m = re.match(r'^[0-9a-f]+ <(.+)>:$', line)
        if m: cur = m.group(1); res[cur] = []; continue
        if cur is None: continue
        m = re.match(r'^\s+[0-9a-f]+:\s+((?:[0-9a-f]{2} ){4})\s*(.*)$', line)
        if m: res[cur].append([int(m.group(1).replace(' ', ''), 16), '']); continue
        m = re.match(r'^\s+[0-9a-f]+: (R_PPC_\w+)\s+(\S+)', line)
        if m and res[cur]: res[cur][-1][1] = m.group(2)
    return res
def mask(w, rl):
    op = w >> 26
    if op == 16: return w & 0xFFFF0003
    if op == 18: return w & 0xFC000003
    if rl: return w & 0xFFE00000 if op in (14, 15) else w & 0xFFFF0000
    return w
class Ctx:
    def __init__(self, unit, func):
        self.unit, self.func = unit, func
        self.target_obj = WT + '/build/GV4E69/obj/%s.o' % unit
        self.src_path = WT + '/src/%s.cpp' % unit
        self.src = open(self.src_path).read()
        self.tm = [mask(w, r) for w, r in funcs(self.target_obj)[func]]
        cname = func.split('__')[0] if '__' in func and not func.startswith('fn_') else func
        self.cname = cname
        m = re.search(r'^[^\n/]*\b%s\([^\n;]*\)[^\n;]*\n\{\n.*?^\}\n' % re.escape(cname), self.src, re.S | re.M)
        assert m, 'function not found in source'
        self.defn = m.group(0)
        self.tmpd = tempfile.mkdtemp()
    def compile(self, text):
        new = self.src.replace(self.defn, text.rstrip('\n') + '\n')
        o = os.path.join(self.tmpd, 's.o')
        vp = WT + '/src/%s__vt%d.cpp' % (self.unit, os.getpid())
        open(vp, 'w').write(new)
        if os.path.exists(o): os.remove(o)
        r = subprocess.run([ngccc] + FLAGS + ['-c', 'src/%s__vt%d.cpp' % (self.unit, os.getpid()), '-o', o], capture_output=True, text=True, env=env, cwd=WT)
        os.remove(vp)
        if r.returncode or not os.path.exists(o):
            return None, (r.stdout + r.stderr)[-800:]
        return funcs(o).get(self.func), ''
    def score(self, text):
        f, err = self.compile(text)
        if f is None: return -99
        bm = [mask(w, r_) for w, r_ in f]
        if bm == self.tm: return len(self.tm)
        import difflib
        sm = difflib.SequenceMatcher(None, self.tm, bm, autojunk=False)
        pos = sum(1 for a, b in zip(self.tm, bm) if a == b)
        return round(sum(b.size for b in sm.get_matching_blocks()) * 0.5 + pos * 0.5 - 0.01 * abs(len(self.tm) - len(bm)) - (0.5 if bm != self.tm and len(bm)==len(self.tm) and False else 0), 2) if bm != self.tm else len(self.tm)
