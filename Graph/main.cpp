#include <iostream>

#include "Graph.h"

#define VERTEX_NUMBER 5

int main()
{
    Graph* graph = new Graph(VERTEX_NUMBER);

    graph->AddEdge(0, 1, 10);
    graph->AddEdge(0, 2, 30),
    graph->AddEdge(0, 3, 5);
    graph->AddEdge(2, 4, 10);
    graph->AddEdge(3, 2, 20);
    graph->AddEdge(3, 1, 40);
    graph->AddEdge(3, 4, 2);
    graph->AddEdge(4, 2, 10);
    graph->AddEdge(4, 3, 30);
    graph->Print();

    graph->Dijkstra(0);
    graph->PrintMark();
    graph->SetVertexVisitedFalse();

    graph->DepthFirstSearch(0, 4);
    graph->PrintWay();
    graph->SetVertexVisitedFalse();

    graph->BreadthFirstSearch(0, 4);
    graph->PrintWay();
    graph->SetVertexVisitedFalse();

    delete graph;
    return 0;
}