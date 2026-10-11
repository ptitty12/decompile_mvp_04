/*
 * Game code, .text 0x802520F8-0x802547C0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024EF40.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;
typedef Unk8024EF40_W W;
typedef Unk8024EF40_Q Q;

extern "C++" {
int fn_80250AC4(P* x);
int fn_80250A90(P* x, int k);
float fn_80251000(P* x, int k);
void* fn_8023CB44(P* x);
void fn_80250B28(P* x, int k);
int fn_80097620(Unk8024EF40_Ent* e, int x0, int x1, int x2);
int fn_8009764C(Unk8024EF40_Ent* e, int x0, int x1, int x2);
float fn_80097678(Unk8024EF40_Ent* e, int x0, int x1, int x2);
int fn_80097A9C(Unk8024EF40_Ent* e, int x0, int x1, int x2, int x3);
float fn_80097B60(Unk8024EF40_Ent* e, int x0, int x1, int x2, int x3);
int fn_80097EA4(Unk8024EF40_Ent* e, int x0, int x1, int x2, int x3);
float fn_80097F68(Unk8024EF40_Ent* e, int x0, int x1, int x2, int x3);
int fn_800983C8(Unk8024EF40_Ent* e, int x0, int x1);
int fn_8009841C(Unk8024EF40_Ent* e, int x0, int x1);
float fn_80098470(Unk8024EF40_Ent* e, int x0, int x1);
int fn_8009896C(Unk8024EF40_Ent* e, int x0, int x1, int x2);
int fn_800989C8(Unk8024EF40_Ent* e, int x0, int x1, int x2);
int fn_80098C68(Unk8024EF40_Ent* e, int x0, int x1, int x2);
float fn_80098CC4(Unk8024EF40_Ent* e, int x0, int x1, int x2);
extern char lbl_8068CC18[];
extern char lbl_8068CCA8[];
int fn_8008CFD8(char* p, int a, unsigned char b);
void fn_8023C254(void* tbl, int a, int* out, int idx, int z);
int fn_80099570(Unk8024EF40_Ent* e, int a, int b, int c);
void fn_8023C2C0(void* tbl, int a, int* out, int idx, int z);
void fn_8008D738(void* p, int a, int b, int c);
float fn_8008D7B8(void* p, int a, int b);
int fn_80089AA0(char* e, int a, int v);
void fn_8023C1E8(void* tbl, int a, int* out, int idx, int z);
float fn_80089E48(void* p, int a, int b);
float fn_800718F0(void* w, int a, int val);
extern char lbl_805D990C[];
extern int lbl_8061DC54;
extern float lbl_8061DC44;
extern int lbl_80691CDC;
inline float G_8061DC44(void* p) { return lbl_8061DC44; }
struct Unk802531FC_C {
    int m0;
    P* m4;
    int m8;
    float mC;
    float m10;
    float m14;
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    unsigned f0 : 1;
    unsigned f1 : 1;
    unsigned f2 : 1;
    unsigned f3 : 29;
    int m48;
    int m4C;
    P* m50;
};
typedef Unk802531FC_C C;
void fn_8037893C(void* q, int id, void* o, int a, int b);
int fn_80097318(Unk8024EF40_Ent* e, int a);
int fn_800973E8(Unk8024EF40_Ent* e, int a);
int fn_80097380(Unk8024EF40_Ent* e, int a);
int fn_80097450(Unk8024EF40_Ent* e, int a);
int fn_800974B8(Unk8024EF40_Ent* e, int a);
int fn_801A2034(Q* q, int pos);
int* fn_801A6DB8(Q* q);
void fn_8025283C(C* self);
void fn_80252964(C* self);
void fn_802529F0(C* self);
void fn_802526D4();
int fn_80254374(W* self, int a);
float fn_80254618(W* self, int a);
int fn_80253100(C* self, int a);
}

void fn_80252460(P* x)
{
    if (fn_80250AC4(x) != 0 && fn_80250A90(x, 0xC) != 0) {
        float p = RandPct(x, lbl_805D990C, 0x62E);
        float t = fn_80251000(x, 0x2B) * G_8061DC44(fn_8023CB44(x));
        if (lbl_8061DC54 != 0 || lbl_80691CDC != 0)
            p = 0.0f;
        if (!(p >= t))
            fn_80250B28(x, 0xC);
    }
}

void fn_802526D4()
{
}

/* near-miss: retail emits `lis r29,0x4330` after the call to the empty fn_802526D4, ours hoists it above (1 slot) */
void fn_802526D8(C* self)
{
    self->m0 = 2;
    fn_802526D4();
    fn_802529F0(self);
    self->m8 = fn_80254374(&self->m4->m588, 0x1A);
    self->mC = (float)fn_80254374(&self->m4->m588, 4);
    self->m10 = (float)fn_80254374(&self->m4->m588, 9);
    self->m14 = (float)fn_80254374(&self->m4->m588, 0xE);
    self->m18 = (float)fn_80254374(&self->m4->m588, 0x13);
    self->m1C = (float)fn_80254374(&self->m4->m588, 0x18);
    self->m20 = fn_80254618(&self->m4->m588, 1);
    fn_8025283C(self);
    fn_80252964(self);
}

