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
- Constructor: `cX::cX() : Unk8037B3E8(lbl_name)` or `: Unk8037B3E8(hash)`.
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
  Open: family B with K != 0 and N == 0 has `li r5` before `li r3` in retail (not reproduced).
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
