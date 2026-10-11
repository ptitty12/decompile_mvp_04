/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80052794-0x8005371C only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80052794.h"

void fn_80052794(void)
{
    fn_8004E68C();
}

void fn_800527B4(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    fn_8001DB70(obj);
    fn_80012648();
}

void fn_800527DC(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    if (fn_80054D98() != 0) {
        int a = fn_8001D780(obj);
        int b = fn_8001DCF8(obj);
        fn_80017978(a, b, fn_8001DA9C(obj));
        if (!(fn_80253F54(&obj->m3B0->m588, 0, 2, 0) > lbl_805A92D4) && obj->m0 > 4 && obj->m50 > 0) {
            fn_8001DB70(obj);
            fn_800124C0();
        }
        if (fn_802F92CC(ctx->m4[idx].m38->m720) == 0 && fn_8040ABA0() % 100 <= 0x31) {
            fn_8001422C();
        }
        if (fn_8006BE18(obj->m130->m44C->m6F8) == 0) {
            fn_80052908(ctx, idx, obj);
        }
    }
}

void fn_80052908(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    Unk80052794_S3B0* s = obj->m3B0;
    int* flags = ctx->mA38;
    if (flags[s->m708] == 0) {
        char* q = &s->m588;
        int a = fn_80253F0C(q, 2, 2, 0);
        int b = fn_80253F0C(q, 3, 2, 0);
        int c = fn_80253F0C(q, 4, 2, 0);
        int d = fn_80253F0C(q, 0, 2, 0);
        int t = fn_801BBF24(obj->m130->m44C->m700->m3BC);
        if (t != 0) {
            if (t == 1) {
                b++;
            } else if (fn_8005000C(ctx, idx + 1, 0x32) >= 0) {
                d++;
            }
        } else {
            d++;
        }
        if (a > 0 && b > 0 && c > 0 && d > 0) {
            fn_80010290();
            flags[s->m708] = 1;
        }
    }
}

void fn_80052E7C(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    if (obj->m3D0 < *lbl_8061B9C4) {
        fn_80058FE4(ctx->mA9C, 0);
        if (obj->m3D0 == 2 && obj->m27C > 2 && fn_8040ABA0() % 10 <= 2) {
            int a = fn_8001D454(obj);
            fn_80017594(a, fn_8001DA4C(obj));
        }
        if (obj->m408 - 4 <= 3) {
            fn_8004FC60(ctx, obj);
        }
    }
}

void fn_80052F4C(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    if (obj->m408 - 4 <= 3) {
        fn_8004FC60(ctx, obj);
    }
    if ((obj->m3B0->m590 & 0x20000000) && obj->m3C4 != 0) {
        fn_8001F45C(obj, (int)obj->m130);
        fn_80013140();
    }
}

void fn_80052FB8(void)
{
}

void fn_80052FBC(void)
{
}

void fn_80052FC0(void)
{
    fn_8001525C();
}

void fn_80052FE0(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    fn_80015140(8, fn_8001F3FC(obj, ctx->m4[idx].m4));
}

void fn_8005301C(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    int v = 0;
    int r = fn_8005000C(ctx, idx, 0x45);
    if (r >= 0) {
        v = ctx->m4[r].m4;
    }
    if (ctx->m4[idx].m0 == 1) {
        fn_800151A4(fn_8001F3FC(obj, v));
    } else {
        fn_80015200(fn_8001F3FC(obj, v));
    }
}

void fn_800530A4(void)
{
    fn_800158E4();
}

void fn_800530C4(void)
{
    fn_80017A50();
}

void fn_800530E4(void)
{
    fn_80015C84(8);
}

void fn_80053108(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    if (obj->m130->m44C->m6CC->m36C == 0) {
        fn_80014DD0();
    }
}

void fn_80053140(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    Unk80052794_S44C* p = ctx->m4[idx].m38;
    if (fn_801BBF30(p->m700->m3BC, p->m6CC, obj) != 0) {
        fn_80011090(0);
    }
}

void fn_80053188(void)
{
}

void fn_8005318C(void)
{
    fn_80015388();
}

void fn_800531AC(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    fn_8001F45C(obj, ctx->m4[idx].m0);
    fn_80013DAC();
}

void fn_800531E0(void)
{
    fn_80013E08();
}

void fn_80053200(void)
{
    fn_800186E8();
}

