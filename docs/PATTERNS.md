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
- Still open: locals at a nonzero frame offset. expand_expr(ADDR_EXPR) runs
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
- Dead `cmpwi`/`cmplwi` before `li r3,0; blr` (fn_8006FB10, FB1C, FF9C,
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
- Loop test at the top with a back edge to it: fn_80255284, fn_80257DFC.
- Dead `cmpwi` before a constant return (mechanism in Hard-case families 2).

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
