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
};
/* CELL screen (vtable lbl_8064CAF0, ctor fn_80124A28). */
struct Unk80124A28_Scr : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    int m144;
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
typedef Unk80124F24_Scr Scr;

extern const char lbl_80656CD8[];
extern const char lbl_8064CAF0[];
extern int lbl_8061977C;
extern const char lbl_8064DB50[];
extern const char lbl_805C0418[];

// PROTOS-BEGIN
extern "C" {
int fn_801247A4(void* a);
int fn_80124800(Scr* self);
int fn_8012483C(Scr* self);
int fn_80124878(Scr* self);
int fn_801248B4(Scr* self);
int fn_801248F0(void* a);
void* fn_80124A28(Unk80124A28_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80124EF4(Scr* self, int a);
int fn_80124F1C();
void* fn_80124F24(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80124F78(Scr* self);
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
void fn_80125490(Scr* self, int a, int b, int id, int e);
void fn_801254EC(Scr* self, int a, int b, int c, int d);
void fn_80125700(Scr* self);
void fn_80125844(Scr* self, int i, int c);
int fn_80125890(Scr* self, int i);
void fn_80125A20(Scr* self, int a);
void fn_80125C84(Unk80126064_Scr* self, int a);
void* fn_80126064(Unk80126064_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
}
// PROTOS-END
extern "C" {
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_800B7ADC(UnkFEMgr* m, void* obj);
void fn_80124DF8(Scr* self);
void fn_8035686C(void* self);
int fn_80090880(int mgr, int id);
void fn_80125180(Scr* self, int a, int id);
void fn_801251CC(Scr* self, int a, int id, int c);
void fn_80125220(Scr* self, int a, int str);
void fn_80125268(Scr* self, int a, int id, int c);
int fn_801252B8(Scr* self, int a);
void fn_80125354(Scr* self, int a, int b, int c);
void fn_801254EC(Scr* self, int a, int b, int c, int d);
int fn_80125890(Scr* self, int i);
void fn_800ECF18(Scr* self);
void fn_800ED310(Scr* self);
}

extern "C" {

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

void fn_80124EF4(Scr* self, int a)
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

void fn_80125490(Scr* self, int a, int b, int id, int e)
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

void fn_80125700(Scr* self)
{
    fn_800ECF18(self);
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

/* near-miss: retail keeps `a` in r30 and `self` in r31 (swapped here). */
void fn_80125A20(Scr* self, int a)
{
    fn_800ED310(self);
    if (a != 0) {
        if (self->m138)
            self->m138->fn_vslot8(0);
    } else {
        if (self->m138)
            self->m138->fn_vslot8(1);
    }
}

void fn_80125C84(Unk80126064_Scr* self, int a)
{
    fn_800C8038(fn_800C8044(self->m140)->fn_vslot32(lbl_805C0418, 1))->fn_vslot8(a);
}

/* near-miss: store scheduling of the leading constant stores differs (same stores). */
void* fn_80126064(Unk80126064_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8064DB50);
    self->m180 = 5;
    self->m184 = 2;
    self->m18C = 0;
    self->m198 = -1;
    self->m194 = 1;
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
    return self;
}

}
