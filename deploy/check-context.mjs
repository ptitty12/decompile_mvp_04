// Fails the Docker build when the build context holds anything that could be
// game data (deploy/Dockerfile, first stage). The public repository and the
// image never contain any: .dockerignore admits only engine/, the symbol map
// and this script, and this check catches what slips through anyway, by name
// and by content:
//   - disc images and executables by extension (.iso .ciso .gcm .rvz .dol .elf ...);
//   - files that start like one (CISO, RVZ, WIA, GCZ, WBFS, ELF, or a GameCube
//     disc header's magic at 0x1C), whatever their name;
//   - anything over 64 MiB (no engine source comes close; a disc is 1.4 GB).
//
//   node deploy/check-context.mjs DIR
import { closeSync, openSync, readSync, readdirSync, statSync } from 'node:fs';
import { join, relative } from 'node:path';

const root = process.argv[2];
if (!root) {
  console.error('usage: check-context.mjs DIR');
  process.exit(2);
}
const BAD_EXT = /\.(iso|ciso|gcm|rvz|wia|wbfs|gcz|nfs|tgc|dol|elf|rel|big|nkit|dec)$/i;
const MAX_BYTES = 64 << 20;

function startsLikeGameData(path) {
  const fd = openSync(path, 'r');
  try {
    const h = Buffer.alloc(0x20);
    const n = readSync(fd, h, 0, h.length, 0);
    const magic = h.subarray(0, 4).toString('latin1');
    if (['CISO', 'RVZ\x01', 'WIA\x01', 'WBFS', '\x7fELF'].includes(magic)) return `starts with ${JSON.stringify(magic)}`;
    if (n >= 4 && h.readUInt32LE(0) === 0xb10bc001) return 'a GCZ image';
    if (n >= 0x20 && h.readUInt32BE(0x1c) === 0xc2339f3d) return 'a GameCube disc header';
    return null;
  } finally {
    closeSync(fd);
  }
}

const problems = [];
let files = 0;
function walk(dir) {
  for (const name of readdirSync(dir)) {
    const p = join(dir, name);
    const st = statSync(p);
    if (st.isDirectory()) {
      walk(p);
      continue;
    }
    ++files;
    const rel = relative(root, p);
    if (BAD_EXT.test(name)) problems.push(`${rel}: a disc image or game executable by its name`);
    else if (st.size > MAX_BYTES) problems.push(`${rel}: ${st.size} bytes, larger than any engine source`);
    else {
      const why = st.size > 0 ? startsLikeGameData(p) : null;
      if (why) problems.push(`${rel}: ${why}`);
    }
  }
}
walk(root);
if (problems.length) {
  console.error('check-context: the Docker build context holds files that may be game data; refusing to build:');
  for (const p of problems) console.error(`  ${p}`);
  console.error('Remove them (or fix .dockerignore). Game data never goes into the image: upload the disc on the Server disc page.');
  process.exit(1);
}
console.log(`check-context: ${files} files, no game data`);
