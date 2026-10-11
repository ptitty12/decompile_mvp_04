/*
 * Game code, .text 0x8016BF30-0x8016F45C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80167DCC.h"

extern float lbl_805CAD78;
extern const char lbl_805CAD7C[];
extern float lbl_805CAD8C;
extern float lbl_805CAD90;

extern const char lbl_805C6244[];

extern float lbl_805CAD38;
extern float lbl_805CAD64;
extern float lbl_805CAD68;
extern float lbl_805CAD6C;
extern float lbl_805CAD70;
extern float lbl_805CAD94;

int fn_8040B6A0(const char* s);
void* fn_803272D0(Unk801527C8_Sub* s, unsigned int idx);
int fn_80169DC4(const char* b);
int fn_8040B574(const char* a, const char* b);
void fn_80359948(Unk8016C1C4_List* l, int a);
int fn_804089B4(char* buf, const char* fmt, ...);
void fn_80303BC4(const char* fmt, ...);
char* fn_8040B61C(char* d, const char* s);
void fn_802AEBCC(void* mgr, const char* s);
void fn_80244A64(Unk8016C788_Obj* o, int a, int b);
extern void* lbl_8061E978;
void fn_80359910(Unk8016C1C4_List* l);
void fn_803596DC(void* p);

float Unk8016C1C4_List::fn_8016BF94() /* 8016BF94 */
{
    float x = lbl_805CAD38;
    float a = fn_8016C248(1);
    float b = this[1].fn_8016C248(0);
    x = a >? b;
    return x;
}

inline int CurId(Unk8016C1C4_List* l)
{
    if (l->mCur >= 0) {
        return l->m4[l->mCur].m0;
    }
    return 0;
}

int Unk8016C1C4_List::fn_8016C1C4(int idx) /* 8016C1C4 */
{
    return CurId(this + idx);
}

int Unk8016C1C4_List::fn_8016C1EC() /* 8016C1EC */
{
    if (CurId(this) == 0) {
        if (CurId(this + 1) == 0) {
            return 0;
        }
    }
    return 1;
}

float Unk8016C1C4_List::fn_8016C248(int flag) /* 8016C248 */
{
    float sum = lbl_805CAD64;
    for (int i = mCur; i >= 0; i--) {
        float v = m4[i].fn_8016C2D0(flag);
        if (!(v < lbl_805CAD64)) {
            sum += v;
        }
    }
    return sum;
}

float Unk8016C1C4_Ent::fn_8016C2D0(int flag) /* 8016C2D0 */
{
    float r = lbl_805CAD68;
    if (m0 != 0) {
        Unk8016C2D0_Obj* o = m4;
        if (o != 0) {
            if (flag != 0) {
                r = o->mC - mC;
            } else {
                r = fn_801510A8(o, m8, m10);
            }
        }
    }
    return r;
}

int Unk8016ACAC::fn_8016C344() /* 8016C344 */
{
    for (int i = 0; i <= 2; i++) {
        if (m1E28[i].mLists[0].fn_8016C1EC() != 0) {
            return 1;
        }
    }
    return 0;
}

inline int AllEmpty(char (*s)[0xA0])
{
    for (int i = 0; i <= 7; i++) {
        if (fn_8040B6A0(s[i]) != 0) {
            return 0;
        }
    }
    return 1;
}

int Unk8016ACAC::fn_8016C39C() /* 8016C39C */
{
    if (m4.m1E00 != 0) {
        return 1;
    }
    if (fn_8016C344() != 0) {
        return 1;
    }
    return !AllEmpty(m3D94);
}

inline void ClearCur(Unk8016C1C4_List* l)
{
    if (l->mCur >= 0) {
        l->m4[l->mCur].m0 = 0;
    }
}

void Unk8016C1C4_List::fn_8016C424(int idx) /* 8016C424 */
{
    ClearCur(this + idx);
}

