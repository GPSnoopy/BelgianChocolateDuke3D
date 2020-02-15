cmake_minimum_required(VERSION 3.10)

project(BelgianChocolateDuke3D)

# Output everything into bin/ and lib/
set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# Ignore the Configuration sub-directory on Visual Studio.
foreach (OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/lib)
endforeach()

# CMake extensions
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

if (WIN32)

	add_definitions(-DWIN32_LEAN_AND_MEAN)
	add_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE)
	
	# Statically link against the multithreaded runtime.
	foreach (flag_var CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
		if (${flag_var} MATCHES "/MD")
			string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
		endif()
	endforeach()
	
	# Compile files in parallel
	add_compile_options("/MP")
	
endif()

if (UNIX)
		
	add_definitions(-DUNIX)
	add_compile_options("-Wall")

endif ()

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(project_suffix ".64")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(project_suffix ".32")
endif()

find_package(ENet REQUIRED)
find_path(SDL2_INCLUDE_DIR SDL2/SDL.h)
find_package(SDL2 CONFIG REQUIRED) 
find_package(SDL2-mixer CONFIG REQUIRED)

add_subdirectory(Engine)
add_subdirectory(Game)
set_property (DIRECTORY PROPERTY VS_STARTUP_PROJECT Game)
