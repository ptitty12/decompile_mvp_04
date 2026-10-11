/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11); original file name unknown, placeholder.
 *
 * .text 0x802A4584-0x802A6334, .rodata 0x805DE2F8-0x805DE56C, .data 0x8061E87C-0x8061E97C, .bss 0x8068CE60-0x8068CE68.
 *
 * Classes (names from vtable slot 3 -> name pointer -> string):
 * cSwingTimeWarp (0x80661C20), cTimeWarp (0x80661BA0), cGenericTimeWarp
 * (0x80661B20), cCycleTimeSpaceWarp (0x80661AA0), cLimbLockWarp (0x80661A20),
 * cHeadingWarp (0x806619A0), cTranslationWarp (0x80661920). One unit because
 * the groups' .data interleave (0x8061E894..0x8061E970 sits inside
 * 0x8061E87C..0x8061E97C).
 */
#include "game/warp.h"

float fn_80382BB8(Unk80271DBC_Link* p);
void fn_80244858(Unk80270BA0_X* x, float v);

inline Unk80273498_Vec3 operator-(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline Unk80273498_Vec3 operator+(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

inline Unk80273498_Vec3 operator*(const Unk80273498_Vec3& v, float s)
{
    Unk80273498_Vec3 r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}

extern Unk80273498_Vec3 lbl_806055AC;    /* shared constant vector */
extern int lbl_8061B9C8;                 /* integer read as the frame rate */
float fn_8026FDB0(Unk80270BA0_Obj* o);
float fn_80382348(Unk80271DBC_Link* link, unsigned int hash, int flag);
unsigned int fn_80378568(const char* token, int len);

/* Lazily computed hash of "cReleaseBall" (.bss 0x8068CE60) and its done flag (0x8068CE64). */
static unsigned int lbl_8068CE60;
static int lbl_8068CE64;

int fn_8023F330(Unk80270BA0_X* x, int a, int b, void* c, void* d, int e, int f, int g, int h);

/* Class name; read by cSwingTimeWarp's vtable slot 3 (0x802ACC04). */
const char* lbl_8061E87C = "cSwingTimeWarp";

class cSwingTimeWarp : public Unk8035EAE8 {
public:
    /* Declared first and defined in the unit at 0x802ACxxx (vtable slots 3/4),
     * which makes g++ 2.95 emit this class's vtable there, as in retail. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cSwingTimeWarp();
    virtual void fn_vslot2();
    virtual ~cSwingTimeWarp();
    virtual void fn_vslot12(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj);
    virtual Unk8037B3E8* fn_vslot5();

    float m4;                  /* "MinWarpPercent" */
    float m8;                  /* "MaxWarpPercent" */
};

cSwingTimeWarp::cSwingTimeWarp() : Unk8035EAE8(0xDEA30859u)
{
    m4 = 0.75f;
    m8 = 1.333f;
}

void cSwingTimeWarp::fn_vslot2()
{
    fn_8037B50C("MinWarpPercent", &m4, "0.01,1.0,2", 0);
    fn_8037B50C("MaxWarpPercent", &m8, "1.0,99,2", 0);
}

cSwingTimeWarp::~cSwingTimeWarp()
{
}

void cSwingTimeWarp::fn_vslot12(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj)
{
    Unk8027107C_Outer* o = obj->fn_vslot1()->m44C->m700;
    float t = 1.0f;

    if (o) {
        t = o->m3A4->m14C;
    }
    t = t > 10.0f ? 10.0f : (t >? 0.1f);
    int n = h->count;
    float d;
    for (int i = 0; i < n; i++) {
        d = e[i].m10 - e[i].m14;
        d *= t;
        e[i].m10 = e[i].m14 + d;
    }
}

Unk8037B3E8* cSwingTimeWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cSwingTimeWarp;
}

/* Class name; read by cTimeWarp's vtable slot 3 (0x802ACC1C). */
const char* lbl_8061E880 = "cTimeWarp";

class cTimeWarp : public Unk8035EAE8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cTimeWarp();
    virtual void fn_vslot2();
    virtual ~cTimeWarp();
    virtual void fn_vslot12(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj);
    virtual Unk8037B3E8* fn_vslot5();

    int m4;                    /* "start" */
    int m8;                    /* "end" */
};

cTimeWarp::cTimeWarp() : Unk8035EAE8(0x1C105B31u)
{
    m4 = lbl_8068D5AC;
    m8 = lbl_8068D5B0;
}

