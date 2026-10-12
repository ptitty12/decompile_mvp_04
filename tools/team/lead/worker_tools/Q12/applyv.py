"""applyv.py unit fn variant-name : apply a variant from Q12/v1.txt via ins.py"""
import sys, re, subprocess
unit, fn, name = sys.argv[1:4]
Q = 'C:/Users/PATRIC~1/AppData/Local/Temp/claude/C--Users-Patrick-Taylor-decompile-mvp-04/ddf206fc-e9e3-4b5f-93d0-98c4cc873084/scratchpad/Q12'
blocks = re.split(r'^//// *(.*)$', open(Q + '/v1.txt').read(), flags=re.M)
for i in range(1, len(blocks), 2):
    if blocks[i].strip() == name:
        open(Q + '/f.txt', 'w').write(blocks[i + 1].strip('\n') + '\n')
        r = subprocess.run(['python', Q + '/ins.py', unit, fn, Q + '/f.txt', '--auto'], capture_output=True, text=True)
        print(r.stdout, r.stderr)
        break
else:
    print('variant not found')
