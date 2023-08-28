//
//  Zachary Warren
//  CSCE 1040
//  Homework 4
//
#include "libraryItem.h"
using namespace std;

Item::Item (int id, float c, int s, int lp) 
{
    itemID = id; 
    cost = c; 
    status = s; 
    loan_period = lp;
}

Item::~Item () {}
int Item::getID() {return itemID;}
float Item::getCost() {return cost;}
int Item::getStatus() {return status;}
int Item::getLoan_period() {return loan_period;}

void Item::setCost(int c) {cost = c;}
void Item::setStatus(int s) {status = s;}
void Item::setLoan_period(int lp) {loan_period = lp;}

void Item::print()
{
    if(status == 0)
    {
        cout << "Avaliable" << endl;
        cout << "Loan Period: " << loan_period << endl;
        cout << "Price: $" << cost <<endl;
        cout << "ID: " << itemID << endl;
    }
    else if(status == 1)
    {
        cout << "Checked Out" << endl;
        cout << "Loan Period: " << loan_period << endl;
        cout << "Price: $" << cost <<endl;
        cout << "ID: " << itemID << endl;
    }
    else if(status == 2)
    {
        cout << "Lost" << endl;
        cout << "Loan Period: " << loan_period << endl;
        cout << "Price: $" << cost <<endl;
        cout << "ID: " << itemID << endl;
    }
}