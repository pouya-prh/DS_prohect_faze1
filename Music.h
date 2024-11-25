#pragma once
#include <iostream>

using namespace std;

class Music
{
public:
	Music(string text, string name, int date,int id) : name(name), text(text), date(date) ,id (id) {}
	Music(Music& other);
	string getText();
	int getDate();
	friend ostream& operator<<(ostream& os, const Music& music);
	
private:
	string name;
	string text;
	int date;
	int id;
};

