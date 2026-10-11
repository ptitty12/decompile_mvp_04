/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8005371C-0x80054874 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80052794.h"

void fn_8005371C(void)
{
    fn_800149CC();
}

void fn_8005373C(Unk80052794_Ctx* ctx)
{
    ctx->mA90 = 0;
}

void fn_80053748(Unk80052794_Ctx* ctx)
{
    ctx->mA90 = 0;
}

void fn_80053754(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    Unk80052794_Entry* e = EntryOf(ctx, idx);
    int k = e->m0;
    if (e->mC == 0 && (k != (int)obj->m130 || obj->m44C != 0 || obj->m458 != 3)) {
        if (e->m10 != 0) {
            fn_8001F3FC(obj, e->m0);
            fn_80014BFC();
            return;
        }
        if (fn_80056E34(lbl_80687600, 0xCD) == 0 && fn_80056E34(lbl_80687600, 0xCE) == 0 && fn_8040ABA0() % 100 <= 0x20) {
            int a = e->m0;
            int b = fn_8001DA28(obj);
            fn_80013E5C(b, fn_8001F45C(obj, a));
        }
    }
}

void fn_8005385C(void)
{
    fn_80015B2C(8);
}

void fn_80053880(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    int r = fn_8004FF78(ctx, ctx->m9D8, 0x48);
    if (r == -1 || ctx->m4[r].m0p->m708 != obj->m3B0->m708) {
        if (ctx->m4[idx].mC == 1) {
            int k = ctx->m4[idx].m0;
            if (fn_8040ABA0() % 100 <= 0x31 || ctx->mA6C == 1) {
                int a = fn_8001F3FC(obj, k);
                int b = fn_8001D8DC(obj);
                fn_800119F8(a, b, fn_8001F45C(obj, k));
                return;
            }
            if (obj->m3E0 == 1) {
                ctx->mA6C = obj->m3E0;
            }
            int c = fn_8001F3FC(obj, k);
            fn_80018918(c, fn_8001D6CC(obj));
            return;
        }
        int v = 0;
        if (ctx->m4[idx].m0p->m460 == 0) {
            v = ctx->m4[idx].m4f > lbl_805A92D8;
        }
        if (v == 0) {
            fn_80013E08();
        }
    }
}

void fn_800539EC(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    int r = fn_8005000C(ctx, ctx->m9DC, 0x48);
    if ((r == -1 || ctx->m4[r].m0p->m708 != obj->m3B0->m708) && ctx->m4[idx].mC == 1) {
        fn_8001897C();
    }
}

void fn_80053F7C(Unk80052794_Ctx* ctx)
{
    if (ctx->mA7C == 0) {
        fn_80014978();
        ctx->mA7C = 1;
    }
}

void fn_80053FBC(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    Unk80052794_S3B0* p = ctx->m4[idx].m0p;
    if ((p->m590 & 0x20000000) && ctx->mA50 == 0) {
        for (int i = 0; i < obj->m4D4; i++) {
            if (obj->m48C[i].m4 == p && (obj->m48C[i].m0 == 1 || obj->m48C[i].m0 == 3)) {
                fn_80012834();
                ctx->mA50 = 1;
                break;
            }
        }
    }
}

void fn_8005405C(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    if (obj->m44 > 0 && fn_80054D98() != 0) {
        fn_80012418();
        return;
    }
    if (fn_80054DAC(ctx, obj, 3) != 0 && fn_80054DCC(ctx, obj, 9) != 0) {
        int a = fn_8001F954(obj);
        fn_8000FA98(a, fn_8001DB70(obj));
    }
}

void fn_800540F8(Unk80052794_Ctx* ctx, int idx)
{
    if (ctx->m4[idx].m0p->m590 & 0x20000000) {
        fn_80013724(8);
        return;
    }
    fn_8000F968(8);
}

void fn_80054140(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    Unk80052794_S130* o130 = obj->m130;
    ctx->mA04 = 1;
    int v = 4;
    ctx->mA08 = ctx->m4[idx].m0;
    Unk80052794_S44C* m = ctx->m4[idx].m38;
    char* spC;
    int sp10;
    fn_8017DD80(m->m700, o130->m708, &spC, &sp10);
    if (spC != 0) {
        v = 2;
        float sp8 = fn_80253434(spC + 0x480);
        if (!(sp8 >= lbl_805A92F0)) {
            v = 1;
        }
        if (sp10 != 0 && !(fn_80253434(spC + 0x480) < lbl_805A92F0)) {
            v = 2;
        }
    }
    fn_800173E8(v);
}

void fn_8005420C(void)
{
    fn_8001A1F4();
}

