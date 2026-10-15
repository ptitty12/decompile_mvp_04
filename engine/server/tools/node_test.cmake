# Runs the server's Node tests (tsc, then node --test). Exit 77 (skipped) when
# Node or engine/server/node_modules (npm ci) is missing.
#   cmake -DNODE=<node> -DDIR=<engine/server> -P node_test.cmake
if(NOT NODE OR NOT EXISTS "${DIR}/node_modules/typescript/bin/tsc" OR NOT EXISTS "${DIR}/node_modules/ws")
  message("SKIP: Node or engine/server/node_modules missing (npm ci)")
  cmake_language(EXIT 77)
endif()
execute_process(COMMAND "${NODE}" node_modules/typescript/bin/tsc -p tsconfig.json
                WORKING_DIRECTORY "${DIR}" RESULT_VARIABLE rc)
if(NOT rc EQUAL 0)
  message(FATAL_ERROR "tsc failed")
endif()
file(GLOB tests "${DIR}/dist/test/*.test.js")
execute_process(COMMAND "${NODE}" --test ${tests} WORKING_DIRECTORY "${DIR}" RESULT_VARIABLE rc)
if(NOT rc EQUAL 0)
  message(FATAL_ERROR "server tests failed")
endif()
