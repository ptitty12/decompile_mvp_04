/*
 * Game code, .text 0x802B5234-0x802B9218 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802ACD88.h"

typedef Unk802ACD88_Mgr Mgr;
typedef Unk802ACD88_Ent Ent;
typedef Unk802B5234_T T;

extern void* lbl_8061EAB4;
extern void* lbl_8061EAB8;
extern void* lbl_8061EABC;
extern void* lbl_8061EAC0;
extern void* lbl_8061EAC4;
extern void* lbl_8061EAC8;
extern void* lbl_8061EACC;
extern void* lbl_8061EAD4;
extern void* lbl_8061EAD8;
extern void* lbl_8061EADC;
extern void* lbl_8061EAE0;
extern const char lbl_805E0138[];
extern const char lbl_805E0EAC[];
extern const char lbl_805E0EBC[];
extern const char lbl_805E0ECC[];
extern const char lbl_805E0EDC[];
extern const char lbl_805E0EEC[];
extern const char lbl_805E0F04[];
extern const char lbl_805E0F1C[];
extern const char lbl_805E0F34[];
extern const char lbl_805E0F48[];

extern void* lbl_8061E978;
extern void* lbl_8061EA64;
extern int lbl_8061EA00[];
extern void* lbl_8061FF44;
extern const char lbl_805E0E5C[];
extern const char lbl_805E0E44[];
extern const char lbl_805E0E50[];
extern const char lbl_805E0E78[];
extern const char lbl_805E0E88[];
extern const char lbl_805E0E94[];
extern const char lbl_805E0EA0[];

extern "C++" {
int fn_802B96C4(const char* name, int a);
void* fn_802B9300(const char* name, int a, int b, int c);
void* fn_802B98AC(const char* name, int a);
void fn_803FED48(const char* name, int a, int b, void* c);
void fn_803FEDB8(void* p, int a);
void fn_803EDA0C(void* p);
int fn_8040B574(const char* a, const char* b);
void fn_802AEBF0(void* a, const char* s);
void fn_802AEBCC(void* a, const char* s);
char* fn_8040B61C(char* d, const char* s);
void fn_803188FC(void* a, int b);
void fn_803DD73C(void* a, int b);
int fn_802B86D4(Mgr* m, const char* s, int* idx);
/* near-miss (parked, 44 vs 47 insns): retail keeps a register copy of the loop index and stores it to idx (stack) after each increment, re-reading idx for the strcpy */
void fn_802B8760(Mgr* m, const char* s);
void fn_802B881C(Mgr* m, const char* s);
int fn_800968C0(void* o, int x, int y);
int fn_80089AA0(void* o, int a, int b);
int fn_8008CFD8(void* o, int a, int b);
int fn_804089B4(char* buf, const char* fmt, ...);
void fn_802C9284(void* p, int a, void* o, int b, int c);
}

Unk802B5234_T* fn_802B53C4(Unk802B5234_T* self)
{
    self->m[0] = 0;
    self->m[1] = 0;
    self->m[2] = 0;
    self->m[3] = 0;
    self->m[4] = 0;
    self->m[5] = 0;
    self->m[6] = 0;
    self->m[7] = 0;
    self->m[8] = 0;
    self->m[9] = 0;
    self->m[10] = 0;
    self->m[11] = 0;
    self->m[12] = 0;
    self->m[13] = 0;
    self->m[14] = 0;
    self->m[15] = 0;
    self->m[16] = 0;
    self->m[17] = 0;
    self->m[18] = 0;
    self->m[19] = 0;
    self->m[20] = 0;
    self->m[21] = 0;
    self->m[22] = 0;
    self->m[23] = 0;
    self->m[24] = 0;
    self->m[25] = 0;
    self->m[26] = 0;
    self->m[27] = 0;
    self->m[28] = 0;
    self->m[29] = 0;
    self->m[30] = 0;
    self->m[31] = 0;
    self->m[32] = 0;
    self->m[33] = 0;
    self->m[34] = 0;
    self->m[35] = 0;
    self->m[36] = 0;
    self->m[37] = 0;
    self->m[38] = 0;
    self->m[39] = 0;
    self->m[40] = 0;
    self->m[41] = 0;
    self->m[42] = 0;
    self->m[43] = 0;
    return self;
}

Unk802B5234_V3 fn_802B5480()
{
    Unk802B5234_V3 a;
    Unk802B5234_V3 b;
    char pad[16];
    a.x = 2702.9f;
    a.y = 11078.4f;
    a.z = -13515.9f;
    b.x = -4908.36f;
    b.y = 19463.4f;
    b.z = -6725.12f;
    return b;
}

void fn_802B56C8()
{
    lbl_8061EA64 = 0;
    for (int i = 0; i < 25; i++)
        lbl_8061EA00[i] = 0;
}

