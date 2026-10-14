#!/usr/bin/env python3
"""Coordination between every agent working on this repo: Claude Code sessions
and Codex sessions alike. Who is who, who owns which unit, who may push to
main, and messages between them. See docs/COORDINATION.md.

    python tools/coord.py register claude-lead --tool claude --role lead --note "integrates worker branches"
    python tools/coord.py who                        # roster: live agents, their worktrees and claims
    python tools/coord.py claim codex-sw03 game/tu_8026C414 fe/tu_804FE34C
    python tools/coord.py release codex-sw03 --all
    python tools/coord.py run-locked claude-lead --purpose "nm-08 merge" -- python tools/team/integrate.py --push
    python tools/coord.py send claude-lead codex "please hold fe/ units until 20:00"
    python tools/coord.py inbox codex-coordinator
    python tools/coord.py log -n 20

State lives in one directory shared by every worktree and clone on this
machine: <main repo>/.git/coord. A clone whose remote is a local path (like
Codex's SWINTEGRATE clone with `local_source`) resolves to that repo's
directory; $COORD_DIR overrides. `python tools/coord.py where` prints it.

Rules the tool enforces:
  - names are unique; an agent is live while it has been seen in the last 45 min
    (every command run as NAME counts as a sighting);
  - a unit claimed by another live agent can't be claimed (use --steal REASON,
    which is logged and messaged to the owner);
  - the integration lock is first come, first served (a waiting queue), expires
    45 min after its last refresh, and `run-locked` refreshes it while the
    command runs and always releases it.

Standard library only. It decides nothing about matching: objdiff and
tools/verify/verify.py do.
"""
from __future__ import annotations

import argparse
import json
import os
import subprocess
import sys
import threading
import time
from contextlib import contextmanager
from datetime import datetime
from pathlib import Path

LIVE_SECONDS = 45 * 60
LOCK_TTL_SECONDS = 45 * 60
QUEUE_STALE_SECONDS = 3 * 60
GROUPS = ("all", "claude", "codex")


# ---------------------------------------------------------------- location


def _git(*args: str, cwd: str | None = None) -> str:
    r = subprocess.run(["git", *args], capture_output=True, text=True, cwd=cwd)
    return r.stdout.strip() if r.returncode == 0 else ""


def coord_dir() -> Path:
    env = os.environ.get("COORD_DIR")
    if env:
        return Path(env)
    # A clone whose remote is a local repo (Codex's integration clone) shares that repo's state.
    for line in _git("config", "--get-regexp", r"^remote\..*\.url$").splitlines():
        url = line.split(" ", 1)[1].strip() if " " in line else ""
        url = url[len("file://"):] if url.startswith("file://") else url
        if url and Path(url).is_dir():  # paths may contain spaces ("Patrick Taylor")
            common = _git("rev-parse", "--path-format=absolute", "--git-common-dir", cwd=url)
            if common:
                return Path(common) / "coord"
    common = _git("rev-parse", "--path-format=absolute", "--git-common-dir")
    if not common:
        raise SystemExit("coord: not inside a git checkout of this repo (or set COORD_DIR)")
    return Path(common) / "coord"


D = None  # set in main()


def now() -> float:
    return time.time()


def stamp(t: float | None = None) -> str:
    return datetime.fromtimestamp(t if t is not None else now()).strftime("%Y-%m-%d %H:%M:%S")


def ago(t: float) -> str:
    s = int(now() - t)
    return f"{s // 3600}h{(s % 3600) // 60:02d}m" if s >= 3600 else f"{s // 60}m{s % 60:02d}s"


# ---------------------------------------------------------------- storage


@contextmanager
def mutex():
    """Cross-process mutex: mkdir is atomic on every OS we use. Stale after 60 s."""
    m = D / ".mutex"
    t0 = now()
    while True:
        try:
            m.mkdir()
            break
        except FileExistsError:
            try:
                if now() - m.stat().st_mtime > 60:
                    os.rmdir(m)
                    continue
            except OSError:
                pass
            if now() - t0 > 30:
                raise SystemExit("coord: state is busy (mutex held > 30 s)")
            time.sleep(0.05)
    try:
        yield
    finally:
        try:
            os.rmdir(m)
        except OSError:
            pass


