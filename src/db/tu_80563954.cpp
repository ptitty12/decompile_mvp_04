/*
 * Database overlay code, .database_codeoverlay 0x80563954-0x80565FD4 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8054FA04.h"
#include "game/clampiter.h"
extern "C" int fn_805668F0(Db80565CDC_S* self, int y);
extern "C" void fn_8052BAA8(Unk8052B978_Tbl* self, int v);
extern "C" void fn_8052BAFC(Unk8052B978_Tbl* self, int v);
extern "C" void fn_8052BB50(Unk8052B978_Tbl* self, int v);
extern "C" void fn_8052BBA4(Unk8052B978_Tbl* self, int v);
extern "C" void fn_8052C1C8(Unk8052B978_Tbl* self);
extern "C" void fn_805652E8(Unk8007B2B0_Screen** pp, Unk8052B978_Tbl* tb, int a);
extern float lbl_805FF878;
extern float lbl_805FF888;
/* Source object (lbl_8061930C): four ints from +0xC copied into the singleton (fn_80564D40). */
struct Db80564D40_Src {
    char pad0[0xC];
    int mC[4];
};
/* Singleton (lbl_80622D88 holds it, lbl_80622D8C counts it; dtor fn_80564E28): m0 source, m4 flag,
 * constants at +8..+0x24, four ints at +0x28 (fn_80564D40). */
struct Db80564D40_S {
    Db80564D40_Src* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28[4];
};
extern Db80564D40_Src* lbl_8061930C;
/* lbl_80619948 as read by fn_805652E8: only the table-set pointer at +0x28. */
struct Db80619948_G {
    char pad0[0x28];
    Unk8052B978_Tbl** m28;
};
extern Db80619948_G* lbl_80619948;
extern "C" int fn_800B548C();
int fn_80075CC0(int a);
int fn_80076104(int a, int b, int c);
int fn_80084408(int a);
int fn_80084458(int a);

extern "C" int fn_80565D48(Db80565CDC_S* s);
extern "C" int fn_80565DDC(Db80565CDC_S* s);
extern "C" int fn_8056AC74(Unk8052B978_Tbl** t, Unk8052B978_Tbl* tb, int idx);
extern "C" int fn_80565E9C(Db80565CDC_S* s);
extern "C" int fn_80568D64(Db80565CDC_S* s, int a, int b, int c);
extern "C" float fn_80563954(float f);
extern "C" Unk8007F198_S12 fn_8052BD58(Unk8052B978_Tbl* t);
extern "C" void fn_805650DC(Db80565CDC_S* s, int y);
extern "C" int fn_8056516C(Db80565CDC_S* s, int y);
extern "C" void* fn_800B555C();
extern "C" int fn_800B57EC(void* p);
extern "C" int fn_80565448(Db80565CDC_S* s, int a);
extern "C" int fn_805656A0(Db80565CDC_S* s, int a);
extern "C" int fn_805658F8(Db80565CDC_S* s, int a);
extern "C" int fn_80565A50(Db80565CDC_S* s, int a);
extern "C" void fn_80377408(void* p);
extern float lbl_805FF864;
extern float lbl_805FF868;
extern float lbl_805FF86C;
extern float lbl_805FF870;
extern float lbl_805FF874;
extern float lbl_805FF8A4;
extern float lbl_805FF914;
extern int lbl_80622D88;
extern int lbl_80622D8C;
/* fn_80563F0C initializes the 0x20-byte state; fn_80564C9C compares the id at +0,
 * float threshold at +4 and unsigned counter at +0xC. */
struct Db80563F0C_S {
    int m0;
    float m4;
    float m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
};

extern "C" int fn_80555EB0(int k, int i);
extern "C" int fn_80555F18(int k, int i);

extern "C" void fn_8052BA70(Unk8052B978_Tbl* self);
extern "C" void fn_8052BBF8(Unk8052B978_Tbl* self, int idx);
extern "C" void fn_8052BC4C(Unk8052B978_Tbl* self, int v);
extern "C" int fn_805668A4(Db80565CDC_S* self, int y);
void fn_802B8D74();
void fn_802B8DDC();

/* near-miss: 17 slots, register allocation of the loop (retail keeps the index in r31 starting at 4 and self in r28) */
inline Unk8052B978_Tbl* Db805650DC_At(Db80565CDC_S* s, int off)
{
    char* b = (char*)s + 0x28;
    return *(Unk8052B978_Tbl**)(b + off);
}

