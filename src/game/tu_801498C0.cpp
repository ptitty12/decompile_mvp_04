/*
 * Game code, .text 0x801498C0-0x8014BEA4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80144CF0.h"

#include "game/tu_8001FDA8.h"
struct Unk8014A310_Obj { int m0; char pad4[4]; int m8; int mC; int m10; int m14; int m18; int m1C; int m20; int m24; };
void* operator new(unsigned int size, int heap);
struct Unk8014A390_Obj { char pad0[0xC]; int mC; char pad10[0xC]; int m1C; };
struct Unk8014A3E8_Obj { char pad0[8]; int m8; int mC; int m10; int m14; int m18; };
struct Unk8014A6D8_Obj { int m0; char pad4[4]; int m8; int mC; };
struct Unk8014A740_Obj { char pad0[8]; int m8; int mC; };
void* operator new[](unsigned int size, int heap);
extern int lbl_806EF9B4;
void fn_8001BC10();
void fn_800AA108();

extern "C" {
void fn_80149F6C();
void fn_8014A0EC();
char* fn_8014A140();
/* near-miss: only the order of the three argument loads of the second fn_803FEBDC call differs */
void fn_8014A1BC(void* self, int a, const char* b);
void fn_8014A290(void* self, int a, int b);
int fn_8014A2B8(void* self, int a, int b, const char* c);
void* fn_8014A310(void* self);
void* fn_8014A344();
float fn_8014A390(Unk8014A390_Obj* p);
int fn_8014A3E8(Unk8014A3E8_Obj* p, int a, int b, int c);
void* fn_8014A6D8(void* self);
void* fn_8014A6F4();
int fn_8014A740(Unk8014A740_Obj* p, int a, int b);
void* fn_8014AA18();
void fn_8014AA64(int a);
void fn_8014AF14();
void fn_8014AF4C();
void fn_8014AFA8();
void fn_8014AFE0();
void fn_8014B018();
void fn_8014B044();
void fn_8014B070();
void fn_8014B09C();
void fn_8014B0C8();
void fn_8014B0F4();
void fn_8014B120();
void fn_8014B14C();
void fn_8014B178();
void fn_8014B1A4();
void fn_8014B1D0();
void fn_8014B1FC();
void fn_8014B228();
void fn_8014B254();
void fn_8014B280();
void fn_8014B2AC();
void fn_8014B2D8();
void fn_8014B304();
void fn_8014B330();
void fn_8014B35C();
void fn_8014B388();
void fn_8014B3B4();
void fn_8014B3E0();
void fn_8014B40C();
void fn_8014B438();
void fn_8014B464();
void fn_8014B490();
void fn_8014B4BC();
void fn_8014B4E8();
/* near-miss (aligned diff 3): retail stores lbl_8061E978 through 'mr r0,r3'; the address-caching
   pointer locals below reproduce the callee-saved lis registers, which plain globals do not */
