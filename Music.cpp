#include "Music.h"

int Music::id_creator = 0;


//Music::Music(Music& other)
//{
//	this->id = other.id;
//	this->date = other.date;
//	this->name = other.name;
//}

string Music::getText()
{
	string t;
	if (text.length() > 30)
	{
		for (int i = 0; i < 30; i++)
		{
			t += text[i];
		}
	}
	else
	{
		for (int i = 0; i < text.length(); i++)
		{
			t += text[i];
		}
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

Music& Music::operator=(Music& music)
{
	this->name = music.name;
	this->date = music.date;
	this->text = music.text;
	this->id = music.id;
	return *this;
}

int* Music::buildSuffixArray(const string& text)
{
	return nullptr;
}

ostream& operator<<(ostream& os, Music& music)
{
	os << "Music Name: " << endl << music.name << endl << "ID: " << music.id<< endl << "Text:" << music.getText() << endl;
	return os;
}
