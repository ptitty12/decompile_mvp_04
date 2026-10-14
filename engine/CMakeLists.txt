# MVP Baseball 2005 browser engine: native development build.
#
# Layout and design: ../docs/ARCHITECTURE.md (§11) and ../docs/engine/E0_SURVEY.md (§8).
# Everything derived from the disc (extracted DOL, translated C++, traces) is
# written under the build tree, never into the source tree.
cmake_minimum_required(VERSION 3.25)
project(mvp_engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Optional local data for tests that need the disc. Unset means those tests
# report "skipped" (exit code 77). They default to the environment variables of
# the same name at configure time, and those also override them at test time.
set(MVP_DISC "$ENV{MVP_DISC}" CACHE FILEPATH "Player's GV4E69 disc image (ISO or CISO), for local-only tests")
set(MVP_DTK_ASM "$ENV{MVP_DTK_ASM}" CACHE PATH "dtk split assembly directory (build/GV4E69/asm), for the local disassembler check")

# Repository root: config/GV4E69 (symbols.txt, splits.txt) is metadata, not game data.
get_filename_component(MVP_REPO_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/.." ABSOLUTE)

# Deterministic floating point on the host: no contraction into FMA, no fast-math.
if(MSVC)
  set(ENGINE_WARN /W4 /permissive- /utf-8 /Zc:__cplusplus /Zc:preprocessor /fp:precise /EHsc /bigobj)
  add_compile_definitions(_CRT_SECURE_NO_WARNINGS NOMINMAX WIN32_LEAN_AND_MEAN)
else()
  set(ENGINE_WARN -Wall -Wextra -ffp-contract=off -fno-fast-math)
endif()

enable_testing()

# Test framework (doctest, MIT, vendored: see docs/REUSE.md).
add_library(engine_doctest_main STATIC third_party/doctest_main.cpp)
target_include_directories(engine_doctest_main PUBLIC third_party)

# Tests that need local data exit 77 when it is missing; ctest reports them as skipped.
function(engine_test name)
  cmake_parse_arguments(ET "" "" "SOURCES;LIBS;ENV" ${ARGN})
  add_executable(${name} ${ET_SOURCES})
  target_link_libraries(${name} PRIVATE engine_doctest_main ${ET_LIBS})
  target_compile_options(${name} PRIVATE ${ENGINE_WARN})
  add_test(NAME ${name} COMMAND ${name})
  set_tests_properties(${name} PROPERTIES SKIP_RETURN_CODE 77)
  if(ET_ENV)
    set_tests_properties(${name} PROPERTIES ENVIRONMENT "${ET_ENV}")
  endif()
endfunction()

add_subdirectory(common)
