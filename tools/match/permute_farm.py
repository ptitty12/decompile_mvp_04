#!/usr/bin/env python3
"""Permuter farm: run decomp-permuter over main's near-misses, unattended, at idle CPU priority.

No agents and no tokens: it only uses spare CPU. It works in its own worktree (FARM_DIR,
default C:\\Users\\Patrick Taylor\\decompile_mvp_04-farm), detached at origin/main and
rebuilt when main has moved (at most every --refresh minutes). For each function between
--min-pct and 100% in that build's report.json, closest first, it runs
tools/match/permute.py for --minutes. Units the lead has handed to workers
(tools/team/lead/state/busy_units.txt in the main checkout) are skipped.

Ledger: <farm>/build/permute_farm/ledger.json, one entry per function: unit, match %, a
hash of the unit's source, status (refused / tried / matched / mismatch), base and best
score, best candidate. A function is tried again only after its unit's source changes.

On a score of 0 the farm puts the candidate's function body into src/<unit>, rebuilds that
unit with ninja, checks that the function's code equals the retail target, saves the
change as <run dir>/match.patch, and restores the source. It never commits or creates
branches: a lead or worker applies the patch and runs tools/verify/verify.py, as for any
match (CLAUDE.md: nothing is done without a passing verifier run).

  python tools/match/permute_farm.py --loop     # what the scheduled task runs; exits if a loop holds the lock
  python tools/match/permute_farm.py --once     # one function, then exit (testing)
  python tools/match/permute_farm.py --status   # ledger summary
  python tools/match/permute_farm.py --install  # scheduled task every 10 min; it restarts the loop if it died
  python tools/match/permute_farm.py --uninstall
Log: <farm>/build/permute_farm/farm.log.
"""
import argparse
import datetime
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
import time
import traceback
from pathlib import Path

HERE = Path(__file__).resolve()
sys.path.insert(0, str(HERE.parent))
from cxx2c import definition_body  # noqa: E402

FARM = Path(os.environ.get("FARM_DIR", r"C:\Users\Patrick Taylor\decompile_mvp_04-farm"))
STATE = FARM / "build" / "permute_farm"
LEDGER = STATE / "ledger.json"
LOG = STATE / "farm.log"
LOCK = STATE / "lock"
VERSION = "GV4E69"
TASK_NAME = "MVP decomp permuter farm"
DISC_IMAGES = {".iso", ".ciso", ".rvz", ".gcm", ".wbfs", ".wia", ".gcz", ".nfs", ".tgc"}
NO_WINDOW = getattr(subprocess, "CREATE_NO_WINDOW", 0)
PY = str(Path(sys.executable).with_name("python.exe")) if Path(sys.executable).name.lower() == "pythonw.exe" else sys.executable


def log(msg):
    STATE.mkdir(parents=True, exist_ok=True)
    if LOG.is_file() and LOG.stat().st_size > 2_000_000:
        os.replace(LOG, LOG.with_suffix(".log.1"))
    with open(LOG, "a", encoding="utf-8") as f:
        for line in str(msg).splitlines() or [""]:
            f.write(f"{datetime.datetime.now():%Y-%m-%d %H:%M:%S}  {line}\n")
    if sys.stdout is not None:
        print(msg, flush=True)


def sh(cmd, cwd=FARM, check=True, timeout=None):
    r = subprocess.run(cmd, cwd=cwd, capture_output=True, text=True, encoding="utf-8", errors="replace",
                       creationflags=NO_WINDOW, timeout=timeout,
                       env=dict(os.environ, GIT_TERMINAL_PROMPT="0"))
    if check and r.returncode:
        raise RuntimeError(f"{' '.join(map(str, cmd[:3]))} failed:\n{(r.stdout + r.stderr)[-1500:]}")
    return r


def git(*args, check=True):
    return sh(["git", *args], check=check).stdout.strip()


def main_checkout():
    out = sh(["git", "worktree", "list", "--porcelain"], cwd=HERE.parent).stdout
    return Path(out.splitlines()[0].split(" ", 1)[1])


def idle_priority():
    if os.name == "nt":  # children inherit IDLE_PRIORITY_CLASS: the fleet's builds always come first
        import ctypes
        k32 = ctypes.windll.kernel32
        k32.SetPriorityClass(k32.GetCurrentProcess(), 0x40)


def alive(pid):
    if os.name != "nt":
        try:
            os.kill(pid, 0)
            return True
        except OSError:
            return False
    import ctypes
    k32 = ctypes.windll.kernel32
    h = k32.OpenProcess(0x100000, False, pid)  # SYNCHRONIZE
    if not h:
        return False
    try:
        return k32.WaitForSingleObject(h, 0) == 0x102  # WAIT_TIMEOUT: still running
    finally:
        k32.CloseHandle(h)


def take_lock():
    STATE.mkdir(parents=True, exist_ok=True)
    try:
        pid = int(LOCK.read_text())
        if pid != os.getpid() and alive(pid):
            return False
    except (OSError, ValueError):
        pass
    LOCK.write_text(str(os.getpid()))
    return True


# ----------------------------------------------------------------------------- worktree


