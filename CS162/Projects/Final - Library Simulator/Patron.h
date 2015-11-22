
/********************************
Author: Luke Brewbaker
Date: 11/28/14
Modified: 11/28/14
File:

Overview:



Input:


Output:


*******************************/

#ifndef Patron_h
#define Patron_h

#include "Library.h"
#include "Book.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Book;

class Patron
{
private:
    string idNum;
    string name;
    vector<Book*> checkedOutBooks;
    double fineAmount;

public:
    Patron();
    Patron(string, string, double);
    string getIdNum();
    string getName();
    vector<Book*> getCheckedOutBooks();
    void setIdNum(string);
    void setName(string);
    void setFine(double);
    void addBook(Book* b);
    void removeBook(Book* b);
    double getFineAmount();
    void amendFine(double);

    ~Patron();
};

#endif
