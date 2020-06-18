/*
* Project: Vehicle Project
* File: CrewHauler.cpp
* Author: Ton That Quynh Thong
* Date: 4/7/2019
* Description: This is the source file for the CrewHauler class.
*/
#include "PassengerVehicle.h"
#include "CargoVehicle.h"
#include "CrewHauler.h"
#include "Vehicle.h"
#include <string> 

using namespace std;

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
CrewHauler::CrewHauler(string brand, string model, int year, int doors, int seats, double capacity)
	: PassengerVehicle(doors, seats, brand, model, year), CargoVehicle(capacity, brand, model, year) 
{}

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
ostream& operator<<(ostream& output, const CrewHauler& c)
{
	output << c.getDoor() << ", " << c.getSeat() << ", " << c.getCapacity();
	return output;
}
