"""Locate compiled data sections in retail from a successful current build.

Read-only shortlist for proper section ownership: pair relocations in matched
code and existing canonical global object symbols, follow initialized pointers
from anchored sections, then try unique
aligned full-section byte matches for unreferenced pools. Zero blocks and
ambiguous matches are never placed by search. All initialized pointer
relocations must resolve and every byte must agree at the proposed placement.

A placement is not proof of TU ownership or source-link correctness. Check
existing splits and external users before changing ownership. Keep a source
promotion only after the final retail DOL hash, check_literals and the
unmodified verifier pass. Never edit generated assembly or linker scripts.

    python tools/match/data_candidates.py [unit ...] [--ready] [--json]
"""
import argparse,json,struct,re
from pathlib import Path
from check_literals import Elf,BUILD,CODE_SECTIONS
from link_candidates import candidates,allocated_layout

def starts():
 result={};unit=None
 for line in Path('config/GV4E69/splits.txt').read_text().splitlines():
  if line and not line[0].isspace():
   unit=line.rstrip(':').rsplit('.',1)[0]
  elif unit:
   m=re.match(r'\s*(\.[\w.]+)\s+start:0x([0-9A-Fa-f]+)',line)
   if m:result[unit,m[1]]=int(m[2],16)
 return result

def address_map(linked):
 out={}
 for n,v,_,_,sh in linked.syms:
  if sh:out.setdefault(n,set()).add(v)
 return {n:next(iter(v)) for n,v in out.items() if len(v)==1}

def bytes_at(linked,addr,size):
 for sec in linked.secs:
  if sec[3] and sec[3]<=addr and addr+size<=sec[3]+sec[5]:
   if sec[1]==8:return bytes(size)
   start=sec[4]+addr-sec[3];return linked.data[start:start+size]
 return None

def proof(unit,linked,unit_starts,exports,source_object=None):
 a=Elf(BUILD/'obj'/(unit+'.o'));b=Elf(source_object or BUILD/'src'/(unit+'.o'))
 ti=a.text_index();bi=b.text_index()
 start=unit_starts.get((unit,a.names[ti]))
 if start is None:return {'error':'no split code start'}
 tf=a.funcs(ti);sf=b.funcs(bi);tr=a.relocs(ti);sr=b.relocs(bi)
 allocated=[i for i,s in enumerate(b.secs) if s[2]&2 and s[5] and b.names[i] not in CODE_SECTIONS]
 bases={i:set() for i in allocated};unknown=[]
 # A canonical global object definition anchors even a zero-filled section.
 # ProDG C emits sized globals as STT_NOTYPE; accept those as well as OBJECT.
 # Local labels and section symbols cannot establish ownership by name.
 for n,v,size,info,sh in b.syms:
  if sh not in bases or info>>4!=1 or info&15 not in (0,1) or not size or n not in exports:continue
  actual=exports[n]-v
  wanted=next((s for name,s in zip(linked.names,linked.secs) if name==b.names[sh]),None)
  if wanted and wanted[3]<=actual and actual+b.secs[sh][5]<=wanted[3]+wanted[5]:
   bases[sh].add(actual)
 def target_address(rel):
  si,_,add=rel;n,v,_,_,sh=a.syms[si]
  if sh==ti:return start+v+add
  if n in exports:return exports[n]+add
  return None
 for n,(off,sz) in tf.items():
  if n not in sf or sf[n][1]!=sz:continue
  soff=sf[n][0]
  # ProDG's ADDR16 relocations can address the immediate halfword (+2),
  # while SDA21 relocations address the instruction word. Visit both.
  for source_pos,source in sr.items():
   if not soff<=source_pos<soff+sz:continue
   pos=source_pos-soff;target=tr.get(off+pos)
   si,_,add=source;sn,sv,_,_,sh=b.syms[si]
   if sh not in bases:continue
   if not target:
    unknown.append({'function':n,'offset':pos,'source':sn});continue
   actual=target_address(target)
   if actual is not None:bases[sh].add(actual-sv-add)
 base={i:next(iter(v)) for i,v in bases.items() if len(v)==1}
 def resolve(si,add):
  n,v,_,_,sh=b.syms[si]
  if sh==bi:
   at=v+add
   for fname,(fo,fs) in sf.items():
    if fname in tf and fo<=at<fo+fs:return start+tf[fname][0]+at-fo
   return None
  if sh in base:return base[sh]+v+add
  if sh==0 and n in exports:return exports[n]+add
  if sh==0xfff1:return v+add
  return None
 # Unreferenced literal pools still exist in this SN C build. Locate only
 # unique, aligned full-section byte matches; never guess from a zero block.
 for _ in range(len(allocated)+2):
  prior=dict(base)
  for i in allocated:
   if i not in base:continue
   for off,(si,typ,add) in b.relocs(i).items():
    _,sv,_,_,sh=b.syms[si]
    if typ!=1 or sh not in bases or sh in base:continue
    original=bytes_at(linked,base[i]+off,4)
    if original is None:continue
    actual=struct.unpack('>I',original)[0]-sv-add
    wanted=next((s for n,s in zip(linked.names,linked.secs) if n==b.names[sh]),None)
    if wanted and wanted[3]<=actual and actual+b.secs[sh][5]<=wanted[3]+wanted[5]:
     bases[sh].add(actual)
     if len(bases[sh])==1:base[sh]=actual
  for i in allocated:
   if i in base or bases[i] or b.secs[i][1]==8:continue
   blob=bytearray(b.sec_bytes(i));good=True
   for off,(si,typ,add) in b.relocs(i).items():
    actual=resolve(si,add)
    if typ!=1 or actual is None:good=False;break
    struct.pack_into('>I',blob,off,actual&0xffffffff)
   if not good or len(blob)<8 or not any(blob):continue
   wanted=next(((j,s) for j,(n,s) in enumerate(zip(linked.names,linked.secs)) if n==b.names[i]),None)
   if wanted is None:continue
   j,sec=wanted;data=linked.sec_bytes(j);hits=[];pos=0
   while True:
    pos=data.find(blob,pos)
    if pos<0:break
    addr=sec[3]+pos
    if addr%b.secs[i][8]==0:hits.append(addr)
    if len(hits)>1:break
    pos+=1
   if len(hits)==1:bases[i].add(hits[0]);base[i]=hits[0]
  if base==prior:break
 rows=[]
 for i in allocated:
  sec=b.secs[i];blob=bytearray(b.sec_bytes(i));unresolved=[]
  for off,(si,typ,add) in b.relocs(i).items():
   actual=resolve(si,add)
   if typ!=1 or actual is None:
    unresolved.append({'offset':off,'type':typ,'symbol':b.syms[si][0]});continue
   struct.pack_into('>I',blob,off,actual&0xffffffff)
  addr=base.get(i);retail=bytes_at(linked,addr,len(blob)) if addr is not None else None
  rows.append({'section':b.names[i],'bytes':len(blob),'alignment':sec[8],
    'bases':[hex(x) for x in sorted(bases[i])],'base':hex(addr) if addr is not None else None,
    'aligned':addr is not None and addr%sec[8]==0,
    'exact':not unresolved and retail is not None and bytes(blob)==retail,
    'unresolved':unresolved})
 return {'unit':unit,'sections':rows,'unknown_code_refs':unknown,
   'source_code_bytes':b.secs[bi][5],'target_code_bytes':a.secs[ti][5],
   'extra_functions':sorted(set(sf)-set(tf))}

