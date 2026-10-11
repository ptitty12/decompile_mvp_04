#line 1 "C:/mvp2004/source/common/animation/choosers/randomloadedchooser.cpp"
/*
 * C:/mvp2004/source/common/animation/choosers/randomloadedchooser.cpp
 * (path string at 0x805DCE8C, passed to the RNG's file/line arguments by
 * vtable slot 17, 0x8027985C).
 *
 * .text 0x80279758-0x80279AE4, .rodata 0x805DCE7C-0x805DCEE8,
 * .data 0x8061E698-0x8061E69C.
 *
 * cRandomLoaded: vtable 0x80661F38 slot 3 (0x802ACB34) returns the pointer at
 * 0x8061E698 -> "cRandomLoaded". It embeds the weights-list helper from
 * randomchooser.cpp (ctor 0x8026FEB8, dtor 0x8026FF08); "a" and "weights"
 * (0x805DC538, 0x805DC53C) belong to that unit too.
 */
#include "game/chooser_base.h"

extern unsigned int lbl_8068D580;         /* cRandomLoaded type hash (also read by 0x802AA7A4, 0x802ACB40) */
extern Unk802AE984_Mgr* lbl_8061E978;

/* Both strings live in randomchooser.cpp's .rodata. */
extern const char lbl_805DC538[];         /* "a" */
extern const char lbl_805DC53C[];         /* "weights" */

/* One accepted candidate while picking: list index and its weight. */
struct Unk8027985C_Pick {
    int id;
    float weight;
};

/* Class name; read by cRandomLoaded's vtable slot 3 (0x802ACB34). */
const char* lbl_8061E698 = "cRandomLoaded";

class cRandomLoaded : public Unk80362C2C {
public:
    /* Declared first and defined in the unit at 0x802AC8xx (vtable slots 3/4),
     * which makes g++ 2.95 emit this class's vtable there, as in retail. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cRandomLoaded();
    virtual ~cRandomLoaded();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f);

    Unk8026FEB8 m4;            /* "a"/"weights" */
};

cRandomLoaded::cRandomLoaded() : Unk80362C2C(lbl_8068D580)
{
}

void cRandomLoaded::fn_vslot2()
{
    fn_8037B728(lbl_805DC538, lbl_805DC53C, &m4, 0);
}

cRandomLoaded::~cRandomLoaded()
{
}

Unk8037B3E8* cRandomLoaded::fn_vslot5()
{
    return new (lbl_806EF9B4) cRandomLoaded;
}

int cRandomLoaded::fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f)
{
    Unk80270BA0_X* x = obj->fn_vslot1();
    Unk8026FEB8* countList = &m4;
    Unk8027985C_Pick picks[100];
    float total = 0.0f;
    int count = 0;
    int n = countList->m4;
    int i;

    if (n > 100) {
        n = 99;
    }
    /* Collect the entries that pass the filter, with their weights. */
    for (i = 0; i < n; i++) {
        /* Declared per iteration, as in playeridchooser.cpp: with one pointer
         * for the whole function the final fn_80270074 call below would
         * reuse it (mr r3,rX) instead of recomputing this+4. */
        Unk8026FEB8* list = &m4;
        int id;
        float weight;

        list->fn_80270074(x, i, &id, &weight);
        if (fn_802AE984(lbl_8061E978, list->fn_8026FF6C(i))) {
            picks[count].id = i;
            picks[count].weight = weight;
            total += weight;
            count++;
        }
    }
    if (count > 0 && !(total <= 0.0f)) {
        float cum = 0.0f;
        float r;
        /* The file name goes through a local, which orders `lis r5` before
         * `lis r4` (same as ICommonPlayerID::fn_80270D64). */
        const char* file = __FILE__;
        float unused1;         /* never read: only reserves stack slot 0x334 */
        float tot = total;
        float unused2;         /* never read: only reserves stack slot 0x33C */
        int chosen = -1;
        int j;
        int pickId;
        float pickWeight;

        /* Roll in [0, total): rand(1000000) is converted as unsigned. */
        r = (float)(unsigned int)x->m44C->m554->fn_8014D8AC(1000000, file, 116) * tot * 0.000001f;
        /* The last entry is never tested: it is the fall-back. */
        for (j = 0; j < count - 1; j++) {
            if (cum >= r) {
                continue;
            }
            if (!(picks[j].weight + cum <= r)) {
                chosen = picks[j].id;
            }
            cum += picks[j].weight;
        }
        if (chosen == -1) {
            chosen = picks[count - 1].id;
        }
        m4.fn_80270074(x, chosen, &pickId, &pickWeight);
        out->type = 1;
        out->id = pickId;
        out->m14 = 1.0f;
    } else {
        out->type = 0;
        out->id = 0;
        out->m14 = 0.0f;
    }
    return Unk8037B3E8::fn_vslot17(out, x, c, d, e, f);
}