void fn_8014BB70();
void fn_8014BE28();
extern int lbl_8061B938;
extern int lbl_8061B93C;
extern int lbl_8061B940;
extern int lbl_8061B944;
extern int lbl_8061B8BC;
extern char lbl_8061B948[];
extern const char lbl_805C4FEC[];
extern char lbl_805C5008[];
int fn_804089B4(char*, const char*, ...);
extern const char lbl_805C5020;
extern const char lbl_805C5024[];
void fn_8040B320(char*, int, int, ...);
int fn_803FEBDC(char*, int, int, int*);
void fn_803FEC9C(int, int);
int fn_803FEC74(int, int, const char*, int, int);
int fn_8040B6A0(const char*);
void fn_8018466C(int, int);
extern void* lbl_8061B978;
extern void* lbl_8061B97C;
extern void* lbl_8061B980;
void* fn_8014A928(void*);
extern int lbl_80620298;
void fn_8014AAA8();
void fn_8014AD2C(int);
extern const char lbl_806557A8[];
extern const void* lbl_80687CE4;
extern const void* lbl_80687E6C;
extern const char lbl_8065BDF8[];
void fn_8033CD28(void*, int);
extern const char lbl_8065F878[];
extern const void* lbl_80687F44;
extern const char lbl_8065F8D8[];
extern const void* lbl_80687F58;
extern char lbl_80687F90[];
void fn_8018102C(void*, int);
extern Unk8001FE34 lbl_80688020;
extern char lbl_806881F8[];
void fn_801421D4(void*, int);
extern char lbl_806882F8[];
void fn_8017F384(void*, int);
extern char lbl_8068836C[];
void fn_8035F6C0(void*, int);
extern char lbl_80688390[];
void fn_80358484(void*, int);
extern char lbl_80688398[];
void fn_8035F6E0(void*, int);
extern char lbl_806883F8[];
void fn_8035F700(void*, int);
extern char lbl_80689558[];
void fn_80151910(void*, int);
extern Unk8002118C lbl_806896BC;
extern char lbl_8068977C[];
void fn_80311BEC(void*, int);
extern char lbl_80689968[];
void fn_8003A9E4(void*, int);
extern char lbl_80689B68[];
void fn_8035F61C(void*, int);
extern char lbl_80689BD0[];
void fn_8035B16C(void*, int);
extern char lbl_80689DB4[];
void fn_8035A5A4(void*, int);
extern char lbl_80689DD4[];
void fn_8035D9F8(void*, int);
extern char lbl_80689E50[];
void fn_8035A344(void*, int);
extern char lbl_80689F08[];
void fn_8035A324(void*, int);
extern char lbl_80689F94[];
void fn_8035A304(void*, int);
extern char lbl_80689FA8[];
void fn_801E5EBC(void*, int);
extern char lbl_80689FF8[];
void fn_801E6330(void*, int);
extern char lbl_8068A060[];
void fn_801E6870(void*, int);
extern char lbl_8068A0BC[];
void fn_8035F67C(void*, int);
extern char lbl_8068A0C4[];
void fn_8035F63C(void*, int);
extern char lbl_8068A0CC[];
void fn_8035F65C(void*, int);
extern char lbl_8068A0D4[];
void fn_80359604(void*, int);
extern char lbl_8068A0F4[];
void fn_8030BFB0(void*, int);
extern char lbl_8068A1A0[];
void fn_8030C728(void*, int);
extern char lbl_8068A380[];
void fn_80311D08(void*, int);
extern int lbl_8061930C;
extern void* lbl_8068B618;
extern void* lbl_8061E978;
extern void* lbl_8068DA4C;
extern void* lbl_8062013C;
extern void* lbl_80620140;
extern int lbl_8061FEDC;
void fn_802DC9C0();
void fn_80071F00();
void fn_800906B8();
void fn_8007295C(int);
void fn_800766B8(int, int);
void fn_80070E38();
void fn_800A152C();
void* fn_80148280(void*);
void* fn_802AD720(void*);
void fn_802B85D8();
void fn_80313BCC(int);
void* fn_802BB4FC(void*);
void fn_800B8108();
void fn_805210A0();
void* fn_8031C62C(void*);
void* fn_8031CD88(void*);
void fn_80322450();
extern void* lbl_806EF9C0;
extern const char lbl_805C5260[];
int fn_803ED9D4();
void fn_803ED720(int, const char*, void*, int, int, int, int, int, int, int);

void fn_80149F6C() {}

void fn_8014A0EC()
{
    if (lbl_8061B938 + lbl_8061B93C + lbl_8061B940 + lbl_8061B944 > 0xFA0) {
        lbl_8061B8BC = 1;
        return;
    }
    lbl_8061B8BC = 0;
}

char* fn_8014A140()
{
    fn_804089B4(lbl_8061B948, lbl_805C4FEC, lbl_8061B938 + lbl_8061B93C + lbl_8061B940 + lbl_8061B944);
    if (lbl_8061B948) {
        return lbl_8061B948;
    }
    return lbl_805C5008;
}

