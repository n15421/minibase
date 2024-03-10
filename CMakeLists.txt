cmake_minimum_required(VERSION 3.21)

project(lightbase)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB_RECURSE SRC_FILES_DIR
    ${PROJECT_SOURCE_DIR}/src/*.c
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

set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /NODEFAULTLIB:MSVCRTD")

set_target_properties(lightbase PROPERTIES OUTPUT_NAME "lightbase")

target_link_libraries(lightbase 
	"${CMAKE_SOURCE_DIR}/lib/minhook.x64.lib"
)
