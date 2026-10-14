# Determinism check (E0b items 9 and 10): boots the game twice with the same
# budget and compares the reports, including the SDK call log's SHA-1. Run by
# ctest as `local_boot_twice` (needs the disc); the logs stay in the build tree.
#   cmake -DBOOT=<mvp-boot> [-DEMULATOR=<runner, e.g. node>] -DWORK=<dir> [-DUNTIL=0xADDR] [-DENTRIES=N] [-DTICKS=N] -P twice.cmake
# With UNTIL the run must reach that function entry; without it, use up the budget.
if(NOT ENTRIES)
  set(ENTRIES 30000000)
endif()
if(NOT UNTIL)
  set(UNTIL none)
endif()
if(NOT TICKS)
  set(TICKS 20000000000)
endif()
foreach(run 1 2)
  execute_process(
    COMMAND ${EMULATOR} "${BOOT}" run --until ${UNTIL} --mmio 0 --max-entries ${ENTRIES} --max-ticks ${TICKS} --log "${WORK}/twice_${run}.log"
    WORKING_DIRECTORY "${WORK}"
    OUTPUT_VARIABLE out_${run}
    RESULT_VARIABLE rc_${run})
  if(rc_${run} EQUAL 77)
    message("SKIP: no disc")
    cmake_language(EXIT 77)  # ctest reports exit code 77 as skipped (SKIP_RETURN_CODE)
  endif()
  # The log's file name is the only difference between the two reports.
  string(REPLACE "twice_${run}.log" "twice.log" out_${run} "${out_${run}}")
endforeach()
string(REGEX MATCH "sha1 [0-9a-f]+" hash "${out_1}")
string(REGEX MATCH "stopped: [^\n]*" stop "${out_1}")
message("run 1: ${stop}; SDK call log ${hash}")
if(NOT out_1 STREQUAL out_2)
  file(WRITE "${WORK}/twice_1.txt" "${out_1}")
  file(WRITE "${WORK}/twice_2.txt" "${out_2}")
  message(FATAL_ERROR "the two runs differ (reports in ${WORK}/twice_1.txt and twice_2.txt)")
endif()
if(UNTIL STREQUAL "none")
  if(NOT stop MATCHES "budget used up")
    message(FATAL_ERROR "the run stopped early: ${stop}")
  endif()
elseif(NOT stop MATCHES "^stopped: reached")
  message(FATAL_ERROR "the run did not reach ${UNTIL}: ${stop}")
endif()
message("PASS: two runs are identical")
