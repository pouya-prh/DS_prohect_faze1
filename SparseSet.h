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
	void insertion(T&);
	void deletation(T&);
	void deletation(int);
	int searching(int);
	void clearing();
	void showAll();
	void show(int);
	T& At(int);
	bool find(string name);
	void findMusic(string);
	void delMusic(int, int);
	void addMusicWithName(string,Music&);
	void addMusicWithId(int,Music&);
	T binarySearch(int, int, T&);
	void deleteSpecialMusic(int);
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
	dense = new T[max_value + 1];
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
void SparseSet<T>::insertion(T& node)
{
	
	int t = node.getId();
	dense[n] = node;
	sparse[t] = n;
	n++;
	cout << purple << node.getName() <<green<< " successfully added:)"<<white<<endl;
	
}

template<class T>
inline void SparseSet<T>::deletation(T& node)
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

	dense = new T[max_value + 1];
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
inline T& SparseSet<T>::At(int index)
{
	return dense[sparse[index]];
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
		string musicName = dense[sparse[id]].find(id).getName();
		dense[sparse[id]].dellMusic(musicID);
		cout <<musicName<< " deleted successfully" << endl;
		return;
	}
	
	cout << musicID << " doesnt exsist!" << endl;
}

template<class T>
void SparseSet<T>::addMusicWithName(string artistName,Music& music)
{
	
	for (int i = 0; i < n; i++)
	{
		if (dense[sparse[i]].getName() == artistName)
		{
			dense[sparse[i]].addMusic(music);
			cout << music.getName() << " successfully added to " << artistName << " musics" << endl;
			return;
		}

	}

	cout << "invalid input!" << endl;
}

template<class T>
inline void SparseSet<T>::addMusicWithId(int id, Music& music)
{
	dense[sparse[id]].addMusic(music);
	cout << music.getName() << " successfully added to " << dense[sparse[id]].getName() << " musics" << endl;
	//return music;
}

template<class T>
inline T SparseSet<T>::binarySearch(int left, int right, T& p)
{
	int mid = left + (left + right) / 2;
	if (left > right)
		return dense[mid];
	if (p.getId() > dense[mid].getId())
	{
		binarySearch(mid + 1, right, p);
	}
	else
	{
		binarySearch(left, mid - 1, p);
	}
}

template<class T>
inline void SparseSet<T>::deleteSpecialMusic(int id)
{
	for (int i = 0; i < n; i++)
	{
		dense[i].dellMusic(id);
	}
}
