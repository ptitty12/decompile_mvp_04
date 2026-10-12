/*
 * Types for the database overlay units db/tu_80584CBC .. db/tu_805942E0
 * (range 45). Names are placeholders: Db<addr> for the first function that
 * proves a type, m<offset> for offsets.
 */
#ifndef GAME_DB_80584CBC_H
#define GAME_DB_80584CBC_H

#include "game/overlay.h"
/* tu_8052A220.h declares fn_80329FA0 with a 4-byte result; the real frame slot is bigger (BLKmode). */
#define fn_80329FA0 db_fn_80329FA0_hdr
#include "game/tu_8052A220.h"
#undef fn_80329FA0
/* tu_8007A4DC.h declares fn_80402EF8 with C++ linkage; the symbol is plain. */
#define fn_80402EF8 db_fn_80402EF8_cxx
#include "game/tu_8007A4DC.h"
#undef fn_80402EF8
#include "game/tu_8007F198.h"
#include "game/clampiter.h"


struct Db80329FA0_Out {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned short m4;
};
extern "C" Db80329FA0_Out fn_80329FA0(int v, ...);

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


/* Unit 0x8058E5B8: screen-like object; fn_8058F08C / fn_8058F114 touch m42C and m434. */
struct Db8058F08C_S {
    char pad0[0x42C];
    int m42C;
    int m430;
    int m434;
};
/* Serialized stack-list record: m38 count, m3C current index, items from +0x20 (fn_8058FA5C/7C/AC8/AD0). */
struct Db8058FA5C_L {
    char pad0[0x20];
    int m20[4];
    int m30;
    int m34;
    int m38;
    int m3C;
};


/*
 * List classes of unit 0x8058E5B8: three data words, the vptr at +0xC (virtual
 * count at vtable +0x10, virtual +0x38 clears), then the payload. Db8058F62C_P is
 * the plain mirror the constructors write through (they store lbl_ vtables
 * themselves); Db8058F62C_V / Db8058F840_V carry the virtual calls.
 */
struct Db8058F62C_Data {
    int m0;
    int m4;
    int m8;
};
struct Db8058F62C_V : Db8058F62C_Data {
    virtual int v08();
    virtual int v10();
    virtual int v18();
    virtual int v20();
    virtual int v28();
    virtual int v30();
    virtual int v38(int a);
};
struct Db8058F62C_L : Db8058F62C_V {
    unsigned short m10[0x13];
    unsigned short m36;
    unsigned short m38;
    int m3C[17];
};
struct Db8058F62C_P : Db8058F62C_Data {
    const void* mC;
    unsigned short m10[0x13];
    unsigned short m36;
    unsigned short m38;
    int m3C[17];
};
struct Db8058F840_V : Db8058F62C_Data {
    virtual int v08();
    virtual int v10();
};
struct Db8058F840_L : Db8058F840_V {
    int m10;
    int m14[4];
};
struct Db8058F840_P : Db8058F62C_Data {
    const void* mC;
    int m10;
    int m14[4];
};


/*
 * Unit 0x8059377C: a global manager (lbl_80619948) with two 0x10-stride row tables
 * selected by fn_800A2EB4 (fn_805937A4 searches them for an id). Rows: id at +0,
 * a word at +4, a float at +8, a byte at +0xC (fn_80593880/E8/4C read them).
 */
struct Db805937A4_Row {
    int m0;
    int m4;
    float m8;
    unsigned char mC;
    char pad[3];
};
struct Db805937A4_Mgr {
    char pad0[0x10480];
    Db805937A4_Row a[612];
    Db805937A4_Row b[11];
    int m12B70;
    int m12B74;
    float m12B78;
    char pad12B7C[0xC];
    int m12B88;
    int m12B8C;
};
extern "C" int fn_800A2EB4(void* p);
extern void* lbl_80619948;

/*
 * Gauge-like table (ctor fn_80593CD0): manager pointer m0, slot count m14, 0x14-byte
 * entries behind m10, a per-slot counter array m18, vptr at +0x1C.
 */
