# Matching patterns (ProDG 3.9.3 / g++ 2.95.3, game code)

Recipes that have produced byte-identical matches here. They are claims, not
evidence: the verifier decides. Add a line when a pattern matches twice.

## Chooser units (`src/animation/choosers/*`)

- One file per chooser class. Helper classes it embeds come first in the file,
  then `const char* lbl_<addr> = "cName";` (the vtable slot 3 name pointer),
  then the chooser's methods in .text order.
- Declare the slot 3 and slot 4 overrides first in the class. They are defined
  in the unit at 0x802AC8xx, so g++ emits the vtable there, as in retail.
- If vtable slot +0xC (the dtor) points into 0x802ACxxx, declare no destructor:
  the implicit one is emitted with the vtable.
- Constructor: `cX::cX() : Unk80362C2C(lbl_name)` or `: Unk80362C2C(hash)`,
  with `#include "game/chooser_base.h"`. Unk80362C2C is the chooser base
  (dtor 0x80362C2C); Unk8037B3E8 is the root (dtor 0x8037B424). Deriving
  choosers straight from the root gives the wrong dtor call (fixed
  2026-10-11, work/false-matches).
  Lazily hashed statics: `if (!a || !b) { a = fn_80378568("x", len); ... }`.
- Slot 5 (factory): `return new (lbl_806EF9B4) cX;`. `new` has no null check.
- Slot 2 (attributes): `fn_8037B6B0(lbl_805DC394, &m8, "EnumA,EnumB")` for an
  enum, `fn_8037B728("listname", "itemname", &mC, 0)` for an embedded list.
- Slot 17 tail: `return Unk8037B3E8::fn_vslot17(out, x, c, d, e, f);`. Passing
  `x` (Unk80270BA0_X*) as the Obj* produces the null-checked `x ? x+0x5F0 : 0`.
- A string or object that another unit also references is a global
  (`const char lbl_X[] = "...";`), defined where retail's .rodata order puts it
  (e.g. "Stand" right after the constructor in tu_80271C64.cpp).

## g++ 2.95 ABI

- Destructors take an in-charge argument; `andi. r0,rX,1` then
  `__builtin_delete` is the deleting part. Member dtors get in_chrg 2.
- Vtable entries are 8 bytes `{delta, pfn}`; entry 0 is the (empty) RTTI slot,
  virtual N is at +8N. Calls load `lha delta` and `lwz pfn`.
- The vptr goes after the data of the class that introduces virtuals.
- `delete` = `__builtin_delete` (0x80377408), `delete[]` =
  `__builtin_vec_delete` (0x80377488), `new[]` = `__vn__FUii` (0x803774A8),
  `new(heap)` = `__nw__FUii` (0x80377428).
- Plain `char` is signed (callers `extsb`); `clrlwi r,r,24` on a parameter
  means `unsigned char`.

## Code generation (`-Os -ffloat-store`)

- The scheduler hoists the last-written field above the vptr store.
- An initializer-list member gets its own zero register.
- `lis r5,...` before `lwz r3,...` means r3 is the object of a method call.
- Identical clamps are cross-jumped; a ternary select avoids that.
- `if (n) {...} else {zero}` puts the zero case last.
- `-ffloat-store`: every assignment to a float variable is `stfs` then `lfs`
  from its stack slot. Inlined functions' float parameters and locals get
  their own slots. Temporaries stay in registers.
- `fcmpu` + `cror un,eq,lt` + `bso` branches on `a <= b`
  (`cror un,eq,gt` is `>=`).
- `(float)floor(x)`: `frsp` after the call, then single-precision math.
  `x * k + c` in float becomes `fmadds`.
- int to float uses the `0x4330000080000000` double constant and `xoris`.
- Float constants: one pool per function, in order of first use, no sharing
  between functions (duplicates in .rodata are normal).

## Learned on cLinearChooser (W3, 2026-10-10)

- Float branches: when the target has `cror`+`bso`, write the negated
  comparison: `if (!(a <= b || a >= c))`, `if (!(d <= eps))`,
  `if (!(e.m8 <= a)) { idx = i; break; }`. A plain `a > b && a < c` gives bare
  `ble`/`bge`. A ternary `c ? x : y` emits `t = y; if (c) t = x`.
- A `const float` local is stored once, and its register (e.g. f31) is reused
  after later calls instead of being reloaded from its slot.
- `const Vec3& pos = x->m60;` declared before the calls makes `x+0x60` a
  callee-saved pointer computed up front. Inline `x->m60` computes it after.
- Stack slots: float locals and by-value struct temps are scoped temp slots,
  split from the end of a freed chunk, so declaration order maps to address
  order in reverse. Struct temps are 8-aligned. An inline function returning a
  struct copies its local into the caller's slot.
- `(&m8[idx])[-1].m8` gives `add r7,r8` order and a `-8(r9)` displacement.
  `m8[idx-1]` folds differently; reads through `int lo = idx - 1` don't fold.
- Statement order of independent stores (`out->type`, `out->id`, `out->m14`;
  constructor field inits) changes the whole function's register allocation.
  Try permutations; a 24-permutation loop takes about a minute.
- Chooser slots 13/14: `return m4 ? 0 : fn_vslot17(out, obj, 3, 0, 0, 0);` and
  `if (m4 == 2) return fn_vslot17(...1...); if (m4 == 0) return fn_vslot17(...3...); return 0;`.

## Tooling tricks

- Register-allocation dumps: `ngccc -E ... -o x.i`, then
  `cc1plus.exe -Os -G0 -ffloat-store -fno-rtti -fno-exceptions -quiet -dg -dl x.i -o x.s`
  writes `x.i.greg`/`x.i.lreg` ("regs to allocate", "Register dispositions").
- Before symbols.txt is renamed, diff_unit shows functions as MISSING:
  `objcopy --redefine-sym old=new` on the compiled object, then
  `tools/match/cmp_objects.py`, gives the real comparison. Or run
  `tools/scout/rename.py <unit> --write` first.
- For scoring source variants, a difflib ratio over instruction lists works
  (a full-text ratio doesn't, because of relocations).

## EA libraries (-O2), learned by W4 (2026-10-11)

- EA lib code is `-O2`: `-Os` doesn't hoist invariant `lis`/`li` into
  callee-saved registers or produce pre-tested loops.
- `extern volatile PPCWGPipe GXWGFifo;` gives `lis 0xcc01` / `-0x8000(rX)`
  (a literal 0xCC008000 gives `lis`/`ori`). objdiff accepts the HA/LO relocs.
- An if/else-if chain gives a linear `cmpwi` chain; a switch gives a binary
  search.
- Stack objects must have their real size, or the frame and `&v` addressing change.
- `GXColor c = {0xff,0xff,0xff,0xff};` by value gives lis/stw/3x stb plus a temp copy.
- An `unsigned char` loop var with `int next = i + 1;` before the inner loop
  and `i = next;` after gives the early `addi` and late `clrlwi`.
- `per = x / m; per = per / 12 * 12;` as two statements gives retail's quotient
  register; `n *= m; n += 3;` gives in-place mullw/addi.
- Loading call arguments into locals before an if hoists the loads above the
  branch, as retail does.
- A 64-byte struct assignment compiles to the 24+24+16 word-copy loop.
- Clone families: write one unit, then generate the others by substituting
  the relocated symbols (derive the map from the asm); don't hand-port.

## Register allocation (GCC 2.95 global-alloc), learned on the EA-lib families

- Priority of a pseudo = floor_log2(refs) * refs / live_length. Read
  "Register N used R times across L insns" in the `.lreg` dump and compute it.
  The higher-priority pseudo gets the first free register (e.g. r9).
- If an inner loop counter steals the outer counter's register, declare the
  outer counter once per block and reuse it across sibling loops: its refs
  grow faster than its live length, so its priority rises. Sharing across
  unrelated branches can make it worse; search the subsets with a script.
- A flag set next to a call (`first = 1; call(...)`) changes the order of the
  argument moves; try the assignment after the call.

## More chooser idioms (randomchooser.cpp)

- Two call sites with the same tail (`if (f) return g(x, a, ...); return g(x, b, ...);`)
  produce the cross-jumped shared tail; a single call with a selected index
  gives different registers.
- `blt` straight to an assert call: write `value < 0.0 || !(value <= x)`.
- Binary search with `cror gt; bso`: `if (!(value >= sum)) top = mid; else lo = mid + 1;`.
- A function-wide pointer for a count load plus a per-iteration
  `T* list = &m;` inside the loop body (two matches now).
- `(float)(unsigned int)x` uses the 0x4330000000000000 constant (signed:
  0x4330000080000000).
- `__FILE__`: units start with `#line 1 "C:/mvp2004/source/..."` (DECISIONS).

## More from the warp, path and EA-setup workers (2026-10-11)

- `-ffloat-store` doesn't force a float inside a one-float struct local to
  memory: a conditional `u.f = 0.0f` becomes a register `fmr` select.
- Out-of-line clamp branch: `if (!(t > 255.0f)) {clamp} else r = 255;` gives
  retail's `bgt` to an out-of-line `li r4,255`.
- Indexed member arrays: an inline `Entry* At(Entry* a, int i) { return &a[i]; }`
  gives `mulli; add rX,this,rX; lwz 0x44(rX)`, where `m20[i].m24` gives
  `addi; lwzx`.
- Struct copies through an inline by-value getter (`mA4 = GetPos(x)`) give
  retail's temp-slot copy; a local copy doesn't. Passing a by-value getter's
  result to a `const Vec3&` parameter gives direct frame stores.
- Inline `Clear()` methods on sub-structs give the `stw 0(...)` plus
  `addi rP,this,off` shape.
- A constructor that returns `this` copies r3 (`mr r9,r3`); no copy in the
  prologue means a plain method.
- Inline mid-class ctor `Mid(unsigned h) : Root(h) {}` leaves only the
  final vptr store in the derived ctor; `~X() {}` gives vptr store plus
  `bl <mid dtor>` passing r4 through.
- A frame bigger than the visible locals: an unused `char buf[N]` local
  reproduces it (fn_802A3974).
- EA lib float literals: write `0.5f` etc.; an `extern const float` gets
  CSE'd into a callee-saved register.
- Under -ffloat-store, re-read `a->m0[k].m4[i]` in every float assignment
  (no local pointer): retail reloads after each float store.
- Ctor float inits: chained assignments (`m3C = m40 = 0.0f;`) store the left
  one first; a generator plus variants.py found ctor orders that plain
  permutations missed.
- Read `cc1plus -da` dumps (jump/cse/sched/greg) before a blind variant search
  when a register or ordering difference persists.

## In-place float clamp: g++'s `>?` / `<?` operators (warps-B worker, 2026-10-11)

- Retail clamps that keep the value in its own register with one shared
  `fmr` come from GNU C++'s min/max operators: `a >? b` is max, `a <? b` is min.
  `>?` expands as `r = x; if (r >= lo) skip; r = lo`.
- Typical forms: `x > hi ? hi : (x >? lo)`, or `!(x > hi) ? (x >? lo) : hi`
  when retail lays the hi arm out after the lo arm. Plain if/else or ternary
  chains never produce the shared `fmr` (that was ~190 failed forms on
  fn_8026FDB0).
- Other warps-B notes: a data-less mid class with an implicit dtor forwards
  (r4 unchanged) to the base dtor; inline virtual no-ops of a mid class are
  still emitted as separate functions; `a*b + c*d` fuses the first product
  into fmadds, so write the fused term first; arguments are evaluated right to
  left (`m8 + d + x->m960` copies the by-value operand first).

## In-place float clamp (hard-case pass, 2026-10-11)
- Retail's [lo, hi] clamp (the result stays in the register that held the
  value, one shared `fmr` per bound, a single `stfs`) uses g++'s maximum
  operator for the low bound:
  `t = !(t > hi) ? (t >? lo) : hi;` gives `bgt` to the hi arm placed last;
  `t = !(t <= hi) ? hi : (t >? lo);` gives `cror lt` + `bso` with the hi arm
  first. A low bound alone is `t = t >? lo;`.
- Why it works: `a >? b` is MAX_EXPR, expanded as `r = a; if (r >= b) skip;
  r = b`. The test reads r itself, so jump.c's "if (...) x = a; else x = b"
  to "x = b; if (...) x = a" rewrite (post-CSE jump pass) can't hoist a copy
  of t above the test. Every if/else or ternary spelling has a plain `R = t`
  arm, which CSE turns into a register copy that gets hoisted. t and R then
  conflict and need two registers.
- fold swaps `!(c) ? const : t` into `c ? t : const` (the constant arm goes
  last whenever the condition can be inverted), so a negated compare can't
  keep the 0.0 arm first in a ternary.
- Matched: fn_8026FDB0 (tu_8026DDE8), fn_8027EFB8 (six clamps, tu_8027DE3C).
  fn_8027A0B8 (tu_80279AE4) also matches as
  `r = !(t > 255.0f) ? (int)(t >? 0.0f) : 255;`; it is currently written with a
  one-float struct. The warps-B worker matched the same form in tu_802A4584.
- `<?` is MIN_EXPR with an `le` test (`cror lt` + `bso` over the `fmr`). It
  is not retail's `bgt` hi test; no retail use of it has turned up yet.
## Vec3 copy destination addressing (hard-case pass, 2026-10-11)
- Tell: `addi rP,r1,k` before a 12-byte copy, word 0 stored to `k(r1)`, and
  words 1 and 2 to `4(rP)` and `8(rP)`. rP may be callee-saved if a call
  follows. Retail stores all three words to `k(r1)`, `k+4(r1)` and `k+8(r1)`.
- Cause: a struct copy written in the function itself (local init, or the
  by-value argument of an inline) goes through emit_block_move with its
  destination address forced into a pseudo (a BLKmode `(plus sp k)` is not
  accepted as an address). CSE folds that pseudo back into `k(r1)` only for
  offset 0. The same copy inside an inlined body comes out direct, because
  integrate.c substitutes the inline frame pointer's constant value
  (subst_constants) into every address.
- Recipe: move the copy into an inline.
  `inline Vec3 Pos(const Goal* g) { return g->m10 + g->mD8; }` then
  `Vec3 v = Pos(g); return v;` matched fn_80286E70 and fn_80286F00.
  `Vec3 pa = Pos0(g);` with `inline Vec3 Pos0(g) { return g->m10; }`, instead
  of `Vec3 pa = g->m10;`, fixed the pa copy in fn_802857C4. The pointer to pa
  is then formed only after the call, as in retail.
- Vec3 here is a POD struct (Unk80273498_Vec3) with free inline operators
  (`operator+(Vec3, const Vec3&)`, `operator-(const Vec3&, const Vec3&)`), and
  no constructors.
- Related: fold distributes `(c ? a : b) - u` into both arms when u is a local.
  Wrapping the ternary in an inline (`Speed(e) - u`) keeps one subtraction
  after the join (fn_802857C4).
- Each inline's frame is its own 8-byte-aligned block. A float passed through
  two inline layers (`SetAngle(p, v) { SetAngle2(p, v); }`) takes two slots
  0x8 apart, retail's 0x30/0x38 in fn_8027F504.

## Big boilerplate families across game code (lead survey, 2026-10-11)

Shape clusters over unmatched game .text (relocations masked). Each has a
known recipe; generate the members with a script once one matches.

