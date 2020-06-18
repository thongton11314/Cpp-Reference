/******************************************************************************
* PROJECT: FinalProject_LibraryCodex
* FILE: Source.cpp
* AUTHOR(S): Dean Ferris, Ton That Quynh Thong , Minpyo Kim & Kalkidan Tamirat
* DATE: 3/12/2019
* DESCRIPTION: This console-based program imitates a library database & allows
*			   the user to add/delete books, bibliophiles & view their activity
******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <ctime>
#include "Activity.h"
#include "Bibliophile.h"
#include "Book.h"
#include "FileIO.h"
#include "BulletProof.h"

using namespace std;

//Function prototype
string getCurrentTime();
int menu();
int bibiliophileOptions();
int bookOptions();
int activityOptions();
int menuOption4();
void checkInDate(vector<Book>& allBooks, vector<Bibliophile>& allBibliophile,
	vector<Activity>& allActivity);
void checkOutDate(vector<Book>& allBooks, vector<Bibliophile>& allBibliophile,
	vector<Activity>& allActivity);
void searchAllBook(const vector<Book>& allBooks);
void searchBookByISBN(vector<Activity>& allRecords);
void searchBibliophileId(vector<Activity>& allRecords);
Bibliophile createBibliophile();
void addBibliophile(vector<Bibliophile>& allBibliophile);
void deleteBibliophile(vector<Bibliophile>& allBibliophile);
Book createBook();
void addBook(vector<Book>& allBooks);
void changeBook(vector<Book>& allBooks);
void deleteBook(vector<Book>& allBooks);
void printActivity(const vector<Activity>& allActivity);
void setupLibrary(vector<Activity> &allActivity, vector<Book> &allBooks,
	vector<Bibliophile> &allBibliophile);

/**********************************************************
* FUNCTION: main
* DESCRIPTION: This function will show all of the option
**********************************************************/
int main()
{
	vector<Bibliophile> allBibliophile;
	vector<Book> allBooks;
	vector<Activity> allActivity;
	setupLibrary(allActivity, allBooks, allBibliophile);
	int option = 0;
	do
	{
		cout << "\t\tWelcome to Library CodeX" << endl << " \nToday is: " <<
			getCurrentTime() << endl;
		cout << "\n\nPlease select Option" << endl;
		option = menu();
		//Option one from menu, this option is "Bibliophile"
		if (option == 1)
		{
			int option1;
			do
			{
				option1 = bibiliophileOptions(); //Get option from menu 1
				switch (option1)
				{
				case 1:
					//Add Bibliophile
					addBibliophile(allBibliophile);
					break;
				case 2:
					//Delete Bibliophile
					deleteBibliophile(allBibliophile);
					break;
				case 3:
					//Return to main menu
					system("CLS");
					break;
				}
			} while (option1 != 3);
		}
		//Option two from menu, this option is "Book"
		else if (option == 2)
		{
			int option2;
			do {
				option2 = bookOptions(); //Get option from menu 2
				switch (option2)
				{
				case 1:
					//Add a book
					addBook(allBooks);
					break;
				case 2:
					//Change book info
					changeBook(allBooks);
					break;
				case 3:
					//Delete book
					deleteBook(allBooks);
					break;
				case 4:
					system("CLS");
					break;
				}
			} while (option2 != 4);
		}
		//Option three from menu, this option is "Activity"
		else if (option == 3)
		{
			int option3;
			do
			{
				option3 = activityOptions(); //Get option from menu 3
				switch (option3)
				{
				case 1:
					//View all books
					cout << "\n\t\tInventory of all Books in Library CodeX: " << endl;
					searchAllBook(allBooks);
					cout << endl;
					break;
				case 2:
					//View book by ISBN
					//Format - SID :  checked out : checked in : due date:
					searchBookByISBN(allActivity);
					cout << endl;
					break;
					//View book by bibliophile
				case 3:
					//Search each BibliophileId
					searchBibliophileId(allActivity);
					cout << endl;
					break;
				case 4:
					//Back to main menu
					system("CLS");
					break;
				}
			} while (option3 != 4);
		}
		//Option four from menu
		else if (option == 4)
		{
			int option4;
			do
			{
				option4 = menuOption4(); //Get option from menu 4
				switch (option4)
				{
					//Check Out
				case 1:
					checkOutDate(allBooks, allBibliophile, allActivity);
					break;
					//Check In
				case 2:
					checkInDate(allBooks, allBibliophile, allActivity);
					break;
					//Activity
				case 3:
					cout << "\n\t\tAll Activity:\n " << endl;
					printActivity(allActivity);
					cout << endl;
					break;
					//Back to main()
				case 4:
					system("CLS");
					break;
				}
			} while (option4 != 4);
		}
		//Exit the program
		else if (option == 5)
		{
			option = 0;
			cout << "\tUntil Next Time!";
		}
		cout << endl;
	} while (option != 0);
	getchar();
	return 0;
}

