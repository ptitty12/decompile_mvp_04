add_library(engine_common STATIC sha1.cpp file.cpp)
target_include_directories(engine_common PUBLIC ${PROJECT_SOURCE_DIR})
target_compile_options(engine_common PRIVATE ${ENGINE_WARN})

engine_test(test_common SOURCES tests/test_common.cpp LIBS engine_common)
