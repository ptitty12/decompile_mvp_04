/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x800320B8-0x80033BC8 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_800320B8.h"

extern "C" void fn_800320B8(Unk8003265C* self, int i)
{
    if (self->mC8[i] == 0) {
        Unk8003265C_Vec2 v = self->m11C[i]->m3B8;
        if (!(v.m0 > 1.0f) && !(v.m0 < -1.0f) && !(v.m4 > 1.0f) && !(v.m4 < -1.0f))
            fn_80039A3C(fn_80031110(self, i, 3), 2, 0);
    }
}

extern "C" void fn_80032154(void* self, float f)
{
}

extern "C" void fn_80032164(void* self, float f)
{
}

extern "C" void fn_80032174(Unk8003265C* self)
{
    if (self->m128 == 1 && self->mB4 != 0) {
        for (int i = 0; i <= 9; i++) {
            if (self->m0[i].m4 != 0) {
                int t = self->m0[i].m4 - 1;
                self->m0[i].m4 = t;
                if (t == 0) {
                    for (int j = 0; j <= 4; j++) {
                        if (lbl_80616B6C[j].id == self->m0[i].m0) {
                            (self->*lbl_80616B6C[j].h)(i);
                            break;
                        }
                    }
                    self->mB4 = self->mB4 - 1;
                }
            }
        }
    }
}

extern "C" void fn_80032294(Unk8003265C* self)
{
    int a = self->m130;
    int b = a & 1;
    if (b == 0 && self->m138 == 1) {
        self->m12C = b;
        if (a == 0)
            fn_8005AF00(fn_8005ACE4(), 2);
        fn_8003968C(fn_80038EB4(), 2);
    }
    for (int i = 0; i < 10; i++)
        self->m0[i].m4 = 0;
    self->mB4 = 0;
    self->m130 = self->m130 + 1;
}

extern "C" void fn_80032328(Unk8003265C* self, int i)
{
    float a = 0.0f;
    float b = 0.0f;
    float c = 0.0f;
    int id = self->m0[i].m8;
    if (self->mBC[id] == 0) {
        self->mBC[id] = 1;
        fn_8018CA5C(self->m11C[id], &a, &b, &c);
        c = c * 0.05681818f;
        fn_80021D6C(self, self->m80[id], (int)c);
    }
}

extern "C" void fn_800323D8(Unk8003265C* self, int i)
{
    int id = self->m0[i].m8;
    if (self->mC8[id] == 0) {
        self->mC8[id] = 1;
        Unk8003265C_P* p = self->m11C[id];
        float a = p->m3F0 - p->m3F4;
        float b = fn_8018A214(p);
        Unk8003265C_Vec3 v = fn_8018959C(self->m11C[id], a);
        float len = fn_804028E4(v.m0 * v.m0 + v.m8 * v.m8) * 0.083333336f;
        if (!(b >= a))
            len = ((len * a) / b) * 0.83f;
        if (!(v.m0 < 0.0f) && !(v.m8 < 0.0f)) {
            if (!(len < 180.0f)) {
                if (!(len > 250.0f)) {
                    fn_80039A3C(fn_80031110(self, id, 8), 1, 0);
                } else if (!(len > 320.0f)) {
                    fn_80039A3C(fn_80031110(self, id, 5), 1, 0);
                } else {
                    fn_80039A3C(fn_80031110(self, id, 5), 2, 0);
                }
            }
        } else {
            if ((!(v.m0 <= -5.0f) && v.m8 > 320.0f) || (!(v.m8 <= -5.0f) && !(v.m0 <= 320.0f)))
                fn_80039A3C(fn_80031110(self, id, 2), 1, 0);
            else
                fn_80039A3C(fn_80031110(self, id, 3), 1, 0);
        }
    }
}

extern "C" void fn_800325BC(Unk8003265C* self, int i)
{
    int id = self->m0[i].m8;
    if (self->mBC[id] == 0)
        fn_80039A3C(fn_80031110(self, id, 3), 2, 0);
}

extern "C" void fn_8003260C(Unk8003265C* self, int i)
{
    int id = self->m0[i].m8;
    if (self->mBC[id] == 0)
        fn_80039A3C(fn_80031110(self, id, 3), 2, 0);
}

