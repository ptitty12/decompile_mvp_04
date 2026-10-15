# Q3 log: controllers in the browser

Working log of the side session `claude-side-q3` (branch `engine/q3-pad`, from origin/main
`1ab1dd27`). The owner: "in the future I need to be able to use a controller on this." E2c
(`docs/engine/E2C_LOG.md` section 2 and G1) had added a first Gamepad API mapping, tested only
with a faked `navigator.getGamepads()`. Q3 makes controllers work for the cases that matter
(Xbox, PlayStation, Switch Pro, GameCube controllers on USB adapters, generic pads), makes
them obvious to use, and checks them solo and online. Design and commands: `docs/engine/WEB.md`
(the Input and Controllers bullets); the lobby side: `docs/engine/NETPLAY.md` section 1.

## Status (2026-10-15)

| # | Item | State |
|---|---|---|
| 1 | Controller support: profiles for standard and non-standard pads, analog sticks with dead zone and the GameCube octagon, analog triggers with the digital click, hot-plug, which controller plays which port | Done (not tried on real hardware, section 8) |
| 2 | The Controls panel: pads found, assignment to players, remap by pressing and a guided setup, live input test, the keyboard's keys, per-browser storage | Done |
| 3 | Netplay: each player's controller drives their own port; the lobby shows "controller ready", yours and the other player's | Done |
| 4 | Determinism: pads reach the guest only through the frame poll's input queue | Checked: live runs replay equal from their own input log, solo and online |
| 5 | Tests: unit tests for the layers; Playwright checks with fake pads in Chrome, Edge and Firefox; the real game on fake pads | Done |
| - | Rumble from the game | Not done: the game's rumble calls are not exposed (section 7); a vibration test button exists |

## 1. What was built

Files are in `engine/web/` (nothing outside it, plus these docs):

