/*
 * Database overlay code, .database_codeoverlay 0x805942E0-0x80596D88 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_80584CBC.h"

struct DbQuad { int m0; int m4; int m8; int mC; };

struct DbQuadTab { char pad[0x20]; DbQuad q[0x52]; int m540; };

struct Db80619948_O { char pad[0x28]; void* m28; };

struct Db80594A10_P : Db805942E0_P { int m18; };

struct Db805951B8_T { char pad[0x1C]; const void* m1C; int a[6][14]; };

unsigned fn_8007FBC0(Unk8007F198_C* self, int a, int c);
extern "C" void fn_805942A8(Db80593CD0_Data* self);
extern const char lbl_806845F8[];
extern "C" int fn_80593E7C(Db80593CD0_Data* self, int i);
extern "C" int fn_8059377C(Db805937A4_Mgr* m, int id);
extern "C" int fn_8059394C(Db805937A4_Mgr* m, int id);
extern "C" Db80593CD0_Ent* fn_80594240(Db80593CD0_Data* self, int i);
extern Unk8007A4DC_Screen* lbl_8061930C;
extern "C" void fn_80594148(Db80593CD0_Data* self, int a, Unk80070DDC_Stream* io);
extern "C" void fn_80593F30(Db80593CD0_Data* self, int i, int n, float f0, float f1);
extern "C" unsigned char fn_80593880(Db805937A4_Mgr* m, int id);
extern "C" int fn_800A3C98(void* o, int a, int b);
int fn_8007F7D0(Unk8007F198_B* self, unsigned i);
extern "C" Db800B555C_Obj* fn_800B555C();
extern "C" int fn_800B5758(Db800B555C_Obj* o);
extern "C" int fn_800B5520(int a);
extern "C" void fn_805950A0(Db805942E0_Data* self, int a);
extern "C" float fn_805938E8(Db805937A4_Mgr* m, int id);
extern "C" int fn_8056AC44(void* o, int a, int b);
extern "C" int fn_8056A5F4(void* o, int a, int b, int c);
extern "C" float fn_800A5A1C(void* o, int x);
extern const char lbl_80682830[];
extern const char lbl_80682CC8[];
extern const char lbl_806845B0[];
extern const char lbl_806828C8[];
extern const char lbl_80682C50[];
extern "C" Db80593CD0_P* fn_80593CD0(Db80593CD0_P* self, Db805937A4_Mgr* m, int b, int n, int c, float f);
extern "C" void fn_80594250(Db80593CD0_Data* self, int i, int a, int b, int c, float f0, float f1);
extern const char lbl_80682878[];

extern "C" int fn_8056A2F8(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern "C" int fn_8007FB98__FP13Unk8007F198_Ciii(void* p, int a, int b, int c);

extern "C" int fn_8056A2F8(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern "C" int fn_8007FB98__FP13Unk8007F198_Ciii(void* p, int a, int b, int c);

struct Db805945A4_Obj : Db80593CD0_P {
    int w[9][13];
};
extern const float lbl_80600CA4;
extern const float lbl_80600CA8;
extern const float lbl_80600CAC;
extern const float lbl_80600CB0;
extern const float lbl_80600CB4;
extern const float lbl_80600CB8;
extern float lbl_80600CBC;
extern float lbl_80600CC0;
extern float lbl_80600CC4;
extern char lbl_80682910[];
/* forward declarations (definitions are in address order) */
extern "C" Db805942E0_P* fn_805942E0(Db805942E0_P* self, Db805937A4_Mgr* m, int n, int x);
extern "C" void fn_805943A0(Db805942E0_P* self, int chrg);
extern "C" float fn_80594418(Db805942E0_Data* self, int i);
extern "C" void fn_80594428(Db805942E0_Data* self, int i, float f);
extern "C" void fn_80594448(Db805942E0_Data* self, int a, Unk80070DDC_Stream* io);
extern "C" Db805942E0_Ent* fn_805944C0(Db805942E0_Data* self, int i);
extern "C" void fn_805944D0(Db805942E0_Data* self, int i, int a, float f0, float f1, float f2, float f3);
extern "C" void fn_80594538(Db805942E0_V* self);
extern "C" Db805945A4_Obj* fn_805945A4(Db805945A4_Obj* self, Db805937A4_Mgr* m, int c, float f);
extern "C" void fn_805947F0(Db80593CD0_Data* self);
extern "C" int fn_80594810(Db80593CD0_Data* self, int k);
extern "C" int fn_80594880(Db80593CD0_Data* self, int k, int r);
extern "C" int fn_805948D0(char* self, int k, int r);
extern "C" float fn_805948E8(Db80593CD0_Data* self);
extern "C" Db80594A10_P* fn_80594A10(Db80594A10_P* self, int a, Db805937A4_Mgr* m, int x);
extern "C" void fn_80594FC4(Db805942E0_Data* self, int i);
extern "C" void fn_80595044(Db805942E0_Data* self);
extern "C" void fn_805950A0(Db805942E0_Data* self, int key);
extern "C" Db805951B8_T* fn_805951B8(Db805951B8_T* self, Db805937A4_Mgr* m, int x, float f);
extern "C" void fn_80595378(Db80593CD0_Data* self);
extern "C" int fn_80595398(Db805951B8_T* self, int idx);
extern "C" int fn_80595408(Db80593CD0_Data* self, int k, int r);
extern "C" int fn_80595458(char* self, int k, int r);
extern "C" float fn_80595470(Db80593CD0_Data* self);
extern "C" Db80594A10_P* fn_80595598(Db80594A10_P* self, int a, Db805937A4_Mgr* m, int x);
extern "C" Db805942E0_P* fn_80595B64(Db805942E0_P* self, Db805937A4_Mgr* m, int x);
extern "C" int fn_80595EEC(Db805942E0_V* self, int i);
extern "C" Db805942E0_P* fn_80595F8C(Db805942E0_P* self, Db805937A4_Mgr* m, int x);
extern "C" void fn_8059603C();
extern "C" DbQuadTab* fn_80596040(DbQuadTab* self, Db805937A4_Mgr* m, int x);
extern "C" void fn_805962F4(Db8058F924_L* self);
extern "C" void fn_8059633C(DbQuadTab* self);
extern "C" float fn_80596388(Db805937A4_Mgr** self, int id);
extern "C" int fn_80596460(Db805937A4_Mgr** self, int id);
extern "C" void fn_805964B4(Db805937A4_Mgr** self, int id);
extern "C" int fn_80596538(DbQuadTab* self, int a);
extern "C" DbQuad* fn_805965DC(DbQuadTab* self, int a);
extern "C" void fn_80596688(DbQuadTab* self, int a, int b, int c);
extern "C" void fn_80596748(float a, float b);
extern "C" void fn_8059675C();
extern "C" void fn_80596760(char* self, int a, Unk80070DDC_Stream* io);
extern "C" int fn_80596BAC(DbQuadTab* self, int a, int b);
extern "C" int fn_80596C7C(DbQuadTab* self, int a, int b);

