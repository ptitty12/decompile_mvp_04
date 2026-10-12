/*
 * Game code, .text 0x80206B08-0x8020ADC4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801EE438.h"

typedef Unk801EE438_Scr Scr;

extern "C" {
}

extern "C" void fn_802087CC(Scr* p)
{
    Unk801EE438_It it;
    fn_8014E09C(&it, p->m0->m0, 1);
    Unk801EE438_It* ip = &it;
    while (ip->m8 != 10) {
        fn_802049E8(&p->m0->m6B8[ip->m8]);
        fn_8014E108(ip);
    }
}

inline Unk801EE438_Sub2B4* Sub2B4Of(Scr* p)
{
    return &p->m0->m2B4;
}

extern float lbl_805D5840;

extern "C" void fn_8020D5D4(void* p);
extern "C" int fn_802054E0(Unk801EE438_G* g, float f);
extern const float lbl_805D57D4;
extern const float lbl_805D57D8;
extern const float lbl_805D57DC;

struct Unk80208B90_Rec {
    char pad0[0xC];
    float mC;
    float m10;
    int m14;
    int m18;
    int m1C;
    int m20;
};

extern "C" void fn_80208B90(Scr* p, int a, int b, int c, Unk80208B90_Rec* r)
{
    r->m20 = 0;
    fn_8020D5D4((char*)p->m0 + 0x2C);
    if (r->m14 != 0) {
        r->m20 = fn_802054E0(p->m0, r->mC);
        if (r->m20 == 0) {
            r->m1C = 0;
            float t = r->mC - lbl_805D57D4;
            t = t >? lbl_805D57D8;
            if (fn_802054E0(p->m0, t) != 0)
                r->m1C = 1;
        }
    }
    r->m18 = 0;
    if (!(r->m10 >= lbl_805D57D8 || r->m10 <= lbl_805D57DC))
        r->m18 = 1;
}

extern "C" void fn_802099F8(Scr* p, int a)
{
    Unk801EE438_G* g = p->m0;
    int t = g->m3A6C;
    if (g->m2B4.m2AC != t) {
        g->m2B4.m2AC = t;
        fn_80212054(&p->m0->m2B4);
        Unk801EE438_G* h = p->m0;
        h->m2B4.m0 = (float)h->m0->m4C * lbl_805D5840;
        fn_80209AC0(p, a);
        fn_80209EEC(p, a);
        fn_8020A654(p, a);
        fn_8020A90C(p, a);
        fn_8020B00C(p, a);
    }
}

extern "C" int fn_80209E74(Scr* p)
{
    for (int i = 12; i > 8; i--) {
        Unk801EE438_Rec2C* r = &Sub2B4Of(p)->m128[i];
        if ((unsigned)(i - 9) > 3)
            r = 0;
        if (r->m24 != 0)
            return i;
    }
    return -1;
}

extern "C" int fn_80209EC4(Unk801EE438_Ent* a, Unk801EE438_Ent* b)
{
    int d = a->m4 - b->m4;
    if (d < 0)
        return -1;
    if (d > 0)
        return 1;
    return 0;
}
