cmake_minimum_required(VERSION 3.10)
project(SimpleSDL2Window C)

include(FetchContent)

FetchContent_Declare(
	sdl
	GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
	GIT_TAG e6bb50a710785299faa7b72c7b52f18acb5aa77b
)

set(SDL_STATIC ON CACHE BOOL "Build SDL3 as a static library")

FetchContent_Declare(
	cglm
	GIT_REPOSITORY https://github.com/recp/cglm
	GIT_TAG 9b678661540e42c38493e276e07b7be76f0cc356
)

FetchContent_MakeAvailable(sdl)
FetchContent_MakeAvailable(cglm)

# include_directories("./lib/cglm/include/cglm" "./lib/sdl/include/SDL3")
#
# add_subdirectory("lib/cglm")
# add_subdirectory("lib/sdl")

add_subdirectory(src)
