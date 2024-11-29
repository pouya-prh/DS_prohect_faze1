#include "Singer.h"

int Singer::id_creator = 0;

Singer::Singer(string name)
{
	this->id = id_creator++;
	this->name = name;
}

Singer::Singer(Singer& other)
{
	this->name = other.getName();
	this->id = other.getId();
	/*if (this->id == -1)
	{
		id = id_creator++;
	}*/
}

string Singer::getName()
{
	return this->name;
}

int Singer::getId()
{
	return id;
}

void Singer::addMusic(Music music)
{
	musics.push_back(music);
}

List<Music> Singer::getMusics()
{
	return this->musics;
}


ostream& operator<<(ostream& os, const Singer& singer)
{
	os << "Singer Name: " << singer.name << ", ID: " << singer.id;
	return os;
	
}
