#include <iostream>
#include "list/list.h"
#include "matrix/matrix.h"
#include "set/set.h"
#include "arc/arc.h"
#include "base/base.h"



void print_by_dfs(IGraph *graph)
{
    dfs(*graph, [](int vertex) { std::cout << vertex << std::endl; });
}


void print_by_bfs(IGraph *graph)
{
    bfs(*graph, [](int vertex) { std::cout << vertex << std::endl; });
}


int main()
{
    IGraph *list_graph = new ListGraph(7);

    list_graph->AddEdge(0, 1);
    list_graph->AddEdge(0, 2);
    list_graph->AddEdge(1, 3);
    list_graph->AddEdge(2, 3);
    list_graph->AddEdge(3, 4);
    list_graph->AddEdge(3, 5);
    list_graph->AddEdge(4, 6);
    list_graph->AddEdge(5, 6);
    
    IGraph *matrix_graph = new MatrixGraph(*list_graph);
    IGraph *set_graph = new SetGraph(*list_graph);
    IGraph *arc_graph = new ArcGraph(*list_graph);
    
    std::cout << "1) ListGraph" << std::endl;
    std::cout << "-- DFS" << std::endl;
    print_by_dfs(list_graph);
    std::cout << "-- BFS" << std::endl;
    print_by_bfs(list_graph);
    
    std::cout << std::endl;
    
    std::cout << "2) MatrixGraph" << std::endl;
    std::cout << "-- DFS" << std::endl;
    print_by_dfs(matrix_graph);
    std::cout << "-- BFS" << std::endl;
    print_by_bfs(matrix_graph);
    
    std::cout << std::endl;
    
    std::cout << "3) SetGraph" << std::endl;
    std::cout << "-- DFS" << std::endl;
    print_by_dfs(set_graph);
    std::cout << "-- BFS" << std::endl;
    print_by_bfs(set_graph);    
    
    std::cout << std::endl;
    
    std::cout << "4) ArcGraph" << std::endl;
    std::cout << "-- DFS" << std::endl;
    print_by_dfs(arc_graph);
    std::cout << "-- BFS" << std::endl;
    print_by_bfs(arc_graph);

    delete list_graph;
    delete matrix_graph;
    delete set_graph;
    delete arc_graph;
    
    return 0;
}