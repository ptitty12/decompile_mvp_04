add_library(engine_translator STATIC symbols.cpp cfg.cpp program.cpp)
target_link_libraries(engine_translator PUBLIC engine_ppc engine_vfs)
target_compile_options(engine_translator PRIVATE ${ENGINE_WARN})
set_source_files_properties(program.cpp PROPERTIES COMPILE_DEFINITIONS
                            "MVP_DISC_DEFAULT=\"${MVP_DISC_PATH}\";MVP_REPO_ROOT=\"${MVP_REPO_ROOT}\"")

add_executable(mvp-xlat tools/mvp_xlat.cpp)
target_link_libraries(mvp-xlat PRIVATE engine_translator)
target_compile_options(mvp-xlat PRIVATE ${ENGINE_WARN})

engine_test(test_translator_cfg SOURCES tests/test_cfg.cpp LIBS engine_translator)

# Local only: the whole DOL's CFG (item 5 exit). Skipped (77) without the disc.
add_executable(local_cfg tests/local_cfg.cpp)
target_link_libraries(local_cfg PRIVATE engine_translator)
target_compile_options(local_cfg PRIVATE ${ENGINE_WARN})
add_test(NAME local_cfg COMMAND local_cfg)
set_tests_properties(local_cfg PROPERTIES SKIP_RETURN_CODE 77 LABELS local)
