/*
 * Game code, .text 0x8021ADDC-0x8021F080 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8020EE9C.h"

extern "C" {
void fn_80205450(TaskInner* in, int x);
void fn_802123D4(Task* t, int kind, int x);
void fn_80229EF8(Task* t, int a, int b, int c, int d);
void fn_8021D4A4(Task* t);
void fn_8021D5D4(Task* t);
int fn_802055F4(TaskInner* in);
void fn_801E8A3C(Obj3A64* p, int a, int b);
void fn_8021C24C(Task* t, Player* p);
int fn_801EE6F4(Task* t, int a);
void fn_8021B430(Task* t, int a, int b, int c, int d, float f);
void fn_801F0174(Task* t, int a, int b);
void fn_801F0EA8(Task* t, int a);
void fn_801F0F48(Task* t, int a);
void fn_8022A71C(Task* t, int a, int b);
void fn_8021A288(Task* t, int a, int b);
void fn_8021CE28(Task* t, float f);
int fn_80225614(Task* t, int a);
int fn_801F41A4(Task* t);
int fn_80219B8C(Task* t, int a);
void fn_80213988(Task* t, int a, int b);
int fn_801F1CA4(Task* t, void* p, float* out);
}

/* Unsigned-to-float in an inline: its constant-pool read stays below the int stores. */
inline float UF(unsigned v)
{
    return (float)v;
}

