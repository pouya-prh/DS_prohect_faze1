#include "PlayList.h"

int PlayList::id_creator = 0;

PlayList::PlayList(string name)
{
	this->id = id_creator++;
	this->name = name;
	cout << "playlist seccessfully created\n";
}

PlayList::PlayList(PlayList& playlist)
{
	this->id = playlist.id;
	this->name = playlist.name;
	/*this->sortedTree = playlist.sortedTree;*/
	this->playlist = playlist.playlist;
	id_creator++;
}

PlayList::~PlayList()
{
	//playlist.clearing();
	id_creator--;
}

void PlayList::AddMusic(Music& music)
{
	playlist.push_back(music);
	//sortedTree.Add(music);
}

void PlayList::DellMusic(int music_id)
{
	playlist.del(music_id);
	//sortedTree.Dell(music_id);
}

void PlayList::Show()
{
	cout<<"playlist name: " << name << endl;
	cout << "musics: \n\n\n";
	playlist.display();
}

void PlayList::search(int music_id)
{
	//cout << sortedTree.BinarySearch(music_id).value;
	cout << playlist.search(music_id);

}

void PlayList::binarySearch(int id)
{
	//cout<<sortedTree.BinarySearch(id).value;
	
}

int PlayList::getId()
{
	return id;
}

string PlayList::getName()
{
	return this->name;
}

