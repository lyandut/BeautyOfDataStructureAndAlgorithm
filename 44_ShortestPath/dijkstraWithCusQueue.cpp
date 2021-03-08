//
// Created by 李研 on 2019/7/13.
//

#include "shortestPath.hpp"


// 因为 C++ 提供的优先级队列，没有暴露更新数据的接口，所以我们需要重新实现一个。
// 根据 vertex.dist 构建小顶堆
class PriorityQueue {
public:
    PriorityQueue(int c) : capacity(c), count(0) { nodes.resize(capacity + 1); } // 从下标1开始存储

    // 从上往下堆化, 大的下沉
    Vertex poll() {
        if (count == 0) return {};
        Vertex top = nodes[1];
        nodes[1] = nodes[count];
        --count;
        int i = 1;
        while (true) {
            int min_pos = i;
            if (i * 2 <= count && nodes[i * 2].dist < nodes[min_pos].dist) min_pos = i * 2;
            if (i * 2 + 1 <= count && nodes[i * 2 + 1].dist < nodes[min_pos].dist) min_pos = i * 2 + 1;
            if (i == min_pos) break;
            std::swap(nodes[i], nodes[min_pos]);
            i = min_pos; // 下沉到孩子节点
        }
        return top;
    }

    // 从下往上堆化，小的提升
    void add(Vertex &data) {
        if (count >= capacity) return;
        ++count;
        nodes[count] = data;
        int i = count;
        while (i / 2 > 0 && nodes[i].dist < nodes[i / 2].dist) {
            std::swap(nodes[i], nodes[i / 2]);
            i /= 2; // 上升到父节点
        }
    }

    // 更新结点的值，并且从下往上堆化，重新符合堆的定义。时间复杂度 O(logn)。
    void update(Vertex &data) {
        int i = 1;
        for (; i <= count; ++i) {
            if (nodes[i].id == data.id && nodes[i].dist > data.dist) {
                nodes[i].dist = data.dist;
                break;
            }
        }
        while (i / 2 > 0 && nodes[i].dist < nodes[i / 2].dist) {
            std::swap(nodes[i], nodes[i / 2]);
            i /= 2;
        }
    }

    bool isEmpty() const { return count == 0; }

private:
    std::vector<Vertex> nodes;
    int capacity; // 最大容量
    int count; // 已存容量
};

void Graph::dijkstraWithCusQueue(int s, int t) {  // 从顶点 s 到顶点 t 的最短路径
    std::vector<int> predecessor(v);  // 用来还原最短路径

    // 初始化①：vertexes
    std::vector<Vertex> vertexes(v);  // 记录任意顶点到起点的最短距离
    for (int i = 0; i < v; ++i) {
        vertexes[i].id = i;
        vertexes[i].dist = INF;
    }
    vertexes[s].dist = 0;
    // 初始化②：queue
    PriorityQueue queue(v);
    queue.add(vertexes[s]);
    // 初始化③：visited
    std::vector<bool> visited(v, false);
    visited[s] = true;

    while (!queue.isEmpty()) {
        Vertex minVertex = queue.poll();
        if (minVertex.id == t) { break; } // 最短路径产生了
        for (auto &e : adj[minVertex.id]) {
            Vertex &nextVertex = vertexes[e.tid]; // minVertex-->nextVertex
            if (minVertex.dist + e.w < nextVertex.dist) {  // 更新 next 的 dist
                nextVertex.dist = minVertex.dist + e.w;
                predecessor[nextVertex.id] = minVertex.id; // 记录前驱顶点
                if (visited[nextVertex.id]) {
                    queue.update(nextVertex); // 元素已在队列中，更新 dist 值
                } else {
                    queue.add(nextVertex);
                    visited[nextVertex.id] = true;
                }
            }
        }
    }
    // 输出最短路径
    printPath(s, t, predecessor);
    // 输出最短路径长度
    printDistance(s, t, vertexes);
}
