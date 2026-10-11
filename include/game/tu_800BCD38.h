#ifndef GAME_TU_800BCD38_H
#define GAME_TU_800BCD38_H

/*
Types for the front-end code in game/tu_800BCD38.cpp .. game/tu_800D1758.cpp
(0x800BCD38..0x800D4D0C; one shared header for the range). Everything is named
by address (Unk<addr>) or offset (m<off>); nothing here comes from original headers.
*/

/* Big front-end screen object (initialised by fn_800C1D6C): small value groups at
 * +0, +0x14, +0x20, +0x7C/+0x84, a 44-byte struct at +0x8C, 25 words at +0x59C. */
struct Unk800C1D6C_Block44 {
    int m0, m4, m8, mC, m10, m14, m18, m1C, m20, m24, m28;
};

struct Unk800C1D6C_Obj {
    int m0;
    int m4;
    int m8;
    char mC;
    char mD;
    short mE;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    char pad28[0x3C];
    int m64;
    int m68;
    char pad6C[0x8];
    int m74;
    char pad78[0x4];
    int m7C;
    int m80;
    int m84;
    int m88;
    Unk800C1D6C_Block44 m8C;
    char padB8[0x4E0];
    int m598;
    int m59C[25];
    int m600;
    char pad604[0x3C];
    int m640;
    int m644;
};

/* Entry of the list at Unk800C16CC_List::m34 (name string at +0xC). */
struct Unk800C16CC_Entry {
    char pad0[0xC];
    char mC[1];
};

struct Unk800C16CC_List {
    char pad0[0x34];
    Unk800C16CC_Entry* m34[100];
    int m1C4;
};
struct Unk800C16CC_Holder {
    char pad0[0x10];
    Unk800C16CC_List* m10;
};
struct Unk800C1754_Pool {
    int m0;
    char pad4[0x14];
    void* m18;
};


/* On-demand file slot, size 0x46C (array at manager+0x9C). m40C holds the queued objects
 * (front-end widgets) with their priorities in m430. The vptr is at +0x468. */
struct Unk800C1BE4_Widget;
struct Unk800C2250_FileData {
    char m0;
    char pad1[0x3FF];
    int m400;
    int m404;
    int m408;
    Unk800C1BE4_Widget* m40C[9];
    float m430[9];
    int m454;
    int m458;
    void* m45C;
    int m460;
    int m464;
};

struct Unk800C2250_File : Unk800C2250_FileData {
    Unk800C2250_File();
    virtual ~Unk800C2250_File();
};

extern "C" {
int fn_800C2EF0(Unk800C2250_File* f);
int fn_800C2F08(Unk800C2250_File* f);
int fn_800C2F1C(Unk800C2250_File* f);
int fn_800C2F30(Unk800C2250_File* f);
int fn_800C2F44(Unk800C2250_File* f);
int fn_800C2F5C(Unk800C2250_File* f);
int fn_800C2F74(Unk800C2250_File* f);
int fn_800C2F7C(Unk800C2250_File* f);
char* fn_800C2F84(Unk800C2250_File* f);
int fn_800C2F88(Unk800C2250_File* f);
int fn_800C2F90(Unk800C2250_File* f, int i);
Unk800C1BE4_Widget* fn_800C2FB0(Unk800C2250_File* f, int i);
Unk800C1BE4_Widget* fn_800C2FC0(Unk800C2250_File* f, int i);
float fn_800C2FD0(Unk800C2250_File* f, int i);
void fn_800C2FF0(Unk800C2250_File* f);
void fn_800C2B94(Unk800C2250_File* f, int i);
void fn_800C2978(Unk800C2250_File* f);
void fn_800C31FC(Unk800C2250_File* f);
void fn_800C2848(Unk800C2250_File* f);
void fn_800C28C8(Unk800C2250_File* f);
}


/* On-demand manager singleton (fn_800C33D0), size 0x5DAC, vptr at +0x5DA8. The ten file
 * slots start at +0x9C; twelve 0x410-byte request records start at +0x2CD4 (see
 * Unk800C3A10_Rec). */
struct Unk800C3A10_Rec {
    int m0;
    char m4;
    char pad5[0x3FF];
    int m404;
    float m408;
    int m40C;
};

struct Unk800C341C_Mgr {
    int m0[0x26];
    char m98;
    char pad99[3];
    Unk800C2250_File files[10];
    Unk800C3A10_Rec recs[12];
    int m5D94;
    int m5D98;
    int m5D9C;
    int m5DA0;
    int m5DA4;
};

extern "C" {
void fn_800C537C(Unk800C341C_Mgr* m, int kind, const char* name, int idx, float scale, int flag);
Unk800C341C_Mgr* fn_800C33D0();
int fn_800C5CF8(Unk800C341C_Mgr* m, const char* name);
int fn_800C5C68(Unk800C341C_Mgr* m, Unk800C1BE4_Widget* w);
void fn_800C2C78(Unk800C2250_File* f);
void fn_800C334C(Unk800C2250_File* f);
void fn_800C3B14(Unk800C341C_Mgr* m);
}

#endif
