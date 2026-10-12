/*
 * Types and callee declarations for the database overlay units db/tu_8056BAEC ..
 * db/tu_80582578 (range 44). Names are placeholders: Db<addr> for the first function
 * that proves a type, m<off> for offsets.
 *
 * Callees whose retail symbol is a C++-mangled name (fn_XXXXXXXX__F...) are declared
 * extern "C" under that exact symbol name: their real classes live in other units and
 * only the argument classes matter here (pointers are void*).
 */
#ifndef GAME_DB_8056BAEC_H
#define GAME_DB_8056BAEC_H

#include "game/overlay.h"

void* operator new(unsigned int size, int heap); /* 0x80377428 */

/* 12-byte record behind fn_80081D08 (Unk8007FF8C_Q): byte at +0, int at +4 and +8. */
struct DbQ {
    unsigned char m0;
    unsigned char m1;
    int m4;
    int m8;
};
extern "C" DbQ* fn_80081D08__FP13Unk8007FF8C_Yi(void* y, int i);

extern "C" {
int fn_8006A214__11Unk80069F0C(void* a0);
int fn_8006BE18__11Unk80069F0C(void* a0);
int fn_8007189C__FP1Wii(void* a0, int a1, int a2);
int fn_8007366C__FPCcT0(const char* a0, const char* a1);
int fn_800736EC__FPCc(const char* a0);
int fn_800758F8__Fi(int a0);
int fn_80075948__18Unk8007B2B0_Screeni(void* a0, int a1);
int fn_80076644__Fiii(int a0, int a1, int a2);
int fn_80077238__18Unk8007A4DC_Screenii(void* a0, int a1, int a2);
int fn_80077320__18Unk8007A4DC_Screenii(void* a0, int a1, int a2);
int fn_80077404__18Unk8007A4DC_Screenii(void* a0, int a1, int a2);
int fn_80077684__18Unk8007A4DC_Screenii(void* a0, int a1, int a2);
int fn_8007776C__18Unk8007A4DC_Screenii(void* a0, int a1, int a2);
int fn_80077850__18Unk8007A4DC_Screenii(void* a0, int a1, int a2);
int fn_80077934__18Unk8007A4DC_Screenii(void* a0, int a1, int a2);
int fn_80078A38__18Unk8007B2B0_Screeni(void* a0, int a1);
int fn_80078A64__18Unk8007A4DC_Screeniii(void* a0, int a1, int a2, int a3);
int fn_800799D0__18Unk8007B2B0_Screeni(void* a0, int a1);
float fn_80079E74__18Unk8007B2B0_Screeni(void* a0, int a1);
unsigned fn_8007A0D0__18Unk8007B2B0_Screeni(void* a0, int a1);
int fn_8007A11C__18Unk8007A4DC_Screeni(void* a0, int a1);
int fn_8007A270__18Unk8007A4DC_Screeni(void* a0, int a1);
int fn_8007A3FC__18Unk8007A4DC_Screenii(void* a0, int a1, int a2);
int fn_8007A6A0__18Unk8007A4DC_Screenii(void* a0, int a1, int a2);
int fn_8007A8DC__18Unk8007A4DC_Screenii(void* a0, int a1, int a2);
int fn_8007B320__18Unk8007B2B0_Screenii(void* a0, int a1, int a2);
int fn_8007B380__18Unk8007B2B0_Screenii(void* a0, int a1, int a2);
int fn_8007B8C4__18Unk8007B2B0_Screenii(void* a0, int a1, int a2);
int fn_8007B924__18Unk8007B2B0_ScreeniiPc(void* a0, int a1, int a2, char* a3);
int fn_8007B98C__18Unk8007B2B0_Screeniii(void* a0, int a1, int a2, int a3);
int fn_8007BA34__18Unk8007B2B0_Screeniii(void* a0, int a1, int a2, int a3);
float fn_8007BB28__18Unk8007B2B0_Screeniii(void* a0, int a1, int a2, int a3);
int fn_8007D9E0__18Unk8007B2B0_ScreenUii(void* a0, unsigned a1, int a2);
int fn_8007DA28__18Unk8007B2B0_Screen(void* a0);
int fn_8007DA34__18Unk8007B2B0_Screeni(void* a0, int a1);
int fn_8007DBBC__FP13Unk8007DB74_Ai(void* a0, int a1);
int fn_8007F198__FP13Unk8007F198_A(void* a0);
int fn_8007F24C__FP13Unk8007F198_Aii(void* a0, int a1, int a2);
int fn_8007F4D0__FP13Unk8007F198_Aii(void* a0, int a1, int a2);
int fn_8007F7D0__FP13Unk8007F198_BUi(void* a0, unsigned a1);
int fn_8007F87C__FP13Unk8007F198_Bi(void* a0, int a1);
int fn_8007F9B4__FP13Unk8007F198_C(void* a0);
int fn_8007FB2C__FP13Unk8007F198_Ci(void* a0, int a1);
int fn_8007FB40__FP13Unk8007F198_Ci(void* a0, int a1);
int fn_8007FB6C__FP13Unk8007F198_Ci(void* a0, int a1);
int fn_8007FB98__FP13Unk8007F198_Ciii(void* a0, int a1, int a2, int a3);
int fn_8007FC00__FP13Unk8007F198_Cii(void* a0, int a1, int a2);
int fn_8007FD2C__FP13Unk8007F198_Ciii(void* a0, int a1, int a2, int a3);
int fn_8007FDA8__FP13Unk8007F198_Cii(void* a0, int a1, int a2);
int fn_8007FDF8__FP13Unk8007F198_D(void* a0);
int fn_8007FE04__FP13Unk8007F198_D(void* a0);
int fn_80080028__FP13Unk8007FF8C_G(void* a0);
int fn_8008004C__FP13Unk8007FF8C_G(void* a0);
int fn_80080070__FP13Unk8007FF8C_G(void* a0);
int fn_8008007C__FP13Unk8007FF8C_GUi(void* a0, unsigned a1);
int fn_800800A4__FP13Unk8007FF8C_G(void* a0);
int fn_80080B98__FP13Unk8007FF8C_Q(void* a0);
int fn_80080BB4__FP13Unk8007FF8C_Qiii(void* a0, int a1, int a2, int a3);
int fn_80081C94__FP13Unk8007FF8C_Yiiii(void* a0, int a1, int a2, int a3, int a4);
int fn_80081CCC__FP13Unk8007FF8C_Yi(void* a0, int a1);
DbQ* fn_80081CF8__FP13Unk8007FF8C_Yi(void* a0, int a1);
int fn_80081D18__FP13Unk8007FF8C_Yii(void* a0, int a1, int a2);
int fn_80081D70__FP13Unk8007FF8C_Y(void* a0);
int fn_80083FC0__Fi(int a0);
int fn_80084114__Fi(int a0);
int fn_800844A8__Fi(int a0);
int fn_8008453C__FiiPiT2(int a0, int a1, int* a2, int* a3);
int fn_800845E4__Fi(int a0);
int fn_8008463C__Fi(int a0);
int fn_80084660__Fi(int a0);
int fn_800848EC__Fi(int a0);
int fn_80084910__FPviii(void* a0, int a1, int a2, int a3);
int fn_80084954__FPv(void* a0);
int fn_80084978__FPv(void* a0);
int fn_8008499C__FPv(void* a0);
int fn_80089AA0__FP20Unk80089894_PackTabDUiUi(void* a0, unsigned a1, unsigned a2);
int fn_80089E48__FP15Unk80089894_Objii(void* a0, int a1, int a2);
int fn_80089EE0__FP20Unk80089894_PackTabDUiUii(void* a0, unsigned a1, unsigned a2, int a3);
int fn_8008FE14__Fi(int a0);
int fn_8009005C__Fif(int a0, float a1);
int fn_80090880__FP11Unk80090880(void* a0);
int fn_800DD44C__FP13Unk800DD610_PPvi(void* a0, void* a1, int a2);
int fn_800DE538__Fiiii(int a0, int a1, int a2, int a3);
int fn_802B8E1C__Fv();
int fn_802B8E84__Fv();
int fn_8035A2D0__FPvi(void* a0, int a1);
int fn_8035B4A0__FPvi(void* a0, int a1);
int fn_8035B4D4__FPvi(void* a0, int a1);
int fn_8035B508__FPvi(void* a0, int a1);
}


