//
// Created by 李研 on 2019/7/13.
//

#include "shortestPath.hpp"
#include <queue>

template<typename T>
using PriorityQueue = std::priority_queue<T>;

void Graph::dijkstraWithSTLQueue(int s, int t) {  // 从顶点 s 到顶点 t 的最短路径
    std::vector<int> predecessor(v); // 用来还原最短路径
    std::vector<Vertex> vertexes(v); // 记录任意顶点到起点的最短距离
    for (int i = 0; i < v; ++i) {
        vertexes[i].id = i;
        vertexes[i].dist = INF;
    }
    vertexes[s].dist = 0;
    PriorityQueue<Vertex> queue; // STL 默认是大顶堆，通过重载 Vertex 的 operator<() 变为小顶堆。
    queue.push(vertexes[s]);

    while (!queue.empty()) {
        Vertex minVertex = queue.top();
        queue.pop();
        if (minVertex.id == t) { break; } // 最短路径产生了
        for (auto &e : adj[minVertex.id]) {
            Vertex &nextVertex = vertexes[e.tid]; // minVertex-->nextVertex, 注意取引用
            if (minVertex.dist + e.w < nextVertex.dist) {  // 更新 next 的 dist
                nextVertex.dist = minVertex.dist + e.w;
                predecessor[nextVertex.id] = minVertex.id; // 记录前驱顶点
                queue.push(nextVertex);
            }
        }
    }
    // 输出最短路径
    printPath(s, t, predecessor);
    // 输出最短路径长度
    printDistance(s, t, vertexes);
}
