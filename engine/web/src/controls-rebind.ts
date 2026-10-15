// Teaching the game a controller by pressing its buttons (Q3): "press the
// button for A". A state machine over snapshots of the pad (no DOM, no clock of
// its own), so tests/controls.test.mjs runs it with scripted snapshots; the
// Controls panel (controls.ts) feeds it one snapshot per animation frame.
//
// Per control: wait until the pad is back at rest (so a button still held from
// the last step is not taken for the answer), wait for the first new press or
// stick/trigger/hat movement, apply it, wait for the release, go on. One control
// is a single "Set"; all of them in order is the guided setup.

import {
  GC_AXES, GC_BUTTONS, detectSource,
  type GamepadMapping, type GcAxis, type GcButton, type GcTrigger, type Snapshot, type Source,
} from './gamepad.js';

export type Control =
  | { kind: 'button'; name: GcButton }
  | { kind: 'trigger'; name: GcTrigger }
  | { kind: 'axis'; name: GcAxis };

export function controlId(c: Control): string {
  return `${c.kind}:${c.name}`;
}

const BUTTON_PROMPT: Record<GcButton, string> = {
  A: 'the A button (the big one)', B: 'the B button', X: 'the X button', Y: 'the Y button', Z: 'the Z button',
  START: 'START', UP: 'D-pad up', DOWN: 'D-pad down', LEFT: 'D-pad left', RIGHT: 'D-pad right',
};
const AXIS_PROMPT: Record<GcAxis, string> = {
  stickX: 'the main stick RIGHT', stickY: 'the main stick UP', cX: 'the C-stick RIGHT', cY: 'the C-stick UP',
};

export function controlLabel(c: Control): string {
  if (c.kind === 'button') return c.name === 'START' ? 'START' : BUTTON_LABEL[c.name];
  if (c.kind === 'trigger') return `${c.name} trigger`;
  return AXIS_LABEL[c.name];
}
const BUTTON_LABEL: Record<GcButton, string> = {
  A: 'A', B: 'B', X: 'X', Y: 'Y', Z: 'Z', START: 'START', UP: 'D-pad up', DOWN: 'D-pad down', LEFT: 'D-pad left',
  RIGHT: 'D-pad right',
};
const AXIS_LABEL: Record<GcAxis, string> = {
  stickX: 'Main stick: right', stickY: 'Main stick: up', cX: 'C-stick: right', cY: 'C-stick: up',
};

export function controlPrompt(c: Control): string {
  if (c.kind === 'button') return `Press ${BUTTON_PROMPT[c.name]}`;
  if (c.kind === 'trigger') return `Press the ${c.name} trigger all the way down`;
  return `Push ${AXIS_PROMPT[c.name]} as far as it goes`;
}

// The guided setup's order: the face buttons, the triggers, the D-pad, the sticks.
export function allControls(): Control[] {
  const order: GcButton[] = ['A', 'B', 'X', 'Y', 'Z', 'START', 'UP', 'DOWN', 'LEFT', 'RIGHT'];
  return [
    ...order.slice(0, 6).map((name): Control => ({ kind: 'button', name })),
    { kind: 'trigger', name: 'L' }, { kind: 'trigger', name: 'R' },
    ...order.slice(6).map((name): Control => ({ kind: 'button', name })),
    ...GC_AXES.map((name): Control => ({ kind: 'axis', name })),
  ];
}

export function settableControls(): Control[] {
  return [
    ...GC_BUTTONS.map((name): Control => ({ kind: 'button', name })),
    { kind: 'trigger', name: 'L' }, { kind: 'trigger', name: 'R' },
    ...GC_AXES.map((name): Control => ({ kind: 'axis', name })),
  ];
}

export function sameSource(a: Source, b: Source): boolean {
  if (a.type !== b.type || a.index !== b.index) return false;
  if (a.type === 'hat' && b.type === 'hat') return a.dir === b.dir;
  if (a.type === 'axis' && b.type === 'axis') return a.dir === b.dir && !!a.full === !!b.full;
  return true;
}

