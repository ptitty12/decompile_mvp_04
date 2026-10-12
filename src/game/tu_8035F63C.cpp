/*
 * Game code, .text 0x8035F63C-0x80360168 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8035B60C.h"
#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))
#define PUTI(o, v) (*(int*)((char*)self + (o)) = (v))
#define PUTB(o, v) (*(unsigned char*)((char*)self + (o)) = (v))
#define PUTF(o, v) (*(float*)((char*)self + (o)) = (v))
#define CPUT(o, v) (*(const void**)((char*)this + (o)) = (v))
#define CPUTI(o, v) (*(int*)((char*)this + (o)) = (v))
#define CPUTB(o, v) (*(unsigned char*)((char*)this + (o)) = (v))
#define CPUTF(o, v) (*(float*)((char*)this + (o)) = (v))
#define GETI(o) (*(int*)((char*)self + (o)))
struct U {
    char pad0[0x4000];
};
void fn_80377408(void* p);
extern char lbl_8064A550[];
extern char lbl_80665D88[];
extern char lbl_80666EC0[];
extern char lbl_806655E8[];
extern char lbl_80665DD8[];
extern char lbl_80665E08[];
extern char lbl_80666EC0[];
void fn_80330870(void* p, int chrg);
void fn_8035686C(void* p, int chrg);
extern char lbl_8064B298[];
extern char lbl_806646F0[];
extern char lbl_80665DC0[];
extern char lbl_80666548[];
#include "game/chooser.h"
void fn_803E47E8(void* p);
void fn_802D1278(void* p);
void fn_803BD1F4(void* p);
void fn_80330870(void* p, int chrg);
void fn_80360004(void* p, int chrg);
void fn_80360080(void* p, int chrg);
void* fn_803774A8(unsigned size, int heap);
void fn_80377488(void* p);
struct Unk80310934_Z;
void fn_80312064(Unk80310934_Z* p);
void fn_8031208C(void* p, int chrg);
extern char lbl_805EBBF8[];
struct Unk8035F69C {
    int m0[9];
    int m24;
};
void fn_8035FFC4(void* p, int chrg);
inline void Unk8035FAA0_Inl(char* p)
{
    *(const void**)(p + 0x58) = lbl_8064B298;
    *(const void**)(p + 0x8) = lbl_80666EC0;
}
struct Unk80330870 {
    char pad0[0x2E0];
    ~Unk80330870();
};
struct Unk8035FC78_VB {
    char pad0[8];
    virtual ~Unk8035FC78_VB();
};
struct Unk8035FC78_E : Unk8035FC78_VB {
    char pad1[0x68 - 0xC];
};
struct Unk8035FC78_M {
    int m0;
    int m4;
    const void* m8;
    ~Unk8035FC78_M() { m8 = lbl_80666EC0; }
};
struct Unk8035FC78 : Unk80330870 {
    Unk8035FC78_E m2E0[32];
    Unk8035FC78_M mFE0;
    char padFEC[0x1300 + 4 - 0xFEC];
    ~Unk8035FC78();
};
void fn_80359604(void* p, int chrg);

extern "C" void fn_8037B424(void*, int);

extern "C" void fn_8035F63C(void* a, int b) { fn_8037B424(a, b); }

extern "C" void fn_8035F65C(void* a, int b) { fn_8037B424(a, b); }

extern "C" void fn_8035F67C(void* a, int b) { fn_8037B424(a, b); }



void fn_8035F69C(Unk8035F69C* s)
{
    s->m24 = 0;
    for (int i = 0; i < 9; i++)
        s->m0[i] = 0;
}

extern "C" void fn_8035F6C0(void* a, int b) { fn_8037B424(a, b); }

extern "C" void fn_8035F6E0(void* a, int b) { fn_8037B424(a, b); }

extern "C" void fn_8035F700(void* a, int b) { fn_8037B424(a, b); }




struct Unk8035F720 {
    char pad0[0x400];
    Unk8035F720();
};

Unk8035F720::Unk8035F720()
{
    CPUT(0x0, lbl_80665E08);
}

struct Unk8035F734 {
    char pad0[0x400];
    Unk8035F734();
};

Unk8035F734::Unk8035F734()
{
    CPUT(0x0, lbl_80665DD8);
}

void fn_8035F748(U* self, int chrg)
{
    PUT(0x8, lbl_80665D88);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035F77C(U* self)
{
    PUTI(0x4, 0);
}

U* fn_8035F788(U* self)
{
    fn_803E47E8(self);
    return self;
}

void fn_8035F7B8(U* self, int chrg)
{
    char* start = (char*)self + 0x10;
    if (start != 0) {
        char* end = (char*)self + 0x88;
        if (start != end) {
            do {
                end -= 0x28;
                fn_8031208C(end, 0);
            } while (start != end);
        }
    }
    if (chrg & 1)
        fn_80377408(self);
}

U* fn_8035F820(U* self)
{
    int i = 2;
    char* p = (char*)self + 0x10;
    do {
        fn_80312064((Unk80310934_Z*)p);
        p += 0x28;
    } while (i-- != 0);
    return self;
}

struct Unk8035F86C {
    char pad0[0x400];
    Unk8035F86C();
};

Unk8035F86C::Unk8035F86C()
{
    CPUT(0x4, lbl_806655E8);
}

void fn_8035F880(U* self, int chrg)
{
    PUT(0x14, lbl_80665DC0);
    fn_803BD1F4(self);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035F8CC(int* a, int* b, int n)
{
    int* tmp = (int*)fn_803774A8(n * 4, 0x100);
    for (int i = 0; i < n; i++)
        tmp[i] = b[a[i]];
    for (int i = 0; i < n; i++)
        b[i] = tmp[i];
    if (tmp)
        fn_80377488(tmp);
}

void fn_8035F95C(int* a, int* b, int n)
{
    int* tmp = (int*)fn_803774A8(n * 4, 0x100);
    for (int i = 0; i < n; i++)
        tmp[i] = b[a[i]];
    for (int i = 0; i < n; i++)
        b[i] = tmp[i];
    if (tmp)
        fn_80377488(tmp);
}

U* fn_8035F9EC(U* self)
{
    fn_802D1278(self);
    return self;
}

void fn_8035FA1C(U* self, int chrg)
{
    PUT(0x0, lbl_806646F0);
    ((Unk8037B3E8*)self)->Unk8037B3E8::~Unk8037B3E8();
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035FA6C(U* self, int chrg)
{
    PUT(0x8, lbl_80666EC0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035FAA0(U* self, int chrg)
{
    PUT(0xC78, lbl_80666EC0);
    PUT(0xC14, lbl_80666EC0);
    PUT(0xBAC, lbl_80666EC0);
    PUT(0xB44, lbl_80666EC0);
    PUT(0xAF8, lbl_80666EC0);
    PUT(0xA94, lbl_80666EC0);
    PUT(0xA00, lbl_80666EC0);
    PUT(0x998, lbl_80666EC0);
    PUT(0x930, lbl_80666EC0);
    PUT(0x8C8, lbl_80666EC0);
    Unk8035FAA0_Inl((char*)self + 0x65C);
    fn_8035FFC4((char*)self + 0x5C0, 2);
    fn_8035FFC4((char*)self + 0x534, 2);
    fn_8035FFC4((char*)self + 0x4A8, 2);
    fn_8035FFC4((char*)self + 0x41C, 2);
    PUT(0x3D0, lbl_80666EC0);
    PUT(0x37C, lbl_80666EC0);
    PUT(0x334, lbl_80666EC0);
    PUT(0x2E8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_8035FB5C(U* self, int chrg)
{
    PUT(0xe38, lbl_80666EC0);
    PUT(0xdec, lbl_80666EC0);
    PUT(0xda0, lbl_80666EC0);
    PUT(0xd54, lbl_80666EC0);
    PUT(0xd08, lbl_80666EC0);
    PUT(0xcbc, lbl_80666EC0);
    PUT(0xc70, lbl_80666EC0);
    PUT(0xc24, lbl_80666EC0);
    PUT(0xbd8, lbl_80666EC0);
    PUT(0xb84, lbl_80666EC0);
    PUT(0xb1c, lbl_80666EC0);
    PUT(0xac8, lbl_80666EC0);
    PUT(0xa74, lbl_80666EC0);
    PUT(0xa10, lbl_80666EC0);
    PUT(0x9bc, lbl_80666EC0);
    PUT(0x968, lbl_80666EC0);
    PUT(0x914, lbl_80666EC0);
    PUT(0x8c0, lbl_80666EC0);
    PUT(0x86c, lbl_80666EC0);
    PUT(0x804, lbl_80666EC0);
    PUT(0x7b0, lbl_80666EC0);
    PUT(0x75c, lbl_80666EC0);
    PUT(0x710, lbl_80666EC0);
    PUT(0x6c4, lbl_80666EC0);
    PUT(0x65c, lbl_80666EC0);
    PUT(0x608, lbl_80666EC0);
    PUT(0x5b4, lbl_80666EC0);
    PUT(0x560, lbl_80666EC0);
    PUT(0x50c, lbl_80666EC0);
    PUT(0x4b8, lbl_80666EC0);
    PUT(0x464, lbl_80666EC0);
    PUT(0x3fc, lbl_80666EC0);
    PUT(0x390, lbl_80666EC0);
    PUT(0x33c, lbl_80666EC0);
    PUT(0x2e8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_8035FC14(U* self, int chrg)
{
    PUT(0x78c, lbl_80666EC0);
    PUT(0x738, lbl_80666EC0);
    PUT(0x6d0, lbl_80666EC0);
    PUT(0x67c, lbl_80666EC0);
    PUT(0x628, lbl_80666EC0);
    PUT(0x5d4, lbl_80666EC0);
    PUT(0x580, lbl_80666EC0);
    PUT(0x52c, lbl_80666EC0);
    PUT(0x4e0, lbl_80666EC0);
    PUT(0x478, lbl_80666EC0);
    PUT(0x424, lbl_80666EC0);
    PUT(0x3d0, lbl_80666EC0);
    PUT(0x37c, lbl_80666EC0);
    PUT(0x2e8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

Unk8035FC78::~Unk8035FC78()
{
    CPUT(0x1300, lbl_80666EC0);
    CPUT(0x1298, lbl_80666EC0);
    CPUT(0x1230, lbl_80666EC0);
    CPUT(0x11C8, lbl_80666EC0);
    CPUT(0x1160, lbl_80666EC0);
    CPUT(0x10F8, lbl_80666EC0);
    CPUT(0x1090, lbl_80666EC0);
    CPUT(0x103C, lbl_80666EC0);
}

/* near-miss: 2 slots; retail emits stw 0x1118 before addi r9,r9,lbl_80666548@l (after lis r9 / addi r11,this+0x524); ours puts the addi first. Tried the vptr in a local before or after s0. */
void fn_8035FD1C(U* self, int chrg)
{
    PUT(0x1598, lbl_80666EC0);
    PUT(0x1544, lbl_80666EC0);
    PUT(0x14f0, lbl_80666EC0);
    PUT(0x148c, lbl_80666EC0);
    PUT(0x1438, lbl_80666EC0);
    PUT(0x13e4, lbl_80666EC0);
    PUT(0x1390, lbl_80666EC0);
    PUT(0x133c, lbl_80666EC0);
    PUT(0x12e8, lbl_80666EC0);
    PUT(0x1294, lbl_80666EC0);
    PUT(0x1240, lbl_80666EC0);
    PUT(0x11ec, lbl_80666EC0);
    PUT(0x1198, lbl_80666EC0);
    fn_80359604((char*)self + 0x1174, 2);
    char* s0 = (char*)self + 0x524;
    PUT(0x1118, lbl_80666EC0);
    PUT(0x10b4, lbl_80666EC0);
    PUT(0x1050, lbl_80666EC0);
    PUT(0xfec, lbl_80666EC0);
    PUT(0xf98, lbl_80666EC0);
    PUT(0xf44, lbl_80666EC0);
    PUT(0xef0, lbl_80666EC0);
    PUT(0xe9c, lbl_80666EC0);
    PUT(0xe48, lbl_80666EC0);
    PUT(0xdf4, lbl_80666EC0);
    PUT(0xda0, lbl_80666EC0);
    PUT(0xd4c, lbl_80666EC0);
    PUT(0xcf8, lbl_80666EC0);
    PUT(0xca4, lbl_80666EC0);
    PUT(0xc50, lbl_80666EC0);
    PUT(0xbfc, lbl_80666EC0);
    PUT(0xba8, lbl_80666EC0);
    PUT(0xb54, lbl_80666EC0);
    PUT(0xb00, lbl_80666EC0);
    PUT(0xaac, lbl_80666EC0);
    PUT(0xa58, lbl_80666EC0);
    PUT(0xa04, lbl_80666EC0);
    PUT(0x9b0, lbl_80666EC0);
    PUT(0x95c, lbl_80666EC0);
    PUT(0x908, lbl_80666EC0);
    *(const void**)(s0 + 0x2DC) = lbl_80666548;
    PUT(0x8b4, lbl_80666EC0);
    PUT(0x860, lbl_80666EC0);
    PUT(0x80c, lbl_80666EC0);
    fn_80330870(s0, 2);
    PUT(0x4e0, lbl_80666EC0);
    PUT(0x48c, lbl_80666EC0);
    PUT(0x438, lbl_80666EC0);
    PUT(0x3e4, lbl_80666EC0);
    PUT(0x390, lbl_80666EC0);
    PUT(0x33c, lbl_80666EC0);
    PUT(0x2e8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_8035FE44(U* self, int chrg)
{
    PUT(0xa00, lbl_80666EC0);
    PUT(0x998, lbl_80666EC0);
    PUT(0x944, lbl_80666EC0);
    PUT(0x8dc, lbl_80666EC0);
    PUT(0x888, lbl_80666EC0);
    PUT(0x83c, lbl_80666EC0);
    PUT(0x7f0, lbl_80666EC0);
    PUT(0x78c, lbl_80666EC0);
    PUT(0x740, lbl_80666EC0);
    PUT(0x6dc, lbl_80666EC0);
    PUT(0x678, lbl_80666EC0);
    PUT(0x614, lbl_80666EC0);
    PUT(0x5b0, lbl_80666EC0);
    PUT(0x564, lbl_80666EC0);
    PUT(0x510, lbl_80666EC0);
    PUT(0x4bc, lbl_80666EC0);
    PUT(0x468, lbl_80666EC0);
    PUT(0x400, lbl_80666EC0);
    PUT(0x398, lbl_80666EC0);
    PUT(0x334, lbl_80666EC0);
    PUT(0x2e8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_8035FEC4(U* self, int chrg)
{
    PUT(0x19DC, lbl_80666EC0);
    PUT(0x1990, lbl_80666EC0);
    PUT(0x1944, lbl_80666EC0);
    PUT(0x18F8, lbl_80666EC0);
    fn_80360004((char*)self + 0xE80, 2);
    fn_80360080((char*)self + 0x378, 2);
    PUT(0x334, lbl_80666EC0);
    PUT(0x2E8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

unsigned short fn_8035FF34(int x) { return (x >> 16) ^ x; }

void fn_8035FF44(U* self, int chrg)
{
    PUT(0x10, lbl_8064A550);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035FF78(U* self, int chrg)
{
    PUT(0x8, lbl_80666EC0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_8035FFAC() {}

int fn_8035FFB0() { return 0; }

char* fn_8035FFB8() { return lbl_805EBBF8; }

void fn_8035FFC4(U* self, int chrg)
{
    PUT(0x58, lbl_8064B298);
    PUT(0x8, lbl_80666EC0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80360004(U* self, int chrg)
{
    PUT(0x9f0, lbl_80666EC0);
    PUT(0x99c, lbl_80666EC0);
    PUT(0x938, lbl_80666EC0);
    PUT(0x8e4, lbl_80666EC0);
    PUT(0x880, lbl_80666EC0);
    PUT(0x81c, lbl_80666EC0);
    PUT(0x7c8, lbl_80666EC0);
    PUT(0x768, lbl_80666EC0);
    PUT(0x708, lbl_80666EC0);
    PUT(0x6a8, lbl_80666EC0);
    PUT(0x648, lbl_80666EC0);
    PUT(0x5e8, lbl_80666EC0);
    PUT(0x588, lbl_80666EC0);
    PUT(0x528, lbl_80666EC0);
    PUT(0x4c8, lbl_80666EC0);
    PUT(0x468, lbl_80666EC0);
    PUT(0x404, lbl_80666EC0);
    PUT(0x3a0, lbl_80666EC0);
    PUT(0x33c, lbl_80666EC0);
    PUT(0x2e8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_80360080(U* self, int chrg)
{
    PUT(0xabc, lbl_80666EC0);
    PUT(0xa68, lbl_80666EC0);
    PUT(0xa14, lbl_80666EC0);
    PUT(0x9b0, lbl_80666EC0);
    PUT(0x95c, lbl_80666EC0);
    PUT(0x8f8, lbl_80666EC0);
    PUT(0x8a4, lbl_80666EC0);
    PUT(0x840, lbl_80666EC0);
    PUT(0x7ec, lbl_80666EC0);
    PUT(0x788, lbl_80666EC0);
    PUT(0x734, lbl_80666EC0);
    PUT(0x6e8, lbl_80666EC0);
    PUT(0x680, lbl_80666EC0);
    PUT(0x604, lbl_80666EC0);
    PUT(0x5b0, lbl_80666EC0);
    PUT(0x548, lbl_80666EC0);
    PUT(0x4f4, lbl_80666EC0);
    PUT(0x4a0, lbl_80666EC0);
    PUT(0x44c, lbl_80666EC0);
    PUT(0x3f8, lbl_80666EC0);
    PUT(0x390, lbl_80666EC0);
    PUT(0x33c, lbl_80666EC0);
    PUT(0x2e8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_80360108(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360128(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360148(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}
