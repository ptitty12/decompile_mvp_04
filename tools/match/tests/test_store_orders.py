import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from store_orders import store_span


class StoreOrderTests(unittest.TestCase):
    def test_span_preserves_crlf_and_surrounding_source(self):
        text = 'void fn_80000000(void* s)\r\n{\r\n    s->m4 = 0;\r\n    s->m8 = lbl_80000100;\r\n}\r\n'
        start, end, rows = store_span(text, 'fn_80000000', 3, 2)
        self.assertEqual(text[start:end], ''.join(rows))
        self.assertTrue(all(row.endswith('\r\n') for row in rows))
        self.assertEqual(text[:start] + ''.join(rows) + text[end:], text)

    def test_rejects_calls_repeated_fields_and_mixed_pointers(self):
        for pair in ('s->m4 = f();\ns->m8 = 0;', 's->m4 = 0;\ns->m4 = 1;',
                     's->m4 = 0;\nt->m8 = 0;', 's->m4 = t->m8;\ns->m8 = 0;'):
            with self.subTest(pair=pair), self.assertRaises(ValueError):
                store_span('void f() {\n' + pair + '\n}', 'f', 2, 2)

    def test_rejects_wrong_function_and_unbounded_search(self):
        text = 'void f() {\ns->m4 = 0;\ns->m8 = 1;\n}'
        for fn, line, count in [('other', 2, 2), ('f', 0, 2), ('f', 2, 7)]:
            with self.subTest(fn=fn, line=line, count=count), self.assertRaises(ValueError):
                store_span(text, fn, line, count)


if __name__ == '__main__':
    unittest.main()
