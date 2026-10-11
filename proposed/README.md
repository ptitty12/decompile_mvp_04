# Proposed verifier change: for the OWNER to review and install

## Problem (found 2026-10-10)

`tools/verify/verify.py` keys functions by **name** when it checks for match
regressions. When a matched function is renamed, its baseline name disappears
and the verifier reports "100% → 0%". A typical rename: the C++ mangled name
changes once a parameter type is corrected. Real example:
`fn_802713D4__11Unk8027130CiPi` → `fn_802713D4__11Unk8027130CScPi`. It is still
100% matched (same unit, address 3236, size 112).

## Fix

`verify-rename-fix.patch` makes a function that is missing by name fall back to
the one with the same **unit, address and size** in the objdiff report. Such
renames are printed as information, not regressions. A function that actually
drops below its baseline still fails.

## Install

```bash
git apply proposed/verify-rename-fix.patch
```
```bash
python tools/verify/verify.py --print-protected
```

Copy the new `tools/verify/verify.py` hash line into `tools/verify/protected.sha256`
(only that line changes). Then commit, and `git rm -r proposed/`.
