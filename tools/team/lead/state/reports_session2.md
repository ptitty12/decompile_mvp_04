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

## W6 p5-26 (19:47, 8 new; merged c69e47c1)
- snd units: tu_803AC88C 32->34, tu_803AFDC0 35->36 (Snd::Hal::SetVol), tu_803B21AC 24->26, tu_803B7DA0 21->24; tu_803B4BEC fn_803B5B6C 99.29 near-miss kept.
- Walls: SNDAEMSI_timerupdate (no LR save, mflr r22 around blrl); fn_803AC494 cse-skip-blocks carries `installed == 0` past small if -> zero stores reuse reg; fn_803B2C0C cross-jump fails on fadd order; fn_803B58E8 andi.+mcrf.
- Patterns: static inline accessor in while condition -> loop-test copies; separate early `return total;` keeps beq to epilogue (merged return = 99.94%); `int* pq = &lbl` before float math keeps lis in loop; `!(t < 0.0f)` -> plain blt (vs cror); `if (ch==1) n=2; else n=ch;`; for-step reload `p = s->mC` at latch; `char* bp = buf + 0x600; f(bp - remaining)` stops hoist; `if (id != 0xFE) continue; break;` -> bne over b.
- rv.py fails over ~25 variants (command line) -> fix to pass directory.

## W2 p5-13 (19:47, 21 new + 4 near-miss; merged 3893550f)
- db/tu_8053967C 33->41; tu_8053E240 26->31; tu_80541F40 23->29; tu_8053CC9C 36->37; tu_80535360 47->48; near-misses kept fn_8053BEC8 98.7, fn_805419C8 97.2, fn_80543AB8 98.9, fn_80530F0C 99.3.
- Patterns: diff_unit MATCH != 100% (check report.json fuzzy); `struct TmpE : Tmp { ~TmpE() { vp = ...; } }` for per-return vptr reset; final `q->vp = ...` through q keeps q live; aggregate locals round to 8 -> enclosing struct for 4-aligned layout; `i != 10` bound removes shared cr7; nest call args to change load order; one slot `virtual int` stops cross-jump of two void vcalls; consumer callee takes the producer's result as first arg (protolint.py); g++ lays case bodies in source order; `rand` by real name; `{c1,c2}` flags saved in CR across calls automatically.

## W3 p5-21 (19:48, 13 new + 3 near-miss; merged c5bfb9f0)
- ealib/tu_803E6FB8 31->32 (fn_803E7A60 99.98 near-miss: sscanf addr-taken int slots); tu_803ED700 28->29 (fn_803EE238 void); tu_803EE8F8 29->31 (fn_803F009C lone `mr. r4,r4; blr`); tu_803F2000 19->23 (dtk unpaired lis in fn_803F2000, report 100); tu_803F73B0 31->36 (near-misses fn_803F7958 99.79, fn_803F7EE4 95.4).
- Original code (skip): psq_ paired-single kernels fn_803EA3EC, fn_803EA338 wrapper, fn_803EB000 in ealib/tu_803E9C20 / tu_803EAF50.
- Patterns: per-arm stores (not shared `next`) get tail-merged after RA -> `li rX,K; b join`; RcLink inline for linked-list temp args; `const void* volatile sv = obj.vp; obj = *src; obj.vp = sv;` singleton copy (int members, explicit vp field, extern const void* sym[3] to avoid sdata); placement-new wrapper for ctors with member arrays; va_start inside the if; `extern T* _impure_ptr __attribute__((section(".sdata")))` -> @sda21; `sum += *p++` shared signed char* p; card.h Set* macros copied locally (`| 0` for rlwinm); `i = 0; if (i < lvl) do {...; i++;} while (i < lvl);` for addi/cmpw/blt loop with pre-test.

