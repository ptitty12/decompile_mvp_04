/*
 * Game code, .text 0x8011A518-0x8011C5E8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8010E0F4.h"
#include "game/tu_8001B190.h"

typedef Unk800C7B40_Widget Wid;

struct Unk8068B618 {
    char pad0[0x24];
    int m24;
};
extern Unk8068B618* lbl_8068B618;
extern char* lbl_8061A328;

struct UnkPair {
    int m0;
    int m4;
};
/* Object with a counted list of {id, ?} pairs at +0x238 (count byte at +0x235). */
struct UnkIdList {
    char pad0[0x235];
    unsigned char m235;
    char pad236[2];
    UnkPair m238[1];
};
struct UnkB6DB8 {
    char pad0[0x14];
    int m14;
};

/* Per-player stats holder: +0x44C the game object, +0x588 an embedded stat table. */
struct UnkPlr {
    char pad0[0x44C];
    UnkGame* m44C;
    char pad450[0x138];
    char m588[1];
};
extern const float lbl_805BFD30;
extern const float lbl_805BFD34;
extern const float lbl_805BFD38;

/* Indexed int load whose index register is a separate temp (lwzx base,idx). */
inline int AtD(int* p, int i)
{
    int off = i * 4;
    return *(int*)((char*)p + off);
}

struct Unk80090880;
char* fn_80090880(Unk80090880* p);
typedef char* (*TxtLook)(Unk80090880*, int);
extern Unk80090880* lbl_8061977C;
struct Unk8024EF40_W;
int fn_8025416C(Unk8024EF40_W* w, int i);
class Unk80619D10 {
public:
    char pad0[0x18];
    virtual ~Unk80619D10();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual int s25();
};
struct UnkRosterHolder {
    char pad0[0x65C];
    UnkGame* m65C[13];
};
inline UnkGame* Roster(UnkGame* g, unsigned i)
{
    if (i <= 0xC)
        return ((UnkRosterHolder*)g)->m65C[i];
    return 0;
}

struct Unk801B23A8_V;
struct Unk801B23A8_Q;
int fn_801B454C(Unk801B23A8_V* v, Unk801B23A8_Q* q);
inline int HasFF(int v, UnkGame* o)
{
    Unk801B23A8_V* a = (Unk801B23A8_V*)v;
    if (fn_801B454C(a, (Unk801B23A8_Q*)o) == 0xFF)
        return 0;
    return 1;
}

struct UnkEnt34 {
    int m0;
    char pad4[0x30];
};
inline int EntAt(UnkEnt34* base, int i)
{
    int o = i * 0x34;
    return *(int*)((char*)base + o);
}

