# E3b log: audio (AX mixer, SDL3 playback, WAV dumps)

Working log for the audio half of milestone E3 (`docs/ROADMAP.md`): mix the AX voices
and play them through SDL3 without breaking determinism. Newest state first in
"Status"; a later session resumes from "Next step". Builds and tests as in E0b/E1
(`engine/tools/msvc.cmd`, preset `msvc`; `MVP_DISC` for the local tests).

## Status

**E3b's exit is met (2026-10-14):** the boot and intro mix to a plausible WAV (the
EA SPORTS logo stinger, a voice-like section, then loud full-band music),
`mvp-play` plays it in the window through SDL3, and every determinism test is
unchanged.

| # | Item | State |
|---|---|---|
| 1 | D5 settled: replace at the DSP command-list level | Done |
| 2 | DSP model AX2 (`runtime/ax.h`): per-millisecond processing, envelope write-back, read-only frame observer | Done |
| 3 | AX mixer (`audio/mixer.h`): SRC, envelope, LPF, mix volumes and ramps, buses, aux returns, DPL2, output | Done |
| 4 | Output: SPSC ring, drift resampler, SDL3 playback in `mvp-play`, `--audio-wav` | Done |
| 5 | Tests: data-free mixer/output tests, `local_audio_determinism` | Done |
| 6 | Exit: WAV of boot + intro analysed, `mvp-play` plays sound, determinism tests identical | Done (below) |

## D5: audio replacement level (decided)

**Decision: replace at the DSP command-list level** (the AX microcode), not at the
AX API level. The retail AX library (`dolphin/ax`), EA's SND driver and EA's
main-CPU mixer all stay guest code; the engine models only what the DSP does with
the command list the CPU posts each 5 ms.

Reasons:
- E0c already models the DSP side (DSP1, AX1) and the game depends on it: EA's SND
  frees voices and refills streams from the PB state the DSP writes back. An AX-API
  replacement would have to re-implement AXAcquireVoice/AXFreeVoice, the voice
  priority and DSP-cycle accounting (`__AXSyncPBs` drops voices by a cycle
  estimate), callbacks and the PB sync flags exactly, or the game's own state
  would differ; at the DSP level all of that is retail code by construction.
- EA's streamed audio (the intro movie's, measured up to the title screen) never
  touches AX voices: EA SND mixes it on the
  CPU (`MIX_audioslice`, float code) and injects the result through the AX aux A
  callback (`SNDDRV_audiocallback`), which only exists at the DSP level (the aux
  return buffers the DSP reads back). An AX-API replacement would have to
  reproduce that path too.
- The DSP interface is small and fixed: one command list format (fn_804181DC
  builds it), the PB layout, the aux buffers. Everything is a pure function of
  guest memory at a point fixed by guest instructions (the mail that posts the
  list), so it is deterministic by construction, and identical in WebAssembly.
- The mix is separable: the DSP model writes only what the CPU reads back (PB
  `state`, `currentAddress`, ADPCM/SRC state, `ve.currentVolume`); the mixer is a
  read-only observer. Guest state is the same with and without audio, which keeps
  audio quality changes (filters, the host's device) out of the netplay contract.

Cost: the microcode's exact arithmetic (polyphase coefficients in DSP ROM, DPL2
matrix encoding, compressor) is not public; those parts are approximations,
listed below. None of them can change guest state.

## Design

### DSP model AX2 (`engine/runtime/ax.h`, guest-visible)

Changes to E0c's AX1, all hardware behaviour the CPU can observe:
- a voice is processed millisecond by millisecond (5 x 32 output samples), each
  millisecond only if the voice is running at its start (the microcode's
  structure; E0c ran one 160-sample pass when no PB updates were queued). Play
  positions are unchanged; a voice that ends mid-frame keeps the SRC fraction of
  the millisecond it ended in (E0c advanced it for the whole frame);
- the volume envelope moves: `ve.currentVolume += ve.currentDelta` per output
  sample (16-bit), written back. The CPU reads it back every frame (fn_80419568,
  sync bit 21 path). EA SND always sets the delta to 0 (SNDDRV_DSPMixerInitChannel
  and SNDDRV_DSPMixerUpdate write 0 to vpb+0x19E), so this changes nothing in this
  game, but it is what the DSP does;
