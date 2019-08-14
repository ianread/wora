cmake_minimum_required(VERSION 3.13.3)
project(WORA)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(wora
  calculator.cc
)
