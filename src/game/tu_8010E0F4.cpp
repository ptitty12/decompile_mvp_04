/*
 * Game code, .text 0x8010E0F4-0x8011243C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8010E0F4.h"
#include "game/tu_8001B190.h"

typedef Unk8010E0F4_Scr Scr;
inline void Init(char* n, const char* s)
{
    fn_8035682C(n);
    fn_8040B830(n, s, 0xF);
    n[15] = 0;
}
struct UnkName {
    char s[16];
    UnkName(const char* x)
    {
        fn_8035682C(this);
        fn_8040B830(this, x, 0xF);
        s[15] = 0;
    }
};

struct Unk80687CB8 {
    Unk800C7B40_Widget* m0;
    int m4;
    Unk800C7B40_Widget* m8;
    int mC;
};
extern Unk80687CB8 lbl_80687CB8;
extern const char* lbl_8061B3E0[];
extern const char lbl_805BFA5C[];
extern const char lbl_805BFA70[];
inline int AtI(int* p, int i)
{
    return p[i];
}
extern const char lbl_806508D0[];
extern const char lbl_805BAF70[];
extern const char lbl_805BDDEC[];
extern const char lbl_805BC1A8[];
extern char lbl_805B9A30;
extern int lbl_8061977C;
struct UnkPly {
    char pad0[0x704];
    int m704;
    int m708;
};
struct UnkCMgr;
struct UnkQ4 {
    int m[4];
};
extern UnkQ4 lbl_805BFA98;
extern const char lbl_805BE1D8[];
extern const char lbl_805BE5E4[];
extern const char lbl_805BE234[];
extern const char lbl_805BA760[];
extern const char lbl_805BC19C[];
extern const char lbl_805BAF40[];
extern const char lbl_805BE138[];
extern const char lbl_805BA6D8[];

Unk8001BC8C* fn_8001BC4C();

extern const char lbl_805BADC8[];
extern const char lbl_8065B888[];
extern const char lbl_80649DA0[];
extern const char lbl_805BF19C[];
struct UnkEvR {
    int id;
    const void* vt;
};
struct UnkMsgEv {
    char name[16];
    UnkEvR e;
};
void fn_8037893C(char* p, int id, UnkEvR* e, int a, int b);
extern "C" void fn_8011452C(Scr* self);
extern "C" void fn_80114664(Scr* self, int b);

extern "C" {
void fn_8010F1E4(Scr* self);
void fn_8010D33C(Scr* self, int a);
void fn_8010EFD0(Scr* self, Unk800C7B40_Widget* w, int i);
void fn_8010A808(Scr* self);
void fn_8010B6B8(Scr* self);
void fn_8010BF88(Scr* self);
void fn_800EC648(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_801142C4(Scr* self);
void fn_8011415C(Scr* self);
void fn_800ED254(Scr* self);
int fn_804089B4(char* buf, const char* fmt, ...);
int fn_8040B320(void* p, int c, int n, ...);
int fn_80090880(int mgr, int id);
int fn_8011B8C8(int a, UnkPly* p);
int fn_8011B9F4(int a, UnkPly* p);
int fn_8011B784(int a, UnkPly* p, int c);
float fn_8011B954(int a, UnkPly* p);
float fn_8011B81C(int a, UnkPly* p, int c);
void fn_80119FF0(char* buf, float v);
void fn_80119F48(char* buf, float v);
UnkPly* fn_801A4A94(UnkGame* g, int a);
void fn_800DE274(UnkTextArg* p, UnkPly* t, int f);
UnkCMgr* fn_800C33D0();
void fn_800C3DCC(UnkCMgr* m, Unk800C7B40_Widget* w, UnkPly* t);
int fn_800DC0F4(UnkTeamArr* t, int a, int b);
void fn_800E0AD4(Unk800C7B40_Widget* w, int a, int b, int c, int d);
void fn_8010F5E8(Scr* self, UnkTextBox* w, UnkPly* t);
void fn_8010F7E0(Scr* self, UnkTextBox* w, UnkPly* t);
int fn_80125180(Unk800C7B40_Widget* self, int a, int id);
UnkTextBox* fn_80110D90(Scr* self, int a);
void fn_8011243C(Scr* self);
void fn_80112D90(Scr* self);
void fn_801138FC(Scr* self);
void fn_80113CA8(Scr* self);
int fn_8006BC74(void* p);
int fn_801059E4();
int fn_8017E030(UnkGameP700* a, int b, int c);
void fn_8010F2CC(Scr* self);
int fn_8010EAF4(Scr* self);
void fn_8010F9CC(Scr* self, int a);
void fn_8012E1C4(Unk800C7B40_Widget* w, int a, int b);
void fn_8010FFD8(int a, Scr* b);
void fn_80131F34(Unk800C7B40_Widget* w, Scr* self, void (*cb)(int, Scr*), int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
}

// PROTOS-BEGIN
extern "C" {
int fn_8010E0F4(Scr* self, Unk800C7B40_Widget* a);
int fn_8010E190(Scr* self, Scr* a, int unused, int c);
int fn_8010E40C(Scr* self, Scr* a, int b, int c);
void fn_8010E4BC(Scr* self);
int fn_8010E4FC(Scr* self, int a);
int fn_8010E5FC(Scr* self, int a);
int fn_8010E69C(Scr* self, int a);
int fn_8010E79C(Scr* self, int a);
int fn_8010E83C(Scr* self, int a);
int fn_8010E8F0(Scr* self, int a);
int fn_8010E998(Scr* self, int a);
int fn_8010EA4C(Scr* self, int a);
int fn_8010EAF4(Scr* self);
void fn_8010EF84(Scr* self);
void fn_8010F1E4(Scr* self);
void fn_8010F290(Scr* self);
void fn_8010F2CC(Scr* self);
void fn_8010F494(Scr* self, int a);
int fn_8010F4D4(int a, int b);
void fn_8010F550(Scr* self);
void fn_8010F5E8(Scr* self, UnkTextBox* w, UnkPly* a);
void fn_8010F7E0(Scr* self, UnkTextBox* w, UnkPly* a);
void fn_8010F9CC(Scr* self, int a);
void* fn_8010FBB0(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
int fn_8010FE70(Scr* self, int a);
void fn_8010FFD8(int a, Scr* b);
void fn_80110088(Scr* self);
void fn_80110A7C(Scr* self);
int fn_80110AB0(Scr* self, int a);
int fn_80110B0C(Scr* self, int a);
int fn_80110B68(Scr* self, int a);
int fn_80110BC4(Scr* self, int a);
int fn_80110C20(Scr* self, int a);
int fn_80110C7C(Scr* self, int a);
int fn_80110CD8(Scr* self, int a);
int fn_80110D34(Scr* self, int a);
UnkTextBox* fn_80110D90(Scr* self, int a);
void fn_80110DDC(Scr* self, int a);
}
// PROTOS-END

extern "C" {

int fn_8010E0F4(Scr* self, Unk800C7B40_Widget* a)
{
    if (a == self->fn_vslot29(lbl_805BFA5C) || a == self->fn_vslot29(lbl_805BFA70)) {
        fn_8010F1E4(self);
        fn_8010D33C(self, 0);
        return 1;
    }
    return 0;
}

int fn_8010E190(Scr* self, Scr* a, int unused, int c)
{
    int r = 0;
    if (a == (Scr*)self->m148) {
        unsigned m = self->m140;
        if (m <= 1) {
            int* arr = self->m16C;
            if (arr[a->fn_vslot60()] == self->m158) {
                self->fn_vslot42(fn_800B555C()->m570);
            } else if (fn_8010EAF4(self) != 0) {
                int idx = self->m14C->fn_vslot60();
                fn_8010F2CC(self);
                if (self->m14C->fn_vslot93(idx, 0) != 0)
                    self->m14C->fn_vslot68(idx);
            }
            a->fn_vslot68(c);
            fn_8010F9CC(self, arr[self->m148->fn_vslot60()]);
            return 1;
        }
        if (m == 2) {
            int* arr = self->m16C;
            if (arr[a->fn_vslot60()] == self->m158)
                self->fn_vslot42(fn_800B555C()->m570);
            a->fn_vslot68(c);
            fn_8010F9CC(self, arr[self->m148->fn_vslot60()]);
            return 1;
        }
    }
    if (a == (Scr*)self->m14C && self->m140 == 1) {
        a->fn_vslot68(c);
        fn_8010F9CC(self, self->m1D0[self->m14C->fn_vslot60()]);
        r = 1;
    }
    return r;
}

int fn_8010E40C(Scr* self, Scr* a, int b, int c)
{
    int r = 0;
    if ((a == (Scr*)self->m148 && (self->m140 == 0 || self->m140 == 2)) || (a == (Scr*)self->m14C && self->m140 == 1)) {
        a->fn_vslot68(c);
        self->fn_vslot44(fn_800B555C()->m570);
        r = 1;
    }
    return r;
}

void fn_8010E4BC(Scr* self)
{
    int f = 0;
    if (self->m13C != 0 && self->m13C->b0)
        f = 1;
    fn_8010D33C(self, f);
}

int fn_8010E4FC(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        switch (self->m140) {
        case 0:
        case 2:
            self->m148->fn_vslot50();
            fn_8010F9CC(self, self->m16C[self->m148->fn_vslot60()]);
            break;
        case 1:
            self->m14C->fn_vslot50();
            fn_8010F9CC(self, self->m1D0[self->m14C->fn_vslot60()]);
            break;
        }
    }
    return 1;
}

int fn_8010E5FC(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        switch (self->m140) {
        case 0:
        case 2:
            self->m148->fn_vslot51();
            break;
        case 1:
            self->m14C->fn_vslot51();
            break;
        }
    }
    return 1;
}

int fn_8010E69C(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        switch (self->m140) {
        case 0:
        case 2:
            self->m148->fn_vslot52();
            fn_8010F9CC(self, self->m16C[self->m148->fn_vslot60()]);
            break;
        case 1:
            self->m14C->fn_vslot52();
            fn_8010F9CC(self, self->m1D0[self->m14C->fn_vslot60()]);
            break;
        }
    }
    return 1;
}

int fn_8010E79C(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        switch (self->m140) {
        case 0:
        case 2:
            self->m148->fn_vslot53();
            break;
        case 1:
            self->m14C->fn_vslot53();
            break;
        }
    }
    return 1;
}

int fn_8010E83C(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        fn_800C805C(fn_800C8044(self->fn_vslot32(lbl_805BA760, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot38(1);
        fn_8010F1E4(self);
    }
    return 1;
}

int fn_8010E8F0(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        fn_800C805C(fn_800C8044(self->fn_vslot32(lbl_805BA760, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot39();
    return 1;
}

int fn_8010E998(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        fn_800C805C(fn_800C8044(self->fn_vslot32(lbl_805BA760, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot40(1);
        fn_8010F1E4(self);
    }
    return 1;
}

int fn_8010EA4C(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        fn_800C805C(fn_800C8044(self->fn_vslot32(lbl_805BA760, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot41();
    return 1;
}

/* near-miss: 7 slots, all register naming (retail reloads m168 into r4 and keeps t in r31); AtI() gives retail's r11 index register. */
int fn_8010EAF4(Scr* self)
{
    int r27 = 0;
    UnkGame* g = fn_8011AA24(0);
    UnkGameP700* p700 = g->m700;
    int t = fn_8017E030(p700, fn_801059E4(), 0);
    int e = fn_800B555C()->m570;
    UnkGameP6F8* p = g->m6F8;
    int x = e ^ AtI(&p->m10->m6C, self->m168);
    int c = x == 0;
    if (self->m144 != 3 && self->m144 != 6 && self->m144 != 7)
        r27 = 1;
    int f = 0;
    if ((unsigned)(t - 1) <= 1 || fn_8006BC74(p) != 0)
        f = 1;
    int r = 0;
    if (c != 0 && (r27 != 0 || f != 0))
        r = 1;
    return r;
}

