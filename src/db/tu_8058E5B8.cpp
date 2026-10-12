/*
 * Database overlay code, .database_codeoverlay 0x8058E5B8-0x805902E0 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_80584CBC.h"

extern "C" void fn_805942A8(Db80593CD0_Data* self);
extern "C" char* fn_8058F1F0(char* p, int k);
extern "C" char* fn_8058F11C(char* p, int k);
extern "C" void fn_8058F7E8(Db8058F62C_P* self, int a, Unk80070DDC_Stream* io);
extern "C" void fn_8058F5EC(char* self, int a, Unk80070DDC_Stream* io);
extern "C" void fn_8058FD40(Db8058F924_L* self, int a, Unk80070DDC_Stream* io);
extern "C" void fn_80590288(Db8058F924_L* self, int a, Unk80070DDC_Stream* io);
extern const char lbl_80683B28[];
extern "C" void fn_8058F774(Db8058F62C_P* self);
extern "C" int fn_8058F588(Db8058F62C_V* self, int* base, int i);
extern const char lbl_80600AAC[];
extern "C" void fn_8058F550(Db8058F62C_V* self);
extern const char lbl_80683AD8[];
extern const char lbl_806839F0[];
extern "C" Db80593CD0_P* fn_80593CD0(Db80593CD0_P* self, Db805937A4_Mgr* m, int b, int n, int c, float f);
extern "C" float fn_80594100(Db80593CD0_Data* self, int i, int n);
extern const char lbl_80683958[];
extern "C" Db80593CD0_Ent* fn_80594240(Db80593CD0_Data* self, int i);
extern "C" int fn_80593E7C(Db80593CD0_Data* self, int i);
extern "C" void fn_80593F30(Db80593CD0_Data* self, int i, int n, float f0, float f1);
extern "C" void fn_8059403C(Db80593CD0_Data* self, int i, int n);
extern "C" void fn_80594148(Db80593CD0_Data* self, int a, Unk80070DDC_Stream* io);
extern const char lbl_80683870[];
extern "C" void fn_80593DD8(Db80593CD0_P* self, int chrg);
extern "C" void fn_8058FBCC(Db8058F924_L* self, int i, float f0, float f1);
extern "C" void fn_8058FC68(Db8058F924_L* self, int i);
extern "C" void fn_8058FCD0(Db8058F924_L* self);
extern "C" void fn_8058FD98(Db8058F924_L* self);
extern "C" Db8058F924_P* fn_8058FAF4(Db8058F924_P* self, Db805937A4_Mgr* m, int b, int c, float f);
extern "C" Db80593CD0_P* fn_8058FDCC(Db80593CD0_P* self, Db805937A4_Mgr* m, int c, float f);
extern int* lbl_80622DD0;
extern const float lbl_80600ABC;
extern "C" void fn_80594250(Db80593CD0_Data* self, int i, int a, float f0, float f1, int b, int c); /* float position from the callers' schedule */
extern const char lbl_80683908[];

inline void DbLimit(Db8058F62C_V* o, int n)
{
    if (n < o->v10())
        o->m8 = n;
}

inline Db8058F924_V* DbMake(Db805937A4_Mgr* m, int c)
{
    void* p = operator new(0x20, 0);
    return (Db8058F924_V*)fn_8058FDCC((Db80593CD0_P*)p, m, c, 0.5f);
}

extern "C" DB_OVERLAY void fn_8058EF94(Db8058F08C_S* self)
{
    self->m42C = 1;
    int k = 0;
    do {
        Db8058F62C_V* o = (Db8058F62C_V*)fn_8058F11C((char*)self, k);
        k++;
        o->v28();
    } while (k <= 12);
    DbLimit((Db8058F62C_V*)((char*)self + 0x134), 1);
    DbLimit((Db8058F62C_V*)((char*)self + 0x17C), 2);
    k = 0;
    do {
        Db8058F924_V* o = (Db8058F924_V*)fn_8058F1F0((char*)self, k);
        k++;
        o->v80();
    } while (k <= 5);
    self->m430 = 0;
}

extern "C" DB_OVERLAY void fn_8058F08C(Db8058F08C_S* s)
{
    s->m434 = 0;
    s->m42C = 0;
}

extern "C" DB_OVERLAY void fn_8058F09C(Db8058F08C_S* self)
{
    if (self->m430 == 0) {
        int k = 0;
        while (1) {
            Db8058F924_V* o = (Db8058F924_V*)fn_8058F1F0((char*)self, k);
            if (o->v50() != -1)
                break;
            k++;
            if (k > 5) {
                self->m430 = 1;
                break;
            }
        }
    }
}

extern "C" DB_OVERLAY void fn_8058F114(Db8058F08C_S* s, int v)
{
    s->m434 = v;
}

