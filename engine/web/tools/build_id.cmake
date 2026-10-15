# Writes the site's build-id.json (E2c): the SHA-256 of the engine module
# (mvp-web.wasm) and of symbols.txt. The Worker keys the browser's cache of the
# translated module by these and the DOL's SHA-1, so a different engine build or
# symbol map never loads a stale translation.
#
#   cmake -DWASM=<mvp-web.wasm> -DSYMBOLS=<symbols.txt> -DOUT=<build-id.json> -P build_id.cmake
file(SHA256 "${WASM}" engine)
file(SHA256 "${SYMBOLS}" symbols)
set(text "{\"engine\":\"${engine}\",\"symbols\":\"${symbols}\"}\n")
if(EXISTS "${OUT}")
  file(READ "${OUT}" old)
  if(old STREQUAL text)
    return()
  endif()
endif()
file(WRITE "${OUT}" "${text}")
