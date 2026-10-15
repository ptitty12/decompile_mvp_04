// The page's roster-pack checker (E6): mvp-packs.js (engine/mods compiled for the
// browser) driven through src/packs-core.ts as the Roster packs panel and the engine
// Worker drive it. The example pack must give the hashes docs/MODDING.md §12
// documents; a broken pack its problems; the empty set the handshake's default.
// Authored packs only (docs/examples), no game data.
import assert from 'node:assert/strict';
import { readFileSync, readdirSync, statSync } from 'node:fs';
import { join, relative, resolve } from 'node:path';
import { test } from 'node:test';
import { fileURLToPath } from 'node:url';
import { deflateRawSync } from 'node:zlib';
import { load } from './site.mjs';

const here = fileURLToPath(new URL('.', import.meta.url));
const repo = process.env.MVP_REPO_ROOT ?? resolve(here, '..', '..', '..');
const example = join(repo, 'docs', 'examples', 'packs', 'fictional-league');

const { default: createMvpPacks } = await load('mvp-packs.js');
const { EMPTY_SET_HASH, feedPacks, summarize } = await load('packs-core.js');
const M = await createMvpPacks();

// A picked folder, as the panel hands it over (paths start with the folder's name).
function folder(dir, top = 'fictional-league') {
  const files = [];
  const walk = (d) => {
    for (const n of readdirSync(d)) {
      const p = join(d, n);
      if (statSync(p).isDirectory()) walk(p);
      else files.push({ path: `${top}/${relative(dir, p).split('\\').join('/')}`, data: buf(readFileSync(p)) });  // a Buffer may view a shared pool
    }
  };
  walk(dir);
  return { label: top, kind: 'files', files };
}

const enc = (s) => new TextEncoder().encode(s);
const buf = (u8) => u8.buffer.slice(u8.byteOffset, u8.byteOffset + u8.byteLength);

// A minimal zip writer (deflate, no CRC check needed by zlib; the engine checks it).
function crc32(b) {
  let c = ~0;
  for (const x of b) {
    c ^= x;
    for (let k = 0; k < 8; ++k) c = (c >>> 1) ^ (0xEDB88320 & -(c & 1));
  }
  return ~c >>> 0;
}
function zip(entries) {
  const parts = [], central = [];
  let off = 0;
  for (const [name, data] of entries) {
    const n = enc(name), comp = deflateRawSync(data), crc = crc32(data);
    const h = Buffer.alloc(30);
    h.writeUInt32LE(0x04034b50, 0); h.writeUInt16LE(20, 4); h.writeUInt16LE(8, 8);
    h.writeUInt32LE(crc, 14); h.writeUInt32LE(comp.length, 18); h.writeUInt32LE(data.length, 22); h.writeUInt16LE(n.length, 26);
    const c = Buffer.alloc(46);
    c.writeUInt32LE(0x02014b50, 0); c.writeUInt16LE(20, 4); c.writeUInt16LE(20, 6); c.writeUInt16LE(8, 10);
    c.writeUInt32LE(crc, 16); c.writeUInt32LE(comp.length, 20); c.writeUInt32LE(data.length, 24); c.writeUInt16LE(n.length, 28);
    c.writeUInt32LE(off, 42);
    parts.push(h, n, comp);
    central.push(c, n);
    off += 30 + n.length + comp.length;
  }
  const cd = Buffer.concat(central), e = Buffer.alloc(22);
  e.writeUInt32LE(0x06054b50, 0); e.writeUInt16LE(entries.length, 8); e.writeUInt16LE(entries.length, 10);
  e.writeUInt32LE(cd.length, 12); e.writeUInt32LE(off, 16);
  return Buffer.concat([...parts, cd, e]);
}

test('the example pack as a picked folder: no problems, the documented hashes', () => {
  const r = feedPacks(M, [folder(example)]);
  assert.equal(r.ok, true, JSON.stringify(r.issues));
  assert.deepEqual(r.issues, []);
  assert.equal(r.packs[0].id, 'fictional-league');
  assert.equal(r.packs[0].version, '1.0.0');
  assert.equal(r.packs[0].hash, 'e83c0341774a0363d2ce834624a8ca62bbc944a9e005806fd025f42bb2aab4f5');
  assert.equal(r.set_hash, 'b9a04e6578e789b4abe0f8a95d4c269ebda1881ace871e083c399f1d6023cafb');
});

test('the same pack zipped hashes the same; order changes the set hash', () => {
  const f = folder(example);
  const z = zip(f.files.map((x) => [x.path, Buffer.from(x.data)]));
  const r = feedPacks(M, [{ label: 'fictional-league.zip', kind: 'zip', files: [{ path: 'fictional-league.zip', data: buf(z) }] }]);
  assert.equal(r.ok, true, JSON.stringify(r.issues));
  assert.equal(r.packs[0].hash, 'e83c0341774a0363d2ce834624a8ca62bbc944a9e005806fd025f42bb2aab4f5');
  const other = { label: 'tweak', kind: 'files', files: [{ path: 'tweak/pack.json', data: buf(enc(JSON.stringify({
    id: 'tweak', name: 'Tweak', version: '1.0.0', game: 'GV4E69-0', engine_api: '1.0', patches: [] }))) }] };
  const ab = feedPacks(M, [f, other]).set_hash, ba = feedPacks(M, [other, f]).set_hash;
  assert.notEqual(ab, ba);
  assert.equal(feedPacks(M, [f, other]).set_hash, ab);
});

test('a broken pack: the problems, with codes and places', () => {
  const bad = { label: 'bad', kind: 'files', files: [
    { path: 'bad/pack.json', data: buf(enc(JSON.stringify({ id: 'bad-pack', name: 'Bad', version: '1.0', game: 'GV4E69-0',
      engine_api: '2.0', patches: ['patches/p.json'] }))) },
    { path: 'bad/patches/p.json', data: buf(enc('{"ops": [{"op": "player.fly"}]}')) },
  ] };
  const r = feedPacks(M, [bad, { label: 'nothing.zip', kind: 'zip', files: [{ path: 'nothing.zip', data: buf(enc('no zip')) }] }]);
  assert.equal(r.ok, false);
  const codes = r.issues.map((i) => `${i.code} ${i.where}`);
  assert.deepEqual(codes, ['E-MANIFEST bad-pack:pack.json', 'E-ENGINE-API bad-pack:pack.json',
                           'E-OP bad-pack:patches/p.json:ops[0]', 'E-PACK nothing.zip']);
  assert.match(summarize(r), /^E-MANIFEST bad-pack:pack\.json: version must be MAJOR\.MINOR\.PATCH/);
  assert.equal(M._mvp_packs_mount(), 0);  // the small module has no disc
});

test('no packs: the empty set, as the netplay handshake sends it', () => {
  const r = feedPacks(M, []);
  assert.equal(r.ok, true);
  assert.equal(r.set_hash, EMPTY_SET_HASH);
});
