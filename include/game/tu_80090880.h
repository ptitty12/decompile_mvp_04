/*
 * Types for the table-manager classes at 0x80090880..0x800A8684
 * (units game/tu_80090880 .. game/tu_800A4668; the original source path in the
 * strings is /mvp2004/source/common/database/tablemanager.cpp). Reconstructed
 * from the vtables (lbl_8064xxxx) and the calls the unit makes; everything is
 * named by offset (m<off>), vtable slot (v<N>) or address (Unk<addr>).
 */
#ifndef GAME_TU_80090880_H
#define GAME_TU_80090880_H

void* operator new(unsigned int size, int heap); /* 0x80377428 */
void* operator new[](unsigned int size, int heap); /* 0x803774A8 */

/*
 * Database object built by fn_803779B8 (size 0x18, vptr at +0x14).
 * Evidence: ctor args in the v5 slots (fn_80091240 etc.), m4/mC read in
 * fn_80090A24, virtual dtor called with 3 in the v6 slots.
 */
/* Argument of fn_80090880 (reads +4 and +8 only). */
struct Unk80090880 {
    int m0;
    char* m4;
    char* m8;
};

struct TblBase;
struct DbObj {
    char* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    virtual ~DbObj();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a, TblBase* b); /* entry 4: +0x20/+0x24 */
};

/*
 * Record collection (size 0x28, vptr at +0x20) built by the per-class
 * constructors fn_80085A3C, fn_8052E654, ...; entry 2 takes an id, entry 5
 * tests a flag for a row, entries 10/11 are used by the v7/v10 slots.
 */
struct Rec {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    Rec(const char* name, DbObj* db, int c); /* fn_80071604 */
    virtual ~Rec();
    virtual void v2(int id);
    virtual int v3(int a);
    virtual void v4();
    virtual int v5(int flag, int row);
    virtual void v6();
    virtual void v7();
    virtual void v8(int a, int b, int c);
    virtual void v9();
    virtual void v10();
    virtual void v11(int a, TblBase* b);
};

/* Record collection with a row pointer after the vptr (+0x24). */
struct RecT : Rec {
    char* m24;
    RecT(const char* name, DbObj* db, int c) : Rec(name, db, c) {}
};

struct RowRef;

extern "C" {
char* fn_8040B61C(char* dst, const char* src); /* strcpy */
char* fn_80402CAC(char* s);
int fn_804089B4(char* dst, const char* fmt, ...); /* sprintf */
void fn_804031BC(char* dst, const char* src);
int fn_800736EC(const char* s);
void fn_8040074C(void* p, unsigned n); /* bzero */
void fn_800716BC(Rec* r);            /* release */
int fn_80071718(Rec* r);             /* next free id, -1 if none */
int fn_80071784(Rec* r, int row);    /* row -> id */
int fn_80071814(Rec* r, int a);      /* current id */
void fn_80377BEC(DbObj* d, int id);
int fn_80377E04(DbObj* d, int* out, int id);
void fn_80377CD8(DbObj* d, int a, int b, int c);
void fn_80377DBC(DbObj* d, int* a, int* b, int idx);
void fn_80377E90(DbObj* d, int* a, int* b, int id);
DbObj* fn_803779B8(void* mem, int a, int b, int c, const char* path, int line);
RowRef* fn_80085BF0(Rec* r, int id);
void fn_80085EF8(RowRef* r, int v);
void fn_80085F2C(RowRef* r, const void* p);
}

/*
 * Base of the table classes (vtable lbl_8064AD40, ctor fn_80090910).
 * Slots 2-6 and 10 are pure; 7-9, 12 and 13 are inline no-op/default
 * virtuals emitted at 0x800A87A8.. (declared, not defined, here).
 */
struct TblBase {
    DbObj* m0;
    TblBase();
    virtual ~TblBase();
    virtual int v2() = 0;
    virtual void v3(int a) = 0;
    virtual int v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(int a, TblBase* b) = 0;
    virtual int v11(int a, DbObj* b);
    virtual int v12(int a);
    virtual int v13(int a);
    DbObj* Db(); /* fn_800A883C: return m0 */
    int RowCount() { return Db() ? Db()->m4 : 0; }
    void Fn90A24(int a);
    int Fn90A90(int key, int flag);
};

/* BEGIN GENERATED (scratch generator; do not edit by hand) */

