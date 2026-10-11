/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8005D268-0x8005DF2C only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80052794.h"

float fn_8005D268(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    void* p = fn_80057074(self, b);
    if (fn_803440F0(p, obj->m3B0->m704) != 0) {
        return lbl_805ADCE0;
    }
    return lbl_805ADCE4;
}

float fn_8005D2C0(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    void* p = fn_80057074(self, b);
    if (fn_803440F0(p, obj->m3B0->m704) > 2) {
        return lbl_805ADCE8;
    }
    return lbl_805ADCEC;
}

float fn_8005D318(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    void* p = fn_800570D8(self, b);
    if (fn_80344138(p, obj->m130->m704) != 0) {
        return lbl_805ADCF0;
    }
    return lbl_805ADCF4;
}

float fn_8005D370(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    void* p = fn_800570D8(self, b);
    if (fn_80344138(p, obj->m130->m704) > 2) {
        return lbl_805ADCF8;
    }
    return lbl_805ADCFC;
}

float fn_8005D3C8(void)
{
    return lbl_805ADD00;
}

float fn_8005D3D4(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    if (obj->m118 != 0 || obj->m120 != 0) {
        return lbl_805ADD04;
    }
    return lbl_805ADD08;
}

float fn_8005D404(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    float v = lbl_805ADD0C;
    if (obj->m118 != 0) {
        v = lbl_805ADD10;
    }
    return v;
}

/* near-miss: same compares and constants as retail, but the two int-to-float
 * conversions come out in the opposite order (about 25 slots differ). */
float fn_8005D438(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    if (!((float)obj->m0 <= (float)obj->m130->m44C->m6F8->m10->m1C * lbl_805ADD28) && !((float)obj->m0 <= (float)obj->m130->m44C->m6F8->m10->m1C * lbl_805ADD30)) {
        return lbl_805ADD34;
    }
    return lbl_805ADD2C;
}

/* near-miss: same compares and constants as retail, but the two int-to-float
 * conversions come out in the opposite order (about 25 slots differ). */
float fn_8005D4E4(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    if (!((float)obj->m0 < (float)obj->m130->m44C->m6F8->m10->m1C * lbl_805ADD48) && !((float)obj->m0 > (float)obj->m130->m44C->m6F8->m10->m1C * lbl_805ADD4C)) {
        return lbl_805ADD50;
    }
    return lbl_805ADD54;
}

/* near-miss: same compares and constants as retail, but the two int-to-float
 * conversions come out in the opposite order (about 25 slots differ). */
float fn_8005D588(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    if (!((float)obj->m0 < (float)obj->m130->m44C->m6F8->m10->m1C * lbl_805ADD68)) {
        return lbl_805ADD6C;
    }
    if (!((float)obj->m0 >= (float)obj->m130->m44C->m6F8->m10->m1C * lbl_805ADD70)) {
        return lbl_805ADD78;
    }
    return lbl_805ADD74;
}

float fn_8005D63C(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    float v = lbl_805ADD7C;
    if (obj->m118 != 0 && obj->m110 == 0) {
        v = lbl_805ADD80;
    }
    return v;
}

float fn_8005D67C(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    if (obj->m50 == 0) {
        return lbl_805ADD84;
    }
    return lbl_805ADD88;
}

float fn_8005D6A0(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    if (obj->m38 == 0) {
        return lbl_805ADD8C;
    }
    return lbl_805ADD90;
}

float fn_8005D6C4(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    fn_8005D6A0(self, a, b, obj);
    return fn_8005CE4C(self);
}

float fn_8005D6F8(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    Unk80052794_S130* o = obj->m130;
    int t = fn_80045F28(fn_8025454C(&fn_801A497C(o->m44C, obj->m3B4 == 0, 6)->m588, 0xE));
    if (t == 1 || t == 4) {
        return lbl_805ADD94;
    }
    return lbl_805ADD98;
}

float fn_8005D764(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    Unk80052794_S130* o = obj->m130;
    int t = fn_80045F28(fn_8025454C(&fn_801A497C(o->m44C, obj->m3B4 == 0, 7)->m588, 0xE));
    if (t == 1 || t == 4) {
        return lbl_805ADD9C;
    }
    return lbl_805ADDA0;
}

float fn_8005D7D0(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    Unk80052794_S130* o = obj->m130;
    int t = fn_80045F28(fn_8025454C(&fn_801A497C(o->m44C, obj->m3B4 == 0, 8)->m588, 0xE));
    if (t == 1 || t == 4) {
        return lbl_805ADDA4;
    }
    return lbl_805ADDA8;
}

float fn_8005D83C(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    if (obj->m278 > 5) {
        return lbl_805ADDAC;
    }
    return lbl_805ADDB0;
}

float fn_8005D860(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    if (obj->m2C0[obj->m130->m708] > 0xA) {
        return lbl_805ADDB4;
    }
    return lbl_805ADDB8;
}

