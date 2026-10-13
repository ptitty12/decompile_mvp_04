# Lead handoff: GV4E69 matching decomp orchestration (written 2026-10-12 ~10:30 CDT)

You are taking over as **lead/coordinator** (Opus) of the MVP Baseball 2005 GameCube matching decomp.
Read `CLAUDE.md` first (hard rules), then this file. Owner standing orders (verbatim):

- "yes i approve all things good job, don't come back to me with action items unless you physically need my help, i trust you for all other things"
- "i never need to code review anything, you can push straight, there should be no human in the loop"
- "it is unacceptable to ask me to run power shell commands, you run them ... continue until you physically cant or run out of tokens"
- On running out of tokens: resume at the next 2am usage reset.

The lead holds full decision authority (DECISIONS 2026-10-10). Never give the owner commands. Owner-only items
(anything under `tools/verify/**`, `.github/workflows/**`, `.claude/**`) are recorded once in
DECISIONS "Open questions for owner"; then keep working.

## Session 2 status (lead, updated 2026-10-12 20:15 CDT; this block overrides sections 1, 4 and 7 below)

- main: **20,582 / 24,158 functions** (85.2%) at 6671eaec. Measure as in section 1.
- Slots and agents: `tools/team/lead/state/assignments.txt` and `state/agents_session2.txt` (agent ids; the last block is the live fleet). Worker reports: `state/reports_session2.md`.
- Assigning a slot: `LEAD_SCRATCH=<lead scratchpad, Windows path> END=HH:MM bash tools/team/lead/prep.sh W<n> p6 <NN>`. That runs assign.sh and writes the filled prompt to `$LEAD_SCRATCH/prompt_W<n>.md`. Then launch a Sonnet Agent that reads that prompt file. `END` sets the wall-clock deadline (default now + 150 min).
- Templates: `worker_prompt_p4.md`, `worker_prompt_p5.md`, `worker_prompt_p6.md`.
- Queue: p4 and p5 are fully assigned (all p5 batches worked once). **p6** is the sweep: every 0% function up to 0x800 in units that are not busy. Units of the p4 batches cut short at 16:00 come first. Batches are `queue/p6_NN.txt` in the order of `queue/p6_order.txt`. p6-00..03 are assigned. Regenerate with `gen_p6.py <report.json> --write` once the current p5/p6 units are free; it skips busy units and unassigned p5 batches.
- Pacing: workers run 50-90 min before their context fills (600-900k tokens), so short deadlines (`END`) waste little. The full fleet burns about 27-35% of a 5 h window per hour; the weekly limit (71% at 20:12) is the binding constraint. When the limit hits, every agent stops; resume with SendMessage to its agentId, or stash leftovers and prep.sh fresh.
- Section 7 status:
  - item 3 (EXI split) is done;
  - item 4 was replaced by a flags change (cflags_ealib_sda_nsr);
  - items 6 and 7 were no-ops;
  - item 9 is done (228 branches deleted);
  - item 5 (Opus round 7): the slot `-match` is on work/opus-families-7 and held. Families 5, 7 and 9 remain.
