/********************************
Author: Luke Brewbaker
Date: 11/28/14
Modified: 11/28/14
File:

Overview:



Input:


Output:


*******************************/
#include "Library.h"
#include "Book.h"
#include "Patron.h"


#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//Default Constructor
Library::Library()
{
    currentDate = 0;
    //vector<Book> holdings;
    //vector<Patron> members;
    holdings.reserve(100);
    members.reserve(100);

}

//Overload Constructor
Library::Library(int dcurrent)
{
     currentDate = dcurrent;
}

//Destructor
Library::~Library(){};

//Current date
int Library::getCurrentDate(){return currentDate;}

//Set current date
void Library::setCurrentDate(int dcurrent)
{
    cout << "What would you like to set the current date too? (Single numbers only) ";
    cin >> dcurrent;
    currentDate = dcurrent;

}

void Library::incrementCurrentDate(int dcurrent)
{
    Book *b;
    //set the current date up
    int incdate;
    cout << "How many days would you like to increment the date? ";
    cin >> incdate;

    dcurrent = incdate + dcurrent;
    double fine = incdate * DAILY_FINE;

    //check for checked out books
    for (int i = 0; i < members.size(); i++)
     {
           members[i].amendFine(fine);
     }





}
//Fill my books
void Library::addBook()
{

	string t, a, idc;
	locale location;

//prompt for book info
		cout << "What is the title of the book? ";
		cin >> t;
		cout << "Who is the author of the book? ";
		cin >> a;
		cout << "What is the ID code for the book? ";
		cin >> idc;


//add to holdings vector
		Book newBook(idc, t, a);
		holdings.push_back(newBook);

}

//Add member
void Library::addMember()
{

	string idn, n;
	double fine;

		cout << "What is the name of the new member? ";
		cin >> n;

//enter the user ID number and check if it is used
        bool usedid = true;

        cout << "What is your ID number? ";
        cin >> idn;

//set fine to 0
		fine = 0;

//adds to members vector
		Patron newMember(idn, n, fine);
		members.push_back(newMember);

}


//Check out book
void Library::checkOutBook(string patronID, string bookID)
{

    Patron *p; //patron pointer
    Book *book;
    bool goodMember = false;
    bool goodTitle = false;
    string pid, bid;
    locale location;
    //int dcurrent;

    //Check if member id is correct
    do
    {
        cout << "What is your memberID? ";
        cin >> pid;
        for(int i = 0; i < members.size(); i ++)
        {
            if(pid == members[i].getIdNum())
                {
                    //p = members[i].getIdNum(); //sets P to the ID number specified, if that number is valid
                    goodMember = true;

                }
            else
                cout << "That is not a valid ID number, please try again. " << endl;
        }



    } while (!goodMember);

    //Check if the book title is correct
    do
    {
        cout << "What is the ID of the book you would like? ";
        cin >> bid;
        for(int i = 0; i < holdings.size(); i ++)
        {
            if(holdings[i].getIdCode() == bid)
                {
                    //book = holdings[i];
                    goodTitle = true;
                }
            else
                cout << "There are no books with that ID code.  Please enter another. " << endl;
        }


    } while (!goodTitle);

    //check if book checked out
    bool bookchecked = false;
    for(int i = 0; i<holdings.size(); i ++)
    {
        if (bid == holdings[i].getIdCode())
            if (holdings[i].getLocation() == CHECKED_OUT)
            {
             cout << "That book is currently checked out to ";
             bookchecked = true;
            }
    }

    //check if book reserved
    bool booknotreserved = true;
    for(int i = 0; i<holdings.size(); i ++)
    {
        if (bid == holdings[i].getIdCode())
            if (holdings[i].getLocation() == ON_HOLD)
            {
             cout << "That book is currently reserved.";
             booknotreserved = false;
            }
    }


    if (goodMember == true && goodTitle == true && bookchecked == true && booknotreserved == true)
    {

        for(int i = 0; i < members.size(); i++)
            {
               if (bid == members[i].getIdNum())
                {
                    book->setCheckedOutBy(p); //set checked out by
                    book->setLocation(CHECKED_OUT); //set book to checked out
                    book->setDateCheckedOut(currentDate);//set current date
                    p->addBook(book);  //adds book to Patrons checked out books

                }

            }
    }


cout << "\n\nThank you for using our Library. " << endl;

}

