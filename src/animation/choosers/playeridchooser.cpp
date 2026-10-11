/*
 * C:/mvp2004/source/common/animation/choosers/playeridchooser.cpp
 *
 * .text 0x80270730-0x80271748, .rodata 0x805DC568-0x805DC644,
 * .data 0x8061E648-0x8061E650. Two chooser classes, named by the strings
 * their GetName-style vtable slots return (0x802AC888 -> "ICommonPlayerID",
 * 0x802AC8A8 -> "cSignatureChooser"), plus the helper list classes they embed.
 *
 * Placeholder names (Unk<addr>, fn_<addr>, m<offset>) are used wherever
 * there is no evidence for a real name (see CLAUDE.md).
 */

void* operator new(unsigned int size, int heap);      /* 0x80377428 */
void* operator new[](unsigned int size, int heap);    /* 0x803774A8 */

extern int lbl_806EF9B4;          /* default heap passed to new */
extern unsigned int lbl_8068D578; /* ICommonPlayerID type hash */

void fn_80378E48(char** cursor, int* remaining, char delim, char** token, int* tokenLen);
unsigned int fn_80378568(const char* token, int len);
int fn_80409DAC(const char* token);
int fn_80383334(unsigned int hash);
/* Random number generator (multi-word add-with-carry state at +0x4..+0x18). */
class Unk8014D8AC {
public:
    int fn_8014D8AC(int max, const char* file, int line);
};

/* Object passed to the choosers' pick functions; only +0x554 is used here. */
struct Unk8027107C_Outer;
struct Unk8014D8AC_Ctx {
    char pad0[0x554];
    Unk8014D8AC* m554;
    char pad558[0x6F4 - 0x558];
    int m6F4;
    char pad6F8[0x700 - 0x6F8];
    Unk8027107C_Outer* m700;
};

/* Returned by fn_8037C7FC(); resolves a raw value via fn_8037CE98. */
class Unk8037C7FC {
public:
    int fn_8037CE98(int arg, int value, int flags);
};
Unk8037C7FC* fn_8037C7FC();

/* Base of the helper list classes (ctor 0x80356798). */
class Unk80356798 {
public:
    Unk80356798();
    virtual void fn_vslot1();
};

/* One parsed (hash, flag) pair. */
struct Unk80270730_Entry {
    unsigned int hash;
    int id;
    int flag;
};

/* List of player IDs parsed from a "hash,flag,hash,flag,..." string. Size 0x1C. */
class Unk80270730 : public Unk80356798 {
public:
    Unk80270730();
    virtual ~Unk80270730();
    void fn_80270824(char* buf, int len);
    int fn_802709D0(int index, int* outId, int* outFlag);

    int m4;                    /* entry count */
    int m8;                    /* count of flag==0 entries (indices in m14) */
    int mC;                    /* ids resolved */
    Unk80270730_Entry* m10;
    int* m14;
    int* m18;
};

/* Result record filled by the choosers' vtable slot 17. */
struct Unk80270BA0_Result {
    unsigned int type : 4;
    unsigned int pad0 : 28;
    int id;
    char pad8[0xC];
    float m14;
};

struct Unk80270BA0_X;

/* Reached through Unk8014D8AC_Ctx::m700 (two levels down). */
struct Unk8027107C_Inner {
    char pad0[0x128];
    int m128;
};
struct Unk8027107C_Outer {
    char pad0[0x3A4];
    Unk8027107C_Inner* m3A4;
};

int fn_8024D9A0(Unk80270BA0_X* x, int* out);

/* Base part of Unk80270BA0_X that precedes its vtable pointer (at +0x98). */
struct Unk80270BA0_XBase {
    char pad0[0x98];
};

/* g++ 2.95 places the vtable pointer after the data of the class that
 * introduces virtuals, so the vptr at +0x98 means a data-less class adds the
 * virtuals on top of a 0x98-byte base. */
class Unk80270BA0_XVirt : public Unk80270BA0_XBase {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual int fn_vslot4();
};

/* Object returned by Unk80270BA0_Obj::fn_vslot1() (a player?). */
class Unk80270BA0_X : public Unk80270BA0_XVirt {
public:
    char pad9C[0x44C - 0x9C];
    Unk8014D8AC_Ctx* m44C;
    char pad450[0x488 - 0x450];
    int m488;
    char pad48C[0x588 - 0x48C];
    char m588[0x708 - 0x588];
    int m708;
    char pad70C[0xB4C - 0x70C];
    int mB4C;
    int mB50;
};

