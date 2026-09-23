# The GameCube's own modules, for a runtime build to compile alongside
# libdol-nx.
#
# These are not a library of their own: they answer a game's SDK calls, and that
# means they use the runtime's memory, its logging and its HLE contracts. A
# build includes this file, adds WIINX_GC_SOURCES to the runtime's sources, and
# puts WIINX_GC_INCLUDE_DIRS on the include path.
#
# libdol-nx's own runtime build does exactly that when it finds this repository
# beside it.
set(WIINX_GC_ROOT "${CMAKE_CURRENT_LIST_DIR}/..")

file(GLOB_RECURSE WIINX_GC_SOURCES CONFIGURE_DEPENDS
    "${WIINX_GC_ROOT}/src/*.cpp")

set(WIINX_GC_INCLUDE_DIRS
    "${WIINX_GC_ROOT}/include"
    "${WIINX_GC_ROOT}/src/aram"
    "${WIINX_GC_ROOT}/src/card"
    "${WIINX_GC_ROOT}/src/dtk"
    "${WIINX_GC_ROOT}/src/boot")
