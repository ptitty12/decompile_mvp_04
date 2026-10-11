#ifndef GAME_CLAMPITER_H
#define GAME_CLAMPITER_H

/*
 * Loop counter that retail keeps in a stack slot: `lwz r9,8(r1); cmpwi r9,MAX;
 * addi r11,r9,1; ble; mr r11,r9; mr r0,r11; stw r11,8(r1)` (fn_8006A138 and
 * about a dozen siblings: loops over 0..MAX whose step saturates at MAX+1).
 *
 * Evidence for the shape: a class with a user-declared destructor is not promoted
 * to a register by g++ 2.95 (the object stays in the frame), Next() returns the new
 * value (the loop variable is a separate register copy `idx = it.Next()`), and the
 * if/else form (`if (v > MAX) t = v; else t = v + 1;`) gives retail's compare-first
 * schedule. The type itself is a placeholder; nothing proves the original name.
 */
template <int MAX>
struct Unk8006A138_It {
    int v;
    Unk8006A138_It(int x) { v = x; }
    ~Unk8006A138_It() {}
    int Next()
    {
        int t;
        if (v > MAX)
            t = v;
        else
            t = v + 1;
        v = t;
        return t;
    }
};

#endif