extern float lbl_805D6148[1];
struct Unk8026C414_O;
struct Unk8026C414_X;
int fn_8026D730(Unk8026C414_O* o, Unk8026C414_X* x);
struct Unk80069F0C;
int fn_8006BE18(Unk80069F0C* o);
struct Unk8024EF40_A;
int fn_80255028(Unk8024EF40_A* a);
extern "C" {

void fn_801EDE78(Task* t, int x);
struct Unk8021C24C_Obj {
    char pad0[0x60];
    Vec3f m60;
    char pad6C[0x928 - 0x6C];
    Player* m928;
};
struct Unk8021BFFC_Obj {
    char pad0[0x60];
    Vec3f m60;
    char pad6C[0x928 - 0x6C];
    Player* m928;
};
extern "C" Vec3f fn_801E73E8(void* self, int k, int sel);
extern const Vec3f lbl_806055DC;
extern const float lbl_805D60EC;
extern const float lbl_805D60F0;
inline int NeFlag(int a, int b)
{
    int r = 0;
    if (a != b)
        r = 1;
    return r;
}
struct Unk8021BA44_Obj {
    char pad0[0x60];
    Vec3f m60;
};
inline Vec3f Unk8021BA44_Flat(Unk8021BA44_Obj* o)
{
    Vec3f v = o->m60;
    v.y = 0.0f;
    return v;
}
extern "C" int fn_802112B4(Sub* t, Player** out);
extern const Vec3f lbl_806055DC;
extern const float lbl_805D60DC;
void fn_8021BA44(Task* t)
{
    Unk8021BA44_Obj* cur = (Unk8021BA44_Obj*)t->m9C->m8[t->m9C->m3A5C];
    Vec3f pos = lbl_806055DC;
    Unk8021BA44_Obj* tgt = 0;
    fn_802112B4((Sub*)&t->m9C, (Player**)&tgt);
    if (tgt != 0) {
        pos = Unk8021BA44_Flat(tgt) - Unk8021BA44_Flat(cur);
    }
    RecQueue* q = t->m9C->m3A60;
    int n = q->count;
    if (n > 5) {
        for (int i = 0; i < n; i++) {
        }
        for (int i = 0; i < n; i++) {
        }
        q->count = 0;
    }
    fn_80204CCC(&q->e[q->count]);
    Rec* e = &q->e[q->count];
    q->count++;
    e->m4 = 3;
    e->m0 = 0xF;
    e->m9C = 1;
    e->mC = 1;
    e->m8 = 1;
    e->m80 = lbl_805D60DC;
    int diff = 0;
    Vec3f* pp = &pos;
    Vec3f* kp = (Vec3f*)&lbl_806055DC;
    if (pos.x != kp->x || pp->y != kp->y || pp->z != kp->z)
        diff = 1;
    if (diff != 0) {
        e->m94 = 1;
        e->m50 = pos;
    }
}

/* near-miss: 148/148 insns, 13 slots differ (about 97%), all register numbers or scheduling order. Retail keeps &cur->m60
   in r4 and gives the lbl_805D60F0 and lbl_806055AC address registers different numbers, so the li constant 6 lands in
   r6 (ours r4). The lbl_806055DC compare through a non-const view (kp) fixed the first half. Tried: compare forms,
   the copy through an inline, diff/pos order, a hill-climb and a permutation search over the store order, and the
   same non-const view for lbl_806055AC. */
void fn_8021BFFC(Task* t, int a, Player* p, Vec3f* v)
{
    RecQueue* q = t->m9C->m3A60;
    Unk8021BFFC_Obj* cur = (Unk8021BFFC_Obj*)t->m9C->m8[t->m9C->m3A5C];
    int n = q->count;
    if (n > 5) {
        for (int i = 0; i < n; i++) {
        }
        for (int i = 0; i < n; i++) {
        }
        q->count = 0;
    }
    PlayerSub* ps = &p->m58C;
    fn_80204CCC(&q->e[q->count]);
    Rec* e = &q->e[q->count];
    q->count++;
    cur->m928 = p;
    int flag = NeFlag(fn_80255028((Unk8024EF40_A*)ps), ps->m38);
    int diff = 0;
    Vec3f pos = lbl_806055DC;
    Vec3f* kp = (Vec3f*)&lbl_806055DC;
    if (v->x != kp->x || v->y != kp->y || v->z != kp->z)
        diff = 1;
    if (diff != 0)
        pos = *v;
    else
        fn_801E73E8(t, a, flag);
    e->m4 = 0x1E;
    e->m0 = 0x19;
    e->m28 = p;
    e->m1C = a;
    e->m9C = 1;
    e->m38 = pos;
    e->m80 = lbl_805D60EC;
    e->mC = 4;
    e->m8 = 3;
    e->m90 = lbl_805D60F0;
    e->m10 = 6;
    e->m94 = 1;
    e->m50 = lbl_806055AC - cur->m60;
    t->m9C->m60 = 0;
}

void fn_8021C24C(Task* t, Player* p)
{
    RecQueue* q = t->m9C->m3A60;
    Unk8021C24C_Obj* cur = (Unk8021C24C_Obj*)t->m9C->m8[t->m9C->m3A5C];
    int n = q->count;
    if (n > 5) {
        for (int i = 0; i < n; i++) {
        }
        for (int i = 0; i < n; i++) {
        }
        q->count = 0;
    }
    fn_80204CCC(&q->e[q->count]);
    Rec* e = &q->e[q->count];
    q->count++;
    Rec16* r = (Rec16*)((char*)t->m9C + (t->m9C->m3A5C * 0x10 + 0x9F4));
    cur->m928 = p;
    int s = fn_80211BB0(&t->m9C->mC0, t->m9C->m3A5C);
    if (s != -1) {
        fn_80211BA0(&t->m9C->mC0, s);
        r->mC = 1;
        fn_801EDE78(t, 0);
    }
    int isX = fn_8026D730((Unk8026C414_O*)p, 0) == 1;
    e->m4 = isX ? 3 : 0x1F;
    e->m9C = 1;
    e->m0 = 0x1A;
    e->mC = 4;
    e->m8 = 3;
    e->m28 = p;
    e->m80 = -1.0f;
    e->m94 = 1;
    const Vec3f* pc = &cur->m60;
    Vec3f d = lbl_806055AC - *pc;
    e->m50 = d;
    if (s != -1)
        r->m4 = s;
}

void fn_8021C424(Task* t, int a)
{
    RecQueue* q = t->m9C->m3A60;
    int n = q->count;
    if (n > 5) {
        for (int i = 0; i < n; i++) {
        }
        for (int i = 0; i < n; i++) {
        }
        q->count = 0;
    }
    fn_80204CCC(&q->e[q->count]);
    Rec* e = &q->e[q->count];
    q->count++;
    e->m4 = 0x2f;
    e->m0 = 0x28;
    e->m88 = -1.0f;
    e->m9C = 0;
    e->m80 = -1.0f;
    e->mD4 = a;
}

void fn_801837F4(Vec3f* out, int a, int b);
struct Unk8021C4E0_Obj {
    char pad0[0x60];
    Vec3f m60;
    char pad6C[0x708 - 0x6C];
    int m708;
};
inline Vec3f Unk8021C4E0_Flat(Unk8021C4E0_Obj* o)
{
    Vec3f v = o->m60;
    v.y = 0.0f;
    return v;
}
inline float Unk8021C4E0_Len2(Vec3f v)
{
    return v.x * v.x + v.z * v.z;
}
void fn_8021C4E0(Task* t)
{
    Unk8021C4E0_Obj* cur = (Unk8021C4E0_Obj*)t->m9C->m8[t->m9C->m3A5C];
    Obj4_36C* o = t->m9C->m0->m6CC;
    if (o != 0 && (Obj36C*)cur == o->m36C)
        fn_8021CE28(t, 3.0f);
    Vec3f pos;
    fn_801837F4(&pos, *(int*)((char*)t->m9C->m0 + 0x6B8), cur->m708);
    RecQueue* q = t->m9C->m3A60;
    int n = q->count;
    if (n > 5) {
        for (int i = 0; i < n; i++) {
        }
        for (int i = 0; i < n; i++) {
        }
        q->count = 0;
    }
    fn_80204CCC(&q->e[q->count]);
    Rec* e = &q->e[q->count];
    q->count++;
    e->m4 = 0x26;
    e->m0 = 0x1E;
    e->m9C = 1;
    e->m38 = pos;
    e->m88 = -1.0f;
    e->m80 = -1.0f;
    {
        const Vec3f* pc = &cur->m60;
        Vec3f d = pos - *pc;
        e->m50 = d;
    }
    e->m94 = 1;
    e->m8 = 1;
    if (fn_8006BE18((Unk80069F0C*)t->m9C->m0->m6F8) != 1 && !(Unk8021C4E0_Len2(Unk8021C4E0_Flat(cur)) <= 2822400.0f))
        e->mC = 1;
    else
        e->mC = 0;
}


struct Unk8021C6FC_Obj {
    char pad0[0x60];
    Vec3f m60;
};
inline Vec3f Unk8021C6FC_Flat(Unk8021C6FC_Obj* o)
{
    Vec3f v = o->m60;
    v.y = 0.0f;
    return v;
}
void fn_8021C6FC(Task* t, Unk8021C6FC_Obj* p)
{
    RecQueue* q = t->m9C->m3A60;
    Unk8021C6FC_Obj* cur = (Unk8021C6FC_Obj*)t->m9C->m8[t->m9C->m3A5C];
    int n = q->count;
    if (n > 5) {
        for (int i = 0; i < n; i++) {
        }
        for (int i = 0; i < n; i++) {
        }
        q->count = 0;
    }
    fn_80204CCC(&q->e[q->count]);
    Rec* e = &q->e[q->count];
    q->count++;
    e->m4 = 4;
    e->m0 = 0x21;
    e->m9C = 1;
    e->m88 = -1.0f;
    e->m80 = -1.0f;
    e->mC = 2;
    e->m10 = 4;
    e->m8 = 1;
    e->m38 = Unk8021C6FC_Flat(cur);
    e->m90 = 99.0f;
    e->m94 = 1;
    e->m28 = (Player*)p;
    e->m50 = Unk8021C6FC_Flat(p) - Unk8021C6FC_Flat(cur);
}

void fn_8021D0C8(Task* t, float f)
{
    RecQueue* q = t->m9C->m3A60;
    if (q->count == 0) {
        fn_80204CCC(&q->e[0]);
        Rec* e = &q->e[q->count];
        q->count++;
        e->m4 = 0;
        e->m0 = 0x26;
        e->m9C = 0;
        e->m80 = UF(t->m9C->m0->m4C) * lbl_805D6148[0] + f;
    }
}

void fn_8021D4A4(Task* t)
{
    RecQueue* q = t->m9C->m3A60;
    int n = q->count;
    if (n > 5) {
        for (int i = 0; i < n; i++) {
        }
        for (int i = 0; i < n; i++) {
        }
        q->count = 0;
    }
    fn_80204CCC(&q->e[q->count]);
    Rec* e = &q->e[q->count];
    q->count++;
    e->m4 = 0;
    e->m0 = 0x29;
    e->m9C = 1;
}

void fn_8021D548(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    fn_80205450(t->m9C, a);
    fn_802123D4(t, 0, 1);
    fn_80229EF8(t, a, e->m1C, e->m28->m460, 0);
    fn_8021D4A4(t);
}

void fn_8021D5B4(Task* t)
{
    fn_8021D5D4(t);
}

/* The zero comes from a global struct so the load stays below the record stores (see fn_8021247C). */
extern Vec3f lbl_805D617C;
void fn_8021DB40(Task* t, int idx, RecQueue* q)
{
    Rec* e = &q->e[0];
    Player* p = (Player*)ObjAt(t->m9C->m8, idx);
    if (fn_802055F4(t->m9C) == 1) {
        fn_801E8A3C(t->m9C->m3A64, idx, -1);
    }
    if (p->m570 == 0) {
        e->mA4 = 1;
        e->m80 = lbl_805D617C.x;
        e->m9C = 0;
        e->mAC = 0;
    }
}

void fn_8021DBC8(Task* t, int a, RecQueue* q)
{
    Rec* e = &q->e[0];
    if (!(e->m90 < 0.0f)) {
        e->m90 = e->m90 - 0.016666668f;
        return;
    }
    e->mA4 = 1;
    e->m80 = 0.0f;
    e->m9C = 0;
    e->mAC = 0;
    fn_80205450(t->m9C, a);
    fn_802123D4(t, 0, 1);
    if (e->m28) {
        fn_8021C24C(t, e->m28);
    } else {
        fn_801F0174(t, a, 0);
    }
}

extern Vec3f lbl_805D6188;
void fn_8021DC7C(Task* t, int idx, RecQueue* q)
{
    TaskInner* in = t->m9C;
    Obj36C* x = in->m4->m36C;
    if (x != ObjAt(in->m8, idx)) {
        Rec* e = &q->e[0];
        e->mA4 = 1;
        e->m80 = lbl_805D6188.x;
        e->m9C = 0;
        e->mAC = 0;
    } else if (x->m460 != idx) {
        Rec* e = &q->e[0];
        e->mA4 = 1;
        e->m80 = lbl_805D6188.x;
        e->m9C = 0;
        e->mAC = 0;
    }
}

extern Vec3f lbl_805D6198;
inline int Is3(Obj4_36C* o) { return o->m38C == 3; }

void fn_8021DCD4(Task* t, int a)
{
    Obj4_36C* o = t->m9C->m4;
    if (o->m36C != 0) {
        fn_80205450(t->m9C, a);
        fn_801F0EA8(t, a);
        fn_802123D4(t, 0, 1);
        if (a == o->m36C->m460) {
            t->m9C->mA4 = -1;
            t->m9C->m30 = 4;
            t->m9C->m5C = 0;
            fn_801F0174(t, a, 0);
        } else {
            fn_8021D4A4(t);
        }
    } else if (fn_802055F4(t->m9C->m3A64->m9C) == 1) {
        float f = 0.0f;
        int r = fn_801F1CA4(t, (char*)t->m9C + 0xAC, &f);
        if (!(f <= 144.0f)) {
            r = -1;
        }
        fn_801E8A3C(t->m9C->m3A64, a, r);
    }
}

void fn_8021DFF4(Task* t, int idx, RecQueue* q)
{
    TaskInner* in = t->m9C;
    Obj4_36C* o = in->m4;
    void* cur = ObjAt(in->m8, idx);
    if (Is3(o) == 1) {
        Rec* e = &q->e[0];
        e->mA4 = 1;
        e->m80 = lbl_805D6198.x;
        e->m9C = 0;
        e->mAC = 0;
        fn_801EE6F4(t, idx);
        fn_80205450(t->m9C, idx);
        fn_802123D4(t, 1, 1);
        fn_8021B430(t, 1, 1, 0, 0, 1.0f);
    } else if ((void*)o->m36C == cur) {
        fn_801EE6F4(t, idx);
        fn_801F0174(t, idx, 0);
    }
}

void fn_8021E0D8(Task* t, int a)
{
    TaskInner* in = t->m9C;
    Obj4_36C* o = in->m4;
    void* cur = ObjAt(in->m8, a);
    if (o->m36C != 0 || o->m378 != 0) {
        if (o->m36C == cur) {
            fn_801F0EA8(t, a);
            fn_801F0174(t, a, 0);
        } else if (fn_80225614(t, a) == 0 && o->m36C == 0) {
            fn_801F0EA8(t, a);
            fn_802123D4(t, 0, 1);
            fn_8021CE28(t, 1.0f);
            fn_8021D4A4(t);
        }
    } else {
        int p = in->m1C4;
        int slot = in->m3A5C;
        fn_80205450(in, a);
        if (p != -1) {
            int q = fn_801F41A4(t);
            if (q == -1) {
                fn_801F0EA8(t, a);
                fn_802123D4(t, 0, 1);
                fn_8021CE28(t, 1.0f);
                fn_8021D4A4(t);
            } else if (q != p) {
                fn_802123D4(t, 0, 0);
                if (fn_80219B8C(t, q)) {
                    t->m9C->m1C4 = q;
                }
            }
        }
        fn_80205450(t->m9C, slot);
    }
}

/* near-miss: 93/94 insns, 7 aligned slots: retail tests o->m36C == 0 twice with cr0 (cmpwi r9,0 again after the cmpw against cur);
   ours keeps one cr7 compare and reuses it. Tried a local for m36C and nested ifs. */
void fn_8021E258(Task* t, int a)
{
    TaskInner* in = t->m9C;
    Obj4_36C* o = in->m4;
    void* cur = ObjAt(in->m8, a);
    if (o->m36C == 0 && o->m378 == 0) {
        return;
    }
    if (o->m36C == cur) {
        fn_801F0F48(t, a);
        fn_801F0174(t, a, 0);
        return;
    }
    if (o->m36C == 0 && o->m374 != 0) {
        fn_80205450(in, a);
        in = t->m9C;
        int x = in->mC0.m[3];
        if (x == o->m374->m460) {
            if (fn_802055F4(in) == 1 && o->m374->m460 == 1) {
                fn_802123D4(t, 0, 0);
                fn_8022A71C(t, 3, o->m378);
            } else {
                fn_802123D4(t, 0, 1);
                fn_8021A288(t, 3, o->m378);
            }
            fn_8021D4A4(t);
        } else {
            fn_801F0F48(t, a);
            fn_802123D4(t, 0, 0);
            fn_8021CE28(t, 1.0f);
            if (t->m9C->mC0.m[0] == -1) {
                fn_80213988(t, 0, 1);
            } else {
                fn_8021D4A4(t);
            }
        }
    }
}

}
