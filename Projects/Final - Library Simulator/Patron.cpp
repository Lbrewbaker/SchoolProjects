/********************************
Author: Luke Brewbaker
Date: 11/28/14
Modified: 11/28/14
File:

Overview:



Input:


Output:


*******************************/
#include "Patron.h"
#include "Book.h"
#include "Library.h"
#include <iostream>

using namespace std;

//empty default constructor
Patron::Patron()
{
	double fineAmount = 0;
    string idNum = "";
    string name = "";
}
//overload constructor
Patron::Patron(string idn, string n, double fine)
{
	idNum = idn;
	name = n;
	fineAmount = fine;
}

//Destructor
Patron::~Patron(){};

//Accessor Functions
string Patron::getName(){return name;}
string Patron::getIdNum(){return idNum;}
double Patron::getFineAmount(){return fineAmount;}

vector<Book*> getCheckedOutBooks();

//Mutator functions
void Patron::setName(string n){name = n;}
void Patron::setIdNum(string idn){idNum = idn;}
void Patron::setFine(double fine){fineAmount = fine;}

//this is to add a book to "CHECKED_OUT" by a patron
void Patron::addBook(Book* b)
{

    checkedOutBooks.push_back(b);

}

//this is to remove a book from "CHECKED_OUT"
void Patron::removeBook(Book* b)
{
   int i;

      if (checkedOutBooks[i]->getIdCode() == b->getIdCode())
      {
          checkedOutBooks.erase(checkedOutBooks.begin()+i);
          cout << "Your book is now checked out. " << endl;
      }


}


void Patron::amendFine(double fine)
{

fineAmount = fine;

}







