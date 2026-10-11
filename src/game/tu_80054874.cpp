/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80054874-0x80056A08 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80052794.h"

void fn_80054874(void)
{
}

void fn_80054878(void)
{
    fn_80014F28();
}

void fn_80054898(void)
{
    fn_80010290();
}

void fn_800548B8(void)
{
}

void fn_800548BC(void)
{
    fn_80014B00();
}

void fn_800548DC(void)
{
    fn_80013F80();
}

void fn_800548FC(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    fn_80044FAC(obj->m40);
    fn_80014570();
}

void fn_80054924(void)
{
}

void fn_80054928(void)
{
    fn_80012C4C();
}

void fn_80054948(void)
{
}

void fn_8005494C(void)
{
    fn_8000FB90();
}

void fn_8005496C(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    float a = fn_80253F54(&obj->m3B0->m588, 2, 2, 0);
    float b = fn_80254128(&obj->m3B0->m588, 2, 2);
    if (!(a >= b * lbl_805A9318)) {
        fn_80015090();
    }
}

void fn_800549EC(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    if (fn_80054574(ctx) != 0) {
        int a = fn_8001DC88(obj);
        int b = fn_8001DCCC(obj);
        int c = fn_8001F300(obj);
        fn_8001A87C(a, b, c, fn_8001F2C4(obj));
    } else {
        int a = fn_8001E0C8(obj);
        int b = fn_8001DCCC(obj);
        int c = fn_8001F300(obj);
        fn_8001A954(a, b, c, fn_8001F2C4(obj));
    }
    fn_800B555C();
    if (fn_800B57EC() != 0 && fn_80054574(ctx) == 0) {
        Unk80052794_Row* r = obj->m130->m44C->m6F8->m14;
        int a = r->mD74;
        int b = r[1].mD74;
        if (a > 0 && a >= b) {
            int c = fn_8001F2C4(obj);
            fn_800157C8(c, fn_80042EF8(a));
        }
        if (b > 0 && b > a) {
            int c = fn_8001F300(obj);
            fn_800157C8(c, fn_80042EF8(b));
        }
    }
}

void fn_80054B40(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    fn_80051060();
    if (fn_8006A1B4(obj->m130->m44C->m6F8) != 0) {
        fn_8001A7BC(fn_8001DCCC(obj));
    } else if (fn_80054574(ctx) != 0) {
        int a = fn_8001DC88(obj);
        fn_8001A818(a, fn_8001DCCC(obj));
    } else {
        int a = fn_8001E0C8(obj);
        fn_8001A8F0(a, fn_8001F914(obj));
    }
    fn_800549EC(ctx, idx, obj);
}

void fn_80054C00(void)
{
    fn_800194FC();
}

void fn_80054C20(void)
{
    fn_800194A8();
}

void fn_80054C40(void)
{
    fn_80019550();
}

void fn_80054C60(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj)
{
    Unk80052794_S3B0* s = fn_801A497C(ctx->m4[idx].m38, 1, 0);
    char* p = &s->m588;
    int a = fn_8025416C(p, 5);
    if (fn_80076644(0, a, fn_8025416C(p, 6)) != 0) {
        if (obj->m130->m708 == 0) {
            int b = fn_8001E0C8(obj);
            int c = fn_8001F378(obj);
            int d = fn_8001F3B8(obj, obj->m130);
            fn_800138C4(b, c, d, fn_8001DC58(obj));
        } else {
            int c = fn_8001F378(obj);
            int d = fn_8001F3B8(obj, s);
            fn_800146F0(c, d, fn_8001DC58(obj));
        }
    }
    fn_80058FE4(ctx->mA9C, 5, obj);
}

void fn_80054D7C(Unk80052794_Ctx* ctx, int a, int b)
{
    ctx->mAD4 = a;
    ctx->mAD8 = b;
}

void fn_80054D88(Unk80052794_Ctx* ctx)
{
    ctx->mAD4 = -1;
    ctx->mAD8 = -1;
}

int fn_80054D98(Unk80052794_Ctx* ctx)
{
    return ctx->mAD4 == -1;
}

int fn_80054DAC(Unk80052794_Ctx* ctx, Unk80052794_Obj* obj, int v)
{
    int x = ctx->mAD8;
    if (x != -1 && v != x) {
        return 0;
    }
    return 1;
}

int fn_80054DCC(Unk80052794_Ctx* ctx, Unk80052794_Obj* obj, int v)
{
    int x = ctx->mAD4;
    if (x != -1 && v != x) {
        return 0;
    }
    return 1;
}

