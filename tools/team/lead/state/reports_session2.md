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
## p4-18 (W5) merged: +4 (fn_802ACE20, fn_802C13AC, fn_802C1F7C, fn_802C7720). Goal/state-machine/animation units yield little.
- Open: interblock scheduling hoists li/lis out of if-arms where retail doesn't (fn_802C78B8: 64 diffs -> 6 with -fno-sched-interblock); find the source feature.
- Tip: `score_variants.py --flags "... -fno-<opt>"` isolates the responsible optimisation. r3 unchanged between two bl = previous result passed as arg 1.
- 2026-10-12 15:46: W6 popped the shared 'leftover work/p4-25' stash by mistake and re-stashed the same two fe files as stash@{0} 'On work/p4-19: On work/p4-25: leftover ...'; content intact, label changed. W6 also left an uncommitted near-miss fn_802C7C08 (156/158) in its worktree; W8 left a broken uncommitted header edit (include/game/tu_80317B88.h) in its worktree: stash both before reassigning.

## W7 p5-24 (19:17, 13 new; 12 commits ffeea250)
- tu_8037B3AC 36->37 (dtor); fn_8037BFCC 99.83% near-miss committed (case-13 cursor/len reg swap).
- tu_8037C764 38->44; fn_8037DB54 parked 79.7% (scratch parked_fn_8037DB54*.txt): fa/fb not copied to callee-saved in retail; dead 2nd beq.
- tu_8037E64C 35->36; fn_8038006C 94.6% (reg alloc only), fn_80382BD8 dropped; 8 others unattempted (10-arg float, CR flags).
- tu_80382BB8 37->39; fn_vslot17 unattempted.
- tu_80383E00 37 (none attempted: CR flags / 12-arg / large).
- tu_80387E28 26->29; fn_8038B630 static init 107/109 near-miss (struct copy addi/lwz order); fn_80388490 CR4 sharing.
- Patterns: new(heap) T[n] vec-init guard; goto-done pretest loop; volatile halfword stops store forwarding; CpQ inline copy for frame-direct struct copy; `*(float*)d=` first store keeps loads below; `{int h=f(); g=h;}` stops lis hoist; same call in both arms -> partial cross-jump; static_init_and_destruction_0 suffixed name only pairs as hand-written fn_XXXX(int,int).

## W1 p5-20 (19:27, 10 new; merged 41a3619b)
- ealib/tu_803E3C08 28->35; tu_803E0ACC 12->13 (fn_803E0ACC 190/193 fmr copies; fn_803E1850 f13 vs f0); tu_803E3280 6->7 (fn_803E3758 ~92% lis sharing); tu_803D2B20 23->24 (fn_803D33C4 225/225 ins, bone count r31 vs r3).
- FP reg-alloc wall: fn_803DE414, fn_803E00EC, fn_803DF4E4. Time base / mtspr skipped. fn_803D9528 has a literal data word after bl.
- Patterns: volatile store + plain load for key-switch tail (v-form switch); switch on a copy `k2=k` stops gcse hoisting compare into CR; GX vertex writes in own braces; char[5..7] locals BLKmode get slot at decl, char[4]/[8] at frame end; `unsigned w[8]` + `*(float*)&w[i]` for distinct slots; `p[0]; *++p; *++p; p[1]` -> lhzx then lhzu.
- Tool: rv.py "command line too long" at 512 variants; W1 wrote dirscore.py (scratch).
- W1 killed a stray python by PID possibly belonging to another worker -> added "kill only your own PIDs" to p5 template.