extern "C" DB_OVERLAY Db805942E0_P* fn_805942E0(Db805942E0_P* self, Db805937A4_Mgr* m, int n, int x)
{
    self->m0 = m;
    self->mC = n;
    self->m8 = 0;
    self->m10 = 0;
    self->m14 = lbl_806845F8;
    self->m4 = x;
    self->m10 = (float*)operator new[](n * 4, 0);
    if (self->m8 == 0)
        self->m8 = new (0) Db805942E0_Ent[n];
    return self;
}

extern "C" DB_OVERLAY void fn_805943A0(Db805942E0_P* self, int chrg)
{
    self->m14 = lbl_806845F8;
    if (self->m10) {
        delete[] self->m10;
        self->m10 = 0;
    }
    if (self->m8) {
        delete[] self->m8;
        self->m8 = 0;
    }
    if (chrg & 1)
        delete self;
}

extern "C" DB_OVERLAY float fn_80594418(Db805942E0_Data* self, int i)
{
    return self->m10[i];
}

extern "C" DB_OVERLAY void fn_80594428(Db805942E0_Data* self, int i, float f)
{
    self->m10[i] = f;
}

extern "C" DB_OVERLAY void fn_80594448(Db805942E0_Data* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, &self->mC, 4);
    io->v08(a, self->m10, self->mC * 4);
}

extern "C" DB_OVERLAY Db805942E0_Ent* fn_805944C0(Db805942E0_Data* self, int i)
{
    return self->m8 + i;
}

extern "C" DB_OVERLAY void fn_805944D0(Db805942E0_Data* self, int i, int a, float f0, float f1, float f2, float f3)
{
    self->m8[i].m0 = f0;
    self->m8[i].m4 = f1;
    self->m8[i].m8 = f2;
    self->m8[i].mC = f3;
    self->m8[i].m10 = a;
}

extern "C" DB_OVERLAY void fn_80594538(Db805942E0_V* self)
{
    int i = 0;
    while (i < self->mC) {
        Db805942E0_Ent* p = self->v30(i);
        int k = i;
        i++;
        fn_80594428(self, k, p->m0);
    }
}

/* near-miss (95.2%): the 19 constant stores; retail loads the 11 distinct constants in the order 9100, 13000, 46000, 9600, 13200,
   32000, ... and so reuses different registers. An 18-minute hill climb over the store order did not reach 0 differences. */
extern "C" DB_OVERLAY Db805945A4_Obj* fn_805945A4(Db805945A4_Obj* self, Db805937A4_Mgr* m, int c, float f)
{
    fn_80593CD0(self, m, 10, 9, c, f);
    self->m1C = lbl_80682910;
    for (int r = 0; r < 9; r++)
        for (int j = 0; j < 13; j++)
            self->w[r][j] = 0;
    self->w[8][12] = 0xB3B0;
    self->w[3][5] = 0x238C;
    self->w[4][2] = 0x32C8;
    self->w[7][2] = 0x32C8;
    self->w[6][4] = 0x238C;
    self->w[5][9] = 0x32C8;
    self->w[5][5] = 0x238C;
    self->w[2][4] = 0x238C;
    self->w[8][7] = 0x3390;
    self->w[7][8] = 0x7D00;
    self->w[8][11] = 0x2580;
    self->w[8][3] = 0x1964;
    self->w[6][10] = 0x4E20;
    self->w[1][1] = 0xFA0;
    self->w[7][11] = 0x2580;
    self->w[5][0] = 0x3E80;
    self->w[0][6] = 0xA28;
    self->w[6][0] = 0x3E80;
    self->w[5][6] = 0xA28;
    fn_805947F0(self);
    fn_80594250(self, 0, 0x5778, 4, 1, lbl_80600CA4, lbl_80600CA4);
    fn_80594250(self, 1, 0x5779, 4, 1, lbl_80600CA8, lbl_80600CAC);
    fn_80594250(self, 3, 0x5776, 4, 1, lbl_80600CB0, lbl_80600CB0);
    fn_80594250(self, 2, 0x5775, 4, 1, lbl_80600CB4, lbl_80600CB4);
    fn_80594250(self, 4, 0x5777, 4, 1, lbl_80600CB8, lbl_80600CB8);
    fn_80594250(self, 5, 0x5773, 1, 1, lbl_80600CBC, lbl_80600CC0);
    fn_80594250(self, 6, 0x5772, 1, 1, lbl_80600CBC, lbl_80600CC0);
    fn_80594250(self, 7, 0x5770, 1, 1, lbl_80600CC4, lbl_80600CC0);
    fn_80594250(self, 8, 0x5771, 1, 1, lbl_80600CC4, lbl_80600CC4);
    return self;
}

