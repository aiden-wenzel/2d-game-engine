add_executable(main main.c circle.c)
target_link_libraries(main SDL3::SDL3)

add_executable(test test.c)
target_link_libraries(test SDL3::SDL3)
