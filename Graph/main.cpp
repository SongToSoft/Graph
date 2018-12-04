#include <iostream>

#include "Graph.h"

#define VERTEX_NUMBER 6

int main()
{
    Graph* graph = new Graph(VERTEX_NUMBER);
    /*graph->AddEdge(0, 5);
    graph->AddEdge(1, 5);
    graph->AddEdge(2, 5);
    graph->AddEdge(3, 5);
    graph->AddEdge(4, 5);
    graph->AddEdge(5, 5);
    graph->AddEdge(6, 5);
    graph->AddEdge(7, 5);
    graph->AddEdge(8, 5);
    graph->AddEdge(9, 5);

    graph->AddEdge(1, 2);
    graph->AddEdge(2, 3);
    graph->AddEdge(3, 4);
    graph->AddEdge(4, 5);
    graph->AddEdge(0, 6);
    graph->AddEdge(0, 1);*/

    graph->AddEdge(0, 1);
    graph->AddEdge(0, 2);
    graph->AddEdge(0, 3);
    graph->AddEdge(1, 2);
    graph->AddEdge(1, 3);
    graph->AddEdge(2, 3);
    graph->AddEdge(3, 4);
    graph->AddEdge(4, 1);
    graph->AddEdge(4, 0);
    graph->AddEdge(4, 5);
    graph->Print();

    graph->DepthFirstSearch(0, 5);
    graph->SetVertexVisitedFalse();

    graph->BreadthFirstSearch(0, 5);
    graph->SetVertexVisitedFalse();

    delete graph;
    return 0;
}