/* Second argument of vtable slot 17; only its first virtual is used here. */
class Unk80270BA0_Obj {
public:
    virtual Unk80270BA0_X* fn_vslot1();
};

int fn_8025416C(void* p, int n);

/* Base of the choosers (ctor 0x8037B3E8, dtor 0x80362C2C). */
class Unk8037B3E8 {
public:
    Unk8037B3E8(unsigned int hash);
    virtual ~Unk8037B3E8();
    virtual void fn_vslot2();
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();
    virtual Unk8037B3E8* fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual int fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f);
    void fn_8037B6B0(const char* name, int* field, const char* values);
    void fn_8037B728(const char* name, const char* name2, void* list, int flags);
};

class ICommonPlayerID : public Unk8037B3E8 {
public:
    ICommonPlayerID();
    virtual ~ICommonPlayerID();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f);
    int fn_80270CDC(int count, int flag);
    int fn_80270D64(Unk8014D8AC_Ctx* ctx, int count);
    int fn_80270E3C(Unk8014D8AC_Ctx* ctx, int count);

    Unk80270730 m4;
};

/* Sorted set of signed-char keys with a parallel int array (vtable 0x80662460). Size 0x18. */
class Unk8027130C : public Unk80356798 {
public:
    Unk8027130C(int arg);
    virtual ~Unk8027130C();
    int fn_802713D4(signed char key, int* outIndex);
    void fn_80271444(unsigned char key, int value);
    void fn_802714FC(int arg);
    int fn_80271580(unsigned char key);
    int fn_802715D8(int index);
    void fn_802715E8(char* buf, int len);

    signed char* m4;           /* keys (third part of the m8 allocation) */
    int* m8;                   /* raw values; owns the allocation */
    int* mC;                   /* resolved values (second part of the allocation) */
    short m10;                 /* count */
    short m12;
    int m14;
};

class cSignatureChooser : public Unk8037B3E8 {
public:
    cSignatureChooser();
    virtual ~cSignatureChooser();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f);
    int fn_8027101C(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);

    int m4;                    /* "sigtype" enum */
    Unk8027130C m8;            /* "playerIDs"/"sigids" */
    int m20;
};

/* ---- Unk80270730 ---- */

Unk80270730::Unk80270730()
{
    m4 = 0;
    m8 = 0;
    m10 = 0;
    m18 = 0;
    m14 = 0;
    mC = 0;
}

Unk80270730::~Unk80270730()
{
    if (m4) {
        if (m10) {
            delete m10;
            m10 = 0;
        }
        if (m18) {
            delete m18;
            m18 = 0;
        }
        if (m14) {
            delete m14;
            m14 = 0;
        }
    }
}

void Unk80270730::fn_80270824(char* buf, int len)
{
    mC = 0;
    if (len) {
        for (int pass = 0; pass <= 1; pass++) {
            char* cursor;
            int remaining;
            char* token;
            int tokenLen;
            char* token2;
            int token2Len;
            int count;
            int done;

            remaining = len;
            count = 0;
            cursor = buf;
            done = 0;
            while (!done) {
                fn_80378E48(&cursor, &remaining, ',', &token, &tokenLen);
                fn_80378E48(&cursor, &remaining, ',', &token2, &token2Len);
                if (tokenLen && token2Len) {
                    if (pass == 1) {
                        m10[count].hash = fn_80378568(token, tokenLen);
                        m10[count].flag = fn_80409DAC(token2);
                        if (m10[count].flag == 0) {
                            m14[m8] = count;
                            m8++;
                        }
                    }
                    count++;
                } else {
                    done = 1;
                }
            }
            if (pass == 0) {
                if (m10) {
                    delete[] m10;
                    m10 = 0;
                }
                m10 = new (lbl_806EF9B4) Unk80270730_Entry[count];
                if (m14) {
                    delete[] m14;
                    m14 = 0;
                }
                m14 = new (lbl_806EF9B4) int[count];
                if (m18) {
                    delete[] m18;
                    m18 = 0;
                }
                m18 = new (lbl_806EF9B4) int[count];
                m4 = count;
            }
        }
    }
}

int Unk80270730::fn_802709D0(int index, int* outId, int* outFlag)
{
    int i;

    if (!mC) {
        for (i = 0; i < m4; i++) {
            m10[i].id = fn_80383334(m10[i].hash);
        }
        mC = 1;
    }
    if (index >= 0 && index < m4) {
        *outId = m10[index].id;
        *outFlag = m10[index].flag;
        return 1;
    }
    return 0;
}

/* ---- ICommonPlayerID ---- */

ICommonPlayerID::ICommonPlayerID() : Unk8037B3E8(lbl_8068D578)
{
}