void fn_8010EF84(Scr* self)
{
    fn_8010EFD0(self, lbl_80687CB8.m0, 0);
    fn_8010EFD0(self, lbl_80687CB8.m8, 1);
}

void fn_8010F1E4(Scr* self)
{
    self->m168 = self->m168 == 0;
    UnkPlayerRec* r = fn_8011AA24(0)->m6F8->m14->rec + self->m168;
    int v = r->m198;
    UnkSub* s = (UnkSub*)((char*)fn_800C8054(self->fn_vslot32(lbl_805BE234, 1)) + 0x98);
    s->fn_vslot20(v, 0);
    fn_8010F2CC(self);
}

void fn_8010F290(Scr* self)
{
    fn_8010A808(self);
    fn_8010B6B8(self);
    fn_8010BF88(self);
}

void fn_8010F2CC(Scr* self)
{
    self->m140 = 0;
    self->m158 = 0;
    self->m15C = 0;
    if (self->m144 != 7) {
        self->m160 = 0;
        self->m164 = 0;
    }
    fn_8010F290(self);
    self->m13C->fn_vslot8(0);
    ((UnkWidgetB*)self->m13C)->fn_vslot84(2, 0);
    self->m13C->fn_vslot16(0);
    if (self->m150 == 0) {
        self->m140 = (int)self->m150;
        self->m148->fn_vslot14(self->b1);
        self->m14C->fn_vslot14(0);
        fn_8010F9CC(self, self->m16C[self->m148->fn_vslot60()]);
    } else {
        self->m140 = 1;
        self->m148->fn_vslot14(0);
        self->m14C->fn_vslot14(self->b1);
        fn_8010F9CC(self, self->m1D0[self->m14C->fn_vslot60()]);
    }
    fn_8010D33C(self, 0);
}

