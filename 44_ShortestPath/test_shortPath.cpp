//
// Created by liyan on 2019/12/8.
//

#include "../tester.h"
#include "shortestPath.hpp"

void Tester::testShortestPath(){
    cout << "==== testShortestPath ====" << endl;

    Graph myGraph(6);
    myGraph.addEdge(0, 1, 10);
    myGraph.addEdge(0, 4, 15);
    myGraph.addEdge(1, 2, 15);
    myGraph.addEdge(1, 3, 2);
    myGraph.addEdge(2, 5, 5);
    myGraph.addEdge(3, 2, 1);
    myGraph.addEdge(3, 5, 12);
    myGraph.addEdge(4, 5, 10);

    myGraph.dijkstraWithSTLQueue(0, 5);
    myGraph.dijkstraWithCusQueue(0, 5);
}