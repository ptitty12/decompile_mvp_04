/*
 * Game code, .text 0x80073914-0x80077238 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8007A4DC.h"
#include "game/clampiter.h"
struct Unk800767DC_P {
    char pad0[0x14];
    void* m14;
    char pad18[0xC - 4];
    int m20;
};
struct Unk800767DC_State {
    char pad0[0x660];
    int m660;
};
struct Unk8007F198_B;
Unk800767DC_State* fn_800B555C();
int fn_80097210(void* p, int a);
int fn_8008CFD8(void* p, int a, int b);
int fn_800A65F4(void* g, int a, int b, int c, int d);
int fn_8007F7D0(Unk8007F198_B* b, unsigned i);
extern "C" int fn_8007B8A0__18Unk8007B2B0_Screen(Unk8007B2B0_Screen* s, int a, int b, int c, int d, int e, int f);

/* View of a widget whose slot 0x38 returns a float (fn_800745C4). */
struct Unk800745C4_WBase {
    char pad0[0x20];
};
struct Unk800745C4_W : Unk800745C4_WBase {
    virtual int v08();
    virtual int v10(int i);
    virtual int v18(int a);
    virtual int v20();
    virtual int v28(int a, int b);
    virtual int v30(int a, int b, char* c);
    virtual float v38(int a, int b);
};
extern const float lbl_805B3D0C;
extern const char* lbl_80622810;
extern const char* lbl_80622814;
extern const int lbl_805B6428[];
extern const int lbl_805B64A8[];
extern const int lbl_805B6698[];
extern const int lbl_805B6888[];
extern const int lbl_805B6968[];
extern const int lbl_805B6A48[];
extern const int lbl_805B6B28[];
extern const char lbl_805B3F4C[];
extern const char lbl_805B3F58[];
unsigned fn_800736EC(const char* s);
int fn_80083FC0(int x);
unsigned fn_8007366C(const char* a, const char* b);
int fn_80075868(int id);
int fn_80076058(int a, int b);
int fn_80329FA0(int* out, int c, ...);
int fn_804089B4(char* buf, const char* fmt, ...);
void fn_80075A44(Unk8007B2B0_Screen* s, int a, int i);
int fn_80075808(int id);
int fn_80377E04(Obj* o, int* out, int id);
int fn_80075D48(int i);
int fn_80075D64(int i);
int fn_80075CC0(int y);
int fn_80075D80(int a);
int fn_800761D8(int x);
int fn_80075DCC(int i);
int fn_80075EF4(int x);
int fn_80075F08(int x);
int fn_800909A4(Handle* h, int a, Obj* o);
void fn_80090A24(Handle* h, int r);
extern const char* lbl_80622818;
extern const char* lbl_8062281C;
extern const char* lbl_80622820;
extern const char* lbl_80622824;

struct Unk80075CF0_Date {
    unsigned short m0;
    unsigned short m2;
};

int Unk8007A4DC_Screen::fn_80073914(int a, int b, int i)
{
    int r;
    if (i > 1)
        r = fn_80073710(a, fn_80072894(b), i);
    else
        r = m190[i].m0->v28(a, b);
    return r;
}

void Unk8007A4DC_Screen::fn_80073994(int a, int b, int i, int c)
{
    if (i <= 1)
        m190[i].m0->v40(a, b, c);
}

struct Unk739E0_Out {
    unsigned a;
    unsigned b;
    unsigned c;
};
void fn_8008395C(Unk8007A4DC_Obj1E8* o, int x, int p, int q, unsigned* out);
int fn_800849C0(int i);
int fn_800801DC(Unk8007A4DC_Screen* s);
/* near-miss (pass 2, ~60 slots): same structure and 137 vs 140 instructions; retail moves d into r4, keeps
 * the m190 base in a callee-saved register across the two vcalls of the d > 1 arm and holds the first result in r26. */
