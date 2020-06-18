/******************************************************************************
* PROJECT: FinalProject_LibraryCodex
* FILE:	BulletProof.h
* AUTHOR(S): Dean Ferris, Ton That Quynh Thong , Minpyo Kim & Kalkidan Tamirat
* DATE: 3/12/2019
* DESCRIPTION: Helper function used to validate user input
******************************************************************************/
#ifndef _BULLETPROOF_
#define _BULLETPROOF_

#include <vector>
#include "Book.h"
#include "Bibliophile.h"

//Function prototyping

/******************************************************************************
* Function: cleanPipe
* Description: This function clears the string variable.
******************************************************************************/
void cleanPipe();

/******************************************************************************
* Function: bulletProof
* Description: function prompts user for input than validate it
* Input: T& input - User input that transfered.
*		 int& lowBound - lower bound of selection.
*		 int& upBound - upper bound of selection.
******************************************************************************/
void bulletProof(int& input, const int& lowBound, const int& upBound);

/******************************************************************************
* Function: bulletProofChar
* Description: Function prompt if user input outside of (y/n)
* Input: char& input - User input that transfered.
******************************************************************************/
void bulletProofChar(char& input);

/******************************************************************************
* Function: checkIDorBM
* Description: This overload function check that if book ISBN in library or not
* Input: const vector<Book>& trans - whole vector type book
		 const string& tmp - specific ISBN number
* Output: return true - if this ISBN is in library
		  return false - if this ISBN is not in library
******************************************************************************/
bool checkIDorBM(const std::vector<Book>& trans, const std::string& tmp);

/******************************************************************************
* Function: checkIDorBM
* Description: This overload function check that if book SID in library or not
* Input: const vector<Bibliophile>& trans - whole vector type Bibliophile
		 const string& tmp - specific SID number
* Output: return true - if this SID is in library
		  return false - if this SID is not in library
		  recieve the current index if matching by pass by reference
******************************************************************************/
bool checkIDorBM(const std::vector<Bibliophile>& trans, const std::string& tmp);

/******************************************************************************
* Function: checkISBN
* Description: This function checks to see if the user entered a valid ISBN
* Input: isbn - const string with a potential ISBN
* Output: return true - if this ISBN is valid
		  return false - if the ISBN isn't valid
******************************************************************************/
bool checkISBN(const std::string isbn);

/******************************************************************************
* Function: checkSID
* Description: This function checks to see if the user entered a valid SID
* Input: sid - const string with a potential SID number
* Output: return true - if this SID is valid
		  return false - if the SID isn't valid
******************************************************************************/
bool checkSID(const std::string sid);

/******************************************************************************
* Function: checkInput
* Description: This function checks to see if the character is a number and alerts
*			   the user if it isn't
* Input: letter - const character with a potential number
* Output: return true - if it is a number
		  return false - if it isn't a number
******************************************************************************/
bool checkInput(const char letter);

#endif // !_BULLETPROOF_