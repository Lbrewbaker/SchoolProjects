/********************************
Author: Luke Brewbaker
Date: 11/28/14
Modified: 11/28/14
File:

Overview:



Input:


Output:


*******************************/
#include "Book.h"
#include "Patron.h"
#include "Library.h"


using namespace std;

//empty default constructor
Book::Book()
{
	 dateCheckedOut = 0;
	 idCode = "";
	 title = "";
	 author = "";
	 location = ON_SHELF;
	 checkedOutBy = NULL;
	 requestedBy = NULL;


}

//Overload constructor
Book::Book(string idc, string t, string a)
{
    idCode = idc;
    title = t;
    author = a;
    location = ON_SHELF;
    checkedOutBy = NULL;
    requestedBy = NULL;

}
//Destructor
Book::~Book(){}

//Accessor Functions
string Book::getIdCode(){return idCode;}
string Book::getTitle(){return title;}
string Book::getAuthor(){return author;}
Locale Book::getLocation(){return location;}
int Book::getDateCheckedOut(){return dateCheckedOut;}
//string::Patron* getCheckedOutBy(){return name;}
//string::Patron* getRequestedBy(){return name;}


//Mutator Functions
void Book::setLocation(Locale location) {location = location;}

void Book::setCheckedOutBy(Patron* p)
{

}


void Book::setRequestedBy(Patron* p)
{

}
void Book::setDateCheckedOut(int dcurrent){dateCheckedOut = dcurrent;}

