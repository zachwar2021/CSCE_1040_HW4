//
//  Zachary Warren
//  CSCE 1040
//  Homework 4
//
#include "book.h"
using namespace std;

Book::Book(int id, float c, int s, int lp, string t, string a, string isbn, string cat):Item(id,c,s,lp)
{
    title = t;
    author = a;
    ISBN = isbn;
    category = cat;
}

string Book::getTitle() {return title;}
string Book::getAuthor() {return author;}
string Book::getISBN() {return ISBN;}
string Book::getCategory() {return category;}

void Book::setTitle(string t) {title = t;}
void Book::setAutor(string a) {author = a;}
void Book::setISBN(string isbn) {ISBN = isbn;}
void Book::setCategory(string c) {category = c;}

void Book::print()

{
    Item::print();
    cout << "Book Name: " << title << endl;
    cout << "Book Author: " << author << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Category: " << category << endl;
    cout<<endl;
}