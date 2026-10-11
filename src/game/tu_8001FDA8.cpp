/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8001FDA8-0x80021BE8 only: every data object is extern by its lbl_ name.
 *
 * Two attribute classes derived from the chooser root Unk8037B3E8 (Unk8001FE34:
 * "aud" volumes, ctor 0x8001FE34; Unk8002118C: "GeneralHitSpecs" and friends, ctor
 * 0x8002118C), each with its slot 2 attribute registration (a straight run of
 * fn_8037B50C float registrations, generated from the retail call sequence), dtor,
 * hash resolver, factory and slot 8, followed by the abstract Unk80021A60 (vtable
 * 0x80649CB0, its data part is Unk80021A60_Data).
 */
#include "game/tu_8001FDA8.h"

/* Attribute names and range strings in the unity TU's .rodata. */
extern const char lbl_805A53A4[];
extern const char lbl_805A53BC[];
extern const char lbl_805A53C8[];
extern const char lbl_805A53D4[];
extern const char lbl_805A53E0[];
extern const char lbl_805A53F0[];
extern const char lbl_805A5400[];
extern const char lbl_805A5410[];
extern const char lbl_805A541C[];
extern const char lbl_805A542C[];
extern const char lbl_805A543C[];
extern const char lbl_805A5448[];
extern const char lbl_805A5454[];
extern const char lbl_805A5464[];
extern const char lbl_805A5474[];
extern const char lbl_805A5484[];
extern const char lbl_805A5494[];
extern const char lbl_805A54A4[];
extern const char lbl_805A54B4[];
extern const char lbl_805A54C0[];
extern const char lbl_805A54D0[];
extern const char lbl_805A54E0[];
extern const char lbl_805A54F0[];
extern const char lbl_805A5500[];
extern const char lbl_805A550C[];
extern const char lbl_805A5518[];
extern const char lbl_805A5528[];
extern const char lbl_805A5534[];
extern const char lbl_805A5544[];
extern const char lbl_805A5550[];
extern const char lbl_805A5560[];
extern const char lbl_805A5574[];
extern const char lbl_805A5588[];
extern const char lbl_805A5598[];
extern const char lbl_805A55A8[];
extern const char lbl_805A55BC[];
extern const char lbl_805A55C8[];
extern const char lbl_805A55D8[];
extern const char lbl_805A55E4[];
extern const char lbl_805A55F8[];
extern const char lbl_805A5600[];
extern const char lbl_805A5608[];
extern const char lbl_805A5614[];
extern const char lbl_805A5620[];
extern const char lbl_805A562C[];
extern const char lbl_805A563C[];
extern const char lbl_805A5648[];
extern const char lbl_805A5658[];
extern const char lbl_805A5668[];
extern const char lbl_805A5678[];
extern const char lbl_805A568C[];
extern const char lbl_805A56A4[];
extern const char lbl_805A56B8[];
extern const char lbl_805A56C8[];
extern const char lbl_805A56DC[];
extern const char lbl_805A56F4[];
extern const char lbl_805A5704[];
extern const char lbl_805A5718[];
extern const char lbl_805A5728[];
extern const char lbl_805A5734[];
extern const char lbl_805A5744[];
extern const char lbl_805A5754[];
extern const char lbl_805A5764[];
extern const char lbl_805A5774[];
extern const char lbl_805A5784[];
extern const char lbl_805A5794[];
extern const char lbl_805A57A8[];
extern const char lbl_805A57B8[];
extern const char lbl_805A57C8[];
extern const char lbl_805A57D8[];
extern const char lbl_805A57E8[];
extern const char lbl_805A57F8[];
extern const char lbl_805A5808[];
extern const char lbl_805A581C[];
extern const char lbl_805A582C[];
extern const char lbl_805A583C[];
extern const char lbl_805A584C[];
extern const char lbl_805A5858[];
extern const char lbl_805A5864[];
extern const char lbl_805A5874[];
extern const char lbl_805A5884[];
extern const char lbl_805A5890[];
extern const char lbl_805A589C[];
extern const char lbl_805A58AC[];
extern const char lbl_805A58BC[];
extern const char lbl_805A58CC[];
extern const char lbl_805A58DC[];
extern const char lbl_805A58EC[];
extern const char lbl_805A5900[];
extern const char lbl_805A590C[];
extern const char lbl_805A5918[];
extern const char lbl_805A5928[];
extern const char lbl_805A5938[];
extern const char lbl_805A5944[];
extern const char lbl_805A5954[];
extern const char lbl_805A5960[];
extern const char lbl_805A5970[];
extern const char lbl_805A5980[];
extern const char lbl_805A598C[];
extern const char lbl_805A599C[];
extern const char lbl_805A59A8[];
extern const char lbl_805A59B4[];
extern const char lbl_805A59C0[];
extern const char lbl_805A59D4[];
extern const char lbl_805A59E4[];
extern const char lbl_805A59F4[];
extern const char lbl_805A5A04[];
extern const char lbl_805A5A14[];
extern const char lbl_805A5A28[];
extern const char lbl_805A5A3C[];
extern const char lbl_805A5A4C[];
extern const char lbl_805A5A5C[];
extern const char lbl_805A5A70[];
extern const char lbl_805A5A88[];
extern const char lbl_805A5A94[];
extern const char lbl_805A5AE4[];
extern const char lbl_805A5AF4[];
extern const char lbl_805A5B08[];
extern const char lbl_805A5B18[];
extern const char lbl_805A5B2C[];
extern const char lbl_805A5B40[];
extern const char lbl_805A5B4C[];
extern const char lbl_805A5B60[];
extern const char lbl_805A5B68[];
extern const char lbl_805A5B78[];
extern const char lbl_805A5B80[];
extern const char lbl_805A5B90[];
extern const char lbl_805A5BA8[];
extern const char lbl_805A5BB8[];
extern const char lbl_805A5BD0[];
extern const char lbl_805A5BE0[];
extern const char lbl_805A5BF0[];
extern const char lbl_805A5C00[];
extern const char lbl_805A5C10[];
extern const char lbl_805A5C20[];
extern const char lbl_805A5C3C[];
extern const char lbl_805A5C4C[];
extern const char lbl_805A5C5C[];
extern const char lbl_805A5C70[];
extern const char lbl_805A5C80[];
extern const char lbl_805A5C90[];
extern const char lbl_805A5CA0[];
extern const char lbl_805A5CB4[];
extern const char lbl_805A5CC8[];
extern const char lbl_805A5CDC[];
extern const char lbl_805A5CEC[];
extern const char lbl_805A5CFC[];
extern const char lbl_805A5D14[];
extern const char lbl_805A5D24[];
extern const char lbl_805A5D34[];
extern const char lbl_805A5D4C[];
extern const char lbl_805A5D64[];
extern const char lbl_805A5D78[];
extern const char lbl_805A5D88[];
extern const char lbl_805A5D98[];
extern const char lbl_805A5DA8[];
extern const char lbl_805A5DC0[];
extern const char lbl_805A5DD0[];
extern const char lbl_805A5DE0[];
extern const char lbl_805A5DF8[];
extern const char lbl_805A5E08[];
extern const char lbl_805A5E18[];
extern const char lbl_805A5E24[];
extern const char lbl_805A5E34[];
extern const char lbl_805A5E4C[];
extern const char lbl_805A5E60[];
extern const char lbl_805A5E74[];
extern const char lbl_805A5E88[];
extern const char lbl_805A5E9C[];
extern const char lbl_805A5EA8[];
extern const char lbl_805A5EB8[];
extern const char lbl_805A5EC8[];
extern const char lbl_805A5ED8[];
extern const char lbl_805A5EEC[];
extern const char lbl_805A5EFC[];
extern const char lbl_805A5F0C[];
extern const char lbl_805A5F1C[];
extern const char lbl_805A5F2C[];
extern const char lbl_805A5F40[];
extern const char lbl_805A5F5C[];
extern const char lbl_805A5F70[];
extern const char lbl_805A5F84[];

