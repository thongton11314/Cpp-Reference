/******************************************************************************
* PROJECT: FinalProject_LibraryCodex
* FILE: FileIO.h
* AUTHOR(S): Dean Ferris, Ton That Quynh Thong , Minpyo Kim & Kalkidan Tamirat
* DATE: 3/12/2019
* DESCRIPTION: This console-based program imitates a library database & allows
*			   user to add/delete books, bibliophiles, and view their activity
******************************************************************************/
#ifndef _FILEIO_
#define _FILEIO_

#include <vector>
#include <string>
#include "Bibliophile.h"
#include "Book.h"
#include "Activity.h"

//Function prototype

/********************************************************************
* Function:	message
* Description: It will throw a message when fail open file
* Input: string tmp: file name
* Output: file is not open
*********************************************************************/
void message(const std::string& tmp);

/********************************************************************
* Function: directoryInfo
* Description: This function will set the name for the file
* Input: int option: the option from developer to get name's file
* Output: string file name
*********************************************************************/
std::string directoryInfo(const int& option);

/********************************************************************
* Function: writeBibliophileFile
* Description: This function will add a bibliophile at the end of file
* Input: Bibliophile aBibliophile: one client
* Outout: a Bibliophile informatin in AllBibliophile.txt
*********************************************************************/
void writeBibliophileFile(const Bibliophile& aBibliophile);

/********************************************************************
* Function: deleteBibliophileFile
* Description: This function will delete bibliophile from file
* Input: vector<Bibliophile> allBibliphile: all bibliophiles
* Output: one bibliophile is deleted each time
*********************************************************************/
void deleteBibliophileFile(std::vector<Bibliophile> allBibliphile);

/********************************************************************
* Function: updateBibliophileFile
* Description: This function will update the Bibliophile from file
*			   to the array from the source.cpp
* Output: the vector type Bibliophile has all Bibliophile from file
*********************************************************************/
std::vector<Bibliophile> updateBibliophileFile();

/********************************************************************
* Function: writeBookFile
* Description: This function will add a book to the AllBook.txt
* Input: Book aBook: a book from cource.cpp
* Output: a book added to AllBook.txt
*********************************************************************/
void writeBookFile(const Book& aBook);

/********************************************************************
* Function: deleteOrChangeBookFile
* Description: It will replace the information of book in AllBook.txt
* Input: vector<Book>& allBook : all book
* Output: book's information is changed
*********************************************************************/
void deleteOrChangeBookFile(std::vector<Book>& allBook);

/********************************************************************
* Function: updateBookFile
* Description: Assign the all book from the text file
*			   to the vector typw of book
* Output : vector<Book> tempReturn : the entire array has all book
*********************************************************************/
std::vector<Book> updateBookFile();

/********************************************************************
* Function: writeActivityFile
* Description: Write the activity in the Activity.txt
* Input: vector<Activity>& allActivity: all activity
* Output: all activities are in the file
*********************************************************************/
void writeActivityFile(const std::vector<Activity>& allActivity);

/********************************************************************
* Function: updateActivityFile
* Description: Assign all activity from file to vector
* Output: vector<Activity> tempReturn: a vector has all of activities
*********************************************************************/
std::vector<Activity> updateActivityFile();

#endif // !_FILEIOTEMP_
