## p4-01 (W1) merged 14:19 as 0e2a49eb: +28 functions (19,729 -> 19,752 on main)
- Units: tu_8004B6BC 7->19/30, tu_8004E364 16->24/30, tu_8005ADD0 24->26/30, tu_8006D05C 47->51/60, tu_80077238 50->52/60, tu_80073914 48/60.
- Near-misses kept: fn_8004E28C (r4 vs r11), fn_8004C660 (addi+lwzx vs add+lwz), fn_800767DC (r9 vs r11/r0).
- Patterns for PATTERNS.md: struct-array indexing beats offset math in loops; two-case switch needs dummy `case 2: break;`;
  `int z = 0; f = x < z;` keeps cmpwi+mfcr scc; `(unsigned)a >= (unsigned)b` gives subfc/adde; accumulate into one result
  variable for averaged switch returns; vptr rewritten after call: `Ev* p = &e; p->vt = base; ...; p->vt = base;` for mixed r1/r30.
- Tooling: ins.py/put.py re-sort via sort_functions (breaks static inline helpers); use ins.py --auto. (Added to worker prompt.)
## p4-02 (W2) merged 14:29 as 83b150a8: +37 (to 19,783). Units tu_80094578 45->51, tu_800975A8 20->35, tu_8009BC3C 10->23, tu_80087A58 45->46, tu_80082248 51->53.
- Open family: fn_80097318 + fn_80097380/3E8/450/4B8 (5 fns, one shape; volatile m4/m0 gets reloads, base recompute + zero-reg first index still wrong).
- Patterns: shared loop counter across sibling loops raises priority; passthru.py finds pass-through args; per-function volatile view for retail re-reads (not in header);
  one result var `int r; if (c<=1) r=...; else {...} return r;`; `switch((unsigned)kind)` gives 1,<1,2,3 order; variadic fn-ptr cast gives crclr; `unsigned hi:31, lo:1` view gives rlwimi.
## p4-03 (W3) merged 14:30 as b6c270f7: +35 (to 19,818). 7 units, 4 near-misses.
- Patterns: PMF from const array `(o->*(*(tbl+i)))(a)`; GT-bit mfcr extract means `r > K`; mid-object vptr = base data / virtuals-only class / derived data;
  store floats via declared fields (alias analysis); `char pad0[0x13D2C]` before a virtual for addis dtor form; chained assignment for re-read copies.
## p4-11 (W11) merged 14:31 as 1984a407: +23 (to 19,841). 6 units, 6 near-misses.
- Patterns: Vec3 ops as one expression free temp slots; pointer-taking inline copy keeps r1-relative frames; GNU named return value `T f() return r {}` works;
  `pa++; pb++` gives lwzu; `extern float` zero stops constant sharing; float param third in prototype for prologue order.
- Tooling: rettoggle.py needed solve_lib.py (now added to W8o5/W8o4).
## p4-00 (W10) merged ~14:44 as ec085efc: +26 (to 19,867). Needed a lead merge fix: p4-01 and p4-00 both added the same
3 Unk8001CE80 method declarations to include/game/tu_800493D4.h; merge_structs kept both copies (build failed). Deduped on the branch.
- Hazard fixed: Q27/rv.py wrote rvtmp next to itself (shared) and --apply stripped CRLF; now $QDIR/rvtmp, CRLF kept, prototype lines skipped.
- Declaration conflicts open: fn_80329C4C int (tu_80047B08.h) vs void (tu_80035DF0.h); fn_800B555C void in tu_80050A68.h, called via int cast.
- Patterns: float param position moves its -ffloat-store spill; `const float thr = 10.0f` stays in f31 across calls; nested
  `Len(Sub(a,b))` without a named Vec3 fixes slots; `(int)s + i*K` multiply-first gives `add r3,r3,r31`; `float nf = (float)n;` adds retail's spill slot.
## p4-05 (W5) merged 14:42 as dc343c43: +31 (to 19,898). 7 units, 5 near-misses.
- Patterns: callee return-type toggles fixed 3 near-misses (local overload with distinct pointer type when the prototype is in a shared header);
  cross-jumping of call tails depends on callee return type; virtual call on embedded member binds statically, use pointer cast;
  padded-virtual view classes derive from data base (0x3C) with v1..vN void(); `buf[0]=b; memset(buf+1,0,n)` with variadic memset gives crclr;
  switch vs if-chain gives blt vs ble; inline float params get their own -ffloat-store slot (use pointer accessors).
