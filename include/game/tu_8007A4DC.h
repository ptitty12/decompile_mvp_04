#ifndef GAME_TU_8007A4DC_H
#define GAME_TU_8007A4DC_H

/*
 * UI screen wrappers at 0x8007A4DC-0x8007DB74 (units tu_8007A4DC, tu_8007B714,
 * tu_8007CAC4). Types here are placeholders named after the first function that
 * proves them.
 *
 * Obj: the record a Handle points at; fn_800A883C(Handle*) is `lwz r3,0(r3)`, and
 * the screens read Obj::m4 when it is non-null.
 *
 * W: a widget with a vptr at +0x20 (a 0x20-byte base, then the virtuals). Evidence:
 * every wrapper loads `lwz r9,0x20(w)`, then `lha delta,N(r9)` / `lwz pfn,N+4(r9)`
 * (g++ 2.95 vtable entries are {delta, pfn}; the first virtual is at +8). The id
 * resolver fn_80071814(W*, int) reads W::m10 and W::m14 (fn_80071814 at 0x80071814).
 * Slot arities come from the call sites: 0x28 and 0x38 take (a, id), 0x30 and 0x40
 * take (a, id, c), 0x48 takes four, 0x18 takes one (fn_8007A984 calls it with 0x1D).
 * Slot 0x30's third argument is a char* (fn_8007B9F4 passes a stack buffer).
 *
 * Entry/EntryTable: the table behind Screen::m8: a count, then 0x6EC-byte entries
 * starting at +0x18 (mulli 0x6EC, addi 0x18, bounds check against *table).
 * fn_8007DADC / fn_8007DB0C / fn_8007DB40 read, clear and set the top bit of the
 * word at Entry+0x38.
 */
struct Obj {
    char* m0;
    int m4;
};
struct Handle {
    Obj* m0;
};
Obj* fn_800A883C(Handle* h);

struct WBase {
    int m0;
    int m4;
    int m8;
    int mC;
    Obj* m10;
    int m14;
    int m18;
    unsigned m1C;
};
struct W : WBase {
    virtual int v08();
    virtual int v10(int i);
    virtual int v18(int a);
    virtual int v20();
    virtual int v28(int a, int b);
    virtual int v30(int a, int b, char* c);
    virtual int v38(int a, int b);
    virtual int v40(int a, int b, int c);
    virtual int v48(int a, int b, int c, int d);
    virtual int v50();
    virtual int v58();
    virtual int v60();
    virtual int v68(int a, int b);
    virtual int v70(int a, int b);
    virtual int v78(int a, int b, int c);
};
struct Unk8007A4DC_Obj1E8;
struct Unk805A19C8_Entry {
    int* m0;
    char pad4[3];
    unsigned char m7;
    char pad8[0x1E0 - 8];
};
struct Unk805A19C8_Roster {
    char pad0[0x10];
    Unk805A19C8_Entry* m10;
};
int fn_805A19C8(Unk805A19C8_Roster* r, int a);
struct Slot {
    W* m0;
    W* m4[2];
};
struct Unk8052_Obj;

int fn_80071814(W* w, int b);
int fn_8007189C(W* w, int b);
float fn_8007189C(W* w, int a, int id);
float fn_800718F0(W* w, int a, int val);
int fn_80071784(W* w, int b);

struct Entry {
    char pad0[0x38];
    unsigned m38_0 : 1;
    unsigned m38_rest : 31;
    char pad3C[0x6EC - 0x3C];
};
struct EntryTable {
    int count;
    int cur;
    int list[4];
    Entry e[1];
};

struct Owner {
    char pad0[0x1F0];
    int m1F0;
};
struct Unk8007A4DC_Screen;
struct Unk8007B2B0_Screen;
void fn_80377E90(Obj* list, int* a, int* b, int idx);
char* fn_80402EF8(char* dst, const char* src);
int fn_800803F0(Unk8007A4DC_Screen* s, int a, int b);
int fn_80080464(Unk8007A4DC_Screen* s, int a, int b);