/* near-miss: `li r0,0` is scheduled before the second lfs/fcmpu here, after the fcmpu in retail */
void fn_802B5D28(int* out, float x)
{
    int r;
    if (!(x >= 0.33333334f)) {
        r = 2;
    } else {
        if (!(x >= 0.8f))
            r = 1;
        else
            r = 0;
    }
    *out = r;
}

void fn_802B5F2C()
{
    fn_803188FC(lbl_8061FF44, 5);
}

void fn_802B832C(Mgr* m)
{
    if (*(void**)((char*)m + 0x18718) != 0) {
        fn_803DD73C(*(void**)((char*)m + 0x18718), 3);
        *(void**)((char*)m + 0x18718) = 0;
    }
    if (*(void**)((char*)m + 0x1871C) != 0) {
        fn_803EDA0C(*(void**)((char*)m + 0x1871C));
        *(void**)((char*)m + 0x1871C) = 0;
    }
}

/* near-miss: retail forms the offset pointer (subi r6) before the name address (addi r3) */
void fn_802B8548(Mgr* m)
{
    fn_803FED48(lbl_805E0E44, 0, 0, (char*)m + 0x18704);
    fn_803FED48(lbl_805E0E50, 0, 0, (char*)m + 0x18708);
}

void fn_802B85A0(Mgr* m)
{
    fn_803FED48(lbl_805E0E5C, 0, 0, (char*)m + 0x18710);
}

void fn_802B85D8(Mgr* m)
{
    fn_803FED48(lbl_805E0E78, 0, 0, (char*)m + 0x1870C);
}

int fn_802B86D4(Mgr* m, const char* s, int* idx)
{
    int i;
    for (i = 0; i <= 31; i++) {
        if (m->ent[i].cnt != 0 && fn_8040B574(m->ent[i].name, s) == 0) {
            *idx = i;
            return 1;
        }
    }
    *idx = 0;
    return 0;
}

/* near-miss (parked, 44 vs 47 insns): retail keeps a register copy of the loop index and stores it to idx (stack) after each increment, re-reading idx for the strcpy */
void fn_802B8760(Mgr* m, const char* s)
{
    int idx;
    if (fn_802B86D4(m, s, &idx) != 0) {
        m->ent[idx].cnt++;
    } else {
        for (idx = 0; idx <= 31; idx++) {
            if (m->ent[idx].cnt == 0) {
                m->ent[idx].cnt = 1;
                fn_8040B61C(m->ent[idx].name, s);
                fn_802AEBCC(lbl_8061E978, s);
                break;
            }
        }
    }
}

void fn_802B881C(Mgr* m, const char* s)
{
    int idx;
    if (fn_802B86D4(m, s, &idx) != 0) {
        if (--m->ent[idx].cnt == 0)
            fn_802AEBF0(lbl_8061E978, s);
    }
}

void fn_802B8888(Mgr* m, void* o, int x)
{
    char buf[32];
    int t = fn_800968C0(o, x, 1);
    int a = fn_8008CFD8((char*)o + 0xC9C, 0x21, t);
    fn_804089B4(buf, lbl_805E0E88, a);
    fn_802B8760(m, buf);
    fn_804089B4(buf, lbl_805E0E94, 0);
    fn_802B8760(m, buf);
}

void fn_802B891C(Mgr* m, void* o, int x)
{
    char buf[32];
    int t = fn_800968C0(o, x, 1);
    int a = fn_80089AA0((char*)o + 0xC74, 0x1A, t);
    fn_804089B4(buf, lbl_805E0EA0, a);
    fn_802B8760(m, buf);
}

void fn_802B898C(Mgr* m, void* o, int x)
{
    char buf[32];
    int t = fn_800968C0(o, x, 1);
    int a = fn_8008CFD8((char*)o + 0xC9C, 0x21, t);
    fn_804089B4(buf, lbl_805E0E88, a);
    fn_802B881C(m, buf);
    fn_804089B4(buf, lbl_805E0E94, 0);
    fn_802B881C(m, buf);
}

void fn_802B8A20(Mgr* m, void* o, int x)
{
    char buf[32];
    int t = fn_800968C0(o, x, 1);
    int a = fn_80089AA0((char*)o + 0xC74, 0x1A, t);
    fn_804089B4(buf, lbl_805E0EA0, a);
    fn_802B881C(m, buf);
}

void fn_802B8A90(Mgr* m)
{
    for (int i = 0; i < 32; i++) {
        if (m->ent[i].cnt > 0) {
            m->ent[i].cnt = 0;
            fn_802AEBF0(lbl_8061E978, m->ent[i].name);
        }
    }
}

void fn_802B8AFC(Mgr* m, void* o)
{
    fn_802C9284((char*)m + 0x12204, *(int*)((char*)o + 0x2C), o, 0, 1);
}

/* near-miss: retail orders the argument setup li r4/li r5/addi r6 before addi r3 (name) */
void fn_802B8B34()
{
    if (fn_802B96C4(lbl_805E0EAC, 0) != 0) {
        void* h = 0;
        fn_803FED48(lbl_805E0EAC, 0x100, 0, &h);
        lbl_8061EAB4 = fn_802B98AC(lbl_805E0EBC, 0x400);
        fn_803FEDB8(h, 0);
    } else {
        lbl_8061EAB4 = 0;
    }
}

