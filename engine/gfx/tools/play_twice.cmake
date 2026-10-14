# Determinism check for the renderer (E1): runs the game for FIELDS VI fields
# with the WebGPU renderer attached (off-screen) and again with no renderer,
# and requires the same guest state at the end ("guest:" line: instructions,
# time base, frame polls, SHA-1 of MEM1). The rendered run must also succeed
# (frames shown, no WebGPU errors). Run by ctest as `local_play_determinism`.
#   cmake -DPLAY=<mvp-play> -DWORK=<dir> [-DFIELDS=N] [-DINPUT=<script>] -P play_twice.cmake
if(NOT FIELDS)
  set(FIELDS 700)
endif()
set(extra)
if(INPUT)
  set(extra --input "${INPUT}")
endif()
foreach(mode render norender)
  if(mode STREQUAL "render")
    set(flags --headless)
  else()
    set(flags --no-render)
  endif()
  execute_process(
    COMMAND "${PLAY}" ${flags} --fields ${FIELDS} ${extra}
    WORKING_DIRECTORY "${WORK}"
    OUTPUT_VARIABLE out_${mode}
    ERROR_VARIABLE err_${mode}
    RESULT_VARIABLE rc_${mode})
  if(rc_${mode} EQUAL 77)
    message("SKIP: no disc")
    cmake_language(EXIT 77)
  endif()
  string(REGEX MATCH "guest: [^\n]*" guest_${mode} "${out_${mode}}")
endforeach()
if(rc_render EQUAL 1 AND err_render MATCHES "no WebGPU adapter|no WebGPU device")
  message("SKIP: no GPU (${err_render})")
  cmake_language(EXIT 77)
endif()
string(REGEX MATCH "renderer: [^\n]*" rstats "${out_render}")
message("rendered: ${guest_render}")
message("          ${rstats}")
message("alone:    ${guest_norender}")
if(NOT rc_render EQUAL 0)
  file(WRITE "${WORK}/play_render.txt" "${out_render}\n${err_render}")
  message(FATAL_ERROR "the rendered run failed (exit ${rc_render}; report in ${WORK}/play_render.txt)")
endif()
if(guest_render STREQUAL "" OR NOT guest_render STREQUAL guest_norender)
  message(FATAL_ERROR "the guest state differs with and without the renderer")
endif()
message("PASS: the renderer does not change the guest")
