/*
 * Game code, .text 0x800B5C68-0x800B8AF0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800A8684.h"
#include "game/tu_8007A4DC.h"
#include "game/tu_800BCD38.h"
#include "game/tu_8001B190.h"

/* Block returned by fn_8007FE04 (lbl_8061930C's inner object): +0x74 receives the
 * fn_80086DD8 result (fn_800B80A4), +0x22C is read by fn_8007FDF8 and fn_800B8044. */
struct Unk8007F198_DI {
    char pad0[0x74];
    int m74;
    char pad78[0x22C - 0x78];
    int m22C;
};
struct Unk8007F198_D {
    Unk8007F198_DI* m0;
};
int fn_8007FDF8(Unk8007F198_D* self);
Unk8007F198_DI* fn_8007FE04(Unk8007F198_D* self);
int fn_80086DD8(void* p, unsigned a);
void fn_800736EC(const char* s);
extern Unk8007B2B0_Screen* lbl_8061930C;
extern const char lbl_805B9E14[];
extern const char lbl_805B9E68[];

/* Object returned by fn_8031CECC (+4 handle, +0x1AC flag). */
struct Unk8031CECC {
    int m0;
    int m4;
    char pad8[0x1AC - 8];
    int m1AC;
};

/* The 0x20-byte singleton at lbl_8061A49C (ctor fn_800B81F4, dtor fn_800B8220). */
class FEObj20 {
public:
    FEObj20();
    ~FEObj20();
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    void (*m1C)();
};
extern FEObj20* lbl_8061A49C;

/* Object with a vptr at +0x18 (vtable lbl_8065CB28): the front-end manager, 0xD8 bytes
 * (lbl_8061A32C, ctor fn_800B64BC). Slot 1 is its virtual destructor. */
class FEMgrV {
public:
    char pad0[0x18];
    virtual ~FEMgrV();
};


struct S74 {
    char pad0[0x74];
    int m74;
    char pad78[0x18C - 0x78];
    int m18C;
    char pad190[0x22C - 0x190];
    int m22C;
};
struct S10 {
    char pad0[0x10];
    S74* m10;
};
struct S806192E0 {
    int m0;
    S10* m4;
    S10* m8;
};
extern S806192E0* lbl_806192E0;

extern const char lbl_8065CBD0[];
extern char lbl_806879A0[];
extern int lbl_8061A4A0[];
extern const char lbl_805BA46C[];
extern const char lbl_805BA474[];
extern const char lbl_805BA488[];
extern int lbl_8061A324;
extern const char lbl_805BA24C[];
extern "C" {
int fn_803AC11C();
void fn_8033E958(const char* fmt, ...);
void fn_8031D134(Unk8031CECC* o);
void fn_8031D014(Unk8031CECC* o);
void fn_8031D2DC(Unk8031CECC* o, char* s, int a, int b);
}

extern "C" {
int fn_8057F14C(int a);
int fn_8057FD34(int a);
int fn_80580140();
int fn_80580C50();
int fn_805806CC();
int fn_8057E070(int a);
int fn_800B57EC();
}

Unk8001BC8C* fn_8001BC4C();
void fn_8001BD18();
struct Unk8008CE64_Own;
void fn_80090814(Unk8008CE64_Own* o, int a, int b);
extern void* lbl_80619948;
extern "C" {
void fn_8037CC30(void* o);
void* fn_8037C7FC();
void fn_800C3774(Unk800C341C_Mgr* m);
void fn_800C3BE0(Unk800C341C_Mgr* m);
Unk800C5E74_Obj* fn_800C5E28();
void fn_802B0778(void* o);
void fn_800A18C0(void* o);
}

struct Unk80090880;
struct FEUsh {
    unsigned short m0;
};
FEUsh* fn_80090880(Unk80090880* o, int id);
extern Unk80090880* lbl_8061977C;
extern const char lbl_805C2E58[];
extern const char lbl_805BA218[];
extern int lbl_8061A334;
struct FE8061B8C0 {
    char pad0[0x20];
    int m20;
    int m24;
};
extern FE8061B8C0* lbl_8061B8C0;
extern void* lbl_8061E978;

