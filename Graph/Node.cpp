//
// Created by dbogdano on 3/12/2018.
//

#include "Node.h"

Node::Node(int value, int weight)
:
m_Value(value),
m_Weight(weight),
m_Parent(-1),
m_Next(nullptr)
{
}