void cTimeWarp::fn_vslot2()
{
    fn_8037B638("start", &m4, "Start,cReleaseBall,cCatchBall,cBlend1,cBlend2,cBlend3");
    fn_8037B638("end", &m8, "End,cReleaseBall,cCatchBall,cBlend1,cBlend2,cBlend3");
}

cTimeWarp::~cTimeWarp()
{
}

void cTimeWarp::fn_vslot12(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj)
{
    Unk80270BA0_X* x = obj->fn_vslot1();

    if (h->m2C == 0) {
        Unk802726BC_Angles* p = &x->m734;
        float* q = &p->m48[p->m190];
        h->m50 = *q;
        if (!(h->m50 <= 0.0f) && (h->m50 <= 0.9999f || !(h->m50 < 1.0001f))) {
            int flag = 0;

            h->m2C = 1;
            if (m4 == lbl_8068D5AC) {
                h->m54 = 0.0f;
            } else {
                h->m54 = -1.0f;
                flag = 1;
            }
            if (m8 == lbl_8068D5B0) {
                h->m58 = 1.0f;
            } else {
                h->m58 = -1.0f;
                flag = 1;
            }
            if (flag) {
                Unk8037E64C* list = &e->m4->m10;
                float len = lbl_8061E978->fn_802AEB4C(e->m0);

                if (!(h->m54 >= 0.0f)) {
                    h->m54 = list->m8[list->fn_8037E64C(m4)].m8 / len;
                }
                if (!(h->m58 >= 0.0f)) {
                    h->m58 = list->m8[list->fn_8037E64C(m8)].m8 / len;
                }
            }
        }
    } else {
        Unk802726BC_Angles* p = &x->m734;
        float* q = &p->m48[p->m190];
        h->m50 = *q;
        if (!(h->m50 > 0.0f)) {
            h->m2C = 0;
        }
        if (!(h->m50 <= 0.9999f) && !(h->m50 >= 1.0001f)) {
            h->m2C = 0;
        }
    }
}

Unk8037B3E8* cTimeWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cTimeWarp;
}

/* Class name; read by cGenericTimeWarp's vtable slot 3 (0x802ACC34). */
const char* lbl_8061E884 = "cGenericTimeWarp";

class cGenericTimeWarp : public Unk8035EAE8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cGenericTimeWarp();
    virtual void fn_vslot2();
    virtual ~cGenericTimeWarp();
    virtual void fn_vslot12(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj);
    virtual Unk8037B3E8* fn_vslot5();

    int m4;                    /* "enabled" */
    int m8;                    /* "Mode": ScaleRunSpeed, TimePitchRelease */
};

cGenericTimeWarp::cGenericTimeWarp() : Unk8035EAE8(0xBFEB4CCEu)
{
    m4 = 1;
    m8 = 0;
}

void cGenericTimeWarp::fn_vslot2()
{
    fn_8037B458("enabled", &m4, 0, 0);
    fn_8037B6B0("Mode", &m8, "ScaleRunSpeed,TimePitchRelease");
}

cGenericTimeWarp::~cGenericTimeWarp()
{
}

void cGenericTimeWarp::fn_vslot12(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj)
{
    Unk80270BA0_X* x = obj->fn_vslot1();

    if (!(x->m71C & 0x800)) {
        if (m4) {
            switch (m8) {
            case 0: {
                Unk802726BC_Angles* p = &x->m734;
                float* q = &p->m8[p->m190];
                float a = *q * 0.0025399998f;
                float b = fn_8026FDB0(x);
                float c = a / b;
                float d = x->mAB4;
                int n;

                d = !(d > 20.0f) ? (d >? 0.01f) : 20.0f;
                n = h->count;
                c = c / d;
                for (int i = 0; i < n; i++) {
                    float from = e[i].m14;
                    float to = e[i].m10;
                    float d = to - from;
                    d = d * c;
                    e[i].m10 = from + d;
                }
                break;
            }
            case 1: {
                if (!lbl_8068CE64) {
                    /* the pointer makes the compiler form the address before the call, as retail does */
                    unsigned int* p = &lbl_8068CE60;
                    *p = fn_80378568("cReleaseBall", 0);
                    lbl_8068CE64 = 1;
                }
                float v = lbl_8061E978->fn_802AEB4C(e[0].m0);
                v = v - 1.0f;
                if (!(v <= 0.0f)) {
                    float w = e[0].m4->m4;
                    float u = fn_80382348(x->m618, lbl_8068CE60, 1);
                    int n = h->count;

                    if (!(u <= 0.0f)) {
                        float t = 0.003f;
                        float q;
                        int iq;
                        float r;
                        float s;
                        float y;
                        float z;

                        if (n == 1) {
                            t = 0.0001f;
                        }
                        u = u + t;
                        q = u / ((float)lbl_8061B9C8 * 0.016666668f);
                        iq = (int)q;
                        r = q - (float)iq;
                        if (!(r <= 0.5f)) {
                            r = r - 1.0f;
                            iq = iq + 1;
                        }
                        s = w * 0.016666668f * (float)lbl_8061B9C8;
                        if (!(s > 0.0f)) {
                            s = 1.0f;
                        }
                        z = 1.0f;
                        y = (float)iq / s;
                        if (!(y <= 0.0f)) {
                            z = r / y + 1.0f;
                        }
                        z = z > 5.0f ? 5.0f : (z >? 0.2f);
                        for (int i = 0; i < n; i++) {
                            float from = e[i].m14;
                            float to = e[i].m10;
                            float d = to - from;
                            d = d * z;
                            e[i].m10 = from + d;
                        }
                    }
                }
                break;
            }
            }
        }
    }
}

