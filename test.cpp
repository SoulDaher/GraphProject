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

    // Verify the structure of the Dijkstra tree
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

    // Verify the structure of the Prim tree
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

    // Verify the structure of the Kruskal tree
    CHECK(tree.isAdjacent(0, 2) == true);
    CHECK(tree.isAdjacent(1, 3) == true);
    CHECK(tree.isAdjacent(3, 4) == true);
}
TEST_CASE("Graph Helper Functions") {
    Graph g;
    g.loadGraph(5, false, false);  // גרף לא מכוון, לא משוקלל
    
    // נוסיף כמה קשתות
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    
    // בדיקות לפונקציות עזר

    // בדוק אם יש קשת בין 0 ל-1
    CHECK(g.isAdjacent(0, 1) == true);
    // בדוק אם אין קשת בין 0 ל-2 (לא הוספנו קשת ישירה)
    CHECK(g.isAdjacent(0, 2) == false);
    
    // הוספת קשת נוספת בין 2 ל-0
    g.addEdge(2, 0);
    // בדוק אם יש קשת בין 0 ל-2 עכשיו
    CHECK(g.isAdjacent(0, 2) == true);

    // נבדוק גם פונקציות של משקל (נוסיף קשת עם משקל)
    g.addEdge(0, 3, 5);
    CHECK(g.getWeight(0, 3) == 5);
    CHECK(g.getWeight(3, 0) == 5);  // כיוון לא מכוון

    // נבדוק את מספר הקודקודים בגרף
    CHECK(g.getNumVertices() == 5);
}

TEST_CASE("Edge Removal") {
    Graph g;
    g.loadGraph(5, false, false);  // גרף לא מכוון
    
    // נוסיף קשתות
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // נוודא שהקשתות נוספו
    CHECK(g.isAdjacent(0, 1) == true);
    CHECK(g.isAdjacent(1, 2) == true);
    CHECK(g.isAdjacent(2, 3) == true);
    CHECK(g.isAdjacent(3, 4) == true);
    
    // נסיר קשת בין 1 ל-2
    g.removeEdge(1, 2);
    
    // נוודא שהקשת הוסרה
    CHECK(g.isAdjacent(1, 2) == false);
    CHECK(g.isAdjacent(2, 1) == false);  // מכיוון שזה גרף לא מכוון, צריך גם לבדוק את הצלע בכיוון השני
}

TEST_CASE("Graph Direction Check") {
    Graph g;
    g.loadGraph(3, false, true);  // גרף מכוון

    // נוסיף קשתות
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    
    // נוודא שצלעות מכוונות כראוי
    CHECK(g.isAdjacent(0, 1) == true);  // קשת ישירה בין 0 ל-1
    CHECK(g.isAdjacent(1, 0) == false); // אין קשת חזרה מ-1 ל-0
}
