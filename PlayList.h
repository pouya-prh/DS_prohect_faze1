#pragma once
//#include "tree.h"
#include "List.h"
class PlayList
{
public:
	PlayList(string);
	PlayList() {}
	PlayList(PlayList&);
	~PlayList();
	void addMusic(Music&);
	void dellMusic(int);
	void show();
	void search(int);
	int getId();
	string getName();
private:

	List<Music> playlist;
	static int id_creator;
	int id;
	string name;
};

