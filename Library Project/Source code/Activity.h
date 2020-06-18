/********************************************************************************
* PROJECT: FinalProject_LibraryCodex
* FILE: Activity.h
* AUTHOR(S): Dean Ferris, Ton That Quynh Thong , Minpyo Kim & Kalkidan Tamirat
* DATE: 3/12/2019
* DESCRIPTION: This console-based program imitates a library database and allows
*			   the user to add/delete books, bibliophiles, and view their activity.
********************************************************************************/
#ifndef _ACTIVITY_
#define _ACTIVITY_
#include <string>
#include <vector>

/******************************************************************************
* CLASS: Activity
* DESCRIPTION: This is a list of records regarding books, the bibliophile,
*			   who checked them out and when they checked it out/in
******************************************************************************/
class Activity
{
private:
	std::string sID;
	std::string bookISBN;
	std::string checkedOutDate;
	std::string checkedInDate;
	bool search;
	std::string dueDate;
public:

	/**************************************************************************
	* Constructor: Activity
	* Description: Default constructor
	*************************************************************************/
	Activity();

	/**************************************************************************
	 * Constructor: Activity
	 * Description: Initializes the Activity object 
	 * Input: SID - string with the bilbiophile's SID
	 *		  bookISBN - string of the book's ISBN
	 *		  checkedOutDate - today's date
	 *************************************************************************/
	Activity(std::string SID, std::string bookISBN, std::string checkedOutDate);

	/**************************************************************************
	* Function: toString
	* Description: Returns a string with the Activity's information to the user
	* Output: string - Activity's info (SID, bookISBN, checkedOut/InDate
	***************************************************************************/
	std::string toString() const;

	/**************************************************************************
	* Function: setCheckedOutDate
	* Description: Sets the checked out date
	* Input: string - the checked out date
	***************************************************************************/
	void setCheckedOutDate(std::string checkedOut);

	/**************************************************************************
	* Function: setCheckedInDate
	* Description: Sets the checked in date
	* Input: string - the checked in date
	***************************************************************************/
	void setCheckedInDate(std::string checkedIn);

	/**************************************************************************
	* Function: goSearch
	* Description: Returns a string with the specific information depending on the 
	*			   search criteria
	* Input: search - a boolean that determines whether ISBN or SID should be returned
	*			     true - ISBN is concatenated in the string but SID isn't
	*				 false - SID is concatenated in the string but ISBN isn't
	* Output: string - the searched activity's info
	***************************************************************************/
	std::string goSearch(bool search);

	/**************************************************************************
	* Function: getSID
	* Description: Returns the activity's SID
	* Output: string - the SID
	***************************************************************************/
	std::string getSID() const;

	/**************************************************************************
	* Function: getISBN
	* Description: Returns the ISBN
	* Output: string - the ISBN
	***************************************************************************/
	std::string getISBN() const;

	/**************************************************************************
	* Function: getCheckedOutDate
	* Description: Returns the checked out date
	* Output: string - the checked out date
	***************************************************************************/
	std::string getCheckedOutDate() const;

	/**************************************************************************
	* Function: setCheckedInDate
	* Description: Returns the checked in date
	* Output: string - the checked in date
	***************************************************************************/
	std::string getCheckedInDate() const;

	/**************************************************************************
	* Function: setDueDate
	* Description: Calculates the due date (adds 8 days from the day it's been
	*			   checked out
	***************************************************************************/
	void setDueDate();

	/**************************************************************************
	* Function: getDueDate
	* Description: Calculates the due date (adds 8 days from the day it's been
	*			   checked out
	***************************************************************************/
	std::string getDueDate() const;
};
#endif


