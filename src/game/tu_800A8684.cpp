/*
 * Game code, .text 0x800A8684-0x800A9858 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/chooser.h"
#include "game/tu_800A8684.h"
#include "game/tu_8001B190.h"

extern const char* lbl_80619308;
extern int lbl_8061996C;
extern const char* lbl_80619968;
extern const float lbl_805B6274;

extern "C" {
int fn_80377E04(void* self, int* out, int key);
int fn_80377E90(void* self, int* a, int* b, int key);
void fn_8014D8AC(void* p);
void fn_800A7518(int a, int b);
}

extern "C" {
void fn_8007FDD4(void* mgr, int v);
void fn_80086DFC(void* o, int v);
void fn_800C1D6C(void* p);
}
struct Unk800A89DC_Slot {
    char pad0[0x10];
    void* m10;
};
struct Unk800A89DC_Mgr {
    char pad0[4];
    Unk800A89DC_Slot* m4;
    Unk800A89DC_Slot* m8;
};
extern void* lbl_8061930C;
extern Unk800A89DC_Mgr* lbl_806192E0;
extern const char* lbl_80619974[];
extern int lbl_805C2D08[];

struct Unk800A8898_Inner {
    char pad0[0x1CD0];
    int m1CD0;
};
struct Unk800A8898 {
    char pad0[0x14];
    Unk800A8898_Inner* m14;
};

extern "C" void* fn_800A883C(void** p);

struct UnkFEMgr {          /* 0xD8-byte object created on demand at lbl_8061A32C */
    char pad0[0xD0];
    int mD0;
    int mD4;
};
struct UnkFESingleton;
extern "C" {
void* fn_800B64BC(void* p);
UnkFESingleton* fn_800AA19C();
void fn_800AA2FC(UnkFESingleton* s, int a, int b, int c);
void* fn_800B8144();
void fn_800B82D0(void* s, int a, int b);
void fn_80072A84(void* o);
void fn_8007295C(void* o);
void fn_800766B8(void* o, int a);
}
extern UnkFEMgr* lbl_8061A32C;
extern const char* lbl_80619A94[];
extern const char* lbl_806199D8[];
extern const char* lbl_806199E4[];
extern const char* lbl_80619A48[];
extern const char* lbl_80619A54[];
extern const char* lbl_80619C18[];
extern int lbl_805C2D68[];
extern int lbl_805C2D70[];
extern int lbl_805C2DD0[];
extern int lbl_805C2DD8[];
extern int lbl_805C2E14[];
extern const char lbl_805B75F0[];
extern int lbl_80619C10;
extern const char* lbl_80619C0C;
void* operator new(unsigned size, int heap);

Unk8001BC8C* fn_8001BC4C();

/* ---- generated externs ---- */
extern const char lbl_805B7340[];
extern const char lbl_805B7358[];
extern const char lbl_805B7364[];
extern const char lbl_805B7374[];
extern const char lbl_805B7388[];
extern const char lbl_805B7398[];
extern const char lbl_805B73DC[];
extern const char lbl_805B75F8[];
extern const char lbl_805B7640[];
extern const char lbl_805B7650[];
extern const char lbl_805B78A0[];
extern const char lbl_805B86C0[];
extern const char lbl_805B8AAC[];
extern int lbl_80619970;
extern int lbl_806199D4;
extern int lbl_806199E0;
extern int lbl_80619A44;
extern int lbl_80619A50;
extern int lbl_80619A90;
extern int lbl_80619C14;

