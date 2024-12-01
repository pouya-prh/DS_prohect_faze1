#pragma once
#include "tree.h"
class PlayList
{
public:
	PlayList(string);
	PlayList() {}
	PlayList(PlayList&);
	~PlayList();
	void AddMusic(Music&);
	void DellMusic(int);
	void Show();
	void search(int);
	int getId();
	string getName();
private:

	List<Music> playlist;
	static int id_creator;
	int id;
	string name;
};

