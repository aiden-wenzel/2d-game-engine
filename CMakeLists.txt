cmake_minimum_required(VERSION 3.10)
project(SimpleSDL2Window C)

find_package(SDL3 REQUIRED)
find_package(cglm REQUIRED)

add_subdirectory(src)