/* Float constants in the unity TU's .rodata. */
extern const float lbl_805A5AC4;
extern const float lbl_805A5AC8;
extern const float lbl_805A5ACC;
extern const float lbl_805A5AD0;
extern const float lbl_805A5AD4;
extern const float lbl_805A5AD8;
extern const float lbl_805A5ADC;
extern const float lbl_805A5AE0;
extern const float lbl_805A539C;
extern const char* lbl_80616524;
extern const char lbl_805A53A0[];
extern const char lbl_805A53AC[];

extern "C" void fn_8001FDA8(Unk8001E444_Obj* x)
{
    fn_80046E68(fn_802540A0(x->m130->m588, 3, 2));
}

extern "C" void fn_8001FDDC(Unk8001E444_Obj* x)
{
    fn_800431DC(fn_80253E7C(x->m130->m588, 2, 2, 0));
}

extern "C" int fn_8001FE14()
{
    return 0;
}

extern "C" int fn_8001FE1C()
{
    return 0;
}

extern "C" int fn_8001FE24()
{
    return 0;
}

extern "C" int fn_8001FE2C()
{
    return 0;
}

Unk8001FE34::Unk8001FE34()
    : Unk8037B3E8(0x9A0B3B52U)
{
    for (int i = 0; i < 99; i++)
        m8[i] = lbl_805A539C;
    for (int j = 0; j < 8; j++) {
        m194[j] = lbl_805A539C;
        m1B4[j] = lbl_805A539C;
    }
    m4 = 100;
}

