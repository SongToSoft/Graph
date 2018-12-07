//
// Created by dbogdano on 3/12/2018.
//

#include <iostream>
#include "List.h"

List::List()
:
m_Head(nullptr)
{
}

List::~List()
{
    Node *node = m_Head;
    while (node != nullptr)
    {
        Node *tmp = node;
        node = node->m_Next;
        delete(tmp);
    }
}

void List::PushToTail(int value)
{
    if (m_Head == nullptr)
    {
        m_Head = new Node(value);
    }
    else
    {
        Node *node = m_Head;
        while (node->m_Next)
        {
            node = node->m_Next;
        }
        Node* new_node = new Node(value);
        node->m_Next = new_node;
    }
}

void List::Push(int value, int weight)
{
    if (weight < 0)
    {
        std::cout << "Incorrect weight value" << std::endl;
    }
    if (Node *node = new Node(value))
    {
        node->m_Next = m_Head;
        node->m_Weight = weight;
        m_Head = node;
    }
    else
    {
        std::cout << "Memory Error with AddNode" << std::endl;
    }
}

void List::PushUniq(int value, int weight)
{
    Node *node = m_Head;
    while (node != nullptr)
    {
        if (node->m_Value == value)
        {
            std::cout << "Non Unique value" << std::endl;
            return;
        }
        node = node->m_Next;
    }
    Push(value, weight);
}

int List::Pop()
{
    if (m_Head)
    {
        Node *node = m_Head->m_Next;
        int value = m_Head->m_Value;
        delete m_Head;
        m_Head = node;
        return value;
    }
}

void List::Print()
{
    Node *node = m_Head;
    while (node != nullptr)
    {
        std::cout << node->m_Value << " ";
        node = node->m_Next;
    }
    std::cout << std::endl;
}

bool List::IsEmpty()
{
    if (m_Head != nullptr)
    {
        return false;
    }
    else
    {
        return  true;
    }
}
