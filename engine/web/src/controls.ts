// The Controls panel (Q3): the controllers the browser sees and which of them
// plays which port, a live test of what the game will get, teaching the game a
// controller by pressing its buttons ("press the button for A"), the keyboard
// keys, and the settings that belong to a controller (dead zone, the GameCube's
// octagonal gate, the trigger click). Everything is stored per browser
// (controls-store.ts). It reads and changes settings; it never talks to the
// engine: the pad reaches the game only through HostInput and the frame poll.

import { PAD, describeSource, snapshot, type GamepadMapping, type PadPart } from './gamepad.js';
import { PORTS, withMapping, withoutMapping, withPort, type ControlsConfig, type PortAssign } from './controls-store.js';
import {
  KEY_ACTIONS, KEY_ACTION_LABELS, defaultKeyMap, keyLabel, keysToPad, rebindKey, type KeyAction,
} from './controls-keys.js';
import {
  Rebinder, allControls, applyBinding, controlId, controlLabel, settableControls, type Control,
} from './controls-rebind.js';
import { HostInput } from './input.js';
import type { Device, DeviceEvent } from './pad-manager.js';

type Target = { kind: 'keyboard' } | { kind: 'device'; handle: string };

const BUTTON_LIST: [string, number][] = [
  ['A', PAD.A], ['B', PAD.B], ['X', PAD.X], ['Y', PAD.Y], ['Z', PAD.Z], ['START', PAD.START], ['L', PAD.L], ['R', PAD.R],
  ['UP', PAD.UP], ['DOWN', PAD.DOWN], ['LEFT', PAD.LEFT], ['RIGHT', PAD.RIGHT],
];

const el = <K extends keyof HTMLElementTagNameMap>(tag: K, props: Partial<HTMLElementTagNameMap[K]> & { id?: string } = {},
                                                    ...kids: (Node | string)[]): HTMLElementTagNameMap[K] => {
  const e = document.createElement(tag);
  Object.assign(e, props);
  e.append(...kids);
  return e;
};

const SVG = 'http://www.w3.org/2000/svg';
function svg<K extends keyof SVGElementTagNameMap>(tag: K, attrs: Record<string, string | number>): SVGElementTagNameMap[K] {
  const e = document.createElementNS(SVG, tag);
  for (const [k, v] of Object.entries(attrs)) e.setAttribute(k, String(v));
  return e;
}

export interface ControlsExtras {
  chip?: HTMLElement | null;        // the toolbar's controller indicator
  details?: HTMLDetailsElement | null;  // the <details> the panel sits in (opened for a pad that needs setting up)
  summary?: HTMLElement | null;     // shows the state next to "Controls"
}

export class ControlsPanel {
  private readonly status: HTMLElement;
  private readonly notice: HTMLElement;
  private readonly noticeText: HTMLElement;
  private readonly portRows: { row: HTMLElement; label: HTMLElement; select: HTMLSelectElement; state: HTMLElement }[] = [];
  private readonly kbSelect: HTMLSelectElement;
  private readonly deviceList: HTMLUListElement;
  private readonly targetSelect: HTMLSelectElement;
  private readonly prompt: HTMLElement;
  private readonly promptText: HTMLElement;
  private readonly bindBody: HTMLTableSectionElement;
  private readonly bindHead: HTMLElement;
  private readonly tuneBox: HTMLElement;
  private readonly deadzone: HTMLInputElement;
  private readonly deadzoneOut: HTMLOutputElement;
  private readonly octagon: HTMLInputElement;
  private readonly click: HTMLInputElement;
  private readonly clickOut: HTMLOutputElement;
  private readonly setupAll: HTMLButtonElement;
  private readonly resetBtn: HTMLButtonElement;
  private readonly rumble: HTMLInputElement;
  private readonly rumbleTest: HTMLButtonElement;
  private readonly readout: HTMLElement;
  private readonly viz: Record<string, SVGElement>;

  /** The state the lobby shows changed (a controller came, went or was used). */
  onChange: () => void = () => {};

  private target: Target = { kind: 'keyboard' };
  private autoTarget = true;
  private online: 1 | 2 | null = null;
  private sig = '';
  private vizSig = '';
  private message = '';
  private messageAt = 0;
  private layout: { get(code: string): string | undefined } | null = null;
  private seenSetup = new Set<string>();
  private job:
    | { type: 'pad'; rebinder: Rebinder; handle: string; key: string; single: boolean; raf: number }
    | { type: 'key'; action: KeyAction; listener: (e: KeyboardEvent) => void; up: (e: KeyboardEvent) => void; timer: number }
    | null = null;