extern "C" DB_OVERLAY char* fn_8058F11C(char* p, int k)
{
    switch (k) {
    case 0:
        return p;
    case 1:
        return p + 0x80;
    case 2:
        return p + 0xA4;
    case 3:
        return p + 0xC8;
    case 4:
        return p + 0xEC;
    case 5:
        return p + 0x110;
    case 6:
        return p + 0x134;
    case 7:
        return p + 0x158;
    case 8:
        return p + 0x17C;
    case 9:
        return p + 0x1A0;
    case 10:
        return p + 0x1C4;
    case 11:
        return p + 0x1E8;
    case 12:
        return p + 0x20C;
    }
    return p;
}

extern "C" DB_OVERLAY char* fn_8058F1F0(char* p, int k)
{
    switch (k) {
    case 0:
        return p + 0x230;
    case 1:
        return p + 0x370;
    case 2:
        return p + 0x270;
    case 3:
        return p + 0x2B0;
    case 4:
        return p + 0x2F0;
    case 5:
        return p + 0x330;
    }
    return p + 0x230;
}

extern "C" DB_OVERLAY void fn_8058F260(char* self, int a, Unk80070DDC_Stream* io)
{
    fn_8058F7E8((Db8058F62C_P*)self, a, io);
    fn_8058F5EC((char*)self + 0x80, a, io);
    fn_8058F5EC((char*)self + 0xA4, a, io);
    fn_8058F5EC((char*)self + 0xC8, a, io);
    fn_8058F5EC((char*)self + 0xEC, a, io);
    fn_8058F5EC((char*)self + 0x110, a, io);
    fn_8058F5EC((char*)self + 0x134, a, io);
    fn_8058F5EC((char*)self + 0x158, a, io);
    fn_8058F5EC((char*)self + 0x17C, a, io);
    fn_8058F5EC((char*)self + 0x1A0, a, io);
    fn_8058F5EC((char*)self + 0x1C4, a, io);
    fn_8058F5EC((char*)self + 0x1E8, a, io);
    fn_8058F5EC((char*)self + 0x20C, a, io);
    fn_8058FD40((Db8058F924_L*)((char*)self + 0x230), a, io);
    fn_8058FD40((Db8058F924_L*)((char*)self + 0x270), a, io);
    fn_8058FD40((Db8058F924_L*)((char*)self + 0x2B0), a, io);
    fn_8058FD40((Db8058F924_L*)((char*)self + 0x2F0), a, io);
    fn_8058FD40((Db8058F924_L*)((char*)self + 0x330), a, io);
    fn_80590288((Db8058F924_L*)(self + 0x370), a, io);
    io->v08(a, self + 0x42C, 4);
    io->v08(a, self + 0x430, 4);
    io->v08(a, self + 0x434, 4);
}

extern "C" DB_OVERLAY float fn_8058F420(char* self)
{
    float a = 0.03448275849223137f;
    float b = 0.0f;
    float c;
    float lo;
    float x;
    float hi;
    int cnt = 0;
    int k = 0;
    do {
        Db8058F924_V* o = (Db8058F924_V*)fn_8058F1F0(self, k);
        if (o->v48() > 0)
            cnt += o->v48();
        k++;
    } while (k <= 5);
    b = cnt * 0.03448275849223137f;
    x = b;
    hi = 1.0f;
    c = x <? hi;
    lo = 0.0f;
    b = lo >? c;
    return b;
}

extern "C" DB_OVERLAY void fn_8058F550(Db8058F62C_V* self)
{
    self->v38(0);
}

extern "C" DB_OVERLAY int fn_8058F588(Db8058F62C_V* self, int* base, int i)
{
    if (i >= 0 && i < self->v10())
        return base[i];
    return 0;
}

extern "C" DB_OVERLAY void fn_8058F5EC(char* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self + 8, 4);
}

extern "C" DB_OVERLAY Db8058F62C_P* fn_8058F62C(Db8058F62C_P* self)
{
    self->m0 = 0;
    self->m4 = 0;
    self->m8 = 0;
    self->mC = lbl_80683B28;
    fn_8058F774(self);
    for (int i = 0; i < 17; i++)
        self->m3C[i] = 0;
    return self;
}

extern "C" DB_OVERLAY void fn_8058F698(Db8058F62C_P* self, const unsigned short* s)
{
    fn_80403144(self->m10, s);
    self->m38 = 0;
}

extern "C" DB_OVERLAY void fn_8058F6D0(Db8058F62C_L* self, int v)
{
    if (self->v10() <= 0x10) {
        self->m3C[self->v10()] = v;
        self->m4++;
    }
}

extern "C" DB_OVERLAY int fn_8058F74C(Db8058F62C_L* self, int i)
{
    return fn_8058F588(self, self->m3C, i);
}