void fn_80252964(C* self)
{
    float v = (float)fn_80254374(&self->m4->m588, 0);
    self->m28 = !(v <= 0.0f) ? self->m24 / v : 0.0f;
}

void fn_80252A90()
{
}

/* near-miss: same stores, scheduler moves m10/m38 earlier than retail */
void fn_80252D38(C* self)
{
    self->m3C = -1;
    self->m2C = 0.0f;
    self->f0 = 0;
    self->f1 = 0;
    self->f2 = 0;
    self->m50 = 0;
    self->m8 = 0;
    self->m28 = 0.0f;
    self->m24 = 0.0f;
    self->mC = 0.0f;
    self->m20 = 0.0f;
    self->m1C = 0.0f;
    self->m18 = 0.0f;
    self->m14 = 0.0f;
    self->m10 = 0.0f;
    self->m30 = 0;
    self->m34 = 0;
    self->m40 = 0;
    self->m38 = 0;
    self->m48 = fn_80253100(self, 0xF);
    self->m4C = fn_80253100(self, 0xFF);
}

void fn_80252DD8(C* self, P* p)
{
    if (p != 0)
        self->m50 = (P*)p->m704;
    else
        self->m50 = p;
}

int fn_802530E8(C* self)
{
    return self->m4C != 0xFF;
}

int fn_80253100(C* self, int a)
{
    P* p = self->m4;
    int t = p->m708;
    int n;
    if (t == 2 || (n = p->m704) == 0 || p->m44C->m6F4 != 0)
        return 15;
    Unk8024EF40_Ent* e = p->m44C->m6F8->m14 + t;
    int r = a;
    if (fn_80097318(e, n) != 0)
        r = 15;
    else if (fn_800973E8(e, n) != 0)
        r = 16;
    else if (fn_80097380(e, n) != 0)
        r = 17;
    else if (fn_80097450(e, n) != 0)
        r = 18;
    else if (fn_800974B8(e, n) != 0)
        r = 19;
    return r;
}

/* near-miss: one register (li r10 vs r11) differs; store order and byte-load spellings tried */
void fn_802531FC(C* self)
{
    self->m3C = *((unsigned char*)self->m4->m44C->m6F8->m14 + 0x1CC8);
    self->m38 = 0;
}

void fn_80253220(C* self)
{
    self->m38 = self->m38 + 1;
    if (self->f1)
        self->f1 = 0;
}

int fn_802536D0(P* self)
{
    if (self->m44C->m6F4 == 1)
        return 1;
    if (fn_801A2034(self->m44C, self->m708) == -1)
        return *fn_801A6DB8(self->m44C);
    return Pick(self->m44C->m6F8->m10, self->m708);
}

int fn_8025374C(P* self)
{
    if (self->m44C->m6F4 == 1)
        return 1;
    if (fn_801A2034(self->m44C, self->m708) != -1)
        return fn_802536D0(self);
    int k = self->m708;
    if (k == 0)
        k = 1;
    else if (k == 1)
        k = 0;
    return Pick(self->m44C->m6F8->m10, k);
}

void fn_80253BFC(W* self)
{
    fn_8037893C(self->m0->m44C->m704, 0x53, 0, 0, 0);
}

void fn_80253C38(W* self)
{
    fn_8037893C(self->m0->m44C->m704, 0x54, 0, 0, 0);
}

int fn_80253DB0(Unk8024EF40_W* self, int a, int b)
{
    P* p = self->m0;
    return fn_80097620(EntOf(p), a, p->m70C, b);
}

int fn_80253DF4(Unk8024EF40_W* self, int a, int b)
{
    P* p = self->m0;
    return fn_8009764C(EntOf(p), a, p->m70C, b);
}

float fn_80253E38(Unk8024EF40_W* self, int a, int b)
{
    P* p = self->m0;
    return fn_80097678(EntOf(p), a, p->m70C, b);
}

int fn_80253E7C(Unk8024EF40_W* self, int a, int b, int c)
{
    P* p = self->m0;
    return fn_80097A9C(EntOf(p), a, p->m70C, b, c);
}

float fn_80253EC4(Unk8024EF40_W* self, int a, int b, int c)
{
    P* p = self->m0;
    return fn_80097B60(EntOf(p), a, p->m70C, b, c);
}

int fn_80253F0C(Unk8024EF40_W* self, int a, int b, int c)
{
    P* p = self->m0;
    return fn_80097EA4(EntOf(p), a, p->m70C, b, c);
}

float fn_80253F54(Unk8024EF40_W* self, int a, int b, int c)
{
    P* p = self->m0;
    return fn_80097F68(EntOf(p), a, p->m70C, b, c);
}

int fn_80253F9C(Unk8024EF40_W* self, int a)
{
    P* p = self->m0;
    return fn_800983C8(EntOf(p), a, p->m70C);
}

