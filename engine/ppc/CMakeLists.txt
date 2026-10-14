add_library(engine_ppc STATIC decode.cpp disasm.cpp)
target_link_libraries(engine_ppc PUBLIC engine_common)
target_compile_options(engine_ppc PRIVATE ${ENGINE_WARN})

engine_test(test_ppc_decode SOURCES tests/test_decode.cpp LIBS engine_ppc)

# Local only: skipped (77) without the disc and dtk's listing.
add_executable(local_disasm tests/local_disasm.cpp)
target_link_libraries(local_disasm PRIVATE engine_ppc engine_vfs)
target_compile_options(local_disasm PRIVATE ${ENGINE_WARN})
target_compile_definitions(local_disasm PRIVATE MVP_DISC_DEFAULT="${MVP_DISC_PATH}" MVP_DTK_ASM_DEFAULT="${MVP_DTK_ASM_PATH}"
                                               MVP_REPO_ROOT="${MVP_REPO_ROOT}")
add_test(NAME local_disasm COMMAND local_disasm)
set_tests_properties(local_disasm PROPERTIES SKIP_RETURN_CODE 77 LABELS local)
