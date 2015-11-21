//
//  Library.h
//  examples
//
//  Created by Tim Alcon on 11/25/14.
//  Copyright (c) 2014 Tim Alcon. All rights reserved.
//

#ifndef Library_h
#define Library_h

#include "Book.h"
#include "Patron.h"

#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;


class Patron;
class Book;

class Library
{
private:
    vector<Book> holdings;
    vector<Patron> members;
    int currentDate;

public:
    static const double DAILY_FINE = 0.1;
	Library();
	Library(int dcurrent);
	int getCurrentDate();
    void setCurrentDate(int);
    void addBook();
    void addMember();
    void checkOutBook(string patronID, string bookID);
    void returnBook(string bookID);
    void requestBook(string patronID, string bookID);
    void incrementCurrentDate(int);
    void payFine(string patronID, double fine);
    void viewPatronInfo(string);
    void viewBookInfo(string );
    void viewPatrons();
    void viewBooks();
    ~Library();
};

#endif