/* forward declarations (definitions are in address order) */
extern "C" int fn_80563B4C(float f);
extern "C" float fn_80563BA0(int a);
extern "C" void fn_80563F0C(Db80563F0C_S* s);
extern "C" void fn_80564A98(Db80563F0C_S* s);
extern "C" void fn_80564E28(void* self, int chrg);
extern "C" void fn_80564E6C(Db80565CDC_S* s);
extern "C" void fn_8056503C(Db80565CDC_S* s);
extern "C" void fn_80565090(Db80565CDC_S* s);
extern "C" void fn_805650DC(Db80565CDC_S* self, int y);
extern "C" int fn_805653B4(Db80565CDC_S* s, int a, int b, int c, int d);
extern "C" int fn_80565BFC(Db80565CDC_S* s);
extern "C" int fn_80565C70(Db80565CDC_S* s, int k);
extern "C" int fn_80565CDC(Db80565CDC_S* s);
extern "C" int fn_80565D48(Db80565CDC_S* self);
extern "C" int fn_80565DDC(Db80565CDC_S* self);
extern "C" int fn_80565E9C(Db80565CDC_S* self);
struct Db80564910_B1 {
    int* m0;
    unsigned m4;
    unsigned m8;
    int mC;
    const void* vp;
    int m14;
    Db80564910_B1(int* buf, int cap)
    {
        vp = lbl_8064B298;
        m0 = buf;
        m8 = cap;
        fn_8040074C(m0, m8 << 2);
    }
    ~Db80564910_B1() { vp = lbl_8064A550; }
};
struct Db80564910_B2 : Db80564910_B1 {
    Db80564910_B2(int* buf, int cap) : Db80564910_B1(buf, cap)
    {
        m4 = 0;
        mC = 0;
        vp = lbl_8064A550;
        fn_8040074C(m0, m8 << 2);
    }
    ~Db80564910_B2() { vp = lbl_8064A550; }
};
struct Db80564910_B3 : Db80564910_B2 {
    int buf[0x28];
    Db80564910_B3() : Db80564910_B2(buf, 0x28)
    {
        m14 = 0;
        m4 = 0;
        mC = 0;
        vp = lbl_8064A4C8;
    }
    ~Db80564910_B3() { vp = lbl_8064A550; }
};
extern "C" void fn_80535650(Unk805352B0_List* self, int x);
extern "C" void fn_805371C4(Unk805352B0_List* self, unsigned f);
extern char lbl_8064A2A8[];

extern "C" DB_OVERLAY int fn_80563B4C(float f)
{
    volatile float pad;
    float r = fn_80563954(f);
    return (int)((r - lbl_805FF864) / lbl_805FF868);
}

extern "C" DB_OVERLAY float fn_80563BA0(int a)
{
    float r;
    if (a == 0 || a == 10)
        r = lbl_805FF86C;
    else if ((unsigned)(a - 1) <= 4)
        r = lbl_805FF870;
    else
        r = lbl_805FF874;
    return r;
}

extern "C" DB_OVERLAY float fn_80563BF0(int a, int b, float* c)
{
    float r = lbl_805FF878;
    float fa = (float)a;
    float fb = (float)b;
    r = r + c[0];
    float b2 = fb * fb;
    r = c[1] * fb + r;
    r = c[2] * b2 + r;
    float b3 = b2 * fb;
    float b4 = b2 * b2;
    r = c[3] * b3 + r;
    r = c[4] * b4 + r;
    r = c[5] * fa + r;
    r = c[6] * fa * fb + r;
    r = c[7] * fa * b2 + r;
    r = c[8] * fa * b3 + r;
    r = c[9] * fa * b4 + r;
    return r + lbl_805FF888;
}

/* near-miss: retail's ctor-shaped bodies copy r3 (mr r9,r3) and load the float in r11 (one more insn).
 * Tried an inline method and a placement-new constructor. */
extern "C" DB_OVERLAY void fn_80563F0C(Db80563F0C_S* s)
{
    s->m0 = 0;
    s->m1C = 0;
    s->m8 = s->m4 = lbl_805FF8A4;
    s->mC = 0;
    s->m10 = 0;
    s->m18 = 0;
}

