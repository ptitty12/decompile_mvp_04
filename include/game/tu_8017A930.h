#ifndef GAME_TU_8017A930_H
#define GAME_TU_8017A930_H

/*
 * Declarations for game/tu_8017A930.cpp (reconstructed; placeholders only).
 * Screen object with sub-objects at +0x3A8..+0x3BC (the unit's functions are
 * thin forwarders to them).
 */

struct Unk8017C954_Rec {
    char pad0[0x108];
    int m108;
    int m10C;
    char pad110[0x1CC8 - 0x110];
    unsigned char m1CC8;
    char pad1CC9[1];
    unsigned char m1CCA;
    unsigned char m1CCB;
    char pad1CCC[4];
    int m1CD0;
};
struct Unk8017C954_Mid {
    char pad0[0x14];
    Unk8017C954_Rec* m14;
};
/* Player object (vptr at +0x98; see tu_802AB810.cpp): only slot 8 is used here. */
class Unk8017BE28_Obj {
public:
    char pad0[0x98];
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8(int a);
};
struct Unk8017D5F8_Sub {
    char pad0[0x14];
    int m14;
};
struct Unk8017B0A4_Ctx {
    char pad0[0x4C];
    unsigned int m4C;
    char pad50[0x564 - 0x50];
    Unk8017D5F8_Sub* m564;
    char pad568[0x660 - 0x568];
    void* m660;
    char pad664[0x6C0 - 0x664];
    void* m6C0;
    char pad6C4[0x6CC - 0x6C4];
    Unk8017BE28_Obj* m6CC;
    char pad6D0[0x6E4 - 0x6D0];
    Unk8017BE28_Obj* m6E4;
    char pad6E8[0x6F4 - 0x6E8];
    int m6F4;
    Unk8017C954_Mid* m6F8;
};
struct Unk8017BBF4_G {
    char pad0[0x20];
    int m20;
};
struct Unk8017A930_T {
    int m0;
    Unk8017B0A4_Ctx* m4;
    char pad8[0xC];
    int m14;
    int m18;
    char pad1C[0x3A4 - 0x1C];
    void* m3A4;
    char* m3A8;
    void* m3AC;
    void* m3B0;
    void* m3B4;
    void* m3B8;
    void* m3BC;
    void* m3C0;
    void* m3C4;
    void* m3C8;
    void* m3CC;
    int m3D0;
    int m3D4;
    int m3D8;
    int m3DC;
    int m3E0;
    float m3E4;
    char pad3E8[0x410 - 0x3E8];
    int m410;
    int m414;
    int m418;
};

