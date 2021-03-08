//
// Created by liyan on 2021/3/8.
//

#ifndef BEAUTYOFDATASTRUCTUREANDALGORITHM_ASTARSEARCH_HPP
#define BEAUTYOFDATASTRUCTUREANDALGORITHM_ASTARSEARCH_HPP

#define INF 0x3f3f3f3f

#include <iostream>
#include <vector>
#include <queue>

template<typename T>
using PriorityQueue = std::priority_queue<T>;

namespace astar {

    struct Vertex {
        int id;
        int dist;
        int f; // f(i)=g(i)+h(i)
        int x, y; // 坐标

        Vertex(int id, int x, int y) : id(id), x(x), y(y), dist(INF), f(INF) {}

        bool operator<(const Vertex &rhs) const { return f > rhs.f; }
    };

    int hManhattan(Vertex &v1, Vertex &v2) { return abs(v1.x - v2.x) + abs(v1.y - v2.y); }

    struct Edge {
        int sid;
        int tid;
        int w;

        Edge(int s, int t, int w) : sid(s), tid(t), w(w) {}
    };

    using AdjList = std::vector<std::vector<Edge>>;

    class Graph {
    public:
        Graph(int v) : v(v), adj(v) { vertexes.reserve(v); }

        void addVertex(int id, int x, int y) { vertexes.emplace_back(id, x, y); }

        void addEdge(int s, int t, int w) { adj[s].emplace_back(s, t, w); }

        void astar(int s, int t) {
            std::vector<int> predecessor(v);
            // 初始化
            vertexes[s].dist = 0;
            vertexes[s].f = 0;
            PriorityQueue<Vertex> q;
            q.push(vertexes[s]);

            while (!q.empty()) {
                Vertex curr = q.top();
                q.pop();
                for (auto &e : adj[curr.id]) {
                    Vertex &next = vertexes[e.tid]; // 注意：这里一定是引用
                    if (curr.dist + e.w < next.dist) { // 只需要考虑dist即可，hManhattan不会变
                        next.dist = curr.dist + e.w;
                        next.f = next.dist + hManhattan(next, vertexes[t]);
                        predecessor[next.id] = curr.id; // curr --> next
                        q.push(next);
                    }
                    if (next.id == t) {
                        while (!q.empty()) q.pop(); // 清空q才能跳出while循环
                        break;
                    }
                }
            }

            printPath(s, t, predecessor);
            printDistance(s, t);
        }

        void printPath(int s, int t, std::vector<int> &predecessor) {
            if (s == t) {
                cout << s;
                return;
            }
            printPath(s, predecessor[t], predecessor);
            std::cout << "->" << t;
        }

        void printDistance(int s, int t) {
            std::cout << std::endl
                      << s << "->" << t << ": " << vertexes[t].dist
                      << std::endl;
        }

    private:
        int v;
        std::vector<Vertex> vertexes;
        AdjList adj;
    };

};

#endif //BEAUTYOFDATASTRUCTUREANDALGORITHM_ASTARSEARCH_HPP
