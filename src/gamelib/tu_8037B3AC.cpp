/*
 * EA gamelib (C:/mvp2004/libraries/gamelib: memory, datafile, animlib), built with
 * the game flags (cflags_game: -Os -G0 -ffloat-store),
 * .text 0x8037B3AC-0x8037C764 (code-only unit, 39 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

#include "game/chooser.h"

extern "C" {
void fn_8037B76C(Unk8037B3E8* self, int kind, int a, int b, int c, int d, int e, int f);
void fn_8037BCC0(const char* name, const char* group);
void fn_8037BD34(const char* name, const char* group);
void* fn_803774A8(unsigned size, int heap);
}

extern char lbl_806849A0[];

struct Unk802BA828 {
    Unk802BA828(int a);
    float m0;
    float m4;
    int m8;
    int mC;
    float m10;
    float m14;
    int m18;
    float m1C;
    float m20;
    int m24;
    float m28;
    float m2C;
    int m30;
};

extern Unk802BA828* lbl_80624254;

/* Attribute registration wrappers of the chooser root class (Unk8037B3E8):
 * each forwards to fn_8037B76C with the attribute kind as the second argument. */
extern "C" char* strcpy(char*, const char*);
extern "C" int fn_8037C5D8(int hash);
unsigned fn_80378568(const char* s, int n);
extern "C" void fn_8037BC28(const char* name, int kind, int a, const char* b, int c, int d, int e, int f);
extern Unk8037B3E8* lbl_806E9684[];
extern int lbl_80624250;
extern int lbl_806EFC10;

/* Attribute group record (0x44 bytes) in the table at lbl_80624254; m0 = 0x10 begin / 0x11 end. */
struct Unk8037BCC0_Entry {
    int m0;
    char m4[0x34];
    int m38;
    int m3C;
    int m40;
};

extern "C" char* strncpy(char*, const char*, unsigned);
extern "C" int strcmp(const char*, const char*);
extern int lbl_806EFC14;
extern int lbl_80624258;

extern "C" unsigned strlen(const char*);
extern int lbl_8062425C;
extern int lbl_806942AC[0x200];
extern int lbl_80694AAC[0x200];
extern "C" int fn_8037C544(int key);

/* View of the root class vtable with the true return type of slot 10 (a "is registered" query). */
struct Unk8037BB0C_View {
    virtual ~Unk8037BB0C_View();
    virtual void v2();
    virtual const char* v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int v10();
};

extern "C" Unk8037B3E8* fn_8037D680(int c, int hash, int a);

extern "C" int fn_803EE310(void* o);
extern "C" void fn_803FFA60(void* dst, const void* src, unsigned n);
extern "C" void fn_803EDA0C(void* p);

/* View of the root class vtable with the true signatures of slots 5 and 7..9 (fn_8037C3F8). */
struct Unk8037C3F8_View {
    virtual ~Unk8037C3F8_View();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int a);
    virtual void v9();
};

extern "C" void fn_8037B458(Unk8037B3E8* self, int p1, int p2, int p3, int p4)
{
    fn_8037B76C(self, 4, 0, p1, p2, p3, p4, 0);
}

extern "C" void fn_8037B494(Unk8037B3E8* self, int p1, int p2, int p3, int p4)
{
    fn_8037B76C(self, 1, 0, p1, p2, p3, p4, 0);
}

extern "C" void fn_8037B4D0(Unk8037B3E8* self, int p1, int p2, int p3, int p4)
{
    fn_8037B76C(self, 2, 0, p1, p2, p3, p4, 0);
}

extern "C" void fn_8037B50C(Unk8037B3E8* self, int p1, int p2, int p3, int p4)
{
    fn_8037B76C(self, 5, 0, p1, p2, p3, p4, 0);
}

extern "C" void fn_8037B548(Unk8037B3E8* self, int p1, int p2)
{
    fn_8037B76C(self, 0, 0, p1, 0, 0, p2, 0);
}

extern "C" void fn_8037B584(Unk8037B3E8* self, int p1, int p2, int p3, int p4)
{
    fn_8037B76C(self, 6, 0, p1, p2, p4, 0, p3);
}

extern "C" void fn_8037B5C0(Unk8037B3E8* self, int p1, int p2, int p3)
{
    fn_8037B76C(self, 11, 0, p1, p2, p3, 0, 0);
}

extern "C" void fn_8037B5FC(Unk8037B3E8* self, int p1, int p2)
{
    fn_8037B76C(self, 7, 0, p1, p2, 0, 0, 0);
}

extern "C" void fn_8037B638(Unk8037B3E8* self, int p1, int p2, int p3)
{
    fn_8037B76C(self, 8, 0, p1, p2, p3, 0, 0);
}

extern "C" void fn_8037B674(Unk8037B3E8* self, int p1, int p2, int p3, int p4)
{
    fn_8037B76C(self, 13, 0, p1, p2, p3, p4, 0);
}

