#pragma once
//#include "Tree.h"
#include "tree.h"
class PlayList
{
public:
	PlayList(string);
	PlayList(PlayList&);
	~PlayList();
	void AddMusic(Music&);
	void DellMusic(int);
	void Show();
	void search(int);
	void binarySearch(int);
	int getId();
	string getName();
private:

	List<Music> playlist;
	//Tree<Music> sortedTree;
	static int id_creator;
	int id;
	string name;
};

