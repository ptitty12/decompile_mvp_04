/*
 * Game code, .text 0x80124738-0x801287AC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8010E0F4.h"
#include "game/tu_8001B190.h"

typedef Unk800C7B40_Widget Wid;
/* BUTTONS screen (vtable lbl_80656CD8, ctor fn_80124F24): four button widgets at +0x13C with their ids (+0x14C),
 * a flag/value pair per button (+0x15C) and a base value per button (+0x17C). */
struct Unk80124F24_Scr : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    Wid* m134;
    Wid* m138;
    Wid* m13C[4];
    int m14C[4];
    int m15C[8];
    int m17C[4];
    int m18C[4];
    Wid* m19C;
};
/* CELL screen (vtable lbl_8064CAF0, ctor fn_80124A28): three child widgets, a callback and its argument widget (fn_80124DF8). */
struct Unk80124A28_Scr : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    Wid* m134;
    Wid* m138;
    Wid* m13C;
    void (*m140)(Wid*);
    Wid* m144;
};
/* PITCHING screen (vtable lbl_8064DB50, ctor fn_80126064). */
struct Unk80126064_Scr : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    int m13C;
    Wid* m140;
    Wid* m144;
    char pad148[0x4];
    int m14C;
    int m150;
    int m154;
    int m158;
    int m15C;
    int m160;
    int m164;
    int m168;
    char pad16C[0x4];
    int m170;
    char pad174[0x4];
    int m178;
    int m17C;
    int m180;
    int m184;
    int m188;
    int m18C;
    int m190;
    int m194;
    int m198;
};
struct UnkNavBar : Unk800C7B40_Widget {
    char pad40[0xF8];
    int m138;
};
/* Screen with two button widgets at +0x188 / +0x18C (continues in tu_801287AC.cpp). */
struct Unk8012684C_Scr : Unk800C7B40_Widget {
    char pad40[0x148];
    Wid* m188;
    Wid* m18C;
};
typedef Unk80124F24_Scr Scr;

extern const char lbl_80656CD8[];
extern const char lbl_8064CAF0[];
extern int lbl_8061977C;
extern const char lbl_8064DB50[];
extern const char lbl_805BAF98[];
extern const char lbl_805BF5CC[];
extern const char lbl_805C03DC[];
extern const char lbl_805C03E4[];
extern const char lbl_805C03EC[];
extern const char lbl_805C03F4[];
extern const char lbl_805C03FC[];
extern const char lbl_805C0404[];
extern const char lbl_805C040C[];
extern const char lbl_805BE1C4[];
extern const char lbl_805BEA8C[];
extern const char lbl_805BEA94[];
extern const char lbl_805BAA20[];
extern const char lbl_805C0418[];

inline int GetW(char* b, int off)
{
    return *(int*)(b + off);
}

inline void PutW(char* b, int off, int v)
{
    *(int*)(b + off) = v;
}