/* The front-end manager singleton (lbl_8061A32C, 0xD8 bytes): vptr at +0x18, a 0x14-byte
 * sub-object at +0x24, the FEObj68 at +0x38, the list at +0xA0. ctor fn_800B64BC, dtor
 * fn_800B6560. */
struct Unk800D876C_A;
struct FEEntry {
    char pad0[0x10];
    int m10;
    int m14;
    char pad18[0x8];
    char m20[1];
};
struct FEPair {
    int a;
    int b;
};
class FEV1C8 {
public:
    char pad0[0x1C8];
    virtual ~FEV1C8();
    virtual void s2();
    virtual void s3();
    virtual void s4(FEPair p);
};
extern FEPair lbl_805B98E8;
extern const char lbl_805BA240[];
struct FEMgr {
    char pad0[0x18];
    const void* m18;
    char pad1C[0x38 - 0x1C];
    FEObj68 m38;
    Unk800C68B4_List* mA0;
    FEEntry* mA4;
    FEEntry* mA8;
    int mAC;
    int mB0;
    int mB4;
    int mB8;
    int mBC;
    int mC0;
    float mC4;
    float mC8;
    int mCC;
    int mD0;
    int mD4;
};
void fn_800D876C(Unk800D876C_A* p);
void fn_8001BC58();
void fn_800AA144();
extern const char lbl_8065CB28[];
extern FEMgr* lbl_8061A32C;
extern const float lbl_805BA068;
extern const float lbl_805BA06C;
extern int lbl_8061A330;
extern int lbl_8061AC54;
extern const char lbl_805BA54C[];
extern const char lbl_805BA560[];
extern const char lbl_805BA574[];

extern "C" {
void fn_800B5D34();
void fn_800B5C9C();
void fn_8031D54C(Unk8031CECC* o);
void fn_8038E038(int h);
void fn_8038E05C(int h);
Unk8031CECC* fn_8031CECC();
void fn_800B82D0(FEObj20* p, int a, int b);
void fn_800B83F8(FEObj20* self, int a, int b);
void fn_800B8654(FEObj68* p, int c);
const char* fn_802B9300(int s, int a, int b, int c);
void fn_802B961C(const char* p, int a);
FEColor* fn_8014DBA0(FEColor* out, int r, int g, int b, int a);
FEColor* fn_8014D9C4(FEColor* p);
void fn_800B5F90(FEList* self, const char* p);
FEV64* fn_800B5FEC(FEList* self, const char** cur, FEV64* prev);
int fn_800B5DE8(const char** self, char* buf, unsigned n);
void fn_800B7614(void* self, int a);
void fn_800B7598(void* self, int k);
void fn_800B7618(FEMgr* self, const char* name);
void fn_800C6A38(Unk800C68B4_List* p);
void fn_800C69DC(Unk800C68B4_List* p);
void fn_802BA708(void* p);
void fn_8035682C(UiMsgBuf* m);
void fn_8040B830(char* dst, const char* src, int n);
void fn_800B7B4C(FEMgr* mgr, UiMsgBuf* m, void* ctx);
void fn_802B0C44(void* o, int a);
void fn_800E2C80(const char* s, int a);
void fn_800C1754(FEObj68* p, int a);
void fn_800B65C0(FEMgr* self);
void fn_800B8150();
Unk800B555C* fn_800B555C();
void fn_800B80A4(void* self, unsigned a);
int fn_802D7DB4(int a, int b);
void fn_80377408(void* p);
void* fn_803774A8(unsigned n, int heap);
char* fn_804031BC(unsigned short* d, const char* s);
void fn_80378C5C(const char* s, unsigned len, char* out, int size, int delim, int flag, unsigned* used);
int fn_804089B4(char* dst, const char* fmt, ...);
void fn_800C17D4(FEObj68* p);
void fn_802B0DB0(void* p);
void fn_800B8B3C(FEObj68* p, int a);
void fn_800B8CA4(FEObj68* p, const char* a);
void fn_800B8AF0(FEObj68* p);
Unk800C68B4_List* fn_800B8AA0(FEObj68* self, const char* a);
void fn_800B86A0(FEObj68* p);
void fn_800B7D14(void* p);
void fn_802D7ACC();
void fn_800C355C(Unk800C341C_Mgr* m, int a);
void fn_800B8700(FEObj68* p, int a);
void fn_8033E884(const char* s);
void fn_80328374(void* p, int c);
void fn_803282A8(void* p, int a);
void fn_8031D494(Unk8031CECC* o, float a, float b, float c, float d);
void fn_8031D61C(Unk8031CECC* o);
Unk8031CECC* fn_8031D6B0(Unk8031CECC* o);
}