void fn_8010F494(Scr* self, int a)
{
    if (self->m234 != 0)
        fn_8001BC4C()->fn_8001BDAC(a);
}

/* Cases 1, 2 and 3 keep their own bodies (only 4/5 share a label), so the tree is
   0, 1, 2, 3, [4,5], 6, 7 rooted at 3 as in retail. */
int fn_8010F4D4(int a, int b)
{
    switch (b) {
    case 0:
        return 0x2441;
    case 1:
        return 0x3A65;
    case 2:
        return 0xC82;
    case 3:
        return 0xC82;
    case 4:
    case 5:
        return 0x3A65;
    case 6:
        return a == 1 ? 0x3A65 : 0xC82;
    case 7:
        return a == 1 ? 0xC82 : 0x3A65;
    }
    return 0x3A65;
}

void fn_8010F550(Scr* self)
{
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    Unk800C7B40_Widget* w = fn_800B7AB8(lbl_8061A32C, lbl_805BAF40);
    fn_8012E1C4(w, 0, fn_8010F4D4(0, self->m144));
    fn_8012E1C4(w, 1, fn_8010F4D4(1, self->m144));
}

/* near-miss: retail stores m158 first and m168 last; the scheduler hoists m168 here (tried all positions of those two). */

void fn_8010F5E8(Scr* self, UnkTextBox* w, UnkPly* a)
{
    char buf[0x64];
    buf[0] = lbl_805B9A30;
    int r26 = lbl_8061977C;
    fn_8040B320(buf + 1, 0, 0x63);
    int t = fn_8011B8C8(3, a);
    fn_804089B4(buf, lbl_805BDDEC, t, fn_8011B8C8(4, a));
    w->fn_vslot43(0, 0, fn_80090880(r26, 0x38A9), 4);
    w->fn_vslot44(0, 1, buf, 4);
    float f = fn_8011B954(1, a);
    fn_80119FF0(buf, f);
    w->fn_vslot43(1, 0, fn_80090880(r26, 0x196D), 4);
    w->fn_vslot44(1, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_8011B9F4(2, a));
    w->fn_vslot43(2, 0, fn_80090880(r26, 0x1979), 4);
    w->fn_vslot44(2, 1, buf, 4);
}

