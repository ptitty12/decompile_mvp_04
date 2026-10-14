#!/usr/bin/env python3
"""Roster and team packs, format v1: the reference implementation of docs/MODDING.md.

Standard library only. A pack is a directory or zip with `pack.json` and JSON patch
files; it never contains retail data. Patches are applied, at load time, to the
tables read from the player's own disc.

    pack.py validate [--disc IMAGE] [--json] PACK...        # static checks; full checks with --disc
    pack.py apply --disc IMAGE --out DIR [--json] PACK...    # write patched files under DIR
    pack.py hash PACK...                                     # pack hashes and the set hash
    pack.py new DIR --id ID [--name NAME]                    # scaffold an empty pack

IMAGE is an ISO/CISO disc image or a directory holding an extracted disc
(`<dir>/data/database/database.big`, `<dir>/data/FEENG.LOC`, ...). PACKs apply in the
order given. DIR must not be inside a git work tree unless git ignores it.

Exit status: 0 ok (warnings allowed), 1 errors found, 2 usage or I/O problem.
"""
import hashlib
import json
import os
import re
import subprocess
import sys
import zipfile

try:
    from . import big, dbtables, loc, refpack
except ImportError:  # run as a script
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import big
    import dbtables
    import loc
    import refpack

API_VERSION = (1, 0)                 # engine mod API = pack format version (MAJOR, MINOR)
GAME_ID = "GV4E69-0"
PACK_HASH_PREFIX = b"mvp2005-pack-hash/1\n"
SET_HASH_PREFIX = b"mvp2005-packset-hash/1\n"
RESULT_HASH_PREFIX = b"mvp2005-result-hash/1\n"

# Capacities fixed in the game code (docs/ROSTERS.md 6.1). The loader never checks them.
LIMITS = {"players": 3250, "pitchers": 1800, "teams": 126, "managers": 36}

DATABASE_PATH = "/data/database/database.big"
LOC_FILES = ("FEENG.LOC", "IGENG.LOC", "MC_ENG.loc")       # spelled as on the disc, in /data/
ASSET_ROOTS = ("/data/frontend/",)                        # v1 allow-list for asset targets
DEFAULT_NAME = "Default,Default"                          # protected row 0 of attrib/pitcher/manager
ALLSTAR_TEAMS = ("AL", "NL")                              # unique_team codes of the All-Star sides
MAX_PATCH_BYTES = 16 << 20
MAX_ASSET_BYTES = 16 << 20
MAX_PACK_BYTES = 64 << 20

# ------------------------------------------------------------------ table schema
# One token per column, in on-disc order: `name:kind`. A leading `!` marks a column
# that packs cannot set. Kinds: `name` (player/manager name part), `code` (team code),
# `textN` (display text of at most N characters), `abbr` (1-3 of A-Z 0-9), `key` (decimal
# team key), `mgr` (manager reference), or an integer range `lo-hi`, with `?` when the
# column also accepts "-" (none). Ranges: the shipped values, widened only for rating
# scales (0-15, 0-99, 0-100) and for counting stats up to the narrowest bit field that
# holds the shipped data (docs/MODDING.md, appendix A).
_LR_ATTRIB = ("lrattrib_contact:0-100 lrattrib_power:0-100 " +
              " ".join("lrattrib_hit_%s:0-2" % z for z in
                       ("ul", "um", "ur", "cl", "cm", "cr", "ll", "lm", "lr")) + " " +
              " ".join("lrattrib_%s_pct:0-100" % z for z in
                       ("lf", "cf", "rf", "hr", "fb", "ld", "gb")))
_LR_DISC = ("lrattrib_chasefb:0-15 lrattrib_chaseslowbreak:0-15 %s"
            "lrattrib_takefb:0-15 lrattrib_takeslowbreak:0-15 lrattrib_takehardbreak:0-15 "
            "lrattrib_missfb:0-15 lrattrib_missslowbreak:0-15 lrattrib_misshardbreak:0-15")
_LRBAT = ("lrbatstat_1b:0-255 lrbatstat_2b:0-63 lrbatstat_3b:0-15 lrbatstat_hr:0-63 "
          "lrbatstat_rbi:0-127 lrbatstat_so:0-255 lrbatstat_bb:0-127 lrbatstat_ibb:0-31 "
          "lrbatstat_sh:0-31 lrbatstat_sf:0-15 lrbatstat_hbp:0-31 lrbatstat_tpa:0-1023")
_LRPIT = ("lrpitchstat_so:0-255 lrpitchstat_bb:0-127 lrpitchstat_ibb:0-15 lrpitchstat_hbp:0-15 "
          "lrpitchstat_sf:0-15 lrpitchstat_sh:0-15 lrpitchstat_1b:0-255 lrpitchstat_2b:0-63 "
          "lrpitchstat_3b:0-15 lrpitchstat_hr:0-63 lrpitchstat_tpa:0-1023")


def _pitch(n, null):
    q = "?" if null else ""
    return ("pitchattrib_pitch{n}_type:1-14{q} pitchattrib_pitch{n}_movement:0-15{q} "
            "pitchattrib_pitch{n}_description:0-7{q} pitchattrib_pitch{n}_control:0-99{q} "
            "pitchattrib_pitch{n}_velocity:47-101{q}").format(n=n, q=q)


_VS = ("ana oak sea tex cws cle det kc min bal bos nyy tam tor ari col la sdp sfg cub cin "
       "hou mil pit stl atl fla mon nym phi al nl").split()
_STRATEGY = ("pinchhitter pinchrunner pitchersub defensivesub defensivealign takepitch sacbunt "
             "buntforhit pickoff int_walks hitandrun steals advancebases suicidesqueeze").split()
_NAMES = "!first_name:name !last_name:name "

_SCHEMA_TEXT = {
    "attrib": _NAMES + (
        "playerattrib_jerseynum:0-99 playerattrib_bats:0-2 playerattrib_throws:0-1 "
        "playerattrib_primary_position:0-10 playerattrib_secondary_position:0-13 "
        "playerattrib_height:18-35 playerattrib_weight:50-190 playerattrib_boneprofile:25-37 "
        "playerattrib_face:1-915 playerattrib_face2004style:0-1 playerattrib_skin_tone:0-10 "
        "playerattrib_hairstyle:0-9 playerattrib_haircolour:0-6 playerattrib_facialhair:0-7 "
        "playerattrib_bodytype:1-2 playerattrib_audioid:0-2665 playerattrib_photo:1-2 "
        "playerattrib_platediscipline:0-15 playerattrib_bunting:0-15 "
        "playerattrib_stealing_aggressive:0-15 playerattrib_baserunning:0-15 "
        "playerattrib_speed:0-99 playerattrib_fielding:0-15 playerattrib_range:0-15 "
        "playerattrib_throwstrength:0-15 playerattrib_throwaccuracy:0-15 "
        "playerattrib_durability:0-15 playerattrib_battingstance:0-65 playerattrib_swingtype:0-6 "
        "playerattrib_batcolour:0-7 playerattrib_batglove:0-1 playerattrib_wristband:0-6 "
        "playerattrib_elbowguard:0-3 playerattrib_shinguard:0-4 playerattrib_socks:0-2 "
        "playerattrib_catchermask:0-1 playerattrib_fieldglovecolour:0-4 playerattrib_ditty:0-6 "
        "playerattrib_salary:0-255 playerattrib_contract_length:1-7 playerattrib_starpower:0-4 "
        "playerattrib_topprospect:0-1 playerattrib_hidden:0-1 playerattrib_birthday:0-32767"),
    "lhattrib": _NAMES + _LR_ATTRIB + " " + _LR_DISC % "",
    "rhattrib": _NAMES + _LR_ATTRIB + " " + _LR_DISC % "lrattrib_chasehardbreak:0-15 ",
    "bstats": _NAMES + "batstat_g:0-255 batstat_r:0-255 batstat_sb:0-127 batstat_cs:0-31",
    "fbstats": _NAMES + "fieldstat_g:0-255 fieldstat_po:0-2047 fieldstat_a:0-1023 fieldstat_e:0-31",
    "lhbstats": _NAMES + _LRBAT,
    "rhbstats": _NAMES + _LRBAT,
    "career": _NAMES + (
        "batcareerstats_g:0-4095 batcareerstats_ab:0-16383 batcareerstats_h:0-8191 "
        "batcareerstats_hr:0-1023 batcareerstats_rbi:0-4095 batcareerstats_r:0-4095 "
        "batcareerstats_sb:0-1023"),
    "pitcher": _NAMES + (
        "pitchattrib_stamina:0-99 pitchattrib_pickoff:0-15 pitchattrib_fastball_movement:0-0 "
        "pitchattrib_fastball_description:0-0 pitchattrib_fastball_control:0-99 "
        "pitchattrib_fastball_velocity:47-101 " + _pitch(2, False) + " " + _pitch(3, True) + " " +
        _pitch(4, True) + " " + _pitch(5, True) + " pitchattrib_pitcher_delivery:0-58"),
    "pstats": _NAMES + (
        "pitchstat_g:0-127 pitchstat_gs:0-63 pitchstat_r:0-255 pitchstat_er:0-255 pitchstat_w:0-31 "
        "pitchstat_l:0-31 pitchstat_sv:0-63 pitchstat_blsv:0-15 pitchstat_cg:0-15 pitchstat_sho:0-3 "
        "pitchstat_pk:0-31 pitchstat_ip:0-255 pitchstat_pip:0-2"),
    "lhpstats": _NAMES + _LRPIT,
    "rhpstats": _NAMES + _LRPIT,
    "careerp": _NAMES + (
        "pitchcareer_g:0-2047 pitchcareer_ip:0-8191 pitchcareer_pip:0-2 pitchcareer_er:0-4095 "
        "pitchcareer_w:0-511 pitchcareer_l:0-511 pitchcareer_sv:0-511 pitchcareer_so:0-8191 "
        "pitchcareer_bb:0-4095"),
    "team": ("!unique_team:code team_location:text13 team_long_name:text12 team_short_name:abbr "
             "!team_league:0-10 !team_division:0-25 !team_artid:1-126 team_climatezone:0-2 "
             "team_homeintensity:0-2 " + " ".join("team_vs_%s:0-2" % v for v in _VS) + " " +
             " ".join("team_%s:0-2" % s for s in _STRATEGY)),
    "tstat": ("!unique_team:code team_wins_1sthalf:0-127? team_losses_1sthalf:0-127? "
              "team_wins_2ndhalf:0-127? team_losses_2ndhalf:0-127?"),
    "roster": ("!roster_teamid:roster !roster_playerid:roster " +
               " ".join("!%s_roster_%s_position:roster !%s_roster_%s_battingorder:roster"
                        % (h, l, h, l) for h, l in (("rh", "al"), ("rh", "nl"), ("lh", "al"),
                                                    ("lh", "nl")))),
    "org": ("!unique_team:code !org_team_mlb:key !org_team_aaa:key !org_team_aa:key !org_team_a:key "
            "!org_is_franchise:0-1 !org_spring:0-1 org_budget:0-100000 !org_penalty1:0-0 "
            "!org_penalty2:0-0 !org_penalty3:0-0 !org_penalty4:0-0 org_mlb_manager:mgr "
            "org_minors_manager:mgr"),
    "manager": _NAMES + (
        "manager_jerseynum:0-99 manager_audioid:5000-5048 manager_height:72-72 "
        "manager_weight:200-200 manager_boneprofile:27-37 manager_face:1-915 "
        "manager_face2004style:0-1 manager_skintone:0-9 manager_hairstyle:0-3 "
        "manager_haircolour:0-4 manager_facialhair:0-0 manager_bodytype:1-2 manager_hitting:0-100 "
        "manager_baserunning:0-100 manager_fielding:0-100 manager_pitching:0-100 "
        "manager_salary:0-15 manager_reallife:0-1 manager_birthday:0-8191"),
}

