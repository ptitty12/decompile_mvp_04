/*
 * Game code, .text 0x8011243C-0x801164AC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8010E0F4.h"
#include "game/tu_8001B190.h"

typedef Unk8010E0F4_Scr UnkScrA;
typedef Unk80114A20_Scr Scr;

extern const char lbl_805BE138[];
typedef Unk800C7B40_Widget Wid;
inline void SetSub(Wid* w, int v)
{
    ((UnkSub*)((char*)w + 0xDC))->fn_vslot6(v);
}
extern const char lbl_805BC980[];
extern const char lbl_805BC988[];
extern const char lbl_805BC19C[];
extern const char lbl_805BF19C[];
extern const char lbl_805B955C[];
extern const char lbl_8065B888[];
extern const char lbl_80649DA0[];
struct UnkEv {
    int m0;
    const void* m4;
    UnkEv(int t)
    {
        m0 = t;
        m4 = lbl_8065B888;
    }
    ~UnkEv() { m4 = lbl_80649DA0; }
};
extern const char lbl_8065C4E0[];
extern const char lbl_80650610[];
extern const char lbl_80650628[];
extern const float lbl_805BFAE8;
Unk8001BC8C* fn_8001BC4C();
extern const char lbl_805BA6D8[];
extern const char lbl_805BADC8[];

// PROTOS-BEGIN
void fn_8011AEB0(int a, int b, int c);

struct UnkQ4 {
    int m[4];
};
extern UnkQ4 lbl_805BFA98;
extern const char lbl_805BFAF8[];
extern const char lbl_805BAFF0[];
int fn_80125180(Unk800C7B40_Widget* self, int a, int id);
void fn_80116AA8(Scr* self);
void fn_80116CA8(Scr* self);
void fn_80116EE8(Scr* self);
void fn_80117288(Scr* self);
extern "C" UnkTextBox* fn_80115D9C(Scr* self, int a);

extern const char lbl_805BFAF0[];
extern const char lbl_805BA04C[];
extern const char lbl_805BA040[];
extern const char lbl_805BA050[];
extern const char lbl_805BA054[];
extern const char lbl_805BA058[];
extern const char* lbl_8061B3F0[];

struct Ui1A0 {
    char pad0[0x50];
    int m50;
    char pad54[0x124 - 0x54];
    int m124;
    char pad128[0x184 - 0x128];
    int m184;
};

struct UnkEvR {
    int id;
    const void* vt;
};
struct UnkMsgEv {
    char name[16];
    UnkEvR e;
};
extern "C" void fn_80117984(Scr* self, int b);
extern "C" void fn_80117844(Scr* self);

extern "C" void fn_80117840(Scr* self);
extern "C" void fn_80116100(Scr* self);
extern "C" void fn_80116268(Scr* self);
extern "C" void fn_801164AC(Scr* self);
extern "C" void fn_801167AC(Scr* self);

extern "C" {
void fn_801138FC(UnkScrA* self);
void fn_8011415C(UnkScrA* self);
void fn_801142C4();
void fn_80114318(UnkScrA* self, int a);
int fn_80114368(UnkScrA* self, char* a);
void fn_80114528(UnkScrA* self);
void fn_8011452C(UnkScrA* self);
void fn_801145C0(UnkScrA* self);
void fn_80114664(UnkScrA* self, int b);
void fn_801147E4(int a, UnkScrA* b);
void fn_80114840(int a, UnkScrA* b);
void fn_8011489C(UnkScrA* self);
void fn_8011496C(UnkScrA* self);
void fn_80114A00(UnkScrA* self);
void* fn_80114A20(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
int fn_80114D14(Scr* self, int a);
void fn_80114E7C(int a, Scr* b);
void fn_80114F2C(Scr* self);
void fn_8011566C(Scr* self);
int fn_801156A0(Scr* self, int a);
int fn_801156FC(Scr* self, int a);
int fn_80115758(Scr* self, int a);
int fn_801157B4(Scr* self, int a);
int fn_80115810(Scr* self, int a);
int fn_8011586C(Scr* self, int a);
int fn_801158C8(Scr* self, int a);
int fn_80115924(Scr* self, int a);
}
// PROTOS-END
extern "C" {
void fn_800ED310(UnkScrA* self);
int fn_802D7CE0(int a, int b);
int fn_8040B574(const char* a, const char* b);
int fn_802D7D64(int a);
int fn_80086D34(UnkGameP10* p, int i);
void fn_8037893C(void* a, int b, void* ev, int c, int d);
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80134E38(void* p, int a);
void fn_800ECAA4(UnkScrA* self);
void fn_800ED254(Scr* self);
void fn_8011489C(UnkScrA* self);
void fn_8011496C(UnkScrA* self);
void fn_80110F7C(UnkScrA* self);
void fn_801114CC(UnkScrA* self);
void fn_80111E50(UnkScrA* self);
void fn_801120EC(UnkScrA* self);
void fn_80117764(Scr* self);
void fn_80117634(Scr* self);
void fn_80131F34(Unk800C7B40_Widget* w, void* self, void (*cb)(int, void*), int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
}

extern "C" {

void fn_801138FC(UnkScrA* self)
{
    UnkGameP6F8* p = fn_8011AA24(0)->m6F8;
    Wid* w0 = fn_800C8058(fn_800C805C(self->m150->fn_vslot73(0, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1));
    if (fn_802D7CE0(0, 0) == 0 || fn_802D7D64(0) == 0)
        SetSub(w0, 0);
    else
        SetSub(w0, fn_80086D34(p->m10, 0));
    Wid* w1 = fn_800C8058(fn_800C805C(self->m150->fn_vslot73(1, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1));
    if (fn_802D7CE0(1, 0) == 0 || fn_802D7D64(1) == 0)
        SetSub(w1, 0);
    else
        SetSub(w1, fn_80086D34(p->m10, 1));
    int v2;
    if (fn_802D7CE0(2, 0) == 0 || fn_802D7D64(2) == 0)
        v2 = 0;
    else
        v2 = fn_80086D34(p->m10, 2);
    ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m150->fn_vslot73(2, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot6(v2);
    int v3;
    if (fn_802D7CE0(3, 0) == 0 || fn_802D7D64(3) == 0)
        v3 = 0;
    else
        v3 = fn_80086D34(p->m10, 3);
    ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m150->fn_vslot73(3, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot6(v3);
}

void fn_8011415C(UnkScrA* self)
{
    Unk8001BC8C* g = fn_8001BC4C();
    float t0 = (float)self->m138;
    g->fn_8001C05C(0, t0 * lbl_805BFAE8, 1);
    float t1 = (float)(int)self->m13C;
    g->fn_8001C05C(3, t1 * lbl_805BFAE8, 1);
    float t2 = (float)self->m140;
    g->fn_8001C05C(1, t2 * lbl_805BFAE8, 1);
    float t3 = (float)self->m144;
    g->fn_8001C05C(4, t3 * lbl_805BFAE8, 1);
    float t4 = (float)(int)self->m148;
    g->fn_8001C05C(2, t4 * lbl_805BFAE8, 1);
}

void fn_801142C4()
{
    int v = fn_8011AA24(0)->m6F8->m10->m124;
    fn_802D61AC(fn_801A4CE8(fn_8011AA24(0), 1), v, 0);
}

void fn_80114318(UnkScrA* self, int a)
{
    fn_800ED310(self);
    self->m150->fn_vslot14(a);
}

int fn_80114368(UnkScrA* self, char* a)
{
    const char* nm = a + 0xC;
    if ((fn_8040B574(nm, lbl_805BC988) == 0 || fn_8040B574(nm, lbl_805BC980) == 0) && self->m134 == 0) {
        UnkSub* s1 = (UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m150->fn_vslot73(self->m158, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC);
        int v = s1->fn_vslot5();
        if (self->m15C != v) {
            self->m15C = v;
            int c = 1;
            if (v == 0)
                c = 2;
            else if (v == 3)
                c = 0;
            UnkSub* s2 = (UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m150->fn_vslot73(2, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC);
            s2->fn_vslot8(c);
        }
    }
    return 0;
}

void fn_80114528(UnkScrA* self)
{
}

void fn_8011452C(UnkScrA* self)
{
    switch (self->m134) {
    case 0:
        fn_80110F7C(self);
        fn_80114528(self);
        break;
    case 1:
        fn_801114CC(self);
        fn_80114528(self);
        break;
    case 2:
        fn_80111E50(self);
        break;
    case 3:
        fn_801120EC(self);
        fn_80114528(self);
        break;
    }
}

void fn_801145C0(UnkScrA* self)
{
    Unk800C7B40_Widget* w = (Unk800C7B40_Widget*)self->m16C[0];
    w->fn_vslot16(0);
    w = (Unk800C7B40_Widget*)self->m16C[0];
    w->fn_vslot8(0);
    self->fn_vslot16(1);
    self->m154->fn_vslot16(1);
}

void fn_80114664(UnkScrA* self, int b)
{
    if (self->m16C[0] == 0 || (fn_801145C0(self), self->m16C[0] == 0)) {
        if (lbl_8061A32C == 0)
            lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
        Unk800C7B40_Widget* w = fn_800B7AB8(lbl_8061A32C, lbl_805BA6D8);
        self->m16C[0] = (int)w;
        *(int*)((char*)w + 0x2F0) = -0x63;
    }
    self->fn_vslot16(0);
    self->m154->fn_vslot16(0);
    if (b != 0)
        fn_80131F34((Unk800C7B40_Widget*)self->m16C[0], self, fn_801147E4, 0, 0x5CDB, 2, -1, 1, 0x26DF, 0x26DE, 0, 0, 0, 0);
    else
        fn_80131F34((Unk800C7B40_Widget*)self->m16C[0], self, fn_80114840, 0, 0x5CDB, 2, -1, 1, 0x26DF, 0x26DE, b, b, b, b);
    ((Unk800C7B40_Widget*)self->m16C[0])->fn_vslot86();
}

void fn_801147E4(int a, UnkScrA* b)
{
    if (a) {
        if (a == 1) {
            lbl_806192E0->m4->mC->m600 = a;
            fn_8011489C(b);
        }
    }
    fn_801145C0(b);
}

void fn_80114840(int a, UnkScrA* b)
{
    if (a) {
        if (a == 1) {
            lbl_806192E0->m4->mC->m600 = a;
            fn_8011496C(b);
        }
    }
    fn_801145C0(b);
}

void fn_8011489C(UnkScrA* self)
{
    char nm[16];
    char* np = nm;
    fn_8011452C(self);
    fn_80114528(self);
    fn_8035682C(np);
    fn_8040B830(np, lbl_805BADC8, 0xF);
    np[15] = 0;
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    fn_800B7B4C(lbl_8061A32C, np, self);
    /* Stack event: id at +0, vptr at +4 (stores at 0x8011492C/0x80114930).
     * The empty destructor gives the same object mode as fn_80117BBC's event. */
    struct Unk8011489C_Ev {
        int id;
        const void* vt;
        ~Unk8011489C_Ev() {}
    };
    Unk8011489C_Ev ev;
    const void* base = lbl_80649DA0;
    ev.vt = base;
    ev.id = 0x9E;
    ev.vt = lbl_8065B888;
    fn_8037893C((char*)fn_8011AA24(0) + 0x704, ev.id, &ev, 0, 0);
    ev.vt = base;
}