int Unk8007A4DC_Screen::fn_800739E0(int a, int id, int c, int d)
{
    if (c <= 1) {
        if (d <= 1) {
            W* w = m190[c].m4[d];
            return w->v28(a, fn_80071814(w, id));
        }
        W* w1 = m190[c].m4[0];
        int r1 = w1->v28(a, fn_80071814(w1, id));
        W* w2 = m190[c].m4[1];
        return r1 + w2->v28(a, fn_80071814(w2, id));
    }
    if (fn_800801DC(this) == 1) {
        Unk8007A4DC_Obj1E8* o = m1E8;
        int p = fn_80080198();
        Unk739E0_Out sp;
        fn_8008395C(o, id, p, fn_800849C0(c), &sp.a);
        switch (a) {
        case 0:
            return sp.b & 0x7F;
        case 1:
            return (sp.b >> 15) & 0xFF;
        case 2:
            return (sp.b >> 23) - (sp.b & 0x7F);
        case 5:
            return (sp.c >> 15) & 0xFF;
        case 6:
            return (sp.c >> 7) & 0xFF;
        case 7:
            break;
        case 8:
            return sp.c & 0x7F;
        case 10:
            break;
        case 11:
            return (sp.a >> 22) + ((sp.c >> 7) & 0xFF) + (sp.c & 0x7F);
        }
    }
    return 0;
}

void Unk8007A4DC_Screen::fn_800743A0(int a, int b, int i, int j, int c)
{
    if (j <= 1 && i <= 1) {
        W* w = m190[i].m4[j];
        w->v40(a, fn_80071814(w, b), c);
    }
}

int Unk8007A4DC_Screen::fn_80074428(int a, int b, int c, int d)
{
    if (d <= 1) {
        if (c <= 1)
            return m190[c].m4[d]->v28(a, b);
        return fn_800739E0(a, fn_80072894(b), c, d);
    }
    return fn_80074428(a, b, c, 0) + fn_80074428(a, b, c, 1);
}

void Unk8007A4DC_Screen::fn_80074500(int a, int b, int i, int j, int c)
{
    if (j <= 1 && i <= 1)
        m190[i].m4[j]->v40(a, b, c);
}

int Unk8007A4DC_Screen::fn_8007455C(int a, int b, int i)
{
    W* w = m1A8[i];
    return w->v28(a, fn_80071814(w, b));
}

float Unk8007A4DC_Screen::fn_800745C4(int a, int b, int i)
{
    if (i <= 4) {
        W* w = m1A8[i];
        return ((Unk800745C4_W*)w)->v38(a, fn_80071814(w, b));
    }
    return lbl_805B3D0C;
}

void Unk8007A4DC_Screen::fn_80074640(int a, int b, int i, int c)
{
    if (i <= 4) {
        W* w = m1A8[i];
        w->v40(a, fn_80071814(w, b), c);
    }
}

int Unk8007A4DC_Screen::fn_800746B8(int a, int b, int i)
{
    int r;
    if (i > 4)
        r = 0;
    else
        r = m1A8[i]->v28(a, b);
    return r;
}

void Unk8007A4DC_Screen::fn_80074708(int a, int b, int i, int c)
{
    if (i <= 4)
        m1A8[i]->v40(a, b, c);
}

struct Unk74754_Out {
    unsigned a;
    unsigned b;
    unsigned c;
};
void fn_8008397C(Unk8007A4DC_Obj1E8* o, int x, int p, int q, unsigned* out);
int fn_800849C0(int i);
int Unk8007A4DC_Screen::fn_80074754(int a, int x, int i)
{
    if (i <= 1) {
        W* w = m1CC[i].m0;
        return w->v28(a, fn_80071814(w, x));
    }
    Unk8007A4DC_Obj1E8* o = m1E8;
    int p = fn_80080198();
    Unk74754_Out sp;
    fn_8008397C(o, x, p, fn_800849C0(i), &sp.a);
    switch (a) {
    case 0:
        return sp.a & 0x7F;
    case 1:
        return sp.b >> 23;
    case 2:
        return (sp.b >> 21) & 3;
    case 3:
        return (sp.b >> 15) & 0x3F;
    case 4:
        return (sp.b >> 9) & 0x3F;
    case 6:
        return sp.a >> 24;
    case 7:
        return sp.c >> 25;
    case 8:
        return (sp.c >> 19) & 0x3F;
    case 9:
        return (sp.c >> 7) & 0x3F;
    default:
        return 0;
    }
}

