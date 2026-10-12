/*
 * Database overlay code, .database_codeoverlay 0x80582578-0x80584CBC (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8056BAEC.h"

extern void* lbl_8061930C;

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
class DbSubX {
public:
    int m0;
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
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
extern "C" int fn_80582578(DbSubX* self);
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

extern "C" DB_OVERLAY int fn_80582578(DbSubX* self)
{
    int r = self->v6();
    int t = 0;
    if (r != -1)
        t = 1;
    return t;
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
