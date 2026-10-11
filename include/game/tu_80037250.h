#ifndef GAME_TU_80037250_H
#define GAME_TU_80037250_H

/*
 * Types for src/game/tu_80037250.cpp (reconstructed). The unit's tail is the
 * controller of a 0x5300-byte singleton (ctor fn_80038570, factory fn_80038EB4,
 * dtor fn_80038F00, pointer at 0x80616F0C): a table of CSV-loaded cue data in
 * the first 0x5288 bytes (addressed by tu_80034BBC.h's Unk80038EB4_Tbl), then
 * the playback state below.
 */

struct Unk80038570_Obj5D0 {
    char pad0[0x5D0];
    int m5D0;
};

struct Unk80038570_Obj734 {
    char pad0[0x734];
    int m734;
};

struct Unk80038570 {
    char pad0[0x5288];
    int m5288;
    int m528C[8];
    int m52AC;
    int m52B0;
    int m52B4;
    int m52B8;
    int m52BC;
    int m52C0;
    int m52C4;
    int m52C8;
    char pad52CC[0x52F0 - 0x52CC];
    int m52F0;
    char pad52F4[0x52FC - 0x52F4];
    int m52FC;
    ~Unk80038570();
};

extern Unk80038570* lbl_80616F0C;
extern int lbl_80616F10;
extern int lbl_80616EEC;
extern Unk80038570_Obj734* lbl_80616EF0[2];
extern int lbl_80616EF8;
extern int lbl_80616EFC;
extern int lbl_80616F00;
extern int lbl_80616F04;
extern int lbl_80616F08;
extern char lbl_80687354[];
extern char lbl_8068735C[];
extern char lbl_8068742C[];

void* operator new(unsigned int size, int heap); /* 0x80377428 */

struct Unk800360F4 {
    char buf[0x80];
    const void* vptr;
};

extern const char* lbl_80616E88;
extern const char* lbl_80616E8C;
extern const char* lbl_80616E90;
extern const char* lbl_80616E94;
extern const char* lbl_80616E98;
extern const char* lbl_80616E9C;
extern const char* lbl_80616EA0;
extern const char* lbl_80616EA4;
extern const char* lbl_80616EA8;
extern const char* lbl_80616EAC;
extern const char* lbl_80616EB0;
extern const char* lbl_80616EB4;
extern const char* lbl_80616EB8;
extern const char* lbl_80616EBC;
extern const char* lbl_80616EC0;
extern const char* lbl_80616EC4;
extern const char* lbl_80616EC8;
extern const char* lbl_80616ECC;
extern const char* lbl_80616ED0;
extern const char* lbl_80616ED4;
extern const char* lbl_80616ED8;
extern const char* lbl_80616EDC;

extern "C" {
Unk800360F4* fn_800360F4(Unk800360F4* s);
void fn_80036108(Unk800360F4* s, int chrg);
void fn_802B9098(const char* s);
void fn_802B90EC();
void fn_80036BCC(char* buf, int out, const char* text);
void fn_80036D70(char* buf, int out, const char* text);
void fn_80036F14(char* buf, int out, const char* text);
void fn_800370B8(char* buf, int out, const char* text, int lo3, int hi3, int lo5, int hi5);
void fn_80037250(char* buf, int out, const char* text);
void fn_800373A4(char* buf, int out, const char* text, int lo, int hi);
void fn_80037530(char* buf, int out, const char* text, int lo, int hi);
void fn_800376EC(char* buf, int out, const char* text);
void fn_80037834(char* buf, int out, const char* text);
void fn_800379A4(char* buf, int out, const char* text);
void fn_80037B44(char* buf, int out, const char* text);
void fn_80037D0C(char* buf, int out, const char* text);
void fn_80037EE0(char* buf, int out, const char* text, int lo, int hi);
void fn_800380D4(char* buf, int out, const char* text, int lo, int hi);
void fn_800382BC(char* buf, int out, const char* text, int lo, int hi);
void fn_80038424(char* buf, int out, const char* text);
Unk80038570* fn_80038570(Unk80038570* s);
const char* fn_802B9300(const char* s, int a, int b, unsigned int* outn);
void fn_802B961C(const char* p, int a);
void fn_803792AC(const char** pp, unsigned int* pn);
int fn_800365A4(char* buf, int* out, const char** pp, unsigned int* pn);
int fn_800361D8(char* buf, const char** pp, unsigned int* pn, int* out, int lo, int hi, int delim);
int fn_800362B4(char* buf, int* out, const char** pp, unsigned int* pn);
int fn_80036628(char* buf, int* out, const char** pp, unsigned int* pn);
int fn_800366A8(char* buf, int* out, const char** pp, unsigned int* pn);
int fn_80036728(char* buf, int* out, const char** pp, unsigned int* pn);
int fn_800367A8(char* buf, int* out, const char** pp, unsigned int* pn);
int fn_80036828(char* buf, int* out, const char** pp, unsigned int* pn);
int fn_800368A8(char* buf, int* out, const char** pp, unsigned int* pn);
int fn_80036928(char* buf, int* out, const char** pp, unsigned int* pn);
int fn_800369A8(char* buf, int* out, const char** pp, unsigned int* pn);
int fn_8003641C(char* buf, unsigned char* out, const char** pp, unsigned int* pn);
void fn_80039E94();
void fn_80039C20(Unk80038570* s);
void fn_80039F04(Unk80038570* s);
void fn_80039F24();
int fn_80039D38(Unk80038570* s, int i);
void fn_80039DBC(Unk80038570* s, int i); /* reads i from r4 (tu_80039B04.cpp) */
void fn_80306AC0(int a, int b);
void fn_803BA7C4(void* tbl, int* v);
int fn_80039178(Unk80038570* s);
void fn_80039664(Unk80038570* s);
void fn_80039988(Unk80038570* s);
void fn_800393B0(Unk80038570* s, int i);
void fn_800398E4(Unk80038570* s, float f);
void fn_80039B04(int a, unsigned int b);
void fn_80039790(Unk80038570* s, float f);
void fn_80039854(Unk80038570* s, int a, float f);
struct Unk805B17A0_Ent {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};
extern Unk805B17A0_Ent lbl_805B17A0[];
void* fn_8004072C();
int fn_800412AC(void* o, int id, int a, int b, int c, int d);
void fn_8004181C(void* o, int id, int h, int a, int b, int c, int d);
void fn_80039A3C(int a, unsigned int b, unsigned int c);
}

#endif /* GAME_TU_80037250_H */
