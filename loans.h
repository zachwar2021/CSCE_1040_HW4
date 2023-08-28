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
#include <ctime>
#include "loan.h"
#include "patrons.h"
#include "libraryItems.h"
using namespace std;


class Loans
{
private:
    int loancount;
    typedef vector<Loan*> custtype;
    custtype loanlist;
    int nextAvaiableID = 2;
public:
    Loans() {loancount = 0; loadLoans();}
    ~Loans() {storeLoans(); cleanup();}
    int getcount();
    void inccount();
    void deccount();
    void addLoan(int,Items);
    void delLoan(int,Items,Patrons);
    void checkOverDue(Patrons&);
    void rechceck(int);
    Loan* findLonaByID(int);
    Loan* findLoan(int, int);
    Loan* findLoanByPatron(int);
    Loan* findLoanByBook(int);
    void cleanup();
    void prtlist();
    void loadLoans();
    void storeLoans();
    
    
};


