/*
 * Translation unit at 0x803D9FE8 (EA library; original file name unknown).
 *
 * .text 0x803D9FE8-0x803DA188, .bss 0x806AA920-0x806AA984,
 * .ctors 0x805A2CDC (static init fn_803DA15C).
 */

struct lbl_Node;

/* Object at +0x8 of the owner: list head at +0xC, current node at +0x8. */
struct lbl_Impl {
    char pad0[0x8];
    lbl_Node* mCur;
    lbl_Node* mHead;
};

struct lbl_Node {
    char pad0[0x1A4];
    lbl_Node* mNext;
    char pad1A8[4];
};

class lbl_Owner {
public:
    char pad0[0x8];
    lbl_Impl* m8;

    void fn_803DA038();
    void fn_803DA098(lbl_Node* node);
    lbl_Node* fn_803DA148();
    void fn_803DA154(lbl_Impl* impl);
};

extern void* (*lbl_8062C668)(int size, int heap);
lbl_Node* fn_803E1F98(void* mem, lbl_Owner* owner);
void fn_803E2188(lbl_Node* node, int flags);

struct Unk803D9FE8 {
    int a, b, c;
    Unk803D9FE8(int x, int y, int z) : a(x), b(y), c(z) {}
};

struct Unk803D9FE8Big {
    Unk803D9FE8 s;
    char pad[0x4C];
    Unk803D9FE8Big(int x, int y, int z) : s(x, y, z) {}
};

Unk803D9FE8 lbl_806AA920(4, 4, 1);
Unk803D9FE8Big lbl_806AA92C(3, 3, 1);

void lbl_Owner::fn_803DA038()
{
    lbl_Node* node = fn_803E1F98(lbl_8062C668(0x1AC, 0), this);
    node->mNext = m8->mHead;
    m8->mHead = node;
}

void lbl_Owner::fn_803DA098(lbl_Node* node)
{
    lbl_Impl* impl = m8;
    if (node == impl->mHead) {
        impl->mHead = node->mNext;
        if (node)
            fn_803E2188(node, 3);
    } else {
        lbl_Node* p = impl->mHead;
        while (p && p->mNext != node)
            p = p->mNext;
        lbl_Node* found = p->mNext;
        p->mNext = found->mNext;
        if (found)
            fn_803E2188(found, 3);
    }
    if (node == m8->mCur)
        m8->mCur = 0;
}

lbl_Node* lbl_Owner::fn_803DA148()
{
    return m8->mCur;
}

void lbl_Owner::fn_803DA154(lbl_Impl* impl)
{
    m8 = impl;
}
