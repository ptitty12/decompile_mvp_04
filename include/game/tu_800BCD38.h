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
    const char* m4_name() { return &m4; }
    int m404;
    float m408;
    int m40C;
};

struct Unk800C341C_Mgr {
    int m0;
    int m4;
    void* m8;
    char padC[0x10];
    void* m1C;
    char pad20[0x78];
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
void fn_800C3D50(Unk800C341C_Mgr* m);
int fn_800C2998(Unk800C2250_File* f, Unk800C1BE4_Widget* w);
void fn_800C2458(Unk800C2250_File* f);
void fn_800C5010(Unk800C341C_Mgr* m);
void fn_800C5080(Unk800C341C_Mgr* m);
void fn_800C3A4C(Unk800C341C_Mgr* m);
void fn_800C3A10(Unk800C341C_Mgr* m);
void fn_800C5AF8(Unk800C341C_Mgr* m);
void fn_800C5B58(Unk800C341C_Mgr* m);
void fn_800C3828(Unk800C341C_Mgr* m);
int fn_800C58E8(Unk800C341C_Mgr* m, int kind);
void fn_800C435C(Unk800C341C_Mgr* m, int idx, float scale, const char* name, int flag);
void fn_800C4D90(Unk800C341C_Mgr* m, int idx, float scale, const char* name, int flag);
void fn_800C56C0(Unk800C341C_Mgr* m, int a);
void fn_803FEDB8(void* p, int a);
void fn_803FB4B0();
int fn_800C5C68(Unk800C341C_Mgr* m, Unk800C1BE4_Widget* w);
int fn_800C587C(Unk800C341C_Mgr* m);
int fn_800C5DAC(Unk800C341C_Mgr* m, int kind);
void fn_800C24B0(Unk800C2250_File* f);
void fn_800C2518(Unk800C2250_File* f);
void fn_800C2948(Unk800C2250_File* f);
int fn_800C510C(Unk800C341C_Mgr* m, const char* name);
int fn_800C512C(Unk800C341C_Mgr* m, int idx);
void fn_800C2C78(Unk800C2250_File* f);
void fn_800C334C(Unk800C2250_File* f);
void fn_800C3B14(Unk800C341C_Mgr* m);
}


/* Data part of the front-end widget base (ctor fn_800C7B40, size 0x40 with the vptr at +0x3C).
 * +0x24 is a word of flag bits (b0 = MSB) whose low half overlaps m26. */
struct Unk800C7B40_Data {
    int m0;
    int m4;
    int m8;
    char mC[16];
    int m1C;
    int m20;
    unsigned b0 : 1;
    unsigned b1 : 1;
    unsigned b2 : 1;
    unsigned b3 : 1;
    unsigned b4 : 1;
    unsigned b5 : 1;
    unsigned b6 : 1;
    unsigned b7 : 1;
    unsigned b8 : 1;
    unsigned b9 : 1;
    unsigned b10 : 1;
    unsigned b11 : 1;
    unsigned b12 : 1;
    unsigned b13 : 1;
    unsigned b14 : 1;
    unsigned b15 : 1;
    short m26;
    short m28;
    short m2A;
    short m2C;
    short m2E;
    short m30;
    short m32;
    short m34;
    short m36;
    float m38;
};

/* Front-end widget base: the virtual part of the class whose data starts with
 * Unk800C7B40_Data. g++ 2.95 puts the vptr (+0x3C) after the data of the class that
 * introduces virtuals, so data that follows the vptr belongs to a derived class.
 * fn_vslotN = vtable slot N (virtual N is at +8N of the vtable). The vtables are about
 * 0x3F8 bytes for the largest classes, so slots up to 127 are declared. */
