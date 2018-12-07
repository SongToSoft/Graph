//
// Created by dbogdano on 3/12/2018.
//

#include <iostream>
#include "limits.h"
#include "Graph.h"

Graph::Graph(int N)
:
m_Number(N)
{
    m_Vertex = new List[m_Number];
    m_Vertex_Visited = new bool[m_Number];
    m_Way = new List();
    m_Way_Tmp = new List();
    m_Queue = new List();
    m_Mark = new int[m_Number];
    SetVertexVisitedFalse();
}

Graph::~Graph()
{
    delete []m_Vertex;
    delete m_Vertex_Visited;
    delete m_Way;
    delete m_Way_Tmp;
    delete m_Queue;
    delete m_Mark;
}

void Graph::AddEdge(int start, int end, int weight)
{
    if ((start < m_Number) && (end < m_Number))
    {
        if (start != end)
        {
            m_Vertex[start].PushUniq(end, weight);
            //m_vertex[end].PushUniq(start);
        }
    }
    else
    {
        std::cout << "Incorrect value" << std::endl;
    }
}

void Graph::Print()
{
    for (int i = 0; i < m_Number; ++i)
    {
        std::cout << "[ " << i << " ] : ";
        m_Vertex[i].Print();
        std::cout << std::endl;
    }
}

bool Graph::DepthFirstSearch(int start, int end)
{
    if (CheckVertexVisited())
    {
        m_Way_Tmp->Pop();
        return false;
    }
    else
    {
        m_Way_Tmp->Push(start);
        m_Vertex_Visited[start] = true;
        if (start == end)
        {
            std::cout << "DFS FIND WAY" << std::endl;
            m_Way = Equate(m_Way_Tmp);
            return true;
        }
        Node *node = m_Vertex[start].m_Head;
        bool checkNearest = false;
        while (node != nullptr )
        {
            if (!m_Vertex_Visited[node->m_Value])
            {
                if (!DepthFirstSearch(node->m_Value, end) && (node->m_Next == nullptr))
                {
                    m_Way_Tmp->Pop();
                    return false;
                }
                checkNearest = true;
            }
            node = node->m_Next;
        }
        if (!checkNearest)
        {
            m_Way_Tmp->Pop();
        }
    }
}

void Graph::BreadthFirstSearch(int start, int end)
{
    m_Queue->PushToTail(start);
    m_Vertex_Visited[start] = true;
    m_Start_Vertex = start;
    while (!m_Queue->IsEmpty())
    {
        int parent = m_Queue->Pop();
        Node *node = m_Vertex[parent].m_Head;
        while (node != nullptr)
        {
            if (!m_Vertex_Visited[node->m_Value])
            {
                node->m_Parent = parent;
                m_Queue->PushToTail(node->m_Value);
                m_Vertex_Visited[node->m_Value] = true;
            }
            if (node->m_Value == end)
            {
                std::cout << "BFS FIND WAY " << std::endl;
                ConstructWay(end);
                return;
            }
            node = node->m_Next;
        }
    }
}

void Graph::SetVertexVisitedFalse()
{
    for (int i = 0; i < m_Number; ++i)
    {
        m_Vertex_Visited[i] = false;
    }
    CleanVisitedVertex();
}

bool Graph::CheckVertexVisited()
{
    for (int i = 0; i < m_Number; ++i)
    {
        if (!m_Vertex_Visited[i])
        {
            return false;
        }
    }
    return true;
}

void Graph::PrintWay()
{
    std::cout << "WAY: ";
    m_Way->Print();
}

void Graph::ConstructWay(int target)
{
    if (target == (-1))
    {
        return;
    }
    if (target == m_Start_Vertex)
    {
        m_Way->Push(target);
        return;
    }
    for (int i = 0; i < m_Number; ++i)
    {
        Node *node = m_Vertex[i].m_Head;
        while (node != nullptr)
        {
            if ((node->m_Value == target) && (node->m_Parent != (-1)))
            {
                m_Way->Push(target);
                ConstructWay(node->m_Parent);
            }
            node = node->m_Next;
        }
    }
}

List* Graph::Equate(List* list)
{
    List *new_list = new List();
    Node *node = list->m_Head;
    while (node != nullptr)
    {
        new_list->Push(node->m_Value);
        node = node->m_Next;
    }
    return new_list;
}

void Graph::CleanVisitedVertex()
{
    delete m_Way;
    delete m_Way_Tmp;
    m_Way = new List();
    m_Way_Tmp = new List();

}

void Graph::Dijkstra(int start)
{
    if (start >= m_Number)
    {
        std::cout << "Dijkstra invalid value" << std::endl;
        return;
    }
    SetMark();
    m_Mark[start] = 0;
    while (!CheckVertexVisited())
    {
        int current_vertex = GetMinMarkIndex();
        Node *node = m_Vertex[current_vertex].m_Head;
        while(node != nullptr)
        {
            if ((node->m_Weight + m_Mark[GetMinMarkIndex()]) < m_Mark[node->m_Value])
            {
                m_Mark[node->m_Value] = node->m_Weight + m_Mark[GetMinMarkIndex()];
            }
            node = node->m_Next;
        }
        m_Vertex_Visited[current_vertex] = true;
    }
}

void Graph::SetMark()
{
    for (int i = 0; i < m_Number; ++i)
    {
        m_Mark[i] = INT_MAX;
    }
}

int Graph::GetMinMarkIndex()
{
    int min_Mark = INT_MAX;
    int min_Index = 0;
    for (int i = 0; i < m_Number; ++i)
    {
        if ((m_Mark[i] < min_Mark) && (!m_Vertex_Visited[i]))
        {
            min_Mark = m_Mark[i];
            min_Index = i;
        }
    }
    return min_Index;
}

void Graph::PrintMark()
{
    std::cout << "Distance to all vertex from start: " << std::endl;
    for (int i = 0; i < m_Number; ++i)
    {
        std::cout << i << " - " << m_Mark[i] << std::endl;
    }
}