| Family | Count | Shape | Recipe |
|---|---|---|---|
| factory, 0x30 | ~144 | `lis/lwz lbl_806EF9B4; li r3,SIZE; bl __nw__FUii; bl ctor` | `return new (lbl_806EF9B4) X;` (X's ctor out of line) |
| dtor, 0x30 | ~159 | `stw <vtable>,8(this); bl fn_80378620` | `X::~X() {}` where the vptr is at +8 and the base dtor is fn_80378620 (non-deleting variant, or a member with inline dtor) |
| dtor+delete, 0x34 | ~56 | `stw <vtable>,0x20(r3); andi. r0,r4,1; beq; bl __builtin_delete` | out-of-line `X::~X() {}` with vptr at +0x20 |
| hash wrapper, 0x20 | ~159 | `bl fn_80378568` passing r3/r4 through | out-of-line copies of an inline `unsigned Hash(const char* s, int n) { return fn_80378568(s, n); }` |
| forwarder, 0x24 | ~131 | `lwz r3,OFF(r3); bl f` | `void X::f() { mOFF->g(); }` / `g(mOFF)` |
| static-call, 0x2C | ~58 | `lis/addi r3,&lbl; li r4,K; bl f` | `f(&lbl_X, K);` |

`python <scratchpad>/tools/families.py . LO HI` (lead's scratch tool) lists
the families with example addresses; ask the lead if you need it.

## Game-code sweep notes (sweep workers, 2026-10-11)

- Trace wrappers come in two families: A `fn_80056C9C(K); lbl_80624408(fn_80391C04(0, 0, LINE), N, a..);`
  and B `lbl_80624408(fn_80391C04(K, 0, LINE), N, a..);` (no fn_80056C9C). LINE > 0x7FFF
  loads as `li r5,0; ori r5,r5,LINE`. Generators: scratchpad S0/gen.py, S8/gen.py.
  Open: family B with K != 0 and N == 0 has `li r5` before `li r3` in retail (not reproduced;
  mechanism under "Hard-case families" below).
- Float parameters compared against double literals: write `x < 0.2`, not `0.2f`, when retail
  loads an 8-byte constant (`lfd`).
- Byte tables: use `unsigned char*` (plain char is signed and adds `extsb`).
- Table rows: keep `lbl_X[idx].mXX` in each expression for retail's `addi base,off; lwzx`;
  a cached element pointer gives `lwz off(rX)`.
- Slot arrays with a 0x1C stride: `char* b = (char*)t + 0xC; *(int*)(b + i*0x1C)`.
- `int f = a < K; r = f << n;` gives the `fcmpu cr7; mfcr; rlwinm` bit extraction;
  `(unsigned)a <= K ? mask : 0` gives `subfic/subfe/nand`.
- `a == 0 ? 2 : 1` gives `li 1; bnelr; li 2`; the if-return spelling gives the opposite order.
- A virtual call taking a by-value POD temporary: declare the parameter `const Z&` and give Z an
  inline ctor `Z() : m0(0), m4(0), m8(0) {}` (by-value gives an extra memset and copy).
- A global struct (`lbl.m0`) keeps its load after `this->` stores; a scalar global gets hoisted.
- Functions whose code needs instructions only inline asm emits (`mftb`, `mfspr`, ...) stay as
  original asm: CLAUDE.md forbids asm. Note them in the unit.

## Near-miss sweep (W4, 2026-10-11)
Recipes that matched 18 parked functions (details in each unit's comments):
- Stack slots: a freed temp slot is reused only by an object of the same machine
  mode. BLKmode objects (structs, arrays, inline frames) reuse BLKmode slots;
  SFmode float locals take fresh ones. `float t0, t1, t2` instead of
  `float th[3]` kept a Vec3 temp's slot free for a later Vec3 (fn_8027B924).
- An inline's float parameters live in its (BLKmode) frame, so routing a value
  through `AbsF(float v)` or `SetF(float* p, float v)` puts it in a reusable
  frame slot where a float local would get a fresh one (fn_8027BA64: one AbsF
  per AngleDiff keeps the two frames apart; fn_8027AD3C, fn_802857C4).
- An inline's locals are allocated at its entry, before the frames of the
  inlines it calls: one `GoalDist2D(g)` holding `Vec3 d = EntPos(..) - FlatPos(..)`
  put d below the getter frames as retail (fn_802855C4).
- Inline parameter pseudos are not pointer-flagged. Passing `&x->m734` to an
  inline (instead of a `T* p = &x->m734` local) makes regclass give the index
  offset BASE_REGS (r9, not r0) and keeps `x+0x734` in a register with grouped
  `(idx*4)+off` offsets (fn_8027FC80, fn_802A3D8C, fn_8027EC58). Side effect:
  alias analysis no longer knows the base, so stores through it keep their
  order against frame accesses (fn_802931D0, fn_80296030 stay open on this).
- A fresh `&x->m734` per use (GetI/SetI inlines) also stops gcse from reusing
  an earlier load through another pointer pseudo (retail reloads m190).
- History-slot writes: `int off = i * 4 + K; *(int*)((char*)p + off) = v;`
  called with `i = m190 - 1` inside `if (m190 == 1)`: CSE substitutes v's zero
  register, giving `li r9,K; stwx` for v == 0 and a displacement for v != 0
  (fn_8027EC58, fn_80280F08).
- Clamp result stored in each arm (`if (!(v <= 0)) v = ...>?...; else v = 5;`):
  jump2 runs after sched2 and cross-jumps the per-arm stfs into the join, so
  sched2 sees a join block starting with the reload (fn_8027F504).
- `int k = 5;` before `m95C = 0; m958 = k;` emits the 5 first, which changes
  the local-alloc ranges (the 0 gets r0). Same idea: `int hit = 0;` before a
  call keeps hit in a callee-saved register (fn_8027B1A0).
- `extern const int` for globals set once by a static initializer: unchanging
  loads may be scheduled past stores (cTimeWarp ctor's two type-id loads).
- `if (lo > v) v = lo;` inside an inline with `lo` a parameter keeps the
  constant in a register for compare and store (`li r9,3; cmpw r9,r0`).
- Bit tests through an inline accessor (`fn_IsF14()`) stop combine from
  folding the test onto the word before a preceding bitfield clear.
- A byte field read through an int-returning inline compares signed (`cmpwi`);
  the direct `unsigned char` compare is shortened to `cmplwi`.
- Calling another class's method as `((Base*)this)->fn(...)` (not a free
  function taking `this`) moves the `mr r3,rX` after the other argument moves.
- Sub-object clears as inline `Clear()` methods called from the constructor
  body: the word at offset 0 folds to a frame address, the others stay on the
  pointer (fn_8027A9AC: bitfield in a 4-byte struct, triple m0/m4/m8).
- Lerp as `a + t * (b - a)` gives `fmadds t, (b-a), a`; const float locals keep
  their registers after the store (fn_80296624, fn_802958F4).
- Reusing a function-scope loop counter in a second loop gave retail's
  count-down copy loop instead of bdnz (fn_8026FB80); a loop bound read through
  an inline taking `&mC` lets the bottom test reuse the body's pointer.
- Check case routing against the asm: fn_8028C264's switch had 6 of 11 hashes
  going to the success path, not to `fail`.

## Range-02 recipes (tablemanager, game-flow; worker report 2026-10-11)

- Volatile enum iterator: loops over a 0..N enum keep the counter in a
  `volatile int sp8` slot with a saturating increment,
  `c = sp8; if (c > N) t = c; else t = c + 1; sp8 = t; e = t;` (write `sp8`
  before `e`). Test-first inner loops: `while (sp8 = t, e = t, e < cnt)`.
  Nested loops: declare the inner volatile before the outer to get the slot
  order (fn_80097238, fn_800A3270, fn_800A6114, fn_800A50F0).
- Independent field stores (state setters) match in exactly one of the
  24..144 orderings; an itertools.permutations script finds it in under a
  minute (fn_800A2598, fn_800A2688, fn_800A2948).
- A loop bound like `Db() ? Db()->m4 : 0` must be an inline accessor
  (`inline int RowCount()`): the hand-inlined ternary does not give retail's
  single-compare shape. `unsigned i` against it gives `cmplw`.
- 0x30-byte record copies through pointer locals (`Row30* d = ..; Row30* s =
  ..; *d = *s;`) give the 24+24 copy loop; a cast-assign does not.
- `if (p->m9C == 1) return p->mA0; <rest>` puts the cheap return last as
  retail does (fn_800A39C4); `if (m9C != 1) {...}` does not.
- Boolean returns: `if (id != -1) { ..; return 1; } return 0;` vs
  `int ok; if (id == -1) ok = 0; else {..} return ok;` are distinct shapes;
  `int ret = 0; if (..) {..; ret = 1;} return ret;` gives `li r3,0` first.
- Inline setter taking a float (`inline void SetM18(C* c, float v)`) adds the
  spill slot at sp+0x10 (fn_800A5BB8).
- `delete p` on a class with an extern non-virtual dtor: `cmpwi; li r4,3; bl
  dtor` (fn_800A28C4). `new (0) int[n]` gives `__vn__FUii(n*4, 0)`;
  `delete[] p` gives `__builtin_vec_delete`.
- Open: retail recomputes `addi rX,r1,buf` per use of `&buf` across calls
  (strcpy chains); ours keeps it in a saved register (fn_800A3DF8 and two
  v8 name-swap methods in tu_80094578).

## Switch trees (sweep-5 report, 2026-10-11)

- Enum-typed switch index: with an `int` index and every case value in
  0..127, g++ 2.95 uses its ASCII cost table (alnum cost 16, punct 8) to pick
  the pivot. With an enum index it balances by node count. If the target's
  root is the middle by count and yours is not, declare
  `enum E { E_Neg = -1, E_Lo = lo, E_Hi = hi };` and write `switch ((E)kind)`.
  The negative enumerator keeps the compares signed (`cmpwi`). This matched
  fn_80059BDC (49 cases) in one shot.
- group_case_nodes merges consecutive values whose labels are adjacent, or
  whose bodies only jump to the same label, into range tests. To keep one
  compare per value:
  - give each empty case a non-jump first insn, such as a dead
    `T* q = &r->field;` that is eliminated later;
  - never let consecutive values share a label (duplicate the body).
  Cases that `return 0` start with `li` and stay unmerged (fn_80055204, fn_80054DEC).
- Open: fn_80055D84 balances as if the case list were two nodes longer than
  the 33 visible values.
- If the target holds the switch index in r4 and yours is in r0, the original
  passed the index to a call in the default branch (a vararg diagnostic
  `fn_8033E958(fmt, kind)`). global-alloc then prefers r4.
- Per-case locals: one `q` declared in each case matched; a single shared `q`
  swapped the obj/q registers.
- A set difference of the target's `cmpwi` immediates against the source's
  `case` values tells at once whether a switch near-miss is a case-set problem
  or a tree problem.
- Compiler dumps: run cc1plus with `-dg -dl -dr -ds -dR` (SN_NGC_PATH set) to
  get `.lreg` (pseudos, uses, live length) and `.greg` ("Register
  dispositions") for allocation questions.
- Open (several units): SumRow-style byte-index loops (fn_80053220,
  fn_80054684, fn_8005CDC4). Retail puts the index in r9 and the element
  address in r11; ours uses r0/r9. Element addresses formed as `add off,base`
  in retail vs `add base,off` (fn_80056A68, fn_80056AC0).

## Range-09 recipes (screen classes, 2026-10-11)

- Families that match first try:
  - vptr store plus base dtor with the in-charge arg passed through;
  - deleting dtor `if (c & 1) fn_80377408(p)`;
  - `this->sN()` thunks;
  - an 8-byte struct passed by value;
  - `new (lbl_806EF9B4)` factories;
  - lazy singleton getters.
- Out-of-line base ctor from an extern "C" ctor:
  `new (p) Unk8037B3E8(hash); *(const void**)p = vtbl; return p;`, with
  `inline void* operator new(unsigned, void*)`.
- Explicit dtor of a global with in-charge 2: `lbl.Unk8001FE34::~Unk8001FE34();`.
  The qualified name stops virtual dispatch.
- `delete p->m8[i]` on a class with a virtual dtor calls slot 1 with arg 3.
  Declare `virtual ~VT18();` as slot 1.
- `int a = c ? f(x) : 0; int r = a;` keeps the ternary in r3 and copies it to
  the callee-saved accumulator after the join.
- Retail's separate callee-saved `lis` registers for stores around calls:
  `T** a = &lbl_X;` locals at the top, then `*a = f(...)`.
- `(float)(unsigned)x` uses the 0x43300000_00000000 constant; the signed form
  uses xoris. Assign to a float local before dividing to get `stfs/lfs`.
- An empty function with float params stores each param.
- Hex digit: `int t=c-0x30; int r=c-0x57; if ((unsigned char)t<=9) r=t; return r;`.
- `if (b<0) return -1; return f(..)` vs `r=-1; if(..) r=f()` swap the
  callee-saved order.
- `if (c != 0) return 1; return 0;` in a nested branch avoids the cross-jump of
  identical `li r3,0; blr` tails.
- Indexed address shapes:
  - `char* b = p + K; int o = i*S; *(int*)(b+o)` gives `addi; lwzx`;
  - `p + K + i*S` gives `add; lwz K(r)`;
  - `(char*)(i*0x18 + (int)p + 0x30)` gives retail's operand order.
- A function whose r3 is never set before a call has an unused first
  parameter. Variadic callees show `crclr cr1eq`.

## Range-00 recipes (2026-10-11)

- Stack-slot loop counters (`lwz r9,N(r1); cmpwi; addi; ble; mr; stw`, about
  a dozen functions): use `template<int MAX> Unk8006A138_It`
  (include/game/clampiter.h). A user-declared dtor keeps it in the frame.
  - `Next()` is `int t; if (v > MAX) t = v; else t = v + 1; v = t; return t;`.
  - Drive the loop with `idx = it.Next()`, or read `it.v` in the body
    (fn_80079BF8, fn_8007C328).
  - Construct the iterator after the other loads.
  - Do-while with an early exit:
    `do { r = f(arr[j]); j = it.Next(); } while (j <= 3 && r != 0);`
- Frame slot order: address-taken plain ints go above objects with dtors.
  Declaring temporaries as `int t[4]` places them at declaration (retail:
  temporaries at 8..0x14, iterator at 0x18).
- Recursive dispatch with `d > 1` laid out last:
  `if (d <= 1) { if (c <= 1) return vcall; return other; } return rec(0) + rec(1);`
  (fn_80074428, fn_80075684).
- `mr r0,r3; mr r3,r30; cmplw; bge; mr r3,r0` max blocks need an explicit copy:
  `unsigned t = a; if (t < b) t = b; sum = t;`. `?:` and `>?` give another
  schedule.
- `*out` in an argument list is evaluated before a later call. Force the call
  first with a named temporary: `int h = f() | 0x100; g(*out, h);` (fn_80073610).
- Arity from callers: if callers set r4/r5 that the callee never reads, the
  callee still takes them. Fix the header and let rename.py re-pin. A result
  used right after a call (`slwi r3,r3,2`) means the callee returns int.
- Still unreproduced (escalated to Opus):
  - dead `cmpwi r4,N` before a constant `li r3,0; blr` (fn_8006FB10 family);
  - lwzx base/index order in the roster walk family (fn_80077238 and six more);
  - cr7/mfcr compare reuse.
## Hard-case families (Opus, 2026-10-11)

### Pass-through arguments (vcall family and 3 more, 13 functions)
- Tell: only the callee-saved registers are permuted, and a callee reads an
  argument register that the caller never sets before the call (the caller's
  own parameter is still in it). Example: fn_80071E2C does `mr r30,r5` and
  calls through r5's vtable, but the old source called `fn_80071E2C(self)`.
- Recipe: pass that parameter. `fn_80071E2C(self, a, obj)` (10 vcall
  wrappers), `fn_8007A6A0(self, 4, b)` (fn_80080374), `fn_80039DBC(s, i)`
  (fn_800393B0), `fn_800999CC(sub, v, q)` (fn_80081BA8). The argument moves
  cost nothing (reload_cse deletes `mr r4,r28` when r4 still holds the value).
- Why it matters: in a single-block function local-alloc assigns the
  callee-saved registers. Its priority is
  `floor_log2(refs) * refs / (death - birth)`, where birth and death are 2 x
  the insn index after sched1. The extra use is one more ref on that pseudo.
  r31 is never used there (local-alloc skips the eliminable frame pointer), so
  the order is r30, r29, r28. vcall: obj goes from 3 refs to 4 (8/20 beats
  self's 8/24), and a goes from 2 to 3.
- To find more: `scratchpad/W7s3/passthru.py <repo>` lists unmatched
  functions whose first call reads an argument register the caller never set
  (uses build/GV4E69/report.json). Not every hit is a fix: the tu_8007DB74
  hits (fn_805A19C8 reads r4) differ in other ways.

### CSV row loaders (tu_80037250, 12 functions)
- Tell: retail keeps `&n` and `&cur` in callee-saved registers set once before
  the loop. Our version recomputes `addi rX,r1,k` at the top of every
  iteration.
- Recipe: use pointer locals. `unsigned int* pn = &n;` goes before the
  fn_802B9300 call (pn is its argument). `const char** pc = &cur;` goes first
  inside `if (n != 0)`. Pass pc/pn everywhere.
- Why: loop.c can't hoist the address computations. The while loop is rotated
  (entry jump to the bottom test), so scan_loop starts at the test. After its
  first conditional jump every body insn is "maybe never" executed, and an
  address pseudo used in several blocks of the body is not movable.
- Locals that retail stores 0 into right after the fn_802B9300 call (they share
  the `n = 0` register, which stays in r30 across the call) are declared with
  `= 0` after `end` (fn_80037D0C, fn_80037EE0, fn_800380D4, fn_80038424).

### Trace wrappers, family B with K != 0 and N == 0 (17 functions, still open)
- The order of the three `li`s before fn_80391C04 is decided by haifa sched1's
  rank_for_schedule. The criteria, in order: priority, register weight (before
  reload), class relative to the last scheduled insn, number of dependents,
  then lower LUID.
- adjust_priority raises an insn to max_priority when it becomes ready after
  another insn is scheduled, kills no register, and sets a register with
  REG_N_SETS == 1. Insns ready at block start never get this boost.
- After a call (family A: fn_80056C9C; the vcall-style wrappers),
  `li r5,LINE` is the only argument register set once, so it is boosted.
  sched1 emits r5, r4, r3, and sched2 turns that into retail's
  `li r4; li r5; li r3`. That is why every family-A and N >= 1 wrapper
  matches.
- Family B with N == 0 has nothing before the `li`s. All three are ready at
  start with equal priority. r4 has an extra dependent (the outer `li r4,0`),
  so the order is r4, then r3 before r5 by LUID.
- Retail behaves as if r5 had a later reference. Passing any third argument
  to lbl_80624408 reproduces retail's pre-call order exactly, for both small
  and big LINE (li/ori), but the argument itself costs a visible `mr`/`li r5`.
- No zero-cost source form has been found. Tried, beyond the earlier list: a
  `(id >> 13, 0, id)` tag (inline, macro, local), unused/`this` parameters,
  struct return (it returns through a hidden pointer here), an uninitialised
  third argument (callee-saved copy), -O2, and no sched1.
## UI/menu range 0x800F1AEC-0x8010E0F4 (range-06 worker, 2026-10-11)

Shared types are in `include/game/tu_800F1AEC.h` (screen base `UiObj`, vptr at +0x3C,
`{delta, pfn}` vtable entries so virtual N is at +8N; `UiObjB`/`UiObjC` are second and
third placeholder classes for slots whose signature differs between object kinds;
`UiW` has its vptr at +0xC, `UiX` at +0x10). Classes never define a virtual, so no
vtable is emitted; retail's vtables are the `lbl_` data objects.

Boilerplate families (generate with a script, they matched on the first compile):
- Button handlers: `int f(Scr* self, int a) { if (fn_800B555C()->m570 == a) self->m134->vN(); return 1; }`
  (N = 50..57, offset 0x190..0x1C8 in steps of 8); the variants test through a helper
  `int h(self, a)` (`return fn_800B555C()->m570 == a;`) or `if (self->m138 != 0 && h(self, a))`.
- Screen constructors: free function `UiScrRaw* f(UiScrRaw* self, int a..h) { fn_800EC648(self, a..h);
  self->m3C = lbl_vtable; self->m130 = 0; ... return self; }`. The 8th argument is a stack word
  (`lwz r0,0x20(r1); stw r0,8(r1)`), so declare eight int parameters after `self`. The vtable
  address is stored by hand (`const void* m3C = lbl_xxx`) because the vtable is a retail data
  object. Zero stores go in ascending field order; with that order every ctor matched
  (also `fn_804D2AC0(self, a..h, 0, 0x3364, K, &lbl)` ctors).
- Dtor with in-charge: `self->m3C = lbl_vt; fn_8035686C(self);` (`mr r11,r3` appears by itself).
- `blr`, `li r3,N; blr`, `*out = 0` wrappers are one-liners.
- Menu-tab widget ctor (vptr at +0xC): a real class ctor `UiWRaw::UiWRaw() { mC = lbl; m0 = 0; m4 = 0; m8 = 0; }`
  gives retail's `mr r11,r3`; found with a 24-permutation search (vptr first, then ascending).

Recipes found while matching:
- **A callee that receives `this`/`a` unchanged takes them as arguments.** If r3 (and r4) stay
  untouched between the prologue moves and a `bl`, pass them (`fn_80101254(self)`,
  `fn_800ED310(self, a)`) even when the callee ignores them: with the extra argument the
  prologue moves come out in retail's order (`mr r31,r3; mr r30,r4`); without it the two
  `mr` are swapped (14 functions in tu_80101254 went from 2-slot near-misses to matches).
  The same applies to a result: `fn_800C8044(obj->v32(...))`, `fn_802D7DB4(r, 0x78)` and
  `fn_800C3DCC(fn_800C33D0(), ...)` pass the previous call's r3 straight through.
- `if (c) { ...; return 1; } return 0;` (not `if (!c) return 0; ...`) gives `bne -> li r3,0`
  with the return value built in the else arm; `if (a == b) {..} else if (a == c)` keeps retail's
  compare order where a `switch` reorders it. `switch (b) { case 1: break; case 2: ...; case 3: ... }`
  with an extra empty low case gives the `cmpwi 2; beq; ble end; cmpwi 3` shape (fn_80108958).
- Range test `x == 6 || x == 7` returning 0/1 as `switch (x) { case 6: case 7: return 0; } return 1;`
  gives `cmpwi 7; bgt; cmpwi 6; li r3,0; bgelr` (retail), if/&& forms give the subtract trick.
- Per-arm tail calls: `switch (a) { case 0: return f(g, 0x2B34); case 2: return f(g, 0x2B35);
  default: return f(g, 0x2B33); }` makes jump2 cross-jump the shared `lwz r3; bl f` tail
  (dtk then shows `lis r9,0x8062` raw in two arms; objdiff still scores 100%).
- `int one = 1; lbl = one; if (a == one) {...}` keeps the constant in a register
  (fn_8010817C); `if (c) { int z = 0; lbl = z; }` puts `li r0,0` before the `lis` (fn_80107BDC).
- Locals: `char buf[100] = "";` reproduces `lbz r0,lbl@l; stb r0,8(r1); memset(buf+1,0,99)`
  with `crclr cr1eq` (libcall); objdiff accepts the `.rodata` literal vs retail's `lbl_` string.
- `UiMsg m; UiMsg* p = &m;` for init/strncpy/`p->name[15] = 0` but `&m` passed directly to the
  final send call gives retail's register split (fn_800F8588).
- Lazy singleton: `inline UiMsgMgr* UiGetMsgMgr() { if (lbl_8061A32C == 0) lbl_8061A32C = new (0) UiMsgMgr; return lbl_8061A32C; }`
  (ctor out of line = `bl __nw__FUii; bl fn_800B64BC`). A string-copy message send is
  `fn_8035682C(p); fn_8040B830(p->name, lbl, 15); p->name[15] = 0; fn_800B7B4C(UiGetMsgMgr(), &m, self);`.
- Table objects with several two-entry int arrays at fixed offsets (`struct { char pad[0x38]; int a38[2];
  int a40[2]; int a48[2]; ...}`): `q->a48[idx]` gives `addi rX,q,0x48; lwzx`, `(int*)q + 18` gives a folded displacement.
- A downward loop's final counter value is reused as the constant 0 afterwards (`mfctr r0` before the
  following stores, fn_800FB0E4/fn_800F9D0C): not reproduced yet.
- Float parameter passed on: `void f(S* self, float t) { g(self->m198, self->m134, t); }` is `stfs f1,8(r1)` / `lfs f2,8(r1)`.
- A by-value 8-byte struct copy from a global to a local (`UiP2 s = lbl;`) is `lwz r10,4; lwz r9,0; stw; stw`;
  declare the locals at function scope when retail uses distinct frame slots per case.

Open (not reproduced):
- Stack layout of two locals in sibling blocks (fn_80108800/fn_80109354: retail event object at
  sp+8 and message at sp+0x10; we get the reverse).
- Ternary-chain id selection passed to a call (fn_8010B0CC): right length, different branch layout.
- fn_800F5250/fn_800F5480, fn_800F3FCC, fn_800F3100, fn_80100BA4 (+2): see the near-miss comments.

## Range-08 recipes (UI widgets, vptr +0x3C, 2026-10-11)

- Vcall wrapper family: `lwz r3,OFF(r3)` then a vcall on that member, with
  optional `li r4,K` and `li r3,1`. The slot is the vtable byte offset / 8
  (the dtor is slot 1). A script matched about 50.
  - A wrapper that does not set r4 before an int-taking slot forwards its own
    second parameter: `void f(W* x, int a) { x->vslotN(a); }`.
  - The same slot called with another arity: cast to a second class declared
    with that signature (fn_80139090).
- Constructors: write the vptr store, then fields in ascending offset order
  (constants included). The last-written store is hoisted above the vptr
  store, so permute only the last 2 or 3 stores (fn_8012E7FC, fn_80131380,
  fn_80137F4C, fn_80136A9C, fn_80135538).
- Sub-object at +0xDC with its vptr at +0x100 (or +0x98 with +0xBC): declare a
  class with a 0x24-byte data pad plus its virtuals, and use a fresh
  `((Sub*)((char*)p + 0xDC))->fn()` at every use. A cached `Sub*` local
  changes allocation, and a by-value member is devirtualised.
- Derived widget data members go in a derived struct, or the vptr moves.
- `x = (a || b) ? 1 : 0` built as `li 1 / b / li 0` is an inline returning
  `if (..) return 1; return 0;`.
- `li r0,0; beq; li r0,1` after a call: `int ok = f(); int t = 0; if (ok) t = 1;`.
  `int t = 0;` before the call puts t in a callee-saved register (fn_8014241C).
- Stride tables (0x1C, 0x234): an inline `KeyAt(char* base, int off)` that
  takes the base pointer keeps `x+K` in a register (`addi; lwzx/stwx`).
  `const float&` store parameters do the same for float copies (fn_80142254).
- Two `subic.` count-down copy loops share one function-scope counter
  (fn_8013CF6C). Loop-scope counters give bdnz.
- `char* p = buf;` caches the buffer address in a callee-saved register
  (fn_8013A35C). A byte-offset `int* p = &x->m190; *(int*)((char*)p + which)`
  keeps the index unfolded (fn_8012DEF4).
- sprintf-style switch: one function-scope `int n;` assigned in each case,
  then the call after the switch (fn_8013B218).
- `bl fn_803774A8(size, heap)` is a plain extern "C" call, not `new[]`.
- Open:
  - a local struct whose address goes to two calls: retail rematerialises
    `addi rX,r1,8` after the call (fn_80134F48, fn_80134F98);
  - r4 moved before r3, suspected method calls into unmatched units (fn_80132630).

## Hard-case families 2 (Opus, 2026-10-11)

Matched 17 functions in 7 units with these recipes. Each recipe is one source change.

### Pass-through, the wider version (fn_8004961C, fn_800488C4, fn_8006473C, fn_80051014)
- Run `python tools/match/passthru.py .` first. The callee can read *every*
  argument register the caller leaves alone. fn_800488C4's caller in another
  unit passes six arguments, and all of them reach fn_80048E50. Read the
  caller's prototype in other headers before trusting this unit's.
- Strcpy chains: `fn_8040B61C(&s1)` was really `fn_8040B61C(&s1, name)`.
  r4 still held `name`.
- Empty callees (a bare `blr`) can still take arguments. fn_80051014 keeps s
  and idx live in r3/r4 up to `fn_80052FBC()`. That makes the entry base and
  offset take fresh registers (`addi r9` / `mulli r0`) instead of the dead
  r3/r4. The recipe is `fn_80052FBC(s, idx)` plus an overload in the header.
- Tell: your build reuses dead argument registers or parameter copies for
  temporaries, and retail does not.

### The callee's return type changes sched2 (fn_8004A8F8, fn_8006473C)
- A call to a value-returning function sets r3. A void call only clobbers it.
  With a void callee, an earlier `r3 = ...` argument setup keeps dependence
  edges to every later call and every later r3 write. That gives it more
  dependents, so it wins sched2 ties against parameter copies.
- Tell: 2 slots swapped near a call, between an argument setup and an
  `mr rN,rM` parameter copy.
- Fix: check the callee's epilogue. If it has `li r3,1` or `mr r3,..` before
  `blr`, declare it `int`. fn_80058FE4 returns 1, and strcpy/strcat return dst.
- Debug with `-fsched-verbose-5` (dash, not `=`). It prints each block's
  dependence table: priority, cost and the forward dependents of every insn.
- In this compiler anti and output deps cost 1.
- Ranking order:
  1. priority
  2. register weight (sched1 only)
  3. class relative to the last insn scheduled
  4. number of dependents
  5. lower LUID

### Indexed load operand order (roster walk family, 7 functions)
- `m0[j]` and `*(int*)((char*)m0 + j*4)` are canonicalised to
  (plus (ashift j 2) m0), which prints `lwzx rD,off,base`.
- Recipe: put the byte offset in its own variable first:
  `int k = f(r, a); int o = j * 4; int id = *(int*)((char*)r->m10[k].m0 + o);`.
- Keep m0 a temporary. A pointer-typed local is flagged as a pointer, and then
  the offset gets index class (r0) instead of retail's r11.

### scc through cr7 (fn_80088EFC, fn_80078D00)
- A cmpwi cr7 / (cror) / mfcr / rlwinm sequence is the CC-register scc
  pattern. `x >= 0` against a literal takes emit_store_flag's sign-bit path
  (`not; srwi 31`). `int z = 0; return x >= z;` keeps the scc form.
- Read the extracted bit before you guess the operator. In cr7, bit 28 is lt,
  29 gt, 30 eq, 31 so/un. `rlwinm r,r,30,31,31` (also printed
  `extrwi r,r,1,29`) is **gt**.
- fn_80078D00's "spC == 6" was `spC > 6`. EQ never stays in the CC form; it
  becomes xori/subfic/adde.

### &buf recomputed per use (fn_800A3DF8)
- An 8-byte local (char[8], or a struct of two ints) has DImode. It goes
  through ADDRESSOF, CSE merges the address pseudos, and the address lives in a
  callee-saved register.
- A BLKmode local (char[5..7], or a class with virtual functions) stays in
  memory. A local at frame offset 0 has the address `virtual-stack-vars`
  itself. Both go straight into the argument register, so `addi rX,r1,8` is
  recomputed at each call.
- fn_800A3DF8's local is a polymorphic 8-byte object. Its out-of-line ctor
  fn_80353218 stores m0 = 0 and the vptr at +4.
- Solved in Hard-case families 4 (inline-argument recipe): locals at a nonzero frame offset. expand_expr(ADDR_EXPR) runs
  force_operand, which makes a pseudo, and CSE keeps it. That covers the v8
  name-swap methods in tu_80094578 (char[0x14] at sp+0x18).

### Smaller recipes
- Form the entry base after the call, inside the branch, as
  `char* b = (char*)s + 8;`. Otherwise it is held across the call in a saved
  register (fn_80051E68).
- The 0x3C entries of Unk800493D4_Sm are Unk80044C10_B, and m6F8 is read
  straight from the entry (`lwzx; lwz 0x6f8`). That fixed fn_8004B538 (34 vs
  35 insns) and fn_80051014.
- Declaring the out-slot locals in address order fixed the zero-store order
  (fn_80078D00).
- objdiff's fuzzy score can rate a 2-slot reorder *lower* than a
  register-only permutation (fn_8004A8F8: 90.9% vs 92.95%). verify fails on
  fuzzy regressions, so when you park a function, keep the higher-scoring form.

### Still open (mechanism known)
- Solved in Hard-case families 4: dead `cmpwi`/`cmplwi` before `li r3,0; blr` (fn_8006FB10, FB1C, FF9C,
  FFD0, fn_80071138, fn_80071154):
  - After reload with sched2 on, delete_computation deletes only the jump.
    The compare stays ("REG_DEAD notes not accurate").
  - So retail's jumps became redundant only after reload, when jump2
    cross-jumped the identical `li r3,0` case tails into the default.
  - Ours merges the `return 0` bodies before reload (jump1's store-before-jump
    rewrite, then CSE), and flow deletes the compare.
  - The range checks are `cmplwi`, so the switch index is **unsigned**.
    `switch (unsigned k) { case 2: return 0; case 5: ...; case 8: ... } return 0;`
    reaches 5 of 13 differing slots on fn_8006FF9C. The tree is right, but the
    case block and the default `li r3,0; blr` are not cross-jumped.
- fn_8028F178 (2 slots): the -ffloat-store parameter spill `stfs f1,8(r1)`
  has to land between `lwz r11,0x44(r3)` and `lwz r0,0x14(r11)`:
  - The original int-field load does not conflict with the spill because of
    the scalar-vs-in-struct alias heuristic. After reload the stack store
    loses MEM_SCALAR_P.
  - With `*(char**)&g->m44->m14`, the load may alias the float slot, and the
    spill moves to the first slot.
  - Retail has the spill one slot later. In sched1 it was issued after
    `lwz r11` and before `lwz r0`.

## Hard-case families 3 (Opus, 2026-10-11)

Matched 23 functions in 7 units, and cut one near-miss from 10 to 6 slots. Each recipe is one
source change.

### Two vptr stores in a row: why retail keeps the first (widget ctors, 16 functions)
- Dead stores to memory are deleted by flow (life_analysis), twice: once
  before sched1 and again after reload (flow2). Going backwards through a
  block it keeps a list of stored MEMs and drops a store when the same address
  is stored again later. An entry leaves the list when, in between, there is
  - a read that may alias it (anti_dependence),
  - a store that may alias it (output_dependence), or
  - a call or a block boundary.
- Writing the base ctor out by hand loses the first store: the 0.0f literal is
  an unchanging MEM, so sched1 hoists its load above the root vptr store, and
  flow2 then sees nothing between the two vptr stores.
- Recipe A (root ctor as an inline): `FxRootInit(self)` in
  include/game/tu_80317B88.h stores lbl_80666EC0, then `m4 = m0 = 0.0f`.
  - A constant-pool read copied by the inliner is a plain `(mem:SF (lo_sum ..))`,
    without the unchanging flag.
  - sched1 cannot move it above the vptr store, and flow2 sees a read that may
    alias between the two stores.
  - The literal is still CSE'd across later calls through its REG_EQUAL note,
    so retail's single `lfs f31` survives.
  - Mid level: `FxWidInit(self, name)` = root, vptr lbl_80666E70, `mC = 0`,
    fn_8032D868. Matched fn_8032ECD8, fn_8032F120, fn_8032F19C, fn_8032F38C,
    fn_8032F428, fn_8032F4CC, and 9 ctors in tu_8032AC58.
- Recipe B (sub-object ctor as an inline): when a sub-object at a nonzero
  offset is initialised between the two stores, write its init as an inline
  that takes the sub-object pointer (`FESub10Init((FESub10*)((char*)o + 0x10))`).
  - Its stores keep their own base register (`stw r11,12(r8)` with
    r8 = o + 0x10). CSE folds only offset-0 stores back to `o + 0x10`.
  - flow cannot prove the `r8`-based stores disjoint from `o + 0xC`, so the
    earlier `mC` store stays. Matched fn_800AEA68.
- Tell: retail has `stw <vtA>,8(rX) ... stw <vtB>,8(rX)` with no call between,
  and an `lfs` of a per-function 0.0f (or a store through another base
  register) between them.
- Scanner: `scratchpad/W8o/vfam.py <repo>` lists every function with two
  vtable stores to the same slot and no call between them, with its match
  status. About 40 more of these (root lbl_80649DA0, UI units 0x800F..0x802F)
  are not done yet.

### Inline-argument recipes found on the same ctors
- By-value struct argument for a setter call (`fn_8032E088(self, &tmp)`):
  - Retail copies the pair or triple to `8(r1)`/`12(r1)` right at the call.
  - Pass it through an inline that takes the struct by value
    (`FxPairSet(self, self->m5C)`), or copy it inside the inline body
    (`FxTripSet`: `FxInt3 v = self->m60; fn_8032E344(self, &v);`).
  - Taking `&param` of the ctor's own by-value parameter spills it at entry
    instead. Matched fn_8032DC2C, DD00, E0B4 and E1DC.
- Callback or pointer arguments that retail keeps in callee-saved registers
  across the item's name call (`lis r29,fn_80332930` before
  `bl fn_8032D868`) are inline parameters. `ButtonInit(it, name, cb)` and
  `SubInit(it, name, sub, p)` matched fn_80332978. It had been parked at
  150 vs 152 instructions, with one callee-saved register short.
- A string or literal byte read from an inline stays after the surrounding
  stores (`FxRecName(this, lbl_805E7988)`, __5FxRec). It is not unchanging,
  for the same reason as Recipe A.

### Callee returns `this`: declare it (3-arg item ctor calls, 4 functions)
- Tell: `li r5,0` comes before `mr r3,<item>` in retail, ours is the other way
  round, and the callee ends with `mr r3,r30; ... blr`.
- Recipe: declare the callee as returning a pointer. That covers fn_8032F120,
  fn_8032F428, fn_8032FAB0 and fn_8032ECD8 (all ctors that return self).
  It is the same sched rule as "the callee's return type changes sched2"
  (Hard-case families 2).
- Matched fn_80331DB8, fn_80332DBC and fn_80333A70. fn_8033C490 went from 10
  to 6 slots; the rest is loop giv order.

### Small ctor orders
- `FxS::FxS(int)`: store the vptr first (`m8; m4; m0`). That gives retail's
  this/vtable register pair.
- `FxU::FxU() : m0(-1), m4(-1) {}` stores m4 first. `m4 = m0 = -1;` does too.
- __5FxRec: stores in ascending order, plus the inline name byte above.

### Not reached this round
- Dead-cmpwi switch family (about 20 functions) and the sched1 constant-set
  hoisting in fn_800E9074: not attempted. The mechanism notes in Hard-case
  families 2 still stand.

## Hard-case families 4 (Opus, 2026-10-11)

Matched 19 functions in 9 units. The dead-compare switches and the per-call frame
address both have a general recipe now. Scratch tools are in `scratchpad/W8o4/`.

### Dead-compare switches (16 functions)
- Where the dead compares come from:
  - With sched2 on, jump2's delete_computation deletes only the jump and never
    the compare.
  - A compare survives exactly when its jump first became redundant in jump2.
  - A jump that dies earlier (in jump1, or in the jump passes after CSE and CSE2)
    loses its compare too, because CSE or flow deletes the dead compare.
- So the case *bodies* decide which compares are left. The tree itself is plain
  balance_case_nodes output: this build never makes a jump table, nodes are
  balanced by count, and ranges count twice.

  | Case body | Removed by | What is left |
  |---|---|---|
  | `break;` (empty) | expand / jump1 | nothing, but the node still counts in the balance |
  | `r = 0;` after `int r = 0;` | CSE (redundant set); the jump passes after CSE and CSE2 peel two layers | interior nodes keep `cmpwi X; beq; cmplwi X; bgt`, chains and leaves vanish |
  | a dead store that CSE keeps (`kind = 0;` on the switch variable) | flow | every compare; jump2 kills the jumps |
  | distinct `return <v>;` per case | jump2 cross-jumping | every compare, `beq` into the shared returns |

- Recipes, by retail shape:
  - **All-zero column stubs** (only `cmpwi/cmplwi` pairs, then `li r3,0; blr`):
    `int r = 0; switch ((unsigned)k) { case 0: r = 0; break; ... case N-1: r = 0; break; } return r;`.
    N is the column count of the table's getter. 4 for fn_8006FB28 gives a lone
    `cmpwi r4,1`; then 7, 12, 14 and 56. Matched fn_8006FB10, FB1C, FF9C, FFD0,
    fn_80071138, fn_80071154, fn_8009FDC8, fn_8009FDD4, fn_8009E060 and fn_80598B3C.
  - **Mixed tables with `li r3,0` at the top and `beqlr`**: the same form with
    `r = <v>;` per case, values read from the tree. fn_80598AB4 returns 100 for
    columns 10..13.
  - **Constant tables without the top `li r3,0`**: one `return <v>;` per case and
    `return 0;` after the switch. The index is signed, so `cmpwi X; beq; bgt`
    share one compare. Matched fn_8059F680 (119 cases) and fn_8059FADC (63).
  - **Result in a stack slot** (`stw r0,8(r1)` ... `lwz r3,8(r1)`): use a union or
    struct local, e.g. `union { int i; float f; } v; v.i = 0; ... return v.i;`.
    The leaf cases keep their own `li r0,0; b` blocks, which jump2 cannot
    cross-jump. Matched fn_8009DDE4.
  - **Void switch with bare `cmpwi X; b end` compares** (fn_80055D84):
    - List every kind of the sibling switch (fn_80055204, 95 kinds).
    - Kinds that leave no compare in retail are plain `break;`. They still weight
      the tree; they were the "two nodes longer" root shift.
    - Kinds with a bare compare do `kind = 0;`, where `kind` is the switch
      variable. That store survives CSE, and flow deletes it.
  - **Slot index form** (fn_8059B280): every case assigns, zero arms included
    (`s = 0;`), with no `default`. Range-46 needed the opposite (`default: s = 0;`)
    on other functions, so try both forms.
- Signedness: a `cmplwi` after each `cmpwi` means an unsigned index
  (`switch ((unsigned)k)`). One `cmpwi` shared by `beq` and `bgt` means signed.
- Tools in `scratchpad/W8o4/` (copy a unit to scratch before compiling it):
  - `deadcmp.py <repo> [busy]` lists unmatched functions with a compare whose
    result is never read.
  - `solve.py <repo> <unit> <fn>` tries the all-zero stub over 0..N
    (`BMAX` env), with int and unsigned index.
  - `treeval.py <repo> <unit> <fn> lo hi` prints the value the tree returns for
    each index.
  - `mixsolve.py <repo> <unit> <fn> [maxN]` takes that table and tries the
    `r = v` and `return v` forms. A run takes seconds.
  - `cmp.py <repo> <unit> <fn> file.cpp` scores every function in a scratch file
    against one target.
- Solved in scratch first, all committed in the second pass (below):
  - db/tu_8052CA60: fn_8052CC18 is all-zero 0..16; fn_8052CB74 is `r = v` 0..16.
  - db/tu_8052E4C0: fn_8052E8D8 is all-zero 0..34; fn_8052E754 is `r = v` 0..34;
    fn_8052F554 and fn_8052F590 are all-zero 0..12.
  - db/tu_8052FF10: fn_805300D0 is all-zero 0..17; fn_80530024 is `r = v` 0..17.
  - db/tu_8053CC9C: fn_8053CE50 is all-zero 0..14; fn_8053CDB0 is `r = v` 0..14.
  - game/tu_80089894 (all-zero): fn_8008AC68 0..8, fn_8008B3E8 0..13,
    fn_8008BEF0 and fn_8008BF24 0..11, fn_80089A0C 0..27.
  - game/tu_8008CE64: fn_8008EC78 is all-zero 0..26. fn_8008CE64 itself is not
    this shape.
  - game/tu_80084910: fn_80084BDC is all-zero 0..21.
  - Every index above is `(unsigned)`.

### Frame addresses rebuilt at every call (2 functions; 2 busy-unit cases in scratch)
- Mechanism: `&local` goes through expand_expr(ADDR_EXPR) and force_operand.
  - At a nonzero frame offset that makes a pseudo per use. CSE merges them into
    the first one, which then lives in a saved register.
  - At offset 0 the address is `virtual-stack-vars` itself, so no pseudo is made.
- Recipe 1, a buffer at a nonzero offset used by several calls: call through an
  inline wrapper, `inline void StrCpy(char* d, const char* s) { fn_8040B61C(d, s); }`.
  - Inline arguments are expanded with EXPAND_SUM.
  - A frame address is substituted into the inline body at each use, so every
    call gets its own `addi r3,r1,N`.
  - Matched v8__11Tbl80094800 and v8__11Tbl800956D8.
  - Check the frame size. Their buffer is char[0x10]: BLKmode sizes round up to
    8, so char[0x14] gave a frame 8 bytes too big.
- Recipe 2, a struct stored to 8(r1) before each call (fe fn_804CF304, fn_804CF368):
  - The callee takes the struct *by value*. SysV passes an aggregate as a pointer
    to a caller temp, and the temp is freed after each call, so both calls use
    8(r1) and rebuild `addi r4,r1,8`.
  - When the extern "C" prototype in the header takes a pointer, call through a cast:
    `((void (*)(FeSlot44*, FePair))fn_804D21B8)(&x->m188, lbl_805F84B8);`.
  - fn_804CF304 matches in scratch (fe/tu_804CE408 is busy).
- Recipe 3, a 4-byte record whose address is passed once: a 4-byte struct is
  SImode and goes through ADDRESSOF.
  - Give it a trivial destructor (`~T() {}`). It becomes BLKmode and addressable
    from its declaration, so `&b` is rebuilt per use and fields are read straight
    from the frame.
  - In scratch, db fn_8053DD68 is then left with one difference: a subtraction
    narrowed to a byte load.
  - fn_8053DB30 still differs in frame layout: retail has the by-value Date copy
    at 8 and the buffer at 12.

### A constant kept out of the saved registers (fn_800E9074)
- The id `li` was hoisted by sched1 above the fn_800A2AE8 call, so id lived in r29.
- Compute the bound first (`int q = fn_8056B7D0(...) - p;`), then
  `int id = 0x4556; if (c >= q) { if (fn_800A2E6C(g) != 0) id = 0x4D52; else id = 0x4D50; }`.
  Every id `li` then comes after the last call on its path, and id gets r4.

### Still open
- The callee-saved permutation cluster (db fn_80533120; fn_80536F28,
  fn_80537054, fn_8053923C).
  - In fn_80533120, retail sets the loop counter by copying the result's zero
    (`li r30,0` ... `mr r31,r30`). That gives the result a fourth reference and a
    global-alloc priority above col and self (r30, not r28).
  - CSE turns every source copy tried back into `li`: `i = r`, `r = i`,
    `r = i = 0`, and the int/unsigned mixes. (Solved in Hard-case families 5:
    `unsigned i = 0;` first, then `for (i = r; ...)`.)
- The FeArr m4/mC store swap (fe fn_8047BB8C, fn_8048A2AC): not attempted (busy units).
- fn_800B08B0 (`lwz r0,16(r3); li r3,0; cmpwi r0,0; blr`):
  `int r = 0; switch (p->m10) { case 0..3: r = 0; break; } return r;` gives the
  right instructions, but the `li` lands after the compare instead of before it.
- fn_8006A1F4 (0xA8 frame, `cmpwi 0x25; beq; cmpwi 0x26`): not attempted.

### Second pass (families 4b): 35 more functions in 16 units
- Every busy-unit recipe listed above is now committed, and so are their value
  twins: fn_8052CB74, fn_80530024, fn_8053CDB0, fn_80084B24, fn_800898D0,
  fn_8008AC18, fn_8008B368, fn_8008EB90 and fn_8008CE64.
  - When `mixsolve.py` accepts two Ns (fn_8053CDB0 15/16, fn_8008BEF0 11/12),
    take the column count of the sibling getter.
- `pureall2.py <repo> <busy>` lists every unmatched function that is only a
  compare tree (index in r3..r6, branches, `li r3`), in any unit.
  - `mixsolve2.py <repo> <unit> <fn> <r3|r4|r5> <maxv>` handles the general case:
    cases a..b, the default value read past the range, `r = v` or `return v`.
  - It solved fn_80084728, a 25-case id table taking `(int k)`.
  - It also solved fn_804F9C64 (`int r = 12`, cases 4..13).
- Grouping tells, read from the tree:
  - A bounded range node (`blt`/`bgt` to a label with no eq test) is two values
    under one label, e.g. `case 4: case 5:`.
  - A value with its own `cmpwi X; beq` needs its own body even when the value
    equals a neighbour's: fn_8010F4D4 needs `case 2: return 0xC82; case 3: return 0xC82;`.
  - `cmpwi hi; bgt; cmpwi lo; li r3,1; bgelr` is a two-value range leaf:
    `switch (v) { case 0x31: case 0x32: return 1; } return 0;` (fn_80166440).
    An inline `v > hi ? 0 : v >= lo` gives an mfcr scc instead.
  - fn_8056A1DC is `int r = 1;` with a `case 0: r = 1;` arm, which still emits
    the `beqlr`.
- ealib: `scratchpad/W8o4/dump.sh` takes the `CFLAGS_OVR` env, e.g.
  `"-O2 -fno-rtti -fno-exceptions"` for the -G8 RealCore units.
  - Two 4-byte `.sdata` wide strings come back as `li r3,X@sda21` only when their
    size is known: `extern unsigned short lbl_806EEA5C[2];` (fn_803F644C).
  - fn_803EB83C is `switch (k) { case 8: return 0x100; case 4: return 0x10; default: return 0; }`.
- More per-call frame addresses:
  - The fe `FePair` argument of fn_804D21B8 is really an 8-byte
    pointer-to-member passed by value (its definition is in tu_804D08D0). Call
    it through a by-value cast (fn_804CF304, fn_804CF368).
  - fn_80134F48's local is the class whose out-of-line ctor retail calls
    (`__11Unk803567AC`), not a struct filled by fn_803567AC. Declare the class in
    the unit with a trivial `~Unk803567AC() {}` (BLKmode), so `&v` is rebuilt per
    call and the frame is 24 bytes.
  - fn_8053DD68: give the buffer a unit-local type with Buf3's layout and a
    trivial dtor, then read `b2.b` into a local before the subtraction. Otherwise
    the halfword load narrows to `lbz`.
- Still open after this pass:
  - fn_803F73B0 (ealib, cases -128 and -14..0, default 16): the case set is
    right but the tree differs (60 slots).
  - snd/tu_803AB310 fn_803ABCB4, fn_803ABDD0 and fn_803AC164 have dead
    `cmpwi -18/-10/-7` trees after the calls (an error-code switch whose arms
    are empty). They are not written yet; the port/mvp2005 reference source
    should give their shape.
  - fn_8053DB30: the by-value Date copy and the buffer sit at swapped frame
    offsets.
  - fn_80299FD4 (animation/goals) differs in more than the frame address.

## Ranges 10-19 recipes (2026-10-11, condensed from worker reports)

Literals and constants
- objdiff's 100% does not check literal values or call/global targets. Run
  `tools/match/check_literals.py <unit>`. Write real literals with the values
  read from the original data. Original strings may contain a literal
  backslash (`"\n"`).
- A `const float k = ...;` local (or a literal used several times) stays in
  f31 across calls. An `extern const float` global may be hoisted above
  earlier int stores. A float read from an aggregate global (`lbl.x`) may
  alias, so it stays below earlier stores (reset-record family, range-17).
  Try each spelling when a `lfs` sits in the wrong place.
- Float locals take stack slots in reverse declaration order. An unused
  `double d;` keeps a 0x10 frame. An unused `volatile int pad;` reproduces a
  slot gap.

Calls
- The callee's return type matters: if its epilogue sets r3 (strcpy, `li r3,1`),
  declare it int even when the result is ignored. A void call changes the
  sched2 dependences, so two slots swap near the call (Hard-case families 2,
  range-16).
- Prototype parameter order drives argument evaluation order (`float k`
  before `int flag` fixed fmr/mr order).
- Struct-returning helpers reused for two calls: `Vec3* f(Vec3* out, ...)`
  with `*out = ...; return out;`. A by-value return makes a second temp slot.
- Declare C++ callees (mangled symbols) outside `extern "C"` blocks. Otherwise
  the plain name is emitted, objdiff still says MATCH, and the link breaks.
- RNG-percent families: `inline float RandPct(P* x, const char* file, int line)`.
  Pass the file string and line as inline parameters, or the lis/li order
  is wrong (range-19 injury family, range-15 RNG lerp).

Indexing
- Retail's base-first `lwzx base,idx` with an r9/r11 index temp comes from an
  inline that takes the base pointer and does explicit byte arithmetic:
  `inline int ObjAt(void** a, int i) { int o = i*4; return *(int*)((char*)a + o); }`.
  The same applies to `KeyAt`, `AtD`, `Pick` and `T* q = base + i; return *q;`.
  Plain `a[i]` gives the swapped order or r0.
- Stride records: `Rec* b = i->arr; Rec* r = b + k;` gives `addi` first, then
  `mulli/add`.

Control flow
- `if (d < 0) return -1; if (d > 0) return 1; return 0;` gives
  `subf.; blt; li 1; bgtlr`.
- A nested-ternary return gives `mr r3,r0` from r0 (fn_801F29AC).
- A clamp with the high arm out of line:
  `if (v <= 99) { if (v < 0) v = 0; } else v = 99;`.
- `int g; if (i != 3) g = f ^ 1; else g = f;` gives `mr; beq; xori`.
- Empty `for (j = 0; j < n; j++) {}` loops survive as `mtctr/bdnz`.
- A volatile saturating counter also works counting down:
  `while (sp8 = t, e = sp8, e > 0) { ...; c = sp8; t = c - 1; if (c <= -1) t = c; }`.
- A member-pointer table entry is copied to a local before an earlier call:
  `Pmf f = tbl[k]; call(); (s->*f)();`.

Objects
- Member arrays of classes with ctors (`Sub m4[2]` of `Ent m4[5]`) give a
  do-while with post-decrement. Give Ent an inline ctor calling the extern.
- Struct assignment via `Assign(const T* src, T* dst) { if (dst != src) memcpy(dst, src, sizeof *dst); }`
  with (src, dst) parameter order.
- Local struct slots follow declaration order, low to high.
- Store-order search: hill-climbing over adjacent swaps (about 0.2 s per
  compile, calling ngccc directly) solves 11-20 stores in minutes.
  Plain permutations are enough up to about 6.

Still open (Opus queue)
- `t == 1 || t == 2` kept as two compares in retail (fold_range_test):
  fn_80254964, fn_8025E5E0, fn_8025CDD8.
- Loop test at the top with a back edge to it: fn_80255284 (solved: the call is written twice, Hard-case families 5), fn_80257DFC.
- Dead `cmpwi` before a constant return: solved, see Hard-case families 4.

## Ranges 20-27 and second passes (2026-10-11, condensed)

- mfcr/mtcrf in the prologue/epilogue is a CR save, and it is reproducible.
  A flag compare that stays live across calls lands in cr2-cr4. Example:
  `int own = out == 0;` with the write pointer declared inside the non-empty
  branch (fn_8008399C, fn_80083AD4). Don't skip these as asm-only; only
  mftb/mfspr-style instructions are.
- Independent global stores: write them in source in the order of retail's
  `lis` instructions (fn_803318CC: 8 stores, matched first try).
- Packed-record getters/setters: the getter's shift/mask pairs give the bit
  widths; an MSB-first bitfield struct with zero-width pads reproduces them.
  Setters clamp `if (v <= MAX) { if (v < 0) v = 0; } else v = MAX;` (7-bit
  percent fields clamp at 100). One generator pass per record type matched
  functions of 234-912 instructions (tu_8008CE64, tu_80089894).
- Store-only iterator slot:
  `struct It { int i; ~It() {} int Next(int c) { n = c > N ? c : c + 1; i = n; return n; } };`
  Write `k = it.Next(k)`, and declare `n` and `k` before `it`.
- `int n = 12; ... if (i >= n) goto done;` keeps `cmpwi 12; bge` (not
  `cmpwi 11; bgt`). A goto-shaped scan loop stops strength reduction.
- Nested loops over the same count: write explicit pre-tests,
  `while (1) { if (!(i < n)) break; ... }`. A plain `for` lets CSE merge the
  inner and outer tests.
- A function that falls off the end without `return` leaves the last call's
  result in r3.
- Member-array dtor loops: `X::~X() {}` with `Elem m[N]`, where
  `struct Elem : ElemD { virtual ~Elem(); }`. This gives the guard, the
  backward loop, the in-charge-0 vcall and the deleting tail. Nested arrays
  use an inline `~Mid() {}` (range-27).
- Ring step: `unsigned k = m4 - 1; mC = (mC + k) % m4;`. Without the named
  temporary, fold reassociates it.
- Hidden-pointer struct returns: a BLKmode local (e.g. `struct { char m0[6]; }`
  or one with a dtor) gets a per-use `addi rX,r1,8`. An 8-byte DImode local
  keeps its address in a saved register.
- `new (heap) T[n]` for T with a ctor gives `__vn` plus the element ctor loop.
  A function shaped `mr r9,r3; mr r11,r9` is often a real ctor.
- Two bitfield read-modify-write groups: put a read of a global between
  them, or the first store is merged away.
- Global store with a branchy RHS: `int* q = &lbl_X; *q = ...;`.
- Float exit tests `if (!(a <= b)) return X;` give `cror; bso` (retail
  shape). `if (a > b)` gives a plain `ble`.
- Open (Opus round 3):
  - widget ctors keep the first of two vptr stores (about 25 functions);
  - dead-cmpwi switch family (about 20; a hidden `default:` case shifts the
    balance root);
  - `li r5` before `mr r3` for 3-arg item ctor calls;
  - sched1 constant hoisting.

## Ranges 29, 36, 41, 42 and pass2-04 (2026-10-11, condensed)

- Evaluation order: call arguments are evaluated left to right. Only binary
  operator operands go right to left. `r = a; r -= b;` puts the first term
  straight into r3.
- Clone first. `scratchpad\R36\clone2.py --apply` clones every matched donor
  into functions with the same relocation-masked shape. It gave range-36
  about 90% of its matches. A donor inside `extern "C" {}` needs
  `extern "C"` on the clone, or the clone compiles mangled.
- Two-argument call to a one-argument mangled symbol (fn_80090880): declare
  the true signature, then call through a cast:
  `((char*(*)(Unk80090880*,int))fn_80090880)(tbl, id)`. This still emits a
  direct `bl`.
- Callee return type changes the caller's arg setup. Declaring fn_803FED48
  `int` instead of `void` fixed `li r4; li r5; addi r3` in fn_800C1A24,
  even though the result is unused.
- Range tests:
  - `k >= 1 && k <= 2` folds to `addi; cmplwi; bgt`.
  - Retail's `cmpwi 1; blt; cmpwi 2; bgt` comes from locals:
    `int lo = 1, hi = 2;`.
- Switch layout: put an empty `case 0: case 1: case 2: break;` first, then
  the real cases in retail layout order, to get `beq; ble; cmpwi 5; bgt`.
- Null-check returns: `if (r == 0) return 0; return r;` keeps
  `mr.; li; beq; mr`. `r ? r : 0` folds it away.
- Single `li r3,0` with `beqlr`/`bnelr` exits: use one result variable,
  `int r = 0; if (...) r = ...; return r;`, not several `return 0`.
- Address arithmetic:
  - `(Rec*)(i * 1040 + (int)m)` then `(char*)r + K` gives `add; stwu K(r)`.
  - `&m->recs[i]` gives `stwx` instead.
  - `(char*)(off + (int)ptr) + K` gives operand order `off, base`.
  - `p + (i*0x118 + 0x168) + j*0x28`, parenthesised, keeps retail's add order.
- Base-first `lwzx`: `int o = i*4; *(int*)((char*)base + o)`.
- Loop forms:
  - `for (; c; c = c->m4) { if (cond) break; }` gives the rotated loop with
    hoisted loads.
  - `while (i < f()) { ...; i++; }` gives the entry-jump loop.
  - A peeled first iteration comes from the plain `for`. Don't
    special-case `m == 0` by hand.
- Register sharing:
  - Reuse one counter variable across two sequential loops to fix swapped
    r26/r27.
  - Declare `unsigned i = 0;` before the zero stores
    (`m4 = i; mC = i; ...`) to share the zero register with the counter.
  - Put the counter init after the stores to get a separate `li r0,0`.
- Pointer `==` and `!=` compile to `cmpw`. Only ordered pointer compares
  give `cmplw`.
- A cross-jumped `return 0` tail comes from sibling branches that each
  `return p->b0;` inside `if (p)`. Jump2 merges the fall-through.
- Macro-style singleton casts (`#define SCR ((T*)lbl_X)`) reload the global
  at each use, as retail does. A pointer local does not.
- Nested call `f(a, g(b))` where retail loads the global twice: split it
  into two statements.
- Destructors:
  - Member-array dtors are real classes. A non-virtual class with
    `O::~O() {}` and `E m[n]` still gets `(this, in_chrg)` and the
    deleting tail.
  - Polymorphic elements: `struct E { char pad[n-4]; virtual ~E(); }` with
    the dtor declared only (no vtable emitted).
  - Member B in a class: `li r4,2; bl B::~B`.
  - Derived `D : B { ~D(){} }`: a pure r4 pass-through forwarder.
  - Inlined member dtor: a separate class with the dtor defined in-class,
    plus an out-of-line twin class for the standalone function.
  - Implicit dtors of data-less classes derived from Unk8037B3E8 are
    linkonce and unpairable (DECISIONS, linkonce).
- Pointer-to-member loops: `(arr[i]->*f)()` with `f` declared
  `void (Widget::*)()` gives the ptmf thunk, with the pmf copied to r30/r31
  before the loop.
- Bitfields: `f0 = 1; f1 = 0;` gives `oris` plus `rlwinm`. Read record
  layout straight from the getter's extrwi operands.
- A 64-byte member struct assignment gives the 24+24+16 copy loop.
- An inline wrapper with default arguments, used by a member array in the
  outer ctor, gives the do-while ctor loop.
- Float parameters of inline functions get float-store stack slots. If
  retail has no slot, read the member inside the inline instead of passing
  it in.
- `char buf[N] = ""` emits memset plus a .rodata string. The verifier
  accepts it; check_literals lists memset as unresolved (retail calls
  fn_8040B320).
- Tooling:
  - After rename.py, asm parsers must normalise mangled `.fn` names back to
    addresses.
  - The R29 tools (gen.py, stores.py, hill2.py), R42 permtest.py and R41
    chklit_db.py are reusable.
  - check_literals.py now covers `.dboverlay`.
- Open:
  - dead-compare switch family (db units, about 8): solved, Hard-case families 4;
  - (solved, Hard-case families 4) nonzero-frame-offset local kept in a callee-saved register instead of
    `addi r4,r1,8` per call;
  - callee-saved permutation cluster (80533120 solved in Hard-case families 5;
    80536F28, 80537054, 8053923C still open);
  - sibling-arm vcall tail sharing (fn_804D0860).

## Ranges 33-46, tail 00-01 and pass-2 g16-g19 (2026-10-12, condensed)

- Float constants:
  - With a literal `0.1f`, a `const float c` local stays in f31 across calls. `extern const float lbl_X` reloads it from its stack slot.
  - A scalar float global gets hoisted by sched1 above earlier int stores. Declare it `extern float g[1]` and read `g[0]` to keep it below them.
  - A non-const extern float keeps its load after earlier stores; `extern const float` lets the `lfs` hoist above them.
- Stack message objects (id at +0, vptr at +4, root vtable lbl_80649DA0):
  - Use inline `Base(id){vptr=root; m0=id;}`, then a derived ctor that stores its own vptr, then `Fill(...)`, then an inline dtor that restores root.
  - Because m0 is stored sp-based and the vptr through `this`, the first vptr store survives.
  - Name the derived class after the callee's class so mangled setters match.
- Dead compares, more forms:
  - An identical body in both arms (`if (f()==2) g(s,6); else g(s,6);`) leaves `cmpwi; b`.
  - A `case 2:` with the same body as `default:` does the same.
- Switch-tree root off by one: add a dummy `case N+1: break;`, or an enum index with a negative enumerator. A two-case tree needs an empty `case hi+1: break;`.
- Arguments and evaluation order:
  - `m->m18->v1(f(m, idx))` loads the vtable before the argument call. Hoist the call into a local to get retail's order.
  - A conditional argument written inline (`w->v16(v != 4 ? 1 : 0)`) keeps the `lwz` between the compare and the argument.
  - When a callee's real arity or return type differs from the shared header, call it through a cast: `((int(*)(void*,int))fn_X)(p,0)` or `((void(*)(T*,Pair))fn_X)(...)`. Both emit a direct `bl`.
  - An empty callee that retail calls with `self` in r3 needs the parameter.
- Frame and locals:
  - Size the frame from the prologue (`char buf[N]`; `stwu r1,-80` leaves 64 bytes of locals). A 12-byte Vec3 gives 0x90 where a 20-byte struct gives 0x98.
  - The first-declared float local gets the lowest slot. An unused `volatile float pad;` or `float u;` reserves a gap.
  - The order of `&x` takes decides slot order, not the declaration order.
  - A BLKmode (odd-size or dtor-bearing) stack temp gets a per-use `addi r3,r1,8`. A `char* p = buf;` pointer local keeps the address in a saved register.
  - Frame-address arguments recomputed per call come from an inline wrapper `inline void Cpy(char* d,const char* s){fn(d,s);}`.
- Loops:
  - `while (n-- != 0)` gives `addi -1; cmpwi`.
  - `do {...} while (k-- != 0)` gives the post-decrement ctor loop.
  - `for (;;) { if (!c) break; ... }` keeps the reload that `while (c)` CSEs away.
  - The `test at top, entry jump into the middle` shape: a loop call written twice, see Hard-case families 5.
- Data structures:
  - Member-array dtors in extern "C" units: element classes whose inline dtor forwards to the real element function, plus an owner `~Owner(){ vp = lbl; }` and `fn_X(Owner* p,int c){ p->~Owner(); if (c&1) delete; }`.
  - A class `operator delete` explains an `andi. r,1` then hook `blrl` tail.
  - A static init pair needs the global object defined in the unit. The compiler then emits `__static_initialization_and_destruction_0` plus `_GLOBAL_.I/.D` byte-identically. Rename those by hand: they are local and per-TU.
  - Bitfield views reproduce `rlwimi` with a shared `li`. A raw mask gives `rlwinm` plus `or`.
  - `f0 = 1; f1 = 0;` gives `oris` plus `rlwinm`. `int f = p->bits; if (f == 1)` gives `rlwinm.`.
- Pairing:
  - A function that is written and matching can still be unpaired. Check the rename.py SKIP lines.
  - If other units call it by plain name, define it `extern "C"` with their parameter types and cast inside.
  - rename.py pins by masked code. Real ctors whose fn_ name is still referenced elsewhere must be renamed by hand.
- Tooling:
  - Run `ninja` before `check_literals.py`; it reads report.json and the rebuilt objects. `ninja build/GV4E69/report.json` takes about 1 s.
  - sort_functions.py moves declarations that sit above a function along with it. Keep every declaration in the file head (`R44\hoist.py`, `P18\hoist.py`).
  - Store-order hill climb: start from retail's emission order (`P16\hill.py`, `P18\hc.py`, `T00\bf.py`).
  - Variant scorers: `R40\hc.py`, `P18\vtry.py`, `R45\cand.py`, and `T01\tv.py` (takes a FLAGS env var).
  - Switch tables: `W8o4\mixsolve2.py` finds the form, signedness and case count in seconds. `W8o4\deadcmp.py` scans for them.
- Library notes:
  - The gamelib (0x80377048..0x8038BC58) is -Os -ffloat-store.
  - ealib/tu_803912F8 and tu_803927E4 take `cflags_ealib_nsr` (-G0 -fno-strength-reduce).
  - Wide strings in sda units are `extern unsigned short lbl[N]`.
  - SDK sources may `#define` a real name onto a placeholder that game code still calls (e.g. GXBegin -> fn_8042C8B0).

## Hard-case families 5 (Opus, 2026-10-12)

Matched 41 functions in 30 units. Three more are solved in scratch for units that turned busy
(below). Scratch tools are in `scratchpad/W8o5/`.

### Argument moves in the wrong order: callee return types (26 functions)
- Tell: same instructions, and two or three argument moves before a `bl` are in a different
  order (often `mr r3,..` / `addi r3,r1,N` first in ours and last in retail, or the reverse).
- Mechanism (haifa sched_analyze, both sched passes):
  - A value-returning call *sets* r3, so it becomes `reg_last_sets[r3]`.
  - A void call only *clobbers* r3, so `reg_last_sets[r3]` stays on the earlier r3 argument
    move. The next r3 write (the next call's `r3 = ..`, or the function's return value) then
    gets an output dependence on that argument move.
  - One more dependent wins the rank_for_schedule tie (priority, then class, then number of
    dependents, then LUID). So the callee's declared return type moves the r3 argument move.
  - The callee that decides is usually the call right after the reordered moves (its result
    or clobber meets the next r3 write); sometimes it is the call before them.
- Recipe: flip the callee's declared return type, either way:
  - void to int/pointer: fn_800DE440, fn_800DE274, fn_800DE538 (tail calls of fn_800DE6A8,
    which ends `mr r3,r24`), fn_80582CF8 (`li r3,1`), fn_8003D944, fn_803FED48, fn_80134A60,
    fn_802542E8, fn_800DBC50, fn_80125180, fn_800DF254; ctors that return this:
    fn_800CFEEC, fn_8028F45C.
  - int/pointer to void: fn_80403DE4 (wide sprintf, three units), fn_8040321C, fn_803FFA60
    (memcpy, r3 advanced), fn_80402EF8, fn_8007A94C and fn_8007B440 (forwarders to a
    v40 virtual; the definitions in tu_8007A4DC are void now), the (int*, int, ...) overload
    of fn_80329FA0.
  - The epilogue is evidence only for the void-to-int direction. A void declaration of a
    function that does return a value is still what some callers' schedules need; the
    caller decides.
  - fn_8058C020 and fn_8058E180 (new, same shape as fn_8058BF68) use the int fn_80582CF8.
  - Where only one call site needs the other type, call through a cast:
    `((void (*)(char*, const char*, ...))fn_80403DE4)(out, fmt, p);` (fn_804ACA20).
- Tool: `W8o5/rettoggle.py <repo> <unit> <fn>` preprocesses the unit, flips each callee's
  declared return type in the `.i` (all declarations of that name) and scores the function.
  `PAIRS=1` also tries every pair (fn_800E25E0 needed two flips). `W8o5/reorder_scan.py
  <repo> [minpct]` lists unmatched functions whose only difference is a reorder, with the
  calls around each cluster. All single flips over every free function at 90-99% were run;
  everything they found is committed or listed below.

### Float arguments: their position in the prototype (3 functions)
- f-register arguments do not show where the float sits in the parameter list, but the
  argument moves are emitted in prototype order and sched breaks ties by that order.
- Tell: `lfs f1`/`fmr f2` lands after (or before) an integer argument move that retail
  orders the other way.
- Recipe: move the float parameters in the caller's declaration (extern "C" names do not
  change) and reorder the call arguments. fn_80591AF4 / fn_805919E8 take
  `(m, float v, x, i, k)` (fn_8059403C, fn_80593F30); fn_80594250 takes
  `(self, i, a, f0, f1, b, c)` (fn_8058FDCC). The definitions were left alone.

### Callee-saved permutations (family 2): four different causes
- fn_80533120: retail copies the result's zero into the counter (`li r30,0` ... `mr r31,r30`).
  CSE folds any `i = r` back to `li`, except when i already holds the same value: CSE leaves
  a set that does not change the destination's value class alone. Recipe:
  `int r = 0; unsigned i = 0; ... for (i = r; i <= 9; i++)`. Flow deletes the dead
  `i = 0`, the copy survives, and r has a fourth reference, which lifts it above col and
  self in global-alloc.
- fn_8025F7F0: `int r = 0; if (p) {...} return r;` makes p live one insn shorter than
  self, so p wins the priority tie (4 refs each). `if (p == 0) return 0; ...; return f(..) != 0;`
  gives both 4 refs over 14 insns, and the lower pseudo (self) gets r31 as in retail.
- fn_804E2014: the getter call was inside the loop (`fn_8005B87C(fn_8005ACE4(), i, ..)`).
  Hoisting it into a local gives the same instructions, because branch targets are masked
  in the diff, but a different allocation. Check where retail's back edge lands before
  blaming the allocator.
- fn_802AF624: the order of the prologue parameter copies. assign_parms emits them in order
  and nothing reorders them. With the cursor as a local copy of the parameter
  (`const char* s = str;`), combine merges the parameter copy into the local copy, so
  `mr r31,r4` comes after the other parameter copies. Declare the local before
  `int n = 0` so it stays ahead of the n store.
- Still open: fn_80536F28, fn_80537054, fn_8053923C (db/tu_80535360, bubble sorts). The
  &bufB address pseudo (4 refs over 13 insns, 0.615) outranks self (11 refs over 66, 0.5);
  retail has self first. Statement and loop-form variants changed nothing.

### Entry jump into the middle of a loop (family 3, 2 functions)
- Retail's `b` lands inside the argument setup of the loop's call, after a pre-loop copy of
  the first part. That is a call written twice in the source, once before the loop and once
  at its end; jump2 cross-jumps the identical tails of the two copies.
- A `while ((n = f(...)) != 0)` condition can't produce this: duplicate_loop_exit_test
  refuses exit tests that contain a CALL_INSN, so the loop stays rotated.
- Recipe: `P* n = f(list, p, 0); while (n != 0) { ...; p = n; n = f(list, p, 0); }`
  (fn_80255284, fn_80254EA4). fn_80254EA4 also needed `int st = p->m44C->m700->m3BC;`
  before the `a != 0 ||` test, so its loads come ahead of the branch.
- Still open: fn_8056A908, fn_8056B658 (db/tu_8056A248) and fn_80555D88. Retail neither
  strength-reduces i*28 nor hoists the table load, yet weights the loop's references like a
  real loop. A goto loop stops the strength reduction but changes the allocation, and the
  first KeyAt then cross-jumps with the loop's copy; that copy reuses the table pointer in
  r11 in retail.

### Smaller recipes
- Mangled callee names give the true arity: fn_802C40BC is
  `__FP11Unk802C3B60P16Unk802C2188_Pair`, so it takes two arguments. Passing the caller's
  x as the second one fixed the prologue order of fn_802AE474 and fn_802AE4C0.
- `if (r == 1) return 5; return r;` stores straight into the return register; jump's
  "x = b; if (c) x = a" rewrite then hoists `li r3,5` above the branch, and r gets r0
  (fn_805881E4, fn_805898A4). A `k` result variable lost r3 to r.
- `int k = a == 4 ? -10000000 : a == 3 ? -5000000 : 0;` lays the a == 4 arm out last
  (fn_8058E180).

### Solved in scratch, units busy at commit time
- game/tu_80101254 fn_80104798: declare both fn_80403DE4 overloads in tu_800F1AEC.h void
  (tu_800F56B4, the other includer, stays 44/60).
- game/tu_800D4D0C fn_800D649C: `UiScrRaw2* fn_800D0D9C(...)` in tu_800D4D0C.h (a ctor that
  returns this).
- game/tu_800E0164 fn_800E25E0: in tu_800E0164.h, `int fn_801254EC(...)` and
  `void fn_8007CF44(...)`.
- Patches: `W8o5/busy_*.patch`.

### Still open (tried this round)
- Member-vptr dtors fn_8052849C, fn_80528588, fn_80528648 (fe/tu_805283C4): retail's self
  copy is r8 because some pseudo held r9 and later vanished. All six store orders, with and
  without inline member-dtor helpers, give r9.
- `mr.` vs `cmpwi r3,0` (fn_8052390C family, fe/tu_80520BE0): combine merges the copy of
  the call result into the compare (`mr.`); retail compares r3 and returns it untouched on
  the false path. Forms that drop the copy (`if (r != 0) {...; return 1;} return r;`) get
  `cmpwi`, but CSE then turns the false-path return into `li r3,0`. Ternary, switch,
  inline, unsigned and assignment-in-condition forms all keep the `mr.`.

## Hard-case families 6 (Opus, 2026-10-12)

Matched 20 functions in 10 units. Scratch tools are in `scratchpad/W8o6/`.

### The case value kept live in the case bodies (family 1, 3 functions)
- Tell: retail compares the switch index against a field with `cmpw rId,r0` (and passes
  it with `mr r4,rId`) inside a case body. Ours folds the known case value (`cmpwi r0,K`,
  `li r4,K`), and the index dies early, so the frame and the callee-saved registers
  differ.
- Mechanism (CSE, `-fcse-follow-jumps`):
  - The bodies are reached along a CSE path: the `beq` into a single-use case label that
    follows a barrier is followed, and record_jump_equiv puts the index and K in one class.
  - fold_rtx then puts K into the compare, but only as its second operand: the `cmpsi`
    pattern needs a register first, and COMPARE is not commutative.
  - Paths are at most 9 branches deep (PATHLENGTH 10). Bodies deeper in the tree are
    processed on their own, without the equivalence. That is why retail's `id` argument
    in case 0x88 of fn_80163CC4 is a plain `mr r4,r31`.
- Recipe: write the kind check with the index first,
  `#define EVK(T, k) ((T*)(e ? ((k) == e->m0 ? e : 0) : 0))`, or `if (id == m->m0)` in
  the cast inline. Matched fn_80163CC4 (600 insns) and fn_80143134.
- More recipes found on fn_80163CC4:
  - A value the entry block computed is reused in a body (`fadds f0,f13,f0`) only when
    the body repeats the expression and its loads survive the -ffloat-store spill. Read
    the field through an in-struct view (`((View*)a)->m4C`, unsigned). A cast pointer
    (`*(unsigned*)&a->m4C`) is not in-struct, so the spill of `t` may alias it and the
    load is redone.
  - A cast written inside the argument list (`f(t, 0.0f, id, EVK(T, id)->m8->m458, ...)`)
    loads `t` before the null check. A cast in a local before the call loads it after.
  - A by-value struct copy whose stores retail makes r1-based goes through an inline
    (`inline Out OutOf(const Ev* c) { return c->mC; }`), as in "Vec3 copy destination
    addressing".
- fn_80143134 also needed the flag store written as `lbl_80687CC8.m4 = 1` (the same
  address as lbl_80687CCC). An in-struct store may alias the `m8` load, so the load
  stays after it.
- fn_8002395C (`if (idx == 0) {...}`) is the same CSE equivalence the other way round.
  The `= 0` stores take idx's register: CSE gives the zero temporary idx's quantity,
  which is retail's `stw r31`. Retail addresses the slot as `lwzx r29,r31` (base + idx,
  unscaled). A scaled `arr[idx]` folds to `lwz 128(x)`.
  `*(T**)((char*)arr + idx)` (equal to arr[0] in that branch) reproduces it. Through an
  inline parameter it folds again.
- Scanner: `fam1scan.py <repo>` lists unmatched functions where retail has more
  register-register `cmpw` and ours more `cmpwi`.

### A field loaded before a spilled float in a compare (family 2, 3 functions)
- Tell: retail does `lfs fA,k(rObj)` then `lfs fB,n(r1)` then `fcmpu fB,fA`. Ours loads the
  stack float first. Swapping the C operands gives the right load order, but the fcmpu
  operands come out swapped.
- Mechanism: expand_expr returns both operands as MEMs. The compare loads them into
  registers in operand order (op0 first). An operand whose expansion emits insns, such as
  an inline call, is loaded while it is expanded, so before op0.
- Recipe: read the field through an inline accessor,
  `inline float M5C(const Data* m) { return m->m5C; }`, then `if (a <= M5C(x->m8C))`.
  Matched fn_80022780 (m4C, m40), fn_80022A28 (m5C) and fn_80022BE0 (m20).
- fn_80022BE0 also needed:
  - `case 1:` and `case 3:` written as two bodies, not `case 1: case 3:`. A label with two
    uses is not followed by CSE, so x->m8C was reloaded. jump2 merges the two copies.
  - `int r = 3; if (!(len2 > thr)) r = 2;` instead of the ternary.
- Scanner: `fam2scan.py <repo>`. Its other hits (fn_802142C8, goal functions) are
  different problems.

### lis cluster above a store (family 3, 14 functions)
- Tell: before a `(float)n * (1/60)` argument, retail hoists the `lis 0x4330` and both
  constant `lis @ha` above a preceding field store or counter increment, but keeps the
  `lfd`/`lfs` below it. Ours moves the loads above the store, or reuses one `lis`
  register for both constants.
- Mechanism: constant-pool loads are unchanging MEMs, which sched1 may move above any
  store. A constant-pool MEM copied by the inliner loses the flag (Hard-case families
  3, recipe A), so it must stay below stores that may alias it. Its `lis` (HIGH) has no
  memory dependence and still moves up.
- Recipe: write the frames-to-seconds conversion as an inline,
  `inline float Secs(unsigned n) { return (float)n * 0.016666668f; }` (the template
  form `template <class T> inline float Secs(T n)` also works), and call it in place of
  the expression. Matched:
  - tu_80029000: fn_800292EC, and the new fn_800297D4 and fn_80029FE4.
  - tu_8002B430: fn_8002BB3C (also needs m130 stored before m12C), fn_8002BE10,
    fn_8002BF20, fn_8002C540.
  - tu_800239F4: fn_800243D4, fn_800263D4, fn_800264F4 (also needs m710 stored before
    m6BC).
  - Others: fn_80291378, fn_8029D094, fn_802456C8, fn_802496BC (these take the actor's
    m4C).
- Apply it per function, gated on the score. It made fn_8002BB3C (alone) and
  fn_8003DC00 worse. `fam3gen.py <unit>` tries the template form on every non-matching
  function that has the conversion, and `fam3gapply.py <unit> fn...` writes it.
- fn_80029FE4 also needed the fn_80253E7C result in a local before
  `fn_8003C270(x->m6C8, k)`, so the call comes before the m6C8 load.

### Still open
- fn_80022DF8 (tu_80021BE8, 99 of 100): retail reloads `b` (`lfs f13,8(r1)`) in the
  block before the cross-jumped tail. Ours keeps it in f13 (GCSE). The goto
  reconstruction probably differs from the original if/else.
- fn_80027CF0 (tu_80026A48) and fn_8002B430 (tu_8002B430) are not written. They are
  family 3 (use the Secs inline). fn_80027CF0 also has a volatile saturating loop over
  m270[0..2] (copy fn_8003049C in tu_8002EB80) and the fields m740, m798, m7C8 and m7CC,
  which the header does not declare yet.
- Families 4 to 9 of the round-6 list were not reached: the row parser's `mr r3,r31`,
  scan-loop pointer copies, the duplicated goal pointer, the ealib switch subtree, the
  separate zero registers, and the round-5 leftovers.

## Pass 4 (p4-00..p4-12, 2026-10-12, condensed from worker reports)

Callees and calls:
- A callee's declared return type changes argument-move order and cross-jumping of call tails. Toggle void/int (W8o5/rettoggle.py). When the prototype lives in a shared header, declare a local overload with a distinct pointer parameter type instead of editing the header.
- A callee that reads r4..r6 its caller never sets takes the caller's parameters: pass them through, or widen the callee's prototype (`tools/match/passthru.py .`).
- `bl` with `crclr cr1eq`: call through a variadic function-pointer cast. `crset`: a float passed to a varargs callee.
- A function whose unmangled symbol another unit references can't be renamed by rename.py: define it `extern "C"` (change the TU's forward declaration too).
- A virtual slot whose signature differs from the shared class: a local view class `class V { char pad0[0xVPTR]; virtual void s1(); ... virtual R sN(args); }` and a cast. g++ 2.95 puts the vptr after the data unless there is a polymorphic base; use an empty polymorphic base for vptr at 0. A virtual call on an embedded member binds statically; go through a pointer cast.