/* near-miss: 99.4%; callee-saved r28/r29 swapped between the list element and the zero/offset register. */
extern "C" DB_OVERLAY void fn_80564910()
{
    Unk80535650_Tmp t;
    int buf[0x82];
    Unk80535650_Tmp* q = &t;
    q->C1(buf, 0x82);
    q->C2();
    q->C3(lbl_8064A2A8);
    fn_805371C4((Unk805352B0_List*)q, 0x01F80000);
    if ((int)q->m4 > 0) {
        int n = q->m4;
        int off = 0;
        do {
            int e = *(int*)((char*)t.m0 + off);
            int off2 = 0;
            Db80564910_B3 b;
            fn_80535650((Unk805352B0_List*)&b, e);
            if ((int)b.m4 > 0) {
                int m = b.m4;
                do {
                    ((Unk8007A4DC_Screen*)lbl_8061930C)->fn_8007A808(0x18, *(int*)((char*)b.m0 + off2), 0);
                    off2 += 4;
                    m--;
                } while (m != 0);
            }
            off += 4;
            n--;
        } while (n != 0);
    }
    q->D();
}

/* near-miss: same (8 vs 9 insns). */
extern "C" DB_OVERLAY void fn_80564A98(Db80563F0C_S* s)
{
    s->m0 = 0;
    s->m8 = lbl_805FF914;
    s->mC = 0;
    s->m4 = lbl_805FF914;
}

extern "C" DB_OVERLAY int fn_80564C9C(Db80563F0C_S* s, float value, float unused3, int unused, int id, int unused2, unsigned count)
{
    int result = 0;
    if (s->m0 == id) {
        if (!(value >= s->m4)) {
            if (count > (unsigned)s->mC) {
                float scale = (float)(int)(count - s->mC) * 0.1f + 1.0f;
                float adjusted = value * scale;
                if (!(adjusted < s->m4))
                    result = 1;
            }
        } else {
            result = 1;
        }
    }
    return result;
}

extern "C" DB_OVERLAY Db80564D40_S* fn_80564D40(Db80564D40_S* s)
{
    if (lbl_80622D88 != 0) {
        if (s != 0)
            fn_80564E28(s, 3);
    } else {
        lbl_80622D88 = (int)s;
        lbl_80622D8C = lbl_80622D8C + 1;
        s->m0 = lbl_8061930C;
        Unk8006A138_It<3> it(0);
        int k = 0;
        do {
            s->m28[k] = s->m0->mC[k];
            k = it.Next();
        } while (k <= 3);
        s->m4 = 1;
        s->m20 = 3;
        s->m8 = 5;
        s->mC = 7;
        s->m10 = 7;
        s->m14 = 5;
        s->m18 = 5;
        s->m24 = 5;
        s->m1C = 7;
    }
    return s;
}

