#!/bin/bash
# usage: assign.sh W9 pass2-g15 [unitsfile]
# Resets the worktree's branch to origin/main, records "W  work/branch  running  [unitsfile]" in
# assignments.txt, and rebuilds busy_units.txt from every running line's units file.
L="/c/Users/Patrick Taylor/decompile_mvp_04/tools/team/lead"
w=$1; b=$2; f=${3:-}
d="/c/Users/Patrick Taylor/decompile_mvp_04-$w"
git -C "$d" fetch -q origin && git -C "$d" checkout -q -f -B work/$b origin/main || exit 1
line="$w work/$b  running  $f"
if grep -q "^$w " "$L/state/assignments.txt"; then sed -i "s#^$w .*#$line#" "$L/state/assignments.txt"; else echo "$line" >> "$L/state/assignments.txt"; fi
grep "running" "$L/state/assignments.txt" | awk '{print $4}' | grep -v "^-$" | grep . | while read uf; do grep -v "^#" "$L/queue/$uf"; done \
  | tr ' ' '\n' | cut -d: -f1 | grep . | sort -u > "$L/state/busy_units.txt"
echo "$w -> work/$b at $(git -C "$d" log --oneline -1 | cut -c1-12); busy units: $(wc -l < "$L/state/busy_units.txt")"
[ -n "$f" ] && head -1 "$L/queue/$f"