Stack frames and floats (-ffloat-store):
- BLKmode locals (structs > 8 bytes, arrays) get slots at their declaration, in order; address-taken scalars and 8-byte two-float structs get slots late, in address-taken order. Group V2s in one struct declared first to fix the layout. A never-read `float unused;` still reserves a slot; locals in a nested `{}` free their slot after the block.
- An inline's float params get their own slots (outer inline first). Use pointer accessors, or a pass-through `inline float Id(float v)` to share one temp slot.
- `const float k = 10.0f;` stays in a callee-saved FPR across calls; one initialised from an extern const is spilled and reloaded.
- Nested `Len(Sub(a, b))` with no named Vec3 gives retail's slots; a named temp does not. A call result bound to a const reference uses the call temp directly.
- Stack buffer sizes set the frame: try 0x3C/0x40/0x44 when only the frame differs.
- `char buf[N] = "";` gives lbz/stb of the pooled empty string plus `memset(buf+1, 0, N-1)` with crclr.

Registers and scheduling:
- One loop counter shared across sibling loops raises its allocation priority.
- Per-function volatile view of one field reproduces retail re-reads (never volatile in a shared header).
- gcse merges `base + const` across joins: compute each use's base from a shared `off` local (`char* e2 = tbl + off;`).
- `int r; if (c) r = ...; else {...} return r;` keeps the first arm first; `if (call() != 0) return 0;` hoists `li r3,0`.
- `int z = 0; f = x < z;` keeps cmpwi+mfcr; `x < 0` folds to srwi. GT-bit extract (`rlwinm 30,31,31` after mfcr) means `>`.