# archive order of the 18 tables in database.big (GV4E69 rev 0)
TABLE_ORDER = ("attrib", "lhattrib", "rhattrib", "bstats", "fbstats", "lhbstats", "lhpstats",
               "pstats", "rhbstats", "rhpstats", "pitcher", "team", "tstat", "roster", "career",
               "careerp", "org", "manager")
BATTER_TABLES = ("attrib", "lhattrib", "rhattrib", "bstats", "fbstats", "lhbstats", "rhbstats",
                 "career")
PITCHER_TABLES = ("pitcher", "pstats", "lhpstats", "rhpstats", "careerp")
PLAYER_TABLES = BATTER_TABLES + PITCHER_TABLES


class Column:
    __slots__ = ("name", "kind", "lo", "hi", "null", "editable")

    def __init__(self, token):
        self.editable = not token.startswith("!")
        name, kind = token.lstrip("!").split(":")
        self.name = name
        self.null = kind.endswith("?")
        kind = kind.rstrip("?")
        self.lo = self.hi = None
        m = re.match(r"^(\d+)-(\d+)$", kind)
        if m:
            self.kind = "int"
            self.lo, self.hi = int(m.group(1)), int(m.group(2))
        else:
            self.kind = kind


SCHEMA = {t: [Column(tok) for tok in s.split()] for t, s in _SCHEMA_TEXT.items()}
COLUMNS = {t: {c.name: c for c in cols} for t, cols in SCHEMA.items()}

LINEUPS = ("rh_al", "rh_nl", "lh_al", "lh_nl")     # vs RHP with DH, vs RHP no DH, vs LHP ...
FIELDERS = ("C", "1B", "2B", "3B", "SS", "LF", "CF", "RF")
STARTERS = ("SP1", "SP2", "SP3", "SP4", "SP5")
PITCH_ROLES = STARTERS + ("LR", "MR", "SU", "CP")
ROSTER_CODES = FIELDERS + ("DH",) + PITCH_ROLES + ("B",)
ROLE_LIMITS = {"LR": 3, "MR": 4, "SU": 2}            # ring sizes in fn_8053BB80 (ROSTERS.md)
LEVEL_SIZE = {0: 25, 1: 25, 2: 25, 3: 25, 4: 22, 5: 22, 6: 22, 7: 22, 8: 22, 9: 22, 10: 25}

NAME_PART = re.compile(r"^[A-Za-z][A-Za-z '.\-]*$")
NAME_LIMITS = (14, 13)                              # last, first: the shipped maxima
TEAM_TEXT = re.compile(r"^[A-Za-z0-9][A-Za-z0-9 '.\-/]*$")
ABBR = re.compile(r"^[A-Z0-9]{1,3}$")
LOC_EXTRA = " ©®…™"         # non-ASCII characters the retail LOC files use
LOC_MAX = 400
PACK_ID = re.compile(r"^[a-z0-9]+(-[a-z0-9]+)*$")
SEMVER = re.compile(r"^(0|[1-9]\d*)\.(0|[1-9]\d*)\.(0|[1-9]\d*)$")
API_RE = re.compile(r"^(0|[1-9]\d*)\.(0|[1-9]\d*)$")
REL_PATH = re.compile(r"^[A-Za-z0-9_][A-Za-z0-9._-]*(/[A-Za-z0-9_][A-Za-z0-9._-]*)*$")
GAME_PATH = re.compile(r"^/[A-Za-z0-9_][A-Za-z0-9._-]*(/[A-Za-z0-9_][A-Za-z0-9._-]*)*$")
ENTRY_NAME = re.compile(r"^[A-Za-z0-9_][A-Za-z0-9._-]*$")


# ------------------------------------------------------------------ report
class Report:
    """Issues in the order they were found: (severity, code, where, message)."""

    def __init__(self):
        self.issues = []

    def error(self, code, where, msg):
        self.issues.append(("error", code, where, msg))

    def warn(self, code, where, msg):
        self.issues.append(("warning", code, where, msg))

    @property
    def errors(self):
        return [i for i in self.issues if i[0] == "error"]

    @property
    def ok(self):
        return not self.errors

    def render(self):
        out = ["%s %s %s: %s" % i for i in self.issues]
        out.append("%d error(s), %d warning(s)" % (len(self.errors),
                                                   len(self.issues) - len(self.errors)))
        return "\n".join(out)

    def to_json(self):
        return [{"severity": s, "code": c, "where": w, "message": m} for s, c, w, m in self.issues]


class PackError(Exception):
    """Raised for a problem that stops processing (bad disc, unreadable pack)."""


# ------------------------------------------------------------------ JSON
class _JsonError(ValueError):
    pass


def _pairs(pairs):
    d = {}
    for k, v in pairs:
        if k in d:
            raise _JsonError("duplicate key %r" % k)
        d[k] = v
    return d


def _no_float(s):
    raise _JsonError("non-integer number %s (only integers are allowed)" % s)


def _no_const(s):
    raise _JsonError("%s is not allowed" % s)


def _check_json(v, path="$"):
    if isinstance(v, bool) or v is None:
        return
    if isinstance(v, int):
        if not -(1 << 31) <= v < (1 << 31):
            raise _JsonError("%s: integer %d outside the signed 32-bit range" % (path, v))
    elif isinstance(v, str):
        try:
            v.encode("utf-8")
        except UnicodeEncodeError:
            raise _JsonError("%s: string holds a lone surrogate" % path)
    elif isinstance(v, list):
        for i, x in enumerate(v):
            _check_json(x, "%s[%d]" % (path, i))
    elif isinstance(v, dict):
        for k, x in v.items():
            if not k or any(not (0x20 <= ord(ch) < 0x7F) for ch in k):
                raise _JsonError("%s: object key %r must be printable ASCII" % (path, k))
            _check_json(x, "%s.%s" % (path, k))


def parse_json(data):
    """Strict JSON: UTF-8 (a leading BOM is ignored), no duplicate keys, integers only."""
    if data[:3] == b"\xef\xbb\xbf":
        data = data[3:]
    try:
        text = data.decode("utf-8")
        obj = json.loads(text, object_pairs_hook=_pairs, parse_float=_no_float,
                         parse_constant=_no_const)
    except UnicodeDecodeError as e:
        raise _JsonError("not UTF-8 (%s)" % e.reason)
    except json.JSONDecodeError as e:
        raise _JsonError("line %d column %d: %s" % (e.lineno, e.colno, e.msg))
    _check_json(obj)
    return obj


def canonical_json(obj):
    """Canonical form used for hashing (RFC 8785 for this integer-only, ASCII-key subset)."""
    return json.dumps(obj, sort_keys=True, separators=(",", ":"), ensure_ascii=False,
                      allow_nan=False).encode("utf-8")


def sha256_hex(data):
    return hashlib.sha256(data).hexdigest()


# ------------------------------------------------------------------ versions
def parse_semver(s):
    m = SEMVER.match(s) if isinstance(s, str) else None
    return tuple(int(x) for x in m.groups()) if m else None


def version_matches(req, ver):
    """`^X.Y.Z` (compatible: same leftmost non-zero part, >=) or `X.Y.Z` (exact)."""
    if req.startswith("^"):
        base = parse_semver(req[1:])
        if base is None or ver < base:
            return False
        if base[0]:
            return ver[0] == base[0]
        if base[1]:
            return ver[:2] == base[:2]
        return ver == base
    base = parse_semver(req)
    return base is not None and ver == base


def valid_requirement(req):
    return isinstance(req, str) and parse_semver(req[1:] if req.startswith("^") else req) is not None


# ------------------------------------------------------------------ names and keys
def key_of(text):
    return "%09x" % dbtables.djb2(text)


