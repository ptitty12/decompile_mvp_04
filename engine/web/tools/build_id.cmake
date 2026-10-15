# Writes the site's build-id.json (E2c): the SHA-256 of the engine module
# (mvp-web.wasm), of the threaded engine module (mvp-web-mt.wasm, P2, when it
# was built) and of symbols.txt. The Worker keys the browser's cache of the
# translated module by these and the DOL's SHA-1, so a different engine build or
# symbol map never loads a stale translation.
#
#   cmake -DWASM=<mvp-web.wasm> [-DWASM_MT=<mvp-web-mt.wasm>] -DSYMBOLS=<symbols.txt> -DOUT=<build-id.json> -P build_id.cmake
if(NOT EXISTS "${WASM}")
  return()  # the engine is not linked yet: its own build writes this file
endif()
file(SHA256 "${WASM}" engine)
file(SHA256 "${SYMBOLS}" symbols)
set(text "{\"engine\":\"${engine}\",\"symbols\":\"${symbols}\"")
if(WASM_MT AND EXISTS "${WASM_MT}")
  file(SHA256 "${WASM_MT}" engine_mt)
  string(APPEND text ",\"engine_mt\":\"${engine_mt}\"")
endif()
string(APPEND text "}\n")
if(EXISTS "${OUT}")
  file(READ "${OUT}" old)
  if(old STREQUAL text)
    return()
  endif()
endif()
file(WRITE "${OUT}" "${text}")