/* ---- generated externs ---- */









/* ---- unit prototypes ---- */
extern "C" {
int fn_800B5C68();
void fn_800B5C9C();
void fn_800B5CBC();
void fn_800B5D0C();
void fn_800B5D34();
int fn_800B5D5C(const char** self, char* buf);
int fn_800B5DE8(const char** self, char* buf, unsigned n);
FEList* fn_800B5E68(FEList* self, int arg);
void fn_800B5EF0(FEList* self, int c);
void fn_800B5F90(FEList* self, const char* p);
FEElem* fn_800B622C(FEElem* self);
void fn_800B62FC(FEElem* self, int c);
void fn_800B6384(FEElem* self, const char* s);
void fn_800B6458(FEV64* self, const char* a);
FEMgr* fn_800B64BC(FEMgr* self);
void fn_800B6560(FEMgr* self, int c);
void fn_800B65C0(FEMgr* self);
void fn_800B66CC();
int fn_800B6C30();
void fn_800B7280(FEMgr* self, int a);
void fn_800B7598(void* self, int k);
void fn_800B7614(void* self, int a);
void fn_800B7618(FEMgr* self, const char* name);
void fn_800B7700(FEMgr* self);
void fn_800B7A94(FEMgr* p, const char* s);
void fn_800B7AB8(FEMgr* p, const char* s);
void fn_800B7ADC(FEMgr* self, FEV3C* obj);
int fn_800B7CDC(void* self, int a, int b);
void fn_800B7FC4(FEMgr* mgr);
void fn_800B8044(FEMgr* self);
void fn_800B80A4(void* self, unsigned a);
void fn_800B8108();
FEObj20* fn_800B8144();
void fn_800B8150();
void fn_800B8194();
void fn_800B81BC(int a);
void fn_800B8268(float a, float b, float c, float d);
void fn_800B82AC();
void fn_800B82D0(FEObj20* self, int to, int flag);
void fn_800B83F8(FEObj20* self, int a, int b);
void fn_800B8494(FEObj20* self);
void fn_800B84FC(FEObj20* self);
char* fn_800B859C(int unused, int idx);
FEObj68* fn_800B85FC(FEObj68* self);
void fn_800B8654(FEObj68* self, int c);
void fn_800B86A0(FEObj68* self);
void fn_800B89E8(FEObj68* self, int k);
Unk800C68B4_List* fn_800B8AA0(FEObj68* self, const char* a);
}
/* ---- end prototypes ---- */

/* ---- functions ---- */

extern "C" int fn_800B5C68()
{
    return fn_8007FDF8((Unk8007F198_D*)lbl_8061930C) == 0xE;
}

extern "C" void fn_800B5C9C()
{
    fn_800B5D34();
}

extern "C" void fn_800B5CBC()
{
    int r = lbl_8061930C->fn_8007DA28();
    if (r == -1) {
        fn_800B5C9C();
    } else {
        lbl_8061930C->fn_8007D098(r, 0);
    }
}

extern "C" void fn_800B5D0C()
{
    fn_800736EC(lbl_805B9E14);
}

extern "C" void fn_800B5D34()
{
    fn_800736EC(lbl_805B9E68);
}

