/******************************************************************************
* PROJECT: FinalProject_LibraryCodex
* FILE: Bibliophile.h
* AUTHOR(S): Dean Ferris, Ton That Quynh Thong , Minpyo Kim & Kalkidan Tamirat
* DATE: 3/12/2019
* DESCRIPTION: This console-based program imitates a library database & allows
*			   the user to add/delete books, bibliophiles & view their activity
******************************************************************************/
#ifndef _BIBLIOPHILE_
#define _BIBLIOPHILE_
#include <string>
#include <vector>

/******************************************************
 * Class: Bilbiophile
 * Description: A class representing someone who uses the 
 *				library alot.
 ******************************************************/
class Bibliophile
{
private:
	std::string name;
	std::string SID;
	std::string occupation;
public:
	/*****************************************************
	 * Constructor: Default
	 * Description: Used to stores collection of objects
	 *****************************************************/
	Bibliophile();

	/*******************************************************
	* Constructor: Bilbiophile
	* Description: Initializes the Bibliophile with its info.
	* Input: name - string with their name
	*		 SID - string with their SID
	*		 occupation - string with their job
	*******************************************************/
	Bibliophile(std::string name, std::string SID, std::string occupation);

	/**************************************************************************
	* Function: setName
	* Description: This function sets the name 
	* Input: string - name
	***************************************************************************/
	void setName(std::string name);

	/**************************************************************************
	 * Function: setSID
	 * Description: This function sets the SID
	 * Input: string - SID
	 ***************************************************************************/
	void setSID(std::string SID);

	/**************************************************************************
	 * Function: setOccupation
	 * Description: This function sets the occupation
	 * Input: string - occupation
	 ***************************************************************************/
	void setOccupation(std::string Occupation);

	/**************************************************************************
	 * Function: getName
	 * Description: This function returns the user's name 
	 * Output: string - name
	 ***************************************************************************/
	std::string getName() const;
	
	/**************************************************************************
     * Function: getSID
     * Description: This function returns the SID
	 * Output: string - SID
	 ***************************************************************************/
	std::string getSID() const;

	/**************************************************************************
	* Function: getOccupation
	* Description: This function returns the occupation
	* Output: string - occupation
	***************************************************************************/
	std::string getOccupation() const;


	/**************************************************************************
	* Function: toString
	* Description: This function returns a string with the Bibliophile's info
	* Output: string - string with the bilbiophile's information 
	***************************************************************************/
	std::string toString() const;
};

#endif
