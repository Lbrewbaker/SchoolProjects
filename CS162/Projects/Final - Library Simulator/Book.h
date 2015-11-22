/********************************
Author: Luke Brewbaker
Date: 11/28/14
Modified: 11/28/14
File:

Overview:



Input:


Output:


*******************************/


#ifndef Book_h
#define Book_h

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Patron;

enum Locale {ON_SHELF, ON_HOLD, CHECKED_OUT};

class Book
{
private:
    string idCode;
    string title;
    string author;
    Locale location;
    Patron* checkedOutBy;
    Patron* requestedBy;
    int dateCheckedOut;

public:
    static const int CHECK_OUT_LENGTH = 21;
    Book();
    Book(string idc, string t, string a);
    string getIdCode();
    string getTitle();
    string getAuthor();
    Locale getLocation();
    void setLocation(Locale location);
    Patron* getCheckedOutBy();
    void setCheckedOutBy(Patron* p);
    Patron* getRequestedBy();
    void setRequestedBy(Patron* p);
    int getDateCheckedOut();
    void setDateCheckedOut(int d);
    ~Book();
};

#endif
