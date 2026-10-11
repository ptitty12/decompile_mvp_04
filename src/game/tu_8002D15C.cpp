/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8002D15C-0x8002EB80 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_8002D15C.h"

extern "C" void fn_8002D15C(Unk8002D15C* self)
{
    fn_800221E4(self, self->m80, self->m7D4, self->m7D8);
}

extern "C" void fn_8002D188(Unk8002D15C* self)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0x51);
    Unk8002D15C_Vec3 v = *(Unk8002D15C_Vec3*)&m->m8;
    fn_80021C9C(self, self->m80, v);
    self->m6BC = 0;
}

extern "C" void fn_8002D224(Unk8002D15C* self)
{
    Unk8002D15C_Owner* o = self->m80;
    Unk8002D15C_Vec3 v = *(Unk8002D15C_Vec3*)(o->m6E4 + 0x60);
    fn_80021D04(self, o, v, self->m524 = 1, v);
}

extern "C" void fn_8002D290(Unk8002D15C* self)
{
    int a = self->m6F0;
    if ((a == 0 && self->m700 != 3) || (a == 1 && self->m700 == 3)) {
        fn_800475EC();
        fn_80048968();
        fn_8005C75C(fn_8005BA9C(), 0, 300);
        if (fn_8005C498(fn_8005BA9C(), 1) == 3)
            fn_8005C75C(fn_8005BA9C(), 1, 300);
    }
}

extern "C" void fn_8002DCF4(Unk8002D15C* self)
{
    fn_8003F6D4(self->m6C8, self->m80->m6F8->m14->m1CD0 == 0);
    fn_800233B4(self, 0x2A, 0x28, 0);
}

extern "C" void fn_8002DD50(Unk8002D15C* self)
{
    fn_80022270(self, self->m80, 0x10);
    if (self->m514 == 0)
        fn_80039A3C(7, 2, 0);
    else
        fn_80039A3C(4, 2, 0);
}

extern "C" void fn_8002DDB4(Unk8002D15C* self)
{
    int t = self->m7BC;
    if (t != 0) {
        self->m12C = t;
        self->m138 = 1;
        StartAnim(self, 0x58);
    }
}

extern "C" void fn_8002DE24(Unk8002D15C* self)
{
    int t = self->m7BC;
    if (t != 0) {
        self->m12C = t;
        self->m138 = 0;
        StartAnim(self, 0x58);
    }
}

extern "C" void fn_8002DE94(Unk8002D15C* self)
{
    int f = (self->m510->m58C.m4 >> 29) & 1;
    if (f == 0) {
        int t = self->m7BC;
        if (t != 0) {
            self->m12C = t;
            self->m138 = 0;
            StartAnim(self, 0x58);
        }
    }
}

extern "C" void fn_8002DF14(Unk8002D15C* self)
{
    fn_800233B4(self, 0x29, 0x1E, 0);
    StartAnim(self, 0x47);
}

extern "C" void fn_8002DF8C(Unk8002D15C* self)
{
    if (self->m514 == 0)
        fn_80039A3C(1, 2, 0);
    else
        fn_80039A3C(0, 2, 0);
}

extern "C" void fn_8002DFD8(Unk8002D15C* self)
{
    for (unsigned int i = 0; i <= self->m6FC; i++)
        StartAnim(self, 0x3A);
}

extern "C" void fn_8002E058(Unk8002D15C* self)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0x8A);
    int id = m->mC;
    int k = m->m8;
    for (int i = 0; i <= 2; i++) {
        if (id == self->m270[i].m0) {
            if (k == 0) {
                self->m270[i].m4++;
                if (self->m270[i].m4 == 2 && self->m264 == 1) {
                    self->m12C = i;
                    StartAnim(self, 0x3D);
                }
            } else if (k == 1) {
                if (self->m270[i].m4 > 0)
                    self->m270[i].m4--;
            }
            break;
        }
    }
    self->m6BC = 0;
}

extern "C" void fn_8002E178(Unk8002D15C* self)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0x8B);
    self->m12C = m->m8;
    StartAnim(self, 0x40);
    int o = self->mD0;
    if (o != 0)
        fn_80035EEC(o, self->m514, fn_8002A2D4(self));
    self->m6BC = 0;
}

extern "C" void fn_8002E240(Unk8002D15C* self)
{
    StartAnim(self, 0x54);
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0x7D);
    int k = m->m8;
    int r = (int)fn_80253EC4(&self->m290->m588, 0, 2, 0);
    switch (k) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        fn_8003F460(self->m6C8, r);
    }
    self->m6BC = 0;
}

extern "C" void fn_8002E314(Unk8002D15C* self)
{
    self->m530++;
    StartAnim(self, 0x64);
}