extern "C" int fn_800B5D5C(const char** self, char* buf)
{
    unsigned used = 0;
    do {
        fn_80378B68(*self, 0x100, buf, 0x100, (int)lbl_805C2E58, 1, &used);
        if (used == 0) {
            return 0;
        }
        *self += used + 1;
    } while (buf[0] == 0x23);
    return 1;
}

extern "C" int fn_800B5DE8(const char** self, char* buf, unsigned n)
{
    unsigned used = 0;
    fn_80378C5C(*self, n, buf, n, lbl_8061A324, 2, &used);
    if (used == 0) {
        return 0;
    }
    *self += used + 1;
    return 1;
}

extern "C" FEList* fn_800B5E68(FEList* self, int arg)
{
    self->mB94 = lbl_806583A8;
    for (int i = 0; i < 0x2E4; i++) {
        self->m[i] = 0;
    }
    self->mB90 = 0;
    const char* p = fn_802B9300(arg, 0x100, 0xe, 0);
    fn_800B5F90(self, p);
    fn_802B961C(p, 0xe);
    return self;
}

extern "C" void fn_800B5EF0(FEList* self, int c)
{
    self->mB94 = lbl_806583A8;
    for (int i = 0; i < self->mB90; i++) {
        delete self->m[i];
        self->m[i] = 0;
    }
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" void fn_800B5F90(FEList* self, const char* p)
{
    const char* cur = p;
    FEV64* e = 0;
    int n = -1;
    do {
        n++;
        e = self->m[n] = fn_800B5FEC(self, &cur, e);
    } while (e);
    self->mB90 = n;
}

extern "C" FEElem* fn_800B622C(FEElem* self)
{
    self->m64 = lbl_80658680;
    fn_8014D9C4(&self->m40);
    fn_8014D9C4(&self->m50);
    for (int i = 0; i < 13; i++) self->m[i] = 0;
    FEColor c;
    fn_8014DBA0(&c, 0xc0, 0xc0, 0xc0, 0xff);
    self->m34 = 0;
    self->m38 = 0x17;
    self->m3C = 0x17;
    self->m40 = c;
    self->m50 = c;
    self->m60 = 5;
    return self;
}

extern "C" void fn_800B62FC(FEElem* self, int c)
{
    self->m64 = lbl_80658680;
    for (int i = 0; i < self->m34; i++) {
        delete[] self->m[i];
        self->m[i] = 0;
    }
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" void fn_800B6384(FEElem* self, const char* s)
{
    int off = self->m34 * 4;
    *(unsigned short**)((char*)self + off) = (unsigned short*)fn_803774A8((fn_8040B6A0(s) + 1) * 2, 0x100);
    fn_804031BC(self->m[self->m34], s);
    unsigned short* p = self->m[self->m34];
    while (*p != 0) {
        int c = *p;
        if (c == 0xA || c == 0xD) {
            *p = 0x20;
        }
        if (*p == 0x99) {
            *p = fn_80090880(lbl_8061977C, 0x337E)->m0;
        }
        p++;
    }
    self->m34 = self->m34 + 1;
}

extern "C" void fn_800B6458(FEV64* self, const char* a)
{
    char buf[0x190];
    while (fn_800B5DE8(&a, buf, 0x18f)) {
        self->s20(buf);
    }
}

extern "C" FEMgr* fn_800B64BC(FEMgr* self)
{
    fn_803282A8(self, 0);
    self->m18 = lbl_8065CB28;
    fn_800D876C((Unk800D876C_A*)((char*)self + 0x24));
    fn_800B85FC(&self->m38);
    self->mC4 = lbl_805BA068;
    self->mC8 = lbl_805BA06C;
    self->mA0 = 0;
    self->mA4 = 0;
    self->mA8 = 0;
    self->mAC = 0;
    self->mB0 = 0;
    self->mB4 = 1;
    self->mB8 = 0;
    self->mBC = 0;
    self->mD0 = 0;
    self->mD4 = 0;
    lbl_8061A330 = 1;
    self->mCC = 0;
    return self;
}

extern "C" void fn_800B6560(FEMgr* self, int c)
{
    self->m18 = lbl_8065CB28;
    fn_800B65C0(self);
    fn_8001BC58();
    fn_800AA144();
    fn_800B8150();
    fn_800B8654(&self->m38, 2);
    fn_80328374(self, c);
}

extern "C" void fn_800B65C0(FEMgr* self)
{
    if (self->mA0 != 0) {
        fn_800C6A38(self->mA0);
        delete (FEV1C8*)self->mA0;
        self->mA0 = 0;
        fn_802BA708((char*)lbl_8061E978 + 0xFAB0);
    }
    fn_8037CC30(fn_8037C7FC());
    fn_800B86A0(&self->m38);
    fn_800B82D0(fn_800B8144(), -1, 1);
    fn_8001BC4C()->fn_8001BDAC(0xB2);
    fn_8001BC4C();
    fn_8001BD18();
    fn_800C3774(fn_800C33D0());
    fn_800C3BE0(fn_800C33D0());
    fn_800C5E28()->fn_800C6624();
    fn_800C3A4C(fn_800C33D0());
    fn_802B0778(lbl_8061E978);
    if (lbl_8061A334 == 0) {
        fn_800A18C0(lbl_80619948);
        fn_80090814((Unk8008CE64_Own*)lbl_8061977C, 1, 0);
    }
}

extern "C" void fn_800B66CC()
{
    if (lbl_8061A32C) {
        delete (FEMgrV*)lbl_8061A32C;
    }
    lbl_8061A32C = 0;
}

extern "C" int fn_800B6C30()
{
    int total = 0;
    S74* g = lbl_806192E0->m4->m10;
    if (g->m74 == 1) {
        total = fn_8057F14C(0);
        total += fn_8057F14C(1);
    } else if (g->m74 == 2) {
        total = fn_8057FD34(0);
        total += fn_8057FD34(1);
    } else if (g->m74 == 5 || (fn_800B555C(), fn_800B57EC() == 0 && fn_800B555C()->m660 == 4)) {
        total = fn_80580140();
    } else if (g->m74 == 6 || (fn_800B555C(), fn_800B57EC() == 0 && fn_800B555C()->m660 == 5)) {
        if (g->m18C == 0) {
            total = fn_80580C50();
        } else {
            total = fn_805806CC();
        }
    } else if (g->m22C == 0) {
        total = fn_8057E070(0);
        total += fn_8057E070(1);
    }
    return total > 0;
}

extern "C" void fn_800B7280(FEMgr* self, int a)
{
    if (lbl_8061A334 != 0) {
        fn_800C355C(fn_800C33D0(), 1);
        fn_800B8700(&self->m38, a);
        lbl_8061A334 = 0;
    }
    fn_8033E884(lbl_805BA218);
}

extern "C" void fn_800B7598(void* self, int k)
{
    FE8061B8C0* f = lbl_8061B8C0;
    switch (k) {
    case 1:
        f->m20 = 1;
        break;
    case 3:
        fn_800B7D14(self);
        f->m20 = 1;
        break;
    case 4:
        f->m20 = 1;
        f->m24 = 0;
        fn_802D7ACC();
        break;
    }
}

extern "C" void fn_800B7614(void* self, int a)
{
}

extern "C" void fn_800B7618(FEMgr* self, const char* name)
{
    if (name != 0) {
        if ((unsigned)fn_8040B6A0(name) > 1) {
            if (self->mA0 != 0) {
                fn_800C6A38(self->mA0);
                delete (FEV1C8*)self->mA0;
                fn_802BA708((char*)lbl_8061E978 + 0xFAB0);
            }
            self->mA0 = 0;
            self->mA0 = fn_800B8AA0(&self->m38, name);
            ((FEV1C8*)self->mA0)->s4(lbl_805B98E8);
            fn_800C69DC(self->mA0);
            self->mA0->fn_800C696C();
        }
    }
}

extern "C" void fn_800B7700(FEMgr* self)
{
    int two = 2;
    self->mC0 = self->mB8 ^ 1;
    lbl_8061AC54 = two;
    if (self->mA8->m10 != 0) {
        fn_800B7614(self, self->mA8->m14);
    }
    if (self->mA4->m10 != 0) {
        fn_800B7598(self, self->mA4->m14);
    }
    fn_800B7618(self, self->mA4->m20);
}

class FEO7784 {
public:
    char pad0[8];
    virtual void s1();
    virtual void s2(int a);
};
typedef void (FEO7784::*FEPmf7784)(int);
struct FEEnt7784 {
    int key;
    FEPmf7784 fn;
};
struct FEObj7784 {
    char pad0[0xA0];
    FEO7784* mA0;
    char padA4[0xB0 - 0xA4];
    int mB0;
    char padB4[0xBC - 0xB4];
    int mBC;
};
extern FEEnt7784 lbl_8061A33C[];
extern int lbl_8061A338;

extern "C" void fn_800B7784(FEObj7784* self)
{
    int j;
    if (self->mBC == 0 || lbl_8061A338 == 1) {
        int i = 0;
        if (self->mB0 == 0) {
            do {
                j = 0;
                do {
                    if (fn_800B7CDC(self, j, lbl_8061A33C[i].key) != 0) {
                        (self->mA0->*lbl_8061A33C[i].fn)(j);
                        if (self->mB0 != 0) {
                            break;
                        }
                    }
                    j++;
                } while (j <= 3);
                i++;
            } while (i <= 0x18 && self->mB0 == 0);
        }
    } else {
        j = 0;
        do {
            if (fn_800B7CDC(self, j, 5) != 0) {
                fn_800B7FC4((FEMgr*)self);
            }
            j++;
        } while (j <= 3);
    }
}

class FER8 {
public:
    char pad0[8];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
};
struct FEObj780 {
    char pad0[0x780];
    int m780;
    int m784;
};
struct FEB8C0v {
    char pad0[8];
    FEObj780* m8;
};
struct FEFF44 {
    char pad0[0x2C];
    int m2C;
};
extern FEPair lbl_805B98F0;
extern int lbl_8061A494;
extern int lbl_8061A498;
extern FEFF44* lbl_8061FF44;
extern "C" FER8* fn_801A4CE8(FEObj780* o, int a);
extern "C" void fn_803188FC(FEFF44* o, int a);

/* near-miss (99.8%): the two flag locals take r28/r29 swapped */
extern "C" void fn_800B78D8(FEMgr* self)
{
    if (self->mCC != 0) {
        lbl_8061A494 = 1;
    }
    int f2 = 0;
    int f1 = 0;
    if (self->mB8 != 0) {
        FEObj780* o = ((FEB8C0v*)lbl_8061B8C0)->m8;
        if (o != 0) {
            if (fn_801A4CE8(o, 1)->v9() != 0) {
                f1 = 1;
            }
            if (o->m784 == 0) {
                int t = 0;
                if (o->m780 != 0) {
                    t = 1;
                }
                if (t != 0) {
                    f2 = 1;
                }
            } else {
                f2 = 1;
            }
        }
    }
    if (lbl_8061A498 != 0 || f1 == 0 || lbl_8061A330 != 0 || self->mCC != 0 || lbl_8061A494 > 0 || lbl_8061B8C0->m24 != 0 || f2 != 0) {
        fn_803188FC(lbl_8061FF44, 0);
        lbl_8061FF44->m2C = 0;
        if (self->mA0 != 0) {
            fn_800B8494(fn_800B8144());
            ((FEV1C8*)self->mA0)->s4(lbl_805B98F0);
        }
        if (self->mCC == 0 && lbl_8061A494 > 0) {
            lbl_8061A494 = lbl_8061A494 - 1;
        }
    }
    lbl_8061A330 = 0;
}

extern "C" void fn_800B7A94(FEMgr* p, const char* s)
{
    p->mA0->fn_800C68D0(s);
}

extern "C" void fn_800B7AB8(FEMgr* p, const char* s)
{
    p->mA0->fn_800C694C(s);
}

extern "C" void fn_800B7ADC(FEMgr* self, FEV3C* obj)
{
    if (self->mB0 == 0) {
        UiMsgBuf m;
        UiMsgBuf* p = &m;
        fn_8035682C(p);
        obj->s79(p->name);
        fn_800B7B4C(self, p, obj);
    }
}

extern "C" int fn_800B7CDC(void* self, int a, int b)
{
    int ok = fn_802D7DB4(a, b);
    int t = 0;
    if (ok) {
        t = 1;
    }
    return t;
}

extern "C" void fn_800B7FC4(FEMgr* mgr)
{
    UiMsgBuf m;
    UiMsgBuf* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, lbl_805BA240, 15);
    p->name[15] = 0;
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC((FEMgr*)operator new(0xD8, 0));
    }
    fn_800B7B4C(lbl_8061A32C, p, 0);
}

