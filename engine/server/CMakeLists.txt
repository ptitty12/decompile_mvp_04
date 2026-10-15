# The VPS server (E5; TypeScript on Node, D3). Not built by CMake: `npm ci` and
# `npm test` in this directory (docs/engine/NETPLAY.md). ctest runs its tests
# when Node and the pinned packages (node_modules) are installed, else skips.
find_program(MVP_NODE_EXE node)
add_test(NAME server_node_tests
         COMMAND ${CMAKE_COMMAND} "-DNODE=${MVP_NODE_EXE}" -DDIR=${CMAKE_CURRENT_SOURCE_DIR}
                 -P ${CMAKE_CURRENT_SOURCE_DIR}/tools/node_test.cmake)
set_tests_properties(server_node_tests PROPERTIES SKIP_RETURN_CODE 77 TIMEOUT 300)