extern "C" DB_OVERLAY void fn_805947F0(Db80593CD0_Data* self)
{
    fn_805942A8(self);
}

/* near-miss (4 slots): retail copies the zero of sum into the counter (mr r31,r29) and sets r29 before the arg moves. */
extern "C" DB_OVERLAY int fn_80594810(Db80593CD0_Data* self, int k)
{
    int sum = 0;
    int r = 0;
    int off = 0;
    do {
        int t = fn_80593E7C(self, r);
        r++;
        char* b = (char*)self + 0x20;
        int o = k * 4 + off;
        int v = *(int*)(b + o);
        off += 0x34;
        sum += t * v;
    } while (r <= 8);
    return sum;
}

extern "C" DB_OVERLAY int fn_80594880(Db80593CD0_Data* self, int k, int r)
{
    int t = fn_80593E7C(self, r);
    char* b = (char*)self + 0x20;
    int o = k * 4 + r * 0x34;
    return *(int*)(b + o) * t;
}

extern "C" DB_OVERLAY int fn_805948D0(char* self, int k, int r)
{
    char* b = self + 0x20;
    int o = k * 4 + r * 0x34;
    return *(int*)(b + o);
}

extern "C" DB_OVERLAY float fn_805948E8(Db80593CD0_Data* self)
{
    float a = 0.0f;
    float u;
    float c;
    float lo;
    float x;
    float hi;
    int sumA = 0;
    int sumB = 0;
    int k = 0;
    do {
        sumB += fn_80594240(self, k)->m8;
        if (fn_80593E7C(self, k) > 0)
            sumA += fn_80593E7C(self, k);
        k++;
    } while (k <= 8);
    a = (float)sumA / (float)sumB;
    x = a;
    hi = 1.0f;
    c = x <? hi;
    lo = 0.0f;
    a = lo >? c;
    return a;
}

extern "C" DB_OVERLAY Db80594A10_P* fn_80594A10(Db80594A10_P* self, int a, Db805937A4_Mgr* m, int x)
{
    fn_805942E0(self, m, 13, x);
    self->m18 = a;
    self->m14 = lbl_806845B0;
    fn_805944D0(self, 0, 0x5762, 3.5f, 0.5f, 9.0f, 1.0f);
    fn_805944D0(self, 1, 0x5763, 4.0f, 0.5f, 9.0f, 1.0f);
    fn_805944D0(self, 2, 0x5764, 3.5f, 0.5f, 9.0f, 1.0f);
    fn_805944D0(self, 3, 0x5765, 3.5f, 0.5f, 9.0f, 1.0f);
    fn_805944D0(self, 4, 0x5766, 3.0f, 0.5f, 9.0f, 1.0f);
    fn_805944D0(self, 5, 0x5767, 4.5f, 0.5f, 9.0f, 1.0f);
    fn_805944D0(self, 6, 0x5768, 4.0f, 0.5f, 9.0f, 1.0f);
    fn_805944D0(self, 7, 0x5769, 6.0f, 0.5f, 9.0f, 1.0f);
    fn_805944D0(self, 8, 0x576A, 5.5f, 0.5f, 9.0f, 1.0f);
    fn_805944D0(self, 9, 0x576B, 4.0f, 0.5f, 9.0f, 1.0f);
    fn_805944D0(self, 0xA, 0x576C, 5.0f, 0.5f, 9.0f, 1.0f);
    fn_805944D0(self, 0xB, 0x576D, 4.5f, 0.5f, 9.0f, 1.0f);
    fn_805944D0(self, 0xC, 0x576F, 4.5f, 0.5f, 9.0f, 1.0f);
    fn_80595044(self);
    return self;
}

struct Db80594C2C_Rec {
    float a;
    float b;
    int c;
};
struct Db80594C2C_Obj : Db805942E0_V {
    Db80593CD0_Data* m18;
};
extern Db80594C2C_Rec lbl_80601B70[];
extern Db80594C2C_Rec lbl_80601BE8[];
extern float lbl_806E0328[];
extern "C" int fn_8040ABA0();
extern "C" int fn_80591A50(Db805919E8_M* m);
extern "C" int fn_80592E04(Db805937A4_Mgr* m, int i);
extern "C" void fn_80591B8C(Db805919E8_M* m, int x, int j, int a3, int a4, int flag);

