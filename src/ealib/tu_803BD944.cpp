/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803BD944-0x803BE8BC (code-only unit, 38 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

/*
 * EAGLAnim resource pool and resource factory. lbl_80626DD0 is the heap
 * object (virtual calls only; slot N is at vtable byte offset 8*N).
 */

struct EAGLHeap {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(unsigned short, void*);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(void*);
    virtual void v14();
};

struct EAGLResB {
    void* m0;
    int m4;
    int m8;
    int mC;
    int* m10;
};

struct EAGLResC {
    void* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    char** m14;
};


struct EAGLObjBase {
    virtual void v1(int);
};

struct EAGLObjV : EAGLObjBase {
    int m4;
    union {
        int m8;
        unsigned short m8s[2];
    };
};

struct EAGLTypeK {
    unsigned short v;
    ~EAGLTypeK() {}
};

struct EAGLVT {
    virtual void v1(int);
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
    virtual void v19(void*);
};

struct EAGLHeapB {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void* v10(unsigned short);
};

struct EAGLSelfC {
    void* m0;
    unsigned short pad4;
    unsigned short pad6;
    int pad8;
    struct {
        char pad0[4];
        unsigned short m4;
    }* mC;
};

struct EAGLSelfV12 {
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
    virtual void v12(float);
};

extern "C" {
void* memset(void*, int, unsigned);
void fn_803CED44(void*);
void fn_803BF9F0(void*);
void fn_803CF2EC(void*);
void fn_803CF37C(void*);
void fn_803CEA5C(void*);
void fn_803BE90C(void*, int);
int strcmp(const char*, const char*);
}

extern EAGLHeap* lbl_80626DD0;
extern int lbl_80626E08;
extern char* lbl_80626E0C;
extern int lbl_80626E10;
extern short lbl_80626E14;
extern int* lbl_80626E18[];
extern int* lbl_80626E80[];
extern unsigned short lbl_80626DD4[];
extern void (*lbl_8062C66C)(void*, int);
extern void* (*lbl_8062C668)(int, const char*);
extern char lbl_80609E00[];
extern char lbl_80685688[];
extern char lbl_80685708[];

extern "C" void* fn_803BDCFC(void* unused, unsigned short* p)
{
    EAGLTypeK k;
    EAGLVT* r;
    k.v = *p;
    switch (k.v) {
    case 0x16:
        r = (EAGLVT*)((char*)p - 0x18);
        break;
    case 0x17:
        r = (EAGLVT*)((char*)p - 0x18);
        break;
    case 0x19:
        r = (EAGLVT*)((char*)p - 0x10);
        break;
    default:
        k.v = *p;
        r = (EAGLVT*)((EAGLHeapB*)lbl_80626DD0)->v10(k.v);
        break;
    }
    r->v19(p);
    return r;
}

/* near-miss: case tree differs (target: 15 / [0,[1-2]] / 22 / 24->23,25 with dead compares; 2 slots) */
extern "C" void fn_803BDDB4(void* unused, unsigned short* p)
{
    EAGLTypeK k;
    k.v = *p;
    switch (k.v) {
    case 0:
        fn_803CED44(p);
        break;
    case 1:
    case 2:
        break;
    case 15:
        fn_803BF9F0(p);
        break;
    case 22:
        fn_803CF2EC(p);
        break;
    case 23:
        fn_803CF37C(p);
        break;
    case 25:
        fn_803CEA5C(p);
        break;
    case 24:
        break;
    }
}

extern "C" void fn_803BDE50(const void** self, int chrg)
{
    *self = lbl_80685688;
    if (chrg & 1)
        lbl_8062C66C(self, 4);
}

extern "C" int fn_803BDE94()
{
    return (int)lbl_80626E0C - lbl_80626E08;
}

extern "C" int fn_803BDEAC()
{
    return lbl_80626E10 - lbl_80626DD0->v4();
}

extern "C" int* fn_803BDEF4(void* unused, int idx)
{
    int* p = lbl_80626E18[idx];
    if (p) {
        lbl_80626E18[idx] = (int*)*p;
    } else {
        int sz = lbl_80626DD4[idx];
        *(int**)lbl_80626E0C = p;
        char* c = lbl_80626E0C;
        lbl_80626E18[idx] = (int*)c;
        lbl_80626E0C = c + sz;
        p = (int*)c;
        lbl_80626E18[idx] = (int*)*p;
    }
    return p;
}

extern "C" int* fn_803BDF54(void* unused, unsigned x)
{
    unsigned char t = x >> 4;
    int* p = lbl_80626E80[t];
    if (p) {
        lbl_80626E80[t] = (int*)*p;
    } else {
        int sz = (t + 1) * 16 + 4;
        *(int*)lbl_80626E0C = t;
        char* c = lbl_80626E0C;
        lbl_80626E0C = c + sz;
        p = (int*)(c + 4);
    }
    return p;
}

extern "C" void fn_803BDFA8()
{
    lbl_80626E0C = (char*)lbl_80626E08;
    int i;
    for (i = 255; i >= 0; i--)
        lbl_80626E80[i] = 0;
    for (i = 25; i >= 0; i--)
        lbl_80626E18[i] = 0;
}

extern "C" void fn_803BE004(void* unused, int size)
{
    lbl_80626E10 = size;
    lbl_80626E08 = (int)lbl_8062C668(size, lbl_80609E00);
    lbl_80626E14 = 0;
    lbl_80626DD0->v14();
}

extern "C" void fn_803BE084()
{
    lbl_8062C66C((void*)lbl_80626E08, lbl_80626E10);
}

extern "C" void fn_803BE0C0(void* unused, int idx, int* p)
{
    *p = (int)lbl_80626E18[idx];
    lbl_80626E18[idx] = p;
}

extern "C" void fn_803BE0DC(void* unused, int* p)
{
    int k = p[-1];
    *p = (int)lbl_80626E80[k];
    lbl_80626E80[k] = p;
}

extern "C" void fn_803BE0FC(void* unused, EAGLObjV* o)
{
    int t = o->m8;
    if (t == 0x16)
        return;
    if (t == 0x17)
        return;
    if (t == 0x19)
        return;
    o->v1(2);
    lbl_80626DD0->v9(o->m8s[1], o);
}

extern "C" void fn_803BE4C0(const void** self, int chrg)
{
    *self = lbl_80685708;
    fn_803BE90C(self, 0);
    if (chrg & 1)
        lbl_8062C66C(self, 0x14);
}

extern "C" int fn_803BE520(EAGLSelfC* self, float* out)
{
    *out = (float)self->mC->m4;
    return 1;
}

extern "C" void fn_803BE55C(EAGLSelfV12* self, float a, float b)
{
    self->v12(b);
}

struct U {
    char pad0[0x4000];
};


extern "C" void fn_803BE6B4(void* p, int flag);

extern "C" U* fn_803BE684(U* self, int flag)
{
    fn_803BE6B4(self, flag);
    return self;
}

extern "C" void fn_803BE6B4(void* p, int flag)
{
    if (flag)
        memset(p, 0xff, 0x20);
    else
        memset(p, 0, 0x20);
}

extern "C" void fn_803BE6F4(unsigned* bits, int idx, int val)
{
    if (val) {
        unsigned* q = &bits[idx >> 5];
        *q |= 1u << (idx & 31);
    } else {
        unsigned* q = &bits[idx >> 5];
        *q &= ~(1u << (idx & 31));
    }
}

extern "C" void fn_803BE744(EAGLResB* self)
{
    int i;
    for (i = self->m4 - 1; i >= 0; i--)
        lbl_80626DD0->v13((void*)self->m10[i]);
}

extern "C" void fn_803BE7B0() {}

extern "C" int fn_803BE7B4(EAGLResC* self, const char* name)
{
    int lo = 0;
    int hi = self->m4 - 1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        int c = strcmp(name, self->m14[mid]);
        if (c > 0)
            lo = mid + 1;
        else if (c < 0)
            hi = mid - 1;
        else
            return mid;
    }
    return -1;
}

struct DtorAt0 { const void* m; };

extern char lbl_80685268[];

extern "C" void fn_80377408(void* p);

extern "C" void fn_803BE838(DtorAt0* self, int chrg)
{
    self->m = lbl_80685268;
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" int fn_803BE86C() { return 0; }

extern "C" void fn_803BE874() {}

extern "C" void fn_803BE878() {}

extern "C" int fn_803BE87C() { return 0; }

extern "C" int fn_803BE884() { return 0; }

extern "C" int fn_803BE88C() { return 0; }

extern "C" int fn_803BE894() { return 0; }

extern "C" int fn_803BE89C() { return 0; }

extern "C" int fn_803BE8A4() { return 0; }

extern "C" int fn_803BE8AC() { return 0; }

extern "C" int fn_803BE8B4() { return 0; }
