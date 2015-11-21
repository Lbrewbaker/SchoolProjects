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
#include "Library.h"
#include "Patron.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iomanip>

using namespace std;



int main()
{
    Library lib; //Library object
    int choice;
    int f = 0;
    string patronID, bookID;
    int dcurrent;
    double fineAmount;

	cout << "\n\nWelcome to the virtual library.  Please enter your selection below.\n " << endl;

    do
    {
		cout << "\n1. Set the current date " << endl;
		cout << "2. Change the date " << endl;
		cout << "3. Add a book " << endl;
		cout << "4. Add a member " << endl;
		cout << "5. Check out a book " << endl;
		cout << "6. Return a book " << endl;
		cout << "7. Request a book " << endl;
		cout << "8. Pay a fine" << endl;
		cout << "9. Display book info " << endl;
		cout << "10. Display Patron info " << endl;
		cout << "11. Exit " << endl;
		cin >> choice;

        if (choice == 1)
			{
                lib.setCurrentDate(dcurrent);

			}

        if (choice == 2)
            {
               lib.incrementCurrentDate(dcurrent);

            }

		if (choice == 3)
			{
				lib.addBook();

			}

		if (choice == 4)
			{
				lib.addMember();
			}

        if (choice == 5)
            {
                lib.checkOutBook(patronID, bookID);
            }
        if (choice == 6)
            {
                lib.returnBook( bookID);
            }
        if (choice == 7)
            {
                lib.requestBook(patronID,  bookID);
            }

        if (choice == 8)
            {
                lib.payFine(patronID, fineAmount);
            }

        if (choice == 9)
            {
                lib.viewBookInfo(bookID);
            }

        if (choice == 10)
            {
                lib.viewPatronInfo(patronID);
            }
		if (choice == 11)
			{
				exit(0);
			}


    } while (f == 0);

    return 0;
}
