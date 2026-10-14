/*
 * Game code, .text 0x8014BEA4-0x8014F47C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80144CF0.h"

struct UnkB8_Obj { char pad0[0xB8]; int mB8; };
void* operator new(unsigned int size, int heap);
struct Unk8014D860_Obj { int m0; int m4; int m8; int mC; int m10; int m14; int m18; };
struct Unk8014D9C4_Obj { float m0; float m4; float m8; float mC; };
struct Unk2C { char b[0x2C]; };
struct Unk8014E09C_Obj { int m0; int m4; int m8; const char* mC; const char* m10; Unk2C* m14; };
struct Unk8014E108_Obj { char pad0[8]; int m8; };
struct V3i { int a; int b; int c; };
struct UnkAt2014 { char pad0[0x2014]; int m2014; };
struct UnkAt2ACS { char pad0[0x2AC]; char m2AC[0x10]; };
struct UnkAt2BCS { char pad0[0x2BC]; char m2BC[0x10]; };
struct UnkAt2CCS { char pad0[0x2CC]; char m2CC[0x10]; };

void fn_8000C674(short x, short y, const char* fmt, ...);

#include "game/tu_8006902C.h"
void fn_802D7538();
struct Unk8014D5C0_Obj { char pad0[0x6F8]; Unk80069F0C* m6F8; };
struct Unk8014D5C0_Own { char pad0[8]; Unk8014D5C0_Obj* m8[3]; char pad14[0x24 - 0x14]; int m24; };
inline Unk8014D5C0_Obj* Get8014D5C0(Unk8014D5C0_Own* p, unsigned i) { return i <= 2 ? p->m8[i] : 0; }
void fn_80071F00();
/* Polymorphic 8-byte object built by fn_80353218 (m0 = 0, vptr lbl_8064B718 at +4); same class as in tu_800A23F4.cpp. */
struct Unk80353218 {
    int m0;
    Unk80353218(); /* fn_80353218 */
    virtual void vf0();
};
#include "game/tu_8000E618.h"
/* 8-byte object built by __11Unk803567AC (m0 = 0, vptr-like pointer at +4). */
struct Unk803567AC {
    int m0;
    Unk803567AC();
    virtual void vf0();
};
unsigned fn_800734D4(void* self, unsigned flags);
Unk8000E618* fn_8000E65C();
void fn_80071F48();
struct Vec3f8014E40C { float x; float y; float z; };
struct Unk8014E40C_Obj { char pad0[0x60]; Vec3f8014E40C m60; };
extern "C" void fn_8014E388(V3i* p, unsigned i);
inline Vec3f8014E40C DiffAt8014E40C(Unk8014E40C_Obj* self, unsigned i)
{
    Vec3f8014E40C t;
    fn_8014E388((V3i*)&t, i);
    const Vec3f8014E40C& b = self->m60;
    Vec3f8014E40C r;
    r.x = t.x - b.x;
    r.y = t.y - b.y;
    r.z = t.z - b.z;
    return r;
}
inline Vec3f8014E40C DiffAtP8014E498(Vec3f8014E40C* pb, unsigned i)
{
    Vec3f8014E40C t;
    fn_8014E388((V3i*)&t, i);
    const Vec3f8014E40C& b = *pb;
    Vec3f8014E40C r;
    r.x = b.x - t.x;
    r.y = b.y - t.y;
    r.z = b.z - t.z;
    return r;
}
struct Vec4f8014DAFC { float x; float y; float z; float w; };
inline Vec4f8014DAFC Div8014DAFC(const Vec4f8014DAFC& a, float s)
{
    Vec4f8014DAFC r;
    float inv = 1.0f / s;
    r.x = a.x * inv;
    r.y = a.y * inv;
    r.z = a.z * inv;
    r.w = a.w * inv;
    return r;
}
inline Vec4f8014DAFC Copy8014DF5C(const Vec4f8014DAFC* p) { return *p; }

struct PackBits8014E01C { unsigned a : 8; unsigned b : 8; unsigned c : 8; unsigned d : 8; };
union Pack8014E01C { PackBits8014E01C p; unsigned u; };
struct Ctx8014ECA8 {
    int r[32];
    int cr;
    int lr;
    char pad88[0x198 - 0x88];
    int srr0;
    int srr1;
};
struct Frame8014EF0C { Frame8014EF0C* next; int lr; };
struct Unk8014E15C_Y { char pad0[0x14]; void* m14; };
struct Unk8014E15C_Ctx { char pad0[0x6F4]; int m6F4; Unk8014E15C_Y* m6F8; };
struct Unk8014E15C_Obj { Unk8014E15C_Ctx* m0; int m4; int m8; int* mC; int* m10; int* m14; };
extern "C" int fn_80081B60__FP13Unk8007FF8C_Y(void* y);
struct Unk80634ADC;
struct Self8014E9E0 {
    char pad0[0x280];
    void* m280;
    char m284;
    char pad285[0x2AC - 0x285];
    char m2AC[0x10];
    char m2BC[0x10];
    char m2CC[0x10];
};
int fn_803D817C();
void fn_803D81FC();
void fn_8000C4A8(unsigned char* fb, Unk80634ADC* rmode);
class V0_8014D6A4 { public: virtual ~V0_8014D6A4(); };
extern int lbl_8061B9B8;
extern VT18* lbl_80620140;
extern VT18* lbl_8062013C;
extern int lbl_8061F688;
extern V0_8014D6A4* lbl_8061B984;
extern VT18* lbl_8068F1F4;
extern VT18* lbl_8068F1FC;
class V2DC_8014D488 { public: char pad0[0x2DC]; virtual ~V2DC_8014D488(); };
struct P74_8014D1EC { char pad0[0x74]; int m74; };
struct PObj_8014D1EC { char pad0[0x10]; P74_8014D1EC* m10; };
struct Unk806192E0_8014D488 { int m0; PObj_8014D1EC* m4; int m8; };
extern int lbl_8061FEDC;
extern int lbl_8061FE20;
extern int lbl_8061C688;
extern V2DC_8014D488* lbl_8061B99C;
extern V2DC_8014D488* lbl_8061B9A0;
extern VT18* lbl_8061B998;
extern void* lbl_8061E978;
extern Unk806192E0_8014D488* lbl_806192E0;