def ensure_worktree():
    main = main_checkout()
    if not (FARM / ".git").exists():
        sh(["git", "worktree", "add", "--detach", str(FARM), "origin/main"], cwd=main)
        log(f"created worktree {FARM}")
    src, dst = main / "orig" / VERSION, FARM / "orig" / VERSION  # as tools/progress_bot.py does
    dst.mkdir(parents=True, exist_ok=True)
    for p in src.iterdir():
        if p.is_file() and p.suffix.lower() not in DISC_IMAGES and not (dst / p.name).exists():
            shutil.copyfile(p, dst / p.name)
    if not (dst / "mvp.elf").is_file():
        shutil.copyfile(main / "build" / VERSION / "orig" / "mvp.elf", dst / "mvp.elf")


def refresh(state, every):
    """Check out and build origin/main when it moved (at most every `every` minutes)."""
    head, target = git("rev-parse", "HEAD"), git("rev-parse", "origin/main")
    built = (FARM / "build" / VERSION / "report.json").exists()
    if head == target and built and state.get("built") == target:
        return True
    if built and state.get("built") and time.time() - state.get("built_at", 0) < every * 60:
        return True
    log(f"building origin/main {target[:10]}")
    git("checkout", "--quiet", "--force", "--detach", target)
    ninja = shutil.which("ninja") or str(Path.home() / r"AppData\Local\Microsoft\WinGet\Links\ninja.exe")
    try:
        sh([PY, "configure.py"], timeout=600)
        sh([ninja], timeout=3600)
        sh([ninja, os.path.normpath("build/binutils")], timeout=600)
    except Exception as e:
        log(f"build failed, retrying later: {e}")
        return built
    state.update(built=target, built_at=time.time())
    return True


# ----------------------------------------------------------------------------- queue


def unit_source(unit):
    for ext in (".c", ".cpp"):
        p = FARM / "src" / f"{unit}{ext}"
        if p.exists():
            return p
    return None


def busy_units():
    try:
        text = (main_checkout() / "tools" / "team" / "lead" / "state" / "busy_units.txt").read_text(encoding="utf-8")
    except OSError:
        return set()
    return set(re.findall(r"[\w./-]+/tu_[0-9A-Fa-f]{8}", text))


def queue(ledger, min_pct):
    report = json.loads((FARM / "build" / VERSION / "report.json").read_text(encoding="utf-8"))
    busy, todo = busy_units(), []
    for u in report["units"]:
        unit = u["name"].split("/", 1)[-1]
        src = unit_source(unit)
        if src is None or unit in busy:
            continue
        digest = hashlib.sha1(src.read_bytes()).hexdigest()
        fns = u.get("functions") or []
        done = sum(1 for f in fns if float(f.get("fuzzy_match_percent", 0)) >= 100)
        for f in fns:
            pct = float(f.get("fuzzy_match_percent", 0))
            if not (min_pct <= pct < 100) or not int(f.get("size", 0)):
                continue
            old = ledger.get(f["name"])
            if old and old.get("src") == digest:
                continue
            todo.append({"unit": unit, "fn": f["name"], "pct": pct, "size": int(f["size"]), "src": digest,
                         "n": done + 1, "m": len(fns)})
    todo.sort(key=lambda t: (-t["pct"], t["size"]))
    return todo


# ----------------------------------------------------------------------------- one function


def permute_one(t, minutes, jobs):
    run_dir = STATE / "runs" / re.sub(r"[^\w.-]", "_", t["fn"])[:80]
    cmd = [PY, str(FARM / "tools" / "match" / "permute.py"), t["unit"], t["fn"], "--minutes", str(minutes),
           "-j", str(jobs), "--dir", str(run_dir)]
    r = sh(cmd, check=False, timeout=minutes * 60 + 900)
    out = r.stdout + r.stderr
    entry = dict(t, time=time.time(), dir=str(run_dir))
    refused = re.search(r"REFUSED: (.*)", out)
    base = re.search(r"base score (\d+)", out)
    if refused or not base:
        last = (out.strip().splitlines() or ["?"])[-1]
        entry.update(status="refused", why=(refused.group(1) if refused else last)[:300])
        return entry
    cands = re.findall(r"^\s+(\d+)\s+(.*source\.c)\s*$", out, re.M)
    best = min(((int(s), p) for s, p in cands), default=(int(base.group(1)), None))
    entry.update(status="tried", base=int(base.group(1)), best=best[0], cand=best[1])
    if best[0] == 0 and best[1]:
        entry.update(apply_match(t, Path(best[1]), run_dir))
    return entry


