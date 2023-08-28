//
//  Zachary Warren
//  CSCE 1040
//  Homework 4
//
#include <iostream>
#include <string>
#include "libraryItem.h"
using namespace std;


class Book : public Item
{
    private:
        string title;
        string author;
        string ISBN;
        string category;
    public:
        Book(int,float,int,int,string,string,string,string);
        string getTitle();
        string getAuthor();
        string getISBN();
        string getCategory();

        void setTitle(string);
        void setAutor(string);
        void setISBN(string);
        void setCategory(string);

        void print();
};