def ready(row):
 return (bool(row.get('sections')) and not row.get('unknown_code_refs')
         and not row.get('extra_functions')
         and row.get('source_code_bytes')==row.get('target_code_bytes')
         and all(s['exact'] and s['aligned'] for s in row['sections']))

def main():
 ap=argparse.ArgumentParser(description=__doc__,formatter_class=argparse.RawDescriptionHelpFormatter)
 ap.add_argument('units',nargs='*',help='unit paths without extension; default: fully matched layout/import candidates')
 ap.add_argument('--ready',action='store_true',help='only units with complete byte placements and no extra code')
 ap.add_argument('--json',action='store_true')
 args=ap.parse_args()
 try:
  linked=Elf(BUILD/'main.elf');st=starts();ex=address_map(linked)
  report=json.loads((BUILD/'report.json').read_text())
  selected=[r['unit'] for r in candidates(report,linked) if not r['same_layout'] and not r['missing']]
  if args.units:selected=[u.removeprefix('src/').removesuffix('.cpp').removesuffix('.c') for u in args.units]
  results=[proof(u,linked,st,ex) for u in selected]
 except (OSError,ValueError) as exc:
  ap.error(f'{exc}; run configure.py and ninja first')
 results=[r for r in results if not args.ready or ready(r)]
 if args.json:
  print(json.dumps(results,indent=2));return
 for row in results:
  print(row.get('unit','?')+(' [complete byte placements]' if ready(row) else ''))
  if 'error' in row:
   print('  '+row['error']);continue
  for sec in row['sections']:
   status='exact' if sec['exact'] else 'unplaced or different'
   print(f"  {sec['section']:10} {sec['bytes']:6} B  {sec['base'] or '?':12} {status}"
         +(' (alignment differs)' if sec['base'] and not sec['aligned'] else ''))
  if row['extra_functions']:print('  extra source functions: '+', '.join(row['extra_functions']))
  if row['unknown_code_refs']:print(f"  {len(row['unknown_code_refs'])} unpaired data references in code")
 print('Placements are a shortlist; final retail hash, literal checks and verifier still required.')

if __name__=='__main__':
 main()
