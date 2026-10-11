#!/usr/bin/env python3
"""Keep the README progress card current without anyone running anything.

Registered by `--install` as a Windows scheduled task that runs every 30
minutes while the owner is logged in (pythonw, no window). Each run:

  1. fetches origin/main and stops if that commit was already handled
     (state in build/_progress/state.json);
  2. checks it out in a private worktree, build/_progress/wt, so the main
     working directory and every other branch are left alone. The disc's
     mvp.elf is copied in exactly as tools/verify/verify.py does for its
     baseline builds; the disc image itself is not;
  3. builds it (configure.py + ninja, whose default target writes
     build/GV4E69/report.json) and redraws docs/progress/ with
     `tools/progress_chart.py --if-changed`; stops if the numbers are the same;
  4. commits "docs: update progress card", runs `tools/verify/verify.py
     --baseline-ref <that origin/main>` on the commit (the project's rule
     before every push) and pushes it to main. Never forced: if
     main moved meanwhile the push is rejected and the next run starts over
     from the new main.

A failed build or verify is logged and not retried until main changes again.
Log: build/_progress/bot.log.

Usage:
  python tools/progress_bot.py               # one run (what the task does)
  python tools/progress_bot.py --force       # run even if origin/main was handled
  python tools/progress_bot.py --no-push     # everything except the push (testing)
  python tools/progress_bot.py --ref REF     # build REF instead of origin/main (testing; never pushes)
  python tools/progress_bot.py --install     # register the scheduled task
  python tools/progress_bot.py --uninstall   # remove it
"""
import argparse
import datetime
import json
import os
import shutil
import subprocess
import sys
import time
import traceback
from pathlib import Path
from typing import List, Optional

ROOT = Path(__file__).resolve().parent.parent
VERSION = "GV4E69"
TASK_NAME = "MVP decomp progress card"
BOT_DIR = ROOT / "build" / "_progress"
WT = BOT_DIR / "wt"
STATE = BOT_DIR / "state.json"
LOG = BOT_DIR / "bot.log"
LOCK = BOT_DIR / "lock"
DISC_IMAGES = {".iso", ".ciso", ".rvz", ".gcm", ".wbfs", ".wia", ".gcz", ".nfs", ".tgc"}
COMMIT_SUBJECT = "docs: update progress card"

# Sign git in with the gh CLI's token for fetch/push, without changing any config.
GIT_AUTH = ["-c", "credential.helper=", "-c", "credential.helper=!gh auth git-credential"]
ENV = dict(os.environ, GIT_TERMINAL_PROMPT="0", GCM_INTERACTIVE="never")
# Under pythonw there is no console; give children a hidden one instead of a popup each.
NO_WINDOW = getattr(subprocess, "CREATE_NO_WINDOW", 0)
PY = str(Path(sys.executable).with_name("python.exe")) if Path(sys.executable).name.lower() == "pythonw.exe" else sys.executable


class BotError(Exception):
    pass


def log(msg: str) -> None:
    BOT_DIR.mkdir(parents=True, exist_ok=True)
    if LOG.is_file() and LOG.stat().st_size > 1_000_000:
        os.replace(LOG, LOG.with_suffix(".log.1"))
    stamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    with open(LOG, "a", encoding="utf-8") as f:
        for line in msg.splitlines() or [""]:
            f.write(f"{stamp}  {line}\n")
    if sys.stdout is not None:
        print(msg, flush=True)


def run(cmd: List[str], cwd: Path, check: bool = True) -> subprocess.CompletedProcess:
    log(f"+ {' '.join(cmd)}   [{cwd}]")
    r = subprocess.run(
        cmd, cwd=cwd, env=ENV, creationflags=NO_WINDOW,
        stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, encoding="utf-8", errors="replace",
    )
    lines = (r.stdout or "").rstrip().splitlines()
    if lines:
        log("\n".join(lines[-60:]))
    if check and r.returncode:
        raise BotError(f"{' '.join(cmd[:3])} ... failed with exit code {r.returncode}")
    return r


def git(cwd: Path, *args: str, check: bool = True) -> str:
    return run(["git", *args], cwd, check).stdout.strip()


