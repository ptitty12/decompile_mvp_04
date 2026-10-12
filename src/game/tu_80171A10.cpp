/*
 * Game code, .text 0x80171A10-0x80174318 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80171A10.h"
#include "game/tu_80170044.h"

extern "C" Unk80170518* fn_80005840(int mode);

/* Popup holder (see Unk80171940 in tu_80170044.h): the dialog at +0 and the current popup at +4. */
struct Unk80171A10_Holder {
    Unk80170B44* m0;
    Unk80171760* m4;
};

void fn_80171FE8(Unk80171A10_Holder* h);

void fn_801728E8(Unk80171A10_Menu* p);

void fn_801726E8(Unk80171A10_Menu* p);

void fn_801748D8(Unk801748D8_Obj* o);

Unk801714E0* fn_80172058(Unk80171A10_Holder* h, const unsigned short* s, int a);

void fn_801720A8(Unk80171A10_Holder* h, Unk801714E0* n, const unsigned short* s, int id);

Unk80171760* fn_80171A10(Unk80171A10_Holder* h, int a)
{
    fn_80171FE8(h);
    h->m4 = new (0x100) Unk80171760;
    h->m4->fn_801718A8(0);
    h->m4->fn_8017181C(0);
    h->m4->m8 = 0;
    h->m4->m4 = 0;
    h->m4->m0 = a;
    return h->m4;
}

/* near-miss: retail stores the zero text terminator through r3 (li r3,0; sth) and then reloads r3 with the
 * holder; here it goes through r0 (26 vs 27 instrs). */
Unk80171760* fn_80171A8C(Unk80171A10_Holder* h, const unsigned short* s)
{
    unsigned short z = 0;
    fn_80171FE8(h);
    Unk801714E0* n = fn_80172058(h, &z, 4);
    if (n) {
        fn_801720A8(h, n, s, 1);
    }
    return h->m4;
}

/* near-miss: retail keeps the zero for m8/m0 in r30 across the calls (3 saved registers, the CE4 result
 * reuses r30); here the zero is rematerialized (r11). 4 variants tried. */
Unk80171760* fn_80171C20(Unk80171A10_Holder* h, int a)
{
    if (a != 0x11) {
        fn_80171FE8(h);
        h->m4 = new (0x100) Unk80171760;
        h->m4->fn_801718A8(0);
        h->m4->m4 = 1;
        h->m4->m8 = 0;
        h->m4->m0 = 0;
        h->m4->fn_8017181C((const unsigned short*)h->m0->fn_80170CE4(a));
        return h->m4;
    }
    return 0;
}

extern int lbl_805CB260[][6];

Unk80171760* fn_80171CC0(Unk80171A10_Holder* h, int a, int rev)
{
    Unk801714E0* n = 0;
    int first = 0;
    int i = 0;
    do {
        int k = rev ? 5 - i : i;
        if (lbl_805CB260[a][k] != 0) {
            if (first == 0) {
                first = 1;
                fn_80171FE8(h);
            }
            n = fn_80172058(h, (const unsigned short*)h->m0->fn_80170C6C(k), k);
        }
        i++;
    } while (i <= 5);
    if (n != 0) {
        fn_801720A8(h, n, (const unsigned short*)h->m0->fn_80170CA8(a), 1);
    }
    return h->m4;
}

Unk80171760* fn_80171F80(Unk80171A10_Holder* h, const unsigned short* s)
{
    fn_80171FE8(h);
    Unk801714E0* n = fn_80172058(h, s, 0);
    fn_801720A8(h, n, (const unsigned short*)h->m0->fn_80170CE4(0xF), 2);
    return h->m4;
}

void fn_80171FE8(Unk80171A10_Holder* h)
{
    if (h->m4 != 0) {
        h->m4->fn_801718A8(0);
        if (h->m4 != 0) {
            delete h->m4;
            h->m4 = 0;
        }
    }
    fn_801715F8();
}

Unk801714E0* fn_80172058(Unk80171A10_Holder* h, const unsigned short* s, int a)
{
    Unk801714E0* n = new (0x100) Unk801714E0;
    n->fn_8017158C(s);
    n->m8 = a;
    return n;
}

void fn_801720A8(Unk80171A10_Holder* h, Unk801714E0* n, const unsigned short* s, int id)
{
    h->m4 = new (0x100) Unk80171760;
    h->m4->m0 = id;
    h->m4->fn_801718A8((int)lbl_8061C66C);
    h->m4->m4 = 1;
    h->m4->fn_8017181C(s);
}