float fn_8005D894(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    Unk80052794_S130* o = obj->m130;
    Unk80052794_S3B0* x = fn_801A4B7C(o->m44C, 1, 1);
    int ok = fn_8005CDC4(self, obj);
    int k = obj->m3CC;
    if (k == 3 && obj->m3D0 <= 1) {
        return lbl_805ADDC0;
    }
    if (k == 2 && obj->m3D0 == 0 && obj->m108 > 0 && ok != 0) {
        char* p = &x->mA0C;
        if (!(fn_8024F20C(p, x->mA04, x->m44C, x->m708, 1) + fn_8024F048(p, x->mA04, x->m44C, x->m708, 1) < lbl_805ADDBC)) {
            return lbl_805ADDC0;
        }
    }
    return lbl_805ADDC4;
}

float fn_8005D98C(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    int i = obj->m130->m708;
    if (obj->m2F0[i] + obj->m2E8[i] > 0x32 && obj->m3CC > (int)(2.0f * (float)obj->m3D0)) {
        return lbl_805ADDD0;
    }
    return lbl_805ADDD4;
}

void fn_8005DA1C(Unk80052794_Obj* obj, int* o1, int* o2, int* o3, int* o4)
{
    Unk80052794_S130* o = obj->m130;
    int key = o->m704;
    int p = o->m44C->m6F8->mC->mC;
    int n = fn_8008838C(p, key, o->m708);
    int hist[16];
    for (int k = 0; k < 16; k++) {
        hist[k] = 0;
    }
    int i = 0x10;
    int cnt;
    *o1 = 0;
    cnt = 0;
    *o3 = -1;
    *o2 = i;
    *o4 = i;
    i = n - 1;
    for (; i >= 0 && cnt <= 0x31; i--) {
        if (fn_80088F84(p, i) == key) {
            int v = fn_80088FFC(p, i);
            int old = *o1;
            hist[v]++;
            if (hist[v] > old) {
                *o3 = old;
                cnt++;
                *o1 = hist[v];
                *o4 = *o2;
                *o2 = v;
            }
        }
    }
}

float fn_8005DB20(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    float v = lbl_805ADDD8;
    Unk80052794_S130* o = obj->m130;
    int p = o->m44C->m6F8->mC->mC;
    if (fn_8008838C(p, o->m704, o->m708) == 0x32) {
        int s0;
        int s4;
        int s8;
        int sC;
        fn_8005DA1C(obj, &s0, &s4, &s8, &sC);
        if (fn_80088FFC(p, -1) == s4 && !((float)s0 < 2.0f * (float)s8)) {
            v = lbl_805ADDE8;
        }
    }
    return v;
}

float fn_8005DC14(void)
{
    float v = lbl_805ADDEC;
    fn_800B555C();
    if (fn_800B57EC() != 0) {
        v = lbl_805ADDF0;
    }
    return v;
}

float fn_8005DC5C(void)
{
    float v = lbl_805ADDF4;
    fn_800B555C();
    if (fn_800B57EC() == 0) {
        v = lbl_805ADDF8;
    }
    return v;
}

float fn_8005DCA4(Unk80052794_Ctx** pp)
{
    Unk80052794_Ctx* c = *pp;
    if (fn_8004FF78(c, c->m9D8, 0x4E) >= 0) {
        return lbl_805ADDFC;
    }
    return lbl_805ADE00;
}

float fn_8005DCEC(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    int ok = fn_8005CDC4(self, obj);
    float x = fn_8025454C(&obj->m3B0->m588, 0xD);
    float y = fn_8025454C(&obj->m3B0->m588, 0xC);
    if (obj->m104 == 0 && ok != 0 && !(x < lbl_805ADE04) && !(y < lbl_805ADE04) && obj->m0 > 1 && obj->m4D4 <= 1 && obj->m3D0 <= 1) {
        return lbl_805ADE08;
    }
    return lbl_805ADE0C;
}

float fn_8005DDB4(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    int sp[2];
    int t = fn_80044D90(obj->m130->m44C->m6F8->m10->m1C, obj->m0);
    fn_8001CEA8(obj, &sp[1], &sp[0]);
    int ok = fn_8005CDC4(self, obj);
    if (t == 4 && ok != 0 && obj->m4D4 <= 1 && obj->m3D0 <= 1 && obj->m110 != 0 && obj->m118 == 0 && obj->m120 == 0) {
        return lbl_805ADE10;
    }
    return lbl_805ADE14;
}

float fn_8005DE7C(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    void* p = fn_80057074(self, 1);
    if (fn_803440F0(p, obj->m3B0->m704) != 0) {
        return lbl_805ADE18;
    }
    return lbl_805ADE1C;
}

float fn_8005DED4(Unk80057204_Mgr* self, int a, int b, Unk80052794_Obj* obj)
{
    void* p = fn_80057074(self, 2);
    if (fn_803440F0(p, obj->m3B0->m704) != 0) {
        return lbl_805ADE20;
    }
    return lbl_805ADE24;
}
