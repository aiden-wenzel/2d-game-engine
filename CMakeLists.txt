if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(CMAKE_C_COMPILER "clang")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}	-Wall -Wextra -Werror -g -fsanitize=address -pedantic")

elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")

endif()

cmake_minimum_required(VERSION 3.22)
project(Pong)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(main "src/main.c")
target_link_libraries(main ${SDL2_LIBRARIES})
