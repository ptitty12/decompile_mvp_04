/*
 * Database overlay code, .database_codeoverlay 0x80582578-0x80584CBC (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8056BAEC.h"

extern void* lbl_8061930C;
class DbFmt {
public:
    int m0;
};
struct DbFlagRec {
    char padC[0xC];
    unsigned mC;
};

extern "C" {
void* fn_8052E408(void* obj, void* a);
int fn_80587728(void* obj);
void fn_80360AF0(void* obj, int chrg);
void fn_805822D0(DbSubObj* p);
int fn_805826AC(void* self, void* a);
int fn_805833A8(void* unused, int a, int b);
int fn_80077BC4(void* g, int a);
int fn_8057CED4(int a, int b);
}
extern char lbl_80683428[];
extern char lbl_80683558[];
extern char lbl_80683390[];

/* Sub-object with a vptr at +4; slots 6 (0x30), 10 (0x50) and 13 (0x68) are called here. */
/* 0x20-byte item of the sub-object's table: two ints, then a 0x18-byte blob whose last word is kept. */
struct DbBlob {
    int w[6];
};
struct DbItem {
    int m0;
    int m4;
    DbBlob blob;
};
class DbSubX {
public:
    int m0;
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int v10();
    virtual int* v11(int idx);
    virtual void v12();
    virtual DbItem* v13(int idx);
    virtual void v14();
    virtual void v15(int idx, int q);
};

inline int RecA(DbRec12* r)
{
    return r->a;
}

inline int ObjE(DbRecO* o)
{
    return o->e;
}

inline int ObjB(DbRecO* o)
{
    return o->b;
}

inline int ObjC(DbRecO* o)
{
    return o->c;
}

/* forward declarations (definitions are in address order) */
extern "C" int fn_80582578(DbSubX* self, int a);
extern "C" int fn_80582DF4(int unused, int k, int* arr);
extern "C" int fn_80582E38(int unused, int a, int b);
extern "C" int fn_80582EE4(int unused, int a);
extern "C" int fn_80583324(int unused, int b);
extern "C" int fn_80583354(int unused, int x, int c);
extern "C" int fn_805833A8(void* unused, int a, int b);
extern "C" DbSubObj* fn_80583404(DbSubObj* self);
extern "C" int fn_805838E8(void* self, void* a);
extern "C" int fn_8058391C(int unused, void* a);
extern "C" DbSubObj* fn_80583964(DbSubObj* self);
extern "C" int fn_805839A0(void);
extern "C" int fn_80583C70(int unused, int x, int y, int z);
extern "C" int fn_805842F8(int unused, void* a);
extern "C" int fn_80584634(void* self, void* a);
extern "C" int fn_805848B8(int unused, void* a);
extern "C" int fn_80584C00(void* self, void* a);
extern "C" DbSubObj* fn_80584C80(DbSubObj* self);

extern "C" {
void* fn_8052E198(void* obj, int id, int b, int c, int d, int e, int f, int g, int h, int i);
int fn_80582CF8(DbSubX* self, void* obj, int a, int b, int c);
}

extern "C" int fn_80552D98(void);

extern void* lbl_8061977C;
extern "C" {
void* fn_800B555C(void);
int fn_800B5758(void* mgr);
void fn_8058233C(DbFmt* self, DbFlagRec* a, unsigned short* b, int c);
int fn_80403DE4(unsigned short* dst, const unsigned short* fmt, ...);
void fn_80403144(unsigned short* dst, const unsigned short* src);
unsigned short* fn_80090880__FP11Unk80090880(void* tbl, int id);
}

extern "C" void* fn_8052E444(void* obj, int a);

