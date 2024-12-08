#include "Music.h"

int Music::id_creator = 0;


Music::Music(Music& other)
{
	this->id = other.id;
	this->date = other.date;
	this->name = other.name;
	this->text = other.text;
}

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
bool Music::compareSuffixes( suffix& a,  suffix& b) {
     char* s1 = a.suff;
     char* s2 = b.suff;

    while (*s1 != '\0' && *s2 != '\0') 
	{
        if (*s1 < *s2) 
			return true;  
        if (*s1 > *s2) 
			return false; 
        s1++;
        s2++;
    }

    return (*s1 == '\0' && *s2 != '\0');
}

void Music::mergeSort(suffix* suffixes, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        
        mergeSort(suffixes, left, mid);
        mergeSort(suffixes, mid + 1, right);

        merge(suffixes, left, mid, right);
    }
}

void Music::merge(suffix* suffixes, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

   
    suffix* leftArray = new suffix[n1];
    suffix* rightArray = new suffix[n2];

    
    for (int i = 0; i < n1; i++)
        leftArray[i] = suffixes[left + i];
    for (int i = 0; i < n2; i++)
        rightArray[i] = suffixes[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compareSuffixes(leftArray[i], rightArray[j])) {
            suffixes[k] = leftArray[i];
            i++;
        }
        else {
            suffixes[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        suffixes[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        suffixes[k] = rightArray[j];
        j++;
        k++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

int Music::callBinarySearch(string word,int select)
{
	int n = word.size();
	char* w = new char[n+1];
	for (int i = 0; i < n; i++)
	{
		w[i] = word[i];
	}
	w[n] = '\0';
	/*suffix* Sword = new suffix[n];
	for (int i = 0; i < n; i++) {
		suffixes[i].index = i;
		suffixes[i].suff = (w + i);
	}
	*/
	n = text.size();
	if (select == 0)
		return binarySearch(0, n - 1, n, word);
	else {
		int counter = 0;
		binaryCounter(0, n - 1, n,counter, word);
		return counter;
		 
	}
		
}

int Music::binaryCounter(int left, int right, int n,int& counter, string word)
{
	int mid = left + (right - left) / 2;

	if (left > right)
		return counter;
	bool flag = true;
	char* suffix = suffixes[mid].suff;

	for (size_t i = 0; i < word.size(); i++) {

		if (suffix[i] == '\0') {
			flag = false;
			break;
		}

		if (suffix[i] != word[i]) {
			flag = false;
			break;
		}
	}

	if (flag)
		counter++;
	if (suffixes[mid].suff[0] < word[0])
	{
		binaryCounter(mid + 1, right, n,counter, word);
	}
	else
	{
		binaryCounter(left, mid - 1, n,counter, word);
	}
}

int Music::binarySearch(int left, int right,int n,string word)
{
	int mid = left + (right - left) / 2;
	
	if (left > right)
		return -1;
	bool flag = true;
	char* suffix = suffixes[mid].suff;
	
	for (size_t i = 0; i < word.size(); i++) {
		
		if (suffix[i] == '\0') {
			flag = false;
			break;
		}

		if (suffix[i] != word[i]) {
			flag = false;
			break;
		}
	}

	if (flag)
		return mid;
	
	if (suffixes[mid].suff[0]<word[0])
	{
		binarySearch(mid + 1, right,n,word);
	}
	else
	{
		binarySearch(left, mid - 1, n, word);
	}
}

int* Music::makeSuffixArray(char* text, int n) {
     
	suffixes = new suffix[n];
    for (int i = 0; i < n; i++) {
		suffixes[i].index = i;
        suffixes[i].suff = (text + i);
		/*std::cout << "Suffix " << i << ": Index = " << suffixes[i].index
			<< ", Suffix = " << suffixes[i].suff << std::endl;*/
    }

    mergeSort(suffixes, 0, n - 1);
	/*for (int i = 0; i < n; i++) {
		cout << "Suffix " << i << ": Index = " << suffixes[i].index
			<< ", Suffix = " << suffixes[i].suff << std::endl;
	}*/
    int* suffixArr = new int[n];
	for (int i = 0; i < n; i++) 
	{
		suffixArr[i] = suffixes[i].index;
		//cout << suffixArr[i];
	}
		

    suffixes; 
    return suffixArr;
}


ostream& operator<<(ostream& os, Music& music)
{
	os << "Music Name: " << endl << music.name << endl << "ID: " << music.id<< endl << "Text:" << music.getText() << endl<<"Date: "<<music.date<<endl;
	return os;
}
