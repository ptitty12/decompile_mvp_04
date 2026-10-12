#!/bin/bash
# usage: prep.sh W<n> <pass: p4|p5> <NN>
# assign.sh the slot to work/<pass>-<NN> with queue/<pass>_<NN>.txt, write the filled-in worker prompt to the
# lead scratchpad ($LEAD_SCRATCH, Windows path) as prompt_W<n>.md, and create the batch scratch dir.
L="/c/Users/Patrick Taylor/decompile_mvp_04/tools/team/lead"
w=$1; p=$2; nn=$3; n=${w#W}
S=${LEAD_SCRATCH:?set LEAD_SCRATCH to the lead scratchpad (Windows path)}
for u in $(cat "$L/queue/${p}_$nn.txt"); do grep -qx "$u" "$L/state/busy_units.txt" && echo "BUSY $u (not assigned)" && exit 1; done
bash "$L/assign.sh" "$w" "$p-$nn" "${p}_$nn.txt" | head -1 || exit 1
python - "$L/worker_prompt_$p.md" "$S" "$n" "$nn" "$w" <<'PY'
import sys
tpl, S, n, nn, w = sys.argv[1:6]
body = open(tpl, encoding='utf-8').read().split('\n---\n', 1)[1].strip()
open(S + '/prompt_' + w + '.md', 'w', encoding='utf-8').write(body.replace('<N>', n).replace('<NN>', nn).replace('<SCRATCH>', S))
PY
q=$(echo "$p" | tr -d p); mkdir -p "$S/Q${q}_$nn"
echo "prompt: $S\prompt_$w.md"