void fn_8011496C(UnkScrA* self)
{
    char nm[16];
    char* np = nm;
    fn_8035682C(np);
    fn_8040B830(np, lbl_805B955C, 0xF);
    np[15] = 0;
    fn_8011452C(self);
    fn_80114528(self);
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    fn_800B7B4C(lbl_8061A32C, np, self);
}

void fn_80114A00(UnkScrA* self)
{
    fn_800ECAA4(self);
}

/* near-miss: clone of fn_8010FE70, same argument-order difference. */

void* fn_80114A20(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->SetVptr(lbl_8065C4E0);
    fn_80134E38(self->m134, 0);
    self->m17C = lbl_80650610;
    self->SetVptr(lbl_80650628);
    self->m198 = 0;
    self->m19C = 0;
    self->m1A8 = 0;
    self->m1AC = 0;
    self->m1B0 = 0;
    self->m1B4 = 0;
    self->m1B8 = 0;
    self->m1BC[0] = 0;
    self->m1A4 = 0;
    self->m1A0 = 0;
    return self;
}

int fn_80114AB8(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        if (self->m184 == 0 && self->m180 == 1) {
            UnkMgrA* mg = lbl_806192E0->m4;
            int x = ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(self->m1A8, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
            int y = ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(self->m1B0, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
            if ((self->m1AC != x || self->m1B4 != y) && mg->mC->m600 == 0) {
                fn_80117984(self, 1);
                return 1;
            }
        }
        fn_80117844(self);
        UnkMsgEv s;
        char* np = s.name;
        fn_8035682C(np);
        fn_8040B830(np, lbl_805BADC8, 15);
        np[15] = 0;
        if (lbl_8061A32C == 0)
            lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
        fn_800B7B4C(lbl_8061A32C, np, self);
        const void* base = lbl_80649DA0;
        s.e.id = 0x9E;
        s.e.vt = lbl_8065B888;
        fn_8037893C((char*)&fn_8011AA24(0)->m704, s.e.id, &s.e, 0, 0);
        s.e.vt = base;
    }
    return 1;
}

int fn_80114D14(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        int v = self->m1B8;
        if (v == 0) {
            char name[16];
            char* np = name;
            fn_8035682C(np);
            fn_8040B830(np, lbl_805BE138, 0xF);
            np[15] = v;
            self->fn_vslot80(0);
            if (lbl_8061A32C == 0)
                lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
            fn_800B7B4C(lbl_8061A32C, np, self);
        } else {
            if (lbl_8061A32C == 0)
                lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
            Unk800C7B40_Widget* w = fn_800B7AB8(lbl_8061A32C, lbl_805BA6D8);
            *(int*)((char*)w + 0x2F0) = -0x63;
            fn_80131F34(w, self, fn_80114E7C, 0, 0x3364, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
            w->fn_vslot86();
        }
    }
    return 1;
}

/* near-miss: clone of fn_8010FFD8, same argument-order difference. */

void fn_80114E7C(int a, Scr* b)
{
    if (a == 1) {
        fn_80114F2C(b);
        char name[16];
        char* np = name;
        fn_8035682C(np);
        fn_8040B830(np, lbl_805BE138, 0xF);
        np[15] = 0;
        b->fn_vslot80(1);
        if (lbl_8061A32C == 0)
            lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
        fn_800B7B4C(lbl_8061A32C, np, b);
    }
}

void fn_80114F2C(Scr* self)
{
    fn_80117764(self);
    if (self->m184 == 3)
        fn_80117634(self);
}

/* near-miss: 1 slot; retail's case 2 loads the lbl_8061A32C high half as `lis r30,0x8062` (plain immediate), ours is the symbol relocation */
int fn_80114F6C(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        char name[16];
        char* np = name;
        fn_8035682C(np);
        fn_8040B830(np, lbl_805B955C, 0xF);
        np[15] = 0;
        switch (self->m184) {
        case 0:
            if (self->m180 == 1) {
                int x = ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(self->m1A8, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
                int y = ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(self->m1B0, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
                UnkMgrA* mg = lbl_806192E0->m4;
                if ((self->m1AC != x || self->m1B4 != y) && mg->mC->m600 == 0) {
                    fn_80117984(self, 0);
                    break;
                }
            }
            fn_80116100(self);
            fn_80117840(self);
            if (lbl_8061A32C == 0)
                lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
            fn_800B7B4C(lbl_8061A32C, name, self);
            break;
        case 1:
            fn_80116268(self);
            fn_80117840(self);
            if (lbl_8061A32C == 0)
                lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
            fn_800B7B4C(lbl_8061A32C, name, self);
            break;
        case 2:
            fn_801164AC(self);
            if (lbl_8061A32C == 0)
                lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
            fn_800B7B4C(lbl_8061A32C, np, self);
            break;
        case 3:
            fn_801167AC(self);
            fn_80117840(self);
            if (lbl_8061A32C == 0)
                lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
            fn_800B7B4C(lbl_8061A32C, np, self);
            break;
        }
    }
    return 1;
}

void fn_8011566C(Scr* self)
{
    fn_800ED254(self);
    fn_80117764(self);
}

int fn_801156A0(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot50();
    return 1;
}

int fn_801156FC(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot51();
    return 1;
}

int fn_80115758(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot52();
    return 1;
}

int fn_801157B4(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot53();
    return 1;
}

int fn_80115810(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot54();
    return 1;
}

int fn_8011586C(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot55();
    return 1;
}

int fn_801158C8(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot56();
    return 1;
}

int fn_80115924(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot57();
    return 1;
}

}

extern "C" {
UnkTextBox* fn_80115D9C(Scr* self, int a)
{
    UnkTextBox* r = 0;
    Unk800C7B40_Widget* c;
    switch (a) {
    case 0:
        c = 0;
        switch (self->m180) {
        case 3:
        case 1:
            c = fn_800C8044(self->fn_vslot32(lbl_805BFAF0, 1));
            break;
        case 2:
            c = fn_800C8044(self->fn_vslot32(lbl_805BA04C, 1));
            break;
        }
        goto tail;
    case 1:
        c = 0;
        switch (self->m180) {
        case 1:
            c = fn_800C8044(self->fn_vslot32(lbl_805BA040, 1));
            break;
        case 2:
            c = fn_800C8044(self->fn_vslot32(lbl_805BA04C, 1));
            break;
        case 3:
            c = fn_800C8044(self->fn_vslot32(lbl_805BA050, 1));
            break;
        case 6:
            c = fn_800C8044(self->fn_vslot32(lbl_805BA058, 1));
            break;
        case 5:
            c = fn_800C8044(self->fn_vslot32(lbl_805BA054, 1));
            break;
        }
    tail:
        c->fn_vslot8(1);
        r = fn_800C8060(c->fn_vslot32(lbl_8061B3F0[a], 1));
        break;
    case 2:
    case 3:
        r = fn_800C8060(self->fn_vslot32(lbl_8061B3F0[a], 1));
        break;
    }
    return r;
}

void fn_80115F60(Scr* self, int a)
{
    self->m184 = a;
    fn_80125180(self->m19C, 0, 0x1A0A);
    UnkQ4 q = lbl_805BFA98;
    fn_800C8040(fn_800C8044(self->fn_vslot32(lbl_805BFAF8, 1))->fn_vslot32(lbl_805BAFF0, 1))->fn_vslot29((const char*)q.m[self->m184]);
    if (self->m198 != 0)
        self->m198->fn_vslot8(0);
    self->m198 = (Unk800C7B40_Widget*)fn_80115D9C(self, a);
    fn_80125180(self->m19C, 1, 0x26DF);
    switch (a) {
    case 0:
        fn_80116AA8(self);
        break;
    case 1:
        fn_80116CA8(self);
        break;
    case 2:
        fn_80116EE8(self);
        break;
    case 3:
        fn_80117288(self);
        break;
    }
    self->m198->fn_vslot8(1);
}

void fn_80116100(Scr* self)
{
    int a = ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(0, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
    int b = ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(1, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
    fn_8011AEB0(self->m180, 0, a);
    fn_8011AEB0(self->m180, 1, b);
}

void fn_80116268(Scr* self)
{
    switch (self->m180) {
    case 0:
        break;
    case 6: {
        int a = ((UnkSub*)((char*)fn_800C8058(self->m198->fn_vslot73(0, 0)->fn_vslot33(10, 1)) + 0xDC))->fn_vslot5();
        int b = ((UnkSub*)((char*)fn_800C8058(self->m198->fn_vslot73(1, 0)->fn_vslot33(10, 1)) + 0xDC))->fn_vslot5();
        ((Ui1A0*)self->m1A0)->m124 = a;
        ((Ui1A0*)self->m1A0)->m50 = b;
        break;
    }
    case 5:
        ((Ui1A0*)self->m1A0)->m184 = ((UnkSub*)((char*)fn_800C8058(self->m198->fn_vslot73(0, 0)->fn_vslot33(10, 1)) + 0xDC))->fn_vslot5();
        break;
    case 3: {
        int v = ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(0, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
        ((Ui1A0*)self->m1A0)->m124 = v;
        if (self->m1A4 != 0)
            ((Ui1A0*)self->m1A4)->m124 = v;
        break;
    }
    }
}
}
