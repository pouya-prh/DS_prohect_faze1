#pragma once
#include "List.h"

template <class T>
class Tree
{
public:
	Tree();
	void Add(Node<T>);
	void Dell(int);
	Node<T>& BinarySearch(int);
private:
	friend class List<T>;
	Node<T>* root;
};

template<class T>
inline Tree<T>::Tree()
{
	root = nullptr;
}

template<class T>
inline void Tree<T>::Add(Node<T> music)
{
	Node<T>* newNode = new Node<T>(music); 
	if (root == nullptr) {
		root = newNode; 
		return;
	}

	Node<T>* current = root;
	while (true) {
		if (newNode->value.getId() >= current->value.getId()) { 
			if (current->next == nullptr) {
				current->next = newNode; 
				break;
			}
			current = current->next;
		}
		else { 
			if (current->prev == nullptr) {
				current->prev = newNode; 
				break;
			}
			current = current->prev;
		}
	}

}

template<class T>
inline void Tree<T>::Dell(int music_id)
{
	Node<T>* parent = nullptr;
	Node<T>* current = root;


	while (current && current->value.getId() != music_id) {
		parent = current;
		if (music_id < current->value.getId()) {
			current = current->prev;
		}
		else {
			current = current->next;
		}
	}

	if (!current) return; 


	if (!current->prev && !current->next) {
		if (current == root) {
			root = nullptr;
		}
		else if (parent->prev == current) {
			parent->prev = nullptr;
		}
		else {
			parent->next = nullptr;
		}
		delete current;
	}

	else if (!current->prev || !current->next) {
		Node<T>* child = current->prev ? current->prev : current->next;
		if (current == root) {
			root = child;
		}
		else if (parent->prev == current) {
			parent->prev = child;
		}
		else {
			parent->next = child;
		}
		delete current;
	}
	else {
		Node<T>* successorParent = current;
		Node<T>* successor = current->next;

		while (successor->prev) {
			successorParent = successor;
			successor = successor->prev;
		}

		current->value = successor->value;
		if (successorParent->prev == successor) {
			successorParent->prev = successor->next;
		}
		else {
			successorParent->next = successor->next;
		}
		delete successor;
	}
}

template<class T>
inline Node<T>& Tree<T>::BinarySearch(int music_id)
{
	Node<T>* current = root;
	while (current)
	{
		if (music_id == current->value.getId())
		{
			return *current;
		}
		else if (music_id > current->value.getId() )
		{
			current = current->next;
		}
		else 
		{
			current = current->prev;
		}
		

	}
	throw runtime_error("Not found");
}