// The mapping with `c` bound to `src`, or null when that cannot be (a button for
// a stick). A physical control that did another job loses it: one press, one meaning.
export function applyBinding(m: GamepadMapping, c: Control, src: Source): GamepadMapping | null {
  const next = structuredClone(m);
  if (c.kind === 'axis') {
    if (src.type !== 'axis') return null;
    next.axes[c.name] = { index: src.index, invert: src.dir < 0 };
    return next;
  }
  if (src.type === 'hat' && c.kind === 'trigger') return null;
  for (const name of GC_BUTTONS) next.buttons[name] = next.buttons[name].filter((s) => !sameSource(s, src));
  for (const t of ['L', 'R'] as const) next.triggers[t] = next.triggers[t].filter((s) => !sameSource(s, src));
  if (c.kind === 'button') next.buttons[c.name] = [src];
  else next.triggers[c.name] = [src];
  return next;
}

export type RebindEvent =
  | { type: 'prompt'; step: number; control: Control }
  | { type: 'bound'; step: number; control: Control; source: Source }
  | { type: 'timeout'; step: number; control: Control }
  | { type: 'done'; cancelled: boolean };

export type Phase = 'neutral' | 'wait' | 'release' | 'finished';

export class Rebinder {
  step = 0;
  phase: Phase = 'neutral';
  private rest: Snapshot;
  private readonly restAxes: number[];
  private deadline = 0;
  private releaseBy = 0;

  constructor(readonly controls: Control[], start: Snapshot, private readonly timeoutMs = 8000) {
    this.rest = start;
    this.restAxes = [...start.axes];
  }

  get control(): Control | null {
    return this.phase === 'finished' ? null : this.controls[this.step] ?? null;
  }

  // Nothing held and every axis near where it rested when the setup began.
  private neutral(snap: Snapshot, tol: number): boolean {
    if (snap.buttons.some((v) => v >= 0.5)) return false;
    return snap.axes.every((v, i) => Math.abs(v - (this.restAxes[i] ?? 0)) < tol);
  }

  update(snap: Snapshot, now: number): RebindEvent[] {
    const ev: RebindEvent[] = [];
    if (this.phase === 'neutral') {
      if (this.neutral(snap, 0.35)) {
        this.rest = snap;
        this.phase = 'wait';
        this.deadline = now + this.timeoutMs;
        ev.push({ type: 'prompt', step: this.step, control: this.controls[this.step] });
      }
    } else if (this.phase === 'wait') {
      const c = this.controls[this.step];
      // A stick answers to an axis only; a button to anything but nothing.
      const now_ = c.kind === 'axis' ? { buttons: [], axes: snap.axes } : snap;
      const rest_ = c.kind === 'axis' ? { buttons: [], axes: this.rest.axes } : this.rest;
      // A trigger answers to its analog axis when it has one (a GameCube pad's L and R move an axis and click
      // a button at the end of the travel: take the axis, so the analog value is kept), else to a button.
      const axesOnly = c.kind === 'trigger' ? detectSource({ buttons: [], axes: this.rest.axes }, { buttons: [], axes: snap.axes }) : null;
      const src = axesOnly && axesOnly.type === 'axis' ? axesOnly : detectSource(rest_, now_);
      if (src && !(c.kind === 'trigger' && src.type === 'hat') && !(c.kind === 'axis' && src.type !== 'axis')) {
        ev.push({ type: 'bound', step: this.step, control: c, source: src });
        this.phase = 'release';
        this.releaseBy = now + 3000;
      } else if (now > this.deadline) {
        ev.push({ type: 'timeout', step: this.step, control: c });
        this.advance(ev);
      }
    } else if (this.phase === 'release') {
      if (this.neutral(snap, 0.3) || now > this.releaseBy) this.advance(ev);
    }
    return ev;
  }

  private advance(ev: RebindEvent[]): void {
    ++this.step;
    if (this.step >= this.controls.length) {
      this.phase = 'finished';
      ev.push({ type: 'done', cancelled: false });
    } else {
      this.phase = 'neutral';
    }
  }

  /** Leave this control as it is and ask for the next. */
  skip(): RebindEvent[] {
    const ev: RebindEvent[] = [];
    if (this.phase !== 'finished') this.advance(ev);
    return ev;
  }

  back(): void {
    if (this.phase === 'finished') return;
    this.step = Math.max(0, this.step - 1);
    this.phase = 'neutral';
  }

  cancel(): RebindEvent[] {
    if (this.phase === 'finished') return [];
    this.phase = 'finished';
    return [{ type: 'done', cancelled: true }];
  }

  get prompt(): string {
    const c = this.control;
    if (!c) return '';
    if (this.phase === 'neutral') return 'Let go of every button and stick...';
    if (this.phase === 'release') return 'Got it. Let go...';
    return controlPrompt(c);
  }
}