## W11 p5-16 (19:30, 11 new + 3 near-miss; merged a4bd033a)
- db/tu_805902E0 45->47 (fn_805913C0 96.8% near-miss: shared lis r29); db/tu_8059A728 47->49; db/tu_805942E0 40->44; db/tu_8058BF2C 27->28 (fn_8058C3C4 near-miss li r7 order); ealib/tu_803663B0 2->3, tu_8036AEE4 2->3 (shader setup clones of fn_80366D94, extern "C" + rename); tu_80599594 fn_80599D30 97.9% near-miss.
- Patterns: which nested loop gets bdnz = global-alloc priority of count pseudos; declare a function-scope counter shared by sibling loops to give CTR to outer loop (check with cc1plus -dL -dg -dl, "insert_bct ... failed"); base-first lfsx via inline At(b,o); `Tab8 t = lbl_X;` struct-typed extern for rodata table copy; PMF dispatch via variadic fnptr cast; `(char)m` at call for extsb; struct-return field read direct; bit getters `*(unsigned char*)&w & 1`; `x % m == 0` via unsigned short r.
- Tools in scratch Q5_16: rvb.py (batched rv), permg.py, opdiff.py.

## W12 p5-03 (19:31, 11 new; merged 6a41b302)
- game/tu_802B9218 49->50 (dtor via twin class); tu_802B5234 53->56; tu_8022BB90 42->43 (fn_8022D304 190/188, fn_8022C2B8 301/304 Vec3 slot layout); tu_802547C0 56->58; tu_8019F8C0 54->56; tu_801B23A8 49->50 (fn_801B3094 non-variadic def + CALL_ macro variadic cast for callers); tu_8023A6C8 52->53 (fn_8023CB50 multi-base ctor 8 vptrs); tu_80256C80 fn_802574DC goal-pointer CSE (mr r31,r25).
- Patterns: dead-compare switch trees from balance_case_nodes (ranges count 2), shared-body cases first in source; by-value struct arg via inline wrapper; float reloaded after each call = extern float, literal gets CSE'd to callee-saved FPR; `c ? -1 : 4` vs `c ? 4 : -1` li/beq order; `if (!(r >= u)) r = u;` vs `>?` (fmr).

## W4 p5-08 (19:32, 19 new; merged ec72c90d)
- fe/tu_80492680 24->37 (near-misses kept: fn_804969A8 99.9, fn_80494108 99.6, fn_80493F20 99.1, fn_80492BA8 97.6 sp8/spC swap, fn_804930F8 95.8); fe/tu_804987EC 37->39 (fn_8049A4DC 97.8); fe/tu_8049B0CC 35->39 (fn_8049C524 99.0; fn_8049DCE0 cr4 reuse dropped).
- Patterns: `int k = j;` copy for second slwi; SumB inline byte-sum loop (the SumRow family!) -> bdnz + addi inside loop; `i = 0;` right before loop in array-buffer ctors; typed FeW* member stores block scheduler; `(x==0)*4` own statement -> subic/subfe; rlwinm 30,31,31 after cmpwi = `> 1`; rotated loop via calls in while test; clamp `((A)?(B>=st):(st<=0)) ? st : H`; fresh cast per +0x98/+0xDC use; explicit inner switch after k==1||k==3 guard -> cr4 reuse.
- Scratch tools Q5_08: ins2.py, tidy.py, vgen.py (@{a~~~b}@ choice groups for rv.py), nm.py.

## W8 p5-23 (19:33, 12 new; merged 6905dee5)
- ealib/tu_803FFD9C 36 (fn_804004D0 cpu-info, fn_80400690/6FC peeled 2nd loop); tu_80400DA4 23->25 (fn_80401924 RefPack, fn_80402570 const vec init); tu_804027DC 26->29 (fn_80402EF8 r7/r8); gamelib/tu_80378D70 29->36 (fn_80379DA0 97.9 near-miss: hidden return-slot ptr loaded last, same as fn_8037B310).
- Patterns: lopsided switch compare chain -> add sibling function's case values as empty breaks; `v *= 16; v += c - K;` vs reassociation; result through local not early return; C copy fn `*self=*o; return self;`; volatile view stores to stop forwarding; Vec3 temp rules (init vs assign copies, const-ref param, placement new for *out=Add(), by-value inline params allocate temps, scoped Sub temps); brute-force 2^n sum-term orders; function-level float reused across rows gets f13.
- Tooling: rv.py segments at first col-0 `}` (indent inner blocks); units with relative ../../include break scratch compiles.
