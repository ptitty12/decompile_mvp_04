/*
 * Game code, .text 0x8016BF30-0x8016F45C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80167DCC.h"

extern const char lbl_805C6244[];

extern float lbl_805CAD38;
extern float lbl_805CAD64;
extern float lbl_805CAD68;
extern float lbl_805CAD6C;
extern float lbl_805CAD70;
extern float lbl_805CAD94;

int fn_8040B6A0(const char* s);
int fn_80169DC4(const char* b);
int fn_8040B574(const char* a, const char* b);
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

/* near-miss: retail uses lwzux on this + idx*0xAC; here lwzx + add */
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

/* near-miss: 2 extra instructions in the second-list lookup */
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

/* near-miss: retail uses lwzux; one instruction less here */
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
