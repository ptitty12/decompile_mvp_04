/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803E2248-0x803E3280 (code-only unit, 13 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 *
 * Not written: fn_803E30A4, fn_803E30D0, fn_803E3178 and fn_803E2D18 read the time base (mftb), which
 * needs an instruction only the original code can emit; the original code stays linked.
 */

/* Per-section profiler record: two 32-entry sample rings with running sums, linked through +0x124. */
struct Unk803E303C_Prof {
    char pad0[4];
    float m4[32];
    float m84;
    float m88[32];
    float m108;
    unsigned int m10C;
    unsigned int m110;
    unsigned int m114;
    float m118;
    unsigned int m11C;
    char pad120[4];
    Unk803E303C_Prof* m124;
};

extern unsigned int lbl_8062C318;
extern Unk803E303C_Prof* lbl_8062C338;

inline float& RingAt(float* a, unsigned int o)
{
    return *(float*)((char*)a + o);
}

extern "C" void fn_803E24C0(Unk803E303C_Prof* p, unsigned int total)
{
    unsigned int cnt = p->m110;
    float f = (float)cnt;
    float pct = 0.0f;
    if (cnt == 0) {
        if (p->m11C <= 31)
            p->m11C = p->m11C + 1;
    } else {
        if (cnt > p->m114)
            p->m114 = cnt;
        p->m11C = 0;
        f = f / (float)total;
        pct = f * 40.0f;
        if (pct > p->m118)
            p->m118 = pct;
    }
    unsigned int o = lbl_8062C318 * 4;
    float* a = p->m4;
    float* b = p->m88;
    a[32] -= RingAt(a, o);
    RingAt(a, o) = (float)p->m110;
    a[32] += RingAt(a, o);
    a[65] -= RingAt(b, o);
    RingAt(b, o) = pct;
    a[65] += pct;
}

/* intrusive singly-linked list (next at +0x124) headed by lbl_8062C338 */
extern "C" void fn_803E303C(Unk803E303C_Prof* o)
{
    o->m124 = lbl_8062C338;
    lbl_8062C338 = o;
}

extern "C" void fn_803E3050(Unk803E303C_Prof* o)
{
    if (lbl_8062C338 == o) {
        lbl_8062C338 = o->m124;
        return;
    }
    Unk803E303C_Prof* p = lbl_8062C338;
    while (p->m124 != o && p->m124 != 0)
        p = p->m124;
    if (p->m124 == o)
        p->m124 = o->m124;
}

extern "C" void fn_803E30A4(void* scope);
extern "C" void fn_803E30D0(void* scope);

struct Unk803E3108_Scope {
    Unk803E303C_Prof* m0;
    Unk803E3108_Scope* m4;
    Unk803E3108_Scope* m8;
    int mC;
    int m10;
};

extern Unk803E3108_Scope* lbl_8062C34C;
extern char lbl_8062C354[];

extern "C" Unk803E3108_Scope* fn_803E3108(Unk803E3108_Scope* s, Unk803E303C_Prof* owner)
{
    s->m0 = owner;
    s->m8 = 0;
    s->m10 = 0;
    Unk803E3108_Scope* cur = lbl_8062C34C;
    if (*(void**)cur != (void*)lbl_8062C354) {
        s->m4 = cur;
        cur->m8 = s;
        fn_803E30D0(s->m4);
        fn_803E30A4(s);
    }
    return s;
}

extern "C" void fn_803E2E18(int a, int b);

extern "C" void fn_803E3228()
{
    fn_803E2E18(1, 0xFFFF);
}

extern "C" void fn_803E3254()
{
    fn_803E2E18(0, 0xFFFF);
}
