# Roster and team packs (E6): format v1 of docs/MODDING.md, the engine's
# implementation. Data-free; the reference is tools/rosters/pack.py.
add_library(engine_mods STATIC json.cpp tables.cpp zip.cpp pack.cpp apply.cpp mount.cpp)
target_link_libraries(engine_mods PUBLIC engine_vfs engine_common)
target_compile_options(engine_mods PRIVATE ${ENGINE_WARN})

# mvp-pack: pack.py's commands on the engine's implementation (and mount-check).
add_executable(mvp-pack tools/mvp_pack.cpp)
target_link_libraries(mvp-pack PRIVATE engine_mods)
target_compile_options(mvp-pack PRIVATE ${ENGINE_WARN})

engine_test(test_mods SOURCES tests/test_mods.cpp LIBS engine_mods
            ENV "MVP_REPO_ROOT=${MVP_REPO_ROOT}")

# The cross-check against the reference tool: pack.py's own synthetic disc and
# test packs (tools/rosters/tests/test_pack.py), applied by both; issues, pack,
# set and result hashes and the output files must be identical. Python only
# (standard library); skipped (77) without it. Native builds only: under
# Emscripten mvp-pack runs through Node, which the harness does not drive.
if(NOT EMSCRIPTEN)
  find_package(Python3 COMPONENTS Interpreter QUIET)
  if(Python3_Interpreter_FOUND)
    add_test(NAME mods_crosscheck
             COMMAND ${Python3_EXECUTABLE} -I ${CMAKE_CURRENT_SOURCE_DIR}/tests/crosscheck.py
                     --mvp-pack $<TARGET_FILE:mvp-pack> --repo ${MVP_REPO_ROOT})
    set_tests_properties(mods_crosscheck PROPERTIES SKIP_RETURN_CODE 77)
  endif()
endif()