class DbStream {
public:
    int m0;
    virtual int v08(int a, void* data, int size);
};
extern "C" void fn_80582238(int* p, int a, DbStream* io);
/* forward declarations (definitions are in address order) */
extern "C" int fn_80582578(DbSubX* self, int a);
extern "C" int fn_80582DF4(int unused, int k, int* arr);
extern "C" int fn_80582E38(int unused, int a, int b);
extern "C" int fn_80582EE4(int unused, int a);
extern "C" int fn_80583324(int unused, int b);
extern "C" int fn_80583354(int unused, int x, int c);
extern "C" int fn_805833A8(void* unused, int a, int b);
extern "C" DbSubObj* fn_80583404(DbSubObj* self);
extern "C" int fn_805838E8(void* self, void* a);
extern "C" int fn_8058391C(int unused, void* a);
extern "C" DbSubObj* fn_80583964(DbSubObj* self);
extern "C" int fn_805839A0(void);
extern "C" int fn_80583C70(int unused, int x, int y, int z);
extern "C" int fn_805842F8(int unused, void* a);
extern "C" int fn_80584634(void* self, void* a);
extern "C" int fn_805848B8(int unused, void* a);
extern "C" int fn_80584C00(void* self, void* a);
extern "C" DbSubObj* fn_80584C80(DbSubObj* self);
extern "C" void fn_80583B04(DbSubX* self, int a);
extern "C" void fn_80583A48(DbSubX* self, int a, int b);
extern "C" void fn_80583BB0(DbSubX* self, int a);
extern "C" void fn_80584504(DbFmt* self, DbFlagRec* a, unsigned short* b, int c);
extern "C" void fn_80584918(DbFmt* self, DbFlagRec* a, unsigned short* b, int c);
extern "C" void fn_8058284C(DbSubX* self, int idx, int p, int q);
extern "C" void fn_80582AA0(DbSubX* self);
extern "C" void fn_80582C54(DbSubX* self, int a, DbStream* io);

struct DbTri {
    int w0;
    int w1;
    int w2;
};
extern DbTri lbl_806005E8;

struct DbTbl13 {
    int w[13];
};
extern DbTbl13 lbl_8060055C;
extern int lbl_80622D90[];

extern const float lbl_806005D0;
/* forward declarations (definitions are in address order) */
extern "C" int fn_80582578(DbSubX* self, int a);
extern "C" void fn_8058284C(DbSubX* self, int idx, int p, int q);
extern "C" void fn_80582AA0(DbSubX* self);
extern "C" void fn_80582C54(DbSubX* self, int a, DbStream* io);
extern "C" int fn_80582DF4(int unused, int k, int* arr);
extern "C" int fn_80582E38(int unused, int a, int b);
extern "C" int fn_80582EE4(int unused, int a);
extern "C" int fn_80583324(int unused, int b);
extern "C" int fn_80583354(int unused, int x, int c);
extern "C" int fn_805833A8(void* unused, int a, int b);
extern "C" DbSubObj* fn_80583404(DbSubObj* self);
extern "C" int fn_805838E8(void* self, void* a);
extern "C" int fn_8058391C(int unused, void* a);
extern "C" DbSubObj* fn_80583964(DbSubObj* self);
extern "C" int fn_805839A0(void);
extern "C" void fn_80583A48(DbSubX* self, int a, int b);
extern "C" void fn_80583B04(DbSubX* self, int a);
extern "C" void fn_80583BB0(DbSubX* self, int a);
extern "C" int fn_80583C70(int unused, int x, int y, int z);
extern "C" int fn_805842F8(int unused, void* a);
extern "C" void fn_80584504(DbFmt* self, DbFlagRec* a, unsigned short* b, int c);
extern "C" int fn_80584634(void* self, void* a);
extern "C" int fn_805848B8(int unused, void* a);
extern "C" void fn_80584918(DbFmt* self, DbFlagRec* a, unsigned short* b, int c);
extern "C" int fn_80584C00(void* self, void* a);
extern "C" DbSubObj* fn_80584C80(DbSubObj* self);
extern "C" int fn_805845BC(int u, int k);
extern "C" int fn_805825BC(DbSubX* self, int a, int* o1, int* o2);
extern "C" int fn_80582F40(void* self, float pa, float pb, float pc, int a, int b, int c);
/* forward declarations (definitions are in address order) */
extern "C" int fn_80582578(DbSubX* self, int a);
extern "C" int fn_805825BC(DbSubX* self, int a, int* o1, int* o2);
extern "C" void fn_8058284C(DbSubX* self, int idx, int p, int q);
extern "C" void fn_80582AA0(DbSubX* self);
extern "C" void fn_80582C54(DbSubX* self, int a, DbStream* io);
extern "C" int fn_80582DF4(int unused, int k, int* arr);
extern "C" int fn_80582E38(int unused, int a, int b);
extern "C" int fn_80582EE4(int unused, int a);
extern "C" int fn_80582F40(void* self, float pa, float pb, float pc, int a, int b, int c);
extern "C" int fn_80583324(int unused, int b);
extern "C" int fn_80583354(int unused, int x, int c);
extern "C" int fn_805833A8(void* unused, int a, int b);
extern "C" DbSubObj* fn_80583404(DbSubObj* self);
extern "C" int fn_805838E8(void* self, void* a);
extern "C" int fn_8058391C(int unused, void* a);
extern "C" DbSubObj* fn_80583964(DbSubObj* self);
extern "C" int fn_805839A0(void);
extern "C" void fn_80583A48(DbSubX* self, int a, int b);
extern "C" void fn_80583B04(DbSubX* self, int a);
extern "C" void fn_80583BB0(DbSubX* self, int a);
extern "C" int fn_80583C70(int unused, int x, int y, int z);
extern "C" int fn_805842F8(int unused, void* a);
extern "C" void fn_80584504(DbFmt* self, DbFlagRec* a, unsigned short* b, int c);
extern "C" int fn_805845BC(int u, int k);
extern "C" int fn_80584634(void* self, void* a);
extern "C" int fn_805848B8(int unused, void* a);
extern "C" void fn_80584918(DbFmt* self, DbFlagRec* a, unsigned short* b, int c);
extern "C" int fn_80584C00(void* self, void* a);
extern "C" DbSubObj* fn_80584C80(DbSubObj* self);