struct UnkW13 : Unk800C7B40_Data {
    virtual ~UnkW13();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10(int a);
    virtual void s11();
    virtual void s12();
    virtual void s13(int a);
};
struct Unk80040640;
Unk80040640* fn_8004072C();
int fn_800412AC(Unk80040640* o, int a, int b, int c, int d, int e);
// PROTOS-BEGIN
extern "C" {
void fn_8011A518(UnkGame* g, Wid* w, const char* name);
void fn_8011A5A0(UnkPlr* a, Wid* w, const char* name);
void fn_8011A6D8(UnkPlr* a, Wid* w, const char* name);
void fn_8011A728(UnkPlr* a, Wid* w, const char* name);
void fn_8011A7F4(UnkPlr* a, int unused, Wid* w, const char* name);
void fn_8011A838(UnkPlr* a, int unused, Wid* w, const char* name);
void fn_8011A87C(UnkPlr* a, int unused, Wid* w, const char* name);
void fn_8011A974(UnkPlr* a, Wid* w, const char* name);
void fn_8011A9B8(const char* s, Wid* w, const char* name);
UnkGame* fn_8011AA24(int i);
int fn_8011AA4C();
int fn_8011AB48(int a);
void fn_8011ABDC(int a, int b);
UnkGameP10* fn_8011AC90(int idx);
int fn_8011AD00(int mode, int idx);
void fn_8011AD88(int mode, int idx, int c);
int fn_8011AE28(int mode, int idx);
void fn_8011AEB0(int mode, int idx, int c);
void fn_8011AF34(Wid* self);
void fn_8011B3E8(int a, int* x, int* y);
int fn_8011B494(int* p, int a, int c);
int fn_8011B4E4();
void fn_8011B5A4();
int fn_8011B5D8(UnkIdList* a, int* b);
int fn_8011B604(UnkIdList* a, int* b);
int fn_8011B630(UnkIdList* a, int* b);
int fn_8011B65C(int a, UnkIdList* o, int* out);
int fn_8011B6F8(int a, UnkPlr* p);
int fn_8011B784(int a, UnkPlr* p, int c);
float fn_8011B81C(int a, UnkPlr* p, int c);
int fn_8011B8C8(int a, UnkPlr* p);
float fn_8011B954(int a, UnkPlr* p);
int fn_8011B9F4(int a, UnkPlr* p);
float fn_8011BA88(int a, UnkPlr* p);
int fn_8011BB30(void* a, int b);
int fn_8011BB54(void* a, int b);
int fn_8011BC98(int a);
int fn_8011BD0C(void* a, int b);
int fn_8011BD3C(UnkGame* g, int b);
int fn_8011BD94(UnkGame* g, int a);
int fn_8011BF1C(UnkGame* g, int a);
void* fn_8011BFAC(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_8011BFFC(void* self, int a);
void fn_8011C04C(Unk800C7B40_Widget* self);
void fn_8011C114(void* self);
int fn_8011C3B4();
int fn_8011C3EC(Wid* self, int a);
void fn_8011C4A8(Wid* self, int a);
void fn_8011C534(Unk80117D20_Scr* self);
}
// PROTOS-END
extern "C" {
void* fn_800DBAE0(void* p, int a, int b, int c);
void fn_8011A0A4(int v, Wid* w, const char* name);
int fn_8011B8C8(int a, UnkPlr* p);
int fn_8011B9F4(int a, UnkPlr* p);
float fn_8011BA88(int a, UnkPlr* p);
void fn_801B5AD0(int a, int b);
int fn_8011B65C(int a, UnkIdList* b, int* c);
int fn_800968C0(void* o, int id, int f);
int fn_8009764C(void* o, int a, int b, int c);
UnkB6DB8* fn_801A6DB8(UnkGame* g);
int fn_801C1638(UnkGame* g, int i);
int fn_8011BB78(void* a, int b, int c);
int fn_8011BB54(void* a, int b);
int fn_8006BC74(void* a, int b);
int fn_8006A1B4(void* p);
void fn_801A23B8(UnkGame* g, int a);
void fn_80086EC0(UnkGameP10* p, int a, int b);
struct Unk800AEC80 {
    char pad0[0xD8];
    int mD8;
};
Unk800AEC80* fn_800AEC80(int a);
int fn_800AB5C8(int a);
int* fn_800ED2B0(void* container, const char* name);
void fn_800CFB38(int* p);
void fn_801389A4(void* w, int a);
Wid* fn_800B7AB8(UnkFEMgr* m, const char* name);
UnkGameP10* fn_8011AC90(int i);
void fn_8035682C(void* name);
void fn_8040B830(void* dst, const char* src, int n);
void fn_800B7B4C(UnkFEMgr* m, const void* name, void* obj);
void fn_800ED254(void* self);
void fn_802DC9C0();
void fn_802D7ADC();
void fn_802D8294(int a);
void fn_802D7A64();
void fn_802D7ACC();
void fn_802D7A74();
void fn_800ECF18(void* self);
void fn_800AB618(int a);
int fn_8017C8C0(UnkGameP700* a);
int fn_8017C8C8(UnkGameP700* a);
int fn_80081B60(void* a);
void fn_800AB6B8(int a);
void fn_8035686C(void* self, int a);
extern const char lbl_805BEAE0[];
extern const char lbl_805BE5E4[];
extern const char lbl_805BE690[];
extern const char lbl_805BA230[];
void fn_8017DD80(UnkGameP700* a, int b, int* c, int* d);
int fn_80097148(void* p, unsigned char i);
int fn_801A49F0(void* g, int a, int b);
int fn_8004181C(void* o, int a, int b, int c, int d, int e, int f);

int fn_8011AA4C();
int fn_800B55A8(UnkFEState* s);
int fn_800B59DC(UnkFEState* s);
int fn_80253DB0(void* t, int a, int b);
int fn_80253F9C(void* t, int a);
int fn_80253F0C(void* t, int a, int b, int c);
int fn_802540E4(void* t, int a, int b);
float fn_80253F54(void* t, int a, int b, int c);
float fn_80254128(void* t, int a, int b);
int fn_80253DF4(void* t, int a, int b);
int fn_80253FDC(void* t, int a);
float fn_80253E38(void* t, int a, int b);
float fn_8025401C(void* t, int a);
int fn_80253E7C(void* t, int a, int b, int c);
int fn_8025405C(void* t, int a, int b);
float fn_80253EC4(void* t, int a, int b, int c);
float fn_802540A0(void* t, int a, int b);
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80119FF0(char* buf, float v);
extern const int lbl_80619D10;
void fn_800EC8EC(void* p);
void fn_800ECB0C(void* p);
extern const char lbl_805BE0C0[];
int fn_804089B4(char* buf, const char* fmt, ...);
int fn_80097210(void* team, int a);
extern const char lbl_805BC1A8[];
extern const char lbl_805BA240[];
extern const char lbl_805BEC18[];
}

extern const char lbl_8065A918[];
extern "C" {

void fn_8011A518(UnkGame* g, Wid* w, const char* name)
{
    void* r = 0;
    if (fn_8011AA24(0) != 0 && fn_8011AA24(0)->m6F8 != 0)
        r = fn_8011AA24(0)->m6F8->m14;
    fn_8011A0A4((int)fn_800DBAE0(r, 0xD, g->m708, g->m704), w, name);
}

void fn_8011A5A0(UnkPlr* a, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B8C8(0, a), w, name);
}

void fn_8011A5E4(UnkPlr* a, Wid* w, const char* name)
{
    char buf[40];
    int x = fn_8011B8C8(1, a);
    float f = (float)x + (float)fn_8011B8C8(2, a) * 0.1f;
    fn_804089B4(buf, lbl_805BE0C0, f);
    fn_800C8040(w->fn_vslot32(name, 1))->fn_vslot30(buf);
}

void fn_8011A6D8(UnkPlr* a, Wid* w, const char* name)
{
    fn_8011A0A4((int)fn_8011BA88(0, a), w, name);
}

void fn_8011A728(UnkPlr* a, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B9F4(2, a), w, name);
}

