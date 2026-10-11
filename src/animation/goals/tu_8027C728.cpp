/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic between cShortestPathChooser and catchgoal.cpp.
 * Original file name unknown; placeholder. 25 functions.
 *
 * .text 0x8027C728-0x8027DE3C, .rodata 0x805DD040-0x805DD134.
 */
#include "game/chooser.h"
#include "game/goals/tu_8027C728.h"


typedef Unk8027C728_Goal Goal;
typedef Unk8027C728_Player Player;
typedef Unk8027C728_Base Base;
typedef Unk80273498_Vec3 Vec3;

extern const Vec3 lbl_806055AC;
extern const Vec3 lbl_806055AC;
extern char lbl_806EF9C7;
extern char lbl_8061EC9C[];

/* in the neighbouring goal units */
void fn_8027A84C(void* base, void* owner);
void fn_8028F34C(void* p);
void fn_8027A05C(void* p, Player* player);
Base* fn_8027C67C(Goal* g);
Unk8027DC98_Ctx* fn_8027A918(Base* base);
void fn_8027A898(Base* base, Vec3 v);
float fn_804028E4(float x);
int fn_80255028(Unk8027C728_Track* t);
int fn_80254EA4(Unk8027C728_Track* t, int a);
Vec3 fn_8014E388(int idx);
Vec3 fn_80379530(const Vec3& a, const Vec3& b, const Vec3& c, float e, float f, int d);
float fn_80410CE8(float y, float x);
float fn_80382BB8(Unk8027C728_Link* link);
void fn_8027AC90(void* base, Unk80279BB8* out, int n, void* b, Vec3* arr);
Vec3 fn_8037B128();
float fn_8037B1F0(Unk80279BB8* out);
void fn_8033E958(const char* fmt, ...);
void fn_803814A4(Unk8027C728_Link* link, unsigned int hash, int a, float b);
void fn_80244A64(Player* player, Goal* g, int flag);
void fn_8024497C(Player* player, Goal* g);

/* init functions called from fn_8027C728 (one per goal type) */
void fn_80298B74(void* p);
void fn_80287D70(void* p);
void fn_80287B2C(void* p);
void fn_8028ED00(void* p);
void fn_8028989C(void* p);
void fn_80299EE4(void* p);
void fn_8028B13C(void* p);
void fn_80298E50(void* p);
void fn_80287BB8(void* p);
void fn_8027D9A4(void* p);
void fn_80299914(void* p);
void fn_8028B12C(void* p);
void fn_802A2DA4(void* p);
void fn_8029B520(void* p);
void fn_802A2F20(void* p);
void fn_802A309C(void* p);

/* per-type execute functions called from fn_8027CA10 */
int fn_80298B8C(void* p, Player* player);
int fn_8028AE80(void* p, Player* player);
int fn_80287E54(void* p, Player* player);
int fn_80287B3C(void* p, Player* player);
int fn_8028F0F4(void* p, Player* player);
int fn_80289B98(void* p, Player* player);
int fn_8028B56C(void* p, Player* player);
int fn_80298FE0(void* p, Player* player);
int fn_80287BC4(void* p, Player* player);
int fn_80299F6C(void* p, Player* player);
int fn_8027E084(void* p, Player* player);
int fn_80299920(void* p, Player* player);
int fn_8028B130(void* p, Player* player);
int fn_802A2DE8(void* p, Player* player);
int fn_8029B834(void* p, Player* player);
int fn_802A2C7C(void* p, Player* player);
int fn_802A2F2C(void* p, Player* player);
int fn_802A3408(void* p, Player* player);