| File | What |
|---|---|
| `src/gamepad.ts` | the mapping math (E2c), plus: a D-pad that the browser reports as one "hat" axis, `octagonScale` / `shapeStick` (the GameCube's octagonal gate), `mappingFromObject` |
| `src/gamepad-profiles.ts` | Chrome and Firefox id parsing, the model key, the family (Xbox, PlayStation, Nintendo, GameCube adapter, generic), the profiles |
| `src/controls-store.ts` | what the panel keeps per browser (`localStorage["mvp.controls.v2"]`): a mapping and settings per controller model, port assignment, the keyboard's port and keys, the vibration switch |
| `src/controls-keys.ts` | the keyboard as a pad: default keys, rebinding with swaps, labels from the keyboard layout |
| `src/controls-rebind.ts` | the press-to-bind state machine (one control, or all sixteen) |
| `src/pad-manager.ts` | hot-plug, used/idle pads, auto-claiming of ports, the pad of each port |
| `src/controls.ts` | the panel (replaces `gamepad-ui.ts`) |
| `src/input.ts` | `HostInput`: keyboard + manager, one pad per port, focus handling |
| `src/netplay.ts` | the lobby's controller lines (`setController`, text messages to the peer) |
| `static/controls.css`, `static/index.html` | the panel's look, the toolbar chip |
| `wasm/mvp_web.cpp`, `src/worker.ts`, `src/protocol.ts` | `inputLog=1`: the inputs the guest consumed, as an `mvp-input` script (development aid, section 4) |
| `tests/controls.test.mjs` | 32 data-free tests of the layers |
| `tools/fake_pads.mjs`, `tools/pad_check.mjs`, `tools/pad_game_check.mjs` | the browser checks |

## 2. Supported controllers and profiles

A browser gives a pad `mapping === "standard"` when it knows the layout; then every pad has the
same button positions and the default mapping applies. Everything else has raw numbers. What the
page does for each case (`gamepad-profiles.ts`):

| Pad as the browser reports it | Profile | Basis |
|---|---|---|
| Xbox 360/One/Series, PlayStation (DualShock 4, DualSense), 8BitDo and most others, standard layout | `standard`: bottom button = A, right = B, left = X, top = Y, either bumper = Z, triggers = L/R, Start = START, D-pad, sticks | the Gamepad API's standard layout; the E2c default |
| Switch Pro, Joy-Con pairs and anything with vendor 057e, standard layout | `standard-nintendo`: A (right button) = A, B (bottom) = B, X (top) = X, Y (left) = Y | Nintendo labels the buttons by name, not position |
| Xbox 360/One without the standard mapping (Firefox on Linux, old Chrome) | `xbox-raw`: the Linux joystick order (buttons A B X Y LB RB Back Start; triggers on axes 2 and 5 resting at -1; D-pad on axes 6 and 7; sticks 0/1 and 3/4) | the documented kernel order; not hardware-tested here |
| GameCube controllers on adapters: Mayflash 0079:1843 and 1844, Nintendo's 057e:0337, anything named GameCube/NGC | `gamecube-adapter`: a generic guess, and the panel offers the guided setup | see below |
| Any other pad without the standard mapping (generic HID, DirectInput) | `generic`: buttons 0-3 = A B X Y, D-pad on buttons 12-15 or on a hat axis 9, sticks on axes 0-3, bumpers as L and R; the guided setup is offered | a guess that finds the menus |

**Why GameCube adapters have no built-in layout.** Their raw reports differ between adapter
firmware, mode (Mayflash PC mode, Wii U mode, Switch mode), OS and browser, and I have no
adapter to read one from. A layout from memory that is wrong by one button silently plays
badly; the guided setup (about 30 seconds, once, stored per browser) is right by construction.
It knows the GameCube specifics: triggers that are an axis resting at one end plus a click
button (the axis wins, so the analog value is kept), a D-pad reported as one hat axis, sticks
that reach only part of the axis range (the game clamps at 72 of 100 anyway). The official
adapter (057e:0337) is a multiplexed HID device that browsers often do not expose as a gamepad
at all; making it work needs WebHID (section 9).

Sticks (`shapeStick`): a radial dead zone (default 15 %, a slider), the rest scaled to
+-100 (the game's `PADClampCircle` then limits to 72, as on a console), and the GameCube's
octagonal gate: notches at the four directions and the four diagonals reach the full distance
and the flat between them is 92.4 % out, so a diagonal is as far as a cardinal. A switch
turns the gate off. Triggers: analog 0-255 from the button's `value` (or an axis, rest at either
end), the digital L/R bit at 90 % of the travel (a slider), digital-only triggers (Switch Pro ZL/ZR)
count as fully pressed. Buttons count as pressed at 50 %.

## 3. The Controls panel

Under "Controls" on the page, and a **chip in the toolbar** ("Controller: Xbox Wireless
Controller", dashed when a pad is connected but unused, "No controller (keyboard)") that
opens it. The panel also opens by itself for a pad whose layout it does not know, with a
notice and a "Set it up now" button.

- **Who plays**: Player 1 and Player 2 each take Auto (the next controller you use), No
  controller, or a model of pad ("Xbox Wireless Controller #2" tells apart two of one model);
  "Keyboard plays" Player 1, Player 2 or nobody. Auto means: a pad is claimed by the first
  press, not by being listed. Browsers list idle pads (Firefox every pad, and a GameCube adapter
  its four sockets with or without a controller), so listing never takes a port; and the pad that
  the player actually touches is Player 1. A pad keeps its port while it stays connected, so
  unplugging Player 1's pad does not hand Player 2's pad to Player 1.
- **Controllers**: each pad found with its layout (standard, or which profile), whether it is
  yours-set-up, and its port or "idle: press a button".
- **Test and change**: pick the pad (or the keyboard) to test. A live picture (buttons light, the
  sticks move inside the octagon, the triggers fill) and numbers show exactly what the game
  receives from it. The table lists every GameCube control and what it is bound to, each with
  **Set**: press the button (or move the stick or trigger) you want; the press does not reach the
  game; Esc cancels; a physical control that did another job loses it. **Set up this controller**
  asks for all sixteen in turn, with Skip, Back and Cancel; it first asks you to let go of
  everything, so a held button is not taken as the answer. **Reset to defaults** removes this
  model's own mapping, so it follows the profile again. Dead zone, octagon gate and trigger click
  sliders edit the same stored mapping.
- **Keyboard**: the same table for keys (Set, then press the key). A key another control uses
  swaps with it, so no key does two things and nothing is left without one; F, M and P (the
  page's own), Esc, Tab, F-keys, Ctrl/Alt/Meta and a few other keys are refused with the
  reason. Labels follow the keyboard layout where the browser has `getLayoutMap()`. The C-stick
  has keys now (numeric keypad 8/4/2/6).
- **Vibration**: a "Test vibration" button plays a short `dual-rumble` effect on the selected
  pad when it has a `vibrationActuator`.
- A hint when the page does not have the focus (Chrome passes the controller only to the page
  that has it), and when a pad is hidden until pressed (Chrome).
- Everything is stored per browser (`mvp.controls.v2`); the E2c mapping
  (`mvp.gamepad.mapping.v1`) is read once for pads that have none of their own.

Clicking a button with the mouse now blurs it (`input.ts`): Enter and Space would press it
again, and the game's keys were ignored until the game was clicked.

## 4. Determinism, and how it was checked

Nothing changed in how input reaches the guest (E0c-IN1): the page reads pads and keys, builds a
`Pad` per port, and posts it to the Worker when it changes; the engine's `LiveInput` holds the
latest state and the guest consumes one `FrameInput` per frame poll. Q3 adds nothing that reads
a clock or talks to the engine except `mvp_set_pad` (unchanged), and the controller panel
never calls the engine.

To *check* that, the engine can now report what the guest consumed: with `?inputLog=1`, at each
frame poll `mvp_web.cpp` records the changes of the consumed `FrameInput` (all four ports) as an
`mvp-input` script (`InputLog`), returned in the Worker's `stopped` message
(`window.mvp.inputLog`). It is host-side only; the guest never reads it. `tools/pad_game_check.mjs`
plays fake pads through the real game, takes that log, and runs the game again with the log as
the page's `script=` and no gamepad: the two runs must end in the same guest line (instruction
count, time base, frame polls, MEM1 hash) at the same frame.

Results (Chrome 155 headless, `render=0`, this PC, 2026-10-15; the live run is at the game's own
speed after the boot, the replay unpaced; the disc stays under `orig/`, nothing is committed):

| Check | What the pad did | Input changes consumed | Live guest line = replay guest line |
|---|---|---|---|
| `standard` | an Xbox-style pad, hidden until its first press: START during the intro, START at the licence screen, unplugged, plugged into another slot and START again, A with the stick down, D-pad down; 2,800 frames | 14 | `21742914119 instructions, time base 2264886887, 2801 frame polls, MEM1 sha1 6be7c4b6...` both |
| `raw` | an Xbox pad without the standard mapping (listed at once): Start on button 7, D-pad up on axis 7, the left trigger on axis 2 (analog 255 and the L click), A; 2,800 frames | 12 | `20776196891 instructions, time base 2164187176, 2801 frame polls, MEM1 sha1 6752ad92...` both |
| `play` | the deployment's Play button (the mock server) pressed with A on a pad: the game started from the server image and ran | - | (starts and runs) |
| `netplay` | two pages through E5's server (login, lobby, invite, both read the disc), player 1 on a DualShock, player 2 on an Xbox pad; the intro's START presses from both; 2,400 frames | the same log on both pages | both pages `19038020719 instructions, time base 1983127158, 2401 frame polls, MEM1 sha1 dfc75e09...`; player 2's presses are on port 2, player 1's on port 1; no page errors |

The guest lines differ between runs of different checks because the live presses fall at
different frames; each live run equals *its own* replay, which is the claim. The check also
asserts that no press is left down, that nothing appears on port 2 in the solo runs, and that the
two online pages consumed byte-identical logs.

## 5. Netplay

The page sends one pad, as its port 0, whatever its role; the engine's session puts it on port 1
(player 1) or port 2 (player 2) (`wasm/net_web.cpp`: `local_port` 0 for live input, the session
maps it by `player`). Q3 keeps the page's other ports disconnected online (`PadManager.online`), so
a second controller on the page cannot reach the game, and online the pad of whichever port has
one is the local player's. The panel then shows one row, "You (player N)". The `netplay` check
above confirms player 2's pad is on port 2 on both pages and player 1's on port 1.

**The lobby** (`netplay.ts`): "Your controller: Xbox Wireless Controller is ready. It plays as
player 2." / "... is connected. Press a button on it to use it." / "Your input: keyboard only.
To use a controller, connect it and press a button on it." The other player's line
("Player 1's controller: ready" / "connected, not used yet" / "Player 1 is on the keyboard") comes
over the data channel as small JSON text messages (`{"mvp":"pad","v":1,"connected":..,"ready":..}`,
on change and every 3 s). The engine's datagrams are binary and a string is never handed to the
Worker, so the engine and its protocol are untouched. (A page from before Q3 that received one
would throw in its data-channel handler and carry on; both players load the page from the same
server, and the engine build ids must match to play anyway.) Display only, no effect on the game.

## 6. Tests

- `tests/controls.test.mjs` (32) and `tests/gamepad.test.mjs` (6): hats, the octagon (notches,
  22.5 degrees, through the mapping), the dead zone, id parsing for Chrome and Firefox, the model
  key, families, every profile with scripted pads, the keyboard (defaults, swaps, refused keys,
  storage, labels), storage (round trip, damage field by field, no storage, a throwing storage,
  the E2c migration, one pad one port), the manager (a pad claimed by its first use, merge with
  the keyboard, hot-plug, two pads, phantoms, manual ports and equal models, per-model
  mappings, capture, online, no Gamepad API), and the press-to-bind machine (rest, press,
  release, an axis, a trigger taking its axis over its click, a hat, timeouts, a whole guided
  setup of a made-up pad that then plays). `test_web_shell`: 58 of 58.
- `tools/pad_check.mjs` (no game data): 11 checks against the real page with fake gamepads
  (`fake_pads.mjs`: fresh snapshots per call like a browser, hidden-until-used and listed pads,
  hot-plug events, a recording vibration actuator). Keyboard only; a standard pad (shown after its
  first press, buttons, sticks, triggers, the live test); hot-plug; two pads; assignment by hand
  and the keyboard on player 2, kept after a reload; a pad that needs the guided setup (the
  notice, the panel opening itself, the whole setup answered from the prompts, every control
  working, kept after a reload and in another slot); one control set by pressing (the press
  never reaches the game, Esc, the old button stops, reset); the keyboard map (a refused key,
  a swap, Space on a focused button, kept after a reload); the dead zone slider and the octagon
  switch; vibration; the lobby line with a scripted lobby WebSocket and online as player 2.
  Passes 11 of 11 in Chrome 155, Edge 155 and Firefox 157, each check in a fresh profile; run
  repeatedly it did not flake (the one flake I met was a test racing its own setup press).
- `tools/pad_game_check.mjs` (disc, local only): section 4.

## 7. Rumble

The game does rumble: `PADControlMotor(chan, 1)` and `(chan, 0)` from the force-feedback code in
`src/game/tu_80008540.cpp`. The engine does not expose it: `PADRead` is replaced, but
`PADControlMotor` is SDK code that programs the SI registers, which have no host-visible state.
A *host-side observer* would be cheap and guest-neutral: one more `HleKind::Before` entry
appended to `hle_table()` in `engine/runtime/hle.cpp` for address `0x80439918` that records `r3`
(the channel) and `r4` (the command: 0 stop, 1 rumble, 2 stop hard) into a host array, an export
in `mvp_web.cpp` to read it after each run batch, and the page playing a `dual-rumble` effect
on the pad of that port (online: the local player's channel only), re-issued every 800 ms while
on (browsers cap an effect's length). That touches `hle.cpp`, which is outside the files this
session may edit, so it is not done; only the panel's "Test vibration" exists. Chrome and Edge
support `vibrationActuator` on XInput and DualShock pads on Windows; Firefox has no
actuator for most pads.

## 8. What was not tried

- **No real controller.** Everything above ran with fake `getGamepads()` objects. The standard
  layout is the browsers' job; the Nintendo swap, the Xbox joystick order and the generic guess
  are from documented layouts, not hardware. A non-standard pad of the owner's will show up with
  the "not a standard layout" notice and be taught in one pass.
- GameCube adapters: no layout built in, by design (section 2); no adapter was available.
- Safari and Chrome on macOS/Linux: not run (no Mac; the Linux ordering is documented only).
- Gamepad-driven page navigation beyond "press A to play" (the lobby's buttons need the mouse).

## 9. How the owner tests (nothing to run)

1. Open the page in Chrome or Edge, plug the controller in (USB, or Bluetooth paired as usual).
2. **Press any button on the controller.** Browsers hide a controller until it is used; the toolbar chip
   should change to "Controller: <name>" and the Controls panel (under the game, or click the chip)
   says "<name>: player 1". Click the page once if it says the page needs the focus.
3. In the panel, move the sticks, press the triggers and buttons: the picture and the numbers
   show what the game will get. If the picture is wrong, or the panel says the layout is not a
   standard one, press **Set up this controller** and press each control when asked.
4. Play: the game's own menus work with the pad; Start skips the intro.
5. A second controller: press a button on it; it becomes Player 2. Or choose by hand under
   "Who plays". The keyboard keeps working next to it (changeable under "Test and change: Keyboard").
6. Online: create or join a game as usual; the lobby line says "Your controller: ... is ready" and
   shows the other player's. Only your controller plays your game.
7. GameCube controller through an adapter: use the adapter's PC/DInput mode, press a button on the
   controller, then **Set up this controller**. If the browser does not list the adapter at all, tell
   the lead which model it is (the official Nintendo one may need WebHID, next step 2).

If anything is wrong, the engine log at the bottom of the page and the panel's text are the first
things to look at; the agents read them with `window.mvp.controls()`.

## Decisions to record (for the lead)

- **Q3-C1, storage:** `localStorage["mvp.controls.v2"]` holds the settings per controller *model*
  (vendor:product, else the cleaned name and array sizes), the ports, the keyboard's port and keys,
  the vibration switch. The E2c key is read once as a fallback; nothing writes it any more.
- **Q3-C2, ports:** an Auto port is claimed by the first *used* pad, not by listing; pads keep
  their ports while connected; the keyboard drives player 1 by default and merges with that port's
  pad. Offline the page drives players 1 and 2; online only its own player, as port 0.
- **Q3-C3, no built-in GameCube adapter layout:** recognised, never guessed; the guided setup is
  the supported path. Revisit with real hardware or WebHID.
- **Q3-C4, `inputLog`:** a host-only development aid in `mvp_web.cpp` (no guest effect, no engine API
  change): the consumed inputs as an `mvp-input` script. The replay check is the evidence for
  "input reaches the guest only at the frame poll".
- **Q3-C5, peer readiness:** text messages on the data channel next to the engine's binary
  datagrams; display only; no change to the engine's protocol version.
- **Open for the owner:** none. (The rumble hook in section 7 needs an edit outside this
  session's files; the lead decides who.)

## Commits (branch `engine/q3-pad`, not pushed)

| Commit | |
|---|---|
| `d8a2bfb8` | controller layers: hats, octagon gate, profiles, per-model settings, pad manager |
| `1cec216b` | the lobby shows controller readiness, yours and the other player's |
| `40187dc7` | report the inputs the guest consumed, for replay tests (inputLog=1, mvp_input_log) |
| `ad8992f1` | the Controls panel: controllers, players, press to bind, keyboard keys |
| `4745f9eb` | browser checks for controllers: fake gamepads, the panel, the real game, replay |
| (this commit) | the log, WEB.md and NETPLAY.md |

## Next step

1. **A real controller.** Try the owner's pad in Chrome and Edge (and Firefox): the panel's text
   says what it is. Anything non-standard is taught once; if a layout turns out to be common and
   wrong in `gamepad-profiles.ts`, fix the profile with the evidence.
2. **WebHID for the official GameCube adapter** (057e:0337, Chromium, a permission prompt): its
   protocol is simple (write `0x13`, read 37-byte `0x21` reports of four 9-byte ports); it would
   give the four ports with analog L/R and no guided setup. Worth doing if the owner has that
   adapter.
3. **Rumble** (section 7): the hook in `hle.cpp`, then `vibrationActuator`.
4. **A pad-driven first screen:** the Play, lobby and download screens still need the mouse.
5. A ctest entry for `pad_check.mjs` where Playwright's browsers are installed (it needs no game data).
