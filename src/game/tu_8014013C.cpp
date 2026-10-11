/*
 * Game code, .text 0x8014013C-0x80144190 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8012C8CC.h"

#include "game/tu_8001B190.h"

/* Object with its vptr at +0x1C (returned by fn_8058F1F0 / fn_8058F11C). */
struct Unk8058F1F0_Data {
    char pad0[0x1C];
};
struct Unk8058F1F0 : Unk8058F1F0_Data {
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual int fn_vslot9();
};
struct Unk8061930C {
    char pad0[0x34];
    int m34;
};
extern Unk8061930C* lbl_8061930C;
extern const int lbl_805C1B54[];
extern "C" {
Unk8058F1F0* fn_8058F1F0(int a, int b);
int fn_805901AC(Unk8058F1F0* o, int v);
int fn_8007DA28(Unk8061930C* g);
int fn_8007D41C(Unk8061930C* g, int v, int w);
int fn_8013BBF0(int v);
void fn_8037B424(void* p, int in_chrg);
void* fn_801418B4(void* p);
void fn_80142254(char* p);
void fn_800ED254(void* p);
int fn_80143114(void* x);
void fn_800ECF18(void* p);
int fn_8040B830(int a, const char* s, int n);
void fn_800C8070(void* p);
void fn_802D7EE4();
}
/* Object returned by fn_8058F11C (vptr at +0xC; the data after it starts at +0x10). */
struct Unk8058F11C_Data {
    char pad0[0xC];
};
struct Unk8058F11C : Unk8058F11C_Data {
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual int fn_vslot3(int a);
    virtual int fn_vslot4();
};
extern int lbl_8061977C;
extern "C" Unk8058F11C* fn_8058F11C(int a, int b);
extern "C" void* fn_80090880(int a, int b);
Unk8001BC8C* fn_8001BC4C();
struct Unk800B7A94_Ret {
    char pad0[0x24];
    int m24;
};
extern int lbl_8061A328;
extern int lbl_8061A32C;
extern int lbl_80687CDC;
extern const char lbl_805BA230[];
extern const float lbl_805C2C54;
extern "C" {
int fn_80143128();
int fn_800B64BC(void* p);
Unk800B7A94_Ret* fn_800B7A94(int a, const char* s);
void* fn_8005ACE4();
void fn_8005B9D4(void* p, int v);
}
struct Unk80687CC8 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};
extern Unk80687CC8 lbl_80687CC8;
extern int lbl_8061B86C;
extern const char lbl_8065C4E0[];
extern const char lbl_80649DB8[];
extern const char lbl_8064C820[];
extern const char lbl_8064C848[];
struct Unk801418B4_Sub {      /* second base at +0x134: ctor fn_803785E4, vptr at +8 */
    int m0;
    int m4;
};
struct Unk801418B4 : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    Unk801418B4_Sub m134;
    const void* m13C;
    int m140;
    char pad144[0x10];
    int m154;
    int m158;
};
extern "C" {
void fn_80143190(Unk801418B4* x, int v);
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_803785E4(void* p);
void fn_80378A34(void* p, void* q);
int fn_8005B864(void* p);
int fn_8005B9B0(void* p, int v);
}
extern int lbl_80687CCC;
extern float lbl_806E02D8[];
extern float lbl_806E02FC[];
extern float lbl_806E0314[];
extern float lbl_806E0328[];
extern float lbl_806E035C[];
extern float lbl_806E0394[];
extern float lbl_806E03A0[];
extern float lbl_806E03B0[];
extern float lbl_806EF9B8[];
static inline float LdF(char* b, int off)
{
    return *(float*)(b + off);
}
static inline void StF(char* b, int off, const float& v)
{
    *(float*)(b + off) = v;
}
struct UnkDC_Data {
    char pad0[0x24];
};
struct UnkDC : UnkDC_Data {
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6(int a);
    virtual void fn_vslot7();
    virtual void fn_vslot8(int a);
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual int fn_vslot11();
    virtual void fn_vslot12();
    virtual int fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
};
struct UnkDC_Owner : Unk800C7B40_Widget {
    char pad40[0x9C];
};
/* Screen class of this unit as seen by fn_80141724: the controls at +0x154/+0x170/+0x178/+0x17C have a second base at +0xDC. */
struct Unk80141724 : Unk800C7B40_Widget {
    char pad40[0xF4];
    int m134;
    Unk800C7B40_Widget* m138;
    char pad13C[0x18];
    UnkDC_Owner* m154;
    char pad158[0x18];
    UnkDC_Owner* m170;
    char pad174[0x4];
    UnkDC_Owner* m178;
    UnkDC_Owner* m17C;
    char pad180[0x5C];
    int m1DC[1];
    char pad1E0[0xDC];
    int m2BC;
};
extern "C" {
int fn_800ED4F0(void* x, int a);
void fn_8013F60C(int a, int b, void* c, void* d);
void fn_8013F91C(void* x, int a);
void fn_801413E8(void* x, int a);
void fn_800C5E28();
void fn_800C6698();
void fn_8013E240(void* x);
void fn_801407AC(void* x);

}
extern const int lbl_805C2074[];
struct Unk80141214_CtlData {
    char pad0[0x3C];
};
struct Unk80141214_Ctl : Unk80141214_CtlData {
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual void fn_vslot24();
    virtual void fn_vslot25();
    virtual void fn_vslot26();
    virtual void fn_vslot27();
    virtual void fn_vslot28();
    virtual void fn_vslot29();
    virtual void fn_vslot30();
    virtual void fn_vslot31();
    virtual void fn_vslot32();
    virtual void fn_vslot33();
    virtual void fn_vslot34();
    virtual void fn_vslot35();
    virtual void fn_vslot36();
    virtual void fn_vslot37();
    virtual void fn_vslot38();
    virtual void fn_vslot39();
    virtual void fn_vslot40();
    virtual void fn_vslot41();
    virtual void fn_vslot42();
    virtual void fn_vslot43();
    virtual void fn_vslot44();
    virtual void fn_vslot45();
    virtual void fn_vslot46();
    virtual void fn_vslot47();
    virtual void fn_vslot48();
    virtual void fn_vslot49();
    virtual void fn_vslot50();
    virtual void fn_vslot51(int a, int b);
};
/* Screen class as seen by fn_80141214. */
struct Unk80141214 : Unk800C7B40_Widget {
    char pad40[0x120];
    Unk800C7B40_Widget* m160;
    Unk80141214_Ctl* m164;
    char pad168[0x4];
    Unk800C7B40_Widget* m16C;
};
extern "C" {
void* fn_800B555C();
int fn_800B57EC(void* s);
}
extern "C" void fn_80141214(void* x, int idx);
struct Unk8061930C_Inner {
    char pad0[0x42C];
    int m42C;
};
/* Screen class as seen by fn_80141084. */
struct Unk80141084 : Unk800C7B40_Widget {
    char pad40[0xF4];
    int m134;
    char pad138[0x1C];
    UnkDC_Owner* m154;
    char pad158[0x54];
    int m1AC;
};
extern "C" {
void fn_80125084(int a, int b);
void fn_80125128(int a, int b);
void fn_801251CC(int a, int b, int c, int d);
int fn_800B5634(void* s);
int fn_800B56C4(void* s);
int fn_80140250(void* x, int a);
}
struct Unk80142F50_Slot {
    char pad0[0x110];
    short m110;
    short m112;
};
struct Unk80142F50_Mgr {
    int m0;
    struct Unk80142F50_Inner {
        char pad0[0x10];
        Unk80142F50_Slot* m10;
    }* m4;
};
extern Unk80142F50_Mgr* lbl_806192E0;
struct Unk80142544_WData {
    char pad0[0x3C];
};
struct Unk80142544_W : Unk80142544_WData {
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual void fn_vslot24();
    virtual void fn_vslot25();
    virtual void fn_vslot26();
    virtual void fn_vslot27();
    virtual void fn_vslot28(const char* name);
};
/* Screen class as seen by fn_80142544. */
struct Unk80142544 : Unk800C7B40_Widget {
    char pad40[0x100];
    Unk800C7B40_Widget* m140;
    int m144;
    int m148;
};
extern const char lbl_805BF1A0[];
extern const char lbl_805C2BF4[];
extern const char lbl_805C2BFC[];
extern const char lbl_805C2C00[];
extern const char lbl_805C2C0C[];
extern const char lbl_805B6F58[];
extern const int lbl_805C3C3C[];
extern int lbl_8061A328;
extern int lbl_8061977C;
extern "C" {
void fn_800ECE34(void* x);
Unk800C7B40_Widget* fn_800C8044(Unk800C7B40_Widget* p);
Unk80142544_W* fn_800C8040(Unk800C7B40_Widget* p);
Unk800C7B40_Widget* fn_800C8058(Unk800C7B40_Widget* p);
void fn_804031BC(char* dst, const char* src);
void fn_800DFEAC(char* buf, const char* s);
void fn_800DFF0C(char* buf, int v);

int fn_80143114(void* x);
void fn_801431A4(void* x);
}

