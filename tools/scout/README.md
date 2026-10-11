# Scout tools

Per-unit setup, done before and after matching. They inform; they verify nothing.
`tools/verify/verify.py` and objdiff decide what counts as matched. The
inner-loop tools are in `tools/match/`.

| Script | Use |
|---|---|
| `packet.py START END` / `--unit NAME` | A "unit packet" from dtk's split asm. Shows function roles (ctor/dtor/attr/factory, with object size), class names proven through vtable slot +0x1C, data clusters with their neighbours, a suggested `splits.txt` block, and the neighbouring functions. Takes about 4 s. |
| `rename.py UNIT [--write]` | Copy the compiled unit's function names (`build/GV4E69/src/<unit>.o`) into `config/GV4E69/symbols.txt`. Pairs by `fn_<addr>` prefix, then exact size in order, then close size. Refuses a pairing it can't trust and lists what it left unpaired. Dry run unless `--write`. |

Checked on `animation/choosers/playeridchooser.cpp` (2026-10-10):

- `packet.py 0x80270730 0x80271748` found the four vtables, the classes
  `ICommonPlayerID` and `cSignatureChooser`, all their ctor/dtor/factory/attr
  functions and object sizes 0x20 and 0x24. Its suggested block equals the
  hand-made split (`.rodata 805DC568..805DC644`, `.data 8061E648..8061E650`).
  The matching session spent about 35 minutes on that by hand.
- `rename.py`, replayed on the pre-rename `symbols.txt`, reproduced the hand
  renames. It left one function unpaired: the source had compiled two
  functions in a different order from the target, and it flagged that instead
  of mislabelling either.

Game-specific call targets (operator new, the base dtor, the attribute
registration functions) are constants at the top of `packet.py`. Add more there
as other units show other bases.
