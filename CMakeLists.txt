cmake_minimum_required (VERSION 2.6)
project(libmelter)

set (CMAKE_BUILD_TYPE Debug)
set (melter_SOURCES BufferObserver.cc Chunk.cc IOAppend.cc IOBuffer.cc IOComplete.cc IOFlush.cc IOManager.cc IOOperation.cc Mangler.cc Melter.cc main.cc)

add_subdirectory(tests)
add_library(melter ${melter_SOURCES})
enable_testing()
