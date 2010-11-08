cmake_minimum_required (VERSION 2.6)

if(DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of build, options are: Debug Release")
else()
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build, options are: Debug Release")
endif()

project(libmelter CXX)

option(WITH_TESTS "Build unit tests" ON)
if (WITH_TESTS)
    add_subdirectory(tests)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g -O2 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

message("-- Building ${CMAKE_BUILD_TYPE} version.")

set (melter_SOURCES BufferObserver.cc Chunk.cc IOAppend.cc IOBuffer.cc IOComplete.cc IOFlush.cc IOManager.cc IOOperation.cc Mangler.cc Melter.cc main.cc)
add_library(melter ${melter_SOURCES})