void fn_8010F7E0(Scr* self, UnkTextBox* w, UnkPly* a)
{
    char buf[0x64];
    buf[0] = lbl_805B9A30;
    int r26 = lbl_8061977C;
    fn_8040B320(buf + 1, 0, 0x63);
    float f = fn_8011B81C(2, a, 2);
    fn_80119F48(buf, f);
    w->fn_vslot43(0, 0, fn_80090880(r26, 0x196A), 4);
    w->fn_vslot44(0, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_8011B784(1, a, 2));
    w->fn_vslot43(1, 0, fn_80090880(r26, 0x199E), 4);
    w->fn_vslot44(1, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_8011B784(0, a, 2));
    w->fn_vslot43(2, 0, fn_80090880(r26, 0x196B), 4);
    w->fn_vslot44(2, 1, buf, 4);
}

void fn_8010F9CC(Scr* self, int a)
{
    UnkPly* t = fn_801A4A94(fn_8011AA24(0), a);
    if (t != 0) {
        self->m238->fn_vslot8(1);
        self->m23C->fn_vslot8(1);
        self->m240->fn_vslot8(1);
        int r26 = t->m704;
        UnkTextArg buf;
        fn_800DE274(&buf, t, 1);
        ((UnkLabel*)self->m238)->fn_vslot28(&buf);
        fn_800C3DCC(fn_800C33D0(), self->m23C, t);
        UnkTeamArr* team = fn_8011AA24(0)->m6F8->m14;
        int t708 = t->m708;
        UnkTextBox* w = fn_800C8060(self->m240->fn_vslot32(lbl_805BAF70, 1));
        if (fn_800DC0F4(team, t708, r26) != 0)
            fn_8010F5E8(self, w, t);
        else
            fn_8010F7E0(self, w, t);
        fn_800E0AD4(self->m240, r26, 2, 0, 0);
    } else {
        self->m238->fn_vslot8(0);
        self->m23C->fn_vslot8(0);
        self->m240->fn_vslot8(0);
    }
}