  constructor(root: HTMLElement, private readonly input: HostInput, private readonly extras: ControlsExtras = {}) {
    root.replaceChildren();
    root.classList.add('ctl');

    // -- status and the "needs setup" notice --
    this.status = el('p', { id: 'ctl-status', className: 'ctl-status' });
    this.status.setAttribute('role', 'status');
    this.noticeText = el('span');
    const noticeBtn = el('button', { type: 'button', id: 'ctl-notice-setup', textContent: 'Set it up now' });
    noticeBtn.addEventListener('click', () => {
      const d = this.input.manager.devices.find((x) => !x.profile.known && !x.custom) ?? this.input.manager.devices[0];
      if (d) {
        this.select({ kind: 'device', handle: d.handle });
        this.begin(allControls());
      }
    });
    this.notice = el('p', { id: 'ctl-notice', className: 'ctl-notice', hidden: true }, this.noticeText, ' ', noticeBtn);

    // -- players --
    const players = el('div', { className: 'ctl-players' });
    for (let p = 0; p < PORTS; ++p) {
      const label = el('label', { htmlFor: `ctl-port-${p}`, textContent: `Player ${p + 1}` });
      const select = el('select', { id: `ctl-port-${p}` });
      select.addEventListener('change', () => this.assign(p, select.value));
      const state = el('span', { className: 'ctl-port-state' });
      const row = el('div', { className: 'ctl-row' }, label, select, state);
      players.append(row);
      this.portRows.push({ row, label, select, state });
    }
    const kbLabel = el('label', { htmlFor: 'ctl-kbport', textContent: 'Keyboard plays' });
    this.kbSelect = el('select', { id: 'ctl-kbport' });
    this.kbSelect.addEventListener('change', () => {
      this.input.config = { ...this.input.config, keyboardPort: Number(this.kbSelect.value) };
      this.touch();
    });
    players.append(el('div', { className: 'ctl-row', id: 'ctl-kbrow' }, kbLabel, this.kbSelect));

    // -- the list of controllers --
    this.deviceList = el('ul', { id: 'ctl-devices', className: 'ctl-devices' });

    // -- the editor: target, live test, bindings, tuning --
    this.targetSelect = el('select', { id: 'ctl-target' });
    this.targetSelect.addEventListener('change', () => {
      this.autoTarget = false;
      this.select(this.targetSelect.value === 'keyboard' ? { kind: 'keyboard' } : { kind: 'device', handle: this.targetSelect.value });
    });
    this.setupAll = el('button', { type: 'button', id: 'ctl-setup-all', textContent: 'Set up this controller' });
    this.setupAll.addEventListener('click', () => this.begin(allControls()));
    this.resetBtn = el('button', { type: 'button', id: 'ctl-reset', textContent: 'Reset to defaults' });
    this.resetBtn.addEventListener('click', () => this.reset());
    const targetRow = el('div', { className: 'ctl-row' }, el('label', { htmlFor: 'ctl-target', textContent: 'Test and change:' }),
                         this.targetSelect, this.setupAll, this.resetBtn);

    const { box, parts } = this.buildViz();
    this.viz = parts;
    this.readout = el('output', { id: 'ctl-readout', className: 'ctl-readout' });
    const live = el('div', { className: 'ctl-live' }, box, this.readout);

    this.promptText = el('span', { id: 'ctl-prompt-text' });
    const skip = el('button', { type: 'button', id: 'ctl-skip', textContent: 'Skip' });
    skip.addEventListener('click', () => this.job?.type === 'pad' && this.advance(this.job.rebinder.skip()));
    const back = el('button', { type: 'button', id: 'ctl-back', textContent: 'Back' });
    back.addEventListener('click', () => this.job?.type === 'pad' && this.job.rebinder.back());
    const cancel = el('button', { type: 'button', id: 'ctl-cancel', textContent: 'Cancel (Esc)' });
    cancel.addEventListener('click', () => this.cancel());
    this.prompt = el('div', { id: 'ctl-prompt', className: 'ctl-prompt', hidden: true }, this.promptText, ' ', skip, back, cancel);
    this.prompt.setAttribute('aria-live', 'polite');

    const table = el('table', { className: 'pad-map', id: 'ctl-bindings' });
    this.bindHead = table.createTHead().insertRow();
    this.bindBody = table.createTBody();

    this.deadzone = el('input', { id: 'ctl-deadzone', type: 'range', min: '0', max: '0.5', step: '0.01' });
    this.deadzoneOut = el('output');
    this.deadzone.addEventListener('input', () => this.tune((m) => { m.deadzone = Number(this.deadzone.value); }));
    this.octagon = el('input', { id: 'ctl-octagon', type: 'checkbox' });
    this.octagon.addEventListener('change', () => this.tune((m) => { m.octagon = this.octagon.checked; }));
    this.click = el('input', { id: 'ctl-click', type: 'range', min: '0.5', max: '1', step: '0.01' });
    this.clickOut = el('output');
    this.click.addEventListener('input', () => this.tune((m) => { m.triggerClick = Number(this.click.value); }));
    this.tuneBox = el('div', { className: 'ctl-tune', id: 'ctl-tune' },
      el('label', {}, 'Stick dead zone ', this.deadzone, ' ', this.deadzoneOut),
      el('label', {}, this.octagon, ' GameCube octagon gate (diagonals reach as far as the four directions)'),
      el('label', {}, 'L/R click at ', this.click, ' ', this.clickOut, ' of the trigger travel'));

    // -- vibration --
    this.rumble = el('input', { id: 'ctl-rumble', type: 'checkbox' });
    this.rumble.addEventListener('change', () => {
      this.input.config = { ...this.input.config, rumble: this.rumble.checked };
    });
    this.rumbleTest = el('button', { type: 'button', id: 'ctl-rumble-test', textContent: 'Test vibration' });
    this.rumbleTest.addEventListener('click', () => this.testRumble());
    const rumbleRow = el('p', { className: 'ctl-row' }, el('label', {}, this.rumble, ' Vibration '), this.rumbleTest);

    const note = el('p', { className: 'note', textContent:
      'Press a button on a controller to wake it up (browsers hide a controller until it is used). ' +
      'The settings are saved in this browser. Page keys: F fullscreen, M sound, P pause.' });

    root.append(this.status, this.notice,
                el('h3', { textContent: 'Who plays' }), players, this.deviceList,
                el('h3', { textContent: 'Test and set up' }), targetRow, live, this.prompt, table, this.tuneBox, rumbleRow, note);
    this.render();

    input.onDevice = (e) => this.onDevice(e);
    input.onSample = () => this.tick();
    try {
      const km = (navigator as unknown as { keyboard?: { getLayoutMap?: () => Promise<{ get(c: string): string | undefined }> } }).keyboard;
      void km?.getLayoutMap?.().then((m) => { this.layout = m; this.sig = ''; }).catch(() => {});
    } catch {
      // no layout map: key labels are the US names
    }
    window.addEventListener('focus', () => this.touch());
    window.addEventListener('blur', () => this.touch());
    window.addEventListener('gamepadconnected', () => this.touch());
    window.addEventListener('gamepaddisconnected', () => this.touch());
  }

