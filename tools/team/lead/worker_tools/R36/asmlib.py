import glob, os, re, sys
ROOT = (os.environ.get('WT') or os.getcwd()) + '/build/GV4E69/asm/fe/'
FN = re.compile(r"^\.fn (\S+), \w+$(.*?)^\.endfn \1$", re.S | re.M)
def funcs(unit):
    txt = open(ROOT+"tu_%s.s" % unit, encoding="utf-8").read()
    for m in FN.finditer(txt):
        yield m.group(1), m.group(2)
def ins(body):
    out=[]
    for l in body.splitlines():
        m = re.match(r"^/\* ([0-9A-F]{8}) [0-9A-F]+\s+([0-9A-F ]+) \*/\t(.*)$", l)
        if m: out.append((m.group(1), m.group(3)))
    return out
UNITS="804BE560 804BFB3C 804C19EC 804C3ECC 804C713C 804C931C 804CB430 804CE408".split()
SRCUNITS="8043FDC0 804439E4 80446CE8 80448E18 8044C508 8044F550 80452120 80455038 80459228 8045B134 8045EDDC 80462504 80464090 804654A0 8046C6F8 8046F770".split()
