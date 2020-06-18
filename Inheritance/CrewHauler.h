/*
* Project: Vehicle Project
* File: CrewHauler.h
* Author: Ton That Quynh Thong
* Date: 4/7/2019
* Description: This is the header file for the CrewHauler class.
*/
#ifndef _CREWHAULER_
#define _CREWHAULER_
#include "PassengerVehicle.h"
#include "CargoVehicle.h"
#include <string>
#include <iostream>

/*
* Class: CrewHauler
* Description: This class definition of a CrewHauler that is
*			   an inheritance class of PassengerVehicle and CargoVehicle
*/
class CrewHauler : public PassengerVehicle, public CargoVehicle
{
	/*
	* Function: operator<<
	* Description: friend function that allows cout to be called on
	*              a CrewHauler object
	* Input:
	*     output - the output stream
	*     c - the vehicle whose data will be output
	* Output:
	*     ostream& - the output stream
	*/
	friend std::ostream& operator<<(std::ostream& output, const CrewHauler& c);
private:
public:
	/*
	* Function: constructor
	* Description: creates a new CrewHauler object
	* Input:
	*     brand - Vehicle's brand
	*     model - Vehicle's model
	*     year - Vehicle's year
	*	  door - Vehicle's door
	*	  seats - Vehicle's seat
	*	  capacity - Vehicle's capacity
	*/
	CrewHauler(std::string brand, std::string model, int year, int doors, int seats, double capacity);
};
#endif // !
