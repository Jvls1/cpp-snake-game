cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC_FILES "src/*.cpp")

add_executable(SnakeGame ${SRC_FILES})

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  include(${CMAKE_SOURCE_DIR}/cmake/toolchain-windows.cmake)
  target_link_libraries(SnakeGame -static -lpdcurses)
else()
  include(${CMAKE_SOURCE_DIR}/cmake/toolchain-linux.cmake)
endif()
