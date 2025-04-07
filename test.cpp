//souldaher210@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Algorithms.cpp"
#include "Graph.cpp"

using namespace graph;

TEST_CASE("Graph Operations") {
    Graph g;
    g.loadGraph(5, false, false);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    CHECK(g.isAdjacent(0, 1) == true);
    CHECK(g.isAdjacent(0, 2) == true);
    CHECK(g.isAdjacent(1, 2) == true);
    CHECK(g.isAdjacent(1, 3) == true);
    CHECK(g.isAdjacent(3, 4) == true);
    CHECK(g.isAdjacent(0, 3) == false);
}

TEST_CASE("BFS") {
    Graph g;
    g.loadGraph(5, false, false);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    Graph tree = Algorithms::bfs(g, 0);

    // Verify the structure of the BFS tree
    CHECK(tree.isAdjacent(0, 1) == true);
    CHECK(tree.isAdjacent(1, 2) == false);
    CHECK(tree.isAdjacent(1, 3) == true);
}

TEST_CASE("DFS") {
    Graph g;
    g.loadGraph(5, false, false);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    Graph tree = Algorithms::dfs(g, 0);

    // Verify the structure of the DFS tree
    CHECK(tree.isAdjacent(0, 1) == true);
    CHECK(tree.isAdjacent(1, 2) == true);
    CHECK(tree.isAdjacent(1, 3) == true);
}

TEST_CASE("Dijkstra") {
    Graph g;
    g.loadGraph(5, true, false);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 9);
    g.addEdge(3, 4, 4);

    Graph tree = Algorithms::dijkstra(g, 0);

    
    CHECK(tree.isAdjacent(0, 1) == true);
    CHECK(tree.isAdjacent(1, 3) == true);
    CHECK(tree.isAdjacent(3, 4) == true);
}

TEST_CASE("Prim") {
    Graph g;
    g.loadGraph(5, true, false);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 9);
    g.addEdge(3, 4, 4);

    Graph tree = Algorithms::prim(g);

    
    CHECK(tree.isAdjacent(0, 2) == true);
    CHECK(tree.isAdjacent(1, 3) == true);
    CHECK(tree.isAdjacent(3, 4) == true);
}

TEST_CASE("Kruskal") {
    Graph g;
    g.loadGraph(5, true, false);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 9);
    g.addEdge(3, 4, 4);

    Graph tree = Algorithms::kruskal(g);

    
    CHECK(tree.isAdjacent(0, 2) == true);
    CHECK(tree.isAdjacent(1, 3) == true);
    CHECK(tree.isAdjacent(3, 4) == true);
}
TEST_CASE("Graph Helper Functions") {
    Graph g;
    g.loadGraph(5, false, false);  
    
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    
    

   
    CHECK(g.isAdjacent(0, 1) == true);
   
    CHECK(g.isAdjacent(0, 2) == false);
    
    
    g.addEdge(2, 0);
    
    CHECK(g.isAdjacent(0, 2) == true);

    
    g.addEdge(0, 3, 5);
    CHECK(g.getWeight(0, 3) == 5);
    CHECK(g.getWeight(3, 0) == 5);  

    
    CHECK(g.getNumVertices() == 5);
}

TEST_CASE("Edge Removal") {
    Graph g;
    g.loadGraph(5, false, false);  
    
   
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

   
    CHECK(g.isAdjacent(0, 1) == true);
    CHECK(g.isAdjacent(1, 2) == true);
    CHECK(g.isAdjacent(2, 3) == true);
    CHECK(g.isAdjacent(3, 4) == true);
    
   
    g.removeEdge(1, 2);
    
    
    CHECK(g.isAdjacent(1, 2) == false);
    CHECK(g.isAdjacent(2, 1) == false);  
}

TEST_CASE("Graph Direction Check") {
    Graph g;
    g.loadGraph(3, false, true);  

   
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    
    
    CHECK(g.isAdjacent(0, 1) == true);  
    CHECK(g.isAdjacent(1, 0) == false); 
}
