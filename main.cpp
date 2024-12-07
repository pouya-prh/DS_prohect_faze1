#include <string>
#include "SparseSet.h"
#include "PlayList.h"
#include "queue.h"


void Commands()
{
	SparseSet<Singer> artists;
	List<PlayList> playlists;
	Tree<PlayList> playlistsTree;
	List<Music> musics;
	queue<PlayList> queueOfPlaylists;
	string cmnd = "";
	while (true)
	{

		getline(cin, cmnd);


		if (cmnd == "exit")
		{
			exit(0);
		}
		else if (cmnd == "adds name")
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
			playlists.clearing();
			musics.clearing();
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
			cout << "\nWhats the music id ?";
			cin >> music_id;
			for (auto& it : playlistsTree)
			{
				it.DellMusic(music_id);
			}
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
			Music music(text, musicName, date);
			artists.addMusic(artistname, music);
			musics.push_back(music);

		}
		else if (cmnd == "search word")
		{
			int artist_id, music_id;
			cout << "Whats the artist id? ";
			cin >> artist_id;
			cout << "Whats the music id? ";
			cin >> music_id;
			string word;
			cout << "Whats the pattern? ";
			cin >> word;
			artists.At(artist_id).find(music_id).callBinarySearch(word);
		}
		else if (cmnd == "addp")
		{
			string name;
			cout << "Whats the playlist name? ";
			cin >> name;
			PlayList playlist(name);
			Node<PlayList> node(playlist);
			//	playlists.push_back(playlist);
			playlistsTree.Add(node);

		}
		else if (cmnd == "addmp")
		{
			cout << "Whats the music id? ";
			int music_id;
			cin >> music_id;
			cout << "Whats the playlist id? ";
			int playlist_id;
			cin >> playlist_id;
			Music music = musics.search(music_id);
			//playlists.search(playlist_id).AddMusic(music);
			playlistsTree.BinarySearch(playlist_id).value.AddMusic(music);
			cout << music.getName() << " successfully added to " << playlistsTree.BinarySearch(playlist_id).value.getName() << endl;
		}
		else if (cmnd == "searchp")
		{
			cout << "Whats the playlist id? ";
			int id;
			cin >> id;
			playlistsTree.BinarySearch(id).value.Show();

		}
		else if (cmnd == "searchm")
		{
			cout << "Whats the play list id? ";
			int playlist_id;
			cin >> playlist_id;
			cout << "What the music id? ";
			int music_id;
			cin >> music_id;
			playlistsTree.BinarySearch(playlist_id).value.search(music_id);
		}
		else if (cmnd == "delmp")
		{
			cout << "Whats the playlist id? ";
			int playlist_id;
			cin >> playlist_id;
			cout << "Whats the music id? ";
			int music_id;
			cin >> music_id;

			playlistsTree.BinarySearch(playlist_id).value.DellMusic(music_id);
		}
		else if (cmnd == "addqp")
		{
			cout << "Whats the playlits id? ";
			int playlist_id;
			cin >> playlist_id;
			string playlist_name = playlistsTree.BinarySearch(playlist_id).value.getName();
			queueOfPlaylists.push_back(playlistsTree.BinarySearch(playlist_id).value);
			cout << playlist_name << " added to queue successfully" << endl;
		}
		else if (cmnd == "pop")
		{
			cout  << "first item pop from queue successfully" << endl;
		}

	}
	

}

int main()
{
	Commands();
	
}


//...ما که میکنیم خب با درد تلاش ولی هیِ! روزگار نامرد یواش