//
// Created by 李研 on 2019/7/13.
//

#include "ShortestPath.h"


// 因为 C++ 提供的优先级队列，没有暴露更新数据的接口，所以我们需要重新实现一个
class PriorityQueue { // 根据 vertex.dist 构建小顶堆
private:
    List<Vertex> nodes;
    int count;

public:
    PriorityQueue(int c) : count(c) { nodes.resize(c);}

    Vertex poll() {

    }

    void add(Vertex vertex) {

    }
    // 更新结点的值，并且从下往上堆化，重新符合堆的定义。时间复杂度 O(logn)。
    void update(Vertex vertex) {

    }
    bool isEmpty() {

    }
};

void Graph::dijkstraWithCusQueue(int s, int t) {  // 从顶点 s 到顶点 t 的最短路径
    List<int> predecessor(v);  // 用来还原最短路径
    List<Vertex> vertexes(v);  // 记录任意顶点到起点的最短距离
    for (int i = 0; i < v; ++i) {
        vertexes[i].id = i;
        vertexes[i].dist = INF;
    }
    PriorityQueue queue(v); // 小顶堆
    List<bool> inqueue(v, false); // 标记是否进入过队列
    vertexes[s].dist = 0;
    queue.add(vertexes[s]);
    inqueue[s] = true;
    while (!queue.isEmpty()) {
        Vertex minVertex= queue.poll();   // 取堆顶元素并删除
        if (minVertex.id == t) { break; } // 最短路径产生了
        for (int i = 0; i < adj[minVertex.id].size(); ++i) {
            Edge e = adj[minVertex.id][i];        // 取出一条 minVetex 相连的边
            Vertex &nextVertex = vertexes[e.tid]; // minVertex-->nextVertex
            if (minVertex.dist + e.w < nextVertex.dist) {  // 更新 next 的 dist
                nextVertex.dist = minVertex.dist + e.w;
                predecessor[nextVertex.id] = minVertex.id; // 记录前驱顶点
                if (inqueue[nextVertex.id]) {
                    queue.update(nextVertex); // 更新队列中的 dist 值
                }
                else {
                    queue.add(nextVertex);
                    inqueue[nextVertex.id] = true;
                }
            }
        }
    }
    // 输出最短路径
    printPath(s, t, predecessor);
    // 输出最短路径长度
    printDistance(s, t, vertexes);
}
