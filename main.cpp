#include <string>
#include "SparseSet.h"


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
	else if (cmnd == "find id")
	{
		int id;
		cout << "Enter id: ";
		cin >> id;
		int find = artists.searching(id);
		if (find >= 0)
		{
			artists.show(id);
		}
		else {
			cout << "doesnt found!" << endl;
		}

	}
	else if (cmnd == "cls")
	{
		artists.clearing();
	}
	else if (cmnd == "findm name")
	{
		string name;
		cout << "Whats the music name? ";
		cin >> name;
		artists.findMusic(name);
	}
	else if (cmnd == "delm")
	{
		int artist_id;
		int music_id;
		cout << "Whats the artist id ?";
		cin >> artist_id;
		cout << "\n Whats the music id ?";
		cin >> music_id;
		artists.delMusic(music_id, artist_id);
	}
	else if (cmnd == "addms")
	{
		string musicName, artistname, date, text;
		cout << "Whats the music name? ";
		cin >> musicName;
		cout << endl << "Whats the artist name? ";
		cin >> artistname;
		cout << endl << "date? ";
		cin >> date;
		cout << "Whats the text of music ?" << endl << ">>";
		cin.clear();
		cin.ignore();
		getline(cin, text);
		artists.addMusic(musicName, artistname, date, text);

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