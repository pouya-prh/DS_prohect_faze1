#include "Music.h"


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

int Music::getDate()
{
	return date;
}

ostream& operator<<(ostream& os, const Music& music)
{
	os << "Music Name: " << music.name << ", ID: " << music.id << "\nMusics: ";
	return os;
}
