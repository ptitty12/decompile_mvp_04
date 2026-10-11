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
