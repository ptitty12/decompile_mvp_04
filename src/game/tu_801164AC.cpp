/*
 * Game code, .text 0x801164AC-0x8011A518 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8010E0F4.h"
#include "game/tu_8001B190.h"

typedef Unk80114A20_Scr Scr;
typedef Unk800C7B40_Widget Wid;

inline void SetSub98(Wid* w, int v)
{
    ((UnkSub*)((char*)w + 0x98))->fn_vslot20(v, 0);
}

extern const char lbl_805BFB7C[];
extern const char lbl_805BFB84[];
extern const char lbl_805BFB88[];
extern const char lbl_805BFB8C[];
extern const char lbl_805BFB90[];
extern const char lbl_805BFBA4[];
extern const char lbl_805BFBB0[];
extern const char lbl_805BFBBC[];
extern const char lbl_805BFBC8[];
extern const char lbl_805BFCDC[];
extern const float lbl_805BFCE4;
extern const float lbl_805BFCE8;
extern const char lbl_805BA6D8[];
extern const char lbl_805B955C[];
extern const char lbl_805BFB3C[];
extern const char lbl_805BFB4C[];
extern const char lbl_805BE1B0[];
int fn_801A71D0();
int* fn_800ED2B0(void* container, const char* name);
extern const float lbl_805BFB38;
Unk8001BC8C* fn_8001BC4C();
extern const char lbl_805BC1A8[];
extern const char lbl_805BFCC4[];
extern const char lbl_805BFCCC[];
extern const float lbl_805BFCD4;
extern const float lbl_805BFCD8;
extern char lbl_805B9A30;
extern const char lbl_805BADC8[];
extern const char lbl_8064E8D8[];
extern const char lbl_8064E630[];

extern char lbl_8065B888[];
extern char lbl_80649DA0[];
extern const char lbl_805BADC8[];
struct EvtRaw {
    int id;
    const void* vt;
    ~EvtRaw() {}
};
// PROTOS-BEGIN
struct WidV91 : Unk800C7B40_Data {
    virtual ~WidV91();
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
    virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36();
    virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41();
    virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46();
    virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
    virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55(); virtual void s56();
    virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60(); virtual void s61();
    virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66();
    virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71();
    virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76();
    virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80(); virtual void s81();
    virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86();
    virtual void s87(); virtual void s88(); virtual void s89(); virtual void s90();
    virtual void s91(int a, int b, int c); virtual void s92(); virtual void s93(); virtual void s94();
    virtual void s95(); virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99();
    virtual void s100(); virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104();
    virtual void s105(); virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109();
    virtual void s110(); virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114();
    virtual void s115(); virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119();
    virtual void s120(); virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124();
    virtual void s125(); virtual void s126(); virtual void s127();
};
inline void SetSub(Wid* w, int v)
{
    ((UnkSub*)((char*)w + 0xDC))->fn_vslot6(v);
}
extern const char lbl_805BC19C[];
extern const char lbl_805BF19C[];
int fn_8011AD00(int mode, int idx);
int fn_8011AE28(int mode, int idx);

struct Ui1A0 {
    char pad0[0x50];
    int m50;
    char pad54[0x124 - 0x54];
    int m124;
    char pad128[0x184 - 0x128];
    int m184;
};

struct Unk80084910_W;
void fn_80086D24(Unk80084910_W* w, int i, int v);

int fn_802D7CE0(int a, int b);
int fn_802D7D64(int a);
int fn_80086D34(Unk80084910_W* w, int i);

extern const char lbl_805BEFE4[];
extern const char lbl_805BDD9C[];
extern const char lbl_805BD934[];
void fn_8011A518(int a, Wid* w, const char* name);

struct Unk800ABDC4_R {
    char pad0[8];
    int m8;
    char padC[4];
    int m10;
    int m14;
};
extern int lbl_80619D10;
extern const char lbl_805BBE2C[];
extern const char lbl_805BE3D0[];
extern const char lbl_805BFC94[];
extern const char lbl_805BFC9C[];
extern const char lbl_805BFCA8[];
extern const char lbl_805BFCB4[];
extern const char lbl_805BDC84[];
int fn_801C1638(UnkGame* g, int a);
int fn_801A4B34(UnkGame* g);
Unk800ABDC4_R* fn_800ABDC4(int a, UnkGame* g);
int fn_800ABC58(int a, UnkGame* g);
int fn_80144BF4(int a);

extern const float lbl_805BFB08;

extern const char lbl_805BF5CC[];
float fn_80097F68(UnkPlayerRec* r, int a, unsigned char i, int b, int c);
int fn_80097A70(UnkPlayerRec* r, int a, unsigned char i, int b);

extern "C" {
int fn_80116A64(Scr* self, int b);
void fn_80117634(Scr* self);
void fn_80117764(Scr* self);
void fn_801177E8(Scr* self, int a);
int fn_80117838();
void fn_80117840(Scr* self);
void fn_80117844(Scr* self);
void fn_801178D8(Scr* self);
void fn_80117984(Scr* self, int b);
void fn_80117B04(int a, Scr* b);
void fn_80117B60(int a, Scr* b);
void* fn_80117D20(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80117D70(Unk80117D20_Scr* self);
void fn_80117EA0(Unk80117D20_Scr* self, Wid* w, int v);
void fn_80117F48(Unk80117D20_Scr* self);
void* fn_80117FDC(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80118144(Unk80117D20_Scr* self, Wid* w, int v);
void fn_801181EC(Scr* self);
void fn_80118A70(Unk80117D20_Scr* self);
void fn_80119F48(char* buf, float v);
void fn_80119FF0(char* buf, float v);
void fn_8011A0A4(int v, Unk800C7B40_Widget* w, const char* name);
void fn_8011A14C(int a, Unk800C7B40_Widget* w, const char* name, int flag);
void fn_8011A1D4(UnkGame* g, int a, Unk800C7B40_Widget* w, const char* name);
void fn_8011A268(char* base, Unk800C7B40_Widget* w, const char* name);
void fn_8011A2AC(int a, Unk800C7B40_Widget* w, const char* name);
void fn_8011A3CC(int a, Unk800C7B40_Widget* w, const char* name);
void fn_8011A414(int a, Unk800C7B40_Widget* w, const char* name);
void fn_8011A468(int a, Unk800C7B40_Widget* w, const char* name);
}
// PROTOS-END
extern "C" {
void fn_800ED310(Scr* self);
void fn_800ECAA4(void* self);
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
int fn_8011AD00(int a);
void fn_800ECF18(void* self);
int fn_801059E4();
void fn_80118D14(Wid* w);
void fn_8035682C(void* name);
void fn_8040B830(void* dst, const char* src, int n);
void fn_800B7B4C(UnkFEMgr* m, const void* name, void* obj);
void fn_80116100(Scr* self);
void fn_80116268(Scr* self);
void fn_801164AC(Scr* self);
void fn_801167AC(Scr* self);
void fn_80117BBC(Scr* self);
void fn_80117C8C(Scr* self);
void fn_80117634(Scr* self);
int fn_804089B4(char* buf, const char* fmt, ...);
int fn_8040B320(void* p, int c, int n, ...);
int fn_8011B784(int a, int b, int c);
float fn_8011B81C(int a, int b, int c);
void fn_8011A0A4(int v, Unk800C7B40_Widget* w, const char* name);
void fn_80119F48(char* buf, float v);
int fn_8025416C(char* p, int a);
int fn_80097288(int a, int b);
const char* fn_800E5E4C(int a);
void fn_800DE274(UnkTextArg* p, int a, int b);
void fn_80131F34(Unk800C7B40_Widget* w, void* self, void (*cb)(int, void*), int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
void fn_8037893C(char* p, int id, EvtRaw* e, int a, int b);
}

extern "C" {

void fn_801164AC(Scr* self)
{
    {
        int v0 = ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(0, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
        fn_80086D24((Unk80084910_W*)self->m1A0, 0, v0);
        if (self->m1A4 != 0)
            fn_80086D24((Unk80084910_W*)self->m1A4, 0, v0);
    }
    {
        int v1 = ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(1, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
        fn_80086D24((Unk80084910_W*)self->m1A0, 1, v1);
        if (self->m1A4 != 0)
            fn_80086D24((Unk80084910_W*)self->m1A4, 1, v1);
    }
    {
        int v2 = ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(2, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
        fn_80086D24((Unk80084910_W*)self->m1A0, 2, v2);
        if (self->m1A4 != 0)
            fn_80086D24((Unk80084910_W*)self->m1A4, 2, v2);
    }
    {
        int v3 = ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(3, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
        fn_80086D24((Unk80084910_W*)self->m1A0, 3, v3);
        if (self->m1A4 != 0)
            fn_80086D24((Unk80084910_W*)self->m1A4, 3, v3);
    }
}

void fn_801167AC(Scr* self)
{
    Unk8001BC8C* g = fn_8001BC4C();
    float t0 = (float)((UnkSub*)((char*)fn_800C8058(self->m198->fn_vslot73(0, 0)->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
    g->fn_8001C05C(3, t0 * lbl_805BFB08, 1);
    float t1 = (float)((UnkSub*)((char*)fn_800C8058(self->m198->fn_vslot73(1, 0)->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
    g->fn_8001C05C(1, t1 * lbl_805BFB08, 1);
    float t2 = (float)((UnkSub*)((char*)fn_800C8058(self->m198->fn_vslot73(2, 0)->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
    g->fn_8001C05C(4, t2 * lbl_805BFB08, 1);
    float t3 = (float)((UnkSub*)((char*)fn_800C8058(self->m198->fn_vslot73(3, 0)->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot5();
    g->fn_8001C05C(2, t3 * lbl_805BFB08, 1);
}

int fn_80116A64(Scr* self, int b)
{
    if (b <= 1) {
        if (b >= 0) {
            if (fn_8011AD00(self->m180) != -1)
                return 1;
        }
    }
    return 0;
}

void fn_80116AA8(Scr* self)
{
    int a0 = fn_8011AE28(self->m180, 0);
    int a1 = fn_8011AE28(self->m180, 1);
    ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(0, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot6(a0);
    ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(1, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot6(a1);
    int c0 = (fn_8011AD00(self->m180, 0) ^ fn_800B555C()->m570) == 0;
    int c1 = (fn_8011AD00(self->m180, 1) ^ fn_800B555C()->m570) == 0;
    ((WidV91*)self->m198)->s91(0, 0, c0);
    ((WidV91*)self->m198)->s91(1, 0, c1);
}

void fn_80116CA8(Scr* self)
{
    switch (self->m180) {
    case 0:
        break;
    case 6: {
        int a = ((Ui1A0*)self->m1A0)->m124;
        int b = ((Ui1A0*)self->m1A0)->m50;
        ((UnkSub*)((char*)fn_800C8058(self->m198->fn_vslot73(0, 0)->fn_vslot33(10, 1)) + 0xDC))->fn_vslot6(a);
        ((UnkSub*)((char*)fn_800C8058(self->m198->fn_vslot73(1, 0)->fn_vslot33(10, 1)) + 0xDC))->fn_vslot6(b);
        break;
    }
    case 5: {
        int a = ((Ui1A0*)self->m1A0)->m184;
        ((UnkSub*)((char*)fn_800C8058(self->m198->fn_vslot73(0, 0)->fn_vslot33(10, 1)) + 0xDC))->fn_vslot6(a);
        break;
    }
    case 3: {
        int a = ((Ui1A0*)self->m1A0)->m124;
        ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(0, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot6(a);
        break;
    }
    }
    self->m198->fn_vslot68(0);
}

void fn_80116EE8(Scr* self)
{
    Wid* w0 = fn_800C8058(fn_800C805C(self->m198->fn_vslot73(0, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1));
    if (fn_802D7CE0(0, 0) == 0 || fn_802D7D64(0) == 0)
        SetSub(w0, 0);
    else
        SetSub(w0, fn_80086D34((Unk80084910_W*)self->m1A0, 0));
    Wid* w1 = fn_800C8058(fn_800C805C(self->m198->fn_vslot73(1, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1));
    if (fn_802D7CE0(1, 0) == 0 || fn_802D7D64(1) == 0)
        SetSub(w1, 0);
    else
        SetSub(w1, fn_80086D34((Unk80084910_W*)self->m1A0, 1));
    int v2;
    if (fn_802D7CE0(2, 0) == 0 || fn_802D7D64(2) == 0)
        v2 = 0;
    else
        v2 = fn_80086D34((Unk80084910_W*)self->m1A0, 2);
    ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(2, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot6(v2);
    int v3;
    if (fn_802D7CE0(3, 0) == 0 || fn_802D7D64(3) == 0)
        v3 = 0;
    else
        v3 = fn_80086D34((Unk80084910_W*)self->m1A0, 3);
    ((UnkSub*)((char*)fn_800C8058(fn_800C805C(self->m198->fn_vslot73(3, 0)->fn_vslot32(lbl_805BC19C, 1))->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot6(v3);
}

void fn_80117288(Scr* self)
{
    UnkGameP6F8* p = fn_8011AA24(0)->m6F8;
    int a0 = (int)((float)((unsigned char*)p->m10)[7] * 0.003921569f * 5.0f);
    ((UnkSub*)((char*)fn_800C8058(self->m198->fn_vslot73(0, 0)->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot6((int)((float)a0 + 0.5f));
    self->m188 = a0;
    int a1 = (int)((float)((unsigned char*)p->m10)[5] * 0.003921569f * 5.0f);
    ((UnkSub*)((char*)fn_800C8058(self->m198->fn_vslot73(1, 0)->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot6((int)((float)a1 + 0.5f));
    self->m18C = a1;
    int a2 = (int)((float)((unsigned char*)p->m10)[8] * 0.003921569f * 5.0f);
    ((UnkSub*)((char*)fn_800C8058(self->m198->fn_vslot73(2, 0)->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot6((int)((float)a2 + 0.5f));
    self->m190 = a2;
    int a3 = (int)((float)((unsigned char*)p->m10)[6] * 0.003921569f * 5.0f);
    ((UnkSub*)((char*)fn_800C8058(self->m198->fn_vslot73(3, 0)->fn_vslot32(lbl_805BF19C, 1)) + 0xDC))->fn_vslot6((int)((float)a3 + 0.5f));
    self->m194 = a3;
}

void fn_80117634(Scr* self)
{
    Unk8001BC8C* g = fn_8001BC4C();
    float t0 = (float)self->m188;
    g->fn_8001C05C(3, t0 * lbl_805BFB38, 1);
    float t1 = (float)self->m18C;
    g->fn_8001C05C(1, t1 * lbl_805BFB38, 1);
    float t2 = (float)self->m190;
    g->fn_8001C05C(4, t2 * lbl_805BFB38, 1);
    float t3 = (float)self->m194;
    g->fn_8001C05C(2, t3 * lbl_805BFB38, 1);
}

void fn_80117764(Scr* self)
{
    UnkGame* g = fn_8011AA24(0);
    int v1 = g->m6F8->m10->m124;
    fn_802D61AC(fn_801A4CE8(g, 1), v1, 0);
    if (self->m1A4 != 0) {
        UnkGame* h = fn_8011AA24(1);
        int v2 = h->m6F8->m10->m124;
        fn_802D61AC(fn_801A4CE8(h, 1), v2, 0);
    }
}

void fn_801177E8(Scr* self, int a)
{
    fn_800ED310(self);
    self->m198->fn_vslot14(a);
}

int fn_80117838()
{
    return 0;
}

void fn_80117840(Scr* self)
{
}

void fn_80117844(Scr* self)
{
    switch (self->m184) {
    case 0:
        fn_80116100(self);
        fn_80117840(self);
        break;
    case 1:
        fn_80116268(self);
        fn_80117840(self);
        break;
    case 2:
        fn_801164AC(self);
        break;
    case 3:
        fn_801167AC(self);
        fn_80117840(self);
        break;
    }
}

void fn_801178D8(Scr* self)
{
    Unk800C7B40_Widget* w = (Unk800C7B40_Widget*)self->m1BC[0];
    w->fn_vslot16(0);
    w = (Unk800C7B40_Widget*)self->m1BC[0];
    w->fn_vslot8(0);
    self->m1BC[0] = 0;
    self->fn_vslot16(1);
    self->m19C->fn_vslot16(1);
}

void fn_80117984(Scr* self, int b)
{
    if (self->m1BC[0] == 0 || (fn_801178D8(self), self->m1BC[0] == 0)) {
        if (lbl_8061A32C == 0)
            lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
        Unk800C7B40_Widget* w = fn_800B7AB8(lbl_8061A32C, lbl_805BA6D8);
        self->m1BC[0] = (int)w;
        *(int*)((char*)w + 0x2F0) = -0x63;
    }
    self->fn_vslot16(0);
    self->m19C->fn_vslot16(0);
    if (b != 0)
        fn_80131F34((Unk800C7B40_Widget*)self->m1BC[0], self, fn_80117B04, 0, 0x5CDB, 2, -1, 1, 0x26DF, 0x26DE, 0, 0, 0, 0);
    else
        fn_80131F34((Unk800C7B40_Widget*)self->m1BC[0], self, fn_80117B60, 0, 0x5CDB, 2, -1, 1, 0x26DF, 0x26DE, b, b, b, b);
    ((Unk800C7B40_Widget*)self->m1BC[0])->fn_vslot86();
}

void fn_80117B04(int a, Scr* b)
{
    if (a) {
        if (a == 1) {
            lbl_806192E0->m4->mC->m600 = a;
            fn_80117BBC(b);
        }
    }
    fn_801178D8(b);
}

void fn_80117B60(int a, Scr* b)
{
    if (a) {
        if (a == 1) {
            lbl_806192E0->m4->mC->m600 = a;
            fn_80117C8C(b);
        }
    }
    fn_801178D8(b);
}

void fn_80117BBC(Scr* self)
{
    char nm[16];
    char* np = nm;
    fn_80117844(self);
    fn_80117840(self);
    fn_8035682C(np);
    fn_8040B830(np, lbl_805BADC8, 0xF);
    np[15] = 0;
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    fn_800B7B4C(lbl_8061A32C, np, self);
    EvtRaw e;
    const void* base = lbl_80649DA0;
    e.vt = base;
    e.id = 0x9E;
    e.vt = lbl_8065B888;
    fn_8037893C((char*)fn_8011AA24(0) + 0x704, e.id, &e, 0, 0);
    e.vt = base;
}

void fn_80117C8C(Scr* self)
{
    char nm[16];
    char* np = nm;
    fn_8035682C(np);
    fn_8040B830(np, lbl_805B955C, 0xF);
    np[15] = 0;
    fn_80117844(self);
    fn_80117840(self);
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    fn_800B7B4C(lbl_8061A32C, np, self);
}

void* fn_80117D20(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->SetVptr(lbl_8064E8D8);
    self->m134 = 0;
    return self;
}

void fn_80117D70(Unk80117D20_Scr* self)
{
    fn_800ECF18(self);
    UnkGame* g = fn_8011AA24(0);
    UnkGameP6F8* p = g->m6F8;
    int n = fn_801A71D0() != 0 ? 3 : 4;
    int idx = n;
    if (n > 2) {
        int t = 0;
        if (g->m6F8->m14->m1CD0 != 0)
            t = 1;
        idx = t;
        if (n != 3)
            idx ^= 1;
    }
    UnkPlayerRec* rec = &p->m14->rec[idx];
    const char* name;
    if (idx == 0)
        name = lbl_805BFB3C;
    else
        name = lbl_805BFB4C;
    SetSub98(fn_800C8054(self->fn_vslot29(name)), rec->m198);
    for (Wid* c = ((UnkGroupW*)self)->m40; c != 0; c = (Wid*)c->m8)
        fn_80117EA0(self, c, rec->m198);
    self->m134 = (int)fn_800ED2B0(self, lbl_805BE1B0);
}

void fn_80117EA0(Unk80117D20_Scr* self, Wid* w, int v)
{
    int t = w->m1C;
    if (t == 9) {
        if (v != 0) {
            UnkSub* s = (UnkSub*)((char*)fn_800C8054(w) + 0x98);
            s->fn_vslot20(v, 0);
        }
    } else if (t == 3 || t == 8) {
        for (Wid* c = ((UnkGroupW*)w)->m40; c != 0; c = (Wid*)c->m8)
            fn_80117EA0(self, c, v);
    }
}

void fn_80117F48(Unk80117D20_Scr* self)
{
    fn_800ECAA4(self);
    int v = *(int*)self->m134;
    if (v == 0) {
        char nm[16];
        char* np = nm;
        fn_8035682C(np);
        fn_8040B830(np, lbl_805B955C, 0xF);
        np[15] = v;
        if (lbl_8061A32C == 0)
            lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
        fn_800B7B4C(lbl_8061A32C, np, self);
    }
}

void* fn_80117FDC(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->SetVptr(lbl_8064E630);
    return self;
}

/* near-miss: shape of fn_80117D70 (same selection); retail has the index in r0 with extra copies (2 insns more). */
void fn_80118028(Unk80117D20_Scr* self)
{
    fn_800ECF18(self);
    UnkGame* g = fn_8011AA24(0);
    UnkGameP6F8* p = g->m6F8;
    int n = fn_801A71D0() != 0 ? 3 : 4;
    int idx = n;
    if (n > 2) {
        int t = 0;
        if (g->m6F8->m14->m1CD0 != 0)
            t = 1;
        idx = t;
        if (n != 3)
            idx ^= 1;
    }
    UnkPlayerRec* rec = &p->m14->rec[idx];
    const char* name;
    if (idx == 0)
        name = lbl_805BFB3C;
    else
        name = lbl_805BFB4C;
    SetSub98(fn_800C8054(self->fn_vslot29(name)), rec->m198);
    for (Wid* c = ((UnkGroupW*)self)->m40; c != 0; c = (Wid*)c->m8)
        fn_80118144(self, c, rec->m198);
}