/* per-type step functions called from fn_8027CCA4 */
void fn_80298CB8(void* p, Player* player, Unk80279BB8* out, int a, Vec3* b, Unk8027D150_Pair* c, int d, float f);
void fn_802893DC(void* p, Player* player, Unk80279BB8* out, int a, Vec3* b, Unk8027D150_Pair* c, int d, float f);
void fn_8028F178(void* p, Player* player, Unk80279BB8* out, int a, Vec3* b, Unk8027D150_Pair* c, int d, float f);
void fn_8028A450(void* p, Player* player, Unk80279BB8* out, int a, Vec3* b, Unk8027D150_Pair* c, int d, float f);
void fn_8028DB44(void* p, Player* player, Unk80279BB8* out, int a, Vec3* b, Unk8027D150_Pair* c, int d, float f);
void fn_802997F0(void* p, Player* player, Unk80279BB8* out, int a, Vec3* b, Unk8027D150_Pair* c, int d, float f);
void fn_80287C70(void* p, Player* player, Unk80279BB8* out, int a, Vec3* b, Unk8027D150_Pair* c, int d, float f);
void fn_8029A9A4(void* p, Player* player, Unk80279BB8* out, int a, Vec3* b, Unk8027D150_Pair* c, int d, float f);
void fn_8027F7D8(void* p, Player* player, Unk80279BB8* out, int a, Vec3* b, Unk8027D150_Pair* c, int d, float f);
void fn_802999D4(void* p, Player* player, Unk80279BB8* out, int a, Vec3* b, Unk8027D150_Pair* c, int d, float f);
void fn_802A2EB0(void* p, Player* player, Unk80279BB8* out, int a, Vec3* b, Unk8027D150_Pair* c, int d, float f);
void fn_802A2B7C(void* p, Player* player, Unk80279BB8* out, int a, Vec3* b, Unk8027D150_Pair* c, int d, float f);

/* per-type compare functions called from fn_8027CFA8 */
int fn_80289808(void* a, void* b);
int fn_8028F1F8(void* a, void* b);
int fn_8028ADB8(void* a, void* b);
int fn_8028E9E8(void* a, void* b);
int fn_80299834(void* a, void* b);
int fn_80287D58(void* a, void* b);
int fn_8029B3F8(void* a, void* b);
int fn_802857C4(void* a, void* b);
int fn_80299AE8(void* a, void* b);
int fn_802A2F0C(void* a, void* b);
int fn_802A2BC0(void* a, void* b);
int fn_802A3094(void* a, void* b);

/* used by fn_8027D670 */
int fn_8028F0AC(void* p);
int fn_8028C0CC(void* p);

int fn_8027D670(Goal* g, Player* player, int flag);
int fn_8027CFA8(Goal* a, Goal* b, Player* player, Unk80279BB8* out);
void fn_8027CCA4(Goal* g, Unk80279BB8* out, int a, float f, Vec3* b, Unk8027D150_Pair* c, int d);
void fn_8027D150(Goal* g, int a, Unk80279BB8* out, float f, Vec3* b, Unk8027D150_Pair* c, int d);
Goal* fn_8027D2FC(Goal* g, int);
int fn_8027D3E8(Goal* g, int a, float* outF, Vec3* pos6, Vec3* pos7, float* out8);

void fn_8027C728(Unk8027C728_Goal* g)
{
    fn_8027A84C(g->m104, g);
    fn_8028F34C(g->m104);
    fn_8027A05C(g->m294, g->mC);
    switch (g->m10) {
    case 0: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_80298B74(p);
        break;
    }
    case 1: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        *(int*)p = 3;
        *(int*)(p + 0x48) = 0;
        break;
    }
    case 2: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_80287D70(p);
        break;
    }
    case 3: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_80287B2C(p);
        break;
    }
    case 4: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_8028ED00(p);
        break;
    }
    case 12: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_8028989C(p);
        break;
    }
    case 5: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_80299EE4(p);
        break;
    }
    case 10: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_8028B13C(p);
        break;
    }
    case 13: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_80298E50(p);
        break;
    }
    case 11: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_80287BB8(p);
        break;
    }
    case 6: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_8027D9A4(p);
        break;
    }
    case 7: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_80299914(p);
        break;
    }
    case 8: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_8028B12C(p);
        break;
    }
    case 9: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_802A2DA4(p);
        break;
    }
    case 14: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_8029B520(p);
        break;
    }
    case 15: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        *(int*)(p + 0x48) = 0;
        break;
    }
    case 16: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_802A2F20(p);
        break;
    }
    case 17: {
        char* p = g->m18;
        fn_8027A84C(p, g);
        fn_802A309C(p);
        break;
    }
    }
}

