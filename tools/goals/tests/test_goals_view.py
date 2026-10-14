"""goals_view.py's parsers on synthetic text (no git, no build)."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import goals_view as gv  # noqa: E402

ROADMAP = """\
## 4. Milestones

### Engine track

| # | Milestone | Exit |
|---|---|---|
| E0a | **Recompiler survey.** Evaluate things. | `docs/engine/E0_SURVEY.md` exists |
| E1 | **First pixels (native).** GX to WebGPU. | The title screen renders |
| Later | Extra team slots | Planned when E7 is done |

### Knowledge track

| # | Milestone | Exit |
|---|---|---|
| K1 | **SDK boundary named.** Names. | ≥ 98% of K1 functions named |
| K5 | **Game-state map (later).** State. | Planned after E5 |

**Dependencies:**
"""

LOG_WITH_COMMIT_COLUMN = """\
# E0b log: native boot spike

## Status

| # | Item | State | Commit |
|---|---|---|---|
| 1 | Skeleton | Done | see git log |
| 2 | Disc | Done (one commit with 3) | see git log |
| 3 | Decoder | To do | |

## Layout
"""

LOG_LAST = """\
# E2 log: browser groundwork

## Status

| # | Step | State |
|---|---|---|
| 1 | Builds for wasm | Done |
| 2 | Baseline | |
"""


class GoalsViewTest(unittest.TestCase):
    def test_roadmap_tables(self):
        engine, knowledge = gv.roadmap_tables(ROADMAP)
        self.assertEqual([r["id"] for r in engine], ["E0a", "E1"])
        self.assertEqual(engine[0]["name"], "Recompiler survey")
        self.assertEqual(engine[1]["exit"], "The title screen renders")
        self.assertEqual([(r["id"], r["threshold"]) for r in knowledge], [("K1", 98), ("K5", None)])

    def test_log_steps_uses_the_state_column(self):
        self.assertEqual(gv.log_steps(LOG_WITH_COMMIT_COLUMN), (2, 3))
        self.assertEqual(gv.log_steps(LOG_LAST), (1, 2))
        self.assertIsNone(gv.log_steps("# E9 log: nothing yet\n"))

    def test_log_title(self):
        self.assertEqual(gv.log_title(LOG_LAST), "browser groundwork")

    def test_milestone_tag(self):
        self.assertEqual(gv.milestone_tag("engine(ppc): Gekko decoder (E0b item 3)"), "E0b")
        self.assertEqual(gv.milestone_tag("engine(gfx): texture decoders to RGBA8 (E1)"), "E1")
        self.assertEqual(gv.milestone_tag("docs(engine): E0a recompiler survey"), "E0a")
        self.assertEqual(gv.milestone_tag("docs: E0c decisions (D4b, IN1, AX1)"), "E0c")
        self.assertIsNone(gv.milestone_tag("docs(rosters): team slot asset mapping (K2, for E7)"))
        self.assertIsNone(gv.milestone_tag("name(ealib/vp6): 98 more VP6 decoder functions named (tier E)"))

    def test_ticks_are_ascending_and_inside(self):
        t0, t1 = 1792000000.0, 1792000000.0 + 6.2 * 3600
        ts = gv.ticks(t0, t1)
        self.assertTrue(ts and all(t0 < t <= t1 for t, _ in ts))
        self.assertEqual([t for t, _ in ts], sorted(t for t, _ in ts))
        self.assertLessEqual(len(gv.ticks(t0, t0 + 30 * 86400)), 8)


if __name__ == "__main__":
    unittest.main()
