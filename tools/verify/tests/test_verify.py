"""Source-free verifier tests: python -m unittest discover -s tools/verify/tests -v."""
import contextlib
import copy
import importlib.util
import io
import json
import random
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch


SCRIPT = Path(__file__).resolve().parents[1] / "verify.py"
spec = importlib.util.spec_from_file_location("project_verify", SCRIPT)
verify = importlib.util.module_from_spec(spec)
spec.loader.exec_module(verify)


def function(name="fn_80001000", percent=100.0, address=0, size=16, virtual=None):
    result = {"name": name, "fuzzy_match_percent": percent,
              "address": str(address), "size": str(size)}
    if virtual is not None:
        result["metadata"] = {"virtual_address": str(virtual)}
    return result


def unit(name, functions):
    total = sum(int(f["size"]) for f in functions)
    matched = sum(int(f["size"]) for f in functions if f["fuzzy_match_percent"] == 100)
    fuzzy = sum(int(f["size"]) * f["fuzzy_match_percent"] for f in functions)
    return {"name": "main/" + name, "functions": functions, "measures": {
        "total_code": str(total), "matched_code": str(matched),
        "matched_code_percent": 100 * matched / total if total else 100,
        "fuzzy_match_percent": fuzzy / total if total else 100}}


class VerifierTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)

    def run_check(self, call, passes, message=None):
        output = io.StringIO()
        with contextlib.redirect_stdout(output):
            if passes:
                call()
            else:
                with self.assertRaises(SystemExit) as raised:
                    call()
                self.assertEqual(raised.exception.code, 1)
        if message:
            self.assertIn(message, output.getvalue())
        return output.getvalue()

    def compare(self, baseline, current, passes=True, message=None):
        bp, cp = self.root / "baseline.json", self.root / "current.json"
        bp.write_text(json.dumps({"units": baseline}), encoding="utf-8")
        cp.write_text(json.dumps({"units": current}), encoding="utf-8")
        return self.run_check(lambda: verify.check_regressions(cp, bp), passes, message)

    def hard_rules(self, source, allowlist, passes=True, suffix=".c"):
        (self.root / "src").mkdir(exist_ok=True)
        (self.root / "src" / ("example" + suffix)).write_text(source, encoding="utf-8")
        allowed = self.root / "allowlist.txt"
        if allowlist is not None:
            allowed.write_text(allowlist, encoding="utf-8")
        with patch.multiple(verify, ROOT=self.root, SOURCE_DIRS=[self.root / "src"],
                            PRAGMA_ALLOWLIST=allowed):
            self.run_check(verify.check_hard_rules, passes)

    def split(self):
        a = function("fn_80001000", 0, 0)
        b = function("fn_80001010", 100, 16)
        return ([unit("sdk/old", [a, b])],
                [unit("sdk/old", [a]), unit("sdk/new", [dict(b, address="0")])])

    def test_all_six_approved_pragmas(self):
        approved = (SCRIPT.parent / "pragma_allowlist.txt").read_text(encoding="utf-8")
        directives = [line for line in approved.splitlines() if line.startswith("#pragma ")]
        self.assertEqual(len(directives), 6)
        self.hard_rules("\n".join(directives), approved)

    def test_approved_pragma_with_indentation_and_comment(self):
        self.hard_rules("  #pragma cplusplus on // SDK setting\n",
                        "# comment\n\n  #pragma cplusplus on\n")

    def test_explicitly_approved_tab_separated_pragma(self):
        self.hard_rules("#pragma\tcplusplus on\n", "#pragma\tcplusplus on\n")

    def test_comment_with_pragma_prefix_is_not_an_entry(self):
        self.hard_rules("#pragmatic comment\n", "#pragmatic comment\n", False)

    def test_unapproved_pragma_still_fails(self):
        self.hard_rules("#pragma pack(1)\n", "#pragma cplusplus on\n", False)

    def test_pragma_approval_is_exact(self):
        self.hard_rules("#pragma cplusplus off\n", "#pragma cplusplus on\n", False)

    def test_comments_are_not_pragma_approvals(self):
        self.hard_rules("#pragma cplusplus on\n", "# approved: #pragma cplusplus on\n", False)

    def test_missing_allowlist_still_fails(self):
        self.hard_rules("#pragma cplusplus on\n", None, False)

    def test_banned_source_remains_rejected(self):
        for source in ("__asm__(\"nop\");", "void naked f(void);", ".incbin blob"):
            with self.subTest(source=source):
                self.hard_rules(source, "", False)

    def test_assembly_source_remains_rejected(self):
        self.hard_rules("", "", False, suffix=".s")

    def test_unchanged_report_passes(self):
        baseline, _ = self.split()
        self.compare(baseline, baseline)

    def test_improvement_passes(self):
        self.compare([unit("sdk/a", [function(percent=90)])],
                     [unit("sdk/a", [function(percent=100)])])

    def test_outgoing_matched_function_is_not_a_regression(self):
        self.compare(*self.split())

    def test_fully_vanished_unit_is_a_move(self):
        self.compare([unit("sdk/old", [function()])], [unit("sdk/new", [function()])])

    def test_incoming_unmatched_function_does_not_dilute_baseline_cohort(self):
        a, b = function(), function("fn_80001010", 0, 0, 32)
        self.compare([unit("sdk/a", [a]), unit("sdk/b", [b])],
                     [unit("sdk/a", [a, dict(b, address="16")])])

    def test_moved_score_drop_fails_even_when_other_function_improves(self):
        for score in (100, 50):
            with self.subTest(score=score):
                a, b = function(percent=0), function("fn_80001010", score, 16)
                self.compare([unit("sdk/a", [a, b])],
                             [unit("sdk/a", [dict(a, fuzzy_match_percent=100)]),
                              unit("sdk/b", [dict(b, address="0", fuzzy_match_percent=score - 1)])],
                             False, "function fn_80001010")

    def test_unchanged_unit_aggregate_drop_still_fails(self):
        baseline = [unit("sdk/a", [function()])]
        current = copy.deepcopy(baseline)
        current[0]["measures"]["matched_code_percent"] = 99
        self.compare(baseline, current, False, "unit main/sdk/a: matched code")

    def test_unchanged_unit_fuzzy_drop_still_fails(self):
        baseline = [unit("sdk/a", [function(percent=50)])]
        current = copy.deepcopy(baseline)
        current[0]["measures"]["fuzzy_match_percent"] = 49
        self.compare(baseline, current, False, "unit main/sdk/a: fuzzy")

    def test_missing_scored_function_fails(self):
        self.compare([unit("sdk/a", [function()])], [], False, "function fn_80001000")

    def test_moved_target_size_change_fails(self):
        self.compare([unit("sdk/a", [function(size=16)])],
                     [unit("sdk/b", [function(size=12)])], False)

    def test_virtual_address_conflict_prevents_move(self):
        self.compare([unit("sdk/a", [function(virtual=0x80001000)])],
                     [unit("sdk/b", [function(virtual=0x80002000)])], False)

    def test_virtual_address_agreement_allows_move_with_changed_relative_offset(self):
        self.compare([unit("sdk/a", [function(address=16, virtual=0x80001000)])],
                     [unit("sdk/b", [function(address=0, virtual=0x80001000)])])

    def test_cross_module_name_does_not_establish_identity(self):
        current = [unit("sdk/b", [function()])]
        current[0]["name"] = "other/sdk/b"
        self.compare([unit("sdk/a", [function()])], current, False)

    def test_duplicate_names_in_current_prevent_move(self):
        self.compare([unit("sdk/a", [function()])],
                     [unit("sdk/b", [function()]), unit("sdk/c", [function()])], False)

    def test_duplicate_names_in_baseline_prevent_move(self):
        self.compare([unit("sdk/a", [function()]), unit("sdk/b", [function()])],
                     [unit("sdk/b", [function()]), unit("sdk/c", [function()])], False)

    def test_duplicate_names_of_different_sizes_still_prevent_move(self):
        self.compare([unit("sdk/a", [function()])],
                     [unit("sdk/b", [function()]), unit("sdk/c", [function(size=32)])], False)

    def test_relative_address_is_not_cross_unit_identity(self):
        self.compare([unit("sdk/a", [function()])],
                     [unit("sdk/b", [function(name="different")])], False)

    def test_same_unit_rename_at_zero_offset_still_passes(self):
        self.compare([unit("sdk/a", [function()])],
                     [unit("sdk/a", [function(name="SDKRealName")])])

    def test_same_unit_rename_score_drop_fails(self):
        self.compare([unit("sdk/a", [function()])],
                     [unit("sdk/a", [function(name="SDKRealName", percent=99)])], False)

    def test_same_unit_name_drop_cannot_be_hidden_by_copy_elsewhere(self):
        self.compare([unit("sdk/a", [function()])],
                     [unit("sdk/a", [function(percent=99)]), unit("sdk/b", [function()])], False)

    def test_move_resolved_before_relative_offset_rename(self):
        a, b = function(), function("fn_80001010", 0, 16)
        self.compare([unit("sdk/a", [a, b])],
                     [unit("sdk/a", [dict(b, address="0")]), unit("sdk/b", [a])])

    def test_same_unit_rename_cannot_reuse_matched_function(self):
        a, alias = function(), function("alias", 100, 0)
        self.compare([unit("sdk/a", [a, alias])], [unit("sdk/a", [a])], False)

    def test_ambiguous_relative_address_rename_fails(self):
        self.compare([unit("sdk/a", [function()])],
                     [unit("sdk/a", [function(name="one"), function(name="two")])], False)

    def test_duplicate_function_entries_fail_closed(self):
        duplicate = [unit("sdk/a", [function(), function()])]
        self.compare(duplicate, duplicate, False, "duplicate function")

    def test_duplicate_unit_entries_fail_closed(self):
        duplicate = [unit("sdk/a", [function()]), unit("sdk/a", [function()])]
        self.compare(duplicate, duplicate, False, "duplicate unit")

    def test_data_only_unit_disappearance_still_passes(self):
        baseline = [unit("data", []), unit("sdk/a", [function()])]
        self.compare(baseline, baseline[1:])

    def test_incomplete_baseline_coverage_rejects_reweighting(self):
        baseline, current = self.split()
        baseline[0]["measures"]["total_code"] = "36"
        self.compare(baseline, current, False, "cannot safely compare")

    def test_incomplete_current_coverage_rejects_reweighting(self):
        baseline, current = self.split()
        current[1]["measures"]["total_code"] = "20"
        self.compare(baseline, current, False, "cannot safely compare")

    def test_inconsistent_matched_bytes_reject_reweighting(self):
        baseline, current = self.split()
        current[1]["measures"]["matched_code"] = "12"
        self.compare(baseline, current, False, "cannot safely compare")

    def test_unmapped_addition_rejects_reweighting(self):
        baseline, current = self.split()
        current[1] = unit("sdk/new", current[1]["functions"] + [function("added", 0, 16)])
        self.compare(baseline, current, False, "cannot safely compare")

    def test_stationary_size_change_in_affected_unit_fails(self):
        baseline, current = self.split()
        current[0] = unit("sdk/old", [function("fn_80001000", 0, 0, 12)])
        self.compare(baseline, current, False, "cannot safely compare")

    def test_reweighting_uses_identical_baseline_weights_and_not_rounded_aggregate(self):
        a, b = function(percent=33.333332, size=28), function("fn_80001010", 100, 28, 44)
        baseline = [unit("sdk/a", [a, b])]
        baseline[0]["measures"]["fuzzy_match_percent"] += 0.000003
        self.compare(baseline, [unit("sdk/a", [a]), unit("sdk/b", [dict(b, address="0")])])

    def test_integrity_still_rejects_tampered_protected_file(self):
        protected = self.root / "protected.py"
        protected.write_text("original\n", encoding="utf-8")
        manifest = self.root / "protected.sha256"
        manifest.write_text(f"{verify.sha256(protected)}  protected.py\n", encoding="utf-8")
        with patch.multiple(verify, ROOT=self.root, PROTECTED_LIST=manifest):
            self.run_check(verify.check_integrity, True)
            protected.write_text("changed\n", encoding="utf-8")
            self.run_check(verify.check_integrity, False, "hash changed")

    def test_seeded_split_merge_permutations_and_real_drops(self):
        rng = random.Random(2005)
        for iteration in range(30):
            with self.subTest(iteration=iteration):
                functions = [function(f"fn_{0x80000000 + i * 256:08X}",
                                      rng.choice([0, 33.333332, 75, 100]),
                                      size=rng.randrange(1, 33) * 4) for i in range(24)]
                functions[0]["fuzzy_match_percent"] = 100

                def redistribute(count, prefix):
                    buckets = [[] for _ in range(count)]
                    for f in functions:
                        bucket = rng.choice(buckets)
                        bucket.append(dict(f, address=str(sum(int(x["size"]) for x in bucket))))
                    return [unit(f"sdk/{prefix}{i}", bucket)
                            for i, bucket in enumerate(buckets) if bucket]

                baseline = redistribute(4, "old")
                current = redistribute(6, "new")
                self.compare(baseline, current)
                for u in current:
                    for f in u["functions"]:
                        if f["name"] == functions[0]["name"]:
                            f["fuzzy_match_percent"] = 99
                    u["measures"] = unit("unused", u["functions"])["measures"]
                self.compare(baseline, current, False, "function fn_80000000")


if __name__ == "__main__":
    unittest.main()