## W5 p5-11 (20:02, 30 new + 6 near-miss; merged f40e7087)
- fe/tu_804E5180 30->35; tu_804E750C 47->52; tu_804EA2E4 42->48 (fn_804EB2C8 mftb); tu_804ECDE0 27->28; tu_804F81E0 35->43; tu_805002DC 39->41; tu_80505484 41->42; tu_80508C98 41->43. Near-misses: fn_804E7E80 99.8, fn_804ECA60 99.7, fn_804F9D10 99.3, fn_805080B8 96.6, fn_8050C724 99.4 (mr r11,r3 like fn_8044C508), fn_8050AE0C 97.9.
- Patterns: compose call chains `fn_800C80xx(obj->v32(s,1))`; named temp for call-result receiver -> `mr r11,r3`; struct-returning virtuals `FeT16 s14();` + `o->v35(p->s14())`; selector compared in run of ifs -> else-if chain (jump2 cross-jump); explicitly peeled first iteration + `for (k=1;...)`; `int c1 = !(mode ^ 1)` cr-free booleans; `int d = j - 1;` separate local avoids extra giv; top-bit flag as `unsigned top:1` bitfield; bitfield stores before vptr via class layout; gotos for block order; never overload a header extern "C" function.

## W9 p5-17 (20:04, 19 new; merged d5a0bd18)
- ealib shader/display-list units 8036BECC, 8036CC08, 8036D8AC, 8036E65C, 80371D9C, 803728E8, 80372F60 all 2/4 -> 4/4 (static-init wrappers renamed via rename.py); 8038F73C 26->28 (IDCT butterflies parked); 8038BC58 47->50 (near-misses fn_8038C99C 99.99 GXColor slots, fn_8038E080 99.46).
- KEY PATTERN: a local object of a class with an empty inline destructor (`struct S { int a,b; ~S() {} } s;`) reserves an unreferenced stack slot -> explains "spare frame bytes" (fn_8038BCD0 matched with VdSpare8). Retry ealib functions with unexplained frame growth.
- Others: junk `mr r10,r11` copies on float-arg calls are compiler artifacts; int->float temp is one reused 8-byte slot; pass-through 3rd arg via cast fnptr.
- INCIDENT: ran `taskkill //F //IM python.exe` ~20:04 -> killed every worker's python jobs (they re-run). p5 template already forbids kill-by-name (added 19:28; W9 launched before).

## W7s3 p5-09 (20:06, 36 new; merged c4c51622)
- fe/tu_8049E0BC 38->54 (fn_804A217C 99.1 near-miss r20/r21); tu_804A2AB4 42->51; tu_804AA58C 28->29; tu_804ABCBC 33->35 (header: fn_804ACD0C returns void*); tu_804AECD0 36->39; tu_804B13FC 33->35 (fn_804B34B8 99.1 sret addi order); tu_804B985C 25->28 (unit complete).
- Patterns: bitfield clear via inline param -> rlwimi from shared zero (literal 0 -> rlwinm); read back just-stored field for li-before-stw order; rodata int a[16] tables via pointer copies -> separate callee-saved regs; inline `int r=0; if (v) r=1; return r;` flag arg polarity; pointer var introduced after init calls (fresh addi r3,r1,8); polymorphic class synthesized copy-assign saves/restores dest vptr (stub class with declared-only virtuals + inline dtor); guarded do-while `if (j<n) { int o=0; do {...} while (j<n); }` avoids strength reduction.
- check_literals reads linked main.elf: run after full ninja.

## W4 p5-04 (20:07, 4 new + 2 near-miss; merged dca4bf2d; stopped after 33 min)
- game/tu_80352E64 44->45 (complete); tu_803401A8 25->27; tu_8035BF0C 21->22 (fn_8035C24C 99.92 vptr store order); tu_80338ECC near-miss fn_80339F60 97 (`lwz r0; mr r4,r0`).
- Walls: g++ virtual-base dtor machinery (fn_8035C4BC..fn_8035D274); by-value temp-struct chains (fn_8035867C).
- Patterns: member arrays of virtual-dtor elements + per-vtable store classes w/ inline dtors + explicit `->~T()` calls reproduce open-coded array destruction; one-field class `{ int m0; const void* m4; ~W() { m4 = lbl; } }`; empty `~Base() {}` stops out-of-line base dtor call; float offsets as separate locals declared inside the if; constants as `extern float lbl_X` each get own lis; inline Height(o, V3 v) for temp chain; float local from pool float spills under -ffloat-store (use extern const float directly); run rename.py after a build that includes the function.

