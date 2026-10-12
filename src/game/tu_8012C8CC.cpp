/*
 * Game code, .text 0x8012C8CC-0x80130DFC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8012C8CC.h"

#include "game/tu_8001B190.h"
struct Unk8013013C_VD {
    char pad0[0x3C];
};
struct Unk8013013C_V : Unk8013013C_VD {
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
    virtual void fn_vslot51();
    virtual void fn_vslot52();
    virtual void fn_vslot53();
    virtual void fn_vslot54();
    virtual void fn_vslot55();
    virtual void fn_vslot56();
    virtual void fn_vslot57();
    virtual void fn_vslot58();
    virtual void fn_vslot59();
    virtual void fn_vslot60();
    virtual void fn_vslot61();
    virtual void fn_vslot62();
    virtual void fn_vslot63();
    virtual void fn_vslot64();
    virtual void fn_vslot65();
    virtual void fn_vslot66();
    virtual void fn_vslot67();
    virtual void fn_vslot68();
    virtual void fn_vslot69();
    virtual void fn_vslot70();
    virtual void fn_vslot71();
    virtual void fn_vslot72();
    virtual void fn_vslot73();
    virtual void fn_vslot74();
    virtual void fn_vslot75();
    virtual void fn_vslot76();
    virtual void fn_vslot77();
    virtual void fn_vslot78();
    virtual void fn_vslot79();
    virtual void fn_vslot80();
    virtual void fn_vslot81();
    virtual void fn_vslot82();
    virtual void fn_vslot83();
    virtual void fn_vslot84(int a);
    virtual int fn_vslot85();
    virtual void fn_vslot86();
    virtual void fn_vslot87();
    virtual void fn_vslot88(int a, int b);
};
extern const char lbl_805BDC38[];
extern "C" void fn_801303A0(void* x);
extern "C" void fn_80130F04(void* x);

struct Unk8012CCF4_Obj {
    char pad0[0x14];
    int m14;
};

/* Front-end screen class (ctor fn_8012E7FC, vptr lbl_806554C8, base ctor fn_800EC648). */
struct Unk8012E7FC : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
    int m150;
    int m154;
    int m158;
    int m15C;
    int m160;
    int m164;
    int m168;
    int m16C;
    void (*m170)();
    int m174;
    Unk8012CCF4_Obj* m178;
    int m17C;
    int m180;
    int m184;
    int m188;
    int m18C;
    int m190;
    int m194;
    int m198;
    int m19C;
};
typedef Unk8012E7FC Scr;

static inline int IsBusy(Scr* x)
{
    if (x->m188 != 0 || x->m18C != 0) {
        return 1;
    }
    return 0;
}

struct UnkFEState {
    char pad0[0x570];
    int m570;
};
struct Unk8061A32C {
    char padB8[0xB8];
    int mB8;
};
extern Unk8061A32C* lbl_8061A32C;
extern const char lbl_806554C8[];
extern const char lbl_805C0424[];
extern const char lbl_805C0438[];
extern const char lbl_805C0A08[];
extern const char lbl_805C0A14[];
Unk8001BC8C* fn_8001BC4C();

