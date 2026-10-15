# Netplay (E5): lockstep session, wire protocol, transports, state hashes.
# docs/engine/NETPLAY.md describes the protocol; docs/engine/E5_LOG.md the work.
add_library(engine_net STATIC protocol.cpp session.cpp transport.cpp state_hash.cpp identity.cpp driver.cpp)
target_link_libraries(engine_net PUBLIC engine_runtime engine_common)
target_compile_options(engine_net PRIVATE ${ENGINE_WARN})

engine_test(test_net_protocol SOURCES tests/test_protocol.cpp LIBS engine_net)
engine_test(test_net_session SOURCES tests/test_session.cpp LIBS engine_net)
engine_test(test_net_driver SOURCES tests/test_driver.cpp LIBS engine_net)

# Native transports (UDP, impairment on the real clock): not in the browser,
# where the transport is a WebRTC data channel (engine/web).
if(NOT EMSCRIPTEN)
  add_library(engine_net_udp STATIC udp.cpp)
  target_link_libraries(engine_net_udp PUBLIC engine_net)
  target_compile_options(engine_net_udp PRIVATE ${ENGINE_WARN})
  if(WIN32)
    target_link_libraries(engine_net_udp PUBLIC ws2_32)
  endif()
  engine_test(test_net_udp SOURCES tests/test_udp.cpp LIBS engine_net_udp)
endif()

# ---- Local only: the translated DOL under netplay (needs the disc) ----
# mvp-netplay runs two peers over UDP on 127.0.0.1 (tools/mvp_netplay.cpp);
# local_netplay_lockstep checks that two peers and the solo reference agree on
# every frame's input, every state-hash window and the final guest state, from
# power-on into the loading of a two-player exhibition game (E5c), with player 2
# slowed down over the loading's fast frame polls so that player 1's run must
# stop at one to wait; local_netplay_lossy does the same over a slow, lossy link.
if(TARGET mvp_game_native AND NOT EMSCRIPTEN)
  add_executable(mvp-netplay tools/mvp_netplay.cpp)
  target_link_libraries(mvp-netplay PRIVATE mvp_game_native engine_net_udp engine_translator)
  target_compile_options(mvp-netplay PRIVATE ${ENGINE_WARN})
  if(MSVC)
    target_link_options(mvp-netplay PRIVATE /STACK:67108864)
  endif()
  add_test(NAME local_netplay_lockstep
           COMMAND ${CMAKE_COMMAND} -DTOOL=$<TARGET_FILE:mvp-netplay> -DWORK=${CMAKE_BINARY_DIR}/netplay
                   -DFRAMES=3050 -DDELAY=3 "-DSTALL=--stall-from 2905 --stall-to 3045 --stall-ms 20" -DEXPECT_STOPS=1
                   -P ${CMAKE_CURRENT_SOURCE_DIR}/tools/lockstep.cmake)
  add_test(NAME local_netplay_lossy
           COMMAND ${CMAKE_COMMAND} -DTOOL=$<TARGET_FILE:mvp-netplay> -DWORK=${CMAKE_BINARY_DIR}/netplay-lossy
                   -DFRAMES=3050 -DDELAY=3 -DPORT=47321 "-DIMPAIR=--loss 0.1 --latency 20 --jitter 10"
                   -P ${CMAKE_CURRENT_SOURCE_DIR}/tools/lockstep.cmake)
  set_tests_properties(local_netplay_lockstep local_netplay_lossy PROPERTIES SKIP_RETURN_CODE 77 LABELS local
                       TIMEOUT 1800)
endif()
