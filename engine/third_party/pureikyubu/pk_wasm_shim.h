// Added for the MVP engine's WebAssembly build (not part of pureikyubu): there is
// no x86 cycle counter. ReadCycleCounter only feeds the optional host profiling
// (CpuStats), which the differential test never turns on. Force-included by
// CMakeLists.txt under Emscripten only.
#pragma once
#if defined(__EMSCRIPTEN__)
#define __builtin_ia32_rdtsc() 0ull
#endif