void fn_80172118() {}

void fn_8017211C() {}

Unk80171A10_Menu::~Unk80171A10_Menu()
{
    fn_801748D8((Unk801748D8_Obj*)m6C);
    m6C = 0;
    fn_80172678(this);
    if (m3C) {
        delete m3C;
        m3C = 0;
    }
}

void fn_80172624(Unk80171A10_Menu* self);
int fn_80174850();

Unk80171A10_Menu::Unk80171A10_Menu()
{
    for (unsigned int i = 0; i < 1; i++) {
        m0[i] = 0;
    }
    for (int i = 0; i < 4; i++) {
        m8[i] = 0;
    }
    m3C = new (0x100) Unk80171940;
    mA4[0] = 0;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    m4C = 0;
    m50 = 0;
    m54 = 0;
    m58 = 0;
    m5C = 0;
    m118 = 0;
    m114 = -1;
    m11C = 0x15;
    m6C = (void*)fn_80174850();
    fn_80172624(this);
}

void fn_8017227C(Unk8017227C_T* p, int a, int b, int i)
{
    p->m1C[i].m0 = a;
    p->m1C[i].m4 = b;
}

extern const Unk80171A10_Fn lbl_805CB114;

extern const Unk80171A10_Fn lbl_805CB11C;

extern const Unk80171A10_Fn lbl_805CB13C;

extern const Unk80171A10_Fn lbl_805CB144;

extern const Unk80171A10_Fn lbl_805CB134;

extern const Unk80171A10_Fn lbl_805CB14C;

extern const Unk80171A10_Fn lbl_805CB154;

extern const Unk80171A10_Fn lbl_805CB174;

extern const Unk80171A10_Fn lbl_805CB18C;

extern const Unk80171A10_Fn lbl_805CB1A4;

extern const Unk80171A10_Fn lbl_805CB1AC;

extern const Unk80171A10_Fn lbl_805CB1BC;

void fn_80172294(Unk80171A10_Menu* p, int a, const unsigned short* s)
{
    p->m64 = a;
    if (s) {
        fn_80403144(p->mDA, s);
    } else {
        p->mDA[0] = (unsigned short)(int)s;
    }
}

void fn_801722D0(Unk80171A10_Menu* p)
{
    p->m118 = 0;
    ((Unk80171A10_Svc*)fn_80173274((Unk80173274_T*)p))->mC4 = 1;
    fn_80174318(p, 0, lbl_805CB114);
}

void fn_80172334(Unk80171A10_Menu* p, int a, int b, const unsigned short* c, const char* d)
{
    p->m68 = a;
    p->m60 = 0;
    p->m4 = 0;
    fn_8040B61C(p->m88, d);
    fn_80172294(p, b, c);
    fn_80174318(p, 0, lbl_805CB114);
}

Unk80171760* fn_801723B8(Unk80171A10_Menu* p)
{
    fn_80171FE8((Unk80171A10_Holder*)(void*)p->m3C);
    fn_801726E8(p);
    return ((Unk80171A10_Holder*)(void*)p->m3C)->m4;
}

int fn_80172514(Unk80171A10_Menu* p)
{
    if (p->m70 <= 0xA) {
        fn_80174318(p, 1, lbl_805CB11C);
    }
    return 0;
}

void fn_80172564(Unk80171A10_Menu* p, const unsigned short* s)
{
    int f = 0;
    if (s != 0 && fn_80403060(s) > 0) {
        f = 1;
    }
    p->m54 = f;
    if (f != 0) {
        fn_80403144(p->mA4, s);
    }
}

int fn_801725C4(Unk80171A10_Menu* p, const unsigned short* s)
{
    if (p->m60 == 2) {
        if (s != 0) {
            fn_80403144(p->mA4, s);
            p->m60 = 0;
            return 1;
        }
        p->mA4[0] = -1;
    }
    return 0;
}

void fn_80172624(Unk80171A10_Menu* self) /* 80172624 */
{
    int i = 0;
    Unk80170518** p = (Unk80170518**)self;
    fn_80172678(self);
    do {
        Unk80170518* o = fn_80005840(i);
        *p = o;
        i++;
        p++;
        o->m64 = (Unk80170518_Svc*)self->m6C;
    } while (i == 0);
}

