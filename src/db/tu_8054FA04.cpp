/*
 * Database overlay code, .database_codeoverlay 0x8054FA04-0x80554628 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8054FA04.h"

extern float lbl_80622C24[][4];
extern float lbl_80622C74[];
extern float lbl_806EFA08;
extern float lbl_805FF458;
extern int lbl_80622C90;
extern int lbl_80622C94;

extern "C" float fn_8054FA04(int a, int b, int c, int d);
extern "C" float fn_80598348();
extern Unk8007A4DC_Screen* lbl_8061930C;
extern Unk80538DD8_G* lbl_80619948;
extern "C" int fn_800A2E90(Unk80538DD8_G* g);
extern "C" int fn_80077BC4(void* g, int a);
extern unsigned char lbl_8060252C[];
extern unsigned char lbl_80602530[];
extern unsigned char lbl_8060251C[];
extern float lbl_805FF41C;
extern float lbl_805FF420;
extern float lbl_805FF424;
extern char lbl_80622C18[];
extern int lbl_806015F4[][3];
extern "C" int fn_80552D98(int a);
struct Db80553358_S {
    char pad0[0x634];
    int m634;
};
extern "C" void fn_8057D20C(Db80553358_S* self, int a, int b, int c);
struct Db80553754_S {
    char pad0[0x10];
    int m10;
};
struct Db8055395C_S {
    char pad0[0x20];
    int m20;
};
struct Db80553E4C_S {
    int m0;
    int m4;
    int m8;
};
struct Db80553E54_S {
    int m0;
    int m4;
    char* m8;
};
extern "C" void fn_805553C0(Db80553754_S* self);
extern "C" void fn_80542274();
extern "C" void fn_805479F0(char* p);
extern "C" void fn_80547B38(char* p);
extern "C" void fn_80547C5C(char* p);
extern "C" void fn_80547D28(char* p);

#include "game/clampiter.h"
int fn_8007F9B4(Unk8007F198_C* s);
extern "C" void* memset(void* p, int c, ...);
extern "C" float fn_805520E4(int a, float* p0, float* p1, float* p2, float* p3);
extern int lbl_805FF48C[];
extern float lbl_805FF49C;
extern float lbl_805FF4A0;
extern float lbl_805FF4A4;
extern char lbl_8065C1B0[];
extern char lbl_80684150[];
extern char lbl_80683EF8[];
extern char lbl_8064A3B8[];
extern char lbl_805FF50C[];
struct Db80553284_Sub {
    int m0;
    virtual void v1();
    virtual void v2(const char* s);
};
struct Db80553284_S {
    char pad0[0x638];
    Unk80535650_Tmp m638;
    char pad650[0xA38 - 0x650];
    Db80553284_Sub mA38;
};

inline void Db80553284_SubInit(Db80553284_Sub* o)
{
    *(const void**)((char*)o + 4) = lbl_80684150;
    o->m0 = 0;
    *(const void**)((char*)o + 4) = lbl_80683EF8;
}

struct Db805535A4_S {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    Unk80535650_Tmp m24;
    int buf[0xCB2];
};

struct Unk803618C4;
void fn_803618C4(Unk803618C4* p, int c);
extern "C" void fn_80556E0C(void* p, int c);
extern "C" void fn_80377408(void* p);
struct Db80553DA0_Big8 {
    char pad0[0x13D2C];
    virtual ~Db80553DA0_Big8();
};
struct Db80553DA0_S {
    void* m0;
    void* m4;
    Db80553DA0_Big8* m8;
    Unk803618C4* mC;
    char pad10[0x24];
    const void* m34_vp;
};

extern "C" void fn_80581808(void* p);
extern "C" char* fn_80549F54(char* o);
extern "C" char* fn_80546600(char* o);
struct Db805536B4_S {
    int m0;
    char* m4;
    char* m8;
    Db80553284_S* mC;
};

extern "C" int fn_8007F7D0__FP13Unk8007F198_BUi(void* g, unsigned a);
extern "C" void fn_8055EBAC(void* x, Unk805352B0_List* l);
struct Db80553C1C_S {
    char pad0[0x24];
    Unk805352B0_List m24;
};

int fn_800E5C74(int a, int b, int c);

extern "C" void fn_80553388(Db80553358_S* self);
struct Db80554540_S {
    char pad0[0xC];
    Db80553358_S* mC;
};

extern "C" int fn_8007F84C__FP13Unk8007F198_B(void* g);
extern "C" void fn_80400CE4(int a);
extern "C" void fn_8055FF28(int id, void* o, int i);
struct Db805542F0_Sub {
    char pad0[0x32E0];
    int* m32E0;
    unsigned m32E4;
};
struct Db805542F0_S {
    char pad0[8];
    Db805542F0_Sub* m8;
};

inline int Db805542F0_At(int* a, int i)
{
    int o = i * 4;
    return *(int*)((char*)a + o);
}

extern float lbl_805FF3B0;
extern float lbl_80602590[];

extern unsigned char lbl_806025A0[];
extern float lbl_805FF3C0;
/* forward declarations (definitions are in address order) */
extern "C" int fn_80550E68(int a);
extern "C" int fn_805513E0(int a, int p2, int b);
extern "C" int fn_8055150C(int flag, int a, int p, int c, int d, float f);
extern "C" float fn_805518D4(int a);
extern "C" float fn_80551984(int a, int b);
extern "C" void fn_805519A0(int a, int b, float f);
extern "C" float fn_805519CC(int i);
extern "C" void fn_805519E0(int i, float f);
extern "C" void fn_80551A04(int a, Unk80070DDC_Stream* io);
extern "C" void fn_80552054();
extern "C" int fn_8055207C(float f);
extern "C" float fn_8055260C(int a, int b, int c, int d);
extern "C" void fn_80552638(int a);
extern "C" int fn_80552650(int a);
extern "C" int fn_80552CE8(float f);
extern "C" int fn_80553248(int i);
extern "C" int fn_80553260(int a);
extern "C" Db80553284_S* fn_80553284(Db80553284_S* self);
extern "C" void fn_80553358(Db80553358_S* self, int a, int b);
extern "C" Db805535A4_S* fn_805535A4(Db805535A4_S* self);
extern "C" void fn_80553668(Db80553DA0_S* self, int chrg);
extern "C" void fn_805536B4(Db805536B4_S* self);
extern "C" void fn_80553754(Db80553754_S* self);
extern "C" void fn_8055395C(Db8055395C_S* self);
extern "C" void fn_80553C1C(Db80553C1C_S* self, int flag);
extern "C" int fn_80553CA8(int unused, int a, int b, int c, int d);
extern "C" void fn_80553DA0(Db80553DA0_S* self);
extern "C" int fn_80553E4C(Db80553E4C_S* self);
extern "C" char* fn_80553E54(Db80553E54_S* self);
extern "C" char* fn_80553E60(Db80553E54_S* self);
extern "C" void fn_80554228(Db80553754_S* self);
extern "C" void fn_80554260(Db80553E54_S* self);
extern "C" void fn_80554284(Db80553E54_S* self);
extern "C" void fn_805542A8(Db80553E54_S* self);
extern "C" void fn_805542CC(Db80553E54_S* self);
extern "C" void fn_805542F0(Db805542F0_S* self, int mode);
extern "C" void fn_8055440C();
extern "C" void fn_80554540(Db80554540_S* self, int a, int b);