Switches:
- `switch ((unsigned)kind)` gives the 1, <1, 2, 3 test order. Dummy `case 0: break;` / `case 6: break;` shape the root and leaves. GNU `case 0 ... 25:` ranges reproduce range trees; a dead statement between stacked labels stops range grouping. A default-label node moves the root: add `case 1:` to the default group.

Data and literals:
- Never write a symbol's address as an integer literal: name the symbol. check_literals resolves pointers to externs since 2026-10-12.
- A struct of two floats `{0,0}` gives word stores; a 16-byte `{0,0,0,0}` gives a memset call.

## Pass 5 (p5 batches, 2026-10-12 evening, condensed from worker reports)

Loops and counters:
- Which nested loop gets `bdnz` is decided by global-alloc priority of the count pseudos (floor_log2(refs)*refs/life), not by loop syntax; the innermost constant-count loop wins by default. To give CTR to an outer loop, declare its counter once at function scope and reuse it in sibling loops. Check with cc1plus `-dL -dg -dl`: look for `insert_bct N: ... failed: count register already in use`.
- Byte-sum loops (the "SumRow" family) that compile to `bdnz` with `addi rX,rec,0x1B4` inside the loop are an inline `int SumB(Rec* r) { for (int j = 0; j < 0x80; j++) s += r->a[(unsigned char)j]; }`; written in the body they get the wrong registers.
- Pre-tested loop with a call and a shared loop-invariant `lis`: write `if (!(a)) goto done; if (!(b)) goto done; do { ... if (!(a)) break; } while (b); done:`. for/while give `b <test>`.
- A loop whose test contains calls stays rotated (entry `b` into the test): put the calls in the `while` condition.
- Array-with-buffer ctor chains: `i = 0;` right before the loop, not at the top (else it merges with the shared zero register).
- `new (heap) T[n]` with an inline ctor reproduces the vec-init guard (redundant second `cmpwi n,0`) and `do {...} while (k-- != 0)`.
- `int k = j;` copy used for a later `*4` stops gcse sharing one `slwi` across a loop.