struct Unk8007A4DC_Screen {
    Owner* m0;
    char pad4[0x34];
    Handle m38;
    char pad3C[0x10];
    Handle m4C;
    char pad50[0x8];
    Unk805A19C8_Roster* m58;
    char pad5C[0x30];
    Handle m8C;
    char pad90[0xEC];
    Handle m17C;
    char pad180[0x4];
    W* m184;
    W* m188[2];
    Slot m190[2];
    W* m1A8[5];
    W* m1BC;
    Handle m1C0;
    char pad1C4[0x4];
    W* m1C8;
    Slot m1CC[2];
    W* m1E4;
    Unk8007A4DC_Obj1E8* m1E8;
    char pad1EC[0x1C];
    int m208;

    void fn_8007285C();
    void fn_8007295C();
    int fn_80072894(int a);
    int fn_800728BC(int a);
    int fn_800728E4(int a);
    void fn_80072ABC();
    int fn_80073710(int a, int x, int i);
    float fn_80073820(int a, int b, int i);
    void fn_8007389C(int a, int b, int i, int c);
    int fn_80073914(int a, int b, int i);
    void fn_80073994(int a, int b, int i, int c);
    int fn_800739E0(int a, int id, int c, int d);
    int fn_80074428(int a, int b, int c, int d);
    void fn_800743A0(int a, int b, int i, int j, int c);
    void fn_80074500(int a, int b, int i, int j, int c);
    int fn_8007455C(int a, int b, int i);
    float fn_800745C4(int a, int b, int i);
    void fn_80074640(int a, int b, int i, int c);
    int fn_800746B8(int a, int b, int i);
    void fn_80074708(int a, int b, int i, int c);
    int fn_80074754(int a, int x, int i);
    void fn_80074F50(int a, int b, int i, int c);
    int fn_80074FC8(int a, int b, int i);
    void fn_80075048(int a, int b, int i, int c);
    int fn_80075094(int a, int id, int c, int d);
    int fn_80075684(int a, int b, int c, int d);
    void fn_800755FC(int a, int b, int i, int j, int c);
    void fn_8007575C(int a, int b, int i, int j, int c);
    int fn_800764F4(const char* a, const char* b, int c);
    int fn_8007661C(int b);
    int fn_80077238(int a, int b);
    int fn_80077320(int a, int b);
    int fn_80077404(int a, int b);
    int fn_80077684(int a, int b);
    int fn_8007776C(int a, int b);
    int fn_80077850(int a, int b);
    int fn_80077934(int a, int b);
    void fn_80077CF8();
    void fn_80077D38(int a, int b);
    void fn_80077D60(int a, int b);
    void fn_80077D88();
    void fn_80077DAC();
    int fn_80078A64(int a, int b, int c);
    void fn_80078AE0(int a, int* o1, int* o2, int* o3, int* o4);
    void fn_80078C04(int a, int* o1, int* o2, int* o3, int* o4);
    int fn_80078D00(int a);
    void fn_8007A008(int a);
    void fn_8007A06C(int a);
    int fn_8007A11C(int a);
    int fn_8007A168(int a);
    int fn_8007A1B4(int a);
    int fn_8007A1D8(int a);
    int fn_8007A224(int a);
    int fn_8007A270(int a);
    void fn_8007A2B4(int flags);
    void fn_8007A380();
    float fn_8007A3FC(int a, int b);
    float fn_8007A444(int a, int b);
    float fn_8007A48C(int a, int b, int i);
    int fn_8007A4DC(int a);
    int fn_8007A500(int a);
    int fn_8007A524(int a, int b, int i);
    int fn_8007A550(int a);
    int fn_8007A588(int a);
    int fn_8007A5C0(int a);
    int fn_8007A5F8();
    int fn_8007A630();
    int fn_8007A668();
    int fn_8007A6A0(int a, int b);
    int fn_8007A700(int a, int b, char* c);
    int fn_8007A768(int a, int b);
    char* fn_8007A7C8(int a, int b, char* out);
    int fn_8007A808(int a, int b, int c);
    int fn_8007A870(int a, int b, int c);
    int fn_8007A8DC(int a, int b);
    int fn_8007A914(int a, int b, char* c);
    int fn_8007A94C(int a, int b, int c);
    int fn_8007A984(int a);
    int fn_8007AA10(int a);
    int fn_8007AA84(int a, int b, int i);
    int fn_8007AAEC(int a, int b, int i, int c);
    int fn_8007AB5C(int a, int b, int i);
    int fn_8007AB9C(int a, int b);
    int fn_8007ABFC(int a, int b);
    int fn_8007AC5C(int a, int b, int c);
    int fn_8007ACC4(int a, int b);
    int fn_8007ACFC(int a, int b, int c);
    int fn_8007AD34(int sel, int x, int y);
    int fn_8007ADD0(unsigned sel, int x, int y);
    int fn_8007AE38(int sel, int x, int y);
    int fn_8007AE84(unsigned sel, int x, int y);
    int fn_8007AEBC(int a, int b);
    int fn_8007AF1C(int a, int b);
    int fn_8007AF7C(int a, int b, int c);
    int fn_8007AFE4(int a, int b);
    int fn_8007B01C(int a, int b, int c);
    int fn_8007B054(int a, int b);
    int fn_8007B0B4(int a, int b);
    int fn_8007B114(int a, int b, int c);
    int fn_8007B17C(int a, int b);
    int fn_8007B1B4(int a, int b, int c);
    int fn_8007B1EC();
    int fn_8007B238();
    int fn_8007B284(int a, int i);
    unsigned fn_8007F198(int x);
    int fn_8007F24C(int x, unsigned char i);
    unsigned fn_8007F674(int a, int b);
    int fn_8007F6C4(int a, int b, unsigned i);
    int fn_80080198();
    Unk8007B2B0_Screen* C2() { return (Unk8007B2B0_Screen*)this; }
};