inline void SetMax(Base* b, int v)
{
    if (v > b->mC) {
        b->mC = v;
    }
}

int fn_8027CA10(Goal* g)
{
    Player* player = g->mC;
    Base* b = fn_8027C67C(g);
    SetMax(b, 1);
    if (!player) {
        return 0;
    }
    if (player->m618->m838 == 0) {
        fn_8033E958("Executing a goal on a player without a current state!\n");
        fn_803814A4(player->m618, 0xEA68D008, 0, 0.0f);
    }
    if (fn_8027D670(g, player, 0)) {
        return 2;
    }
    int r = 0;
    switch (g->m10) {
    case 0:
        r = fn_80298B8C(g->m18, player);
        break;
    case 1:
        r = fn_8028AE80(g->m18, player);
        break;
    case 2:
        r = fn_80287E54(g->m18, player);
        break;
    case 3:
        r = fn_80287B3C(g->m18, player);
        break;
    case 4:
        r = fn_8028F0F4(g->m18, player);
        break;
    case 12:
        r = fn_80289B98(g->m18, player);
        break;
    case 10:
        r = fn_8028B56C(g->m18, player);
        break;
    case 13:
        r = fn_80298FE0(g->m18, player);
        break;
    case 11:
        r = fn_80287BC4(g->m18, player);
        break;
    case 5:
        r = fn_80299F6C(g->m18, player);
        break;
    case 6:
        r = fn_8027E084(g->m18, player);
        break;
    case 7:
        r = fn_80299920(g->m18, player);
        break;
    case 8:
        r = fn_8028B130(g->m18, player);
        break;
    case 9:
        r = fn_802A2DE8(g->m18, player);
        break;
    case 14:
        r = fn_8029B834(g->m18, player);
        break;
    case 15:
        r = fn_802A2C7C(g->m18, player);
        break;
    case 16:
        r = fn_802A2F2C(g->m18, player);
        break;
    case 17:
        r = fn_802A3408(g->m18, player);
        break;
    }
    b = fn_8027C67C(g);
    SetMax(b, 2);
    return r;
}

inline void Nop(float f)
{
}

inline void StepN(Goal* g, Unk80279BB8* out, Vec3* a, Unk8027D150_Pair* b, int c, float f)
{
    fn_8027AC90(g->m18, out, c, b, a);
}

void fn_8027CCA4(Goal* g, Unk80279BB8* out, int a, float f, Vec3* b, Unk8027D150_Pair* c, int d)
{
    Player* player = g->mC;
    switch (g->m10) {
    case 0:
        fn_80298CB8(g->m18, player, out, a, b, c, d, f);
        break;
    case 1:
        StepN(g, out, b, c, d, f);
        out->mD8 = 1;
        break;
    case 2:
        fn_802893DC(g->m18, player, out, a, b, c, d, f);
        break;
    case 4:
        fn_8028F178(g->m18, player, out, a, b, c, d, f);
        break;
    case 12:
        fn_8028A450(g->m18, player, out, a, b, c, d, f);
        break;
    case 10:
        fn_8028DB44(g->m18, player, out, a, b, c, d, f);
        break;
    case 13:
        fn_802997F0(g->m18, player, out, a, b, c, d, f);
        break;
    case 11:
        fn_80287C70(g->m18, player, out, a, b, c, d, f);
        break;
    case 5:
        fn_8029A9A4(g->m18, player, out, a, b, c, d, f);
        break;
    case 6:
        fn_8027F7D8(g->m18, player, out, a, b, c, d, f);
        break;
    case 7:
        fn_802999D4(g->m18, player, out, a, b, c, d, f);
        break;
    case 3:
    case 8:
        StepN(g, out, b, c, d, f);
        out->mD8 = 1;
        break;
    case 9:
        fn_802A2EB0(g->m18, player, out, a, b, c, d, f);
        break;
    case 14:
        fn_802A2B7C(g->m18, player, out, a, b, c, d, f);
        break;
    case 15:
        Nop(f);
        break;
    case 16:
        StepN(g, out, b, c, d, f);
        break;
    case 17:
        StepN(g, out, b, c, d, f);
        break;
    }
}

