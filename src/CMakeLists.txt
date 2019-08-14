cmake_minimum_required(VERSION 3.13.3)
project(WORA)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(src_include ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${src_include})

add_subdirectory(core)
add_subdirectory(node)
# add_subdirectory(server)
# add_subdirectory(client)
