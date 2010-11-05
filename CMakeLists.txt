cmake_minimum_required (VERSION 2.6)
project(libmelter)

add_library(melter BufferObserver.cc Chunk.cc IOAppend.cc IOBuffer.cc IOComplete.cc IOFlush.cc IOManager.cc IOOperation.cc Mangler.cc Melter.cc main.cc)