extern "C" void fn_8037B6B0(Unk8037B3E8* self, int p1, int p2, int p3)
{
    fn_8037B76C(self, 10, 0, p1, p2, p3, 0, 0);
}

extern "C" void fn_8037B6EC(Unk8037B3E8* self, int p1, int p2)
{
    fn_8037B76C(self, 14, 0, p1, p2, 0, 0, 0);
}

extern "C" void fn_8037B728__11Unk8037B3E8PCcT1Pvi(Unk8037B3E8* self, int p1, int p2, int p3, int p4)
{
    fn_8037B76C(self, 12, p1, p2, p3, p4, 0, 0);
}

extern "C" void fn_8037B76C(Unk8037B3E8* self, int kind, int a, int b, int c, int d, int e, int f)
{
    fn_8037BC28(self->fn_vslot3(), kind, a, (const char*)b, c, d, e, f);
}

extern "C" void fn_8037B7E4() {}

extern "C" void fn_8037B7E8(Unk8037B3E8* self, const char* group)
{
    fn_8037BCC0(self->fn_vslot3(), group);
}

extern "C" void fn_8037B830(Unk8037B3E8* self, const char* group)
{
    fn_8037BD34(self->fn_vslot3(), group);
}

extern "C" void fn_8037B878(Unk8037B3E8* self, int p1, int p2)
{
    fn_8037B76C(self, 18, 0, p1, p2, 0, 0, 0);
}

extern "C" void fn_8037B8B4(int n)
{
    lbl_80624254 = (Unk802BA828*)fn_803774A8(n * 0x44, 0);
}

extern "C" void fn_8037B8EC()
{
    if (lbl_80624254 != 0) {
        delete[] lbl_80624254;
        lbl_80624254 = 0;
    }
}

extern "C" void fn_8037B92C(Unk8037B3E8* self, const char* name)
{
    if (lbl_80624250 == 0) {
        for (int i = 0; i < 0xA5; i++) {
            lbl_806E9684[i] = 0;
            lbl_806EFC10 = 0;
        }
    }
    if (lbl_80624250 <= 0xA4) {
        if (fn_8037C5D8(fn_80378568(name, 0)) == -1) {
            lbl_806E9684[lbl_80624250] = self;
            lbl_80624250++;
        }
    }
}

Unk8037B3E8::Unk8037B3E8(const char* name)
{
    fn_8037B92C(this, name);
}

extern "C" void fn_8037B9D4(Unk8037B3E8* self, int hash)
{
    if (lbl_80624250 == 0) {
        for (int i = 0; i < 0xA5; i++) {
            lbl_806E9684[i] = 0;
            lbl_806EFC10 = 0;
        }
    }
    if (lbl_80624250 <= 0xA4) {
        if (fn_8037C5D8(hash) == -1) {
            lbl_806E9684[lbl_80624250] = self;
            lbl_80624250++;
        }
    }
}

Unk8037B3E8::Unk8037B3E8(unsigned int hash)
{
    fn_8037B9D4(this, hash);
}

extern "C" int fn_8037BA74(int hash)
{
    if (lbl_806EFC14 != hash) {
        int idx = fn_8037C5D8(hash);
        if (idx == -1)
            return 0;
        lbl_806EFC14 = hash;
        Unk8037B3E8* o = lbl_806E9684[idx];
        lbl_806EFC10 = 0;
        lbl_80624258 = 1;
        o->fn_vslot2();
        lbl_80624258 = 0;
    }
    return 1;
}

extern "C" void fn_8037BB0C(char* out, int* remaining)
{
    int first = 1;
    for (int i = 0; i < lbl_80624250; i++) {
        if (((Unk8037BB0C_View*)lbl_806E9684[i])->v10() != 0) {
            if (first == 0) {
                *out++ = ',';
                (*remaining)--;
            } else {
                first = 0;
            }
            int len = strlen(lbl_806E9684[i]->fn_vslot3());
            strncpy(out, lbl_806E9684[i]->fn_vslot3(), len);
            out += len;
            *remaining -= len;
        }
    }
    *out = 0;
}

