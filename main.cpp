//
//  Zachary Warren
//  CSCE 1040
//  Homework 4
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <string>
#include <ctime>

//#include "books.h"
//#include "patrons.h"
#include "loans.h"

using namespace std;

Patrons pats;
Items inventory;
Loans exchanges;


int main(int argc, const char * argv[]) {
    //sets the seconds sence Januart 1,1970 to current time
    time_t currentTime = time(0);
    
    //initalizing and declairing menu variables
    int choice = -1;
    int subChoice = -1;
    int id = 0;

    //checks if any loans are overdue and changes the balance of patrons accordingly
    exchanges.checkOverDue(pats); 
    //loops the menu and choices untill user says otherwise
    while (choice != 0)
    {
        if(choice != -2)
        {
            //menu with list of choices for the user
            cout<<"What do you want to do?"<<endl;
            cout<<"1 - Add/Modify/Delete Item"<<endl;
            cout<<"2 - Add/Modify/Delete Patron"<<endl;
            cout<<"3 - Add/Modify/Delete Loan"<<endl;
            cout<<"4 - Find Item"<<endl;
            cout<<"5 - Find Patron"<<endl;
            cout<<"6 - Find Loan"<<endl;
            cout<<"7 - print Items"<<endl;
            cout<<"8 - print Patrons"<<endl;
            cout<<"9 - print Loans"<<endl;
            cout<<"0 - Quit"<<endl;
            cout<<"Enter your selection: ";
            scanf ("%d%*c", &choice);
        }
        
        switch(choice)
        {  
            //this case is to end the program and skip looking through all of the other cases 
            case 0: break;
            //case 1 is for adding, modifying, and deleting a chosen book
            case 1:
            {
                //this is the submenu for choice 1
                cout<<endl;
                cout<<"1 - Add Item"<<endl;
                cout<<"2 - Modify Item"<<endl;
                cout<<"3 - Delete Item"<<endl;
                cout<<"Enter your selection: ";
                cin>>subChoice;cout<<endl;

                switch(subChoice)    
                {
                    //this is the case for adding a book to the collection
                    case 1: 
                    {
                        inventory.addItem();  
                        choice = -1;
                        subChoice = -1;
                        break;
                    }
                    //this is the case for modifting a chosen book
                    case 2: 
                    {
                        //this is another submenu of the submenu stated above
                        Item* temp;
                        int sub2Choice;
                        int sub3Choice;
                        cout<<"What do you want to modify?"<<endl;
                        cout<<"1 - Book"<<endl;
                        cout<<"2 - CD"<<endl;
                        cout<<"3 - DVD"<<endl;
                        cout<<"Enter your selection: ";
                        cin>>sub2Choice;
                        cout<<endl;
                        //this askes the user for the book they want to modify the price of
                        //then modifys the price based off of the user input
                        if(sub2Choice == 1)
                        {
                            if((inventory.numberOfSpecificItem("Book")) <= 0)
                            {
                                cout<<"There are no Book's in the inventory"<<endl;
                                cout<<endl;
                                break;
                            }
                            int book_ID;
                            cout<<"How do you want to change the Book?"<<endl;
                            cout<<"1 - Title"<<endl;
                            cout<<"2 - Author"<<endl;
                            cout<<"3 - ISBN"<<endl;
                            cout<<"4 - category"<<endl;
                            cout<<"5 - Price"<<endl;
                            cout<<"6 - Status"<<endl;
                            cout<<"7 - Loan Period"<<endl;
                            cout<<"Enter your selection: ";
                            cin>>sub3Choice;
                            switch (sub3Choice)
                            {
                                case 1:
                                {
                                    string newTitle;
                                    int modID;
                                    Book *temp;
                                    cout<<"Enter the Book's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = dynamic_cast<Book*>(inventory.findItem(modID));
                                    cout<<"Enter the new Title: ";
                                    getline(cin,newTitle);
                                    temp->setTitle(newTitle);
                                    break;
                                }
                                case 2:
                                {
                                    string newAuthor;
                                    int modID;
                                    Book *temp;
                                    cout<<"Enter the Book's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = dynamic_cast<Book*>(inventory.findItem(modID));
                                    cout<<"Enter the new Author Name: ";
                                    getline(cin,newAuthor);
                                    temp->setAutor(newAuthor);
                                    break;
                                }
                                case 3:
                                {
                                    string newISBN;
                                    int modID;
                                    Book *temp;
                                    cout<<"Enter the Book's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = dynamic_cast<Book*>(inventory.findItem(modID));
                                    cout<<"Enter the new ISBN: ";
                                    getline(cin,newISBN);
                                    temp->setISBN(newISBN);
                                    break;
                                }
                                case 4:
                                {
                                    string newCategory;
                                    int modID;
                                    Book *temp;
                                    cout<<"Enter the Book's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = dynamic_cast<Book*>(inventory.findItem(modID));
                                    cout<<"Enter the new Category: ";
                                    getline(cin,newCategory);
                                    temp->setCategory(newCategory);
                                    break;
                                }
                                case 5:
                                {
                                    int newPrice;
                                    int modID;
                                    Item *temp;
                                    cout<<"Enter the Book's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = inventory.findItem(modID);
                                    cout<<"Enter the new Price: ";
                                    cin>>newPrice;
                                    temp->setCost(newPrice);
                                    break;
                                }
                                case 6:
                                {
                                    int newStatus;
                                    int modID;
                                    Item *temp;
                                    cout<<"Enter the Book's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = inventory.findItem(modID);
                                    cout << "0 - in stock" << endl;
                                    cout << "1 - checked out" << endl;
                                    cout << "2 - lost" << endl;
                                    cout<<"Enter the new Status: ";
                                    cin>>newStatus;
                                    temp->setStatus(newStatus);
                                    break;
                                }
                                case 7:
                                {
                                    int newLoan_period;
                                    int modID;
                                    Item *temp;
                                    cout<<"Enter the Book's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = inventory.findItem(modID);
                                    cout<<"Enter the new Loan Period: ";
                                    cin>>newLoan_period;
                                    temp->setLoan_period(newLoan_period);
                                    break;
                                }
                            }
                            
                            
                            
                            
                            /*
                            cout<<"Enter book ID";
                            cin>>book_ID;
                            temp = inventory.findItem(book_ID);
                            float newPrice;
                            cout<<"What is the new price?"<<endl;
                            cin >> newPrice;*/
                            //temp->setPrice(newPrice);
                        }
                        //this ask the user for the book they want to modift the status of 
                        //then modifys the status based off of a menu with 3 choices and changes accordingly
                        else if(sub2Choice == 2)
                        {
                            if((inventory.numberOfSpecificItem("CD")) <= 0)
                            {
                                cout<<"There are no CD's in the inventory"<<endl;
                                cout<<endl;
                                break;
                            }
                            cout<<"How do you want to change the CD?"<<endl;
                            cout<<"1 - Author"<<endl;
                            cout<<"2 - Title"<<endl;
                            cout<<"3 - Number of Tracks"<<endl;
                            cout<<"4 - Release Date"<<endl;
                            cout<<"5 - Genre"<<endl;
                            cout<<"6 - Price"<<endl;
                            cout<<"7 - Status"<<endl;
                            cout<<"8 - Loan Period"<<endl;
                            cout<<"Enter your selection: ";
                            cin>>sub3Choice;cin.ignore();
                            switch (sub3Choice)
                            {
                                case 1:
                                {
                                    string newArtist;
                                    int modID;
                                    CD *temp;
                                    cout<<"Enter the CD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = dynamic_cast<CD*>(inventory.findItem(modID));
                                    cout<<"Enter the new Author: ";
                                    getline(cin,newArtist);
                                    temp->setArtist(newArtist);
                                    break;
                                }
                                case 2:
                                {
                                    string newTitle;
                                    int modID;
                                    CD *temp;
                                    cout<<"Enter the CD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = dynamic_cast<CD*>(inventory.findItem(modID));
                                    cout<<"Enter the new Title:  ";
                                    getline(cin,newTitle);
                                    temp->setTitle(newTitle);
                                    break;
                                }
                                case 3:
                                {
                                    int newNum;
                                    int modID;
                                    CD *temp;
                                    cout<<"Enter the CD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = dynamic_cast<CD*>(inventory.findItem(modID));
                                    cout<<"Enter the new Number of Tracks: ";
                                    cin>>newNum;
                                    temp->setNumOfTracks(newNum);
                                    break;
                                }
                                case 4:
                                {
                                    string newDate;
                                    int modID;
                                    CD *temp;
                                    cout<<"Enter the CD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = dynamic_cast<CD*>(inventory.findItem(modID));
                                    cout<<"Enter the new Release Date:  ";
                                    getline(cin,newDate);
                                    temp->setReleaseDate(newDate);
                                    break;
                                }
                                case 5:
                                {
                                    string newGenre;
                                    int modID;
                                    CD *temp;
                                    cout<<"Enter the CD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = dynamic_cast<CD*>(inventory.findItem(modID));
                                    cout<<"Enter the new Genre: ";
                                    getline(cin,newGenre);
                                    temp->setGenre(newGenre);
                                    break;
                                }
                                case 6:
                                {
                                    int newPrice;
                                    int modID;
                                    Item *temp;
                                    cout<<"Enter the CD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = inventory.findItem(modID);
                                    cout<<"Enter the new Price: ";
                                    cin>>newPrice;
                                    temp->setCost(newPrice);
                                    break;
                                }
                                case 7:
                                {
                                    int newStatus;
                                    int modID;
                                    Item *temp;
                                    cout<<"Enter the CD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = inventory.findItem(modID);
                                    cout << "0 - in stock" << endl;
                                    cout << "1 - checked out" << endl;
                                    cout << "2 - lost" << endl;
                                    cout<<"Enter the new Status: ";
                                    cin>>newStatus;
                                    temp->setStatus(newStatus);
                                    break;
                                }
                                case 8:
                                {
                                    int newLoan_period;
                                    int modID;
                                    Item *temp;
                                    cout<<"Enter the CD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = inventory.findItem(modID);
                                    cout<<"Enter the new Loan Period: ";
                                    cin>>newLoan_period;
                                    temp->setLoan_period(newLoan_period);
                                    break;
                                }
                            }
                            /*
                            int iD;
                            int newStatus;
                            cout<<"Enter book ID" <<endl;
                            cin>>iD;
                            temp = inventory.findItem(iD); 
                            cout<<"What is the new status?"<<endl;
                            cout<<"0 - avaiable"<<endl;
                            cout<<"1 - checked out"<<endl;
                            cout<<"2 - being Repaired"<<endl;
                            cout<<"3 - lost"<<endl;
                            cin>>newStatus;*/
                            //temp->setCurrentStatus(newStatus);

                        }
                        else if (sub2Choice == 3)
                        {
                            if((inventory.numberOfSpecificItem("DVD")) <= 0)
                            {
                                cout<<"There are no DVD's in the inventory"<<endl;
                                cout<<endl;
                                break;
                            }
                            int book_ID;
                            cout<<"How do you want to change the DVD?"<<endl;
                            cout<<"1 - Title"<<endl;
                            cout<<"2 - Category"<<endl;
                            cout<<"3 - Run Time"<<endl;
                            cout<<"4 - Release Date"<<endl;
                            cout<<"5 - Genre"<<endl;
                            cout<<"6 - Price"<<endl;
                            cout<<"7 - Status"<<endl;
                            cout<<"8 - Loan Period"<<endl;
                            cout<<"Enter your selection: ";
                            cin>>sub3Choice;
                            switch (sub3Choice)
                            {
                                case 1:
                                {
                                    string newTitle;
                                    int modID;
                                    DVD *temp;
                                    cout<<"Enter the DVD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = dynamic_cast<DVD*>(inventory.findItem(modID));
                                    cout<<"Enter the new Title:  ";
                                    getline(cin,newTitle);
                                    temp->setTitle(newTitle);
                                    break;
                                }
                                case 2:
                                {
                                    string newCategory;
                                    int modID;
                                    DVD *temp;
                                    cout<<"Enter the DVD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = dynamic_cast<DVD*>(inventory.findItem(modID));
                                    cout<<"Enter the new Category: ";
                                    getline(cin,newCategory);
                                    temp->setCategory(newCategory);
                                    break;
                                }
                                case 3:
                                {
                                    string newRunTime;
                                    int modID;
                                    DVD *temp;
                                    cout<<"Enter the DVD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = dynamic_cast<DVD*>(inventory.findItem(modID));
                                    cout<<"Enter the new Run Time: ";
                                    getline(cin,newRunTime);
                                    temp->setRunTime(newRunTime);
                                    break;
                                }
                                case 4:
                                {
                                    string newDate;
                                    int modID;
                                    CD *temp;
                                    cout<<"Enter the DVD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = dynamic_cast<CD*>(inventory.findItem(modID));
                                    cout<<"Enter the new Release Date:  ";
                                    getline(cin,newDate);
                                    temp->setReleaseDate(newDate);
                                    break;
                                }
                                case 5:
                                {
                                    string newGenre;
                                    int modID;
                                    DVD *temp;
                                    cout<<"Enter the DVD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = dynamic_cast<DVD*>(inventory.findItem(modID));
                                    cout<<"Enter the new Genre: ";
                                    getline(cin,newGenre);
                                    temp->setGenre(newGenre);
                                    break;
                                }
                                case 6:
                                {
                                    int newPrice;
                                    int modID;
                                    Item *temp;
                                    cout<<"Enter the DVD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = inventory.findItem(modID);
                                    cout<<"Enter the new Price: ";
                                    cin>>newPrice;
                                    temp->setCost(newPrice);
                                    break;
                                }
                                case 7:
                                {
                                    int newStatus;
                                    int modID;
                                    Item *temp;
                                    cout<<"Enter the DVD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = inventory.findItem(modID);
                                    cout << "0 - in stock" << endl;
                                    cout << "1 - checked out" << endl;
                                    cout << "2 - lost" << endl;
                                    cout<<"Enter the new Status: ";
                                    cin>>newStatus;
                                    temp->setStatus(newStatus);
                                    break;
                                }
                                case 8:
                                {
                                    int newLoan_period;
                                    int modID;
                                    Item *temp;
                                    cout<<"Enter the DVD's ID: ";
                                    cin>>modID;cin.ignore();
                                    temp = inventory.findItem(modID);
                                    cout<<"Enter the new Loan Period: ";
                                    cin>>newLoan_period;
                                    temp->setLoan_period(newLoan_period);
                                    break;
                                }
                            }
                        }
                        //this is if they enter an incorrect choice and it sends them back to the menu
                        else
                        {
                            choice = -1;
                            sub2Choice = -1;
                        }
                        break;
                    }
                    //this is for finding the book ID or book ISBN
                    //the case asks the user for the book title and author name then prints out the ID and ISBN
                    /*case 3: 
                    {
                        string the_title;
                        string the_name;
                        Item *foundBook;
                        cin.ignore();
                        cout<<"What is the Book Title?"<<endl;
                        getline(cin,the_title);
                        cout<<"What is the Author Name?"<<endl;
                        getline(cin,the_name);
                        //foundBook = inventory.findID(the_title, the_name);
                        cout<<endl;
                        /*
                        cout<<"Book ID: "<<foundBook->getID()<<endl;
                        cout<<"Book ISBN: "<<foundBook->getISBN()<<endl;
                        cout<<endl;
                        
                        break;
                    }*/
                    //This case delets a book based off of the user input
                    //all other books keep ther original id
                    case 3: 
                    {
                        int id;
                        cout<<"Please enter the ID of the Item: ";
                        cin>>id;
                        inventory.delItem(id);
                        break;
                    }
                    cout<<endl;
                }
                break;
            }
            //case 2 is for adding, modifying, and deleting a chosen patron
            case 2:
            {
                //this is the submenu for choice 2
                cout<<endl;
                cout<<"1 - Add Patron"<<endl;
                cout<<"2 - Modify Patron"<<endl;
                cout<<"3 - Find Patron ID"<<endl;
                cout<<"4 - Delete Patron"<<endl;
                cout<<"Enter your selection: ";
                cin>>subChoice;
                switch(subChoice)
                {
                    //this case adds a patron to the collection of patron 
                    //the patron is added with the input of there name
                    case 1: 
                    {
                        string pat_name;
                        cin.ignore();
                        cout<<"What is the patrons name?"<<endl;
                        getline(cin,pat_name);
                        pats.addPatron(pat_name);
                        break;
                    }
                    //this case is if the user mis typed a patrons name and would like to correct it
                    case 2: 
                    {
                        char sub2Choice;
                        cout<<"Whould you like to modify there name? y/n"<<endl;
                        cin>>sub2Choice;
                        //this is if they would like to correct a patrons name
                        if(sub2Choice == 'y')
                        {
                            Patron* temp;
                            int name_ID;
                            cout<<"Whos name would you like to change?"<<endl;
                            cout<<"Enter ID: ";
                            cin>>name_ID;
                            temp = pats.findPatronByID(name_ID);
                            string newName;
                            cin.ignore();
                            cout<<"What is the new name?"<<endl;
                            getline(cin, newName);
                            temp->setName(newName);
                        }
                        //this is to take them back to the original menu if they input no
                        else if(sub2Choice == 'n')
                        {
                            choice = -1;
                            sub2Choice = -1;
                        }
                        //this takes them back to the submenu if they inputed a wrong input
                        else
                        {
                            choice = -2;
                            break;
                        }
                        break;
                    }
                    //this case is to find a patrons id based off of thier name
                    case 3: 
                    {
                        string name;
                        Patron *foundPatron;
                        cin.ignore();
                        cout<<"Enter Patrons name: "<<endl;
                        getline(cin, name);
                        cout<<name<<endl;
                        foundPatron = pats.findPatronByName(name);
                        if(foundPatron == NULL)
                        {
                        cout<<"Nothing found"<<endl;
                        break;
                        }
                        cout<<"ID: "<<foundPatron->getID()<<endl;
                        break;
                    }
                    //this case delets a patron while not modifying any other patrons id
                    case 4: 
                    {
                        int id;
                        cout<<"Please enter the ID of the Patron: ";
                        cin>>id;
                        pats.deletPatron(id);
                        break;
                    }
                }
                break;
            }
            //case 3 is for adding, modifying, and deleting a chosen lOan or rechecking a book
            case 3:
            {
                //this is the submenu of choice 3
                cout<<endl;
                cout<<"1 - Add Loan"<<endl;
                cout<<"2 - Find Loan ID"<<endl;
                cout<<"3 - Recheck Book"<<endl;
                cout<<"3 - Delete Loan"<<endl;
                cout<<"Enter your selection: ";
                cin>>subChoice;
                switch(subChoice)
                {
                    //this case is if the user wants to check out a book
                    case 1: 
                    {
                        Patron* temp;
                        int id2;
                        int checker;
                        cout << "Enter Patron ID: ";
                        cin>>id2;
                        temp = pats.findPatronByID(id2);
                        //this section checks if the patron has to many books checked out or an unpaid balance
                        checker = temp->checkIfTheyCan();
                        if(checker == 0)
                        {
                            exchanges.addLoan(id2,inventory);
                        }
                        else if(checker == 1)
                        {
                            cout<<"You Have to many books checked out"<<endl;
                        }
                        else if(checker == 2)
                        {
                            char choice1;
                            cout<<"You have an unpaided balance"<<endl;
                            cout<<"Whould you like to pay it? y/n"<<endl;
                            cin>>choice1;
                            if(choice1 == 'y')
                            {
                                cout<<"Enter card"<<endl;
                                cout<<"Transaction complete"<<endl;
                                temp->setBalance(0);
                                cout<<"Redirecting to new loan page"<<endl;
                                exchanges.addLoan(id2,inventory);
                            }
                            else
                            {
                                break;
                            }
                        }
                        break;
                    }
                    //This section is for the user to find the loan id by either
                    //both patron and book ID or only the patrons ID
                    case 2: 
                    {
                        //this is a submenu for finding the loan id
                        char sub2Choice;
                        cout<<"Do you know Patron's ID and the Book's ID?"<<endl;
                        cout<<"Both - y"<<endl;
                        cout<<"only Patron's ID - o"<<endl;
                        cout<<"Neither - n"<<endl;
                        cin>>sub2Choice;
                        //this case is to find the loan id by both ID's
                        if(sub2Choice == 'y')
                        {
                            Loan *temp;
                            int pats_ID;
                            int books_ID;
                            cout<<"Enter Patron's ID: ";
                            cin>>pats_ID;
                            cout<<"Enter Book's ID: ";
                            cin>>books_ID;
                            temp = exchanges.findLoan(pats_ID,books_ID);
                            cout<<"Loan ID: "<<temp->getLoanID()<<endl;
                            cout<<endl;
                        }
                        //this case finds the loan id by outputing all the loans for the patron
                        //then theu choose which loan they needed the ID and its outputted
                        else if(sub2Choice == 'o')
                        {
                            int pats_ID;
                            Loan *temp;
                            cout<<"Enter Patrons ID: "<<endl;
                            cin>>pats_ID;
                            temp = exchanges.findLoanByPatron(pats_ID);
                            cout<<"Loan ID: "<<temp->getLoanID()<<endl;
                            cout<<endl;
                        }
                        //this is for if they enter n or anyother letter
                        else
                        {
                            choice = -1;
                            subChoice = -1;
                        }
                        break;
                    }
                    //this case is for rechecking a book
                    case 3:
                    {
                        int iD;
                        cout<<"Enter Loan ID"<<endl;
                        cin>>iD;
                        exchanges.rechceck(iD);
                        break;
                    }
                    //this case is for returning a book
                    case 4: 
                    {
                        int id;
                        cout<<"Please enter the ID of the Loan: ";
                        cin>>id;
                        exchanges.delLoan(id,inventory,pats);
                        break;
                    }
                }
                break;
            }
            //this case is to find a book by either book title. author name, or both
            case 4: 
            {
                //varanles
                char userChoice;
                Item *temp;
                string btitle, bauthor;
                //this is a submenu for choice 4
                cout<<endl;
                cout<<"Do you know the Item ID?"<<endl;
                cout<<"y - YES"<<endl;
                cout<<"n - NO"<<endl;
                cout<<"Enter your selection: ";
                cin>>userChoice;cin.ignore();
                //this is for choice y and finds the book by book title and author name
                if(userChoice == 'y')
                {
                    int findIT;
                    cout<<"Enter ID: ";
                    cin>>findIT;
                    inventory.findItemNoReturn(findIT);
                }
                else if(userChoice == 'n')
                {
                    int type;
                    cout<<"What type of item is it?"<<endl;
                    cout<<"1 - Book"<<endl;
                    cout<<"2 - CD"<<endl;
                    cout<<"3 - DVD"<<endl;
                    cout<<"Enter your selection: ";
                    cin>>type;

                    switch(type)
                    {
                        case 1:
                        {
                            int selection;
                            cout<<"What would you like to find the book by?"<<endl;
                            cout<<"1 - Title"<<endl;
                            cout<<"2 - Author"<<endl;
                            cout<<"3 - ISBN"<<endl;
                            cout<<"4 - Category"<<endl;
                            cout<<"Enter your selection: ";
                            cin>>selection;cin.ignore();cout<<endl;
                            inventory.findByOther(type,selection);
                            break;
                        }
                        case 2:
                        {
                            int selection;
                            cout<<"What would you like to find the CD by?"<<endl;
                            cout<<"1 - Artist"<<endl;
                            cout<<"2 - Title"<<endl;
                            cout<<"3 - Release Date"<<endl;
                            cout<<"4 - Genre"<<endl;
                            cout<<"Enter your selection: ";
                            cin>>selection;cin.ignore();cout<<endl;
                            inventory.findByOther(type,selection);
                            break;
                        }
                        case 3:
                        {
                            int selection;
                            cout<<"What would you like to find the DVD by?"<<endl;
                            cout<<"1 - Title"<<endl;
                            cout<<"2 - Category"<<endl;
                            cout<<"3 - Run Time"<<endl;
                            cout<<"4 - Release Date"<<endl;
                            cout<<"5 - Genre"<<endl;
                            cout<<"Enter your selection: ";
                            cin>>selection;cin.ignore();cout<<endl;
                            inventory.findByOther(type,selection);
                            break;
                        }
                    }
                }
                //this tells the user they are returning to the menu after a incorrect input
                else
                {
                    cout<<"Incorrect input returning to menu."<<endl;
                }
                break;
            }
            //this case is for finding a patron
            case 5: 
            {
                //varables
                char userChoice;
                Patron *temp;
                string name;
                int iD;
                //this askes the user if theu know their id
                cout<<endl;
                cout<<"Do you know the ID? y/n"<<endl;
                cin>>userChoice;cin.ignore();
                //this section is for if they input that they know their id
                if(userChoice == 'y')
                {
                    //asks the user for the patrons id
                    cout<<endl;
                    cout<<"What is the Patron's ID?"<<endl;
                    cin>>iD;
                    temp = pats.findPatronByID(iD);
                    //this outputs nothing found if the patron cannot be found form inputted id
                    if(temp == NULL)
                    {
                        cout<<"Nothing found"<<endl;
                        break;
                    }
                    cout<<endl;
                    temp->print();
                    cout<<endl;
                }
                //this section is for the user not knowing the patron id and finds the patron by name
                //this also outputs all patrons with the inputted name
                else if(userChoice == 'n')
                {
                    //asks the user for the patrons name
                    cout<<endl;
                    cout<<"What is the Patron's name?"<<endl;
                    getline(cin,name);
                    temp = pats.findPatronByName(name);
                    //this outputs nothing found if the patron cannot be found form inputted name
                    if(temp == NULL)
                    {
                        cout<<"Nothing found"<<endl;
                        break;
                    }
                    cout<<endl;
                    temp->print();
                    cout<<endl;
                }
                //this outputs a error message and returns the user to the menu
                else
                {
                    cout<<"Incorrect input returning to menu."<<endl;
                }
                break;
            }
            //this case is to find a loan by loanID, bookID and patron ID, bookID, or patronID
            case 6: 
            {
                //varables
                char userChoice;
                Loan *temp;
                int lID, pID, bID;
                //submenu for choice 6 asking the user for what informtaion the user knows
                cout<<endl;
                cout<<"Do you know the Loan ID or Book ID and/or Patron ID?"<<endl;
                cout<<"LoanID - l"<<endl;
                cout<<"Both Book and Patron- y"<<endl;
                cout<<"BookID - b"<<endl;
                cout<<"PatronID - p"<<endl;
                cin>>userChoice;cin.ignore();
                //this is for choice L which asks the user for the loan id and outputs the loan
                if(userChoice == 'l')
                {
                    cout<<endl;
                    cout<<"What is the Loan ID?"<<endl;
                    cin>>lID;
                    temp = exchanges.findLonaByID(lID);
                    //this outputs nothing found if the loan cannot be found form inputted id
                    if(temp == NULL)
                    {
                        cout<<"Nothing found"<<endl;
                        break;
                    }
                    cout<<endl;
                    temp->print();
                    cout<<endl;
                }
                //this is for choice y which asks the user for the book id and patron id then outputs the loan
                else if(userChoice == 'y')
                {
                    cout<<endl;
                    cout<<"what's the Book ID?"<<endl;
                    cin>>bID;
                    cout<<"What's the Patron's ID?"<<endl;
                    cin>>pID;
                    temp = exchanges.findLoan(pID,bID);
                    //this outputs nothing found if the loan cannot be found form inputted
                    //book and patron ID
                    if(temp == NULL)
                    {
                        cout<<"Nothing found"<<endl;
                        break;
                    }
                    cout<<endl;
                    temp->print();
                    cout<<endl;
                }
                //this is for choice b which asks the user for the book id and outputs the loan with that book id
                else if(userChoice == 'b')
                {
                    cout<<endl;
                    cout<<"What is the Book ID?"<<endl;
                    cin>>bID;
                    temp = exchanges.findLoanByBook(bID);
                    //this outputs nothing found if the loan cannot be found form inputted book ID
                    if(temp == NULL)
                    {
                        cout<<"Nothing found"<<endl;
                        break;
                    }
                    cout<<endl;
                    temp->print();
                    cout<<endl;
                }
                //this is for choice p which asks the user for the patron id and outputs the loans that the patron has
                else if(userChoice == 'p')
                {
                    cout<<endl;
                    cout<<"What is the Patron's ID?"<<endl;
                    cin>>pID;
                    temp = exchanges.findLoanByPatron(pID);
                    //this outputs nothing found if the loan cannot be found form inputted patron ID
                    if(temp == NULL)
                    {
                        cout<<"Nothing found"<<endl;
                        break;
                    }
                    cout<<endl;
                    temp->print();
                    cout<<endl;
                }
                //this outputs a error message and returns the user to the menu
                else
                {
                    cout<<"Incorrect input returning to menu."<<endl;
                }
                break;
            }
            //this case prints all of the Items 
            case 7: inventory.prtlist();break;
            //this case prints all of the patrons 
            case 8: pats.prtlist();break;          
            //this case prints all of the loans 
            case 9: exchanges.prtlist();break;
            //this case gets back to a submenu
            case -2: break;
        }
    }
    return 0;
}
