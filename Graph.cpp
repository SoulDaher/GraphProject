//souldaher210@gmail.com
#include "Graph.hpp"
#include <iostream>

namespace graph {

    Graph::Graph(int vertices, bool weightedGraph, bool directedGraph)
    : numVertices(vertices), weighted(weightedGraph), directed(directedGraph) {
    adjacencyList.resize(vertices, nullptr); 
}

    

    Graph::~Graph() {
        for (int i = 0; i < numVertices; ++i) {
            Edge* current = adjacencyList[i];
            while (current != nullptr) {
                Edge* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
    }

    void Graph::loadGraph(int vertices, bool weightedGraph, bool directedGraph) {
        this->numVertices = vertices;
        this->weighted = weightedGraph;
        this->directed = directedGraph;
        adjacencyList.resize(vertices, nullptr); 
    }

    void Graph::addEdge(int u, int v, int weight) {
        Edge* newEdge = new Edge(v, weight);
        newEdge->next = adjacencyList[u];
        adjacencyList[u] = newEdge;

        if (!directed) {
            newEdge = new Edge(u, weight);
            newEdge->next = adjacencyList[v];
            adjacencyList[v] = newEdge;
        }
    }

    
    void Graph::print_graph() const {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i << " -> ";
            Edge* current = adjacencyList[i];
            while (current) {
                std::cout << "(" << current->destination << ", weight: " << current->weight << ") ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
    void Graph::removeEdge(int u, int v) {
        
        Edge* current = adjacencyList[u];
        Edge* prev = nullptr;
        while (current != nullptr) {
            if (current->destination == v) {
                if (prev == nullptr) {
                    // אם הקשת היא הראשונה ברשימה
                    adjacencyList[u] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                break;
            }
            prev = current;
            current = current->next;
        }
    
        
        if (!directed) {
            current = adjacencyList[v];
            prev = nullptr;
            while (current != nullptr) {
                if (current->destination == u) {
                    if (prev == nullptr) {
                        adjacencyList[v] = current->next;
                    } else {
                        prev->next = current->next;
                    }
                    delete current;
                    break;
                }
                prev = current;
                current = current->next;
            }
        }
    }
    

    bool Graph::isDirected() const {
        return directed;
    }

  int Graph::getWeight(int u, int v) const {
    Edge* current = adjacencyList[u];
    while (current) {
        if (current->destination == v) {
            return current->weight;
        }
        current = current->next;
    }
    return -1;
  }

   

    bool Graph::isWeighted() const {
        return weighted;
    }

    int Graph::getNumVertices() const {
        return numVertices;
    }

    bool Graph::isAdjacent(int u, int v) const {
        Edge* current = adjacencyList[u];
        while (current) {
            if (current->destination == v) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
}