void Unk8007A4DC_Screen::fn_80074F50(int a, int b, int i, int c)
{
    if (i <= 1) {
        W* w = m1CC[i].m0;
        w->v40(a, fn_80071814(w, b), c);
    }
}

int Unk8007A4DC_Screen::fn_80074FC8(int a, int b, int i)
{
    int r;
    if (i > 1)
        r = fn_80074754(a, fn_800728E4(b), i);
    else
        r = m1CC[i].m0->v28(a, b);
    return r;
}

void Unk8007A4DC_Screen::fn_80075048(int a, int b, int i, int c)
{
    if (i <= 1)
        m1CC[i].m0->v40(a, b, c);
}

struct Unk75094_Out {
    unsigned a;
    unsigned b;
    unsigned c;
};
void fn_8008397C(Unk8007A4DC_Obj1E8* o, int x, int p, int q, unsigned* out);
int fn_800849C0(int i);
int fn_800801DC(Unk8007A4DC_Screen* s);
/* near-miss (pass 2): same shape as fn_800739E0; retail moves d into r4 at entry and indexes the
 * second slot as (c * 12 + 4) from a callee-saved base. */
int Unk8007A4DC_Screen::fn_80075094(int a, int id, int c, int d)
{
    if (c <= 1) {
        if (d <= 1) {
            W* w = m1CC[c].m4[d];
            return w->v28(a, fn_80071814(w, id));
        }
        char* b = (char*)this + 0x1D0;
        int o = c * 12;
        W* w1 = *(W**)(b + (o + 4));
        int r1 = w1->v28(a, fn_80071814(w1, id));
        W* w2 = *(W**)(b + o);
        return r1 + w2->v28(a, fn_80071814(w2, id));
    }
    if (fn_800801DC(this) == 1) {
        Unk8007A4DC_Obj1E8* o = m1E8;
        int p = fn_80080198();
        Unk75094_Out sp;
        fn_8008397C(o, id, p, fn_800849C0(c), &sp.a);
        switch (a) {
        case 0:
            return (sp.a >> 16) & 0xFF;
        case 2:
            return (sp.a >> 7) & 0x1FF;
        case 7:
            return (sp.c >> 13) & 0x3F;
        }
    }
    return 0;
}

void Unk8007A4DC_Screen::fn_800755FC(int a, int b, int i, int j, int c)
{
    if (i <= 1 && j <= 1) {
        W* w = m1CC[i].m4[j];
        w->v40(a, fn_80071814(w, b), c);
    }
}

int Unk8007A4DC_Screen::fn_80075684(int a, int b, int c, int d)
{
    if (d <= 1) {
        if (c <= 1)
            return m1CC[c].m4[d]->v28(a, b);
        return fn_80075094(a, fn_800728E4(b), c, d);
    }
    return fn_80075684(a, b, c, 0) + fn_80075684(a, b, c, 1);
}

void Unk8007A4DC_Screen::fn_8007575C(int a, int b, int i, int j, int c)
{
    if (j <= 1 && i <= 1)
        m1CC[i].m4[j]->v40(a, b, c);
}

int Unk8007B2B0_Screen::fn_800757B8(int a)
{
    int r = fn_80075948(a);
    if (r != 0 && fn_8007B3E0(0xE, r) != 0)
        return 1;
    return 0;
}

int fn_80075808(int id)
{
    int a = fn_800736EC(lbl_80622810);
    int b = fn_800736EC(lbl_80622814);
    int r = 0;
    if (id == a || id == b)
        r = 1;
    return r;
}

int fn_80075868(int id)
{
    int a = fn_800736EC(lbl_80622818);
    int b = fn_800736EC(lbl_8062281C);
    int c = fn_800736EC(lbl_80622820);
    int d = fn_800736EC(lbl_80622824);
    int r = 0;
    if (id == a || id == b || id == c || id == d)
        r = 1;
    return r;
}

int fn_800758F8(int id)
{
    int r = 0;
    if (fn_80075808(id) || fn_80075868(id))
        r = 1;
    return r;
}