void fn_8011A76C(UnkPlr* a, Wid* w, const char* name)
{
    char buf[40];
    float f = fn_8011B954(1, a);
    fn_80119FF0(buf, f);
    fn_800C8040(w->fn_vslot32(name, 1))->fn_vslot30(buf);
}

void fn_8011A7F4(UnkPlr* a, int unused, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B8C8(3, a), w, name);
}

void fn_8011A838(UnkPlr* a, int unused, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B8C8(4, a), w, name);
}

void fn_8011A87C(UnkPlr* a, int unused, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B8C8(7, a), w, name);
}

void fn_8011A8C0(UnkPlr* a, Wid* w, const char* name)
{
    int id = 0;
    int k = fn_8025416C((Unk8024EF40_W*)a->m588, 9);
    if (k != 0) {
        if (k == 1)
            id = 0x1999;
    } else
        id = 0x199A;
    fn_800C8040(w->fn_vslot32(name, 1))->fn_vslot28(((TxtLook)fn_80090880)(lbl_8061977C, id));
}

void fn_8011A974(UnkPlr* a, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B9F4(0, a), w, name);
}

void fn_8011A9B8(const char* s, Wid* w, const char* name)
{
    fn_800C8040(w->fn_vslot32(name, 1))->fn_vslot30(s);
}

/* near-miss: retail's lwzx index is r11, ours r0 (2 slots; many spellings of the offset/base tried:
 * inline base+offset, char* locals, member-array pointer). */