extern "C" void fn_8002E378(Unk8002D15C* self)
{
    Unk8002D15C_Owner* o = self->m80;
    if (!(o->m6CC->m3F4 >= 0.25f))
        fn_800233B4(self, 0x32, 0x1E, 0);
    else
        StartAnim(self, 0x65);
}

extern "C" void fn_8002E400(Unk8002D15C* self)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0x63);
    int k = self->m264;
    self->m7C8 = m->m8;
    self->m7CC = (Unk8002D15C_Player*)m->mC;
    if (k == 1) {
        fn_800233B4(self, 0x2E, 0xF, 0);
        return;
    }
    if (k > 1)
        fn_800233B4(self, 0x2E, 0x2D, 0);
}

extern "C" void fn_8002E488(Unk8002D15C* self)
{
    if (self->mE4 == 0) {
        Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0x8D);
        self->m12C = m->mC;
        self->m130 = m->m8;
        StartAnim(self, 0x67);
        self->mE4 = 1;
    }
}

extern "C" void fn_8002E53C(Unk8002D15C* self)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0x90);
    self->m12C = m->m8;
    self->m130 = m->mC;
    self->m134 = m->m10;
    self->m138 = m->m14;
    StartAnim(self, 0x6C);
}

extern "C" void fn_8002E5E4(Unk8002D15C* self)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0x91);
    self->m12C = m->m8;
    self->m130 = m->mC;
    self->m134 = m->m10;
    StartAnim(self, 0x6D);
}

extern "C" void fn_8002E684(Unk8002D15C* self)
{
    if (fn_80023430(self, 0x2E, 0, 0) == 0) {
        self->m130 = 1;
    } else {
        fn_80023490(self, 0x2E, 0);
        self->m130 = 2;
    }
    int k = self->m7C8;
    Unk8002D15C_Sub58C* p = &self->m7CC->m58C;
    if (p->m30 > k && !(p->m4 & 0x20000000) && self->m634 <= 2) {
        self->m12C = k;
        StartAnim(self, 0x3B);
    }
}

extern "C" void fn_8002E758(Unk8002D15C* self)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0x7A);
    int k = m->m8;
    self->m12C = k;
    self->m130 = (k == (int)self->m290);
    self->m134 = (k == (int)self->m510);
    StartAnim(self, 0x3F);
    self->m6BC = 0;
}

extern "C" void fn_8002E820(Unk8002D15C* self)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0x93);
    fn_8003049C(self, 0x93, m->m10, m->mC);
    self->m7A0 = (Unk8002D15C_Player*)m->mC;
    self->m7A8 = m->m8;
    self->m7A4 = (Unk8002D15C_Player*)m->m10;
    if (self->m7A8 == 0) {
        int i = self->m7A0->m708;
        self->m4C4 = self->m3F0[i];
        self->m4C0 = self->m470[i];
    } else {
        self->m4C0 = -1;
        self->m4C4 = 0;
    }
    if (self->m7A4 == self->m510)
        self->mE8 = 0;
    int z = self->m7A4->m460;
    if (z == 0) {
        int i = self->m7A4->m708;
        fn_800303A4(self, i);
        self->m3F0[i] = z;
    }
    if (fn_80023430(self, 0x1C, 0, 0) != 0)
        self->m7AC = 1;
    fn_800233B4(self, 0x1C, 0x64, 0);
    self->m6BC = 0;
    if (self->m80->m6F8->m10->m6C[self->m7A0->m708] == -1)
        fn_8002F1E4(self);
    if (lbl_8061B8C0->m24 == 0)
        fn_8002F1E4(self);
}

extern "C" void fn_8002E9A8(Unk8002D15C* self)
{
    fn_800233B4(self, 0x1C, 0x64, 0);
}

extern "C" void fn_8002E9D4(Unk8002D15C* self)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0x94);
    self->m7D0 = *(unsigned char*)&m->m18;
    self->m7A0 = (Unk8002D15C_Player*)m->m10;
    self->m7A4 = (Unk8002D15C_Player*)m->m14;
    if (self->m7A4 == self->m510)
        self->mE8 = 0;
    fn_8003049C(self, 0x94, m->m14, m->m10);
    fn_8003049C(self, 0x94, m->mC, m->m8);
    fn_800233B4(self, 0x1D, 0x64, 0);
    self->m6BC = 0;
    if (self->m80->m6F8->m10->m6C[self->m7A0->m708] == -1)
        fn_8002F1E4(self);
}

extern "C" void fn_8002EAC4(Unk8002D15C* self)
{
    fn_800233B4(self, 0x1D, 0x64, 0);
}

extern "C" void fn_8002EAF0(Unk8002D15C* self)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0x95);
    fn_8003049C(self, 0x95, m->m8, m->mC);
    self->m7B0 = m->m8;
    self->m7B4 = m->mC;
    fn_800233B4(self, 0x25, 0x64, 0);
    self->m6BC = 0;
}