def check_name(name, report, where, what="player"):
    """'Last,First' -> (last, first) or None (an error is reported)."""
    if not isinstance(name, str):
        report.error("E-NAME", where, "%s name must be a string \"Last,First\"" % what)
        return None
    parts = name.split(",")
    if len(parts) != 2:
        report.error("E-NAME", where, "%s name %r must be \"Last,First\" with one comma" % (what, name))
        return None
    last, first = parts
    for part, lim, label in ((last, NAME_LIMITS[0], "last"), (first, NAME_LIMITS[1], "first")):
        if not NAME_PART.match(part) or part != part.strip() or "  " in part:
            report.error("E-NAME", where, "%s name %r: %s name may use letters, space, ' - . "
                         "and must start with a letter" % (what, name, label))
            return None
        if len(part) > lim:
            report.error("E-NAME", where, "%s name %r: %s name longer than %d characters"
                         % (what, name, label, lim))
            return None
    return last, first


# ------------------------------------------------------------------ pack sources
def _check_rel(path):
    return (isinstance(path, str) and len(path) <= 200 and REL_PATH.match(path)
            and all(seg not in (".", "..") for seg in path.split("/")))


class _DirSource:
    def __init__(self, root):
        self.root = os.path.abspath(root)
        self.label = root

    def _path(self, rel):
        # exact-case check, so a pack that works on Windows also works elsewhere
        cur = self.root
        for seg in rel.split("/"):
            try:
                names = os.listdir(cur)
            except OSError:
                return None
            if seg not in names:
                return None
            cur = os.path.join(cur, seg)
        real = os.path.realpath(cur)
        if os.path.commonpath([real, os.path.realpath(self.root)]) != os.path.realpath(self.root):
            return None
        return cur if os.path.isfile(cur) else None

    def exists(self, rel):
        return self._path(rel) is not None

    def size(self, rel):
        return os.path.getsize(self._path(rel))

    def read(self, rel):
        with open(self._path(rel), "rb") as f:
            return f.read()


class _ZipSource:
    def __init__(self, path):
        self.label = path
        self.zf = zipfile.ZipFile(path)
        infos = {i.filename: i for i in self.zf.infolist() if not i.is_dir()}
        prefix = ""
        if "pack.json" not in infos:
            tops = {n.split("/", 1)[0] for n in infos}
            if len(tops) == 1 and (next(iter(tops)) + "/pack.json") in infos:
                prefix = next(iter(tops)) + "/"
        self.files = {n[len(prefix):]: i for n, i in infos.items() if n.startswith(prefix)}

    def exists(self, rel):
        return rel in self.files

    def size(self, rel):
        return self.files[rel].file_size

    def read(self, rel):
        return self.zf.read(self.files[rel])


# ------------------------------------------------------------------ packs
class Pack:
    def __init__(self, label):
        self.label = label
        self.manifest = None
        self.id = None
        self.version = None
        self.engine_api = None
        self.depends = []          # [(id, requirement)]
        self.patches = []          # [(path, [op, ...])]
        self.assets = []           # [{"path", "entry", "file", "data"}]
        self.digests = {}          # path -> sha256 hex of the file's canonical content
        self.hash = None

    def where(self, path=None, index=None):
        s = self.id or self.label
        if path:
            s += ":" + path
        if index is not None:
            s += ":ops[%d]" % index
        return s


MANIFEST_KEYS = {"id", "name", "version", "game", "engine_api", "description", "authors",
                 "license", "depends", "patches", "assets", "meta"}
REQUIRED_MANIFEST = ("id", "name", "version", "game", "engine_api", "patches")


def load_pack(spec, report):
    """Read and statically validate one pack. Returns a Pack (check report.ok)."""
    pack = Pack(spec)
    if os.path.isdir(spec):
        return _load_pack(pack, _DirSource(spec), report)
    if os.path.isfile(spec) and zipfile.is_zipfile(spec):
        src = _ZipSource(spec)
        try:
            return _load_pack(pack, src, report)
        finally:
            src.zf.close()
    report.error("E-PACK", spec, "not a pack directory or zip file")
    return pack


def _load_pack(pack, src, report):
    spec = pack.label
    if not src.exists("pack.json"):
        report.error("E-PACK", spec, "no pack.json at the top level")
        return pack
    try:
        m = parse_json(src.read("pack.json"))
    except _JsonError as e:
        report.error("E-JSON", pack.where("pack.json"), str(e))
        return pack
    if not isinstance(m, dict):
        report.error("E-MANIFEST", pack.where("pack.json"), "the manifest must be a JSON object")
        return pack
    pack.manifest = m
    w = pack.where("pack.json")
    for k in sorted(set(m) - MANIFEST_KEYS):
        report.error("E-MANIFEST", w, "unknown field %r" % k)
    for k in REQUIRED_MANIFEST:
        if k not in m:
            report.error("E-MANIFEST", w, "missing required field %r" % k)
    if "id" in m:
        if isinstance(m["id"], str) and PACK_ID.match(m["id"]) and 3 <= len(m["id"]) <= 64:
            pack.id = m["id"]
            w = pack.where("pack.json")
        else:
            report.error("E-MANIFEST", w, "id must be 3-64 characters of a-z 0-9 and single hyphens")
    if "name" in m and not (isinstance(m["name"], str) and 1 <= len(m["name"]) <= 100):
        report.error("E-MANIFEST", w, "name must be a string of 1-100 characters")
    if "version" in m:
        pack.version = parse_semver(m["version"])
        if pack.version is None:
            report.error("E-MANIFEST", w, "version must be MAJOR.MINOR.PATCH")
    if "game" in m and m["game"] != GAME_ID:
        report.error("E-GAME", w, "game must be %r, not %r" % (GAME_ID, m["game"]))
    if "engine_api" in m:
        mm = API_RE.match(m["engine_api"]) if isinstance(m["engine_api"], str) else None
        if not mm:
            report.error("E-MANIFEST", w, "engine_api must be MAJOR.MINOR, e.g. \"1.0\"")
        else:
            pack.engine_api = (int(mm.group(1)), int(mm.group(2)))
            if pack.engine_api[0] != API_VERSION[0] or pack.engine_api[1] > API_VERSION[1]:
                report.error("E-ENGINE-API", w, "targets engine API %s; this implementation is %d.%d"
                             % (m["engine_api"], API_VERSION[0], API_VERSION[1]))
    if "description" in m and not (isinstance(m["description"], str) and len(m["description"]) <= 2000):
        report.error("E-MANIFEST", w, "description must be a string of at most 2000 characters")
    if "license" in m and not (isinstance(m["license"], str) and len(m["license"]) <= 100):
        report.error("E-MANIFEST", w, "license must be a short string (an SPDX id)")
    if "authors" in m and not (isinstance(m["authors"], list) and
                               all(isinstance(a, str) and 1 <= len(a) <= 100 for a in m["authors"])):
        report.error("E-MANIFEST", w, "authors must be a list of strings")
    if "meta" in m and not isinstance(m["meta"], dict):
        report.error("E-MANIFEST", w, "meta must be an object")
    for i, d in enumerate(m.get("depends", []) if isinstance(m.get("depends", []), list) else [None]):
        if not (isinstance(d, dict) and set(d) == {"id", "version"} and isinstance(d["id"], str)
                and PACK_ID.match(d["id"]) and valid_requirement(d["version"])):
            report.error("E-MANIFEST", w, "depends[%d] must be {\"id\": <pack id>, \"version\": "
                         "\"^X.Y.Z\" or \"X.Y.Z\"}" % i)
        else:
            pack.depends.append((d["id"], d["version"]))
    total = 0
    files = {}

    def take(rel, what, limit):
        nonlocal total
        if not _check_rel(rel):
            report.error("E-PATH", w, "%s path %r is not a valid relative path" % (what, rel))
            return None
        if rel == "pack.json" or not src.exists(rel):
            report.error("E-PATH", w, "%s file %r not found (paths are case-sensitive)" % (what, rel))
            return None
        if rel in files:
            return files[rel]
        size = src.size(rel)
        total += size
        if size > limit:
            report.error("E-PATH", w, "%s file %r is larger than %d bytes" % (what, rel, limit))
            return None
        files[rel] = src.read(rel)
        return files[rel]

    patches = m.get("patches", [])
    if not isinstance(patches, list) or not all(isinstance(p, str) for p in patches):
        report.error("E-MANIFEST", w, "patches must be a list of file paths")
        patches = []
    if len(set(patches)) != len(patches):
        report.error("E-MANIFEST", w, "a patch file is listed twice")
    for rel in patches:
        data = take(rel, "patch", MAX_PATCH_BYTES)
        if data is None:
            continue
        try:
            obj = parse_json(data)
        except _JsonError as e:
            report.error("E-JSON", pack.where(rel), str(e))
            continue
        if not (isinstance(obj, dict) and set(obj) == {"ops"} and isinstance(obj["ops"], list)):
            report.error("E-OP", pack.where(rel), "a patch file is an object {\"ops\": [...]}")
            continue
        pack.digests[rel] = sha256_hex(canonical_json(obj))
        ops = []
        for i, op in enumerate(obj["ops"]):
            if check_op(op, report, pack.where(rel, i)):
                ops.append((i, op))
        pack.patches.append((rel, ops))
    assets = m.get("assets", [])
    if not isinstance(assets, list):
        report.error("E-MANIFEST", w, "assets must be a list")
        assets = []
    seen = set()
    for i, a in enumerate(assets):
        aw = "%s:assets[%d]" % (pack.where("pack.json"), i)
        if not (isinstance(a, dict) and {"path", "file"} <= set(a) <= {"path", "entry", "file"}):
            report.error("E-ASSET", aw, "an asset is {\"path\", [\"entry\"], \"file\"}")
            continue
        target = check_asset_target(a.get("path"), a.get("entry"), report, aw)
        data = take(a["file"], "asset", MAX_ASSET_BYTES) if isinstance(a["file"], str) else None
        if data is None or target is None:
            if not isinstance(a["file"], str):
                report.error("E-ASSET", aw, "file must be a relative path")
            continue
        if data[:4] in (b"BIGF", b"LOCH"):
            report.error("E-ASSET", aw, "asset files must be authored content, not archives or "
                         "LOC files (replace single entries; use loc.set for text)")
            continue
        if target in seen:
            report.error("E-ASSET", aw, "two assets map to %s" % _target_label(target))
            continue
        seen.add(target)
        pack.digests[a["file"]] = sha256_hex(data)
        pack.assets.append({"target": target, "file": a["file"], "data": data, "where": aw})
    if total > MAX_PACK_BYTES:
        report.error("E-PACK", w, "pack content is larger than %d bytes" % MAX_PACK_BYTES)
    if pack.manifest is not None:
        pack.hash = sha256_hex(PACK_HASH_PREFIX + canonical_json(
            {"manifest": pack.manifest, "files": pack.digests}))
    return pack