void fn_8005422C(Unk80052794_Ctx* ctx, int idx)
{
    switch (ctx->m4[idx].m0) {
    case 32:
        fn_8001A398();
        return;
    case 35:
        fn_8001A050();
        return;
    case 33:
        fn_8001A0A4();
        return;
    case 36:
        fn_8001A14C();
        return;
    case 34:
        fn_8001A0F8();
        return;
    case 37:
        fn_8001A1A0();
        return;
    }
}

void fn_800542B8(Unk80052794_Ctx* ctx, int idx)
{
    switch (ctx->m4[idx].m0) {
    case 22:
        fn_8001A29C();
        return;
    case 24:
        fn_8001A248();
        return;
    case 23:
        fn_8001A2F0();
        return;
    case 25:
        fn_8001A344();
        return;
    }
}

void fn_80054328(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    int r = fn_80043460(EntryOf(ctx, idx), ctx->m4[idx].m20 == 0);
    if (r != 0 && r != lbl_80617F5C) {
        lbl_80617F5C = r;
        int a = fn_8001D694(obj);
        fn_80013370(r, a, fn_8001D47C(obj));
    }
}

void fn_800543B0(void)
{
}

void fn_800543B4(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    obj->m3B0->v4();
    fn_80043650();
    fn_800150E4();
}

void fn_800543F4(Unk80052794_Ctx* ctx, int idx)
{
    int sp8;
    int spC;
    int k = ctx->m4[idx].m0p->m708;
    Unk80052794_S44C* m = ctx->m4[idx].m38;
    Unk80052794_S700* s = m->m700;
    Unk80052794_S6F8* t = m->m6F8;
    int r = fn_8017DD64(s, k);
    if (t->m10->m1C > 1 && r > 0) {
        sp8 = 0;
        spC = 0;
        fn_8017DD80(s, k, &sp8, &spC);
    }
}

void fn_8005447C(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    int sp8;
    int spC;
    int k = ctx->m4[idx].m0;
    int a = fn_8009E1D4((char*)ctx->m4[idx].m38->m6F8->m14 + k * 0xE64 + 0x8C, 2, 0);
    Unk80052794_S700* s = ctx->m4[idx].m38->m700;
    int b = fn_8017DD64(s, k);
    sp8 = 0;
    spC = 0;
    fn_8017DD80(s, k, &sp8, &spC);
    int c = fn_800461F8(b, sp8, spC);
    fn_800152B0(c, a, fn_8001F45C(obj, sp8));
}

int fn_80054544(Unk80052794_Ctx* ctx, int idx)
{
    return fn_8005481C(ctx, idx) <= 3;
}

int fn_80054574(void)
{
    int r = 0;
    fn_800B555C();
    if (fn_800B57EC() != 0) {
        Unk80052794_Quad q = fn_800B555C()->m688;
        r = q.m0 <= 2;
    }
    return r;
}

void fn_800545EC(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    Unk80052794_S6F8* t = ctx->m4[idx].m38->m6F8;
    int side = fn_80054750(ctx, idx) == 0;
    Unk80052794_Row* row = &t->m14[side];
    unsigned char b = row->m17C;
    if (fn_8009DB0C(row, b) != 0) {
        fn_8001DBE0(obj);
        fn_80013674();
        return;
    }
    if (fn_8009DA60(row, b) != 0) {
        fn_8001DBE0(obj);
        fn_80014E24();
    }
}

int fn_80054684(Unk80052794_Ctx* ctx, int idx, int k)
{
    Unk80052794_Row* row = &ctx->m4[idx].m38->m6F8->m14[k];
    int s = 0;
    for (int i = 0; i < 0x80; i++) {
        s += row->vals[(unsigned char)i];
    }
    return s;
}

void fn_800546D0(Unk80052794_Ctx* ctx, int idx, int* eq, int* gt, int* lt)
{
    int a = fn_80054684(ctx, idx, 0);
    int b = fn_80054684(ctx, idx, 1);
    *gt = a > b;
    *lt = b > a;
    *eq = b == a;
}

int fn_80054750(Unk80052794_Ctx* ctx, int idx)
{
    int a = fn_80054684(ctx, idx, 0);
    return a > fn_80054684(ctx, idx, 1);
}

float fn_800547A4(Unk80052794_Ctx* ctx, unsigned char* p, int idx)
{
    float f = (float)*p / (float)ctx->m4[idx].m38->m6F8->m10->m1C;
    return f;
}

int fn_8005481C(Unk80052794_Ctx* ctx, int idx)
{
    int a = fn_80054684(ctx, idx, 0);
    int d = a - fn_80054684(ctx, idx, 1);
    return d < 0 ? -d : d;
}
