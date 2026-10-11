/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8002EB80-0x80030778 only: every data object is extern by its lbl_ name.
 *
 * More handlers of the object described in game/tu_8002D15C.h.
 */
#include "game/tu_8002D15C.h"

extern "C" void fn_80039790(int a);

extern "C" void fn_8002EB80(Unk8002D15C* self)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0x98);
    self->m12C = m->m8;
    StartAnim(self, 0x5B);
    fn_8003F698(self->m6C8);
    self->m6BC = 0;
}

extern "C" void fn_8002EC28(Unk8002D15C* self)
{
    self->m7F0 = -1.0f;
}

extern "C" void fn_8002EC38(Unk8002D15C* self)
{
    Unk8002D15C_P700* p = self->m290->m44C->m700;
    float lim = p->m3E4;
    int flag = p->m3E0;
    if (!(self->m7F0 >= lim)) {
        int tbl[3] = { 0, 1, 2 };
        for (int i = 0; i <= 2; i++) {
            float t = (float)i * (1.0f / 3.0f);
            if (!(self->m7F0 >= t) && !(t > lim)) {
                if (flag == 0)
                    fn_80039A3C(8, tbl[i], 0);
                else
                    fn_80039A3C(4, tbl[i], 0);
                break;
            }
        }
        self->m7F0 = lim;
    }
}

extern "C" void fn_8002ED4C(Unk8002D15C* self)
{
    self->m7F0 = 0.0f;
}

extern "C" void fn_8002ED5C(Unk8002D15C* self)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0x97);
    Unk8002D15C_Player* p = (Unk8002D15C_Player*)m->mC;
    if (p != 0)
        self->m7B8 = p;
    fn_800233B4(self, 0x28, 0x64, 0);
    self->m6BC = 0;
    if (self->m80->m6F8->m10->m6C[p->m708] == -1)
        fn_8002F1E4(self);
}

extern "C" void fn_8002EE04(Unk8002D15C* self)
{
    fn_800233B4(self, 0x28, 0x64, 0);
}

extern "C" void fn_8002EE30()
{
}

extern "C" void fn_8002EE34(Unk8002D15C* self)
{
    fn_8003FA44(self->m6C8);
}

extern "C" void fn_8002EE58(Unk8002D15C* self)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0x92);
    if (m->m10 != m->mC || m->m18 != m->m14 || m->m20 != m->m1C || m->m28 != m->m24) {
        fn_8003B0F4(self->m6C8, m);
        self->m12C = m->m10;
        self->m130 = m->m18;
        self->m134 = m->m20;
        self->m138 = m->m28;
        self->m13C = m->mC;
        self->m140 = m->m14;
        self->m144 = m->m1C;
        self->m148 = m->m24;
        self->m14C = m->m8;
        StartAnim(self, 0x5A);
    }
    self->m6BC = 0;
}

extern "C" void fn_8002EF84(Unk8002D15C* self)
{
    StartAnim(self, 0x4E);
    int o = self->mD0;
    if (o != 0)
        fn_80036064(o, self->m514, 0, fn_8002A2D4(self));
    int r = fn_80253E7C(&self->m290->m588, 3, 2, 0);
    fn_8003C710(self->m6C8, r);
}

extern "C" void fn_8002F038(Unk8002D15C* self)
{
    int r = -1;
    if (*lbl_8061B9C4 - 1 == self->m530) {
        int s = self->m52C;
        if (s == 3) {
            switch (fn_8002A2D4(self)) {
            case 0:
                r = (self->m514 == 1);
                break;
            case 1:
                r = 1;
                if (self->m514 == 1)
                    r = 2;
                break;
            case 2:
                r = 0;
                break;
            case 3:
                if (self->m514 == 1)
                    r = 0;
                break;
            }
        } else if (s == 0 && self->m514 == 1) {
            switch (fn_8002A2D4(self)) {
            case 1:
                r = 2;
                break;
            case 0:
                r = 1;
                break;
            case 2:
                r = 0;
                break;
            case 3:
                r = 0;
                break;
            }
        }
    }
    if (r != -1)
        fn_80039E2C(fn_80038EB4(), r);
}

extern "C" void fn_8002F160(Unk8002D15C*)
{
    fn_80038EB4();
    fn_80039E94();
}

extern "C" void fn_8002F184(Unk8002D15C* self)
{
    self->m708 = 1;
    StartAnim(self, 0x4F);
}