extern "C" void fn_800B8044(FEMgr* self)
{
    if (self->mD0 != 0) {
        fn_800B555C()->m660 = self->mD4;
        self->mD0 = 0;
        fn_800B80A4(self, fn_8007FE04((Unk8007F198_D*)lbl_8061930C)->m22C);
    }
}

extern "C" void fn_800B80A4(void* self, unsigned a)
{
    Unk8007F198_DI* p = fn_8007FE04((Unk8007F198_D*)lbl_8061930C);
    int v = fn_80086DD8(p, a);
    p->m74 = v;
    lbl_806192E0->m4->m10->m74 = v;
    lbl_806192E0->m8->m10->m74 = v;
}

extern "C" void fn_800B8108()
{
    lbl_8061A49C = new (0) FEObj20;
}

extern "C" FEObj20* fn_800B8144()
{
    return lbl_8061A49C;
}

extern "C" void fn_800B8150()
{
    if (lbl_8061A49C) {
        delete lbl_8061A49C;
        lbl_8061A49C = 0;
    }
}

extern "C" void fn_800B8194()
{
    FEObj20* o = lbl_8061A49C;
    if (o == 0) {
        return;
    }
    if (o->m8 == -1) {
        return;
    }
    o->m4 = 1;
}

extern "C" void fn_800B81BC(int a)
{
    FEObj20* o = lbl_8061A49C;
    if (o) {
        fn_800B83F8(o, a, 0);
    }
}