void fn_802B8BBC()
{
    if (lbl_8061EAB4 != 0) {
        fn_803EDA0C(lbl_8061EAB4);
        lbl_8061EAB4 = 0;
    }
}

/* near-miss: retail orders the argument setup li r4/li r5/addi r6 before addi r3 (name) */
void fn_802B8BFC()
{
    if (fn_802B96C4(lbl_805E0ECC, 0) != 0) {
        void* h = 0;
        fn_803FED48(lbl_805E0ECC, 0x100, 0, &h);
        lbl_8061EAB8 = fn_802B98AC(lbl_805E0EDC, 0x500);
        fn_803FEDB8(h, 0);
    } else {
        lbl_8061EAB8 = 0;
    }
}

void fn_802B8C84()
{
    if (lbl_8061EAB8 != 0) {
        fn_803EDA0C(lbl_8061EAB8);
        lbl_8061EAB8 = 0;
    }
}

void fn_802B8CCC()
{
    if (fn_802B96C4(lbl_805E0EEC, 0) == 1)
        lbl_8061EABC = fn_802B9300(lbl_805E0EEC, 0x500, 14, 0);
    else
        lbl_8061EABC = 0;
}

void fn_802B8D34()
{
    if (lbl_8061EABC != 0) {
        fn_803EDA0C(lbl_8061EABC);
        lbl_8061EABC = 0;
    }
}

void fn_802B8D74()
{
    if (fn_802B96C4(lbl_805E0F04, 0) == 1)
        lbl_8061EAC0 = fn_802B9300(lbl_805E0F04, 0x500, 14, 0);
    else
        lbl_8061EAC0 = 0;
}

void fn_802B8DDC()
{
    if (lbl_8061EAC0 != 0) {
        fn_803EDA0C(lbl_8061EAC0);
        lbl_8061EAC0 = 0;
    }
}

void fn_802B8E1C()
{
    if (fn_802B96C4(lbl_805E0F1C, 0) == 1)
        lbl_8061EAC4 = fn_802B9300(lbl_805E0F1C, 0x500, 14, 0);
    else
        lbl_8061EAC4 = 0;
}

void fn_802B8E84()
{
    if (lbl_8061EAC4 != 0) {
        fn_803EDA0C(lbl_8061EAC4);
        lbl_8061EAC4 = 0;
    }
}

void fn_802B8EC4()
{
    if (fn_802B96C4(lbl_805E0F34, 0) == 1)
        lbl_8061EAC8 = fn_802B9300(lbl_805E0F34, 0x400, 14, 0);
    else
        lbl_8061EAC8 = 0;
}

void fn_802B8F2C()
{
    if (lbl_8061EAC8 != 0) {
        fn_803EDA0C(lbl_8061EAC8);
        lbl_8061EAC8 = 0;
    }
}

void fn_802B8F6C(const char* name)
{
    void* r = (void*)fn_802B96C4(name, 0);
    if (r != 0)
        r = fn_802B9300(name, 0x500, 14, 0);
    lbl_8061EACC = r;
}

void fn_802B8FC0()
{
    if (lbl_8061EACC != 0) {
        fn_803EDA0C(lbl_8061EACC);
        lbl_8061EACC = 0;
    }
}

void fn_802B9000()
{
    void* r = (void*)fn_802B96C4(lbl_805E0F48, 0);
    if (r != 0)
        r = fn_802B9300(lbl_805E0F48, 0x500, 14, 0);
    lbl_8061EAD4 = r;
}

void fn_802B9058()
{
    if (lbl_8061EAD4 != 0) {
        delete lbl_8061EAD4;
        lbl_8061EAD4 = 0;
    }
}

void fn_802B9098(const char* name)
{
    void* r = (void*)fn_802B96C4(name, 0);
    if (r != 0)
        r = fn_802B9300(name, 0x500, 14, 0);
    lbl_8061EAD8 = r;
}

void fn_802B90EC()
{
    if (lbl_8061EAD8 != 0) {
        fn_803EDA0C(lbl_8061EAD8);
        lbl_8061EAD8 = 0;
    }
}

void fn_802B912C(const char* name)
{
    void* r = (void*)fn_802B96C4(name, 0);
    if (r != 0)
        r = fn_802B9300(name, 0x500, 14, 0);
    lbl_8061EADC = r;
}

void fn_802B9180()
{
    if (lbl_8061EADC != 0) {
        fn_803EDA0C(lbl_8061EADC);
        lbl_8061EADC = 0;
    }
}

void fn_802B91C0()
{
    void* r = (void*)fn_802B96C4(lbl_805E0138, 0);
    if (r != 0)
        r = fn_802B9300(lbl_805E0138, 0x100, 14, 0);
    lbl_8061EAE0 = r;
}
