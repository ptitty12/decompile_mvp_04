import re
def insert(src, text):
    """Append text to src; if the unit body is wrapped in extern "C" { ... } closed by a final '}', insert before it."""
    nl = '\r\n' if src.count('\r\n') > src.count('\n')//2 else '\n'
    s = src.replace('\r\n','\n')
    t = text.replace('\r\n','\n')
    st = s.rstrip('\n')
    if re.search(r'^extern "C" \{$', s, re.M) and st.endswith('\n}'):
        body = st[:-1].rstrip('\n')
        out = body + '\n\n' + t.strip('\n') + '\n\n}\n'
    else:
        out = st + '\n\n' + t.strip('\n') + '\n'
    return out.replace('\n', nl)
