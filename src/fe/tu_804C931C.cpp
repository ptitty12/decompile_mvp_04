/*
 * Front-end overlay code, .frontend_codeoverlay 0x804C931C-0x804CB430 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804BE560.h"

extern void* lbl_8061977C;
extern "C" const char* fn_80090880__FP11Unk80090880(void* t, int id);
void fn_800DE538(int out, int a, int b, int c);
extern "C" void fn_804031F8(char* out, const char* a, const char* b);
extern "C" void fn_801321D4(FeW* o, void* self, void (*cb)(int, void*), int (*cb2)(), char* b, int c, int d, int e,
                            const char* s1, const char* s2, const char* s3, int f, int g, int h);
extern "C" int fn_8013484C();
extern "C" char* fn_800DF254(char* out, int a, int b, float f);

extern const char lbl_805F8108[];
struct Unk8007F198_B;
int fn_8007F7D0(Unk8007F198_B* b, unsigned i);
extern const char lbl_805F3CA8[];
extern "C" void fn_8013013C(void* w, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);

extern const char lbl_8066F0D0[];
extern const char lbl_8066EE28[];
extern const char lbl_80671198[];
extern "C" int fn_804CA1E8(void* x);
extern "C" int fn_804C9810(FeScrN* x);
extern "C" int fn_804C984C(FeScrN* x);
extern "C" int fn_804C9888(FeScrN* x);
extern "C" int fn_804C98C4(FeScrN* x);
extern "C" int fn_804C9900(FeScrN* x);
extern "C" int fn_804C993C(FeScrN* x);
extern "C" int fn_804C9978(FeScrN* x);
extern "C" int fn_804C99B4(FeScrN* x);
extern "C" FeScrN* fn_804CA3F8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804CA448(FeScrN* x);
extern "C" int fn_804CA788(FeScrN* x);
extern "C" int fn_804CA7C8(FeScrN* x);
extern "C" int fn_804CA804(FeScrN* x);
extern "C" int fn_804CA840(FeScrN* x);
extern "C" int fn_804CA87C(FeScrN* x);
extern "C" FeScrN* fn_804CA8B8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" void fn_804CA908(FeScrN* self);
extern "C" int fn_804CB254(FeScrN* x);
extern "C" int fn_804CB290(FeScrN* x);
extern "C" int fn_804CB2CC(FeScrN* x);
extern "C" int fn_804CB308(FeScrN* x);
extern "C" FeScrN* fn_804CB3DC(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int fn_804CA2F0(void* x);
extern "C" void fn_804CA328(FeScrN* x, int a);
extern "C" int fn_804CA38C(FeScrN* x, int a);

extern "C" void fn_804C9A40(void* x);

extern "C" void fn_804C9AC4(void*);

extern "C" void fn_804C9D58(FeScrN* x);
extern "C" void fn_804CA12C(int a);

extern "C" FE_OVERLAY void fn_804C9738(FeW* x, int sel, int c)
{
    switch (sel) {
    case 0:
        fn_804C9A40(x);
        break;
    case 1:
        fn_804C9AC4(x);
        break;
    case 2:
        fn_804C9D58((FeScrN*)x);
        break;
    case 3: {
        int r = fn_804CA1E8(x);
        if (r == 4)
            x->fn_vslot67(1, c);
        else if (r == 5)
            x->fn_vslot67(2, c);
        break;
    }
    }
}

extern "C" FE_OVERLAY int fn_804C9810(FeScrN* x)
{
    x->m150->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C984C(FeScrN* x)
{
    x->m150->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C9888(FeScrN* x)
{
    x->m150->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C98C4(FeScrN* x)
{
    x->m150->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C9900(FeScrN* x)
{
    x->m150->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C993C(FeScrN* x)
{
    x->m150->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C9978(FeScrN* x)
{
    x->m150->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804C99B4(FeScrN* x)
{
    x->m150->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY void fn_804C99F0(FeScrN* x, int a)
{
    fn_800ED310(x, a);
    x->m150->fn_vslot14(a);
}

extern const char lbl_805F4450[];

extern "C" FE_OVERLAY void fn_804C9A40(void* x)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    fn_8040B830(mp->name, lbl_805F4450, 15);
    mp->name[15] = 0;
    fn_800B7B4C(FeGetMgr(), mp, x);
}

extern "C" FE_OVERLAY void fn_804C9D58(FeScrN* x)
{
    char big[0x200];
    char small[0x80];
    fn_800DE538((int)small, fn_8008FD78((int)x->m13C), (int)x->m138, 1);
    fn_804031F8(big, fn_80090880__FP11Unk80090880(lbl_8061977C, 0x1A47), small);
    const char* s1 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E9);
    const char* s2 = fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3E8);
    fn_801321D4(x->m154, x, (void (*)(int, void*))fn_804CA12C, fn_8013484C, big, 2, -1, 1, s1, s2, 0, 0, 0, 0);
    x->m154->fn_vslot86();
}

extern "C" FE_OVERLAY void fn_804C9FDC(FeScrN* x)
{
    char buf[0x80];
    float v = *(float*)((char*)*(void**)((Unk8007B2B0_Screen*)lbl_8061930C)->m30 + 0x12B78);
    fn_800DF254(buf, 0, 3, v);
    ((FeWV*)x->m144)->s28(buf);
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    float w = s->fn_80079E74(fn_8007F7D0((Unk8007F198_B*)s, 0));
    fn_800DF254(buf, 0, 3, w);
    ((FeWV*)x->m140)->s28(buf);
}

extern "C" FE_OVERLAY void fn_804CA0A8(void) {}

extern "C" FE_OVERLAY void fn_804CA0AC(int a, FeScrN* x)
{
    if (x != 0) {
        int s = fn_800B555C()->m38;
        int t = fn_800B555C()->m34;
        fn_8013013C(x->m158, 0, s, t, fn_800B555C()->m38, 0, 1, 0, 0, 0, 0, 0);
        fn_804C9A40(x);
    }
}

extern "C" FE_OVERLAY void fn_804CA12C(int a)
{
    if (a != 0) {
        if (a == 1) {
            Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
            int st = fn_800B555C()->m34;
            s->fn_8007C328(st, fn_8007F7D0((Unk8007F198_B*)s, 0));
            FeMsg m;
            FeMsg* mp = &m;
            fn_8035682C(mp);
            fn_8040B830(mp->name, lbl_805F8108, 15);
            mp->name[15] = 0;
            fn_800B7B4C(FeGetMgr(), mp, 0);
        }
    }
}

extern "C" FE_OVERLAY int fn_804CA1E8(void* x)
{
    FeW* w = ((FeScrN*)x)->m150->fn_vslot70();
    if (w->fn_vslot30("SALARY", 1) != 0)
        return 0;
    if (w->fn_vslot30("TERM", 1) != 0)
        return 1;
    if (w->fn_vslot30("RESIGNPLAYERST", 1) != 0)
        return 4;
    w->fn_vslot30("RELEASEPLAYERST", 1);
    return 5;
}

/* near-miss: 2 slots (retail compares `cmpwi r3,4; bge`, we emit `cmpwi r3,3; bgt`). The
 * comma form below is the closest of ~14 spellings of `n >= 4 && n <= 5`. */