def apply_match(t, cand, run_dir):
    """Check a 0-score body in the real source and save it as a patch. Never commits: a
    lead or worker applies the patch and runs tools/verify/verify.py as for any match."""
    sys.path.insert(0, str(FARM / "tools" / "match"))
    from permute import disasm  # noqa: E402  (the farm checkout's copy)
    settings = (run_dir / "settings.toml").read_text(encoding="utf-8")
    cname = re.search(r'func_name = "([^"]+)"', settings).group(1)
    src = unit_source(t["unit"])
    rel = src.relative_to(FARM).as_posix()
    text, cand_text = src.read_text(encoding="utf-8"), cand.read_text(encoding="utf-8")
    sb, cb = definition_body(text, cname), definition_body(cand_text, cname)
    if not sb or not cb:
        return {"status": "mismatch", "why": "could not locate the function body to apply"}
    try:
        src.write_text(text[:sb[0]] + cand_text[cb[0]:cb[1]] + text[sb[1]:], encoding="utf-8", newline="\n")
        obj = os.path.normpath(f"build/{VERSION}/src/{t['unit']}.o")
        ninja = shutil.which("ninja") or str(Path.home() / r"AppData\Local\Microsoft\WinGet\Links\ninja.exe")
        sh([ninja, obj], timeout=900)
        got, _ = disasm(FARM / obj, t["fn"])
        want, _ = disasm(run_dir / "target.o", t["fn"])
        if not want or got != want:
            return {"status": "mismatch",
                    "why": f"in the real source it differs in {sum(a != b for a, b in zip(got, want))} slots"}
        patch = run_dir / "match.patch"
        patch.write_text(sh(["git", "diff", "--", rel]).stdout, encoding="utf-8")
        log(f"MATCH CANDIDATE {t['fn']}: {patch}")
        return {"status": "matched", "patch": str(patch)}
    finally:
        sh(["git", "checkout", "--quiet", "--", rel])  # the farm worktree stays clean


# ----------------------------------------------------------------------------- driver


def load():
    try:
        return json.loads(LEDGER.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return {"functions": {}, "state": {}}


def save(db):
    tmp = LEDGER.with_suffix(".tmp")
    tmp.write_text(json.dumps(db, indent=1), encoding="utf-8")
    os.replace(tmp, LEDGER)


def loop(a, once=False):
    idle_priority()
    ensure_worktree()
    if not take_lock():
        return
    db = load()
    log(f"farm started (pid {os.getpid()}, {a.minutes} min per function, -j {a.jobs})")
    while True:
        if not refresh(db["state"], a.refresh):
            time.sleep(300)
            continue
        todo = queue(db["functions"], a.min_pct)
        db["state"].update(queue=len(todo), current=None)
        save(db)
        if not todo:
            log("queue empty; checking again in 10 minutes")
            time.sleep(600)
            continue
        t = todo[0]
        db["state"].update(current=t["fn"], current_unit=t["unit"], current_since=time.time())
        save(db)
        log(f"{t['fn']} ({t['unit']}, {t['pct']:.2f}%, {t['size']} B); {len(todo)} in queue")
        try:
            entry = permute_one(t, a.minutes, a.jobs)
        except Exception as e:
            entry = dict(t, time=time.time(), status="refused", why=f"farm error: {e}"[:300])
        db["functions"][t["fn"]] = entry
        log(f"  -> {entry['status']}" + (f" base {entry.get('base')} best {entry.get('best')}" if "base" in entry else "")
            + (f" ({entry.get('why')})" if entry.get("why") else ""))
        save(db)
        if once:
            return


def status():
    db = load()
    fns = db["functions"].values()
    by = {}
    for e in fns:
        by[e["status"]] = by.get(e["status"], 0) + 1
    st = db.get("state", {})
    print(f"farm {FARM}; queue {st.get('queue')}; current {st.get('current')}; {by}")
    for e in sorted(fns, key=lambda e: -e.get("time", 0))[:15]:
        print(f"  {e['status']:9} {e['fn'][:34]:34} {e['pct']:6.2f}%  base {e.get('base', '-')} best {e.get('best', '-')}"
              f"  {e.get('patch') or e.get('why', '')[:60]}")


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--loop", action="store_true")
    ap.add_argument("--once", action="store_true")
    ap.add_argument("--status", action="store_true")
    ap.add_argument("--install", action="store_true")
    ap.add_argument("--uninstall", action="store_true")
    ap.add_argument("--minutes", type=float, default=10, help="permuter time per function")
    ap.add_argument("-j", "--jobs", type=int, default=10, help="permuter jobs (idle priority)")
    ap.add_argument("--min-pct", type=float, default=95)
    ap.add_argument("--refresh", type=float, default=30, help="minimum minutes between rebuilds of main")
    a = ap.parse_args()
    if a.install:
        script = FARM / "tools" / "match" / "permute_farm.py"
        tr = f'"{Path(PY).with_name("pythonw.exe")}" "{script}" --loop'
        subprocess.run(["schtasks", "/Create", "/F", "/TN", TASK_NAME, "/SC", "MINUTE", "/MO", "10", "/TR", tr], check=True)
        print(f"Scheduled '{TASK_NAME}' every 10 minutes: {tr}")
    elif a.uninstall:
        subprocess.run(["schtasks", "/Delete", "/F", "/TN", TASK_NAME], check=True)
    elif a.status:
        status()
    elif a.loop or a.once:
        try:
            loop(a, once=a.once)
        except Exception:
            log("ERROR\n" + traceback.format_exc())
            sys.exit(1)
    else:
        ap.print_help()


if __name__ == "__main__":
    main()