Unk8037B3E8* cGenericTimeWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cGenericTimeWarp;
}

/* Class name; read by cCycleTimeSpaceWarp's vtable slot 3 (0x802ACC4C). */
const char* lbl_8061E888 = "cCycleTimeSpaceWarp";

class cCycleTimeSpaceWarp : public Unk8035EAE8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cCycleTimeSpaceWarp();
    virtual void fn_vslot2();
    virtual ~cCycleTimeSpaceWarp();
    virtual void fn_vslot11(float* a, Unk80270BA0_Obj* obj);
    virtual void fn_vslot12(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj);
    virtual void fn_vslot13(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj);
    virtual Unk8037B3E8* fn_vslot5();

    int m4;                    /* "enabled" */
    int m8;                    /* "timespace" */
    int mC;                    /* "time" */
    int m10;                   /* "direction" */
    Unk80273498_Vec3 m14;      /* player position, set by slot 11 */
    float m20;
};

cCycleTimeSpaceWarp::cCycleTimeSpaceWarp() : Unk8035EAE8(0x05B43FADu)
{
    m4 = 1;
    m8 = 0;
    mC = 0;
    m10 = 0;
}

void cCycleTimeSpaceWarp::fn_vslot2()
{
    fn_8037B458("enabled", &m4, 0, 0);
    fn_8037B458("timespace", &m8, 0, 0);
    fn_8037B458("time", &mC, 0, 0);
    fn_8037B458("direction", &m10, 0, 0);
}

cCycleTimeSpaceWarp::~cCycleTimeSpaceWarp()
{
}

void cCycleTimeSpaceWarp::fn_vslot11(float* a, Unk80270BA0_Obj* obj)
{
    Unk80270BA0_X* x = obj->fn_vslot1();

    m14 = x->m60;
    m20 = fn_80382BB8(x->m618);
}

void cCycleTimeSpaceWarp::fn_vslot12(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj)
{
    Unk80270BA0_X* x = obj->fn_vslot1();

    if (!(x->m71C & 0x800)) {
        float scale = 1.0f;

        if (m8) {
            Unk802726BC_Angles* p = &x->m734;
            float* q = &p->mD8[p->m190];
            float t = *q;

            if (!(t <= 0.0f)) {
                scale = 1.0f / t;
            }
        } else if (mC) {
            Unk802726BC_Angles* p = &x->m734;
            float* q = &p->m48[p->m190];
            float t = *q;

            if (!(t <= 0.0f)) {
                scale = t;
            }
        }
        if (scale != 1.0f) {
            int n = h->count;
            float d;

            for (int i = 0; i < n; i++) {
                d = e[i].m10 - e[i].m14;
                d *= scale;
                e[i].m10 = e[i].m14 + d;
            }
        }
    }
}

void cCycleTimeSpaceWarp::fn_vslot13(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj)
{
}

Unk8037B3E8* cCycleTimeSpaceWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cCycleTimeSpaceWarp;
}

/* Class name; read by cLimbLockWarp's vtable slot 3 (0x802ACC64). */
const char* lbl_8061E894 = "cLimbLockWarp";