def _target_label(t):
    return t[0] + ("" if t[1] is None else " entry " + t[1])


def check_asset_target(path, entry, report, where):
    """Return the canonical target (lowercase path, lowercase entry or None)."""
    if not (isinstance(path, str) and GAME_PATH.match(path)):
        report.error("E-ASSET", where, "path must be an absolute disc path like "
                     "\"/data/frontend/logos.big\"")
        return None
    low = path.lower()
    if not any(low.startswith(r) for r in ASSET_ROOTS):
        report.error("E-ASSET", where, "path %r is outside the v1 asset roots %s"
                     % (path, ", ".join(ASSET_ROOTS)))
        return None
    is_big = low.endswith(".big")
    if is_big and entry is None:
        report.error("E-ASSET", where, "a .big archive is replaced entry by entry: give \"entry\"")
        return None
    if not is_big and entry is not None:
        report.error("E-ASSET", where, "\"entry\" is only valid for .big archives")
        return None
    if entry is not None and not (isinstance(entry, str) and ENTRY_NAME.match(entry)):
        report.error("E-ASSET", where, "entry must be an archive entry name like \"l000.gsh\"")
        return None
    return (low, entry.lower() if entry is not None else None)


# ------------------------------------------------------------------ static op checks
OP_FIELDS = {
    "player.add": ({"op", "player"}, {"pitcher", "set"}),
    "player.edit": ({"op", "player"}, {"pitcher", "set"}),
    "player.remove": ({"op", "player"}, set()),
    "player.rename": ({"op", "player", "to"}, set()),
    "roster.set": ({"op", "team", "entries"}, {"release"}),
    "roster.replace": ({"op", "team", "out", "in"}, {"release"}),
    "roster.swap": ({"op", "a", "b"}, set()),
    "team.edit": ({"op", "team", "set"}, set()),
    "manager.edit": ({"op", "set"}, {"manager", "team"}),
    "manager.rename": ({"op", "to"}, {"manager", "team"}),
    "loc.set": ({"op", "file", "strings"}, set()),
}
SET_GROUPS = {
    "player.add": PLAYER_TABLES,
    "player.edit": PLAYER_TABLES,
    "team.edit": ("team", "tstat", "org"),
    "manager.edit": ("manager",),
}


def check_op(op, report, where):
    """Shape, field and value checks that need no disc. True if the op can be applied."""
    if not isinstance(op, dict) or not isinstance(op.get("op"), str):
        report.error("E-OP", where, "an op is an object with an \"op\" field")
        return False
    kind = op["op"]
    if kind not in OP_FIELDS:
        report.error("E-OP", where, "unknown op %r" % kind)
        return False
    req, opt = OP_FIELDS[kind]
    ok = True
    for k in sorted(req - set(op)):
        report.error("E-OP", where, "%s: missing field %r" % (kind, k))
        ok = False
    for k in sorted(set(op) - req - opt):
        report.error("E-OP", where, "%s: unknown field %r" % (kind, k))
        ok = False
    if not ok:
        return False
    where = "%s (%s)" % (where, kind)
    what = "manager" if kind.startswith("manager.") else "player"
    for k in ("player", "to", "out", "in", "a", "b", "manager"):
        if k in op and check_name(op[k], report, where, what) is None:
            ok = False
    if "pitcher" in op and not isinstance(op["pitcher"], bool):
        report.error("E-OP", where, "pitcher must be true or false")
        ok = False
    if "release" in op and op["release"] not in ("keep", "remove"):
        report.error("E-OP", where, "release must be \"keep\" or \"remove\"")
        ok = False
    if "team" in op and not (isinstance(op["team"], str) and re.match(r"^[A-Za-z0-9]{1,3}$", op["team"])):
        report.error("E-OP", where, "team must be a unique_team code such as \"Ana\"")
        ok = False
    if kind.startswith("manager.") and ("manager" in op) == ("team" in op):
        report.error("E-OP", where, "give either \"manager\" (a name) or \"team\" (the club "
                     "whose MLB manager is meant)")
        ok = False
    if kind == "player.edit" and "set" not in op and "pitcher" not in op:
        report.error("E-OP", where, "player.edit needs \"set\" or \"pitcher\"")
        ok = False
    if "set" in op:
        ok = check_set(op, report, where) and ok
    if kind == "roster.set":
        ok = check_entries(op["entries"], report, where) is not None and ok
    if kind == "loc.set":
        ok = check_loc(op, report, where) and ok
    return ok


def check_set(op, report, where):
    groups = op["set"]
    allowed = SET_GROUPS[op["op"]]
    if not isinstance(groups, dict):
        report.error("E-OP", where, "set must be an object {table: {column: value}}")
        return False
    ok = True
    for table, fields in groups.items():
        if table not in allowed:
            report.error("E-FIELD", where, "table %r cannot be set by %s (allowed: %s)"
                         % (table, op["op"], ", ".join(allowed)))
            ok = False
            continue
        if op["op"] == "player.add" and table in PITCHER_TABLES and not op.get("pitcher"):
            report.error("E-OP", where, "set.%s needs \"pitcher\": true" % table)
            ok = False
        if not isinstance(fields, dict):
            report.error("E-OP", where, "set.%s must be an object {column: value}" % table)
            ok = False
            continue
        for name, value in fields.items():
            col = COLUMNS[table].get(name)
            if col is None:
                report.error("E-FIELD", where, "%s has no column %r" % (table, name))
                ok = False
            elif not col.editable:
                hint = " (use player.rename / manager.rename)" if col.kind == "name" else ""
                report.error("E-FIELD", where, "%s.%s cannot be set by a pack%s" % (table, name, hint))
                ok = False
            elif not check_value(col, value, report, "%s set.%s.%s" % (where, table, name)):
                ok = False
    return ok


def check_value(col, v, report, where):
    if col.kind == "int":
        if col.null and v == "-":
            return True
        if isinstance(v, bool) or not isinstance(v, int):
            report.error("E-VALUE", where, "must be an integer%s" % (" or \"-\"" if col.null else ""))
            return False
        if not col.lo <= v <= col.hi:
            report.error("E-VALUE", where, "%d is outside %d-%d" % (v, col.lo, col.hi))
            return False
        return True
    if col.kind.startswith("text"):
        lim = int(col.kind[4:])
        if not (isinstance(v, str) and TEAM_TEXT.match(v) and v == v.strip() and len(v) <= lim):
            report.error("E-VALUE", where, "must be 1-%d characters of A-Z a-z 0-9 space ' . - / "
                         "starting with a letter or digit" % lim)
            return False
        return True
    if col.kind == "abbr":
        if not (isinstance(v, str) and ABBR.match(v)):
            report.error("E-VALUE", where, "must be 1-3 characters of A-Z 0-9")
            return False
        return True
    if col.kind == "mgr":
        return check_name(v, report, where, "manager") is not None
    report.error("E-FIELD", where, "column cannot be set")
    return False


def parse_slot(text):
    """'C:8' -> ('C', '8'); 'B' -> ('B', '-1'); None if malformed."""
    if not isinstance(text, str):
        return None
    m = re.match(r"^([A-Z0-9]+)(?::([1-9]))?$", text)
    if not m or m.group(1) not in ROSTER_CODES:
        return None
    return m.group(1), m.group(2) or "-1"


def check_entries(entries, report, where):
    """roster.set entries -> [[name, c0, o0, c1, o1, c2, o2, c3, o3]] or None."""
    if not isinstance(entries, list) or not entries:
        report.error("E-ROSTER", where, "entries must be a non-empty list")
        return None
    out = []
    ok = True
    for i, e in enumerate(entries):
        ew = "%s entries[%d]" % (where, i)
        if not (isinstance(e, dict) and "player" in e and set(e) <= {"player", "pos"} | set(LINEUPS)):
            report.error("E-ROSTER", ew, "an entry is {\"player\", \"pos\", \"rh_al\", \"rh_nl\", "
                         "\"lh_al\", \"lh_nl\"}")
            ok = False
            continue
        if check_name(e["player"], report, ew) is None:
            ok = False
            continue
        row = [e["player"]]
        for ln in LINEUPS:
            text = e.get(ln, e.get("pos"))
            if text is None:
                report.error("E-ROSTER", ew, "no position for lineup %s (give \"pos\" or \"%s\")"
                             % (ln, ln))
                ok = False
                break
            slot = parse_slot(text)
            if slot is None:
                report.error("E-ROSTER", ew, "%s: %r is not CODE or CODE:N (codes %s; N 1-9)"
                             % (ln, text, " ".join(ROSTER_CODES)))
                ok = False
                break
            row += slot
        else:
            out.append(row)
    return out if ok else None