int Unk8007B2B0_Screen::fn_80075948(int a)
{
    if (a != 0) {
        unsigned i = 0;
        unsigned n = fn_8007B2B0();
        for (; i < n; i++) {
            Unk8006A138_It<3> it(0);
            int j = 0;
            while (j <= 3) {
                int id = fn_80083FC0(j);
                if (fn_8007B5D8(id, i) == a)
                    return fn_8007B2FC(i);
                j = it.Next();
            }
        }
    }
    return 0;
}

void fn_800759F8(Unk8007B2B0_Screen* s, int a)
{
    int i = 0;
    do {
        fn_80075A44(s, a, i++);
    } while (i <= 0x3E);
}

int Unk8007B2B0_Screen::fn_80075C64(int id)
{
    int i;
    for (i = 0; i <= 3; i++) {
        if (fn_8007DA34(i) == id)
            return i;
    }
    return 5;
}

int fn_80075CC0(int y)
{
    unsigned short idx = (y - 2005) % 32;
    return lbl_805B6428[idx];
}

int fn_80075CF0(int a, int x)
{
    int v = fn_80075D80(a);
    Unk80075CF0_Date d;
    fn_80329FA0((int*)&d, x);
    return v == fn_80075CC0(d.m2);
}

int fn_80075D48(int i)
{
    return lbl_805B64A8[i] >= 0;
}

int fn_80075D64(int i)
{
    return lbl_805B6698[i] >= 0;
}

int fn_80075D80(int i)
{
    int r = 0;
    if (fn_80075D48(i) == 1)
        r = lbl_805B64A8[i];
    return r;
}

int fn_80075DCC(int i)
{
    int r;
    if (fn_80075D64(i) == 0)
        r = 0;
    else
        r = lbl_805B6698[i];
    return r;
}

int fn_80075E18(int i, int kind)
{
    int v = -1;
    switch (kind) {
    case 0:
        v = lbl_805B6888[i];
        break;
    case 1:
        v = lbl_805B6968[i];
        break;
    case 2:
        v = lbl_805B6A48[i];
        break;
    }
    return v >= 0;
}

int fn_80075E7C(int x)
{
    int i;
    for (i = 0; i <= 0x37; i++) {
        int j;
        for (j = 0; j <= 2; j++) {
            if (fn_80076058(i, j) == x)
                return i;
        }
    }
    if ((unsigned)(x - 0x25) <= 1)
        return 0x34;
    return 0;
}

int fn_80075EF4(int x)
{
    return (unsigned)(x - 0x1E) <= 0xF;
}

int fn_80075F08(int x)
{
    return (unsigned)(x - 0x2E) <= 8;
}

int fn_80075F1C(int id, int a, int b)
{
    int i;
    int j;
    for (i = 0; i <= 0x7B; i++) {
        if (fn_80075D48(i)) {
            int v;
            v = fn_80075D80(i);
            for (j = 0; j <= 2; j++) {
                if (fn_80075E18(v, j) && fn_80076058(v, j) == id)
                    return i;
            }
        }
    }
    for (i = 0; i <= 0x7B; i++) {
        if (fn_80075D64(i)) {
            int v;
            v = fn_80075DCC(i);
            for (j = 0; j <= 2; j++) {
                if (fn_80075E18(v, j) && fn_80076058(v, j) == id)
                    return i;
            }
        }
    }
    if (a != 0 && fn_800761D8(id) != 0)
        return 0;
    if (b != 0 && id > 0x4D && id <= 0x53)
        return 0x29;
    return 0;
}

int fn_80076058(int i, int kind)
{
    int v = -1;
    switch (kind) {
    case 0:
        v = lbl_805B6888[i];
        break;
    case 1:
        v = lbl_805B6968[i];
        break;
    case 2:
        v = lbl_805B6A48[i];
        break;
    }
    if (v >= 0)
        return v;
    int a = lbl_805B6968[i];
    if (a != -1)
        return a;
    int b = lbl_805B6A48[i];
    if (b != -1)
        return b;
    int c = lbl_805B6888[i];
    if (c != -1)
        return c;
    return v;
}

