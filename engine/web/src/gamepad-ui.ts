// The controller panel (E2c): shows the connected gamepad and what each
// GameCube control is bound to, and rebinds a control by pressing the button
// (or moving the axis) wanted for it. The mapping is stored per browser
// (gamepad.ts). Rebinding holds the gamepad (HostInput.capture), so the press
// that sets a binding never reaches the game.

import {
  GC_AXES, GC_BUTTONS, defaultMapping, describeSource, detectSource, snapshot,
  type GamepadLike, type GamepadMapping, type GcAxis, type GcButton, type GcTrigger, type Snapshot,
} from './gamepad.js';
import { HostInput } from './input.js';

type Control = { kind: 'button'; name: GcButton } | { kind: 'trigger'; name: GcTrigger } | { kind: 'axis'; name: GcAxis };

const AXIS_LABEL: Record<GcAxis, string> = {
  stickX: 'Main stick: right', stickY: 'Main stick: up', cX: 'C-stick: right', cY: 'C-stick: up',
};

export class GamepadPanel {
  private readonly status: HTMLElement;
  private readonly table: HTMLTableSectionElement;
  private waiting: { control: Control; rest: Snapshot; until: number; button: HTMLButtonElement } | null = null;

  constructor(root: HTMLElement, private readonly input: HostInput) {
    root.replaceChildren();
    this.status = document.createElement('p');
    this.status.className = 'pad-status';
    const table = document.createElement('table');
    table.className = 'pad-map';
    table.createTHead().innerHTML = '<tr><th>GameCube</th><th>Bound to</th><th></th></tr>';
    this.table = table.createTBody();
    const reset = document.createElement('button');
    reset.type = 'button';
    reset.textContent = 'Reset to defaults';
    reset.addEventListener('click', () => {
      this.input.mapping = defaultMapping();
      this.render();
    });
    const note = document.createElement('p');
    note.className = 'note';
    note.textContent = 'Press "Set", then the button (or move the stick or trigger) you want for that control. ' +
                       'The mapping is saved in this browser.';
    root.append(this.status, table, reset, note);
    this.render();
    window.addEventListener('gamepadconnected', () => this.render());
    window.addEventListener('gamepaddisconnected', () => this.render());
  }

  private controls(): Control[] {
    return [
      ...GC_BUTTONS.map((name): Control => ({ kind: 'button', name })),
      { kind: 'trigger', name: 'L' }, { kind: 'trigger', name: 'R' },
      ...GC_AXES.map((name): Control => ({ kind: 'axis', name })),
    ];
  }

  private describe(m: GamepadMapping, c: Control, standard: boolean): string {
    if (c.kind === 'axis') {
      const a = m.axes[c.name];
      return `axis ${a.index}${a.invert ? ' (inverted)' : ''}`;
    }
    const list = c.kind === 'button' ? m.buttons[c.name] : m.triggers[c.name];
    return list.length ? list.map((s) => describeSource(s, standard)).join(', ') : '(none)';
  }

  render(): void {
    const gp = HostInput.firstGamepad();
    const standard = !gp || gp.mapping === 'standard';
    this.status.textContent = gp
      ? `Controller: ${gp.id} (${gp.mapping === 'standard' ? 'standard layout' : 'non-standard layout: check the bindings'})`
      : 'No controller found. Connect one and press a button on it.';
    const m = this.input.mapping;
    this.table.replaceChildren();
    for (const c of this.controls()) {
      const tr = this.table.insertRow();
      tr.insertCell().textContent = c.kind === 'axis' ? AXIS_LABEL[c.name] : c.kind === 'trigger' ? `${c.name} (trigger)` : c.name;
      tr.insertCell().textContent = this.describe(m, c, standard);
      const btn = document.createElement('button');
      btn.type = 'button';
      btn.textContent = 'Set';
      btn.addEventListener('click', () => this.begin(c, btn));
      tr.insertCell().append(btn);
    }
  }

  private begin(control: Control, button: HTMLButtonElement): void {
    const gp = HostInput.firstGamepad();
    if (!gp) {
      this.status.textContent = 'No controller found. Connect one and press a button on it first.';
      return;
    }
    this.input.capture = true;
    this.waiting = { control, rest: snapshot(gp as GamepadLike), until: performance.now() + 6000, button };
    button.textContent = control.kind === 'axis' ? 'Move it...' : 'Press...';
    requestAnimationFrame(() => this.watch());
  }

  private watch(): void {
    const w = this.waiting;
    if (!w) return;
    const gp = HostInput.firstGamepad();
    if (!gp || performance.now() > w.until) {
      this.finish();
      return;
    }
    const src = detectSource(w.rest, snapshot(gp as GamepadLike));
    if (!src) {
      requestAnimationFrame(() => this.watch());
      return;
    }
    const m = structuredClone(this.input.mapping);
    const c = w.control;
    if (c.kind === 'button') m.buttons[c.name] = [src];
    else if (c.kind === 'trigger') m.triggers[c.name] = [src];
    else if (src.type === 'axis') m.axes[c.name] = { index: src.index, invert: src.dir < 0 };
    else {  // a button for an axis: not supported
      requestAnimationFrame(() => this.watch());
      return;
    }
    this.input.mapping = m;
    // Wait for the control to return before the game sees the pad again.
    const rest = w.rest;
    const release = () => {
      const now = HostInput.firstGamepad();
      if (now && detectSource(rest, snapshot(now as GamepadLike), 0.3)) requestAnimationFrame(release);
      else this.finish();
    };
    this.waiting = null;
    release();
  }

  private finish(): void {
    this.waiting = null;
    this.input.capture = false;
    this.render();
  }
}
