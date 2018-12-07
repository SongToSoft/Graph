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
    void AddEdge(int start, int end, int weight = 0);
    void Print();
    bool DepthFirstSearch(int start, int end);
    void BreadthFirstSearch(int start, int end);
    void PrintWay();
    void SetVertexVisitedFalse();
    void Dijkstra(int start);
    void PrintMark();
private:
    bool CheckVertexVisited();
    void ConstructWay(int target);
    void CleanVisitedVertex();
    void SetMark();
    int GetMinMarkIndex();
    List* Equate(List* list);

private:
    int m_Number;
    List* m_Vertex;
    bool* m_Vertex_Visited;
    //variables for DFS
    List *m_Way, *m_Way_Tmp;
    //variables for BFS
    int m_Start_Vertex;
    List* m_Queue;
    //variables for Dijkstra
    int* m_Mark;
};


#endif //GRAPH_GRAPH_H
