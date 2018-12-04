//
// Created by dbogdano on 3/12/2018.
//

#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H


class Node {
public:
    Node(int value, int m_weight = 0);
public:
    int m_value;
    int m_weight;
    Node *m_next;

};


#endif //GRAPH_NODE_H