int fn_80054DEC(int kind)
{
    switch (kind) {
    case 0xF4:
        return 0;
    case 0x151:
        return 0;
    case 0x188:
        return 0;
    case 0x19B:
        return 0;
    case 0x1B3:
        return 0;
    case 0x1B4:
        return 0;
    case 0x1C1:
        return 0;
    case 0x19C:
        return 0;
    case 0x1A7:
        return 0;
    case 0x18E:
        return 0;
    case 0x18F:
        return 0;
    case 0x19A:
        return 0;
    case 0x189:
        return 0;
    case 0x18D:
        return 0;
    case 0x180:
        return 0;
    case 0x185:
        return 0;
    case 0x186:
        return 0;
    case 0x187:
        return 0;
    case 0x181:
        return 0;
    case 0x182:
        return 0;
    case 0x17D:
        return 0;
    case 0x17E:
        return 0;
    case 0x17F:
        return 0;
    case 0x178:
        return 0;
    case 0x179:
        return 0;
    case 0x112:
        return 0;
    case 0x11B:
        return 0;
    case 0x12A:
        return 0;
    case 0x149:
        return 0;
    case 0x150:
        return 0;
    case 0x11F:
        return 0;
    case 0x120:
        return 0;
    case 0x115:
        return 0;
    case 0x116:
        return 0;
    case 0x119:
        return 0;
    case 0x113:
        return 0;
    case 0x114:
        return 0;
    case 0x108:
        return 0;
    case 0x10D:
        return 0;
    case 0x10E:
        return 0;
    case 0x10F:
        return 0;
    case 0x10B:
        return 0;
    case 0x10C:
        return 0;
    case 0xFB:
        return 0;
    case 0xFD:
        return 0;
    case 0x107:
        return 0;
    case 0xF5:
        return 0;
    case 0xFA:
        return 0;
    case 0x59:
        return 0;
    case 0xC5:
        return 0;
    case 0xE8:
        return 0;
    case 0xED:
        return 0;
    case 0xF3:
        return 0;
    case 0xE9:
        return 0;
    case 0xEA:
        return 0;
    case 0xE5:
        return 0;
    case 0xE6:
        return 0;
    case 0xC6:
        return 0;
    case 0xE4:
        return 0;
    case 0x9D:
        return 0;
    case 0xA0:
        return 0;
    case 0xA8:
        return 0;
    case 0xB9:
        return 0;
    case 0x9E:
        return 0;
    case 0x9F:
        return 0;
    case 0x74:
        return 0;
    case 0x77:
        return 0;
    case 0x8D:
        return 0;
    case 0x5C:
        return 0;
    case 0x5D:
        return 0;
    case 0xF:
        return 0;
    case 0x41:
        return 0;
    case 0x53:
        return 0;
    case 0x56:
        return 0;
    case 0x57:
        return 0;
    case 0x4B:
        return 0;
    case 0x52:
        return 0;
    case 0x32:
        return 0;
    case 0x33:
        return 0;
    case 0x11:
        return 0;
    case 0x12:
        return 0;
    case 0x8:
        return 0;
    case 0xC:
        return 0;
    case 0xD:
        return 0;
    case 0xE:
        return 0;
    case 0xA:
        return 0;
    case 0xB:
        return 0;
    case 0x5:
        return 0;
    case 0x6:
        return 0;
    case 0x7:
        return 0;
    case 0x2:
        return 0;
    case 0x3:
        return 0;
    case 0x38:
        return 2;
    case 0xF2:
        return 4;
    case 0xE7:
        return 5;
    default:
        return 0;
    }
}

/* near-miss: payload fillers match the retail calls, but retail's switch has one compare node
 * per kind (95 of them, the same set as fn_80054DEC) and this build merges consecutive kinds
 * that share a body into ranges (676 vs 736 instructions). Not matched. */