inline float Db80594C2C_At(float* b, int o)
{
    return *(float*)((char*)b + o);
}
extern "C" DB_OVERLAY void fn_80594C2C(Db80594C2C_Obj* self)
{
    int i = 0;
    Db805919E8_M* mgr = (Db805919E8_M*)self->m0;
    int off = 0;
    int total = fn_8059394C((Db805937A4_Mgr*)mgr, fn_80592E04((Db805937A4_Mgr*)mgr, fn_80591A50(mgr)));
    do {
        int cap = fn_80594810(self->m18, i);
        if (cap > 0) {
            int v = 0;
            float d = fn_80594418(self, i) - self->v30(i)->m0;
            if (d == 0.0f) {
                v = (int)((float)total * Db80594C2C_At(lbl_806E0328, off));
            } else if (!(d <= 0.0f)) {
                int idx = ((int)(d + d) - 1) * 12;
                Db80594C2C_Rec* rec = (Db80594C2C_Rec*)((char*)lbl_80601BE8 + idx);
                float s = Db80594C2C_At(lbl_806E0328, off) * (float)total;
                float t = (float)(fn_8040ABA0() % 100);
                t = t * 0.01f;
                t = t * rec->a;
                v = (int)(s - (Db80594C2C_At(lbl_806E0328, off) * (t + rec->b + (float)rec->c) * (float)total));
            } else if (!(d >= 0.0f)) {
                int idx = ((int)(d * -2.0f) - 1) * 12;
                Db80594C2C_Rec* rec = (Db80594C2C_Rec*)((char*)lbl_80601B70 + idx);
                float t = (float)(fn_8040ABA0() % 100);
                t = t * 0.01f;
                t = t * rec->a;
                v = (int)(Db80594C2C_At(lbl_806E0328, off) * (t + rec->b + (float)rec->c) * (float)total);
            }
            int w = v;
            if (w > cap)
                w = cap;
            v = w;
            Db805919E8_M* m = (Db805919E8_M*)self->m0;
            fn_80594418(self, i);
            fn_80591B8C(m, 1, i, cap, v, 0);
        }
        i++;
        off += 4;
    } while (i <= 12);
}

extern "C" DB_OVERLAY void fn_80594FC4(Db805942E0_Data* self, int i)
{
    if (fn_800B5758(fn_800B555C()) && i == 0xC) {
        int t = fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0);
        int u = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B320(0, t);
        fn_805950A0(self, fn_800B5520(u));
    }
    fn_805944C0(self, i);
}

extern "C" DB_OVERLAY void fn_80595044(Db805942E0_Data* self)
{
    int i = 0;
    while (i < self->mC) {
        Db805942E0_Ent* e = fn_805944C0(self, i);
        int k = i;
        i++;
        fn_80594428(self, k, e->m0);
    }
}

extern "C" DB_OVERLAY void fn_805950A0(Db805942E0_Data* self, int key)
{
    int ka[30] = { 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x10, 0x1D, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C };
    int kb[30] = { 0x580D, 0x580E, 0x580F, 0x5810, 0x5811, 0x5812, 0x5813, 0x5814, 0x5815, 0x5816, 0x5817, 0x5818, 0x5819, 0x581A, 0x581B, 0x581C, 0x581D, 0x581E, 0x581F, 0x5820, 0x5821, 0x5822, 0x5823, 0x5824, 0x5825, 0x5826, 0x5827, 0x5828, 0x5829, 0x582A };
    for (int i = 0; i <= 0x1D; i++) {
        if (key == ka[i]) {
            fn_805944D0(self, 0xC, kb[i], 4.5f, 0.5f, 9.0f, 1.0f);
            break;
        }
    }
}

extern "C" DB_OVERLAY Db805951B8_T* fn_805951B8(Db805951B8_T* self, Db805937A4_Mgr* m, int x, float f)
{
    fn_80593CD0((Db80593CD0_P*)self, m, 0xB, 6, x, f);
    self->m1C = lbl_80682878;
    for (int r = 0; r < 6; r++)
        for (int j = 0; j < 14; j++)
            self->a[r][j] = 0;
    *(int*)((char*)self + 0x100) = 0x82;
    *(int*)((char*)self + 0xD8) = 0x294;
    *(int*)((char*)self + 0x108) = 0x82;
    *(int*)((char*)self + 0x104) = 0x140;
    *(int*)((char*)self + 0xD4) = 0x82;
    *(int*)((char*)self + 0xDC) = 0xA28;
    *(int*)((char*)self + 0x154) = 0x514;
    *(int*)((char*)self + 0x158) = 0x3C0;
    *(int*)((char*)self + 0x150) = 0xA28;
    *(int*)((char*)self + 0xB4) = 0x514;
    *(int*)((char*)self + 0xB8) = 0x79E;
    *(int*)((char*)self + 0xBC) = 0x514;
    *(int*)((char*)self + 0x88) = 0x3C0;
    *(int*)((char*)self + 0x54) = 0x294;
    fn_80595378((Db80593CD0_Data*)self);
    fn_80594250((Db80593CD0_Data*)self, 4, 0x583C, 1, 1, 900000.0f, 1000000.0f);
    fn_80594250((Db80593CD0_Data*)self, 3, 0x583D, 1, 1, 500000.0f, 500000.0f);
    fn_80594250((Db80593CD0_Data*)self, 5, 0x583E, 1, 1, 800000.0f, 800000.0f);
    fn_80594250((Db80593CD0_Data*)self, 2, 0x583F, 1, 1, 300000.0f, 300000.0f);
    fn_80594250((Db80593CD0_Data*)self, 1, 0x5840, 1, 1, 200000.0f, 200000.0f);
    fn_80594250((Db80593CD0_Data*)self, 0, 0x5841, 1, 1, 200000.0f, 100000.0f);
    return self;
}