int fn_80253FDC(Unk8024EF40_W* self, int a)
{
    P* p = self->m0;
    return fn_8009841C(EntOf(p), a, p->m70C);
}

float fn_8025401C(Unk8024EF40_W* self, int a)
{
    P* p = self->m0;
    return fn_80098470(EntOf(p), a, p->m70C);
}

int fn_8025405C(Unk8024EF40_W* self, int a, int b)
{
    P* p = self->m0;
    return fn_8009896C(EntOf(p), a, p->m70C, b);
}

int fn_802540A0(Unk8024EF40_W* self, int a, int b)
{
    P* p = self->m0;
    return fn_800989C8(EntOf(p), a, p->m70C, b);
}

int fn_802540E4(Unk8024EF40_W* self, int a, int b)
{
    P* p = self->m0;
    return fn_80098C68(EntOf(p), a, p->m70C, b);
}

float fn_80254128(Unk8024EF40_W* self, int a, int b)
{
    P* p = self->m0;
    return fn_80098CC4(EntOf(p), a, p->m70C, b);
}

int fn_8025416C(W* self, int a)
{
    int r;
    P* p = self->m0;
    Unk8024EF40_Ent* e = EntOf(p);
    r = fn_8008CFD8((char*)e + 0xC9C, a, p->m70C);
    fn_8023C254(lbl_8068CC18, a, &r, self->m0->m708, 0);
    fn_8023C254(lbl_8068CCA8, a, &r, self->m0->m708, 0);
    fn_8023C254((char*)e + 0x118, a, &r, self->m0->m708, 0);
    return r;
}

int fn_80254228(W* self, int a, int b)
{
    int r;
    P* p = self->m0;
    Unk8024EF40_Ent* e = EntOf(p);
    r = fn_80099570(e, a, p->m70C, b);
    fn_8023C2C0(lbl_8068CC18, a, &r, self->m0->m708, 0);
    fn_8023C2C0(lbl_8068CCA8, a, &r, self->m0->m708, 0);
    fn_8023C2C0((char*)e + 0x118, a, &r, self->m0->m708, 0);
    return r;
}

void fn_802542E8(W* self, int a, int b)
{
    P* p = self->m0;
    fn_8008D738((char*)EntOf(p) + 0xC9C, a, p->m70C, b);
}

float fn_80254330(W* self, int a)
{
    P* p = self->m0;
    return fn_8008D7B8((char*)EntOf(p) + 0xC9C, a, p->m70C);
}

int fn_80254374(W* self, int a)
{
    int r;
    P* p = self->m0;
    Unk8024EF40_Ent* e = EntOf(p);
    r = fn_80089AA0((char*)e + 0xC74, a, p->m70C);
    fn_8023C1E8(lbl_8068CC18, a, &r, self->m0->m708, 0);
    fn_8023C1E8(lbl_8068CCA8, a, &r, self->m0->m708, 0);
    fn_8023C1E8((char*)e + 0x118, a, &r, self->m0->m708, 0);
    return r;
}

float fn_80254430(W* self, int a)
{
    P* p = self->m0;
    return fn_80089E48((char*)EntOf(p) + 0xC74, a, p->m70C);
}

float fn_80254474(W* self, int a, int b)
{
    int r;
    P* p = self->m0;
    Unk8024EF40_Ent* e = EntOf(p);
    r = fn_80099570(e, a, p->m70C, b);
    fn_8023C2C0(lbl_8068CC18, a, &r, self->m0->m708, 0);
    fn_8023C2C0(lbl_8068CCA8, a, &r, self->m0->m708, 0);
    fn_8023C2C0((char*)e + 0x118, a, &r, self->m0->m708, 0);
    int o = b * 4;
    char* bb = (char*)e + 0xCC4;
    return fn_800718F0(*(void**)(bb + o), a, r);
}

float fn_8025454C(W* self, int a)
{
    int r;
    P* p = self->m0;
    Unk8024EF40_Ent* e = EntOf(p);
    char* q = (char*)e + 0xC9C;
    r = fn_8008CFD8(q, a, p->m70C);
    fn_8023C254(lbl_8068CC18, a, &r, self->m0->m708, 0);
    fn_8023C254(lbl_8068CCA8, a, &r, self->m0->m708, 0);
    fn_8023C254((char*)e + 0x118, a, &r, self->m0->m708, 0);
    return fn_800718F0(q, a, r);
}

float fn_80254618(W* self, int a)
{
    int r;
    P* p = self->m0;
    Unk8024EF40_Ent* e = EntOf(p);
    char* q = (char*)e + 0xC74;
    r = fn_80089AA0(q, a, p->m70C);
    fn_8023C1E8(lbl_8068CC18, a, &r, self->m0->m708, 0);
    fn_8023C1E8(lbl_8068CCA8, a, &r, self->m0->m708, 0);
    fn_8023C1E8((char*)e + 0x118, a, &r, self->m0->m708, 0);
    return fn_800718F0(q, a, r);
}
