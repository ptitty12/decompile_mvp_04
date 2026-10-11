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