int fn_80076104(int id, int a, int b)
{
    int i;
    for (i = 0; i <= 0x7B; i++) {
        if (fn_80075D48(i) && fn_80075D80(i) == id)
            return i;
    }
    for (i = 0; i <= 0x7B; i++) {
        if (fn_80075D64(i) && fn_80075DCC(i) == id)
            return i;
    }
    if (a != 0 && fn_80075EF4(id) != 0)
        return 0;
    if (b != 0 && fn_80075F08(id) != 0)
        return 0x29;
    return 0;
}

int fn_800761D8(int x)
{
    int r = 0;
    switch (x) {
    case 6:
    case 10:
    case 12:
    case 23:
    case 27:
    case 29:
    case 39:
    case 65:
    case 69:
    case 71:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 86:
        r = 1;
    }
    return r;
}

int fn_80076270(int x)
{
    int r = 0;
    switch (x) {
    case 6:
    case 10:
    case 12:
    case 23:
    case 27:
    case 29:
    case 39:
    case 76:
        r = 1;
    }
    return r;
}

int Unk8007A4DC_Screen::fn_800764F4(const char* a, const char* b, int c)
{
    Handle* h = &m17C;
    int r = fn_800909A4(h, fn_8007366C(a, b), 0);
    fn_80090A24(h, r);
    if (c == 0 || c == 10)
        fn_80090A24(&m1C0, r);
    fn_8007A808(0xB, r, 0);
    return r;
}

int fn_80076584(int a, int b)
{
    int r = b == 0;
    if (b == 2 && a == 1)
        r = 1;
    return r;
}

unsigned fn_800765A8(int x)
{
    char a[0x40];
    char b[0x40];
    int s = x << 2;
    fn_804089B4(a, lbl_805B3F4C, x, s);
    fn_804089B4(b, lbl_805B3F58, x, s);
    return fn_8007366C(a, b);
}

int Unk8007A4DC_Screen::fn_8007661C(int b)
{
    return fn_8007A6A0(5, b);
}

int fn_80076644(int a, int b, int c)
{
    if (a <= 9) {
        int t = lbl_805B6B28[a];
        int r = 0;
        if (((t >> b) & 1) || ((t >> c) & 1))
            r = 1;
        return r;
    }
    return 0;
}

int fn_8007668C(int a, int b)
{
    if (a <= 9)
        return (lbl_805B6B28[a] >> b) & 1;
    return 0;
}

/* Four-slot view of the db widget table object used by fn_800766B8 / fn_80076758. */
struct Unk800766B8_Obj {
    char pad0[0xC];
    void* mC;
    void* m10;
    void* m14;
    void* m18;
    char pad1C[0x14];
    void* m30;
};
struct Unk80076758_Ev {
    char pad0[0xC];
    struct Unk80076758_Ev0* mC;
};
struct Unk80076758_Ev0 {
    char pad0[0x84];
    int m84;
    int m88;
};
struct Unk80076758_G {
    char pad0[0x5C];
    void* m5C;
};
void fn_802B8D74();
void fn_802B8DDC();
extern "C" void fn_8052BAA8(void* p, int a);
extern "C" void fn_8052BAFC(void* p, int a);
extern "C" void fn_8052BB50(void* p, int a);
extern "C" void fn_8052BBA4(void* p, int a);
extern "C" void fn_8052BF14(void* p, int a, void* ev);
extern "C" void fn_8006A860(void* ev);
extern "C" void fn_80590CA8(void* p);
extern "C" int fn_800A2EB4(void* g);
extern "C" void fn_8053FC0C(void* p);
extern Unk80076758_G* lbl_80619948;

extern "C" void fn_800766B8(Unk800766B8_Obj* self, int k)
{
    fn_802B8D74();
    switch (k) {
    case 0:
        {
            char* b = (char*)self + 0xC;
            fn_8052BAA8(*(void**)(b + k), 0);
        }
        break;
    case 1:
        fn_8052BAFC(self->m10, 0);
        break;
    case 2:
        fn_8052BB50(self->m14, 0);
        break;
    case 3:
        fn_8052BBA4(self->m18, 0);
        break;
    }
    fn_802B8DDC();
}