Stores, loads and scheduling:
- Volatile store then plain load (`*(volatile int*)&kk->m30 = v;`) reproduces a hoisted `li r0,0` plus reload in key-switch tails; use the v-form switch (`int v = 0; switch (k) {...} store v`).
- A halfword stored then re-read without forwarding (`sth; lhz`): make that member volatile in a local view.
- The first store of an inline V3 copy written as `*(float*)d = ...` keeps the next global load below it.
- `{ int h = f(...); g = h; }` stops the `lis` for later stores hoisting over calls in static-init sequences.
- Typed (FeW*) member stores block the scheduler from moving a later global load above them; a `void*` store does not.
- The same call written in both arms of an if/else reproduces retail's partial cross-jump of the argument setup.
- `v = v*16 - K + c` is reassociated; write `v *= 16; v += c - K;`.
- Sum-term order (`x*x + z*z` vs `z*z + x*x`) changes fmadd operand order; brute-force the 2^n orders.

Switches:
- Lopsided compare chains: GCC deletes compares whose two outcomes are identical, so the original had extra empty cases. Add the sibling function's case values as empty `break` cases. Derive the case set from balance_case_nodes (a range counts as 2); put shared-body cases first in source order (jump2 keeps the first copy).
- Switch on a copy (`int k2 = k;`) when an outer if precedes it, so gcse does not hoist the compare into a callee-saved CR.
- After a `k==1||k==3` guard, an explicit inner `switch (k) { case 1: ... case 3: ... }` reproduces cr4 reuse and out-of-line bodies.

