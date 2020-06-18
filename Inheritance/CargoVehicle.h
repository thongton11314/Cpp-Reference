/*
* Project: Vehicle Project
* File: CargoVehicle.h
* Author: Ton That Quynh Thong
* Date: 4/7/2019
* Description: This is the header file for the CargoVehicle class.
*/
#ifndef _CargoVehicle_
#define _CargoVehicle_
#include <string>
#include "Vehicle.h"
#include <iostream>

/*
* Class: CargoVehicle
* Description: This is the class definition of an CargoVehicle that
*			   inherits from Vehicle class, also add capacity
* Data Members:
*	capacity : vehicle's capacity
*
*/
class CargoVehicle : public Vehicle
{
	/*
	* Function: operator<<
	* Description: friend function that allows cout to be called on
	*              a CargoVehicle object
	* Input:
	*     output - the output stream
	*     c - the vehicle whose data will be output
	* Output:
	*     ostream& - the output stream
	*/
	friend std::ostream& operator<<(std::ostream& output, const CargoVehicle& c);
private:
	double capacity;
public:
	/*
	* Function: constructor
	* Description: creates a new cargo vehicle object and set capacity,
	*              passing the remaining data to the vehicle base constructors
	* Input:
	*	  capacity - vehicle's capacity
	*     brand - Vehicle's brand
	*     model - Vehicle's model
	*     year - Vehicle's year
	*/
	CargoVehicle(double capacity, std::string brand, std::string model, int year);

	/*
	* Function: setCapacity
	* Description: This function will set capacity for vehicle
	* Input
	*	doors : vehicle's capacity
	*/
	void setCapacity(double capacity);

	/*
	* Function: getCapacity
	* Description: This function will get capacity for vehicle
	* Output
	*	capacity : vehicle's capacity
	*/
	double getCapacity() const;
};
#endif