extern "C" DB_OVERLAY void fn_80595378(Db80593CD0_Data* self)
{
    fn_805942A8(self);
}

extern "C" DB_OVERLAY int fn_80595398(Db805951B8_T* self, int idx)
{
    int s = 0;
    int r = 0;
    for (r = s; r <= 5; r++)
        s += fn_80593E7C((Db80593CD0_Data*)self, r) * self->a[r][idx];
    return s;
}

extern "C" DB_OVERLAY int fn_80595408(Db80593CD0_Data* self, int k, int r)
{
    int t = fn_80593E7C(self, r);
    char* b = (char*)self + 0x20;
    int o = k * 4 + r * 0x38;
    return *(int*)(b + o) * t;
}

extern "C" DB_OVERLAY int fn_80595458(char* self, int k, int r)
{
    char* b = self + 0x20;
    int o = k * 4 + r * 0x38;
    return *(int*)(b + o);
}

extern "C" DB_OVERLAY float fn_80595470(Db80593CD0_Data* self)
{
    float a = 0.0f;
    float u;
    float c;
    float lo;
    float x;
    float hi;
    int sumA = 0;
    int sumB = 0;
    int k = 0;
    do {
        sumB += fn_80594240(self, k)->m8;
        if (fn_80593E7C(self, k) > 0)
            sumA += fn_80593E7C(self, k);
        k++;
    } while (k <= 5);
    a = (float)sumA / (float)sumB;
    x = a;
    hi = 1.0f;
    c = x <? hi;
    lo = 0.0f;
    a = lo >? c;
    return a;
}

extern "C" DB_OVERLAY Db80594A10_P* fn_80595598(Db80594A10_P* self, int a, Db805937A4_Mgr* m, int x)
{
    fn_805942E0(self, m, 14, x);
    self->m18 = a;
    self->m14 = lbl_806828C8;
    fn_805944D0(self, 0, 0x582C, 170.0f, 10.0f, 230.0f, 100.0f);
    fn_805944D0(self, 1, 0x582D, 120.0f, 10.0f, 170.0f, 70.0f);
    fn_805944D0(self, 2, 0x582E, 220.0f, 10.0f, 280.0f, 150.0f);
    fn_805944D0(self, 3, 0x582F, 110.0f, 10.0f, 160.0f, 60.0f);
    fn_805944D0(self, 4, 0x5830, 30.0f, 5.0f, 50.0f, 10.0f);
    fn_805944D0(self, 5, 0x5831, 12.0f, 1.0f, 20.0f, 5.0f);
    fn_805944D0(self, 6, 0x5832, 18.0f, 1.0f, 25.0f, 10.0f);
    fn_805944D0(self, 7, 0x5833, 15.0f, 1.0f, 20.0f, 5.0f);
    fn_805944D0(self, 8, 0x5834, 20.0f, 5.0f, 50.0f, 10.0f);
    fn_805944D0(self, 9, 0x5835, 13.0f, 1.0f, 17.0f, 5.0f);
    fn_805944D0(self, 0xA, 0x5836, 5.0f, 1.0f, 10.0f, 3.0f);
    fn_805944D0(self, 0xB, 0x5837, 7.0f, 1.0f, 12.0f, 3.0f);
    fn_805944D0(self, 0xC, 0x5838, 27.0f, 1.0f, 35.0f, 20.0f);
    fn_805944D0(self, 0xD, 0x5839, 22.0f, 1.0f, 30.0f, 15.0f);
    fn_80595044(self);
    return self;
}

extern Db80594C2C_Rec lbl_80601C78[];
extern Db80594C2C_Rec lbl_80601CC8[];
extern int lbl_80601C90[];
extern float lbl_806E035C[];
inline float Db8059581C_At(float* b, int o)
{
    return *(float*)((char*)b + o);
}

inline int Db8059581C_AtI(int* b, int o)
{
    return *(int*)((char*)b + o);
}
extern "C" DB_OVERLAY void fn_8059581C(Db80594C2C_Obj* self)
{
    Db805919E8_M* mgr = (Db805919E8_M*)self->m0;
    int i = 0;
    int off = 0;
    int total = fn_8059394C((Db805937A4_Mgr*)mgr, fn_80592E04((Db805937A4_Mgr*)mgr, fn_80591A50(mgr)));
    float s = 0.0f;
    do {
        int v = 0;
        s = Db8059581C_At(lbl_806E035C, off) * (float)total;
        float d = fn_80594418(self, i) - self->v30(i)->m0;
        int k = (int)(d / self->v30(i)->m4 - 1.0);
        int cap = fn_80595398((Db805951B8_T*)self->m18, i);
        if (cap > 0) {
            if (d == 0.0f) {
                v = (int)(s + 0.5f);
            } else if (!(d >= 0.0f)) {
                Db80594C2C_Rec* rec = (Db80594C2C_Rec*)((char*)lbl_80601C78 + Db8059581C_AtI(lbl_80601C90, off) * 12);
                float t = (float)(fn_8040ABA0() % 100) * (rec->a * 0.01f) + rec->b + (float)rec->c;
                v = (int)(s * t + 0.5f);
            } else if (!(d <= 0.0f)) {
                Db80594C2C_Rec* rb = (Db80594C2C_Rec*)((char*)lbl_80601CC8 + Db8059581C_AtI(lbl_80601C90, off) * 12);
                Db80594C2C_Rec* rec = (Db80594C2C_Rec*)((char*)(k * 24) + (int)rb);
                float t = (float)(fn_8040ABA0() % 100) * (rec->a * 0.01f) + rec->b + (float)rec->c;
                v = (int)(s - s * t + 0.5f);
            }
            int w = v;
            if (w > cap)
                w = cap;
            v = w;
            Db805919E8_M* m = (Db805919E8_M*)self->m0;
            fn_80594418(self, i);
            fn_80591B8C(m, 2, i, cap, v, 0);
        }
        i++;
        off += 4;
    } while (i <= 13);
}