UnkGame* fn_8011AA24(int i)
{
    UnkGameTbl* t = lbl_8061B8C0;
    UnkGame* r;
    if ((unsigned)i <= 2) {
        int o = i * 4;
        char* b = (char*)t + 8;
        r = *(UnkGame**)(b + o);
    } else
        r = 0;
    return r;
}

int fn_8011AA4C()
{
    return lbl_806192E0->m4->m10->m74;
}

int fn_8011AA64(int a)
{
    int r = 0;
    int mode = fn_8011AA4C();
    switch (mode) {
    case 1:
    case 2: {
        UnkGame* o = fn_8011AA24(a == 0);
        if (mode == 2) {
            UnkTeamArr* g = (UnkTeamArr*)o->m6F8->m14;
            int s = g->m1CD0 == 0;
            UnkPlayerRec* t = (UnkPlayerRec*)((char*)g + s * 0xE64);
            r = t->m198;
        } else {
            UnkTeamArr* g = (UnkTeamArr*)o->m6F8->m14;
            int s = 0;
            if (g->m1CD0 != 0)
                s = 1;
            UnkPlayerRec* t = (UnkPlayerRec*)((char*)g + s * 0xE64);
            r = t->m198;
        }
        break;
    }
    case 0:
    case 3:
    case 4:
    case 5:
    case 6:
    case 10: {
        UnkPlayerRec* t = (UnkPlayerRec*)((char*)fn_8011AA24(0)->m6F8->m14 + a * 0xE64);
        r = t->m198;
        break;
    }
    }
    return r;
}

int fn_8011AB48(int a)
{
    int r = -1;
    int mode = fn_8011AA4C();
    switch (mode) {
    case 1:
    case 2:
        r = fn_8011AD00(mode, a == 0);
        break;
    case 0:
    case 3:
    case 4:
    case 5:
    case 6:
    case 10:
        r = AtD(&fn_8011AA24(0)->m6F8->m10->m6C, a);
        break;
    }
    return r;
}

void fn_8011ABDC(int a, int b)
{
    int mode = fn_8011AA4C();
    switch (mode) {
    case 1:
    case 2: {
        int c = a == 0;
        fn_8011AD88(mode, c, b);
        fn_801A23B8(fn_8011AA24(c), 0);
        break;
    }
    case 0:
    case 3:
    case 4:
    case 5:
    case 6:
    case 10: {
        UnkGame* g = fn_8011AA24(0);
        fn_80086EC0(g->m6F8->m10, a, b);
        fn_801A23B8(g, 1);
        break;
    }
    }
}

UnkGameP10* fn_8011AC90(int idx)
{
    UnkGame* g = 0;
    switch (fn_8011AA4C()) {
    case 1:
    case 2:
        g = fn_8011AA24(idx);
        break;
    case 3:
    case 5:
    case 6:
        g = fn_8011AA24(0);
        break;
    }
    return g->m6F8->m10;
}

int fn_8011AD00(int mode, int idx)
{
    UnkGameP10* o = fn_8011AC90(idx);
    switch (mode) {
    case 1:
    case 2:
        if (mode == 1)
            return o->m70;
        return o->m6C;
    case 3:
    case 5:
    case 6:
        switch (idx) {
        case 0:
            return o->m6C;
        case 1:
            return o->m70;
        }
        break;
    }
    return -1;
}

void fn_8011AD88(int mode, int idx, int c)
{
    UnkGameP10* o = fn_8011AC90(idx);
    switch (mode) {
    case 1:
    case 2:
        if (mode == 1)
            fn_80086EC0(o, 1, c);
        else
            fn_80086EC0(o, 0, c);
        break;
    case 3:
    case 5:
    case 6:
        switch (idx) {
        case 0:
            fn_80086EC0(o, 0, c);
            break;
        case 1:
            fn_80086EC0(o, 1, c);
            break;
        }
        break;
    }
}

int fn_8011AE28(int mode, int idx)
{
    UnkGameP10* o = fn_8011AC90(idx);
    switch (mode) {
    case 1:
    case 2:
        if (mode == 1)
            return o->m18;
        return o->m14;
    case 3:
    case 5:
    case 6:
        switch (idx) {
        case 0:
            return o->m14;
        case 1:
            return o->m18;
        }
        break;
    }
    return 1;
}

