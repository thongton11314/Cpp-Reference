/*
* Project: Vehicle Project
* File: PassengerVehicle.cpp
* Author: Ton That Quynh Thong
* Date: 4/7/2019
* Description: This is the source file for the PassengerVehicle class.
*/
#include <string>
#include <iostream>
#include <stdexcept>
#include "PassengerVehicle.h"
#include "Vehicle.h"

using namespace std;

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
PassengerVehicle::PassengerVehicle(int doors, int seats, string brand, string model, int year)
	: doors(doors), seats(seats), Vehicle(brand,model,year)
{
	setDoor(doors);
	setSeat(seats);
}

/*
* Function: setDoor
* Description: This function will set doors for vehicle
* Input
*	doors : vehicle's doors
*/
void PassengerVehicle::setDoor(int doors)
{
	if (doors <= 0)
		throw invalid_argument("It must have at least one door");
	this->doors = doors;
}

/*
* Function: setSeat
* Description: This function will set seats for vehicle
* Input
*	seats : vehicle's seats
*/
void PassengerVehicle::setSeat(int seats)
{
	if (seats <= 0)
		throw invalid_argument("It must have at least one seat");
	this->seats = seats;
}

/*
* Function: getDoor
* Description: This function will get vehicle's doors
* Output
*	int : vehicle's doors
*/
int PassengerVehicle::getDoor() const
{
	return this->doors;
}

/*
* Function: getSeat
* Description: This function will get vehicle's seats
* Output
*	int : vehicle's seat
*/
int PassengerVehicle::getSeat() const
{
	return this->seats;
}

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
ostream& operator<<(ostream& output, const PassengerVehicle& p)
{
	output << p.getBrand() << ", " << p.getModel() << ", "  << p.getYear() << ", "  << p.getDoor() << ": " << p.getSeat();
	return output;
}