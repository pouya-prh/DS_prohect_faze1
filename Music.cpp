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

bool Music::operator>(Music& music)
{
	int day, mounth, year;
	parseDate(date, day, mounth, year);
	int day2, mounth2, year2;
	parseDate(music.date, day2, mounth2, year2);
	if (year < year2) {
		return true;
	}
	else if (year == year2 && mounth < mounth2)
	{
		return true;
	}
	else if (year == year2 && mounth == mounth2 && day < day2)
	{
		return true;
	}	
	return false;
}

void Music::parseDate(string& date, int& day, int& month, int& year)
{
	int index = 0;
	day = 0;
	month = 0;
	year = 0;


	while (date[index] != '/') {
		day = day * 10 + (date[index] - '0');
		++index;
	}
	++index; 

	
	while (date[index] != '/') {
		month = month * 10 + (date[index] - '0');
		++index;
	}
	++index; 

	
	while (index < date.length()) {
		year = year * 10 + (date[index] - '0');
		++index;
	}
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