## W10 p5-14 (20:08, 20 new + several near-miss; merged d01e2ecf)
- db/tu_805467E0 37->39; tu_805495DC 33->36; tu_8054FA04 38->40 (fn_80551A80 99.8); tu_80554628 (fn_805559D4 96.1); tu_8055A3B0 30->31 (fn_8055D124 95.9); tu_8055F730 13->18 (fn_80562E34 96.3, fn_80560314 98.7); tu_80563954 (fn_80564910 99.4); tu_80565FD4 19->24 (fn_80566F40 97.8, fn_8056746C 97.1, fn_8056792C 96.7); tu_8056BAEC 34->35; tu_8056EC68 34->35.
- Patterns: host-object vcalls at +0xDBC via `struct H : D { virtual... }` with `D { char pad[0xDBC]; }`, slot n at +8+8n; declare all locals up front then call (straight-line vcalls); extern "C" empty prototype passes no arg (stale r3 -> declare exact mangled name with `()`); 2-byte struct by value via hidden ref, write through second pointer to stop halfword merge; shared `unsigned i` for backward scan + forward loop; `!(f >= 0.5f)` -> cror un,eq,gt; bso; `Step(int&)` clamp-and-increment.

## W7 p5-02 (20:10, 14 new; merged 6671eaec)
- game/tu_800C2F90 59->60 (complete); tu_800C5158 55->57; tu_800CB3A8 56->57; tu_800CF178 54->56; tu_80107F74 57->59; tu_8014013C 35->39; tu_80147748 55->56 (fn_8014849C mftb); tu_801547AC 57->58 (fn_80154EF4 97.7 near-miss 24-byte copy); tu_800BCD38 fn_800BCD38 86.8 dropped.
- Patterns: -ffloat-store float param spilled at its position in C param list; `n.m4 = 0; cnt = 0;` separate zero regs; float clamp polarity table (`!(f <= K)` -> cror un,eq,lt; `!(cur < hi)` -> blt; `f > K` -> ble); by-value Vec3 inline param gives extra stack copy; `(q = &pl->m58C, (q->m4 & M) || fn(q))`; unsigned int->float via `(float)*(unsigned*)&x`; diff_unit needs mangled substring for methods; ins.py --auto anchors only on free fns (use --before Class::method).

## W8 p5-25 (20:19, 4 new; merged 7bf03b56)
- animation/goals/tu_8027FD64 10->13 (header: goal pad fields named); tu_8029B70C 12->13 (fn_8029D2E0 99.2 near-miss; fn_8029CB34 94.7 dropped: `mr r0,r3` before cmpwi on call result unresolved); tu_80287600 fn_802893DC 267/267 regs only.
- Patterns: Abs(float) inline param slot for fabs store/reload; extern const data vector loads schedule above stores; duplicate arms instead of ternaries (no -ffloat-store spill); atan2f `extern "C"`; macro OR chain for hash-probe; uninitialised multi-assigned `int r` + goto label in the arm for shared `return 2`.

## W11 p5-01 (20:20, 5 new + 3 near-miss; merged 433e15db after rewording 3 wip( commits to match()
- game/tu_8007FF8C 56->57 (fn_80081D88 99.8); tu_800AB0E8 57->58; tu_8006902C 28->29 (fn_8006BA84 98.0); tu_80050A68 25->26 (fn_80050BCC SumRow-like reload ~85); tu_800A9858 fn_800AABA4 98.2; tu_80070DDC 55->56.
- Patterns: owner dtor with `delete p` per owned class with declared dtor -> `_._11Cls(p,3)`; explicit `self->t.~T()` in reverse -> (p,2) calls; CR0 compare live across calls from plain source; separate lbz via inline accessors; `!(E > hi) ? (E >? lo) : hi` clamp w/o spill; inline returning float for per-arm ternary sharing one stfs; loop bound read in condition (`i < o->m100`) avoids bdnz.