/* near-miss: only the order of the three argument loads of the second fn_803FEBDC call differs */
void fn_8014A1BC(void* self, int a, const char* b)
{
    char buf[0x80];
    int h = 0;
    buf[0] = lbl_805C5020;
    fn_8040B320(buf + 1, 0, 0x7F);
    fn_804089B4(buf, lbl_805C5024, a);
    fn_803FEBDC(buf, 6, 0x64, &h);
    fn_803FEC9C(h, 0x64);
    fn_803FEBDC(buf, 0, 0x64, &h);
    fn_803FEC74(h, 0, b, fn_8040B6A0(b), 0x64);
    fn_803FEC9C(h, 0x64);
}

void fn_8014A290(void* self, int a, int b)
{
    fn_8018466C(a, b);
}

int fn_8014A2B8(void* self, int a, int b, const char* c)
{
    if (b < 0) {
        return -1;
    }
    return fn_803FEC74(a, b, c, fn_8040B6A0(c), 0x64);
}

void* fn_8014A310(void* self)
{
    Unk8014A310_Obj* p = (Unk8014A310_Obj*)self;
    p->m0 = -1;
    p->m8 = 0;
    p->mC = 0;
    p->m1C = 0;
    p->m20 = 0;
    p->m24 = 0;
    p->m10 = 0;
    p->m14 = 0;
    p->m18 = 0;
    return p;
}

void* fn_8014A344() { if (!lbl_8061B978) lbl_8061B978 = fn_8014A310(operator new(0x28, 0)); return lbl_8061B978; }

float fn_8014A390(Unk8014A390_Obj* p)
{
    return (float)p->m1C / (float)p->mC;
}

int fn_8014A3E8(Unk8014A3E8_Obj* p, int a, int b, int c)
{
    if (p->m10 != 0 && a % p->m10 <= 2 && b != 0) {
        int t = p->mC;
        if (t != 0 && a > p->m14 - 2 && p->m8 < t) {
            if (p->m18 != 0) {
                if (c != 0) {
                    return 1;
                }
                return 0;
            }
            return 1;
        }
    }
    return 0;
}

void* fn_8014A6D8(void* self)
{
    Unk8014A6D8_Obj* p = (Unk8014A6D8_Obj*)self;
    p->m0 = -1;
    p->m8 = 0;
    p->mC = 0;
    return p;
}

void* fn_8014A6F4() { if (!lbl_8061B97C) lbl_8061B97C = fn_8014A6D8(operator new(0x10, 0)); return lbl_8061B97C; }

int fn_8014A740(Unk8014A740_Obj* p, int a, int b)
{
    int t = p->m8;
    if (t != 0 && b != 0 && p->mC == 0 && t - a <= 0) {
        p->mC = 1;
        return 1;
    }
    return 0;
}

void* fn_8014AA18() { if (!lbl_8061B980) lbl_8061B980 = fn_8014A928(operator new(0x6C, 0)); return lbl_8061B980; }

void fn_8014AA64(int a)
{
    fn_8014AAA8();
    if (lbl_80620298 == 0) {
        fn_8014AD2C(a);
    }
}

void fn_8014AF14() { lbl_80687CE4 = lbl_806557A8; ((Unk8037B3E8*)&lbl_80687CE4)->Unk8037B3E8::~Unk8037B3E8(); }

void fn_8014AF4C()
{
    lbl_80687E6C = lbl_8065BDF8;
    fn_8033CD28((char*)&lbl_80687E6C + 0xBC, 2);
    fn_8033CD28((char*)&lbl_80687E6C + 0xB0, 2);
    ((Unk8037B3E8*)&lbl_80687E6C)->Unk8037B3E8::~Unk8037B3E8();
}

void fn_8014AFA8() { lbl_80687F44 = lbl_8065F878; ((Unk8037B3E8*)&lbl_80687F44)->Unk8037B3E8::~Unk8037B3E8(); }

void fn_8014AFE0() { lbl_80687F58 = lbl_8065F8D8; ((Unk8037B3E8*)&lbl_80687F58)->Unk8037B3E8::~Unk8037B3E8(); }

void fn_8014B018() { fn_8018102C(lbl_80687F90, 0x2); }