int fn_8052FC1C(Unk8052_Obj* o);
int fn_8052FC34(Unk8052_Obj* o);
int fn_8052FC4C(Unk8052_Obj* o);
int fn_8052FDC8(Unk8052_Obj* o);
int fn_8052FDD8(Unk8052_Obj* o);
int fn_8052FDFC(Unk8052_Obj* o);
int fn_8052FE0C(Unk8052_Obj* o);
int fn_8052FE20(Unk8052_Obj* o);
int fn_8052FE34(Unk8052_Obj* o);
int fn_8052FE48(Unk8052_Obj* o);
int fn_8052FE5C(Unk8052_Obj* o);
int fn_8052FE70(Unk8052_Obj* o);
int fn_8052FE94(Unk8052_Obj* o);
int fn_8059AC0C(Entry* e, int a, int z);
int fn_8059AC80(Entry* e, int a, int b);
int fn_8059AE4C(Entry* e, int a, int b, int c);
int fn_8059AF50(Entry* e, int a, int b, int c, int d);
int fn_8059B158(Entry* e, int a);
int fn_8059B1EC(Entry* e, int a);
int fn_8059B280(Entry* e, int a, int b, int c, int d);
int fn_8059B308(Entry* e, int a, int b, int c);
int fn_8059B3D4(Entry* e, int a, int b);
int fn_8059B47C(Entry* e, int a, int b);
int fn_8059B6AC(Entry* e, int a);
int fn_8059B988(Entry* e, int a);
int fn_8059BAA4(Entry* e, int a);
int fn_8059BCD4(Entry* e, int a, int b);
int fn_8059BCF0(Entry* e, int a, int b);
int fn_8059BD58(Entry* e, int a);
int fn_8059BE14(Entry* e, int a, int b);
int fn_8059D5C4(Entry* e, int a);
int fn_8059D5E8(Entry* e, int a, int b);
int fn_8059D910(Entry* e, int a, int b);
int fn_8059E5D0(Entry* e, int a, int b);
int fn_8059E684(Entry* e, int a, int b);
int fn_8059E708(Entry* e, int a);
int fn_8059F040(Entry* e, int a);
int fn_8059F05C(Entry* e, int a);
int fn_8059F18C(Entry* e, int a);
int fn_8059F64C(Entry* e, int a);
int fn_8059F680(Entry* e, int a);
int fn_8059FA44(Entry* e, int a);
int fn_8059FADC(Entry* e, int a);
int fn_8059FC90(Entry* e, int a);
int fn_8059FCC4(Entry* e);
int fn_8059FD1C(Entry* e);
int fn_8059FD74(Entry* e);
int fn_8059FDCC(Entry* e);
int fn_8059FE24(Entry* e, int a);
int fn_8059FE48(Entry* e, int a);

