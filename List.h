#pragma once

#include "Node.h"

using namespace std;


template <class T>
class List
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
    T* Arr;
   friend class Node<T>;
public:
    
     List() : head(nullptr), tail(nullptr) ,size(0){}
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
    void showInDateSortedMode();
    void operator = (List<T>&);

    int partition(Music* arr, int low, int high) {
        Music pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (pivot > arr[j]) {
                ++i;
                Music temp(arr[i]);
                arr[i] = arr[j];
                arr[j] = temp;
                // std::swap(arr[i], arr[j]); // Swap smaller element to the left
            }
        }
        Music temp(arr[i + 1]);
        arr[i + 1] = arr[high];
        arr[high] = temp;
        //std::swap(arr[i + 1], arr[high]); 
        return i + 1;
    }


    void quicksort(Music* arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quicksort(arr, low, pivotIndex - 1);
            quicksort(arr, pivotIndex + 1, high);
         
        }
        
    }
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
    size++;
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
    size--;
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
    size--;

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
    size--;
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
    size = 0;
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
inline void List<T>::showInDateSortedMode()
{
    Arr = new T[size];
    Node<T>* current = head;
    int i = 0;
    while (current)
    {
        Arr[i] = current->value;
        current = current->next;
        i++;
    }

    quicksort(Arr, 0, size-1);

    for (int i = 0; i < size; i++)
    {
        cout << Arr[i];
    }

}

template<class T>
inline void List<T>::operator=(List<T>& list)
{
    this->head = list.head;
    this->tail = list.tail;
}