/* ---- functions ---- */
extern "C" {

void fn_800A8684() {}

void fn_800A8688(void* p)
{
    fn_80400560(p, 0x28);
}

void fn_800A86AC(int a, int b, int c, char* dst)
{
    fn_8040B61C(dst, lbl_80619308);
}

void fn_800A86D8() {}

void fn_800A86DC(void* p)
{
    fn_80400560(p, 0x28);
}

void fn_800A8700(int a, int b, int c, char* dst)
{
    fn_8040B61C(dst, lbl_80619308);
}

void fn_800A872C() {}

void fn_800A8730(void* p)
{
    fn_80400560(p, 0x28);
}

void fn_800A8754(int a, int b, int c, char* dst)
{
    fn_8040B61C(dst, lbl_80619308);
}

void fn_800A8780() {}

void fn_800A8784(void* p)
{
    fn_80400560(p, 0x28);
}

void fn_800A87A8() {}

void fn_800A87AC() {}

void fn_800A87B0() {}

int fn_800A87B4(void** self, int key)
{
    int out;
    return fn_80377E04(fn_800A883C(self), &out, key) != 0;
}

int fn_800A87FC(void** self, int key)
{
    int a;
    int b;
    fn_80377E90(fn_800A883C(self), &a, &b, key);
    return a;
}

void* fn_800A883C(void** p)
{
    return *p;
}

float fn_800A8844()
{
    return lbl_805B6274;
}

void fn_800A8850(void* p)
{
    fn_80400560(p, 0x28);
}

void fn_800A8874(char* p)
{
    fn_8014D8AC(p + 0x28);
}

int fn_800A8898(Unk800A8898* p)
{
    if (p->m14->m1CD0 == 0) {
        return 0;
    }
    return 1;
}

void fn_800A88B4() {}

void fn_800A88B8()
{
    fn_800A7518(1, 0xffff);
}

void fn_800A88E4()
{
    fn_800A7518(0, 0xffff);
}

int fn_800A8910(void* self, char** ps, unsigned n)
{
    unsigned used = 0;
    char buf[4];
    if (fn_8040B6A0(*ps) != 0) {
        fn_80378B68(*ps, n, buf, 4, lbl_8061996C, 1, &used);
        unsigned t = used + 1;
        if (t < n) {
            *ps = *ps + t;
        } else {
            *ps = *ps + used;
        }
        if (fn_8040B574(lbl_80619968, buf) == 0) {
            return 1;
        }
    }
    return 0;
}

int fn_800A89C4(UnkFEObj* self)
{
    if (self->m4 == -0x3e7) {
        return 0;
    }
    return 1;
}

void fn_800A89DC(UnkFEObj* self)
{
    if (self->fn_vslot3()) {
        int v = self->m4;
        fn_8007FDD4(lbl_8061930C, v);
        fn_80086DFC(lbl_806192E0->m4->m10, v);
        fn_80086DFC(lbl_806192E0->m8->m10, v);
        fn_800C1D6C(fn_800B555C()->m8);
    }
}

void fn_800A8A70(UnkFEObj* self, char* s, int n)
{
    if (fn_8040B6A0(s) != 0) {
        char* p = s;
        int i = 0;
        if (self->fn_vslot6(&p, n)) {
            for (; i <= 0x17; i++) {
                if (fn_8040B574(p, lbl_80619974[i]) == 0) {
                    self->m4 = lbl_805C2D08[i];
                    break;
                }
            }
        } else {
            self->m4 = -0x3e7;
        }
    }
}

void fn_800A8B30(void* self, Unk8037B3E8* o)
{
    o->fn_8037B728(lbl_805B7340, lbl_805B7358, self, lbl_80619970);
}

void fn_800A8B70(UnkFEObj* self)
{
    if (self->fn_vslot3()) {
        int v = self->m4;
        if (lbl_8061A32C == 0) {
            lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
        }
        lbl_8061A32C->mD0 = 1;
        lbl_8061A32C->mD4 = v;
    }
}

void fn_800A8BF0(void* self, Unk8037B3E8* o)
{
    o->fn_8037B728(lbl_805B7340, lbl_805B7364, self, lbl_80619970);
}

int fn_800A8C30(UnkFEObj* self)
{
    if (self->m8 == 0x0) {
        return 0;
    }
    return 1;
}

void fn_800A8C48(UnkFEObj* self)
{
    if (self->fn_vslot3()) {
        fn_800AA2FC(fn_800AA19C(), self->m8, self->m4, self->mC);
    }
}

void fn_800A8CA4(UnkFEObj* self, char* s, unsigned n)
{
    if (fn_8040B6A0(s) != 0) {
        char* p = s;
        unsigned used = 0;
        char a[0x28];
        char b[0x28];
        int ok = self->fn_vslot6(&p, n);
        if (ok) {
            fn_80378B68(p, n, a, 0x28, lbl_8061996C, 1, &used);
            unsigned t = used + 1;
            if (t < n) {
                p = p + t;
                unsigned rem = n - 1;
                fn_80378B68(p, rem - used, b, 0x28, lbl_8061996C, 1, &used);
                unsigned t2 = used + 1;
                if (t2 < n) {
                    p = p + t2;
                } else {
                    p = p + used;
                }
            } else {
                p = p + used;
            }
            self->m8 = fn_80378568(a, 0);
            self->m4 = fn_80378568(b, 0);
            self->mC = fn_80378568(p, 0);
        } else {
            self->m4 = ok;
            self->m8 = ok;
            self->mC = ok;
        }
    }
}

void fn_800A8DE8(void* self, Unk8037B3E8* o)
{
    o->fn_8037B728(lbl_805B7374, lbl_805B7388, self, (int)lbl_805B7398);
}

int fn_800A8E28(UnkFEObj* self)
{
    if (self->m4 == 0x9d) {
        return 0;
    }
    return 1;
}

void fn_800A8E40(UnkFEObj* self, int* flag)
{
    if (*flag == 0) {
        fn_8001BC4C()->fn_8001BDAC(self->m4);
    }
}

void fn_800A8E80(UnkFEObj* self, char* s, int n)
{
    if (fn_8040B6A0(s) != 0) {
        char* p = s;
        int i = 0;
        if (self->fn_vslot6(&p, n)) {
            for (; i <= 1; i++) {
                if (fn_8040B574(p, *(lbl_806199D8 + i)) == 0) {
                    self->m4 = *(lbl_805C2D68 + i);
                    break;
                }
            }
        } else {
            self->m4 = 0x9d;
        }
    }
}

void fn_800A8F40(void* self, Unk8037B3E8* o)
{
    o->fn_8037B728(lbl_805B7340, lbl_805B73DC, self, lbl_806199D4);
}

int fn_800A8F80(UnkFEObj* self)
{
    if (self->m4 == -0x3) {
        return 0;
    }
    return 1;
}

void fn_800A8F98(UnkFEObj* self)
{
    if (self->fn_vslot3()) {
        fn_800B82D0(fn_800B8144(), self->m4, 0);
    }
}

void fn_800A8FF0(UnkFEObj* self, char* s, int n)
{
    if (fn_8040B6A0(s) != 0) {
        char* p = s;
        char buf[0x14];
        unsigned used = 0;
        int i = 0;
        if (self->fn_vslot6(&p, n)) {
            fn_80378B68(p, n, buf, 0x14, lbl_8061996C, 1, &used);
            for (i = 0; i <= 0x17; i++) {
                if (fn_8040B574(buf, lbl_806199E4[i]) == 0) {
                    self->m4 = lbl_805C2D70[i];
                    break;
                }
            }
            if (fn_8040B574(p, lbl_805B75F0) == 0) {
                self->m8 = 0;
            }
        } else {
            self->m4 = -3;
            self->m8 = 1;
        }
    }
}

void fn_800A9104(void* self, Unk8037B3E8* o)
{
    o->fn_8037B728(lbl_805B7340, lbl_805B75F8, self, lbl_806199E0);
}

int fn_800A9144(UnkFEObj* self)
{
    if (self->m4 == 0x0) {
        return 0;
    }
    return 1;
}

void fn_800A915C(UnkFEObj* self)
{
    if (self->fn_vslot3() && (self->m4 & 2)) {
        fn_80072A84(lbl_8061930C);
        fn_8007295C(lbl_8061930C);
        fn_800766B8(lbl_8061930C, 0);
    }
}

void fn_800A91D0(UnkFEObj* self, char* s, int n)
{
    unsigned used = 0;
    char buf[0x14];
    if (fn_8040B6A0(s) != 0) {
        do {
            fn_80378B68(s, n, buf, 0x14, lbl_8061996C, 1, &used);
            int rem = n - 1;
            n = rem - used;
            if (n > 0) {
                s += used + 1;
            } else {
                s += used;
            }
            for (int i = 0; i <= 1; i++) {
                if (fn_8040B574(buf, *(&lbl_80619A48[0] + i)) == 0) {
                    self->m4 |= *(&lbl_805C2DD0[0] + i);
                    break;
                }
            }
        } while (n > 0);
    } else {
        self->m4 = 0;
    }
}

void fn_800A92D0(void* self, Unk8037B3E8* o)
{
    o->fn_8037B728(lbl_805B7640, lbl_805B7650, self, lbl_80619A44);
}

int fn_800A9310(UnkFEObj* self)
{
    if (self->m4 == 0x0) {
        return 0;
    }
    return 1;
}

void fn_800A9328(UnkFEObj* self)
{
    fn_800B555C()->m4 = self->m4;
}

void fn_800A935C(UnkFEObj* self, char* s, int n)
{
    unsigned used = 0;
    char buf[0x28];
    if (fn_8040B6A0(s) != 0) {
        do {
            fn_80378B68(s, n, buf, 0x28, lbl_8061996C, 1, &used);
            int rem = n - 1;
            n = rem - used;
            if (n > 0) {
                s += used + 1;
            } else {
                s += used;
            }
            for (int i = 0; i <= 0xe; i++) {
                if (fn_8040B574(buf, lbl_80619A54[i]) == 0) {
                    self->m4 |= lbl_805C2DD8[i];
                    break;
                }
            }
        } while (n > 0);
    } else {
        self->m4 = 0;
    }
}

void fn_800A945C(void* self, Unk8037B3E8* o)
{
    o->fn_8037B728(lbl_805B7640, lbl_805B78A0, self, lbl_80619A50);
}

int fn_800A949C(UnkFEObj* self)
{
    if (self->m4 == 0x0) {
        return 0;
    }
    return 1;
}

void fn_800A94B4(UnkFEObj* self)
{
    fn_800B555C()->m0 = self->m4;
}

void fn_800A94E8(UnkFEObj* self, char* s, int n)
{
    if (fn_8040B6A0(s) != 0) {
        char* p = s;
        int i = 0;
        if (self->fn_vslot6(&p, n)) {
            for (; i <= 0x5d; i++) {
                if (fn_8040B574(p, lbl_80619A94[i]) == 0) {
                    self->m4 = i;
                    break;
                }
            }
        } else {
            self->m4 = 0;
        }
    }
}

void fn_800A9598(void* self, Unk8037B3E8* o)
{
    o->fn_8037B728(lbl_805B7340, lbl_805B86C0, self, lbl_80619A90);
}

int fn_800A95D8(void* self, char** ps, unsigned n)
{
    unsigned used = 0;
    char buf[4];
    if (fn_8040B6A0(*ps) != 0) {
        fn_80378B68(*ps, n, buf, 4, lbl_80619C10, 1, &used);
        unsigned t = used + 1;
        if (t < n) {
            *ps = *ps + t;
        } else {
            *ps = *ps + used;
        }
        if (fn_8040B574(lbl_80619C0C, buf) == 0) {
            return 1;
        }
    }
    return 0;
}

int fn_800A968C(UnkFEByte* self)
{
    if (self->m4 == 0) {
        return 0;
    }
    return 1;
}

/* near-miss: retail lays the `return 1` (vslot3 false) arm first, right after the call test; everything else matches */
int fn_800A96A4(UnkFEByte* self)
{
    if (self->fn_vslot3()) {
        unsigned char c = self->m4;
        if (!(c & 2)) {
            int t = c & 0x10;
            return t == 0;
        }
        return 0;
    }
    return 1;
}

void fn_800A9714(UnkFEByte* self, char* s, int n)
{
    unsigned used = 0;
    char buf[0x14];
    if (fn_8040B6A0(s) != 0) {
        do {
            fn_80378B68(s, n, buf, 0x14, lbl_80619C10, 1, &used);
            int rem = n - 1;
            n = rem - used;
            if (n > 0) {
                s += used + 1;
            } else {
                s += used;
            }
            for (int i = 0; i <= 4; i++) {
                if (fn_8040B574(buf, lbl_80619C18[i]) == 0) {
                    self->m4 |= lbl_805C2E14[i];
                    break;
                }
            }
        } while (n > 0);
    } else {
        self->m4 = 0;
    }
}

void fn_800A9818(void* self, Unk8037B3E8* o)
{
    o->fn_8037B728(lbl_805B7640, lbl_805B8AAC, self, lbl_80619C14);
}

}
