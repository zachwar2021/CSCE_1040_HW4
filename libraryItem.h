//
//  Zachary Warren
//  CSCE 1040
//  Homework 4
//
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <typeinfo>
using namespace std;

class Item
{
    private:
        int itemID;
        float cost;
        int status; //(0=in,1=out,2=lost)
        int loan_period;
    public:
        Item(int,float,int,int);
        virtual ~Item();

        int getID();
        float getCost();
        int getStatus();
        int getLoan_period();

        void setCost(int);
        void setStatus(int);
        void setLoan_period(int);
        
        virtual void print();
};

#endif