  // ---- state seen from outside (the page, the lobby, the browser check) ----

  /** The online player (1 or 2) while this page plays online, else null. */
  setOnline(player: 1 | 2 | null): void {
    if (this.online === player) return;
    this.online = player;
    this.input.online = player !== null;
    this.touch();
  }

  /** What the lobby shows: the controller that plays this page's game. */
  localController(): { connected: boolean; name?: string; ready: boolean; port: number } {
    const d = this.input.manager.localDevice();
    return d ? { connected: true, name: d.name, ready: d.active, port: d.port } : { connected: false, ready: false, port: 0 };
  }

  snapshot(): Record<string, unknown> {
    const m = this.input.manager;
    return {
      devices: m.devices.map((d) => ({
        index: d.index, name: d.name, key: d.key, nth: d.nth, standard: d.standard, profile: d.profile.id, known: d.profile.known,
        custom: d.custom, active: d.active, port: d.port,
      })),
      ports: this.input.config.ports, keyboardPort: this.input.config.keyboardPort, online: this.online,
      target: this.target, busy: this.job?.type ?? null,
    };
  }

  // ---- events ----

  private onDevice(e: DeviceEvent): void {
    const d = e.device;
    if (e.kind === 'connected') {
      if (!d.active) this.say(`Controller found: ${d.name}. Press a button on it to use it.`);
    } else if (e.kind === 'claimed') {
      this.say('');  // the status line below says who plays what
      if (this.autoTarget) this.target = { kind: 'device', handle: d.handle };
    } else {
      this.say(`Controller unplugged: ${d.name}.`);
      if (this.job?.type === 'pad' && this.job.handle === d.handle) this.cancel('The controller went away.');
    }
    // A pad the page does not know: say so where the player will see it.
    if (e.kind === 'claimed' && !d.profile.known && !d.custom && !this.seenSetup.has(d.key)) {
      this.seenSetup.add(d.key);
      if (this.extras.details) this.extras.details.open = true;
    }
    this.touch();
  }

