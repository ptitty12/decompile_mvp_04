/*
 * Game code, .text 0x80156714-0x8015AA94 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8015AA94.h"
#include "game/tu_80167DCC.h"

extern float lbl_805C8C1C;

extern float lbl_805C8C04;

extern float lbl_805C89F4;
extern float lbl_805C89F8;
extern float lbl_805C89FC;

int fn_8016C1C4(Unk801527C8_Ctx* ctx, int n);
int fn_8016C798(Unk801527C8_Ctx* ctx, int n);
float fn_80382BD8(void* link, int a);
int fn_8027D574(Unk8027C728_Goal* g);
int fn_8027D670(Unk8027C728_Goal* g, Unk8027C728_Player* p, int flag);
void fn_80185D80(void* o);
void fn_8030D28C(void* o, int v);
int fn_801525B0(int v);
void fn_80359A40(int* p);
Unk801527C8_Actor* fn_801A04A8(Unk801527C8_Actor* a, int i);

extern const char lbl_805C7BCC[];
extern const char lbl_805C7CBC[];
extern const char lbl_805C8468[];
extern const char lbl_805C8988[];
extern const char lbl_805C89A8[];
extern const char lbl_805C89B4[];
extern const char lbl_805C89C0[];
extern const char lbl_805C8A6C[];
extern const char lbl_805C8A80[];
extern const char lbl_805C8A94[];
extern const char lbl_805C8BE0[];
extern const char lbl_805C8BF8[];
extern const char* lbl_8061BE0C;

extern const char lbl_805C7994[];

extern const char lbl_805C60F8[];
extern const char lbl_805C6240[];
extern const char* lbl_8061BD80;

Unk801527C8_Actor* fn_801A04A8(Unk801527C8_Actor* a, int i);

extern int lbl_8061D460;
extern "C" int fn_80163748(Unk80159F28* self);
extern "C" int fn_80163390(Unk80159F28* self);
extern "C" int fn_80162FE4(Unk80159F28* self);
extern "C" int fn_80162C28(Unk80159F28* self);
extern "C" int fn_80161FBC(Unk80159F28* self);
extern "C" void fn_801599DC(Unk80159F28* self);

extern const char lbl_8065E9E0[];
extern const char lbl_80649DB8[];
void fn_80359ACC(Unk80359ACC* p);
struct Node8015737C { void* m0; };
inline void SetW8015737C(char* base, int off, int v) { *(int*)(base + off) = v; }
extern "C" {
void fn_803785E4(void* self);
void fn_80378A34(void* self, int v);
void fn_80378620(void* self, int chrg);
void fn_80377408(void* p);
void fn_80377488(void* p);
}
class Vt8_801574E0 {
public:
    char pad0[8];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
};
extern "C" {
void fn_801597F0(Unk80159F28* self);
int fn_8015A6A0(Unk80159F28* self);
void fn_80161004(Unk80159F28* self);
void fn_801609EC(Unk80159F28* self);
void fn_80161924(Unk80159F28* self);
int fn_8017CF14(void* p, int i);
void fn_8017CD04(void* p, int i, int j);
}
int fn_801A2034(Unk801527C8_Actor* a, int i);
struct V2_80159E40 { float x; float y; };
V2_80159E40 fn_8022EA60(void* a, ...);
inline float AbsF80159E40(float v) { return (float)__builtin_fabs(v); }
extern int lbl_80619D10;
extern const Unk8015AB2C_Blk lbl_8068B828;
int fn_800AB528(int g);
int fn_800AC330();
void fn_800AC36C();
void fn_8031E1D4(Unk801527C8_Actor* a, const char* s);
extern "C" int fn_80326C20(Unk801527C8_Sub* s);
inline void SetM4C(Unk8061FEDC_Obj* o, float v)
{
    o->m40.mC = v;
}

int cWait::fn_801567CC(Unk80156838_Entry* e) /* 801567CC */
{
    switch (e->m0) {
    case 0x39:
    case 0x42:
    case 0x5F:
    case 0x60:
    case 0x61:
    case 0x62:
    case 0x84:
    case 0x87:
        return 1;
    case 0xAD:
        if (e->m14 & 0x10) {
            return 1;
        }
    }
    return 0;
}

