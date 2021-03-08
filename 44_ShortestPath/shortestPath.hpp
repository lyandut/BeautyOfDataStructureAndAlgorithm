//
// Created by 李研 on 2019/7/13.
//

#ifndef BEAUTYOFDATASTRUCTUREANDALGORITHM_SHORTESTPATH_HPP
#define BEAUTYOFDATASTRUCTUREANDALGORITHM_SHORTESTPATH_HPP

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>

// 下面这个类是为了 dijkstra 实现用的
struct Vertex {
    int id;   // 顶点编号 ID
    int dist; // 从起始顶点到这个顶点的距离

    Vertex() : id(-1), dist(INF) {}

    Vertex(int id, int dist) : id(id), dist(dist) {}

    bool operator<(const Vertex &v) const { return dist > v.dist; } // 使得STL默认priority_queue是小顶堆
};

struct Edge {
    int sid; // 边的起始顶点编号
    int tid; // 边的终止顶点编号
    int w;   // 权重

    Edge(int sid, int tid, int w) : sid(sid), tid(tid), w(w) {}
};

using AdjList = std::vector<std::vector<Edge>>;

// 有向有权图的邻接表表示
class Graph {
public:
    Graph(int v) : v(v) {
        adj.resize(v);
        for (int i = 0; i < v; ++i) { adj[i].reserve(v); }
    }

    // 添加一条边
    void addEdge(int s, int t, int w) { adj[s].emplace_back(s, t, w); }

    void dijkstraWithSTLQueue(int s, int t);

    void dijkstraWithCusQueue(int s, int t);

    void printPath(int s, int t, std::vector<int> &predecessor) {
        if (s == t) {
            std::cout << s;
            return;
        }
        printPath(s, predecessor[t], predecessor);
        std::cout << "->" << t;
    }

    void printDistance(int s, int t, std::vector<Vertex> &vertexes) {
        std::cout << std::endl
                  << s << "->" << t << ": " << vertexes[t].dist
                  << std::endl;
    }

private:
    AdjList adj; // 邻接表
    int v;       // 顶点个数
};

#endif //BEAUTYOFDATASTRUCTUREANDALGORITHM_SHORTESTPATH_HPP