extern char* lbl_8061E978;
extern "C" void fn_800D4254(int a, int b, void* p, float* q);
extern const char lbl_805B7FE4[];
extern const char lbl_805C0430[];
extern "C" void fn_800DEA90(Wid* w);
extern "C" void fn_800C3AB4(int m, int a);
extern "C" void fn_800ECE34(void* self);
extern int lbl_8061930C;
extern const char lbl_805BA6D0[];
extern const char lbl_805BC1A8[];
extern const char lbl_805C03A8[];
extern const char lbl_805C03B0[];
extern const char lbl_805C03BC[];
extern "C" int fn_8007FD2C(int, int, int, int);
extern "C" int fn_8007FBC0(int, int, int);
extern "C" void fn_800DAD50(int, int*, int, int, int);
extern "C" void fn_800DD44C(void*, void*, int);
extern "C" void fn_80329FA0(void*, ...);
extern "C" int fn_804089B4(char*, const char*, ...);
// PROTOS-BEGIN
extern "C" {
int fn_80124738(void* a);
int fn_801247A4(void* a);
int fn_80124800(Scr* self);
int fn_8012483C(Scr* self);
int fn_80124878(Scr* self);
int fn_801248B4(Scr* self);
int fn_801248F0(void* a);
void fn_8012494C(Unk80124A28_Scr* self, char* out);
void* fn_80124A28(Unk80124A28_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80124A90(Unk80124A28_Scr* self);
void fn_80124DF8(Unk80124A28_Scr* self);
void fn_80124EF4(Unk80124A28_Scr* self, int a);
int fn_80124F1C();
void* fn_80124F24(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80124F78(Scr* self);
int fn_80124FA8(Scr* self, Wid* a);
int fn_80125084(Scr* self, int a);
void fn_801250D8(Scr* self);
void fn_80125100(Scr* self);
void fn_80125128(Scr* self, int a);
void fn_80125154(Scr* self, int a);
void fn_80125180(Scr* self, int a, int id);
void fn_801251CC(Scr* self, int a, int id, int c);
void fn_80125220(Scr* self, int a, int str);
void fn_80125268(Scr* self, int a, int str, int c);
int fn_801252B8(Scr* self, int a);
void fn_80125300(Scr* self, int a, int b, int id);
int fn_80125354(Scr* self, int i, int a, int str);
int fn_80125490(Scr* self, int a, int b, int id, int e);
void fn_801254EC(Scr* self, int a, int b, int c, int d);
int fn_80125538(Scr* self);
void fn_80125700(Scr* self);
int fn_80125720(Scr* self, int a);
void fn_801257C0(Scr* self);
void fn_80125844(Scr* self, int i, int c);
void fn_80125EC8(Unk80126064_Scr* self);
void fn_801263DC(Unk80126064_Scr* self);
int fn_80125890(Scr* self, int i);
void fn_80125940(Scr* self, int a, int i);
void fn_80125A20(Scr* self, int a);
void fn_80125AAC(Scr* self);
void fn_80125BC0(Scr* self);
void fn_80125C84(Unk80126064_Scr* self, int a);
int fn_80126034();
void* fn_80126064(Unk80126064_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_8012611C(Scr* self);
void fn_8012684C(Unk8012684C_Scr* self);
int fn_80127550(Scr* self, Wid* a);
}
// PROTOS-END
extern "C" {
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_800B7ADC(UnkFEMgr* m, void* obj);
void fn_8035686C(void* self);
int fn_80090880(int mgr, int id);
void fn_80125180(Scr* self, int a, int id);
void fn_801251CC(Scr* self, int a, int id, int c);
void fn_80125220(Scr* self, int a, int str);
void fn_80125268(Scr* self, int a, int id, int c);
int fn_801252B8(Scr* self, int a);
int fn_80125354(Scr* self, int a, int b, int c);
void fn_801254EC(Scr* self, int a, int b, int c, int d);
int fn_80125890(Scr* self, int i);
void fn_800ECF18(Scr* self);
void fn_800ED310(Scr* self);
void fn_800ECAA4(void* self);
int fn_8057CE00(int a);
void fn_8035682C(void* name);
void fn_800B7B4C(UnkFEMgr* m, const void* name, void* obj);
void fn_80125940(Scr* self, int a, int i);
int fn_800B5898(UnkFEState* s);
void fn_800ECE34(void* self);
UnkNavBar* fn_800B7A94(UnkFEMgr* m, const char* name);
Unk8001BC8C* fn_8001BC4C();
int fn_800ED00C();
void fn_800ED254(Scr* self);
void fn_800C3BE0(int a);
int fn_800C33D0();
extern const char lbl_805C0424[];
extern const char lbl_805C0438[];
}

extern "C" {

int fn_80124738(void* a)
{
    char nm[16];
    char* np = nm;
    fn_8035682C(np);
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    fn_800B7B4C(lbl_8061A32C, np, a);
    return 1;
}

int fn_801247A4(void* a)
{
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    fn_800B7ADC(lbl_8061A32C, a);
    return 1;
}

int fn_80124800(Scr* self)
{
    self->m134->fn_vslot52();
    return 1;
}

int fn_8012483C(Scr* self)
{
    self->m134->fn_vslot53();
    return 1;
}

int fn_80124878(Scr* self)
{
    self->m134->fn_vslot50();
    return 1;
}

int fn_801248B4(Scr* self)
{
    self->m134->fn_vslot51();
    return 1;
}

int fn_801248F0(void* a)
{
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    fn_800B7ADC(lbl_8061A32C, a);
    return 1;
}

void fn_8012494C(Unk80124A28_Scr* self, char* out)
{
    int v = fn_8057CE00(fn_800B555C()->m608);
    if (fn_800B5898(fn_800B555C()) == 0) {
        if (self->m134->fn_vslot60() == 0 && v > -1) {
            fn_8040B830(out, lbl_805BAF98, 0x10);
            return;
        }
    }
    fn_8040B830(out, (char*)self->m134->fn_vslot70()->fn_vslot33(5, 1) + 0xC, 0x10);
}

void* fn_80124A28(Unk80124A28_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, 0, 0, d, e, f, g, h);
    self->SetVptr(lbl_8064CAF0);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    return self;
}

void fn_80124A90(Unk80124A28_Scr* self)
{
    fn_800ECE34(self);
    self->m134 = (Wid*)fn_800C8060(self->fn_vslot32(lbl_805BE1C4, 1));
    self->m138 = fn_800C8044(self->fn_vslot32(lbl_805BEA8C, 1));
    self->m13C = fn_800C8044(self->fn_vslot32(lbl_805BEA94, 1));
}

void fn_80124B40(Unk80124A28_Scr* self, Wid* w, int a2, int a3, void (*cb)(Wid*))
{
    int g = lbl_8061930C;
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    Scr* mg = (Scr*)fn_800B7A94(lbl_8061A32C, lbl_805BA6D0);
    fn_80124FA8(mg, (Wid*)self);
    ((int (*)(Scr*, int))fn_80125154)(mg, 0);
    fn_801251CC(mg, 3, 0x27D7, 0);
    self->m140 = cb;
    self->m144 = w;
    int u0 = fn_8007FD2C(g, a2, 0, a3);
    int u1 = fn_8007FD2C(g, a2, 1, a3);
    int d;
    char buf8[0x40];
    char buf48[0x10];
    fn_80329FA0(&d, fn_8007FBC0(g, a2, a3));
    fn_800DAD50((int)self->m134, &a2, 1, a3, 2);
    fn_800DD44C(&d, buf8, 1);
    fn_800C8040(self->fn_vslot32(lbl_805C03A8, 1))->fn_vslot28(buf8);
    fn_804089B4(buf48, lbl_805BC1A8, u0);
    fn_800C8040(self->fn_vslot29(lbl_805C03B0))->fn_vslot30(buf48);
    fn_804089B4(buf48, lbl_805BC1A8, u1);
    fn_800C8040(self->fn_vslot29(lbl_805C03BC))->fn_vslot30(buf48);
    if (self->m144 != 0)
        self->m144->fn_vslot16(0);
    self->fn_vslot16(1);
    self->fn_vslot8(1);
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    UnkNavBar* nb = fn_800B7A94(lbl_8061A32C, lbl_805BAA20);
    if (nb)
        nb->m138 = 1;
}

void fn_80124DF8(Unk80124A28_Scr* self)
{
    if (self->m140 != 0) {
        fn_8001BC4C()->fn_8001BDAC(0xA0);
        if (self->m144)
            self->m144->fn_vslot16(1);
        self->m140(self->m144);
        self->m140 = 0;
        self->m144 = 0;
        self->fn_vslot16(0);
        self->fn_vslot8(0);
        if (lbl_8061A32C == 0)
            lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
        UnkNavBar* nb = fn_800B7A94(lbl_8061A32C, lbl_805BAA20);
        if (nb)
            nb->m138 = 0;
    }
}

void fn_80124EF4(Unk80124A28_Scr* self, int a)
{
    if (a == 0)
        fn_80124DF8(self);
}

int fn_80124F1C()
{
    return 0;
}

void* fn_80124F24(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80656CD8);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

void fn_80124F78(Scr* self)
{
    self->SetVptr(lbl_80656CD8);
    fn_8035686C(self);
}

int fn_80124FA8(Scr* self, Wid* a)
{
    self->m134 = a;
    int o8 = 0;
    int o4 = 0;
    int n = 4;
    do {
        char* b = (char*)self + 0x13C;
        (*(Wid**)(b + o4))->fn_vslot16(0);
        (*(Wid**)(b + o4))->fn_vslot8(0);
        o4 += 4;
        char* pa = (char*)self + 0x15C;
        *(int*)(pa + o8) = 0;
        n--;
        char* pb = (char*)self + 0x160;
        *(int*)(pb + o8) = 0;
        o8 += 8;
    } while (n != 0);
    self->fn_vslot16(1);
    self->fn_vslot8(1);
    return 1;
}

int fn_80125084(Scr* self, int a)
{
    for (int i = 0; i < 4; i++) {
        if (self->m14C[i] == a)
            return fn_80125890(self, i);
    }
    return 0;
}

void fn_801250D8(Scr* self)
{
    fn_80125180(self, 0, 0x1A0D);
}

void fn_80125100(Scr* self)
{
    fn_80125180(self, 1, 0x1A0C);
}

void fn_80125128(Scr* self, int a)
{
    fn_801251CC(self, 0, 0x1A0D, a);
}

void fn_80125154(Scr* self, int a)
{
    fn_801251CC(self, 1, 0x1A0C, a);
}

void fn_80125180(Scr* self, int a, int id)
{
    fn_80125220(self, a, fn_80090880(lbl_8061977C, id));
}

void fn_801251CC(Scr* self, int a, int id, int c)
{
    fn_80125268(self, a, fn_80090880(lbl_8061977C, id), c);
}

void fn_80125220(Scr* self, int a, int str)
{
    fn_80125354(self, fn_801252B8(self, a), a, str);
}

void fn_80125268(Scr* self, int a, int str, int c)
{
    fn_801254EC(self, fn_801252B8(self, a), a, str, c);
}

int fn_801252B8(Scr* self, int a)
{
    int r = 0;
    switch (a) {
    case 1:
        break;
    case 2:
        r = 1;
        break;
    case 3:
        r = 2;
        break;
    case 0:
        r = 3;
        break;
    }
    return r;
}

void fn_80125300(Scr* self, int a, int b, int id)
{
    fn_80125354(self, a, b, fn_80090880(lbl_8061977C, id));
}

int fn_80125354(Scr* self, int i, int a, int str)
{
    int o4 = i * 4;
    char* b = (char*)self + 0x13C;
    fn_800C8040(fn_800C8044(*(Wid**)(b + o4))->fn_vslot32(lbl_805BF5CC, 1))->fn_vslot28((const void*)str);
    ((UnkSub*)((char*)fn_800C8054(fn_800C8044(*(Wid**)(b + o4))->fn_vslot32(lbl_805C03DC, 1)) + 0x98))->fn_vslot6(a);
    (*(Wid**)(b + o4))->fn_vslot8(1);
    (*(Wid**)(b + o4))->fn_vslot16(1);
    int o8 = i * 8;
    char* p14C = (char*)self + 0x14C;
    *(int*)(p14C + o4) = a;
    char* p15C = (char*)self + 0x15C;
    *(int*)(p15C + o8) = 0;
    char* p160 = (char*)self + 0x160;
    *(int*)(p160 + o8) = 0;
    return 1;
}

int fn_80125490(Scr* self, int a, int b, int id, int e)
{
    fn_801254EC(self, a, b, fn_80090880(lbl_8061977C, id), e);
}

void fn_801254EC(Scr* self, int a, int b, int c, int d)
{
    fn_80125354(self, a, b, c);
    int off = a * 8;
    char* x = (char*)self + 0x15C;
    char* y = (char*)self + 0x160;
    *(int*)(x + off) = 1;
    *(int*)(y + off) = d;
}

int fn_80125538(Scr* self)
{
    fn_800ECE34(self);
    Wid* g = self->fn_vslot32(lbl_805C03E4, 1);
    self->m13C[0] = g->fn_vslot32(lbl_805C03EC, 1);
    self->m13C[1] = g->fn_vslot32(lbl_805C03F4, 1);
    self->m13C[2] = g->fn_vslot32(lbl_805C03FC, 1);
    Wid* b3 = g->fn_vslot32(lbl_805C0404, 1);
    self->m13C[3] = b3;
    Wid* a = self->m13C[0];
    Wid* c = self->m13C[1];
    Wid* d = self->m13C[2];
    self->m17C[0] = a->m26;
    self->m18C[0] = a->m28;
    self->m17C[1] = c->m26;
    self->m18C[1] = c->m28;
    self->m17C[2] = d->m26;
    self->m18C[2] = d->m28;
    self->m17C[3] = b3->m26;
    self->m18C[3] = b3->m28;
    self->m14C[0] = -1;
    self->m14C[1] = -1;
    self->m14C[2] = -1;
    self->m14C[3] = -1;
    Wid* r = self->fn_vslot30(lbl_805C040C, 1);
    int res = (int)r;
    if (r != 0) {
        self->m138 = fn_800C8038(r);
        self->m138->fn_vslot8(0);
        res = self->m138->fn_vslot18(self->m138->m2E + 1);
    }
    return res;
}

void fn_80125700(Scr* self)
{
    fn_800ECF18(self);
}

int fn_80125720(Scr* self, int a)
{
    Wid* w = self->m134;
    if (w != 0 && w->b1) {
        int i = 0;
        int o8 = 0;
        int o4 = 0;
        do {
            char* pa = (char*)self + 0x14C;
            if (*(int*)(pa + o4) == a) {
                char* pb = (char*)self + 0x15C;
                if (*(int*)(pb + o8) != 0) {
                    char* pc = (char*)self + 0x160;
                    w->fn_vslot67(*(int*)(pc + o8));
                    return 1;
                }
            }
            i++;
            o8 += 8;
            o4 += 4;
        } while (i <= 3);
    }
    return 0;
}

void fn_801257C0(Scr* self)
{
    if (!self->m13C[0]->b0 && self->m13C[1]->b0)
        fn_80125940(self, 0, 1);
    if (!self->m13C[3]->b0 && self->m13C[2]->b0)
        fn_80125940(self, 3, 2);
}

void fn_80125844(Scr* self, int i, int c)
{
    self->m13C[i]->fn_vslot9(self->m17C[i] + c);
}

int fn_80125890(Scr* self, int i)
{
    if (self->m14C[i] == -1)
        return 0;
    self->m13C[i]->fn_vslot16(0);
    self->m13C[i]->fn_vslot8(0);
    int off = i * 8;
    char* x = (char*)self + 0x15C;
    char* y = (char*)self + 0x160;
    *(int*)(x + off) = 0;
    *(int*)(y + off) = 0;
    self->m14C[i] = -1;
    return 1;
}

void fn_80125940(Scr* self, int a, int i)
{
    int x = self->m14C[i];
    int v = fn_800C8040(fn_800C8044(self->m13C[i])->fn_vslot32(lbl_805BF5CC, 1))->fn_vslot31();
    fn_80125890(self, i);
    int off = i * 8;
    char* px = (char*)self + 0x15C;
    if (*(int*)(px + off) != 0) {
        char* py = (char*)self + 0x160;
        fn_801254EC(self, a, x, v, *(int*)(py + off));
    } else {
        fn_80125354(self, a, x, v);
    }
}

void fn_80125A20(Scr* self, int a)
{
    ((void (*)(Scr*, int))fn_800ED310)(self, a);
    if (a != 0) {
        if (self->m138)
            self->m138->fn_vslot8(0);
    } else {
        if (self->m138)
            self->m138->fn_vslot8(1);
    }
}

/* near-miss: retail recomputes the field base addresses per arm; GCC shares them here. */

void fn_80125AAC(Scr* self)
{
    int o8 = 0;
    int o4 = 0;
    int n = 4;
    self->m19C = self->m134;
    do {
        char* b13C = (char*)self + 0x13C;
        int t = (*(Wid**)(b13C + o4))->b1;
        PutW((char*)self + 0x1A0, o4, t);
        if (t != 0) {
            int v = fn_800C8040(fn_800C8044(*(Wid**)(b13C + o4))->fn_vslot32(lbl_805BF5CC, 1))->fn_vslot31();
            PutW((char*)self + 0x1C0, o4, v);
            PutW((char*)self + 0x1B0, o4, GetW((char*)self + 0x14C, o4));
            PutW((char*)self + 0x1D0, o8, GetW((char*)self + 0x15C, o8));
            PutW((char*)self + 0x1D4, o8, GetW((char*)self + 0x160, o8));
        } else {
            PutW((char*)self + 0x1C0, o4, t);
            PutW((char*)self + 0x1B0, o4, -1);
            PutW((char*)self + 0x1D0, o8, t);
            PutW((char*)self + 0x1D4, o8, t);
        }
        o8 += 8;
        o4 += 4;
        n--;
    } while (n != 0);
}

/* near-miss: same base-address sharing difference as fn_80125AAC. */

void fn_80125BC0(Scr* self)
{
    int i = 0;
    int o8 = 0;
    int o4 = 0;
    self->m134 = self->m19C;
    do {
        char* pa = (char*)self + 0x1A0;
        if (*(int*)(pa + o4) != 0) {
            char* pb = (char*)self + 0x1D0;
            if (*(int*)(pb + o8) != 0) {
                char* p1 = (char*)self + 0x1B0;
                char* p2 = (char*)self + 0x1C0;
                char* p3 = (char*)self + 0x1D4;
                fn_801254EC(self, i, *(int*)(p1 + o4), *(int*)(p2 + o4), *(int*)(p3 + o8));
            } else {
                char* p1 = (char*)self + 0x1B0;
                char* p2 = (char*)self + 0x1C0;
                fn_80125354(self, i, *(int*)(p1 + o4), *(int*)(p2 + o4));
            }
        } else {
            fn_80125890(self, i);
        }
        i++;
        o8 += 8;
        o4 += 4;
    } while (i <= 3);
}

void fn_80125C84(Unk80126064_Scr* self, int a)
{
    fn_800C8038(fn_800C8044(self->m140)->fn_vslot32(lbl_805C0418, 1))->fn_vslot8(a);
}

void fn_80125CF8(Unk80126064_Scr* self)
{
    char* b = lbl_8061E978;
    int w0 = fn_800C8038(fn_800C8044(self->m144)->fn_vslot32(lbl_805C03DC, 1))->m26;
    int w1 = fn_800C8038(fn_800C8044(self->m140)->fn_vslot32(lbl_805C0418, 1))->m2A + 4;
    int a = fn_800C8040(fn_800C8044(self->m140)->fn_vslot32(lbl_805BF5CC, 1))->fn_vslot31();
    int idx = fn_800C8040(fn_800C8044(self->m140)->fn_vslot32(lbl_805BF5CC, 1))->fn_vslot34();
    float spC[1];
    int sp8;
    int off = idx * 4;
    char* bb = b + 0x11E88;
    fn_800D4254(a, *(int*)(bb + off), &sp8, spC);
    int v = fn_800C8044(self->m140)->fn_vslot32(lbl_805BF5CC, 1)->m26 + (int)spC[0] + w1;
    if (v > w0) {
        int d = (v - w0) / 2;
        fn_80125844((Scr*)self, 1, -d);
        fn_80125844((Scr*)self, 2, d);
    }
    fn_80125EC8(self);
}

void fn_80125EC8(Unk80126064_Scr* self)
{
    short x = fn_800C8044(self->m140)->fn_vslot32(lbl_805BF5CC, 1)->m26;
    char* b = lbl_8061E978;
    int a = fn_800C8040(fn_800C8044(self->m140)->fn_vslot32(lbl_805BF5CC, 1))->fn_vslot31();
    int idx = fn_800C8040(fn_800C8044(self->m140)->fn_vslot32(lbl_805BF5CC, 1))->fn_vslot34();
    float spC[1];
    int sp8;
    int off = idx * 4;
    char* bb = b + 0x11E88;
    fn_800D4254(a, *(int*)(bb + off), &sp8, spC);
    fn_800C8038(fn_800C8044(self->m140)->fn_vslot32(lbl_805C0418, 1))->fn_vslot9(x + (int)spC[0] + 2);
}

int fn_80126034()
{
    if (fn_800ED00C() == 0)
        return 0;
    return 1;
}

void* fn_80126064(Unk80126064_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8064DB50);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m154 = -1;
    self->m158 = -1;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m170 = 0;
    self->m178 = 0;
    self->m17C = 5;
    self->m188 = 0;
    self->m190 = 1;
    self->m180 = 5;
    self->m184 = 2;
    self->m18C = 0;
    self->m198 = -1;
    self->m194 = 1;
    return self;
}

void fn_8012611C(Scr* self)
{
    fn_800ED254(self);
    fn_800C3BE0(fn_800C33D0());
}

void fn_80126144(Unk80126064_Scr* self)
{
    fn_800ECE34(self);
    int i = 3;
    Wid* a = (Wid*)fn_800C8060(fn_800C8044(fn_800C8044(self->fn_vslot32(lbl_805C0424, 1))->fn_vslot32(lbl_805B7FE4, 1))->fn_vslot32(lbl_805C0430, 1));
    Wid* b = (Wid*)fn_800C8060(fn_800C8044(fn_800C8044(self->fn_vslot32(lbl_805C0438, 1))->fn_vslot32(lbl_805B7FE4, 1))->fn_vslot32(lbl_805C0430, 1));
    do {
        Wid* p = fn_800C8058(a->fn_vslot73(i, 0)->fn_vslot33(10, 1));
        Wid* q = fn_800C8058(b->fn_vslot73(i++, 0)->fn_vslot33(10, 1));
        fn_800DEA90(p);
        fn_800DEA90(q);
    } while (i <= 6);
    fn_801263DC(self);
    fn_800C3AB4(fn_800C33D0(), 9);
    self->fn_vslot8(0);
    self->fn_vslot16(0);
    self->fn_vslot32(lbl_805C0424, 1)->fn_vslot8(0);
    self->fn_vslot32(lbl_805C0438, 1)->fn_vslot8(0);
}

void fn_8012684C(Unk8012684C_Scr* self)
{
    fn_800ECAA4(self);
    int c;
    if (self->m188 != 0 || self->m18C != 0)
        c = 1;
    else
        c = 0;
    if (c != 0)
        ((UnkWidgetB*)self)->fn_vslot84(2, 0);
}

int fn_80127550(Scr* self, Wid* a)
{
    if (a == fn_800C8044(self->fn_vslot32(lbl_805C0424, 1)))
        return self->m17C[0];
    if (a == fn_800C8044(self->fn_vslot32(lbl_805C0438, 1)))
        return self->m17C[1];
    return 0;
}

}
