// Fake gamepads for the browser checks (Q3). Playwright cannot emulate a
// controller, so the page's navigator.getGamepads() is replaced, before the page
// loads, by a function over a few slots this file edits: connect and unplug a
// pad, press buttons, move axes, as a browser's Gamepad API reports them:
// fresh snapshot objects per call, `index`, `id`, `mapping`, `buttons[]` with
// pressed/touched/value, `axes[]`, a vibration actuator that records its calls.
// Chrome-style pads stay hidden until their first input and then fire
// `gamepadconnected`; Firefox-style pads are listed at once (`hidden: false`).
//
// Used by pad_check.mjs; tests/ do not need a browser (tests/controls.test.mjs).

// The in-page part (serialized by Playwright's addInitScript). No closure over module scope.
export function installFakePads() {
  const slots = [null, null, null, null];
  const rumbles = [];
  const api = {
    rumbles,
    // spec: { id, mapping, buttons, axes, rest: {axisIndex: value}, hidden, vibration }
    connect(slot, spec) {
      const s = {
        slot, spec, listed: spec.hidden === false,
        stamp: 0,
        buttons: Array.from({ length: spec.buttons }, () => 0),
        axes: Array.from({ length: spec.axes }, (_, i) => (spec.rest && spec.rest[i]) ?? 0),
      };
      slots[slot] = s;
      if (s.listed) api._event('gamepadconnected', s);
    },
    disconnect(slot) {
      const s = slots[slot];
      slots[slot] = null;
      if (s && s.listed) api._event('gamepaddisconnected', s);
    },
    set(slot, buttons = {}, axes = {}) {
      const s = slots[slot];
      if (!s) throw new Error(`no fake pad in slot ${slot}`);
      for (const [i, v] of Object.entries(buttons)) s.buttons[Number(i)] = v;
      for (const [i, v] of Object.entries(axes)) s.axes[Number(i)] = v;
      s.stamp++;
      if (!s.listed) {
        s.listed = true;
        api._event('gamepadconnected', s);  // Chrome: the first input shows the pad
      }
    },
    press(slot, i, v = 1) { api.set(slot, { [i]: v }); },
    release(slot, i) { api.set(slot, { [i]: 0 }); },
    axis(slot, i, v) { api.set(slot, {}, { [i]: v }); },
    // Everything back to rest.
    rest(slot) {
      const s = slots[slot];
      if (!s) return;
      s.buttons.fill(0);
      s.axes.forEach((_, i) => { s.axes[i] = (s.spec.rest && s.spec.rest[i]) ?? 0; });
      s.stamp++;
    },
    _snap(s) {
      const actuator = s.spec.vibration
        ? {
            type: 'dual-rumble',
            playEffect: async (type, params) => { rumbles.push({ slot: s.slot, type, params }); return 'complete'; },
            reset: async () => 'complete',
          }
        : undefined;
      return {
        id: s.spec.id, index: s.slot, connected: true, mapping: s.spec.mapping, timestamp: s.stamp,
        buttons: s.buttons.map((v) => ({ pressed: v >= 0.5, touched: v > 0, value: v })),
        axes: [...s.axes],
        vibrationActuator: actuator,
      };
    },
    _event(type, s) {
      try {
        window.dispatchEvent(new GamepadEvent(type, { gamepad: api._snap(s) }));
      } catch {
        window.dispatchEvent(new Event(type));
      }
    },
  };
  Object.defineProperty(navigator, 'getGamepads', {
    value: () => slots.map((s) => (s && s.listed ? api._snap(s) : null)),
    configurable: true,
  });
  window.__pads = api;
}

// ---- controller specs ----

const std = (id, buttons = 17) => ({ id, mapping: 'standard', buttons, axes: 4, vibration: true });
export const PADS = {
  xbox: std('Xbox Wireless Controller (STANDARD GAMEPAD Vendor: 045e Product: 0b13)'),
  ds4: std('Wireless Controller (STANDARD GAMEPAD Vendor: 054c Product: 09cc)', 18),
  pro: std('Pro Controller (STANDARD GAMEPAD Vendor: 057e Product: 2009)'),
  // Firefox on Linux: an Xbox 360 pad without the standard mapping (the joystick order).
  xpad: { id: '045e-028e-Microsoft X-Box 360 pad', mapping: '', buttons: 11, axes: 8, rest: { 2: -1, 5: -1 }, hidden: false },
  // A generic HID pad with a hat on axis 9 (Chrome on Windows), no standard mapping.
  hat: { id: 'USB Gamepad (Vendor: 0810 Product: e501)', mapping: '', buttons: 12, axes: 10, rest: { 9: 1.2857143 } },
  // A GameCube adapter as it might show up: made-up layout, so the guided setup is needed.
  gcadapter: {
    id: 'MAYFLASH GameCube Controller Adapter (Vendor: 0079 Product: 1843)', mapping: '', buttons: 12, axes: 6,
    rest: { 4: -1, 5: -1 }, hidden: false,
  },
};

// What a person does for each control of gcadapter: buttons X=0 A=1 B=2 Y=3, Z=7, START=9, D-pad 12-15,
// L and R triggers on axes 4 and 5 (resting at -1), main stick axes 0/1, C-stick axes 3 (x) and 2 (y).
export const GCADAPTER_ACTIONS = {
  A: { buttons: { 1: 1 } }, B: { buttons: { 2: 1 } }, X: { buttons: { 0: 1 } }, Y: { buttons: { 3: 1 } },
  Z: { buttons: { 7: 1 } }, START: { buttons: { 9: 1 } },
  L: { axes: { 4: 1 } }, R: { axes: { 5: 1 } },
  UP: { buttons: { 12: 1 } }, RIGHT: { buttons: { 13: 1 } }, DOWN: { buttons: { 14: 1 } }, LEFT: { buttons: { 15: 1 } },
  stickX: { axes: { 0: 1 } }, stickY: { axes: { 1: -1 } }, cX: { axes: { 3: 1 } }, cY: { axes: { 2: -1 } },
};

// The Controls panel's prompts, mapped to the control they ask for (controls-rebind.ts controlPrompt).
export const PROMPTS = {
  'Press the A button (the big one)': 'A', 'Press the B button': 'B', 'Press the X button': 'X', 'Press the Y button': 'Y',
  'Press the Z button': 'Z', 'Press START': 'START',
  'Press the L trigger all the way down': 'L', 'Press the R trigger all the way down': 'R',
  'Press D-pad up': 'UP', 'Press D-pad down': 'DOWN', 'Press D-pad left': 'LEFT', 'Press D-pad right': 'RIGHT',
  'Push the main stick RIGHT as far as it goes': 'stickX', 'Push the main stick UP as far as it goes': 'stickY',
  'Push the C-stick RIGHT as far as it goes': 'cX', 'Push the C-stick UP as far as it goes': 'cY',
};
