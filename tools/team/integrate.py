"""Merge worker branches onto origin/main, verify every step, optionally push.

Run from an integration worktree (one with orig/ and a working build), e.g.:

    python tools/team/integrate.py work/circle work/linear --push
    python tools/team/integrate.py --push      # lead mode: verify and push the current branch's own commits

Steps:
1. Fetch, then start `integrate/auto` from origin/main (refuses a dirty tree).
2. For each branch: refuse it if it changes files outside the allowed paths
   (default: src/, include/); otherwise merge it (--no-ff). Conflicts in
   configure.py are append-style Object lists and are resolved by keeping both
   sides; any other conflict aborts that branch's merge and it is reported.
3. Build, check main.dol against config/GV4E69/build.sha1, then run
   tools/verify/verify.py on every first-parent commit against its parent.
4. With --push, and only if everything passed and origin/main has not moved,
   push HEAD to main.

It decides nothing about matching itself: verify.py does.
"""
import argparse
import hashlib
import os
import subprocess
import sys
from pathlib import Path

ALLOWED_DEFAULT = ("src/", "include/")


def run(*args, check=True, capture=True):
    r = subprocess.run(args, capture_output=capture, text=True)
    if check and r.returncode != 0:
        raise SystemExit(f"command failed ({r.returncode}): {' '.join(args)}\n{r.stdout}\n{r.stderr}")
    return r


def git(*args, check=True):
    return run("git", *args, check=check).stdout.strip()


def union_resolve(path: Path) -> int:
    out, ours, theirs, state, hunks = [], [], [], None, 0
    for line in path.read_text().splitlines(keepends=True):
        if line.startswith("<<<<<<< "):
            state, ours, theirs = "ours", [], []
        elif line.startswith("||||||| ") and state == "ours":
            state = "base"
        elif line.startswith("=======") and state in ("ours", "base"):
            state = "theirs"
        elif line.startswith(">>>>>>> ") and state == "theirs":
            out += ours + [l for l in theirs if l not in ours]
            state, hunks = None, hunks + 1
        elif state == "ours":
            ours.append(line)
        elif state == "theirs":
            theirs.append(line)
        elif state is None:
            out.append(line)
    if state is not None:
        raise SystemExit(f"{path}: unterminated conflict")
    path.write_text("".join(out))
    return hunks


def build_ok() -> bool:
    run(sys.executable, "configure.py")
    r = run("ninja", check=False)
    if r.returncode != 0:
        print(r.stdout[-3000:], r.stderr[-2000:])
        return False
    want = Path("config/GV4E69/build.sha1").read_text().split()[0].lower()
    got = hashlib.sha1(Path("build/GV4E69/main.dol").read_bytes()).hexdigest()
    print(f"main.dol {got} ({'OK' if got == want else 'MISMATCH, want ' + want})")
    return got == want


def verify(baseline: str) -> bool:
    r = run(sys.executable, "tools/verify/verify.py", "--baseline-ref", baseline, check=False)
    tail = [l for l in r.stdout.splitlines() if l.startswith(("VERIFY", "regressions", "  "))][-6:]
    print("    " + "\n    ".join(tail))
    return r.returncode == 0


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("branches", nargs="*", help="worker branches; none = verify the current branch's own commits")
    ap.add_argument("--push", action="store_true")
    ap.add_argument("--allow", action="append", default=[], help="extra allowed path prefix")
    a = ap.parse_args()
    allowed = ALLOWED_DEFAULT + tuple(a.allow)

    # Content check: `git status` here sometimes flags splits.txt as modified
    # when its bytes equal HEAD's (merge-driver attributes), so compare content.
    if run("git", "diff", "--quiet", "HEAD", "--", check=False).returncode != 0:
        raise SystemExit("working tree has uncommitted changes; refusing")
    git("fetch", "-q", "origin")
    base = git("rev-parse", "origin/main")
    if not a.branches:
        # Lead mode: the current branch's commits on top of origin/main.
        if git("merge-base", "HEAD", "origin/main") != base:
            raise SystemExit("current branch is not on top of origin/main; rebase first")
        work = git("rev-parse", "--abbrev-ref", "HEAD")
        if not git("rev-list", f"{base}..HEAD"):
            raise SystemExit("no commits to verify")
        finish(base, work, a.push)
        return
    git("checkout", "-q", "-B", "integrate/auto", "origin/main")

    merged, refused = [], []
    for b in a.branches:
        mb = git("merge-base", b, "origin/main")
        files = git("diff", "--name-only", mb, b).splitlines()
        bad = [f for f in files if not f.startswith(allowed)]
        if bad:
            refused.append(f"{b}: touches {', '.join(bad[:5])}")
            continue
        r = run("git", "merge", "--no-ff", "--no-edit", b, check=False)
        if r.returncode != 0:
            conflicted = git("diff", "--name-only", "--diff-filter=U").splitlines()
            if conflicted == ["configure.py"]:
                print(f"{b}: configure.py union-resolved ({union_resolve(Path('configure.py'))} hunks)")
                git("add", "configure.py")
                git("commit", "-q", "--no-edit")
            else:
                git("merge", "--abort")
                refused.append(f"{b}: conflicts in {', '.join(conflicted)}")
                continue
        merged.append(b)
        print(f"merged {b} ({len(files)} files)")

    for line in refused:
        print("REFUSED", line)
    if not merged:
        raise SystemExit("nothing merged")
    finish(base, "integrate/auto", a.push)


def finish(base: str, branch: str, push: bool) -> None:
    """Build, verify every first-parent commit since `base`, push if asked and all pass."""
    if not build_ok():
        raise SystemExit("build check failed; not pushing")
    head = git("rev-parse", "HEAD")
    ok = True
    for c in git("rev-list", "--first-parent", "--reverse", f"{base}..HEAD").splitlines():
        git("checkout", "-q", "-f", "--detach", c)  # -f: content was checked clean at start
        print(f"  {git('log', '--oneline', '-1', c)[:70]}")
        ok = verify(f"{c}~1") and ok
    git("checkout", "-q", "-f", branch)
    if git("rev-parse", "HEAD") != head:
        raise SystemExit("HEAD moved during verification")
    if not ok:
        raise SystemExit("verification failed; not pushing")
    if not build_ok():
        raise SystemExit("rebuild at HEAD failed; not pushing")
    print("all commits VERIFY PASS")
    if push:
        git("fetch", "-q", "origin")
        if git("rev-parse", "origin/main") != base:
            raise SystemExit("origin/main moved; rerun to rebase")
        r = run("git", "push", "origin", "HEAD:main", check=False)
        print((r.stdout + r.stderr).strip())
        if r.returncode != 0:
            raise SystemExit("push failed")


if __name__ == "__main__":
    main()
