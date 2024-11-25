#pragma once
#define green "\033[1;32m"
#define white "\033[0m"
#define red   "\033[1;31m"
#define blue  "\033[1;34m"
#define purple "\033[1;35m"
#include "List.h"
#include "Singer.h"
#define MAX 100
template<class T>
class SparseSet
{
public:
	SparseSet();
	~SparseSet();
	void insertion(string);
	void deletation(T);
	void deletation(int);
	int searching(int);
	void clearing();
	void showAll();
	T At(int);
	bool find(string name);
private:
	int n;
	int capacity;
	int* sparse;
	T* dense;
	int max_value;
};

template<class T>
inline SparseSet<T>::SparseSet()
{
	this->n = 0;
	max_value = MAX;
	this->capacity = MAX;
	sparse = new int[max_value+1];
	dense = new Singer[max_value + 1];
	for (int i = 0; i < max_value; i++)
	{
		sparse[i] = -1;
		
	}
}

template<class T>
inline SparseSet<T>::~SparseSet()
{
	delete[] sparse;
	//delete[] dense;
}

template<class T>
void SparseSet<T>::insertion(string name)
{
	Singer singer(name);
	
	if (!find(name))
	{
		int t = singer.getId();
		dense[n] = singer;
		sparse[t] = n;
		n++;
		cout << purple << name <<green<< " seccessfully added:)"<<white<<endl;
	}
	else
	{
		cout << red<<"Repeated name!" <<white<< endl;
	}

	
}

template<class T>
inline void SparseSet<T>::deletation(T node)
{
	int toDel = node.getId();
	sparse[dense[n - 1].getId()] = sparse[toDel];
	sparse[dense[toDel].getId()] = -1;
	dense[sparse[toDel]] = dense[n - 1];
	n--;
}

template<class T>
inline void SparseSet<T>::deletation(int id)
{
	int toDel = id;
	sparse[dense[n - 1].getId()] = sparse[toDel];
	sparse[dense[toDel].getId()] = -1;
	dense[sparse[toDel]] = dense[n - 1];
	n--;
}

template<class T>
int SparseSet<T>::searching(int id)
{
	if (sparse[id] >= 0)
		return sparse[id];
	return -1;
}

template<class T>
inline void SparseSet<T>::clearing()
{
	n = 0;
}

template<class T>
inline void SparseSet<T>::showAll()
{
	for (int i = 0; i < n; i++)
	{
		cout << dense[i].getName() << " , ";
	}
	cout << endl;
}

template<class T>
inline T SparseSet<T>::At(int index)
{
	return dense[index];
}

template<class T>
inline bool SparseSet<T>::find(string name)
{
	for (int i = 0; i < n; i++)
	{
		if (name == dense[i].getName())
			return true;
	}
	return false;
}
