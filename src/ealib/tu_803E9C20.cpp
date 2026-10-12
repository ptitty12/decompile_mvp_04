/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803E9C20-0x803EAF50 (code-only unit, 17 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

/* 0x14-byte array holder: m4 = capacity (ints), m8 = storage, m10 = length. */
struct Unk803EA068 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

extern int lbl_8062C680;
extern void (*lbl_8062C66C)(void* p, int size);
extern void* (*lbl_8062C668)(int size, const char* tag);
extern char lbl_8060D944[];
extern char lbl_806AABD0[];
extern char lbl_8062C688[];
extern char lbl_8062C6A8[];
extern char lbl_8060DAA8[];

extern "C" int strlen(const char* s);
extern "C" int strcmp(const char* a, const char* b);
extern "C" char* strcpy(char* d, const char* s);
extern "C" void fn_803EA1E0(Unk803EA068* o);
extern "C" void fn_803E9C20(void* o, const char* s, void* v);
extern "C" void fn_803EABA8();
extern "C" void* fn_803DA440(void* self, void (*fn)(), void* a, void* b, void* c);

/* Open-addressing string hash table: m0 = live entries, m4 = slot count, m8 = slot array. An entry is the value
 * word followed by the NUL-terminated key (allocated strlen + 5 bytes). */
struct Unk803E9E30_Ent {
    int m0;
    char key[1];
};

struct Unk803E9E30_Tbl {
    int m0;
    unsigned int m4;
    Unk803E9E30_Ent** m8;
};

/* near-miss: retail strength-reduces idx*4 into a second counter (addi r31,r31,4; li r31,0 / li r30,0 at the wrap); ours
 * recomputes slwi each pass (about 2-4 slots). */
extern "C" void fn_803E9E30(Unk803E9E30_Tbl* t, const char* name)
{
    if (t->m8 == 0)
        return;
    unsigned int h = 0;
    for (int i = 0; name[i] != 0; i++)
        h ^= (h << 5) ^ name[i];
    unsigned int idx = h % t->m4;
    unsigned int probes = 0;
    for (;;) {
        Unk803E9E30_Ent* e = t->m8[idx];
        if (e && strcmp(name, e->key) == 0) {
            Unk803E9E30_Ent* hit = t->m8[idx];
            if (hit == 0)
                return;
            lbl_8062C66C(hit, strlen(hit->key) + 5);
            t->m8[idx] = 0;
            t->m0--;
            return;
        }
        if (probes > t->m4)
            return;
        idx++;
        if (idx >= t->m4)
            idx = 0;
        probes++;
    }
}

/* near-miss: same as fn_803E9E30. */
extern "C" int fn_803E9F50(Unk803E9E30_Tbl* t, const char* name, int* found)
{
    if (t->m8 == 0) {
        *found = 0;
        return 0;
    }
    unsigned int h = 0;
    for (int i = 0; name[i] != 0; i++)
        h ^= (h << 5) ^ name[i];
    unsigned int idx = h % t->m4;
    unsigned int probes = 0;
    for (;;) {
        Unk803E9E30_Ent* e = t->m8[idx];
        if (e && strcmp(name, e->key) == 0) {
            Unk803E9E30_Ent* hit = t->m8[idx];
            if (hit) {
                *found = 1;
                return hit->m0;
            }
        }
        if (probes > t->m4)
            break;
        idx++;
        if (idx >= t->m4)
            idx = 0;
        probes++;
    }
    *found = 0;
    return 0;
}

extern "C" Unk803EA068* fn_803EA068(Unk803EA068* o)
{
    o->m0 = 0;
    o->m4 = lbl_8062C680;
    o->m8 = 0;
    o->m10 = 0;
    return o;
}

extern "C" void fn_803EA08C(Unk803EA068* o)
{
    fn_803EA1E0(o);
    if (o->m8) {
        lbl_8062C66C((void*)o->m8, o->m4 << 2);
        o->m8 = 0;
    }
}

extern "C" void fn_803EA0E4(Unk803EA068* o, int chrg)
{
    fn_803EA1E0(o);
    if (o->m8) {
        lbl_8062C66C((void*)o->m8, o->m4 << 2);
        o->m8 = 0;
    }
    if (chrg & 1)
        lbl_8062C66C(o, 0x14);
}

extern "C" char* fn_803EA160(void* o, const char* s, int v)
{
    int* p = (int*)lbl_8062C668(strlen(s) + 5, lbl_8060D944);
    char* name = (char*)(p + 1);
    *p = v;
    strcpy(name, s);
    fn_803E9C20(o, s, p);
    return name;
}

extern "C" void fn_803EA1E0(Unk803EA068* o)
{
    if (o->m8 != 0) {
        unsigned int i = 0;
        if (i < (unsigned int)o->m4) {
            do {
                char* e = ((char**)o->m8)[i];
                if (e != 0)
                    lbl_8062C66C(e, strlen(e + 4) + 5);
                ((int*)o->m8)[i] = 0;
                i++;
            } while (i < (unsigned int)o->m4);
        }
    }
    o->m0 = 0;
    if (o->m10 != 0) {
        do {
            int* n = (int*)o->m10;
            o->m10 = n[2];
            lbl_8062C66C(n, 0xc);
        } while (o->m10 != 0);
    }
    o->m10 = 0;
}

extern "C" int fn_803EA2C4(unsigned char* t, int bit)
{
    int i = bit / 8;
    unsigned char b = *(unsigned char*)(((int)t) + i + 2);
    if ((b >> (bit & 7)) & 1)
        return 1;
    return 0;
}

extern "C" int fn_803EA320(int n);

extern "C" int fn_803EA2FC(unsigned short* p)
{
    return fn_803EA320(*p);
}

extern "C" int fn_803EA320(int n)
{
    return (n + 7) / 8 + 2;
}

/* static initializer: registers the node lbl_806AABD0 */
extern "C" void fn_803EAEC4(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize)
        fn_803DA440(lbl_806AABD0, fn_803EABA8, lbl_8062C688, lbl_8062C6A8, lbl_8060DAA8);
}

extern "C" void fn_803EAF24()
{
    fn_803EAEC4(1, 0xFFFF);
}