void fn_80118144(Unk80117D20_Scr* self, Wid* w, int v)
{
    int t = w->m1C;
    if (t == 9) {
        if (v != 0) {
            UnkSub* s = (UnkSub*)((char*)fn_800C8054(w) + 0x98);
            s->fn_vslot20(v, 0);
        }
    } else if (t == 3 || t == 8) {
        for (Wid* c = ((UnkGroupW*)w)->m40; c != 0; c = (Wid*)c->m8)
            fn_80118144(self, c, v);
    }
}

void fn_801181EC(Scr* self)
{
    fn_800ECAA4(self);
}

void fn_80118A70(Unk80117D20_Scr* self)
{
    UnkGameP6F8* p = fn_8011AA24(0)->m6F8;
    int i = fn_801059E4();
    UnkPlayerRec* r = p->m14->rec + i;
    int v = r->m198;
    SetSub98(fn_800C8054(self->fn_vslot33(9, 1)), v);
    fn_80118D14(fn_800C8044(self->fn_vslot32(lbl_805BFB7C, 1)));
}

void fn_80118B2C(Scr* self)
{
    UnkGame* g = fn_8011AA24(0);
    const char* tbl1[4] = { lbl_805BFB84, lbl_805BFB88, lbl_805BFB8C, lbl_805BFB90 };
    const char* tbl2[4] = { lbl_805BFBA4, lbl_805BFBB0, lbl_805BFBBC, lbl_805BFBC8 };
    int k = 0;
    for (unsigned i = 9; (int)i <= 12; i++, k++) {
        int v;
        if (i <= 12) {
            char* b = (char*)g + 0x65C;
            int off = i * 4;
            v = *(int*)(b + off);
        } else
            v = 0;
        Wid* c = fn_800C8044(self->fn_vslot32(lbl_805BEFE4, 1));
        Wid* b = fn_800C8034(c->fn_vslot32(tbl1[k], 1));
        Wid* d = fn_800C8044(c->fn_vslot32(tbl2[k], 1));
        if (v != 0) {
            d->fn_vslot8(1);
            b->fn_vslot15(1);
            fn_8011A14C(v, d, lbl_805BDD9C, 1);
            fn_8011A518(v, d, lbl_805BD934);
        } else {
            d->fn_vslot8(0);
            b->fn_vslot15(0);
        }
    }
}