FEObj20::FEObj20()
{
    m4 = 0;
    m14 = -1;
    m18 = 0;
    m1C = 0;
    m8 = -1;
    m0 = 0;
    m10 = -1;
}

extern "C" void fn_800B8268(float a, float b, float c, float d)
{
    fn_8031D494(fn_8031CECC(), a, b, c, d);
}

extern "C" void fn_800B82AC()
{
    fn_8031D54C(fn_8031CECC());
}

FEObj20::~FEObj20()
{
    fn_800B82D0(this, -1, 1);
}

/* near-miss (73 vs 74 insns): retail keeps two separate -1 constants (r28, r29) set before the first call; ours merges them */
extern "C" void fn_800B82D0(FEObj20* self, int to, int flag)
{
    if (self->m0 == 0) {
        if ((unsigned)to > 7) {
            if (to != self->m8) {
                if (to != -3) {
                    int f = 0;
                    if ((unsigned)(to - 9) <= 0x2F) {
                        int ok = fn_803AC11C();
                        f = 1;
                        if (ok == 0) {
                            to = -1;
                            fn_8033E958(lbl_805BA24C);
                        }
                    }
                    int m1 = -1;
                    int m2 = -1;
                    self->m8 = m1;
                    fn_8031D134(fn_8031CECC());
                    fn_8031D014(fn_8031CECC());
                    if (to == -1) {
                        if (self->m8 != -1) {
                            self->m10 = self->m8;
                        }
                        void (*cb)() = self->m1C;
                        self->m8 = m2;
                        if (cb != 0) {
                            cb();
                            self->m1C = 0;
                        }
                    } else {
                        int w = to;
                        if (to == -2) {
                            w = self->m10;
                        }
                        if ((unsigned)w > 0x3A) {
                            self->m8 = m1;
                        } else {
                            char* str = fn_800B859C((int)self, w);
                            fn_8031D2DC(fn_8031CECC(), str, f, 0);
                            self->m8 = w;
                        }
                    }
                }
            }
        }
    }
}

