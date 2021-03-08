//
// Created by liyan on 2021/3/8.
//

#ifndef BEAUTYOFDATASTRUCTUREANDALGORITHM_TEST_ASTARSEARCH_CPP
#define BEAUTYOFDATASTRUCTUREANDALGORITHM_TEST_ASTARSEARCH_CPP

#include "../tester.h"
#include "astarSearch.hpp"

void Tester::testAStarSearch() {
    cout << "==== testAStarSearch ====" << endl;

    astar::Graph myGraph(11);
    myGraph.addVertex(0, 320, 630);
    myGraph.addVertex(1, 300, 630);
    myGraph.addVertex(2, 280, 625);
    myGraph.addVertex(3, 270, 630);
    myGraph.addVertex(4, 320, 700);
    myGraph.addVertex(5, 360, 620);
    myGraph.addVertex(6, 320, 590);
    myGraph.addVertex(7, 370, 580);
    myGraph.addVertex(8, 350, 730);
    myGraph.addVertex(9, 390, 690);
    myGraph.addVertex(10, 400, 620);

    myGraph.addEdge(0, 1, 20);
    myGraph.addEdge(0, 4, 60);
    myGraph.addEdge(0, 5, 60);
    myGraph.addEdge(0, 6, 60);
    myGraph.addEdge(1, 2, 20);
    myGraph.addEdge(2, 3, 10);
    myGraph.addEdge(4, 8, 50);
    myGraph.addEdge(5, 8, 70);
    myGraph.addEdge(5, 9, 80);
    myGraph.addEdge(5, 10, 50);
    myGraph.addEdge(6, 7, 70);
    myGraph.addEdge(8, 9, 50);
    myGraph.addEdge(9, 10, 60);

    myGraph.astar(0, 10);
}


#endif //BEAUTYOFDATASTRUCTUREANDALGORITHM_TEST_ASTARSEARCH_CPP
