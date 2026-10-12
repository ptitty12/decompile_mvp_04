/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803A81E0-0x803A8438 (code-only unit, 2 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include "snd/sndo.h"
#include "snd/cmn/sndcmn.h"

/* MVP's sample attribute block (older than nfsmw's SNDSAMPLEATTR): user data count at +0x17,
 * pointers at +0x34 and sizes at +0x44. */
struct SndUserDataAttr {
    char pad0[0x17];
    signed char numuserdata;
    char pad18[0x34 - 0x18];
    void* puserdata[4];
    int userdatasize[4];
};

extern "C" {

int fn_803A8648(int bhandle);
void* fn_803B1118(int a, int size);
int fn_803B11A8(int a, void* src, void* dst, int n);
int fn_803B11FC(int h);
void fn_803A93D0(int a, void* src, void* dst, int* p);

void fn_803A81E0(SndUserDataAttr* attr, int type)
{
    while (attr->numuserdata > 0) {
        SNDUSERDATACBINFO info;
        attr->numuserdata--;
        info.type = type;
        info.pdata = attr->puserdata[attr->numuserdata];
        info.size = attr->userdatasize[attr->numuserdata];
        for (int i = 0; i < sndgs.numuserdataclients; i++) {
            sndgs.userdataclient[i](&info);
        }
    }
}


int fn_803A82A8(int* phandle, BANKVER5* pb)
{
    sndgs.bankremove = fn_803A8648;
    int h = SNDBANKI_alloc();
    *phandle = h;
    BANKLIST* list = sndgs.banklist;
    int o = h * 12;
    reinterpret_cast<BANKLIST*>(reinterpret_cast<char*>(list) + o)->phdr = pb;
    BANKLIST* bl = reinterpret_cast<BANKLIST*>(reinterpret_cast<char*>(list) + o);
    bl->locked = 1;
    bl->pspuram = NULL;
    if (pb->spusize != 0) {
        bl->pspuram = fn_803B1118(0x200, pb->spusize + 0x30);
        if (bl->pspuram == NULL) {
            reinterpret_cast<BANKLIST*>(reinterpret_cast<char*>(list) + o)->phdr = NULL;
            bl->locked = 0;
            return -6;
        }
        int off = 0;
        while (off < pb->spusize) {
            int n = pb->spusize - off;
            if (n > 0x1000) {
                n = 0x1000;
            }
            int dh = fn_803B11A8(0x200, reinterpret_cast<char*>(pb) + pb->hdrsize + pb->iopcpusize + off,
                                 reinterpret_cast<char*>(bl->pspuram) + off, n);
            while (fn_803B11FC(dh) == 0) {
            }
            off += 0x1000;
        }
        int local = 0;
        int j;
        for (j = 0; j < pb->numpatches; j++) {
            if (pb->patch[j] != NULL) {
                fn_803A93D0(0x200, reinterpret_cast<char*>(&pb->patch[j]) + reinterpret_cast<int>(pb->patch[j]), bl->pspuram, &local);
            }
        }
    }
    bl->locked = 0;
    if (pb->spusize != 0 || pb->iopcpusize != 0) {
        return 7;
    }
    return 8;
}

}