extern "C" FE_OVERLAY int fn_804CA2F0(void* x)
{
    int n = fn_804CA1E8(x);
    int r;
    if (n > 5 || (r = 1, n < 4)) {
        r = 0;
    }
    return r;
}

extern "C" FE_OVERLAY void fn_804CA328(FeScrN* x, int a)
{
    if (a == (int)x->m150) {
        if (fn_804CA2F0(x) != 0) {
            fn_801251CC(x->m164, 0, 0x10, 3);
            return;
        }
        fn_80125084(x->m164, 0);
    }
}

extern "C" FE_OVERLAY int fn_804CA38C(FeScrN* x, int a)
{
    if (a == (int)x->m150 && fn_804CA2F0(x) != 0) {
        x->fn_vslot67(3, 0);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY FeScrN* fn_804CA3F8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066F0D0);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804CA448(FeScrN* x)
{
    fn_800ECAA4(x);
}

extern "C" FE_OVERLAY void fn_804CA664(FeScrN* x, int sel)
{
    FeMsg m;
    FeMsg* mp = &m;
    fn_8035682C(mp);
    switch (sel) {
    case 0:
        fn_8040B830(mp->name, "BACK", 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    case 1:
        fn_8040B830(mp->name, (char*)x->m134->fn_vslot70()->fn_vslot33(5, 1) + 0xC, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
        break;
    }
}

extern "C" FE_OVERLAY int fn_804CA788(FeScrN* x)
{
    x->fn_vslot67(1, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804CA7C8(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CA804(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CA840(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CA87C(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY FeScrN* fn_804CA8B8(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8066EE28);
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804CA908(FeScrN* self)
{
    self->SetVptr(lbl_8066EE28);
    fn_8035686C(self);
}

extern "C" FE_OVERLAY int fn_804CB254(FeScrN* x)
{
    x->m134->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CB290(FeScrN* x)
{
    x->m134->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CB2CC(FeScrN* x)
{
    x->m134->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804CB308(FeScrN* x)
{
    x->m134->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY void fn_804CB344(void* x, int b)
{
    if (b == 0) {
        fn_800A2030(lbl_80619948, 0);
        FeMsg m;
        FeMsg* mp = &m;
        fn_8035682C(mp);
        fn_8040B830(mp->name, lbl_805F3CA8, 15);
        mp->name[15] = 0;
        fn_800B7B4C(FeGetMgr(), mp, x);
    }
}

extern "C" FE_OVERLAY FeScrN* fn_804CB3DC(FeScrN* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80671198);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}
