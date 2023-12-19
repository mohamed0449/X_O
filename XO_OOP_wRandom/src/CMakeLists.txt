cmake_minimum_required(VERSION 3.25)
project(src)

set(CMAKE_CXX_STANDARD 14)

add_executable(src
        GameManager.cpp
        Player.cpp
        Pyramic_X_O_Board.cpp
        RandomPlayer.cpp
        X_O_App.cpp
        X_O_Board.cpp ../include/BoardGame_Classes.hpp ../include/BoardGame_Classes.hpp ../include/BoardGame_Classes.hpp ../include/BoardGame_Classes.hpp ../include/BoardGame_Classes.hpp X_O_5x5.cpp "PyramidTicTacToe .cpp")
