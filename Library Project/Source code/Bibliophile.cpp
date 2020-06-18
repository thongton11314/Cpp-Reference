/******************************************************************************
* PROJECT: FinalProject_LibraryCodex
* FILE: Bibliophile.cpp
* AUTHOR(S): Dean Ferris, Ton That Quynh Thong , Minpyo Kim & Kalkidan Tamirat
* DATE: 3/12/2019
* DESCRIPTION: This console-based program imitates a library database & allows
*			   the user to add/delete books, bibliophiles & view their activity
******************************************************************************/
#include "Bibliophile.h"
#include "BulletProof.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Bibliophile::Bibliophile() {}

/*******************************************************
* Constructor: Bilbiophile
* Description: Initializes the Bibliophile with its info.
* Input: name - string with their name
*		 SID - string with their SID
*		 occupation - string with their job
*******************************************************/
Bibliophile::Bibliophile(string name, string SID, string occupation)
{
	Bibliophile::setName(name);
	Bibliophile::setSID(SID);
	Bibliophile::setOccupation(occupation);
}

/**************************************************************************
 * Function: setName
 * Description: This function sets the name
 * Input: string - name
 ***************************************************************************/
void Bibliophile::setName(string name)
{
	Bibliophile::name = name;
}

/**************************************************************************
 * Function: setSID
 * Description: This function sets the SID
 * Input: string - SID
 ***************************************************************************/
void Bibliophile::setSID(string SID)
{
	if (checkSID(SID))
		Bibliophile::SID = SID;
	else
		throw invalid_argument("Please enter a proper SID.");
}

/**************************************************************************
 * Function: setOccupation
 * Description: This function sets the occupation
 * Input: string - occupation
 ***************************************************************************/
void Bibliophile::setOccupation(string Occupation)
{
	Bibliophile::occupation = occupation;
}

/**************************************************************************
 * Function: getName
 * Description: This function returns the user's name
 * Output: string - name
 ***************************************************************************/
string Bibliophile::getName() const
{
	return name;
}

/**************************************************************************
 * Function: getSID
 * Description: This function returns the SID
 * Output: string - SID
 ***************************************************************************/
string Bibliophile::getSID() const
{
	return SID;
}

/**************************************************************************
* Function: getOccupation
* Description: This function returns the occupation
* Output: string - occupation
***************************************************************************/
string Bibliophile::getOccupation() const
{
	return occupation;
}

/**************************************************************************
* Function: toString
* Description: This function returns a string with the Bibliophile's info
* Output: string - string with the bilbiophile's information
***************************************************************************/
string Bibliophile::toString() const
{
	return "Bibliophile: " + name + ", SID: " + SID + ", Occupation: " + occupation;
}