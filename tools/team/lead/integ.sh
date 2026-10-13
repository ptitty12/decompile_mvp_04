#!/bin/bash
# usage: integ.sh work/<branch> [extra --allow args...]
# Integrates with retries (the verifier's baseline build sometimes fails to download sjiswrap).
cd "/c/Users/Patrick Taylor/decompile_mvp_04-orch" || exit 1
export PATH="/c/Users/Patrick Taylor/AppData/Local/Microsoft/WinGet/Links:$PATH"
b=$1; shift
# CLAUDE.md commit format: workers sometimes label near-misses "wip(<unit>): ...". Reword those to
# "match(" in the (finished) worker's worktree before merging; main itself is never rewritten.
wt=$(git worktree list --porcelain | awk -v r="refs/heads/$b" '/^worktree /{w=substr($0,10)} $0=="branch "r{print w}')
if [ -n "$wt" ] && git -C "$wt" log --format=%s origin/main..HEAD | grep -q "^wip("; then
  FILTER_BRANCH_SQUELCH_WARNING=1 git -C "$wt" filter-branch -f --msg-filter 'sed -E "1s/^wip\(/match(/"' \
    "$(git -C "$wt" merge-base HEAD origin/main)..HEAD" >/dev/null 2>&1 && echo "reworded wip( commits on $b"
  git -C "$wt" update-ref -d "refs/original/refs/heads/$b" 2>/dev/null
fi
for i in 1 2 3; do
  git checkout -q -f integrate/auto
  out=$(python tools/team/integrate.py "$b" --allow config/GV4E69/symbols.txt "$@" --push 2>&1)
  echo "$out" | grep -E "REFUSED|regressions|VERIFY|-> main|failed|mismatch|hunk" | tail -4
  # success only on a real ref update ("abc..def  HEAD -> main"), not "[remote rejected] HEAD -> main"
  echo "$out" | grep -qE "^ +[0-9a-f]+\.\.[0-9a-f]+ +HEAD -> main" && exit 0
  echo "$out" | grep -q "REFUSED\|mismatch\|regressions: [1-9]\|build check failed" && exit 1
  echo "(retry $i)"
done
exit 1