extern "C" void fn_800B83F8(FEObj20* self, int a, int b)
{
    if (self->m18 == 0 && self->m18 == a) {
        return;
    }
    int id = self->m8;
    self->m18 = a;
    if (id != -1) {
        if (a != 0) {
            if (b != 0) {
                fn_8038E038(fn_8031CECC()->m4);
            } else {
                Unk8031CECC* s = fn_8031CECC();
                fn_8038E038(s->m4);
                s->m1AC = 1;
            }
        } else {
            Unk8031CECC* s = fn_8031CECC();
            fn_8038E05C(s->m4);
            s->m1AC = a;
        }
    }
}

extern "C" void fn_800B8494(FEObj20* self)
{
    if (self->m0 != 0) {
        if (self->m1C != 0) {
            self->m1C();
            self->m1C = 0;
        }
    } else if (self->m8 != -1) {
        fn_8031D61C(fn_8031CECC());
    }
}

extern "C" void fn_800B84FC(FEObj20* self)
{
    if (self->m4 != 0) {
        FEObj20* o = lbl_8061A49C;
        void (*f)() = o->m1C;
        int id = o->m8;
        o->m1C = 0;
        fn_800B82D0(o, -1, 0);
        lbl_8061A49C->m1C = f;
        fn_800B82D0(lbl_8061A49C, id, 0);
        self->m4 = 0;
    } else {
        Unk8031CECC* r = fn_8031D6B0(fn_8031CECC());
        if (r == 0) {
            if (self->m1C != 0) {
                self->m1C();
                self->m1C = 0;
            }
        }
    }
}