void fn_80172678(Unk80171A10_Menu* p)
{
    fn_801743E0(p);
    fn_80174438(p);
    fn_801744AC(p);
    p->m70 = 0x19;
    p->m7C = 0x19;
    p->m74 = 0;
    p->m80 = 0;
    p->m4 = 1;
    p->m18 = 4;
}

void fn_801728A0(Unk80171A10_Menu* p, Unk8016FF40* info, int st)
{
    p->m110 = st;
    fn_801728E8(p);
    ((Unk80170518*)fn_80173274((Unk80173274_T*)p))->fn_80170668(info, p->m110);
}

void fn_80172D00(Unk80171A10_Menu* p)
{
    int t = p->m4 + 1;
    p->m4 = t;
    if (t > 0) {
        p->m4 = 0;
    }
    fn_801728A0(p, 0, 4);
}

/* near-miss: retail sets i (li r29,0) before the first call's argument moves and the scaled index (li r28,0)
 * right before that call; here both come after the argument moves (6 slots, 95.6%). */
int fn_801730E8(Unk80171A10_Menu* p, unsigned short* s, int* out)
{
    Unk8016FF40 info;
    unsigned int i = 0;
    fn_801701B4(&info, p->mDA, p->m64);
    fn_80170158(&info, s);
    fn_8017008C(&info, p->m88);
    ((Unk80170518*)fn_80173274((Unk80173274_T*)p))->fn_80005A7C(&info);
    for (i = 0; i <= 3; i++) {
        if (((Unk8016FF40*)p->m8[i])->fn_80170218(&info) != 0 && i != p->m18) {
            if (out != 0) {
                *out = i;
            }
            return 1;
        }
    }
    return 0;
}

int fn_801731D8(Unk80171A10_Menu* p, int idx)
{
    int id;
    switch (idx) {
    case 5: id = 5; break;
    case 6: id = 0xB; break;
    case 7: id = 0x11; break;
    case 8: id = 0xA; break;
    case 9: id = 0xD; break;
    default: id = 0x15; break;
    }
    if (id != 0x15) {
        fn_80172B60(p, id, 8);
        return 1;
    }
    return 0;
}

int fn_80173274(Unk80173274_T* p)
{
    int idx = p->m4;
    if (idx != 0) {
        return p->m0;
    }
    return *(int*)((char*)p + idx);
}

void fn_80173290(Unk80171A10_Menu* p)
{
    fn_80174438(p);
    p->m4 = 1;
    fn_80174318(p, 3, lbl_805CB134);
}

void fn_801732EC(Unk80171A10_Menu* p)
{
    fn_80172D00(p);
    if (p->m68 == 3) {
        fn_80174318(p, 4, lbl_805CB13C);
    } else {
        fn_80174318(p, 4, lbl_805CB144);
    }
}

/* near-miss: retail shares one tail call between the m40 path and the 805CB14C path (50 instrs); the
 * goto and pointer-variable spellings tried are 11+ slots off. */
void fn_80173378(Unk80171A10_Menu* p)
{
    p->m60 = 1;
    if (fn_80172D44(p, 0) == 0) {
        if (p->m40 != 0) {
            fn_80174318(p, 1, lbl_805CB11C);
            return;
        }
        if (((Unk80171A10_Svc*)fn_80173274((Unk80173274_T*)p))->mC4 == 0) {
            fn_80174318(p, 1, lbl_805CB11C);
            return;
        }
    }
    fn_80174318(p, 7, lbl_805CB14C);
}

extern const Unk80171A10_Fn lbl_805CB15C;

extern const Unk80171A10_Fn lbl_805CB154;

void fn_80173440(Unk80171A10_Menu* p)
{
    Unk8016FF40 info;
    for (int i = 1; i < 4; i++) {
        Unk8016FF40_Entry* v = (Unk8016FF40_Entry*)&p->m1C[i];
        info.m108[i] = v;
    }
    int r;
    if (p->m50 > 0) {
        r = p->m0[0]->fn_8000850C(p->m50);
    } else {
        r = p->m0[0]->fn_80005B88(&info);
    }
    int t = p->m0[0]->m34;
    fn_801728E8(p);
    if (t < r) {
        fn_80172B60(p, 1, 8);
    }
    fn_80174318(p, 0x14, lbl_805CB154);
}