struct UnkP0 {
    const void* m0;
};

extern const unsigned char lbl_805C2004[];
extern "C" int fn_8014013C(int i) { return lbl_805C2004[i]; }

extern const int lbl_805C2074[];
extern "C" int fn_8014014C(int i) { return lbl_805C2074[i]; }

extern const unsigned char lbl_805C203C[];
extern "C" int fn_80140160(int i) { return lbl_805C203C[i]; }

extern const short lbl_805C2154[];
extern "C" int fn_80140170(int i) { return lbl_805C2154[i]; }

extern "C" int fn_80140184(int i)
{
    if (i == 0x37) {
        Unk8058F1F0* o = fn_8058F1F0(lbl_8061930C->m34, 1);
        return fn_805901AC(o, o->fn_vslot9());
    }
    return lbl_805C1B54[i];
}

extern const int lbl_8061B6AC[];
extern "C" int fn_80140200(int i) { return lbl_8061B6AC[i]; }

extern const int lbl_8061B5CC[];
extern "C" int fn_80140214(int i) { return lbl_8061B5CC[i]; }

extern const int lbl_8061B78C[];
extern "C" int fn_80140228(int i) { return lbl_8061B78C[i]; }

extern const int lbl_805C1F24[];
extern "C" int fn_8014023C(int i) { return lbl_805C1F24[i]; }