void Unk8016ACAC_Slot::fn_8016C448() /* 8016C448 */
{
    int p = (int)this;
    int end = p + 0x968;
    do {
        fn_80359948((Unk8016C1C4_List*)p, 0);
        ((Unk8016C1C4_List*)p)->mCur = 0;
        p += 0xAC;
    } while (p <= end);
    fn_8016A6AC();
}

void Unk8016ACAC::fn_8016C4A0() /* 8016C4A0 */
{
    Unk8016ACAC_Slot* s = m1E28;
    for (int i = 3; i != 0; i--, s++) {
        s->fn_8016C448();
    }
    m4.fn_8016DFD0();
    fn_8016A880();
    fn_8016D128();
}

/* near-miss: retail forms the offset cur*0x14+idx*0xAC once and uses four (this+k)[off] stores; raw-offset and pointer forms tried */
void Unk8016C1C4_List::fn_8016C620(int idx, int p) /* 8016C620 */
{
    char* b = (char*)this;
    int off = idx * 0xAC;
    off += this[idx].mCur * 0x14;
    *(int*)(b + 8 + off) = p;
    *(float*)(b + 0x10 + off) = lbl_805CAD6C;
    *(int*)(b + 0xC + off) = 0;
    *(float*)(b + 0x14 + off) = lbl_805CAD6C;
}

/* near-miss: same as fn_8016C620 */
void Unk8016C1C4_List::fn_8016C660(int idx) /* 8016C660 */
{
    this[idx].m4[this[idx].mCur].mC = lbl_805CAD70;
    this[idx].m4[this[idx].mCur].m8 = 0;
    this[idx].m4[this[idx].mCur].m10 = lbl_805CAD70;
}

void Unk8016C1C4_List::fn_8016C698(int a) /* 8016C698 */
{
    for (int i = 0; i < 15; i++) {
        this[i].mCur = this[i].mCur + 1;
    }
    fn_8016C004(a, 0);
}

int Unk8016ACAC::fn_8016C764(int idx) /* 8016C764 */
{
    return m1E28[0].mLists[0].fn_8016C788(idx);
}

/* near-miss: lwzx operand order (r3,r4 vs r4,r3); 3 forms tried */
int Unk8016C1C4_List::fn_8016C788(int idx) /* 8016C788 */
{
    char* b = (char*)this + 0xA4;
    return *(int*)(b + idx * 0xAC);
}

/* near-miss: same as fn_8016C788 */
int Unk8016C1C4_List::fn_8016C798(int idx) /* 8016C798 */
{
    return *(int*)((char*)this + 0xA8 + idx * 0xAC);
}

inline void* GetPtr(void** arr, unsigned int i)
{
    return arr[i];
}

/* near-miss: same code; the shifted index lives in r0 here, retail uses r11 (inline index helper, ternary, cast forms tried) */
void* Unk801527C8_Ctx::fn_8016C7A8(unsigned int idx) /* 8016C7A8 */
{
    if (mA54->m44 == 0) {
        void* r;
        Unk801527C8_Actor* a = mA4C;
        if (idx <= 12) {
            r = a->m65C[idx];
        } else {
            r = 0;
        }
        return r;
    }
    return fn_803272D0(&mA4C->m50, idx);
}

void Unk80159F28::fn_8016CFC4(Unk8016C788_Obj* o) /* 8016CFC4 */
{
    if (o != 0) {
        *(unsigned int*)((char*)o + 0x71C) |= 0x1000;
        fn_80244A64(o, 0, 1);
        ((Unk80189300*)((char*)o + 0))->fn_v8(0);
        fn_80244A64(o, 0, 1);
    }
}

void Unk8016C1C4_List::fn_8016D258() /* 8016D258 */
{
    int p = (int)this;
    int end = p + 0x968;
    do {
        int z = 0;
        ((Unk8016C1C4_List*)p)->mCur = z;
        fn_80359910((Unk8016C1C4_List*)p);
        ((Unk8016C1C4_List*)p)->mA4 = z;
        p += 0xAC;
    } while (p <= end);
}

