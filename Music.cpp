#include "Music.h"

int Music::id_creator = 0;


Music::Music(Music& other)
{
	this->id = other.id;
	this->date = other.date;
	this->name = other.name;
}

string Music::getText()
{
	string t;
	for (int i = 0; i < 30; i++)
	{
		t += text[i];
	}
	t += " ...";
	return t;
}

string Music::getDate()
{
	return date;
}

string Music::getName()
{
	return name;
}

int Music::getId()
{
	return id;
}

ostream& operator<<(ostream& os, Music& music)
{
	os << "Music Name: " << endl << music.name << endl << "ID: " << music.id << "Text:" << music.text << endl;
	return os;
}