def check_loc(op, report, where):
    ok = True
    if not (isinstance(op["file"], str) and op["file"].upper() in [f.upper() for f in LOC_FILES]):
        report.error("E-LOC", where, "file must be one of %s" % ", ".join(LOC_FILES))
        ok = False
    s = op["strings"]
    if not isinstance(s, dict) or not s:
        report.error("E-LOC", where, "strings must be a non-empty object {\"<id>\": \"text\"}")
        return False
    for k, v in s.items():
        if not re.match(r"^(0|[1-9]\d{0,4})$", k) or int(k) > 65535:
            report.error("E-LOC", where, "string id %r must be a decimal number 0-65535" % k)
            ok = False
        if not isinstance(v, str) or len(v) > LOC_MAX or any(
                not (0x20 <= ord(c) < 0x7F or c in LOC_EXTRA) for c in v):
            report.error("E-LOC", where, "string %s: text must be at most %d characters of printable "
                         "ASCII (plus %s)" % (k, LOC_MAX, " ".join("U+%04X" % ord(c) for c in LOC_EXTRA)))
            ok = False
    return ok


# ------------------------------------------------------------------ composition
def check_set_order(packs, report):
    """Ids unique; dependencies present earlier with a matching version. Returns
    {pack id: set of ids it depends on, transitively}."""
    deps = {}
    seen = {}
    for p in packs:
        if p.id is None:
            continue
        if p.id in seen:
            report.error("E-DUPLICATE", p.where(), "pack id %r appears twice in the set" % p.id)
            continue
        closure = set()
        for did, req in p.depends:
            if did == p.id:
                report.error("E-DEPENDENCY", p.where(), "a pack cannot depend on itself")
            elif did not in seen:
                later = any(q.id == did for q in packs)
                report.error("E-DEPENDENCY", p.where(), "depends on %r, which %s" % (
                    did, "must come earlier in the set" if later else "is not in the set"))
            elif not version_matches(req, seen[did].version or (0, 0, 0)):
                report.error("E-DEPENDENCY", p.where(), "depends on %s %s, the set has %s" % (
                    did, req, ".".join(map(str, seen[did].version))))
            else:
                closure.add(did)
                closure |= deps[did]
        deps[p.id] = closure
        seen[p.id] = p
    return deps


def set_hash(packs):
    return sha256_hex(SET_HASH_PREFIX + canonical_json(
        {"packs": [{"id": p.id, "version": p.manifest["version"], "hash": p.hash} for p in packs]}))


# ------------------------------------------------------------------ disc access
class Disc:
    """The player's disc: an ISO/CISO image, or a directory holding an extracted disc."""

    def __init__(self, spec):
        self.spec = spec
        if os.path.isdir(spec):
            self.root = spec
            self.image = None
        elif os.path.isfile(spec):
            self.root = None
            self.image = big._open_disc(spec)
            self._files = {p.lower(): (off, size) for p, off, size in self.image.files}
        else:
            raise PackError("disc %r not found" % spec)

    def _dir_path(self, path):
        cur = self.root
        for seg in path.strip("/").split("/"):
            try:
                names = {n.lower(): n for n in os.listdir(cur)}
            except OSError:
                return None
            if seg.lower() not in names:
                return None
            cur = os.path.join(cur, names[seg.lower()])
        return cur if os.path.isfile(cur) else None

    def exists(self, path):
        if self.root is not None:
            return self._dir_path(path) is not None
        return path.lower() in self._files

    def read(self, path):
        if self.root is not None:
            p = self._dir_path(path)
            if p is None:
                raise PackError("%s not found in %s" % (path, self.spec))
            with open(p, "rb") as f:
                return f.read()
        if path.lower() not in self._files:
            raise PackError("%s not found on %s" % (path, self.spec))
        off, size = self._files[path.lower()]
        return self.image.d.read(off, size)


# ------------------------------------------------------------------ game data model
class Player:
    __slots__ = ("key", "name", "vals")

    def __init__(self, key, name, vals):
        self.key, self.name, self.vals = key, name, vals     # vals: table -> [v0, v1, ...]

    @property
    def pitcher(self):
        return "pitcher" in self.vals


class Model:
    """The tables of database.big and the LOC files, as records keyed by stable keys."""

    def __init__(self, db, locs):
        self.db = db
        self.locs = locs                       # file name (disc spelling) -> loc.Loc
        self.loc_orig = {f: dict(l.entries) for f, l in locs.items()}
        t = db.tables
        for name in TABLE_ORDER:
            if name not in t:
                raise PackError("database.big has no %s table" % name)
            want = [c.name for c in SCHEMA[name]]
            if t[name].fields != want:
                raise PackError("%s columns differ from format v1 (not GV4E69 rev 0?)" % name)
        att = t["attrib"]
        self.order = [r[0] for r in att.rows]
        self.players = {}
        for r in att.rows:
            self.players[r[0]] = Player(r[0], "%s,%s" % (r[2], r[1]), {"attrib": r[1:]})
        for name in BATTER_TABLES[1:]:
            if [r[0] for r in t[name].rows] != self.order:
                raise PackError("%s rows are not in attrib order" % name)
            for r in t[name].rows:
                self.players[r[0]].vals[name] = r[1:]
        pk = [r[0] for r in t["pitcher"].rows]
        if pk != [k for k in self.order if k in set(pk)]:
            raise PackError("pitcher rows are not a subsequence of attrib")
        for name in PITCHER_TABLES:
            if [r[0] for r in t[name].rows] != pk:
                raise PackError("%s rows are not in pitcher order" % name)
            for r in t[name].rows:
                self.players[r[0]].vals[name] = r[1:]
        for p in self.players.values():
            if key_of(p.name) != p.key:
                raise PackError("player key %s does not match its name" % p.key)
        self.default_key = key_of(DEFAULT_NAME)
        # teams: fixed rows; tstat and org follow the team keys
        self.teams = [r[1:] for r in t["team"].rows]
        self.team_keys = [r[0] for r in t["team"].rows]
        self.code_index = {r[0]: i for i, r in enumerate(self.teams)}
        if any(key_of(r[0]) != k for r, k in zip(self.teams, self.team_keys)):
            raise PackError("team key does not match unique_team")
        self.tstat = {r[0]: r[1:] for r in t["tstat"].rows}
        self.org = {r[0]: r[1:] for r in t["org"].rows}
        self.managers = {r[0]: r[1:] for r in t["manager"].rows}
        self.manager_order = [r[0] for r in t["manager"].rows]
        by_team_key = {k: self.teams[i][0] for i, k in enumerate(self.team_keys)}
        self.rosters = {r[0]: [] for r in self.teams}
        for r in t["roster"].rows:
            code = by_team_key.get(r[1])
            if code is None:
                raise PackError("roster row %s names an unknown team key %s" % (r[0], r[1]))
            self.rosters[code].append([r[2]] + r[3:])
        self.start_players = len(self.players)
        self.start_pitchers = sum(1 for p in self.players.values() if p.pitcher)

    # ---- lookups
    def player(self, name):
        p = self.players.get(key_of(name))
        return p if p is not None and p.name == name else None

    def team_row(self, code):
        i = self.code_index.get(code)
        return None if i is None else self.teams[i]

    def team_league(self, code):
        return int(self.teams[self.code_index[code]][COL_INDEX["team"]["team_league"]])

    def manager_key(self, name):
        k = key_of(name)
        r = self.managers.get(k)
        return k if r is not None and "%s,%s" % (r[1], r[0]) == name else None

    def homes(self):
        """player key -> list of team codes whose roster lists him."""
        out = {}
        for code, entries in self.rosters.items():
            for e in entries:
                out.setdefault(e[0], []).append(code)
        return out

    # ---- serialization
    def tables(self):
        """The 18 tables, rebuilt from the model in canonical order."""
        old = self.db.tables
        new = {}
        for name in PLAYER_TABLES:
            rows = [[k] + self.players[k].vals[name] for k in self.order
                    if name in self.players[k].vals]
            new[name] = dbtables.Table(name, old[name].fields, rows)
        new["team"] = dbtables.Table("team", old["team"].fields,
                                     [[k] + r for k, r in zip(self.team_keys, self.teams)])
        new["tstat"] = dbtables.Table("tstat", old["tstat"].fields,
                                      [[r[0]] + self.tstat[r[0]] for r in old["tstat"].rows])
        new["org"] = dbtables.Table("org", old["org"].fields,
                                    [[r[0]] + self.org[r[0]] for r in old["org"].rows])
        new["manager"] = dbtables.Table("manager", old["manager"].fields,
                                        [[k] + self.managers[k] for k in self.manager_order])
        rows = []
        for i, r in enumerate(self.teams):
            for e in self.rosters[r[0]]:
                rows.append(["%09x" % len(rows), self.team_keys[i]] + list(e))
        new["roster"] = dbtables.Table("roster", old["roster"].fields, rows)
        return new


COL_INDEX = {t: {c.name: i for i, c in enumerate(cols)} for t, cols in SCHEMA.items()}


def load_model(disc):
    try:
        arc = big.BigArchive.from_bytes(disc.read(DATABASE_PATH))
        db = dbtables.Database(arc)
        locs = {}
        for f in LOC_FILES:
            locs[f] = loc.Loc.parse(disc.read("/data/" + f))
    except (big.BigError, dbtables.TableError, loc.LocError, refpack.RefPackError) as e:
        raise PackError("cannot read the disc tables: %s" % e)
    return Model(db, locs)


