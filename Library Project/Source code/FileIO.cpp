/******************************************************************************
* PROJECT: FinalProject_LibraryCodex
* FILE: FileIOtemp.cpp
* AUTHOR(S): Dean Ferris, Ton That Quynh Thong, Minpyo Kim and Kalkidan Tamirat
* DATE: 3/12/2019
* DESCRIPTION: This console-based program imitates a library database & allows
*			   user to add/delete books, bibliophiles, and view their activity.
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <ios>
#include <direct.h>
#include "FileIO.h"

using namespace std;

/********************************************************************
* Function:	message
* Description: It will throw a message when fail open file
* Input: string tmp: file name
* Output: file is not open
*********************************************************************/
void message(const string& tmp)
{
	string message = "File not open " + tmp;
	throw invalid_argument(message);
}

/********************************************************************
* Function: directoryInfo
* Description: This function will set the name for the file
* Input: int option: the option from developer to get name's file
* Output: string file name
*********************************************************************/
string directoryInfo(const int& option)
{	
	if (option == 1)
	{		
		return "AllBibliophile.txt";
	}
	else if (option == 2)
	{		
		return "AllBooks.txt";
	}
	else if (option == 3)
	{		
		return  "AllActivity.txt";
	}
	else
		throw out_of_range("Please select option");
}

/********************************************************************
* Function: writeBibliophileFile
* Description: This function will add a bibliophile at the end of file
* Input: Bibliophile aBibliophile: one client
* Outout: a Bibliophile informatin in AllBibliophile.txt
*********************************************************************/
void writeBibliophileFile(const Bibliophile& aBibliophile)
{	
	ofstream file(directoryInfo(1), ios::app);
	if ((file.is_open()))
	{
		file << aBibliophile.getName() << ".";
		file << aBibliophile.getSID() << ".";
		file << aBibliophile.getOccupation();
		file << '\n';
		file.close();
	}
	else
	{
		message(directoryInfo(1));
	}
}

/********************************************************************
* Function: deleteBibliophileFile
* Description: This function will delete bibliophile from file
* Input: vector<Bibliophile> allBibliphile: all bibliophiles
* Output: one bibliophile is deleted each time
*********************************************************************/
void deleteBibliophileFile(vector<Bibliophile> allBibliphile)
{
	ofstream file(directoryInfo(1), ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0; i < allBibliphile.size(); i++)
		{
			file << allBibliphile.at(i).getName() << ".";
			file << allBibliphile.at(i).getSID() << ".";
			file << allBibliphile.at(i).getOccupation();
			file << '\n';
		}
		file.close();
	}
	else
		message(directoryInfo(1));
}

/********************************************************************
* Function: updateBibliophileFile
* Description: This function will update the Bibliophile from file
to the array from the source.cpp
* Output: the vector type Bibliophile has all Bibliophile from file
*********************************************************************/
vector<Bibliophile> updateBibliophileFile()
{
	vector<Bibliophile> tempReturn;
	string name, occupation, sID;
	ifstream file(directoryInfo(1), ios::in);
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, name, '.');
			getline(file, sID, '.');
			if (sID == "")
				throw invalid_argument("There are currently no bibliophiles");
			getline(file, occupation);
			Bibliophile temp(name, sID, occupation);
			tempReturn.push_back(temp);
		}
		tempReturn.pop_back(); //Back door cleanbuffer.
		file.close();
	}
	else
		message(directoryInfo(1));
	return tempReturn;
}

/********************************************************************
* Function: writeBookFile
* Description: This function will add a book to the AllBook.txt
* Input: Book aBook: a book from cource.cpp
* Output: a book added to AllBook.txt
*********************************************************************/
void writeBookFile(const Book& aBook)
{
	ofstream file(directoryInfo(2), ios::app);
	if (file.is_open())
	{
		cin.ignore(10, '\n');
		file << aBook.getBookTitle() << "." <<
			aBook.getBookAuthor() << "." <<
			aBook.getPublisher() << "." <<
			aBook.getEdition() << "." <<
			aBook.getBookISBN() << "." <<
			aBook.getBookYearPublished();
		file << '\n';
		file.close();
	}
	else
		message(directoryInfo(2));
}