void fn_800759F8(Unk8007B2B0_Screen* s, int a);
int fn_8008FBE8(int k);
int fn_8008FC40(int k, int j);
int fn_8008FE14(int x);
int fn_8008FD78(int x);
int fn_80079ADC(float f);
void fn_80090540(int o, int a, int t);
void fn_800905FC(int o, int a, int t);
void fn_80590C24(void* p);
struct Unk8007B2B0_Pair {
    float m0;
    int m4;
};
struct Unk8007B2B0_Clamp {
    int v;
    void Next() { v = v > 9 ? v : v + 1; }
};
int fn_800909A4(Handle* h, int a, Obj* o);
void fn_8009230C(Handle* h, int r, int c);
void fn_80092C30(Handle* h, int r, int c);
void fn_80093554(Handle* h, int r, int c);
void fn_80093E78(Handle* h, int r, int c);
void fn_8009479C(Handle* h, int r, int c);
int fn_800918AC(Handle* h, int a);

/*
 * Per-kind table behind Screen::mC[] (fn_80076A24 and fn_80076AE4): a count at +4,
 * then 0x1C-byte records at +8 made of a word and two 12-byte (key, byte) pairs.
 */
struct Unk80076A24_Sub {
    int m0;
    unsigned char m4;
    char pad5[7];
};
struct Unk80076A24_Rec {
    int m0;
    Unk80076A24_Sub m4[2];
};
struct Unk80076A24_Grp {
    int m0;
    unsigned m4;
    Unk80076A24_Rec* m8;
};
struct Unk8007B2B0_Screen {
    char pad0[0x8];
    EntryTable* m8;
    Unk80076A24_Grp* mC[9];
    void* m30;
    char pad34[0x4];
    Handle m38;
    char pad3C[0x4];
    W* m40;
    W* m44;
    Unk8052_Obj* m48;
    Handle m4C;
    char pad50[0x4];
    W* m54;
    char pad58[0x4];
    W* m5C[2];
    W* m64;
    char pad68[0x4];
    Handle m6C;
    char pad70[0x4];
    W* m74;
    char pad78[0x14];
    Handle m8C;
    char pad90[0x4];
    W* m94;
    char pad98[0x14];
    Handle mAC;
    char padB0[0xC];
    Handle mBC;
    char padC0[0x4];
    W* mC4;
    char padC8[0x14];
    Handle mDC;
    char padE0[0xC];
    Handle mEC;
    char padF0[0x4];
    W* mF4;
    char padF8[0x14];
    Handle m10C;
    char pad110[0xC];
    Handle m11C;
    char pad120[0x4];
    W* m124;
    char pad128[0x14];
    Handle m13C;
    char pad140[0xC];
    Handle m14C;
    char pad150[0x4];
    W* m154;
    char pad158[0x14];
    Handle m16C;
    char pad170[0x7C];
    int m1EC;
    char pad1F0[0x4];
    float m1F4;
    float m1F8;
    float m1FC;
    float m200;
    float m204;

