cmake_minimum_required(VERSION 3.14)
project(BeautyOfDataStructureAndAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(BeautyOfDataStructureAndAlgorithm
        main.cpp
        05_Array/Array.cpp 05_Array/Array.h
        06_LinkedList/LinkedList.cpp 06_LinkedList/LinkedList.h
        44_ShortestPath/ShortestPath.h 44_ShortestPath/dijkstraWithSTLQueue.cpp 44_ShortestPath/dijkstraWithCusQueue.cpp
        )