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
	void show(int);
	T At(int);
	bool find(string name);
	void findMusic(string);
	void delMusic(int, int);
	void addMusic(string, string, string, string);
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
	sparse = new int[MAX + 1];
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
	delete[] dense;
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
void SparseSet<T>::deletation(int id)
{
	
	if (n != 1)
	{

		T temp = dense[id];
		dense[sparse[id]] = temp;
		sparse[temp.getId()] = sparse[id];
		
		for (int i = id + 1; i < n ; i++ )
		{
			dense[sparse[i - 1]] = dense[sparse[i]];
			
		}
		sparse[id] = -1;
	}
	
	n--;
}

template<class T>
int SparseSet<T>::searching(int id)
{
	if (sparse[id] > -1)
		return sparse[id];
	return -1;
}

template<class T>
inline void SparseSet<T>::clearing()
{
	
	delete[] dense;
	delete[] sparse;

	dense = new Singer[max_value + 1];
	for (int i = 0; i < max_value; i++)
	{
		sparse[i] = -1;

	}
	n = 0;
}

template<class T>
inline void SparseSet<T>::showAll()
{
	for (int i = 0; i < n; i++)
	{
		cout << dense[i] << '\n' << "musics: \n";
		dense[i].getMusics().display();
	}

	cout << endl;
}

template<class T>
inline void SparseSet<T>::show(int index)
{
	cout << dense[index];
	dense[index].getMusics().display();
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

template<class T>
void SparseSet<T>::findMusic(string name)
{
	bool find = false;
	for (int i = 0; i < n; i++)
	{
		find = dense[i].getMusics().findMusic(name);
		if (find)
			return;
	}
	cout << name << " doesnt exsist!"<<endl;
}

template<class T>
void SparseSet<T>::delMusic(int musicID, int id)
{
	bool find = false;
	find = dense[sparse[id]].getMusics().findMusic(musicID);
	if (find)
	{
		dense[sparse[id]].getMusics().del(musicID);
		cout << musicID << " deleted successfully" << endl;
		return;
	}
	
	cout << musicID << " doesnt exsist!" << endl;
}

template<class T>
inline void SparseSet<T>::addMusic(string musicName, string artistName, string date, string text)
{
	Music music(text, musicName, date);
	for (int i = 0; i < n; i++)
	{
		if (dense[i].getName() == artistName)
		{
			dense[i].addMusic(music);
			cout << musicName << " seccessfully added to " << artistName << " musics" << endl;
			return;
		}

	}

	cout << "invalid input!" << endl;
}