void Unk8001FE34::fn_vslot2()
{
    fn_8037B7E4(lbl_805A53A0);
    fn_8037B7E8(lbl_805A53A4);
    fn_8037B494(lbl_805A53AC, &m4, 0, 0);
    fn_8037B50C(lbl_805A53BC, &m194[0], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A53D4, &m194[1], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A53E0, &m194[2], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A53F0, &m194[3], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5400, &m194[4], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5410, &m194[5], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A541C, &m194[6], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A542C, &m194[7], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A543C, &m8[0], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5448, &m8[1], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5454, &m8[2], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5464, &m8[3], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5474, &m8[4], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5484, &m8[5], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5494, &m8[53], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A54A4, &m8[54], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A54B4, &m8[6], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A54C0, &m8[7], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A54D0, &m8[47], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A54E0, &m8[48], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A54F0, &m8[49], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5500, &m8[50], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A550C, &m8[51], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5518, &m8[52], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5528, &m8[55], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5534, &m8[56], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5544, &m8[57], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5550, &m8[58], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5560, &m8[60], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5574, &m8[61], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5588, &m8[59], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5598, &m8[62], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A55A8, &m8[63], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A55BC, &m8[64], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A55C8, &m8[78], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A55D8, &m8[65], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A55E4, &m8[79], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A55F8, &m8[70], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5600, &m8[71], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5608, &m8[72], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5614, &m8[73], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5620, &m8[74], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A562C, &m8[75], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A563C, &m8[76], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5648, &m8[77], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5658, &m8[66], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5668, &m8[67], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5678, &m8[68], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A568C, &m8[69], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A56A4, &m8[80], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A56B8, &m8[8], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A56C8, &m8[9], lbl_805A53C8, 0);
    fn_8037B830(lbl_805A53A4);
    fn_8037B7E8(lbl_805A56DC);
    fn_8037B50C(lbl_805A56F4, &m8[10], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5704, &m8[11], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5718, &m8[12], lbl_805A53C8, 0);
    fn_8037B830(lbl_805A56DC);
    fn_8037B7E8(lbl_805A5728);
    fn_8037B50C(lbl_805A5734, &m8[13], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5744, &m8[14], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5754, &m8[20], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5764, &m8[21], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5774, &m8[22], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5784, &m8[23], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5794, &m8[15], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A57A8, &m8[16], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A57B8, &m8[17], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A57C8, &m8[18], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A57D8, &m8[19], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A57E8, &m8[24], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A57F8, &m8[25], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5808, &m8[26], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A581C, &m8[27], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A582C, &m8[28], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A583C, &m8[29], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A584C, &m8[30], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5858, &m8[31], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5864, &m8[32], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5874, &m8[33], lbl_805A53C8, 0);
    fn_8037B830(lbl_805A5728);
    fn_8037B7E8(lbl_805A5884);
    fn_8037B50C(lbl_805A5890, &m8[34], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A589C, &m8[35], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A58AC, &m8[36], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A58BC, &m8[37], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A58CC, &m8[38], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A58DC, &m8[39], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A58EC, &m8[40], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5900, &m8[41], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A590C, &m8[42], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5918, &m8[43], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5928, &m8[44], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5938, &m8[45], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5944, &m8[46], lbl_805A53C8, 0);
    fn_8037B830(lbl_805A5884);
    fn_8037B7E8(lbl_805A5954);
    fn_8037B50C(lbl_805A5960, &m8[81], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5970, &m8[82], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5980, &m8[83], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A598C, &m1B4[4], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A599C, &m1B4[1], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A59A8, &m8[84], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A59B4, &m8[85], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A59C0, &m8[86], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A59D4, &m8[87], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A59E4, &m8[88], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A59F4, &m8[89], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5A04, &m8[90], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5A14, &m8[91], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5A28, &m8[92], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5A3C, &m8[93], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5A4C, &m8[94], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5A5C, &m8[95], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5A70, &m8[96], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5A88, &m8[97], lbl_805A53C8, 0);
    fn_8037B50C(lbl_805A5A94, &m8[98], lbl_805A53C8, 0);
    fn_8037B830(lbl_805A5954);
}

