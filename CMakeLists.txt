# libgc-nx: the GameCube's own hardware.
#
# This is not built on its own. Its modules answer a game's SDK calls, which
# means they are compiled into the runtime beside libdol-nx's own - see
# cmake/Sources.cmake, which a runtime build includes.
cmake_minimum_required(VERSION 3.20)
project(libgc-nx LANGUAGES CXX VERSION 2.0.0)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Sources.cmake")
list(LENGTH WIINX_GC_SOURCES wiinx_gc_count)

if(PROJECT_IS_TOP_LEVEL)
    message(STATUS "libgc-nx: ${wiinx_gc_count} source files, built by a runtime build.")
    message(STATUS "  Point a build at this with -DWIINX_GC_DIR=${CMAKE_CURRENT_SOURCE_DIR}")
endif()