# ------------------------------------------------------------------ applying ops
class Applier:
    """Applies the ops of an ordered pack set to a Model, tracking which pack wrote
    each cell so that conflicts between packs are reported (MODDING.md section 8)."""

    def __init__(self, model, report, deps):
        self.m = model
        self.r = report
        self.deps = deps
        self.writer = {}          # cell -> pack id that last wrote it
        self.touched = {}         # entity -> {pack ids that wrote any of its cells}
        self.pack = None
        self.where = None
        self.org_set = set()      # (code, column) set by packs (manager refs to check)

    # ---- conflict tracking
    def _foreign(self, pid):
        return pid is not None and pid != self.pack.id and pid not in self.deps.get(self.pack.id, ())

    def write(self, cell, entity):
        w = self.writer.get(cell)
        if self._foreign(w):
            self.r.error("E-CONFLICT", self.where, "%s was already changed by pack %r; declare a "
                         "dependency on it to build on it" % (_cell_label(cell), w))
            return False
        self.writer[cell] = self.pack.id
        self.touched.setdefault(entity, set()).add(self.pack.id)
        return True

    def use(self, entity):
        """Reading an entity another pack created or renamed needs a dependency on it."""
        w = self.writer.get(entity)
        if self._foreign(w):
            self.r.error("E-CONFLICT", self.where, "%s comes from pack %r; declare a dependency "
                         "on it" % (_cell_label(entity), w))
            return False
        return True

    def whole(self, entity):
        """Removing or renaming touches every cell of the entity."""
        bad = sorted(p for p in self.touched.get(entity, ()) if self._foreign(p))
        if bad:
            self.r.error("E-CONFLICT", self.where, "%s was changed by pack(s) %s; declare a "
                         "dependency to remove or rename it" % (_cell_label(entity), ", ".join(bad)))
            return False
        self.writer[entity] = self.pack.id
        self.touched.setdefault(entity, set()).add(self.pack.id)
        return True

    # ---- driver
    def run(self, packs):
        for pack in packs:
            self.pack = pack
            for path, ops in pack.patches:
                for i, op in ops:
                    self.where = "%s (%s)" % (pack.where(path, i), op["op"])
                    getattr(self, "op_" + op["op"].replace(".", "_"))(op)
            for a in pack.assets:
                self.where = a["where"]
                self.write(("A",) + a["target"], ("A",) + a["target"])

    # ---- helpers
    def _get_player(self, name, what="player"):
        if name == DEFAULT_NAME:
            self.r.error("E-PROTECTED", self.where, "the Default,Default row cannot be changed")
            return None
        p = self.m.player(name)
        if p is None:
            self.r.error("E-NOT-FOUND", self.where, "no %s %r" % (what, name))
            return None
        if not self.use(("P", p.key)):
            return None
        return p

    def _new_key(self, name):
        k = key_of(name)
        p = self.m.players.get(k)
        if p is not None:
            if p.name == name:
                self.r.error("E-KEY-EXISTS", self.where, "player %r already exists" % name)
            else:
                self.r.error("E-KEY-EXISTS", self.where, "%r has the same key %s as %r (djb2 "
                             "collision); choose another spelling" % (name, k, p.name))
            return None
        return k

    def _default(self, table):
        return list(self.m.players[self.m.default_key].vals[table])

    def _set_fields(self, p, groups):
        for table, fields in groups.items():
            if table not in p.vals:
                self.r.error("E-OP", self.where, "%s is not a pitcher; set \"pitcher\": true first"
                             % p.name if table in PITCHER_TABLES else "%s has no %s row" % (p.name, table))
                continue
            for col, v in fields.items():
                if self.write(("P", p.key, table, col), ("P", p.key)):
                    p.vals[table][COL_INDEX[table][col]] = dbtables._to_text(v)

    def _make_pitcher(self, p, flag):
        if flag == p.pitcher:
            return
        if not self.write(("P", p.key, "pitcher"), ("P", p.key)):
            return
        if flag:
            first, last = p.vals["attrib"][0], p.vals["attrib"][1]
            for t in PITCHER_TABLES:
                p.vals[t] = [first, last] + self._default(t)[2:]
        else:
            for t in PITCHER_TABLES:
                p.vals.pop(t)

    # ---- player ops
    def op_player_add(self, op):
        last, first = op["player"].split(",")
        k = self._new_key(op["player"])
        if k is None or not self.whole(("P", k)):
            return
        vals = {}
        for t in BATTER_TABLES + (PITCHER_TABLES if op.get("pitcher") else ()):
            vals[t] = [first, last] + self._default(t)[2:]
        p = Player(k, op["player"], vals)
        self.m.players[k] = p
        self.m.order.append(k)
        self._set_fields(p, op.get("set", {}))

    def op_player_edit(self, op):
        p = self._get_player(op["player"])
        if p is None:
            return
        if "pitcher" in op:
            self._make_pitcher(p, op["pitcher"])
        self._set_fields(p, op.get("set", {}))

    def op_player_remove(self, op):
        p = self._get_player(op["player"])
        if p is None:
            return
        on = self.m.homes().get(p.key)
        if on:
            self.r.error("E-ROSTER", self.where, "%s is still on the roster of %s; replace him there "
                         "first (roster.replace with \"release\": \"remove\")" % (p.name, ", ".join(on)))
            return
        if self.whole(("P", p.key)):
            self._drop(p)

    def _drop(self, p):
        del self.m.players[p.key]
        self.m.order.remove(p.key)

    def op_player_rename(self, op):
        p = self._get_player(op["player"])
        if p is None:
            return
        k = self._new_key(op["to"])
        if k is None or not self.whole(("P", p.key)) or not self.whole(("P", k)):
            return
        last, first = op["to"].split(",")
        old = p.key
        for t in p.vals:
            p.vals[t][0], p.vals[t][1] = first, last
        p.key, p.name = k, op["to"]
        del self.m.players[old]
        self.m.players[k] = p
        self.m.order[self.m.order.index(old)] = k
        for entries in self.m.rosters.values():
            for e in entries:
                if e[0] == old:
                    e[0] = k
        self.touched[("P", k)] = self.touched.pop(("P", old), set()) | {self.pack.id}
        for cell in [c for c in self.writer if c[:2] == ("P", old)]:
            self.writer[("P", k) + cell[2:]] = self.writer.pop(cell)
        self.writer[("P", k)] = self.pack.id

    # ---- roster ops
    def _team(self, code):
        if self.m.team_row(code) is None:
            self.r.error("E-NOT-FOUND", self.where, "no team with unique_team %r" % code)
            return False
        return True

    def _release(self, players, mode):
        if mode != "remove":
            return
        homes = self.m.homes()
        for k in players:
            p = self.m.players.get(k)
            if p is None or k == self.m.default_key or homes.get(k):
                continue
            if self.whole(("P", k)):
                self._drop(p)

    def op_roster_set(self, op):
        code = op["team"]
        if not self._team(code):
            return
        rows = check_entries(op["entries"], Report(), "")
        new = []
        for row in rows:
            p = self._get_player(row[0])
            if p is None:
                return
            new.append([p.key] + row[1:])
        if not self.write(("R", code), ("R", code)):
            return
        before = [e[0] for e in self.m.rosters[code]]
        self.m.rosters[code] = new
        self._release(before, op.get("release", "keep"))

    def op_roster_replace(self, op):
        code = op["team"]
        if not self._team(code):
            return
        out = self._get_player(op["out"])
        new = self._get_player(op["in"])
        if out is None or new is None:
            return
        entries = self.m.rosters[code]
        hit = [e for e in entries if e[0] == out.key]
        if not hit:
            self.r.error("E-ROSTER", self.where, "%s is not on the roster of %s" % (out.name, code))
            return
        if any(e[0] == new.key for e in entries):
            self.r.error("E-ROSTER", self.where, "%s is already on the roster of %s" % (new.name, code))
            return
        if self.write(("R", code), ("R", code)):
            hit[0][0] = new.key
            self._release([out.key], op.get("release", "keep"))

    def op_roster_swap(self, op):
        a = self._get_player(op["a"])
        b = self._get_player(op["b"])
        if a is None or b is None:
            return
        if a.key == b.key:
            self.r.error("E-ROSTER", self.where, "a player cannot be swapped with himself")
            return
        homes = self.m.homes()
        ha = [c for c in homes.get(a.key, []) if c not in ALLSTAR_TEAMS]
        hb = [c for c in homes.get(b.key, []) if c not in ALLSTAR_TEAMS]
        if len(ha) != 1 or len(hb) != 1:
            self.r.error("E-ROSTER", self.where, "roster.swap needs both players on exactly one "
                         "team other than the All-Star sides")
            return
        if not (self.write(("R", ha[0]), ("R", ha[0])) and self.write(("R", hb[0]), ("R", hb[0]))):
            return
        ea = next(e for e in self.m.rosters[ha[0]] if e[0] == a.key)
        eb = next(e for e in self.m.rosters[hb[0]] if e[0] == b.key)
        if ha[0] == hb[0]:
            ea[1:], eb[1:] = eb[1:], ea[1:]          # same team: exchange depth-chart slots
        else:
            ea[0], eb[0] = b.key, a.key              # trade: each takes the other's slot

    # ---- teams, managers, text
    def op_team_edit(self, op):
        code = op["team"]
        if not self._team(code):
            return
        key = key_of(code)
        for table, fields in op["set"].items():
            if table == "team":
                row = self.m.team_row(code)
            elif table == "tstat":
                row = self.m.tstat.get(key)
            else:
                row = self.m.org.get(key)
            if row is None:
                self.r.error("E-NOT-FOUND", self.where, "team %s has no %s row" % (code, table))
                continue
            for col, v in fields.items():
                if table == "org" and col in ("org_mlb_manager", "org_minors_manager"):
                    mk = self.m.manager_key(v)
                    if mk is None:
                        self.r.error("E-NOT-FOUND", self.where, "no manager %r" % v)
                        continue
                    if not self.use(("M", mk)):
                        continue
                    v = str(int(mk, 16) - (1 << 32) if int(mk, 16) >= (1 << 31) else int(mk, 16))
                if self.write(("T", code, table, col), ("T", code)):
                    row[COL_INDEX[table][col]] = dbtables._to_text(v)

    def _get_manager(self, op):
        if "team" in op:
            row = self.m.org.get(key_of(op["team"]))
            if row is None:
                self.r.error("E-NOT-FOUND", self.where, "team %r has no org row (no manager)"
                             % op["team"])
                return None
            k = "%09x" % (int(row[COL_INDEX["org"]["org_mlb_manager"]]) & 0xFFFFFFFF)
            if k not in self.m.managers:
                self.r.error("E-NOT-FOUND", self.where, "the manager of %s is not in the manager "
                             "table" % op["team"])
                return None
        else:
            k = self.m.manager_key(op["manager"])
            if k is None:
                self.r.error("E-NOT-FOUND", self.where, "no manager %r" % op["manager"])
                return None
        if k == key_of(DEFAULT_NAME):
            self.r.error("E-PROTECTED", self.where, "the Default,Default manager cannot be changed")
            return None
        return k if self.use(("M", k)) else None

    def op_manager_edit(self, op):
        k = self._get_manager(op)
        if k is None:
            return
        for col, v in op["set"]["manager"].items():
            if self.write(("M", k, col), ("M", k)):
                self.m.managers[k][COL_INDEX["manager"][col]] = dbtables._to_text(v)

    def op_manager_rename(self, op):
        k = self._get_manager(op)
        if k is None:
            return
        nk = key_of(op["to"])
        if nk in self.m.managers:
            self.r.error("E-KEY-EXISTS", self.where, "manager key %s of %r is taken" % (nk, op["to"]))
            return
        if not (self.whole(("M", k)) and self.whole(("M", nk))):
            return
        last, first = op["to"].split(",")
        row = self.m.managers.pop(k)
        row[0], row[1] = first, last
        self.m.managers[nk] = row
        self.m.manager_order[self.m.manager_order.index(k)] = nk
        old_s, new_s = (str(int(x, 16) - (1 << 32) if int(x, 16) >= (1 << 31) else int(x, 16))
                        for x in (k, nk))
        for r in self.m.org.values():
            for c in ("org_mlb_manager", "org_minors_manager"):
                i = COL_INDEX["org"][c]
                if r[i] == old_s:
                    r[i] = new_s
        self.touched[("M", nk)] = self.touched.pop(("M", k), set()) | {self.pack.id}
        for cell in [c for c in self.writer if c[:2] == ("M", k)]:
            self.writer[("M", nk) + cell[2:]] = self.writer.pop(cell)
        self.writer[("M", nk)] = self.pack.id

    def op_loc_set(self, op):
        f = next(x for x in LOC_FILES if x.upper() == op["file"].upper())
        L = self.m.locs[f]
        index = {sid: i for i, (sid, _) in enumerate(L.entries)}
        for k, text in op["strings"].items():
            sid = int(k)
            if sid not in index:
                self.r.error("E-NOT-FOUND", self.where, "%s has no string id %d" % (f, sid))
                continue
            if self.write(("L", f.upper(), sid), ("L", f.upper(), sid)):
                L.entries[index[sid]] = (sid, text)
                orig = self.m.loc_orig[f][sid]
                if len(text) > len(orig):
                    self.r.warn("W-LOC-LENGTH", self.where, "%s string %d is longer than the "
                                "original (%d > %d characters); it may not fit its box"
                                % (f, sid, len(text), len(orig)))


