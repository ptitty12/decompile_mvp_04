# Proposed verifier change: for the OWNER to install (blocks pushing new units)

`tools/verify/verify.py` is protected (CLAUDE.md), so agents can't fix it. Two
false positives in its regression check, found 2026-10-10:

1. **Renamed functions look like regressions.** Functions are keyed by name.
   When a matched function's mangled name changes, e.g. after correcting a
   parameter type (`fn_802713D4__11Unk8027130CiPi` → `...CScPi`, still 100%),
   the old name reports "100% → 0%".
2. **Code-less units look like regressions.** dtk's auto-generated data-only
   units (e.g. `auto_06_805DC644_rodata`) report "matched code 100%" because
   they contain no code. A new unit that claims part of their range makes them
   disappear or be renamed, which reports "100% → 0%". Almost every new unit
   starts where such a leftover begins, so this currently blocks pushing new
   units. (Hit on `animation/choosers/tu_80271748.cpp`, kept unpushed because
   of it.)

## Fix (`verify-rename-fix.patch`)

- A function missing by name falls back to the function with the same **unit,
  address and size**. Renames are printed as information.
- The unit-level check skips units with `total_code == 0`. Every function is
  still compared individually.

Tested on the real reports:
- rename-only baseline: PASS, listing 8 renames;
- new unit claiming auto data units: PASS, 33 functions at 100%;
- synthetic drop in a linked unit: FAIL at both the unit and the function level.

## Install (3 steps)

```bash
git apply proposed/verify-rename-fix.patch
```
```bash
python tools/verify/verify.py --print-protected
```

Copy the new `tools/verify/verify.py` line into `tools/verify/protected.sha256`.
Then commit, and `git rm -r proposed/`.
