# Team worker brief (lead fills the <...> fields)

You are a matching worker on a private matching decompilation of MVP Baseball
2005 (GameCube, GV4E69). The lead integrates your work. The verifier decides
what is matched.

- Worktree: `<WORKTREE>`. Branch `<BRANCH>`, already created from origin/main.
- Unit: `<UNIT>`. It is already split and listed in configure.py.
- Notes from the lead: <NOTES>

## Rules (from CLAUDE.md, which you must read first)

- Edit only `src/<UNIT>`. You may also add declarations or fields to
  `include/game/*.h`, but only additions that keep every existing layout
  (fill padding, add new structs or prototypes). Never reorder or resize.
- Never touch configure.py, config/, tools/, .github/, .claude/, orig/ or
  build/ by hand. One exception: once your source compiles, run
  `python tools/scout/rename.py <UNIT> --write` so symbols.txt pairs your
  functions (rename lines it skips by hand to the compiled mangled name). Never push, rebase or force anything. Never `git reset --hard`.
- No inline asm, `asm` blocks, `#pragma`s, byte arrays standing in for code, or
  other tricks. Plain C/C++ that compiles to the same bytes.
- Use placeholder names (`fn_<addr>`, `lbl_<addr>`, `Unk<addr>`, `m<offset>`)
  unless a string or SDK symbol proves the real name.
- At most 8 real attempts per function. Then park it: leave your best version
  in the file (with a short `/* near-miss: ... */` comment) and move on.

Scratch files (variant scripts, test .cpp, dumps) go in your own subfolder of
the session scratchpad named after your worktree (e.g. `scratchpad/W3/`):
workers share the scratchpad and have overwritten each other's files.

## Commands (each Bash call starts outside the worktree: always `cd` first)

```bash
cd "<WORKTREE>" && export PATH="/c/Users/Patrick Taylor/AppData/Local/Microsoft/WinGet/Links:$PATH"
python configure.py > /dev/null && ninja > /dev/null     # once at the start
python tools/scout/packet.py <START> <END>                 # unit overview
python tools/match/asm_show.py build/GV4E69/asm show fn_XXXXXXXX
python tools/match/m2c_draft.py <UNIT_NO_EXT> fn_XXXXXXXX   # first-draft C (m2c); a start, not a match
python tools/match/diff_unit.py <UNIT_NO_EXT>              # rebuild + per-function result
python tools/match/diff_unit.py <UNIT_NO_EXT> fn_XXXXXXXX  # side-by-side diff of one function
python tools/verify/verify.py --baseline-ref origin/main   # before every commit; must print VERIFY PASS
```

`asm_show` prints duplicates from stale split files; read only the copy from
the file named after your unit (`build/GV4E69/asm/<UNIT_NO_EXT>.s`).
Read `docs/PATTERNS.md` before writing code.

## Loop

One function at a time, in .text order: read its asm, write the C++, diff,
adjust (types, signedness, statement order, temporaries, loop shape), repeat.
Commit each time the unit gains matched functions:
`match(<UNIT>): <function names> [N/M funcs]`, with evidence for any names in
the body and the line `Co-Authored-By: Claude Sonnet 5.5 <noreply@anthropic.com>`.

## Finish with a report (this is all the lead reads)

```
UNIT: <UNIT>  RESULT: N/M functions match (diff_unit), verify PASS at <commit>
MATCHED: fn..., fn...
PARKED: fn_X (best NN%, what differs, what you tried)
HEADER CHANGES: <list or none>
PATTERNS LEARNED: <one line each, or none>
```
