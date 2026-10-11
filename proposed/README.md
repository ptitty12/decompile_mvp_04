# Proposed verifier + CI: for the OWNER to review and install

The agent is denied write access to `tools/verify/**` and `.github/workflows/**`
(`.claude/settings.json`), so these files are staged here. Installing them is
your sign-off on the verifier.

## What's here

| File | Installs to | Purpose |
|---|---|---|
| `verify/verify.py` | `tools/verify/verify.py` | The PASS/FAIL verifier (integrity, retail hash, hard rules, regressions) |
| `verify/protected.sha256` | `tools/verify/protected.sha256` | Locked hashes of verification-critical files |
| `verify/pragma_allowlist.txt` | `tools/verify/pragma_allowlist.txt` | Owner-approved `#pragma` lines (empty) |
| `workflows/build.yml` | `.github/workflows/build.yml` | CI: integrity job (GitHub-hosted) + full build on your self-hosted runner |
| `CODEOWNERS` | `.github/CODEOWNERS` | Requires your review on verifier/CI/layout changes (replace `@OWNER`) |

## What `verify.py` checks (exit code 1 on any failure)

1. **Integrity:** SHA-256 (line-ending neutral) of 9 protected files must equal `protected.sha256`.
2. **Build:** `python configure.py && ninja` must succeed. `build/GV4E69/main.dol` must equal the retail
   SHA-1 `da6becdb…84dd`, which is pinned inside `verify.py` and must also be the value in `config/GV4E69/build.sha1`.
3. **Hard rules:** no inline asm, `naked`, `.incbin` or `.s` files under `src/`/`include/`. Every `#pragma` must be
   allowlisted.
4. **Regressions** (`--baseline-ref <git ref>` or `--baseline <report.json>`): builds the ref in a worktree under
   `build/_baseline/` and fails if any unit's or function's match % dropped.

Tested by the agent on 2026-10-10 in a scratch clone with these files installed:
- (a) `--integrity-only` PASS;
- (b) full PASS;
- (c) edited `build.sha1` → FAIL;
- (d) `asm(...)` + `#pragma` in `src/` → FAIL;
- (e) worsened compiler flags on a 100%-matched unit → FAIL, listing the two regressions;
- (f) same commit as baseline → PASS.

## Install (from the repo root)

```bash
git mv proposed/verify tools/verify
```
```bash
mkdir -p .github && git mv proposed/workflows .github/workflows && git mv proposed/CODEOWNERS .github/CODEOWNERS
```
```bash
git rm proposed/README.md && git commit -m "ci: install verifier and workflow (owner-approved)"
```

Then edit `.github/CODEOWNERS` (replace `@OWNER`). Run `python tools/verify/verify.py` once to confirm PASS.
`.claude/settings.json` already denies agent edits to `tools/verify/**` and `.github/workflows/**`; no change is needed.

## CI notes / decision needed

- The template's CI keeps game files in a private container image on GitHub. This proposal instead uses a
  **self-hosted runner on your machine**, so the disc never leaves it. See the header of `workflows/build.yml`
  for runner setup (labels `self-hosted, windows, gv4e69`; env var `GV4E69_ORIG`).
- If you'd rather not run a self-hosted runner, the `integrity` job still works alone. Agents then run
  `python tools/verify/verify.py --baseline-ref origin/main` locally before every PR (as `prompts/10_WORKER.md` asks).