extern "C" int fn_80140250(void* self, int a)
{
    Unk8061930C* g = lbl_8061930C;
    int s = fn_8007DA28(g);
    int idx = fn_8013BBF0(a);
    if (idx != -1 && (s == -1 || fn_8007D41C(g, s, idx) == 0)) {
        return 1;
    }
    return 0;
}

extern "C" void* fn_80140718()
{
    Unk8058F11C* o = fn_8058F11C(lbl_8061930C->m34, 0);
    int v = o->fn_vslot4();
    if (v == 0) {
        return (char*)o + 0x10;
    }
    return fn_80090880(lbl_8061977C, o->fn_vslot3(v));
}

extern "C" void fn_80141084(Unk80141084* x)
{
    if (fn_80140250(x, ((UnkDC*)((char*)x->m154 + 0xDC))->fn_vslot11()) != 0) {
        fn_80125084(x->m1AC, 2);
        fn_80125084(x->m1AC, 0);
    } else {
        fn_801251CC(x->m1AC, 2, x->m134 == 1 ? 0x351C : 0x351B, 2);
        fn_80125128(x->m1AC, 0);
    }
    if (((UnkDC*)((char*)x->m154 + 0xDC))->fn_vslot11() == 0x37) {
        if (((Unk8061930C_Inner*)lbl_8061930C->m34)->m42C == 0) {
            fn_80125084(x->m1AC, 2);
            fn_80125084(x->m1AC, 0);
        } else {
            fn_80125128(x->m1AC, 0);
            fn_801251CC(x->m1AC, 2, x->m134 == 1 ? 0x351C : 0x351B, 2);
        }
        if (fn_800B56C4(fn_800B555C()) != 0 || fn_800B5634(fn_800B555C()) != 0) {
            fn_801251CC(x->m1AC, 3, 0x5D79, 3);
            return;
        }
        fn_80125084(x->m1AC, 3);
        return;
    }
    fn_801251CC(x->m1AC, 3, 0x3CA5, 4);
}