extern "C" DB_OVERLAY void fn_8058F774(Db8058F62C_P* self)
{
    fn_804031BC(self->m10, lbl_80600AAC);
    self->m36 = 0;
}

extern "C" DB_OVERLAY void fn_8058F7B4(Db8058F62C_P* self)
{
    fn_8058F774(self);
    fn_8058F550((Db8058F62C_V*)self);
}

extern "C" DB_OVERLAY void fn_8058F7E8(Db8058F62C_P* self, int a, Unk80070DDC_Stream* io)
{
    fn_8058F5EC((char*)self, a, io);
    io->v08(a, self->m10, 0x2A);
}

extern "C" DB_OVERLAY void fn_8058F840(Db8058F840_P* self)
{
    self->m0 = 0;
    self->m4 = 0;
    self->m8 = 0;
    self->mC = lbl_80683AD8;
    for (int i = 0; i < 4; i++)
        self->m14[i] = 0;
}

extern "C" DB_OVERLAY void fn_8058F880(Db8058F840_L* self, int v)
{
    if (self->v10() <= 3) {
        self->m14[self->v10()] = v;
        self->m4++;
    }
}

extern "C" DB_OVERLAY int fn_8058F8FC(Db8058F840_L* self, int i)
{
    return fn_8058F588((Db8058F62C_V*)self, self->m14, i);
}

extern "C" DB_OVERLAY Db8058F924_P* fn_8058F924(Db8058F924_P* self, Db805937A4_Mgr* m, int b, short c, float f)
{
    fn_80593CD0(self, m, b, 6, c, f);
    self->m1C = lbl_806839F0;
    int* p = self->m20;
    int n = 6;
    do {
        *p = 0;
        p++;
        n--;
    } while (n != 0);
    self->m38 = 0;
    return self;
}

/* near-miss (10 slots): retail keeps the scale constant in f12 and stores it to the stack just before the call. */
extern "C" DB_OVERLAY void fn_8058F990(Db8058F924_L* self, int id, int v, int c, float f0, float f1)
{
    if (self->m38 < *lbl_80622DD0) {
        f0 *= lbl_80600ABC;
        f1 *= lbl_80600ABC;
        float t = lbl_80600ABC;
        fn_80594250(self, self->m38, id, f0, f1, 1, c);
        self->m20[self->m38] = v;
        self->m38++;
    }
}

extern "C" DB_OVERLAY float fn_8058FA38(Db80593CD0_Data* self, int i)
{
    return fn_80594100(self, i, 1);
}

extern "C" DB_OVERLAY int fn_8058FA5C(Db8058FA5C_L* l, int i)
{
    if (i >= 0 && i < l->m38)
        return 1;
    return 0;
}

extern "C" DB_OVERLAY int* fn_8058FA7C(Db8058F924_L* self, int i)
{
    if (fn_8058FA5C((Db8058FA5C_L*)self, i) != 0)
        return (int*)((char*)self + (i * 4 + 0x20));
    return self->m20;
}

extern "C" DB_OVERLAY int fn_8058FAC8(Db8058FA5C_L* l)
{
    return l->m3C;
}

extern "C" DB_OVERLAY int fn_8058FAD0(Db8058FA5C_L* l)
{
    int n = l->m3C + 1;
    if (n >= l->m38)
        return -1;
    return n;
}

extern "C" DB_OVERLAY Db8058F924_P* fn_8058FAF4(Db8058F924_P* self, Db805937A4_Mgr* m, int b, int c, float f)
{
    fn_8058F924(self, m, b, c, f);
    self->m3C = 0;
    self->m1C = lbl_80683958;
    return self;
}

extern "C" DB_OVERLAY float fn_8058FB44(Db8058F924_L* self, int i)
{
    if (fn_8058FA5C((Db8058FA5C_L*)self, i)) {
        int k = 0;
        float s = 0.0f;
        if (k <= i) {
            do {
                Db80593CD0_Ent* e = fn_80594240(self, k);
                k++;
                s += e->m4;
            } while (k <= i);
        }
        return s;
    }
    return 0.0f;
}

extern "C" DB_OVERLAY void fn_8058FBCC(Db8058F924_L* self, int i, float f0, float f1)
{
    if (fn_8058FA5C((Db8058FA5C_L*)self, i)) {
        int ok = 0;
        if (i == 0) {
            ok = fn_80593E7C(self, 0) == 0;
        } else if (i == self->m3C + 1) {
            ok = 1;
        }
        if (ok) {
            self->m3C = i;
            fn_80593F30(self, i, 1, f0, f1);
        }
    }
}