/********************************************************************
* Function:	setupLibrary
* Description: This function will store all the information in
*			   in the text files and store them in their respective
*			   vectors.
* Input: allActivity - vector of Activity objects
*		 allBooks - vector of Book objects
*		 allBibliophile - vector of Bibliophile objects
*********************************************************************/
void setupLibrary(vector<Activity> &allActivity, vector<Book> &allBooks,
	vector<Bibliophile> &allBibliophile)
{
	//Update BibliophileFile from file
	try
	{
		allBibliophile = updateBibliophileFile();
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	//Update Book from file
	try
	{
		allBooks = updateBookFile();
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	//Update ActivityFile from file;
	try
	{
		allActivity = updateActivityFile();
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	for (int i = 0; i < allActivity.size(); i++)
	{
		Activity temp = allActivity.at(i);
		for (int j = 0; j < allBooks.size(); j++)
		{
			if (allBooks.at(j).getBookISBN() == temp.getISBN())
			{
				allBooks.at(j).setBookStatus(true);
				allBooks.at(j).setBibliophileID(temp.getSID());
			}
		}
	}
}

/*********************************************************
* Function:	getCurrentTime
* Description: This function will return the mm/dd/yy format
* Output: - string - month, day, year, hour, minute
*********************************************************/
string getCurrentTime()
{
	struct tm accessTime;
	time_t now = time(0);
	localtime_s(&accessTime, &now);
	int year = 1900 + accessTime.tm_year; //year goes from 1900
	int month = 1 + accessTime.tm_mon;
	int day = accessTime.tm_mday;
	int hour = accessTime.tm_hour;
	int minute = accessTime.tm_min;

	string temp = to_string(minute);
	if (minute < 10)
	{
		temp = "0" + to_string(minute);
	}
	return to_string(month) + "/" + to_string(day) + "/" + to_string(year) + " " + to_string(hour) + ":" + temp;
}

/*********************************************************
* Function: menu
* Description: This function will show all menu in main
* Output: - int option: an option which user chosed
*********************************************************/
int menu()
{
	int option = 0;
	cout << "\n\n\t1. Bibliophile(s)" << endl;
	cout << "\t2. Book(s)" << endl;
	cout << "\t3. Search" << endl;
	cout << "\t4. Check out Book / Check in Book / Activity" << endl;
	cout << "\t5. Exit" << endl;
	cout << "\n\t>";
	cin >> option;
	bulletProof(option, 1, 5);
	return option;
}

/*********************************************************
* Function: menuOption1
* Description: When user choose option 1 from menu
			 , the sub menu in option 1 will show up
* Output: - int option: an option which user chosed
*********************************************************/
int bibiliophileOptions()
{
	int option;
	cout << "\t\t1- Add Bibliophile" << endl;
	cout << "\t\t2- Delete Bibliophile" << endl;
	cout << "\t\t3- Return to Main Menu" << endl;
	cout << "\n\t\t> ";
	cin >> option;
	bulletProof(option, 1, 3);
	return option;
}

/*********************************************************
* Function: menuOption2
* Description: When user choose option 2 from menu
			, the next sub menu in option 2 will show up
* Output: - int option: an option which user chosed
*********************************************************/
int bookOptions()
{
	int option;
	cout << "\t\t1- Add Book" << endl; // Go to addBook() to see this
	cout << "\t\t2- Change Book" << endl; //Go to changeBook() to see this
	cout << "\t\t3- Delete Book" << endl; // Go to deleteBook() to see this
	cout << "\t\t4- Return to Main Menu" << endl; // Return to main menu
	cout << "\n\t\t>";
	cin >> option;
	bulletProof(option, 1, 4);
	return option;
}

/*********************************************************
* Function: menuOption3
* Description: When user choose option 3 from menu
			, the sub menu in option 3 will show up
* Output: - int option: an option which user chosed
*********************************************************/
int activityOptions()
{
	int option;
	cout << "\t\t1- View Inventory of all Books in Library CodeX" << endl; // View all books activity
	cout << "\t\t2- Search by ISBN" << endl; // Search by ISBN
	cout << "\t\t3- Search by Bibliophile" << endl; // Search by Bibliophile
	cout << "\t\t4- Return to Main Menu" << endl; // Return to main menu
	cout << "\n\t\t>";
	cin >> option;
	bulletProof(option, 1, 4);
	return option;
}

/*********************************************************
* Function: menuOption4
* Description: When user choose option 4 from menu
			 , the sub menu in option 4 will show up
* Output: - int option: an option which user chosed
*********************************************************/
int menuOption4()
{
	int option;
	cout << "\t\t1- Checkout" << endl; //Check out
	cout << "\t\t2- Checkin" << endl; //Check in
	cout << "\t\t3- Activity" << endl;
	cout << "\t\t4- Return to Main Menu" << endl; // Return to main menu
	cout << "\n\t\t>";
	cin >> option;
	bulletProof(option, 1, 4);
	return option;
}

/*********************************************************
* Function: aBibliophile
* Description: This function will get a Bibliophile's infor
* Output: - Bibliophile aBibliophile - return one person
*********************************************************/
Bibliophile createBibliophile()
{
	//Input name
	cout << "\t\t\tEnter Name:\t\t";
	string name;
	getline(cin, name);
	//Input SID
	string sid;
	do
	{
		cout << "\t\t\tEnter SID\n\t\t\t(Format: xxx-xx-xxxx):\t";
		getline(cin, sid);
	} while (!checkSID(sid));
	//Input occupation
	cout << "\t\t\tEnter Occupation:\t";
	string occupation;
	getline(cin, occupation);
	//Create aBibliophile
	Bibliophile aBibliophile(name, sid, occupation);
	//Return aBibliophile
	return aBibliophile;
}

/*********************************************************
* Function: addBibliophile
* Description: This function ask the user confirm the
			   information of aBibliophile and check if
			   this aBibliophile is in the library or not
			   then add one Bibliophile at a time
* Input: - vector<Bibliophile>& allBibliophile:
		   list of Bibliohphile
* Output: a new Bibliophile added into allBibliophile
*********************************************************/
void addBibliophile(vector<Bibliophile>& allBibliophile)
{
	//Create a bibliophile
	Bibliophile aBibliophile = createBibliophile();
	//Check if this Bibliophile is in Codex Library or not
	if (checkIDorBM(allBibliophile, aBibliophile.getSID()) == false)
	{
		//Asking to confirm
		char confirm;
		cout << "\n\t\t\tConfirm Details and Press ''Y'' to Save: ";
		cin >> confirm;
		bulletProofChar(confirm);//Bulletproof
		if (confirm == 'Y' || confirm == 'y')
		{
			cout << "\n\t\t\t\tBibliophile has been Successfully Added\n" << endl;
			allBibliophile.push_back(aBibliophile);
			writeBibliophileFile(aBibliophile);
		}
		else
		{
			cout << "\n\t\t\t\tAdding Bibliophile has Failed\n" << endl;
		}
	}
	else
	{
		cout << "\n\t\t\tThis Bibliophile's SID already exists in Library CodeX" << endl;
		cout << endl;
	}

}

/*********************************************************
* Function: deleteBibliophile
* Description: This function will confirm the information
			   of Bibliophile to delete
* Input: - vector<Bibliophile>& allBibliophile:
		   List of Bibliophile
*********************************************************/
void deleteBibliophile(vector<Bibliophile>& allPeople)
{
	int count = 0;
	cout << "\t\t\tEnter Bibliophile SID to Delete: ";
	string sid;
	getline(cin, sid);
	bool qualified = false;
	//Looping to check
	for (size_t i = 0; i < allPeople.size(); i++)
	{
		if (sid == allPeople.at(i).getSID())
		{
			qualified = true;
			char confirm;
			cout << "\n\t\t\tConfirm Details and Press ''Y'' to Save: ";
			cin >> confirm;
			bulletProofChar(confirm); //Bulletproof
			if (confirm == 'Y' || confirm == 'y')
			{
				cout << "\n\t\t\t" << allPeople.at(i).getName() + ", SID: " <<
					allPeople.at(i).getSID() << " has been Successfully Deleted" <<
					endl << endl;
				allPeople.erase(allPeople.begin() + i);
				deleteBibliophileFile(allPeople);
			}
			else
			{
				cout << "\n\t\t\t\tDelete Bibliophile has Failed\n" << endl;
			}
		}
	}
	if (qualified == false)
	{
		cout << "\n\t\tBibliophile SID not registered in Library CodeX" << endl;
		cout << endl;
	}
}

/*********************************************************
* Function: createBook
* Description: This function will get a book's infor
* Output: - return aBook: return one book
*********************************************************/
Book createBook()
{
	//Input title
	cout << "\t\t\tEnter Title:\t\t";
	string title;
	getline(cin, title);
	//Input author
	cout << "\t\t\tEnter Author:\t\t";
	string author;
	getline(cin, author);
	//Input year published
	cout << "\t\t\tEnter Year Published:\t";
	int yearPublished;
	cin >> yearPublished;
	bulletProof(yearPublished, 1, 2019);
	//Input publisher
	cout << "\t\t\tEnter Publisher:\t";
	string publisher;
	getline(cin, publisher);
	//Input edition
	cout << "\t\t\tEnter Edition:\t\t";
	string edition;
	getline(cin, edition);
	//Input ISBN
	string ISBN;
	do
	{
		cout << "\t\t\tEnter ISBN\n\t\t\t(Format: xxx-xxxxxxxx): ";
		getline(cin, ISBN);
	} while (!checkISBN(ISBN));
	//Create a book
	Book aBook;
	try
	{
		aBook = Book(title, author, edition, yearPublished, publisher, ISBN);
	}
	catch (invalid_argument &e)
	{
		cout << "\t\t\t" << e.what() << endl;
	}
	//Return a book
	return aBook;
}

/*********************************************************
* Function: addBook
* Description: This function ask the user confirm the
			   information of book and check if
			   this book is in the library or not
			   then add one book at a time
* Input: - vector<Book>& allBooks: a list of book
* Output: a new book added into allBooks
*********************************************************/
void addBook(vector<Book>& allBooks)
{
	//Create a book
	Book aBook = createBook();
	//Check if this book is in Codex Library or not
	if (checkIDorBM(allBooks, aBook.getBookISBN()) == false)
	{
		if (aBook.getBookISBN() == "")
		{
			cout << "\n\t\t\tISBN needed to add Book in Library CodeX" << endl << endl;
		}
		else
		{
			//Asking to confirm
			char confirm;
			cout << "\n\t\t\tConfirm Details and Press ''Y'' to Save: ";
			cin >> confirm;
			bulletProofChar(confirm); //Bulletproof		
			//Adding one book if user say y/Y (mean yes)	
			if (confirm == 'Y' || confirm == 'y')
			{
				allBooks.push_back(aBook);
				writeBookFile(aBook);
				cout << "\n\t\t\tBook has been Successfully Added" << endl;
				cout << endl;
			}
			else
			{
				cout << "\n\t\t\ttAdding Book has Faild\n" << endl;
			}
		}
	}
	//Fail adding book if user say n/N (mean no)
	else
	{
		cout << "\n\t\t\tBooks already exists in Library CodeX" << endl;
		cout << endl;
	}
}

/*********************************************************
* Function: changeBook
* Description: This function will change the book's infor
* Input: vector<Book>& allBooks: list of book
* Output: a new book added in to allBooks
*********************************************************/
void changeBook(vector<Book>& allBooks)
{
	int count = 0;
	cout << "\t\t\tEnter Book ISBN: ";
	string iSBN;
	getline(cin, iSBN);
	bool qualified = false;
	for (size_t i = 0; i < allBooks.size(); i++)
	{
		if (iSBN == allBooks.at(i).getBookISBN())
		{
			qualified = true; //Check if this book is in library or not
			if (allBooks.at(i).getBookStatus() == false)
			{
				Book bookChange = createBook();
				if (checkIDorBM(allBooks, bookChange.getBookISBN()) == false)
				{
					allBooks.at(i) = bookChange;
					deleteOrChangeBookFile(allBooks);
					cout << "\n\t\t\tBook has been changed Successfully" << endl;
					cout << endl;
				}
				else
				{
					cout << "\n\t\t\tBook ISBN already exists in Library CodeX" << endl;
					cout << endl;
				}
			}
			else
			{
				cout << "\n\n\t\t\tThis Book must be returned before any changes" << endl;
				cout << endl;
			}
		}
	}
	if (qualified == false)
	{
		cout << "\t\t\tBook has not been registered in Library CodeX" << endl;
		cout << endl;
	}
}

/*********************************************************
* Function: deleteBook
* Description: This function will delete the book
* Input: vector<Book>& allBooks: a list all of book
* Output:  a book chosed is deleted
*********************************************************/
void deleteBook(vector<Book>& allBooks)
{
	int count = 0;
	cout << "\t\t\tEnter ISBN to Delete:\t";
	string ISBN;
	getline(cin, ISBN);
	for (size_t i = 0; i < allBooks.size(); i++)
	{
		if (ISBN == allBooks.at(i).getBookISBN())
		{
			count++; //Check the book is in Codex library or not		
			char confirm;
			cout << "\n\t\t\tConfirm Details and Press ''Y'' to Save: ";
			cin >> confirm;
			bulletProofChar(confirm);//Bulletproof			
			if (confirm == 'Y' || confirm == 'y')
			{
				cout << "\n\t\t\tBook Title:" << allBooks.at(i).getBookAuthor() <<
					", ISBN: " << allBooks.at(i).getBookISBN() <<
					" has been Successfully Deleted" << endl << endl;
				allBooks.erase(allBooks.begin() + i);
				deleteOrChangeBookFile(allBooks);
			}
			else
			{
				cout << "\n\t\t\t\tBook Failed to be Deleted\n" << endl;
				cout << endl;
			}
		}
	}
	if (count == 0)
	{
		cout << "\n\t\t\tThis ISBN does not exist in Library CodeX" << endl;
		cout << endl;
	}
}

/*********************************************************
* Function: checkOutDate
* Description: This function lets a bibliophile checkout a book
* Input: allBooks - vector of Books
*		 allPeople - vector of Bibliophiles
*		 allRecords - vector of Activities
*********************************************************/
void checkOutDate(vector<Book>& allBooks, vector<Bibliophile>& allPeople, vector<Activity>& allRecords)
{
	Bibliophile aBibliophile;
	bool qualifiedSID = false, qualifiedISBN = false;
	string sid = "";
	if (allBooks.size() > 0)
	{
		cout << "\t\tEnter Bibliophile SID:\t";
		getline(cin, sid);
		for (size_t i = 0; i < allPeople.size(); i++)
		{
			if (sid == allPeople.at(i).getSID())
			{
				qualifiedSID = true;
				aBibliophile = allPeople.at(i);
			}
		}
		if (qualifiedSID == true)
		{
			cout << "\t\tEnter ISBN:\t\t";
			string iSBN;
			getline(cin, iSBN);
			for (size_t i = 0; i < allBooks.size(); i++)
			{
				if (iSBN == allBooks.at(i).getBookISBN())
				{
					if (allBooks.at(i).getBookStatus() == false)
					{
						qualifiedISBN = true;
						allBooks.at(i).setBibliophileID(aBibliophile.getSID());	//Seting the SID of owner				
						allBooks.at(i).setBookStatus(true);	//Marking this book is taken
						Activity aRecord(allBooks.at(i).getBibliophileID(),
							allBooks.at(i).getBookISBN(), getCurrentTime());
						allRecords.push_back(aRecord); // Adding a record to the main record
						writeActivityFile(allRecords); //Saving record to text file 
						cout << "\n\t\tBook has been successfuly Checked Out" << endl;
						cout << endl;
					}
					else
					{
						cout << "\n\t\tBook is currently being borrowed. Please select another book." << endl;
						cout << endl;
						return;
					}
				}
			}
			if (qualifiedISBN == false)
			{
				cout << "\n\t\tBook is not in Library CodeX" << endl;
				cout << endl;
			}
		}
		else if (qualifiedSID == false)
		{
			cout << "\n\t\tSID is not in Library CodeX, please create SID account then try again" << endl;
			cout << endl;
		}
	}
	else
		cout << "\t\tThere are currently no books.\n" << endl;
}

/*********************************************************
* Function: checkInDate
* Description: This function allows the bibliphile to return
*			   a book after checking it out.
* Input: allBooks - vector of Book objects
*		 allPeople - vector of Bibliophile objects
*		 allRecords - vector of Activity objects
*********************************************************/
void checkInDate(vector<Book>& allBooks, vector<Bibliophile>& allPeople, vector<Activity>& allRecords)
{
	string getISBNReturn;
	bool qualified = false;
	if (allBooks.size() == 0)
	{
		cout << "\t\tThere are currently no books." << endl;
		cout << endl;
		return;
	}
	cout << "\t\tEnter Book ISBN to Check In:\t";
	string isbn;
	getline(cin, isbn);
	//Return book from here
	for (size_t i = 0; i < allBooks.size(); i++)
	{
		if (isbn == allBooks.at(i).getBookISBN())
		{
			// the allBooks.at(i).setOwner() will be overide for the next person
			// for now just set the book available by setting it false.
			allBooks.at(i).setBookStatus(false);
			qualified = true;
			getISBNReturn = allBooks.at(i).getBookISBN(); // Need this step to set day return later on.
			cout << "\t\tBook has been Successfuly Returned" << endl;
			cout << endl;
		}
	}
	//Assign record from here
	for (size_t i = 0; i < allRecords.size(); i++)
	{
		if (getISBNReturn == allRecords.at(i).getISBN())
		{
			allRecords.at(i).setCheckedInDate(getCurrentTime());
			writeActivityFile(allRecords);
		}
	}
	//If storage is empty
	if (qualified == false)
	{
		cout << "\t\tBook is not in Library CodeX, please create Book then try again" << endl;
		cout << endl;
	}
}

/*********************************************************
* Function: printActivity
* Description: This function prints out the activities
* Input: allRecords - vector of Activitie objecs
*********************************************************/
void printActivity(const vector<Activity>& allActivity)
{
	if (allActivity.size() == 0)
		cout << "\t\t - There is no current Activity\n" << endl;
	else
	{
		for (size_t i = 0; i < allActivity.size(); i++)
		{
			cout << "\t\t - " + allActivity.at(i).toString() << endl;
		}
	}
}

/*********************************************************
* Function: searchAllBook
* Description: This functions displays all the Books registered
*			   in the system.
* Input: allBooks - a vector of Book objects
*********************************************************/
void searchAllBook(const vector<Book>& allBooks)
{
	if (allBooks.size() == 0)
	{
		cout << "\t\tThere are no Books registered in Library CodeX" << endl;
	}
	else
	{
		for (size_t i = 0; i < allBooks.size(); i++)
		{
			cout << "\t\t - " + allBooks.at(i).toString() << endl;
		}
	}
}

/*****************************************************************
* Function: searchBookByISBN
* Description: This function searches for books based
*			   of the ISBN and displays the users who've checked
*			   out that book.
* Input: allRecords - a vector of Activity objects
******************************************************************/
void searchBookByISBN(vector<Activity>& allRecords)
{
	int flag = 0;
	bool searchSID = false;
	string ISBN;
	cout << "\t\tEnter ISBN:\t";
	getline(cin, ISBN);
	for (size_t i = 0; i < allRecords.size(); i++)
	{
		if (ISBN == allRecords.at(i).getISBN())
		{
			cout << "\t\t - " << allRecords.at(i).goSearch(searchSID) << endl;
			flag = 1;
		}
		if (i == allRecords.size() - 1 && flag == 0)
			searchSID = true;
	}
	if (searchSID == true)
	{
		cout << "\n\t\tBook has no Activity in Library CodeX" << endl << endl;
	}
}

/*********************************************************
* Function: searchBibliophileId
* Description: This function looks up a user's SID and
*			   displays the user's checked out books.
* Input: allPeople - a vector of Bibliophile objects
*	     allRecods - a vector of Activity objects
*********************************************************/
void searchBibliophileId(vector<Activity>& allRecords)
{
	int flag = 0;
	bool searchID = true;
	cout << "\t\tEnter Bibliophile SID:\t";
	string SID;
	getline(cin, SID);
	for (size_t i = 0; i < allRecords.size(); i++)
	{
		if (SID == allRecords.at(i).getSID())
		{
			cout << "\t\t - " + allRecords.at(i).goSearch(searchID) << endl;
			flag = 1;
		}
		if (i == allRecords.size() - 1 && flag == 0)
			searchID = false;
	}
	if (searchID == false)
	{
		cout << "\n\t\tBibliophile has not been registered in Library CodeX" << endl;
		return;
	}
}