extern "C" void fn_8037BC28(const char* nm, int kind, int a, const char* b, int c, int d, int e, int f)
{
    ((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m0 = kind;
    strncpy(((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m4, b, 0x31);
    ((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m4[0x31] = 0;
    ((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m38 = c;
    ((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m3C = d;
    ((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m40 = f;
    lbl_806EFC10++;
}

extern "C" void fn_8037BCC0(const char* name, const char* group)
{
    ((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m0 = 0x10;
    strcpy(((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m4, group);
    ((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m38 = 0;
    ((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m3C = 0;
    ((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m40 = 0;
    lbl_806EFC10++;
}

extern "C" void fn_8037BD34(const char* name, const char* group)
{
    ((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m0 = 0x11;
    strcpy(((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m4, group);
    ((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m38 = 0;
    ((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m3C = 0;
    ((Unk8037BCC0_Entry*)lbl_80624254)[lbl_806EFC10].m40 = 0;
    lbl_806EFC10++;
}

extern "C" Unk8037B3E8* fn_8037BDA8(int hash, int a, int c)
{
    Unk8037B3E8* result = 0;
    if (fn_8037BA74(hash) != 0) {
        int i = 0;
        int found = 0;
        int idx = fn_8037C5D8(hash);
        if (idx != -1) {
            Unk8037B3E8* o = lbl_806E9684[idx];
            if (o != 0)
                o->fn_vslot6();
            Unk8037B3E8* r = fn_8037D680(c, hash, a);
            if (r != 0) {
                result = r;
                found = 1;
            }
        }
        if (found == 0 && i != lbl_80624250) {
            do {
                Unk8037B3E8* o = lbl_806E9684[i];
                if (o != 0 && hash == o->fn_vslot4()) {
                    found = 1;
                    result = lbl_806E9684[i]->fn_vslot5();
                }
                i++;
                if (found != 0)
                    break;
            } while (i != lbl_80624250);
        }
    }
    return result;
}

extern "C" int fn_8037BEE4(int hash, const char* name)
{
    int found = 0;
    int i = 0;
    if (fn_8037BA74(hash) != 0 && i != lbl_806EFC10) {
        do {
            if (strcmp(((Unk8037BCC0_Entry*)lbl_80624254)[i].m4, name) == 0)
                found = 1;
            else
                i++;
        } while (!found && i != lbl_806EFC10);
    }
    if (!found)
        i = -1;
    return i;
}

extern "C" void fn_8037BF88()
{
    for (int i = 0; i < lbl_80624250; i++)
        lbl_806E9684[i] = 0;
}

/* near-miss (99.9%): swaps the live object with the registered one; same instructions, but retail loads the tested registry entry into r4 where ours uses r0 (one cmpwi pair). */
extern "C" void fn_8037C3F8(int hash, int a, int flag, Unk8037C3F8_View* obj)
{
    int idx = fn_8037C5D8(hash);
    if (idx != -1) {
        Unk8037C3F8_View* reg = (Unk8037C3F8_View*)lbl_806E9684[idx];
        if (reg != 0)
            reg->v8(a);
        if (obj == 0) {
            Unk8037C7FC* mgr = fn_8037C7FC();
            obj = (Unk8037C3F8_View*)mgr->fn_8037CE98(hash, a, 0);
        }
        if (obj != 0 && lbl_806E9684[idx] != 0) {
            if (flag == 0)
                obj->v7();
            obj->~Unk8037C3F8_View();
            int n = fn_803EE310(obj);
            fn_803FFA60(obj, lbl_806E9684[idx], n);
            void* v = ((Unk8037C3F8_View*)lbl_806E9684[idx])->v5();
            fn_803FFA60(lbl_806E9684[idx], v, n);
            fn_803EDA0C(v);
            obj->v9();
        }
    }
}

extern "C" int fn_8037C544(int key)
{
    for (int i = 0; i < lbl_80624250; i++) {
        Unk8037B3E8* o = lbl_806E9684[i];
        if (o != 0 && key == o->fn_vslot4())
            return i;
    }
    return -1;
}

struct Unk8037C704 {
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[8];
    int m18;
    const void* m1C;
    Unk8037C704();
};

Unk8037C704::Unk8037C704()
{
    m1C = lbl_806849A0;
    m0 = 0;
    m4 = 0;
    m8 = 0;
    mC = 0;
    m18 = 0;
}

extern "C" int fn_8037C5D8(int hash)
{
    int h = (unsigned char)(hash + (hash >> 15));
    if (lbl_8062425C != 0) {
        lbl_8062425C = 0;
        for (int i = 0; i < 0x200; i++)
            lbl_806942AC[i] = -1;
    }
    int r = lbl_806942AC[h];
    if (r == -1) {
        r = fn_8037C544(hash);
        if (r == -1)
            return -1;
        lbl_806942AC[h] = r;
        lbl_80694AAC[h] = hash;
        return r;
    }
    if (lbl_80694AAC[h] == hash)
        return r;
    for (int i = 0xFF; i <= 0x1FF; i++) {
        if (lbl_80694AAC[i] == hash)
            return lbl_806942AC[i];
        if (lbl_806942AC[i] == -1) {
            r = fn_8037C544(hash);
            if (r != -1) {
                lbl_80694AAC[i] = hash;
                lbl_806942AC[i] = r;
            }
            return r;
        }
    }
    return -1;
}

struct DtorAt1C { char pad[0x1c]; const void* m; };


extern "C" void fn_80377408(void* p);

extern "C" void fn_8037C730(DtorAt1C* self, int chrg)
{
    self->m = lbl_806849A0;
    if (chrg & 1)
        fn_80377408(self);
}
