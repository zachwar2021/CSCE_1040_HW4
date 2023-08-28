//
//  Zachary Warren
//  CSCE 1040
//  Homework 4
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "patron.h"
using namespace std;

class Patrons
{
private:
    int patroncount;

    typedef vector<Patron*> custtype;
    custtype patronlist;
    vector<Patron>::iterator it;
    int nextAvaiableID = 100001;
public:
    Patrons() {patroncount = 0; loadPatrons();}
    ~Patrons() {storePatrons(); cleanup();}
    int getcount();

    void inccount();
    void deccount();

    void addPatron(string);
    void deletPatron(int);
    Patron* findPatronByID(int);
    Patron* findPatronByName(string);
    void cleanup();
    void prtlist();
    void loadPatrons();
    void storePatrons();
};