    int fn_8007290C(int a);
    int fn_80072934(int a);
    void fn_80072B60();
    void fn_80072B98();
    void fn_80072BD0();
    void fn_80072C28();
    void fn_80072CE8();
    void fn_80072D68();
    void fn_80072DC0();
    int fn_800757B8(int a);
    int fn_80075948(int a);
    int fn_80075C64(int id);
    int fn_80078A38(int a);
    int fn_80079094(int a, int b, int c, int d, int e, int kind);
    int fn_80079264(int a, int b, int c, int d, int e);
    float fn_800799D0(int n);
    float fn_80079A1C();
    int fn_80079A58(float f);
    float fn_80079A90(int n);
    float fn_80079B14(int a);
    float fn_80079B5C(int a, int kind);
    float fn_80079BF8(int a);
    float fn_80079CF8(int a);
    float fn_80079E74(int a);
    float fn_80079EFC(int a);
    float fn_80079F54(int n);
    int fn_80079F90(float f);
    int fn_8007A0D0(int a);
    int fn_8007B2B0();
    int fn_8007B2FC(int a);
    int fn_8007B320(int a, int b);
    int fn_8007B380(int a, int b);
    int fn_8007B3E0(int a, int b);
    int fn_8007B440(int a, int b, int c);
    int fn_8007B4A8(int a, int b, int c);
    int fn_8007B510(int a, int b);
    int fn_8007B570(int a, int b, int c);
    int fn_8007B5D8(int a, int b);
    int fn_8007B610(int a, int b);
    int fn_8007B648(int a, int b);
    int fn_8007B680(int a, int b, int c);
    int fn_8007B6B8(int a, int b, int c);
    int fn_8007B6F0();
    int fn_8007B714();
    int fn_8007B738();
    int fn_8007B75C();
    int fn_8007B780();
    int fn_8007B7A4();
    int fn_8007B7C8();
    int fn_8007B7EC();
    int fn_8007B810();
    int fn_8007B834();
    int fn_8007B858();
    int fn_8007B87C();
    int fn_8007B8A0();
    int fn_8007B8C4(int a, int b);
    int fn_8007B924(int a, int b, char* c);
    int fn_8007B98C(int a, int b, int c);
    char* fn_8007B9F4(int a, int b, char* out);
    int fn_8007BA34(int a, int b, int c);
    int fn_8007BAA8(int a, int b, int c, int d);
    int fn_8007BB28(int a, int b, int c);
    int fn_8007BB9C(int a, int b);
    int fn_8007BBFC(int a, int b, int c);
    int fn_8007BC64(int a, int b, char* c);
    int fn_8007BC9C();
    int fn_8007BCAC(int a, int b, int* c);
    int fn_8007BD94(int a);
    int fn_8007BE10(int a, int b);
    int fn_8007BEA0(int a, int c);
    int fn_8007BEF4(int a, int c);
    int fn_8007BF44(int a, int c);
    int fn_8007BF94(int a, int c);
    int fn_8007BFE4(int a, int c);
    int fn_8007C034(int a, int b);
    void fn_8007C088(int a, int b);
    void fn_8007C134();
    int fn_8007C1D0(int a, int b, int d, Unk8007B2B0_Pair* e);
    int fn_8007C288(int a, int b, Unk8007B2B0_Pair* c, int d, int e, int f);
    void fn_8007C328(int a, int b);
    int fn_8007C3E8();
    int fn_8007C434(int a);
    int fn_8007C458();
    int fn_8007C4A4(int a);
    int fn_8007C4C8();
    int fn_8007C514(int a, int b);
    int fn_8007C574(int a, int b, int c);
    int fn_8007C5DC(int a, int b, char* c);
    int fn_8007C644(int a, int b, int c);
    int fn_8007C67C(int a, int b);
    int fn_8007C6B4();
    int fn_8007C700(int a);
    int fn_8007C724();
    int fn_8007C770(int a, int b);
    int fn_8007C7D0(int a, int b, int c);
    int fn_8007C838(int a, int b, char* c);
    int fn_8007C8A0(int a, int b, int c);
    int fn_8007C8D8();
    int fn_8007C924(int a);
    int fn_8007C948();
    int fn_8007C994(int a, int b);
    int fn_8007C9F4(int a, int b, int c);
    int fn_8007CA5C(int a, int b, char* c);
    int fn_8007CAC4(int a, int b, int c);
    int fn_8007CAFC();
    int fn_8007CB48(int a);
    int fn_8007CB6C();
    int fn_8007CBB8(int a, int b);
    int fn_8007CC18(int a, int b, int c);
    int fn_8007CC80(int a, int b, char* c);
    int fn_8007CCE8(int a, int b, int c);
    int fn_8007CD20();
    int fn_8007CD6C(int a);
    int fn_8007CD90();
    int fn_8007CDDC(int a, int b);
    int fn_8007CE3C(int a, int b, int c);
    int fn_8007CEA4(int a, int b, char* c);
    int fn_8007CF0C(int a, int b, int c);
    int fn_8007CF44(unsigned i, int a, int b);
    int fn_8007CF90(unsigned i, int a);
    Entry* fn_8007CFDC(unsigned i);
    int fn_8007D004(unsigned i, int a, int b);
    int fn_8007D050(unsigned i, int a);
    int fn_8007D098(unsigned i, int a);
    int fn_8007D0E0(unsigned i, int a, int b);
    int fn_8007D12C(unsigned i, int a, int b, int c);
    int fn_8007D180(unsigned i, int a);
    int fn_8007D1C8(unsigned i, int a, int b);
    int fn_8007D214(unsigned i, int a);
    int fn_8007D25C(unsigned i, int a, int b);
    int fn_8007D2A8(unsigned i, int a, int b);
    int fn_8007D2F4(unsigned i, int a, int b);
    int fn_8007D340(unsigned i, int a, int b);
    int fn_8007D38C(unsigned i, int a);
    int fn_8007D3D4(unsigned i, int a);
    int fn_8007D41C(unsigned i, int a);
    int fn_8007D464(unsigned i, int a);
    int fn_8007D4AC(unsigned i, int a);
    int fn_8007D4F4(unsigned i, int a);
    int fn_8007D53C(unsigned i, int a);
    int fn_8007D584(unsigned i, int a);
    int fn_8007D5CC(unsigned i, int a);
    int fn_8007D614(unsigned i);
    int fn_8007D658(unsigned i);
    int fn_8007D69C(unsigned i);
    int fn_8007D6E0(unsigned i);
    int fn_8007D724(unsigned i, int a, int b, int c, int d);
    int fn_8007D77C(unsigned i, int a);
    int fn_8007D7C4(unsigned i, int a);
    int fn_8007D80C(unsigned i, int a);
    int fn_8007D854(unsigned i, int a, int b);
    int fn_8007D8A0(unsigned i, int a, int b);
    int fn_8007D8EC(unsigned i, int a, int b, int c, int d);
    int fn_8007D944(unsigned i, int a, int b, int c);
    int fn_8007D998(unsigned i, int a);
    int fn_8007D9E0(unsigned i, int a);
    int fn_8007DA28();
    int fn_8007DA34(int i);
    void fn_8007DA58(int a);
    void fn_8007DA8C(int a, int b);
    int fn_8007DADC(unsigned i);
    void fn_8007DB0C(unsigned i);
    void fn_8007DB40(unsigned i);
    Unk8007A4DC_Screen* C1() { return (Unk8007A4DC_Screen*)this; }
    int fn_80079ADC(float f);
    Entry* At(unsigned i) { return i < m8->count ? &m8->e[i] : 0; }
};

#endif