extern "C" Unk8003265C* fn_8003265C(Unk8003265C* self)
{
    void* sub = &self->mBC;
    fn_80021A60(self);
    fn_803785E4(sub);
    *(const void**)((char*)sub + 8) = lbl_80649DB8;
    self->mC4 = lbl_80649858;
    self->SetVptr(lbl_80649880);
    self->m128 = 0;
    self->m12C = 0;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m14C = 0;
    for (int i = 0; i < 3; i++) {
        self->mC8[i] = 0;
        self->mD4[i] = 0;
        self->mE0[i] = 0;
        self->m11C[i] = 0;
        self->m110[i] = -1;
        self->mEC[i] = 0;
        self->mF8[i] = 0;
        self->m104[i] = 0;
    }
    int r = fn_8001CC40(fn_8001C394(), 1);
    if (r == 1)
        self->m128 = r;
    self->m144 = fn_80377458(0xC);
    self->m148 = fn_80377458(0xC);
    return self;
}

extern "C" void fn_80032768(Unk8003265C* self, int chrg)
{
    self->mC4 = lbl_80649858;
    self->SetVptr(lbl_80649880);
    for (int i = 0; i < 3; i++) {
        if (self->m80[i] != 0)
            self->m80[i] = 0;
    }
    fn_8005B58C(fn_8005ACE4(), 0);
    fn_8004181C(fn_8004072C(), 0x1E, self->m140, 0, 0, 0, 0);
    fn_8004181C(fn_8004072C(), self->m148[0], self->m144[0], 0, 0, 0, 0);
    fn_8004181C(fn_8004072C(), self->m148[1], self->m144[1], 0, 0, 0, 0);
    fn_8004181C(fn_8004072C(), self->m148[2], self->m144[2], 0, 0, 0, 0);
    if (self->m148)
        fn_80377488(self->m148);
    if (self->m144)
        fn_80377488(self->m144);
    void* sub = &self->mBC;
    *(const void**)((char*)sub + 8) = lbl_80649DB8;
    fn_80378620(sub, 0);
    fn_80021BB4(self, chrg);
}

extern "C" int fn_800328C4(Unk8003265C* self, Unk8002D15C_Owner* o)
{
    int idx = -1;
    for (int i = 0; i <= 2; i++) {
        if (self->m80[i] == 0) {
            fn_80378A34(&self->mBC, (char*)o + 0x704);
            self->m80[i] = o;
            idx = i;
            if (self->m7C < idx)
                self->m7C = idx;
            break;
        }
    }
    return idx;
}

extern "C" void fn_80032948(Unk8003265C* self, int i)
{
    if (self->m80[i] != 0) {
        fn_8003A058(fn_80038EB4(), self->m110[i]);
        self->m80[i] = 0;
        for (int j = 0; j < 3; j++) {
            if (self->m80[j] != 0)
                self->m7C = j;
        }
    }
}

extern "C" void fn_800329C8(Unk8003265C* self, int a)
{
    if (self->m138 == 0)
        fn_800233B4(self, 0x1B, 0x1E, a);
}

extern "C" void fn_80032A00(Unk8003265C* self)
{
    if (self->m138 == 0) {
        float f = 0.45f;
        Unk8002D15C_Owner* o = self->m80[0];
        if (o != 0)
            f = fn_8017FA08((int)o->m700 + 0x24);
        self->m138 = 1;
        fn_8005AF00(fn_8005ACE4(), 0);
        self->m13C = 1;
        self->m140 = fn_800412AC(fn_8004072C(), 0x1E, 0, 0, 0, 0);
        self->m148[0] = 0x1A;
        self->m148[1] = 0x1B;
        self->m148[2] = 0x1C;
        self->m144[0] = -1;
        self->m144[1] = -1;
        self->m144[2] = -1;
    }
}

extern "C" int fn_80032AD4(Unk8003265C* self)
{
    int n = 0;
    for (int i = 0; i < 3; i++) {
        if (self->m80[i] != 0)
            n++;
    }
    return n;
}

extern "C" void fn_800331C8(Unk8003265C* self, int i, Unk8002D15C_Msg* msg)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(msg, 0x3A);
    self->m104[i] = m->m14;
    int t = self->mF8[i] + 1;
    self->mF8[i] = t;
    if (t > 4)
        self->mF8[i] = 4;
    if (self->m104[i] == 1)
        fn_80021E30(self, self->m80[i], 0x5A);
}