- Open: the OSTime pair needs a nopeephole split (dolphin/os). Never run two integ jobs at once: they share the orch worktree and break each other's verify.
- Known fragile point: two branches adding the same declaration to a shared header merge cleanly into a duplicate, and the build gate catches it. Fix it on the branch (git merge origin/main, dedupe), then re-integrate.
- Worker incidents: one worker ran `taskkill /IM python.exe` (killed every worker's jobs). The p5/p6 templates forbid killing processes by name or pattern.

---

## 1. Current state

| | |
|---|---|
| origin/main measured at | `b0964f4fdd6d423effdcbde2b5083a23cd34da2b` (2026-10-12 10:09 CDT) |
| Matched functions | **19,329 / 24,158 = 80.01 %** |
| Matched code bytes | 2,348,592 / 5,896,176 = 39.83 % |
| main now | `ab2ec845` (10:23). It only adds the p4-31 merge (`a45298cc`, +3 match commits) and a progress card. UNVERIFIED: count at ab2ec845 is about 19,33x. |

Per directory (matched/total functions) at b0964f4f: game 11650/14246, fe 2774/3408, db 1372/1779,
ealib 1211/1643, animation 961/1057, dolphin 505/792, snd 338/480, gamelib 334/402, libsn 28/134,
libc 92/93, sdk 0/47, libm 33/33, ealibs 20/22, libgcc 11/13, AUTO 0/9.

**How it is measured** (Git Bash, in the integration worktree):
```
cd "/c/Users/Patrick Taylor/decompile_mvp_04-orch"
git fetch -q origin && git checkout -q -f integrate/auto && git reset -q --hard origin/main
export PATH="/c/Users/Patrick Taylor/AppData/Local/Microsoft/WinGet/Links:$PATH"
python configure.py && ninja
python -c "import json;m=json.load(open('build/GV4E69/report.json'))['measures'];print(m['matched_functions'],m['total_functions'],m['matched_functions_percent'])"
```
Per-unit numbers come from `report.json["units"][i]["measures"]` (unit name `main/<dir>/<tu>`).
Daily history: `docs/progress/history.csv` (10-10: 120, 10-11: 16,053, 10-12: 19,329).

## 2. Repo and environment layout

All paths are under `C:\Users\Patrick Taylor\` (Git Bash: `/c/Users/Patrick Taylor/`). Remote: private GitHub
`ptitty12/decompile_mvp_04` (`gh` is logged in). Host is native Windows; the Bash tool is Git Bash.

| Path | Branch / HEAD | Purpose | State |
|---|---|---|---|
| `decompile_mvp_04` | main @ 99fcb230 (STALE) | Owner's checkout. Holds this HANDOFF.md and `tools/team/lead/` (both uncommitted). | Don't build or merge here. |
| `decompile_mvp_04-orch` | integrate/auto | **Integration worktree**: all merges, lead commits and measurements. | Active, lead only |
| `decompile_mvp_04-W1`..`W12`, `-W7s3` | work/<batch> | Worker worktrees (13 slots) | See section 4 |
| `decompile_mvp_04-audit` | detached @ a45298cc | UNVERIFIED: left over from an earlier verify/audit run. | Cleanup candidate |
| `decompile_mvp_04-match` | lead/prep5 @ 94b2cb6c | Old lead prep branch | Cleanup candidate |
| `decompile_mvp_04-port` | port/mvp2005 @ f779630b | Source of the CC0 libc port. Mostly consumed. | Keep (reference) |
| `decompile_mvp_04/build/_progress/wt` | detached | Progress bot's private worktree | Bot-owned; don't touch |

Every worktree needs `orig/GV4E69/` (the disc's files; gitignored). Existing worktrees already have it.

**Progress bot.** `tools/progress_bot.py` runs as a Windows scheduled task (installed with `--install`; a recent
commit says it polls every 2 min). It builds origin/main, redraws `docs/progress/`, verifies, and pushes
"docs: update progress card" to main. **main therefore moves on its own.** integrate.py rebases over these
commits. Log: `build/_progress/bot.log`.

### Lead scripts (were in the session scratchpad; copied to `tools/team/lead/`, uncommitted)
The old scratchpad is
`C:\Users\PATRIC~1\AppData\Local\Temp\claude\C--Users-Patrick-Taylor-decompile-mvp-04\ddf206fc-...\scratchpad\`.
It is session temp and will not survive cleanup or a reboot. The running workers' prompts still point there
(units files, `Q4_NN` scratch dirs, helper tools). Everything critical is copied:

| Repo copy | What |
|---|---|
| `tools/team/lead/assign.sh W<n> <batch> [unitsfile]` | Fetches, then `checkout -f -B work/<batch> origin/main` in `decompile_mvp_04-W<n>`. Records the slot in `state/assignments.txt` and rebuilds `state/busy_units.txt` from every "running" line's `queue/<unitsfile>`. Paths are already rewritten to the repo copy. |
| `tools/team/lead/integ.sh work/<branch> [--allow X ...]` | cd's to orch, then runs `integrate.py <branch> --allow config/GV4E69/symbols.txt [extra] --push`. Up to 3 tries (transient verifier download failure). Exits 0 on "-> main", 1 on REFUSED / mismatch / regressions / build check failed. |
| `tools/team/lead/queue/p4_00..p4_33.txt`, `p3_28.txt` | Batch unit lists (space-separated `dir/tu_XXXXXXXX`) |
| `tools/team/lead/state/assignments.txt` | Slot → branch, status, unitsfile |
| `tools/team/lead/state/busy_units.txt` | Units held by running workers (don't double-assign) |
| `tools/team/lead/state/resume_state.md` | Older (00:26) lead resume note: TODOs, partly superseded by this file |
| `tools/team/lead/state/opus6_families.txt` | Hard-case family list for Opus rounds (families 1-3 done in round 6) |
| `tools/team/lead/state/relocname_fixes.txt` | 19 functions with identical code that score <100 % because of symbol-name differences (small cleanup task) |
| `tools/team/lead/state/link_issues.txt` | linkonce/vtable link notes |
| `tools/team/lead/state/zero_gain_names.txt` | 712 protolint return-type mismatches that gain nothing. Don't churn them. |
| `tools/team/lead/worker_prompt_p4.md` | **Exact worker prompt template** (section 3) |
| `tools/team/lead/worker_tools/<Qxx>/*.py` | Worker helper scripts referenced by prompts. UNVERIFIED portability: some hardcode a `decompile_mvp_04-W<n>` path or a scratchpad path near the top; edit before use. |
| `tools/team/lead/pending/exi_split/*.c` | Ready drafts for the EXI split (section 7) |
| `tools/team/lead/unpaired.py REPO [unit-substr]` | Finds target functions a unit already reproduces under another symbol name (rename candidates) |

Suggested first lead commit: copy `tools/team/lead/` into orch and commit it
(`integrate.py --push --allow tools/team/lead` in lead mode), so it survives. The owner asked that HANDOFF.md not be
committed yet.

### Build, verify and the merge gate
- Build (any worktree): `export PATH="/c/Users/Patrick Taylor/AppData/Local/Microsoft/WinGet/Links:$PATH"; python configure.py && ninja`.
  ninja is NOT on the Bash PATH without that export.
- Verify (protected; never edit): `python tools/verify/verify.py --baseline-ref $(git merge-base HEAD origin/main)`.
  It rejects regressions, any `#pragma`, and the word "asm" anywhere in source (comments too).
- Literal/target gate: `python tools/match/check_literals.py <unit>` must report 0 NEW mismatches. It catches functions
  that objdiff scores 100 % but that load the wrong float/string/jump target. It uses `tools/match/symbol_aliases.tsv`.
- **Merge gate** = `tools/team/integrate.py`:
  1. merges the worker branch onto origin/main; refuses files outside `src/`, `include/` unless `--allow`;
  2. runs configure + ninja and checks main.dol against `config/GV4E69/build.sha1`;
  3. runs verify.py on each first-parent commit and check_literals;
  4. pushes only if everything passed and main did not move (it rebases over progress-card commits).
  `--head-only` / no branches = lead mode (verify and push the current branch's own commits).

## 3. Workflow and conventions

**Batches.** A batch is a list of about 3-12 units in `queue/<name>.txt`, given to one worker in one worktree,
on branch `work/<name with dash>`.

| Batch family | Target |
|---|---|
| `range_NN` | Pass 1, address ranges, ~8 units |
| `pass2_gNN` / `pass2-NN` | Pass 2 over game groups |
| `tail_NN` | Library tail 0x8036F44C+ |
| `p3_NN` | Pass 3: 0 % functions ≤0x200 in units with ≥2 of them |
| `p4_NN` | Pass 4: 0 % functions ≤0x400 in units with ≥3 of them; game first, then fe/db/ealib/dolphin |
| `opus-families-N` | An Opus worker on cross-unit hard-case families (`state/opus6_families.txt`) |

Lists were generated from report.json, excluding units in `busy_units.txt`. A p5 list does not exist yet (section 7).

**Assigning.**
1. `bash tools/team/lead/assign.sh W<n> p4-NN p4_NN.txt`.
2. Launch an Agent: Sonnet by default, Opus for hard-case families; background; worktree = that slot.
3. Use the prompt from `worker_prompt_p4.md`, substituting `<N>`/`<NN>` and per-unit flag notes from configure.py.
The workers run about 2.5 h, commit locally and never push. Their final report says per unit: before/after, and what blocked the rest.

**Merge procedure** (lead, when a worker reports done, or on its branch at timebox):
1. `bash tools/team/lead/integ.sh work/p4-NN` and add `--allow` for any of these the branch touched:
   `--allow docs/PATTERNS.md --allow docs/NEARMISS.md --allow configure.py --allow tools/match`.
2. **REFUSED (merge conflict):** in the worker's worktree, `git merge origin/main`.
   - Header field-split conflicts (e.g. `fe_80459228.h` FeState/FeGlobal80619948): take the union by hand.
   - A unit .cpp that conflicts with a clone/range commit: `git checkout --ours` (or `--theirs`, whichever has more matches), then commit.
   - Re-run integ. Verify catches any lost match.
3. **build check failed:** usually a duplicate extern or a header redefinition. Fix on the branch (commit), then re-integrate.
4. **NEW literal/target mismatch:** fix the literal/target on the branch first (e.g. 1.0f vs 60.0f). Never merge it.
5. **VERIFY regressions:** find the commit; usually a shared-header change or a rename. Fix, or drop that commit (`git revert` on the branch).
6. **HTTPError / "remote rejected":** transient. integ.sh retries; re-run if needed.
7. Then mark the slot done in `state/assignments.txt`, `assign.sh` the slot to the next queue item, and launch a worker.
   Docs files (PATTERNS/DECISIONS/PROGRESS) use union merge (`.gitattributes`).

**Commit messages.**
- Workers: `match(<dir>/<tu>.cpp): <function> [N/M funcs]`, one unit per commit (several functions allowed: `..., 23 functions [23/30 funcs]`).
- Lead: `config(...)`, `tools: ...`, `docs: ...`, `setup(<unit>): ...`.
- Renames need evidence in the message (CLAUDE.md: no invented names).
- End every commit with `Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>`.

**DECISIONS.md** holds owner-approved or lead-decided project rules with evidence, plus "Open questions for owner".
Add an entry for every flag/split/convention change (`- YYYY-MM-DD | **Title** *[lead, owner authority]* | evidence | where`).

Decided, one line each:
1. Target GV4E69 USA rev 0.
2. prodg-hybrid: ProDG for game/EA, MWCC for the Dolphin SDK.
3. Native Windows host.
4. Phase 1 tool downloads approved.
5. Private GitHub repo.
6. Blanket owner approval.
7. Build pipeline approved.
8. Compilers: ProDG 3.9.3 = g++ 2.95.3 SN v1.76.
9. SN small-data bases r13 0x806F69C0 / r2.
10. libgcc -O2 -G0.
11. Game: -Os -G0 -fno-rtti -fno-exceptions, plus -ffloat-store.
12. SDK OS first flags datapoint.
13. Probe functions committed.
14. Verifier + CI installed.
15. CI hosting.
16. Original-assembly functions stay split (never C).
17. Push + one issue per unit.
18. No human in loop; push to main.
19. SDK units with original-code functions stay NonMatching.
20. Verifier rename/code-less fix (owner, 87d2cc9).
21. Lead has full authority.
22. Animation choosers/goals = one unity TU.
23. Six pragma lines allowed (ineffective; see open questions).
24. EA libs -O2 -G0.
25. `#line` original paths where retail has `__FILE__`.
26. Early game TUs use game flags.
27. linkonce link issue known, non-blocking.
28. 0x803401A8..0x803663B0 is game code.
29. Code overlay units fe (`FE_OVERLAY`, .feoverlay) and db (`extern "C"` + `DB_OVERLAY`).
30. Tail library map/flags/split.
31. tu_803912F8 + tu_803927E4 nsr.
32. OS.c-range unit -opt nopeephole.
33. Note: SDK OS toggles peephole per function.
34. libgcc/tu_80413940 -O2 -G 1024 (+ `__shr2i` rename).
35. dvdlow split at 0x80426CD0.
36. dvderror -inline noauto.
37. ealib/tu_803EB2AC sda + nsr.

Open questions (owner-only, already recorded; don't re-ask):
- (a) verify.py ignores allowlisted `#pragma` lines (bug).
- (b) verify scores ignore relocation targets. Mitigated by check_literals.
- (c) verify cannot accept SDK unit splits that move already-matched functions. `staged/sdk-resplit` (card/ax/mtx) is ready but unmergeable.
- (d) Reading public NFS:MW EA SND decomp as reference: proceeding under option (a).

## 4. Live work in progress (as of 10:23 CDT)

Agent IDs belong to the OLD coordinator session; a new session probably cannot `SendMessage` them (UNVERIFIED).
Workers keep running in the background and commit to their branches. If no report arrives, integrate by
branch state after the timebox (start + ~2.5 h). Uncommitted work in a worktree is not merged; leave it.

| Slot | Branch | Batch units file | Agent | Started | Ahead of main | Last commit | Notes |
|---|---|---|---|---|---|---|---|
| W1 | work/p3-28 | p3_28.txt | aa3ef94dd702af8fb | 08:45 | 14 | 10:18 | p3, near timebox |
| W2 | work/p4-28 | p4_28.txt | a746e9217f8d235cc | 09:44 | 4 | 10:20 | |
| W3 | work/p4-30 | p4_30.txt | af7ce6467193eee16 | 09:54 | 2 | 09:58 | |
| W4 | work/p4-27 | p4_27.txt | a9589810dc46486d3 | 09:44 | 9 | 10:13 | |
| W5 | work/p4-22 | p4_22.txt | a58a53b54ae662906 | 09:00 | 16 | 10:18 | |
| W6 | work/p4-33 | p4_33.txt | ae8600c4f09a7ddc9 | 10:08 | 1 | 10:19 | sdk/tu_8043F058, libsn/tu_80407604, animation/goals/tu_8027FD64 |
| W7 | work/p4-26 | p4_26.txt | ac9e3f079334e4a6c | 09:14 | 4 | 10:17 | fe |
| W7s3 | work/p4-32 | p4_32.txt | a8092f112d12a8d63 | 10:01 | 0 | — | |
| W8 | work/p4-25 | p4_25.txt | a34e6937384b10ba2 | 09:08 | 10 | 10:10 | |
| W9 | work/p4-29 | p4_29.txt | a109c1b496f2d8b00 | 09:52 | 4 | 10:17 | |
| W10 | work/p4-31 | — | (done) | — | 0 | — | **FREE.** Merged as a45298cc (dolphin exi/os, +3 commits incl. 23-function EXIBios). |
| W11 | work/p4-24 | p4_24.txt | a22b8411026ed722a | 09:03 | 8 | 10:17 | |
| W12 | work/p4-23 | p4_23.txt | a014e28e6f18df869 | 09:02 | 31 | 10:20 | |

Check the live state any time:
```
for w in W1 W2 W3 W4 W5 W6 W7 W7s3 W8 W9 W10 W11 W12; do d="/c/Users/Patrick Taylor/decompile_mvp_04-$w"; echo "$w $(git -C "$d" branch --show-current) ahead=$(git -C "$d" rev-list --count origin/main..HEAD) last=$(git -C "$d" log -1 --format=%cd --date=format:%H:%M)"; done
```

No failed or partially merged batches are outstanding. Everything before p4-22 is merged (p3_00..p3_27, pass2, tail,
opus rounds 1-6, p4-31). `staged/sdk-resplit` is intentionally unmerged (open question c).

**Remaining queue, in order.** p4_33 is already running on W6. Then the 22 game batches below.
Count = 0 % functions ≤0x400 when the lists were built.

| Batch | Units (first … last) | 0% fns |
|---|---|---|
| p4_00 | tu_80021BE8 … tu_800493D4 | 51 |
| p4_01 | tu_8004B6BC … tu_80077238 | 61 |
| p4_02 | tu_80082248 … tu_8009BC3C | 63 |
| p4_03 | tu_8009FC5C … tu_800B5C68 | 65 |
| p4_04 | tu_800C1438 … tu_800E4234 | 62 |
| p4_05 | tu_800E8890 … tu_800FD438 | 66 |
| p4_06 | tu_80101254 … tu_801164AC | 65 |
| p4_07 | tu_8011C5E8 … tu_801498C0 | 61 |
| p4_08 | tu_8014BEA4 … tu_8015F164 | 62 |
| p4_09 | tu_80163390 … tu_80174318 | 60 |
| p4_10 | tu_80177C34 … tu_801800FC | 68 |
| p4_11 | tu_8018423C … tu_80198DB8 | 69 |
| p4_12 | tu_8019C1F8 … tu_801BAC74 | 61 |
| p4_13 | tu_801BDD60 … tu_801D31D8 | 62 |
| p4_14 | tu_801D771C … tu_801EA36C | 62 |
| p4_15 | tu_801EE438 … tu_80216CF4 | 63 |
| p4_16 | tu_8021ADDC … tu_802362A8 | 72 |
| p4_17 | tu_8023DB8C … tu_8025B59C | 73 |
| p4_18 | tu_8025F708 … tu_802C3974 | 61 |
| p4_19 | tu_802C79F0 … tu_802FCAC0 | 70 |
| p4_20 | tu_80300848 … tu_80313C14 | 89 |
| p4_21 | tu_80317B88 … tu_8032ECD8 | 60 |

The first free slot is W10. Start with `bash tools/team/lead/assign.sh W10 p4-00 p4_00.txt`. Before assigning,
re-check that no unit of the batch is in `busy_units.txt`. The lists predate p4-22..33 merges; overlaps are unlikely
(different dirs) but UNVERIFIED.

## 5. Known compiler/matching patterns

**Flag fixes** (all confirmed by whole-unit rebuilds: matched count up, no unit lost, verify passed):

| Fix | Units | Evidence |
|---|---|---|
| `cflags_ealib_nsr` (-O2 -G0 -fno-strength-reduce) | ealib/tu_803912F8, tu_803927E4 | Loop index kept as multiply, not induction pointers. Several loops went 100 %. |
| `cflags_ealib_sda_nsr` (-O2 -G8 -fno-strength-reduce) | ealib/tu_803EB2AC (RealCore) | Like tail-06 fn_803EB5E4/fn_803EB61C; whole-unit gain, no loss |
| `-opt nopeephole` added to cflags_dolphin_sdk | dolphin/os/tu_80431828 (OS.c range) | Matches retail un-peepholed rlwinm/mr pairs |
| `-O2 -G 1024` | libgcc/tu_80413940 | __divdi3/__moddi3/__udivdi3/__umoddi3 read sdata via r13. `fn_80406CCC` → `__shr2i`. |
| Split at 0x80426CD0; dvdlow part = cflags_dolphin_sdk | dolphin/exi/tu_80425E54 → + tu_80426CD0 | Only 0 % functions moved, so verify accepted it. Then EXIBios matched 23 functions. |
| `-inline noauto` | dolphin/dvd/tu_80425954 (dvderror.c) | fn_80425A70 stops auto-inlining |
| `-ffloat-store` for all game code | game/*, fe, db | Float locals spill and reload after every assignment |

Partial/unadopted:
- RealCore per-function nsr (fn_804006FC in tu_803FFD9C is 100 % only with nsr; other loops in the unit need it off).
- SDK OS per-function peephole (functions after the first hand-written function use peephole off).
Neither can be expressed without `#pragma` (ineffective: open question a) or a unit split.

**Recurring match tricks** (details and examples in `docs/PATTERNS.md`, newest sections last):
- **Store order:** the last-written store is emitted first. Constructor zeroing order is reversed relative to source.
- **Register order:** register order follows ref counts. Separate locals or a re-read change callee-saved priority. A pass-through param kept as its own variable changes allocation.
- **Function pointers:** give callees and function pointers their TRUE return type (void vs int changes scheduling). Tool: `rettoggle.py`; repo-wide `tools/match/protolint.py`.
- **Float placement:**
  - float-param position;
  - pool floats written as literals (always confirm with check_literals);
  - one-float-struct globals.
- **Switches:**
  - written index-first so the case value stays live (no constant folding);
  - a dummy `case 0: break;` to shape the root;
  - dead-compare switches.
- **Jump threading:** goto chains to stop it; loops entered via a jump (`goto` into the loop, or a twice-called body).
- **Load order:** an inline accessor gives field-vs-spilled-float load order; inline `Secs(n)` hoists lis clusters.
- **Indexed loads:** base-first lwzx: `char* b = (char*)x + K; int off = i*4; *(int*)(b+off)`.
- **fe widgets:** two-vptr widget ctors (Recipe A); views via `mkcls.py`; a local holder pointer for +0xDC sub-object calls.
- **Callback structs:** a volatile field subset.
- **Linkage:** `extern "C"` blocks. Functions appended after an `extern "C" {}` need their own block; mangled vs C linkage must match the target symbol.
- **Shared code:** `tools/match/clone.py <unit> --write` finds exact-shape twins across the repo; run it first. Generators/dispatcher templates (`worker_tools/R28/gen_all.py`, `R38/genv.py`) handle big families.

**Categories that keep failing:**
1. **Original hand-written functions** (mtspr/mfdsisr/trap words, PPCArch, libsn low-level, `dolphin/base/tu_8041A5A4`, `libsn/tu_80403E80`). Must stay split assembly by rule. Never "fix" these.
2. **Register-allocation-only diffs** from g++ 2.95 (mr r8 vs r9, mr. vs cmpwi, second zero register, duplicated pointer copy). These sit at 95-99 % as near-misses (`docs/NEARMISS.md`, 86 lines). `state/opus6_families.txt` families 4-9 are the open ones.
3. **Large functions (>0x400)**, especially EAGL/SND and event dispatchers. Low first-pass yields; need generator scripts.
4. **Flag-granularity problems** (per-function nsr/peephole, above).
5. **Relocation-name-only diffs**, 19 functions (`state/relocname_fixes.txt`). Code is right; a symbol rename or alias is needed.
6. **fe header families:** `tu_8043FDC0.h` (FeObj) and `fe_80459228.h` (FeW) are incompatible. Workers must use the one the unit already includes.

## 6. Throughput data

- Totals: 120 (10-10) → 16,053 (10-11) → 19,329 (10-12 10:09).
  - 16,353 at 00:26 → 19,329 at 10:09: ~3,000 in ~10 h, about 300/h. This includes bulk clone/rename wins and a usage-limit stall.
  - Current p4 rate is lower: a 13-slot fleet of 2.5 h batches gives an estimated 150-250 functions/h (UNVERIFIED).
- Match commits on main: 1,648 on 10-11, 684 on 10-12 so far (225 since 06:00). Some commits cover several functions.
- Per batch (match commits in each merge; approximate, and a few large outliers may include re-merged commits):
  - **Pass 1** ranges: 98-353 functions per ~8-unit range.
  - **Pass 2:**
    - most game groups 5-46;
    - outliers: pass2-04 386, pass2-g03 217, pass2-g16 157.
  - **Tail:** tail_00..10: 4-35.
  - **p3:**
    - game batches p3_00..09 1-22 (p3_03 = 1: heavily worked);
    - p3_10..27 mostly 7-29, outliers p3_06 192, p3_10 181, p3_12 174, p3_14 156 (UNVERIFIED: those counts probably include clone/rename sweeps);
    - p3_27 gamelib ≈ 89 functions by report.
  - **Opus families:** round 4 96, round 5 296, round 6 10.
  - **p4:** p4-31 (dolphin) 3 commits = 25 functions.
- Better yields: fe/db/ealib/gamelib/snd groups. Worse yields: heavily-worked game units.

**Low-rate units (flag/section audit candidates):**

| Bucket | Units (matched/total) |
|---|---|
| 0 % / near | dolphin/vm/tu_8043D960 0/21, sdk/tu_8043F058 0/33 (on W6), snd/tu_803B998C 2/43 (Csis) |
| 0 %, original code (expected) | dolphin/base/tu_8041A5A4 0/23 (PPCArch), libsn/tu_80403E80 0/101 |
| Low: dolphin | os/tu_804330D0 6/46, os/tu_80437444 6/26, ai/AI 6/19, dvd/tu_804227D4 17/57, os/tu_80435A10 15/42 |
| Low: game | tu_8004B6BC 7/30, tu_8009BC3C 10/36, tu_80194D44 12/39, tu_80216CF4 7/22, tu_80227564 10/29, tu_8021ADDC 11/31, tu_8022309C 8/21, tu_802EFF28 7/18, tu_801287AC 11/27 |
| Low: db | tu_8055F730 9/31, tu_80565FD4 14/48, tu_80563954 11/32 |
| Low: ealib / snd | ealib/tu_803A0310 14/39, ealib/tu_8039B3E4 18/47, snd/tu_803B7DA0 12/29 |

## 7. Open problems and recommended next steps

**Do next, in order:**
1. **Commit the lead kit.** Copy `tools/team/lead/` into orch, then lead-commit and push it (integrate lead mode with `--allow tools/team/lead`).
2. **Refill W10** with p4_00. As each worker finishes (or passes start+2.5 h), integrate it with integ.sh, then refill from the queue.
   - Point new prompts at `tools/team/lead/queue/` and a scratch dir in your own scratchpad.
   - Append a short session entry to `PROGRESS.md` (CLAUDE.md requires it each session).
3. **EXI split** (from p4-31 report; not started).
   - Split dolphin/exi at 0x804286AC: 0x804286AC..0x80428C64 is EXIUart.c (`cflags_dolphin_sdk` + `-char signed`, -O4,p).
   - 0x80428C64..0x80428F14 is the GXInit head (`-O4,p -opt nopeephole`).
   - Drafts: `tools/team/lead/pending/exi_split/exiuart.c`, `gxinit_head.c`.
   - The moved functions are all 0 %, so verify accepts it (like dvdlow). Requires: `config/GV4E69/splits.txt` + configure.py object entries; regenerate the split (never hand-edit split output); DECISIONS entry.
4. **tu_80394744 re-split** at 0x803959D8 (fn_803959D8 is sda). Then try moving the first part to `cflags_ealib_nsr` (adopt only if no unit loses).
5. **Opus round 7** on `state/opus6_families.txt` families 4-9: one Opus worker, branch `work/opus-families-7`.
6. **symbols.txt `type:label`** for the OSExceptionVector labels (they are mis-typed as functions).
7. **relocname_fixes.txt cleanup** (19 functions; small Sonnet task).
8. **After p4:** generate a p5 list from report.json (0 % functions in larger size bands, or >0x400 with a generator-first prompt), excluding busy units.
   - Also consider second passes on the low-rate units above.
   - Also a large-function strategy: generator/dispatcher templates in `worker_tools/R28`, `R38`.
9. **Cleanup:** remove `decompile_mvp_04-match` (lead/prep5) and `-audit` worktrees and stale merged `work/*` branches (`git worktree remove`; no `rm -rf`, which is denied).
10. **Resume crons.** The 2am resume crons (Oct 14 02:06) were session-only in the old session and die with it. Re-create if you need an auto-resume (CronCreate / scheduled-tasks).

**Fragile points (easy to break):**
- **Protected paths:** never edit `tools/verify/**`, `.github/workflows/**` or `.claude/**`; they are permission-denied anyway. Never add `#pragma` or the word "asm" to source.
- **verify keys regressions by (unit name, function name).** Never move an already-matched function to another unit or rename a unit. Splits may only move 0 % functions.
- **`sed -i` strips CRLF** on sources. Use Python or the Edit tool. Workers were told; watch for whole-file diffs.
- **`tools/match/sort_functions.py`** breaks virtual-method units and inline/type placement. Don't run it on those.
- **`tools/scout/rename.py`** skips functions still referenced by their plain `fn_` name; hand-rename those (`unpaired.py` finds them). Its `masked_bodies()` content pins pair a compiled function to a unique identical target.
- **Shared headers** (`include/fe/fe_80459228.h` and other multi-unit headers): conflicts need a manual union. A struct change must keep every matched user matching (CLAUDE.md).
- **`extern "C"` vs mangled linkage** mismatches show up as 0 % with identical code.
- **Literal pool:** objdiff ignores relocation names. Always run check_literals; integrate.py enforces it.
- **main moves** every couple of minutes (progress bot). integrate.py handles the rebase; never force-push.
- **Verifier baseline download flake** (HTTPError fetching sjiswrap/tools): retry (integ.sh does).
- **ninja PATH:** Bash needs the WinGet Links export. The home path has a space; ninja rules don't quote paths, so pass relative tool paths.
- **`.claude/settings.json`** denies edits/mkdir under `build/**` and `orig/**` and any `rm -rf`. Let configure/ninja create build outputs.
- **Busy units:** `busy_units.txt` must be rebuilt after every assignment change; assign.sh does it. Don't hand two workers the same unit.
- **One unit per commit; no game data in git** (`orig/`, `build/` gitignored). Don't commit `.o` files from scratch dirs.