extern "C" DB_OVERLAY int fn_80582578(DbSubX* self, int a)
{
    int r = self->v6();
    int t = 0;
    if (r != -1)
        t = 1;
    return t;
}

extern "C" DB_OVERLAY int fn_805825BC(DbSubX* self, int a, int* o1, int* o2)
{
    *o1 = 0;
    int idx = self->v6();
    if (fn_80582578(self, a) != 0) {
        DbTbl13 t = lbl_8060055C;
        *o2 = lbl_80622D90[idx];
        *o1 = t.w[idx];
        return 1;
    }
    return 0;
}

extern "C" DB_OVERLAY void fn_8058284C(DbSubX* self, int idx, int p, int q)
{
    if (idx < self->v10() && p != 0) {
        int z = *self->v11(idx);
        int flag = 1;
        if (z == 0)
            flag = 0;
        if (flag == 0) {
            if (q != 0)
                self->v15(idx, q);
            self->v13(idx)->m0 = p;
        }
    }
}

/* near-miss: retail keeps the saved word in a stack slot (sp+8) and copies the temp through registers; not reproduced */
extern "C" DB_OVERLAY void fn_80582AA0(DbSubX* self)
{
    int i = 0;
    while (i < self->v10()) {
        DbItem* it = self->v13(i);
        i += 1;
        it->m4 = 0;
        it->m0 = 0;
        int keep = it->blob.w[5];
        char obj[0x18];
        fn_8052E444(obj, 0x10);
        it->blob = *(DbBlob*)obj;
        it->blob.w[5] = keep;
        fn_80360AF0(obj, 2);
    }
}

extern "C" DB_OVERLAY void fn_80582C54(DbSubX* self, int a, DbStream* io)
{
    io->v08(a, self, 4);
    for (int i = 0; i < self->v10(); i++)
        fn_80582238((int*)self->v13(i), a, io);
}

extern "C" DB_OVERLAY int fn_80582DF4(int unused, int k, int* arr)
{
    switch (k) {
    case 0:
        return arr[0];
    case 1:
        return arr[1];
    case 2:
        return arr[2];
    default:
        return arr[0];
    }
}

