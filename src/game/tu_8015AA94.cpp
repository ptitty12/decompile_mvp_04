

/*
 * Game code, .text 0x8015AA94-0x8015F164 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 * fn_8015AE08 (0x435c bytes) is not written yet.
 */
#include "game/tu_8015AA94.h"

extern const char lbl_805C8C20[];

extern float lbl_805C8E54;
extern float lbl_805C8E58;
extern float lbl_805C8E68;
extern float lbl_805C8E6C;
extern Unk8015ABB8_Rec lbl_8068B7DC;

void fn_80326ED4(Unk801527C8_Sub* s, float* a, float* b);
int fn_803270C4(Unk801527C8_Sub* s, int id, int n, float t);
int fn_801D0294(void* p);

void Unk80159F28::fn_8015AA94() /* 8015AA94 */
{
    float a, b;
    Unk801527C8_Actor* actor = mC;
    Unk801527C8_Sub* s = &actor->m50;
    fn_80326ED4(s, &a, &b);
    int r = fn_803270C4(s, 0x40, 1, lbl_805C8E54);
    Unk801527C8_Slots* sl = actor->m700;
    if (sl->m3BC->m24 != 0) {
        int v = fn_801D0294((char*)sl->m3A4 + 0x28C);
        fn_80159F28(v, r > 0 ? 1 : 0);
    }
}

void Unk8015AB2C::fn_8015AB2C(int a, int b, Unk8015AB2C_Blk blk) /* 8015AB2C */
{
    if (m0 > 9) {
        return;
    }
    m4[m0].m0 = b;
    m4[m0].m4 = a;
    m4[m0].m8 = blk;
    m0++;
}

Unk8015ABB8_Rec Unk8015AB2C::fn_8015ABB8(int t) /* 8015ABB8 */
{
    Unk8015ABB8_Rec best = lbl_8068B7DC;
    int bestTime = 0;
    for (int i = 0; i < m0; i++) {
        if (m4[i].m0 >= t && m4[i].m0 > bestTime) {
            best = *(Unk8015ABB8_Rec*)&m4[i].m4;
            bestTime = m4[i].m0;
        }
    }
    if (bestTime == t) {
        float p = lbl_805C8E58;
        const char* file = lbl_805C8C20;
        unsigned int n = m324->m554->fn_8014D8AC(1000000, file, 0x593);
        if (!((float)n * p * lbl_805C8E68 < lbl_805C8E6C)) {
            best = lbl_8068B7DC;
        }
    }
    return best;
}
