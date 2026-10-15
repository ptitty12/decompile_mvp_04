# Audio (E3b): the AX mixer on the DSP's frames, WAV dumps, and playback.
#
# engine_audio is data-free and portable (the mixer, the ring, the drift
# resampler, WAV files); engine_audio_sdl plays it through SDL3 in native
# development builds (the browser build will use an AudioWorklet instead).
# SDL3 is the pinned package gfx/ already locates (docs/engine/TOOLCHAIN.md).

add_library(engine_audio STATIC mixer.cpp drift.cpp wav.cpp)
target_link_libraries(engine_audio PUBLIC engine_runtime engine_common)
target_compile_options(engine_audio PRIVATE ${ENGINE_WARN})

engine_test(test_mixer SOURCES tests/test_mixer.cpp LIBS engine_audio)
engine_test(test_audio_out SOURCES tests/test_audio_out.cpp LIBS engine_audio)

if(MVP_SDL3_DIR AND EXISTS "${MVP_SDL3_DIR}/cmake/SDL3Config.cmake")
  find_package(SDL3 CONFIG REQUIRED PATHS "${MVP_SDL3_DIR}/cmake" NO_DEFAULT_PATH)
  add_library(engine_audio_sdl STATIC sdl_out.cpp)
  target_link_libraries(engine_audio_sdl PUBLIC engine_audio PRIVATE SDL3::SDL3)
  target_compile_options(engine_audio_sdl PRIVATE ${ENGINE_WARN})
  # SDL's dummy audio driver: no device needed.
  engine_test(test_audio_sdl SOURCES tests/test_audio_sdl.cpp LIBS engine_audio_sdl SDL3::SDL3)
  add_custom_command(TARGET test_audio_sdl POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:SDL3::SDL3> $<TARGET_FILE_DIR:test_audio_sdl>
    VERBATIM)
  message(STATUS "audio: SDL3 playback")
else()
  message(STATUS "audio: SDL3 not found; no playback (the mixer and WAV dumps still build)")
endif()
