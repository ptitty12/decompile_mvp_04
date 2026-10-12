import struct,sys
d=open('C:/Users/Patrick Taylor/decompile_mvp_04-W5/build/GV4E69/main.dol','rb').read()
off=struct.unpack_from('>18I',d,0); addr=struct.unpack_from('>18I',d,0x48); size=struct.unpack_from('>18I',d,0x90)
def rd(a,n):
    for o,ad,sz in zip(off,addr,size):
        if sz and ad<=a<ad+sz: return d[o+a-ad:o+a-ad+n]
    return None
if __name__=='__main__':
    a=int(sys.argv[1],16); n=int(sys.argv[2]) if len(sys.argv)>2 else 16
    b=rd(a,n)
    print(b.hex() if b else None, repr(b))