struct RowRef;
extern "C" {
RecT* fn_80085A3C(void* mem, const char* name, DbObj* db, int c);
RowRef* fn_80085BF0(Rec* r, int id);
void fn_80085EF8(RowRef* r, int v);
void fn_80085F2C(RowRef* r, const void* p);
RecT* fn_8052CA60(void* mem, const char* name, DbObj* db, int c);
RecT* fn_8052D80C(void* mem, const char* name, DbObj* db, int c);
RowRef* fn_8052D9C0(Rec* r, int id);
RowRef* fn_8052D9D0(Rec* r, int row);
void fn_8052D9E0(char* dst, RowRef* src);
void fn_8052DC60(RowRef* r, int v);
void fn_8052DC94(RowRef* r, const void* p);
RecT* fn_8052FF10(void* mem, const char* name, DbObj* db, int c);
RecT* fn_80530D38(void* mem, const char* name, DbObj* db, int c);
RowRef* fn_80530EEC(Rec* r, int id);
RowRef* fn_80530EFC(Rec* r, int row);
void fn_80530F0C(char* dst, RowRef* src);
void fn_805311A4(RowRef* r, int v);
void fn_805311D8(RowRef* r, const void* p);
RecT* fn_8053CC9C(void* mem, const char* name, DbObj* db, int c);
RecT* fn_8053D95C(void* mem, const char* name, DbObj* db, int c);
RowRef* fn_8053DB10(Rec* r, int id);
RowRef* fn_8053DB20(Rec* r, int row);
void fn_8053DB30(char* dst, RowRef* src);
void fn_8053DD34(RowRef* r, int v);
void fn_8053DD68(RowRef* r, const void* p);
RecT* fn_805989A0(void* mem, const char* name, DbObj* db, int c);
RecT* fn_805995F0(void* mem, const char* name, DbObj* db, int c);
RowRef* fn_805997A4(Rec* r, int id);
RowRef* fn_805997B4(Rec* r, int row);
void fn_805997C4(char* dst, RowRef* src);
void fn_805999B4(RowRef* r, int v);
void fn_805999E8(RowRef* r, const void* p);
}

/* vtable lbl_8064AB40, ctor 0x80091EAC, 0-byte object up to the name/row fields */
struct Tbl80091EAC : TblBase {
    RecT* m8;
    int mC;
    Tbl80091EAC(int c);
    virtual ~Tbl80091EAC();
    virtual int v2();
    virtual void v3(int a);
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v10(int a, TblBase* b);
    virtual void v14(Tbl80091EAC* src);
    void Extra(int a, int b);
};

/* vtable lbl_8064AAC0, ctor 0x80092370, 0-byte object up to the name/row fields */
struct Tbl80092370 : TblBase {
    RecT* m8;
    int mC;
    char m10[0x20]; /* name, strcpy'd by the ctor; real size unknown */
    Tbl80092370(const char* name, int c);
    virtual ~Tbl80092370();
    virtual int v2();
    virtual void v3(int a);
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v10(int a, TblBase* b);
    virtual void v14(Tbl80092370* src);
};

/* vtable lbl_8064AA40, ctor 0x800927D0, 0-byte object up to the name/row fields */
struct Tbl800927D0 : TblBase {
    RecT* m8;
    int mC;
    Tbl800927D0(int c);
    virtual ~Tbl800927D0();
    virtual int v2();
    virtual void v3(int a);
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v10(int a, TblBase* b);
    virtual void v14(Tbl800927D0* src);
    void Extra(int a, int b);
};

/* vtable lbl_8064A9C0, ctor 0x80092C94, 0-byte object up to the name/row fields */
struct Tbl80092C94 : TblBase {
    RecT* m8;
    int mC;
    char m10[0x20]; /* name, strcpy'd by the ctor; real size unknown */
    Tbl80092C94(const char* name, int c);
    virtual ~Tbl80092C94();
    virtual int v2();
    virtual void v3(int a);
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v10(int a, TblBase* b);
    virtual void v14(Tbl80092C94* src);
};

/* vtable lbl_8064A940, ctor 0x800930F4, 0-byte object up to the name/row fields */
struct Tbl800930F4 : TblBase {
    RecT* m8;
    int mC;
    Tbl800930F4(int c);
    virtual ~Tbl800930F4();
    virtual int v2();
    virtual void v3(int a);
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v10(int a, TblBase* b);
    virtual void v14(Tbl800930F4* src);
    void Extra(int a, int b);
};

/* vtable lbl_8064A8C0, ctor 0x800935B8, 0-byte object up to the name/row fields */
struct Tbl800935B8 : TblBase {
    RecT* m8;
    int mC;
    char m10[0x20]; /* name, strcpy'd by the ctor; real size unknown */
    Tbl800935B8(const char* name, int c);
    virtual ~Tbl800935B8();
    virtual int v2();
    virtual void v3(int a);
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v10(int a, TblBase* b);
    virtual void v14(Tbl800935B8* src);
};

/* vtable lbl_8064A840, ctor 0x80093A18, 0-byte object up to the name/row fields */
struct Tbl80093A18 : TblBase {
    RecT* m8;
    int mC;
    Tbl80093A18(int c);
    virtual ~Tbl80093A18();
    virtual int v2();
    virtual void v3(int a);
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v10(int a, TblBase* b);
    virtual void v14(Tbl80093A18* src);
    void Extra(int a, int b);
};

/* vtable lbl_8064A7C0, ctor 0x80093EDC, 0-byte object up to the name/row fields */
struct Tbl80093EDC : TblBase {
    RecT* m8;
    int mC;
    char m10[0x20]; /* name, strcpy'd by the ctor; real size unknown */
    Tbl80093EDC(const char* name, int c);
    virtual ~Tbl80093EDC();
    virtual int v2();
    virtual void v3(int a);
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v10(int a, TblBase* b);
    virtual void v14(Tbl80093EDC* src);
};