void fn_8011AEB0(int mode, int idx, int c)
{
    UnkGameP10* o = fn_8011AC90(idx);
    switch (mode) {
    case 1:
    case 2:
        if (mode == 1)
            o->m18 = c;
        else
            o->m14 = c;
        break;
    case 3:
    case 5:
    case 6:
        switch (idx) {
        case 0:
            o->m14 = c;
            break;
        case 1:
            o->m18 = c;
            break;
        }
        break;
    }
}

void fn_8011AF34(Wid* self)
{
    int m = fn_8011AA4C();
    int v = 0xBBC;
    switch (m) {
    case 1:
        v = 0x4179;
        break;
    case 6: {
        int c = fn_800AEC80(fn_800AB5C8(lbl_80619D10))->mD8;
        v = 0x119;
        if (c == 1)
            v = 0x5C4A;
        break;
    }
    case 5:
        v = 0x5C4B;
        break;
    }
    self->fn_vslot29((const char*)v);
}

void fn_8011AFD4(int a, UnkLabel* w1, int b, UnkLabel* w2, int c, int d, UnkW13* w3)
{
    char buf[32];
    fn_804089B4(buf, lbl_805BC1A8, a);
    w1->fn_vslot30(buf);
    fn_804089B4(buf, lbl_805BC1A8, b);
    w2->fn_vslot30(buf);
    float r = (float)a / (float)b;
    if (!(r <= 1.0f))
        r = 1.0f;
    int t = (int)((float)c * r);
    w3->s13(t);
    w3->s10(d + c - t);
}

/* near-miss: retail keeps the quotient in r30 and w2 in r31 (copy `mr r0,r30` before the mulli); ours has them swapped and no copy. */
void fn_8011B148(int a, Wid* w1, int* p1, Wid* w2, int* p2)
{
    int t = a / 10;
    ((UnkSub*)((char*)w1 + 0x98))->fn_vslot6(a % 10);
    int* r;
    if (t == 0) {
        w2->fn_vslot8(0);
        r = p1;
    } else {
        ((UnkSub*)((char*)w2 + 0x98))->fn_vslot6(t);
        w2->fn_vslot8(1);
        r = p2;
        if (*p1 != 0)
            *p1 = 0;
    }
    if (*r == 0)
        fn_800CFB38(r);
}

void fn_8011B24C(int a, int b, int c, int d, int* p1, int* p2)
{
    if (a != b && fn_8001C394()->fn_8001CCD8() != 0) {
        float f = (float)c;
        float u;
        int x = (int)((float)a * 100.0f / f);
        int y = (int)((float)b * 100.0f / f);
        float s = (float)(b - a) / (float)d * 16.666668f;
        int z = (int)__builtin_fabs(s);
        if (y > x)
            *p1 = fn_800412AC(fn_8004072C(), 0xF, x, y, z, 0);
        else
            *p2 = fn_800412AC(fn_8004072C(), 0x10, x, y, z, 0);
    }
}

void fn_8011B3E8(int a, int* x, int* y)
{
    if (fn_8001C394()->fn_8001CCD8() != 0 && a == 0) {
        if (*x != -1) {
            fn_8004181C(fn_8004072C(), 0xF, *x, 0, 0, 0, 0);
            *x = -1;
        }
        if (*y != -1) {
            fn_8004181C(fn_8004072C(), 0x10, *y, 0, 0, 0, 0);
            *y = -1;
        }
    }
}

int fn_8011B494(int* p, int a, int c)
{
    int v = *p;
    if (v > 0) {
        *p = v - c;
        *p = *p < 0 ? 0 : *p;
    } else if (v < 0) {
        *p = v + c;
        *p = *p > 0 ? 0 : *p;
    }
    int r = a - *p;
    if (r < 0)
        r = 0;
    return r;
}

