//
// Created by 李研 on 2019/7/13.
//

#include "ShortestPath.h"
#include <queue>

template <typename T>
using PriorityQueue = std::priority_queue<T>;

void Graph::dijkstra(int s, int t) {  // 从顶点 s 到顶点 t 的最短路径
    List<int> predecessor(v); // 用来还原最短路径
    List<Vertex> vertexes(v); // 记录任意顶点到起点的最短距离
    for (int i = 0; i < v; ++i) {
        vertexes[i].id = i;
        vertexes[i].dist = INF;
    }
    PriorityQueue<Vertex> queue; // 小顶堆
    vertexes[s].dist = 0;
    queue.push(vertexes[s]);
    while (!queue.empty()) {
        Vertex minVertex= queue.top(); queue.pop(); // 取堆顶元素并删除
        if (minVertex.id == t) { break; }           // 最短路径产生了
        for (int i = 0; i < adj[minVertex.id].size(); ++i) {
            Edge e = adj[minVertex.id][i];        // 取出一条 minVetex 相连的边
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
