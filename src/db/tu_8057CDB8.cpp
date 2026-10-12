/*
 * Database overlay code, .database_codeoverlay 0x8057CDB8-0x8058154C (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8056BAEC.h"
#include "game/clampiter.h"

extern char lbl_80682C38[];
extern unsigned char lbl_80600038[];
extern int lbl_806000A0[];
extern const float lbl_805FFFD0;
extern void* lbl_8061930C;
extern void* lbl_80619948;
extern "C" int fn_800A2E90(void* o);
extern "C" int fn_800A2E6C(void* o);
extern "C" int fn_800A2EB4(void* o);
extern "C" int fn_800A1AC0(void* o);

/* List of ids (data at +0, count at +4). */
struct DbIdList {
    int* m0;
    int m4;
};

inline int IdAt(int* a, int i)
{
    int o = i * 4;
    return *(int*)((char*)a + o);
}

extern "C" float fn_8057D810(void* self, int a, int b);

extern "C" void fn_80542FCC(void);

/* Polymorphic object whose vptr sits at +8 (slot 1 is the deleting destructor). */
class DbV8 {
public:
    int m0;
    int m4;
    virtual ~DbV8();
};
/* forward declarations (definitions are in address order) */
extern "C" int fn_8057CDB8(DbIdList* self, int k);
extern "C" int fn_8057CE00(int a);
extern "C" int fn_8057CED4(int a, int b);
extern "C" void fn_8057CF60(int a, int b);
extern "C" int fn_8057D084(int a);
extern "C" int fn_8057D0F0(int a);
extern "C" float fn_8057D4EC(void* self, int mode);
extern "C" char* fn_8057DDB4(char* p, int i);
extern "C" int fn_8057DE6C(int k);
extern "C" void fn_8057DF2C(int* p);
extern "C" void fn_8057DF38(void* p, int c);
extern "C" void fn_8057DF60(void);
extern "C" void fn_8057E03C(void* self, int c);
extern "C" int fn_80581368(int a, int b);
extern "C" int fn_80581374(unsigned i);
extern "C" int fn_80581398(unsigned i);
extern "C" void fn_805814EC(DbV8** list);

extern "C" DB_OVERLAY int fn_8057CDB8(DbIdList* self, int k)
{
    int per = self->m4 / 6;
    int last = self->m4 - 1;
    int idx = (k + 1) * per - 1;
    int r;
    if (last < idx)
        r = last;
    else
        r = idx;
    return IdAt(self->m0, r);
}

extern "C" DB_OVERLAY int fn_8057CE00(int a)
{
    void* o = lbl_80619948;
    if (fn_800A2E90(o) == 1 || fn_800A2E6C(o) == 1)
        return -1;
    if (fn_800A2EB4(o) == 1 && fn_800A1AC0(o) != 1) {
        int t = fn_8007FB2C__FP13Unk8007F198_Ci(lbl_8061930C, 0);
        if (t == 0x14) {
            if (a == 0 || a == 3)
                return 0;
            return 1;
        }
        if (t == 0x22) {
            if (a == 0 || a == 3)
                return 1;
        }
        return 2;
    }
    return 3;
}

extern "C" DB_OVERLAY int fn_8057CED4(int a, int b)
{
    void* s = lbl_8061930C;
    Unk8006A138_It<3> it(0);
    int i = 0;
    do {
        if (b == fn_8007B320__18Unk8007B2B0_Screenii(s, fn_80083FC0__Fi(i), a))
            return 1;
        i = it.Next();
    } while (i <= 3);
    return 0;
}

extern "C" DB_OVERLAY void fn_8057CF60(int a, int b)
{
    void* s = lbl_8061930C;
    fn_8007B320__18Unk8007B2B0_Screenii(s, fn_80083FC0__Fi(b), a);
}

extern "C" DB_OVERLAY int fn_8057D084(int a)
{
    if (fn_8008499C__FPv(a) == 1) {
        int id = fn_8008463C__Fi(a);
        return fn_800A3A10(lbl_80619948, id)->v10(a);
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8057D0F0(int a)
{
    if (fn_800845E4__Fi(a) == 1) {
        int id = fn_80084114__Fi(a);
        return fn_800A3A10(lbl_80619948, id)->v5(a);
    }
    return 0;
}

extern "C" DB_OVERLAY float fn_8057D4EC(void* self, int mode)
{
    float r = lbl_805FFFD0;
    int a, b;
    switch (mode) {
    case 0:
        a = 0;
        b = 6;
        break;
    case 6:
        a = 6;
        b = 4;
        break;
    default:
        a = mode;
        b = 1;
        break;
    }
    r = fn_8057D810(self, a, b);
    return r;
}

extern "C" DB_OVERLAY char* fn_8057DDB4(char* p, int i)
{
    return p + (i * 0x634 + 4);
}

extern "C" DB_OVERLAY int fn_8057DE6C(int k)
{
    switch (k) {
    case 0:
    case 10:
        return 0;
    case 12:
        return 7;
    case 13:
        return 8;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
    case 7:
    case 8:
    case 11:
        return 6;
    }
    return 0;
}

extern "C" DB_OVERLAY void fn_8057DF2C(int* p)
{
    *p = 2;
}

extern "C" DB_OVERLAY void fn_8057DF38(void* p, int c)
{
    if (c & 1)
        fn_80377408(p);
}

extern "C" DB_OVERLAY void fn_8057DF60(void)
{
    fn_80542FCC();
}

extern "C" DB_OVERLAY void fn_8057E03C(void* self, int c)
{
    *(const void**)((char*)self + 0x34) = lbl_80682C38;
    if (c & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_80581368(int a, int b)
{
    return a * (b + 1);
}

extern "C" DB_OVERLAY int fn_80581374(unsigned i)
{
    return i <= 0x67 ? lbl_80600038[i] * 0x19 : 0;
}

extern "C" DB_OVERLAY int fn_80581398(unsigned i)
{
    return i <= 0x67 ? lbl_806000A0[i] ^ 1 : 0;
}

extern "C" DB_OVERLAY void fn_805814EC(DbV8** list)
{
    if (*list) {
        DbV8** q = list;
        do {
            delete *q;
            q++;
        } while (*q);
    }
}
