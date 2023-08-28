//
//  Zachary Warren
//  CSCE 1040
//  Homework 4
//
#include "libraryItems.h"
using namespace std;

//returns bookcount
int Items::getcount() {return itemcount;}
//increases bookcount
void Items::inccount() {itemcount++;}
//decreases bookcount
void Items::deccount() {itemcount--;}

//adds a book to the collection by asking the user for all required information
void Items::addItem()
{
    int choice;
    cout << "What Item would you like to add?" << endl;
    cout << "1 - Book" << endl;
    cout << "2 - CD" << endl;
    cout << "3 - DVD" << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
        int status, loan;
        float cost;
        string d1, d2,d3, category;

        cout << "What is the cost of the item?" << endl;
        cin >> cost;
        cout << "What is the status of the item?" <<endl;
        cout << "0 - in stock" << endl;
        cout << "1 - checked out" << endl;
        cout << "2 - lost" << endl;
        cin>>status;
        cout << "What is the amount of time this item can be loned out? (in days)" << endl;
        cin>>loan;
        cin.ignore();
    
        cout << "Enter Book Title: ";
        getline(cin,d1);

        cout << "Enter Author name: ";
        getline(cin,d2);

        cout << "Enter ISBN: ";
        getline(cin,d3);

        cout << "Enter the category: ";
        getline(cin,category);


        itemlist.push_back(new Book(nextAvaiableID, cost, status, loan, d1, d2, d3, category));
        break;
        }
        case 2:
        {
            int status, loan;
            float cost;
            int num;
            string artist, title, genre, date;

            cout << "What is the cost of the item?" << endl;
            cin >> cost;
            cout << "What is the status of the item?" <<endl;
            cout << "0 - in stock" << endl;
            cout << "1 - checked out" << endl;
            cout << "2 - lost" << endl;
            cin>>status;
            cout << "What is the amount of time this item can be loned out? (in days)" << endl;
            cin>>loan;
            cin.ignore();

            cout << "What is the artist's name?" << endl;
            getline(cin,artist);
            cout << "What is the title of the CD?" << endl;
            getline(cin,title);
            cout << "How many tracks are in the CD?" << endl;
            cin>>num;
            cin.ignore();
            cout << "What is the release date of the CD? (XX/XX/XXXX)" << endl;
            getline(cin,date);
            cout << "What is the genre of the CD?" << endl;
            getline(cin,genre);

            itemlist.push_back(new CD(nextAvaiableID, cost, status, loan, artist, title, num, date, genre));
            break;
        }
        case 3:
        {
            int status, loan;
            float cost;
            string title, category, time, genre, date;

            cout << "What is the cost of the item?" << endl;
            cin >> cost;
            cout << "What is the status of the item?" <<endl;
            cout << "0 - in stock" << endl;
            cout << "1 - checked out" << endl;
            cout << "2 - lost" << endl;
            cin>>status;
            cout << "What is the amount of time this item can be loned out? (in days)" << endl;
            cin>>loan;
            cin.ignore();

            cout << "What is the title of the DVD?" << endl;
            getline(cin,title);
            cout << "What is the catagory of the DVD?" << endl;
            getline(cin,category);
            cout << "What is the run time of the DVD? (XX:XX:XX)" << endl;
            getline(cin,time);
            cout << "What is the release date of the DVD? (XX/XX/XXXX)" << endl;
            getline(cin,date);
            cout << "What is the genre of the DVD?" << endl;
            getline(cin,genre);

            itemlist.push_back(new DVD(nextAvaiableID, cost, status, loan, title, category, time, date, genre));
            break;
        }
    }
    inccount();

}

//delets the book from the collection without messing with other books ID's
void Items::delItem(int id)
{
    for (auto it = itemlist.begin(); it !=itemlist.end(); ++it)
    {
        if ((*it)->getID() == id)
        {
            itemlist.erase(it);
            break;
        }
    }
    deccount();
}