struct Db80593CD0_Ent {
    float m0;
    float m4;
    int m8;
    int mC;
    int m10;
    Db80593CD0_Ent() { m4 = m0 = 0.0f; m8 = 0; mC = 0; m10 = 0; }
};
struct Db80593CD0_Data {
    Db805937A4_Mgr* m0;
    int m4;
    float m8;
    int mC;
    Db80593CD0_Ent* m10;
    int m14;
    int* m18;
    void Clear()
    {
        int i = 0;
        if (i < m14) {
            int off = 0;
            do {
                *(int*)(off + (int)m18) = 0;
                i++;
                off += 4;
            } while (i < m14);
        }
    }
};
struct Db80593CD0_P : Db80593CD0_Data {
    const void* m1C;
};


/*
 * Unit 0x8058E5B8, second half: classes derived from the slot table (vptr at +0x1C).
 * Db8058F924_V carries the virtual calls (slot index = vtable byte offset / 8);
 * Db8058F924_L adds the data after the vptr: six ints at +0x20, a count at +0x38, the
 * current index at +0x3C, a sub-object pointer at +0x40 and six rows of five ints.
 */
struct Db8058F924_V : Db80593CD0_Data {
    virtual void v08(int chrg);
    virtual void v10(int k, int a, float f0, float f1);
    virtual void v18(int k, int a);
    virtual void v20();
    virtual void v28();
    virtual void v30(int a, int b);
    virtual void v38();
    virtual void v40();
    virtual int v48();
    virtual int v50();
    virtual void v58();
    virtual void v60(int a, float f0, float f1);
    virtual void v68();
    virtual void v70();
    virtual void v78();
    virtual void v80();
};
struct Db8058F924_L : Db8058F924_V {
    int m20[6];
    int m38;
    int m3C;
    Db8058F924_V* m40;
    int m44[6][5];
};
struct Db8058F924_P : Db80593CD0_P {
    int m20[6];
    int m38;
    int m3C;
    Db8058F924_V* m40;
    int m44[6][5];
};


/*
 * Unit 0x805942E0: float-slot table (ctor fn_805942E0): manager pointer m0, a user value m4,
 * 0x14-byte entries behind m8, slot count mC, float array m10, vptr at +0x14.
 */
struct Db805942E0_Ent {
    float m0;
    float m4;
    float m8;
    float mC;
    int m10;
    Db805942E0_Ent() { m10 = 0; mC = m8 = m4 = m0 = 0.0f; }
};
struct Db805942E0_Data {
    Db805937A4_Mgr* m0;
    int m4;
    Db805942E0_Ent* m8;
    int mC;
    float* m10;
};
struct Db805942E0_P : Db805942E0_Data {
    const void* m14;
};
struct Db805942E0_V : Db805942E0_Data {
    virtual void v08(int chrg);
    virtual void v10();
    virtual void v18();
    virtual void v20();
    virtual void v28();
    virtual Db805942E0_Ent* v30(int i);
};


/*
 * Unit 0x805902E0: the manager at lbl_80619948's save block, seen from its float tables.
 * Three 16-float-per-row tables at +0, +0x340 and +0x440 (row stride 0x40, indexed
 * (row << 6) + slot * 4), then the row arrays of Db805937A4_Mgr at 0x10480 and the
 * counters at 0x12B70... (fn_805919E8 / fn_80591AF4 add to and subtract from them).
 */
struct Db805922EC_Cell {
    float m0;
    int m4;
    int m8;
};
struct Db805922EC_Grp {
    Db805922EC_Cell c[4][16];
};
struct Db805919E8_M {
    float t0[13][16];
    float t1[4][16];
    float t2[13][16];
    float t3[4][16];
    Db805922EC_Grp a[85];
    char pad10780[0x109C0 - 0x10780];
    Db805922EC_Grp b[11];
    char pad12AC0[0x12B70 - 0x12AC0];
    int m12B70;
    int m12B74;
    float m12B78;
    float m12B7C;
    int m12B80;
    int m12B84;
};

#endif