extern "C" void fn_80141214(void* xp, int idx)
{
    Unk80141214* x = (Unk80141214*)xp;
    int n = 0x4D46;
    int t = lbl_805C2004[idx];
    ((UnkDC*)((char*)x->m164 + 0xDC))->fn_vslot15();
    x->m164->fn_vslot51(t + 0x4D27, 0);
    x->m164->fn_vslot51(0x3C90, 0);
    do {
        x->m164->fn_vslot51(n, 0);
        n = n + 1;
    } while (n <= 0x4D4C);
    if (fn_800B57EC(fn_800B555C()) != 0) {
        ((UnkDC*)((char*)x->m164 + 0xDC))->fn_vslot6(1);
    } else {
        ((UnkDC*)((char*)x->m164 + 0xDC))->fn_vslot6(0);
    }
    if (idx == 0x1E || idx == 0xA || idx == 0x19 || idx == 0x27) {
        x->m16C->fn_vslot16(0);
        x->m160->fn_vslot16(0);
        return;
    }
    x->m16C->fn_vslot16(1);
    x->m160->fn_vslot16(1);
}

extern const int lbl_805C3C00[];
extern "C" int fn_80141710(int i) { return lbl_805C3C00[i]; }

extern "C" void fn_80141724(Unk80141724* x)
{
    int idx = x->m1DC[fn_800ED4F0(x, x->m2BC)];
    ((UnkDC*)((char*)x->m154 + 0xDC))->fn_vslot8(idx);
    int sel = fn_800ED4F0(x, 3);
    fn_80141214(x, idx);
    ((UnkDC*)((char*)x->m170 + 0xDC))->fn_vslot6(lbl_805C2074[idx]);
    fn_8013F60C(idx, sel, x->m17C, x->m178);
    fn_8013F91C(x, idx);
    if (x->m138->fn_vslot60() == 0) {
        if (((UnkDC*)((char*)x->m17C + 0xDC))->fn_vslot13() == 1) {
            x->m138->fn_vslot68(1);
        }
    }
    fn_801413E8(x, idx);
    fn_800C5E28();
    fn_800C6698();
    fn_8013E240(x);
    if (x->m134 == 1) {
        fn_801407AC(x);
    }
}

struct Unk8014188C {
    char pad0[0x1D4];
    int m1D4;
    int m1D8;
};
extern "C" int fn_8014188C(Unk8014188C* x, int a)
{
    if (a == x->m1D4 || a == x->m1D8) {
        return 1;
    }
    return 0;
}

extern const char lbl_8064B738[];
extern "C" void fn_801421D4(UnkP0* x, int chrg)
{
    x->m0 = lbl_8064B738;
    fn_8037B424(x, chrg);
}

extern "C" void* fn_80142204()
{
    return fn_801418B4(operator new(0xFC, lbl_806EF9B4));
}

extern "C" void fn_80142234(char* x)
{
    fn_80142254(x);
}

