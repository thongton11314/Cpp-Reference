/*
* Project: Vehicle Project
* File: CargoVehicle.cpp
* Author: Ton That Quynh Thong
* Date: 4/7/2019
* Description: This is the source file for the CargoVehicle class.
*/
#include <string>
#include <iostream>
#include <stdexcept>
#include "Vehicle.h"
#include "CargoVehicle.h"

using namespace std;

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
CargoVehicle::CargoVehicle(double capacity, string brand, string model, int year)
	: Vehicle(brand, model, year)
{
	setCapacity(capacity);
}

/*
* Function: setCapacity
* Description: This function will set capacity for vehicle
* Input
*	doors : vehicle's capacity
*/
void CargoVehicle::setCapacity(double capacity)
{
	if (capacity <= 0)
		throw invalid_argument("Capacity should be positive value");
	this->capacity = capacity;
}

/*
* Function: getCapacity
* Description: This function will get capacity for vehicle
* Output
*	capacity : vehicle's capacity
*/
double CargoVehicle::getCapacity() const
{
	return this->capacity;
}

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
ostream& operator<<(ostream& output, const CargoVehicle& c)
{
	output << c.getBrand() << ", " << c.getModel() << ", " << c.getYear() << ", " << c.getCapacity();
	return output;
}	