int fn_8027CFA8(Goal* a, Goal* b, Player* player, Unk80279BB8* out)
{
    int r;
    if (b && b->mC == a->mC && b->m10 == a->m10) {
        switch (b->m10) {
        case 2:
            r = fn_80289808(a->m18, b->m18);
            break;
        case 0:
        case 3:
            r = 1;
            break;
        case 4:
            r = fn_8028F1F8(a->m18, b->m18);
            break;
        case 12:
            r = fn_8028ADB8(a->m18, b->m18);
            break;
        case 10:
            r = fn_8028E9E8(a->m18, b->m18);
            break;
        case 13:
            r = fn_80299834(a->m18, b->m18);
            break;
        case 11:
            r = fn_80287D58(a->m18, b->m18);
            break;
        case 5:
            r = fn_8029B3F8(a->m18, b->m18);
            break;
        case 6:
            r = fn_802857C4(a->m18, b->m18);
            break;
        case 7:
            r = fn_80299AE8(a->m18, b->m18);
            break;
        case 9:
            r = fn_802A2F0C(a->m18, b->m18);
            break;
        case 14:
            r = fn_802A2BC0(a->m18, b->m18);
            break;
        case 16:
            r = fn_802A3094(a->m18, b->m18);
            break;
        case 1:
            r = 0;
            break;
        case 8:
            r = 0;
            break;
        case 15:
            r = 0;
            break;
        case 17:
            r = 0;
            break;
        default:
            r = 0;
            break;
        }
    } else {
        r = 0;
    }
    return r;
}

void fn_8027D150(Goal* g, int a, Unk80279BB8* out, float f, Vec3* b, Unk8027D150_Pair* c, int d)
{
    Player* player = g->mC;
    Unk8027C728_Angles* angles = &player->m734;
    Goal* top = fn_8027D2FC(g, -1);
    Goal* head = player->m934;
    int saved = angles->m190;
    angles->m190 = 0;
    Goal* cur = top;
    angles->m194 = saved;
    if (cur) {
        do {
            int v;
            if (f >= 0.0f || cur == g) {
                v = a;
            } else {
                v = fn_8027C67C(cur)->m0;
            }
            float t = -1.0f;
            if (!(f < 0.0f)) {
                t = f - out->mD4;
            }
            if (cur == top && head != 0 && (head == cur || fn_8027CFA8(head, cur, player, out))) {
                fn_8027CCA4(head, out, v, t, b, c, d);
            } else {
                fn_8027CCA4(cur, out, v, t, b, c, d);
            }
            if (!(f < 0.0f) && out->mD4 >= f) {
                break;
            }
            if (out->mD8 == 0 || cur == g) {
                break;
            }
            cur = cur->m0;
        } while (cur);
    }
    angles->m190 = angles->m194;
}

Goal* fn_8027D2DC(Goal* g, int)
{
    if (g->m4) {
        do {
            g = g->m4;
        } while (g->m4);
    }
    return g;
}

Goal* fn_8027D2FC(Goal* g, int)
{
    if (g->m4) {
        do {
            g = g->m4;
        } while (g->m4);
    }
    return g;
}

Goal* fn_8027D31C(Goal* g)
{
    if (g->m0) {
        do {
            g = g->m0;
        } while (g->m0);
    }
    return g;
}

void fn_8027D33C(Goal* g)
{
    fn_80244A64(g->mC, g, 0);
}

void fn_8027D368(Goal* g)
{
    fn_8024497C(g->mC, g);
}

int fn_8027D390(Goal* g, float* a, Vec3* b, Vec3* c, float* d)
{
    return fn_8027D3E8(g, fn_8027C67C(g)->m0, a, b, c, d);
}

inline Vec3 GetVec()
{
    Vec3 v = fn_8037B128();
    return v;
}

inline void SetFloat(float* p, float v)
{
    *p = v;
}

inline int GetResult(Unk80279BB8* o, float* dist)
{
    int r = o->mD8;
    *dist = r ? o->mD4 : -1.0f;
    return r;
}

