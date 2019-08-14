cmake_minimum_required(VERSION 3.13.3)
project(WORA)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_custom_target(node_wora ALL
  COMMAND cp -a ${CMAKE_CURRENT_SOURCE_DIR}/. ${CMAKE_CURRENT_BINARY_DIR}
  VERBATIM
)

set(node_include ${CMAKE_CURRENT_SOURCE_DIR}/node_modules/node-addon-api)
include_directories(${node_include})

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
  set(DEBUG_FLAG "--debug")
else()
  set(DEBUG_FLAG "")
endif()

add_custom_command(
  TARGET node_wora POST_BUILD
  COMMAND export SRC_INCLUDES=${src_include} 
       && export NODE_INCLUDES=${node_include}
       && export TARGET_PATH=${LIBRARY_OUTPUT_PATH}
       && npm install
  VERBATIM
)