void ICommonPlayerID::fn_vslot2()
{
    fn_8037B728("playerIDs", "sigids", &m4, 0);
}

ICommonPlayerID::~ICommonPlayerID()
{
}

Unk8037B3E8* ICommonPlayerID::fn_vslot5()
{
    return new (lbl_806EF9B4) ICommonPlayerID;
}

int ICommonPlayerID::fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f)
{
    Unk80270730* list = &m4;
    int n = list->m4;
    int id;
    int flag;

    out->type = 1;
    if (n != 0) {
        if (n == 1) {
            list->fn_802709D0(0, &id, &flag);
        } else {
            Unk80270BA0_X* x = obj->fn_vslot1();
            int k = fn_8025416C(x->m588, 32);
            if (k && (k = fn_80270CDC(n, k))) {
                id = fn_80270E3C(x->m44C, k);
            } else {
                id = fn_80270D64(x->m44C, n);
            }
        }
    } else {
        flag = 0;
        id = 0;
        out->type = 0;
    }
    out->id = id;
    out->m14 = 1.0f;
    return Unk8037B3E8::fn_vslot17(out, obj, c, d, e, f);
}

int ICommonPlayerID::fn_80270CDC(int count, int flag)
{
    int found = 0;
    for (int i = 0; i < count; i++) {
        Unk80270730* list = &m4;
        int id;
        int entryFlag;
        list->fn_802709D0(i, &id, &entryFlag);
        if (entryFlag == flag) {
            list->m18[found] = i;
            found++;
        }
    }
    return found;
}

int ICommonPlayerID::fn_80270D64(Unk8014D8AC_Ctx* ctx, int count)
{
    Unk80270730* list = &m4;
    int id = 0;
    int flag;
    int n = list->m8;

    if (n == 0) {
        /* The file name goes through a local here (only in this branch):
         * that is what orders `lis r5` before `lwz r3` in the original. */
        const char* file = __FILE__;
        int pick = ctx->m554->fn_8014D8AC(count, file, 292);
        list->fn_802709D0(pick, &id, &flag);
    }
    if (n == 1) {
        list->fn_802709D0(list->m14[0], &id, &flag);
    }
    if (n > 1) {
        int pick = ctx->m554->fn_8014D8AC(n, __FILE__, 301);
        list->fn_802709D0(list->m14[pick], &id, &flag);
    }
    return id;
}

int ICommonPlayerID::fn_80270E3C(Unk8014D8AC_Ctx* ctx, int count)
{
    int id = 0;
    int flag;

    if (count == 1) {
        Unk80270730* list = &m4;
        list->fn_802709D0(list->m18[0], &id, &flag);
    }
    if (count > 1) {
        int pick = ctx->m554->fn_8014D8AC(count, __FILE__, 325);
        Unk80270730* list = &m4;
        list->fn_802709D0(list->m18[pick], &id, &flag);
    }
    return id;
}

/* ---- cSignatureChooser ---- */

cSignatureChooser::cSignatureChooser() : Unk8037B3E8(0x29505A6D), m8(1)
{
    m20 = 0;
}

void cSignatureChooser::fn_vslot2()
{
    fn_8037B6B0("sigtype", &m4, "Batting,Pitching,Fielding,HRToFirstCelebration,PowerSwing,BodyType");
    fn_8037B728("playerIDs", "sigids", &m8, 0);
}

cSignatureChooser::~cSignatureChooser()
{
}

Unk8037B3E8* cSignatureChooser::fn_vslot5()
{
    return new (lbl_806EF9B4) cSignatureChooser;
}

int cSignatureChooser::fn_8027101C(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    if (m4 == 4 || m4 == 5) {
        return fn_vslot17(out, obj, 3, 0, 0, 0);
    }
    return 0;
}