int Items::numberOfSpecificItem(string type)
{
    int count = 0;
    for (auto it = itemlist.begin(); it !=itemlist.end(); ++it)
    {
        if(type == "CD")
        {
            if( typeid(**it) == typeid(CD) )
                count++;
        }
        else if(type == "DVD")
        {
            if( typeid(**it) == typeid(DVD) )
                count++;
        }
        else if(type == "Book")
        {
            if( typeid(**it) == typeid(Book) )
                count++;
        }
    }  
    return count;
}
//finds a book's ID from the paramiters of a title and author name
/*
Item* Items::findID(string t,string n)
{
    Item *temp;
    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
    {
        temp = *it;
        if(temp->getTitle() == t && temp->getAuthor() == n)
        {
            return *it;
        }
    }
    return NULL;
}
*/

//finds a book from the book ID
Item* Items::findItem(int iD)
{
    Item *temp ;
    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
    {
        temp = *it;
        if (temp->getID() == iD)
        {
            return temp;
        }
    }
    return NULL;
}

void Items::findItemNoReturn(int iD)
{
    CD *temp1;
    DVD *temp2;
    Book *temp3;
    cout<<endl;
    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
    {
        
        if( typeid(**it) == typeid(CD) )
        {
            temp1 = dynamic_cast<CD*>(*it);
            if(temp1->getID() == iD)
                temp1->print();
        }
        else if ( typeid(**it) == typeid(DVD) )
        {
            temp2 = dynamic_cast<DVD*>(*it);
            if(temp2->getID() == iD)
                temp2->print();
        }
        else if ( typeid(**it) == typeid(Book) )
        {
            temp3 = dynamic_cast<Book*>(*it);
            if(temp3->getID() == iD)
                temp3->print();
        }
    }
}

