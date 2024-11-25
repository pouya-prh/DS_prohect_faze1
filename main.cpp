#include "Singer.h"
#include "List.h"
#include <string>
#include "SparseSet.h"
#include "Music.h"




SparseSet<Singer> artists;


void Commands(string cmnd)
{
	
	if (cmnd == "adds name")
	{
		
		string name;
		cout << "what is the singer`s name? ";
		cin >> name;
		artists.insertion(name);	
	}
	else if (cmnd == "show")
	{
		artists.showAll();
	}
	else if (cmnd == "dels id")
	{
		int id = 0;
		cout << "What is the singer`s id? ";
		cin >> id;
		artists.deletation(id);
	}
}

int main()
{
	
	string cmnd = "";
	while (cmnd != "exit")
	{
	
		getline(cin, cmnd);
		Commands(cmnd);
	}
}