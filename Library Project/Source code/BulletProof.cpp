/*******************************************************************************
* PROJECT: FinalProject_LibraryCodex
* FILE:	BulletProof.cpp
* AUTHORS: Dean Ferris, Ton That Quynh Thong, Minpyo Kim and Kalkidan Tamirat
* DATE: 3/12/2019
* DESCRIPTION: Source file of BulletProof.h
*******************************************************************************/
#include <iostream>
#include <string>
#include "BulletProof.h"

using namespace std;

/******************************************************************************
* Function: cleanPipe
* Description: This function clears the string variable.
******************************************************************************/
void cleanPipe()
{
	cin.clear();
	cin.ignore(100, '\n');
}

/******************************************************************************
* Function: bulletProof
* Description: function prompts user for input than validate it
* Input: T& input - User input that transfered.
*		 int& lowBound - lower bound of selection.
*		 int& upBound - upper bound of selection.
******************************************************************************/
//template <typename T>
//void bulletProof(T& input, const int& lowBound, const int& upBound)
void bulletProof(int& input, const int& lowBound, const int& upBound)
{
	//Declaration of variables
	bool check = true;
	while (check)
	{
		if (cin.fail())
		{
			cleanPipe();
			cout << "\n\t\tPlease enter number within range" << endl;
			cout << "\t\t> ";
			cin >> input;
		}
		else if (lowBound > input || input > upBound)
		{
			cleanPipe();
			cout << "\n\t\tPlease enter a number between "
				<< lowBound << " and " << upBound;
			cout << "\n\t\t> ";
			cin >> input;
		}
		else
			check = false;
	}
	cleanPipe();
}

/******************************************************************************
* Function: bulletProofChar
* Description: Function prompt if user input outside of (y/n)
* Input: char& input - User input that transfered.
******************************************************************************/
void bulletProofChar(char& input)
{
	while (input != 'y' && input != 'Y' && input != 'n' && input != 'N')
	{
		cout << "\n\t\t\tInvalid input, y/n only, try again" << endl;
		cout << "\t\t\t> ";
		cin >> input;
	}
	cleanPipe();
}

/******************************************************************************
* Function: checkIDorBM
* Description: This overload function check that if book ISBN in library or not
* Input: const vector<Book>& trans - whole vector type book
		 const string& tmp - specific ISBN number
* Output: return true - if this ISBN is in library
		  return false - if this ISBN is not in library		 
******************************************************************************/
bool checkIDorBM(const vector<Book>& trans, const string& tmp)
{
	for (unsigned int i = 0; i < trans.size(); i++)
	{
		if (tmp == trans.at(i).getBookISBN())			
			return true;
	}
	return false;
}

/******************************************************************************
* Function: checkIDorBM
* Description: This overload function check that if book SID in library or not
* Input: const vector<Bibliophile>& trans - whole vector type Bibliophile
		 const string& tmp - specific SID number
* Output: return true - if this SID is in library
		  return false - if this SID is not in library
		  recieve the current index if matching by pass by reference
******************************************************************************/
bool checkIDorBM(const vector<Bibliophile>& trans, const string& tmp)
{
	for (unsigned int i = 0; i < trans.size(); i++)
	{
		if (tmp == trans.at(i).getSID())		
			return true;
	}
	return false;
}

/******************************************************************************
* Function: checkSID
* Description: This function checks to see if the user entered a valid SID
* Input: sid - const string with a potential SID number
* Output: return true - if this SID is valid
		  return false - if the SID isn't valid
******************************************************************************/
bool checkSID(const string sid)
{
	char letter;
	if (sid.length() != 11)
	{
		cout << "\t\t\tError. Please follow the proper format." << endl;
		return false;
	}
	for (int i = 0; i < 3; i++)
	{
		letter = sid.at(i);
		if (!checkInput(letter))
			return false;
	}
	letter = sid.at(3);
	if (letter != '-')
	{
		cout << "\t\t\tError. Please follow the proper format." << endl;
		return false;
	}
	for (int i = 4; i < 6; i++)
	{
		letter = sid.at(i);
		if (!checkInput(letter))
			return false;
	}
	letter = sid.at(6);
	if (letter != '-')
	{
		cout << "\t\t\tError. Please follow the proper format." << endl;
		return false;
	}
	for (int i = 7; i < sid.size(); i++)
	{
		letter = sid.at(i);
		if (!checkInput(letter))
			return false;
	}
	return true;
}

/******************************************************************************
* Function: checkISBN
* Description: This function checks to see if the user entered a valid ISBN
* Input: isbn - const string with a potential ISBN
* Output: return true - if this ISBN is valid
		  return false - if the ISBN isn't valid
******************************************************************************/
bool checkISBN(const string isbn)
{
	if (isbn.length() != 13)
		return false;
	char letter;
	for (int i = 0; i < 3; i++)
	{
		letter = isbn.at(i);
		if (!checkInput(letter))
			return false;
	}
	letter = isbn.at(3);
	if (letter != '-')
	{
		cout << "\t\t\tError. Please follow the proper format." << endl;
		return false;
	}
	for (int i = 4; i < isbn.length(); i++)
	{
		letter = isbn.at(i);
		if (!checkInput(letter))
			return false;
	}
	return true;
}

/******************************************************************************
* Function: checkInput
* Description: This function checks to see if the character is a number and alerts
*			   the user if it isn't
* Input: letter - const character with a potential number
* Output: return true - if it is a number
		  return false - if it isn't a number
******************************************************************************/
bool checkInput(const char letter)
{
	if (!isdigit(letter))
	{
		cout << "\t\t\tError. Please follow the proper format." << endl;
		return false;
	}
	return true;
}