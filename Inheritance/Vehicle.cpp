/*
* Project: Vehicle Project
* File: Vehicle.cpp
* Author: Ton That Quynh Thong
* Date: 4/7/2019
* Description: This is the source file for the Vehicle class.
*/
#include <string>
#include <iostream>
#include <stdexcept>
#include "Vehicle.h"

using namespace std;

/*
* Function: constructor
* Description: creates a new Vehicle object and sets the vehicle data
* Input:
*     brand - Vehicle's brand
*     model - Vehicle's model
*     year - Vehicle's year
*/
Vehicle::Vehicle(string brand, string model, int year) : brand(brand), model(model), year(year) 
{
	setBrand(brand);
	setModel(model);
	setYear(year);
}

/*
* Function: setBrand
* Description: This function use for setting Vehicle brand
* Input:
*	brand - the vehicle's brand
*/
void Vehicle::setBrand(std::string brand) 
{
	if (brand.empty())
		throw invalid_argument("Brand must be type value");
	this->brand = brand.substr(0, 25);
}

/*
* Function: setModel
* Description: This function use for setting Vehicle model
* Input:
*	model - the vehicle's model
*/
void Vehicle::setModel(std::string model) 
{
	if (model.empty())
		throw invalid_argument("Model must be type value");
	this->model = model.substr(0, 25);
}

/*
* Function: setYear
* Description: This function use for setting Vehicle year
* Input:
*	year - the vehicle's year
*/
void Vehicle::setYear(int year)
{
	if (year < 0)
		throw invalid_argument("Year must be greater than 0");
	this->year = year;
}

/*
* Function: getBrand
* Description: This function use for getting Vehicle brand
* Output:
*	string - the vehicle's brand
*/
string Vehicle::getBrand() const 
{
	return brand;
}

/*
* Function: getModel
* Description: This function use for getting Vehicle model
* Output:
*	string - the vehicle's model
*/
string Vehicle::getModel() const 
{
	return model;
}

/*
* Function: getYear
* Description: This function use for getting Vehicle year
* Output:
*	string - the vehicle's year
*/
int Vehicle::getYear() const
{
	return year;
}

/*
* Function: operator==
* Description: Compare if another vehicle is same to this one
* Input:
*	other - the other vehicle to be compared
* Output:
*	bool - true if the are same, false if not
*/
bool Vehicle::operator==(const Vehicle& other) const
{
	if (this->model == other.getModel() && this->brand == other.getBrand() && this->year == other.getYear())
		return true;
	else
		return false;
}

/*
* Function: operator!=
* Description: Compare if another vehicle is not same to this one
* Input:
*	other - the other vehicle to be compared
* Output:
*	bool - true if they are not same, true if they are same
*/
bool Vehicle::operator!=(const Vehicle& other) const
{
	if (this->model != other.getModel() || this->brand != other.getBrand() || this->year != other.getYear())
		return true;
	else
		return false;
}

/*
* Function: operator<
* Description: Compare if another vehicle's year less than to this one
* Input:
*	other - the other vehicle to be compared
* Output:
*	bool - true if this vehicle's year less than other, false if other > this one
*/
bool Vehicle::operator<(const Vehicle& other) const
{
	if (this->year < other.getYear())
		return true;
	else
		return false;
}

/*
* Function: operator<=
* Description: Compare if another vehicle's year less than to this one
* Input:
*	other - the other vehicle to be compared
* Output:
*	bool - true if this vehicle's year <= other, false if other > this one
*/
bool Vehicle::operator<=(const Vehicle& other) const
{
	if (this->year <= other.getYear())
		return true;
	else
		return false;
}

/*
* Function: operator>
* Description: Compare if another vehicle's year less than to this one
* Input:
*	other - the other vehicle to be compared
* Output:
*	bool - true if this vehicle's year >  other, false if other < this one
*/
bool Vehicle::operator>(const Vehicle& other) const
{
	if (this->year > other.getYear())
		return true;
	else
		return false;
}

/*
* Function: operator>=
* Description: Compare if another vehicle's year less than to this one
* Input:
*	other - the other vehicle to be compared
* Output:
*	bool - true if this vehicle's year >=  other, false if other <= this one
*/
bool Vehicle::operator>=(const Vehicle& other) const
{
	if (this->year >= other.getYear())
		return true;
	else
		return false;
}

/*
* Function: operator<<
* Description: friend function that allows cout to be called on
*              a Vehicle object
* Input:
*     output - the output stream
*     v - the vehicle whose data will be output
* Output:
*     ostream& - the output stream
*/
ostream& operator<<(ostream& output, const Vehicle& vehicle) 
{	
	output << vehicle.getBrand() << ", " << vehicle.getModel() << ", " << vehicle.getYear() << ".";
	return output;
}
