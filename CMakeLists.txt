cmake_minimum_required(VERSION 3.21)

project(lightbase)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB_RECURSE SRC_FILES_DIR
    ${PROJECT_SOURCE_DIR}/src/file_utils.c
    ${PROJECT_SOURCE_DIR}/src/hashmap.c
    ${PROJECT_SOURCE_DIR}/src/lightbase.c
    ${PROJECT_SOURCE_DIR}/src/loader.c
)

file(GLOB_RECURSE HIJACK_SRC_FILES_DIR
    ${PROJECT_SOURCE_DIR}/src/hijack/hijack.c
)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

link_directories(
    ${CMAKE_SOURCE_DIR}/lib
)

add_definitions(
    -D"_CRT_SECURE_NO_WARNINGS"
    -DWIN32_LEAN_AND_MEAN
    -D"LIGHTBASE_EXPORTS"
)

add_compile_options(
    /diagnostics:column
    /FC
    /GL
    /nologo
    /permissive-
    /sdl
    /utf-8
    /Zi
)

add_link_options(
    /LTCG
    /INCREMENTAL:NO
)

add_library(lightbase SHARED ${SRC_FILES_DIR})

add_library(hijack SHARED ${HIJACK_SRC_FILES_DIR})

set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /NODEFAULTLIB:MSVCRTD")

set_target_properties(lightbase PROPERTIES OUTPUT_NAME "lightbase")

set_target_properties(hijack PROPERTIES OUTPUT_NAME "winhttp")

target_link_libraries(lightbase 
	"${CMAKE_SOURCE_DIR}/lib/minhook.x64.lib"
)

target_link_libraries(hijack
	debug "MSVCRTD.lib"
    optimized "MSVCRT.lib"
)
