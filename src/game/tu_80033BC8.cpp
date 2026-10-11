/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80033BC8-0x80034BBC only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80033BC8.h"

extern "C" void fn_80033BC8()
{
}

extern "C" Unk80033BCC* fn_80033BCC(Unk80033BCC* self)
{
    fn_80021A60(self);
    self->SetVptr(lbl_806497F8);
    self->mD0 = -1;
    self->mC8 = 0;
    self->mCC = 0;
    self->mD4 = 0;
    self->mD8 = 0;
    self->mDC = 0;
    self->mE0 = 0;
    for (int i = 0; i < 3; i++)
        self->mBC[i] = 0;
    int r = fn_8001CC40(fn_8001C394(), 5);
    if (r == 1)
        self->mD4 = r;
    return self;
}

extern "C" void fn_80033C64(Unk80033BCC* self, int chrg)
{
    self->SetVptr(lbl_806497F8);
    fn_8005B58C(fn_8005ACE4(), 0);
    if (self->mD0 != -1)
        fn_8004181C(fn_8004072C(), 0x2D, self->mD0, 0, 0, 0, 0);
    for (int i = 0; i < 3; i++) {
        if (self->m80[i] != 0)
            self->m80[i] = 0;
    }
    fn_80021BB4(self, chrg);
}

extern "C" int fn_80033D0C(Unk80033BCC* self, Unk8002D15C_Owner* o)
{
    int idx = -1;
    for (int i = 0; i <= 2; i++) {
        if (self->m80[i] == 0) {
            self->m80[i] = o;
            idx = i;
            if (self->m7C < idx)
                self->m7C = idx;
            break;
        }
    }
    return idx;
}

extern "C" void fn_80033D74(Unk80033BCC* self, int i)
{
    if (self->m80[i] != 0) {
        self->m80[i] = 0;
        for (int j = 0; j < 3; j++) {
            if (self->m80[j] != 0)
                self->m7C = j;
        }
    }
}

extern "C" void fn_80033DC0(Unk80033BCC* self, int a)
{
    if (self->mD8 == 0)
        fn_800233B4(self, 0x1B, 0x1E, a);
}

extern "C" void fn_80033DF8(Unk80033BCC* self)
{
    if (self->mD8 == 0) {
        float f = 0.45f;
        Unk8002D15C_Owner* o = self->m80[0];
        if (o != 0)
            f = fn_8017FA08((int)o->m700 + 0x24);
        self->mD8 = 1;
        if (self->mD0 == -1)
            self->mD0 = fn_800412AC(fn_8004072C(), 0x2D, 0, 0, 0, 0);
        fn_8005AF00(fn_8005ACE4(), 0);
        self->mDC = 1;
    }
}

extern "C" int fn_80033E98(Unk80033BCC* self)
{
    int n = 0;
    for (int i = 0; i < 3; i++) {
        if (self->m80[i] != 0)
            n++;
    }
    return n;
}
extern "C" void fn_80033ECC(Unk80033BCC* self, int i, int id, Unk8002D15C_Msg* msg)
{
    if (self->m80[i] != 0) {
        switch (id) {
        case 0x10:
        case 0x31:
        case 0x32:
        case 0x3A:
        case 0x3B:
        case 0x45:
            break;
        case 0x22:
            fn_80034028(self, i, (Unk8002F894_Ev*)msg);
            break;
        case 0x3D: {
            Unk8002D15C_Cc* c = self->m80[i]->m6CC;
            self->mBC[i] = c;
            fn_80034234(self, self->m80[i], c, (int)(c->m3F8 * 0.016666668f));
            break;
        }
        case 0x58:
            fn_80034144(self, i, msg);
            break;
        case 0x2B:
            self->mCC = self->mCC + 1;
            if (self->mCC == fn_80033E98(self) && self->mD8 == 0)
                fn_80033DC0(self, i);
            break;
        case 0x36:
            self->mCC = self->mCC - 1;
            break;
        }
    }
}

extern "C" void fn_80034028(Unk80033BCC* self, int i, Unk8002F894_Ev* ev)
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

extern "C" void fn_80034144(Unk80033BCC* self, int i, Unk8002D15C_Msg* msg)
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

extern "C" void fn_80034234(Unk80033BCC* self, Unk8002D15C_Owner* o, Unk8002D15C_Cc* c, int n)
{
    int a;
    int b;
    fn_800222B4(o, &a, &b, c->m60);
    if (c != o->m6CC)
        a = 0xA;
    fn_800412AC(fn_8004072C(), 0x2C, a, b, n, 0);
}

extern "C" void fn_800342C8(void* self, float f)
{
}

extern "C" void fn_800342D8(void* self, float f)
{
}

extern "C" void fn_800342E8(Unk80033BCC* self)
{
    if (self->mD4 == 1 && self->mB4 != 0) {
        for (int i = 0; i <= 9; i++) {
            if (self->m0[i].m4 != 0) {
                int t = self->m0[i].m4 - 1;
                self->m0[i].m4 = t;
                if (t == 0) {
                    for (int j = 0; j <= 0; j++) {
                        if (lbl_80616BF4[j].id == self->m0[i].m0) {
                            (self->*lbl_80616BF4[j].h)(i);
                            break;
                        }
                    }
                    self->mB4 = self->mB4 - 1;
                }
            }
        }
    }
}