extern "C" void fn_8037893C(void* q, int id, void* e, int a, int b); /* post an event (id, event object at +4 vptr) */
extern "C" {
float fn_8056FFB0(void); /* random float in [0, 1) from the global generator */
unsigned fn_8014D8AC(void* rng, int max, const char* file, int line);
int fn_80097210(void* team, int a);
int fn_800971C8(void* team, int a);
int fn_80097148(void* team, int a);
int fn_8008CFD8(char* p, int a, int b);
void fn_8040074C(void* p, unsigned n); /* bzero */
int fn_8040ABA0(void);
}
extern char lbl_80649DA0[];
extern int lbl_8060558C[2];

/*
 * Game-state object behind screen->m14->m14 (Unk8007FF8C_Y in tu_8007FF8C.h): two 0xE64-byte
 * per-side sub-objects from +0, then the side flag at +0x1CD0. Evidence: fn_8056BEC8,
 * fn_8056C0A0, fn_8056C1C4 (side selection through m1CD0, record stride 0xE64).
 */
struct DbEnt34 {
    int m0;
    char pad4[0x30];
};
struct DbT {
    char pad0[0x168];
    unsigned char* m168;
    char pad16C[0x174 - 0x16C];
    int m174;
    char pad178[4];
    unsigned char m17C;
    unsigned char m17D;
    char pad17E[0x3E8 - 0x17E];
    DbEnt34 m3E8[1];
    char pad41C[0xE64 - 0x41C];
};
struct DbG {
    DbT t[2];
    unsigned char m1CC8;
    unsigned char m1CC9;
    char pad1CCA[2];
    int m1CCC;
    int m1CD0;
};
inline int Round(DbG* g)
{
    return g->m1CC9;
}
inline DbT* TeamAt(DbG* g, int i)
{
    return (DbT*)((char*)g + i * 0xE64);
}
/* Word 0 of the 0x34-byte record i (base-first indexed load; the base is a parameter, not a pointer local). */
inline int EntAt(DbEnt34* base, int i)
{
    int o = i * 0x34;
    return *(int*)((char*)base + o);
}
struct DbScrB {
    char pad0[0x14];
    DbG* m14;
};
/* Screen-like object: m10 flag, m14 -> DbScrB. */
struct DbScr {
    char pad0[0x10];
    int m10;
    DbScrB* m14;
};

