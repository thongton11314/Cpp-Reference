/*
* Project: Vehicle Project
* File: Vehicle.h
* Author: Ton That Quynh Thong
* Date: 4/7/2019
* Description: This is the header file for the Vehicle class.
*/
#ifndef _VEHICLE_
#define _VEHICLE_
#include <string>
#include <iostream>

/*
* Class: Vehicle
* Description: This class definition of a Vehicle that can
*              be used for an individual class.
* Data Members:
*     brand - Vehicle's brand
*     model - Vehicle's model
*     year - Vehicle's year
*/
class Vehicle
{
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
	friend std::ostream& operator<<(std::ostream& output, const Vehicle& v);
private:
	std::string brand;
	std::string model;
	int year;

public:
	/*
	* Function: constructor
	* Description: creates a new Vehicle object and sets the vehicle data
	* Input:
	*     brand - Vehicle's brand
	*     model - Vehicle's model
	*     year - Vehicle's year
	*/
	Vehicle(std::string brand, std::string model, int year);	

	/*
	* Function: setBrand
	* Description: This function use for setting Vehicle brand 
	* Input: 
	*	brand - the vehicle's brand
	*/
	void setBrand(std::string brand);

	/*
	* Function: setModel
	* Description: This function use for setting Vehicle model 
	* Input: 
	*	model - the vehicle's model
	*/
	void setModel(std::string model);	

	/*
	* Function: setYear
	* Description: This function use for setting Vehicle year 
	* Input: 
	*	year - the vehicle's year
	*/
	void setYear(int year);

	/*
	* Function: getBrand
	* Description: This function use for getting Vehicle brand 
	* Output:
	*	string - the vehicle's brand
	*/
	std::string getBrand() const;

	/*
	* Function: getModel
	* Description: This function use for getting Vehicle model 
	* Output:
	*	string - the vehicle's model
	*/
	std::string getModel() const;


	/*
	* Function: getYear
	* Description: This function use for getting Vehicle year 
	* Output:
	*	string - the vehicle's year
	*/
	int getYear() const;

	/*
	* Function: operator==
	* Description: Compare if another vehicle is same to this one
	* Input:
	*	other - the other vehicle to be compared
	* Output:
	*	bool - true if the are same, false if not
	*/
	bool operator==(const Vehicle& other) const;

	/*
	* Function: operator!=
	* Description: Compare if another vehicle is not same to this one
	* Input:
	*	other - the other vehicle to be compared
	* Output:
	*	bool - true if they are not same, true if they are same
	*/
	bool operator!=(const Vehicle& other) const;

	/*
	* Function: operator<
	* Description: Compare if another vehicle's year less than to this one
	* Input:
	*	other - the other vehicle to be compared
	* Output:
	*	bool - true if this vehicle's year less than other, false if other > this one
	*/
	bool operator<(const Vehicle& other) const;

	/*
	* Function: operator<=
	* Description: Compare if another vehicle's year less than to this one
	* Input:
	*	other - the other vehicle to be compared
	* Output:
	*	bool - true if this vehicle's year <= other, false if other > this one
	*/
	bool operator<=(const Vehicle& other) const;

	/*
	* Function: operator>
	* Description: Compare if another vehicle's year less than to this one
	* Input:
	*	other - the other vehicle to be compared
	* Output:
	*	bool - true if this vehicle's year >  other, false if other < this one
	*/
	bool operator>(const Vehicle& other) const;

	/*
	* Function: operator>=
	* Description: Compare if another vehicle's year less than to this one
	* Input:
	*	other - the other vehicle to be compared
	* Output:
	*	bool - true if this vehicle's year >=  other, false if other <= this one
	*/
	bool operator>=(const Vehicle& other) const;
};
#endif