def load_state() -> dict:
    try:
        return json.loads(STATE.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return {}


def save_state(**state: str) -> None:
    state["time"] = datetime.datetime.now().isoformat(timespec="seconds")
    STATE.write_text(json.dumps(state, indent=2) + "\n", encoding="utf-8")


def prepare_worktree(target: str) -> None:
    if (WT / ".git").exists():
        # Only docs/progress/ is ever modified here; put it back before moving on.
        git(WT, "checkout", "--quiet", "HEAD", "--", "docs/progress")
        git(WT, "checkout", "--quiet", "--detach", target)
    else:
        git(ROOT, "worktree", "prune")
        git(ROOT, "worktree", "add", "--detach", str(WT), target)

    src, dst = ROOT / "orig" / VERSION, WT / "orig" / VERSION
    dst.mkdir(parents=True, exist_ok=True)
    for p in src.iterdir():
        if p.is_file() and p.suffix.lower() not in DISC_IMAGES and not (dst / p.name).exists():
            shutil.copyfile(p, dst / p.name)
    if not (dst / "mvp.elf").is_file():
        elf = ROOT / "build" / VERSION / "orig" / "mvp.elf"
        if not elf.is_file():
            raise BotError(f"{elf} is missing; build the main checkout once (ninja) so it is extracted")
        shutil.copyfile(elf, dst / "mvp.elf")


def bot(force: bool, push: bool, ref: str) -> None:
    git(ROOT, *GIT_AUTH, "fetch", "--quiet", "origin", "main")
    target = git(ROOT, "rev-parse", ref)
    state = load_state()
    if not force and state.get("handled") == target:
        log(f"origin/main {target[:10]} already handled ({state.get('result')}); nothing to do")
        return

    log(f"{ref} is {target[:10]}; building it")
    testing = ref != "origin/main"
    try:
        prepare_worktree(target)
        ninja = shutil.which("ninja")
        if not ninja:
            raise BotError("ninja is not on PATH")
        run([PY, "configure.py"], WT)
        run([ninja], WT)
        chart = run([PY, "tools/progress_chart.py", "--if-changed"], WT)
        if not git(WT, "status", "--porcelain", "--", "docs/progress"):
            log("progress numbers unchanged; nothing to commit")
            if not testing:
                save_state(handled=target, result="unchanged")
            return

        summary = chart.stdout.strip().splitlines()[0]
        git(WT, "add", "--", "docs/progress")
        git(WT, "commit", "--quiet", "-m", COMMIT_SUBJECT, "-m",
            f"{summary}\n\nAutomated by tools/progress_bot.py from a build of {target[:10]}.")
        # The project's pre-push check, with the baseline pinned to the main we built on
        # (origin/main itself may move if another session fetches meanwhile).
        r = run([PY, "tools/verify/verify.py", "--baseline-ref", target], WT, check=False)
        if r.returncode or "VERIFY PASS" not in r.stdout:
            raise BotError("verify.py did not pass; not pushing")
    except BotError as e:
        log(f"FAILED: {e}")
        if not testing:
            save_state(handled=target, result=f"failed: {e}")
        return

    head = git(WT, "rev-parse", "HEAD")
    if not push:
        log(f"--no-push: verified commit {head[:10]} left in {WT}")
        return
    r = run(["git", *GIT_AUTH, "push", "origin", "HEAD:refs/heads/main"], WT, check=False)
    if r.returncode:
        log("push rejected (main probably moved); the next run starts from the new main")
        return
    log(f"pushed {head[:10]}: {summary}")
    save_state(handled=head, result="pushed")


def acquire_lock() -> bool:
    BOT_DIR.mkdir(parents=True, exist_ok=True)
    try:
        if LOCK.is_file() and time.time() - LOCK.stat().st_mtime > 2 * 3600:
            LOCK.unlink()  # left behind by a run that died
        fd = os.open(LOCK, os.O_CREAT | os.O_EXCL | os.O_WRONLY)
    except FileExistsError:
        return False
    os.write(fd, str(os.getpid()).encode())
    os.close(fd)
    return True


def install(every: int) -> None:
    pythonw = Path(PY).with_name("pythonw.exe")
    tr = f'"{pythonw}" "{Path(__file__).resolve()}"'
    subprocess.run(
        ["schtasks", "/Create", "/F", "/TN", TASK_NAME, "/SC", "MINUTE", "/MO", str(every), "/TR", tr],
        check=True,
    )
    print(f"Scheduled '{TASK_NAME}' every {every} minutes: {tr}")


def uninstall() -> None:
    subprocess.run(["schtasks", "/Delete", "/F", "/TN", TASK_NAME], check=True)


def main(argv: Optional[List[str]] = None) -> None:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--force", action="store_true", help="run even if origin/main was already handled")
    ap.add_argument("--no-push", action="store_true", help="do everything except the push")
    ap.add_argument("--ref", default="origin/main", help="build this ref instead (testing; never pushes)")
    ap.add_argument("--install", action="store_true", help="register the scheduled task")
    ap.add_argument("--every", type=int, default=30, help="minutes between runs (with --install)")
    ap.add_argument("--uninstall", action="store_true", help="remove the scheduled task")
    args = ap.parse_args(argv)

    if args.install:
        install(args.every)
        return
    if args.uninstall:
        uninstall()
        return
    if not acquire_lock():
        log("another run is in progress; skipping")
        return
    try:
        bot(args.force, not args.no_push and args.ref == "origin/main", args.ref)
    except Exception:
        log("ERROR\n" + traceback.format_exc())
        sys.exit(1)
    finally:
        LOCK.unlink(missing_ok=True)


if __name__ == "__main__":
    main()
