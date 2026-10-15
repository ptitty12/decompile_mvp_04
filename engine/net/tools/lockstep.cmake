# Netplay lockstep check (E5): two mvp-netplay peers on 127.0.0.1 (player 1 and
# player 2, each driving its own port from the same script) and the solo
# reference (no network, the script shifted by the delay) must agree on every
# frame's input, every state-hash window and the final guest state (instructions,
# time base, frame polls, MEM1 SHA-1). Run by ctest as `local_netplay_lockstep`
# and, over an impaired link, `local_netplay_lossy` (both need the disc); the
# script is written here, the logs stay in the build tree.
#
#   cmake -DTOOL=<mvp-netplay> -DWORK=<dir> [-DFRAMES=N] [-DDELAY=D] [-DIMPAIR="--loss 0.2 --latency 30 --jitter 20"]
#         [-DPORT=47311] [-DEXPECT_STOPS=1] -P lockstep.cmake
#
# The script starts an exhibition game between the two players (E5c): the menus,
# Select Team with player 2 on the away side, then the match's loading, where the
# game polls frames without rendering, closer together than any VI, audio or DVD
# event (frames 2,914-3,000). There a poll could come before the run had a
# chance to wait for the peer ("gate missed", E6); now the run stops at such a
# poll. -DEXPECT_STOPS=1 requires that it did (a slow link makes it certain).
#
# With -DDESYNC=1 player 2 corrupts one window hash instead: both peers must stop
# with a desync at that window.
if(NOT FRAMES)
  set(FRAMES 3050)
endif()
if(NOT DELAY)
  set(DELAY 3)
endif()
if(NOT PORT)
  set(PORT 47311)
endif()
math(EXPR PORT2 "${PORT} + 1")
file(MAKE_DIRECTORY "${WORK}")
set(script "${WORK}/netplay_input.txt")
file(WRITE "${script}" "mvp-input 1
# E5c local test: E3a's path into an exhibition game. Player 1 (port 1) skips
# the intro, passes the memory card and profile dialogs, picks Play Now and
# stays on the home team (Boston); player 2 moves to the away team (St. Louis)
# at Select Team, and both advance their sides through the uniforms and the
# difficulty. The match loads from frame 2,913.
280 1 tap 3 START
430 1 tap 3 START
580 1 tap 3 START
730 1 tap 3 START
800 1 tap 3 DOWN
860 1 tap 3 A
1300 1 tap 3 DOWN
1360 1 tap 3 A
1500 1 tap 3 A
1700 2 tap 3 LEFT
1900 1 tap 3 A
1910 2 tap 3 A
2700 1 tap 3 A
2710 2 tap 3 A
2900 1 tap 3 A
2910 2 tap 3 A
")
separate_arguments(impair UNIX_COMMAND "${IMPAIR}")
set(common --input "${script}" --frames ${FRAMES} --delay ${DELAY} --hash-every 60)

if(NOT DESYNC)
  execute_process(COMMAND "${TOOL}" solo ${common} --log "${WORK}/solo.frames"
                  WORKING_DIRECTORY "${WORK}" OUTPUT_VARIABLE out_solo RESULT_VARIABLE rc_solo)
  if(rc_solo EQUAL 77)
    message("SKIP: no disc")
    cmake_language(EXIT 77)
  endif()
endif()

set(corrupt)
if(DESYNC)
  set(corrupt --corrupt-window 599)
endif()
# The two peers run at the same time (execute_process runs its commands as one
# pipeline; neither reads its standard input). Each writes its report to a file.
execute_process(
  COMMAND "${TOOL}" peer --player 1 --port ${PORT} --peer-port ${PORT2} ${common} ${impair}
          --log "${WORK}/p1.frames" --report "${WORK}/p1.report" --diag "${WORK}/p1.diag"
  COMMAND "${TOOL}" peer --player 2 --port ${PORT2} --peer-port ${PORT} ${common} ${impair} ${corrupt}
          --log "${WORK}/p2.frames" --report "${WORK}/p2.report" --diag "${WORK}/p2.diag"
  WORKING_DIRECTORY "${WORK}"
  RESULTS_VARIABLE rcs
  OUTPUT_QUIET ERROR_QUIET)
if(rcs MATCHES "77")
  message("SKIP: no disc")
  cmake_language(EXIT 77)
endif()
file(READ "${WORK}/p1.report" out_p1)
file(READ "${WORK}/p2.report" out_p2)
message("player 1:\n${out_p1}")
message("player 2:\n${out_p2}")

if(DESYNC)
  foreach(p p1 p2)
    if(NOT out_${p} MATCHES "session: desynced")
      message(FATAL_ERROR "${p} did not stop with a desync")
    endif()
  endforeach()
  if(NOT out_p1 MATCHES "frame 599")
    message(FATAL_ERROR "player 1 did not name the corrupted window (frame 599)")
  endif()
  message("PASS: both peers stopped with a desync at the corrupted window")
  return()
endif()

message("solo:\n${out_solo}")
foreach(p solo p1 p2)
  if(NOT out_${p} MATCHES "stopped: ran ${FRAMES} frames")
    string(REGEX MATCH "stopped: [^\n]*" stop "${out_${p}}")
    message(FATAL_ERROR "${p} did not run ${FRAMES} frames: ${stop}")
  endif()
  string(REGEX MATCH "frame log [^,]*, ([0-9]+ bytes, sha1 [0-9a-f]+)" m "${out_${p}}")
  set(frames_${p} "${CMAKE_MATCH_1}")
  string(REGEX MATCH "windows: [^\n]*" windows_${p} "${out_${p}}")
  string(REGEX MATCH "guest: [^\n]*" guest_${p} "${out_${p}}")
endforeach()
set(stops 0)
foreach(p p1 p2)
  if(NOT out_${p} MATCHES " 0 gate misses")
    message(FATAL_ERROR "${p}: the lockstep gate missed a frame poll")
  endif()
  string(REGEX MATCH "([0-9]+) poll stops" m "${out_${p}}")
  math(EXPR stops "${stops} + ${CMAKE_MATCH_1}")
  if(out_${p} MATCHES "session: desynced")
    message(FATAL_ERROR "${p}: desync")
  endif()
  foreach(what frames windows guest)
    if(NOT "${${what}_${p}}" STREQUAL "${${what}_solo}")
      message(FATAL_ERROR "${p} and the solo run differ in ${what}:\n  ${${what}_${p}}\n  ${${what}_solo}")
    endif()
  endforeach()
endforeach()
if(EXPECT_STOPS AND stops EQUAL 0)
  message(FATAL_ERROR "no run stopped at a frame poll: the test did not exercise the wait at the poll")
endif()
message("PASS: two peers and the solo reference agree on ${FRAMES} frames of input, every state-hash window and the "
        "final guest state; ${stops} runs stopped at a poll to wait for the peer, 0 gate misses")
