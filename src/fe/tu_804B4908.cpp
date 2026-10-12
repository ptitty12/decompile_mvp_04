/*
 * Front-end overlay code, .frontend_codeoverlay 0x804B4908-0x804B7C98 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804ABCBC.h"
extern "C" float fn_80592474(int h, int a, int i);
extern "C" int fn_80593088(int h, int a, int i);
extern int fn_8007F9B4(Unk8007F198_C* s);
extern "C" int fn_80592E04(int h, int i);
extern "C" int fn_800E52F8__Fi(int a);
extern "C" int fn_805931BC(int h, int a, int b, int c);
extern "C" float fn_80592F94(int h, int a, int b, int c);
class FeSub20 {
public:
    char pad0[0x24];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20(int a, int b);
};
extern "C" int fn_804B78A8(FeScr* x);
extern "C" int fn_804B79FC(FeScr* x);
extern "C" int sprintf(char* d, const char* f, ...);
extern "C" int fn_800A3C98(void* g, int a, int b);
extern "C" int fn_805901AC(int a, int b);
extern "C" int fn_800E1930__Fi(int a);
class FeObj4i : public UiBase {
public:
    FE_LO(FE_V0) virtual FeObj* v32(const char* a, int b);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42(int a, int b, int c, int d);
};
struct FeRct4 {
    float m0, m4, m8, mC;
    int m10;
};
class FeV14 {
public:
    char pad0[0xC];
    int mC;
    char pad10[4];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual int s5();
    virtual FeRct4* s6(int i);
};
extern "C" float fn_80594418(int h, int i);
extern "C" void fn_80594428(int h, int i, float v);
extern "C" int fn_80591A50(int h);
extern "C" int fn_80591AA0(int h);
extern "C" int fn_805934C0(int h, int a, int b, int c);

extern "C" void fn_804BB17C(FeCam* c, FeObj* w, int n);
extern "C" void fn_804BC414(FeCam* c, float a);
extern "C" void fn_804BC2B0(FeCam* c, float a, float b);
extern "C" int fn_804BB8B4(FeCam* c, int a);
extern "C" void fn_804BB780(FeCam* c, const char* s, int n);
extern "C" void fn_804BB58C(FeCam* c, char* s, int n);
extern "C" void fn_804BC42C(FeCam* c, int a, int b);
struct FeSt3 { int m0; int m4; int m8; };
extern "C" FeSt3* fn_805932E4(int a, int b, int c, int d);
extern "C" int fn_800B57EC();
extern "C" int fn_8056A5F4(int a, int b, int c, int d);
extern "C" int fn_8056A2F8(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern FeGame* lbl_80619948;

extern "C" FE_OVERLAY void fn_804B4908(FeScr* x)
{
    FeObj* z = 0;
    fn_800ECF18(x);
    fn_800C2034((char*)fn_800B555C() + 8, 0);
    ((FeObj1*)fn_800C8040(((FeObj*)x)->v32("TITLE", 1)))->v29(((FeV14*)FI(x, 0xE14))->s5());
    FeObj* t = fn_800C8040(((FeObj*)x)->v32("TITLE", 1));
    fn_800DD204(t, fn_800C8038(((FeObj*)x)->v32("SH1", 1)));
    FeObj4i* g = (FeObj4i*)fn_800C8060(fn_800C8044(((FeObj*)x)->v32("LASTFOUR", 1))->v32("LAST4", 1));
    g->v42(0, 0, 0x578E, 4);
    g->v42(0, 1, 0x5781, 4);
    g->v42(0, 2, 0x578F, 4);
    g->v42(0, 3, 0x578D, 4);
    x->m148 = z;
    x->m144 = fn_800B7AB8(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(x->m144, x);
    ((FeObj*)x)->v85();
    ((FeObj*)x)->v97();
    ((FeObj*)x)->v87();
    ((FeObj*)x)->v86();
    ((FeObj*)x)->v89();
}

extern "C" FE_OVERLAY void fn_804B4BC4(FeObj* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY void fn_804B4BEC(FeScr* x)
{
    char b8[0x68];
    char b70[0x38];
    int i = 0;
    ((FeObj2*)x->m134)->v79(((FeV14*)FI(x, 0xE14))->mC, 0);
    ((FeObj*)x->m134)->v3();
    ((FeObj1*)x->m134)->v88(1);
    FeV14* e = (FeV14*)FI(x, 0xE14);
    for (; i < e->mC; i++, e = (FeV14*)FI(x, 0xE14)) {
        ((FeObj4i*)x->m134)->v42(i, 0, ((FeV14*)FI(x, 0xE14))->s6(i)->m10, 5);
        ((char* (*)(char*, float, int, int))fn_800DF254)(b8, fn_80594418(FI(x, 0xE14), i), ((FeObjI*)x)->v98() == 1, 3);
        ((FeObjS43*)x->m134)->v43(i, 1, b8, 4);
        fn_800DF254(b8, 0, 3, fn_80592474(FI(x, 0xE18), ((FeObjI*)x)->v98(), i));
        ((FeObjS43*)x->m134)->v43(i, 4, b8, 5);
        if (fn_80591AA0(FI(x, 0xE18)) > 0) {
            sprintf(b70, "%d%%", fn_80593088(FI(x, 0xE18), ((FeObjI*)x)->v98(), i));
            fn_804031BC(b8, b70);
            ((FeObjS43*)x->m134)->v43(i, 3, b8, 5);
        } else {
            ((FeObj4i*)x->m134)->v42(i, 3, 0x1A4B, 5);
        }
    }
}

extern "C" FE_OVERLAY void fn_804B4E8C(FeScr* x, int i)
{
    char buf[0x68];
    float v = !(fn_80594418(FI(x, 0xE14), i) + ((FeV14*)FI(x, 0xE14))->s6(i)->m4 <= ((FeV14*)FI(x, 0xE14))->s6(i)->m8) ? ((FeV14*)FI(x, 0xE14))->s6(i)->m8 : !(fn_80594418(FI(x, 0xE14), i) + ((FeV14*)FI(x, 0xE14))->s6(i)->m4 >= ((FeV14*)FI(x, 0xE14))->s6(i)->mC) ? ((FeV14*)FI(x, 0xE14))->s6(i)->mC : fn_80594418(FI(x, 0xE14), i) + ((FeV14*)FI(x, 0xE14))->s6(i)->m4;
    fn_80594428(FI(x, 0xE14), i, v);
    ((char* (*)(char*, float, int, int))fn_800DF254)(buf, fn_80594418(FI(x, 0xE14), i), ((FeObjI*)x)->v98() == 1, 3);
    ((FeObjS43*)x->m134)->v43(i, 1, buf, 4);
    ((FeObj1*)x->m134)->v14(1);
}

extern "C" FE_OVERLAY void fn_804B50B8(FeScr* x, int i)
{
    char buf[0x68];
    float v = !(fn_80594418(FI(x, 0xE14), i) - ((FeV14*)FI(x, 0xE14))->s6(i)->m4 <= ((FeV14*)FI(x, 0xE14))->s6(i)->m8) ? ((FeV14*)FI(x, 0xE14))->s6(i)->m8 : !(fn_80594418(FI(x, 0xE14), i) - ((FeV14*)FI(x, 0xE14))->s6(i)->m4 >= ((FeV14*)FI(x, 0xE14))->s6(i)->mC) ? ((FeV14*)FI(x, 0xE14))->s6(i)->mC : fn_80594418(FI(x, 0xE14), i) - ((FeV14*)FI(x, 0xE14))->s6(i)->m4;
    fn_80594428(FI(x, 0xE14), i, v);
    ((char* (*)(char*, float, int, int))fn_800DF254)(buf, fn_80594418(FI(x, 0xE14), i), ((FeObjI*)x)->v98() == 1, 3);
    ((FeObjS43*)x->m134)->v43(i, 1, buf, 4);
    ((FeObj1*)x->m134)->v14(1);
}

extern "C" FE_OVERLAY void fn_804B52E4(FeScr* x)
{
    fn_80125154(x->m144, 0);
}

extern "C" FE_OVERLAY void fn_804B530C(FeScr* x)
{
    char buf[0x400];
    fn_800DF254(buf, 0, 0, *(float*)((char*)FI(x, 0xE18) + 0x12B78));
    ((FeObj1*)fn_800C8040(((FeObj*)x->m140)->v32("BANK", 1)))->v28((int)buf);
    fn_800E5380(x->m140);
    ((FeObj*)x)->v88();
}

extern "C" FE_OVERLAY void fn_804B53B8(FeScr* x)
{
    char buf[16];
    FeObj* g = fn_800C8044(((FeObj*)x->m138)->v32("NEXTGAME", 1));
    FeObj* h = fn_800C8054(g->v32("OPPLOGO", 1));
    int sel = fn_804B78A8(x);
    if (sel == -1) {
        ((FeObj1*)h)->v8(0);
        ((FeObj1*)fn_800C8040(g->v32("TEAM", 1)))->v29(0x1A4B);
        ((FeObj1*)fn_800C8040(g->v32("IMPACT", 1)))->v29(0x1A4B);
        ((FeObj1*)fn_800C8040(g->v32("CAPACITY", 1)))->v29(0x1A4B);
        return;
    }
    ((FeObj1*)h)->v8(1);
    fn_800D0074(&((FeHolder*)h)->m98, 0, 0);
    ((FeSub20*)((char*)h + 0x98))->s20(fn_804B797C(x), 0);
    ((FeObj1*)fn_800C8040(g->v32("TEAM", 1)))->v29(fn_800E1930__Fi(fn_804B79FC(x)));
    sprintf(buf, "%d/10", fn_800A3C98(lbl_80619948, sel, ((FeObjI*)x)->v96()));
    ((FeObj1*)fn_800C8040(g->v32("IMPACT", 1)))->v30((int)buf);
    sprintf(buf, "%d", fn_805901AC(FI(x, 0xE1C), FI(x, 0xE20)));
    ((FeObj1*)fn_800C8040(g->v32("CAPACITY", 1)))->v30((int)buf);
}

extern "C" FE_OVERLAY void fn_804B5C1C(FeScr* x, int a)
{
    char b8[16];
    char b18[0x68];
    FeObj* g = fn_800C8044(((FeObj*)x->m138)->v32("LASTSEVEN", 1));
    int i = fn_80591A50(FI(x, 0xE18));
    while (i >= 0) {
        int t = fn_8007F9B4((Unk8007F198_C*)lbl_8061930C);
        Unk8007F198_C* s = (Unk8007F198_C*)lbl_8061930C;
        if (!(t - fn_8007FBC0(s, fn_80592E04(FI(x, 0xE18), i), 0) <= 0x1E))
            break;
        i--;
    }
    int k = fn_80591A50(FI(x, 0xE18)) - i;
    if (k <= 0) {
        ((FeObj1*)fn_800C8040(g->v32("NUMGAMES", 1)))->v29(0x1A4B);
        ((FeObj1*)fn_800C8040(g->v32("AVGATTEND", 1)))->v29(0x1A4B);
        ((FeObj1*)fn_800C8040(g->v32("AVGSOLD", 1)))->v29(0x1A4B);
        ((FeObj1*)fn_800C8040(g->v32("AVGREV", 1)))->v29(0x1A4B);
        return;
    }
    sprintf(b8, "%d", k);
    ((FeObj1*)fn_800C8040(g->v32("NUMGAMES", 1)))->v30((int)b8);
    sprintf(b8, "%d", fn_800E52F8__Fi(k));
    ((FeObj1*)fn_800C8040(g->v32("AVGATTEND", 1)))->v30((int)b8);
    sprintf(b8, "%3d%%", fn_805931BC(FI(x, 0xE18), ((FeObjI*)x)->v98(), a, k));
    ((FeObj1*)fn_800C8040(g->v32("AVGSOLD", 1)))->v30((int)b8);
    ((char* (*)(char*, float, int, int))fn_800DF254)(b18, fn_80592F94(FI(x, 0xE18), ((FeObjI*)x)->v98(), a, k), 0, 3);
    ((FeObj1*)fn_800C8040(g->v32("AVGREV", 1)))->v28((int)b18);
}

extern "C" FE_OVERLAY void fn_804B5FC4(FeScr* x)
{
    char buf[8];
    char* p = buf;
    FeCam* c = (FeCam*)((char*)x + 0x14C);
    fn_804BB17C(c, fn_800C8044(x->m138->v32("BARGRAPH", 1)), 0x4B);
    fn_804BC414(c, 0.5f);
    fn_804BC2B0(c, 0.0f, 100.0f);
    fn_804BB780(c, "Item", fn_804BB8B4(c, 4));
    fn_804BB780(c, "Avg.", fn_804BB8B4(c, 4));
    fn_804031BC(p, "");
    fn_804BB58C(c, p, (int)fn_80090880(lbl_8061977C, 0x57FA));
    fn_804BC42C(c, 0x1A4B, 0);
    fn_804BC42C(c, 0x1A4B, 1);
    fn_804BC42C(c, 0x1A4B, 2);
    fn_804BC42C(c, 0x1A4B, 3);
}

extern "C" FE_OVERLAY void fn_804B65D0(FeScr* x, int a)
{
    if (a != 0)
        FI(x, 0x148) = FI(x, 0x148) + 1;
    else
        FI(x, 0x148) = FI(x, 0x148) - 1;
    int t = FI(x, 0x148);
    if (t > 5)
        FI(x, 0x148) = 0;
    else if (t < 0)
        FI(x, 0x148) = 5;
    if (fn_804B797C(x) == 0 && (unsigned)(FI(x, 0x148) - 3) <= 1) {
        ((FeObj1*)x)->v93(a);
        return;
    }
    ((FeObj*)x)->v87();
}

extern "C" FE_OVERLAY void fn_804B7044(FeObj* x, int b)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    if (b == 0) {
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), &m, x);
    }
}

extern "C" FE_OVERLAY int fn_804B70D0(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v41();
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v39();
    ((FeObj*)x->m134)->v52();
    ((FeObj*)x)->v87();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B722C(FeScr* x)
{
    x->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B7268(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v41();
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v39();
    ((FeObj*)x->m134)->v50();
    ((FeObj*)x)->v87();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B73C4(FeScr* x)
{
    x->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B7400(FeScr* x)
{
    FeObj* w = x->m134;
    if (FI(w, 0x24) & 0x40000000) {
        ((FeObj1*)x)->v95(((FeObjI*)w)->v60());
        FeObj* c = (FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1);
        ((FeObj1*)fn_800C805C(c->v32("PRICE", 1)))->v40(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804B74FC(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B75A4(FeScr* x)
{
    FeObj* w = x->m134;
    if (FI(w, 0x24) & 0x40000000) {
        ((FeObj1*)x)->v94(((FeObjI*)w)->v60());
        FeObj* c = (FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1);
        ((FeObj1*)fn_800C805C(c->v32("PRICE", 1)))->v38(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804B76A0(FeScr* x)
{
    ((FeObj*)fn_800C805C(((FeObj*)((FeObjP2*)x->m134)->v73(((FeObjI*)x->m134)->v60(), 1))->v32("PRICE", 1)))->v39();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B7748(FeScr* x)
{
    FeObj* w = x->m13C;
    if (FI(w, 0x24) & 0x40000000) {
        ((FeObj1*)w)->v38(1);
        ((FeObj1*)x)->v93(1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804B77BC(FeScr* x)
{
    x->m13C->v39();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B77F8(FeScr* x)
{
    FeObj* w = x->m13C;
    if (FI(w, 0x24) & 0x40000000) {
        ((FeObj1*)w)->v40(1);
        ((FeObj1*)x)->v93(0);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804B786C(FeScr* x)
{
    x->m13C->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804B78A8(FeScr* x)
{
    int r = 0;
    int g = lbl_80619948->m28;
    fn_800B555C();
    if (fn_800B57EC() == 1) {
        r = fn_8056A2F8(g, 0, 0, 1, 0, ((FeObjI*)x)->v96(), 0, 0, r, 0x1A);
    } else {
        r = -1;
    }
    return r;
}

extern "C" FE_OVERLAY void fn_804B7948(void)
{
    fn_8057CF60(fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0), 0);
}

extern "C" FE_OVERLAY int fn_804B797C(FeScr* x)
{
    int r = fn_804B78A8(x);
    if (r != -1) {
        int g = lbl_80619948->m28;
        int s = fn_800B555C()->m608;
        return fn_8056A5F4(g, s, r, ((FeObjI*)x)->v96());
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804B79FC(FeScr* x)
{
    int r = fn_804B797C(x);
    if (r != 0)
        return fn_800B5520(r);
    return 0x7C;
}

extern "C" FE_OVERLAY int fn_804B7A30(FeScr* x, int a, int b)
{
    if (fn_805932E4(FI(x, 0xE18), ((FeObjI*)x)->v98(), a, b)->m4 > 0) {
        FeSt3* p = fn_805932E4(FI(x, 0xE18), ((FeObjI*)x)->v98(), a, b);
        return p->m8 * 100 / fn_805932E4(FI(x, 0xE18), ((FeObjI*)x)->v98(), a, b)->m4;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804B7B18(FeScr* x, int* out, int a, int max, int rev)
{
    int n = 0;
    if (a == 0) {
        if (max > fn_80591AA0(FI(x, 0xE18))) {
            n = fn_80591AA0(FI(x, 0xE18));
        } else {
            n = max;
            if (n < 0)
                n = 0;
        }
        out[0] = fn_80591A50(FI(x, 0xE18));
        for (int i = 1; i < n; i++)
            out[i] = out[i - 1] - 1;
    } else if (fn_80591A50(FI(x, 0xE18)) >= 0) {
        int h = FI(x, 0xE18);
        out[0] = fn_805934C0(h, a, fn_80591A50(h), 0);
        if (n < max && out[0] != -1) {
            int j = 0;
            do {
                n++;
                out[j + 1] = fn_805934C0(FI(x, 0xE18), a, out[j], 1);
                j++;
            } while (n < max && out[j] != -1);
        }
    }
    if (rev == 0) {
        for (int i = 0; i < n / 2; i++) {
            int u = out[i];
            int k = n - 1 - i;
            int t = out[k];
            out[i] = t;
            out[k] = u;
        }
    }
    return n;
}
