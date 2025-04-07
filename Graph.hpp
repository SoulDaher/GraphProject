//souldaher210@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

namespace graph {

    struct Edge {
        int destination;
        int weight;
        Edge* next;

        Edge(int dest, int w) : destination(dest), weight(w), next(nullptr) {}
    };

    class Graph {
    public:
        
        Graph(int vertices = 0, bool weightedGraph = false, bool directedGraph = false);

        ~Graph();

        void loadGraph(int vertices, bool weightedGraph, bool directedGraph);
        void addEdge(int u, int v, int weight = 1);
        void print_graph() const;
        void removeEdge(int source, int dest);
        bool isDirected() const;
        int getWeight(int from, int to) const;
        bool isWeighted() const;
        int getNumVertices() const;
        bool isAdjacent(int u, int v) const;

    private:
        int numVertices;
        bool weighted;
        bool directed;
        std::vector<Edge*> adjacencyList;
    };

}

#endif
