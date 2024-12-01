#pragma once
#include <iostream>

using namespace std;

class Music
{
public:
	Music(string text, string name, string date) :text(text), name(name), date(date), id(id_creator++) {}
	Music() {}
	//Music(Music& other);
	string getText();
	string getDate();
	string getName();
	int getId();
	friend ostream& operator<<(ostream&, Music&);
	Music& operator = (Music&);
	bool operator > (Music&);
	void parseDate (string& date, int& day, int& month, int& year);
	int* buildSuffixArray(const string& text);
	
private:
	string name;
	string text;
	string date;
	int id;
	static int id_creator;
};