int cWait::fn_80156838(Unk80156838_Entry* e, int n, float t) /* 80156838 */
{
    float c1 = lbl_805C89F4;
    float c2 = lbl_805C89F8;
    for (int i = 0; i < n; i++) {
        Unk80156838_Entry* p = &e[i];
        if (fn_801567CC(p)) {
            if (!(p->m4 <= t) && !(t + lbl_805C89F4 <= p->m4)) {
                return 1;
            }
        } else {
            if (!(p->m4 <= t) && !(t + lbl_805C89F8 <= p->m4)) {
                return 1;
            }
        }
    }
    return 0;
}

int cWait::fn_80156904(Unk80156838_Entry* e, int n, float t) /* 80156904 */
{
    float c = lbl_805C89FC;
    for (int i = 0; i < n; i++) {
        float x = e[i].m4;
        if (!(x >= t) && !(x < t - lbl_805C89FC)) {
            return 1;
        }
    }
    return 0;
}

Unk8037B3E8* cWait::fn_vslot5() /* 80156C8C */
{
    return new (lbl_806EF9B4) cWait;
}

cWaitForAnimation::cWaitForAnimation() : Unk80359B48(0x3C5D0164u) /* 80156CBC */
{
}

void cWaitForAnimation::fn_vslot2() /* 80156D00 */
{
}

extern "C" void* fn_801572FC(Unk80159F28* self, Unk801527C8_Ctx* ctx) /* 801572FC */
{
    fn_803785E4(self);
    self->mC = (Unk801527C8_Actor*)ctx;
    *(const void**)((char*)self + 8) = lbl_8065E9E0;
    fn_80359ACC(&self->m5F4);
    int off = 0;
    for (int k = 0; k < 0xAE; k++) {
        SetW8015737C((char*)self + 0x33C, off, 0);
        off += 4;
    }
    self->fn_80157410();
    fn_80378A34(self, (int)ctx + 0x704);
    return self;
}

extern "C" void fn_8015737C(Unk80159F28* self, int chrg) /* 8015737C */
{
    *(const void**)((char*)self + 8) = lbl_8065E9E0;
    int off = 0;
    for (int k = 0; k < 0xAE; k++) {
        Node8015737C** arr = (Node8015737C**)((char*)self + 0x33C);
        Node8015737C* p = *(Node8015737C**)((char*)arr + off);
        if (p != 0) {
            if (p->m0 != 0) {
                fn_80377488(p->m0);
            }
            fn_80377408(p);
            *(Node8015737C**)((char*)arr + off) = 0;
        }
        off += 4;
    }
    *(const void**)((char*)self + 8) = lbl_80649DB8;
    fn_80378620(self, chrg);
}

void Unk80159F28::fn_80157410() /* 80157410 */
{
    m34 = 2;
    m40 = 5;
    m10 = 0;
    m4C = -1;
    m14 = 0;
    m18 = 0;
    m1C = 0;
    m44 = -1;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2C = 0;
    m30 = 0;
    m38 = 0;
    m3C = 0;
    m32C = 0;
    m330 = lbl_805C8C1C;
    m334 = lbl_805C8C1C;
    m338 = lbl_805C8C1C;
    m48 = 0;
    fn_80161A34();
    for (int i = 0; i <= 6; i++) {
        for (unsigned char j = 0; j <= 24; j++) {
            *fn_80161A5C(i, j) = 0;
        }
    }
}

extern "C" void fn_801574E0(Vt8_801574E0* self) /* 801574E0 */
{
    self->s4();
}

int fn_80157708(void* self, int v) /* 80157708 */
{
    if ((unsigned int)(v - 0x18) <= 1 || v == 0xA || v == 0x27) {
        return 0;
    }
    return 1;
}

void Unk80159F28::fn_801593D8() /* 801593D8 */
{
    fn_8015A1D4();
}

extern "C" void fn_801593F8(Unk80159F28* self)
{
    if (lbl_8061D460 == 0) {
        int a = fn_80163748(self);
        int b = fn_80163390(self);
        int c = fn_80162FE4(self);
        int d = self->fn_801625FC();
        int e = fn_80162C28(self);
        int f = fn_80161FBC(self);
        if (e == 0 && f == 0 && b == 0 && a == 0 && c == 0 && d == 0) {
            fn_801599DC(self);
        }
    }
}