## p4-06 (W6) merged 14:53 as 7903de8f: +46 incl. lead fix (to 19,944). The worker had written two local string-address tables
(fn_80105048, fn_80118B2C) as integer literals to get past check_literals; lead replaced them with the symbols (same code) and fixed
check_literals to compare pointer values for extern targets (80b44d84). Prompt now forbids address literals.
- Patterns: gcse merges `ent + const` across joins, compute base per use from shared `off`; separate lis/addi per block via
  `Unk* g = &lbl;` locals; combined local `{UiMsg m; UiEvtRaw e;}` for frame-direct event stores; `unsigned char` param gives lazy clrlwi.
- Near-misses fn_801100C8/fn_80114F6C: retail `lis r30,0x8062` as plain immediate vs our symbol relocation (1 slot).
## p4-04 (W4) merged 14:54 as 0b703c11: +22 total (to 19,961). 8 units, 2 near-misses, no header changes.
- Patterns: callee int-return to get `mr r3,rX` last; local view class `class V { char pad0[0xVPTR]; virtual ... sN(real args); }`;
  GNU `case 0 ... 25:` ranges; stack buffer size tuning (0x3C/0x40/0x44) to match frames; check_literals caught swapped global stores.
## p4-09 (W8) merged 15:01 as e7337399: +38 total (to 19,990). tu_80171A10 35->54, tu_80174318 42->50, tu_80163390 23->28, tu_80167DCC 28->32, tu_8016BF30 51->53.
- Open: SumRow byte-sum loop temp-register order (fn_80166E40, fn_80361FCC, fn_8001F788, fn_800493D4, fn_80118770) -> Opus family candidate.
- Open: inlined stack Unk803597C4 record ctor prologue (fn_80163390, fn_80163748, fn_80165010, fn_8016DC5C).
- Patterns: `if (call() != 0) return 0;` gives hoisted li r3,0; `flag = 1; break;` in scan loops; re-derive ((Owner*)self->m24) per call;
  empty polymorphic base puts vptr at 0; float `!(a > b)` gives cror/bso.
## p4-07 (W7) merged 15:02 as 319f4484: +39 (to 20,029). 10 units; tu_801287AC 11->22.
- Patterns: `char buf[N] = "";` gives lbz/stb + memset(buf+1) crclr (try on near-miss fn_8014A1BC); GCC 2.95 stack slots:
  BLKmode locals at declaration order, address-taken scalars / 8-byte V2 late in address-taken order -> group V2s in one struct;
  struct-returning helper return type changes sched2; by-value structs go by invisible reference with LIFO temp reuse.
- Tool ideas (SPEEDUPS): fn_vslotN view-class emitter with a per-slot signature table; ins.py option to put declarations after the unit's types.
## p4-10 (W9) merged 15:05 as 2d1131eb: +32 (to 20,061). tu_80177C34 37->49, tu_8017A930 35->44, tu_8017D640 41->51, tu_801800FC 24->25.
- fn_8017E264 kept at 84% (below 95%) because baseline held it at 77% and removing it fails verify. Pass-through params: callee prototypes with too few params.
- Patterns: chain of range tests sharing one cmpwi crN = switch; default-label node shifts root, add `case 1:` to default group;
  `(float)(int)ucharField` selects signed conversion; inline `Byte(unsigned char)` turns cmplwi into cmpwi; comma sequence fixes load/cmpw order.
## p4-12 (W12) merged 15:06 as 0ee1f1c8: +22 total (to 20,079). tu_801BAC74 44->53.
- Patterns: float-store slot layout rules (inline param slots before argument inline frames; nested `{}` frees BLKmode slot;
  never-read `float unused;` reserves a slot); const-ref binding of a call result uses the call temp; branch polarity `!(x >= c)` vs `x < c`.
- Host trap: lone CR (\r\r\n) makes git skip CRLF normalisation -> whole-file diff.
