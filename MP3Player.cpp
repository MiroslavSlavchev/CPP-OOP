// MP3Player.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <random>

using namespace System;
using namespace std;

bool play_song = true;
bool dont_play_song = false;

class Song
{
private:
	char* name;
	float length;
	char* artist;
public:
	Song();
	Song(char* name, float length);
	Song(char* name, float length, char* artist);
	char* getName() const;
	float getLength() const;
	char* getArtist() const; 
};
Song::Song(char* name, float length)
{
	this->name = name;
	this->length=length;
}
Song::Song(char* name, float length, char* artist)
{
	this->name = name;
	this->length = length;
	this->artist = artist;
}
char* Song::getName() const 
{
	return name;
}
float Song::getLength() const
{
	return length;
}
char* Song::getArtist() const
{
	return artist;
}

class Album
{
private:
	Song* songs;
	char* name;
public:
	
	void addSong(const Song); 
	void removeSong(const char* name); 
	void removeSong(const int index);
	Song* get_playlist();
	Album();
	Album(char* name);
	Album(char* name, Song song);
	Album(char* name, Song* song);
};
Song * Album::get_playlist()
{
	for (int i = 0; i < sizeof(songs); i++)
	{
		return &songs[i];
	}
}
void Album::addSong(const Song s)
{
	/*s.getArtist();
	s.getLength();
	s.getArtist();*/
	songs[sizeof(songs)] = s;
	songs++;
}
void Album::removeSong(const char*name)
{
	delete[]name;
}
void Album::removeSong(int index)
{
	for (index = 0; index < sizeof(songs); index++)
	{
		delete[index]songs;
	}
}
Album::Album(char*name)
{
	this->name = name;
}
Album::Album(char*name, Song song)
{
	this->name = name;
	for (int i = 0; i < sizeof(songs); i++)
	{
		song = songs[i];
	}
}
Album::Album(char*name, Song*song)
{
	this->name = name;
	this->songs = song;
}

class MP3Player
{
private:
	Song songs; 
	Album album;
	Song*playlist;
	Album* albums;
	int batteryPower; 
public:
	MP3Player();
	MP3Player(Song* songs);
	MP3Player(Album* albums);
	MP3Player(Song* songs, Album* albums);

	int song_counter();
	void addSong(Song);
	void addSongs(Song* songs);
	void addAlbum(Album album);
	void addAlbums(Album* Albums);
	void removeAlbum(char* name);


	void charge();
	void stopCharge();
	void play(bool shuffle);

	bool pause();
	Song previous();
	Song next();
};

MP3Player::MP3Player(Song*songs)
{
	for (int i = 0; i < sizeof(songs); i++)
	{
		songs[i].getArtist();
		songs[i].getLength();
		songs[i].getName();
	}
}
MP3Player::MP3Player(Album* albums)
{
	for (int i = 0; i < sizeof(albums); i++)
	{
		 albums[i].get_playlist();
	}
}
MP3Player::MP3Player(Song* songs, Album* albums)
{
	for (int i = 0; i < sizeof(songs); i++)
	{
		songs[i].getArtist();
		songs[i].getLength();
		songs[i].getName();
	}
	for (int i = 0; i < sizeof(albums); i++)
	{
		(albums[i]);
	}
}
int MP3Player::song_counter()
{
	int count = 0;
	for (int i = 0; i < sizeof(songs); i++)
	{
		return count++;
	}
}
void MP3Player::addSong(Song s)
{
	s.getName();
	s.getArtist();
	s.getLength();
}
void MP3Player::addSongs(Song*songs)
{
	for (int i = 0; i < sizeof(songs); i++)
	{
		addSong(songs[i]);
	}
}
void MP3Player::addAlbum(Album album)
{
	albums[sizeof(albums)] = album;
	albums++;
}
void MP3Player::removeAlbum(char*name)
{
	delete[]name;
}

void MP3Player::charge()
{
	do
	{
		batteryPower++;
	} while (batteryPower < 0 || batteryPower > 100);
	
}
void MP3Player::stopCharge()
{
	if (batteryPower == 100) cout << "Battery charged!100%" << endl;
	else cout << "Battery Charging..." << endl;
}
void MP3Player::play(bool shuffle)
{
	if (batteryPower < 15)
	{
		cout << "Battery is running low,please charge!" << endl;
	}
	int minus_song = songs.getLength() - (songs.getLength() / 10);
	batteryPower = batteryPower - minus_song;
	if (charge)
	{
		dont_play_song;
		cout << "You can't play song, while battery's charging! " << endl;
	}
	if (song_counter == 0)
	{
		dont_play_song;
		cout << "You don't have any songs" << endl;
	}
	if (shuffle)
	{
		shuffle =rand() % sizeof(playlist);
	}
	else
	{
		int n = sizeof(playlist);
		playlist[n - 1];
	}
}
bool MP3Player::pause()
{
	
	if (pause() == true)
	{
		return songs.getLength();
	}
	else return songs.getLength++;
}
Song MP3Player::previous()
{
	for (int i = 0; i < sizeof(playlist); i++)
	{
		if (i = 0)
		{
			return playlist[sizeof(songs) - 1];
			cout << "Now you are listening the last song in the playlist:" << playlist[sizeof(songs)-1].getName() << "." << endl;
		}
		else {
			return playlist[i + 1];
			cout << "Now you are listening the previous song in the playlist:" << playlist[i].getName() << "." << endl;
		}
	}
}
Song MP3Player::next()
{
	for (int i = 0; i < sizeof(playlist); i++)
	{
		if (i = sizeof(playlist) - 1)
		{
			return playlist[0];
			cout << "Now you are listening the first song in the playlist:" << playlist[0].getName() << "." << endl;
		}
		else {
			return playlist[i + 1];
			cout << "Now you are listening the next song in the playlist:" << playlist[i].getName() << "." << endl;
		}
	}
}

int main()
{

	
}