  private say(text: string): void {
    this.message = text;
    this.messageAt = performance.now();
    this.sig = '';
  }

  private touch(): void {
    this.sig = '';
  }

  // Called after every sample (an animation frame, or a key change).
  private tick(): void {
    this.driveJob();
    if (this.message && !this.job && performance.now() - this.messageAt > 8000) this.say('');  // old news
    const open = this.extras.details ? this.extras.details.open : true;
    const m = this.input.manager;
    const sig = JSON.stringify([m.devices.map((d) => [d.handle, d.active, d.port, d.custom, d.profile.id]), this.input.rev,
                                this.online, this.target, this.message, this.job?.type ?? null, this.layout ? 1 : 0]);
    if (sig !== this.sig) {
      this.sig = sig;
      this.render();
    }
    if (open) this.updateViz();
  }

  // ---- rendering ----

  private selectedDevice(): Device | null {
    if (this.target.kind !== 'device') return null;
    const h = this.target.handle;
    return this.input.manager.devices.find((d) => d.handle === h) ?? null;
  }

  private render(): void {
    const m = this.input.manager;
    const cfg = this.input.config;
    const devices = m.devices;
    // The target: still there? else the player-1 pad, else any pad, else the keyboard.
    if (this.target.kind === 'device' && !this.selectedDevice()) this.target = { kind: 'keyboard' };
    if (this.autoTarget && this.target.kind === 'keyboard' && devices.length) {
      const d = devices.find((x) => x.port === 0) ?? devices.find((x) => x.active) ?? devices[0];
      this.target = { kind: 'device', handle: d.handle };
    }
    this.renderStatus();
    this.renderPorts(cfg);
    this.renderDevices();
    this.renderTargets();
    this.renderEditor(cfg);
    this.onChange();
  }

  private renderStatus(): void {
    const m = this.input.manager;
    const local = this.localController();
    const named = (d: Device) => `${d.name}${m.devices.filter((x) => x.key === d.key).length > 1 ? ` #${d.nth + 1}` : ''}`;
    let line: string;
    let chip: string;
    if (!m.devices.length) {
      line = 'No controller found. Connect one and press a button on it. The keyboard works too.';
      chip = 'No controller (keyboard)';
    } else if (this.online) {
      const d = m.localDevice();
      line = d ? `${named(d)} plays your game (you are player ${this.online}).` +
                 (d.active ? '' : ' Press a button on it to use it.')
               : 'A controller is connected but not used yet: press a button on it.';
      chip = d ? `Controller: ${d.name}${d.active ? '' : ' (press a button)'}` : 'Controller: press a button';
    } else {
      const driving = m.devices.filter((d) => d.port >= 0).sort((a, b) => a.port - b.port);
      line = driving.length
        ? driving.map((d) => `${named(d)}: player ${d.port + 1}`).join('. ') + '.'
        : 'A controller is connected but not used yet: press a button on it.';
      chip = driving.length ? `Controller: ${driving[0].name}${driving.length > 1 ? ` +${driving.length - 1}` : ''}`
                            : 'Controller: press a button';
    }
    // Chrome gives the Gamepad API's data only to the page that has the focus.
    const focus = m.devices.length && typeof document.hasFocus === 'function' && !document.hasFocus()
      ? ' Click the page so the browser passes the controller to it.' : '';
    this.status.textContent = (this.message ? `${this.message} ${line}` : line) + focus;
    if (this.extras.chip) {
      this.extras.chip.textContent = chip;
      this.extras.chip.dataset.state = local.ready ? 'ready' : local.connected ? 'idle' : 'none';
    }
    if (this.extras.summary) this.extras.summary.textContent = m.devices.length ? `(${chip.replace(/^Controller: /, '')})` : '';
    const needs = m.devices.find((d) => !d.profile.known && !d.custom);
    this.notice.hidden = !needs;
    if (needs) {
      this.noticeText.textContent = `${needs.name} is not a standard layout, so the game does not know its buttons yet. ` +
        'Tell it once: press each control when asked (about 30 seconds).';
    }
  }

  private optionList(sel: HTMLSelectElement, options: [string, string][], value: string): void {
    sel.replaceChildren(...options.map(([v, t]) => el('option', { value: v, textContent: t })));
    sel.value = options.some(([v]) => v === value) ? value : options[0][0];
  }

