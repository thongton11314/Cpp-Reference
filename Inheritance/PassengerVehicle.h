/*
* Project: Vehicle Project
* File: PassengerVehicle.h
* Author: Ton That Quynh Thong
* Date: 4/7/2019
* Description: This is the header file for the PassengerVehicle class.
*/
#ifndef _PassengerVehicle_
#define _PassengerVehicle_
#include <string>
#include "Vehicle.h"

/*
* Class: PassengerVehicle
* Description: This is the class definition of an PassengerVehicle that
*			   inherits from Vehicle class, also add doors and seats           
* Data Members:
*	doors : vehicle's doors
*	seats : vehicle's seats
*     
*/
class PassengerVehicle : public Vehicle
{
	/*
	* Function: operator<<
	* Description: friend function that overrides the vehicle version to
	*              add doors and seats information
	* Input:
	*     output - the output stream
	*     p - the passenget vehicle's data will be output
	* Output:
	*     ostream& - the output stream
	*/
	friend std::ostream& operator<<(std::ostream& output, const PassengerVehicle& p);
private:
	int doors;
	int seats;
public:
	/*
	* Function: constructor
	* Description: creates a new Passenger vehicle object and sets doors, seats,
	*              passing the remaining data to the vehicle base constructors
	* Input:
	*     doors - Vehicle's doors
	*     seats - Vehicle's seats
	*     brand - Vehicle's brand
	*     model - Vehicle's model
	*     year - Vehicle's year
	*/
	PassengerVehicle(int doors, int seats, std::string brand, std::string model, int year);

	/*
	* Function: setDoor
	* Description: This function will set doors for vehicle
	* Input
	*	doors : vehicle's doors
	*/
	void setDoor(int doors);

	/*
	* Function: setSeat
	* Description: This function will set seats for vehicle
	* Input
	*	seats : vehicle's seats
	*/
	void setSeat(int seats);

	/*
	* Function: getDoor
	* Description: This function will get vehicle's doors
	* Output
	*	int : vehicle's doors
	*/
	int getDoor() const;

	/*
	* Function: getSeat
	* Description: This function will get vehicle's seats
	* Output
	*	int : vehicle's seat
	*/
	int getSeat() const;
};
#endif