int fn_8011B4E4()
{
    if (fn_801A6DB8(fn_8011AA24(0))->m14 != 0) {
        int a = 1;
        UnkGame* g = fn_8011AA24(0);
        if (fn_801C1638(g, 0xA) == 0)
            a = 0;
        int b = fn_801C1638(g, 0xB) != 0;
        int c = fn_801C1638(g, 0xC) != 0;
        int r = 0;
        if (a != 0 || b != 0 || c != 0)
            r = 1;
        return r;
    }
    return 0;
}

void fn_8011B5A4()
{
    fn_801B5AD0(fn_8011AA24(0)->m700->m3C4, 2);
}

int fn_8011B5D8(UnkIdList* a, int* b)
{
    return fn_8011B65C(7, a, b);
}

int fn_8011B604(UnkIdList* a, int* b)
{
    return fn_8011B65C(3, a, b);
}

int fn_8011B630(UnkIdList* a, int* b)
{
    return fn_8011B65C(4, a, b);
}

int fn_8011B65C(int a, UnkIdList* o, int* out)
{
    int r = 0;
    int i = 0;
    if (r < o->m235) {
        do {
            int id = o->m238[(unsigned char)i].m0;
            *out = id;
            if (fn_8009764C(o, a, fn_800968C0(o, id, 1), 0) > 0) {
                r = 1;
                break;
            }
            i++;
        } while (i < o->m235);
    }
    return r;
}

int fn_8011B6F8(int a, UnkPlr* p)
{
    void* x = p->m44C->m6F8;
    int y = fn_800B55A8(fn_800B555C());
    int z = fn_8006A1B4(x);
    int w = fn_800B59DC(fn_800B555C());
    if (z != 0 || y != 0 || w != 0)
        return fn_80253DB0(&p->m588, a, 1);
    return fn_80253F9C(&p->m588, a);
}

int fn_8011B784(int a, UnkPlr* p, int c)
{
    void* x = p->m44C->m6F8;
    int y = fn_800B55A8(fn_800B555C());
    int z = fn_8006A1B4(x);
    int w = fn_800B59DC(fn_800B555C());
    if (z != 0 || y != 0 || w != 0)
        return fn_80253F0C(&p->m588, a, c, 1);
    return fn_802540E4(&p->m588, a, c);
}

float fn_8011B81C(int a, UnkPlr* p, int c)
{
    float r = lbl_805BFD30;
    void* x = p->m44C->m6F8;
    int y = fn_800B55A8(fn_800B555C());
    int z = fn_8006A1B4(x);
    int w = fn_800B59DC(fn_800B555C());
    if (z != 0 || y != 0 || w != 0)
        r = fn_80253F54(&p->m588, a, c, 1);
    else
        r = fn_80254128(&p->m588, a, c);
    return r;
}

int fn_8011B8C8(int a, UnkPlr* p)
{
    void* x = p->m44C->m6F8;
    int y = fn_800B55A8(fn_800B555C());
    int z = fn_8006A1B4(x);
    int w = fn_800B59DC(fn_800B555C());
    if (z != 0 || y != 0 || w != 0)
        return fn_80253DF4(&p->m588, a, 1);
    return fn_80253FDC(&p->m588, a);
}

float fn_8011B954(int a, UnkPlr* p)
{
    float r = lbl_805BFD34;
    void* x = p->m44C->m6F8;
    int y = fn_800B55A8(fn_800B555C());
    int z = fn_8006A1B4(x);
    int w = fn_800B59DC(fn_800B555C());
    if (z != 0 || y != 0 || w != 0)
        r = fn_80253E38(&p->m588, a, 1);
    else
        r = fn_8025401C(&p->m588, a);
    return r;
}

int fn_8011B9F4(int a, UnkPlr* p)
{
    void* x = p->m44C->m6F8;
    int y = fn_800B55A8(fn_800B555C());
    int z = fn_8006A1B4(x);
    int w = fn_800B59DC(fn_800B555C());
    if (z != 0 || y != 0 || w != 0)
        return fn_80253E7C(&p->m588, a, 2, 1);
    return fn_8025405C(&p->m588, a, 2);
}

