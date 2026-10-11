/*
 * Game code, .text 0x802547C0-0x80256C80 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

struct Unk80256978_S84 {
    char pad0[0x84];
    int m84;
};
struct Unk80256980_S8 {
    int m0;
    int m4;
    int m8;
};
struct Unk80256990_S658 {
    char pad0[0x658];
    int m658;
};
struct Unk80256A88_SA08 {
    char pad0[0xA08];
    int mA08;
};
struct Unk80256B2C_S6D4 {
    char pad0[0x6D4];
    float m6D4[4];
};
struct Unk80256BE4_S71C {
    char pad0[0x71C];
    short m71C;
};
struct Unk80256C70_SAB4 {
    char pad0[0xAB4];
    float mAB4;
};

int fn_80256978(Unk80256978_S84* self)
{
    return self->m84;
}

int fn_80256980(Unk80256980_S8* self)
{
    return self->m8;
}

int fn_80256988(Unk80256980_S8* self)
{
    return self->m8;
}

void fn_80256990(Unk80256990_S658* self, int a)
{
    self->m658 = a;
}

int fn_80256A88(Unk80256A88_SA08* self)
{
    return self->mA08;
}

float fn_80256B2C(Unk80256B2C_S6D4* self, int i)
{
    return self->m6D4[i];
}

void fn_80256B3C(Unk80256B2C_S6D4* self, float v, int i)
{
    self->m6D4[i] = v;
}

void fn_80256B5C()
{
}

extern char lbl_806EF9C7;
extern char lbl_806EF9C8;
extern char lbl_806EF9C4;
extern char lbl_8061EC9C;
int fn_80256B60()
{
    return lbl_806EF9C7;
}

int fn_80256B70()
{
    return lbl_806EF9C8;
}

int fn_80256B80()
{
    return lbl_806EF9C4;
}

int fn_80256B90(int a, int b)
{
    return b;
}

int fn_80256B98(int a, int b)
{
    return b;
}

int fn_80256BA0()
{
    return lbl_8061EC9C;
}

int fn_80256BE4(Unk80256BE4_S71C* self)
{
    return self->m71C > 0;
}

int* fn_80256C68(char* self)
{
    return (int*)(self + 0x8C);
}

float fn_80256C70(Unk80256C70_SAB4* self)
{
    return self->mAB4;
}

char* fn_80256C78(char* self)
{
    return self + 0x60;
}