/* near-miss (97%, 3 insns): everything matches except that retail addresses the
 * result record through r4 (addi r4,r1,8; lwz r31,0xd8(r4); lfs f0,0xd4(r4)) in
 * the GetResult part where this gets r9. Tried (all give r9): inline taking a
 * pointer or reference, a member function, if/else and ternary forms, a
 * separate inline for the int and the float, a pointer variable assigned in
 * both branches, ~1500 combinations of declaration order, store order and the
 * pos6 copy. */
int fn_8027D3E8(Goal* g, int a, float* outF, Vec3* pos6, Vec3* pos7, float* out8)
{
    Player* player = g->mC;
    if (pos6) {
        pos6->x = 0.0f;
        pos6->y = -1000.0f;
        pos6->z = 0.0f;
    }
    Unk80279BB8 out(player);
    if (pos6) {
        Unk8027D150_Pair pair;
        Vec3 tmp[2];
        pair.m0 = lbl_806EF9C7;
        pair.m4 = lbl_8061EC9C[0];
        fn_8027D150(g, a, &out, -1.0f, tmp, &pair, 2);
        *pos6 = tmp[1];
    } else {
        fn_8027D150(g, a, &out, -1.0f, 0, 0, 0);
    }
    int r = GetResult(&out, outF);
    if (pos7) {
        *pos7 = GetVec();
    }
    if (out8) {
        SetFloat(out8, fn_8037B1F0(&out));
    }
    return r;
}

int fn_8027D574(Goal* g)
{
    int n = 0;
    if (g) {
        do {
            g = g->m0;
            n++;
        } while (g);
    }
    return n;
}

int fn_8027D598(Goal* g, int* out)
{
    Goal* p = fn_8027D2DC(g, -1);
    while (p && p->m14 != 0) {
        p = p->m0;
    }
    if (p) {
        Unk8027D598_Type10* b = p->m10 == 10 ? (Unk8027D598_Type10*)p->m18 : 0;
        if (b) {
            int v = b->m4C;
            if (!(b->mA8 & 0x40000) && v > 10 && v <= 16) {
                if (out) {
                    *out = v;
                }
                return 1;
            }
        } else {
            Base* c = p->m10 == 12 ? (Base*)p->m18 : 0;
            if (c) {
                return c->m4C > 3;
            }
        }
    }
    return 0;
}

int fn_8027D670(Goal* g, Player*, int)
{
    if (g->m14) {
        return 1;
    }
    switch (g->m10) {
    case 0:
    case 1:
    case 2:
    case 3:
        return 0;
    case 4:
        return fn_8028F0AC(g->m18);
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return 0;
    case 10:
        return fn_8028C0CC(g->m18);
    case 11:
        return 0;
    case 12:
        return 0;
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
        return 0;
    }
    return 0;
}

inline bool operator==(const Vec3& a, const Vec3& b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

inline float Dist2(const Vec3& a, const Vec3& b)
{
    return (b.x - a.x) * (b.x - a.x) + (b.z - a.z) * (b.z - a.z);
}

inline float Atan2(const Vec3& a, const Vec3& b)
{
    return fn_80410CE8(b.x - a.x, b.z - a.z);
}

inline float AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}

/* d2 is computed before lim is stored: a store to the stack between the
 * comparisons and the loads of q would stop retail sharing the q.x load. */
int fn_8027D708(void*, Player* pa, Player* pb)
{
    Unk8027C728_Track* trk = &pb->m58C;
    int a = fn_80255028(trk);
    if (a == fn_80254EA4(trk, 0)) {
        return 0;
    }
    int cur = trk->m38;
    if (cur == 3) {
        return 0;
    }
    int next = cur == a ? a + 1 : cur;
    Vec3 posA = pa->m60;
    Vec3 posB = pb->m60;
    Vec3 p0 = fn_8014E388(next);
    Vec3 p1 = fn_8014E388(a);
    Vec3 q = fn_80379530(p0, p1, posA, 0.0f, 0.0f, 0);
    if (!(q == p0)) {
        if (!(q == p1)) {
            float d2 = Dist2(posA, q);
            const float lim = 9216.0f;
            float ang;
            float adiff;
            float diff;
            if (!(d2 > lim)) {
                ang = Atan2(posA, p1);
                diff = AngleDiff(ang, fn_80382BB8(pa->m618));
                adiff = __builtin_fabsf(diff);
                if (!(adiff > 0.7853982f)) {
                    float da = Dist2(p1, posA);
                    float db = Dist2(p1, posB);
                    return db < da;
                }
            }
        }
    }
    return 0;
}

