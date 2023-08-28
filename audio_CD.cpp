//
//  Zachary Warren
//  CSCE 1040
//  Homework 4
//
#include "audio_CD.h"
using namespace std;

CD::CD(int id,float c, int s, int lp, string a, string t, int nt,string rd,string g):Item(id,c,s,lp)
{
    artist = a;
    title = t;
    number_of_tracks = nt;
    release_date = rd;
    genre = g;
    
}

string CD::getArtist() {return artist;}
string CD::getTitle() {return title;}
int CD::getNumOfTracks() {return number_of_tracks;}
string CD::getReleaseDate() {return release_date;}
string CD::getGenre() {return genre;}

void CD::setArtist(string a) {artist = a;}
void CD::setTitle(string t) {title = t;}
void CD::setNumOfTracks(int nt) {number_of_tracks = nt;}
void CD::setReleaseDate(string rd) {release_date = rd;}
void CD::setGenre(string g) {genre = g;}

void CD::print()
{
    Item::print();
    cout << "Title: "  << title << endl;
    cout << "Artist: " << artist << endl;
    cout << "Genre: " << genre << endl;
    cout << "Number of Tracks: " << number_of_tracks << endl;
    cout << "Release Date: " << release_date << endl;   
    cout<<endl; 
}
