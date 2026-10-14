add_library(engine_runtime STATIC native.cpp machine.cpp)
target_link_libraries(engine_runtime PUBLIC engine_ppc engine_vfs)
target_compile_options(engine_runtime PRIVATE ${ENGINE_WARN})

# Lockstep checker (development): translated code against the interpreter.
add_library(engine_lockstep STATIC lockstep.cpp)
target_link_libraries(engine_lockstep PUBLIC engine_runtime engine_translator)
target_compile_options(engine_lockstep PRIVATE ${ENGINE_WARN})

# Data-free emitter test: the synthetic program is translated at build time.
set(MVP_SYNTH_DIR ${CMAKE_BINARY_DIR}/synth_gen)
set(MVP_SYNTH_SOURCES ${MVP_SYNTH_DIR}/game_00.cpp ${MVP_SYNTH_DIR}/game_01.cpp ${MVP_SYNTH_DIR}/game_table.cpp)
add_custom_command(
  OUTPUT ${MVP_SYNTH_SOURCES} ${MVP_SYNTH_DIR}/game_decls.h
  COMMAND mvp-synth-emit ${MVP_SYNTH_DIR}
  DEPENDS mvp-synth-emit
  COMMENT "Translating the synthetic test program to C++"
  VERBATIM)
engine_test(test_emit_lockstep SOURCES tests/test_emit_lockstep.cpp ${PROJECT_SOURCE_DIR}/translator/tests/synth.cpp
            ${MVP_SYNTH_SOURCES} LIBS engine_lockstep)
target_include_directories(test_emit_lockstep PRIVATE ${MVP_SYNTH_DIR})
if(MSVC)
  set_source_files_properties(${MVP_SYNTH_SOURCES} PROPERTIES COMPILE_OPTIONS "/w;/bigobj")
else()
  set_source_files_properties(${MVP_SYNTH_SOURCES} PROPERTIES COMPILE_OPTIONS "-w")
endif()

# ---- Translated game code: local only, derived from the player's disc ----
# mvp-xlat translates main.dol into build/engine/<preset>/gen at build time. The
# files never leave build/. Without the disc these targets do not exist.
if(MVP_DISC_PATH AND EXISTS "${MVP_DISC_PATH}")
  set(MVP_GEN_DIR ${CMAKE_BINARY_DIR}/gen)
  set(MVP_GEN_SHARDS 48)
  set(MVP_GEN_SOURCES ${MVP_GEN_DIR}/game_table.cpp)
  math(EXPR last "${MVP_GEN_SHARDS} - 1")
  foreach(i RANGE 0 ${last})
    if(i LESS 10)
      list(APPEND MVP_GEN_SOURCES ${MVP_GEN_DIR}/game_0${i}.cpp)
    else()
      list(APPEND MVP_GEN_SOURCES ${MVP_GEN_DIR}/game_${i}.cpp)
    endif()
  endforeach()
  add_custom_command(
    OUTPUT ${MVP_GEN_SOURCES} ${MVP_GEN_DIR}/game_decls.h
    COMMAND mvp-xlat emit-cpp ${MVP_GEN_DIR} --shards ${MVP_GEN_SHARDS}
    DEPENDS mvp-xlat ${MVP_REPO_ROOT}/config/GV4E69/symbols.txt
    COMMENT "Translating main.dol to C++ (build/ only)"
    VERBATIM)
  add_library(mvp_game_native STATIC ${MVP_GEN_SOURCES})
  target_include_directories(mvp_game_native PRIVATE ${MVP_GEN_DIR})
  target_link_libraries(mvp_game_native PUBLIC engine_runtime)
  set_target_properties(mvp_game_native PROPERTIES MSVC_DEBUG_INFORMATION_FORMAT "")
  if(MSVC)
    target_compile_options(mvp_game_native PRIVATE /Od /bigobj /w /EHsc)
  else()
    target_compile_options(mvp_game_native PRIVATE -O1 -w)
  endif()

  add_executable(mvp-boot tools/mvp_boot.cpp)
  target_link_libraries(mvp-boot PRIVATE mvp_game_native engine_lockstep)
  target_compile_options(mvp-boot PRIVATE ${ENGINE_WARN})
  if(MSVC)
    target_link_options(mvp-boot PRIVATE /STACK:67108864)
  endif()
  add_test(NAME local_lockstep COMMAND mvp-boot lockstep)
  set_tests_properties(local_lockstep PROPERTIES SKIP_RETURN_CODE 77 LABELS local)
endif()