void fn_80055204(Unk80052794_Rec* r, Unk80052794_Obj* obj)
{
    switch (r->m4) {
    case 0x5C:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001F984(obj);
        return;
    }
    case 0x74:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001E4F4(obj);
        q->m8 = fn_8001EDBC(obj);
        return;
    }
    case 0x19A:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001EDBC(obj);
        q->m8 = fn_8001E34C(obj);
        return;
    }
    case 0x19B:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001EDBC(obj);
        q->m8 = fn_8001E3C8(obj);
        return;
    }
    case 0x19C:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001D280(obj);
        q->m8 = fn_8001E444(obj);
        return;
    }
    case 0x113:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001F218(obj);
        return;
    }
    case 0x112:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001EB78(obj);
        return;
    }
    case 0x114:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001FCEC(obj);
        q->m8 = fn_8001FCC0(obj);
        return;
    }
    case 0x10B:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001FD74(obj);
        q->m8 = fn_8001FD18(obj);
        q->mC = fn_8001FDA8(obj);
        return;
    }
    case 0x10D:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001FC60(obj);
        return;
    }
    case 0x108:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001FC90(obj);
        return;
    }
    case 0x10C:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001FD44(obj);
        return;
    }
    case 0x77:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001FE14(obj);
        return;
    }
    case 0x107:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001FE1C(obj);
        return;
    }
    case 0x12A:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001FE24(obj);
        return;
    }
    case 0x11B:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001FE2C(obj);
        return;
    }
    case 0x10F:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001ED28(obj);
        return;
    }
    case 0x10E:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001ED80(obj);
        q->m8 = fn_8001EC80(obj);
        return;
    }
    case 0xED:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001E108(obj);
        return;
    }
    case 0x1A7:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001E134(obj);
        return;
    }
    case 0x9D:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001E294(obj);
        return;
    }
    case 0xE7:
    {
        ((Unk80052794_Payload*)&r->mC)->m10 = fn_8001E2EC(obj);
        return;
    }
    case 0x115:
    case 0xF3:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001E664(obj);
        return;
    }
    case 0xE8:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001F030(obj);
        q->m8 = fn_8001D218(obj);
        q->mC = fn_8001D62C(obj);
        q->m10 = fn_8001EFB4(obj);
        q->m14 = fn_8001F8B8(obj);
        return;
    }
    case 0xE9:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001DA9C(obj);
        q->m8 = fn_8001EDE4(obj);
        q->mC = fn_8001F030(obj);
        q->m10 = fn_8001EFB4(obj);
        q->m14 = fn_8001D218(obj);
        q->m18 = fn_8001D62C(obj);
        q->m1C = fn_8001EE28(obj);
        return;
    }
    case 0xEA:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001F8B8(obj);
        q->m8 = fn_8001EFB4(obj);
        q->mC = fn_8001D218(obj);
        q->m10 = fn_8001D62C(obj);
        q->m14 = fn_8001E810(obj);
        q->m18 = fn_8001D538(obj);
        q->m1C = fn_8001F030(obj);
        q->m20 = fn_8001EDE4(obj);
        q->m24 = fn_8001EE28(obj);
        q->m28 = fn_8001DCF8(obj);
        q->m2C = fn_8001D454(obj);
        return;
    }
    case 0x4B:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001D5D8(obj);
        return;
    }
    case 0xA8:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001DA4C(obj);
        q->m8 = fn_8001D780(obj);
        q->mC = fn_8001DDD8(obj);
        return;
    }
    case 0x8D:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001F954(obj);
        return;
    }
    case 0xC5:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001D7D0(obj);
        q->m8 = fn_8001D75C(obj);
        return;
    }
    case 0xE5:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001EDE4(obj);
        q->m8 = fn_8001EE28(obj);
        q->mC = fn_8001F030(obj);
        q->m10 = fn_8001D62C(obj);
        q->m14 = fn_8001D454(obj);
        return;
    }
    case 0xE6:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001DA9C(obj);
        q->m8 = fn_8001EDE4(obj);
        q->mC = fn_8001F030(obj);
        q->m10 = fn_8001EFB4(obj);
        q->m14 = fn_8001D62C(obj);
        q->m18 = fn_8001EE28(obj);
        q->m1C = fn_8001D454(obj);
        q->m20 = fn_8001D538(obj);
        return;
    }
    case 0xB9:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001F954(obj);
        q->m8 = fn_8001E664(obj);
        return;
    }
    case 0xFB:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001DCCC(obj);
        q->m8 = fn_8001DDFC(obj);
        q->mC = fn_8001DC88(obj);
        q->m10 = fn_8001D538(obj);
        return;
    }
    case 0x18D:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001EDE4(obj);
        q->m8 = fn_8001D454(obj);
        q->mC = fn_8001EFB4(obj);
        q->m10 = fn_8001D218(obj);
        q->m14 = fn_8001DA9C(obj);
        q->m18 = fn_8001D5D8(obj);
        return;
    }
    case 0x18E:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001FDDC(obj);
        q->m8 = fn_8001E31C(obj);
        return;
    }
    case 0x182:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001D5D8(obj);
        q->m8 = fn_8001D62C(obj);
        q->mC = fn_8001D538(obj);
        return;
    }
    case 0x17F:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001EDE4(obj);
        q->m8 = fn_8001EE28(obj);
        q->mC = fn_8001DA9C(obj);
        return;
    }
    case 0x178:
    case 0x32:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001EDE4(obj);
        return;
    }
    case 0x59:
    case 0x56:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001E054(obj);
        q->m8 = fn_8001F4F0(obj);
        return;
    }
    case 0x150:
    case 0x52:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001E054(obj);
        return;
    }
    case 0x185:
    case 0x186:
    case 0x179:
    case 0x57:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001F4F0(obj);
        return;
    }
    case 0x53:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001F4F0(obj);
        q->m8 = fn_8001E2EC(obj);
        return;
    }
    case 0x5D:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001F4F0(obj);
        q->m8 = fn_8001DB70(obj);
        return;
    }
    case 0xFA:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001D47C(obj);
        q->m8 = fn_8001D538(obj);
        q->mC = fn_8001DA7C(obj);
        return;
    }
    case 0x3:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001E084(obj);
        q->m8 = fn_8001F2A0(obj);
        q->mC = fn_8001F5CC(obj);
        return;
    }
    case 0x2:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001E084(obj);
        q->m8 = fn_8001F2A0(obj);
        q->mC = fn_8001F5CC(obj);
        q->m10 = fn_8001F614(obj);
        return;
    }
    case 0x41:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001FA58(obj);
        q->m8 = fn_8001FA20(obj);
        return;
    }
    case 0x151:
    {
        Unk80052794_Payload* q = (Unk80052794_Payload*)&r->mC;
        q->m4 = fn_8001D42C(obj);
        q->m8 = fn_8001DE9C(obj);
        q->mC = fn_8001E664(obj);
        q->m10 = fn_8001E810(obj);
        q->m14 = fn_8001E054(obj);
        return;
    }
    case 0x18F:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001F9B4(obj);
        return;
    }
    case 0x116:
    {
        ((Unk80052794_Payload*)&r->mC)->m4 = fn_8001DA28(obj);
        return;
    }
    case 0x5:
        return;
    case 0x6:
        return;
    case 0x7:
        return;
    case 0x8:
        return;
    case 0xA:
        return;
    case 0xB:
        return;
    case 0xC:
        return;
    case 0xD:
        return;
    case 0xE:
        return;
    case 0xF:
        return;
    case 0x11:
        return;
    case 0x12:
        return;
    case 0x33:
        return;
    case 0x38:
        return;
    case 0x9E:
        return;
    case 0x9F:
        return;
    case 0xA0:
        return;
    case 0xC6:
        return;
    case 0xE4:
        return;
    case 0xF2:
        return;
    case 0xF4:
        return;
    case 0xF5:
        return;
    case 0xFD:
        return;
    case 0x119:
        return;
    case 0x11F:
        return;
    case 0x120:
        return;
    case 0x149:
        return;
    case 0x17D:
        return;
    case 0x17E:
        return;
    case 0x180:
        return;
    case 0x181:
        return;
    case 0x187:
        return;
    case 0x188:
        return;
    case 0x189:
        return;
    case 0x1B3:
        return;
    case 0x1B4:
        return;
    case 0x1C1:
        return;
    default:
    {
        fn_8033E958(lbl_805A931C);
        return;
    }
    }
}