void fn_80173534(Unk80171A10_Menu* p)
{
    fn_80174348(p);
    p->m18 = 4;
    if (p->m58 == 0) {
        ((Unk80170518*)fn_80173274((Unk80173274_T*)p))->fn_80170780((int)p->m8, 4, p->mDA, p->m64);
    }
    fn_80171C20((Unk80171A10_Holder*)(void*)p->m3C, p->m70);
    fn_80174318(p, 0xA, lbl_805CB15C);
}

void fn_80173A24(Unk80171A10_Menu* p)
{
    fn_80172B60(p, 7, 1);
    fn_80174318(p, 0xF, lbl_805CB174);
}

void fn_80173A80(Unk80171A10_Menu* p)
{
    fn_80172B60(p, 0xF, 0);
    fn_80174318(p, 0x11, lbl_805CB18C);
}

void fn_80173ADC(Unk80171A10_Menu* p)
{
    fn_80174318(p, 0x11, lbl_805CB18C);
}

void fn_80173B1C(Unk80171A10_Menu* p)
{
    Unk8016FF40 info;
    for (int i = 1; i < 4; i++) {
        Unk8016FF40_Entry* v = (Unk8016FF40_Entry*)&p->m1C[i];
        info.m108[i] = v;
    }
    fn_80174318(p, 0xF, lbl_805CB174);
}

void fn_80173BA4(Unk80171A10_Menu* p, unsigned short* buf)
{
    if (p->m48 != 0) {
        if (p->m64 == 0x11) {
            fn_80403144(buf, (const unsigned short*)fn_80090880(lbl_8061977C, 0x61C));
            return;
        }
        fn_80403144(buf, p->mDA);
    }
}

void fn_80173DF4(Unk80171A10_Menu* p)
{
    if (p->m5C != 0) {
        int v = 8;
        if (p->m64 == 0x200000) {
            v = 9;
        }
        fn_80172B60(p, v, 8);
        fn_80174318(p, 1, lbl_805CB11C);
    } else {
        fn_801728A0(p, (Unk8016FF40*)p->m8[p->m18], 3);
        fn_80174318(p, 0x11, lbl_805CB18C);
    }
}

void fn_80173EBC(Unk80171A10_Menu* p)
{
    fn_80174318(p, 0x15, lbl_805CB1A4);
}

void fn_80173EFC(Unk80171A10_Menu* p)
{
    fn_80174318(p, 0x12, lbl_805CB1AC);
}

void fn_80174080(Unk80171A10_Menu* p)
{
    fn_80172B60(p, 0x10, 8);
    fn_80174318(p, 0x13, lbl_805CB1BC);
}

extern const Unk80171A10_Fn lbl_805CB1C4;

void fn_801740DC(Unk80171A10_Menu* p)
{
    fn_801728A0(p, (Unk8016FF40*)p->m8[p->m18], 2);
    fn_80174318(p, 0x15, lbl_805CB1C4);
    ((Unk80171A10_Holder*)(void*)p->m3C)->m0->fn_80170D20(2);
    ((Unk80171A10_Holder*)(void*)p->m3C)->m0->fn_80170EC4(((Unk8016FF40*)p->m8[p->m18])->m8E);
}

void fn_80174170(Unk80171A10_Menu* p)
{
    fn_80172B60(p, 0x14, 2);
    fn_80174318(p, 0, lbl_805CB114);
}

void fn_801741CC(Unk80171A10_Menu* p)
{
    if (((Unk80171A10_Svc*)fn_80173274((Unk80173274_T*)p))->mC4 != 0) {
        fn_80174318(p, 0x14, lbl_805CB154);
        if (p->m44 == 0) {
            fn_80172B60(p, 0x14, 8);
        }
    } else {
        fn_80174318(p, 1, lbl_805CB11C);
    }
}

void fn_80174274(Unk80174274_T* p)
{
    fn_80171A10(p->m3C, 5);
}

void fn_8017429C(Unk80174274_T* p)
{
    fn_80171A10(p->m3C, 6);
}

/* near-miss: native PTMF members give retail's separate zero registers; 3 slots of store order differ. */
void fn_801742C4(Unk80171A10_Menu* p)
{
    int t = p->m54;
    p->m60 = 0;
    p->m114 = -1;
    if (t == 0) {
        p->mA4[0] = (unsigned short)t;
    }
    p->m70 = p->m7C;
    p->m7C = 0x19;
    p->m74 = p->m80;
    p->m80 = 0;

}
