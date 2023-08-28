//
//  Zachary Warren
//  CSCE 1040
//  Homework 4
//
#include "dvd.h"
using namespace std;

DVD::DVD(int id, float c, int s, int lp, string t, string cat, string rt, string rd, string g):Item(id,c,s,lp)
{
    title = t;
    category = cat;
    runTime = rt;
    releaseDate = rd;
    genre = g;
}

string DVD::getTitle() {return title;}
string DVD::getCategory() {return category;}
string DVD::getRunTime() {return runTime;}
string DVD::getReleaseDate() {return releaseDate;}
string DVD::getGenre() {return genre;}

void DVD::setTitle(string t) {title = t;}
void DVD::setCategory(string c) {category = c;}
void DVD::setRunTime(string rt) {runTime = rt;}
void DVD::setReleaseDate(string rd) {releaseDate = rd;}
void DVD::setGenre(string g) {genre = g;}

void DVD::print()
{
    Item::print();
    cout << "Title: " << title << endl;
    cout << "Category: " << category << endl;
    cout << "Genre: " << genre << endl;
    cout << "Run Time: " << runTime << endl;
    cout << "Release Date: " << releaseDate << endl;
    cout<<endl;
}