void Library::viewPatrons()
{
    for(int i = 0; i < members.size(); i ++)
    {
        cout << "Member name: " <<members[i].getName() << endl;
        cout << "Member ID Number: " << members[i].getIdNum() << endl;
    }

}
void Library::viewBooks()
{
    //loop holdings vector to print books
    for (int i = 0; i < holdings.size(); i ++)
    {
        cout << "Book title: " << holdings[i].getTitle() << endl;
        cout << "Book Author: " << holdings[i].getAuthor() << endl;
        cout << "Book ID Number: " << holdings[i].getIdCode() << endl;
        cout << "Location: " << holdings[i].getLocation() << endl;
    }

}

void Library::viewPatronInfo(string patronID)
{

    Patron *p;//patron pointer
    bool ispatron = false;

    cout << "Please enter the ID of the patron you would like to view: ";
    cin >> patronID;
    do
    {
        for (int i = 0; i < members.size(); i ++)
            {
                if (patronID == members[i].getIdNum())
                    {
                        cout << "Member name: " << members[i].getName() << endl;
                        cout << "Member ID: " << members[i].getIdNum() << endl;
                        cout << "Fine amount: " << members[i].getFineAmount() << setprecision(2) << endl;
                        ispatron = true;
                    }
                else
                    cout << "No patron by that ID code. Please try again." << endl;
            }

    } while (ispatron = false);

}
void Library::viewBookInfo(string bookID)
{
    bool isbook = false;

    cout << "Please enter the ID of the book you would like to display info on " << endl;
    cin >> bookID;

    do
    {
        //loop holdings vector to print specific book info
        for (int i = 0; i < holdings.size(); i ++)
        {
            if (bookID == holdings[i].getIdCode())
            {
                cout << "Book title: " << holdings[i].getTitle() << endl;
                cout << "Book Author: " << holdings[i].getAuthor() << endl;
                cout << "Book ID Number: " << holdings[i].getIdCode() << endl;
                cout << "Book location: " << holdings[i].getLocation() << endl;
                isbook = true;
            }
            else
                cout << "Invalid ID, please try again. " << endl;
        }


    } while (!isbook);

}


void Library::requestBook (string patronID, string bookID)
{

	Patron *p;
	Book *b;
	bool goodid = false;
	bool goodbook = false;

//enter book id
	cout << "What book ID would you like to check out? ";
	cin >> bookID;

	for (int i = 0; i < holdings.size(); i++)
        if (bookID == holdings[i].getIdCode())
            goodbook = true; //if book is in the library return true bool
    if (goodbook = false)
        cout << "That book is not in the library. " << endl;

//enter patron id
    cout << "What is your user ID? ";
    cin >> patronID;

    for (int i = 0; i < members.size(); i++)
        if (patronID == members[i].getIdNum())
            goodid = true;

    if (goodid = false)
        cout << "There is not member by that number. " << endl;



//check if book on hold
bool bookavail = true;
    for (int i = 0; i < holdings.size(); i ++)
    {
        if (holdings[i].getLocation() == ON_HOLD)
            {
                bookavail = false;
            }
    }

//if all bools = true set book on hold.
    if (goodid == true && goodbook == true && bookavail == true)
        {
            b->setLocation(ON_HOLD);
            b->setRequestedBy(p);
            cout << "Your requested book is now on hold" << endl;
        }
}

void Library::returnBook(string bookID)
{

bool bookgood = false;
//string bookID;

    cout << "What book would you like to return? ";
    cin >> bookID;

        //check if book id is good
    for (int i = 0; i < holdings.size(); i ++)
        {
            if (holdings[i].getIdCode() == bookID)
                {
                    bookgood = true;
                    holdings[i].setLocation(ON_SHELF);
                    cout << "Your book is now checked in. " << endl;
                }
            else if (holdings[i].getIdCode() != bookID)
                cout << "There is no book by that ID Code. " << endl;
        }


}

void Library::payFine(string patronID, double fine)
{

    Patron *p; //patron pointer
    bool goodpatron = false;
    cout << "Please enter your ID: ";
    cin >> patronID;
        for (int i = 0; i < members.size(); i++)
        {
            if (patronID == members[i].getIdNum())
                {
                    goodpatron = true;
                    fine = 0;
                    p->amendFine(fine);
                    cout << "Thank you for paying your fine. " << endl;
                }
        }
        if (goodpatron = false)
           {
               cout << "That is not a valid ID. " << endl;
           }


}