extern "C" DB_OVERLAY int fn_80582E38(int unused, int a, int b)
{
    void* g = lbl_8061930C;
    int i = fn_80080070__FP13Unk8007FF8C_G(g) - 1;
    if (i >= 0) {
        do {
            DbRec12* rec = fn_8008007C__FP13Unk8007FF8C_GUi(g, i);
            if (b == RecA(rec)) {
                char obj[0x18];
                char* p = obj;
                fn_8052E408(p, rec);
                if (fn_80587728(p) == a) {
                    fn_80360AF0(p, 2);
                    return 1;
                }
                fn_80360AF0(p, 2);
            }
            i -= 1;
        } while (i >= 0);
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_80582EE4(int unused, int a)
{
    int k = 0;
    int r = fn_8007A6A0__18Unk8007A4DC_Screenii(lbl_8061930C, 5, a);
    if (r == 0)
        k = 1;
    else if (r == 0xA)
        k = 2;
    return k;
}

extern "C" DB_OVERLAY int fn_80582F40(void* self, float pa, float pb, float pc, int a, int b, int c)
{
    int ia = (int)(pa * lbl_806005D0);
    int ib = (int)(pb * lbl_806005D0);
    int r = fn_8040ABA0();
    r = r % 100;
    if (r >= 0 && r < ia)
        return a;
    int ret = c;
    if (r >= ia && r < ib)
        ret = b;
    return ret;
}

extern "C" DB_OVERLAY int fn_80583324(int unused, int b)
{
    return fn_80077BC4(lbl_8061930C, b) == 0;
}

extern "C" DB_OVERLAY int fn_80583354(int unused, int x, int c)
{
    int r = fn_80077BC4(lbl_8061930C, x);
    if (r != 0) {
        if (fn_8057CED4(c, r) != 0)
            return 1;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_805833A8(void* unused, int a, int b)
{
    if (fn_8007A6A0__18Unk8007A4DC_Screenii(lbl_8061930C, 0x1E, a) != 0)
        return 1;
    int r = 0xB;
    if (b != 0x31)
        r = 0xA;
    return r;
}

extern "C" DB_OVERLAY DbSubObj* fn_80583404(DbSubObj* self)
{
    fn_805822D0(self);
    *(const void**)((char*)self + 4) = lbl_80683428;
    return self;
}

extern "C" DB_OVERLAY int fn_805838E8(void* self, void* a)
{
    int r = fn_805826AC(self, a);
    if (r == 1)
        return 4;
    return r;
}

extern "C" DB_OVERLAY int fn_8058391C(int unused, void* a)
{
    char obj[0x18];
    char* p = obj;
    fn_8052E408(p, a);
    int v = ((DbRecO*)p)->e;
    fn_80360AF0(p, 2);
    return v;
}

extern "C" DB_OVERLAY DbSubObj* fn_80583964(DbSubObj* self)
{
    fn_805822D0(self);
    *(const void**)((char*)self + 4) = lbl_80683558;
    return self;
}

extern "C" DB_OVERLAY int fn_805839A0(void)
{
    void* g = lbl_8061930C;
    int i = fn_80080070__FP13Unk8007FF8C_G(g) - 1;
    if (i >= 0) {
        do {
            DbRec12* rec = fn_8008007C__FP13Unk8007FF8C_GUi(g, i);
            char obj[0x18];
            char* p = obj;
            fn_8052E408(p, rec);
            int ra = RecA(rec);
            int oe = ObjE((DbRecO*)p);
            if (ra == 0xE && oe == 1) {
                fn_80360AF0(p, 2);
                return 1;
            }
            fn_80360AF0(p, 2);
            i -= 1;
        } while (i >= 0);
    }
    return 0;
}

extern "C" DB_OVERLAY void fn_80583A48(DbSubX* self, int a, int b)
{
    int r = fn_805839A0();
    if (r == 0 && fn_8007FDF8__FP13Unk8007F198_D(lbl_8061930C) == 0xC) {
        int id = self->v3();
        char obj[0x18];
        fn_8052E198(obj, id, a, b, 0, 0, 0, 0, 1, r);
        fn_80582CF8(self, obj, 0, 0, 0);
        fn_80360AF0(obj, 2);
    }
}

extern "C" DB_OVERLAY void fn_80583B04(DbSubX* self, int a)
{
    if (fn_8007FDF8__FP13Unk8007F198_D(lbl_8061930C) == 0xC) {
        int id = self->v3();
        char obj[0x18];
        fn_8052E198(obj, id, 0, 0, 0, (char)a, 0, 0, 0, 0);
        fn_80582CF8(self, obj, 0, 0, 0);
        fn_80360AF0(obj, 2);
    }
}

extern "C" DB_OVERLAY void fn_80583BB0(DbSubX* self, int a)
{
    if (fn_8007FDF8__FP13Unk8007F198_D(lbl_8061930C) == 0xC) {
        int k = fn_80552D98();
        if (k <= 2) {
            int id = self->v3();
            char obj[0x18];
            fn_8052E198(obj, id, a, k, 0, 0, 0, 0, 2, 0);
            fn_80582CF8(self, obj, 0, 0, 0);
            fn_80360AF0(obj, 2);
        }
    }
}

extern "C" DB_OVERLAY int fn_80583C70(int unused, int x, int y, int z)
{
    void* g = lbl_8061930C;
    int i = fn_80080070__FP13Unk8007FF8C_G(g) - 1;
    if (i >= 0) {
        do {
            DbRec12* rec = fn_8008007C__FP13Unk8007FF8C_GUi(g, i);
            char obj[0x18];
            char* p = obj;
            fn_8052E408(p, rec);
            DbRecO* o = (DbRecO*)p;
            int bb = ObjB(o);
            int ra = RecA(rec);
            int ee = ObjE(o);
            int cc = ObjC(o);
            if (ra == 0xE && ee == x && bb == y && cc == z) {
                fn_80360AF0(p, 2);
                return 1;
            }
            fn_80360AF0(p, 2);
            i -= 1;
        } while (i >= 0);
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_805842F8(int unused, void* a)
{
    char obj[0x18];
    char* p = obj;
    fn_8052E408(p, a);
    int v = ((DbRecO*)p)->e;
    fn_80360AF0(p, 2);
    return v;
}

extern "C" DB_OVERLAY void fn_80584504(DbFmt* self, DbFlagRec* a, unsigned short* b, int c)
{
    fn_8058233C(self, a, b, c);
    if (fn_800B5758(fn_800B555C()) != 0) {
        char obj[0x18];
        char* p = obj;
        fn_8052E408(p, a);
        int v = ((DbRecO*)p)->m8;
        if (v != 0) {
            unsigned short fmtbuf[0x80];
            unsigned short numstr[0x40];
            void* tbl = lbl_8061977C;
            fn_800DE538__Fiiii(numstr, 4, v, 1);
            fn_80403DE4(fmtbuf, fn_80090880__FP11Unk80090880(tbl, 0x5C65), numstr, b);
            fn_80403144(b, fmtbuf);
        }
        fn_80360AF0(p, 2);
    }
}

extern "C" DB_OVERLAY int fn_805845BC(int u, int k)
{
    DbTri a = lbl_806005E8;
    a.w1 = 0x1D69;
    a.w2 = 0x1E20;
    a.w0 = 0x5BCF;
    DbTri b = a;
    return fn_80582DF4(u, k, (int*)&b);
}

extern "C" DB_OVERLAY int fn_80584634(void* self, void* a)
{
    int r = fn_805826AC(self, a);
    if (r == 1) {
        char obj[0x18];
        char* p = obj;
        fn_8052E408(p, a);
        int id = fn_80587728(p);
        unsigned w = *(unsigned*)(p + 0xC);
        unsigned lo = (w >> 18) & 0x3F;
        unsigned hi = (w >> 6) & 0xFC0;
        int r2 = fn_805833A8(self, id, hi | lo);
        fn_80360AF0(p, 2);
        r = r2;
    }
    return r;
}

extern "C" DB_OVERLAY int fn_805848B8(int unused, void* a)
{
    char obj[0x18];
    char* p = obj;
    fn_8052E408(p, a);
    if (!((DbRecO*)p)->d) {
        fn_80360AF0(p, 2);
        return 0xD;
    }
    fn_80360AF0(p, 2);
    return 0xE;
}

extern "C" DB_OVERLAY void fn_80584918(DbFmt* self, DbFlagRec* a, unsigned short* b, int c)
{
    fn_8058233C(self, a, b, c);
    if (fn_800B5758(fn_800B555C()) != 0) {
        char obj[0x18];
        char* p = obj;
        fn_8052E408(p, a);
        int v = ((DbRecO*)p)->m8;
        if (v != 0) {
            unsigned short fmtbuf[0x80];
            unsigned short numstr[0x40];
            void* tbl = lbl_8061977C;
            fn_800DE538__Fiiii(numstr, 3, v, 1);
            fn_80403DE4(fmtbuf, fn_80090880__FP11Unk80090880(tbl, 0x5C65), numstr, b);
            fn_80403144(b, fmtbuf);
        }
        fn_80360AF0(p, 2);
    }
}

extern "C" DB_OVERLAY int fn_80584C00(void* self, void* a)
{
    int r = fn_805826AC(self, a);
    if (r == 1) {
        char obj[0x18];
        char* p = obj;
        fn_8052E408(p, a);
        int id = fn_80587728(p);
        unsigned w = *(unsigned*)(p + 0xC);
        unsigned lo = (w >> 18) & 0x3F;
        unsigned hi = (w >> 6) & 0xFC0;
        int r2 = fn_805833A8(self, id, hi | lo);
        fn_80360AF0(p, 2);
        r = r2;
    }
    return r;
}

extern "C" DB_OVERLAY DbSubObj* fn_80584C80(DbSubObj* self)
{
    fn_805822D0(self);
    *(const void**)((char*)self + 4) = lbl_80683390;
    return self;
}
