cmake_minimum_required(VERSION 3.21)

project(lightbase)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

# ------------------------------------------------
# ------------------------------------------------
# ------------------------------------------------
# ------------------------------------------------
# ------------------------------------------------

# lightbase linux
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(dep/funchook)

include_directories(include)

set(LIGHTBASE_SOURCE src/linux/lightbase.c src/linux/hook.c src/linux/symbol.c src/linux/cache.c)

add_library(lightbase SHARED ${LIGHTBASE_SOURCE})

target_link_libraries(lightbase funchook-static dl)
# target_compile_definitions(lightbase PRIVATE)
# target_include_directories(lightbase PUBLIC include)

ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

# ------------------------------------------------
# ------------------------------------------------
# ------------------------------------------------
# ------------------------------------------------
# ------------------------------------------------

# lightbase windows
IF (CMAKE_SYSTEM_NAME MATCHES "Windows")

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

set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /NODEFAULTLIB:MSVCRTD")

# lightbase main
file(GLOB_RECURSE SRC_FILES_DIR
    ${PROJECT_SOURCE_DIR}/src/win/file_utils.c
    ${PROJECT_SOURCE_DIR}/src/win/hashmap.c
    ${PROJECT_SOURCE_DIR}/src/win/lightbase.c
    ${PROJECT_SOURCE_DIR}/src/win/loader.c
)

add_library(lightbase SHARED ${SRC_FILES_DIR})

set_target_properties(lightbase PROPERTIES OUTPUT_NAME "lightbase")



# hijack for win
file(GLOB_RECURSE HIJACK_SRC_FILES_DIR
    ${PROJECT_SOURCE_DIR}/src/win/hijack/hijack.c
)

add_library(hijack SHARED ${HIJACK_SRC_FILES_DIR})

set_target_properties(hijack PROPERTIES OUTPUT_NAME "winhttp")

target_link_libraries(lightbase 
	"${CMAKE_SOURCE_DIR}/lib/minhook.x64.lib"
)

target_link_libraries(hijack
	debug "MSVCRTD.lib"
    optimized "MSVCRT.lib"
)

ENDIF (CMAKE_SYSTEM_NAME MATCHES "Windows")