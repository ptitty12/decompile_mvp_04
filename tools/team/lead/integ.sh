#!/bin/bash
# usage: integ.sh work/<branch> [extra --allow args...]
# Integrates with retries (the verifier's baseline build sometimes fails to download sjiswrap).
cd "/c/Users/Patrick Taylor/decompile_mvp_04-orch" || exit 1
export PATH="/c/Users/Patrick Taylor/AppData/Local/Microsoft/WinGet/Links:$PATH"
b=$1; shift
for i in 1 2 3; do
  git checkout -q -f integrate/auto
  out=$(python tools/team/integrate.py "$b" --allow config/GV4E69/symbols.txt "$@" --push 2>&1)
  echo "$out" | grep -E "REFUSED|regressions|VERIFY|-> main|failed|mismatch|hunk" | tail -4
  echo "$out" | grep -q -- "-> main" && exit 0
  echo "$out" | grep -q "REFUSED\|mismatch\|regressions: [1-9]\|build check failed" && exit 1
  echo "(retry $i)"
done
exit 1
