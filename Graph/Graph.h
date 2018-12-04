//
// Created by dbogdano on 3/12/2018.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include "List.h"

class Graph {
public:
    Graph(int N);
    ~Graph();
    void AddEdge(int start, int end);
    void Print();
    void DepthFirstSearch(int start, int end);
    void BreadthFirstSearch(int start, int end);
    void PrintWay();
    void SetVertexVisitedFalse();

private:
    bool CheckVertexVisited();

public:
    int m_Number;
    List* m_vertex;
    bool* m_vertexVisited;
    List* m_way;
    List* m_queue;
};


#endif //GRAPH_GRAPH_H