extern "C" DB_OVERLAY void fn_80564E28(void* self, int chrg)
{
    lbl_80622D88 = 0;
    lbl_80622D8C = lbl_80622D8C - 1;
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_80564E6C(Db80565CDC_S* s)
{
    if (fn_800B57EC(fn_800B555C()) == 1)
        fn_8056516C(s, 0x7D5);
}

extern "C" DB_OVERLAY void fn_8056503C(Db80565CDC_S* s)
{
    int key = fn_8052BD58(s->m28).w0;
    fn_805650DC(s, fn_80329FA0(key).m2 + 1);
}

extern "C" DB_OVERLAY void fn_80565090(Db80565CDC_S* s)
{
    fn_8056516C(s, fn_80329FA0(*(unsigned short*)s->m28->m8).m2);
}

extern "C" DB_OVERLAY void fn_805650DC(Db80565CDC_S* self, int y)
{
    fn_802B8D74();
    int i;
    for (i = 0; i < 3; i++)
        fn_8052BA70(Db805650DC_At(self, i * 4 + 4));
    Unk8052B978_Tbl* t = *(Unk8052B978_Tbl**)((char*)self + 0x28);
    int h = fn_805668A4(self, (unsigned short)y);
    y -= 0x7D5;
    fn_8052BBF8(t, y % 2);
    fn_8052BC4C(t, h);
    fn_802B8DDC();
}

extern "C" DB_OVERLAY void fn_805652E8(Unk8007B2B0_Screen** pp, Unk8052B978_Tbl* tb, int a)
{
    unsigned i = 0;
    fn_80076104(fn_80075CC0(a), 0, 0);
    int k = fn_800B548C();
    int g = (*pp)->fn_8007B8C4(0, k);
    int v1 = fn_80084408(g);
    int v2 = fn_80084458(g);
    unsigned n = tb->m4;
    Unk8052B978_Tbl** t = lbl_80619948->m28;
    for (; i < n; i++) {
        if (fn_8056AC74(t, tb, i) == 1) {
            *(int*)((char*)tb->m8 + i * 0x1C + 4) = v1;
            *(int*)((char*)tb->m8 + i * 0x1C + 0x10) = v2;
        }
    }
}

extern "C" DB_OVERLAY int fn_805653B4(Db80565CDC_S* s, int a, int b, int c, int d)
{
    int r0 = fn_80565448(s, a);
    int r1 = fn_805656A0(s, b);
    int r2 = fn_805658F8(s, c);
    int r3 = fn_80565A50(s, d);
    int ok = 0;
    if (r0 && r1 && r2 && r3)
        ok = 1;
    return ok;
}

extern "C" DB_OVERLAY int fn_80565BFC(Db80565CDC_S* s)
{
    Unk8006A138_It<3> it(0);
    int k = 0;
    do {
        if (fn_80565C70(s, k) == 0)
            return 0;
        k = it.Next();
    } while (k <= 3);
    return 1;
}

extern "C" DB_OVERLAY int fn_80565C70(Db80565CDC_S* s, int k)
{
    switch (k) {
    case 0:
        return fn_80565CDC(s);
    case 1:
        return fn_80565D48(s);
    case 2:
        return fn_80565DDC(s);
    case 3:
        return fn_80565E9C(s);
    }
    return 1;
}

extern "C" DB_OVERLAY int fn_80565CDC(Db80565CDC_S* s)
{
    int a = s->m8 * 4 + s->mC * 2;
    int b = s->m10;
    if (s->m28->m4 >= (unsigned)(a + b)) {
        if (fn_80568D64(s, a, b, 0) != 0)
            return 1;
        return 0;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_80565D48(Db80565CDC_S* self)
{
    int n = self->m14;
    int res = 0;
    int c = n * 4;
    if (self->m2C->m4 >= (unsigned)(c + (n + n))) {
        int a = fn_80568D64(self, c, n, 1);
        int b = fn_80568D64(self, c | 1, n, 1);
        int t = 0;
        if (a != 0 && b != 0)
            t = 1;
        res = t;
    }
    return res;
}

extern "C" DB_OVERLAY int fn_80565DDC(Db80565CDC_S* self)
{
    int n = *(int*)((char*)self + 0x18);
    int k = *(int*)((char*)self + 0x1C);
    int res = 0;
    int c = (n + n + n) * 2;
    if ((*(Unk8052B978_Tbl**)((char*)self + 0x30))->m4 >= (unsigned)(c + (n + n + k))) {
        int a = fn_80568D64(self, c, n, 2);
        int b = fn_80568D64(self, c + 1, n, 2);
        int d = fn_80568D64(self, c + 2, k, 2);
        int t = 0;
        if (a != 0 && b != 0 && d != 0)
            t = 1;
        res = t;
    }
    return res;
}

extern "C" DB_OVERLAY int fn_80565E9C(Db80565CDC_S* self)
{
    int p0 = fn_80555EB0(0, 3) * fn_80555F18(0, 7);
    int p1 = fn_80555EB0(1, 3) * fn_80555F18(1, 7);
    int s = p0 + p1;
    int p2 = fn_80555EB0(2, 3) * fn_80555F18(2, 7);
    int t = s + p2;
    int res = 0;
    if ((*(Unk8052B978_Tbl**)((char*)self + 0x34))->m4 >= (unsigned)t) {
        int a = fn_80568D64(self, s, fn_80555F18(2, 7), 3);
        int b = fn_80568D64(self, s + 1, fn_80555F18(2, 8), 3);
        int c = fn_80568D64(self, s + 2, fn_80555F18(2, 9), 3);
        int r = 0;
        if (a != 0 && b != 0 && c != 0)
            r = 1;
        res = r;
    }
    return res;
}

/* fn_805658F8: host vptr +0xDBC, row-set vptr +0x10, row status +0x20. */
struct Db805658F8_Row { int m0; char pad4[0xC]; float m10; char pad14[8]; int m1C; int m20; };
class Db805658F8_Rows { public: char pad0[0x10];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual Db805658F8_Row* v21(int);
};
class Db805658F8_Host { public: char pad0[0xDBC];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Db805658F8_Rows* v4(int);
    virtual Db805658F8_Rows* v5(int);
    virtual void v6();
    virtual void v7();
    virtual Db805658F8_Rows* v8(int);
    virtual Db805658F8_Rows* v9(int);
    virtual Db805658F8_Rows* v10(int);
};
extern "C" int fn_8052BD40(Unk8052B978_Tbl*);
extern "C" int fn_80084954__FPv(void*);
extern "C" DB_OVERLAY int fn_805658F8(Db80565CDC_S* self,int a)
{
    Unk8052B978_Tbl* t=*(Unk8052B978_Tbl**)((char*)self+0x30);
    int last=fn_8052BD40(t);
    int active=1;
    if(t->m8[last].f4==0) active=0;
    if(active==1) {
        Db805658F8_Host* host=(Db805658F8_Host*)a;
        Unk8006A138_It<25> it(13);
        int i=13;
        do {
            Db805658F8_Rows* rows=host->v8(i);
            if(rows->v21(0)->m20!=4) goto failure;
            if(fn_80084954__FPv((void*)it.v)==1) {
                if(host->v9(it.v)->v21(0)->m20!=4) goto failure;
            } else {
                if(rows->v21(1)->m20!=4) goto failure;
            }
            i=it.Next();
        } while(i<=18);
        return 1;
    }
    failure:return 0;
}

extern "C" int fn_80566570();
extern "C" int fn_80566520(Db80565CDC_S*);
extern "C" int fn_800A3AB0(void*);
extern "C" int fn_800A3AF4(void*);
extern "C" int fn_800A3B38(void*);
extern "C" int fn_800A3B7C(void*);
extern "C" void fn_80567338(Db80565CDC_S*,int,int);
extern "C" void fn_8056693C(Db80565CDC_S*,int,int,int,int);
extern "C" void fn_80568EA8(Db80565CDC_S*);
extern "C" void fn_80568F5C(Db80565CDC_S*);
extern "C" void fn_80569000(Db80565CDC_S*);
extern "C" void fn_80569094(Db80565CDC_S*);
extern "C" DB_OVERLAY void fn_80564EB0(Db80565CDC_S* self)
{
    if(fn_80566570()==1) {
        Unk8006A138_It<3> first(0);
        int maximum=-1;
        int i=0;
        do {
            Unk8052B978_Tbl* t=Db805650DC_At(self,i*4);
            int last=(int)t->m4-1;
            int off=last*28;
            int key=*(unsigned short*)(off+(unsigned)t->m8);
            if(maximum==-1 || key>maximum)maximum=key;
            i=first.Next();
        }while(i<=3);
        Unk8006A138_It<3> second(0);
        int j=0;
        do {
            fn_80567338(self,j,maximum+1);
            j=second.Next();
        }while(j<=3);
        return;
    }
    void* g=lbl_80619948;
    int a=fn_800A3AB0(g);
    int b=fn_800A3AF4(g);
    int c=fn_800A3B38(g);
    int d=fn_800A3B7C(g);
    if(fn_80566520(self)==1 && fn_805653B4(self,a,b,c,d)==1) {
        fn_8056693C(self,a,b,c,d);
        return;
    }
    if(fn_80566520(self)) {
        fn_80568EA8(self);fn_80568F5C(self);fn_80569000(self);fn_80569094(self);
    }
}

extern "C" int fn_8008499C__FPv(void*);
extern "C" DB_OVERLAY int fn_80565A50(Db80565CDC_S* self,int a)
{
    Unk8052B978_Tbl* t=*(Unk8052B978_Tbl**)((char*)self+0x34);
    int last=fn_8052BD40(t);
    int active=1;
    if(t->m8[last].f4==0) active=0;
    if(active==1) {
        Db805658F8_Host* host=(Db805658F8_Host*)a;
        Unk8006A138_It<25> it(19);
        int i=19;
        do {
            Db805658F8_Rows* rows=host->v8(i);
            if(rows->v21(0)->m1C!=0) goto failure;
            if(fn_80084954__FPv((void*)it.v)==1) {
                if(host->v9(it.v)->v21(0)->m1C!=0) goto failure;
                if(fn_8008499C__FPv((void*)it.v)==1) {
                    if(host->v10(it.v)->v21(0)->m1C!=2)goto failure;
                }
            } else {
                if(rows->v21(1)->m1C!=3) goto failure;
            }
            i=it.Next();
        } while(i<=24);
        return 1;
    }
    failure:return 0;
}

struct Db80563D3C_Six { int v[6]; };
extern const Db80563D3C_Six lbl_805FF88C;
extern float lbl_806022C0[][10];
extern signed char lbl_80602360[];
extern float lbl_8060236C[][10];
extern signed char lbl_8060240C[];
extern float lbl_80602418[][10];
extern signed char lbl_806024B8[];
extern "C" DB_OVERLAY int* fn_80563D3C(int* out,int id,int level,int age,int kind)
{
    int raw=level+1;
    Db80563D3C_Six map=lbl_805FF88C;
    Unk8007A4DC_Screen* sc=(Unk8007A4DC_Screen*)lbl_8061930C;
    int k=map.v[kind];
    int low=1;
    if(low<raw)low=raw;
    int n=low;
    if(n>5)n=5;
    int young=18;
    if(young<age)young=age;
    int a=young;
    if(a>44)a=44;
    int adjust=0;
    int limit;
    float* curve;
    signed char* result;
    if(sc->fn_8007A270(id)) {
        if(sc->fn_8007A6A0(5,id)==0) {
            curve=lbl_8060236C[k]; limit=9; result=lbl_8060240C;
        }else {
            curve=lbl_80602418[k]; result=lbl_806024B8;
            if(n<=1)adjust=-1;
            else if(n>2)adjust=1;
            limit=4;
        }
    }else {
        curve=lbl_806022C0[k]; limit=12; result=lbl_80602360;
    }
    int value=(int)fn_80563BF0(n,a,curve)+adjust;
    if(value<=limit) {if(value<0)value=0;} else value=limit;
    int selected=result[value];
    if(!sc->fn_8007A270(id) && (selected==8 || selected==4))selected++;
    *out=selected;
    return out;
}

extern "C" int fn_800845E4__Fi(int);
extern "C" int fn_8056B734(Unk8052B978_Tbl**,int);
extern float lbl_805FF948;
extern "C" DB_OVERLAY int fn_80565448(Db80565CDC_S* self,int a)
{
    float oldValue,oldBudget,change,newBudget;
    Unk8052B978_Tbl* t=self->m28;
    int last=fn_8052BD40(t);
    int active=1;
    if(t->m8[last].f4==0)active=0;
    if(active==1) {
        Db805658F8_Host* host=(Db805658F8_Host*)a;
        Unk8006A138_It<25> first(0);
        int i=0;
        do {
            if(host->v4(i)->v21(0)->m20!=4)goto failure;
            i=first.Next();
        }while(i<=5);
        Unk8006A138_It<10> second(0);
        int j=0;
        do {
            if(fn_800845E4__Fi(j)==1) {
                Db805658F8_Rows* rows=host->v5(second.v);
                int key=rows->v21(0)->m0;
                oldValue=rows->v21(0)->m10;
                oldBudget=(float)fn_8056B734(lbl_80619948->m28,key);
                int key2=rows->v21(1)->m0;
                change=rows->v21(1)->m10-oldValue;
                newBudget=(float)fn_8056B734(lbl_80619948->m28,key2);
                if(change<=(newBudget+oldBudget)*lbl_805FF948)goto failure;
            }
            j=second.Next();
        }while(j<=1);
        return 1;
    }
    failure:return 0;
}

extern float lbl_805FF958;
extern "C" DB_OVERLAY int fn_805656A0(Db80565CDC_S* self,int a)
{
    float oldValue,oldBudget,change,newBudget;
    Unk8052B978_Tbl* t=self->m2C;
    int last=fn_8052BD40(t);
    int active=1;
    if(t->m8[last].f4==0)active=0;
    if(active==1) {
        Db805658F8_Host* host=(Db805658F8_Host*)a;
        Unk8006A138_It<25> first(6);
        int i=6;
        do {
            if(host->v4(i)->v21(0)->m20!=4)goto failure;
            i=first.Next();
        }while(i<=12);
        Unk8006A138_It<10> second(2);
        int j=2;
        do {
            if(fn_800845E4__Fi(j)==1) {
                Db805658F8_Rows* rows=host->v5(second.v);
                int key=rows->v21(0)->m0;
                oldValue=rows->v21(0)->m10;
                oldBudget=(float)fn_8056B734(lbl_80619948->m28,key);
                int key2=rows->v21(1)->m0;
                change=rows->v21(1)->m10-oldValue;
                newBudget=(float)fn_8056B734(lbl_80619948->m28,key2);
                if(change<=(newBudget+oldBudget)*lbl_805FF958)goto failure;
            }
            j=second.Next();
        }while(j<=3);
        return 1;
    }
    failure:return 0;
}
