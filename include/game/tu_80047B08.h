#ifndef GAME_TU_80047B08_H
#define GAME_TU_80047B08_H

#include "game/tu_80046964.h"

/*
Types for game/tu_80047B08.cpp (see tu_80044C10.h for the shared game object and
the Unk8004763C manager).
*/

void fn_80392708();
void fn_80392DF4();
void fn_803EDA0C(void* p);
void fn_80377488(void* p); /* __builtin_vec_delete */
void fn_803917D0(int a);
void fn_80057778(void* p);
void fn_80057950(void* p);
void* fn_8005BA9C(void* p);
void fn_8005C654(void* a, void* b, int c, int d);
int fn_80048E50(Unk80048A10_Sub* p, unsigned id, float f, int* a, void* b, void* w);
void* fn_8040B320(void* dst, int c, unsigned n); /* memset */
void fn_80049090(Unk80048A10_Sub* p, int a);
void fn_800490D0(Unk80048A10_Sub* p);
void fn_800490F8(Unk80048A10_Sub* p);
void fn_800490FC(Unk80048A10_Sub* p);
/* 0xD8-byte records at 0x805B09F4 (voice channels): the word at +0xD4 is -1 when free. */
struct Unk80047B08_Chan {
    char pad0[0xD4];
    int mD4;
};
extern Unk80047B08_Chan lbl_805B09F4[];
extern char lbl_80649AB0[];
void fn_800575E4(void* sink, int c);

/* Object held at Sub + 0xADC: 0x7E0 data bytes, then the vptr; slot 1 is the virtual destructor (fn_80048B2C). */
struct Unk80048B2C_Base {
    char pad0[0x7E0];
};
class Unk80048B2C_Obj : public Unk80048B2C_Base {
public:
    virtual ~Unk80048B2C_Obj();
};
void fn_80048464(Unk8004763C* t, int i);
extern int lbl_80617804;
extern int lbl_80617808;
void fn_80048DA4(Unk80048A10_Sub* s);
void fn_80048F84(Unk80048A10_Sub* s, int i, int v);
/* 0xB0-byte rows at 0x805B10B4: fn_8004801C and fn_80048294 read the words at +0x80 (one per slot). */
struct Unk80047B08_Row {
    char pad0[0x80];
    int m80[8];
    char padA0[0x10];
};
extern Unk80047B08_Row lbl_805B10B4[];
extern char lbl_805B0A95[];
struct Unk8005BA1C_Obj;
Unk8005BA1C_Obj* fn_8005BA9C();
void fn_8005C384(Unk8005BA1C_Obj* o, int i);
int fn_802B96C4(const char* name, int a);
int fn_802B9300(const char* name, int a, int b, int* out);
int fn_80395250(int buf, int x);
extern char lbl_805B0A09[];
/* Callback record returned by fn_80395864 (three function pointers; fn_80047B08 fills them). */
struct Unk80047B08_Cb {
    void (*m0)();
    void (*m4)();
    void (*m8)();
};
extern "C" Unk80047B08_Cb* fn_80395864();
extern "C" void fn_80377814();
extern "C" void fn_80400DA4();
void fn_80047B04();
void fn_8001B950(unsigned a);
void fn_8001B9C0(void* p);
void fn_80044C98(Unk80044C98_Arg* a);
void fn_8004483C(int a, int b, int c);
void fn_80044B94(int a, int b, int c);
void fn_80044C10();
extern "C" void fn_80392B6C(void (*a)(unsigned), void (*b)(void*));
extern "C" int fn_80392C28(int a, int b, int c);
extern "C" void fn_80392D08(void (*a)(Unk80044C98_Arg*), int b, int c);
extern "C" void fn_80392C94(void (*a)(int, int, int), void (*b)(int, int, int));
extern "C" void fn_80392CE4(void (*a)());
extern "C" int fn_803913F4(int a);
extern "C" void fn_803913FC(int a, int b);
void* operator new[](unsigned int size, int heap); /* 0x803774A8 */
struct Unk800642F0 {
    Unk800642F0();
    int fn_800644CC();
    char pad0[0x40];
};
extern Unk800642F0* lbl_80618FBC;
int fn_800480FC(Unk8004763C* t);
extern "C" int fn_80329C4C(const char** pp, unsigned* pn, int* out, int lo, int hi, int delim);
extern "C" int fn_80329DF0(const char* name, const char** pbuf, unsigned* plen);
extern "C" void fn_80329E50(const char* buf);
struct Unk800652F4 {
    Unk800652F4();
    void fn_80065338();
    char pad0[0x7E4];
};
extern "C" void* fn_80057370(void* obj, void* owner);
void fn_80048C08(Unk80048A10_Sub* s);
int fn_8040ABA0();
void fn_80057A4C(void* mgr);
void fn_800449D8();
/* 12-byte entries at 0x8061780C: a key word, then a pointer to member function of the sub-manager. */
class Unk8061780C_Cls {
public:
    virtual void f0(int, int);
};
struct Unk8061780C_Ent {
    int key;
    void (Unk8061780C_Cls::*fn)(int, int);
};
extern Unk8061780C_Ent lbl_8061780C[];

#endif