- `ax::FrameObserver`: `frame_begin` (guest memory, command list address),
  `voice_ms` (the PB as it was at the start of each millisecond, after that
  millisecond's updates, and the input samples the voice consumed), `frame_end`.
  All read-only. `Hardware::set_ax_observer` attaches one.

Not written (the DSP would): the output and surround buffers, the aux send
buffers, ramped mix volumes, `dpop`, LPF history. Only the DSP itself reads those
back, except the aux sends, which the CPU's aux callback reads (see "Known
deviations").

### Mixer (`engine/audio/mixer.h`, host-only)

Per audio frame of 160 samples at 32 kHz:
- **command list**: 0x00 studio (bus start values and per-sample deltas: the SDK's
  depop), 0x07 / 0x11 (last frame's main surround folded into L/R: stereo, or
  -S/+S in surround mode), 0x02/0x03 voices, 0x04/0x05 aux A/B, 0x13/0x10 Dolby
  Pro Logic II, 0x12 compressor (counted, not modeled), 0x0E output. Commands
  before 0x03 run at `frame_begin`, the others at `frame_end` in list order.
- **per voice millisecond**: sample-rate conversion from the consumed input
  samples (srcSelect 0: 4-tap polyphase, 128 phases, coefSelect 0/1/2; 1: linear;
  2: none), the envelope (`sample x volume >> 15`, volume += delta per sample),
  the one-pole LPF (`(a0 x + b0 y1) >> 15`), then each bus mixerCtrl enables gets
  `clamp16(sample x volume >> 15)`, the volume moving by its delta per sample when
  the bus's ramp bit is set.
- **mixerCtrl bits** (2004 microcode; EA's SNDDRV_DSPMixerUpdate sets them this
  way): main L 0x1, R 0x2, S 0x4, ramp 0x8; aux A L 0x10, R 0x20, ramp 0x40, S
  0x80, S ramp 0x100; aux B L 0x200, R 0x400, ramp 0x800, S 0x1000, S ramp 0x2000.
- **shadow state** per PB: mix volumes keep ramping across frames until the CPU
  writes a new mix block (EA ramps over two frames: delta = difference / 320 at
  its 100 Hz update), the LPF history likewise.
- **host-side depop**: a voice that ran last frame and not in this one has its
  last bus outputs faded out with the SDK's own ramp (at most 20 per sample, the
  rest carried over), from the frame it disappeared in.
- **aux**: sends are summed (and counted) but not delivered; returns are read
  from the buffer address in the command list and added (0x04/0x05: L, R, S to
  main L, R, S; 0x13: four channels to main L, main R, aux B L, aux B R).
