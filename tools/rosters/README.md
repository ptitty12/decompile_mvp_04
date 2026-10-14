# tools/rosters

Readers and writers for the roster and team data of MVP Baseball 2005 (GameCube,
GV4E69). Python 3, standard library only. The format is specified in
[`docs/ROSTERS.md`](../../docs/ROSTERS.md). The roadmap milestone is K2
([`docs/ROADMAP.md`](../../docs/ROADMAP.md)); roster and team packs (E6, E7) are built on
these modules.

| File | What it does |
|---|---|
| `refpack.py` | EA RefPack (QFS) decompress and compress. The compressor is a greedy matcher: its output decodes to the same bytes, but it is not byte-identical to EA's tool (and about 5% larger). |
| `big.py` | BIGF archives: list, read, extract, rebuild. Opens a plain file or an entry of a disc image (`image.ciso:/data/database/database.big`, through `tools/recon/gcdisc.py`). `build()` writes the game's exact layout; 193 of the 197 archives under 20 MB on the disc rebuild byte for byte. |
| `dbtables.py` | The 18 tables inside `database.big`: parse, list, dump as JSON, show value ranges, check the round trip, and write a table back. Also `djb2()`, the game's key hash. |
| `loc.py` | The text files `FEENG.LOC`, `IGENG.LOC`, `MC_ENG.loc` (team names, stadium names and every other UI string): parse, dump, edit, re-serialize. All three files re-serialize byte for byte. |
| `tests/test_rosters.py` | Unit tests. They build all their data in the test, so no game bytes are involved. |

## Use

Everything reads the player's own disc image; nothing is copied into the repo.
On Git Bash set `MSYS_NO_PATHCONV=1` so a path like `image.ciso:/data/...` reaches Python unchanged.

```
python -I tools/rosters/big.py list      "image.ciso:/data/database/database.big"
python -I tools/rosters/big.py extract   "image.ciso:/data/database/database.big" team.dat -o team.txt
python -I tools/rosters/dbtables.py list   database.big
python -I tools/rosters/dbtables.py dump   database.big team --limit 3
python -I tools/rosters/dbtables.py ranges database.big attrib
python -I tools/rosters/dbtables.py check  database.big
python -I tools/rosters/dbtables.py write  database.big team team.json -o patched.big
python -I tools/rosters/refpack.py d packed.bin unpacked.bin
python -I tools/rosters/loc.py dump FEENG.LOC --grep stadium
python -I tools/rosters/loc.py check FEENG.LOC
```

`<archive>` is a file path or `image:/path/inside/the/disc`. `dump` writes JSON to
stdout: `{"table", "fields", "records": [{"_key": "...", field: value, ...}]}`.
`write` replaces one table with the JSON you give it and rebuilds the archive; tables
you did not touch keep their original compressed bytes.

As a library:

```python
import sys; sys.path.insert(0, "tools/rosters")
import dbtables
db = dbtables.Database.open("image.ciso:/data/database/database.big")
team = db.table("team")
team.set("%09x" % dbtables.djb2("Ana"), team_long_name="Anaheim")   # keyed by hash of the abbreviation
data = db.to_bytes()                                                # a complete database.big
```

## Rules

- **Never commit anything read from a disc**: extracted files, JSON dumps of real
  records, table text. Put scratch output outside the repo.
- `check` is the K2 acceptance test: it reads `database.big` from the disc, parses
  all 18 tables, re-serializes them and compares the bytes, then rebuilds the archive.
  Run it locally; it prints a report and commits nothing.
- Run the tests with `python -I -m unittest discover -s tools/rosters/tests -v`.
