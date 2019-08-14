cmake_minimum_required(VERSION 3.13.3)
project(WORA)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/target/)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/target/)

add_subdirectory(src)
# add_subdirectory(test)
