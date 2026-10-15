# Determinism check for the mixer (E3b): mvp-boot runs to frame FRAMES with
# START taps (the intro's music through the aux return, then the first sound
# effects on AX voices), once mixing into a WAV and once without a mixer. The
# reports must be identical apart from the audio lines and the log file names:
# SDK call log, frame log, clock, MEM1 hash, AX voice counts. The mixed run must
# have produced non-silent audio. Run by ctest as `local_audio_determinism`;
# the logs and the WAV stay in the build tree (never commit them).
#   cmake -DBOOT=<mvp-boot> -DWORK=<dir> [-DFRAMES=N] -P audio_twice.cmake
if(NOT FRAMES)
  set(FRAMES 800)
endif()
set(script "${WORK}/audio_starts.txt")
file(WRITE "${script}" "mvp-input 1\n# E3b local test: START taps through the intro and the title\n"
                       "280 1 tap 3 START\n430 1 tap 3 START\n580 1 tap 3 START\n730 1 tap 3 START\n")
foreach(run mix nomix)
  set(extra)
  if(run STREQUAL "mix")
    set(extra --audio-wav "${WORK}/audio_twice.wav")
  endif()
  execute_process(
    COMMAND "${BOOT}" run --until none --mmio 0 --max-entries 8000000000 --max-ticks 80000000000 --frames ${FRAMES}
            --input "${script}" --log "${WORK}/audio_${run}.log" --frame-log "${WORK}/audio_${run}.frames" ${extra}
    WORKING_DIRECTORY "${WORK}"
    OUTPUT_VARIABLE out_${run}
    RESULT_VARIABLE rc_${run})
  if(rc_${run} EQUAL 77)
    message("SKIP: no disc")
    cmake_language(EXIT 77)
  endif()
  if(NOT out_${run} MATCHES "stopped: ran ${FRAMES} frames")
    string(REGEX MATCH "stopped: [^\n]*" stop "${out_${run}}")
    message(FATAL_ERROR "run ${run} did not run ${FRAMES} frames: ${stop}")
  endif()
  string(REPLACE ";" "," out_${run} "${out_${run}}")  # CMake lists split at semicolons
  string(REGEX MATCHALL "audio: [^\n]*" audio_${run} "${out_${run}}")
  string(REGEX REPLACE "audio: [^\n]*\n" "" out_${run} "${out_${run}}")
  string(REPLACE "audio_${run}." "audio." out_${run} "${out_${run}}")
endforeach()
string(REGEX MATCH "SDK call log: [^\n]*" log "${out_mix}")
string(REGEX MATCH "memory: [^\n]*" mem "${out_mix}")
message("${log}")
message("${mem}")
foreach(line IN LISTS audio_mix)
  message("${line}")
endforeach()
if(NOT out_mix STREQUAL out_nomix)
  file(WRITE "${WORK}/audio_mix.txt" "${out_mix}")
  file(WRITE "${WORK}/audio_nomix.txt" "${out_nomix}")
  message(FATAL_ERROR "the guest differs with and without the mixer (reports in ${WORK}/audio_mix.txt and audio_nomix.txt)")
endif()
if(NOT audio_nomix STREQUAL "")
  message(FATAL_ERROR "the run without --audio-wav printed audio lines")
endif()
if(NOT audio_mix MATCHES " ([1-9][0-9]*) of [0-9]+ windows above -60 dBFS")
  message(FATAL_ERROR "the mixed run produced no audible audio")
endif()
message("PASS: the mixer does not change the guest (and it mixed audible audio)")
