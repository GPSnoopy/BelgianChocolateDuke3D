
set(project_name "Game")
set(exe_name "ChocoDuke3D${project_suffix}")

add_definitions(-DCHECK_XDUKE_REV)

set(src_files_audiolib_headers
	src/audiolib/_multivc.h
	src/audiolib/dpmi.h
	src/audiolib/dsl.h
	src/audiolib/fx_man.h
	src/audiolib/linklist.h
	src/audiolib/ll_man.h
	src/audiolib/multivoc.h
	src/audiolib/music.h
	src/audiolib/pitch.h
	src/audiolib/sndcards.h
	src/audiolib/usrhooks.h
	src/audiolib/util.h
)

set(src_files_audiolib
	src/audiolib/dpmi.c
	src/audiolib/dsl.c
	src/audiolib/fx_man.c
	src/audiolib/ll_man.c
	src/audiolib/multivoc.c
	src/audiolib/mv_mix.c
	src/audiolib/mvreverb.c
	src/audiolib/pitch.c
	# TODO source contains loads of files that are not used (only DOS). Delete them?
)

set(src_files_console_headers
	src/_functio.h
	src/console.h
	src/cvar_defs.h
	src/cvars.h
)

set(src_files_console
	src/console.c
	src/cvar_defs.c
	src/cvars.c
)

set(src_files_midi
	src/midi/sdl_midi.c
)

set(src_files_headers
	src/_rts.h
	src/animlib.h
	src/config.h
	src/control.h
	src/develop.h
	src/duke3d.h
	src/dukeunix.h
	src/dukewin.h
	src/file_lib.h
	src/funct.h
	src/function.h
	src/game.h
	src/gamedefs.h
	src/global.h
	src/joystick.h
	src/keyboard.h
	src/mouse.h
	src/names.h
	src/premap.h
	src/rts.h
	src/scriplib.h
	src/sounddebugdefs.h
	src/soundefs.h
	src/sounds.h
	src/types.h
	src/util_lib.h
)

set(src_files
	src/actors.c
	src/animlib.c
	src/config.c
	src/control.c
	src/game.c
	src/gamedef.c
	src/global.c
	src/keyboard.c
	src/menues.c
	src/player.c
	src/premap.c
	src/rts.c
	src/scriplib.c
	src/sector.c
	src/sounds.c
)

if (WIN32)
	set (resource_files chocolateDukeResources.rc)
	set (socket_library ws2_32.lib)
endif()

source_group("AudioLib Header Files" FILES ${src_files_audiolib_headers})
source_group("AudioLib Source Files" FILES ${src_files_audiolib})
source_group("Console Header Files" FILES ${src_files_console_headers})
source_group("Console Source Files" FILES ${src_files_console})
source_group("Main Header Files" FILES ${src_files_headers})
source_group("Main Source Files" FILES ${src_files})
source_group("Midi Source Files" FILES ${src_files_midi})
source_group("Resources" FILES ${resource_files})

include_directories(../Engine/src)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(${project_name} 
	${src_files_audiolib_headers}
	${src_files_audiolib}
	${src_files_console_headers} 
	${src_files_console} 
	${src_files_midi} 
	${src_files_headers} 
	${src_files}
	${resource_files}
)

target_link_libraries(${project_name} PRIVATE Engine ${socket_library})
set_target_properties(${project_name} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
set_target_properties(${project_name} PROPERTIES OUTPUT_NAME "ChocoDuke3D${project_suffix}")
set_target_properties(${project_name} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
