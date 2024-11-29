#pragma once
#include "Music.h"
template<class T>
class Node
{
public:
    Node(T value) : value(value), next(nullptr), prev(nullptr) {}
    ~Node() {}
    T value;
    Node* next;
    Node* prev;
};