extern "C" void fn_80142254(char* x)
{
    float t;
    int off;
    off = 0;
    for (int i = 0; i < 9; i++) {
        t = LdF(x + 4, off);
        StF((char*)lbl_806E02D8, off, t);
        off += 4;
    }
    off = 0;
    for (int i = 0; i < 6; i++) {
        t = LdF(x + 0x28, off);
        StF((char*)lbl_806E02FC, off, t);
        off += 4;
    }
    off = 0;
    for (int i = 0; i < 5; i++) {
        t = LdF(x + 0x40, off);
        StF((char*)lbl_806E0314, off, t);
        off += 4;
    }
    off = 0;
    for (int i = 0; i < 13; i++) {
        t = LdF(x + 0x54, off);
        StF((char*)lbl_806E0328, off, t);
        off += 4;
    }
    off = 0;
    for (int i = 0; i < 14; i++) {
        t = LdF(x + 0x88, off);
        StF((char*)lbl_806E035C, off, t);
        off += 4;
    }
    off = 0;
    for (int i = 0; i < 3; i++) {
        t = LdF(x + 0xC0, off);
        StF((char*)lbl_806E0394, off, t);
        off += 4;
    }
    off = 0;
    for (int i = 0; i < 4; i++) {
        t = LdF(x + 0xCC, off);
        StF((char*)lbl_806E03A0, off, t);
        off += 4;
    }
    off = 0;
    for (int i = 0; i < 6; i++) {
        t = LdF(x + 0xDC, off);
        StF((char*)lbl_806E03B0, off, t);
        off += 4;
    }
    off = 0;
    for (int i = 0; i < 2; i++) {
        t = LdF(x + 0xF4, off);
        *(float*)(off + (char*)lbl_806EF9B8) = t;
        off += 4;
    }
}

extern int lbl_8061B870;
extern "C" int fn_80142410() { return lbl_8061B870; }

extern "C" Unk801418B4* fn_8014241C(Unk801418B4* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    Unk801418B4_Sub* s = &self->m134;
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->SetVptr(lbl_8065C4E0);
    fn_803785E4(s);
    *(const void**)((char*)s + 8) = lbl_80649DB8;
    self->m13C = lbl_8064C820;
    self->SetVptr(lbl_8064C848);
    lbl_8061B870 = (int)self;
    self->m158 = 0;
    fn_80378A34(s, fn_8005ACE4());
    if (lbl_8061B86C != 0) {
        int r = fn_8005B864(fn_8005ACE4());
        if (r != 0) {
            Unk80687CC8* g = &lbl_80687CC8;
            int ok = fn_8005B9B0(fn_8005ACE4(), r - 1);
            int t = 0;
            if (ok != 0) {
                t = 1;
            }
            g->m4 = t;
        } else {
            lbl_80687CCC = r;
        }
        fn_80143190(self, r);
        self->m154 = 0;
        lbl_80687CC8.m8 = 1;
        lbl_80687CC8.m10 = -1;
        lbl_8061B86C = 0;
        lbl_80687CC8.m14 = -1;
        lbl_80687CC8.m18 = 1;
    }
    return self;
}

extern "C" void fn_80142544(Unk80142544* x)
{
    fn_800ECE34(x);
    x->fn_vslot8(0);
    x->m140 = fn_800C8044(x->fn_vslot32(lbl_805BF1A0, 1));
    x->m144 = x->m140->m26;
    x->m148 = x->m140->m28;
    ((UnkDC*)((char*)fn_800C8058(x->m140->fn_vslot32(lbl_805C2BF4, 1)) + 0xDC))->fn_vslot6(lbl_80687CC8.m0 - 1);
    char buf[104];
    fn_804031BC(buf, lbl_805B6F58);
    fn_800DFEAC(buf, lbl_805C2BFC);
    fn_800DFF0C(buf, (int)fn_80090880(lbl_8061977C, lbl_805C3C3C[lbl_80687CC8.m0 - 1]));
    fn_800DFEAC(buf, lbl_805C2BFC);
    fn_800C8040(x->m140->fn_vslot32(lbl_805C2C00, 1))->fn_vslot28(buf);
    ((UnkDC*)((char*)fn_800C8058(x->m140->fn_vslot32(lbl_805C2C0C, 1)) + 0xDC))->fn_vslot6(lbl_80687CC8.m0 - 1);
    if (fn_80143114(x) == 0 || lbl_8061A328 <= lbl_80687CC8.m10) {
        x->fn_vslot8(0);
    } else {
        fn_801431A4(x);
    }
    Unk80142F50_Slot* s = lbl_806192E0->m4->m10;
    int a = s->m110;
    int b = s->m112;
    if ((unsigned)(a - 0xF) <= 0x262) {
        x->m140->fn_vslot9(a);
    }
    if ((unsigned)(b - 8) <= 0x1D0) {
        x->m140->fn_vslot10(b);
    }
}