extern "C" void fn_8002F1E4(Unk8002D15C* self)
{
    if (fn_80023430(self, 0x1C, 0, 0) == 1) {
        fn_80023490(self, 0x1C, 0);
        int t = self->m7AC;
        self->m130 = (int)self->m7A4;
        self->m12C = (int)self->m7A0;
        self->m134 = self->m7A8;
        if (t == 1) {
            self->m138 = t;
            self->m7AC = 0;
        } else {
            self->m138 = 0;
        }
        StartAnim(self, 0x41);
        self->m130 = (int)self->m7A4;
        self->m12C = (int)self->m7A0;
        StartAnim(self, 0x6A);
        if (self->m7A4->m460 == 0) {
            Unk8002D15C_Player* p = self->m7A0;
            Unk8002D15C_PI* e = &((Unk8002D15C_PI*)self->m80->m6F8->m14)[p->m708];
            int v = e->m238;
            int r = fn_80253DF4(&p->m588, 5, 0);
            if (v == self->m7A0->m704)
                fn_8003F250(self->m6C8, r);
            else
                fn_8003F37C(self->m6C8, r);
        }
    }
    if (fn_80023430(self, 0x1D, 0, 0) == 1) {
        fn_80023490(self, 0x1D, 0);
        self->m130 = (int)self->m7A4;
        self->m12C = (int)self->m7A0;
        self->m134 = self->m7D0;
        StartAnim(self, 0x42);
    }
    if (fn_80023430(self, 0x25, 0, 0) == 1) {
        fn_80023490(self, 0x25, 0);
        self->m12C = self->m7B0;
        self->m130 = self->m7B4;
        StartAnim(self, 0x6B);
    }
    if (fn_80023430(self, 0x28, 0, 0) == 1) {
        fn_80023490(self, 0x28, 0);
        self->m12C = (int)self->m7B8;
        StartAnim(self, 0x61);
    }
}

extern "C" void fn_8002F4D8(Unk8002D15C* self)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(self->m6BC, 0xA5);
    switch (m->m8) {
    case 8:
        StartAnim(self, 0x83);
        break;
    case 10:
        StartAnim(self, 0x84);
        break;
    case 11:
        StartAnim(self, 0x85);
        break;
    case 12:
        StartAnim(self, 0x86);
        break;
    case 2:
        StartAnim(self, 0x87);
        break;
    }
}

extern "C" void fn_8002F618(Unk8002D15C* self)
{
    StartAnim(self, 0x5F);
    fn_8002F1E4(self);
}

inline float LenSq(const Unk8002D15C_Vec3& v)
{
    return v.m0 * v.m0 + v.m4 * v.m4 + v.m8 * v.m8;
}

extern "C" void fn_8002F684(Unk8002D15C* self)
{
    Unk8002D15C_Cc* c = self->m80->m6CC;
    Unk8002D15C_Vec3 v = c->m60;
    if (c->m38C == 1 && self->mF0 == 0 && c->m388 != 1) {
        float len = fn_804028E4(LenSq(v)) * (1.0f / 12.0f);
        if (!(v.m0 <= 0.0f) && !(v.m8 <= 0.0f) && !(len <= lbl_80686DCC))
            StartAnim(self, 0x11);
    }
}

extern "C" void fn_8002F7A4(Unk8002D15C* self)
{
    int r = self->m80->m700->m3B8->m4->m9C;
    if (r != -0x30) {
        int p = r + 0xE8;
        if (fn_80211DB8(p) == 1 && fn_80211D78(p) != -1)
            fn_8003F14C(self->m6C8, fn_80211D78(p));
    }
}

extern "C" void fn_8002F824(Unk8002D15C* self)
{
    fn_800233B4(self, 0x25, 0x64, 0);
}

extern "C" void fn_8002F850(Unk8002D15C* self)
{
    self->m164++;
    int i = (self->m514 == 0);
    self->m170[i]++;
    self->m478[i][0]++;
}

extern "C" void fn_8002F894(Unk8002D15C* self, Unk8002F894_Ev* ev)
{
    int t = ev->m4;
    Unk8002D15C_Player* p = ev->m8;
    if (t == 0xB) {
        fn_8003F0D0(self->m6C8);
        return;
    }
    if ((unsigned int)t <= 9) {
        Unk8002F894_Obj o;
        o.Base(0x3B);
        o.Derived();
        int x = 0;
        if (t == 0)
            x = 0xA;
        else if (t == 1)
            x = 0xB;
        else if (t == 7)
            x = 2;
        else if (t == 4)
            x = 3;
        else if (t == 5)
            x = 4;
        else if (t == 6)
            x = 1;
        else if (t == 9)
            x = 6;
        else if (t == 2 && self->m530 <= 2)
            x = 0xC;
        else if (t == 3)
            x = 0xD;
        else if (t == 8)
            x = 0x10;
        if (x != 0) {
            o.Set(x, p);
            fn_8037893C((char*)p->m44C + 0x704, o.m0, &o, 0, 0);
        }
        fn_803444D0(&o, 2);
    }
}