extern "C" DB_OVERLAY int fn_80550E68(int a)
{
    Unk8007B2B0_Screen* sc = (Unk8007B2B0_Screen*)lbl_8061930C;
    float f = ((Unk80537D24_Screen*)sc)->fn_8007BB28(5, a, fn_800A2E90(lbl_80619948));
    int i = 0;
    if (!(f >= lbl_80622C74[0])) {
        while (++i <= 6 && f < lbl_80622C74[i])
            ;
    }
    return i;
}

extern "C" DB_OVERLAY int fn_805513E0(int a, int p2, int b)
{
    Unk8007B2B0_Screen* sc = (Unk8007B2B0_Screen*)lbl_8061930C;
    int base = 0;
    switch (sc->fn_80078A38(p2)) {
    case 0:
        break;
    case 1:
        base = 4;
        break;
    case 2:
        base = 8;
        break;
    case 3:
        base = 0xC;
        break;
    }
    float ratio = lbl_805FF3B0;
    if (b != 0)
        ratio = (float)a / (float)b;
    int i = 0;
    if (!(ratio > lbl_80602590[0])) {
        for (;;) {
            i++;
            if (i > 3)
                break;
            if (!(ratio <= lbl_80602590[i])) {
                base += i;
                break;
            }
        }
    }
    if (i == 4 && b > 20)
        base += 4;
    return base;
}

