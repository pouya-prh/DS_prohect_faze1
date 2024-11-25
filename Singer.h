#pragma once
#include "List.h"
#include "Music.h"
using namespace std;

class Singer
{
public:
	Singer() : name("unkown"), id(-1) { id_creator++; }
	Singer(string name);
	Singer(Singer& other);
	~Singer() { id_creator--; };
	string getName();
	int getId();
	void addMusic(Music);
	friend ostream& operator<<(ostream& os, const Singer& singer);
	
private:
	List<Music> musics;
	string name;
	int id;
	static int id_creator;
	
};

