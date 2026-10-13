# Matching swarm — 2026-10-13

Twelve distinct workers ran in waves, with a maximum of three active workers
beside the coordinator. Assignments owned separate units. Three prepared
worktrees were reused only after their preceding workers finished; every
worker branch and its scratch evidence was preserved.

The pass produced six exact functions, totaling **1,088 code bytes**.
These are function-matching gains; none of these partially matched units was
promoted to source linking. The complete decompilation remains unfinished.

| Worker | Assignment | Result |
|---|---|---|
| 01 | Early game | No exact gain; two bounded targets parked |
| 02 | Database | `fn_80564C9C`, 164 bytes |
| 03 | Animation goals | No exact gain; 24 variants across three targets |
| 04 | Middle game | `fn_8026C864`, 152 bytes |
| 05 | Lower front end | `fn_804BB334`, 156 bytes; secondary ABI blocker and near miss |
| 06 | EA library | `fn_804006FC`, 80 bytes |
| 07 | Late game | `fn_802E7FA8`, 268 bytes |
| 08 | Sound | No exact gain; repeated-load optimization mismatch |
| 09 | Game library | No exact gain; 16 variants across two targets |
| 10 | Upper front end | `fn_804EADD4`, 268 bytes |
| 11 | Dolphin GX | No exact gain; eight register-allocation variants |
| 12 | Fresh database | No exact gain; eight scheduling variants |

## Acceptance evidence

Every winning worker ran the normal build, literal checks and unmodified
regression verifier. The baseline was the unchanged commit
`6d282adfaeffbc58f7e5e5f24726dbbb68c9a1d5`. Its archived report was independently
reproduced by the coordinator before using the verifier's supported
`--baseline FILE.json` option. Final integration also uses the repository's
per-commit gate against the then-current main branch.

Retail SHA-1: `da6becdbea614d03c4b5eae9f8a0fb08e0a184dd`.

| Function | Worker commit | Literal/reference checks |
|---|---|---|
| `fn_80564C9C` | `29e8e34a` | 67 references; zero mismatches/unresolved |
| `fn_8026C864` | `91c56f0f` | 78 references; zero mismatches/unresolved |
| `fn_804BB334` | `833ff887` | 175 references; zero mismatches/unresolved |
| `fn_804006FC` | `7a1e2810` | 119 references; zero mismatches/unresolved |
| `fn_802E7FA8` | `3b11ba93` | 144 references; zero mismatches; 20 preexisting unrelated unresolved names |
| `fn_804EADD4` | `082f4615` | 264 references; zero mismatches/unresolved |

The database predicate's otherwise-unused parameters are supported by the
retail caller at `0x804C9BBC`: two floating-point arguments in f1/f2 and integer
arguments through r7. They were not removed merely because the body ignores
them.

No protected verifier, CI, compiler flags, generated code or game assets were
modified. Failed source candidates remain in ignored scratch directories.

## Continuation

Concrete failed attempts are recorded in `docs/NEARMISS.md`. Fresh leads
inspected but not attempted include database `fn_80582B7C` and `fn_8053EA68`,
front-end `fn_804F9FD8`, and EA library `fn_804004D0` (requires evidence for its
hardware/boot-data layout).

Local evidence lives under the coordinator's `build/swarm-*` logs and the
three worker worktrees' `build/swarm01` through `build/swarm12` directories.
Workers 01/05/09/11 used SW01; 02/07 used SW02; 03/04/06/08/10/12 used SW03.
All are siblings of the original `match-shortcuts` worktree.

Repeated Ninja dependency-state recovery in SW02 caused redundant full
rebuilds even with sequential Ninja invocations and a consistent executable.
This remains a local build-cache issue to investigate separately; no build or
verification rules were weakened to avoid it.

## Verified project totals after this pass

- Exact functions: 20,910 / 24,158.
- Matched code: 3,002,884 / 5,896,176 bytes (50.93%).
- Source-linked units: 215; source-linked code: 330,388 bytes.
- Swarm contribution: six functions / 1,088 bytes. Concurrent work by the
  existing agent is included in the project totals, not in this contribution.
