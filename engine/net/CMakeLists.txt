# Netplay (E5): lockstep session, wire protocol, transports, state hashes.
# docs/engine/NETPLAY.md describes the protocol; docs/engine/E5_LOG.md the work.
add_library(engine_net STATIC protocol.cpp session.cpp transport.cpp state_hash.cpp identity.cpp)
target_link_libraries(engine_net PUBLIC engine_runtime engine_common)
target_compile_options(engine_net PRIVATE ${ENGINE_WARN})

engine_test(test_net_protocol SOURCES tests/test_protocol.cpp LIBS engine_net)
engine_test(test_net_session SOURCES tests/test_session.cpp LIBS engine_net)

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