extern "C" void fn_801427C8(Unk800C7B40_Widget* x)
{
    fn_800ECF18(x);
    if (fn_80143114(x) == 0) {
        x->fn_vslot8(0);
    }
}

extern "C" void fn_80142F08(Unk800C7B40_Widget* x)
{
    x->fn_vslot39();
    fn_800ED254(x);
}

struct Unk80142F50 : Unk800C7B40_Widget {
    char pad40[0x100];
    Unk800C7B40_Data* m140;
    char pad144[8];
    int m14C;
    int m150;
    int pad154;
    int m158;
};
extern "C" void fn_80142F50(Unk80142F50* x)
{
    Unk80142F50_Slot* s = lbl_806192E0->m4->m10;
    int a = x->m140->m26;
    s->m110 = a;
    int b = x->m140->m28;
    s->m112 = b;
    x->m158 = 0;
    x->m14C = 0;
    x->m150 = 0;
}

extern "C" int fn_80142F8C()
{
    if (fn_80143128() != 0 && lbl_8061A328 >= lbl_80687CDC - 0x12C) {
        if (lbl_8061A32C == 0) {
            lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
        }
        Unk800B7A94_Ret* t = fn_800B7A94(lbl_8061A32C, lbl_805BA230);
        if (t == 0 || t->m24 >= 0) {
            if (!(fn_8001BC4C()->fn_8001C048(3) <= lbl_805C2C54)) {
                fn_8001BC4C()->fn_8001BDAC(0x9D);
            }
            fn_8005B9D4(fn_8005ACE4(), 0);
        }
    }
    return 0;
}

extern "C" int fn_8014305C(void* x)
{
    if (fn_80143114(x) != 0) {
        fn_800C8070(x);
        fn_802D7EE4();
        return 0;
    }
    return 0;
}

extern const char lbl_805B6F58[];
extern "C" int fn_801430A4(void* self, int a)
{
    return fn_8040B830(a, lbl_805B6F58, 16);
}

extern int lbl_80687CD0;
extern "C" void fn_801430D4(Unk800C7B40_Widget* x)
{
    x->fn_vslot39();
    lbl_80687CD0 = 1;
}

extern int lbl_80687CD0;
extern "C" int fn_80143114(void* x) { return lbl_80687CD0 == 0; }

extern int lbl_80687CE0;
extern "C" int fn_80143128() { return lbl_80687CE0; }

struct Unk80143134_Msg {
    int m0;
    int m4;
    int m8;
};
extern int lbl_80687CCC;
static inline Unk80143134_Msg* Cast(int id, Unk80143134_Msg* m)
{
    if (m != 0) {
        if (m->m0 == id) {
            return m;
        }
        return 0;
    }
    return 0;
}
/* near-miss: 23/23 insns, 7 differ: retail compares the message id in r4 against m->m0 (cmpw r4,r0); here the known id 0xA3 is folded into cmpwi r0,163 */
extern "C" void fn_80143134(Unk801418B4* self, int msg, Unk80143134_Msg* m)
{
    if (msg == 0xA3) {
        Unk80143134_Msg* mm = Cast(msg, m);
        lbl_80687CCC = 1;
        fn_80143190(self, mm->m8);
    }
}

extern "C" void fn_80143190(Unk801418B4* x, int v)
{
    lbl_80687CC8.m0 = v;
    x->m154 = 1;
}

extern "C" void fn_801431A4() {}