struct Unk8017EE24_T;
void fn_8017EE24(Unk8017EE24_T* p);
int fn_8017C6BC(Unk8017A930_T* p);
void fn_8017C5F0(Unk8017A930_T* p, int a);
int fn_8018019C(void* p);
int fn_801A57B8(void* p);
void fn_80252460(void* p);
void* fn_801A4B34(void* p);
void* fn_801C1638(void* p, int a);
void fn_801BB520(void* p);
void fn_80235220(void* p);
void fn_801C4D04(void* p);
void fn_80176FD0(char* p);
void fn_80178CF8(void* p);
void fn_802570E0(void* p);
void fn_80179D90(Unk8017B0A4_Ctx* p);
void fn_8017A1FC(Unk8017B0A4_Ctx* p);
void fn_80176740(char* p);
void fn_801A98C4(void* p);
void fn_801DBB2C(void* p);
void fn_80258E64(void* p);
void fn_80235364(void* p);
void fn_801BB0F4(void* p);
void fn_80258BA8(void* p, int a);
void fn_802356D4(void* p, int a);
void fn_801C26FC(void* p, int a);
void fn_801A985C(void* p);
void fn_801BB13C(void* p);
void fn_801DBB74(void* p);
void fn_80258000(void* p);
void fn_801C2724(void* p);
void fn_801A1EDC(Unk8017B0A4_Ctx* p);
void fn_80235730(void* p);
void fn_80258048(void* p, int a);
void fn_801C277C(void* p, int a);
int fn_801DC10C(void* p);
void fn_801BB194(void* p);
void fn_80258390(void* p);
void fn_801C2A40(void* p);
void fn_801BB1E0(void* p);
void fn_801DBB98(void* p, int a);
void fn_80258098(void* p, int a);
void fn_8023584C(void* p, int a);
void fn_801C2AD0(void* p, int a);
void fn_801BB4D8(void* p);
void fn_801DBBBC(void* p, int a);
void fn_80258250(void* p, int a);
void fn_801C2C10(void* p, int a);
void fn_801BB1A4(void* p);
void fn_801DBC48(void* p);
void fn_80258354(void* p);
void fn_8037893C(void* p, int a, int b, int c, int d);
void fn_801B03B8(void* p);
void fn_801BB65C(void* p);
void fn_801DBC6C(void* p);
void fn_80258444(void* p);
void fn_8023590C(void* p);
void fn_801C2C64(void* p);
void fn_802595E0(void* p);
void fn_801DBE78(void* p, int a, int b, int c);
void fn_801DBC90(void* p);
void fn_80258E40(void* p, int a, int b, int c);
void fn_801C2F28(void* p, int a, int b, int c);
void fn_801B0354(void* p, int a, int b, int c);
void fn_801AD38C(void* p);
void fn_802572CC(void* p);
void fn_80176780(char* p);
void fn_803295F0();
extern int lbl_8061C688;
extern char lbl_8068BE40[];
void fn_80186890(void* p);
void fn_801C2144(void* p);
void fn_8023538C(void* p);
void fn_801ABAA0(void* p);
void fn_801B1220(void* p);
void fn_801A9724(void* p);
void fn_801DBA9C(void* p);
void fn_80258644(void* p);
void fn_80176B70(void* p);
void fn_80178C5C(void* p);
void fn_801C2544(void* p);
void fn_8023533C(void* p);
void fn_801A98A0(void* p);
void fn_801AB6A0(void* p);
void fn_801B1190(void* p);
void fn_801BAE90(void* p);
void fn_801DBAC0(void* p);
void fn_802585E8(void* p);
void fn_80178C08(void* p);
void fn_8017E264(void* p);
struct Unk8017EE24_T;
void fn_8017EE70(Unk8017EE24_T* p);
void fn_801DBD14(void* p);
void fn_801C30F8(void* p);
void fn_802592E8(void* p);
void fn_8023596C(void* p);
void fn_801BB994(void* p);
void fn_8017EEAC(void* p, void* q);
void fn_801BB988(void* p);
void fn_801DBD38(void* p);
void fn_802591D0(void* p);
void fn_8017EA6C(Unk8017A930_T* p);
void fn_801ABBA8(void* p);
void fn_801B12C0(void* p);
void fn_801B032C(void* p);
void fn_801766FC(void* p);
void fn_801C20CC(void* p);
void fn_80235294(void* p);
void fn_801DBD80(void* p);
extern Unk8017BBF4_G* lbl_8061B8C0;
struct Unk8017C5F0_Y {
    char pad0[0x1B4];
    unsigned char m1B4[0x80];
};
inline int SumYBytes(int y)
{
    int s = 0;
    for (int i = 0; i < 128; i++)
        s += ((Unk8017C5F0_Y*)y)->m1B4[(unsigned char)i];
    return s;
}
struct Unk8017C75C_Obj {
    char pad0[0x458];
    int m458;
};
void fn_8017C228(Unk8017A930_T* p, int a, int b, int c);
void fn_801C3B04(void* p);
void fn_801DBDA4(void* p);
void fn_80258070(void* p);
void fn_80178F10(void* p);
void fn_8017696C(void* p);
int fn_8017D5F8(Unk8017A930_T* p);
struct Unk8017C8D0_Obj {
    char pad0[0x3D90];
    int m3D90;
};
Unk8017C8D0_Obj* fn_801A6D84(void* ctx, int a);
int fn_803272D0(void* p, int a);
extern const float lbl_805CC8AC;
extern const float lbl_805CC8B0;
extern const float lbl_805CC8B4;
int fn_8017E030(Unk8017A930_T* p, int a, int b);
int fn_801C1638i(void* p, int a);
void fn_80176B90(char* p);
void fn_80176F04(char* p);
void fn_8017671C(char* p);
void fn_801DBB50(void* p);
void fn_801BB800(void* p);
void fn_801DBCB4(void* p);
void fn_801DC918(void* p);
void fn_80235A40(void* p);
void fn_80235AD4(void* p);

#endif
