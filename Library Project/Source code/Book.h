/******************************************************************************
* PROJECT: FinalProject_LibraryCodex
* FILE: Book.h
* AUTHOR(S): Dean Ferris, Ton That Quynh Thong , Minpyo Kim & Kalkidan Tamirat
* DATE: 3/12/2019
* DESCRIPTION: This console-based program imitates a library database & allows
*			   the user to add/delete books, bibliophiles & view their activity
******************************************************************************/
#ifndef _BOOK_
#define _BOOK_
#include <string>
#include "Bibliophile.h"

/*********************************************************
 * Class: Book
 * Description: A class that represents a book
 ********************************************************/
class Book
{
private:
	std::string title;
	std::string author;
	int yearPublished;
	std::string edition;
	std::string ISBN;
	std::string publisher;
	std::string bibliophileSID;
	bool status = false;
public:
	Book();

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
	Book(std::string title, std::string author, std::string edition, 
		int yearPublished, std::string publisher, std::string ISBN);

	/**************************************************************************
	* Function: setBookTitle
	* Description: This function sets the book title
	* Input: string - title
	***************************************************************************/
	void setBookTitle(std::string title);

	/**************************************************************************
	* Function: setBookAuthor
	* Description: This function sets the author
	* Input: string - author
	***************************************************************************/
	void setBookAuthor(std::string author);

	/**************************************************************************
	* Function: setYearPublished
	* Description: This function sets the year published
	* Input: year - integer with the year published
	***************************************************************************/
	void setYearPublished(int year);

	/**************************************************************************
	* Function: setEdition
	* Description: This function sets the edition
	* Input: string - edition of book
	***************************************************************************/
	void setEdition(std::string edition);

	/**************************************************************************
	* Function: setPublisher
	* Description: This function sets the publisher
	* Input: string - publisher of book
	***************************************************************************/
	void setPublisher(std::string publisher);

	/**************************************************************************
	* Function: setBookISBN
	* Description: This function sets the book ISBN
	* Input: string - ISBN
	***************************************************************************/
	void setBookISBN(std::string ISBN);

	/**************************************************************************
	* Function: setBookStatus
	* Description: This function sets the book status
	* Input: boolean - condition of the boko
	*		 true - book is checked out 
	*		 false - book isn't checked out
	***************************************************************************/
	void setBookStatus(bool condition);

	/**************************************************************************
	* Function: setBibliophile
	* Description: This function sets the name
	* Input: string - SID of the Bibliophile checking out the book
	***************************************************************************/
	void setBibliophileID(std::string SID);

	/**************************************************************************
	* Function: getBibliophileID
	* Description: This function returns the bibliophile's SID
	* Output: string - bibliophile's SID
	***************************************************************************/
	std::string getBibliophileID() const;

	/**************************************************************************
	* Function: getBookStatus
	* Description: This function gets the Book's checked out condition
	* Output: boolean - returns the condition of the book
	*					true - books is checked out
	*					false - book isn't checked out
	***************************************************************************/
	bool getBookStatus() const;

	/**************************************************************************
	* Function: toString
	* Description: This function returns the book's info in a string
	* Input: string - book's information
	***************************************************************************/
	std::string toString() const;

	/**************************************************************************
	* Function: getBookTitle
	* Description: This function returns the title
	* Output: string - book's title
	***************************************************************************/
	std::string getBookTitle() const;

	/**************************************************************************
	* Function: getBookAuthor
	* Description: This function returns the author of the book
	* Output: string - name
	***************************************************************************/
	std::string getBookAuthor() const;

	/**************************************************************************
	* Function: getBookYearPublished
	* Description: This function returns the year this book was published
	* Input: integer - year the book was published
	***************************************************************************/
	int getBookYearPublished() const;

	/**************************************************************************
	* Function: getPublisher
	* Description: This function returns the publisher
	* Input: string - publisher of book
	***************************************************************************/
	std::string getPublisher() const;

	/**************************************************************************
	* Function: getEdition
	* Description: This function returns the edition of the book
	* Output: string - the edition of the book
	***************************************************************************/
	std::string getEdition() const;

	/**************************************************************************
	* Function: getBookISBN
	* Description: This function returns the ISBN
	* Input: string - the ISBN of the book
	***************************************************************************/
	std::string getBookISBN() const;
};

#endif