/*
 * Event objects built on the stack and posted with fn_8037893C: id at +0, vptr at +4
 * (base vtable lbl_80649DA0, restored by the inline destructors), fields from +8.
 * The derived classes' vtables are retail data objects (lbl_ names in the comments).
 */
class DbEv {
public:
    DbEv(int id) { m0 = id; }
    int m0;
    virtual ~DbEv() {}
};

/*
 * Selection state over the three leading Q records of the game state (fn_80081CF8 index 0..2),
 * built by fn_8056DE50 (sizeof 0x30; embedded at +0xCC of the menu object of db/tu_8056EC68).
 */
struct DbSrcC {
    char pad0[0x84];
    int m84;
};
struct DbSelSrcB {
    char pad0[0x20];
    int m20;
    char pad24[4];
    int m28;
};
struct DbSelSrc {
    char pad0[0xC];
    DbSrcC* mC;
    DbSelSrcB* m10;
    DbG* m14;
};
struct DbSel {
    DbQ* m0;
    DbQ* m4;
    DbQ* m8;
    DbSelSrc* mC;
    DbG* m10;
    int* m14;
    DbScr* m18;
    void* m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
};

/* 0x18-byte entry of DbSub50 (a counter and five floats; entry 0 at +0x14). */
struct DbEnt18 {
    int m0;
    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
};
/*
 * Sub-object at +0x50 of DbMgr (sizeof 0x7C): side flag and its complement at +0/+4, two DbEnt18
 * at +0x14, thirteen floats from +0x44, two flags at +0x74/+0x78. Evidence: fn_80573840 (ctor
 * clearing the floats), fn_805738F0, fn_80573D44, fn_80573D84.
 */
struct DbSub50 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    DbEnt18 e[2];
    float m44, m48, m4C, m50, m54, m58, m5C, m60, m64, m68, m6C, m70;
    int m74;
    int m78;
};

/*
 * Menu object of db/tu_8056EC68 (sizeof >= 0x11C): source object at +8, game state at +0xC, a
 * sub-object at +0x50, the selection state DbSel at +0xCC (0x30 bytes), a DbScr at +0xFC and a
 * mode word at +0x118. Evidence: fn_8057001C, fn_805700C0 (ctors), fn_805715D8, fn_805718E8.
 */
struct DbMgr {
    int m0;
    char pad4[4];
    DbSelSrc* m8;
    DbG* mC;
    int m10;
    int m14;
    char pad18[0x50 - 0x18];
    DbSub50 m50;
    DbSel mCC;
    DbScr mFC;
    char pad114[4];
    int m118;
};
extern "C" {
void fn_8056BA20(void* p, int c);
void fn_8056BA80(DbScr* scr, DbSelSrc* src, int flag);
void fn_8056BACC(DbScr* p);
void fn_80573840(DbSub50* p);
void fn_80573918(DbSub50* p, DbSelSrc* src);
void fn_8056F228(DbSel* s);
void fn_8056C2B4(DbScr* p);
void fn_8056C520(DbScr* p);
void fn_8056C6BC(DbScr* p);
void fn_8056DEF4(DbSel* p);
void fn_8056E130(DbSel* p);
void fn_8056BD50(void* q);
void fn_80377408(void* p);
}

#endif
