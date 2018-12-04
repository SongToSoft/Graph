//
// Created by dbogdano on 3/12/2018.
//

#include <iostream>
#include "Graph.h"

Graph::Graph(int N)
:
m_Number(N)
{
    m_vertex = new List[m_Number];
    m_vertexVisited = new bool[m_Number];
    m_way = new List();
    m_queue = new List();
    SetVertexVisitedFalse();
}

Graph::~Graph()
{
    delete []m_vertex;
    delete m_vertexVisited;
    delete m_way;
    delete m_queue;
}

void Graph::AddEdge(int start, int end)
{
    if ((start < m_Number) && (end < m_Number))
    {
        if (start != end)
        {
            m_vertex[start].PushUniq(end);
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
        m_vertex[i].Print();
        std::cout << std::endl;
    }
}

void Graph::DepthFirstSearch(int start, int end)
{
    if (CheckVertexVisited())
    {
        m_way->Pop();
        return;
    }
    else
    {
        m_way->Push(start);
        m_vertexVisited[start] = true;
        if (start == end)
        {
            std::cout << "We find way" << std::endl;
            PrintWay();
            return;
        }
        Node *node = m_vertex[start].m_head;
        bool checkNearest = false;
        while (node != nullptr )
        {
            if (!m_vertexVisited[node->m_value])
            {
                DepthFirstSearch(node->m_value, end);
                checkNearest = true;
            }
            node = node->m_next;
        }
        if (!checkNearest)
        {
            m_way->Pop();
        }
    }
}

void Graph::BreadthFirstSearch(int start, int end)
{
    m_queue->PushToTail(start);
    m_vertexVisited[start] = true;
    while (!m_queue->IsEmpty())
    {
        //std::cout << "Queue:";
        //m_queue->Print();
        Node *node = m_vertex[m_queue->Pop()].m_head;
        while (node != nullptr)
        {
            if (node->m_value == end)
            {
                std::cout << "WE FIND WAY" << std::endl;
            }
            if (!m_vertexVisited[node->m_value])
            {
                m_queue->PushToTail(node->m_value);
                m_vertexVisited[node->m_value] = true;
            }
            node = node->m_next;
        }
    }
}

void Graph::SetVertexVisitedFalse()
{
    for (int i = 0; i < m_Number; ++i)
    {
        m_vertexVisited[i] = false;
    }
}

bool Graph::CheckVertexVisited()
{
    for (int i = 0; i < m_Number; ++i)
    {
        if (!m_vertexVisited[i])
        {
            return false;
        }
    }
    return true;
}

void Graph::PrintWay()
{
    m_way->Print();
}