  private renderPorts(cfg: ControlsConfig): void {
    const m = this.input.manager;
    const devOptions: [string, string][] = m.devices.map((d) => {
      const many = m.devices.filter((x) => x.key === d.key).length > 1;
      return [`dev:${d.key}:${d.nth}`, `${d.name}${many ? ` #${d.nth + 1}` : ''}${d.active ? '' : ' (idle)'}`];
    });
    for (let p = 0; p < PORTS; ++p) {
      const a = cfg.ports[p];
      const row = this.portRows[p];
      const options: [string, string][] = [['auto', 'Auto: the next controller you use'], ['none', 'No controller'], ...devOptions];
      let value = 'auto';
      if (a.mode === 'none') value = 'none';
      else if (a.mode === 'device') {
        value = `dev:${a.key}:${a.nth}`;
        if (!options.some(([v]) => v === value)) options.push([value, `${a.name ?? 'Controller'} (not connected)`]);
      }
      this.optionList(row.select, options, value);
      const d = m.deviceAt(p);
      row.row.hidden = this.online !== null && p > 0;
      row.label.textContent = this.online !== null ? `You (player ${this.online})` : `Player ${p + 1}`;
      row.state.textContent = d ? `using ${d.name}` : a.mode === 'none' ? 'no controller' : 'no controller yet';
    }
    const kbOptions: [string, string][] = this.online !== null
      ? [['0', 'your game'], ['-1', 'nothing']]
      : [...Array.from({ length: PORTS }, (_, p): [string, string] => [String(p), `Player ${p + 1}`]), ['-1', 'nobody']];
    this.optionList(this.kbSelect, kbOptions, String(cfg.keyboardPort));
  }

  private renderDevices(): void {
    const m = this.input.manager;
    this.deviceList.replaceChildren();
    if (!m.devices.length) {
      this.deviceList.append(el('li', { className: 'ctl-none', textContent: 'No controller detected.' }));
      return;
    }
    for (const d of m.devices) {
      const badges: string[] = [d.standard ? 'standard layout' : `layout: ${d.profile.label}`];
      if (d.custom) badges.push('your mapping');
      badges.push(d.active ? (d.port >= 0 ? `player ${d.port + 1}` : 'in use') : 'idle: press a button');
      const li = el('li', { className: d.active ? 'ctl-dev on' : 'ctl-dev' },
                    el('strong', { textContent: d.name }), ' ', el('span', { className: 'ctl-badges', textContent: badges.join(' / ') }));
      li.dataset.index = String(d.index);
      this.deviceList.append(li);
    }
  }

  private renderTargets(): void {
    const m = this.input.manager;
    const options: [string, string][] = [['keyboard', 'Keyboard'], ...m.devices.map((d): [string, string] => [d.handle, `${d.name}${m.devices.filter((x) => x.key === d.key).length > 1 ? ` #${d.nth + 1}` : ''}`])];
    this.optionList(this.targetSelect, options, this.target.kind === 'keyboard' ? 'keyboard' : this.target.handle);
  }

  private renderEditor(cfg: ControlsConfig): void {
    const dev = this.selectedDevice();
    const busy = this.job !== null;
    this.setupAll.hidden = !dev;
    this.setupAll.disabled = busy;
    this.resetBtn.disabled = busy;
    this.tuneBox.hidden = !dev;
    this.rumble.checked = cfg.rumble;
    this.rumbleTest.disabled = !(dev && dev.raw.vibrationActuator);
    this.rumbleTest.title = this.rumbleTest.disabled ? 'This controller or this browser has no vibration' : 'Vibrate the selected controller';
    this.bindHead.replaceChildren(
      ...(dev ? ['GameCube', 'Bound to', ''] : ['Control', 'Key', '']).map((t) => el('th', { textContent: t })));
    this.bindBody.replaceChildren();
    if (dev) {
      const mapping = this.input.manager.mappingFor(dev);
      for (const c of settableControls()) this.bindRow(controlLabel(c), this.describe(mapping, c, dev.standard), c, controlId(c));
      this.deadzone.value = String(mapping.deadzone);
      this.deadzoneOut.textContent = `${Math.round(mapping.deadzone * 100)}%`;
      this.octagon.checked = mapping.octagon;
      this.click.value = String(mapping.triggerClick);
      this.clickOut.textContent = `${Math.round(mapping.triggerClick * 100)}%`;
    } else {
      for (const a of KEY_ACTIONS) this.keyRow(a, cfg);
    }
    this.highlight();
  }

  private bindRow(label: string, bound: string, c: Control, id: string): void {
    const tr = this.bindBody.insertRow();
    tr.dataset.control = id;
    tr.insertCell().textContent = label;
    tr.insertCell().textContent = bound;
    const btn = el('button', { type: 'button', textContent: 'Set' });
    btn.dataset.set = id;
    btn.disabled = this.job !== null;
    btn.addEventListener('click', () => this.begin([c]));
    tr.insertCell().append(btn);
  }

  private keyRow(a: KeyAction, cfg: ControlsConfig): void {
    const tr = this.bindBody.insertRow();
    tr.dataset.key = a;
    tr.insertCell().textContent = KEY_ACTION_LABELS[a];
    tr.insertCell().textContent = cfg.keys[a].map((c) => keyLabel(c, this.layout)).join(', ') || '(none)';
    const btn = el('button', { type: 'button', textContent: 'Set' });
    btn.dataset.setKey = a;
    btn.disabled = this.job !== null;
    btn.addEventListener('click', () => this.beginKey(a));
    tr.insertCell().append(btn);
  }

  private describe(m: GamepadMapping, c: Control, standard: boolean): string {
    if (c.kind === 'axis') {
      const a = m.axes[c.name];
      return `axis ${a.index}${a.invert ? ' (inverted)' : ''}`;
    }
    const list = c.kind === 'button' ? m.buttons[c.name] : m.triggers[c.name];
    return list.length ? list.map((s) => describeSource(s, standard)).join(', ') : '(none)';
  }

  private highlight(): void {
    const j = this.job;
    const pad = j?.type === 'pad' ? j.rebinder.control : null;
    for (const tr of Array.from(this.bindBody.rows)) {
      const on = (!!pad && tr.dataset.control === controlId(pad)) || (j?.type === 'key' && tr.dataset.key === j.action);
      tr.classList.toggle('active', on);
    }
  }

  // ---- the live test ----

  private buildViz(): { box: HTMLElement; parts: Record<string, SVGElement> } {
    const s = svg('svg', { viewBox: '0 0 320 200', class: 'ctl-svg', role: 'img', 'aria-label': 'Live view of the controller' });
    const parts: Record<string, SVGElement> = {};
    const add = <T extends SVGElement>(name: string, e: T): T => {
      e.classList.add('ctl-part');
      e.dataset.part = name;
      parts[name] = e;
      s.append(e);
      return e;
    };
    // triggers (bars that fill) and their click marks
    for (const [name, x] of [['L', 20], ['R', 210]] as const) {
      s.append(svg('rect', { x, y: 8, width: 90, height: 12, class: 'ctl-bar' }));
      add(`fill${name}`, svg('rect', { x, y: 8, width: 0, height: 12, class: 'ctl-fill' }));
      add(name, svg('rect', { x: name === 'L' ? x - 14 : x + 94, y: 6, width: 10, height: 16, rx: 2, class: 'ctl-btn' }));
    }
    add('Z', svg('rect', { x: 238, y: 30, width: 34, height: 12, rx: 3, class: 'ctl-btn z' }));
    // main stick
    s.append(svg('circle', { cx: 70, cy: 95, r: 42, class: 'ctl-well' }));
    s.append(svg('polygon', { points: octagonPoints(70, 95, 40), class: 'ctl-gate' }));
    add('stick', svg('circle', { cx: 70, cy: 95, r: 8, class: 'ctl-dot main' }));
    // d-pad
    add('UP', svg('rect', { x: 100, y: 128, width: 16, height: 18, class: 'ctl-btn' }));
    add('DOWN', svg('rect', { x: 100, y: 162, width: 16, height: 18, class: 'ctl-btn' }));
    add('LEFT', svg('rect', { x: 82, y: 146, width: 18, height: 16, class: 'ctl-btn' }));
    add('RIGHT', svg('rect', { x: 116, y: 146, width: 18, height: 16, class: 'ctl-btn' }));
    // face buttons
    add('START', svg('circle', { cx: 160, cy: 92, r: 8, class: 'ctl-btn start' }));
    add('A', svg('circle', { cx: 245, cy: 100, r: 19, class: 'ctl-btn a' }));
    add('B', svg('circle', { cx: 210, cy: 122, r: 11, class: 'ctl-btn b' }));
    add('X', svg('circle', { cx: 278, cy: 92, r: 12, class: 'ctl-btn' }));
    add('Y', svg('circle', { cx: 238, cy: 66, r: 12, class: 'ctl-btn' }));
    // C-stick
    s.append(svg('circle', { cx: 255, cy: 160, r: 26, class: 'ctl-well' }));
    add('c', svg('circle', { cx: 255, cy: 160, r: 7, class: 'ctl-dot c' }));
    for (const [name, x, y, t] of [['A', 245, 105, 'A'], ['B', 210, 126, 'B'], ['X', 278, 96, 'X'], ['Y', 238, 70, 'Y'],
                                   ['START', 160, 112, 'START'], ['Z', 255, 40, 'Z'], ['L', 20, 36, 'L'], ['R', 296, 36, 'R']] as const) {
      const tx = svg('text', { x, y, class: 'ctl-label', 'text-anchor': name === 'L' ? 'start' : name === 'R' ? 'end' : 'middle' });
      tx.textContent = t;
      s.append(tx);
    }
    const box = el('div', { className: 'ctl-viz' });
    box.append(s);
    return { box, parts };
  }

  private currentPart(): PadPart | null {
    const dev = this.selectedDevice();
    if (dev) return dev.part;
    if (this.target.kind === 'keyboard') return keysToPad(this.input.manager.keys, this.input.config.keys);
    return null;
  }

  private updateViz(): void {
    const part = this.currentPart();
    if (!part) return;
    const names = BUTTON_LIST.filter(([, bit]) => part.buttons & bit).map(([n]) => n);
    const sig = `${part.buttons}|${part.stickX},${part.stickY}|${part.cX},${part.cY}|${part.trigL},${part.trigR}`;
    if (sig === this.vizSig) return;
    this.vizSig = sig;
    for (const [n, bit] of BUTTON_LIST) this.viz[n]?.classList.toggle('on', (part.buttons & bit) !== 0);
    const move = (name: string, cx: number, cy: number, x: number, y: number, r: number) => {
      this.viz[name].setAttribute('cx', String(cx + (x / 128) * r));
      this.viz[name].setAttribute('cy', String(cy - (y / 128) * r));
    };
    move('stick', 70, 95, part.stickX, part.stickY, 36);
    move('c', 255, 160, part.cX, part.cY, 22);
    this.viz.fillL.setAttribute('width', String((part.trigL / 255) * 90));
    this.viz.fillR.setAttribute('width', String((part.trigR / 255) * 90));
    this.readout.textContent = `Buttons: ${names.length ? names.join(' ') : '(none)'}\n` +
      `Main stick: ${part.stickX}, ${part.stickY}   C-stick: ${part.cX}, ${part.cY}   L: ${part.trigL}   R: ${part.trigR}`;
    this.readout.dataset.buttons = names.join(' ');
    this.readout.dataset.stick = `${part.stickX},${part.stickY}`;
    this.readout.dataset.cstick = `${part.cX},${part.cY}`;
    this.readout.dataset.triggers = `${part.trigL},${part.trigR}`;
  }

  // ---- changing things ----

  private select(t: Target): void {
    this.target = t;
    this.vizSig = '';
    this.touch();
  }

  private assign(port: number, value: string): void {
    let a: PortAssign = { mode: 'auto' };
    if (value === 'none') a = { mode: 'none' };
    else if (value.startsWith('dev:')) {
      const m = /^dev:(.*):(\d+)$/.exec(value);
      const name = this.input.manager.devices.find((d) => `dev:${d.key}:${d.nth}` === value)?.name;
      if (m) a = { mode: 'device', key: m[1], nth: Number(m[2]), ...(name ? { name } : {}) };
    }
    this.input.config = withPort(this.input.config, port, a);
    this.say('');
  }

  private tune(f: (m: GamepadMapping) => void): void {
    const dev = this.selectedDevice();
    if (!dev) return;
    const m = structuredClone(this.input.manager.mappingFor(dev));
    f(m);
    this.input.config = withMapping(this.input.config, dev.key, m);
    this.say('');
  }

  private reset(): void {
    const dev = this.selectedDevice();
    if (dev) {
      this.input.config = withoutMapping(this.input.config, dev.key);
      this.say(`${dev.name} is back to ${dev.profile.label.toLowerCase()}.`);
    } else {
      this.input.config = { ...this.input.config, keys: defaultKeyMap() };
      this.say('Keyboard keys are back to the defaults.');
    }
  }

  // ---- press to bind (controllers) ----

  private begin(controls: Control[]): void {
    const dev = this.selectedDevice();
    if (!dev || this.job) return;
    this.input.capture = true;
    const rebinder = new Rebinder(controls, snapshot(dev.raw), controls.length > 1 ? 15000 : 8000);
    this.job = { type: 'pad', rebinder, handle: dev.handle, key: dev.key, single: controls.length === 1, raf: 0 };
    this.listenEscape();
    this.prompt.hidden = false;
    this.promptText.textContent = rebinder.prompt;
    this.touch();
  }

  private driveJob(): void {
    const j = this.job;
    if (!j || j.type !== 'pad') return;
    const dev = this.input.manager.devices.find((d) => d.handle === j.handle);
    if (!dev) return;
    const events = j.rebinder.update(snapshot(dev.raw), performance.now());
    for (const ev of events) {
      if (ev.type === 'bound') {
        const next = applyBinding(this.input.manager.mappingFor(dev), ev.control, ev.source);
        if (next) {
          this.input.config = withMapping(this.input.config, j.key, next);
          this.say(`${controlLabel(ev.control)}: ${this.describe(next, ev.control, dev.standard)}.`);
        } else {
          this.say(`${controlLabel(ev.control)} needs a stick or a trigger movement, not a button.`);
        }
        this.sig = '';
      }
    }
    this.advance(events);
    if (this.job) {
      this.promptText.textContent = j.rebinder.prompt;
      this.highlight();
    }
  }

  private advance(events: { type: string }[]): void {
    if (events.some((e) => e.type === 'done')) this.finish();
  }

  private finish(): void {
    const j = this.job;
    if (j?.type === 'key') {
      window.removeEventListener('keydown', j.listener, true);
      clearTimeout(j.timer);
      // The key being released must not press the focused button again (Space does on keyup).
      setTimeout(() => window.removeEventListener('keyup', j.up, true), 600);
    }
    this.job = null;
    this.input.capture = false;
    this.prompt.hidden = true;
    window.removeEventListener('keydown', this.escListener, true);
    this.touch();
  }

  private cancel(msg = 'Cancelled.'): void {
    if (!this.job) return;
    this.finish();
    this.say(msg);
  }

  private readonly escListener = (e: KeyboardEvent): void => {
    if (e.code !== 'Escape') return;
    e.preventDefault();
    e.stopPropagation();
    this.cancel();
  };

  private listenEscape(): void {
    window.addEventListener('keydown', this.escListener, true);
  }

  // ---- press to bind (keyboard) ----

  private beginKey(action: KeyAction): void {
    if (this.job) return;
    this.input.capture = true;
    const listener = (e: KeyboardEvent): void => {
      e.preventDefault();
      e.stopPropagation();
      if (e.repeat) return;
      if (e.code === 'Escape') {
        this.cancel();
        return;
      }
      const r = rebindKey(this.input.config.keys, action, e.code);
      if ('error' in r) {
        this.promptText.textContent = `Press the key for ${KEY_ACTION_LABELS[action]}: ${r.error}. Try another (Esc cancels).`;
        return;
      }
      this.input.config = { ...this.input.config, keys: r.map };
      this.finish();
      const swapped = r.swapped.length ? ` ${r.swapped.map((s) => KEY_ACTION_LABELS[s]).join(', ')} took the old key.` : '';
      this.say(`${KEY_ACTION_LABELS[action]}: ${keyLabel(e.code, this.layout)}.${swapped}`);
    };
    // Keys that would press the focused button again must not reach it.
    const up = (e: KeyboardEvent) => e.preventDefault();  // (the game still sees the key go up)
    window.addEventListener('keydown', listener, true);
    window.addEventListener('keyup', up, true);
    const timer = window.setTimeout(() => this.cancel('No key pressed.'), 8000);
    this.job = { type: 'key', action, listener, up, timer };
    this.prompt.hidden = false;
    this.promptText.textContent = `Press the key for ${KEY_ACTION_LABELS[action]} (Esc cancels).`;
    this.touch();
  }

  // ---- vibration ----

  private testRumble(): void {
    const dev = this.selectedDevice();
    const a = dev?.raw.vibrationActuator;
    if (!a?.playEffect) return;
    void a.playEffect('dual-rumble', { startDelay: 0, duration: 350, weakMagnitude: 0.6, strongMagnitude: 0.9 }).catch(() => {});
  }
}

// The gate's outline for the picture: eight corners at the four directions and the four diagonals.
function octagonPoints(cx: number, cy: number, r: number): string {
  const pts: string[] = [];
  for (let i = 0; i < 8; ++i) {
    const a = (i * Math.PI) / 4;
    pts.push(`${(cx + r * Math.cos(a)).toFixed(1)},${(cy - r * Math.sin(a)).toFixed(1)}`);
  }
  return pts.join(' ');
}

