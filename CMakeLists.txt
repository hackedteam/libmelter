cmake_minimum_required (VERSION 2.6)
cmake_policy(SET CMP0015 NEW)

set (melter_VERSION_MAJOR 0)
set (melter_VERSION_MINOR 1)

if(DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of build, options are: Debug Release")
else()
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build, options are: Debug Release")
endif()

project(libmelter CXX)

message("-- Building pemelter (${CMAKE_BUILD_TYPE}), version ${melter_VERSION_MAJOR}.${melter_VERSION_MINOR}")

configure_file (
    "${PROJECT_SOURCE_DIR}/version.h.in"
    "${PROJECT_BINARY_DIR}/version.h"
)

include_directories("${PROJECT_BINARY_DIR}")

option(WITH_TESTS "Build unit tests" ON)
if (WITH_TESTS)
    message("-- Unit tests will be built (use make test to execute).")
    add_subdirectory(tests)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g -O2 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set (melter_SOURCES BufferObserver.cc Chunk.cc IOAppend.cc IOBuffer.cc IOComplete.cc IOFlush.cc IOManager.cc IOOperation.cc Mangler.cc Melter.cc main.cc)
add_library(melter ${melter_SOURCES})