Unk8001FE34::~Unk8001FE34()
{
}

int Unk8001FE34::fn_80020BCC()
{
    return fn_8037C7FC()->fn_8037CE98(0x9A0B3B52, (int)this, 0);
}

Unk8037B3E8* Unk8001FE34::fn_vslot5()
{
    return new (lbl_806EF9B4) Unk8001FE34;
}

void Unk8001FE34::fn_vslot8()
{
    fn_80020C5C();
}

void Unk8001FE34::fn_80020C5C()
{
    fn_80020FCC();
    if (fn_8001C394()->fn_8001CC40(3) == 0 && fn_8001C394()->fn_8001CC40(6) == 0
        && fn_8001C394()->fn_8001CC40(2) == 0 && fn_8001C394()->fn_8001CC40(1) == 0
        && fn_8001C394()->fn_8001CC40(5) == 0 && fn_8001C394()->fn_8001CC40(7) == 0) {
        fn_80020DC8();
        fn_80020F4C();
    } else {
        fn_80020D58();
        fn_80020ECC();
        Unk8004072C_Obj* o = fn_8004072C();
        fn_800414FC(o, fn_80021010(lbl_805AF5FC, m8[0x51]), 0x51);
    }
    fn_80020E3C();
}

void Unk8001FE34::fn_80020D58()
{
    for (int i = 0; i <= 7; i++) {
        int v = fn_80021010(lbl_805B09D4[i], m194[i]);
        fn_800489B4(fn_800475EC(), i, v);
    }
}

void Unk8001FE34::fn_80020DC8()
{
    int v = fn_80021010(lbl_805B09D4[4], m1B4[4]);
    fn_800489B4(fn_800475EC(), 4, v);
    v = fn_80021010(lbl_805B09D4[1], m1B4[1]);
    fn_800489B4(fn_800475EC(), 1, v);
}

void Unk8001FE34::fn_80020E3C()
{
    int v;
    if (fn_8001C394()->fn_8001CC40(5))
        v = fn_80021010(3, m8[46]);
    else if (fn_8001C394()->fn_8001CC40(1))
        v = fn_80021010(3, m8[33]);
    else
        v = fn_80021010(3, m8[82]);
    fn_8005B76C(fn_8005ACE4(), v);
}

/* near-miss: 32/32 insns, 4 slots differ (the two loop offset registers r28/r29 are swapped:
 * retail gives the stride-8 table offset r28 and the stride-4 float offset r29). Tried:
 * temps for the table entry/float, pointer locals, do/while and while forms, int* view. */
void Unk8001FE34::fn_80020ECC()
{
    for (int i = 0; i <= 0x50; i++) {
        Unk8004072C_Obj* o = fn_8004072C();
        fn_800414FC(o, fn_80021010(lbl_805AF370[i].m4, m8[i]), i);
    }
}

/* near-miss: same r28/r29 swap as fn_80020ECC. */
void Unk8001FE34::fn_80020F4C()
{
    for (int i = 0x51; i <= 0x62; i++) {
        Unk8004072C_Obj* o = fn_8004072C();
        fn_800414FC(o, fn_80021010(lbl_805AF370[i].m4, m8[i]), i);
    }
}

void Unk8001FE34::fn_80020FCC()
{
    if (fn_8004072C()->m5D0 == 1)
        fn_80042C78(fn_8004072C(), m4);
}

/* near-miss: 53/53 insns, 2 slots differ: the stray `mr r9,r11` copy of the int-to-float
 * path is `mr r3,r11` here (register choice only). Tried temps for m4/scale and return forms. */
int Unk8001FE34::fn_80021010(int idx, float f)
{
    float t = !(f > lbl_805A5AA0) ? (f >? lbl_805A5AA4) : lbl_805A5AA0;
    if (idx == 0 || idx == 3)
        return (int)(t * lbl_80616508[idx] * lbl_805A5AA8);
    return (int)(t * lbl_80616508[idx] * (float)m4);
}