void Unk8016ACAC::fn_8016D2A4() /* 8016D2A4 */
{
    float t = lbl_805CAD78;
    Unk8016ACAC_Slot* s = m1E28;
    for (int i = 3; i != 0; i--, s++) {
        s->fn_8016D368(&t);
    }
}

/* near-miss: retail enters the loop through its condition (pre-header jump) and keeps the previous pointer in r30; for/while forms tried */
void Unk801527C8_Ctx::fn_8016D2F4(const char* s) /* 8016D2F4 */
{
    char* p = mA24[0];
    for (int i = 0; i <= 3; i++, p += 10) {
        if (fn_8040B6A0(p) == 0) {
            fn_8040B61C(p, s);
            break;
        }
    }
    fn_802AEBCC(lbl_8061E978, s);
}

void Unk8016ACAC_Slot::fn_8016D368(float* t) /* 8016D368 */
{
    if (mA20 != 0) {
        char buf[32];
        fn_804089B4(buf, lbl_805CAD7C, mA20);
        fn_80303BC4(buf, lbl_805CAD8C, *t);
    }
    *t = *t + lbl_805CAD90;
}

/* near-miss: same as fn_8016C620 */
void Unk8016C1C4_List::fn_8016D3DC(int idx) /* 8016D3DC */
{
    this[idx].m4[this[idx].mCur].m8 = this[idx].m4[this[idx].mCur].m8 + 1;
    this[idx].m4[this[idx].mCur].m10 = lbl_805CAD94;
}

int fn_8016DB74(const char* s) /* 8016DB74 */
{
    return fn_8040B574(s, lbl_805C6244) == 0;
}

int Unk8016DBAC_Obj::fn_8016DBA4() /* 8016DBA4 */
{
    return m98;
}

void Unk8016DBAC_Obj::fn_8016DBAC() /* 8016DBAC */
{
    if (fn_8016DB74((char*)this) != 0) {
        fn_803596DC(this);
        m98 = 1;
    }
}

int Unk8016D9A0::fn_8016DBF0() /* 8016DBF0 */
{
    for (int i = 0; i < m1E00; i++) {
        if (fn_80169DC4(m0[i].m) != 0) {
            return 1;
        }
    }
    return 0;
}

void Unk8016D9A0::fn_8016E18C() /* 8016E18C */
{
    for (int i = 0; i < 6; i++) {
        m1E04[i] = 0;
    }
    m1E1C = 0;
}

/*
 * Tail of the unity TU: virtual slot 3 (class-name string) / slot 4 (name hash)
 * getters of the script classes whose vtables are emitted here (cLocationObject,
 * cDepthOfFieldParameters, cActorScriptConditional, ...). The classes are declared
 * in the previous range; these are written as free functions with the same code.
 */
extern const char* lbl_8061BE10;
extern const char* lbl_8061BE18;
extern const char lbl_805C626C[];
extern const char lbl_805C7958[];

void fn_8016F340() /* 8016F340 */
{
}

const char* fn_8016F344() /* 8016F344 */
{
    return lbl_8061BE10;
}

int fn_8016F350() /* 8016F350 */
{
    return 0x149EF3D8;
}

const char* fn_8016F35C() /* 8016F35C */
{
    return lbl_805C626C;
}

int fn_8016F368() /* 8016F368 */
{
    return 0x916112DD;
}

const char* fn_8016F374() /* 8016F374 */
{
    return lbl_8061BE18;
}

int fn_8016F380() /* 8016F380 */
{
    return 0x37EF0C2A;
}

const char* fn_8016F3E8() /* 8016F3E8 */
{
    return lbl_805C7958;
}

int fn_8016F3F4() /* 8016F3F4 */
{
    return 0x323DA6EA;
}