void fn_80119D44(UnkGame* g, Wid* w, int flag)
{
    int v;
    if (g->m6F8->m10->m74 == 2)
        v = fn_801C1638(g, 0);
    else
        v = fn_801A4B34(g);
    fn_8011A14C(v, w, lbl_805BDC84, 0);
    char buf[100] = "";
    fn_804089B4(buf, lbl_805BBE2C, fn_8025416C((char*)v + 0x588, 7));
    fn_800C8038(w->fn_vslot32(lbl_805BE3D0, 1))->fn_vslot8(0);
    Unk800ABDC4_R* r = fn_800ABDC4(lbl_80619D10, g);
    fn_8011A0A4(r->m10, w, lbl_805BFC9C);
    fn_8011A0A4(r->m14, w, lbl_805BFCA8);
    fn_8011A0A4(r->m8, w, lbl_805BFCB4);
    if (flag != 0) {
        fn_800C8058(w->fn_vslot32(lbl_805BFC94, 1))->fn_vslot8(1);
        int gg = lbl_80619D10;
        int a = fn_80144BF4(gg);
        int c = (a ^ fn_800ABC58(gg, g)) == 0;
        ((UnkSub*)((char*)fn_800C8058(w->fn_vslot32(lbl_805BFC94, 1)) + 0xDC))->fn_vslot6(c ^ 1);
    }
}