Calls and arguments:
- Pass-through: `fn_X(o->m4, h)` with h unset (callee reads the caller's live r4); a 2-arg callee called with one visible argument takes the byte already in r4.
- A call site with `crclr` against a non-variadic definition: declare the exact `extern "C"` prototype and call through a variadic function-pointer cast (e.g. a `#define CALL_X ((R (*)(A, ...))X)`). PMF-returning functions: `((Pmf (*)(int, int, ...))fn)(self, k)`.
- By-value struct argument: pass it through an inline wrapper. A struct-return field is read directly (`f(x).m2 == K`); a named copy adds a stack copy.
- `(char)m` at the call gives the `extsb` there; keep the variable int.
- A float that retail reloads after every call is an `extern float lbl_X`; a literal gets CSE'd into a callee-saved FPR.
- `r = c ? -1 : 4;` and `c ? 4 : -1` give opposite `li`/`beq` orders. `if (!(r >= u)) r = u;` stores u directly; `r >?= u` adds an `fmr`.
- A widget call whose argument contains a call keeps `this` and the vptr in callee-saved registers; compute the argument into a plain local first if retail does not.

Frames and types:
- char[5..7] locals are BLKmode (slot at declaration); char[4]/char[8] are scalar modes (end of frame).
- `unsigned w[8]` with `*(float*)&w[i]` gives eight distinct slots where an inline's local would reuse one.
- Inline float params take frame slots (`Rand(rng, scale)`); a plain local `float k = ...` gets the local slot, an inline float param the temp slot.
- Vec3 temps: `Vec3 nn = Norm(*n);` is one copy, `nn = Norm(...)` two; placement new for `*out = Add(...)`; by-value Vec3 inline params allocate extra temps; scope Sub temps in `{}` to reuse slots; an else-branch keeps the if-condition's float-param slots live.
- One function-level `float a;` reused across matrix rows raises its priority (gets f13).
- Local copy of a rodata table: `Tab8 t = lbl_X;` with a struct-typed extern gives the block copy and keeps the relocation.
- A virtual view with an empty polymorphic base (vptr at 0) plus `inline void CpQ(T* d, const T& s) { *d = s; }` gives frame-direct copies of a vcall-filled temp.
- Bit getters: `*(unsigned char*)&w & 1` (lbz), `*(unsigned short*)&w & 1` (lhz), else `((unsigned)w >> n) & 1`. `x % m == 0` flags: `unsigned short r = nn % m; f = (r == 0);`.
- Implicit copy assignment of a class with a vptr copies the whole object and restores the vptr; a small POD copies only data words.
- A `__static_initialization_and_destruction_0` whose `_GLOBAL_.I/.D` wrappers live in another object gets a suffixed name; only a hand-written `fn_XXXX(int init, int prio)` pairs with it.
- EA shader setup functions clone from fn_80366D94 (define `extern "C"`, run rename.py); only the `m0`/`m6C`/`m8` store order needs a permutation search.

Tooling notes:
- Q27/rv.py segments at the first column-0 `}` after the start line: indent inner blocks. Command lines overflow above ~500 variants; batch them.
- Units that include `../../include/...` relative headers cannot be scored from a scratch directory unless the include is made absolute (or the header copied under scratch/include).
- Wall: retail functions using `mftb`, `mtspr`, or a literal data word after a `bl` cannot be produced from C; skip them.

Pass 5, second half (p5-09/11/13/14/17/21/26/04):
- **Spare frame bytes**: a local object of a class with an empty inline destructor (`struct S { int a, b; ~S() {} } s;`) reserves a stack slot that no code references, at its declaration. Unused arrays, ctor-only objects and dead conversions do not. This explains many "frame 8/16 bytes too small" near-misses (fn_8038BCD0 matched with an 8-byte one).
- Dtor families: member arrays of virtual-dtor elements plus small per-vtable store classes with inline dtors, called explicitly (`((T*)(self + off))->~T()`), reproduce open-coded array destruction. Vptr resets that run after the member loops belong in a base class's inline dtor. An empty `~Base() {}` stops the out-of-line base dtor call. `struct TmpE : Tmp { ~TmpE() { vp = lbl; } }` gives per-return/per-continue vptr resets.
- A polymorphic class's synthesized copy-assign saves and restores the destination vptr through a stack slot (stub class with declared-only virtuals and an inline dtor). A singleton copy with explicit save/restore: `const void* volatile sv = obj.vp; obj = *src; obj.vp = sv;` (int members, explicit `vp` field, no real vtable).
- Host-object virtual calls at a large offset: `struct D { char pad[0xDBC]; }; struct H : D { virtual void v1(); ... };` puts the vptr at +0xDBC; slot n is at vtable +8+8n.
- Struct-returning calls take a hidden r3 pointer: declare the real struct return (`FeT16 s14();`) and nest it (`o->v35(p->s14())`); no copy is emitted. Small structs by value go through a hidden reference to a temp at 8(r1).
- Compose call chains when retail has no argument setup between calls: `fn_800C80xx(obj->v32(s, 1))`. A named temporary for a call-result receiver gives retail's `mr r11,r3` copy.
- Per-arm stores (each switch/if arm stores its own constant, then `break`) are tail-merged after register allocation and give `li rX,K; b join`; a shared `next` variable does not. A run of `if (sel == self->mN)` blocks must be an else-if chain for jump2 to cross-jump the tails. Two void vcalls flowing to the same label get cross-jumped; declare one slot `virtual int` to stop it.
- Loops: explicit peel of the first iteration plus `for (k = 1; ...)` reproduces a jump into the loop tail; `i = 0; if (i < n) do { ...; i++; } while (i < n);` gives an addi/cmpw/blt loop with a pre-test; `i != 10` as bound removes a cr7 compare shared with `i == 9`; a guarded do-while puts the offset init after the guard. A separate local `int d = j - 1;` avoids an extra giv.
- Flags and bits: `int c1 = !(mode ^ 1);` computed early gives xori/subfic/adde; an inline `int r = 0; if (v) r = 1; return r;` gives `li; beq; li`; a top-bit read needs a 1-bit bitfield (`unsigned top:1`) for srwi + cmpwi; a bitfield clear via an inline's parameter gives `rlwimi` from a shared zero register (literal 0 gives rlwinm).
- Floats: a float local assigned from a pool float spills under -ffloat-store; use the `extern const float` directly in each expression. `!(f >= 0.5f)` gives `cror un,eq,gt; bso`; `!(t < 0.0f)` gives a plain `blt`. Offsets in separate float locals declared inside the `if` give retail's slots.
- Read back a just-stored field (`r->m14 = x; use(r->m14)`) for retail's li-before-stw order. `char* bp = (char*)buf + 0x600; f(bp - remaining)` stops a loop-invariant hoist that the int form allows.
- `extern "C"` function with an empty prototype `()` passes no argument: use it when retail leaves a stale r3. `rand` and other libc callees must use their real names (objdiff counts relocation names).
- Static-init wrappers: build first, then `tools/scout/rename.py <unit> --write` renames `_GLOBAL_.I.lbl_X` to `_GLOBAL_.I.fn_X`; rename.py only works after a build that includes the function.
- diff_unit's MATCH can hide a different branch target: trust report.json fuzzy == 100. check_literals reads the linked main.elf, so run it after a full ninja.
- A -ffloat-store float parameter is spilled at its position in the C parameter list, regardless of register class: `fn(o, a, b, char* name, float f, int flag)` puts `stfs f1,8(r1)` between the r6 and r7 copies. Float clamp polarity: `if (!(f <= K))` gives cror un,eq,lt/bso; `if (!(f >= K))` cror un,eq,gt/bso; `if (!(cur < hi))` a plain blt; `f > K` ble.
- `n.m4 = 0; cnt = 0;` (the scalar assigned after the struct store) keeps two separate zero registers. Unsigned int-to-float without xoris is `(float)*(unsigned*)&x`.

## Near-miss pass and pass 6 (2026-10-12 night, condensed from worker reports)

Method that converted near-misses (nm-03: 10/10, nm-05: 7 plus 2 raised):
- Read the allocator instead of guessing. `cc1plus -dg -dl` (or `ngccc ... -dg -save-temps`, giving `t.i.greg`/`.lreg`) lists "regs to allocate" in priority order with refs and live length per pseudo. Global-alloc priority is floor_log2(refs)*refs/life, and the higher priority gets the higher callee-saved register. To flip two registers, change one pseudo's refs or life:
  - duplicate `return r;` on every path;
  - give the result pseudo more sets (separate case bodies);
  - share one local between two loops;
  - copy an index (`unsigned j = i;`).
- A/B a pass with flags (`-fno-gcse`, `-fno-cse-skip-blocks`) to find which pass rewrites the code, then defeat it in source: reuse the temporary for a later value, add a dead store, or write a lookup once per arm.
- Block-local pseudos are allocated in creation order: writing an expression once per arm (`c ? A[f(x,0)] : B[f(x,b)]`) changes which one gets r0/r9/r11.
- Score many small variants with `tools/match/score_variants.py` (about 0.2 s each) from a spec of OLD text plus replacements.
- decomp-permuter (`tools/match/permute.py`) mostly produced cheating candidates: dropped calls, early returns, uninitialised temps. Use it only as a lead; reject any candidate that loses a `bl` or changes the instruction count.

Shapes:
- Select-then-store (`v = c ? 0 : 1; x->m = v;`) vs per-arm stores (`if (c) x->m = 0; else x->m = 1;`): retail is usually per-arm (jump2 tail-merges them).
- A shared `yes:` label merges the `li r3,1`. Write `if (... ) return 1;` in each arm when retail keeps separate ones.
- Peeled first iteration of a search loop: read through the index variable copied from the result (`i = r; acc += m[i];`), not through a literal 0.
- MIN/MAX (`<?`, `>?`) expand operand 1 first, including a global's `lis`, so `lbl_B >? (lbl_A <? v)` decides which `lis` comes first.
- Struct-return outputs: read the whole word and truncate (`unsigned bw = *(unsigned*)&buf; (unsigned short)bw`) to get `lhz` at the right offset. A field read goes through an address register.
- A byte-aligned shift (`(w >> 24) & 0x7F`) is narrowed to `lbz`. Retail's `lwz` + `rlwinm` needs a local bitfield view.
- A float-returning callee (fctiwz after the call): declare its exact mangled name locally as `extern "C" float`.
- An empty inline destructor on a local object reserves an unreferenced stack slot (see Pass 5). A spare 32-byte dtor object can move all temporaries by 0x20.
- Header `extern const Vec3f` loads hoist above int stores. Compare and copy through a non-const view (`Vec3f* kp = (Vec3f*)&lbl_X`) to keep them below.
- Brute-force short store runs exhaustively (6 stores = 720 orders, about 2 minutes); hill-climbing stalls on them.
- Data walls not solved yet:
  - by-value Date stores into the frame: (mem (addressof)) at a nonzero offset is forced into a register, and CSE merges the two;
  - a peeled first iteration that is not constant-folded (`lbzx` with the zero register; fn_80097318 and its siblings).


## Matched twins for existing near-misses (Codex, 2026-10-13)

Run `tools/match/clone.py --scan` before expensive random search, even if the
remaining functions already have definitions. The scan finds exact retail
instruction-shape twins, but normal clone mode skips existing definitions. That
skip does not mean a twin is useless: compare the matched twin's source manually,
retain the target's symbols/types/section, score a scratch copy, then run the full
build, literal/target check and verifier. Do not copy relocation targets blindly.

Confirmed examples:
- `snd/tu_803A9204` iSNDrandom: twin `ealib/tu_804027DC` fn_804027DC. The same
  six-word generator has array vs struct storage. Three volatile intermediate
  stores preserve the later carry reloads; adapt the state accesses, not its
  extern declaration. Reached 66/66 instructions, +264 bytes.
- `fe/tu_8051E878` fn_8051F784: twin fn_8051FA24 in the same unit. The final
  s9 call belongs after the conditional, so both arms execute it. Reached 49/49.
- `ealib/tu_803D2B20` fn_803D2B64: twin `ealib/tu_803CECA4` fn_803D189C.
  Use a separate difference temporary and `x >= hi` (not `!(x < hi)`, which
  differs for NaNs). Reached 23/23.
- `game/tu_8011243C` fn_8011489C: twin `game/tu_801164AC` fn_80117BBC.
  Its 8-byte event needs an empty destructor to select the old compiler's
  object mode. Explicit id/vptr stores with a plain trivial struct were 54
  instructions; the empty-destructor form is the exact 52-instruction target.
- `game/tu_801A57C8` fn_801A7CBC: twin `game/tu_800B5C68` fn_800B7FC4.
  A 16-byte character buffer and explicit calls to fn_8035682C / fn_800B64BC
  reproduce register priority; the class-constructor form swapped r30/r31.
  Reached 32/32. The target's string remains lbl_805CEB0C.

Each example passed the unmodified verifier without regressions. A twin is a
starting point; differing prototypes, flags or object modes can still prevent a
match. Avoid copying a donor's guessed behavior when its retail shape differs.

## Source-link import repair (Codex, 2026-10-13)

Run link_candidates.py after a current successful build. A fully matched object
with matching allocated sections can still be unlinked because its caller uses
a guessed address-name declaration while main.elf exports the real C symbol.
Inspect the actual implementation and symbols.txt before changing the caller.
The trace-tag helper fn_80391C04 had a C implementation but several C++ caller
declarations; one shared header correction plus 11 local fixes unlocked 15 units.

Canonical libc names can enable builtins and silently alter generated code.
Compare a scratch object first. For memcpy callers game/tu_803543FC and
game/tu_80353930, per-unit -fno-builtin preserves the explicit retail calls and
all code bytes. Do not apply that flag globally. Changing a declaration is
accepted only after the final retail DOL hash, literal/target checks and the
unmodified regression verifier pass; an import shortlist alone is not proof.

Vector norm fn_80402A90: reusing x for x*x + y*y before loading z reproduced the
exact 15 instructions, whereas a direct expression and separate product
temporaries changed load/register order. Preserve floating-point grouping.

## Real global initialization and inline dependencies (Codex, 2026-10-13)

For a large compiler-generated vector initializer, adapt an already matched
global-initialization twin and keep the target's points and destination globals.
Do not replace C++ object initialization with a sequence of assignments: the
old compiler creates different aggregate temporaries and spills. For
game/tu_800034A0 the explicit assignments were 967 instructions; the 13 genuine
global initializers reproduce the retail 889. The compiler-generated names are
recorded in symbols.txt with the static helper scoped local. The original
unit's unrelated rodata remains a separate source-link blocker.

When clone.py copies a class declaration, it now also collects the donor's
separate inline member bodies and their dependencies. Previously it copied the
prototypes alone, producing out-of-line calls. This fixed the 415-vs-426 length
failure for fn_803EA500, but its unresolved GXWGFifo still fails the strict
pre-check. Do not relax that check to declare a match.

For trivial arrays/objects, an explicit call to the established deallocator can
resolve a compiler-generated __builtin_delete import without a linker alias.
Use it only when no element/object destructor is being skipped. For a real
class destructor, a class-specific inline operator delete can forward to that
same runtime function. Both approaches in this sweep were retained only after
the actual source-linked DOL retained the exact retail hash.

## Data ownership can block fully matched code (Codex, 2026-10-13)

A code-only split target may omit the private constants or BSS that its actual
source object emits. data_candidates.py uses paired relocations, canonical
sized global objects, initialized pointers, and unique aligned whole-section
byte searches to shortlist placements. It refuses zero-block and ambiguous
searches. ProDG C globals may have sized STT_NOTYPE symbols rather than OBJECT.
Check external users and existing split ownership before changing boundaries;
identical bytes alone do not prove ownership. The retail hash and unmodified
verifier remain mandatory. This approach source-linked 29 units and 26,996
code bytes in the initial trials, with 4,160 bytes of compiled data.

Oversized anonymous constant-pool metadata can cross a proven new boundary.
Correct an extent only with compiled-section and retail-byte evidence. Keep
shared pools extracted until their users and actual ownership are understood;
ef_log and sf_sin trials exposed references from other extracted objects.


### Paired constant state initialization (2026-10-13)

For the event-string initializers fn_803F113C, fn_803F1204 and fn_803F12D4,
retail loads the positive state before the negative state but stores the negative
field first. Store permutations alone failed. An initialized local preserves the
source dependency until the compiler's scheduling stages:

```cpp
int active;
// Existing lock and event-pointer setup.
active = 1;
event->m18 = -active;
event->m1C = active;
```

This produces the same -1/1 field values and exact instructions in all three
functions (612 B). It does not fix every related initializer: fn_803F0FCC still
has three differing words, and the short-zero variants fn_803F0D94/108C remain
parked. Keep successful rewrites function-local and recheck branches, literal
targets and the retail hash; do not apply the recipe unit-wide.


### Writable constants versus duplicate pools (2026-10-13)

The double/float ceil references use a const-qualified private huge value. ProDG
C keeps that definition in read-only small data while substituting another copy
in writable small data for each function's arithmetic. The retail code references
the writable block, but the redundant pool has no unique placement evidence.
Making just huge mutable produces the actual 16/8-byte writable blocks without
the duplicate. Changing huge+x to x+huge restores the exact target fadd operand
ordering (including the machine's NaN behavior). Both units then pass the retail
hash and verifier. This is a source constness finding, not permission to drop
arbitrary unreferenced constants. Check exact words and all data bytes per unit.

An unresolved vector-deallocation builtin may also hide a simple null guard:
in fn_800C334C, guarded fn_80377488(pointer) reproduces all 33 instructions;
an unguarded call had only 31. Check the actual provider and local branch targets.


### Inline float result placement (2026-10-13)

In fn_801A2158, an inline clamp assigned a conditional expression to its own
float parameter before returning it. The caller returned the helper result
directly, introducing a distinct stack slot for that inline return. Returning
the expression directly from the helper and assigning it to the caller's
existing local produces the exact 56 target words, including eight local branch
destinations. Either change alone failed. All other 65 function streams stayed
unchanged. Preserve the existing comparison and GNU min-expression semantics;
sequential min/max operations generated different instructions and branches.

Named canonical data references can also keep reconstructed objects code-only:
fe/tu_804B985C retains its local ids/values arrays but initializes them with
memcpy from the two original 120-byte table objects. Paired relocations prove
which objects are used; bytes and extents are checked independently. Replacing
the locals with direct global reads would change the original stack behavior.


### Local object alias and destructor-store addressing (2026-10-13)

fn_80562BC8 used a pointer q = &t for a stack-local temporary list. Calling the
same operations through t directly lets ProDG address the final inline destructor
vptr store as 24(r1), exactly as retail, instead of 16(r29). Only that one word
changes in the 155-instruction function; twelve local branches and thirty data/call
references agree. This is alias/lifetime code generation, not a reason to change
the list layout or to replace required destructor behavior with manual stores.
