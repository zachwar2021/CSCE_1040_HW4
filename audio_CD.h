//
//  Zachary Warren
//  CSCE 1040
//  Homework 4
//
#include <iostream>
#include <string>
#include "libraryItem.h"
using namespace std;


class CD: public Item
{
    private:
        string artist;
        string title;
        int number_of_tracks;
        string release_date; //or string or tm
        string genre;
    public:
        CD(int,float,int,int,string,string,int,string,string);
        string getArtist();
        string getTitle();
        int getNumOfTracks();
        string getReleaseDate();
        string getGenre();

        void setArtist(string);
        void setTitle(string);
        void setNumOfTracks(int);
        void setReleaseDate(string);
        void setGenre(string);
        
        void print();
};