void fn_8014B044()
{
    lbl_80688020.Unk8001FE34::~Unk8001FE34();
}

void fn_8014B070() { fn_801421D4(lbl_806881F8, 0x2); }

void fn_8014B09C() { fn_8017F384(lbl_806882F8, 0x2); }

void fn_8014B0C8() { fn_8035F6C0(lbl_8068836C, 0x2); }

void fn_8014B0F4() { fn_80358484(lbl_80688390, 0x2); }

void fn_8014B120() { fn_8035F6E0(lbl_80688398, 0x2); }

void fn_8014B14C() { fn_8035F700(lbl_806883F8, 0x2); }

void fn_8014B178() { fn_80151910(lbl_80689558, 0x2); }

void fn_8014B1A4()
{
    lbl_806896BC.Unk8002118C::~Unk8002118C();
}

void fn_8014B1D0() { fn_80311BEC(lbl_8068977C, 0x2); }

void fn_8014B1FC() { fn_8003A9E4(lbl_80689968, 0x2); }

void fn_8014B228() { fn_8035F61C(lbl_80689B68, 0x2); }

void fn_8014B254() { fn_8035B16C(lbl_80689BD0, 0x2); }

void fn_8014B280() { fn_8035A5A4(lbl_80689DB4, 0x2); }

void fn_8014B2AC() { fn_8035D9F8(lbl_80689DD4, 0x2); }

void fn_8014B2D8() { fn_8035A344(lbl_80689E50, 0x2); }

void fn_8014B304() { fn_8035A324(lbl_80689F08, 0x2); }

void fn_8014B330() { fn_8035A304(lbl_80689F94, 0x2); }

void fn_8014B35C() { fn_801E5EBC(lbl_80689FA8, 0x2); }

void fn_8014B388() { fn_801E6330(lbl_80689FF8, 0x2); }

void fn_8014B3B4() { fn_801E6870(lbl_8068A060, 0x2); }

void fn_8014B3E0() { fn_8035F67C(lbl_8068A0BC, 0x2); }

void fn_8014B40C() { fn_8035F63C(lbl_8068A0C4, 0x2); }

void fn_8014B438() { fn_8035F65C(lbl_8068A0CC, 0x2); }

void fn_8014B464() { fn_80359604(lbl_8068A0D4, 0x2); }

void fn_8014B490() { fn_8030BFB0(lbl_8068A0F4, 0x2); }

void fn_8014B4BC() { fn_8030C728(lbl_8068A1A0, 0x2); }

void fn_8014B4E8() { fn_80311D08(lbl_8068A380, 0x2); }

/* near-miss (aligned diff 3): retail stores lbl_8061E978 through 'mr r0,r3'; the address-caching
   pointer locals below reproduce the callee-saved lis registers, which plain globals do not */
void fn_8014BB70()
{
    void** a = &lbl_8068B618;
    void** b = &lbl_8061E978;
    void** c = &lbl_8068DA4C;
    void** d = &lbl_8062013C;
    void** e = &lbl_80620140;
    fn_802DC9C0();
    fn_80071F00();
    fn_800906B8();
    fn_8007295C(lbl_8061930C);
    fn_800766B8(lbl_8061930C, 0);
    fn_80070E38();
    fn_800A152C();
    *a = fn_80148280(operator new(0x38, 0));
    *b = fn_802AD720(operator new(0x18720, 0));
    fn_802B85D8();
    fn_80313BCC(lbl_8061FEDC);
    *c = fn_802BB4FC(operator new(8, 0));
    fn_800B8108();
    fn_8001BC10();
    fn_800AA108();
    fn_805210A0();
    *d = fn_8031C62C(operator new(0x90, 0));
    *e = fn_8031CD88(operator new(0x28, 0));
    fn_80322450();
}

void fn_8014BE28()
{
    lbl_806EF9C0 = operator new[](0x181BE0, 0);
    int h = fn_803ED9D4();
    lbl_806EF9B4 = h;
    fn_803ED720(h, lbl_805C5260, lbl_806EF9C0, 0x181BE0, 4, 4, 0, 0, 0, 0);
}

}