/* vtable lbl_8064A740, ctor 0x8009433C, 0-byte object up to the name/row fields */
struct Tbl8009433C : TblBase {
    RecT* m8;
    int mC;
    Tbl8009433C(int c);
    virtual ~Tbl8009433C();
    virtual int v2();
    virtual void v3(int a);
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v10(int a, TblBase* b);
    virtual void v14(Tbl8009433C* src);
    void Extra(int a, int b);
};

/* Small object built by fn_8052FA84 (size 0xC, vptr at +8). */
struct Obj0C {
    int m0;
    int m4;
    virtual ~Obj0C();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a, TblBase* b);
};

/* Object built by fn_8053BB80 (size 0x58, vptr at +0x54, row array pointer at +0x10). */
struct Obj58 {
    int m0;
    int m4;
    int m8;
    int mC;
    char* m10;
    char pad14[0x40];
    virtual ~Obj58();
    virtual void v2(int a, TblBase* b);
};

struct Row30 {
    int w[12];
};

struct Tbl80090B28 : TblBase {
    Rec* m8;
    Rec* mC;
    Obj0C* m10;
    Tbl80090B28();
    virtual ~Tbl80090B28();
    virtual int v2();
    virtual void v3(int a);
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v10(int a, TblBase* b);
};

struct Tbl8009101C : TblBase {
    Rec* m8;
    Obj58* mC;
    Rec* m10[2];
    Rec* m18;
    Tbl8009101C();
    virtual ~Tbl8009101C();
    virtual int v2();
    virtual void v3(int a);
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(int a, TblBase* b);
};

struct Tbl80091760 : TblBase {
    RecT* m8;
    int mC;
    char m10[0x20]; /* name, strcpy'd by the ctor; real size unknown */
    Tbl80091760(const char* name, int c);
    virtual ~Tbl80091760();
    virtual int v2();
    virtual void v3(int a);
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v10(int a, TblBase* b);
    virtual void v14(Tbl80091760* src);
    virtual void v15(Tbl80091760* src);
    virtual void v16(Tbl80091760* src);
};

struct Grp3 {
    Rec* a;
    Rec* b[2];
};

struct Tbl80094800 : TblBase {
    Rec* m8;
    Rec* mC[2];
    Grp3 m14[2];
    Rec* m2C[5];
    Rec* m40;
    Tbl80094800();
    virtual ~Tbl80094800();
    virtual int v2();
    virtual void v3(int a);
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(int a, TblBase* b);
    int Fn956B8(int a, int b);
};

struct Tbl800956D8 : TblBase {
    Rec* m8;
    Grp3 mC[2];
    Rec* m24;
    Tbl800956D8();
    virtual ~Tbl800956D8();
    virtual int v2();
    virtual void v3(int a);
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(int a, TblBase* b);
};

/* Rec subclasses of the colour/attribute tables (entries of 4 bytes at +0x24). */
struct RecA : Rec {
    int* m24;
    RecA(const char* name, DbObj* db, int c);
    virtual ~RecA();
};

struct RecB : Rec {
    int* m24;
    RecB(const char* name, DbObj* db, int c);
    virtual ~RecB();
};

/* Rec subclass with 0x3C-byte entries (vtable lbl_8064B4D8). */
struct Ent3C {
    int w[15];
};

struct RecC : Rec {
    Ent3C* m24;
    RecC(const char* name, DbObj* db, int c);
    virtual ~RecC();
};

extern "C" {
void fn_8052FB70(Obj0C* o);
void fn_8053BE58(Obj58* o);
void fn_8053BEC8(Obj58* o);
void fn_8053B548(char* p, int v);
Rec* fn_8052E654(void* mem, const char* name, DbObj* db, int c);
Rec* fn_8052F454(void* mem, const char* name, DbObj* db, int c);
Obj0C* fn_8052FA84(void* mem, int v);
Obj58* fn_8053BB80(void* mem, const char* name, DbObj* db, int c);
RowRef* fn_80085C00(Rec* r, int row);
void fn_80085C10(char* dst, RowRef* src);
Rec* fn_80084A10(void* mem, const char* name, DbObj* db, int c);
}
extern "C" Rec* fn_8008CAF8(void* mem, const char* name, DbObj* db, int c);
extern "C" Rec* fn_8008EA7C(void* mem, const char* name, DbObj* db, int c);
extern "C" Rec* fn_8006F9FC(void* mem, const char* name, DbObj* db, int c);
extern "C" Rec* fn_8006FE88(void* mem, const char* name, DbObj* db, int c);
extern "C" Rec* fn_800805FC(void* mem, const char* name, DbObj* db, int c);
extern "C" Rec* fn_80071020(void* mem, const char* name, DbObj* db, int c);
extern "C" Rec* fn_800897B8(void* mem, const char* name, DbObj* db, int c);
extern "C" Rec* fn_8008B254(void* mem, const char* name, DbObj* db, int c);
extern "C" Rec* fn_8008BDDC(void* mem, const char* name, DbObj* db, int c);
extern "C" Rec* fn_8008AB04(void* mem, const char* name, DbObj* db, int c);
/* END GENERATED */

#endif