/********************************************************************
* Function: deleteOrChangeBookFile
* Description: This function will delete book or change book in file
* Input: vector<Book>& allBook : all of book
* Output: the book change or deelte
*********************************************************************/
void deleteOrChangeBookFile(vector<Book>& allBook)
{
	ofstream file(directoryInfo(2), ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0; i < allBook.size(); i++)
		{
			file << allBook.at(i).getBookTitle() << "." <<
				allBook.at(i).getBookAuthor() << "." <<
				allBook.at(i).getPublisher() << "." <<
				allBook.at(i).getEdition() << "." <<
				allBook.at(i).getBookISBN() << "." <<
				allBook.at(i).getBookYearPublished();
			file << '\n';
		}
		file.close();
	}
	else
		message(directoryInfo(2));
}

/********************************************************************
* Function: updateBookFile
* Description: Assign the all book from the text file
*			   to the vector typw of book
* Output : vector<Book> tempReturn : the entire array has all book
*********************************************************************/
vector<Book> updateBookFile()
{	
	vector<Book> tempReturn;
	string title, author, publisher, yearPublishedString, edition, iSBN, SID;
	int yearPublishedInt = 0;
	ifstream file(directoryInfo(2));
	if (file.is_open())
	{
		while (!file.eof())
		{			
			getline(file, title, '.');
			getline(file, author, '.');
			getline(file, publisher, '.');
			getline(file, edition, '.');
			getline(file, iSBN, '.');
			if(iSBN == "")				
				throw invalid_argument("There are currently no books.");
			getline(file, yearPublishedString);
			yearPublishedInt = stoi(yearPublishedString); //convert string to int.
			Book temp(title, author, edition, yearPublishedInt, publisher, iSBN);
			tempReturn.push_back(temp);
		}
		tempReturn.pop_back(); //Back door cleanbuffer.
		file.close();
	}
	else
		message(directoryInfo(2));
	return tempReturn;
}

/********************************************************************
* Function: writeActivityFile
* Description: Write the activity in the Activity.txt
* Input: vector<Activity>& allActivity: all activity
* Output: all activities are in the file
*********************************************************************/
void writeActivityFile(const vector<Activity>& allActivity)
{
	ofstream file(directoryInfo(3), ios::trunc);
	if (file.is_open())
	{
		if (allActivity.size() > 0)
		{
			for (size_t i = 0; i < allActivity.size(); i++)
			{
				file << allActivity.at(i).getSID() << ".";
				file << allActivity.at(i).getISBN() << ".";
				file << allActivity.at(i).getCheckedOutDate() << ".";
				file << allActivity.at(i).getDueDate() << ".";
				file << allActivity.at(i).getCheckedInDate() << ".";
				file << '\n';
			}
		}
		file.close();
	}
	else
		message(directoryInfo(3));
}

/********************************************************************
* Function: updateActivityFile
* Description: Assign all activity from file to vector
* Output: vector<Activity> tempReturn: a vector has all of activities
*********************************************************************/
vector<Activity> updateActivityFile()
{
	vector<Activity> tempReturn;
	ifstream file(directoryInfo(3));
	string sID, iSBN, checkOutDate, dueDate, checkInDate;
	if (file.is_open())
	{
		while (!file.eof())
		{		
				getline(file, sID, '.');
				getline(file, iSBN, '.');
				if(iSBN == "")
					throw invalid_argument("There are currently no activities.");
				getline(file, checkOutDate, '.');
				getline(file, dueDate, '.');
				getline(file, checkInDate, '.');
				Activity tempActivity(sID, iSBN, checkOutDate);
				tempActivity.setCheckedInDate(checkInDate);
				tempReturn.push_back(tempActivity);
				file.ignore(100, '\n');			
				
		}
		tempReturn.pop_back(); //Back door cleanbuffer.
		file.close();
	}
	else
		message(directoryInfo(3));
	return tempReturn;
}
