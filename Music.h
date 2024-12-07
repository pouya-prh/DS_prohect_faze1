#pragma once
#include <iostream>
using namespace std;



typedef struct suffix {
	int index;
	char* suff;
	
}suffix;


class Music
{
public:
	Music(string text, string name, string date) :text(text), name(name), date(date), id(id_creator++)
	{
		int n = text.size();
		char* txt = new char[n + 1];
		int c = 0;
		/*for (int i = 0; i < n; i++)
		{
			if (text[i] == ' ')
			{
				c++;
				continue;	
			}
			txt[i - c] = text[i];
		}
		txt[n - c] = '\0';*/
		for (int i = 0; i < n; i++)
		{
			txt[i] = text[i];
		}
		txt[n] = '\0';
		makeSuffixArray(txt, n - c);
	}
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
	int* makeSuffixArray(char* , int);
	bool compareSuffixes(suffix&, suffix&);
	void mergeSort(suffix*, int, int);
	void merge(suffix* , int , int , int );
	int binarySearch(int,int, int,string);
	int callBinarySearch(string);
	
private:
	string name;
	string text;
	string date;
	suffix* suffixes;
	int* suffixArray;
	int id;
	static int id_creator;
};