float fn_8011BA88(int a, UnkPlr* p)
{
    float r = lbl_805BFD38;
    void* x = p->m44C->m6F8;
    int y = fn_800B55A8(fn_800B555C());
    int z = fn_8006A1B4(x);
    int w = fn_800B59DC(fn_800B555C());
    if (z != 0 || y != 0 || w != 0)
        r = fn_80253EC4(&p->m588, a, 2, 1);
    else
        r = fn_802540A0(&p->m588, a, 2);
    return r;
}

int fn_8011BB30(void* a, int b)
{
    return fn_8011BB78(a, b, 1);
}

int fn_8011BB54(void* a, int b)
{
    return fn_8011BB78(a, b, 0);
}

int fn_8011BB78(void* gv, int side, int flag)
{
    UnkGame* g = (UnkGame*)gv;
    int cnt = 0;
    UnkGameP700* p = g->m700;
    UnkPlayerRec* team = (UnkPlayerRec*)((char*)g->m6F8->m14 + side * 0xE64);
    int n = team->m3E4;
    for (int i = 0; i < n; i++) {
        unsigned char k = i;
        UnkEnt34* b = (UnkEnt34*)team->m3E8;
        UnkGame* o = (UnkGame*)fn_801A49F0(g, side, EntAt(b, k));
        if (fn_80097148(team, k) == 0) {
            if (!HasFF(p->m3CC, o) && !HasFF(p->m3C8, o)) {
                int t = fn_8025416C((Unk8024EF40_W*)((char*)o + 0x588), 5);
                if (flag != 0) {
                    if (t == 0 || t == 10)
                        cnt++;
                } else {
                    if (t != 0 && t != 10)
                        cnt++;
                }
            }
        }
    }
    return cnt;
}

int fn_8011BC98(int a)
{
    int x = 0;
    int y = 0;
    UnkGame* g = fn_8011AA24(0);
    fn_8017DD80(g->m700, g->m788, &x, &y);
    int r = 0;
    switch (a) {
    case 0:
        r = x;
        break;
    case 1:
        r = y;
        break;
    }
    return r;
}

int fn_8011BD0C(void* a, int b)
{
    if (fn_8011BB54(a, b) <= 0)
        return 0;
    return 1;
}

int fn_8011BD3C(UnkGame* g, int b)
{
    int r = 0;
    if (fn_8011BB30(g, b) > 0) {
        if (fn_8006BC74(g->m6F8, b) != 0)
            r = 1;
    }
    return r;
}

int fn_8011BD94(UnkGame* g, int a)
{
    if (a == (g->m6F8->m14->m1CD0 == 0))
        return 0;
    if (fn_8011BD0C(g, a) == 0)
        return 0;
    if (fn_8017C8C8(g->m700) != 0 || fn_8017C8C0(g->m700) != 0)
        return 0;
    return 1;
}

int fn_8011BE1C(UnkGame* g, int side)
{
    int r = 0;
    if (side == (g->m6F8->m14->m1CD0 == 0))
        return r;
    if (fn_8011BD0C(g, side) != 0) {
        UnkPlayerRec* team = (UnkPlayerRec*)((char*)g->m6F8->m14 + side * 0xE64);
        int n = fn_8011BB30(g, side);
        for (int i = 10; i <= 12; i++) {
            if (Roster(g, i) != 0) {
                int v = Roster(g, i)->m704;
                if (v != fn_80097210(team, 0) || n > 0)
                    return 1;
            }
        }
    }
    return r;
}

int fn_8011BF1C(UnkGame* g, int a)
{
    if (fn_80081B60(g->m6F8->m14) != 0)
        return 0;
    if (fn_8011BD0C(g, a) == 0)
        return 0;
    int n = fn_8011BB30(g, a);
    int f = 0;
    if (n > 0) {
        if (fn_8006BC74(g->m6F8, a) != 0)
            f = 1;
    }
    return f;
}

void* fn_8011BFAC(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->SetVptr(lbl_8065A918);
    self->m134 = 0;
    return self;
}

void fn_8011BFFC(void* self, int a)
{
    *(const void**)((char*)self + 0x3C) = lbl_8065A918;
    fn_800AB6B8(lbl_80619D10);
    fn_8035686C(self, a);
}