## W12 p5-12 (20:22, 11 new + 4 near-miss; merged 674a01ed; 2 wip( commits went to main unreworded - 31 older ones exist too)
- fe/tu_805283C4 55->56; tu_8051E878 49->50; tu_8050C9DC 33->38 (near-misses fn_8050DA2C 99.2, fn_8050E7B0 ~99 vptr-first store family; fn_8050DD7C 95.9); tu_80516990 fn_80516B6C 98.2; tu_80520BE0 35->37; tu_80529364 69->71 (complete).
- Patterns: `return (float)p[N] * k;` per case for cross-jumped conversion tail; typed-field cast for vptr-load-before-addi sub-object call; `(a() + 1) % b()` one expression; inner calls as separate locals to stop global-load CSE; repeat `(char*)self + K` inline for rematerialised dtor array start; stores via typed view on char* sub-pointer; stack-struct init through pointers `FeP4* r1 = &p1;`; int-returning ctor prototypes; `f(x) == 0` -> subfic/adde.

## W1 p5-00 (20:23, 7 new + 3 near-miss; merged 4185dc6e)
- game/tu_80008540 19->20 (`_._11Unk800085B0` via explicit inline `virtual ~X() {}` in the class: implicit derived dtors go to .gnu.linkonce.t and never pair -> SWEEP candidate); tu_8001D7F8 fn_8001DEC0 99.95; tu_8001E444 24->25 (fn_8001F030 96.1 gcse slwi sharing; array ctor loop calls plain fn_80344538(Unk*) not a ctor -> hand-written do-while); tu_80026A48 26->28; tu_8003AEE4 fn_8003C388 99.54 (float->unsigned cror vs blt); tu_800437AC 24->26; tu_80044C10 26->27 (`r = r | (flag | 2)` form decides RA); tu_80046964 fn_8004763C mftb.
- report.json is the authority; objdiff-cli diff/diff_unit can score literal-pool functions lower.

## W2 p5-05 (20:24, 5 new + 4 near-miss; merged d2f8df99)
- game/tu_8035ECE4 51->53 (complete; copy ctors as extern "C" plain functions); tu_80362FB4 41->42 (4 wrap functions 98.3: (float)(int) temp regs, local-alloc order - one fix fixes all four); tu_80362A30 `_._11Unk80362C2C` implicit-dtor (stores vptr when user-declared); fe/tu_804439E4 28->30.
- Patterns: vcall target before branches via inline with control flow as the argument; `inline float Zero()` keeps pool load late; `FeTimer* t = 0;` before calls shares zero reg; `int dd = day;` loop var flips param priority; last loop on a copy `int j = idx;` keeps retail's redundant cmpwi/ble (99.97 -> 100).

## W3 p5-07 (20:25, 9 new + 2 near-miss; merged 3bff1b78)
- fe/tu_8048E6A0 27->33; tu_80477068 43->45 (fn_80479690 96.4); tu_80488CDC fn_8048A43C 96.2.
- Patterns: ctor in plain ascending offset order (compiler emits later-in-source first per kind); `int a[2][25]` nested zero loop; typed struct pointer keeps unfolded addi; volatile reads into locals in retail order; `&m` vs `FeMsg* mp = &m` alias stops cross-jump of identical tails; long vslot73/fn_800C80xx runs straight from m2c are the cheapest wins.
- 20:27 usage 77% (5h), 73% weekly: W1/W2/W3 slots held empty; restart cron 22:56.

