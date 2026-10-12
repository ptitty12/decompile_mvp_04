/*
 * Game code, .text 0x802EFF28-0x802F42A4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802EFF28.h"

struct Unk802F398C_V4 {
    float m0;
    float m4;
    float m8;
    float mC;
};
extern Unk802F398C_V4 lbl_8068DF38;

inline void Set4(Unk802F398C_V4* p, float x, float y, float z, float w)
{
    p->m0 = x;
    p->m4 = y;
    p->m8 = z;
    p->mC = w;
}

void fn_802EFF28(void* a, void* b, void* c)
{
    fn_802EFF54(b, a, c);
}

void fn_802F1E80(void* a, void* b, void* c)
{
    fn_802F1EAC(b, a, c);
}

void fn_802F3330(void* a, void* b)
{
    fn_802F335C(b, a);
}

/* near-miss: loop shape and instructions match (jump into the do-while test); i and the loaded
   char are in r9/r11 instead of r11/r9 (8 slots) */
void fn_802F35A4(char* dst, char* src)
{
    int i = 0;
    goto test;
    do {
        dst[i] = src[i];
        i++;
        if (i > 15) {
            break;
        }
    test:;
    } while (i < src[i]);
    dst[i] = 0;
}

void fn_802F398C(int a, int b)
{
    if (b == 0xFFFF && a != 0) {
        Set4(&lbl_8068DF38, 1.0f, 1.0f, 1.0f, 0.0f);
        for (int i = 0; i < 3; i++) {
        }
    }
}

Unk802F3A04::~Unk802F3A04()
{
}

int Unk802F3A04::s8()
{
    return 0;
}

int Unk802F3A04::s9()
{
    return 0;
}

void fn_802F3A90()
{
    fn_802F398C(1, 0xFFFF);
}