int cSignatureChooser::fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f)
{
    Unk8027130C* list = &m8;
    int n = list->m10;
    int id;

    out->type = 1;
    if (n != 0) {
        if (!m20) {
            m20 = 1;
            list->fn_802714FC(0x75A812E8);
            list->fn_802714FC(0x935DD095);
        }
        if (n == 1) {
            id = list->fn_802715D8(0);
        } else {
            Unk80270BA0_X* x = obj->fn_vslot1();
            Unk8014D8AC_Ctx* ctx = x->m44C;
            int key = 0;
            int haveB = 0;
            int b = 0;
            int c2 = 0;

            if (ctx->m6F4 == 1) {
                b = x->mB4C;
                haveB = 1;
                c2 = x->mB50;
            }
            if (m4 == 1) {
                if (!haveB) {
                    key = x->m488;
                } else {
                    key = c2;
                    if (c2 < 0) {
                        key = 0;
                    }
                }
            } else if (!haveB) {
                if (m4 == 3) {
                    int v = fn_8025416C(x->m588, 0x20);
                    if (!fn_8024D9A0(x, &key)) {
                        key = v;
                    }
                } else if (m4 == 4) {
                    if (ctx->m700->m3A4->m128 == 5) {
                        if (x->fn_vslot4()) {
                            key = 3;
                        } else {
                            key = 4;
                        }
                    } else {
                        int r = 0;
                        if (x->m708 <= 1) {
                            r = fn_8025416C(x->m588, 0x21);
                        }
                        if (r == 14) {
                            key = 2;
                        } else {
                            key = fn_8025416C(x->m588, 0x20);
                        }
                    }
                } else {
                    int arg = 0x21;
                    if (m4 != 0) {
                        if (m4 == 5) {
                            arg = 0x2E;
                        }
                    }
                    if (x->m708 <= 1) {
                        key = fn_8025416C(x->m588, arg);
                    } else {
                        key = 0;
                    }
                }
                if (m4 == 5) {
                    key = 0;
                }
            } else if (m4 == 0) {
                key = b < 0 ? 0 : b;
            } else {
                key = 0;
            }
            id = list->fn_80271580(key);
        }
    } else {
        out->type = 0;
        id = 0;
    }
    out->id = id;
    out->m14 = 1.0f;
    return Unk8037B3E8::fn_vslot17(out, obj, c, d, e, f);
}

/* ---- Unk8027130C ---- */

Unk8027130C::Unk8027130C(int arg) : m12(0)
{
    m4 = 0;
    m8 = 0;
    mC = 0;
    m10 = 0;
    m14 = arg;
}

Unk8027130C::~Unk8027130C()
{
    m4 = 0;
    mC = 0;
    if (m8) {
        delete m8;
        m8 = 0;
    }
}

int Unk8027130C::fn_802713D4(signed char key, int* outIndex)
{
    int lo = 0;
    int hi = m10 - 1;

    *outIndex = 0;
    while (hi >= lo) {
        int mid = (hi + lo + 1) >> 1;
        *outIndex = mid;
        if (key == m4[mid]) {
            return 1;
        }
        if (key > m4[mid]) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    *outIndex = (hi + lo + 1) >> 1;
    return 0;
}

void Unk8027130C::fn_80271444(unsigned char key, int value)
{
    int index;

    if (!fn_802713D4(key, &index)) {
        for (int i = m10 - 1; i >= index; i--) {
            m4[i + 1] = m4[i];
            m8[i + 1] = m8[i];
        }
        m4[index] = key;
        m8[index] = value;
        m10++;
    }
}

void Unk8027130C::fn_802714FC(int arg)
{
    Unk8037C7FC* mgr = fn_8037C7FC();

    for (int i = 0; i < m10; i++) {
        int resolved = mgr->fn_8037CE98(arg, m8[i], 0);
        if (resolved) {
            mC[i] = resolved;
        }
    }
}

int Unk8027130C::fn_80271580(unsigned char key)
{
    int index;

    return fn_802713D4(key, &index) ? mC[index] : mC[0];
}

int Unk8027130C::fn_802715D8(int index)
{
    return mC[index];
}

void Unk8027130C::fn_802715E8(char* buf, int len)
{
    if (len) {
        for (int pass = 0; pass <= 1; pass++) {
            char* cursor;
            int remaining;
            char* token;
            int tokenLen;
            char* token2;
            int token2Len;
            int count;
            int done;

            remaining = len;
            count = 0;
            cursor = buf;
            done = 0;
            while (!done) {
                fn_80378E48(&cursor, &remaining, ',', &token, &tokenLen);
                fn_80378E48(&cursor, &remaining, ',', &token2, &token2Len);
                if (token2Len && tokenLen) {
                    if (pass == 1) {
                        int value;
                        if (m14) {
                            value = fn_80378568(token, tokenLen);
                        } else {
                            value = fn_80409DAC(token);
                        }
                        fn_80271444(fn_80409DAC(token2), value);
                    }
                    count++;
                } else {
                    done = 1;
                }
            }
            if (pass == 0) {
                m10 = 0;
                m12 = count;
                m4 = new (lbl_806EF9B4) signed char[m12 * 9];
                if (m8) {
                    delete m8;
                    m8 = 0;
                }
                m8 = (int*)m4;
                mC = m8 + m12;
                m4 = (signed char*)(mC + m12);
            }
        }
    }
}