class cLimbLockWarp : public Unk8035EAE8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cLimbLockWarp();
    virtual void fn_vslot2();
    virtual ~cLimbLockWarp();
    virtual void fn_vslot11(float* a, Unk80270BA0_Obj* obj);
    virtual void fn_vslot13(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj);
    virtual Unk8037B3E8* fn_vslot5();

    int m4;                    /* "enabled" */
    int m8;                    /* "limb" */
    int mC;                    /* "use_current_start_end" */
    int m10;                   /* "y_warp" */
    int m14;                   /* "heading_warp" */
};

cLimbLockWarp::cLimbLockWarp() : Unk8035EAE8(0x1CE0FF4Fu)
{
    m4 = 1;
    m8 = 0;
    m10 = 0;
    m14 = 0;
    mC = 0;
}

void cLimbLockWarp::fn_vslot2()
{
    fn_8037B458("enabled", &m4, 0, "1");
    fn_8037B638("limb", &m8, "_please_select_,RootBone,LeftFoot,RightFoot");
    fn_8037B458("use_current_start_end", &mC, 0, "0");
    fn_8037B458("y_warp", &m10, 0, "0");
    fn_8037B458("heading_warp", &m14, 0, "0");
}

cLimbLockWarp::~cLimbLockWarp()
{
}

void cLimbLockWarp::fn_vslot11(float* a, Unk80270BA0_Obj* obj)
{
    if (m4) {
        Unk80270BA0_X* x = obj->fn_vslot1();

        if (m14) {
            if (x->m95C < x->m958) {
                fn_80244858(x, fn_80382BB8(x->m618) + x->m954);
                x->m95C = x->m95C + 1;
            }
        }
    }
}

void cLimbLockWarp::fn_vslot13(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj)
{
    if (m4) {
        Unk80270BA0_X* x = obj->fn_vslot1();
        Unk80273498_Vec3 pos = x->m948;

        if (pos.y != -1000.0f) {
            int ok = 1;

            if (mC) {
                if (h->m2C) {
                    ok = 0;
                    if (!(e[0].m10 < h->m54)) {
                        ok = e[0].m10 <= h->m58;
                    }
                } else {
                    ok = 0;
                }
            }
            if (ok) {
                Unk80273498_Vec3 limb = lbl_806055AC;
                int found = 0;

                if (m8 == lbl_8068D5B8) {
                    if (x->m618->m85C) {
                        fn_8023F330(x, 0, 0, 0, &limb, 0, 0, 0, 0);
                        found = 1;
                    }
                } else if (m8 == lbl_8068D5BC) {
                    limb = x->m60;
                    found = 1;
                } else if (m8 == lbl_8068D5B4) {
                    if (x->m618->m85C) {
                        fn_8023F330(x, 0, 0, &limb, 0, 0, 0, 0, 0);
                        found = 1;
                    }
                }
                if (found) {
                    Unk80273498_Vec3 d = pos - limb;

                    if (!m10) {
                        d.y = 0.0f;
                    }
                    Unk80273498_Vec3 target = x->m60 + d * 0.25f;
                    x->fn_vslot3(&target);
                }
            }
        }
    }
}

Unk8037B3E8* cLimbLockWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cLimbLockWarp;
}

/* Class name; read by cHeadingWarp's vtable slot 3 (0x802ACC7C). */
const char* lbl_8061E898 = "cHeadingWarp";

class cHeadingWarp : public Unk8035EAE8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cHeadingWarp();
    virtual void fn_vslot2();
    virtual ~cHeadingWarp();
    virtual void fn_vslot11(float* a, Unk80270BA0_Obj* obj);
    virtual void fn_vslot13(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj);
    virtual Unk8037B3E8* fn_vslot5();

    int m4;                    /* "enabled" */
    Unk80273498_Vec3 m8;       /* player position, set by slot 11 */
    float m14;
};

cHeadingWarp::cHeadingWarp() : Unk8035EAE8(0x688FB392u)
{
    m4 = 1;
}

void cHeadingWarp::fn_vslot2()
{
    fn_8037B458("enabled", &m4, 0, "1");
}

cHeadingWarp::~cHeadingWarp()
{
}

void cHeadingWarp::fn_vslot11(float* a, Unk80270BA0_Obj* obj)
{
    if (m4) {
        Unk80270BA0_X* x = obj->fn_vslot1();

        if (x->m95C < x->m958) {
            fn_80244858(x, fn_80382BB8(x->m618) + x->m954);
            x->m95C = x->m95C + 1;
        }
        m8 = x->m60;
        m14 = fn_80382BB8(x->m618);
    }
}

void cHeadingWarp::fn_vslot13(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj)
{
}

Unk8037B3E8* cHeadingWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cHeadingWarp;
}

