//
// Created by dbogdano on 3/12/2018.
//

#include <iostream>
#include "List.h"

List::List()
:
m_head(nullptr)
{
}

List::~List()
{
    Node *node = m_head;
    while (node != nullptr)
    {
        Node *tmp = node;
        node = node->m_next;
        delete(tmp);
    }
}

void List::PushToTail(int value)
{
    if (m_head == nullptr)
    {
        m_head = new Node(value);
    }
    else
    {
        Node *node = m_head;
        while (node->m_next)
        {
            node = node->m_next;
        }
        Node* new_node = new Node(value);
        node->m_next = new_node;
    }
}

void List::Push(int value)
{
    if (Node *node = new Node(value))
    {
        node->m_next = m_head;
        m_head = node;
    }
    else
    {
        std::cout << "Memory Error with AddNode" << std::endl;
    }
}

void List::PushUniq(int value)
{
    Node *node = m_head;
    while (node != nullptr)
    {
        if (node->m_value == value)
        {
            std::cout << "Non Unique value" << std::endl;
            return;
        }
        node = node->m_next;
    }
    Push(value);
}

int List::Pop()
{
    if (m_head)
    {
        Node *node = m_head->m_next;
        int value = m_head->m_value;
        delete( m_head );
        m_head = node;
        return value;
    }
}

void List::Print()
{
    Node *node = m_head;
    while (node != nullptr)
    {
        std::cout << node->m_value << " ";
        node = node->m_next;
    }
    std::cout << std::endl;
}

bool List::IsEmpty()
{
    if (m_head != nullptr)
    {
        return false;
    }
    else
    {
        return  true;
    }
}