extern "C" DB_OVERLAY void fn_8058FC68(Db8058F924_L* self, int i)
{
    if (fn_8058FA5C((Db8058FA5C_L*)self, i) && i != 0 && i == self->m3C) {
        fn_8059403C(self, i, 1);
        self->m3C--;
    }
}

extern "C" DB_OVERLAY void fn_8058FCD0(Db8058F924_L* self)
{
    self->v28();
    self->v60(0, -1.0f, -1.0f);
    self->m3C = 0;
}

extern "C" DB_OVERLAY void fn_8058FD40(Db8058F924_L* self, int a, Unk80070DDC_Stream* io)
{
    fn_80594148(self, a, io);
    io->v08(a, &self->m3C, 4);
}

extern "C" DB_OVERLAY void fn_8058FD98(Db8058F924_L* self)
{
    fn_805942A8(self);
    self->m3C = -1;
}

extern "C" DB_OVERLAY Db80593CD0_P* fn_8058FDCC(Db80593CD0_P* self, Db805937A4_Mgr* m, int c, float f)
{
    fn_80593CD0(self, m, 0xC, 5, c, f);
    self->m1C = lbl_80683908;
    fn_80594250(self, 0, 0x1612, 0.0f, 0.0f, 0x3E80, 1);
    fn_80594250(self, 1, 0x1613, 0.0f, 0.0f, 0x5DC0, 1);
    fn_80594250(self, 2, 0x1614, 0.0f, 0.0f, 0x7D0, 1);
    fn_80594250(self, 3, 0x1615, 0.0f, 0.0f, 0x59D8, 1);
    fn_80594250(self, 4, 0x1616, 0.0f, 0.0f, 0x32, 1);
    return self;
}

extern "C" DB_OVERLAY void fn_8058FEC0(Db80593CD0_Data* self)
{
    fn_805942A8(self);
}

extern "C" DB_OVERLAY Db8058F924_P* fn_8058FEE0(Db8058F924_P* self, Db805937A4_Mgr* m, int unused, int c, float f)
{
    fn_8058FAF4(self, m, 3, c, f);
    self->m40 = 0;
    self->m1C = lbl_80683870;
    self->m40 = DbMake(m, c);
    for (int r = 0; r < 6; r++)
        for (int j = 0; j < 5; j++)
            self->m44[r][j] = 0;
    self->m44[0][0] = 0x2EE0;
    self->m44[1][2] = 0x7D0;
    self->m44[0][1] = 0x1F40;
    self->m44[1][1] = 0xBB8;
    self->m44[3][3] = 0x1770;
    self->m44[2][3] = 0x1F40;
    self->m44[4][0] = 0xFA0;
    self->m44[3][1] = 0xBB8;
    self->m44[3][4] = 0x32;
    self->m44[4][1] = 0x1770;
    self->m44[5][1] = 0xFA0;
    self->m44[5][3] = 0x2328;
    return self;
}

extern "C" DB_OVERLAY void fn_8058FFE4(Db8058F924_P* self, int chrg)
{
    Db8058F924_V* sub = self->m40;
    self->m1C = lbl_80683870;
    if (sub) {
        sub->v08(3);
        self->m40 = 0;
    }
    self->m1C = lbl_806839F0;
    fn_80593DD8(self, chrg);
}

extern "C" DB_OVERLAY void fn_80590064(Db8058F924_L* self, int i, float f0, float f1)
{
    fn_8058FBCC(self, i, f0, f1);
    int k = 0;
    do {
        int v = self->m44[i][k];
        if (v > 0)
            self->m40->v10(k, v, -1.0f, -1.0f);
        k++;
    } while (k < 5);
}

extern "C" DB_OVERLAY void fn_80590104(Db8058F924_L* self, int i)
{
    fn_8058FC68(self, i);
    int k = 0;
    do {
        int v = self->m44[i][k];
        if (v > 0)
            self->m40->v18(k, v);
        k++;
    } while (k < 5);
}

extern "C" DB_OVERLAY int fn_80590188(Db8058F924_L* self, int i)
{
    return fn_80593E7C(self->m40, i);
}

extern "C" DB_OVERLAY int fn_805901AC(Db8058F924_L* self, int k)
{
    int sum = 0;
    for (int r = 0; r <= k; r++)
        for (int j = 0; j < 5; j++)
            sum += self->m44[r][j];
    return sum;
}

extern "C" DB_OVERLAY void fn_805901F8(Db8058F924_L* self)
{
    self->v28();
    fn_8058FCD0(self);
}

extern "C" DB_OVERLAY void fn_80590240(Db8058F924_L* self)
{
    fn_8058FD98(self);
    self->m40->v28();
}

extern "C" DB_OVERLAY void fn_80590288(Db8058F924_L* self, int a, Unk80070DDC_Stream* io)
{
    fn_8058FD40(self, a, io);
    self->m40->v30(a, (int)io);
}
