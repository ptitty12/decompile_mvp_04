/*
 * Database overlay code, .database_codeoverlay 0x8058154C-0x80582578 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8056BAEC.h"

extern void* lbl_8061930C;

/* Text formatter sub-object: int at +0, vptr at +4; slots 16 and 17 are called by fn_80582424. */
class DbFmt {
public:
    int m0;
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int v16();
    virtual int v17(int mode, void* a);
};
struct DbFlagRec {
    char padC[0xC];
    unsigned mC;
};
extern void* lbl_8061977C;
extern "C" {
void* fn_8052E408(void* obj, void* a);
unsigned short* fn_80090880__FP11Unk80090880(void* tbl, int id);
void fn_80403144(unsigned short* dst, const unsigned short* src);
int fn_80403060(const unsigned short* s);
void fn_8058750C(void* obj, const unsigned short* s, unsigned short* b, int c);
}

extern "C" {
void fn_8058DE9C(void* p);
void fn_805846B4(void* p);
void fn_8058D8E0(void* p);
void fn_80583A48(void* p);
void fn_80583B04(void* p);
void fn_8058E180(void* p);
void fn_80582AA0(DbSubObj* p);
void fn_80582314(DbSubObj* p);
}

extern char lbl_80683720[];
extern char lbl_80683688[];
extern "C" void fn_80361720(void* p, int chrg);
extern "C" void fn_80377408(void* p);

#define PUT(p, o, v) (*(const void**)((char*)(p) + (o)) = (v))

extern "C" void fn_8058284C(DbSubObj* p, int a, int b, int c);

extern "C" {
int fn_800A2AE8(void* glob);
void fn_8052DE88(void* rec, int a);
}
extern void* lbl_80619948;

/* Serializer stream: vptr at +4, slot 1 reads or writes (id, data, size) (cf. Unk80070DDC_Stream). */
class DbStream {
public:
    int m0;
    virtual int v08(int a, void* data, int size);
};

extern char lbl_806837B8[];

extern "C" {
void fn_80582424(DbFmt* self, int mode, DbFlagRec* a, unsigned short* b, int c);
}

struct DbU16At10 {
    char pad0[0x10];
    unsigned short m10;
};

extern "C" {
int fn_80587728(void* obj);
void fn_80360AF0(void* obj, int chrg);
}

extern "C" DB_OVERLAY DbSubObj* fn_8058213C(char* self, int idx);

extern char lbl_80682E00[];
extern char lbl_806832F8[];
extern char lbl_80683260[];
extern char lbl_806831C8[];
extern char lbl_80683130[];
extern char lbl_80682F68[];
extern char lbl_80682ED0[];

extern "C" {
void fn_80583404(void* p);
void fn_80588340(void* p);
void fn_8058A2D0(void* p);
void fn_8058C34C(void* p);
void fn_80583964(void* p);
void fn_8058BF2C(void* p);
void fn_80584C80(void* p);
void fn_8058D080(void* p);
void fn_80587770(void* p);
void fn_8058E144(void* p);
}
/* forward declarations (definitions are in address order) */
extern "C" char* fn_8058154C(char* self);
extern "C" void fn_80581660(char* self, int chrg);
extern "C" void fn_80581770(char* self);
extern "C" void fn_80581808(char* self);
extern "C" void fn_8058185C(char* self, int a, int b);
extern "C" void fn_805818C8(char* self, unsigned idx, int val);
extern "C" int fn_80581900(char* self, unsigned idx);
extern "C" void fn_80581938(char* self);
extern "C" void fn_8058195C(char* self);
extern "C" void fn_80581980(char* self);
extern "C" void fn_805819A4(char* self);
extern "C" void fn_805819C8(char* self);
extern "C" void fn_805819EC(char* self);
extern "C" int fn_80581A10(int unused, int b);
extern "C" void fn_80581F98(int unused, unsigned a);
extern "C" void fn_8058200C(int unused, unsigned idx);
extern "C" void fn_8058205C(char* self, int a);
extern "C" void fn_805820C0(char* self, unsigned idx, int a, int b);
extern "C" DbSubObj* fn_8058211C(char* self, int idx);
extern "C" DbSubObj* fn_8058213C(char* self, int idx);
extern "C" void fn_80582238(int* p, int a, DbStream* io);
extern "C" DbSubObj* fn_805822D0(DbSubObj* self);
extern "C" void fn_80582314(DbSubObj* p);
extern "C" void fn_8058233C(DbFmt* self, DbFlagRec* a, unsigned short* b, int c);
extern "C" void fn_80582370(void* unused, DbU16At10* y, void* z);
extern "C" void fn_805823BC(DbFmt* self, DbFlagRec* a, unsigned short* b, int c);
extern "C" void fn_805823F0(DbFmt* self, DbFlagRec* a, unsigned short* b, int c);
extern "C" void fn_80582424(DbFmt* self, int mode, DbFlagRec* a, unsigned short* b, int c);
extern "C" int fn_8058252C(int unused, void* a);