extern "C" void fn_80033254(Unk8003265C* self, int i, Unk8002F894_Ev* ev)
{
    int t = ev->m4;
    Unk8002D15C_Player* p = ev->m8;
    if ((unsigned int)t <= 1 || t == 3 || t == 6 || t == 4 || t == 5 || t == 9) {
        Unk8002F894_Obj o;
        o.Base(0x3B);
        o.Derived();
        int x;
        if (t == 0)
            x = 0xA;
        else if (t == 1)
            x = 0xB;
        else if (t == 4)
            x = 3;
        else if (t == 5)
            x = 4;
        else if (t == 6)
            x = 1;
        else if (t == 9)
            x = 6;
        else
            x = 0xD;
        o.Set(x, p);
        fn_8037893C((char*)p->m44C + 0x704, o.m0, &o, 0, 0);
        fn_803444D0(&o, 2);
    }
}

extern "C" void fn_80033728(Unk8003265C* self, int i, Unk8002D15C_Msg* msg)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(msg, 0x58);
    Unk8002D15C_Player* p = (Unk8002D15C_Player*)m->mC;
    int r = p->m460;
    if (m->m20 == 1) {
        Unk8002D15C_Cc* c = self->m80[i]->m6CC;
        float d = c->m3F4 - 0.016666668f;
        float len;
        Unk8002D15C_Vec3 v = fn_80196E3C(c->m448, d);
        len = fn_804028E4(v.m0 * v.m0 + v.m4 * v.m4 + v.m8 * v.m8) * 0.05681818f;
        int n = (int)(float)fn_80410634(len) + 0xC;
        fn_80021EB4(self, self->m80[i], r, 2, n);
    }
}

extern "C" void fn_80033818()
{
}

extern "C" void fn_8003381C(void* self, float f)
{
}

extern "C" void fn_8003382C(void* self, float f)
{
}

extern "C" void fn_8003383C(Unk8003265C* self)
{
    if (self->m128 == 1) {
        Unk8002D15C_Owner* own = lbl_8061B8C0->m8;
        int h = ((Unk8003383C_Owner730*)own)->m730;
        Unk8003383C_Obj* ids[3];
        ids[0] = (Unk8003383C_Obj*)fn_8031C228(h, lbl_805A66EC);
        ids[1] = (Unk8003383C_Obj*)fn_8031C228(h, lbl_805A66F4);
        ids[2] = (Unk8003383C_Obj*)fn_8031C228(h, lbl_805A66FC);
        for (int i = 0; i < 3; i++) {
            Unk8003383C_Obj* p = ids[i];
            if (p != 0) {
                Unk8003383C_Cc* c = p->m120;
                if (c->m264 == 0) {
                    Unk8002D15C_Vec3 v = c->m60;
                    int a;
                    int b;
                    fn_800222B4(own, &a, &b, v);
                    if (self->m144[i] == -1) {
                        self->m144[i] = fn_800412AC(fn_8004072C(), self->m148[i], a, b, 0x32, 0);
                    } else {
                        fn_80041778(fn_8004072C(), self->m148[i], self->m144[i], a, b, 0x32, 0);
                    }
                }
            }
        }
        if (self->mB4 != 0) {
            for (int i = 0; i <= 9; i++) {
                if (self->m0[i].m4 != 0) {
                    int t = self->m0[i].m4 - 1;
                    self->m0[i].m4 = t;
                    if (t == 0) {
                        for (int j = 0; j <= 4; j++) {
                            if (lbl_80616BA8[j].id == self->m0[i].m0) {
                                (self->*lbl_80616BA8[j].h)(i);
                                break;
                            }
                        }
                        self->mB4 = self->mB4 - 1;
                    }
                }
            }
        }
    }
}

extern "C" void fn_80033A88(Unk8003265C* self)
{
    int a = self->m130;
    int b = a & 1;
    if (b == 0 && self->m138 == 1) {
        if (a == 0)
            fn_8005AF00(fn_8005ACE4(), 0);
        self->m12C = b;
    }
    for (int i = 0; i < 10; i++)
        self->m0[i].m4 = 0;
    self->mB4 = 0;
    self->m130 = self->m130 + 1;
}
extern "C" void fn_80033B10(Unk8003265C* self, int i)
{
    float a = 0.0f;
    float b = 0.0f;
    float c = 0.0f;
    int id = self->m0[i].m8;
    if (self->mC8[id] == 0) {
        self->mC8[id] = 1;
        fn_8018CA5C(self->m11C[id], &a, &b, &c);
        c = c * 0.05681818f;
        fn_80021D6C(self, self->m80[id], (int)c);
    }
}

extern "C" void fn_80033BC0()
{
}

extern "C" void fn_80033BC4()
{
}
