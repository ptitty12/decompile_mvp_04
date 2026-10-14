# pureikyubu's Gekko interpreter core (CC0-1.0), used only as a test oracle.
# See docs/REUSE.md section 6. pk_jit_stub.h and its include in pch.h are ours;
# the other files are unmodified upstream (pinned commit 0c29dca5).
add_library(pureikyubu_core STATIC gekko.cpp gekkoc.cpp gekkodec.cpp gekkodisasm.cpp stubs.cpp)
target_include_directories(pureikyubu_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
if(MSVC)
  target_compile_options(pureikyubu_core PRIVATE /w /utf-8 /EHsc)
  target_compile_definitions(pureikyubu_core PUBLIC _WINDOWS _CRT_SECURE_NO_WARNINGS)
else()
  target_compile_options(pureikyubu_core PRIVATE -w -fno-strict-aliasing)
  target_compile_definitions(pureikyubu_core PUBLIC _LINUX)
endif()