void fn_80076758(Unk800766B8_Obj* self, Unk80076758_Ev* ev)
{
    Unk80076758_G** g = &lbl_80619948;
    int k = ev->mC->m84;
    char* tb = (char*)self + 0xC;
    int to = k * 4;
    fn_8052BF14(*(void**)(tb + to), ev->mC->m88, ev);
    fn_8006A860(ev);
    fn_80590CA8(self->m30);
    if (fn_800A2EB4(*g) == 1 && k == 0)
        fn_8053FC0C((*g)->m5C);
}

/* The table base is an int (`tb`): a pointer-typed local is flagged as a pointer, which puts the index pseudo
 * in the index class (r0 allowed); retail's index byte and its *0x34 product stay in r9. */
extern "C" void fn_800767DC(Unk8007B2B0_Screen* s, Unk800767DC_P* p)
{
    int a = 0;
    int v;
    int k;
    switch (fn_800B555C()->m660) {
    case 4: {
        char* q = (char*)p->m14;
        k = 7;
        int tb = (int)q + 0x124C;
        int off = (*(unsigned char*)(*(unsigned char**)(q + 0xFCC) + *(int*)(q + 0xFD8))) * 0x34;
        v = *(int*)(tb + off);
        a = fn_8008CFD8(q + 0xC9C, 9, *(unsigned char*)(q + 0x17C));
        break;
    }
    case 5:
        k = 8;
        v = fn_80097210(p->m14, 0);
        break;
    default:
        v = 0;
        k = 0xD;
        break;
    }
    if (v != 0 && k != 0xD) {
        char* b = (char*)p + 0x14;
        int c = fn_800A65F4(lbl_80619948, v, k, a, *(int*)(b + 0xC));
        fn_8007B8A0__18Unk8007B2B0_Screen(s, fn_8007F7D0((Unk8007F198_B*)s, 0), v, k, *(int*)(b + 0xC), a, c);
    }
}

/* near-miss (pass 2): same loop structure and iterator; retail keeps `total` in r31 and forms the
 * record address as (i*0x1C + base) with a byte offset j*12+4, ours folds the offsets differently. */
int Unk8007B2B0_Screen::fn_80076A24(int id)
{
    int idx = fn_80078A38(id);
    int total = 0;
    unsigned n = mC[idx]->m4;
    unsigned i;
    for (i = 0; i < n; i++) {
        Unk8006A138_It<1> it(0);
        int j = 0;
        while (j <= 1) {
            Unk80076A24_Rec* r = &mC[idx]->m8[i];
            if (r->m4[j].m0 == id)
                total += r->m4[j].m4;
            j = it.Next();
        }
    }
    return total;
}

/* near-miss (pass 2): as fn_80076A24; the key is read from the other entry ((j == 0) as subfic/adde in retail). */
int Unk8007B2B0_Screen::fn_80076AE4(int id)
{
    int idx = fn_80078A38(id);
    int total = 0;
    unsigned n = mC[idx]->m4;
    unsigned i;
    for (i = 0; i < n; i++) {
        Unk8006A138_It<1> it(0);
        int j = 0;
        while (j <= 1) {
            Unk80076A24_Rec* r = &mC[idx]->m8[i];
            if (r->m4[j == 0].m0 == id)
                total += r->m4[j].m4;
            j = it.Next();
        }
    }
    return total;
}

float Unk8007A4DC_Screen::fn_80076BAC(int a, int b)
{
    Unk805A19C8_Roster* r = m58;
    unsigned cnt = 0;
    unsigned i = 0;
    unsigned char n = r->m10[fn_805A19C8(r, a)].m7;
    float tot = 0.0f;
    for (; i < n; i++) {
        unsigned char j = i;
        int k = fn_805A19C8(r, a);
        int o = j * 4;
        int id = *(int*)((char*)r->m10[k].m0 + o);
        int x;
        int f = fn_80377E04(fn_800A883C(&m17C), &x, id) != 0;
        if (f == 1) {
            tot += fn_80073C10(0, id, b, 2);
            cnt += (int)fn_80073C10(1, id, b, 2);
        }
    }
    float res = 0.0f;
    if (cnt != 0)
        res = tot / (float)cnt;
    return res;
}