- **DPL2** (the game's mode, below): 0x10 adds aux B L/R (the rear channels) one
  frame late to main L/R: a plain 4-to-2 fold, as Dolphin describes these
  commands; the console's phase-shift matrix encoding is not modeled.
- **output**: main L/R clamped to 16 bits, 160 stereo frames per frame to a
  `FrameSink` (WAV writer, level meter, SDL ring), at the AI's DSP rate.

The polyphase coefficients are our own design (Lanczos-2 windowed sinc, cutoffs
0.5/0.8/1.0 of the input Nyquist, unity DC gain), not the DSP ROM's table.

### Output (`audio/ring.h`, `audio/drift.h`, `audio/sdl_out.h`, `audio/wav.h`)

- `Ring`: lock-free single-producer/single-consumer ring of stereo frames. The
  mixer writes on the emulation thread at virtual-time pace; a full ring drops
  (counted). Nothing flows back.
- `DriftResampler`: the consumer side. Linear interpolation at a ratio within
  +-0.5 % of 1, steered by a smoothed fill level toward a target (default 100 ms):
  absorbs the drift between the guest's virtual clock and the device clock. Runs
  dry: fades out, waits for the target again (underrun, counted). Far ahead (> 4 x
  the target): skips down to it (counted).
- `SdlAudioOut`: SDL3 `SDL_OpenAudioDeviceStream` (S16 stereo at 32 kHz; SDL
  converts to the device rate); SDL's audio thread pulls through the drift
  resampler. `throttle()` lets `mvp-play` wait (host only) while the ring holds
  more than 2 x the target, so a host faster than real time does not overrun the
  device. The browser (E2) replaces SDL with an AudioWorklet around the same ring
  and resampler.
- `WavWriter` / `LevelMeter`: the exact virtual-time mix as 16-bit stereo WAV, and
  RMS/peak per second for reports.

### Tools

- `mvp-play`: plays sound when a window is open (`--no-audio` turns it off,
  `--audio-latency MS`), `--audio-wav FILE` (any mode, also `--no-render`), an
  `audio:` report (mixer, levels, playback).
- `mvp-boot`: `--audio-wav FILE`, a `memory: MEM1 sha1` line, and two
  investigation options: `--count NAME,...` (function entry counts) and
  `--peek ADDR:LEN,...` (guest memory in hex at the end).

## What the game does (measured)

- **AI DSP rate: 32 kHz** (AICR bit 6, set by AIInit/AISetDSPSampleRate):
  `Hardware::ai_dsp_rate()` reads 32000 at every frame (0 rate changes in the WAV
  over 800 frames). One AI DMA block = 0x280 bytes
  = 160 stereo samples = one AX frame.
- **Dolby Pro Logic II mode.** SNDPLATFORM_init calls `AXSetMode(2)` when EA SND
  has more than two output channels (`sndgs+0x3F`, 4 at run time) and
  `AXSetCompressor(0)`. The command list is 0x00, 0x02, 0x03, 0x13, 0x10, 0x0E,
  0x0F (no 0x07/0x04). EA's aux A callback copies its four-channel CPU mix
  (`lbl_8069C8BB` = 4) into the callback's four buffers.
- **Music and movie audio are mixed on the CPU** (EA's `MIX_*`: SNDSTRM taps,
  SNDPKTPLAY packets, `MIX_audioslice` once per audio frame) and reach the DSP
  only as the aux A return. Over the intro, `SNDDRV_allocateaxvoice` is never
  called; the first AX voices are the title screen's START sound (two voices).

## Exit evidence (2026-10-14)

All dumps and pictures stayed in `build/engine/msvc/` and the session's scratch
directory; none is committed. Analysis: Python (numpy/matplotlib) over the WAV:
per-second RMS and peak per channel, per-second spectrum (centroid, band shares,
strongest bins), L/R correlation, frame-boundary continuity, waveform and
spectrogram pictures, looked at.

**1. Boot and intro, no input** (`mvp-play --no-render --fields 3600 --audio-wav`):
60.09 s of guest time, 11,962 AX frames = 1,913,920 stereo frames (59.81 s) at
32 kHz. Overall RMS -16.3 dBFS, peak 31,566 (-0.3 dBFS), 0 clipped samples, 47 of
59 one-second windows above -60 dBFS. 0 AX voices; the aux A return (EA's CPU mix)
was non-zero in 9,527 frames. Over time (WAV seconds, about guest time - 0.3 s):

| WAV time | What | Measured |
|---|---|---|
| 0-9.7 s | boot, loading screen | digital silence |
| 9.7-12.5 s | EA SPORTS logo stinger (the logo is on screen at VI fields 600-720, E1) | RMS -18.7 to -22.9 dBFS, peaks 30,310; mono (L/R correlation 1.000); transient hits with decays, 2-8 kHz 48-77 % of the energy in two of the three seconds |
| 15.5-31 s | a voice-like section of the intro movie (judged from the spectrum only) | RMS -23 to -29 dBFS; 250 Hz-2 kHz 40-84 %, centroid 1.3-2.8 kHz; curved harmonic pitch contours in the spectrogram |
| 31.5-60 s | the intro's music (E1 saw "The Donots - We Got the Noise" on screen) | RMS -11 to -15 dBFS, peaks about 30,500 without clipping; below 250 Hz 28-69 % (strongest bins 38-139 Hz: kick and bass), centroid 0.6-1.3 kHz, full band to 16 kHz; stereo (L/R correlation 0.57 over the file) |

Continuity at the 5 ms frame boundaries (where a misordered or repeated aux
return buffer would show): the mean sample-to-sample step at boundaries over the
mean elsewhere is 1.013 in the music (36-58 s) and 0.989 in the voice-like section
(18-30 s); 0 identical consecutive non-silent frames.

**2. With START taps** (`e3b_starts.txt`: frames 280, 430, 580, ...; `--frames 1500`):
the stinger and the start of the intro until the press at frame 280 skips it,
then the title screen's START sound at 35.5-36.8 s from the first two AX voices
(linear SRC, 1,262 voice-milliseconds; centroid 2.4-3.3 kHz, strongest bins 3.5
and 4.2 kHz, peak 5,581). No music on the title screen or the memory-card dialog
up to frame 1500.

**3. Playback in the window** (`mvp-play --input e3b_starts.txt --frames 800
--audio-wav`): SDL 3.4.18 `wasapi`, device "Headphones (HyperX Cloud Alpha
Wireless)" at 44.1 kHz, 100 ms buffer. 82.0 s of host time for 37.2 s of guest
time (0.45x real time: the intro movie decodes at 0.13-0.18x). Played 2,627,840
frames, 323,141 of them non-silent (10.1 s of sound), peak 30,269; 87 underruns
(the emulation is slower than real time during the movie), 0 skipped, 0 dropped,
resampler ratio 0.9950-1.0014, throttle never waited; 2,224 presents, 0 WebGPU
errors.
- The window run's WAV is **byte-identical** to `mvp-boot`'s WAV of the same
  script and length (sha1 `471e427a...`), and the guest state is identical (MEM1
  sha1 `b6ac9ca6...` in both): playback, rendering and host timing reach neither
  the guest nor the mix.

**4. Determinism (all pass):**
- `local_audio_determinism` (new, 234 s): to frame 800 with START taps, with and
  without the mixer: identical reports (SDK call log sha1 `09cfc165...`, MEM1
  `b6ac9ca6...`, frame log, clock); the mixed run: 7,387 frames, 11 of 36 seconds
  above -60 dBFS, peak 30,498.
- `local_boot_twice` (SDK log `0054fb22...`, unchanged from E0c), `local_input_start`
  (`c6d85264...` / `e652d99f...`, first difference at frame 281, unchanged),
  `local_play_determinism` (MEM1 `eef70ba3...`, unchanged), `local_lockstep`,
  `local_boot_main`, `local_disc`, `local_cfg`, `local_disasm`.
- The 60 s intro and the 1500-frame menu runs gave the same guest state (MEM1
  `318467d5...`, `7f3fe18c...`) with the first mixer build (which ignored DPL2 and
  mixed silence) and the final one.

**5. Data-free tests:** `ctest -LE local` 23/23, among them `test_mixer` (14 cases),
`test_audio_out` (6), `test_audio_sdl` (dummy driver), `test_ax` (7, one new).

**Mixer statistics over 800 frames** (`mvp-boot --audio-wav`): 7,385 of 7,387
frames in DPL2 mode (the first two are stereo with the compressor on, before
SNDPLATFORM_init sets mode 2 and turns it off); every voice millisecond uses
linear SRC; envelope volumes up to 0x0D7D, no envelope deltas; 5 mix-block
reloads, 10 ramped milliseconds; no LPF, no ITD, no aux sends from voices, no
depops, no unknown commands, nothing clipped.

How the silence was found: the first full intro dump was silent although EA's
CPU mixer ran (`--count`: `MIX_audioslice` once per frame, `SNDDRV_audiocallback`
5,224 times by frame 500) and the aux buffers held audio (`--peek`); `--peek` of
`lbl_806EF578` showed AX mode 2 (DPL2), whose command list has 0x13/0x10 instead
of 0x04. With those modeled the intro is audible.

## Known deviations (none reaches guest state)

- Aux sends are not delivered to the guest: the CPU's aux callback sees silence
  where the console would give it the voices' aux A mix (EA converts aux A left to
  float for `fn_803B1364`'s effect buffers; with one effect slot registered, that
  effect hears nothing). Writing them would make guest state depend on the
  mixer's filters.
