// The Roster packs panel (E6): the player picks pack folders or .zip files, puts
// them in order and sees what the engine thinks of them: each pack's id, version
// and hash, the set hash, and every problem (docs/MODDING.md §7). The checks run
// in the engine's own pack code (mvp-packs.js, the same C++ as the engine), with
// no disc; the full check runs in the engine Worker when the game starts, against
// the player's disc, and its result comes back through showMounted().
//
// Both players of an online game must pick the same packs in the same order: the
// set hash goes into the netplay handshake, which refuses a game otherwise.
// The packs never leave the browser.

import { EMPTY_SET_HASH, feedPacks, readPick, type PacksModule } from './packs-core.js';
import type { PackInput, PackSetReport } from './protocol.js';

export interface PacksState {
  count: number;
  setHash: string;
  report?: PackSetReport;   // the static check
  mounted?: PackSetReport;  // the engine's, after applying the set to the disc
  locked: boolean;
}

export class PackPanel {
  readonly state: PacksState = { count: 0, setHash: EMPTY_SET_HASH, locked: false };
  private packs: PackInput[] = [];
  private module: Promise<PacksModule> | null = null;
  private readonly list: HTMLOListElement;
  private readonly summary: HTMLElement;
  private readonly issues: HTMLUListElement;
  private readonly inputs: HTMLInputElement[] = [];
  private seq = 0;

  /** Called after every change (the page refreshes what depends on the set). */
  onChange: (state: PacksState) => void = () => {};

  constructor(el: HTMLElement) {
    el.replaceChildren();
    const h = document.createElement('h2');
    h.textContent = 'Roster packs';
    const note = document.createElement('p');
    note.className = 'note';
    note.textContent = 'Packs change rosters, players and team names. They are applied to your own disc when the ' +
      'game starts, in this order. In an online game both players need the same packs in the same order.';
    const row = document.createElement('div');
    row.className = 'packs-row';
    row.append(this.picker('Add packs (.zip)', 'packs-zip', (input) => {
      input.accept = '.zip,application/zip';
      input.multiple = true;
    }, 'zip'));
    row.append(this.picker('Add a pack folder', 'packs-folder', (input) => {
      input.webkitdirectory = true;
    }, 'files'));
    this.list = document.createElement('ol');
    this.list.className = 'packs-list';
    this.summary = document.createElement('p');
    this.summary.className = 'packs-summary';
    this.issues = document.createElement('ul');
    this.issues.className = 'packs-issues';
    el.append(h, note, row, this.list, this.summary, this.issues);
    void this.refresh();
  }

  /** The packs for the engine Worker (copies: the panel keeps its own). */
  current(): PackInput[] {
    return this.packs.map((p) => ({ ...p, files: p.files.map((f) => ({ path: f.path, data: f.data.slice(0) })) }));
  }

  /** The game started: the set can no longer change. */
  lock(): void {
    this.state.locked = true;
    for (const i of this.inputs) i.disabled = true;
    this.render();
  }

  /** The engine's result of applying the set to the disc. */
  showMounted(r: PackSetReport): void {
    this.state.mounted = r;
    this.render();
  }

  /** Static checks are ok (no errors). */
  ok(): boolean {
    return !this.state.report || this.state.report.ok;
  }

  private picker(text: string, id: string, setup: (i: HTMLInputElement) => void, kind: 'zip' | 'files'): HTMLElement {
    const label = document.createElement('label');
    label.className = 'picker';
    label.textContent = text + ' ';
    const input = document.createElement('input');
    input.type = 'file';
    input.id = id;
    setup(input);
    input.addEventListener('change', () => {
      const files = input.files;
      if (!files || !files.length) return;
      void readPick(files, kind).then((picked) => {
        input.value = '';
        this.packs.push(...picked);
        return this.refresh();
      });
    });
    label.append(input);
    this.inputs.push(input);
    return label;
  }

  private async check(): Promise<PackSetReport | undefined> {
    if (!this.packs.length) return undefined;
    if (!this.module) {
      this.module = import(new URL('./mvp-packs.js', import.meta.url).href)
        .then((m: { default: () => Promise<PacksModule> }) => m.default());
    }
    return feedPacks(await this.module, this.packs);
  }

  private async refresh(): Promise<void> {
    const seq = ++this.seq;
    let report: PackSetReport | undefined;
    try {
      report = await this.check();
    } catch (e) {
      report = { ok: false, set_hash: '', packs: [], issues: [{ severity: 'error', code: 'E-PACK', where: 'page',
        message: `the pack checker failed to load: ${String(e)}` }] };
    }
    if (seq !== this.seq) return;  // a newer change is being checked
    this.state.report = report;
    this.state.count = this.packs.length;
    this.state.setHash = report?.set_hash || EMPTY_SET_HASH;
    this.render();
    this.onChange(this.state);
  }

  private move(i: number, d: number): void {
    const j = i + d;
    if (j < 0 || j >= this.packs.length) return;
    [this.packs[i], this.packs[j]] = [this.packs[j]!, this.packs[i]!];
    void this.refresh();
  }

  private render(): void {
    const r = this.state.mounted ?? this.state.report;
    this.list.replaceChildren(...this.packs.map((p, i) => {
      const li = document.createElement('li');
      const info = r?.packs[i];
      const name = document.createElement('strong');
      name.textContent = info?.name || p.label;
      const meta = document.createElement('span');
      meta.className = 'packs-meta';
      meta.textContent = info?.id ? ` ${info.id} ${info.version}` + (info.hash ? `, ${info.hash.slice(0, 12)}` : '') : ` ${p.label}`;
      li.append(name, meta);
      if (!this.state.locked) {
        const btn = (text: string, title: string, f: () => void) => {
          const b = document.createElement('button');
          b.type = 'button';
          b.textContent = text;
          b.title = title;
          b.addEventListener('click', f);
          return b;
        };
        li.append(btn('Up', 'Apply earlier', () => this.move(i, -1)), btn('Down', 'Apply later', () => this.move(i, 1)),
                  btn('Remove', 'Remove from the set', () => {
                    this.packs.splice(i, 1);
                    void this.refresh();
                  }));
      }
      return li;
    }));
    const errors = r?.issues.filter((x) => x.severity === 'error').length ?? 0;
    const warnings = (r?.issues.length ?? 0) - errors;
    let text = this.packs.length
      ? `Pack set ${this.state.setHash.slice(0, 16)} (${this.packs.length} pack${this.packs.length > 1 ? 's' : ''}): ` +
        (errors ? `${errors} error(s), ${warnings} warning(s). Fix or remove the packs with errors.`
                : warnings ? `no errors, ${warnings} warning(s).` : 'no problems found.')
      : 'No packs: the game\'s own rosters.';
    if (this.state.mounted) {
      text += this.state.mounted.ok
        ? ` Applied to your disc: ${this.state.mounted.files?.length ?? 0} file(s) patched, result ` +
          `${(this.state.mounted.result_hash ?? '').slice(0, 16)}.`
        : ` Could not be applied to your disc${this.state.mounted.fatal ? `: ${this.state.mounted.fatal}` : ''}.`;
    } else if (this.packs.length && !this.state.locked) {
      text += ' The full check runs against your disc when the game starts.';
    }
    this.summary.textContent = text;
    this.summary.className = 'packs-summary' + (errors ? ' err' : '');
    this.issues.replaceChildren(...(r?.issues ?? []).slice(0, 200).map((x) => {
      const li = document.createElement('li');
      li.className = x.severity === 'error' ? 'err' : 'warn';
      li.textContent = `${x.code} ${x.where}: ${x.message}`;
      return li;
    }));
  }
}