void fn_80119F48(char* buf, float v)
{
    int m = (int)((v + lbl_805BFCD4) * lbl_805BFCD8);
    m = m % 1000;
    if ((int)v > 0)
        fn_804089B4(buf, lbl_805BFCC4);
    else
        fn_804089B4(buf, lbl_805BFCCC, m);
}

void fn_80119FF0(char* buf, float v)
{
    int x = (int)((v + lbl_805BFCE4) * lbl_805BFCE8);
    if (x % 10 > 4)
        x += 10;
    x = x / 10;
    fn_804089B4(buf, lbl_805BFCDC, x / 100, x % 100);
}

void fn_8011A0A4(int v, Unk800C7B40_Widget* w, const char* name)
{
    char buf[40];
    buf[0] = lbl_805B9A30;
    fn_8040B320(buf + 1, 0, 0x27);
    fn_804089B4(buf, lbl_805BC1A8, v);
    fn_800C8040(w->fn_vslot32(name, 1))->fn_vslot30(buf);
}

void fn_8011A14C(int a, Unk800C7B40_Widget* w, const char* name, int flag)
{
    UnkTextArg arg;
    int c = 0;
    if (flag != 0)
        c = 1;
    fn_800DE274(&arg, a, c);
    fn_800C8040(w->fn_vslot32(name, 1))->fn_vslot28(&arg);
}

