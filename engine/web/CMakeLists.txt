# The browser build (E2): the engine as a Worker module (mvp-web.js + .wasm)
# and the web shell (TypeScript), assembled into one static site directory:
#
#   build/engine/emscripten/web/site/
#     index.html, style.css      the page (static/)
#     main.js, worker.js, ...    the shell (src/*.ts, compiled by tsc)
#     mvp-web.js, mvp-web.wasm   the engine: translator, runtime, renderer
#     symbols.txt                config/GV4E69/symbols.txt (repository metadata,
#                                not game data: ARCHITECTURE.md §4)
#
# Nothing in it is derived from the disc: the player's browser translates the
# DOL from the image the player picks. tools/serve.mjs serves this directory
# (and only it) on localhost. docs/engine/WEB.md has the details.

set(MVP_WEB_SITE ${CMAKE_CURRENT_BINARY_DIR}/site)

# ---- The engine module ----
add_executable(mvp-web wasm/mvp_web.cpp wasm/net_web.cpp)
target_link_libraries(mvp-web PRIVATE engine_wasm_host engine_net)
target_compile_options(mvp-web PRIVATE ${ENGINE_WARN})
if(TARGET engine_gfx_wgpu)
  target_link_libraries(mvp-web PRIVATE engine_gfx_wgpu)
else()
  message(WARNING "web: no browser renderer (emdawnwebgpu missing); mvp-web is not built")
  set_target_properties(mvp-web PROPERTIES EXCLUDE_FROM_ALL ON)
endif()
set_target_properties(mvp-web PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${MVP_WEB_SITE})
# The engine-wide Emscripten options target Node (tests and tools); these come
# after them and win: a Worker ES module, no host file system, the runtime
# kept alive between calls, the exports the shell uses.
target_link_options(mvp-web PRIVATE
  -sENVIRONMENT=worker
  -sNODERAWFS=0
  -sEXIT_RUNTIME=0
  -sMODULARIZE=1
  -sEXPORT_ES6=1
  -sEXPORT_NAME=createMvpEngine
  -sALLOW_TABLE_GROWTH=1
  "-sEXPORTED_RUNTIME_METHODS=['UTF8ToString','HEAPU8','specialHTMLTargets']"
  "-sEXPORTED_FUNCTIONS=['_malloc','_free']")

# ---- The shell ----
# tsc from engine/web/node_modules (pinned in package.json / package-lock.json;
# installed with `npm ci` in engine/web, docs/engine/TOOLCHAIN.md).
set(MVP_WEB_TSC ${CMAKE_CURRENT_SOURCE_DIR}/node_modules/typescript/bin/tsc)
# The SDK's Node (Emscripten's toolchain file finds it for running the tests).
set(MVP_NODE "${CMAKE_CROSSCOMPILING_EMULATOR}")
file(GLOB MVP_WEB_TS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.ts)
file(GLOB MVP_WEB_STATIC CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/static/*)
if(EXISTS ${MVP_WEB_TSC} AND MVP_NODE)
  add_custom_command(
    OUTPUT ${MVP_WEB_SITE}/main.js ${MVP_WEB_SITE}/worker.js
    COMMAND ${MVP_NODE} ${MVP_WEB_TSC} -p ${CMAKE_CURRENT_SOURCE_DIR}/tsconfig.json --outDir ${MVP_WEB_SITE}
    DEPENDS ${MVP_WEB_TS} ${CMAKE_CURRENT_SOURCE_DIR}/tsconfig.json
    COMMENT "web: compiling the shell (tsc)"
    VERBATIM)
  set(_mvp_web_js ${MVP_WEB_SITE}/main.js ${MVP_WEB_SITE}/worker.js)
else()
  message(STATUS "web: TypeScript not installed in engine/web/node_modules (npm ci); the shell is not compiled")
  set(_mvp_web_js)
endif()
set(_mvp_web_copies)
foreach(f ${MVP_WEB_STATIC})
  get_filename_component(n ${f} NAME)
  add_custom_command(OUTPUT ${MVP_WEB_SITE}/${n}
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different ${f} ${MVP_WEB_SITE}/${n}
                     DEPENDS ${f} VERBATIM)
  list(APPEND _mvp_web_copies ${MVP_WEB_SITE}/${n})
endforeach()
add_custom_command(OUTPUT ${MVP_WEB_SITE}/symbols.txt
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different ${MVP_REPO_ROOT}/config/GV4E69/symbols.txt
                           ${MVP_WEB_SITE}/symbols.txt
                   DEPENDS ${MVP_REPO_ROOT}/config/GV4E69/symbols.txt VERBATIM)
# Notices for the third-party code compiled into mvp-web.js/.wasm (docs/REUSE.md
# §6): Emscripten's runtime and libraries, and emdawnwebgpu (Dawn's BSD-3-Clause
# C++ side; its JS side is under Emscripten's license).
set(_mvp_web_notices)
if(EMSCRIPTEN_ROOT_PATH AND EXISTS "${EMSCRIPTEN_ROOT_PATH}/LICENSE")
  list(APPEND _mvp_web_notices "${EMSCRIPTEN_ROOT_PATH}/LICENSE=emscripten.txt")
endif()
if(MVP_EMDAWNWEBGPU_DIR AND EXISTS "${MVP_EMDAWNWEBGPU_DIR}/webgpu_cpp/LICENSE")
  list(APPEND _mvp_web_notices "${MVP_EMDAWNWEBGPU_DIR}/webgpu_cpp/LICENSE=dawn-emdawnwebgpu.txt")
endif()
foreach(pair ${_mvp_web_notices})
  string(REPLACE "=" ";" pair "${pair}")
  list(GET pair 0 src)
  list(GET pair 1 name)
  add_custom_command(OUTPUT ${MVP_WEB_SITE}/licenses/${name}
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different ${src} ${MVP_WEB_SITE}/licenses/${name}
                     DEPENDS ${src} VERBATIM)
  list(APPEND _mvp_web_copies ${MVP_WEB_SITE}/licenses/${name})
endforeach()

add_custom_target(mvp-web-shell ALL DEPENDS ${_mvp_web_js} ${_mvp_web_copies} ${MVP_WEB_SITE}/symbols.txt)
add_dependencies(mvp-web mvp-web-shell)
