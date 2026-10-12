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

extern "C" void fn_8057D20C(char* self, int id, int a, int b);

struct DbGlob28 {
    char pad0[0x28];
    void* m28;
};
extern "C" int fn_8056A2F8(void* o, int cur, int mode, int a, int b, int who, int p6, int p7, int s8, int sC);

struct DbO74 {
    char pad0[0x74];
    int m74;
};
extern "C" {
int fn_800A4EA4(void* o);
int fn_80545BB8(void* p, int a);
}

extern const float lbl_805FFFD4;

/* Top-4 table of (candidate index, score) pairs at +0x2C, fed from seven scores at +8. */
struct DbTop4Slot {
    int idx;
    float val;
};
struct DbTop4 {
    char pad0[8];
    float sc[7];
    char pad24[0x2C - 0x24];
    DbTop4Slot e[4];
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
extern "C" char* fn_8057DDC4(char* self, int id);
extern "C" int fn_8057D15C(int a);
extern "C" int fn_8057DF80(int* out);
extern "C" void fn_8057D550(DbTop4* self);
extern "C" void fn_8057CFA8(int a, int b);
/* forward declarations (definitions are in address order) */
extern "C" int fn_8057CDB8(DbIdList* self, int k);
extern "C" int fn_8057CE00(int a);
extern "C" int fn_8057CED4(int a, int b);
extern "C" void fn_8057CF60(int a, int b);
extern "C" void fn_8057CFA8(int a, int b);
extern "C" int fn_8057D084(int a);
extern "C" int fn_8057D0F0(int a);
extern "C" int fn_8057D15C(int a);
extern "C" float fn_8057D4EC(void* self, int mode);
extern "C" void fn_8057D550(DbTop4* self);
extern "C" char* fn_8057DDB4(char* p, int i);
extern "C" char* fn_8057DDC4(char* self, int id);
extern "C" int fn_8057DE6C(int k);
extern "C" void fn_8057DF2C(int* p);
extern "C" void fn_8057DF38(void* p, int c);
extern "C" void fn_8057DF60(void);
extern "C" int fn_8057DF80(int* out);
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

extern "C" DB_OVERLAY void fn_8057CFA8(int a, int b)
{
    if (fn_80084954__FPv(a) == 1) {
        int id = fn_8008463C__Fi(a);
        DbHost* h = fn_800A3A10(lbl_80619948, id);
        if (fn_8057D15C(id) == 0 || b == 1)
            h->v8(a);
        else
            h->v9(a);
    } else {
        int id = fn_8008463C__Fi(a);
        fn_800A3A10(lbl_80619948, id)->v4(a);
    }
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

extern "C" DB_OVERLAY int fn_8057D15C(int a)
{
    if ((unsigned)(a - 2) <= 1) {
        int r = fn_8056A2F8(((DbGlob28*)lbl_80619948)->m28, 0, 0, 1, a, 0, 0, 2, 0, 0x1A);
        if (r == -1)
            return 1;
        return (unsigned)(r + 1) > (unsigned)fn_8007FB2C__FP13Unk8007F198_Ci(lbl_8061930C, a) / 2;
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

extern "C" DB_OVERLAY void fn_8057D550(DbTop4* self)
{
    for (int i = 0; i < 4; i++)
        self->e[i].val = lbl_805FFFD4;
    for (unsigned c = 0; c <= 6; c++) {
        for (unsigned j = 0; j < 4; j++) {
            if (self->sc[c] >= self->e[j].val)
                continue;
            for (unsigned k = 3; k > j; k--) {
                self->e[k].val = self->e[k - 1].val;
                self->e[k].idx = self->e[k - 1].idx;
            }
            self->e[j].val = self->sc[c];
            self->e[j].idx = c;
            break;
        }
    }
}

extern "C" DB_OVERLAY char* fn_8057DDB4(char* p, int i)
{
    return p + (i * 0x634 + 4);
}

/* near-miss: ~14 slots; retail keeps the search result in r3 and self in r30 (return-value pseudo) */
extern "C" DB_OVERLAY char* fn_8057DDC4(char* self, int id)
{
    char* r = 0;
    unsigned i = 0;
    if (*(int*)(self + 4) == id) {
        r = self + 4;
    } else {
        while (1) {
            i += 1;
            if (i > 5)
                break;
            int o = i * 0x634;
            if (*(int*)(self + o + 4) == id) {
                r = self + (o + 4);
                break;
            }
        }
    }
    if (r == 0) {
        char* e = self + 0x1F08;
        fn_8057D20C(e, id, fn_8007F9B4__FP13Unk8007F198_C(lbl_8061930C), 0);
        return e;
    }
    return r;
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

/* near-miss: retail sets r3=2 in the cmpwi/bne gap (one li per exit); not reproduced */
extern "C" DB_OVERLAY int fn_8057DF80(int* out)
{
    int t = fn_8007FE04__FP13Unk8007F198_D(lbl_8061930C)->m1D8;
    if (t == 1) {
        DbO74* o = (DbO74*)lbl_80619948;
        if ((fn_8007FE04__FP13Unk8007F198_D(lbl_8061930C)->m1D4 == 1 && fn_800A4EA4(o) != 0) || fn_800A2EB4(o) != 0 || o->m74 == 2)
            return 2;
        if (fn_80545BB8((char*)o + 0xA8, 0) != 0)
            *out = t;
        else
            *out = 2;
        return *out;
    }
    return 2;
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