void fn_8011A1D4(UnkGame* g, int a, Unk800C7B40_Widget* w, const char* name)
{
    int t = fn_80097288(a, g->m704);
    fn_800C8040(w->fn_vslot32(name, 1))->fn_vslot30(fn_800E5E4C(t));
}

void fn_8011A268(char* base, Unk800C7B40_Widget* w, const char* name)
{
    fn_8011A0A4(fn_8025416C(base + 0x588, 4), w, name);
}

void fn_8011A2AC(int a, Unk800C7B40_Widget* w, const char* name)
{
    fn_8011A0A4(fn_8011B784(0, a, 2), w, name);
}

/* near-miss: 2 slots (retail sets r5=39 after mr r28,r6; li r4,0; 8 spellings of the buffer init tried). */
void fn_8011A2F4(char* p, int unused, Wid* w, const char* name, int flag)
{
    char buf[40];
    buf[0] = lbl_805B9A30;
    fn_8040B320(&buf[1], 0, 39);
    int s = fn_8025416C(p + 0x588, 9) == 1;
    int c = 2;
    if (flag == 0)
        c = s ^ 1;
    float f = fn_8011B81C(2, (int)p, c);
    fn_80119F48(buf, f);
    fn_800C8040(w->fn_vslot32(name, 1))->fn_vslot30(buf);
}

void fn_8011A3CC(int a, Unk800C7B40_Widget* w, const char* name)
{
    fn_8011A0A4(fn_8011B784(1, a, 2), w, name);
}

void fn_8011A414(int a, Unk800C7B40_Widget* w, const char* name)
{
    fn_8011A0A4((int)fn_8011B81C(0, a, 2), w, name);
}

void fn_8011A468(int a, Unk800C7B40_Widget* w, const char* name)
{
    char buf[40];
    buf[0] = lbl_805B9A30;
    fn_8040B320(buf + 1, 0, 0x27);
    float f = fn_8011B81C(3, a, 2);
    fn_80119F48(buf, f);
    fn_800C8040(w->fn_vslot32(name, 1))->fn_vslot30(buf);
}

}
