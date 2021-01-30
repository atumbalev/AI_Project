cmake_minimum_required(VERSION 3.17)
project(NPuzzleGenetic)

set(CMAKE_CXX_STANDARD 20)

add_executable(NPuzzleGenetic
        Board.h Board.cpp
        Population.h Population.cpp
        Solution.h Solution.cpp
        Chromosome.h Chromosome.cpp
        main.cpp)