/* near-miss (4 slots): retail forms the buffer address (addi r3) after the string addresses; ~10 argument/local forms tried */
extern "C" char* fn_800B859C(int unused, int idx)
{
    fn_804089B4(lbl_806879A0, lbl_805BA46C, lbl_805BA474, lbl_8061A4A0[idx], lbl_805BA488);
    return lbl_806879A0;
}

extern "C" FEObj68* fn_800B85FC(FEObj68* self)
{
    self->m64 = lbl_8065CBD0;
    self->m0 = 0;
    self->m4 = 0;
    self->m8 = 0;
    self->mC = 0;
    self->m10 = 0;
    self->m34 = -1;
    self->m38 = 0;
    self->m48 = -1;
    self->m3C = 0;
    self->m58 = 0;
    self->m1C = 0;
    self->m5C = 7;
    self->m40 = 0;
    self->m60 = 0;
    return self;
}

extern "C" void fn_800B8654(FEObj68* self, int c)
{
    self->m64 = lbl_8065CBD0;
    fn_800B86A0(self);
    if (c & 1) {
        fn_80377408(self);
    }
}

extern "C" void fn_800B86A0(FEObj68* self)
{
    if (self->mC != 0) {
        fn_80377408((void*)self->mC);
        self->mC = 0;
    }
    fn_800C17D4(self);
    fn_802B0DB0(lbl_8061E978);
    self->m10 = 0;
    self->m14 = 0;
}

extern "C" void fn_800B89E8(FEObj68* self, int k)
{
    if (k == 1) {
        fn_800B86A0(self);
        fn_802B0C44(lbl_8061E978, 0x16);
        fn_802B0C44(lbl_8061E978, 0x15);
        fn_802B0C44(lbl_8061E978, 0x17);
        fn_800E2C80(lbl_805BA54C, 0x400);
        fn_800E2C80(lbl_805BA560, 0x400);
        fn_800E2C80(lbl_805BA574, 0x500);
        fn_800C1754(self, 0x465);
        self->m8 = 0x119400;
        fn_800B8B3C(self, 1);
        self->m5C = k;
    }
}

extern "C" Unk800C68B4_List* fn_800B8AA0(FEObj68* self, const char* a)
{
    if (self->m60 != 0) {
        fn_800B8AF0(self);
    }
    fn_800B8CA4(self, a);
    self->m10 = 0;
}
