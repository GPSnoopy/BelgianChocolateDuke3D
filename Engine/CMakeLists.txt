
set(project_name "Engine")

add_definitions(-DUDP_NETWORKING)

set(src_files
	src/build.h
	src/cache.c
	src/cache.h
	src/display.c
	src/display.h
	src/draw.c
	src/draw.h
	src/dummy_multi.c
	src/engine.c
	src/engine.h
	src/filesystem.c
	src/filesystem.h
	src/fixedPoint_math.c
	src/fixedPoint_math.h
	src/icon.h
	src/macos_compat.h
	src/mmulti.c
	src/mmulti_stable.cpp
	src/mmulti_stable.h
	src/mmulti_unstable.h
	src/network.c
	src/network.h
	src/platform.h
	src/sdl_util.h
	src/tiles.c
	src/tiles.h
	src/unix_compat.h
	src/win32_compat.h
)

include_directories(${SDL2_INCLUDE_DIR})
add_library(${project_name} STATIC ${src_files})
#set_target_properties(${project_name} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
set_target_properties(${project_name} PROPERTIES OUTPUT_NAME "Engine${project_suffix}")