extern "C" DB_OVERLAY Db805942E0_P* fn_80595B64(Db805942E0_P* self, Db805937A4_Mgr* m, int x)
{
    fn_805942E0(self, m, 5, x);
    self->m14 = lbl_80682CC8;
    fn_805944D0(self, 0, 0x1612, 50.0f, 5.0f, 90.0f, 10.0f);
    fn_805944D0(self, 1, 0x1613, 25.0f, 5.0f, 70.0f, 5.0f);
    fn_805944D0(self, 2, 0x1614, 35.0f, 5.0f, 80.0f, 10.0f);
    fn_805944D0(self, 3, 0x1615, 15.0f, 1.0f, 25.0f, 5.0f);
    fn_805944D0(self, 4, 0x1616, 3000.0f, 500.0f, 7000.0f, 500.0f);
    fn_80594538((Db805942E0_V*)self);
    return self;
}

struct Db80595C84_S30 {
    char pad0[0x10];
    DbQuadTab* m10;
    char pad14[0x2C - 0x14];
    int* m2C;
};
struct Db80595C84_Scr {
    char pad0[0x30];
    Db80595C84_S30* m30;
    char* m34;
};
struct Db80595C84_Self {
    Db805919E8_M* m0;
};
extern "C" char* fn_8058F1F0(char* p, int k);
extern "C" int fn_80590188(char* p, int i);
extern "C" int fn_80591A50(Db805919E8_M* m);
extern "C" int fn_80592E04(Db805937A4_Mgr* m, int i);
extern "C" int fn_80593E68(DbQuadTab* self, int i);
extern "C" void fn_80591B8C(Db805919E8_M* m, int x, int j, int a3, int a4, int flag);
extern "C" void* memset(void* p, int c, ...);

extern "C" DB_OVERLAY void fn_80595C84(Db80595C84_Self* self)
{
    int i = 0;
    int total = 0;
    int off = 0;
    char* lst = fn_8058F1F0(((Db80595C84_Scr*)lbl_8061930C)->m34, 1);
    Db805919E8_M* mgr = self->m0;
    int* tbl = ((Db80595C84_Scr*)lbl_8061930C)->m30->m2C;
    int idx = fn_80592E04((Db805937A4_Mgr*)mgr, fn_80591A50(mgr));
    int a1[5];
    int a2[5];
    float fr[5];
    memset(a2, 0, 0x14);
    do {
        int v = fn_80590188(lst, i);
        i++;
        total += v;
        *(int*)((char*)a1 + off) = v;
        off += 4;
    } while (i <= 4);
    for (int k = 0; k < 4; k++)
        fr[k] = (float)a1[k] / (float)total;
    DbQuadTab* t = ((Db80595C84_Scr*)lbl_8061930C)->m30->m10;
    if (fn_80596538(t, idx)) {
        DbQuad* q = fn_805965DC(t, idx);
        if (q->mC == 0xD) {
            int tot = q->m8 * fn_80593E68(t, 0xD);
            int rem = tot;
            for (int k = 0; k < 4; k++) {
                int v = (int)(fr[k] * (float)tot + 0.5f);
                a2[k] = v;
                rem -= v;
            }
            if (rem > 0)
                a2[1] -= rem;
            else if (rem < 0)
                a2[0] -= rem;
            a2[4] = 0;
        }
    }
    if (total > 0) {
        i = 0;
        off = 0;
        do {
            char* b1 = (char*)tbl + 4;
            char* b2 = (char*)a2;
            int v = *(int*)(b1 + off) - *(int*)(b2 + off);
            if (v < 0)
                v = 0;
            Db805919E8_M* m = self->m0;
            fn_80594418((Db805942E0_Data*)self, i);
            int c = *(int*)(off + (int)a1);
            off += 4;
            fn_80591B8C(m, 0, i, c, v, 0);
            i++;
        } while (i <= 4);
    }
}

extern "C" DB_OVERLAY int fn_80595EEC(Db805942E0_V* self, int i)
{
    float lo = self->v30(i)->mC;
    float cur = fn_80594418(self, i);
    float step = self->v30(i)->m4;
    return (int)((cur - lo) / step);
}