void* fn_8010FBB0(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806508D0);
    self->m158 = 1;
    self->m130 = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m16C[0] = 0;
    return self;
}

int fn_8010FC20(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        fn_8011452C(self);
        if (self->m134 == 0) {
            UnkMgrA* mg = lbl_806192E0->m4;
            int x = ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m150->fn_vslot73(self->m158, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
            int y = ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m150->fn_vslot73(self->m160, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
            if ((self->m164 != y || self->m15C != x) && mg->mC->m600 == 0) {
                fn_80114664(self, 1);
                return 1;
            }
        }
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

/* near-miss: 2 slots; retail loads the fn_8040B830 arguments as lis r4, li r5, addi r4, mr r3 (name pointer last). */

int fn_8010FE70(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        int v = self->m168;
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
            fn_80131F34(w, self, fn_8010FFD8, 0, 0x3364, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
            w->fn_vslot86();
        }
    }
    return 1;
}

/* near-miss: same argument-order difference as fn_8010FE70 (name pointer copied last in retail). */

void fn_8010FFD8(int a, Scr* b)
{
    if (a == 1) {
        fn_80110088(b);
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

void fn_80110088(Scr* self)
{
    fn_801142C4(self);
    if (self->m134 == 3)
        fn_8011415C(self);
}

void fn_80110A7C(Scr* self)
{
    fn_800ED254(self);
    fn_801142C4(self);
}

int fn_80110AB0(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot50();
    return 1;
}

int fn_80110B0C(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot51();
    return 1;
}

int fn_80110B68(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot52();
    return 1;
}

int fn_80110BC4(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot53();
    return 1;
}

int fn_80110C20(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot54();
    return 1;
}

int fn_80110C7C(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot55();
    return 1;
}

int fn_80110CD8(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot56();
    return 1;
}

int fn_80110D34(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot57();
    return 1;
}

UnkTextBox* fn_80110D90(Scr* self, int a)
{
    return fn_800C8060(self->fn_vslot32(lbl_8061B3E0[a], 1));
}

void fn_80110DDC(Scr* self, int a)
{
    self->m134 = a;
    fn_80125180(self->m154, 0, 0x1A0A);
    UnkQ4 q = lbl_805BFA98;
    fn_800C8040(fn_800C8044(self->fn_vslot32(lbl_805BE1D8, 1))->fn_vslot32(lbl_805BE5E4, 1))->fn_vslot29((const char*)q.m[self->m134]);
    if (self->m150 != 0)
        self->m150->fn_vslot8(0);
    self->m150 = (Unk800C7B40_Widget*)fn_80110D90(self, a);
    fn_80125180(self->m154, 1, 0x26DF);
    switch (a) {
    case 0:
        fn_8011243C(self);
        break;
    case 1:
        fn_80112D90(self);
        break;
    case 2:
        fn_801138FC(self);
        break;
    case 3:
        fn_80113CA8(self);
        break;
    }
    self->m150->fn_vslot8(1);
}

}