/* Class name; read by cTranslationWarp's vtable slot 3 (0x802ACC94). */
const char* lbl_8061E89C = "cTranslationWarp";

class cTranslationWarp : public Unk8035EAE8 {
public:
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cTranslationWarp();
    virtual void fn_vslot2();
    virtual ~cTranslationWarp();
    virtual void fn_vslot11(float* a, Unk80270BA0_Obj* obj);
    virtual void fn_vslot13(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj);
    virtual Unk8037B3E8* fn_vslot5();

    int m4;                    /* "enabled" */
    Unk80273498_Vec3 m8;       /* player position, set by slot 11 */
};

cTranslationWarp::cTranslationWarp() : Unk8035EAE8(0xF394EA31u)
{
    m4 = 1;
}

void cTranslationWarp::fn_vslot2()
{
    fn_8037B458("enabled", &m4, 0, "1");
}

cTranslationWarp::~cTranslationWarp()
{
}

void cTranslationWarp::fn_vslot11(float* a, Unk80270BA0_Obj* obj)
{
    if (m4) {
        m8 = obj->fn_vslot1()->m60;
    }
}

void cTranslationWarp::fn_vslot13(Unk802A4674_Entry* e, Unk802A4674_Hdr* h, Unk80270BA0_Obj* obj)
{
    if (m4) {
        Unk80270BA0_X* x = obj->fn_vslot1();

        if (x->m978 < x->m974) {
            Unk80273498_Vec3 d = x->m60 - m8;
            Unk80273498_Vec3 w = x->m960;

            float sx = x->m96C;
            float sz = x->m970;
            d.x *= sx;
            d.z *= sz;
            Unk80273498_Vec3 r = m8 + d + w;
            x->fn_vslot3(&r);
            x->m978 = x->m978 + 1;
        }
    }
}

Unk8037B3E8* cTranslationWarp::fn_vslot5()
{
    return new (lbl_806EF9B4) cTranslationWarp;
}

/* The last three functions of the unit belong to two classes whose other
 * methods are in the next unit (0x802A6334..): a list class (vtable 0x80661900:
 * dtor 0x802ACCAC, slot 2 0x802A6250) and a container (vtable 0x806618A0:
 * slot 12 0x802A62CC, slot 13 0x802A62A8). Only what these functions touch is
 * declared. The list nodes hold objects whose vptr is at +0x18 (a data-bearing
 * base precedes the first virtual), called through slots 6 and 7. */
struct Unk802A6250_Base {
    char pad0[0x18];
};

class Unk802A62CC;

class Unk802A6250_Child : public Unk802A6250_Base {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7(Unk802A62CC* owner, float dt);
};

struct Unk802A6250_Node {
    Unk802A6250_Child* m0;
    int m4;
    Unk802A6250_Node* m8;
};

/* g++ 2.95 puts the vptr after the data of the class that introduces the
 * virtuals; the data starts at +4 here, so the virtuals come from a data-less
 * base. */
class Unk802A6250_Virt {
public:
    virtual ~Unk802A6250_Virt();
    virtual void fn_vslot2();
};

class Unk802A6250 : public Unk802A6250_Virt {
public:
    virtual ~Unk802A6250();
    virtual void fn_vslot2();      /* 0x802A6250 */

    int m4;
    int m8;
    Unk802A6250_Node* mC;
};

void Unk802A6250::fn_vslot2()
{
    for (Unk802A6250_Node* n = mC; n; n = n->m8) {
        n->m0->fn_vslot6();
    }
}

/* Embedded at +0x20 of Unk802A62CC; method 0x802A6458 is in the next unit. */
class Unk802A6458 {
public:
    void fn_802A6458();
    char pad0[0xC];
};

class Unk802A62CC_Virt {
public:
    virtual ~Unk802A62CC_Virt();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12(float dt);
    virtual void fn_vslot13();
};

class Unk802A62CC : public Unk802A62CC_Virt {
public:
    virtual ~Unk802A62CC();
    virtual void fn_vslot12(float dt);      /* 0x802A62CC */
    virtual void fn_vslot13();              /* 0x802A62A8 */

    char pad4[0x1C];
    Unk802A6458 m20;
    Unk802A6250_Node* m2C;
};

void Unk802A62CC::fn_vslot13()
{
    m20.fn_802A6458();
}

void Unk802A62CC::fn_vslot12(float dt)
{
    for (Unk802A6250_Node* n = m2C; n; n = n->m8) {
        n->m0->fn_vslot7(this, dt);
    }
}