static inline int SumRow(Unk80052794_Row* r)
{
    int s = 0;
    for (int i = 0; i < 0x80; i++) {
        s += r->vals[(unsigned char)i];
    }
    return s;
}

/* near-miss (5 slots): the first SumRow loop gets base r11 / idx r0 / addr r9
 * where retail has base r8 / idx r9 / addr r11. */
void fn_80053220(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d;
    switch (ctx->m4[idx].m0) {
    case 13:
        d = 0;
        break;
    case 14:
        d = 0;
        break;
    case 15:
        a = 4;
        break;
    case 16:
        a = 1;
        break;
    case 17:
        b = 1;
        break;
    case 18:
        c = 1;
        break;
    case 19:
        c = 4;
        break;
    default:
        return;
    }
    Unk80052794_S6F8* p = obj->m130->m44C->m6F8;
    Unk80052794_Row* t = p->m14;
    unsigned lim = p->m10->m1C;
    int s1 = SumRow(t);
    int s2 = SumRow(t + 1);
    int lo = s2;
    int hi = s1;
    d = 0;
    int w = 0;
    if (hi < lo) {
        hi = lo;
        w = 1;
        lo = s1;
    }
    int ob = obj->m3B4;
    if (w != ob) {
        int diff = hi - lo;
        if (diff == 1) {
            d = 1;
            if (ob == 0 && obj->m0 >= lim) {
                d = 4;
            }
        } else if (diff == 2) {
            d = 2;
        }
    }
    fn_80017904(a, b, c, d);
}

/* near-miss (5 slots): retail keeps ctx in r31 and idx in r30; this gets them swapped.
 * Retail forms r = ctx + idx * 0x48 once, then reads the type at r + 4 and the
 * other three fields through e = r + 4. */
void fn_800533A0(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    fn_800B555C();
    if (fn_800B57EC() != 0) {
        int* r = (int*)((char*)ctx + idx * 0x48);
        int* e = r + 1;
        if (e[2] != 0) {
            int x = fn_801A49F0(obj->m130->m44C, obj->m3B4, e[3]);
            int a = fn_800463E4(r[1]);
            int b = fn_800465D4(r[1], e[1]);
            int c = fn_80046580(e[1]);
            int d = fn_8001F45C(obj, x);
            fn_80014A7C(a, b, c, d, 0, fn_800465C0(e[2]));
        }
    }
}

/* near-miss (5 slots): same ctx/idx register swap as fn_800533A0. */
void fn_8005346C(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    fn_800B555C();
    if (fn_800B57EC() != 0) {
        int* r = (int*)((char*)ctx + idx * 0x48);
        int* e = r + 1;
        if (e[2] != 0) {
            int a = fn_80046658(r[1]);
            int b = fn_80046580(e[1]);
            int c = fn_8001E31C(obj);
            int d = fn_800464C4(r[1]);
            fn_80014A7C(0, a, b, c, d, fn_800465C0(e[2]));
        }
    }
}

void fn_80053518(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    if (obj->m4D8 == 0 && obj->m38 == 0 && obj->m104 > 0) {
        fn_80015C30();
    }
}

void fn_8005355C(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    int r = fn_8005000C(ctx, ctx->m9E0, 0x67);
    if (obj->m104 > 0) {
        if (ctx->m4[r].m0 == 0) {
            fn_80015658();
            return;
        }
        if (obj->m4D8 == 2) {
            fn_8001F3FC(obj, ctx->m4[r].m4);
            fn_800155FC();
            return;
        }
        if (fn_8005000C(ctx, idx, 0x2B) != -1) {
            fn_800156AC();
        }
    }
}

void fn_80053600(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    if (fn_8005000C(ctx, idx, 0x4F) != -1 && obj->m110 != 0 && obj->m118 != 0 && obj->m4D4 <= 2) {
        fn_800127E0();
    }
}

void fn_80053660(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    if (fn_8005000C(ctx, idx, 0x57) == -1 && obj->m4C == 1 && fn_8004FF78(ctx, ctx->m9D8, 0x24) >= 0) {
        fn_80010754(0, 0);
    }
}

void fn_800536CC(Unk80052794_Ctx* ctx, int idx)
{
    if (fn_8005000C(ctx, idx, 0x59) == -1) {
        fn_80044D3C(ctx->m4[idx].m4);
        fn_80014514();
    }
}