def _cell_label(cell):
    kind = cell[0]
    if kind == "P":
        return "player %s%s" % (cell[1], "" if len(cell) == 2 else " " + ".".join(map(str, cell[2:])))
    if kind == "R":
        return "the roster of %s" % cell[1]
    if kind == "T":
        return "team %s%s" % (cell[1], "" if len(cell) == 2 else " " + ".".join(cell[2:]))
    if kind == "M":
        return "manager %s%s" % (cell[1], "" if len(cell) == 2 else " " + cell[2])
    if kind == "L":
        return "%s string %d" % (cell[1], cell[2])
    return "asset %s" % _target_label(cell[1:])


# ------------------------------------------------------------------ final validation
def validate_model(m, report, where="result"):
    """Rules on the final state (MODDING.md section 7.3)."""
    n_players = len(m.players)
    n_pitchers = sum(1 for p in m.players.values() if p.pitcher)
    if n_players > LIMITS["players"]:
        report.error("E-CAPACITY", where, "%d players; the game holds at most %d (Default row included)"
                     % (n_players, LIMITS["players"]))
    if n_pitchers > LIMITS["pitchers"]:
        report.error("E-CAPACITY", where, "%d pitchers; the game holds at most %d"
                     % (n_pitchers, LIMITS["pitchers"]))
    if len(m.managers) > LIMITS["managers"]:
        report.error("E-CAPACITY", where, "%d managers; the game holds at most %d"
                     % (len(m.managers), LIMITS["managers"]))
    for label, now, start, cap in (("player", n_players, m.start_players, LIMITS["players"]),
                                   ("pitcher", n_pitchers, m.start_pitchers, LIMITS["pitchers"])):
        if now > start and now <= cap:
            report.warn("W-FREE-SLOTS", where, "%d free %s slots remain (the disc leaves %d); "
                        "dynasty drafts and created players need free slots"
                        % (cap - now, label, cap - start))
    # values
    for k in m.order:
        p = m.players[k]
        for t, vals in p.vals.items():
            _check_row(t, vals, report, "%s player %s %s" % (where, p.name, t))
        pos = int(p.vals["attrib"][COL_INDEX["attrib"]["playerattrib_primary_position"]])
        if pos in (0, 10) and not p.pitcher and k != m.default_key:
            report.error("E-PITCHER", where, "player %s has primary position %s but no pitcher "
                         "rows (\"pitcher\": true)" % (p.name, "SP" if pos == 0 else "RP"))
        if p.pitcher:
            vals = p.vals["pitcher"]
            present = []
            for n in (3, 4, 5):
                cols = [vals[COL_INDEX["pitcher"]["pitchattrib_pitch%d_%s" % (n, s)]]
                        for s in ("type", "movement", "description", "control", "velocity")]
                none = [c == "-" for c in cols]
                if any(none) and not all(none):
                    report.error("E-VALUE", where, "player %s pitch %d: set all five fields or "
                                 "all to \"-\"" % (p.name, n))
                present.append(not any(none))
            if present in ([False, True, False], [False, True, True], [False, False, True],
                           [True, False, True]):
                report.error("E-VALUE", where, "player %s: pitches 3-5 must be filled in order"
                             % p.name)
    for i, r in enumerate(m.teams):
        _check_row("team", r, report, "%s team %s" % (where, r[0]))
        _check_row("tstat", m.tstat[m.team_keys[i]], report, "%s team %s tstat" % (where, r[0]))
    for k in m.manager_order:
        _check_row("manager", m.managers[k], report, "%s manager %s" % (where, k))
    # rosters
    homes = {}
    pitchers = {k for k, p in m.players.items() if p.pitcher}
    for code, entries in m.rosters.items():
        validate_roster(m, code, entries, pitchers, report, where)
        for e in entries:
            homes.setdefault(e[0], []).append(code)
    for k in m.order:
        on = homes.get(k, [])
        name = m.players[k].name
        if k == m.default_key:
            if on:
                report.error("E-PROTECTED", where, "Default,Default must not be on a roster")
            continue
        clubs = [c for c in on if c not in ALLSTAR_TEAMS]
        if not on:
            report.error("E-ROSTER-HOME", where, "player %s is on no roster (give him a team, or "
                         "release him with \"remove\")" % name)
        elif len(clubs) > 1:
            report.error("E-ROSTER-HOME", where, "player %s is on %s; a player belongs to one team "
                         "(plus an All-Star side)" % (name, ", ".join(clubs)))
        elif not clubs:
            report.warn("W-ALLSTAR-ONLY", where, "player %s is only on the All-Star roster %s"
                        % (name, on[0]))


def _check_row(table, vals, report, where):
    for c, v in zip(SCHEMA[table], vals):
        if c.kind != "int":
            continue
        if v == "-" and c.null:
            continue
        n = dbtables._canon_int(v)
        if n is None or not c.lo <= n <= c.hi:
            report.error("E-VALUE", where, "%s = %r is outside %d-%d" % (c.name, v, c.lo, c.hi))


def validate_roster(m, code, entries, pitchers, report, where):
    w = "%s roster %s" % (where, code)
    want = LEVEL_SIZE.get(m.team_league(code))
    if want is not None and len(entries) != want:
        report.error("E-ROSTER", w, "%d players; a team of league %d has exactly %d"
                     % (len(entries), m.team_league(code), want))
    if len(entries) > 25:
        report.error("E-ROSTER", w, "more than 25 players (the game keeps 25 per team)")
    seen = set()
    for e in entries:
        if e[0] in seen:
            report.error("E-ROSTER", w, "player %s is listed twice" % _pname(m, e[0]))
        seen.add(e[0])
        if e[0] not in m.players:
            report.error("E-ROSTER", w, "player key %s does not exist" % e[0])
            continue
        codes = e[1::2]
        roles = [c for c in codes if c in PITCH_ROLES]
        if roles and (len(roles) != 4 or len(set(codes)) != 1):
            report.error("E-ROSTER", w, "%s: a pitching role must be the same in all four lineups "
                         "(the game reads it from rh_al)" % _pname(m, e[0]))
        if roles and e[0] not in pitchers:
            report.error("E-ROSTER", w, "%s has the pitching role %s but is not a pitcher"
                         % (_pname(m, e[0]), roles[0]))
        if not roles and e[0] in pitchers:
            report.warn("W-PITCHER-BENCH", w, "pitcher %s has no pitching role" % _pname(m, e[0]))
    for li, ln in enumerate(LINEUPS):
        codes = [e[1 + 2 * li] for e in entries]
        orders = [e[2 + 2 * li] for e in entries]
        dh = ln.endswith("_al")
        need = list(FIELDERS) + list(STARTERS) + ["CP"] + (["DH"] if dh else [])
        for c in need:
            n = codes.count(c)
            if n != 1:
                report.error("E-ROSTER", w, "lineup %s has %d at %s (needs exactly 1)" % (ln, n, c))
        if not dh and "DH" in codes:
            report.error("E-ROSTER", w, "lineup %s has no designated hitter; DH is not allowed" % ln)
        for c, lim in ROLE_LIMITS.items():
            if codes.count(c) > lim:
                report.error("E-ROSTER", w, "lineup %s has %d %s (at most %d)"
                             % (ln, codes.count(c), c, lim))
        batters = set(FIELDERS) | ({"DH"} if dh else {"SP1"})
        got = []
        for c, o in zip(codes, orders):
            if c in batters:
                if o == "-1":
                    report.error("E-ROSTER", w, "lineup %s: %s needs a batting order" % (ln, c))
                else:
                    got.append(int(o))
            elif o != "-1":
                report.error("E-ROSTER", w, "lineup %s: %s does not bat (batting order only for "
                             "%s)" % (ln, c, " ".join(sorted(batters))))
        if sorted(got) != list(range(1, 10)) and len(got) == 9:
            report.error("E-ROSTER", w, "lineup %s: batting orders must be 1-9, each once" % ln)