def read_json(p: Path, default):
    try:
        return json.loads(p.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return default


def write_json(p: Path, data) -> None:
    p.parent.mkdir(parents=True, exist_ok=True)
    tmp = p.with_suffix(p.suffix + f".{os.getpid()}.tmp")
    tmp.write_text(json.dumps(data, indent=1), encoding="utf-8")
    os.replace(tmp, p)


def append_jsonl(p: Path, rec: dict) -> None:
    p.parent.mkdir(parents=True, exist_ok=True)
    with p.open("a", encoding="utf-8") as f:
        f.write(json.dumps(rec) + "\n")


def read_jsonl(p: Path) -> list[dict]:
    try:
        return [json.loads(l) for l in p.read_text(encoding="utf-8").splitlines() if l.strip()]
    except OSError:
        return []


def event(kind: str, who: str, **kw) -> None:
    append_jsonl(D / "events.jsonl", {"t": now(), "kind": kind, "who": who, **kw})


# ---------------------------------------------------------------- agents


def agent_path(name: str) -> Path:
    return D / "agents" / f"{name}.json"


def agents() -> dict[str, dict]:
    out = {}
    for p in sorted((D / "agents").glob("*.json")):
        a = read_json(p, None)
        if a:
            out[a["name"]] = a
    return out


def is_live(a: dict | None) -> bool:
    return bool(a) and now() - a.get("last_seen", 0) < LIVE_SECONDS


def touch(name: str, must_exist: bool = True) -> dict:
    p = agent_path(name)
    a = read_json(p, None)
    if a is None:
        if must_exist:
            raise SystemExit(f"coord: unknown agent '{name}'. Register first: python tools/coord.py register {name} --tool claude|codex --role ...")
        return {}
    a["last_seen"] = now()
    write_json(p, a)
    return a


def cmd_register(args) -> None:
    if args.name in GROUPS:
        raise SystemExit(f"coord: '{args.name}' is reserved")
    with mutex():
        old = read_json(agent_path(args.name), None)
        wt = str(Path(args.worktree).resolve()) if args.worktree else str(Path.cwd())
        if old and is_live(old) and old.get("worktree") != wt and not args.force:
            raise SystemExit(f"coord: '{args.name}' is already live in {old.get('worktree')} (seen {ago(old['last_seen'])} ago). "
                             "Pick another name, or --force if that is you.")
        a = {
            "name": args.name, "tool": args.tool, "role": args.role, "note": args.note or "",
            "worktree": wt, "branch": _git("branch", "--show-current", cwd=wt),
            "registered": (old or {}).get("registered", now()), "last_seen": now(),
        }
        write_json(agent_path(args.name), a)
        event("register", args.name, tool=args.tool, role=args.role)
    print(f"registered {args.name} ({args.tool}, {args.role}) in {a['worktree']} [{a['branch']}]")
    unread = unread_messages(args.name)
    if unread:
        print(f"{len(unread)} unread message(s): python tools/coord.py inbox {args.name}")


def cmd_who(args) -> None:
    ags = agents()
    claims = read_json(D / "claims.json", {})
    lock = read_json(D / "lock" / "owner.json", None) if (D / "lock").exists() else None
    by_owner: dict[str, list[str]] = {}
    for unit, c in claims.items():
        by_owner.setdefault(c["owner"], []).append(unit)
    rows = sorted(ags.values(), key=lambda a: (not is_live(a), a["tool"], a["name"]))
    print(f"coord: {D}")
    for a in rows:
        if not args.all and not is_live(a):
            continue
        state = "live" if is_live(a) else "gone"
        units = by_owner.get(a["name"], [])
        print(f"{a['name']:22} {a['tool']:6} {a['role']:12} {state:4} seen {ago(a['last_seen']):>7} ago  {a.get('branch', '')}")
        print(f"{'':22} {a['worktree']}" + (f"  -- {a['note']}" if a.get("note") else ""))
        if units:
            print(f"{'':22} claims: {', '.join(sorted(units))}")
    if not args.all:
        gone = sum(1 for a in ags.values() if not is_live(a))
        if gone:
            print(f"({gone} agent(s) not seen for 45 min; --all shows them)")
    if lock:
        print(f"integration lock: {lock['owner']} since {stamp(lock['acquired'])} ({lock.get('purpose', '')})")
    else:
        print("integration lock: free")


# ---------------------------------------------------------------- claims


def cmd_claim(args) -> None:
    with mutex():
        touch(args.name)
        claims = read_json(D / "claims.json", {})
        ags = agents()
        refused = []
        for u in args.units:
            c = claims.get(u)
            if c and c["owner"] != args.name and is_live(ags.get(c["owner"])):
                if not args.steal:
                    refused.append(f"{u} (claimed by {c['owner']} since {stamp(c['since'])})")
                    continue
                append_jsonl(D / "messages.jsonl", {"t": now(), "from": args.name, "to": c["owner"],
                                                    "text": f"I took over {u} from you: {args.steal}"})
                event("steal", args.name, unit=u, previous=c["owner"], reason=args.steal)
            claims[u] = {"owner": args.name, "since": now(), "note": args.note or ""}
            event("claim", args.name, unit=u)
        write_json(D / "claims.json", claims)
    taken = [u for u in args.units if all(not r.startswith(u + " ") for r in refused)]
    if taken:
        print(f"{args.name} claims: {', '.join(taken)}")
    if refused:
        print("refused: " + "; ".join(refused))
        sys.exit(1)


def cmd_release(args) -> None:
    with mutex():
        touch(args.name)
        claims = read_json(D / "claims.json", {})
        mine = [u for u, c in claims.items() if c["owner"] == args.name]
        units = mine if args.all else [u for u in args.units if u in mine]
        for u in units:
            del claims[u]
            event("release", args.name, unit=u)
        write_json(D / "claims.json", claims)
    print(f"{args.name} released: {', '.join(units) or 'nothing'}")


def cmd_claims(args) -> None:
    claims = read_json(D / "claims.json", {})
    ags = agents()
    for u, c in sorted(claims.items()):
        live = is_live(ags.get(c["owner"]))
        if args.busy:
            if live:
                print(u)
            continue
        print(f"{u:40} {c['owner']:22} {'live' if live else 'GONE (claim is free to take)'}  since {stamp(c['since'])}"
              + (f"  {c['note']}" if c.get("note") else ""))


# ---------------------------------------------------------------- integration lock


def lock_owner():
    return read_json(D / "lock" / "owner.json", None) if (D / "lock").exists() else None


def try_acquire(name: str, purpose: str) -> tuple[bool, str]:
    with mutex():
        q = D / "queue"
        q.mkdir(parents=True, exist_ok=True)
        write_json(q / f"{name}.json", {"name": name, "since": read_json(q / f"{name}.json", {}).get("since", now()),
                                        "refreshed": now(), "purpose": purpose})
        waiting = []
        for p in q.glob("*.json"):
            w = read_json(p, None)
            if not w or now() - w.get("refreshed", 0) > QUEUE_STALE_SECONDS:
                p.unlink(missing_ok=True)
                continue
            waiting.append(w)
        waiting.sort(key=lambda w: w["since"])
        owner = lock_owner()
        if owner and owner["owner"] != name and now() - owner.get("refreshed", 0) > LOCK_TTL_SECONDS:
            event("lock-expired", name, previous=owner["owner"])
            append_jsonl(D / "messages.jsonl", {"t": now(), "from": name, "to": owner["owner"],
                                                "text": "your integration lock expired (no refresh for 45 min) and was taken over"})
            for p in (D / "lock").glob("*"):
                p.unlink(missing_ok=True)
            os.rmdir(D / "lock")
            owner = None
        if owner:
            if owner["owner"] == name:
                return True, "already held"
            return False, f"held by {owner['owner']} since {stamp(owner['acquired'])} ({owner.get('purpose', '')})"
        if waiting and waiting[0]["name"] != name:
            return False, f"queue: {', '.join(w['name'] for w in waiting)}"
        (D / "lock").mkdir()
        write_json(D / "lock" / "owner.json", {"owner": name, "acquired": now(), "refreshed": now(), "purpose": purpose})
        (q / f"{name}.json").unlink(missing_ok=True)
        event("lock", name, purpose=purpose)
        return True, "acquired"


def acquire(name: str, purpose: str, wait_min: float) -> None:
    touch(name)
    t0, last = now(), ""
    while True:
        ok, why = try_acquire(name, purpose)
        if ok:
            print(f"integration lock {why} by {name}")
            return
        if why != last:
            print(f"waiting for the integration lock: {why}", flush=True)
            last = why
        if now() - t0 > wait_min * 60:
            with mutex():
                (D / "queue" / f"{name}.json").unlink(missing_ok=True)
            raise SystemExit(f"coord: gave up waiting for the integration lock after {wait_min:g} min")
        time.sleep(10)


def release_lock(name: str, quiet: bool = False) -> None:
    with mutex():
        owner = lock_owner()
        if not owner or owner["owner"] != name:
            if not quiet:
                print(f"{name} does not hold the integration lock")
            return
        for p in (D / "lock").glob("*"):
            p.unlink(missing_ok=True)
        os.rmdir(D / "lock")
        event("unlock", name)
    if not quiet:
        print(f"integration lock released by {name}")


def refresh_lock(name: str) -> None:
    with mutex():
        owner = lock_owner()
        if owner and owner["owner"] == name:
            owner["refreshed"] = now()
            write_json(D / "lock" / "owner.json", owner)
    touch(name, must_exist=False)


def cmd_lock(args) -> None:
    acquire(args.name, args.purpose, args.wait)


def cmd_unlock(args) -> None:
    release_lock(args.name)


def cmd_lock_status(args) -> None:
    owner = lock_owner()
    print(f"held by {owner['owner']} since {stamp(owner['acquired'])}, refreshed {ago(owner['refreshed'])} ago: {owner.get('purpose', '')}"
          if owner else "free")
    for p in sorted((D / "queue").glob("*.json")):
        w = read_json(p, None)
        if w:
            print(f"  waiting: {w['name']} since {stamp(w['since'])} ({w.get('purpose', '')})")


def cmd_run_locked(args) -> None:
    if not args.cmd:
        raise SystemExit("coord: nothing to run (put the command after --)")
    acquire(args.name, args.purpose, args.wait)
    stop = threading.Event()

    def keepalive():
        while not stop.wait(300):
            refresh_lock(args.name)

    th = threading.Thread(target=keepalive, daemon=True)
    th.start()
    try:
        rc = subprocess.call(args.cmd)
    finally:
        stop.set()
        release_lock(args.name)
    sys.exit(rc)


# ---------------------------------------------------------------- messages


def addressed_to(msg: dict, name: str, tool: str) -> bool:
    return msg["to"] in (name, "all", tool) and msg["from"] != name


def unread_messages(name: str) -> list[dict]:
    a = read_json(agent_path(name), {})
    cur = int(read_json(D / "cursors" / f"{name}.json", {}).get("seen", 0))
    msgs = read_jsonl(D / "messages.jsonl")
    return [m for m in msgs[cur:] if addressed_to(m, name, a.get("tool", ""))]


def cmd_send(args) -> None:
    ags = agents()
    if args.to not in GROUPS and args.to not in ags:
        raise SystemExit(f"coord: no agent '{args.to}' (known: {', '.join(sorted(ags)) or 'none'}; groups: {', '.join(GROUPS)})")
    with mutex():
        touch(args.name)
        append_jsonl(D / "messages.jsonl", {"t": now(), "from": args.name, "to": args.to, "text": " ".join(args.text)})
    print(f"sent to {args.to}")


def cmd_inbox(args) -> None:
    a = touch(args.name)
    msgs = read_jsonl(D / "messages.jsonl")
    cur = int(read_json(D / "cursors" / f"{args.name}.json", {}).get("seen", 0))
    shown = [m for m in (msgs if args.all else msgs[cur:]) if addressed_to(m, args.name, a.get("tool", ""))]
    for m in shown:
        print(f"[{stamp(m['t'])}] {m['from']} -> {m['to']}: {m['text']}")
    if not shown:
        print("no new messages")
    if not args.peek:
        write_json(D / "cursors" / f"{args.name}.json", {"seen": len(msgs)})


def cmd_log(args) -> None:
    for e in read_jsonl(D / "events.jsonl")[-args.n:]:
        extra = " ".join(f"{k}={v}" for k, v in e.items() if k not in ("t", "kind", "who"))
        print(f"[{stamp(e['t'])}] {e['who']:22} {e['kind']:12} {extra}")


def main() -> None:
    global D
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="command", required=True)
    sub.add_parser("where", help="print the shared state directory")
    p = sub.add_parser("register", help="announce yourself (once per session; re-run to update)")
    p.add_argument("name", help="unique: <tool>-<role>[-n], e.g. claude-lead, codex-coordinator, codex-sw03")
    p.add_argument("--tool", required=True, choices=["claude", "codex", "other"])
    p.add_argument("--role", required=True, help="lead, integrator, worker, coordinator, side, bot")
    p.add_argument("--note", help="one line: what you're doing")
    p.add_argument("--worktree", help="register a worker you manage (default: the current directory)")
    p.add_argument("--force", action="store_true")
    p = sub.add_parser("who", help="roster of agents, worktrees, claims and the lock")
    p.add_argument("--all", action="store_true", help="include agents not seen for 45 min")
    p = sub.add_parser("claim", help="claim units before editing them")
    p.add_argument("name")
    p.add_argument("units", nargs="+")
    p.add_argument("--note")
    p.add_argument("--steal", metavar="REASON", help="take units another live agent holds (logged; they get a message)")
    p = sub.add_parser("release", help="release units when done (or --all)")
    p.add_argument("name")
    p.add_argument("units", nargs="*")
    p.add_argument("--all", action="store_true")
    p = sub.add_parser("claims", help="all claims; --busy prints live claimed units one per line")
    p.add_argument("--busy", action="store_true")
    p = sub.add_parser("lock", help="take the integration lock (wait in line)")
    p.add_argument("name")
    p.add_argument("--purpose", required=True)
    p.add_argument("--wait", type=float, default=60, help="minutes to wait (default 60)")
    p = sub.add_parser("unlock", help="release the integration lock")
    p.add_argument("name")
    sub.add_parser("lock-status")
    p = sub.add_parser("run-locked", help="take the lock, run a command (e.g. the integration gate + push), release")
    p.add_argument("name")
    p.add_argument("--purpose", required=True)
    p.add_argument("--wait", type=float, default=60)
    p = sub.add_parser("send", help="message an agent, or a group: all, claude, codex")
    p.add_argument("name", help="you")
    p.add_argument("to")
    p.add_argument("text", nargs="+")
    p = sub.add_parser("inbox", help="unread messages for you (--all for history)")
    p.add_argument("name")
    p.add_argument("--all", action="store_true")
    p.add_argument("--peek", action="store_true", help="don't mark as read")
    p = sub.add_parser("log", help="recent coordination events")
    p.add_argument("-n", type=int, default=30)
    argv, run = sys.argv[1:], []
    if "--" in argv:  # run-locked NAME --purpose P -- command...
        i = argv.index("--")
        argv, run = argv[:i], argv[i + 1 :]
    args = ap.parse_args(argv)
    args.cmd = run
    D = coord_dir()
    D.mkdir(parents=True, exist_ok=True)
    {
        "where": lambda a: print(D),
        "register": cmd_register, "who": cmd_who, "claim": cmd_claim, "release": cmd_release,
        "claims": cmd_claims, "lock": cmd_lock, "unlock": cmd_unlock, "lock-status": cmd_lock_status,
        "run-locked": cmd_run_locked, "send": cmd_send, "inbox": cmd_inbox, "log": cmd_log,
    }[args.command](args)


if __name__ == "__main__":
    main()
