/*
 * Game code, .text 0x8014F47C-0x801527C8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80144CF0.h"

struct Unk50Ent { char m0; char pad1[8]; char m9; char pad2[0x4C - 0xA]; int m4C; };
void* operator new(unsigned int size, int heap);
extern int lbl_806EF9B4;
struct Unk80151FA0_Obj { char pad0[0x48]; int m48; char pad4C[8]; int m54; int m58; };
struct UnkAt20F2 { char pad0[0x20]; float m20; };
class Unk8037B3E8 {
public:
    Unk8037B3E8(unsigned int hash);
    int m0;
};
inline void* operator new(unsigned int, void* p) { return p; }
struct Unk801522E4_Obj { const void* m0; char m4; };
struct UnkAt13B { char pad0[0x13]; char m13; };
struct Unk8015242C_Obj { int m0; int m4; float m8; float mC; int m10; float m14; float m18; };

extern "C" {
/* near-miss (6 of 14 slots): retail keeps base+0x4C as an invariant pointer and indexes it with the
   0x50 stride (addi r11,r8,0x4C; stwx r9,r11,r10); the forms tried give 'add r11,r10,r8; stw 0x4C(r11)' */
void fn_8014F47C(Unk50Ent* p);
int fn_8014F530(void* self, int c);
int fn_80150D8C();
int fn_80150D98();
void fn_80150DA4();
void fn_80150DC4();
void fn_80150DF0();
void* fn_80150F90();
void fn_80150FC0(void* p);
void fn_801519A4();
void* fn_801519A8();
void fn_801519D8(void* p);
char* fn_80151A18(char* p, int i);
int fn_80151A28(char* p, int i);
int fn_80151A38(char* p, int i);
void* fn_80151C10();
void fn_80151FA0(Unk80151FA0_Obj* p);
float fn_80152064(UnkAt20F2* p, float f);
void* fn_801522B4();
void* fn_801522E4(void* self);
void fn_8015238C(float a, float b, float c);
void fn_801523A4(UnkAt13B* p);
void* fn_801523B0();
void* fn_801523E0(void* self);
void fn_8015242C(Unk8015242C_Obj* p);
void* fn_80152580();
void fn_801525B0(void* p);
void fn_80152728();
extern int lbl_8061B880;
void fn_80149F6C();
void fn_8014FC50(int, int);
void* fn_80150E1C(void*);
void* fn_8037C7FC();
void fn_8037CE98(void*, unsigned, void*, int);
void* fn_80151684(void*);
void* fn_80151A48(void*);
void fn_8033CD74(void*);
void* fn_80151C40(void*);
extern const char lbl_8065E878[];
extern const char lbl_8065EA40[];
extern const float lbl_805C7BE4;

/* near-miss (6 of 14 slots): retail keeps base+0x4C as an invariant pointer and indexes it with the
   0x50 stride (addi r11,r8,0x4C; stwx r9,r11,r10); the forms tried give 'add r11,r10,r8; stw 0x4C(r11)' */
void fn_8014F47C(Unk50Ent* p)
{
    Unk50Ent* b = p;
    int off = 0;
    for (int i = 0; i < 8; i++) {
        p->m0 = 0;
        p->m9 = 0;
        *(int*)((char*)b + 0x4C + off) = 0;
        p++;
        off += 0x50;
    }
}

int fn_8014F530(void* self, int c)
{
    int t = c - 0x30;
    int r = c - 0x57;
    if ((unsigned char)t <= 9) {
        r = t;
    }
    return r;
}

int fn_80150D8C() { return lbl_8061B880; }

int fn_80150D98() { return 0xA22DD41B; }

void fn_80150DA4() { fn_80149F6C(); }

void fn_80150DC4() { fn_8014FC50(0x1, 0xFFFF); }

void fn_80150DF0() { fn_8014FC50(0x0, 0xFFFF); }

void* fn_80150F90() { return fn_80150E1C(operator new(0x14, lbl_806EF9B4)); }

void fn_80150FC0(void* p) { fn_8037CE98(fn_8037C7FC(), 0x149EF3D8, p, 0x0); }

void fn_801519A4() {}

void* fn_801519A8() { return fn_80151684(operator new(0x160, lbl_806EF9B4)); }

void fn_801519D8(void* p) { fn_8037CE98(fn_8037C7FC(), 0x916112DD, p, 0x0); }

char* fn_80151A18(char* p, int i)
{
    return (char*)(i * 0x18 + (int)p + 0x30);
}

int fn_80151A28(char* p, int i)
{
    char* b = p + 0x28;
    int o = i * 0x18;
    return *(int*)(b + o);
}

int fn_80151A38(char* p, int i)
{
    char* b = p + 0x2C;
    int o = i * 0x18;
    return *(int*)(b + o);
}

void* fn_80151C10() { return fn_80151A48(operator new(0x1C, lbl_806EF9B4)); }

void fn_80151FA0(Unk80151FA0_Obj* p)
{
    p->m48 = p->m48 + 1;
    p->m54 = p->m54 + 1;
    if (p->m58 == 0) {
        fn_8033CD74((char*)p + 0x5C);
    }
}

float fn_80152064(UnkAt20F2* p, float f)
{
    return p->m20 - f;
}

void* fn_801522B4() { return fn_80151C40(operator new(0x68, lbl_806EF9B4)); }

void* fn_801522E4(void* self)
{
    new (self) Unk8037B3E8(0x1BE7961C);
    Unk801522E4_Obj* p = (Unk801522E4_Obj*)self;
    p->m4 = 0;
    p->m0 = lbl_8065E878;
    return p;
}

void fn_8015238C(float a, float b, float c)
{
}

void fn_801523A4(UnkAt13B* p)
{
    p->m13 = 0;
}

void* fn_801523B0() { return fn_801522E4(operator new(0x14, lbl_806EF9B4)); }

void* fn_801523E0(void* self)
{
    new (self) Unk8037B3E8(0x37EF0C2A);
    *(const void**)self = lbl_8065EA40;
    fn_8015242C((Unk8015242C_Obj*)self);
    return self;
}

void fn_8015242C(Unk8015242C_Obj* p)
{
    p->m4 = 0;
    p->m10 = 0;
    p->m8 = lbl_805C7BE4;
    p->mC = lbl_805C7BE4;
    p->m14 = lbl_805C7BE4;
    p->m18 = lbl_805C7BE4;
}

void* fn_80152580() { return fn_801523E0(operator new(0x1C, lbl_806EF9B4)); }

void fn_801525B0(void* p) { fn_8037CE98(fn_8037C7FC(), 0x37EF0C2A, p, 0x0); }

void fn_80152728() {}

}
