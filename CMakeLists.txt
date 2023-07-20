cmake_minimum_required(VERSION 3.15)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp board.cpp player.cpp player.h ship.cpp game.cpp game.h inputValidation.cpp inputValidation.h helper.h helper.cpp)
