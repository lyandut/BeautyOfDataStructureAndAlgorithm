//
// Created by 李研 on 2019/7/13.
//

#ifndef BEAUTYOFDATASTRUCTUREANDALGORITHM_SHORTESTPATH_H
#define BEAUTYOFDATASTRUCTUREANDALGORITHM_SHORTESTPATH_H

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>

template<typename T>
using List = std::vector<T>;

// 下面这个类是为了 dijkstra 实现用的
class Vertex {
public:
    int id;   // 顶点编号 ID
    int dist; // 从起始顶点到这个顶点的距离
    Vertex() { }
    Vertex(int id, int dist) : id(id), dist(dist) { }
    bool operator < (const Vertex &v) const { return dist > v.dist; }
};

class Edge {
public:
    int sid; // 边的起始顶点编号
    int tid; // 边的终止顶点编号
    int w;   // 权重
    Edge(int sid, int tid, int w) : sid(sid), tid(tid), w(w) { }
};

using AdjList = List<List<Edge>>;

class Graph { // 有向有权图的邻接表表示
private:
    AdjList adj; // 邻接表
    int v;       // 顶点个数

public:
    Graph(int v) : v(v) {
        adj.resize(v);
        for (int i = 0; i < v; ++i) { adj[i].reserve(v); }
    }

    void addEdge(int s, int t, int w) { // 添加一条边
        adj[s].emplace_back(s, t, w);
    }

    void dijkstra(int s, int t);
    void dijkstraWithCusQueue(int s, int t);

    void printPath(int s, int t, List<int> &predecessor) {
        if (s == t) { return; }
        printPath(s, predecessor[t], predecessor);
        std::cout << "->" << t;
    }

    void printDistance(int s, int t, List<Vertex> &vertexes){
        std::cout << std::endl
                  << s << "->" << t << ": " << vertexes[t].dist
                  << std::endl;
    }

};

#endif //BEAUTYOFDATASTRUCTUREANDALGORITHM_SHORTESTPATH_H