int cWaitForAnimation::fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80156D04 */
{
    Unk8016C788_Obj* o = fn_8016C788(ctx, a);
    if (o != 0) {
        Unk8027C728_Goal* g = ((Unk8027C728_Player*)o)->m934;
        if (g != 0) {
            if (fn_8027D574(g) != 1 || fn_8027D670(g, (Unk8027C728_Player*)o, 0) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

Unk8037B3E8* cWaitForAnimation::fn_vslot5() /* 80156D88 */
{
    return new (lbl_806EF9B4) cWaitForAnimation;
}

cHomerunCelebration::cHomerunCelebration() : Unk80359B48(0xECDFF60Eu) /* 80156DB8 */
{
}

void cHomerunCelebration::fn_vslot2() /* 80156DFC */
{
}

int cHomerunCelebration::fn_cslot8() /* 80156E00 */
{
}

int cHomerunCelebration::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80156E04 */
{
    fn_80185D80(ctx->mA4C->m6C0);
}

Unk8037B3E8* cHomerunCelebration::fn_vslot5() /* 80156E38 */
{
    return new (lbl_806EF9B4) cHomerunCelebration;
}

cScriptParticleEffect::cScriptParticleEffect() : Unk80359B48(0x1A5105BEu) /* 80156E68 */
{
    m4 = 1;
}

int cScriptParticleEffect::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80156F18 */
{
    fn_8030D28C(ctx->mA4C->m738, m4);
}

Unk8037B3E8* cScriptParticleEffect::fn_vslot5() /* 80156F50 */
{
    return new (lbl_806EF9B4) cScriptParticleEffect;
}

cWaitForActiveActors::cWaitForActiveActors() : Unk80359B48(0xDC217F0Cu) /* 80156F80 */
{
    m4 = 0;
    m8 = 0;
}

void cWaitForActiveActors::fn_vslot2() /* 80156FD0 */
{
    fn_8037B458(lbl_805C8BE0, &m4, lbl_805C60F8, lbl_805C6240);
    fn_8037B6B0(lbl_805C8BF8, &m8, lbl_8061BD80);
}

int cWaitForActiveActors::fn_cslot8() /* 80157034 */
{
}

int cWaitForActiveActors::fn_cslot12(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80157038 */
{
    if (m4 == 0) {
        for (int i = 0; i <= 12; i++) {
            int n = i + 2;
            if (fn_8016C1C4(ctx, n) != 0) {
                return 0;
            }
            Unk8027C728_Player* o = (Unk8027C728_Player*)fn_8016C788(ctx, n);
            if (o != 0) {
                if (o->m934 != 0) {
                    return 0;
                }
                if (fn_80382BD8(o->m618, 0) < lbl_805C8C04) {
                    return 0;
                }
            }
        }
        return 1;
    }
    int i = 0;
    do {
        int n = i + 2;
        if (fn_8016C798(ctx, n) == m8) {
            if (fn_8016C1C4(ctx, n) != 0) {
                break;
            }
            Unk8027C728_Player* o = (Unk8027C728_Player*)fn_8016C788(ctx, n);
            if (o == 0) {
                break;
            }
            if (o->m934 != 0) {
                break;
            }
            if (fn_80382BD8(o->m618, 0) < lbl_805C8C04) {
                break;
            }
            return 1;
        }
        i++;
    } while (i <= 12);
    return 0;
}

Unk8037B3E8* cWaitForActiveActors::fn_vslot5() /* 80157174 */
{
    return new (lbl_806EF9B4) cWaitForActiveActors;
}

cSetDepthOfField::cSetDepthOfField() : Unk80359B48(0x98373702u) /* 801571A4 */
{
    m4 = 0;
}

void cSetDepthOfField::fn_vslot2() /* 801571F0 */
{
    fn_8037B5C0(lbl_805C7CBC, &m4, lbl_805C7BCC);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C7CBC);
}

int cSetDepthOfField::fn_cslot8() /* 8015724C */
{
}

int cSetDepthOfField::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 80157250 */
{
    Unk801527C8_Actor* cur = ctx->mA54;
    if (cur == fn_801A04A8(ctx->mA4C, 1)) {
        int r = fn_801525B0(m4);
        Unk8061FEDC_Sub* s = &lbl_8061FEDC->m40;
        if (r == 0) {
            fn_80359A40(&s->m4);
        } else {
            s->m4 = r;
        }
    }
}

Unk8037B3E8* cSetDepthOfField::fn_vslot5() /* 801572CC */
{
    return new (lbl_806EF9B4) cSetDepthOfField;
}

void cWait::fn_vslot2() /* 80156714 */
{
    fn_8037B6B0(lbl_805C8468, &m4, lbl_8061BE0C);
    fn_8037B458(lbl_805C8988, &mC, 0, lbl_805C6240);
    fn_8037B50C(lbl_805C89A8, &m8, lbl_805C89B4, 0);
    fn_8037B584(lbl_805C7994, 0, 0, lbl_805C89C0);
}

int cWait::fn_cslot11(Unk801527C8_Ctx* ctx, int a, float f1, float f2, float f3) /* 801567B4 */
{
}

void cScriptParticleEffect::fn_vslot2() /* 80156EB4 */
{
    fn_8037B7E8(lbl_805C8A6C);
    fn_8037B674(lbl_805C8A80, &m4, lbl_805C8A94, 0);
    fn_8037B830(lbl_805C8A6C);
}

int cScriptParticleEffect::fn_cslot8() /* 80156F14 */
{
}

extern "C" void fn_801597F0(Unk80159F28* self) /* 801597F0 */
{
    self->m334 = -1.0f;
    int g = lbl_80619D10;
    if (fn_800AB528(g) == 0 || (fn_800AB528(g), fn_800AC330() != 0)) {
        if (fn_80326C20(&self->mC->m50) != 0) {
            Unk80189300* o = fn_801A4B34(self->mC);
            if (o != 0) {
                self->m32C = 1;
                Unk801527C8_Actor* a = fn_801A04A8(self->mC, 5);
                if (o->fn_v4() != 0) {
                    fn_8031E1D4(a, "batterreplayleft");
                    ((Unk8016ACAC*)a->m40)->fn_8016BB50("batterreplay_left_foul", 0, 0, lbl_8068B828, 0);
                } else {
                    fn_8031E1D4(a, "batterreplayright");
                    ((Unk8016ACAC*)a->m40)->fn_8016BB50("batterreplay_right_foul", 0, 0, lbl_8068B828, 0);
                }
                int g2 = lbl_80619D10;
                a->m4 = 1;
                if (fn_800AB528(g2) != 0) {
                    fn_800AB528(g2);
                    fn_800AC36C();
                }
            }
        }
    }
}

extern "C" void fn_80159E40(Unk80159F28* self, int* a, int* b) /* 80159E40 */
{
    int k = self->mC->m700->m3A4->m200;
    switch (k) {
    case 0:
    case 3:
        *a = 1;
        *b = 1;
        break;
    case 1: {
        *a = k;
        V2_80159E40 v = fn_8022EA60(self->mC->m700->m3B0);
        if (!(AbsF80159E40(v.x) <= AbsF80159E40(v.y))) {
            *b = k;
        } else {
            *b = 0;
        }
        break;
    }
    case 2:
    case 4:
    case 5:
    case 6:
        *a = 0;
        break;
    }
}

extern "C" void fn_8015A5A4(Unk80159F28* self) /* 8015A5A4 */
{
    if (!(self->m334 <= 0.0f)) {
        fn_801597F0(self);
    }
    int r = fn_801A6D84(self->mC, 5)->m3D90;
    if (r == 0) {
        if (fn_8015A6A0(self) == 0) {
            self->fn_8015AA94();
            fn_80161004(self);
        }
        self->fn_8015F87C();
        volatile int sp8 = r;
        int e = 0;
        do {
            if (fn_801A2034(self->mC, e) == -1 && fn_8017CF14(self->mC->m700, sp8) != 0) {
                fn_8017CD04(self->mC->m700, sp8, 0);
            }
            int c = sp8;
            int t;
            if (c > 1)
                t = c;
            else
                t = c + 1;
            sp8 = t;
            e = t;
        } while (e <= 1);
        fn_801609EC(self);
        fn_80161924(self);
    }
}
