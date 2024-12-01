#pragma once

#include "Node.h"

using namespace std;


template <class T>
class List
{
private:
    Node<T>* head;
    Node<T>* tail;
   friend class Node<T>;
public:
    
     List() : head(nullptr), tail(nullptr) {}
    ~List();
    void push_back(T& value);
    T& pop_back();
    void display() ;
    bool empty() const;
    T& front() const;
    T& last() const;
    void del(int);
    void del(string);
    void swap(int index1, int index2);
    bool findMusic(string);
    bool findMusic(int);
    T& find(int);
    void clearing();
    Node<T>* BinarySearch(int,Node<T>&);
    T& search(int);
    void operator = (List<T>&);
   
};


template <class T>
List<T>::~List()
{
   /* Node<T>* current = head;
    while (current)
    {
        Node<T>* toDelete = current;
        current = current->next;
        delete toDelete;
    }*/
}

template <class T>
void List<T>::push_back(T& value)
{
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template <class T>
T& List<T>::pop_back()
{
    if (!tail)
        throw runtime_error("Cannot pop from an empty list");

    T value = tail->value;
    Node<T>* toDelete = tail;

    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete toDelete;
    return value;
}

template <class T>
void List<T>::display() 
{
    Node<T>* current = head;
    while (current)
    {
        cout << current->value<< endl;
        current = current->next;
    }
    cout << endl;
}

template<class T>
bool List<T>::empty() const
{
    return head == tail;
}


template <class T>
T& List<T>::front() const
{
    if (!head)
        throw runtime_error("List is empty");
    return head->value;
}

template <class T>
T& List<T>::last() const
{
    if (!tail)
        throw runtime_error("List is empty");
    return tail->value;
}

template<class T>
inline void List<T>::del(int id)
{
    Node<T>* current = head;
    while (current)
    {
        if (current->value.getId() == id) 
        {
            Node<T>* toDelete = current;

            if (current->prev)  
                current->prev->next = current->next;
            else  
                head = current->next;

            if (current->next)  
                current->next->prev = current->prev;
            else  
                tail = current->prev;

            current = current->next;  
            delete toDelete;         
        }
        else
        {
            current = current->next;
        }
    }

}

template<class T>
inline void List<T>::del(string name)
{
    Node<T>* current;
    current = head;
    while (current)
    {
        if (current->value.getName() == name)
        {
            Node<T>* toDelete = current;

            if (current->prev)
                current->prev->next = current->next;
            else
                head = current->next;

            if (current->next)
                current->next->prev = current->prev;
            else
                tail = current->prev;

            current = current->next;
            delete toDelete;
        }
        else
        {
            current = current->next;
        }
    }
}

template <class T>
void List<T>::swap(int index1, int index2)
{

    if (index1 == index2)
        return;

    Node<T>* node1 = head;
    for (int i = 0; i < index1; i++)
        node1 = node1->next;

    Node<T>* node2 = head;
    for (int i = 0; i < index2; i++)
        node2 = node2->next;

    T temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}

template<class T>
bool List<T>::findMusic(string name)
{
    Node<T>* current = head;
    while (current)
    {
        if (current->value.getName() == name)
        {
            cout << current->value;
            return true;
        }
        current = current->next;
    }
     return false;
}

template<class T>
inline bool List<T>::findMusic(int id)
{
    Node<T>* current = head;
    while (current)
    {
        if (current->value.getId() == id)
        {
            cout << current->value;
            return true;
        }
        current = current->next;
    }
    return false;
}

template<class T>
inline T& List<T>::find(int id)
{

    Node<T>* current = head;
    while (current)
    {
        if (current->value.getId() == id)
        {
            return current->value;
           
        }
        current = current->next;
    }
    throw runtime_error("Not found!");
}

template<class T>
inline void List<T>::clearing()
{
    Node<T>* current;
    current = head;
    while (current)
    {
       
        Node<T>* toDelete = current;

        if (current->prev)
            current->prev->next = current->next;
        else
            head = current->next;

        if (current->next)
            current->next->prev = current->prev;
        else
            tail = current->prev;

        current = current->next;
        delete toDelete;
       
    }
    head = nullptr;
    tail = nullptr;
}


template<class T>
inline Node<T>* List<T>::BinarySearch(int music_id, Node<T>& root)
{
    while (true)
    {
        if (music_id == root->value.getId())
        {
            return root;
        }
        else if (music_id > root->value.getId())
        {
            root = root->next;
            continue;
        }
        else 
        {
            root = root->prev;
            continue;
        }
        break;

    }
    throw runtime_error("Not found");
}

template<class T>
inline T& List<T>::search(int playlist_id)
{
    Node<T>* current = head;
    while (current)
    {
        if (current->value.getId() == playlist_id)
        {
            return current->value;
        }
        current = current->next;
    }
    throw runtime_error("Not found");
   
}

template<class T>
inline void List<T>::operator=(List<T>& list)
{
    this->head = list.head;
    this->tail = list.tail;
}