struct Unk800C7B40_Widget : Unk800C7B40_Data {
    virtual ~Unk800C7B40_Widget();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5(int a, int b, int c, int d);
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8(int a);
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12(int a);
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18(int a);
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual void fn_vslot24();
    virtual void fn_vslot25();
    virtual void fn_vslot26();
    virtual void fn_vslot27();
    virtual Unk800C7B40_Widget* fn_vslot28(const char* name, int a);
    virtual void fn_vslot29();
    virtual Unk800C7B40_Widget* fn_vslot30(const char* name, int a);
    virtual Unk800C7B40_Widget* fn_vslot31(int type, int a);
    virtual void fn_vslot32();
    virtual void fn_vslot33();
    virtual void fn_vslot34();
    virtual void fn_vslot35();
    virtual void fn_vslot36();
    virtual void fn_vslot37();
    virtual void fn_vslot38();
    virtual void fn_vslot39();
    virtual void fn_vslot40();
    virtual void fn_vslot41();
    virtual void fn_vslot42();
    virtual void fn_vslot43();
    virtual void fn_vslot44();
    virtual void fn_vslot45();
    virtual void fn_vslot46();
    virtual void fn_vslot47();
    virtual void fn_vslot48();
    virtual void fn_vslot49();
    virtual void fn_vslot50();
    virtual void fn_vslot51();
    virtual void fn_vslot52();
    virtual void fn_vslot53();
    virtual void fn_vslot54();
    virtual void fn_vslot55();
    virtual void fn_vslot56();
    virtual void fn_vslot57();
    virtual void fn_vslot58();
    virtual void fn_vslot59();
    virtual void fn_vslot60();
    virtual void fn_vslot61();
    virtual void fn_vslot62();
    virtual void fn_vslot63();
    virtual void fn_vslot64();
    virtual void fn_vslot65();
    virtual void fn_vslot66();
    virtual void fn_vslot67();
    virtual void fn_vslot68();
    virtual void fn_vslot69();
    virtual void fn_vslot70();
    virtual void fn_vslot71();
    virtual void fn_vslot72();
    virtual void fn_vslot73();
    virtual void fn_vslot74();
    virtual void fn_vslot75();
    virtual void fn_vslot76();
    virtual void fn_vslot77();
    virtual void fn_vslot78();
    virtual void fn_vslot79();
    virtual void fn_vslot80();
    virtual void fn_vslot81();
    virtual void fn_vslot82();
    virtual void fn_vslot83();
    virtual void fn_vslot84();
    virtual void fn_vslot85();
    virtual void fn_vslot86();
    virtual void fn_vslot87();
    virtual void fn_vslot88();
    virtual void fn_vslot89();
    virtual void fn_vslot90();
    virtual void fn_vslot91();
    virtual void fn_vslot92();
    virtual void fn_vslot93();
    virtual void fn_vslot94();
    virtual void fn_vslot95();
    virtual void fn_vslot96();
    virtual void fn_vslot97();
    virtual void fn_vslot98();
    virtual void fn_vslot99();
    virtual void fn_vslot100();
    virtual void fn_vslot101();
    virtual void fn_vslot102();
    virtual void fn_vslot103();
    virtual void fn_vslot104();
    virtual void fn_vslot105();
    virtual void fn_vslot106();
    virtual void fn_vslot107();
    virtual void fn_vslot108();
    virtual void fn_vslot109();
    virtual void fn_vslot110();
    virtual void fn_vslot111();
    virtual void fn_vslot112();
    virtual void fn_vslot113();
    virtual void fn_vslot114();
    virtual void fn_vslot115();
    virtual void fn_vslot116();
    virtual void fn_vslot117();
    virtual void fn_vslot118();
    virtual void fn_vslot119();
    virtual void fn_vslot120();
    virtual void fn_vslot121();
    virtual void fn_vslot122();
    virtual void fn_vslot123();
    virtual void fn_vslot124();
    virtual void fn_vslot125();
    virtual void fn_vslot126();
    virtual void fn_vslot127();
};

/* Container widget: five child pointers at +0x40..+0x50. */
struct Unk800C7A4C_Group : Unk800C7B40_Widget {
    Unk800C7B40_Widget* m40;
    Unk800C7B40_Widget* m44;
    Unk800C7B40_Widget* m48;
    Unk800C7B40_Widget* m4C;
    Unk800C7B40_Widget* m50;
    void fn_800C7A4C(int v);
    void fn_800C7584(Unk800C7B40_Widget* c);
    void fn_800C75F0(Unk800C7B40_Widget* c);
    void fn_800C765C(Unk800C7B40_Widget* c);
    void fn_800C76C8(Unk800C7B40_Widget* c);
    void fn_800C7734(Unk800C7B40_Widget* c);
};

void* operator new(unsigned int size, int heap); /* 0x80377428 */

/* Singleton at lbl_8061ABE0 (fn_800C5E28, size 0x44, vptr at +0x40). */
struct Unk800C5E74_Data {
    int m0;
    char m4;
    char pad5[0xB];
    int m10;
    int m14;
    char m18;
    char pad19[0xF];
    int m28;
    int m2C;
    int m30;
    float m34;
    int m38;
    int m3C;
};

struct Unk800C5E74_Obj : Unk800C5E74_Data {
    Unk800C5E74_Obj();
    virtual ~Unk800C5E74_Obj();
    void fn_800C5EB0();
    void fn_800C6604();
    void fn_800C6624();
};

/* Name/handle list at +0x34 (count at +0x1C4) used by fn_800C16CC and fn_800C68D0. */
struct Unk800C68B4_List {
    char pad0[0x34];
    Unk800C7B40_Widget* m34[100];
    int m1C4;
    void fn_800C68B4(Unk800C7B40_Widget* e);
    Unk800C7B40_Widget* fn_800C68D0(const char* name);
    void fn_800C694C(const char* name);
    void fn_800C696C();
};

extern int lbl_8061A330;

#endif
