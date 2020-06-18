/********************************************************************************
* PROJECT: FinalProject_LibraryCodex
* FILE: Activity.cpp
* AUTHOR(S): Dean Ferris, Ton That Quynh Thong , Minpyo Kim & Kalkidan Tamirat
* DATE: 3/12/2019
* DESCRIPTION: This console-based program imitates a library database and allows
*			   the user to add/delete books, bibliophiles, and view their activity.
********************************************************************************/
#include "Activity.h"
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

/**************************************************************************
* Constructor: Activity
* Description: Default constructor
*************************************************************************/
Activity::Activity() {}

/**************************************************************************
 * Constructor: Activity
 * Description: Initializes the Activity object
 * Input: SID - string with the bilbiophile's SID
 *		  bookISBN - string of the book's ISBN
 *		  checkedOutDate - today's date
 *************************************************************************/
Activity::Activity(std::string sID, std::string bookISBN, std::string checkedOutDate)
{
	Activity::sID = sID;
	Activity::bookISBN = bookISBN;
	Activity::checkedOutDate = checkedOutDate;
	setDueDate();
}

/**************************************************************************
 * Function: toString
 * Description: Returns a string with the Activity's information to the user
 * Output: string - Activity's info (SID, bookISBN, checkedOut/InDate
 ***************************************************************************/
string Activity::toString() const 
{
	string status = "SID: " + sID + "\t";
	status += "ISBN: " + bookISBN;
	status += "\tChecked Out Date: " + checkedOutDate +
		"\tDue Date: " + dueDate;
	if (checkedInDate != "")
		status += "\tChecked In: " + checkedInDate;
	return status;
}

/**************************************************************************
* Function: goSearch
* Description: Returns a string with the specific information depending on the
*			   search criteria
* Input: search - a boolean that determines whether ISBN or SID should be returned
*			     true - ISBN is concatenated in the string but SID isn't
*				 false - SID is concatenated in the string but ISBN isn't
* Output: string - the searched activity's info
***************************************************************************/
string Activity::goSearch(bool search)
{
	string status;
	if (search)
		status = "ISBN: " + bookISBN;
	else
		status = "SID: " + sID;
	status += "\tChecked Out Date: " + checkedOutDate +
		"\tDue Date: " + dueDate;
	if (checkedInDate != "")
		status += "\tChecked In: " + checkedInDate;
	return status;
}

/**************************************************************************
* Function: setCheckedOutDate
* Description: Sets the checked out date
* Input: string - the checked out date
***************************************************************************/
void Activity::setCheckedOutDate(string checkedOut)
{
	checkedOutDate = checkedOut;
}

/**************************************************************************
* Function: setCheckedInDate
* Description: Sets the checked in date
* Input: string - the checked in date
***************************************************************************/
void Activity::setCheckedInDate(string checkedIn)
{
	checkedInDate = checkedIn;
}

/**************************************************************************
* Function: getDueDate
* Description: Calculates the due date (adds 8 days from the day it's been
*			   checked out
***************************************************************************/
void Activity::setDueDate() 
{
	string date = checkedOutDate;
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	size_t index = date.find("/");
	int month = stoi(date.substr(0, index));
	index++;
	int day = stoi(date.substr(index, date.find("/", index)));
	index = date.find("/", index);
	int year = stoi(date.substr(index + 1));
	day += 8;
	if (day > daysInMonth[month-1])
	{
		if (month == 12)
		{
			year++;
			day -= daysInMonth[month - 1];
			month = 1;
		}
		day -= daysInMonth[month - 1];
		month++;
	}
	dueDate = to_string(month) + "/" + to_string(day) + "/" + to_string(year) + " 11:59";
	string temp = dueDate;
}

string  Activity::getDueDate() const
{
	return dueDate;
}

/**************************************************************************
* Function: getCheckedOutDate
* Description: Returns the checked out date
* Output: string - the checked out date
***************************************************************************/
string Activity::getCheckedOutDate() const
{
	return checkedOutDate;
}

/**************************************************************************
 * Function: setCheckedInDate
 * Description: Returns the checked in date
 * Output: string - the checked in date
 ***************************************************************************/
string Activity::getCheckedInDate() const
{
	return checkedInDate;
}

/**************************************************************************
* Function: getSID
* Description: Returns the activity's SID
* Output: string - the SID
***************************************************************************/
string Activity::getSID() const
{
	return sID;
}

/**************************************************************************
* Function: getISBN
* Description: Returns the ISBN
* Output: string - the ISBN
***************************************************************************/
std::string Activity::getISBN() const
{
	return bookISBN;
}