struct Unk80615854;
extern Unk80615854 lbl_80615854;
extern Unk80615854 lbl_8061589C;
extern const char* lbl_8061BD30[];
extern const char lbl_8061BD1C[];
struct OSCtx8014F05C { char b[0x2C8]; };
void fn_8000C50C(int v);
void fn_8000C540(const Unk80615854* c);
void fn_8000C574(const Unk80615854* c);
void fn_8000C5A8();
struct X1DC_8014D1EC { char pad0[0x1DC]; int m1DC; };
class V18c_8014D1EC {
public:
    char pad0[0x18];
    virtual ~V18c_8014D1EC();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual int s8();
    virtual int s9();
    virtual int s10();
    virtual int s11();
    virtual int s12();
    virtual int s13();
    virtual int s14();
    virtual int s15();
    virtual int s16();
    virtual int s17();
    virtual void s18(int a);
    virtual int s19();
};
struct B8C0_8014D1EC { char pad0[8]; void* m8; };
class Unk8001BC8C { public: void fn_8001C05C(int idx, float value, int flag); };
Unk8001BC8C* fn_8001BC4C();
void fn_8014D6A4();
struct FxBase8014C5A4 { char pad0[0x18]; const void* m18; };
class V4_8014C5A4 { public: int m0; virtual void v1(); virtual void v2(); };
extern V4_8014C5A4* lbl_8061FF64;
extern const char lbl_805C5678[];
extern const char lbl_805C5694[];
extern const char lbl_805C56A0[];
extern const char lbl_80665558[];
extern const char lbl_8065D5A0[];
extern void* lbl_80624278;
extern Unk8014D5C0_Own* lbl_80624270;
extern const char* lbl_80620150;
extern int lbl_8061977C;
extern "C" {
void fn_80400690(void (*cb)());
int fn_8033E958(const char* fmt, ...);
FxBase8014C5A4* fn_80328234(FxBase8014C5A4* self, int a, int b);
FxBase8014C5A4* fn_803282A8(FxBase8014C5A4* self, int a);
void fn_8030408C(void* p);
int fn_8037C924(void* self);
void fn_8014BB70();
unsigned char* fn_8007FE04__FP13Unk8007F198_D(void*);
void fn_8031CE68();
void fn_802ACFB0(void* m);
void* fn_802BB580();
void fn_802BB894(void* o);
void* fn_80314790(void* p);
void fn_8031E1D4(void* self, const char* a);
void* fn_80329988();
void fn_80329AA8(void* p);
void fn_800C33D0();
void fn_800C5E28();
void fn_800B555C();
void fn_800907A4(int p, int idx, int flag);
void fn_802B8C84();
}
struct Unk802D58E8;
extern int lbl_8061B9A4;
extern int lbl_80620424;
extern int lbl_80620428;
extern int lbl_8061D45C;
extern B8C0_8014D1EC* lbl_8061B8C0;
extern const char lbl_80666A18[];
extern const char lbl_8065D550[];
void fn_802D7A74();
void fn_802D5BF4(Unk802D58E8* o, int a, const char* s);
extern "C" {
void fn_8006A1F4__11Unk80069F0C(void* self);
void fn_80316614(void* o, int a, float f);
int fn_801498C0(void* a, void* b);
void fn_801810C8();
void fn_8014CBE8(void* a, int b);
Unk802D58E8* fn_801A4CE8(void* a, int b);
void fn_802D7ACC();
void fn_803E4A50(void* p);
void fn_80357B58(void* p);
void* fn_80335604(void* self, void* o, int a);
void fn_8032D36C();
void fn_803164A0__Fv(void* x);
}
extern "C" {
void VISetBlack(int b);
void VIFlush();
void fn_80433814(OSCtx8014F05C* c);
void fn_8043364C(OSCtx8014F05C* c);
void fn_80434F9C();
void* fn_80433CE8(const char* file, int line, const char* msg, ...);
void fn_8014F954(char* self);
void VISetBlack(int b);
void VIFlush();
void fn_80433814(OSCtx8014F05C* c);
void fn_8043364C(OSCtx8014F05C* c);
void fn_80434F9C();

void fn_8014F954(char* self);
int fn_8031C6A8();
void fn_8031C6B4();
void fn_80149DD4(void* a, void* b);
void fn_80312018(int a);
void fn_802B832C__FP15Unk802ACD88_Mgr(void* mgr);
void* fn_802BB19C__Fv();
void fn_802BB1E4__FP15Unk802BB1E4_Obji(void* o, int i);
}
extern "C" {
void fn_80329A50();
void fn_8031D0F0();
void fn_8014BC64();
void fn_8037C764();
void fn_8037B8EC();
void fn_802E3980__15Unk802E3980_Mgr(int self);
void fn_8024F6CC__Fv();
void* fn_8037C7FC__Fv();
void fn_8001C394__Fv();
void fn_8001C410__11Unk8001C314();
void fn_802B8BBC__Fv();
}
extern "C" {
void fn_8014F3A8(const char* str);
void fn_8014F47C(void* p);
void fn_803D9E00(int a, unsigned char** b, Unk80634ADC** c);
void* fn_80433E14(unsigned short sig, void* handler);
int sprintf(char* buf, const char* fmt, ...);
void fn_8014F4B4(int a, char* s);
void fn_8014F738(int a);
void OSReport(const char* msg, ...);
void DVDReadAsyncPrio(void* blk, void* buf, int len, int off, void* cb, int prio);
int fn_80425064(void* blk);
void OSYieldThread();
void* fn_803774A8(unsigned n, int heap);
int fn_80072E90(void* g, void* a, int b, int c, int d, void* out);
void fn_800A59F0(void* p);
void fn_80377488(void* p);
extern void* lbl_8061B9B4;
extern int lbl_8061B9B0;
extern void* lbl_80619948;
int fn_80148404(void*);
void fn_80148438(void*);
int fn_8014E6E0(void* self, char* buf, int n);
void fn_8040B320(char*, int, int, ...);
int fn_8040B574(const char* a, const char* b);
void DVDClose(void* p);
int DVDOpen(const char* a, void* p);
int fn_803FEC74(int buf, int pos, const char* s, int len, int n);
unsigned int strlen(const char* s);
void fn_8014BEA4();
void fn_8014C3BC();
void fn_8014C4E8();
void fn_8014C540();
void fn_8014BEB8(int argc, char** argv);
void fn_8014C5A4(int a, char** b);
void fn_8014D63C(int a, char** b);
void fn_8014D81C(int* p);
void fn_8014D860(Unk8014D860_Obj* p, int a);
Unk8014D9C4_Obj* fn_8014D9C4(Unk8014D9C4_Obj* p);
void fn_8014DD30(Vec4f8014DAFC* v);
int fn_8014DD68(int a0, int a1, unsigned a2, unsigned a3);
Unk8014E09C_Obj* fn_8014E09C(Unk8014E09C_Obj* p, int a, int b);
void* fn_8014E108(Unk8014E108_Obj* p);
int fn_8014E2B4(int a);
int fn_8014E310(int a);
int fn_8014E374(int a);
/* near-miss: struct-copy form schedules like retail, but the two arms are joined by a cross-jump
   (retail keeps two separate copy+blr tails); field-wise copies schedule differently */
void fn_8014E388(V3i* p, unsigned i);
int fn_8014E3E0(int a);
void fn_8014E57C(UnkAt2014* p);
void* fn_8014E88C(void* p);
void fn_8014E8DC(void* p);
void* fn_8014EB44();
void fn_8014EBEC(UnkAt2ACS* p, const char* s);
void fn_8014EC24(UnkAt2BCS* p, const char* s);
void fn_8014EC5C(UnkAt2CCS* p, const char* s);
int fn_8014EC94(int a, unsigned b, unsigned c);
void* fn_8014F008(int a, int b, int c, int d);
void fn_8014F34C(int a);
void fn_8014F42C();
struct Unk8068B3CC_E { int a; int b; int c; };
struct Unk8068B3CC { const void* vptr; Unk8068B3CC_E e[1]; int m10; };
extern Unk8068B3CC lbl_8068B3CC;
extern const char lbl_8065D448[];
void fn_80378744();
extern UnkB8_Obj* lbl_8061A32C;
UnkB8_Obj* fn_800B64BC(void*);
void fn_8014C468();
extern void* lbl_8061930C;
void fn_80072B98(void*);
void fn_8014C3DC();
extern Unk8014D5C0_Own* lbl_8068B618;
void __main();
void fn_8014C8BC();
int fn_80148930(void*);
int fn_8014D1EC();
void fn_8014D5C0();
void fn_8014D488();
extern const char lbl_805C5F90[];
void fn_803FFA60(void*, const char*, int);
extern const float lbl_805C58AC;
extern const float lbl_805C58B0;
unsigned fn_8014DDAC(Vec4f8014DAFC* v);
extern Unk2C lbl_8061BAD4[];
extern char lbl_8061B9CC[];
extern char lbl_8061BA7C[];
void fn_8014E15C(Unk8014E15C_Obj*);
void fn_803579D4(void*);
extern V3i lbl_805C5F54[];
extern V3i lbl_805C5F78;
extern const char lbl_805C5A90[];
extern const char lbl_805C5A98[];
void fn_8014E588(void*, const char*);
void fn_8014E7EC(void*, const char*);
extern void* lbl_8061BD74;
void* fn_8014E9E0(void*);
void fn_8040B830(char*, const char*, int);
void* fn_8014F05C(void*, int, int, int, int);
extern int lbl_8068B704;
extern int lbl_8068B700;
extern int lbl_8068B6FC;
int fn_803FEBDC(int, int, int, int*);
int fn_803FEC9C(int, int);

struct Self8014E588 {
    char pad0[0x2000];
    int m2000;
    int m2004;
    int m2008;
    int m200C;
    int m2010;
    int m2014;
    char m2018[0x34];
    int m204C;
};
struct Self8014EB90 {
    char pad0[0x2AB];
    char m2AB;
};
extern int lbl_8061B9BC;

extern const char lbl_805C5020;
extern const char lbl_805C5A64[];
extern const char lbl_805C5ABC[];

class Unk802D73B4_W { public: int m0; Unk802D73B4_W(); };
class FxReg { public: int m0; int m4; FxReg(); };
extern int lbl_8061B88C;
extern unsigned lbl_8062F204;
extern void (*lbl_80624248)();
extern Unk8068B3CC* lbl_80624230;
extern int lbl_8068B3E0;
extern char lbl_8068B3E4[];
extern int lbl_8068B3E8;
extern char lbl_8068B3EC[];
extern int lbl_8068B3F0;
extern void* lbl_8062426C;
extern void* lbl_80624274;
extern int lbl_8061B9A8;
extern int lbl_80624284;
extern int lbl_80624280;
extern int lbl_8062428C;
extern int lbl_80624298;
extern int lbl_8062429C;
extern int lbl_80624290;
extern int lbl_80624294;
extern int lbl_8062427C;
extern int lbl_80624234;
extern int lbl_80624238;
extern int lbl_8062423C;
extern int lbl_80624240;
extern int lbl_80624244;
extern int lbl_8062422C;
extern void* lbl_80621580;
extern int lbl_8061B988;
extern int lbl_8061B9AC;
extern int lbl_80620334;
extern int lbl_80620338;
extern int lbl_8062033C;
extern int lbl_80620340;
extern int lbl_8061CBD0;
extern int lbl_8061BE30;
extern int lbl_80621548;
extern void* lbl_8068F1F8;
extern const char lbl_805C5270[];
extern const char lbl_805C5284[];
extern const char lbl_805C544C[];
extern const char lbl_805C5464[];
extern const char lbl_805C5474[];
extern const char lbl_805C5490[];
extern const char lbl_805C54AC[];
extern const char lbl_805C5508[];
extern const char lbl_805C551C[];
extern const char lbl_805C55F4[];
extern const char lbl_805C55FC[];
extern const char lbl_805C5654[];
struct Unk8014BEB8_FsOpts { int size; void* alloc; void* free; char* heap; int heapSize; };
class Unk8001C314_T { public: void fn_8001C50C(); void fn_8001C568(); };
Unk8001C314_T* fn_8001C394();
void fn_8033E7A4();
void fn_8043188C();
void fn_80422FD8();
void VIInit();
int PADInit();
void fn_8000D650();
extern "C" int atexit(void (*fn)(void));
void* fn_803579C0(void* self);
void* fn_80357A70(void* self);
void* fn_80357AEC(void* self);
void fn_80377048();
void fn_803FFE14();
void fn_803FF888(int hz);
int fn_80316B90();
int fn_803FACFC(void* p);
int fn_803FAD60(void* p);
int fn_803F9494(int a, int b, int c);
void* fn_802BB19C__Fv();
void fn_8014BE28();
int fn_803EE3D4(int i);
void* fn_803ED604(const char* name, int sz, int k);
void fn_803EDA0C(void* b);
extern char lbl_8068A3CC[];
void* fn_80312468(void* p);
void fn_8031392C(int p);
void fn_800057F0();
int strcmp(const char* a, const char* b);
int fn_802D7A84(int* a);
void fn_802D75D4(int a);
void fn_80400DE4(int d);
void fn_80400E18();
void fn_802D7AC4(int a, int b);
void fn_8000D6D4();
void fn_80316310(char* self);
int DVDChangeDir(const char* path);
struct Unk8014BEB8_Scr { char pad0[0x1DC]; int m1DC; };
void fn_803167F0(void* p, float a, float b, float c, float d);
void fn_800308FC();
void fn_8014B514();
void fn_802D3804();
void fn_802A70F8();
void fn_802AA210();
void fn_800AA5F8();
void fn_80169E38();
extern const char lbl_805C5664[];

void fn_8014BEA4()
{
    lbl_8068B3CC.vptr = lbl_8065D448;
}

/* near-miss (95.9%, 321/321 insns): only the order of the config/constant store groups (lbl_8062427C..80624298,
   lbl_80624234..80624244) and their callee-saved lis registers differ; hill-climbed and permuted store orders
   (group sizes 8 and 5, full permutations of the second) tried; the unused-looking local 'z' holds the zero that
   fn_802D7A84 receives by pointer.
   System start-up (called first from fn_8014C5A4): initialises the OS, DVD, VI and pad libraries, the
   memory pools and the frame timer ("UPDATEhz = %d" with 60), builds the global singletons and finishes with
   "Init complete!". argc/argv are scanned for "-inifile". */
void fn_8014BEB8(int argc, char** argv)
{
    int savedFlag = lbl_8061B88C;
    lbl_8061B88C = 0;
    lbl_8062F204 = 0x80000000;
    fn_8043188C();
    fn_80422FD8();
    VIInit();
    PADInit();
    fn_8033E958(lbl_805C5270);
    fn_8000D650();
    fn_8033E958(lbl_805C5284);
    lbl_80624248 = fn_8033E7A4;
    fn_8000E65C();
    if (lbl_8068B3E0 == 0) {
        Unk8068B3CC* o = &lbl_8068B3CC;
        fn_803579C0(o);
        lbl_8068B3CC.vptr = lbl_8065D448;
        int i = 0;
        Unk8068B3CC_E* e = o->e;
        do {
            e->a = -1;
            e->b = 0;
            e->c = 0;
            e++;
        } while (i-- != 0);
        o->m10 = 0;
        lbl_8068B3E0 = 1;
        atexit(fn_8014BEA4);
    }
    lbl_80624230 = &lbl_8068B3CC;
    fn_80377048();
    if (lbl_8068B3E8 == 0) {
        fn_80357A70(lbl_8068B3E4);
        lbl_8068B3E8 = 1;
    }
    lbl_8062426C = lbl_8068B3E4;
    if (lbl_8068B3F0 == 0) {
        fn_80357AEC(lbl_8068B3EC);
        lbl_8068B3F0 = 1;
    }
    lbl_8062427C = 0;
    lbl_80624298 = 0x44C;
    lbl_80624280 = 0;
    lbl_80624284 = lbl_8061B9A8;
    lbl_8062428C = 0x55F0;
    lbl_8062429C = 0x1F4;
    lbl_80624290 = 0x1F4;
    lbl_80624274 = lbl_8068B3EC;
    lbl_80624294 = 0x1F4;
    fn_803FFE14();
    fn_8033E958(lbl_805C544C);
    fn_803FF888(0x3C);
    fn_8033E958(lbl_805C5464, 0x3C);
    fn_80316B90();
    Unk8014BEB8_FsOpts opts;
    opts.size = 0x14;
    fn_803FACFC(&opts);
    opts.alloc = (void*)fn_803ED604;
    opts.free = (void*)fn_803EDA0C;
    opts.heap = lbl_8068A3CC;
    opts.heapSize = 0x1000;
    fn_803FAD60(&opts);
    fn_803F9494(0x20, 0x800, 0x30);
    fn_802BB19C__Fv();
    fn_8014BE28();
    lbl_8061B88C = savedFlag;
    fn_8033E958(lbl_805C5474);
    fn_8033E958(lbl_805C5490, fn_803EE3D4(0));
    lbl_80624238 = 0x32;
    lbl_8062423C = 0x3C;
    lbl_80624240 = 0x46;
    lbl_80624244 = 0x6E;
    lbl_80624234 = 0x5F;
    fn_80312468(operator new(0x20C, 0));
    fn_8031392C(lbl_8061FEDC);
    lbl_8062422C = lbl_8061FEDC;
    fn_800057F0();
    int idx = 0;
    char** a = argv;
    while (idx < argc && (*a == 0 || strcmp(*a, lbl_805C54AC) != 0)) {
        a++;
        idx++;
    }
    lbl_80621580 = operator new(1, 0);
    lbl_8061B988 = 0;
    fn_8033E958(lbl_805C5508);
    lbl_8061B984 = (V0_8014D6A4*)new (0) Unk802D73B4_W;
    int z = 0;
    fn_802D7A84(&z);
    fn_802D75D4(0);
    int j = 0;
    while (j < lbl_8061B9AC) {
        j++;
        fn_802D75D4(0);
        fn_80400DE4(1);
        fn_80400E18();
    }
    fn_802D7AC4(0, 0);
    fn_802D7AC4(1, 1);
    fn_8000D6D4();
    fn_80316310((char*)lbl_8061FEDC);
    fn_8033E958(lbl_805C551C);
    lbl_80621548 = 0;
    lbl_80620334 = 0;
    lbl_80620338 = 0;
    lbl_8062033C = 0;
    lbl_80620340 = 0;
    lbl_8061CBD0 = 0;
    lbl_8061BE30 = 1;
    fn_8001C394();
    DVDChangeDir(lbl_805C55F4);
    ((Unk8014BEB8_Scr*)lbl_8061FEDC)->m1DC = 2;
    fn_803167F0((void*)lbl_8061FEDC, 0.323f, 0.838f, 0.358f, 0.022f);
    fn_80316614((void*)lbl_8061FEDC, 2, 0.02f);
    fn_800308FC();
    fn_8014B514();
    fn_802D3804();
    fn_802A70F8();
    fn_802AA210();
    fn_800AA5F8();
    fn_80169E38();
    lbl_8068F1F8 = new (0) FxReg;
    fn_8033E958(lbl_805C55FC);
    fn_8001C394()->fn_8001C50C();
    fn_8033E958(lbl_805C5654);
    fn_8001C394()->fn_8001C568();
    fn_8014EB44();
}

void fn_8014C3BC() { fn_80378744(); }

void fn_8014C3DC()
{
    unsigned n = fn_800734D4(lbl_8061930C, 0x03531311);
    lbl_8061B9B0 = n;
    lbl_8061B9B4 = fn_803774A8(n, fn_8000E65C()->fn_8000E6F0() | 0x500);
    Unk803567AC sp8;
    fn_80072E90(lbl_8061930C, lbl_8061B9B4, lbl_8061B9B0, 0x03531311, 0, &sp8);
    fn_80071F48();
}

void fn_8014C468()
{
    fn_80071F00();
    Unk80353218 sp8;
    fn_80072E90(lbl_8061930C, lbl_8061B9B4, lbl_8061B9B0, 0x03531311, 0, &sp8);
    fn_800A59F0(lbl_80619948);
    if (lbl_8061B9B4 != 0) {
        fn_80377488(lbl_8061B9B4);
    }
    lbl_8061B9B4 = 0;
}

void fn_8014C4E8()
{
    if (!lbl_8061A32C) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    lbl_8061A32C->mB8 = 0;
    fn_8014C468();
}

void fn_8014C540()
{
    fn_80072B98(lbl_8061930C);
    fn_8014C3DC();
    if (!lbl_8061A32C) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    lbl_8061A32C->mB8 = 1;
}

/* Game start-up (called from main, fn_8014D63C): runs fn_8014BEB8, registers the exit hook
   fn_8014D6A4, builds two singletons, sets the audio levels from the saved settings and
   prints "Entering game loop." */
void fn_8014C5A4(int a, char** b)
{
    VT18** pa = &lbl_8068F1FC;
    VT18** pb = &lbl_8068F1F4;
    fn_8014BEB8(a, b);
    fn_80400690(fn_8014D6A4);
    fn_8033E958(lbl_805C5678);
    FxBase8014C5A4* fx = (FxBase8014C5A4*)operator new(0x1128, 0);
    fn_80328234(fx, 0xB, 0);
    fx->m18 = lbl_80665558;
    fn_8030408C(fx);
    *pa = (VT18*)fx;
    FxBase8014C5A4* fy = (FxBase8014C5A4*)operator new(0x24, 0);
    fn_803282A8(fy, 0);
    *pb = (VT18*)fy;
    fy->m18 = lbl_8065D5A0;
    fn_8033E958(lbl_805C5694);
    fn_8037C924(fn_8037C7FC__Fv());
    fn_80316614((void*)lbl_8061FEDC, 2, 0.39999998f);
    fn_8014BB70();
    lbl_80624270 = lbl_8068B618;
    lbl_80624278 = lbl_8061E978;
    unsigned char* settings = fn_8007FE04__FP13Unk8007F198_D(lbl_8061930C);
    unsigned char* levels = settings + 4;
    Unk8001BC8C* snd = fn_8001BC4C();
    snd->fn_8001C05C(0, (unsigned)settings[4] * (1.0f / 255.0f), 1);
    snd->fn_8001C05C(3, (unsigned)levels[3] * (1.0f / 255.0f), 1);
    snd->fn_8001C05C(1, (unsigned)levels[1] * (1.0f / 255.0f), 1);
    snd->fn_8001C05C(4, (unsigned)levels[4] * (1.0f / 255.0f), 1);
    snd->fn_8001C05C(2, (unsigned)levels[2] * (1.0f / 255.0f), 1);
    fn_8031CE68();
    fn_802ACFB0(lbl_8061E978);
    fn_80316614((void*)lbl_8061FEDC, 2, 0.7804878f);
    fn_80316614((void*)lbl_8061FEDC, 2, 0.88780487f);
    fn_802BB894(fn_802BB580());
    fn_8031E1D4(fn_80314790((void*)lbl_8061FEDC), lbl_80620150);
    lbl_8061FF64->v2();
    fn_80329AA8(fn_80329988());
    fn_800C33D0();
    fn_800C5E28();
    fn_8033E958(lbl_805C5694);
    fn_800B555C();
    fn_800907A4(lbl_8061977C, 1, 0);
    fn_802B8C84();
    if (!lbl_8061A32C) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    fn_80316614((void*)lbl_8061FEDC, 2, 1.0f);
    fn_803164A0__Fv((void*)lbl_8061FEDC);
    ((X1DC_8014D1EC*)lbl_8061FEDC)->m1DC = 0;
    fn_8033E958(lbl_805C56A0);
}

/* near-miss (2 slots, 98.8%): retail stores 0x174 before forming o+0x210 (addi r3); the scheduler here hoists the addi above the first store; 120 store orders and a local for the sub-object pointer tried */
int fn_8014D1EC() /* 8014D1EC */
{
    X1DC_8014D1EC* x = (X1DC_8014D1EC*)lbl_8061FEDC;
    lbl_8061B9A4 = 0;
    fn_802D7A74();
    if (!lbl_8061A32C) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    ((VT18*)lbl_8061A32C)->s19();
    int k1 = 0x1B;
    int k2 = 0x1C;
    lbl_80620424 = k1;
    lbl_80620428 = k2;
    if (lbl_8061B998 != 0) {
        delete lbl_8061B998;
        lbl_8061B998 = 0;
    }
    if (lbl_8061B9A0 != 0) {
        delete lbl_8061B9A0;
        lbl_8061B9A0 = 0;
    }
    PObj_8014D1EC* p = lbl_806192E0->m4;
    fn_8006A1F4__11Unk80069F0C(p);
    fn_8014C540();
    fn_8014C3BC();
    fn_80316614(x, 1, 0.02f);
    fn_80316614(x, 3, 0.02f);
    fn_80316614(x, 5, 0.02f);
    fn_802BB1E4__FP15Unk802BB1E4_Obji(fn_802BB19C__Fv(), 1);
    if (fn_801498C0(lbl_8068B618, p) == 0) {
        return 0;
    }
    fn_801810C8();
    fn_8014CBE8(p, lbl_806192E0->m8);
    if (lbl_8061D45C != 0) {
        fn_802D5BF4(fn_801A4CE8(lbl_8061B8C0->m8, 1), 1, "HeadViewer");
    }
    lbl_8068B618->m24 = 0;
    fn_802D7ACC();
    if (p->m10->m74 != 0xA) {
        char* o = (char*)operator new(0x2E0, 0);
        *(int*)(o + 0x174) = 0;
        *(const void**)(o + 0x2DC) = lbl_80666A18;
        *(int*)(o + 0x178) = 0;
        *(int*)(o + 0x1FC) = 0;
        *(int*)(o + 0x200) = 0;
        fn_803E4A50(o + 0x210);
        *(int*)(o + 0x2D8) = 0;
        *(const void**)(o + 0x2DC) = lbl_8065D550;
        fn_80357B58(o);
        lbl_8061B99C = (V2DC_8014D488*)o;
        lbl_8061B998 = (VT18*)fn_80335604(operator new(0x30C, 0), lbl_8061B99C, 0);
    }
    fn_8032D36C();
    x->m1DC = 0;
    if (!lbl_8061A32C) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    ((V18c_8014D1EC*)lbl_8061A32C)->s18(3);
    fn_803164A0__Fv(x);
    return 1;
}

void fn_8014D488()
{
    int x = lbl_8061FEDC;
    if (fn_8031C6A8() != 0) {
        fn_8031C6A8();
        fn_8031C6B4();
    }
    if (!lbl_8061A32C) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    ((VT18*)lbl_8061A32C)->s19();
    if (lbl_8061B99C != 0) {
        delete lbl_8061B99C;
        lbl_8061B99C = 0;
    }
    if (lbl_8061B998 != 0) {
        delete lbl_8061B998;
        lbl_8061B998 = 0;
    }
    fn_802B832C__FP15Unk802ACD88_Mgr(lbl_8061E978);
    fn_80149DD4(lbl_8068B618, lbl_806192E0->m4);
    fn_80312018(x + 0x40);
    lbl_8061FE20 = 0;
    fn_802BB1E4__FP15Unk802BB1E4_Obji(fn_802BB19C__Fv(), 0);
    fn_8014C4E8();
    lbl_8061C688 = 0;
}

void fn_8014D5C0()
{
    fn_802D7538();
    int i = 0;
    while (i < fn_80148404(lbl_8068B618)) {
        Unk8014D5C0_Obj* o = Get8014D5C0(lbl_8068B618, i);
        i++;
        o->m6F8->fn_8006A070();
    }
    fn_80148438(lbl_8068B618);
}

void fn_8014D63C(int a, char** b)
{
    __main();
    fn_8014C5A4(a, b);
    for (;;) {
        fn_8014C8BC();
        fn_80148930(lbl_8068B618);
        if (fn_8014D1EC() == 1) {
            while ((unsigned)(fn_80148930(lbl_8068B618) - 2) <= 1) {
                fn_8014D5C0();
            }
        }
        fn_8014D488();
    }
}

void fn_8014D6A4()
{
    if (lbl_8061B9B8 == 0) {
        lbl_8061B9B8 = 1;
        if (lbl_80620140 != 0) {
            delete lbl_80620140;
            lbl_80620140 = 0;
        }
        lbl_80620140 = 0;
        if (lbl_8062013C != 0) {
            delete lbl_8062013C;
            lbl_8062013C = 0;
        }
        lbl_8062013C = 0;
        fn_80329A50();
        if (lbl_8061F688 != 0) {
            fn_802E3980__15Unk802E3980_Mgr(lbl_8061F688);
        }
        fn_8024F6CC__Fv();
        if (lbl_8061B984 != 0) {
            delete lbl_8061B984;
            lbl_8061B984 = 0;
        }
        if (lbl_8068F1F4 != 0) {
            delete lbl_8068F1F4;
            lbl_8068F1F4 = 0;
        }
        if (lbl_8068F1FC != 0) {
            delete lbl_8068F1FC;
            lbl_8068F1FC = 0;
        }
        fn_8031D0F0();
        fn_8014BC64();
        fn_8037C7FC__Fv();
        fn_8037C764();
        fn_8001C394__Fv();
        fn_8001C410__11Unk8001C314();
        fn_802B8BBC__Fv();
        fn_8037B8EC();
    }
}

void fn_8014D81C(int* p)
{
    fn_803FFA60(p + 1, lbl_805C5F90, 0x18);
    *p = 0;
}

void fn_8014D860(Unk8014D860_Obj* p, int a)
{
    int t = a + 0xF22D0E56;
    p->m4 = t;
    t = t + 0x96041893;
    p->m8 = t;
    t = t + 0x3DF3B646;
    p->mC = t;
    t = t + 0x40DDE76D;
    p->m10 = t;
    t = t + 0x97327AE1;
    p->m14 = t;
    p->m18 = t + 0xD1A9FBE7;
}

Unk8014D9C4_Obj* fn_8014D9C4(Unk8014D9C4_Obj* p)
{
    p->m0 = lbl_805C58AC;
    p->m4 = lbl_805C58AC;
    p->m8 = lbl_805C58AC;
    p->mC = lbl_805C58B0;
    return p;
}

void fn_8014D9EC(Vec4f8014DAFC* out, float x, float y, float z, float w, float m)
{
    float inv = 1.0f / m;
    out->x = inv * (!(x > m) ? (x >? 0.0f) : m);
    out->y = inv * (!(y > m) ? (y >? 0.0f) : m);
    out->z = inv * (!(z > m) ? (z >? 0.0f) : m);
    out->w = inv * (!(w > m) ? (w >? 0.0f) : m);
}

Vec4f8014DAFC fn_8014DAFC(Vec4f8014DAFC v, float s)
{
    Vec4f8014DAFC t = Div8014DAFC(v, s);
    return t;
}

void fn_8014DBA0(Vec4f8014DAFC* out, int r, int g, int b, int a)
{
    float k = 0.003921569f;
    out->x = r > 255 ? 1.0f : ((float)r >? 0.0f) * 0.003921569f;
    out->y = g > 255 ? 1.0f : ((float)g >? 0.0f) * 0.003921569f;
    out->z = b > 255 ? 1.0f : ((float)b >? 0.0f) * 0.003921569f;
    out->w = a > 255 ? 1.0f : ((float)a >? 0.0f) * 0.003921569f;
}

void fn_8014DD30(Vec4f8014DAFC* v)
{
    unsigned c = fn_8014DDAC(v);
    fn_8014DD68(c >> 24, (c >> 16) & 0xFF, (c >> 8) & 0xFF, c & 0xFF);
}

int fn_8014DD68(int a0, int a1, unsigned a2, unsigned a3)
{
    int r;
    if (a3 > 0xDF) {
        r = (a2 >> 3) | (((a0 << 7) & 0x7C00) | ((a1 * 4) & 0x3E0)) | 0x8000;
    } else {
        r = (a2 >> 4) | ((a1 & 0xF0) | ((a0 * 0x10) & 0xF00)) | ((a3 << 7) & 0x7000);
    }
    return r;
}

void fn_8014DF5C(Vec4f8014DAFC* out, Vec4f8014DAFC* pa, Vec4f8014DAFC* pb, float t)
{
    Vec4f8014DAFC a = Copy8014DF5C(pa);
    Vec4f8014DAFC b = Copy8014DF5C(pb);
    float it = 1.0f - t;
    out->x = it * a.x + t * b.x;
    out->y = it * a.y + t * b.y;
    out->z = it * a.z + t * b.z;
    out->w = it * a.w + t * b.w;
}

unsigned fn_8014E01C(Vec4f8014DAFC* v)
{
    const float s = 255.0f;
    Pack8014E01C c;
    c.p.a = (int)(v->z * s);
    c.p.b = (int)(v->y * s);
    c.p.c = (int)(v->x * s);
    c.p.d = (int)(v->w * s);
    return c.u;
}

Unk8014E09C_Obj* fn_8014E09C(Unk8014E09C_Obj* p, int a, int b)
{
    Unk2C* t = &lbl_8061BAD4[b];
    p->m0 = a;
    p->m8 = 0;
    p->mC = lbl_8061B9CC;
    p->m10 = lbl_8061BA7C;
    p->m14 = t;
    p->m4 = b;
    fn_8014E15C((Unk8014E15C_Obj*)p);
    return p;
}

void* fn_8014E108(Unk8014E108_Obj* p)
{
    int t = p->m8;
    if (t != 0xA) {
        int v;
        if (t > 9) {
            v = t;
        } else {
            v = t + 1;
        }
        p->m8 = v;
        fn_803579D4(p);
    }
    return p;
}

void fn_8014E15C(Unk8014E15C_Obj* p)
{
    int type;
    Unk8014E15C_Ctx* c = p->m0;
    switch (c->m6F4) {
    case 0:
    case 12:
        type = 0;
        break;
    case 2:
    case 5:
        type = 1;
        break;
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
        type = 2;
        break;
    case 9:
        type = 3;
        break;
    default:
        type = 1;
        break;
    }
    int k = fn_80081B60__FP13Unk8007FF8C_Y(c->m6F8->m14) == 1 ? 0 : 1;
    int idx = p->m8;
    p->mC = (int*)&((Unk2C*)lbl_8061B9CC)[type];
    p->m10 = (int*)&((Unk2C*)lbl_8061BA7C)[k];
    p->m14 = (int*)&lbl_8061BAD4[p->m4];
    while (*(int*)((char*)p->mC + (idx << 2)) == 0 || *(int*)((char*)p->m10 + (idx << 2)) == 0 || *(int*)((char*)p->m14 + (idx << 2)) == 0) {
        int v;
        if (idx > 9) {
            v = idx;
        } else {
            v = idx + 1;
        }
        p->m8 = v;
        idx = v;
    }
}

int fn_8014E2B4(int a)
{
    int r = 9;
    switch (a) {
    case -1:
        break;
    case 0:
        r = 10;
        break;
    case 1:
        r = 11;
        break;
    case 2:
        r = 12;
        break;
    case 3:
        r = 18;
        break;
    }
    return r;
}

int fn_8014E310(int a)
{
    switch (a) {
    case 9:
        return -1;
    case 10:
        return 0;
    case 11:
        return 1;
    case 12:
        return 2;
    case 13:
        return 3;
    default:
        return -1;
    }
}

int fn_8014E374(int a)
{
    a = a + 1;
    if (a > 3) {
        a = 3;
    }
    return a;
}

/* near-miss: struct-copy form schedules like retail, but the two arms are joined by a cross-jump
   (retail keeps two separate copy+blr tails); field-wise copies schedule differently */
void fn_8014E388(V3i* p, unsigned i)
{
    if (i <= 3) {
        *p = lbl_805C5F54[i];
        return;
    }
    *p = lbl_805C5F78;
}

int fn_8014E3E0(int a)
{
    if (a > 9) {
        if (a == 10) {
            return 0;
        }
        if (a != 11) {
            return 2;
        }
        return 7;
    }
    return a;
}

float fn_8014E40C(Unk8014E40C_Obj* self, unsigned i)
{
    Vec3f8014E40C d = DiffAt8014E40C(self, i);
    return d.x * d.x + d.z * d.z;
}

int fn_8014E498(Vec3f8014E40C* p, float* out)
{
    int idx = -1;
    int i = 0;
    float d2;
    float best = 144000000.0f;
    do {
        Vec3f8014E40C d = DiffAtP8014E498(p, i);
        d2 = d.x * d.x + d.z * d.z;
        if (!(d2 >= best)) {
            best = d2;
            idx = i;
        }
        i++;
    } while (i <= 3);
    if (out != 0) {
        *out = best;
    }
    return idx;
}

void fn_8014E57C(UnkAt2014* p) { p->m2014 = 0x0; }

void fn_8014E588(void* sv, const char* a)
{
    Self8014E588* s = (Self8014E588*)sv;
    if (s->m2014 != 0) {
        DVDClose(s->m2018);
        s->m2014 = 0;
    }
    s->m2010 = 1;
    s->m2004 = 0;
    s->m200C = 0;
    int ok = DVDOpen(a, s->m2018);
    int t = 1;
    if (ok == 0) {
        t = 0;
    }
    s->m2014 = t;
    if (t != 0) {
        t = s->m204C;
    }
    s->m2008 = t;
}

char fn_8014E614(Self8014E588* s)
{
    if (s->m2014 == 0) {
        return 0;
    }
    if (s->m2010 != 0 || s->m2000 > 0x1FFF) {
        s->m2000 = 0;
        char* blk = s->m2018;
        DVDReadAsyncPrio(blk, s, 0x2000, s->m2004, 0, 2);
        int r;
        while ((r = fn_80425064(blk)) != 0) {
            OSYieldThread();
        }
        s->m2010 = r;
        s->m2004 += 0x2000;
        if (s->m2004 >= s->m2008) {
            s->m200C = 1;
        }
    }
    int i = s->m2000;
    s->m2000 = i + 1;
    return ((char*)s)[i];
}

int fn_8014E6E0(void* sv, char* buf, int n)
{
    Self8014E588* s = (Self8014E588*)sv;
    if (s->m200C != 0 || s->m2014 == 0) {
        *buf = 0;
        return 0;
    }
    int i = 0;
    char c = fn_8014E614(s);
    while (c != 10 && c != 0 && i < n) {
        buf[i] = c;
        i++;
        c = fn_8014E614(s);
    }
    if (i < n) {
        if (i > 0 && c == 10 && buf[i - 1] == 13) {
            i--;
        }
        buf[i] = 0;
    } else {
        buf[n - 1] = 0;
        while (c != 10 && c != 0) {
            c = fn_8014E614(s);
        }
    }
    return s->m200C ^ 1;
}

void fn_8014E7EC(void* self, const char* target)
{
    char buf[0x2000];
    buf[0] = lbl_805C5020;
    fn_8040B320(buf + 1, 0, 0x1FFF);
    do {
        int ok = fn_8014E6E0(self, buf, 0x2000);
        if (ok != 1 || strlen(buf) > 0x1FFF) {
            fn_8000C674(0, 0x1A, lbl_805C5A64);
        }
    } while (fn_8040B574(buf, target) != 0);
}

void* fn_8014E88C(void* p)
{
    fn_8014E57C((UnkAt2014*)p);
    fn_8014E588(p, lbl_805C5A90);
    fn_8014E7EC(p, lbl_805C5A98);
    return p;
}

void fn_8014E8DC(void* p)
{
    fn_8014E588(p, lbl_805C5A90);
}

/* near-miss: 55/55 insns, 2 slots: retail keeps 'bad = r ^ 1' in r24 with a real xori on entry and on return;
   ours folds the two xor 1 into a move (== 0 gives subfic/adde) */
int fn_8014E904(char* self, char* a, char* b, char* c)
{
    *a = 0;
    *b = 0;
    *c = 0;
    int bad = fn_8014E6E0(self, self + 0x2060, 0x2000) ^ 1;
    int n = strlen(self + 0x2060);
    if (n > 0x1FFF) {
        fn_8000C674(0, 0x1A, lbl_805C5ABC);
    }
    if (n > 0) {
        fn_8040B830(a, self + 0x2060, 9);
        a[8] = 0;
    }
    if (n > 9) {
        fn_8040B830(b, self + 0x2069, 9);
        b[8] = 0;
    }
    if (n > 0x17) {
        fn_8040B830(c, self + 0x2077, 0x401);
        c[0x400] = 0;
    }
    return bad ^ 1;
}

void* fn_8014E9E0(void* sv)
{
    Self8014E9E0* s = (Self8014E9E0*)sv;
    void* old[18];
    s->m280 = 0;
    if (lbl_8061B9BC != 0) {
        s->m284 = 0;
        s->m2AC[0] = 0;
        s->m2BC[0] = 0;
        s->m2CC[0] = 0;
        s->m280 = fn_8014E88C(operator new(0x4060, 0));
        fn_8014F47C(s);
        unsigned char* fb = 0;
        Unk80634ADC* rm = 0;
        fn_803D81FC();
        fn_803D9E00(fn_803D817C() + 0x10, &fb, &rm);
        fn_8000C4A8(fb, rm);
        void* h = (void*)fn_8014F008;
        old[6] = fn_80433E14(6, h);
        old[10] = fn_80433E14(10, h);
        old[12] = fn_80433E14(12, h);
        old[0] = fn_80433E14(0, h);
        old[1] = fn_80433E14(1, h);
        old[2] = fn_80433E14(2, h);
        old[3] = fn_80433E14(3, h);
        old[5] = fn_80433E14(5, h);
        old[11] = fn_80433E14(11, h);
        old[13] = fn_80433E14(13, h);
        old[14] = fn_80433E14(14, h);
        old[15] = fn_80433E14(15, h);
    }
    return s;
}

void* fn_8014EB44() { if (!lbl_8061BD74) lbl_8061BD74 = fn_8014E9E0(operator new(0x2DC, 0)); return lbl_8061BD74; }

void fn_8014EB90(Self8014EB90* s, int* a, const char* name)
{
    if (lbl_8061B9BC != 0 && a == 0) {
        fn_8040B830((char*)s + 0x284, name, 0x28);
        s->m2AB = 0;
        *a = 0;
    }
}

void fn_8014EBEC(UnkAt2ACS* p, const char* s) { p->m2AC[0] = 0; if (s) fn_8040B830(p->m2AC, s, 0x10); }

void fn_8014EC24(UnkAt2BCS* p, const char* s) { p->m2BC[0] = 0; if (s) fn_8040B830(p->m2BC, s, 0x10); }

void fn_8014EC5C(UnkAt2CCS* p, const char* s) { p->m2CC[0] = 0; if (s) fn_8040B830(p->m2CC, s, 0x10); }

int fn_8014EC94(int a, unsigned b, unsigned c) { return (b & (c - 1)) == 0; }

/* near-miss (3 slots): retail schedules li r29,0 (loop counter) before the first OSReport call, ours after it */
void fn_8014ECA8(int unused, Ctx8014ECA8* c, int dsisr, int dar)
{
    int i;
    for (i = 0, OSReport("Registers\n"); i < 16; i++) {
        OSReport("r%-2d  = 0x%08x (%14d)  r%-2d  = 0x%08x (%14d)\n", i, c->r[i], c->r[i], i + 16, c->r[i + 16], c->r[i + 16]);
    }
    OSReport("LR   = 0x%08x                   CR   = 0x%08x\n", c->lr, c->cr);
    OSReport("SRR0 = 0x%08x                   SRR1 = 0x%08x\n", c->srr0, c->srr1);
    OSReport("DSISR= 0x%08x                   DAR  = 0x%08x\n", dsisr, dar);
    OSReport("\n");
}

/* near-miss (2 slots): the first fn_8000C674 call loads r3 before r4 here, r4 (2) before r3 (1) in retail */
void fn_8014ED80(int a, unsigned* addr)
{
    fn_8000C674(1, 2, "Disassembly:");
    unsigned* p = addr - 4;
    OSReport("\nDisassembly:\n");
    int row = 13;
    fn_8014F3A8("\nDisassembly:\n");
    do {
        char buf[16] = "";
        if (p == addr) {
            OSReport("      -->");
            fn_8000C674(3, row - 10, "      -->");
            fn_8014F3A8("-->");
        } else {
            OSReport("%08x:", p);
            sprintf(buf, "%08x:", p);
            fn_8000C674(3, row - 10, buf);
            fn_8014F3A8(buf);
        }
        if (fn_8014EC94(a, (unsigned)p, 4) != 0) {
            OSReport("%08x:\n", *p);
            sprintf(buf, "%08x:", *p);
            fn_8000C674(0xC, row - 10, buf);
            fn_8014F3A8(buf);
        }
        row++;
        p++;
        fn_8014F3A8("\n");
    } while (row <= 19);
}

void fn_8014EF0C(int a, int unused, Frame8014EF0C* sp0)
{
    OSReport("\nAddress:      Back Chain    LR Save\n");
    Frame8014EF0C* sp = sp0;
    unsigned i = 0;
    while (sp != 0 && sp != (Frame8014EF0C*)-1 && i++ <= 31) {
        if (sp->lr != 0) {
            char buf[16] = "";
            OSReport("  0x%08x:   0x%08x    0x%08x\n", sp, sp->next, sp->lr);
            sprintf(buf, "%08x", sp->lr);
            fn_8014F4B4(a, buf);
        } else {
            OSReport("--------");
        }
        sp = sp->next;
    }
    fn_8014F738(a);
}

void* fn_8014F008(int a, int b, int c, int d)
{
    void* r = fn_8014EB44();
    if (r != 0) {
        r = fn_8014F05C(r, a, b, c, d);
    }
    return r;
}

void* fn_8014F05C(void* sv, int code0, int ctxp, int dsisr, int dar) /* 8014F05C */
{
    char* self = (char*)sv;
    unsigned code = code0;
    Ctx8014ECA8* ctx = (Ctx8014ECA8*)ctxp;
    OSCtx8014F05C c;
    fn_80433814(&c);
    fn_8043364C(&c);
    fn_80434F9C();
    fn_8014F34C((int)"crash.txt");
    VISetBlack(0);
    VIFlush();
    VISetBlack(0);
    VIFlush();
    VISetBlack(0);
    VIFlush();
    fn_8000C50C(0);
    fn_8000C540(&lbl_8061589C);
    fn_8000C574(&lbl_80615854);
    if (self[0x284] == 0) {
        char buf[0x50] = "";
        fn_8000C674(1, 1, "Exception:");
        OSReport("\n");
        OSReport("Exception: ");
        if (code <= 0x10) {
            fn_8000C674(0xC, 1, lbl_8061BD30[code]);
            OSReport("%s\n", lbl_8061BD30[code]);
            sprintf(buf, "%s\n", lbl_8061BD30[code]);
            fn_8014F3A8(buf);
        } else {
            fn_8000C674(0xC, 1, lbl_8061BD1C);
            OSReport("%s\n", lbl_8061BD1C);
            sprintf(buf, "%s\n", lbl_8061BD1C);
            fn_8014F3A8(buf);
        }
        OSReport("\n");
    } else {
        fn_8000C674(1, 1, "RelAssert:");
        char* name = self + 0x284;
        OSReport("\n");
        OSReport("RelAssert: ");
        fn_8000C674(0xC, 1, name);
        OSReport("%s\n", name);
        char buf[0x50] = "";
        sprintf(buf, "%s\n", name);
        fn_8014F3A8(buf);
        OSReport("\n");
    }
    fn_8014ECA8((int)self, ctx, dsisr, dar);
    int pc = ctx->srr0;
    if ((pc & 3) == 0) {
        fn_8014ED80((int)self, (unsigned*)pc);
    }
    fn_8014EF0C((int)self, pc, (Frame8014EF0C*)ctx->r[1]);
    fn_8014F954(self);
    fn_8000C50C(0);
    fn_8000C5A8();
    fn_8014F42C();
    fn_8043364C((OSCtx8014F05C*)ctx);
    fn_80433814(&c);
    return fn_80433CE8("C:/mvp2004/source/gc/exception/ddtrap.cpp", 0x2F8, "cExceptionHandler calling OSHalt()\n");
}

void fn_8014F34C(int a)
{
    lbl_8068B700 = 1;
    lbl_8068B704 = 0;
    int r = fn_803FEBDC(a, 6, 0x64, &lbl_8068B6FC);
    if (r == 0) {
        lbl_8068B700 = r;
    }
}

void fn_8014F3A8(const char* str)
{
    if (lbl_8068B700 != 0) {
        if (str == 0) {
            lbl_8068B700 = 0;
        } else {
            int pos = lbl_8068B704;
            lbl_8068B704 += fn_803FEC74(lbl_8068B6FC, pos, str, strlen(str), 100);
        }
    }
}

void fn_8014F42C()
{
    if (lbl_8068B700 != 0) {
        int r = fn_803FEC9C(lbl_8068B6FC, 0x64);
        if (r == 0) {
            lbl_8068B700 = r;
        }
    }
}

}
