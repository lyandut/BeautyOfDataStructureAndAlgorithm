#include <iostream>
#include "44_ShortestPath/ShortestPath.h"

using namespace std;

void testShortestPath(){
    Graph myGraph(6);
    myGraph.addEdge(0, 1, 10);
    myGraph.addEdge(0, 4, 15);
    myGraph.addEdge(1, 2, 15);
    myGraph.addEdge(1, 3, 2);
    myGraph.addEdge(2, 5, 5);
    myGraph.addEdge(3, 2, 1);
    myGraph.addEdge(3, 5, 12);
    myGraph.addEdge(4, 5, 10);

    myGraph.dijkstra(0, 5);
}


int main() {
    cout << "Hello, Beauty of Data Structure and Algorithm!" << std::endl;

    testShortestPath();

    return 0;
}