void Items::findByOther(int type, int var)
{
    CD *temp1;
    DVD *temp2;
    Book *temp3;
    switch(type)
    {
        case 1:
        {
            switch(var)
            {
                case 1:
                {
                    string findTitle;
                    cout<<"Enter the Title: ";
                    getline(cin,findTitle);

                    cout<<endl<<"Here are your choices: "<<endl<<endl;
                    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
                    {
                        if( typeid(**it) == typeid(Book) )
                        {
                            temp3 = dynamic_cast <Book*>(*it);
                            if (temp3->getTitle() == findTitle)
                            {
                                temp3->print();
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    string findAuthor;
                    cout<<"Enter the Author: ";
                    getline(cin,findAuthor);

                    cout<<endl<<"Here are your choices: "<<endl<<endl;
                    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
                    {
                        if( typeid(**it) == typeid(Book) )
                        {
                            temp3 = dynamic_cast <Book*>(*it);
                            if (temp3->getAuthor() == findAuthor)
                            {
                                temp3->print();
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    string findISBN;
                    cout<<"Enter the ISBN: ";
                    getline(cin,findISBN);

                    cout<<endl<<"Here are your choices: "<<endl<<endl;
                    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
                    {
                        if( typeid(**it) == typeid(Book) )
                        {
                            temp3 = dynamic_cast <Book*>(*it);
                            if (temp3->getISBN() == findISBN)
                            {
                                temp3->print();
                            }
                        }
                    }
                    break;
                }
                case 4:
                {
                    string findCategory;
                    cout<<"Enter the Category: ";
                    getline(cin,findCategory);

                    cout<<endl<<"Here are your choices: "<<endl<<endl;
                    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
                    {
                        if( typeid(**it) == typeid(Book) )
                        {
                            temp3 = dynamic_cast <Book*>(*it);
                            if (temp3->getCategory() == findCategory)
                            {
                                temp3->print();
                            }
                        }
                    }
                    break;
                }
            }
            break;
        }
        case 2:
        {
            switch(var)
            {
                case 1:
                {
                    string findArtist;
                    cout<<"Enter the Artist Name: ";
                    getline(cin,findArtist);

                    cout<<endl<<"Here are your choices: "<<endl<<endl;
                    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
                    {
                        if( typeid(**it) == typeid(CD) )
                        {
                            temp1 = dynamic_cast <CD*>(*it);
                            if (temp1->getArtist() == findArtist)
                            {
                                temp1->print();
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    string findTitle;
                    cout<<"Enter the Title: ";
                    getline(cin,findTitle);

                    cout<<endl<<"Here are your choices: "<<endl<<endl;
                    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
                    {
                        if( typeid(**it) == typeid(CD) )
                        {
                            temp1 = dynamic_cast <CD*>(*it);
                            if (temp1->getTitle() == findTitle)
                            {
                                temp1->print();
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    string findRD;
                    cout<<"Enter the Release Date (XX/XX/XX): ";
                    getline(cin,findRD);

                    cout<<endl<<"Here are your choices: "<<endl<<endl;
                    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
                    {
                        if( typeid(**it) == typeid(CD) )
                        {
                            temp1 = dynamic_cast <CD*>(*it);
                            if (temp1->getReleaseDate() == findRD)
                            {
                                temp1->print();
                            }
                        }
                    }
                    break;
                }
                case 4:
                {
                    string findGenre;
                    cout<<"Enter the Genre: ";
                    getline(cin,findGenre);

                    cout<<endl<<"Here are your choices: "<<endl<<endl;
                    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
                    {
                        if( typeid(**it) == typeid(CD) )
                        {
                            temp1 = dynamic_cast <CD*>(*it);
                            if (temp1->getGenre() == findGenre)
                            {
                                temp1->print();
                            }
                        }
                    }
                    break;
                }
            }
            break;
        }
        case 3:
        {
            switch(var)
            {
                case 1:
                {
                    string findTitle;
                    cout<<"Enter the Title: ";
                    getline(cin,findTitle);

                    cout<<endl<<"Here are your choices: "<<endl<<endl;
                    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
                    {
                        if( typeid(**it) == typeid(DVD) )
                        {
                            temp2 = dynamic_cast <DVD*>(*it);
                            if (temp2->getTitle() == findTitle)
                            {
                                temp2->print();
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    string findCat;
                    cout<<"Enter the Category: ";
                    getline(cin,findCat);

                    cout<<endl<<"Here are your choices: "<<endl<<endl;
                    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
                    {
                        if( typeid(**it) == typeid(DVD) )
                        {
                            temp2 = dynamic_cast <DVD*>(*it);
                            if (temp2->getCategory() == findCat)
                            {
                                temp2->print();
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    string findRT;
                    cout<<"Enter the Run Time: ";
                    getline(cin,findRT);

                    cout<<endl<<"Here are your choices: "<<endl<<endl;
                    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
                    {
                        if( typeid(**it) == typeid(DVD) )
                        {
                            temp2 = dynamic_cast <DVD*>(*it);
                            if (temp2->getRunTime() == findRT)
                            {
                                temp2->print();
                            }
                        }
                    }
                    break;
                }
                case 4:
                {
                    string findRD;
                    cout<<"Enter the Release Date: ";
                    getline(cin,findRD);

                    cout<<endl<<"Here are your choices: "<<endl<<endl;
                    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
                    {
                        if( typeid(**it) == typeid(DVD) )
                        {
                            temp2 = dynamic_cast <DVD*>(*it);
                            if (temp2->getReleaseDate() == findRD)
                            {
                                temp2->print();
                            }
                        }
                    }
                    break;
                }
                case 5:
                {
                    string findGenre;
                    cout<<"Enter the Genre: ";
                    getline(cin,findGenre);

                    cout<<endl<<"Here are your choices: "<<endl<<endl;
                    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
                    {
                        if( typeid(**it) == typeid(DVD) )
                        {
                            temp2 = dynamic_cast <DVD*>(*it);
                            if (temp2->getGenre() == findGenre)
                            {
                                temp2->print();
                            }
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
}

//finds and prints all books with the same title as the paramiter t
/*
void Items::findByTitle(string t)
{
    Item *temp;
    int count = 0;
    cout<<endl;
    cout<<"Here are your choice's"<<endl;
    cout<<endl;
    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
    {
        temp = *it;
        if (temp->getTitle() == t)
        {
            count++;
            temp->print();
        }
    }
    if(count == 0)
    {
        cout<<"Nothing found"<<endl;
    }
}

//finds and prints all books with the same author as the paramiter a
void Items::findByAuther(string a)
{
    Item *temp;
    int count = 0;
    cout<<endl;
    cout<<"Here are your choice's"<<endl;
    cout<<endl;
    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
    {
        temp = *it;
        if (temp->getAuthor() == a)
        {
            count++;
            temp->print();
        }
    }
    if(count == 0)
    {
        cout<<"Nothing found"<<endl;
    }
}
*/
//deletes all of the book's in the collection then clears the collection
void Items::cleanup()
{
    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
    {
        
        delete *it;
    }
    itemlist.clear();
}

//prints everybook in the collection
void Items::prtlist()
{
    CD *temp1;
    DVD *temp2;
    Book *temp3;
    cout<<endl;
    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
    {
        
        if( typeid(**it) == typeid(CD) )
        {
            temp1 = dynamic_cast<CD*>(*it);
            temp1->print();
        }
        else if ( typeid(**it) == typeid(DVD) )
        {
            temp2 = dynamic_cast<DVD*>(*it);
            temp2->print();
        }
        else if ( typeid(**it) == typeid(Book) )
        {
            temp3 = dynamic_cast<Book*>(*it);
            temp3->print();
        }
    }
}

//stores all the books information in a file called books.dat
void Items::storeItems()
{
    ofstream fout;
    fout.open("items.dat");
    fout << itemcount << endl;

    Item *temp;
    for (auto it = itemlist.begin(); it != itemlist.end(); ++it)
    {
        temp = dynamic_cast <Item*>(*it);
        fout << temp->getID() << " " << temp->getCost() << " " << temp ->getStatus() << " " << temp->getLoan_period()  << endl;
        if( typeid(**it) == typeid(CD) )
        {
            CD *temp1 = dynamic_cast <CD*>(*it);
            fout << "CD" << endl;
            fout << temp1->getArtist() << endl;
            fout << temp1->getTitle() << endl;
            fout << temp1->getNumOfTracks() << " " << temp1->getReleaseDate() << endl; 
            fout << temp1->getGenre() << endl;
        }
        else if ( typeid(**it) == typeid(DVD) )
        {
            DVD *temp1 = dynamic_cast <DVD*>(*it);
            fout << "DVD" << endl;
            fout << temp1->getTitle() << endl;
            fout << temp1->getCategory() << endl;
            fout << temp1->getRunTime() << endl;
            fout << temp1->getReleaseDate() << endl;
            fout << temp1->getGenre() << endl;
        }
        else if ( typeid(**it) == typeid(Book) )
        {
            Book *temp1 = dynamic_cast <Book*>(*it);
            fout << "Book" << endl;
            fout << temp1->getTitle() << endl;
            fout << temp1->getAuthor() << endl;
            fout << temp1->getISBN() << endl;
            fout << temp1->getCategory() << endl;
        }
    }
    fout.close();
}

//loads all the books from a file called books.dat
void Items::loadItems()
{
    nextAvaiableID = 2;
    ifstream fin;
    int id, status, period;
    float cost;
    string type;
    fin.open("items.dat");
    fin >> itemcount;
    for ( int i=0; i < itemcount; i++)
    {
        fin >> id >> cost >> status >> period; 
        fin.ignore();
        getline(fin, type);

        if(type == "CD")
        {
            string artist, title, genre, date;
            int num;
            getline(fin,artist);
            getline(fin,title);
            fin >> num;
            fin.ignore();
            getline(fin,date);
            getline(fin,genre);
            itemlist.push_back(new CD(id, cost, status, period, artist, title, num, date, genre));
        }
        else if(type == "DVD")
        {
            string title, category, time, date, genre;
            getline(fin,title);
            getline(fin,category);
            getline(fin,time);
            getline(fin,date);
            getline(fin,genre);
            itemlist.push_back(new DVD(id, cost, status, period, title, category, time, date, genre));
        }
        else if(type  == "Book")
        {
            string title, author, isbn, category;
            getline(fin,title);
            getline(fin,author);
            getline(fin,isbn);
            getline(fin,category);
            itemlist.push_back(new Book(id, cost, status, period, title, author, isbn, category));
        }
        if(id >= nextAvaiableID)
            nextAvaiableID = (id+1);
    }
    fin.close();
    
}