/* near-miss: the case set (33 values, from the compares in retail) compiles to a
 * pruned 38-instruction tree; retail keeps a bare cmpwi for each empty case
 * (101 instructions, root 0xF4). Not matched. */
void fn_80055D84(Unk80052794_Rec* r)
{
    switch (r->m4) {
    case 0x10B:
        fn_80046750(&r->m10);
        fn_80046760(&r->m14);
        break;
    case 0x10C:
        fn_80046770(&r->m10);
        break;
    case 0x5:
        break;
    case 0x8:
        break;
    case 0xC:
        break;
    case 0xF:
        break;
    case 0x32:
        break;
    case 0x41:
        break;
    case 0x53:
        break;
    case 0x59:
        break;
    case 0x74:
        break;
    case 0x9D:
        break;
    case 0xA0:
        break;
    case 0xC5:
        break;
    case 0xE5:
        break;
    case 0xE8:
        break;
    case 0xED:
        break;
    case 0xF4:
        break;
    case 0xFB:
        break;
    case 0x108:
        break;
    case 0x10D:
        break;
    case 0x112:
        break;
    case 0x115:
        break;
    case 0x11B:
        break;
    case 0x12A:
        break;
    case 0x151:
        break;
    case 0x17D:
        break;
    case 0x180:
        break;
    case 0x185:
        break;
    case 0x188:
        break;
    case 0x18E:
        break;
    case 0x19B:
        break;
    case 0x1B3:
        break;
    }
}

void fn_8005695C(void)
{
}

void fn_80056960(Unk80056970_Obj* self, int a)
{
    self->m8 = a;
    self->m0 = 1;
}

Unk80056970_Obj* fn_80056970(Unk80056970_Obj* self, int n)
{
    self->m8 = n;
    self->m0 = 0;
    self->m10 = &lbl_80649C80;
    self->m4 = 0;
    self->mC = new (0) Unk80056970_Entry[n];
    fn_803EE7BC();
    fn_80056A68(self);
    return self;
}