void fn_8011C04C(Unk800C7B40_Widget* self)
{
    fn_800ECF18(self);
    fn_800B555C()->m570 = -1;
    fn_802D7ACC();
    fn_802D8294(1);
    fn_802D7A74();
    lbl_8061B8C0->m24 = 0;
    fn_802D7ACC();
    fn_800C8044(self->fn_vslot32(lbl_805BEAE0, 1))->fn_vslot8(lbl_806192E0->m4->m10->m120 == 1);
    fn_800AB618(lbl_80619D10);
}

void fn_8011C114(void* self)
{
    fn_800ED254(self);
    fn_802DC9C0();
    lbl_8061B8C0->m24 = 1;
    fn_802D7ADC();
    fn_802D8294(2);
    fn_802D7A64();
    fn_802D7ADC();
}

void fn_8011C15C(Unk80117D20_Scr* self)
{
    fn_800EC8EC(self);
    fn_800ECB0C(self);
    self->fn_vslot85();
    int v = self->m134;
    if (v > 0 && v < (int)lbl_8061A328) {
        self->m134 = 0;
        if (((Unk80619D10*)lbl_80619D10)->s25() != 0)
            self->fn_vslot87();
        else
            self->fn_vslot86();
    }
}

int fn_8011C228(Unk80117D20_Scr* self, int a)
{
    if (lbl_806192E0->m4->m10->m120 == 1) {
        char name[16];
        char* np = name;
        fn_8035682C(np);
        fn_8040B830(np, lbl_805BA240, 0xF);
        np[15] = 0;
        if (lbl_8061A32C == 0)
            lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
        fn_800B7B4C(lbl_8061A32C, np, 0);
    } else if (self->fn_vslot85() != 0) {
        int z = self->m134;
        if (z == 0) {
            int ok = fn_8011C3EC(self, a);
            fn_800B555C()->m570 = a;
            if (ok != 0) {
                char name[16];
                char* np = name;
                fn_8035682C(np);
                fn_8040B830(np, lbl_805BE5E4, 0xF);
                np[15] = z;
                if (lbl_8061A32C == 0)
                    lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
                fn_800B7B4C(lbl_8061A32C, np, 0);
            } else {
                fn_800B555C()->m570 = a;
                char name[16];
                char* np = name;
                fn_8035682C(np);
                fn_8040B830(np, lbl_805BEC18, 0xF);
                np[15] = ok;
                if (lbl_8061A32C == 0)
                    lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
                fn_800B7B4C(lbl_8061A32C, np, 0);
            }
        }
    }
    return 1;
}

int fn_8011C3B4()
{
    return fn_8011AA24(0)->m65C != 0;
}

int fn_8011C3EC(Wid* self, int a)
{
    int r = 0;
    if (self->fn_vslot88() != 0) {
        UnkGameP10* p0 = fn_8011AC90(0);
        UnkGameP10* p1 = fn_8011AC90(1);
        if (a == p0->m70 || a == p0->m6C || a == p1->m70 || a == p1->m6C)
            r = 1;
    } else {
        UnkGameP10* p = fn_8011AA24(0)->m6F8->m10;
        if (a == p->m70 || a == p->m6C)
            r = 1;
    }
    return r;
}

void fn_8011C4A8(Wid* self, int a)
{
    if (a == 0xA0) {
        char name[16];
        char* np = name;
        fn_8035682C(np);
        fn_8040B830(np, lbl_805BE5E4, 0xF);
        np[15] = 0;
        if (lbl_8061A32C == 0)
            lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
        fn_800B7B4C(lbl_8061A32C, np, self);
    }
}

void fn_8011C534(Unk80117D20_Scr* self)
{
    fn_800CFB38(fn_800ED2B0(self, lbl_805BE690));
    fn_800412AC(fn_8004072C(), 0x12, 0, 0, 0, 0);
    self->m134 = (int)(lbl_8061A328 + 0x78);
    lbl_8068B618->m24 = 1;
    fn_802D7ADC();
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    fn_801389A4(fn_800B7AB8(lbl_8061A32C, lbl_805BA230), 0);
}

}
