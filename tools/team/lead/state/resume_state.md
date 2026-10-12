# Lead resume state (written 2026-10-12 00:26 CDT)
Main: 16,353 functions at 100% (of 24,158). Integration: decompile_mvp_04-orch, branch integrate/auto,
`python tools/team/integrate.py work/<branch> --allow config/GV4E69/symbols.txt --push`
(add --allow configure.py / docs/PATTERNS.md / docs/NEARMISS.md when a branch touches them).
On conflicts with main: in the worktree `git merge origin/main`, `git checkout --ours` the conflicted
unit files, commit, re-integrate (verify catches lost matches).
Assign a freed worktree: `scratchpad/tools/assign.sh W<n> <branch> <unitsfile>` (rebuilds busy_units.txt).

## Running agents (worktree, branch, agent id)
W1   work/p3-28                 aa3ef94dd702af8fb
W2   work/p4-28                 a746e9217f8d235cc
W3   work/p4-30                 af7ce6467193eee16
W4   work/p4-27                 a9589810dc46486d3
W5   work/p4-22                 a58a53b54ae662906
W6   work/p4-33                 ae8600c4f09a7ddc9
W7   work/p4-26                 ac9e3f079334e4a6c
W7s3 work/p4-32                 a8092f112d12a8d63
W8   work/p4-25                 a34e6937384b10ba2
W9   work/p4-29                 a109c1b496f2d8b00
W10  work/p4-31                 a5fce2aa2bbd73611
W11  work/p4-24                 a22b8411026ed722a
W12  work/p4-23                 a014e28e6f18df869

## Queue (next assignments)
p4_00 .. p4_21 (game). Same PASS-3 prompt with size cap 0x400; dolphin groups: MWCC, skip original-code (asm-only) functions like PPCArch.
 second pass (units in range_43.txt, 98/290 first pass)
tail second passes (tail_00..10 units had low first-pass yields on big EAGL/SND functions)
Opus round 6 when opus5_families.txt grows again.
## Pending owner-only items (don't ask): verify.py #pragma allowlist bug (DECISIONS open question).

## Lead TODO
- Flags experiment: RealCore (ealib_sda units 0x803EB2AC..0x80403E80) may be -fno-strength-reduce (tail-06: fn_803EB5E4/fn_803EB61C exact with it, others unchanged). Run when tail-07/tail-08 are merged: rebuild all ealib_sda units with +-fno-strength-reduce, compare per-unit counts, adopt per unit if no unit loses (like cflags_ealib_nsr).
- tu_80394744 boundary at 0x803959D8 (fn_803959D8 is sda); then move tu_80394744 to cflags_ealib_nsr.
- The PASS-3 prompt text is the same as the one used for p3_00/p3_01 (Q00/Q01 scratch): worklist = 0% functions in the units smallest first, about 15 min cap each, no near-miss retries, no sort_functions on virtual-method units.
- staged/sdk-resplit (card/ax/mtx splits) is blocked: verify.py counts moved functions as regressions (open question in DECISIONS). Don't merge it.
- p3 yield note: heavily-worked game units (p3_03) gave 1 match; fe/db/ealib/gamelib/snd groups (p3_10+) are the better yield. Game groups p3_00..09 already assigned.
- relocname_fixes.txt: 19 functions with identical code but <100% (symbol-name diffs) -> small cleanup task for a worker.
- protolint merged: tools/match/protolint.py (+11). 712 zero-gain mismatches listed in scratchpad PL/zero_gain_names.txt (don't churn).
- Integrate with scratchpad/tools/integ.sh work/<branch> [--allow ...] (retries transient verifier download failures).
- Flags lead: RealCore units may need per-function -fno-strength-reduce: fn_804006FC (tu_803FFD9C) matches 100% with it; fn_803FAA84 shows same per-iteration mulli. Investigate per-unit flag split later (tu_803FFD9C has other loops that match without).