## W6 p5-10 (20:3x, 8 new + 2 near-miss)
- fe/tu_804BB110 fn_804BB8B4 98.5; tu_804C713C 33->34; tu_804D6180 37->39; tu_804DA10C 40->41 (fn_804DA74C 98.0); tu_804E1A6C 41->45 (fn_804E2E00 shared lis + `cmpwi 4; blt` same as fn_804E2D1C).
- Patterns: fnptr cast for true return type; r3 pass-through as first arg (`fn_800E5C74__Fiii(l->s3(), a, b)`); void vs int slot stops cross-jump of identical vcall tails; float slots by function-scope declaration order; `int (*cmp)(float,float) = fn;`; `*(int*)(o + (int)t->m0) = v` -> stwx offset-first; UiMsgMgr via local inline `lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0))`.

## W7 p6-03 (20:35, 1 new + 1 near-miss) - cut-p4 game units are Vec-heavy, low yield
- game/tu_8020ADC4 19->20 (fn_8020E9CC 96.7 Vec copy store order); tu_802028E4 record-push family (fn_80203C24 + 5 siblings) needs args kept in r3..r8 not callee-saved.
- Patterns: fully nested `*v = Add(base, Mul(Norm(d), K))` allocates inline return temps outermost first; Norm from Len/Scale inlines with `float s = N/len` local; Vec d by const ref keeps &d callee-saved across sqrt; LenSqXZ accessor in compare shares x*x/z*z; literal 0.0f (same value) keeps one pooled FPR across a call while extern const float reloads.

## W9 p5-27 (20:39, 36 new + 3 near-miss; merged 2adda5b1)
- dolphin/dvd/tu_804227D4 17->53 (dvd.c state machine, callbacks, dvdfs, async starters). fn_804227D4 (dvdfs.c) defined at END of the merged unit so it is not inlined into later callers -> owner question (proper fix = split at 0x80422FD8, which verify would count as a regression for moved matched functions). Do NOT sort_functions this file.
- ax fn_80419F7C VPB init loops unroll 64 vs retail 8 (dropped); gx fn_8042D9F8 psq (original asm); os/tu_804330D0 17/20 original-code.
- Patterns: one struct overlay over adjacent .bss objects (`DvdBss* b = &lbl_X;`); unused `u32 pad[2];` for +8 frame (MWCC); volatile for store-then-load order; `u32` extern for cmplwi; explicit `command - 4 <= 1`; inlined BOOL function for li/li/cmpwi; address marker comment keeps static helper above user; MWCC evaluates retail-second operand first in `tolower(*a++) != tolower(*b++)`; OSPanic as fn_80433CE8; switch case order from the jump table.

## W10 p6-02 (20:40, 4 new + 2 near-miss)
- game/tu_801E6D88 41->44 (fn_801E8EF4 99.9); tu_801EA36C 16->17; tu_801EE438 fn_801EE438 99.7; tu_801F263C triage only (switch + shared tail + Vec3 temps).
- Patterns: `inline float G() { return lbl_X; }` keeps global in f31 across call; volatile counted-loop shape; explicit per-arm `if (fn(k, K) == 1) r = 1;` for shared call tail; `*out = cond ? a : b` in both arms; forward-declared structs reproduce mangled callee names.

## W5 p5-06 (20:41, 7 new + 1 near-miss)
- fe/tu_80459228 29->30; tu_8045B134 26->27; tu_804654A0 28->29; tu_8046C6F8 fn_8046F510 98.65; tu_8046F770 39->40 (fn_80471390 296/296 but frame +8); tu_804740A8 41->44.
- Patterns: per-call return-type casts (char* vs void) for the same callee; int flag tested twice -> second test on a copy `int d = c;` (avoids CR4 save); `a >? b` for fcmpu/cror max; ternary for if/else float before spill; `float fv[4]` for out-param spill slot; pointer locals for stack buffers keep them callee-saved; FeW* t local inside each cross-jumped case block; bit-test `(*(int*)(b+off) >> (i - (q<<5))) & 1`.

