#pragma once
#include "Music.h"
template<class T>
class Node
{
public:
    Node(T valu) : value(valu), next(nullptr), prev(nullptr) {}
    ~Node() {}
    T value;
    Node* next;
    Node* prev;
};