extern "C" void fn_8002F9E8(Unk8002D15C* self)
{
    fn_803EE7BC();
    self->m6FC = 0;
    self->m700 = 0;
    self->m6F0 = 0;
    ((Unk8002D15C_Obj6C8*)self->m6C8)->v12();
    Unk8002D15C_Data14* d = self->mC8->m14;
    int b = d->mFFC;
    int a = d->m198;
    fn_8003B394(self->m6C8, fn_801A4B34(self->m80));
    fn_8003B3B8(self->m6C8, fn_801A497C(self->m80, self->m80->m6F8->m14->m1CD0 == 0, 0));
    fn_8003B23C(self->m6C8, 0, a);
    fn_8003B23C(self->m6C8, 1, b);
    fn_8002F160(self);
    fn_80021BE8(self);
    if (self->m704 == 1) {
        fn_800475EC();
        int k = 3;
        fn_80048968();
        fn_80048C08(fn_800475EC() + 0xFC);
        if (self->mC8->mC->m28 == 0x37)
            k = 6;
        fn_8003968C(fn_80038EB4(), k);
        int x = fn_80038EB4();
        fn_8017FA08(self->mCC);
        fn_80039790(x);
    }
    if (self->mD0 != 0)
        fn_80035E94(self->mD0);
    fn_803EE7BC();
}

extern "C" void fn_80030130(Unk8002D15C* self)
{
    self->m260 = 0;
    self->m264 = 0;
    self->m268 = 0;
    for (int i = 0; i < 4; i++)
        self->m1D0[i].m0 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m19C = 0;
    self->m1A0 = 0;
    self->m290 = (Unk8002D15C_Player*)fn_801A497C(self->m80, 0, 0);
    self->m510 = (Unk8002D15C_Player*)fn_801A4B34(self->m80);
    int flag = 0;
    if (self->m80->m6F8->m14->m1CD0 != 0)
        flag = 1;
    self->m714 = 0;
    self->m7AC = 0;
    self->m514 = flag;
    self->mE8 = 1;
    fn_8002FE88(self);
    for (int j = 0; j < 4; j++)
        self->m1C0[j] = 0;
    unsigned int k = self->m160;
    if (k <= 2) {
        self->m57C = 0;
    } else {
        if (k == 3)
            self->m57C = (fn_8040ABA0() % 100 <= 0x31);
        else
            self->m57C = 1;
    }
}

extern "C" void fn_80030274(Unk8002D15C* self)
{
    self->m7F4 = 0;
    self->m120 = 0;
    self->m11C = 0;
    self->m124 = 0;
    self->m128 = 0;
    self->m16C = 0;
    fn_80030380(self, 0);
    fn_80030380(self, 1);
    fn_800303A4(self, 0);
    fn_800303A4(self, 1);
    Unk8002D15C_Vec3* v = fn_8019CF24(self->m80->m6BC);
    v = fn_8019CF30(self->m6C0 = fn_804028E4(v->m0 * v->m0 + v->m8 * v->m8) * (1.0f / 12.0f), self->m80->m6BC);
    self->m6C4 = fn_804028E4(v->m0 * v->m0 + v->m8 * v->m8) * (1.0f / 12.0f);
    fn_80030130(self);
    fn_8005C75C(fn_8005BA9C(), 0, 300);
    fn_8005C75C(fn_8005BA9C(), 1, 300);
    fn_8005C75C(fn_8005BA9C(), 3, 300);
    self->m704 = 0;
}

extern "C" void fn_80030380(Unk8002D15C* self, int i)
{
    self->m190[i] = 0;
    self->m180[i] = 0;
    self->m178[i] = 0;
}

extern "C" void fn_800303A4(Unk8002D15C* self, int i)
{
    self->m3F0[i] = 1;
    self->m170[i] = 0;
    self->m450[i] = 0;
    self->m448[i] = 0;
    self->m460[i] = 0;
    self->m458[i] = 0;
    self->m188[i] = 0;
    self->m470[i] = 0;
    self->m468[i] = 0;
    self->m3F8[i] = 0;
    self->m400[i] = 0;
    self->m408[i] = 0;
    self->m410[i] = 0;
    self->m418[i] = 0;
    self->m420[i] = 0;
    self->m428[i] = 0;
    self->m430[i] = 0;
    self->m438[i] = 0;
    self->m440[i] = 0;
    for (int j = 0; j < 3; j++) {
        self->m478[i][j] = 0;
        self->m490[i][j] = 0;
        self->m4A8[i][j] = 0;
        self->m4C8[i][j] = 0;
        self->m4E0[i][j] = 0;
        self->m4F8[i][j] = 0;
    }
}

extern "C" void fn_8003049C(Unk8002D15C* self, int id, int newv, int oldv)
{
    if (oldv == (int)self->m290)
        self->m290 = (Unk8002D15C_Player*)fn_801A497C(self->m80, self->m514 == 0, 0);
    if (oldv == (int)self->m510)
        self->m510 = (Unk8002D15C_Player*)fn_801A4B34(self->m80);
    fn_8003B394(self->m6C8, (int)self->m510);
    fn_8003B3B8(self->m6C8, (int)self->m290);
    volatile int n = 0;
    int i = 0;
    do {
        if (self->m270[i].m0 == oldv)
            self->m270[i].m0 = newv;
        int t = n;
        int u;
        if (t > 3)
            u = t;
        else
            u = t + 1;
        n = u;
        i = u;
    } while (i <= 2);
    for (int k = 0; k < self->m260; k++) {
        if (self->m1D0[k].m0 == oldv)
            self->m1D0[k].m0 = newv;
    }
}