- DPL2 is a plain fold (rears added to L/R one frame late), not the console's
  matrix encoding; the polyphase table is ours; the compressor (unused) and
  initial time delay (ITD) are not modeled; mixerCtrl bit 0x4000 (DPL2 surround
  input selection) is ignored.
- Depop is host-side (same ramp as the SDK), since `dpop` is never written to the
  PBs and the studio block stays zero.
- Unverified against a console: the per-sample envelope wrap, the ramp
  arithmetic, the order of SRC/envelope/LPF (taken from Dolphin's description).

## Decisions to record (for the lead)

- **D5 (decided, E3b):** replace audio at the DSP command-list level (reasons
  above). ARCHITECTURE §7 and §9 still say "open".
- **E3b-AX2** (R8): the DSP model processes voices per millisecond and writes the
  volume envelope back; nothing else the DSP writes (output, surround and aux send
  buffers, ramped mix volumes, dpop, LPF history) goes to guest memory. Part of the
  netplay configuration like `ax_voices`.
- **E3b-MIX1:** the mixer is a read-only observer; guest state and the WAV of a run
  are independent of the mixer, the renderer, playback and host timing. Host
  audio may only throttle the host (`SdlAudioOut::throttle`), never the guest.
- DETERMINISM R8 can say: AX frames run at AIDINT (5 ms of virtual time, 32 kHz
  DSP rate); output is dropped or time-stretched only on the host side.

## Next step

1. **Speed, not audio:** the intro plays with underruns in a window because the
   movie decodes at 0.13-0.18x real time (E3a's translated-code optimisation); the
   menus already run faster than real time and play cleanly.
2. **Browser (E2):** an AudioWorklet around the same `Ring` (SharedArrayBuffer) and
   `DriftResampler`, 32 kHz into the AudioContext's rate; `throttle()` becomes the
   frame loop's pacing hint.
3. **Further into the game:** menu music and in-game sounds (crowd, bat, commentary)
   need input scripts past the memory-card dialog; the mixer statistics in
   `mvp-boot --audio-wav` show which microcode features (LPF, ITD, aux sends, ramps)
   the game starts using.
4. **Fidelity, optional:** the DPL2 matrix encoding, the DSP ROM's polyphase response
   and the compressor need a console capture or a permissive reference. Delivering
   aux sends to the guest (EA's effect input) would change guest state and needs a
   decision first.