extern "C" DB_OVERLAY char* fn_8058154C(char* self)
{
    *(const void**)(self + 0x204) = lbl_80682E00;
    char* s1BC = self + 0x1BC;
    fn_80583404(self);
    char* s1C4 = self + 0x1C4;
    fn_80588340(self + 0x8);
    char* s1CC = self + 0x1CC;
    fn_8058A2D0(self + 0xD0);
    char* s1D4 = self + 0x1D4;
    char* s1EC = self + 0x1EC;
    fn_8058C34C(self + 0x188);
    char* s1F4 = self + 0x1F4;
    fn_80583964(self + 0x1A4);
    fn_8058BF2C(self + 0x1AC);
    fn_80584C80(self + 0x1B4);
    fn_805822D0((DbSubObj*)s1BC);
    *(const void**)(s1BC + 4) = lbl_806832F8;
    fn_805822D0((DbSubObj*)s1C4);
    *(const void**)(s1C4 + 4) = lbl_80683260;
    fn_805822D0((DbSubObj*)s1CC);
    *(const void**)(s1CC + 4) = lbl_806831C8;
    fn_805822D0((DbSubObj*)s1D4);
    *(const void**)(s1D4 + 4) = lbl_80683130;
    fn_8058D080(self + 0x1DC);
    fn_80587770(self + 0x1E4);
    fn_805822D0((DbSubObj*)s1EC);
    *(const void**)(s1EC + 4) = lbl_80682F68;
    fn_805822D0((DbSubObj*)s1F4);
    *(const void**)(s1F4 + 4) = lbl_80682ED0;
    fn_8058E144(self + 0x1FC);
    return self;
}

