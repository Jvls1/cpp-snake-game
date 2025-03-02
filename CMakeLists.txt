cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SRC_FILES
    src/main.cpp
    src/game.cpp
    src/snake.cpp
    src/food.cpp
)

add_executable(SnakeGame ${SRC_FILES})

target_link_libraries(SnakeGame ncurses)
