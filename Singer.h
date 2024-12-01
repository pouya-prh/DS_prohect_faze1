#pragma once
#include "List.h"
#include "Music.h"
using namespace std;

class Singer
{
public:
	Singer() : name("unkown"), id(-1) {}
	Singer(string name);
	Singer(Singer& other);
	~Singer() { musics.clearing(); }
	string getName();
	int getId();
	void addMusic(Music);
	List<Music> getMusics();
	friend ostream& operator<<(ostream& os, const Singer& singer);
private:
	List<Music> musics;
	string name;
	int id;
	static int id_creator;
	
};