## W4 p6-01 (20:42, 1 new) - low yield (batch had 10 small fns, mostly Vec/float stack temps)
- game/tu_801DC918 51->52 (fn_801DCC1C). Goal-factory family (fn_801E5644, fn_801E5928, fn_801E57A8, fn_801E52B8, near-misses fn_801E5A8C/5D7C): retail keeps `mr r28,r27` copy of g; cse-skip-blocks propagates it away - needs a construct whose skipped block is too big or has two predecessors.
- Patterns: give the result pseudo MORE sets (separate case bodies) to raise global-alloc priority (diagnose with cc1plus -dg -dl "regs to allocate"); switch shapes with dummy case 2 into default, range [2..5] root, backward goto into a shared block.
- Tool: Q12/hc12.py hard-codes src/fe/.

## W7s3 p6-00 (20:4x, 4 new + 1 near-miss)
- game/tu_801C16B0 57->58; tu_801C2C64 36->37 (fn_801C3B04 144/144 callee-saved rotation, best in scratch Q6_00); tu_801CF054 38->40 (fn_801D04C0 99.2; fn_801CF430 goal-pointer copy `mr r30,r28` same family as W4's goal-factory copy problem).
- Patterns: literal float stays in f31 across call; inline FZero()/FOne() to keep lfs below int stores; `int b = f() != 0;` vs `int b = 1; if (!f()) b = 0;`; mfcr extrwi bit 28 = LT; dead float locals still stored under -ffloat-store (keep them); register dump `ngccc -dg -save-temps` -> t.i.greg (regs to allocate, dispositions).

## W8 p6-04 (20:5x, 2 new)
- game/tu_8021ADDC 14->16 (fn_8021BA44, fn_8021BFFC); fn_8021DDEC q/e/cur register allocation; tu_80216CF4 fn_80218AF8 82.9 (spilled float param reload hoisted in retail).
- Patterns: header `extern const Vec3f` loads hoist above int stores -> compare/copy through a non-const view `Vec3f* kp = (Vec3f*)&lbl_X`; `const Vec3f* cp = &cur->m60;` declared right before the stores; brute-force all 720 orders of 6 consecutive constant stores (hill-climb stalls); NeFlag inline keeps li after the call; mangled callees declared outside extern "C" block; discarded struct return as a plain statement.

## W12 p6-06 (21:0x, 8 new + 2 near-miss)
- game/tu_802362A8 25->30 (fn_80237E9C 98.4); tu_8023DB8C 23->25 (fn_80241A94 constant-true `li r0,1; cmpwi; beq` folds away); tu_80241C24 26->27; tu_80233F08 fn_80234B18 98.4.
- Patterns: vptr at +0x98 view class; stack event object via inline Base/Derived/Set/Dtor with `Msg* mp=&m`; nest the rest under `if (!(x <= K)) {...} return 0;` for cror/bso; `Vec v = Pos(p)` by-value inline gives z,y,x copy order; byte-offset accumulation in a local for table index; ArmB inline called in each arm for cross-jumped tail; clamp `if (n0<=5){n=n0; if(n<=0)n=1;} else n=5;` -> mr.; dead local float array stores are kept.

## W11 p6-05 (21:0x, 4 new + 3 near-miss)
- game/tu_8022FE34 31->34; tu_80227564 14->15; tu_8022309C fn_80226BC0 98.1; tu_8021F080 fn_80220BFC 98.4, fn_80222D70 97.9. Unsolved recurring: `slwi r0` vs `r11` index temp in `in->m8[id]` loops; `cmpwi` before `li r3,4` in `cond ? k : 4`.
- Patterns: dead float local `float f = lbl_X; call(lbl_X)` reproduces never-reloaded -ffloat-store spill (`fmr f1,f0; stfs f0,N(r1)`); sub-record reset in inline + literal 0.0f keeps lfs below int stores, source order = retail order rotated left by one; class by value = hidden ref + callee copy; gotos in retail block order for flag chains.

## W1 p6-35 (21:34, 7 new + 1 near-miss)
- ealib/tu_803912F8 26->30 (varargs packer via prodg/stdarg.h); tu_80394744 16->18 (McPair halves unsigned short; fn_803950B4 96.9); tu_803927E4 43->44.
- Patterns: give a stale-r3/r4 callee its params and pass the caller's value (fixed 2 near-misses); hold base as `int` to flip lbzx/add operand order; inline taking int* for addi+mr; `fn(i); ret = i;` keeps index live across call; scratch include tree under scratchpad/include for rv.py on relative-include units (shared).

## W2 p6-40 (21:38, 9 new + 11 near-miss)
- ealib/tu_803F9350 26->32 (fn_803FADD0 99.1, fn_803FA100 98.0); tu_803FAE94 23->24 (fn_803FBB48 98.6, fn_803FBC94 97.6); tu_803EBF90 39->40 (fn_803EC568 switch in loop with CR fields + 16-byte local); tu_803FBF54 40 (5 near-misses 96-99.9).
- Patterns: objdiff fuzzy gives 96-99% for register-only permutations (most land above the keep line); `*(volatile int*)&j->m8` read in callback args for r4-before-r5 load order; store first then local (`j->m4 = 1; state = 1;`) for separate constants; shared loop counter keeps second loop out of bdnz (`addic.; bne`); typed struct do-while with `--i != 0`; 16-byte struct for a one-byte address-taken local frame hole; `extern T* lbl[3]` (>8 bytes) to avoid small-data addressing; byte-assembled 24-bit sizes with brute-forced store order.

## W3 p6-09 (21:39, 10 new + 3 near-miss)
- game/tu_8026C414 47->51; tu_80275F24 16->18 (header Unk80276DB8_Row fields); tu_802ACD88 48->51 (fn_802AD2B8 97.0); tu_802B0ACC 26->27 (fn_802B2EF0 99.8 branch target); tu_802BF974 near-misses fn_802C37F8 99.8, fn_802C0050 97.5.
- Patterns: inline Reset() at two offsets, member stores in reverse of emitted order; `Tab t1 = lbl_X; Tab t4 = {};` block copy + memset; classifier leaves as `int r = 3; if (!(u <= K)) r = 4; return r;`; unused float local reserves a slot; count-down `for (i = 1; i != 0; i--)` with `m38[1-i]`; `const float k` spilled once (no extra copy); signed cursor compare needs int not pointer; `int* q = &v->m18700; *q = f(...)` computes address first.

## W4 p6-19 (21:5x, 9 new + 4 near-miss)
- game/tu_80087A58 46->49 (fn_80088024 98.3, fn_800888F4 99.8); tu_8009BC3C 23->27 (fn_8009CF6C 96.9, fn_8009DA60 95.3); tu_800975A8 35->37; tu_80094578 fn_80097318 family (4 siblings): ~200 loop variants, retail's peeled first iteration is not constant-folded (lbzx with zero reg) - unsolved.
- Patterns: stack ByteVec stores via `q = &v`; `*(int*)&sp` plain read of a volatile counter as call arg; 8-byte Pair struct copied whole lives in a register pair; extern "C" under the mangled name of a same-unit C++ function -> ICE 378 (use fnptr cast); `if (i != 9 || f != 0) k = call(); else k = 0xFF;` keeps call arm first; `int a; if (c) a = X; else a = 0;` vs `int a = 0; if (c) a = X;` before a call.

## W2 p6-12 (22:2x, 8 new + 1 near-miss)
- game/tu_80300848 30->36 (fn_80301E44 99.69 struct copy word order); tu_80304858 37->39; tu_802FCAC0 46 (V2 copy temps).
- Patterns: clamp `v = v > p->hi ? p->hi : (v >? p->lo);`; nested min/max via `!(x >= lim)` / `!(x <= a+k)`; first declared local gets lower slot; array ctor loop `do { new (e) Cls(); e++; } while (i-- != 0);`; group independent init stores ascending before hill-climb; struct copy inside an inline from const-ref -> direct stack word copies; 0x4330 magic -> unsigned source; pool floats readable from build/GV4E69/asm/*rodata*.s.

## W1 p6-36 (22:3x, 2 new + 2 near-miss)
- ealib/tu_8039B3E4 18->19 (Huffman table builder; fn_8039FC88 xor temp r0 vs r9 wall like fn_8039FB00/FBB0); tu_803A0310 14->15 (fn_803A2A44 99.1, fn_803A2244 96.5; 12 paired-single functions skipped as original code).
- Patterns: bitfield write of top bits into uninitialised word -> clrlwi on garbage; strength-reduced loops with no running locals; `if (!ok) return ok;` -> mr r3,r14; Rd(c, K, idx) inline for addi+lbzx base-first; `&c->m150` inline at each call for duplicate pseudos.
- Tool: rmfn.py without QDIR writes into shared Q12 folder (fixing); ins.py --proto can land inside a function body.

## 22:30 lead notes
- Enablers session (owner-approved tool downloads, relayed 22:10) put tools/match/permute.py (decomp-permuter wrapper, C units) on main at e2f3bda2; --from-cpp extraction in progress. New near-miss batch type: queue/nm_00.txt (12 dolphin units, 38 fns at 90-99.99%), template worker_prompt_nm.md, prep.sh W<n> nm 00.
- rmfn.py now parks into $QDIR or a temp dir (never the shared tools folder).
- All slots idle 22:30; main 20,740. Restart cron 22:56.
- 22:35 permute.py handles C++ (7dce9440; ~85% of near-misses set up, refuses ctors/methods/named-return). gen_nm.py wrote nm_01..nm_39 (580 fns >= 95%, closest-first in queue/nm_order.txt). Machine: 28 logical CPUs, 64 GB -> plan 7 nm workers (one permuter at -j 3 each) + 6 p6 workers at the 22:56 restart.

## W4 nm-03 (00:01, 10 new: all 8 near-misses in its units -> 100% plus 2 bonus; merged 1150c561)
- fe units tu_8047BB8C, tu_804A2AB4, tu_804654A0, tu_8049B0CC, tu_80459228 (+2), tu_804987EC, tu_804740A8 (+2), tu_8046C6F8.
- Permuter: no help (candidates cheat: drop calls, move returns; refused fn_8049C524 parse). Suggest penalising lost `bl`/shorter code.
- What worked: cc1plus -dg -dl lreg priorities (floor_log2(refs)*refs/life; duplicate `return r;` raises a pseudo); -fno-gcse A/B to find the rewriting pass; per-arm expressions change local-alloc creation order; per-arm stores instead of select-then-store; score_variants specs (~0.2 s/variant).

## W6 nm-05 (00:1x, 7 new + 2 near-miss raises)
- db units: fn_8052BD58, fn_8052DEE8, fn_8052DFDC, fn_8053352C, fn_8053384C, fn_8053217C (bonus), fn_8054EED4 -> 100; fn_80534C7C 98.4->99.8, fn_8053DB30 95.9->99.1.
- Permuter: only truncation candidates (score rewards deleted code, not alignment-aware); slow under load; refuses <?/>? and methods; orphaned --splice helpers need tree kill.
- Patterns: `unsigned j = i;` copy for indexed copy loop giv base; peeled first search iteration reads via `i = r` not literal 0; MIN/MAX `<?`/`>?` expand operand 1 first; struct-return outputs read as whole word then truncated; bitfield view for byte-aligned shifts (lwz+rlwinm, not lbz/lhz); float-returning callee via local extern "C" mangled decl. Unsolved: by-value Date frame stores (addressof CSE merges; fn_80530F0C, fn_805997C4).

## 00:10 owner shutdown ("make a writeup ... and spin down")
- All 12 running workers stopped (TaskStop); uncommitted leftovers stashed as "leftover <branch> (stopped 00:10 for owner shutdown)" in W5, W8, W9, W10, W11, W12. Orphaned permuter runs (W2, W3, W4 worktrees) killed by PID; the farm (idle priority, no tokens) left running.
- Session crons deleted; scheduled task mvp-decomp-lead-resume DISABLED (re-enable to resume the 2:25 auto-restart). busy_units.txt emptied (no running slots), so the farm may now take any unit.
- Committed branches integrated: nm-00, 01, 02, 04, 06, p6-14, 10, 26, 28, 07, 13 (see PROGRESS).
