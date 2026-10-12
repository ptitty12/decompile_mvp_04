/*
 * Types for the database overlay units db/tu_80584CBC .. db/tu_805942E0
 * (range 45). Names are placeholders: Db<addr> for the first function that
 * proves a type, m<offset> for offsets.
 */
#ifndef GAME_DB_80584CBC_H
#define GAME_DB_80584CBC_H

#include "game/overlay.h"
#include "game/tu_8052A220.h"
/* tu_8007A4DC.h declares fn_80402EF8 with C++ linkage; the symbol is plain. */
#define fn_80402EF8 db_fn_80402EF8_cxx
#include "game/tu_8007A4DC.h"
#undef fn_80402EF8
#include "game/tu_8007F198.h"
#include "game/clampiter.h"


/* Text helpers shared by the overlay formatter slots (wide strings are unsigned short). */
struct Unk80090880;
char* fn_80090880(Unk80090880* p); /* real signature (p, id); called through DbLook */
typedef unsigned short* (*DbLook)(Unk80090880*, int);
extern Unk80090880* lbl_8061977C;
#define DBTXT(id) ((DbLook)fn_80090880)(lbl_8061977C, (id))
extern "C" {
unsigned short* fn_804031BC(unsigned short* dst, const char* src); /* ascii -> wide */
int fn_80403DE4(unsigned short* dst, const unsigned short* fmt, ...); /* wide sprintf */
void fn_80403144(unsigned short* dst, const unsigned short* src); /* wide strcpy */
int fn_8040321C(unsigned short* dst, const unsigned short* fmt, const unsigned short* a, const unsigned short* b);
void fn_80402EF8(unsigned short* dst, const char* src); /* ascii -> wide */
void fn_80119FF0(char* buf, float f);
void fn_80119F48(char* buf, float f);
int fn_804089B4(char* dst, const char* fmt, ...); /* sprintf */
}
int fn_800E6058(int x);
void fn_800DE538(int out, int a, int b, int c);

/* Stack record built by fn_8052E408 and destroyed by fn_80360AF0 (in_chrg 2). */
struct Db80586420_Ent;
extern "C" {
Db80586420_Ent* fn_8052E408(Db80586420_Ent* self);
void fn_80360AF0(Db80586420_Ent* self, int chrg);
}
struct Db80586420_Ent {
    int m0;
    int m4;
    int m8;
    Unk8052DD58_Bits mC;
    unsigned short m10;
    unsigned short m12;
    const void* m14;
    Db80586420_Ent(void* src) { ((Db80586420_Ent * (*)(Db80586420_Ent*, void*)) fn_8052E408)(this, src); }
    Db80586420_Ent() { fn_8052E408(this); }
    int GetM8() { return m8; }
    int HasE() { return mC.e != 0; }
    ~Db80586420_Ent() { fn_80360AF0(this, 2); }
};
struct Db80586420_Tri {
    int a;
    int b;
    int c;
};
extern "C" {
/* Base of the overlay screen/list classes: ctor fn_805822D0, vptr at +4. */
struct Db805822D0_Base {
    int m0;
    const void* m4;
};
extern "C" Db805822D0_Base* fn_805822D0(Db805822D0_Base* self);
struct Db800B555C_Obj;
Db800B555C_Obj* fn_800B555C();
int fn_800B5758(Db800B555C_Obj* o);
void fn_8058233C(void* self);
int fn_80582DF4(int a, int b, Db80586420_Tri t);
}

#endif
