//souldaher210@gmail.com
#include "Algorithms.hpp"

namespace graph {

    // Queue Implementation
    class Queue {
    private:
        int data[100];
        int front, rear;
    public:
        Queue() : front(0), rear(0) {}
        void enqueue(int x) { data[rear++] = x; }
        int dequeue() { return data[front++]; }
        bool isEmpty() const { return front == rear; }
    };

    // Union-Find Implementation
    class UnionFind {
    private:
        int parent[100];
    public:
        UnionFind(int n) {
            for (int i = 0; i < n; ++i) parent[i] = i;
        }
        int find(int u) {
            if (parent[u] != u)
                parent[u] = find(parent[u]);
            return parent[u];
        }
        void unite(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if (pu != pv) parent[pu] = pv;
        }
    };

    // Constant for Infinity (substitute for INT_MAX)
    const int INF = 1e9;

    // ===== BFS =====
    Graph Algorithms::bfs(const Graph& g, int start) {
        Graph tree;
        tree.loadGraph(g.getNumVertices(), false, false);  // טוען גרף חדש לרשימת השכנות
        bool visited[100] = { false };
        Queue q;
        visited[start] = true;
        q.enqueue(start);
    
        while (!q.isEmpty()) {
            int u = q.dequeue();
            for (int v = 0; v < g.getNumVertices(); ++v) {
                if (g.isAdjacent(u, v) && !visited[v]) {
                    visited[v] = true;
                    tree.addEdge(u, v);  // הוספת הקשת לגרף ה-BFS
                    q.enqueue(v);
                }
            }
        }
        return tree;
    }
    
    

    // ===== DFS =====
    void dfsVisit(const Graph& g, Graph& tree, bool visited[], int u) {
        visited[u] = true;
        for (int v = 0; v < g.getNumVertices(); ++v) {
            if (g.isAdjacent(u, v) && !visited[v]) {
                tree.addEdge(u, v);
                dfsVisit(g, tree, visited, v);
            }
        }
    }

    Graph Algorithms::dfs(const Graph& g, int start) {
        Graph tree;
        tree.loadGraph(g.getNumVertices(), false, false);
        bool visited[100] = { false };
        dfsVisit(g, tree, visited, start);
        return tree;
    }

    // ===== Dijkstra =====
    Graph Algorithms::dijkstra(const Graph& g, int start) {
        // Check for negative edge weights
        for (int u = 0; u < g.getNumVertices(); ++u) {
            for (int v = 0; v < g.getNumVertices(); ++v) {
                if (g.isAdjacent(u, v)) {
                    int weight = g.getWeight(u, v);
                    if (weight < 0) {
                        throw std::invalid_argument("Graph contains negative edge weights, Dijkstra's algorithm cannot handle negative weights.");
                    }
                }
            }
        }
    
        Graph tree;
        tree.loadGraph(g.getNumVertices(), g.isWeighted(), false);
        
        int dist[100];
        bool visited[100] = { false };
        for (int i = 0; i < g.getNumVertices(); ++i) dist[i] = INF;
        dist[start] = 0;
        
        Queue q;
        q.enqueue(start);
        
        while (!q.isEmpty()) {
            int u = q.dequeue();
            
            if (visited[u]) continue;
            visited[u] = true;
        
            // Update neighboring vertices
            for (int v = 0; v < g.getNumVertices(); ++v) {
                if (g.isAdjacent(u, v) && !visited[v]) {
                    int w = g.getWeight(u, v);
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        tree.addEdge(u, v, w);
                        q.enqueue(v);  // Enqueue neighbors with updated distance
                    }
                }
            }
        }
        return tree;
    }
    
    // ===== Prim =====
    Graph Algorithms::prim(const Graph& g) {
        Graph tree;
        tree.loadGraph(g.getNumVertices(), g.isWeighted(), false);
        bool visited[100] = { false };
        int key[100];
        for (int i = 0; i < g.getNumVertices(); ++i) key[i] = INF;
        key[0] = 0;

        for (int count = 0; count < g.getNumVertices(); ++count) {
            int u = -1;
            for (int v = 0; v < g.getNumVertices(); ++v) {
                if (!visited[v] && (u == -1 || key[v] < key[u])) u = v;
            }
            visited[u] = true;

            for (int v = 0; v < g.getNumVertices(); ++v) {
                if (g.isAdjacent(u, v) && !visited[v] && g.getWeight(u, v) < key[v]) {
                    key[v] = g.getWeight(u, v);
                    tree.addEdge(u, v, g.getWeight(u, v));
                }
            }
        }
        return tree;
    }

    // ===== Kruskal =====
    Graph Algorithms::kruskal(const Graph& g) {
        Graph tree;
        tree.loadGraph(g.getNumVertices(), g.isWeighted(), false);
        UnionFind uf(g.getNumVertices());

        for (int u = 0; u < g.getNumVertices(); ++u) {
            for (int v = u + 1; v < g.getNumVertices(); ++v) {
                if (g.isAdjacent(u, v)) {
                    if (uf.find(u) != uf.find(v)) {
                        uf.unite(u, v);
                        tree.addEdge(u, v, g.getWeight(u, v));
                    }
                }
            }
        }
        return tree;
    }

} 
