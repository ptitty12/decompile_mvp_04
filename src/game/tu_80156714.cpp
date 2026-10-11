/*
 * Game code, .text 0x80156714-0x8015AA94 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8015AA94.h"

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

inline void SetM4C(Unk8061FEDC_Obj* o, float v)
{
    o->m40.mC = v;
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

void cScriptParticleEffect::fn_vslot2() /* 80156EB4 */
{
    fn_8037B7E8(lbl_805C8A6C);
    fn_8037B674(lbl_805C8A80, &m4, lbl_805C8A94, 0);
    fn_8037B830(lbl_805C8A6C);
}

int cScriptParticleEffect::fn_cslot8() /* 80156F14 */
{
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
