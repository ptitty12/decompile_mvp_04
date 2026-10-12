/*
 * Game code, .text 0x80171A10-0x80174318 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80171A10.h"
#include "game/tu_80170044.h"

extern "C" Unk80170518* fn_80005840(int mode);
extern "C" int fn_804030C8(const unsigned short* a, const unsigned short* b);

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

Unk80171760* fn_80171AF8(Unk80171A10_Holder* h, const unsigned short* s, const unsigned short* a, const unsigned short* b, const unsigned short* c, const unsigned short* d) /* 80171AF8 */
{
    Unk801714E0* n = 0;
    fn_80171FE8(h);
    int flag = 0;
    for (int i = 0; i <= 5; i++) {
        int k = i + 0xA;
        if (a != 0 && k == 0xA) {
            n = fn_80172058(h, a, 0xA);
        } else if (b != 0 && k == 0xB) {
            n = fn_80172058(h, b, 0xB);
        } else if (c != 0 && k == 0xC) {
            n = fn_80172058(h, c, 0xC);
        } else if (d != 0 && k == 0xD) {
            n = fn_80172058(h, d, 0xD);
        }
    }
    if (n == 0) {
        unsigned short z = 0;
        flag = 1;
        n = fn_80172058(h, &z, 4);
        if (n == 0) {
            goto done;
        }
    }
    fn_801720A8(h, n, s, 1);
done:
    h->m4->m8 = flag;
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

Unk80171760* fn_80171D98(Unk80171A10_Holder* h, Unk8016FF40** infos, int count, int a3, const unsigned short* a4, int a5, int a6, int a7) /* 80171D98 */
{
    Unk801714E0* n = 0;
    int found = 0;
    const unsigned short* tmpl = (const unsigned short*)fn_80090880(lbl_8061977C, 0x650);
    int i = 0;
    unsigned short buf[0x100];
    fn_80171FE8(h);
    if (count > 0) {
        int off = 0;
        do {
            if ((*(Unk8016FF40**)(off + (int)infos))->fn_80170044(a3) != 0
                || (*(Unk8016FF40**)(off + (int)infos))->fn_80170248() != 0) {
                Unk8016FF40* info = *(Unk8016FF40**)(off + (int)infos);
                found = 1;
                unsigned short* nm = info->m78;
                char* q = (char*)info + 0x50;
                if (fn_804030C8(nm, tmpl) == 0 || (*(Unk8016FF40**)(off + (int)infos))->fn_80170248() != 0) {
                    fn_80403144(buf, tmpl);
                } else {
                    h->m0->fn_80170EC4(info->m8E);
                    h->m0->fn_80170EF8(nm);
                    h->m0->fn_80170F2C(0, *(int*)(q + 0x20), 0);
                    fn_80403144(buf, (const unsigned short*)h->m0->fn_80170C30(4));
                }
                n = fn_80172058(h, buf, i);
            }
            i++;
            off += 4;
        } while (i < count);
    }
    if (a6 > 0 && (a7 == 0 || found == 0)) {
        h->m0->fn_80170F2C(0, a6, 0);
        h->m0->fn_80170EC4(a4);
        fn_80403144(buf, (const unsigned short*)h->m0->fn_80170CE4(0xC));
        n = fn_80172058(h, buf, 4);
    }
    if (n != 0) {
        fn_801720A8(h, n, (const unsigned short*)h->m0->fn_80170CE4(a5), 4);
    } else {
        fn_80171C20(h, 0xB);
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

extern const Unk80171A10_Fn lbl_805CB124;
void fn_8001BC58();

int fn_801723F8(Unk80171A10_Menu* p, int a) /* 801723F8 */
{
    if (p->m60 == 1) {
        p->m114 = a;
        return 1;
    }
    if (p->m60 == 3) {
        p->m60 = 0;
        switch (a) {
        case 4:
        case 0:
            break;
        case 2:
            fn_80174318(p, 0xE, lbl_805CB124);
            break;
        case 3:
        case 1:
            fn_80174318(p, 1, lbl_805CB11C);
            break;
        case 5:
            fn_8001BC58();
            ((Unk80170518*)fn_80173274((Unk80173274_T*)p))->fn_80005A50();
            break;
        }
        return 1;
    }
    if (((Unk80170518*)fn_80173274((Unk80173274_T*)p))->mBC != 0) {
        ((Unk80170518*)fn_80173274((Unk80173274_T*)p))->fn_80170A54(a);
    }
    return 0;
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

extern "C" int fn_804030F0(const unsigned short* a, const unsigned short* b, int n);
int fn_801730E8(Unk80171A10_Menu* p, unsigned short* s, int* out);

/* near-miss (97.6%): only the prologue copies differ. Retail copies the parameter into r29, then i = k into r31
 * before the slwi; here i takes r4 directly (r31) and k is copied from it afterwards. */
int fn_80172D44(Unk80171A10_Menu* p, int k) /* 80172D44 */
{
    int i = k;
    Unk80170518** q = (Unk80170518**)(i * 4 + (int)p);
    for (; i <= 0; q++, i++) {
        if ((*q)->fn_80005B74(i) != 0) {
            break;
        }
    }
    if (p->m40 != 0) {
        int j = k;
        if (j <= 0 && i == 1) {
            Unk80170518** q2 = (Unk80170518**)(j * 4 + (int)p);
            do {
                if ((*q2++)->fn_80005E8C(1) != 0) {
                    i = j;
                }
                j++;
            } while (j <= 0 && i == 1);
        }
    } else if (p->m114 != -1) {
        i = p->m114;
    }
    if (i == 0) {
        p->m4 = i;
        fn_801728E8(p);
        int r = ((Unk80170518*)fn_80173274((Unk80173274_T*)p))->fn_80005E8C(1);
        if (r != 0) {
            if (((Unk80171A10_Svc*)fn_80173274((Unk80173274_T*)p))->mC4 == 0) {
                r = 0;
            }
        }
        if (r == 0) {
            p->m114 = -1;
        }
        return r;
    }
    return 0;
}

int fn_80172EA4(Unk80171A10_Menu* p) /* 80172EA4 */
{
    unsigned int sel = -1;
    int t;
    if (p->m44 != 0) {
        for (unsigned int i = 0; i <= 3; i++) {
            if (p->m54 != 0) {
                int n = fn_80403060(p->mA4);
                if (fn_804030F0(p->mA4, ((Unk8016FF40*)p->m8[i])->m78, n) == 0) {
                    sel = i;
                    break;
                }
            } else if (((Unk8016FF40*)p->m8[i])->fn_80170044(p->m64) != 0) {
                sel = i;
                break;
            }
        }
    } else if (p->m54 != 0) {
        fn_801730E8(p, p->mA4, (int*)&sel);
        if (sel == -1) {
            t = p->m114;
            if (t != -1) {
                goto setsel;
            }
            goto set60;
        }
    } else {
        t = p->m114;
        if (t != -1) {
setsel:
            sel = t;
        } else {
set60:
            p->m60 = 1;
        }
    }
    if (sel <= 4) {
        p->m18 = sel;
        return 1;
    }
    return 0;
}

extern const char lbl_805CB12C[];
extern "C" int fn_804030C8(const unsigned short* a, const unsigned short* b);
extern "C" unsigned short* fn_804031BC(unsigned short* dst, const char* src);

int fn_80172FCC(Unk80171A10_Menu* p, unsigned short* dst, int n) /* 80172FCC */
{
    unsigned short fmt[0x1C];
    unsigned short name[0x1C];
    unsigned int idx = p->m18;
    if (idx <= 3) {
        unsigned short* cur = ((Unk8016FF40*)p->m8[idx])->m78;
        if (fn_804030C8(cur, (const unsigned short*)fn_80090880(lbl_8061977C, 0x650)) != 0) {
            fn_8040316C(dst, ((Unk8016FF40*)p->m8[p->m18])->m78, n);
            return 1;
        }
    }
    Unk80171A10_Holder* h = (Unk80171A10_Holder*)(void*)p->m3C;
    unsigned short* s = (unsigned short*)h->m0->fn_80170C30(2);
    if (fn_80403060(s) > 4) {
        fn_80403144(name, s);
        name[4] = 0;
    }
    fn_804031BC(fmt, lbl_805CB12C);
    unsigned int k = 1;
    do {
        fn_80403DE4(dst, (int)fmt, name, k);
        k++;
        int r = fn_801730E8(p, dst, 0);
        if (k > 0x62 || r == 0) {
            break;
        }
    } while (1);
    return 0;
}


int fn_801730E8(Unk80171A10_Menu* p, unsigned short* s, int* out)
{
    Unk8016FF40 info;
    unsigned int i = 0;
    int off = 0;
    fn_801701B4(&info, p->mDA, p->m64);
    fn_80170158(&info, s);
    fn_8017008C(&info, p->m88);
    ((Unk80170518*)fn_80173274((Unk80173274_T*)p))->fn_80005A7C(&info);
    for (; i <= 3; i++, off += 4) {
        char* bb = (char*)p + 8;
        if ((*(Unk8016FF40**)(bb + off))->fn_80170218(&info) != 0 && i != p->m18) {
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

extern const Unk80171A10_Fn lbl_805CB16C;
extern const Unk80171A10_Fn lbl_805CB17C;
extern const Unk80171A10_Fn lbl_805CB184;
extern const Unk80171A10_Fn lbl_805CB194;

void fn_80173870(Unk80171A10_Menu* p) /* 80173870 */
{
    if (fn_80172EA4(p) != 0) {
        switch (p->m68) {
        case 1:
            if (p->m18 == 4) {
                fn_80174318(p, 0xC, lbl_805CB16C);
            } else if (p->m4C != 0) {
                fn_80174318(p, 0xF, lbl_805CB174);
            } else {
                fn_80174318(p, 0xF, lbl_805CB17C);
            }
            break;
        case 0:
            if (p->m44 == 0 && p->m4C == 0) {
                fn_80174318(p, 0xF, lbl_805CB184);
            } else {
                fn_80174318(p, 0x11, lbl_805CB18C);
            }
            break;
        case 2:
            fn_80172B60(p, 0x10, 1);
            fn_80174318(p, 0xF, lbl_805CB194);
            break;
        }
    } else if (p->m44 != 0) {
        if (fn_80172D44(p, p->m4 + 1) != 0) {
            fn_80174318(p, 7, lbl_805CB14C);
        } else if (p->m4C != 0 && p->m68 == 1) {
            fn_80172D44(p, 0);
            fn_80174318(p, 0xF, lbl_805CB16C);
        } else {
            fn_80174318(p, 1, lbl_805CB11C);
        }
    }
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

extern const Unk80171A10_Fn lbl_805CB19C;

/* near-miss: the loop over the info slots keeps retail's layout (jump to a bottom test) via gotos, but retail
 * recomputes p+8 after the loop (loop-invariant hoist) while CSE reuses it here (3 slots). */
void fn_80173C14(Unk80171A10_Menu* p) /* 80173C14 */
{
    if (p->m48 != 0) {
        fn_80173BA4(p, p->mA4);
    }
    if (p->mA4[0] == 0xFFFF) {
        fn_80174318(p, 0, lbl_805CB114);
        return;
    }
    if (p->mA4[0] != 0) {
        int sel = -1;
        if (fn_801730E8(p, p->mA4, &sel) != 0) {
            p->m18 = sel;
        }
        if (p->m18 == 4) {
            int idx = 0;
            int* base = p->m8;
            p->m18 = idx;
            goto test;
body:
            idx = p->m18 + 1;
            p->m18 = idx;
            if ((unsigned int)idx > 3) {
                goto done;
            }
test:
            if (((Unk8016FF40*)base[idx])->m0 != 0) {
                goto body;
            }
done:
            fn_8017008C((Unk8016FF40*)p->m8[p->m18], p->m88);
            fn_80174318(p, 0x10, lbl_805CB19C);
        } else {
            fn_80174318(p, 0x11, lbl_805CB18C);
        }
        fn_80170158((Unk8016FF40*)p->m8[p->m18], p->mA4);
        fn_801701B4((Unk8016FF40*)p->m8[p->m18], p->mDA, p->m64);
        return;
    }
    if (p->m60 == 0) {
        unsigned short buf[0x1B];
        if (fn_80172FCC(p, buf, 0x1B) != 0) {
            fn_80403144(p->mA4, buf);
        } else {
            fn_80171F80((Unk80171A10_Holder*)(void*)p->m3C, buf);
            p->m60 = 2;
        }
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

extern const Unk80171A10_Fn lbl_805CB1B4;

void fn_80173F3C(Unk80171A10_Menu* p) /* 80173F3C */
{
    switch (p->m68) {
    case 1:
        fn_801701B4((Unk8016FF40*)p->m8[p->m18], p->mDA, p->m64);
        fn_801728A0(p, (Unk8016FF40*)p->m8[p->m18], 1);
        fn_80174318(p, 0x12, lbl_805CB1B4);
        break;
    case 0:
        fn_801728A0(p, (Unk8016FF40*)p->m8[p->m18], 0);
        fn_80174318(p, 0x12, lbl_805CB1AC);
        break;
    case 2:
        fn_801728A0(p, (Unk8016FF40*)p->m8[p->m18], 2);
        fn_80174318(p, 0x15, lbl_805CB1A4);
        break;
    default:
        fn_80174318(p, 0x15, lbl_805CB1A4);
        break;
    }
    fn_80171C20((Unk80171A10_Holder*)(void*)p->m3C, p->m70);
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