/* near-miss: 7 slots, retail forms (table + 9/0x12/0x1B) in a register and indexes it; ours folds idx + K into the index */
extern "C" DB_OVERLAY int fn_8055150C(int flag, int a, int p, int c, int d, float f)
{
    int idx = c / 20;
    int base = 0;
    switch (((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80078A38(p)) {
    case 0:
        break;
    case 1:
        base = 5;
        break;
    case 2:
        base = 10;
        break;
    case 3:
        base = 15;
        break;
    }
    if (flag != 0) {
        if (a < lbl_806025A0[idx])
            base += 1;
    } else if (a >= lbl_806025A0[9 + idx]) {
        base += 1;
    } else if (a >= lbl_806025A0[0x12 + idx]) {
        base += 2;
    } else if (!(f < lbl_805FF3C0)) {
        base += 3;
    } else {
        base += 4;
        int v = lbl_806025A0[0x1B + idx];
        if (!(d > v)) {
            if (d > (int)((unsigned)v >> 1))
                base += 1;
            else
                base += 2;
        }
    }
    return base;
}

extern "C" DB_OVERLAY float fn_805518D4(int a)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    int s = lbl_8060252C[sc->fn_8007A6A0(0x34, a)];
    s += lbl_80602530[sc->fn_8007A6A0(0x35, a)];
    s += lbl_8060251C[sc->fn_8007A6A0(0x36, a)];
    return (float)s;
}

extern "C" DB_OVERLAY float fn_80551984(int a, int b)
{
    return lbl_80622C24[a][b];
}

extern "C" DB_OVERLAY void fn_805519A0(int a, int b, float f)
{
    lbl_80622C24[a][b] = f;
}

extern "C" DB_OVERLAY float fn_805519CC(int i)
{
    return lbl_80622C74[i];
}

extern "C" DB_OVERLAY void fn_805519E0(int i, float f)
{
    lbl_80622C74[i] = f;
}

extern "C" DB_OVERLAY void fn_80551A04(int a, Unk80070DDC_Stream* io)
{
    io->v08(a, lbl_80622C18, 4);
    io->v08(a, &lbl_806EFA08, 4);
}

extern "C" DB_OVERLAY void fn_80552054()
{
    lbl_806EFA08 = fn_80598348();
}

extern "C" DB_OVERLAY int fn_8055207C(float f)
{
    int r = 0;
    if (!(f <= lbl_805FF41C))
        r = 3;
    else if (!(f <= lbl_805FF420))
        r = 2;
    else if (!(f <= lbl_805FF424))
        r = 1;
    return r;
}

extern "C" DB_OVERLAY float fn_8055260C(int a, int b, int c, int d)
{
    return fn_8054FA04(a, b, c, d) * lbl_805FF458;
}

extern "C" DB_OVERLAY void fn_80552638(int a)
{
    lbl_80622C90 = a;
    lbl_80622C94 = 0;
}

extern "C" DB_OVERLAY int fn_80552650(int a)
{
    Unk8007B2B0_Screen* sc = (Unk8007B2B0_Screen*)lbl_8061930C;
    int n = fn_80077BC4(sc, a);
    int flag = 1;
    if (fn_800A2E90(lbl_80619948) == 0)
        flag = 0;
    if (n == 0)
        return 0;
    return (int)((Unk80537D24_Screen*)sc)->fn_8007BB28(2, n, flag);
}

extern "C" DB_OVERLAY int fn_80552BE0(int a, int b, int* out)
{
    float v[4];
    float* p = v;
    memset(p, 0, 16);
    float f = fn_805520E4(a, p, &v[1], &v[2], &v[3]);
    if (!(f >= lbl_805FF49C)) {
        float best = lbl_805FF4A0;
        float cur = lbl_805FF4A4;
        int i = 0;
        int k = fn_80552650(a);
        do {
            cur = p[i] / fn_8055260C(a, b, lbl_805FF48C[i], k);
            if (!(cur >= best)) {
                best = cur;
                *out = i;
            }
            i++;
        } while (i <= 3);
        return 1;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_80552CE8(float f)
{
    float t[10] = {0.94f, 0.89f, 0.84f, 0.79f, 0.74f, 0.69f, 0.64f, 0.59f, 0.54f, 0.49f};
    int i;
    for (i = 0; i < 10; i++) {
        if (f > t[i])
            return 10 - i;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_80553248(int i)
{
    return lbl_806015F4[i][1];
}

extern "C" DB_OVERLAY int fn_80553260(int a)
{
    return fn_80553248(fn_80552D98(a));
}

extern "C" DB_OVERLAY Db80553284_S* fn_80553284(Db80553284_S* self)
{
    Unk80535650_Tmp* t = &self->m638;
    t->C1((int*)((char*)self + 0x650), 0xFA);
    t->C2();
    t->vp = lbl_8065C1B0;
    t->mC = 0;
    t->m14 = 0;
    t->m4 = 0;
    Db80553284_Sub* o = (Db80553284_Sub*)((char*)self + 0xA38);
    Db80553284_SubInit(o);
    o->v2(lbl_805FF50C);
    return self;
}

extern "C" DB_OVERLAY void fn_80553358(Db80553358_S* self, int a, int b)
{
    self->m634 = b;
    fn_8057D20C(self, a, b, 1);
}

extern "C" DB_OVERLAY Db805535A4_S* fn_805535A4(Db805535A4_S* self)
{
    self->m0 = 0;
    self->m4 = 0;
    self->m8 = 0;
    self->mC = 0;
    self->m10 = 0;
    self->m14 = 0;
    self->m18 = 0;
    self->m1C = 0x3FFFFFF;
    self->m20 = 0;
    Unk80535650_Tmp* t = &self->m24;
    t->C1(self->buf, 0xCB2);
    t->C2();
    t->C3(lbl_8064A3B8);
    return self;
}

extern "C" DB_OVERLAY void fn_80553668(Db80553DA0_S* self, int chrg)
{
    fn_80553DA0(self);
    self->m34_vp = lbl_8064A550;
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805536B4(Db805536B4_S* self)
{
    fn_80581808(*(void**)((char*)lbl_8061930C + 0x2C));
    if (self->m4 == 0)
        self->m4 = fn_80549F54((char*)operator new(0x14ED4, 0x100));
    if (self->m8 == 0)
        self->m8 = fn_80546600((char*)operator new(0x13D30, 0x100));
    if (self->mC == 0)
        self->mC = fn_80553284((Db80553284_S*)operator new(0xC70, 0x100));
}

extern "C" DB_OVERLAY void fn_80553754(Db80553754_S* self)
{
    self->m10 = 10;
}

extern "C" DB_OVERLAY void fn_8055395C(Db8055395C_S* self)
{
    self->m20 = 1;
}

extern "C" DB_OVERLAY void fn_80553C1C(Db80553C1C_S* self, int flag)
{
    Unk8007B2B0_Screen* sc = (Unk8007B2B0_Screen*)lbl_8061930C;
    int g = fn_8007F7D0__FP13Unk8007F198_BUi(sc, 0);
    int i = 0;
    do {
        int a = sc->fn_8007B2FC(i);
        int x = sc->fn_8007B5D8(0, i);
        i++;
        if (a != g || flag != 0)
            fn_8055EBAC((void*)x, &self->m24);
    } while (i <= 29);
}

/* near-miss: register allocation only (retail keeps base in r11 and 3*base in r9; ours r9/r0) */
extern "C" DB_OVERLAY int fn_80553CA8(int unused, int a, int b, int c, int d)
{
    int base = 15000;
    if (b == 8)
        base = 6000;
    int adj = 0;
    int lo = 6, hi = 8;
    if (b <= hi && b >= lo) {
        if (d > base)
            adj = (d - base) / base;
        else if (d <= ((base * 3) >> 2)) {
            adj = -4;
            if (d > (int)((unsigned)base >> 1))
                adj = -2;
        }
    }
    int res;
    if (adj > 5 - fn_800E5C74(a, b, c))
        res = 5 - fn_800E5C74(a, b, c);
    else if (adj < -4 - fn_800E5C74(a, b, c))
        res = -4 - fn_800E5C74(a, b, c);
    else
        res = adj;
    return res;
}

extern "C" DB_OVERLAY void fn_80553DA0(Db80553DA0_S* self)
{
    if (self->m0) {
        fn_80556E0C(self->m0, 3);
        self->m0 = 0;
    }
    if (self->m4) {
        fn_80377408(self->m4);
        self->m4 = 0;
    }
    if (self->m8) {
        delete self->m8;
        self->m8 = 0;
    }
    if (self->mC) {
        fn_803618C4(self->mC, 3);
        self->mC = 0;
    }
}

extern "C" DB_OVERLAY int fn_80553E4C(Db80553E4C_S* self)
{
    return self->m8;
}

extern "C" DB_OVERLAY char* fn_80553E54(Db80553E54_S* self)
{
    return self->m8 + 0x32E0;
}

extern "C" DB_OVERLAY char* fn_80553E60(Db80553E54_S* self)
{
    return self->m8 + 0x3500;
}

extern "C" DB_OVERLAY void fn_80554228(Db80553754_S* self)
{
    fn_805553C0(self);
    fn_80542274();
    self->m10 = 3;
}

extern "C" DB_OVERLAY void fn_80554260(Db80553E54_S* self)
{
    fn_805479F0(self->m8);
}

extern "C" DB_OVERLAY void fn_80554284(Db80553E54_S* self)
{
    fn_80547B38(self->m8);
}

extern "C" DB_OVERLAY void fn_805542A8(Db80553E54_S* self)
{
    fn_80547C5C(self->m8);
}

extern "C" DB_OVERLAY void fn_805542CC(Db80553E54_S* self)
{
    fn_80547D28(self->m8);
}

extern "C" DB_OVERLAY void fn_805542F0(Db805542F0_S* self, int mode)
{
    unsigned i = 0;
    Db805542F0_Sub* s = self->m8;
    Unk8007B2B0_Screen* sc = (Unk8007B2B0_Screen*)lbl_8061930C;
    unsigned n = s->m32E4;
    for (; i < n; i++) {
        if ((i & 0xF) == 0)
            fn_80400CE4(0);
        int id = sc->fn_80075948(Db805542F0_At(s->m32E0, i));
        int flag = 1;
        if (mode == 0) {
            unsigned j;
            for (j = 0; j < (unsigned)fn_8007F84C__FP13Unk8007F198_B(sc); j++) {
                if (fn_8007F7D0__FP13Unk8007F198_BUi(sc, j) == id) {
                    flag = 0;
                    break;
                }
            }
        } else if (mode == 1) {
            flag = 0;
            unsigned j;
            for (j = 0; j < (unsigned)fn_8007F84C__FP13Unk8007F198_B(sc); j++) {
                if (fn_8007F7D0__FP13Unk8007F198_BUi(sc, j) == id) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1)
            fn_8055FF28(id, self->m8, i);
    }
}

extern "C" DB_OVERLAY void fn_8055440C()
{
}

extern "C" DB_OVERLAY void fn_80554410(Db80554540_S* self, int mode)
{
    Unk8007B2B0_Screen* sc = (Unk8007B2B0_Screen*)lbl_8061930C;
    unsigned i = 0;
    unsigned n = sc->fn_8007B2B0();
    int g = fn_8007F9B4((Unk8007F198_C*)sc);
    for (; i < n; i++) {
        fn_80400CE4(0);
        if (sc->fn_8007B648(0xE, i) != 0) {
            int flag = 1;
            int id = sc->fn_8007B2FC(i);
            if (mode == 0) {
                unsigned j;
                for (j = 0; j < (unsigned)fn_8007F84C__FP13Unk8007F198_B(sc); j++) {
                    if (id == fn_8007F7D0__FP13Unk8007F198_BUi(sc, j)) {
                        flag = 0;
                        break;
                    }
                }
            } else if (mode == 1) {
                flag = 0;
                unsigned j;
                for (j = 0; j < (unsigned)fn_8007F84C__FP13Unk8007F198_B(sc); j++) {
                    if (id == fn_8007F7D0__FP13Unk8007F198_BUi(sc, j)) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1)
                fn_80554540(self, id, g);
        }
    }
}

extern "C" DB_OVERLAY void fn_80554540(Db80554540_S* self, int a, int b)
{
    Unk8007B2B0_Screen* sc = (Unk8007B2B0_Screen*)lbl_8061930C;
    int p0 = sc->fn_8007B320(0, a);
    int p1 = sc->fn_8007B320(1, a);
    int p2 = sc->fn_8007B320(2, a);
    int p3 = sc->fn_8007B320(3, a);
    fn_80553358(self->mC, p0, b);
    fn_80553388(self->mC);
    fn_80553358(self->mC, p1, b);
    fn_80553388(self->mC);
    fn_80553358(self->mC, p2, b);
    fn_80553388(self->mC);
    fn_80553358(self->mC, p3, b);
    fn_80553388(self->mC);
}