extern "C" DB_OVERLAY Db805942E0_P* fn_80595F8C(Db805942E0_P* self, Db805937A4_Mgr* m, int x)
{
    fn_805942E0(self, m, 3, x);
    self->m14 = lbl_80682830;
    fn_805944D0(self, 0, 0x5C6E, 1.0f, 1.0f, 1.0f, 1.0f);
    fn_805944D0(self, 1, 0x5C6F, 1.0f, 1.0f, 1.0f, 1.0f);
    fn_805944D0(self, 2, 0x5C70, 1.0f, 1.0f, 1.0f, 1.0f);
    fn_80594538((Db805942E0_V*)self);
    return self;
}

extern "C" DB_OVERLAY void fn_8059603C()
{
}

extern "C" DB_OVERLAY DbQuadTab* fn_80596040(DbQuadTab* self, Db805937A4_Mgr* m, int x)
{
    fn_80593CD0((Db80593CD0_P*)self, m, 9, 0x10, x, 0.0f);
    *(const void**)((char*)self + 0x1C) = lbl_80682C50;
    DbQuad* p = self->q;
    int n = 0x52;
    do {
        p->m4 = 1;
        p->m0 = 0;
        p->m8 = 0;
        p->mC = 0x10;
        p++;
        n--;
    } while (n != 0);
    fn_80594250((Db80593CD0_Data*)self, 0, 0x5847, 0x2710, 0x3E8, 2000.0f, 0.0f);
    fn_80594250((Db80593CD0_Data*)self, 1, 0x5848, 0x2710, 0x3E8, 5000.0f, 0.0f);
    fn_80594250((Db80593CD0_Data*)self, 2, 0x5849, 0x2710, 0x3E8, 3500.0f, 0.0f);
    fn_80594250((Db80593CD0_Data*)self, 3, 0x584A, 0x2710, 0x3E8, 15000.0f, 0.0f);
    fn_80594250((Db80593CD0_Data*)self, 4, 0x584B, 0x2710, 0x3E8, 30000.0f, 0.0f);
    fn_80594250((Db80593CD0_Data*)self, 5, 0x584C, 0x2710, 0x3E8, 10000.0f, 0.0f);
    fn_80594250((Db80593CD0_Data*)self, 6, 0x584D, 0x2710, 0x3E8, 3000.0f, 0.0f);
    fn_80594250((Db80593CD0_Data*)self, 7, 0x584E, 0x2710, 0x3E8, 10000.0f, 0.0f);
    fn_80594250((Db80593CD0_Data*)self, 8, 0x584F, 0x2710, 0x3E8, 15000.0f, 0.0f);
    fn_80594250((Db80593CD0_Data*)self, 9, 0x5850, 0x2710, 0x3E8, 4000.0f, 0.0f);
    fn_80594250((Db80593CD0_Data*)self, 0xA, 0x5851, 0x2710, 0x3E8, 20000.0f, 0.0f);
    fn_80594250((Db80593CD0_Data*)self, 0xB, 0x5852, 0x2710, 0x3E8, 8000.0f, 0.0f);
    fn_80594250((Db80593CD0_Data*)self, 0xC, 0x5853, 0x2710, 0x3E8, 30000.0f, 0.0f);
    fn_80594250((Db80593CD0_Data*)self, 0xD, 0x5854, 0x2710, 0x3E8, 0.0f, 0.0f);
    fn_80594250((Db80593CD0_Data*)self, 0xE, 0x5856, 0x2710, 0x3E8, 15000.0f, 0.0f);
    fn_80594250((Db80593CD0_Data*)self, 0xF, 0x5857, 0x2710, 0x3E8, 4000.0f, 0.0f);
    fn_805962F4((Db8058F924_L*)self);
    return self;
}

extern "C" DB_OVERLAY void fn_805962F4(Db8058F924_L* self)
{
    self->v48();
    fn_805942A8(self);
}

extern "C" DB_OVERLAY void fn_8059633C(DbQuadTab* self)
{
    for (int i = 0; i < 0x52; i++) {
        self->q[i].m0 = -1;
        self->q[i].m4 = 1;
        self->q[i].m8 = 0;
        self->q[i].mC = 0x10;
    }
    self->m540 = -1;
}

extern "C" DB_OVERLAY float fn_80596388(Db805937A4_Mgr** self, int id)
{
    float r = 0.0f;
    if (fn_8059377C(*self, id)) {
        r = fn_805938E8(*self, id);
    } else if (fn_8056AC44(((Db80619948_O*)lbl_80619948)->m28, id, 0)) {
        r = 1.0f;
    } else {
        Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
        int t = fn_8007F7D0((Unk8007F198_B*)s, 0);
        int u = s->fn_8007B320(0, t);
        int v = fn_8056A5F4(((Db80619948_O*)lbl_80619948)->m28, 0, id, u);
        r = fn_800A5A1C(lbl_80619948, v);
    }
    return r;
}

extern "C" DB_OVERLAY int fn_80596460(Db805937A4_Mgr** self, int id)
{
    int r = 0;
    if (fn_8059377C(*self, id) != 0)
        r = fn_8059394C(*self, id);
    return r;
}

extern "C" DB_OVERLAY void fn_805964B4(Db805937A4_Mgr** self, int id)
{
    if (fn_8059377C(*self, id)) {
        fn_80593880(*self, id);
    } else {
        Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
        int t = fn_8007F7D0((Unk8007F198_B*)s, 0);
        int u = s->fn_8007B320(0, t);
        fn_800A3C98(lbl_80619948, id, u);
    }
}