void Unk8001FE34::fn_800210E4(float f, int idx)
{
    float t = !(f > lbl_805A5AB8) ? (f >? lbl_805A5ABC) : lbl_805A5AB8;
    lbl_80616508[idx] = t;
    fn_80020C5C();
}

void Unk8001FE34::fn_8002114C(int v)
{
    m4 = v > 100 ? 100 : v < 0 ? 0 : v;
    fn_80020C5C();
}

Unk8002118C::Unk8002118C()
    : Unk8037B3E8(0x871AE7A9U)
{
    m4 = lbl_805A5AC4;
    m8 = lbl_805A5AC8;
    mC = lbl_805A5ACC;
    m10 = lbl_805A5AD0;
    m14 = lbl_805A5AD4;
    m18 = lbl_805A5AD8;
    m1C = lbl_805A5ADC;
    m20 = lbl_805A5ADC;
    m24 = lbl_805A5ADC;
    m28 = lbl_805A5AC4;
    m2C = lbl_805A5AC4;
    m30 = lbl_805A5AC4;
    m34 = lbl_805A5AC4;
    m38 = lbl_805A5AC4;
    m3C = lbl_805A5AC4;
    m40 = lbl_805A5AC4;
    m44 = lbl_805A5AC4;
    m48 = lbl_805A5AC4;
    m4C = lbl_805A5AC4;
    m50 = lbl_805A5AC4;
    m54 = lbl_805A5AC4;
    m58 = lbl_805A5AC4;
    m5C = lbl_805A5AC4;
    m60 = lbl_805A5AC4;
    m64 = lbl_805A5AC4;
    m68 = lbl_805A5AC4;
    m6C = lbl_805A5AC4;
    m70 = lbl_805A5AC4;
    m74 = lbl_805A5AC4;
    m78 = lbl_805A5AC4;
    m7C = lbl_805A5AC4;
    m80 = lbl_805A5AC4;
    m84 = lbl_805A5AC4;
    m88 = lbl_805A5AC4;
    m8C = lbl_805A5AC4;
    m90 = lbl_805A5AC4;
    m94 = lbl_805A5AE0;
    m98 = lbl_805A5AC4;
    m9C = lbl_805A5AC4;
    mA0 = lbl_805A5AC4;
    mA4 = lbl_805A5AC4;
    mA8 = lbl_805A5AC4;
    mAC = lbl_805A5AC4;
    mB0 = lbl_805A5AC4;
    mB4 = lbl_805A5AC4;
    mB8 = lbl_805A5AC4;
}