extern "C" {
UnkFEState* fn_800B555C();
Unk8061A32C* fn_800B64BC(void* p);
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
Unk800C7B40_Widget* fn_800C8044(Unk800C7B40_Widget* p);
int fn_8012E3F4(Scr* x, int a);
void fn_8012E328(Scr* x, int a);
void fn_8012D180(Scr* x, Unk800C7B40_Widget* w, int v);
void fn_800ECAA4(void* x);
void fn_800ED254(void* x);
void* fn_800C33D0();
void fn_800C3BE0();
int fn_8011AA24(int a);
int fn_801A4A94(int a, int b);
void fn_800C3DCC(void* a, int b, int c);
void fn_800C3ED4(void* a, int b, int c);
}
extern "C" {
void* fn_800B8144();
void fn_800B83F8(void* p, int a, int b);
int fn_80127550(Scr* x, Unk800C7B40_Widget* w);
int fn_800DC0F4(int a, int b, int c);
void fn_800ECE34(void* x);
void fn_8012E9D4(void* x);
void fn_800C3AB4(void* p, int v);
}
extern const char lbl_805C0938[];
extern const char lbl_805C0954[];
extern const char lbl_805BC19C[];
extern const char lbl_805BC1A0[];
extern const char lbl_805BDE3C[];
extern const char lbl_805BF22C[];
/* Second base object at +0xDC of the list/spinner controls: vptr at +0x24 of that base (+0x100). */
struct Unk8012E1C4_LData {
    char pad0[0x3C];
};
struct Unk8012E1C4_L : Unk8012E1C4_LData {
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
    virtual void fn_vslot51();
    virtual void fn_vslot52();
    virtual int fn_vslot53(int a);
};
struct UnkDC_Data {
    char pad0[0x24];
};
struct UnkDC : UnkDC_Data {
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual int fn_vslot5();
    virtual void fn_vslot6(int a);
};
extern "C" {
void fn_80126CF4(Scr* x, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
Unk800C7B40_Widget* fn_800C805C(Unk800C7B40_Widget* p);
Unk800C7B40_Widget* fn_800C8058(Unk800C7B40_Widget* p);
void fn_8012D0D0(Scr* x);
}
struct Unk8007FE04_Ret {
    char pad0[0x1E0];
    int m1E0;
};
struct Unk8061A32C_FE {
    char padB8[0xB8];
    int mB8;
};
extern void* lbl_8061930C;
extern "C" {
int fn_80077BC4(void* g, int a);
int fn_8007B320(void* g, int a, int b);
int fn_8007F7D0(void* g, int a);
int fn_8007F84C(void* g);
Unk8007FE04_Ret* fn_8007FE04(void* g);
int fn_800B5758(UnkFEState* s);
int fn_800B57EC(UnkFEState* s);
}
struct Unk8061B400_Row {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};
extern Unk8061B400_Row lbl_8061B400[];
extern Unk8061B400_Row lbl_8061B4A8[];
extern "C" {
Unk800C7B40_Widget* fn_8012CC20(Scr* x);
int fn_8012CCF4(Scr* x, int which);
}
struct Unk8012CEF4_WPad : Unk800C7B40_Widget {
    char pad40[0x9C];
};
struct Unk8012CEF4_List : Unk8012CEF4_WPad, UnkDC {
};

extern const char lbl_805C0898[];
extern const char lbl_805C08AC[];
extern const char lbl_805C08C0[];
extern const char lbl_805C08EC[];
extern const char lbl_805C08F8[];
extern const char lbl_805C0918[];

struct UnkI184 {
    char pad0[0x184];
    int m184;
};

extern "C" int fn_8012C8CC(Scr* x, int a)
{
    if (!IsBusy(x) && x->m13C != 0 && x->m164 != 0 && x->m168 != 0 && fn_8012E3F4(x, a) != 0) {
        x->fn_vslot84(0, 0);
    }
    return 0;
}

extern "C" int fn_8012C978(Scr* x, int a)
{
    if (!IsBusy(x) && x->m13C != 0 && x->m164 != 0 && x->m168 != 0 && fn_8012E3F4(x, a) != 0) {
        x->fn_vslot84(1, 0);
    }
    return 0;
}

extern "C" int fn_8012CA24(Scr* x, int a)
{
    if (x->m134 != 0 && fn_8012E3F4(x, a) != 0) {
        fn_8001BC4C()->fn_8001BDAC(0xA0);
        x->fn_vslot8(0);
        x->fn_vslot16(0);
        fn_8012E328(x, 0);
        if (x->m170 != 0) {
            x->m170();
        }
        return 1;
    }
    return 0;
}

extern "C" int fn_8012CAD4(void* unused, int a)
{
    int r = 0;
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    if (lbl_8061A32C->mB8 == 0) {
        UnkFEState* s = fn_800B555C();
        if (fn_800B57EC(s) != 0 && (fn_8007FE04(lbl_8061930C)->m1E0 == 1 || fn_800B5758(s) != 0)) {
            void* g = lbl_8061930C;
            if (fn_8007F84C(g) != 0) {
                int t = fn_8007F7D0(g, 0);
                int c0 = fn_8007B320(g, 0, t);
                int c1 = fn_8007B320(g, 1, t);
                int c2 = fn_8007B320(g, 2, t);
                int c3 = fn_8007B320(g, 3, t);
                int h = fn_80077BC4(g, a);
                if (h != 0 && (h == c0 || h == c1 || h == c2 || h == c3)) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

extern "C" Unk800C7B40_Widget* fn_8012CC20(Scr* x)
{
    Unk800C7B40_Widget* r = 0;
    int k = x->fn_vslot85();
    if (k != 2) {
        if (k == 0) {
            if (x->fn_vslot86() != 0) {
                r = fn_800C8044(x->fn_vslot32(lbl_805C0424, 1));
            }
        } else {
            if (x->fn_vslot87() != 0) {
                r = fn_800C8044(x->fn_vslot32(lbl_805C0438, 1));
            }
        }
    }
    return r;
}

extern "C" int fn_8012CCF4(Scr* x, int which)
{
    int sub = 0;
    int v = 5;
    if (x->m178 != 0) {
        sub = x->m178->m14;
        Unk800C7B40_Widget* w;
        if (which == 0) {
            w = fn_800C8044(x->fn_vslot32(lbl_805C0424, 1));
        } else {
            w = fn_800C8044(x->fn_vslot32(lbl_805C0438, 1));
        }
        v = fn_80127550(x, w);
    }
    return fn_800DC0F4(sub, v, which == 0 ? x->m164 : x->m168);
}

/* near-miss: 77/79 insns but about 70 slots differ; retail keeps the vslot-85 result's CR bit (mr. / mfcr / mtcrf) to select both m15C/m160 and m154/m158 and computes the two member addresses before the call */
extern "C" void fn_8012CDC0(Scr* x)
{
    Unk800C7B40_Widget* c = fn_8012CC20(x);
    if (c != 0) {
        Unk800C7B40_Widget* a = fn_800C8058(c->fn_vslot29(lbl_805C0898));
        Unk800C7B40_Widget* b = fn_800C8058(c->fn_vslot29(lbl_805C08AC));
        x->m174 = ((UnkDC*)((char*)a + 0xDC))->fn_vslot5();
        int k = x->fn_vslot85();
        int* pa = &x->m160;
        if (k == 0) {
            pa = &x->m15C;
        }
        int r = fn_8012CCF4(x, k);
        *pa = r;
        int* pb = &x->m158;
        if (k == 0) {
            pb = &x->m154;
        }
        if (r != 0) {
            *pb = ((UnkDC*)((char*)b + 0xDC))->fn_vslot5();
        } else {
            *pb = ((UnkDC*)((char*)a + 0xDC))->fn_vslot5();
        }
    }
}

extern "C" void fn_8012CEF4(Scr* x)
{
    if (!IsBusy(x)) {
        Unk800C7B40_Widget* c = fn_8012CC20(x);
        if (c != 0) {
            Unk800C7B40_Widget* a = fn_800C8058(c->fn_vslot29(lbl_805C0898));
            Unk800C7B40_Widget* b = fn_800C8058(c->fn_vslot29(lbl_805C08AC));
            if (((UnkDC*)((char*)a + 0xDC))->fn_vslot5() == x->m174) {
                int p = x->fn_vslot85() == 0 ? x->m15C : x->m160;
                int q = fn_8012CCF4(x, x->fn_vslot85());
                if (p != q) {
                    int idx = x->fn_vslot85() == 0 ? x->m154 : x->m158;
                    if (idx != -1) {
                        if (q != 0) {
                            ((UnkDC*)((char*)b + 0xDC))->fn_vslot6(lbl_8061B400[idx].m14);
                        } else {
                            ((UnkDC*)((char*)a + 0xDC))->fn_vslot6(lbl_8061B4A8[idx].m14);
                        }
                    }
                }
            }
            fn_8012D0D0(x);
        }
    }
}

extern "C" void fn_8012D0D0(Scr* x)
{
    if (x->m164 != 0) {
        fn_8012D180(x, fn_800C8044(x->fn_vslot32(lbl_805C0424, 1)), x->m164);
    }
    if (x->m168 != 0) {
        fn_8012D180(x, fn_800C8044(x->fn_vslot32(lbl_805C0438, 1)), x->m168);
    }
}

extern "C" int fn_8012DEE4(UnkI184* p) { return p->m184; }

extern "C" int fn_8012DEEC() { return 0; }

extern "C" void fn_8012DEF4(Scr* x, int which, int v)
{
    if (which == 0) {
        x->fn_vslot32(lbl_805C08C0, 1)->fn_vslot8(v);
        int* p = &x->m190;
        *(int*)((char*)p + which) = v;
    } else if (which == 1) {
        x->fn_vslot32(lbl_805C08EC, 1)->fn_vslot8(v);
        x->m194 = v;
    }
}

extern "C" void fn_8012DFC0(Scr* x, int which, int v)
{
    if (which == 0) {
        x->fn_vslot29(lbl_805C08F8)->fn_vslot8(v);
    } else if (which == 1) {
        x->fn_vslot29(lbl_805C0918)->fn_vslot8(v);
    }
}

extern "C" int fn_8012E078(Scr* x, int a)
{
    if (a == (int)x->fn_vslot29(lbl_805C0938)) {
        if (x->m188 != 0) {
            fn_8001BC4C()->fn_8001BDAC(0xA3);
            ((Unk800C7B40_Widget*)x->m188)->fn_vslot91();
            fn_80126CF4(x, 0, x->m168, x->m134, x->m16C, (int)x->m170, 0, x->m138, x->m13C, x->m148, x->m14C);
            return 1;
        }
        return 0;
    }
    if (a == (int)x->fn_vslot29(lbl_805C0954) && x->m18C != 0) {
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        ((Unk800C7B40_Widget*)x->m18C)->fn_vslot91();
        fn_80126CF4(x, x->m164, 0, x->m134, x->m16C, (int)x->m170, 0, x->m138, x->m13C, x->m148, x->m14C);
        return 1;
    }
    return 0;
}

/* near-miss: 87/89 insns, about 40 slots differ (arm/loop layout of the two name selects and the 0/1 loop); chain of casts fn_800C8044 / fn_800C805C / fn_800C8058 matches retail order */
extern "C" void fn_8012E1C4(Scr* x, int which, int a)
{
    const char* n = which == 0 ? lbl_805C0424 : lbl_805C0438;
    Unk800C7B40_Widget* p = fn_800C805C(fn_800C8044(fn_800C8044(x->fn_vslot32(n, 1))->fn_vslot32(lbl_805BC1A0, 1))->fn_vslot32(lbl_805BC19C, 1));
    for (int i = 0; i <= 1; i++) {
        Unk8012E1C4_L* o = (Unk8012E1C4_L*)fn_800C8058(p->fn_vslot32(i == 0 ? lbl_805BF22C : lbl_805BDE3C, 1));
        int idx = o->fn_vslot53(a);
        if (idx != -1) {
            ((UnkDC*)((char*)o + 0xDC))->fn_vslot6(idx);
        }
    }
    fn_8012D0D0(x);
}

extern "C" void fn_8012E328(Scr* x, int a)
{
    if (a != 0) {
        fn_800B83F8(fn_800B8144(), 1, 1);
    } else if (x->m140 == 0) {
        if (!x->b0 || (!x->fn_vslot32(lbl_805C0424, 1)->b0 && !x->fn_vslot32(lbl_805C0438, 1)->b0)) {
            fn_800B83F8(fn_800B8144(), 0, 0);
        }
    }
}

extern "C" int fn_8012E3F4(Scr* x, int a)
{
    int t = x->m198;
    if (t == -99) {
        int s = fn_800B555C()->m570;
        return a == s || s == -1;
    }
    return t == -1 || a == t;
}

extern "C" void fn_8012E45C(Scr* x, int v, int which)
{
    if (which == 0) {
        x->m188 = v;
    } else if (which == 1) {
        x->m18C = v;
    }
}

extern "C" void fn_8012E47C(int a, int b)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    if (lbl_8061A32C->mB8 != 0) {
        int c = fn_801A4A94(fn_8011AA24(0), b);
        fn_800C3DCC(fn_800C33D0(), a, c);
    } else {
        fn_800C3ED4(fn_800C33D0(), a, b);
    }
}

extern "C" int fn_8012E7F4() { return 0; }

extern "C" Scr* fn_8012E7FC(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806554C8);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = -1;
    self->m154 = -1;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m174 = 0;
    self->m17C = 0;
    self->m180 = 5;
    self->m184 = 5;
    self->m188 = 2;
    self->m18C = 0;
    self->m190 = 0;
    self->m194 = 1;
    self->m19C = -1;
    self->m198 = 1;
    return self;
}

extern "C" void fn_8012E8B4(Scr* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" void fn_8012E8DC(Scr* x)
{
    fn_800ECE34(x);
    fn_8012E9D4(x);
    fn_800C3AB4(fn_800C33D0(), 9);
    x->fn_vslot8(1);
    x->fn_vslot16(1);
    x->fn_vslot32(lbl_805C0A08, 1)->fn_vslot8(0);
    x->fn_vslot32(lbl_805C0A14, 1)->fn_vslot8(0);
}

extern "C" void fn_8013011C(Scr* x)
{
    fn_800ECAA4(x);
}

extern "C" void fn_8013013C(Scr* x, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int s8, int sC, int s10, int s14)
{
    x->m13C = s10;
    x->m180 = 5;
    x->m134 = a5;
    x->m138 = sC;
    x->m148 = s14;
    x->m17C = 0;
    x->m184 = 5;
    x->m174 = a7;
    x->m168 = a2;
    x->m16C = a4;
    x->m170 = (void (*)())a6;
    x->m160 = a1;
    x->m164 = a3;
    if (s10 == 0) {
        if (a1 != 0) {
            if (((Unk8013013C_V*)x)->fn_vslot85() != 0)
                ((Unk8013013C_V*)x)->fn_vslot84(0);
        } else if (a3 != 0) {
            if (((Unk8013013C_V*)x)->fn_vslot85() != 1)
                ((Unk8013013C_V*)x)->fn_vslot84(1);
        } else {
            if (((Unk8013013C_V*)x)->fn_vslot85() != 2)
                ((Unk8013013C_V*)x)->fn_vslot84(2);
        }
    }
    if (x->m138 == 0) {
        ((Unk8013013C_V*)x)->fn_vslot88(0, 0);
        ((Unk8013013C_V*)x)->fn_vslot88(1, 0);
    }
    fn_800C8044(x->fn_vslot32(lbl_805C0A08, 1))->fn_vslot32(lbl_805BDC38, 1)->fn_vslot8(0);
    fn_800C8044(x->fn_vslot32(lbl_805C0A14, 1))->fn_vslot32(lbl_805BDC38, 1)->fn_vslot8(0);
    fn_8012E9D4(x);
    fn_801303A0(x);
    fn_80130F04(x);
}

extern "C" int fn_8013080C(Scr* x, Unk800C7B40_Widget* a)
{
    if (a == fn_800C8044(x->fn_vslot32(lbl_805C0A08, 1))) {
        return x->m180;
    }
    return a == fn_800C8044(x->fn_vslot32(lbl_805C0A14, 1)) ? x->m184 : 0;
}
