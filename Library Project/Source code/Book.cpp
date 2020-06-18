/******************************************************************************
* PROJECT: FinalProject_LibraryCodex
* FILE: Book.cpp
* AUTHOR(S): Dean Ferris, Ton That Quynh Thong , Minpyo Kim & Kalkidan Tamirat
* DATE: 3/12/2019
* DESCRIPTION: This console-based program imitates a library database & allows
*			   the user to add/delete books, bibliophiles & view their activity
******************************************************************************/
#include "Book.h"
#include "BulletProof.h"
#include <string>

using namespace std;
/***********************
 * Default Constructor
 ***********************/
Book::Book() {}

/**************************************************************************
* Constructor: Book
* Description: Initializes book with information
* Input: title - string holding title
*	     author - string holding author
*	     edition - string holding the edition
*		 yearPublished - integer holding the year published
*		 publisher - string holding publisher
*		 ISBN - string holding the ISBN
***************************************************************************/
Book::Book(string title, string author, string edition, int yearPublished, string publisher, string ISBN)
{
	setBookTitle(title);
	setBookAuthor(author);
	setYearPublished(yearPublished);
	setEdition(edition);
	setPublisher(publisher);
	setBookISBN(ISBN);
}

/**************************************************************************
* Function: setBookTitle
* Description: This function sets the book title
* Input: string - title
***************************************************************************/
void Book::setBookTitle(std::string title)
{
	Book::title = title;
}

/**************************************************************************
* Function: setBookAuthor
* Description: This function sets the author
* Input: string - author
***************************************************************************/
void Book::setBookAuthor(std::string author)
{
	Book::author = author;
}

/**************************************************************************
* Function: setYearPublished
* Description: This function sets the year published
* Input: year - integer with the year published
***************************************************************************/
void Book::setYearPublished(int year)
{
	Book::yearPublished = year;
}

/**************************************************************************
* Function: setPublisher
* Description: This function sets the publisher
* Input: string - publisher of book
***************************************************************************/
void Book::setPublisher(string publisher)
{
	Book::publisher = publisher;
}

/**************************************************************************
* Function: setEdition
* Description: This function sets the edition
* Input: string - edition of book
***************************************************************************/
void Book::setEdition(string edition)
{
	Book::edition = edition;
}

/**************************************************************************
* Function: setBookISBN
* Description: This function sets the book ISBN
* Input: string - ISBN
***************************************************************************/
void Book::setBookISBN(string iSBN)
{
	if (!checkISBN(iSBN))
		throw invalid_argument("Incorrent ISBN. Please try adding the book again.");
	else
		Book::ISBN = iSBN;
}

/**************************************************************************
* Function: setBibliophile
* Description: This function sets the name
* Input: string - SID of the Bibliophile checking out the book
***************************************************************************/
void Book::setBibliophileID(const string SID)
{
	Book::bibliophileSID = SID;
}

/**************************************************************************
* Function: setBookStatus
* Description: This function sets the book status
* Input: boolean - condition of the boko
*		 true - book is checked out
*		 false - book isn't checked out
***************************************************************************/
void Book::setBookStatus(bool condition)
{
	status = condition;
}

/**************************************************************************
* Function: getBibliophileID
* Description: This function returns the bibliophile's SID
* Output: string - bibliophile's SID
***************************************************************************/
string Book::getBibliophileID() const
{
	return bibliophileSID;
}

/**************************************************************************
* Function: getBookStatus
* Description: This function gets the Book's checked out condition
* Output: boolean - returns the condition of the book
*					true - books is checked out
*					false - book isn't checked out
***************************************************************************/
bool Book::getBookStatus() const
{
	return status;
}

/**************************************************************************
* Function: toString
* Description: This function returns the book's info in a string
* Input: string - book's information
***************************************************************************/
string Book::toString() const
{
	if (status == false)
	{
		string withOutOwner = "Title: " + title + ", Author: " + author +  
			", Published:" + to_string(yearPublished) + ", Publisher:" +
			publisher + ", Edition:" + edition + ", ISBN: " + ISBN;
		return withOutOwner;
	}
	else
	{
		string withOwner = "Title: " + title + ", Author: " + author + 
			", Published:" + to_string(yearPublished) + ", Publisher:" 
			+ publisher + ", Edition:" + edition + ", ISBN: " + ISBN
			+ "\n\t\t\tCurrently checkedout by:" + bibliophileSID;
		return withOwner;
	}
}

/**************************************************************************
* Function: getBookTitle
* Description: This function returns the title
* Output: string - book's title
***************************************************************************/
string Book::getBookTitle() const
{
	return title;
}

/**************************************************************************
* Function: getBookAuthor
* Description: This function returns the author of the book
* Output: string - name
***************************************************************************/
string Book::getBookAuthor() const
{
	return author;
}

/**************************************************************************
* Function: getBookYearPublished
* Description: This function returns the year this book was published
* Input: integer - year the book was published
***************************************************************************/
int Book::getBookYearPublished() const
{
	return yearPublished;
}

/**************************************************************************
* Function: getPublisher
* Description: This function returns the publisher
* Input: string - publisher of book
***************************************************************************/
string Book::getPublisher() const
{
	return publisher;
}

/**************************************************************************
* Function: getEdition
* Description: This function returns the edition of the book
* Output: string - the edition of the book
***************************************************************************/
string Book::getEdition() const
{
	return edition;
}

/**************************************************************************
* Function: getBookISBN
* Description: This function returns the ISBN
* Input: string - the ISBN of the book
***************************************************************************/
string Book::getBookISBN() const
{
	return ISBN;
}