def _pname(m, key):
    p = m.players.get(key)
    return p.name if p else key


# ------------------------------------------------------------------ outputs
def build_outputs(m, packs):
    """Patched files as {disc path: bytes}, the canonical texts for the result hash,
    and the names of the changed tables."""
    files = {}
    texts = {}
    tables = m.tables()
    changed = []
    replace = {}
    for e in m.db.archive.entries:
        name = e.name[:-4]
        text = tables[name].serialize()
        texts["%s:%s" % (DATABASE_PATH, e.name.lower())] = text
        if text != m.db._orig_text[name]:
            changed.append(name)
            replace[e.name] = refpack.compress(text)
    if replace:
        files[DATABASE_PATH] = m.db.archive.to_bytes(replace)
    for f in LOC_FILES:
        data = m.locs[f].serialize()
        texts["/data/" + f.lower()] = data
        if m.locs[f].entries != list(m.loc_orig[f].items()):
            files["/data/" + f] = data
    by_file = {}
    for p in packs:
        for a in p.assets:
            by_file.setdefault(a["target"][0], []).append(a)
    return files, texts, changed, by_file


def apply_assets(disc, by_file, files, texts, report):
    for path in sorted(by_file):
        items = by_file[path]
        real = _disc_name(disc, path)
        if real is None:
            report.error("E-NOT-FOUND", items[0]["where"], "the disc has no file %s" % path)
            continue
        if items[0]["target"][1] is None:
            a = items[-1]
            if disc.read(real) == a["data"]:
                report.error("E-RETAIL-COPY", a["where"], "the asset is a copy of the retail file")
                continue
            files[real] = a["data"]
            texts[path] = a["data"]
            continue
        try:
            arc = big.BigArchive.from_bytes(disc.read(real))
        except big.BigError as e:
            report.error("E-ASSET", items[0]["where"], "%s is not a BIGF archive (%s)" % (path, e))
            continue
        replace = {}
        for a in items:
            entry = a["target"][1]
            try:
                e = arc.entry(entry)
            except KeyError:
                report.error("E-NOT-FOUND", a["where"], "%s has no entry %s" % (path, entry))
                continue
            if arc.raw(e.name) == a["data"] or arc.read(e.name) == a["data"]:
                report.error("E-RETAIL-COPY", a["where"], "the asset is a copy of the retail entry")
                continue
            replace[e.name] = a["data"]
            texts["%s:%s" % (path, entry)] = a["data"]
        if replace:
            files[real] = arc.to_bytes(replace)


def _disc_name(disc, path):
    if disc.image is not None:
        for p, off, size in disc.image.files:
            if p.lower() == path:
                return p
        return None
    return path if disc.exists(path) else None


def result_hash(texts):
    return sha256_hex(RESULT_HASH_PREFIX + canonical_json(
        {k: sha256_hex(v) for k, v in texts.items()}))


def run_packs(pack_specs, report, disc=None):
    """Load, compose and (with a disc) apply. Returns (packs, model or None, outputs)."""
    packs = [load_pack(s, report) for s in pack_specs]
    deps = check_set_order(packs, report)
    if disc is None or not report.ok:
        return packs, None, None
    model = load_model(disc)
    Applier(model, report, deps).run(packs)
    validate_model(model, report)
    if not report.ok:
        return packs, model, None
    files, texts, changed, by_file = build_outputs(model, packs)
    apply_assets(disc, by_file, files, texts, report)
    return packs, model, (files, texts, changed)


# ------------------------------------------------------------------ CLI
def _inside_git_tracked_tree(path):
    path = os.path.abspath(path)
    cur = path
    while True:
        if os.path.exists(os.path.join(cur, ".git")):
            break
        parent = os.path.dirname(cur)
        if parent == cur:
            return False
        cur = parent
    try:
        r = subprocess.run(["git", "-C", cur, "check-ignore", "-q", path],
                           stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        return r.returncode != 0          # 0 = ignored
    except OSError:
        return True


def _emit(report, as_json, extra=None):
    if as_json:
        obj = {"ok": report.ok, "issues": report.to_json()}
        obj.update(extra or {})
        print(json.dumps(obj, indent=1, sort_keys=True))
    else:
        print(report.render())


def cmd_validate(a):
    report = Report()
    try:
        disc = Disc(a.disc) if a.disc else None
        packs, _, _ = run_packs(a.packs, report, disc)
    except PackError as e:
        print("error: %s" % e, file=sys.stderr)
        return 2
    _emit(report, a.json, {"packs": [{"id": p.id, "hash": p.hash} for p in packs]})
    return 0 if report.ok else 1


def cmd_apply(a):
    if _inside_git_tracked_tree(a.out):
        print("error: %s is inside a git work tree and not ignored; patched game files must "
              "never be committed" % a.out, file=sys.stderr)
        return 2
    report = Report()
    try:
        disc = Disc(a.disc)
        packs, model, out = run_packs(a.packs, report, disc)
    except PackError as e:
        print("error: %s" % e, file=sys.stderr)
        return 2
    extra = {}
    if out is not None:
        files, texts, changed = out
        os.makedirs(a.out, exist_ok=True)
        for path, data in sorted(files.items()):
            dst = os.path.join(a.out, *path.strip("/").split("/"))
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            with open(dst, "wb") as f:
                f.write(data)
        extra = {"set_hash": set_hash(packs), "result_hash": result_hash(texts),
                 "changed_tables": changed, "written": sorted(files),
                 "packs": [{"id": p.id, "version": p.manifest["version"], "hash": p.hash}
                           for p in packs]}
        with open(os.path.join(a.out, "pack-apply.json"), "w", encoding="utf-8") as f:
            json.dump(dict(extra, issues=report.to_json()), f, indent=1, sort_keys=True)
    _emit(report, a.json, extra)
    if out is not None and not a.json:
        print("set hash    %s\nresult hash %s\nchanged tables: %s\nwrote: %s" % (
            extra["set_hash"], extra["result_hash"], ", ".join(extra["changed_tables"]) or "none",
            ", ".join(extra["written"]) or "nothing"))
    return 0 if report.ok else 1


def cmd_hash(a):
    report = Report()
    packs = [load_pack(s, report) for s in a.packs]
    check_set_order(packs, report)
    if not report.ok:
        print(report.render())
        return 1
    for p in packs:
        print("%s  %s %s" % (p.hash, p.id, p.manifest["version"]))
    print("%s  (set of %d, in this order)" % (set_hash(packs), len(packs)))
    return 0


SCAFFOLD_PLAYERS = {"ops": []}


def cmd_new(a):
    if not (PACK_ID.match(a.id) and 3 <= len(a.id) <= 64):
        print("error: id must be 3-64 characters of a-z 0-9 and single hyphens", file=sys.stderr)
        return 2
    if os.path.exists(a.dir) and os.listdir(a.dir):
        print("error: %s exists and is not empty" % a.dir, file=sys.stderr)
        return 2
    os.makedirs(os.path.join(a.dir, "patches"), exist_ok=True)
    manifest = {"id": a.id, "name": a.name or a.id, "version": "0.1.0", "game": GAME_ID,
                "engine_api": "%d.%d" % API_VERSION, "description": "", "authors": [],
                "license": "CC0-1.0", "depends": [], "patches": ["patches/players.json"],
                "assets": []}
    with open(os.path.join(a.dir, "pack.json"), "w", encoding="utf-8", newline="\n") as f:
        json.dump(manifest, f, indent=2)
        f.write("\n")
    with open(os.path.join(a.dir, "patches", "players.json"), "w", encoding="utf-8",
              newline="\n") as f:
        json.dump(SCAFFOLD_PLAYERS, f, indent=2)
        f.write("\n")
    print("created %s (pack.json, patches/players.json)" % a.dir)
    return 0


def main(argv):
    import argparse
    ap = argparse.ArgumentParser(description="Roster and team packs, format v1 (docs/MODDING.md)")
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("validate", help="check packs; with --disc, apply them in memory too")
    p.add_argument("--disc")
    p.add_argument("--json", action="store_true")
    p.add_argument("packs", nargs="+")
    p.set_defaults(fn=cmd_validate)
    p = sub.add_parser("apply", help="write the patched files of a pack set")
    p.add_argument("--disc", required=True)
    p.add_argument("--out", required=True)
    p.add_argument("--json", action="store_true")
    p.add_argument("packs", nargs="+")
    p.set_defaults(fn=cmd_apply)
    p = sub.add_parser("hash", help="print each pack hash and the set hash")
    p.add_argument("packs", nargs="+")
    p.set_defaults(fn=cmd_hash)
    p = sub.add_parser("new", help="scaffold an empty pack")
    p.add_argument("dir")
    p.add_argument("--id", required=True)
    p.add_argument("--name")
    p.set_defaults(fn=cmd_new)
    a = ap.parse_args(argv)
    return a.fn(a)


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