extern "C" DB_OVERLAY void fn_80581660(char* self, int chrg)
{
    PUT(self, 0x204, lbl_80682E00);
    const void* base = lbl_806837B8;
    PUT(self, 0x200, base);
    PUT(self, 0x1F8, base);
    char* s0xD0 = self + 0xD0;
    PUT(self, 0x1F0, base);
    PUT(self, 0x1E8, base);
    PUT(self, 0x1E0, base);
    char* s8 = self + 0x8;
    PUT(self, 0x1D8, base);
    PUT(self, 0x1D0, base);
    PUT(self, 0x1C8, base);
    PUT(self, 0x1C0, base);
    PUT(self, 0x1B8, base);
    PUT(self, 0x1B0, base);
    PUT(self, 0x1A8, base);
    PUT(self, 0x18C, base);
    PUT(s0xD0, 4, lbl_80683720);
    fn_80361720(self + 0x15C, 2);
    fn_80361720(self + 0x130, 2);
    fn_80361720(self + 0x104, 2);
    fn_80361720(self + 0xD8, 2);
    PUT(s0xD0, 4, base);
    PUT(s8, 4, lbl_80683688);
    fn_80361720(self + 0x94, 2);
    fn_80361720(self + 0x68, 2);
    fn_80361720(self + 0x3C, 2);
    fn_80361720(s8 + 8, 2);
    PUT(s8, 4, base);
    PUT(self, 4, base);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_80581770(char* self)
{
    int i = 0;
    fn_800800A4__FP13Unk8007FF8C_G(lbl_8061930C);
    do {
        DbSubObj* o = fn_8058213C(self, i);
        i += 1;
        o->v2();
    } while (i <= 0xF);
    i = 0;
    do {
        int t = i;
        i += 1;
        fn_805818C8(self, t, 0);
    } while (i <= 0xF);
    fn_805818C8(self, 0, 1);
}

extern "C" DB_OVERLAY void fn_80581808(char* self)
{
    int i = 0;
    fn_800800A4__FP13Unk8007FF8C_G(lbl_8061930C);
    do {
        DbSubObj* o = fn_8058213C(self, i);
        i += 1;
        fn_80582AA0(o);
    } while (i <= 0xF);
}

extern "C" DB_OVERLAY void fn_8058185C(char* self, int a, int b)
{
    int i = 0;
    do {
        DbSubObj* o = fn_8058213C(self, i);
        i += 1;
        o->v12(a, b);
    } while (i <= 0xF);
}

extern "C" DB_OVERLAY void fn_805818C8(char* self, unsigned idx, int val)
{
    if (idx <= 0xF)
        fn_8058213C(self, idx)->m0 = val;
}

extern "C" DB_OVERLAY int fn_80581900(char* self, unsigned idx)
{
    if (idx <= 0xF)
        return fn_8058211C(self, idx)->m0;
    return 0;
}

extern "C" DB_OVERLAY void fn_80581938(char* self)
{
    fn_8058DE9C(self + 0x1C4);
}

extern "C" DB_OVERLAY void fn_8058195C(char* self)
{
    fn_805846B4(self + 0x1D4);
}

extern "C" DB_OVERLAY void fn_80581980(char* self)
{
    fn_8058D8E0(self + 0x1BC);
}

extern "C" DB_OVERLAY void fn_805819A4(char* self)
{
    fn_80583A48(self + 0x1A4);
}

extern "C" DB_OVERLAY void fn_805819C8(char* self)
{
    fn_80583B04(self + 0x1A4);
}

extern "C" DB_OVERLAY void fn_805819EC(char* self)
{
    fn_8058E180(self + 0x1FC);
}

extern "C" DB_OVERLAY int fn_80581A10(int unused, int b)
{
    int r = fn_8040ABA0();
    r = r % 100;
    return r < b;
}

extern "C" DB_OVERLAY void fn_80581F98(int unused, unsigned a)
{
    void* g = lbl_8061930C;
    int i = fn_80080070__FP13Unk8007FF8C_G(g) - 1;
    if (i >= 0) {
        do {
            unsigned v = fn_8008007C__FP13Unk8007FF8C_GUi(g, i)->m12;
            if (v != 0 && v <= a)
                fn_8008004C__FP13Unk8007FF8C_G(g, i);
            i -= 1;
        } while (i >= 0);
    }
}

extern "C" DB_OVERLAY void fn_8058200C(int unused, unsigned idx)
{
    DbRec12* r = fn_8008007C__FP13Unk8007FF8C_GUi(lbl_8061930C, idx);
    if (r)
        fn_8052DE88(r, fn_800A2AE8(lbl_80619948) + 0xE);
}

extern "C" DB_OVERLAY void fn_8058205C(char* self, int a)
{
    int i = 0;
    do {
        DbSubObj* o = fn_8058213C(self, i);
        i += 1;
        o->v9(a);
    } while (i <= 0xF);
}

extern "C" DB_OVERLAY void fn_805820C0(char* self, unsigned idx, int a, int b)
{
    if (idx <= 0xF)
        fn_8058284C(fn_8058213C(self, idx), a, fn_8007F9B4__FP13Unk8007F198_C(lbl_8061930C), b);
}

extern "C" DB_OVERLAY DbSubObj* fn_8058211C(char* self, int idx)
{
    return fn_8058213C(self, idx);
}

extern "C" DB_OVERLAY DbSubObj* fn_8058213C(char* self, int idx)
{
    switch (idx) {
    case 9:
        return (DbSubObj*)(self + 0x1C4);
    case 1:
        return (DbSubObj*)(self + 0x1EC);
    case 14:
        return (DbSubObj*)(self + 0x1A4);
    case 2:
        return (DbSubObj*)(self + 0x1F4);
    case 7:
        return (DbSubObj*)(self + 0x1D4);
    case 10:
        return (DbSubObj*)(self + 0x1B4);
    case 6:
        return (DbSubObj*)(self + 0x1CC);
    case 4:
        return (DbSubObj*)(self + 0x8);
    case 3:
        return (DbSubObj*)(self + 0x1E4);
    case 11:
        return (DbSubObj*)(self + 0xD0);
    case 0:
        return (DbSubObj*)(self + 0x1AC);
    case 12:
        return (DbSubObj*)(self + 0x188);
    case 5:
        return (DbSubObj*)(self + 0x1DC);
    case 8:
        return (DbSubObj*)(self + 0x1BC);
    case 15:
        return (DbSubObj*)(self + 0x1FC);
    case 13:
        return (DbSubObj*)self;
    }
    return (DbSubObj*)(self + 0xD0);
}

extern "C" DB_OVERLAY void fn_80582238(int* p, int a, DbStream* io)
{
    io->v08(a, p, 4);
    io->v08(a, p + 1, 4);
    io->v08(a, p + 2, 0x18);
}

extern "C" DB_OVERLAY DbSubObj* fn_805822D0(DbSubObj* self)
{
    *(const void**)((char*)self + 4) = lbl_806837B8;
    self->m0 = 0;
    fn_80582314(self);
    return self;
}

extern "C" DB_OVERLAY void fn_80582314(DbSubObj* p)
{
    p->m0 = 0;
    fn_80582AA0(p);
}

extern "C" DB_OVERLAY void fn_8058233C(DbFmt* self, DbFlagRec* a, unsigned short* b, int c)
{
    fn_80582424(self, 0, a, b, c);
}

extern "C" DB_OVERLAY void fn_80582370(void* unused, DbU16At10* y, void* z)
{
    char buf[8];
    fn_80329FA0(buf, y->m10);
    fn_800DD44C__FP13Unk800DD610_PPvi(buf, z, 2);
}

extern "C" DB_OVERLAY void fn_805823BC(DbFmt* self, DbFlagRec* a, unsigned short* b, int c)
{
    fn_80582424(self, 1, a, b, c);
}

extern "C" DB_OVERLAY void fn_805823F0(DbFmt* self, DbFlagRec* a, unsigned short* b, int c)
{
    fn_80582424(self, 2, a, b, c);
}

extern "C" DB_OVERLAY void fn_80582424(DbFmt* self, int mode, DbFlagRec* a, unsigned short* b, int c)
{
    int id;
    if (a->mC & 0x40000000) {
        id = self->v16();
        if (mode == 1) {
            fn_80403144(b, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x1D0A));
            int n = fn_80403060(fn_80090880__FP11Unk80090880(lbl_8061977C, 0x1D0A));
            c -= n;
            b += n;
        }
    } else {
        id = self->v17(mode, a);
    }
    char obj[0x18];
    char* p = obj;
    fn_8052E408(p, a);
    fn_8058750C(p, fn_80090880__FP11Unk80090880(lbl_8061977C, id), b, c);
    fn_80360AF0(p, 2);
}

extern "C" DB_OVERLAY int fn_8058252C(int unused, void* a)
{
    char obj[0x18];
    char* p = obj;
    fn_8052E408(p, a);
    int r = fn_80587728(p);
    fn_80360AF0(p, 2);
    return r;
}