extern "C" DB_OVERLAY int fn_80596538(DbQuadTab* self, int a)
{
    int i = 0;
    int id = fn_8007FBC0((Unk8007F198_C*)lbl_8061930C, a, 0);
    if (i <= self->m540) {
        do {
            if (id == self->q[i].m0 && self->q[i].m4 == fn_80596C7C(self, a, id))
                return 1;
            i++;
        } while (i <= self->m540);
    }
    return 0;
}

extern "C" DB_OVERLAY DbQuad* fn_805965DC(DbQuadTab* self, int a)
{
    int i = 0;
    int id = fn_8007FBC0((Unk8007F198_C*)lbl_8061930C, a, 0);
    for (; i <= self->m540; i++) {
        if (id == self->q[i].m0 && self->q[i].m4 == fn_80596C7C(self, a, id))
            return &self->q[i];
    }
    return (DbQuad*)((char*)self + 0x10);
}

extern "C" DB_OVERLAY void fn_80596688(DbQuadTab* self, int a, int b, int c)
{
    int id = fn_8007FBC0((Unk8007F198_C*)lbl_8061930C, c, 0);
    fn_80593F30((Db80593CD0_Data*)self, a, b, -1.0f, -1.0f);
    self->m540++;
    self->q[self->m540].m0 = id;
    self->q[self->m540].m4 = fn_80596C7C(self, c, id);
    self->q[self->m540].m8 = b;
    self->q[self->m540].mC = a;
}

extern "C" DB_OVERLAY void fn_80596748(float a, float b)
{
}

extern "C" DB_OVERLAY void fn_8059675C()
{
}

extern "C" DB_OVERLAY void fn_80596760(char* self, int a, Unk80070DDC_Stream* io)
{
    fn_80594148((Db80593CD0_Data*)self, a, io);
    io->v08(a, self + 0x20, 0x520);
    io->v08(a, self + 0x540, 4);
}

struct Db805967DC_TabF {
    float v[16];
};
struct Db805967DC_TabI {
    int v[16];
};
extern Db805967DC_TabF lbl_80600F50;
extern Db805967DC_TabF lbl_80600F90;
extern Db805967DC_TabI lbl_80600FD0;
extern Db805967DC_TabF lbl_80601010;
extern "C" int fn_8040ABA0();
extern "C" int fn_8055207C();

extern "C" DB_OVERLAY float fn_805967DC(DbQuadTab* self, int id)
{
    float res = 0.0f;
    if (fn_80596538(self, id)) {
        DbQuad* q = fn_805965DC(self, id);
        Db805967DC_TabF a = lbl_80600F50;
        Db805967DC_TabF b = lbl_80600F90;
        Db805967DC_TabI c = lbl_80600FD0;
        res = a.v[q->mC];
        res += (float)(fn_8040ABA0() % 100) * ((b.v[q->mC] - a.v[q->mC]) * 0.01f);
        int prod = q->m8 * fn_80593E68(self, q->mC);
        if (prod <= 3000)
            res = res * (float)(prod / 30) * 0.01f;
        int r = fn_80596BAC(self, id, q->mC);
        int lim = c.v[q->mC];
        if (r > lim) {
            r -= lim;
            Db805967DC_TabF e = lbl_80601010;
            for (int n = 0; n < r; n++)
                res *= e.v[q->mC];
        }
        fn_80596388((Db805937A4_Mgr**)self, id);
        switch (fn_8055207C()) {
        case 0:
            break;
        case 1:
            res *= 0.9f;
            break;
        case 2:
            res *= 0.8f;
            break;
        case 3:
            res *= 0.5f;
            break;
        }
    }
    return res;
}

/* near-miss (25 slots): retail forms &row[0].m4 before the call and keeps it in r30, one more callee-saved register than here. */
extern "C" DB_OVERLAY int fn_80596BAC(DbQuadTab* self, int a, int b)
{
    int cnt = 0;
    int i = self->m540;
    int id = fn_8007FBC0((Unk8007F198_C*)lbl_8061930C, a, 0);
    int flag = 0;
    if (i >= 0) {
        do {
            if (flag == 0) {
                if (id == self->q[i].m0)
                    flag = self->q[i].m4 == fn_80596C7C(self, a, id);
            } else if (b == self->q[i].mC && self->q[i].m8 > 0) {
                cnt++;
            }
            i--;
        } while (i >= 0);
    }
    return cnt;
}

extern "C" DB_OVERLAY int fn_80596C7C(DbQuadTab* self, int a, int b)
{
    Unk8007F198_C* scr = (Unk8007F198_C*)lbl_8061930C;
    int m28 = (int)((Db80619948_O*)lbl_80619948)->m28;
    int hi = 0;
    int t = fn_8007FB98__FP13Unk8007F198_Ciii(scr, a, 0, 0);
    int lo = 0;
    int r0 = fn_8056A2F8(m28, a, 0, 2, 0, t, 0, 2, 0, 0x1A);
    int r1 = fn_8056A2F8(m28, a, 1, 2, 0, t, 0, 2, 0, 0x1A);
    if (r1 != -1)
        lo = fn_8007FBC0(scr, r1, 0);
    if (r0 != -1)
        hi = fn_8007FBC0(scr, r0, 0);
    if (b == lo && b == hi)
        return 0;
    return 1;
}
