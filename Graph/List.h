//
// Created by dbogdano on 3/12/2018.
//

#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include "Node.h"

class List {

public:
    List();
    ~List();
    void PushToTail(int value);
    void Push(int value, int weight = 0);
    void PushUniq(int value, int weight = 0);
    int Pop();
    void Print();
    bool IsEmpty();

public:
    Node *m_Head;
};


#endif //GRAPH_LIST_H