extern "C" void fn_80034404(Unk80033BCC* self)
{
    int a = self->mC8;
    int b = a & 1;
    if (b == 0 && self->mD8 == 1) {
        if (a == 0)
            fn_8005AF00(fn_8005ACE4(), 0);
    }
    for (int i = 0; i < 10; i++)
        self->m0[i].m4 = 0;
    self->mB4 = 0;
    self->mC8 = self->mC8 + 1;
}
extern "C" Unk80034488* fn_80034488(Unk80034488* self)
{
    fn_80021A60(self);
    self->SetVptr(lbl_80649798);
    self->mC4 = -1;
    self->mBC = 0;
    self->mC0 = 0;
    self->mC8 = 0;
    self->mCC = 0;
    self->mD0 = 0;
    self->mD4 = 0;
    int r = fn_8001CC40(fn_8001C394(), 7);
    if (r == 1)
        self->mC8 = r;
    return self;
}

extern "C" void fn_80034500(Unk80034488* self, int chrg)
{
    self->SetVptr(lbl_80649798);
    fn_8005B58C(fn_8005ACE4(), 0);
    if (self->mC4 != -1)
        fn_8004181C(fn_8004072C(), 0x2D, self->mC4, 0, 0, 0, 0);
    for (int i = 0; i < 3; i++) {
        if (self->m80[i] != 0)
            self->m80[i] = 0;
    }
    fn_80021BB4(self, chrg);
}

extern "C" int fn_800345A8(Unk80034488* self, Unk8002D15C_Owner* o)
{
    int idx = -1;
    for (int i = 0; i <= 2; i++) {
        if (self->m80[i] == 0) {
            self->m80[i] = o;
            idx = i;
            if (self->m7C < idx)
                self->m7C = idx;
            break;
        }
    }
    return idx;
}

extern "C" void fn_80034610(Unk80034488* self, int i)
{
    if (self->m80[i] != 0) {
        self->m80[i] = 0;
        for (int j = 0; j < 3; j++) {
            if (self->m80[j] != 0)
                self->m7C = j;
        }
    }
}

extern "C" void fn_8003465C(Unk80034488* self, int a)
{
    if (self->mCC == 0)
        fn_800233B4(self, 0x1B, 0x1E, a);
}

extern "C" void fn_80034694(Unk80034488* self)
{
    if (self->mCC == 0) {
        float f = 0.45f;
        Unk8002D15C_Owner* o = self->m80[0];
        if (o != 0)
            f = fn_8017FA08((int)o->m700 + 0x24);
        self->mCC = 1;
        if (self->mC4 == -1)
            self->mC4 = fn_800412AC(fn_8004072C(), 0x2D, 0, 0, 0, 0);
        fn_8005AF00(fn_8005ACE4(), 0);
        self->mD0 = 1;
    }
}

extern "C" int fn_80034734(Unk80034488* self)
{
    int n = 0;
    for (int i = 0; i < 3; i++) {
        if (self->m80[i] != 0)
            n++;
    }
    return n;
}

extern "C" void fn_80034768(Unk80034488* self, int i, int id, Unk8002D15C_Msg* msg)
{
    if (self->m80[i] != 0) {
        switch (id) {
        case 0x31:
        case 0x32:
        case 0x3F:
        case 0x45:
        case 0x49:
            break;
        case 0x58:
            fn_80034854(self, i, msg);
            break;
        case 0x2B:
            self->mC0 = self->mC0 + 1;
            if (self->mC0 == fn_80034734(self) && self->mCC == 0)
                fn_8003465C(self, i);
            break;
        case 0x36:
            self->mC0 = self->mC0 - 1;
            break;
        }
    }
}

extern "C" void fn_80034854(Unk80034488* self, int i, Unk8002D15C_Msg* msg)
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

extern "C" void fn_80034944(void* self, float f)
{
}

extern "C" void fn_80034954(void* self, float f)
{
}

extern "C" void fn_80034964(Unk80034488* self)
{
    if (self->mC8 == 1) {
        if (self->mD0 != 0) {
            if (fn_802D7DB4(0, 0x107))
                fn_8005B9D4(fn_8005ACE4(), 0);
        }
        int k = fn_802D7DB4(0, 0x108);
        if (k != 0) {
            if (self->mD4 == 0) {
                if (self->mD0 == 1)
                    fn_8005B58C(fn_8005ACE4(), 0);
                else
                    fn_8005AF00(fn_8005ACE4(), 0);
                self->mD4 = 1;
                self->mD0 = self->mD0 ^ 1;
            }
        } else {
            self->mD4 = k;
        }
        if (self->mB4 != 0) {
            for (int i = 0; i <= 9; i++) {
                if (self->m0[i].m4 != 0) {
                    int t = self->m0[i].m4 - 1;
                    self->m0[i].m4 = t;
                    if (t == 0) {
                        for (int j = 0; j <= 0; j++) {
                            if (lbl_80616C00[j].id == self->m0[i].m0) {
                                (self->*lbl_80616C00[j].h)(i);
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

extern "C" void fn_80034B10(Unk80034488* self)
{
    int a = self->mBC;
    int b = a & 1;
    if (b == 0 && self->mCC == 1) {
        if (a == 0)
            fn_8005AF00(fn_8005ACE4(), 0);
    }
    for (int i = 0; i < 10; i++)
        self->m0[i].m4 = 0;
    self->mB4 = 0;
    self->mBC = self->mBC + 1;
}

extern "C" Unk80034B94* fn_80034B94(Unk80034B94* self, int a)
{
    self->mC = lbl_80649D70;
    self->m0 = -1;
    self->m4 = a;
    self->m8 = 0;
    return self;
}
