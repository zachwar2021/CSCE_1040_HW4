//
//  Zachary Warren
//  CSCE 1040
//  Homework 4
//
#include <iostream>
#include <string>
#include "libraryItem.h"
using namespace std;

class DVD : public Item
{
    private:
        string title;
        string category;
        string runTime; //or int runTime
        string releaseDate;
        string genre;
    public:
        DVD(int, float,int,int,string,string,string,string,string);
        string getTitle();
        string getCategory();
        string getRunTime();
        string getReleaseDate();
        string getGenre();

        void setTitle(string);
        void setCategory(string);
        void setRunTime(string);
        void setReleaseDate(string);
        void setGenre(string);

        void print();
};