/* Zeroes the flag word with word masks (an AND against a register constant is
 * what retail has for the multi-run masks; bit-field stores would give rlwinm
 * pairs): 0x001E6000 = bits 11-14 and 17-18, 0xA2E002FF keeps bits 0, 2, 6,
 * 8-10, 22 and the low byte. */
void fn_8027D9A4(Unk8027D9A4* d)
{
    d->m0 = 4;
    d->f2 = 0;
    d->f6 = 0;
    d->m78 = 0;
    d->m7C = 0;
    d->m84 = 0.0f;
    d->m80 = 0.0f;
    d->f22 = 0;
    d->m88 = 0.0f;
    d->m90 = 0.0f;
    d->m8C = 0.0f;
    d->m98 = 0.0f;
    d->m9C = -1;
    d->mA0 = -1;
    d->mA4 = lbl_806055AC;
    d->f0 = 0;
    d->f8 = 0;
    d->f9 = 0;
    d->f10 = 0;
    d->mB0 = lbl_806055AC;
    d->mBC = lbl_806055AC;
    d->mE8 &= ~0x001E6000u;
    d->mCC = 1000.0f;
    d->m94 = 5;
    d->f3 = 0;
    d->f7 = 0;
    d->mD0 = -1.0f;
    d->mE8 &= 0xA2E002FFu;
    d->mC8 = -1.0f;
    d->mE4 = 0;
    d->mD4 = 0.0f;
    d->mD8 = lbl_806055AC;
}

inline void SetVec(Vec3* dst, Vec3 v)
{
    *dst = v;
}

Base* fn_8027DAE8(Base* b, Vec3 v)
{
    SetVec(&b->m10, v);
    b->m28 = 1;
    return b;
}

inline Vec3 operator-(const Vec3& v)
{
    Vec3 r;
    r.x = -v.x;
    r.y = -v.y;
    r.z = -v.z;
    return r;
}

Unk8027D9A4* fn_8027DB38(Unk8027D9A4* d, Vec3* p, Vec3* q)
{
    if (p->x != 0.0f || p->y != 0.0f || p->z != 0.0f) {
        fn_8027A898(d, *p);
    }
    if (q->x != 0.0f || q->y != 0.0f || q->z != 0.0f) {
        d->mD0 = fn_804028E4(q->x * q->x + q->z * q->z);
        if (d->m2C == 0) {
            fn_8027A898(d, -*q);
        }
        if (d->m2C != 0) {
            if (!(fn_804028E4(q->x * q->x + q->y * q->y + q->z * q->z) >= 88.0f)) {
                d->m2C = 0;
            }
        }
    }
    return d;
}

Unk8027D9A4* fn_8027DC98(Unk8027D9A4* d, float f)
{
    d->m80 = f;
    if (!(f > 0.0f)) {
        d->m84 = 0.0f;
        d->f2 = 0;
    } else {
        d->f2 = 1;
        float t = (float)fn_8027A918(d)->m4C * 0.016666668f;
        d->m84 = f + t;
    }
    d->m78 = 0;
    return d;
}

Unk8027D9A4* fn_8027DD54(Unk8027D9A4* d, float f)
{
    d->m84 = f;
    d->f2 = 1;
    float t = (float)fn_8027A918(d)->m4C * 0.016666668f;
    d->m78 = 0;
    d->m80 = f - t;
    return d;
}

Unk8027D9A4* fn_8027DDE8(Unk8027D9A4* d, int v)
{
    d->m78 = v;
    d->f6 = 1;
    return d;
}

Unk8027D9A4* fn_8027DE00(Unk8027D9A4* d, int v)
{
    d->f15 = v;
    return d;
}

Unk8027D9A4* fn_8027DE14(Unk8027D9A4* d, int v)
{
    d->f16 = v;
    return d;
}

Unk8027D9A4* fn_8027DE28(Unk8027D9A4* d)
{
    d->f19 = 1;
    return d;
}
