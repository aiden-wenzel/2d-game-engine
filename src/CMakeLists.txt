set(CMAKE_BUILD_TYPE Debug)
add_executable(main main.c game_object.c circle.c)
target_link_libraries(main PRIVATE SDL3::SDL3 m)
