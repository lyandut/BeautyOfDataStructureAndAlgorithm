cmake_minimum_required(VERSION 3.14)
project(BeautyOfDataStructureAndAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(BeautyOfDataStructureAndAlgorithm
        main.cpp tester.h
        05_Array/Array.cpp 05_Array/Array.h
        06_LinkedList/LinkedList.cpp 06_LinkedList/LinkedList.h
        15_BinarySearch/binarySearch.hpp 15_BinarySearch/test_binarySearch.cpp
        16_BinarySearch/binarySearch2.hpp 16_BinarySearch/test_binarySearch2.cpp
        44_ShortestPath/shortestPath.hpp 44_ShortestPath/dijkstraWithSTLQueue.cpp 44_ShortestPath/dijkstraWithCusQueue.cpp 44_ShortestPath/test_shortPath.cpp
        )