void Unk8002118C::fn_vslot2()
{
    fn_8037B7E4(lbl_80616524);
    fn_8037B7E8(lbl_805A5AE4);
    fn_8037B50C(lbl_805A5AF4, &m4, lbl_805A5B08, 0);
    fn_8037B50C(lbl_805A5B18, &m8, lbl_805A5B08, 0);
    fn_8037B50C(lbl_805A5B2C, &mC, lbl_805A5B08, 0);
    fn_8037B50C(lbl_805A5B40, &m10, lbl_805A5B08, 0);
    fn_8037B830(lbl_805A5AE4);
    fn_8037B7E8(lbl_805A5B4C);
    fn_8037B50C(lbl_805A5B60, &m1C, lbl_805A5B68, 0);
    fn_8037B50C(lbl_805A5B78, &m20, lbl_805A5B80, 0);
    fn_8037B50C(lbl_805A5B90, &m24, lbl_805A5BA8, 0);
    fn_8037B830(lbl_805A5B4C);
    fn_8037B7E8(lbl_805A5BB8);
    fn_8037B50C(lbl_805A5BD0, &m28, lbl_805A5BE0, 0);
    fn_8037B50C(lbl_805A5BF0, &m2C, lbl_805A5C00, 0);
    fn_8037B50C(lbl_805A5C10, &m30, lbl_805A5BA8, 0);
    fn_8037B830(lbl_805A5BB8);
    fn_8037B7E8(lbl_805A5C20);
    fn_8037B50C(lbl_805A5C3C, &m34, lbl_805A5C4C, 0);
    fn_8037B50C(lbl_805A5C5C, &m38, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5C70, &m3C, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5C80, &m40, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5C90, &m44, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5CA0, &m48, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5CB4, &m4C, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5CC8, &m50, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5CDC, &m54, lbl_805A5C00, 0);
    fn_8037B50C(lbl_805A5CEC, &m58, lbl_805A5BA8, 0);
    fn_8037B830(lbl_805A5C20);
    fn_8037B7E8(lbl_805A5CFC);
    fn_8037B50C(lbl_805A5D14, &m5C, lbl_805A5BE0, 0);
    fn_8037B50C(lbl_805A5D24, &m60, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5D34, &m64, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5D4C, &m68, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5D64, &m6C, lbl_805A5D78, 0);
    fn_8037B50C(lbl_805A5D88, &m70, lbl_805A5C00, 0);
    fn_8037B50C(lbl_805A5D98, &m74, lbl_805A5BA8, 0);
    fn_8037B830(lbl_805A5CFC);
    fn_8037B7E8(lbl_805A5DA8);
    fn_8037B50C(lbl_805A5DC0, &m78, lbl_805A5DD0, 0);
    fn_8037B50C(lbl_805A5DE0, &m7C, lbl_805A5DF8, 0);
    fn_8037B830(lbl_805A5DA8);
    fn_8037B7E8(lbl_805A5E08);
    fn_8037B50C(lbl_805A5E18, &mA4, lbl_805A5DF8, 0);
    fn_8037B50C(lbl_805A5E24, &mA8, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5E34, &mB0, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5E4C, &mAC, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5E60, &mB4, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5E74, &mB8, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5E88, &mA0, lbl_805A53C8, 0);
    fn_8037B830(lbl_805A5E08);
    fn_8037B7E8(lbl_805A5E9C);
    fn_8037B50C(lbl_805A5EA8, &m14, lbl_805A5B08, 0);
    fn_8037B50C(lbl_805A5EB8, &m18, lbl_805A5EC8, 0);
    fn_8037B50C(lbl_805A5ED8, &m80, lbl_805A5DF8, 0);
    fn_8037B50C(lbl_805A5EEC, &m84, lbl_805A5EFC, 0);
    fn_8037B50C(lbl_805A5F0C, &m88, lbl_805A5F1C, 0);
    fn_8037B50C(lbl_805A5F2C, &m8C, lbl_805A5EFC, 0);
    fn_8037B50C(lbl_805A5F40, &m90, lbl_805A5EFC, 0);
    fn_8037B50C(lbl_805A5F5C, &m94, lbl_805A5BE0, 0);
    fn_8037B50C(lbl_805A5F70, &m98, lbl_805A5BA8, 0);
    fn_8037B50C(lbl_805A5F84, &m9C, lbl_805A5BA8, 0);
    fn_8037B830(lbl_805A5E9C);
}

Unk8002118C::~Unk8002118C()
{
}

Unk8002118C* Unk8002118C::fn_8002194C()
{
    return (Unk8002118C*)fn_8037C7FC()->fn_8037CE98(0x871AE7A9, (int)this, 0);
}

Unk8037B3E8* Unk8002118C::fn_vslot5()
{
    return new (lbl_806EF9B4) Unk8002118C;
}

void Unk8002118C::fn_vslot8()
{
    fn_800475EC()->SetAE0(m80);
    fn_800475EC()->SetAE4(m8C);
    fn_800475EC()->SetAE8(m94);
    fn_800475EC()->SetAEC(m1C);
}

Unk80021A60::Unk80021A60(int arg)
{
    m78 = arg;
    m7C = -1;
    m8C = 0;
    m90 = lbl_805A5F9C;
    m94 = lbl_805A5F9C;
    m98 = lbl_805A5F9C;
    m9C = lbl_805A5FA0;
    mA0 = lbl_805A5FA4;
    mA4 = lbl_805A5FA8;
    mA8 = lbl_805A5FAC;
    mAC = lbl_805A5FB0;
    mB0 = lbl_805A5FB4;
    mB4 = 0;
    for (int i = 0; i < 3; i++)
        m80[i] = 0;
    fn_vslot10();
    Unk8002118C* p = lbl_80686DC8->fn_8002194C();
    m8C = p;
    m9C = (lbl_805A5FB8 - p->m8) * lbl_805A5FBC;
    mA0 = p->m8 + m9C;
    mAC = m9C - p->m10;
    mB0 = mA0 + p->m10;
    mA4 = (lbl_805A5FB8 - p->mC) * lbl_805A5FBC;
    mA8 = p->mC + mA4;
}

Unk80021A60::~Unk80021A60()
{
}

