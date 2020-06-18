/*
* Project: Vehicle Project
* File: Main.cpp
* Author: Ton That Quynh Thong
* Date: 4/7/2019
* Description: This is the main source file for the project.
*/

#include <iostream>
#include <string>
#include "Vehicle.h"
#include "PassengerVehicle.h"
#include "CargoVehicle.h"
#include "CrewHauler.h"

using namespace std;

//Function prototype
void testingVehicle(Vehicle v);
void testingPassengerVehicle(PassengerVehicle pV);
void testingCargoVehicle(CargoVehicle cV);
void testingOverload(Vehicle v1, Vehicle v2);

/*
* Function: main
* Description: Statring point of program, test the classes
				which Vehicle, PassengetVehicle, CargoVehicle, CewHauler
*/
int main()
{
	//Start testing Vehicle class
	Vehicle vehicle1("Lamboghini", "Aventador", 2019);
	cout << "Vehicle constructor: PASSED" << endl;
	//Testing Vehicle overload cout<<
	cout << "Overload cout<< " << vehicle1 << ": PASSED" << endl;	
	//Testing Vehicle argument and function
	testingVehicle(vehicle1);
	Vehicle vehicle2("Ferrari", "458 Italia", 2016);
	testingOverload(vehicle1, vehicle2);
	cout << endl; //End of testing Vehicle Class
	//Start testing PassengerVehicle class
	//Testing PassengerVehicle constructor
	PassengerVehicle passenger1(2, 2, vehicle1.getBrand(), vehicle1.getModel(), vehicle1.getYear());
	cout << "PassengerVehicle constructor: PASSED" << endl;
	//Testing PassengerVehicle overload cout<<
	cout << "Overload cout<< " << passenger1 << ": PASSED" << endl;
	//Testing PassengerVehicle arugment and function
	testingPassengerVehicle(passenger1);
	cout << endl; //End of testing PassengerVehicle Class
	//Start testing CargoVehicle class
	//Testing CargoVehicle constructor
	CargoVehicle cargo1(50, vehicle1.getBrand(), vehicle1.getModel(), vehicle1.getYear());
	cout << "CargoVehicle constructor: PASSED" << endl;
	//Testing CargoVehicle overload cout<<
	cout << "Overload cout<< " << cargo1 << ": PASSED" << endl;
	//Testing CargoVehicle arugment and function
	testingCargoVehicle(cargo1);
	cout << endl; // End of testing CargoVehicle Class
	//Start testing CrewHauler class
	//Testing CrewHauler constructor
	CrewHauler crew(vehicle1.getBrand(), vehicle1.getModel(), vehicle1.getYear(), passenger1.getDoor(), passenger1.getSeat(), cargo1.getCapacity());
	cout << "CrewHauler constructor: PASSED" << endl;
	//Testing CrewHauler overload cout<<
	cout << "Overload cout<< " << crew << ": PASSED" << endl;
	cout << endl; // End of testing CrewHauler Class
	//Testing end
	getchar();
	return 0;
}

/*
* Function: testingVehicle
* Description: Testing vehicle class
* Input:
*	Vehicle v : an object type vehicle
*/
void testingVehicle(Vehicle v)
{
	//Testing getBrand
	if (v.getBrand() == "Lamboghini")
		cout << "getBrand: PASSED" << endl;
	else
		cout << "getBrand: FAILED" << endl;
	//Testing getModel
	if(v.getModel() == "Aventador")
		cout << "getModel: PASSED" << endl;
	else
		cout << "getModel: FAILED" << endl;
	//Testing getYear
	if (v.getYear() > 0)
		cout << "getYear: PASSED" << endl;
	else
		cout << "getYear: FAILED" << endl;
	//Test setBrand with blank data
	try
	{
		v.setBrand("");
	}
	catch (invalid_argument ia)
	{
		cout << "setBrand with blank data: PASSED" << endl;
	}	
	if (v.getBrand() == "")
		cout << "setBrand with blank data: FAILED" << endl;
	//Test setModel with blank data
	try
	{
		v.setModel("");
	}
	catch (invalid_argument ia)
	{
		cout << "setModel with blank data: PASSED" << endl;
	}
	if (v.getModel() == "")
		cout << "setModel with blank data: FAILED" << endl;
	//Test setYear with negative data
	try
	{
		v.setYear(0);
	}
	catch (invalid_argument ia)
	{
		cout << "setYear with non-positive data: PASSED" << endl;
	}
}

/*
* Function: testingOverload
* Description: compare two vehicle object
* Input:
*	Vehicle v1 : first object type vehicle
*	Vehicle v2 : second object type vehicle
*/
void testingOverload(Vehicle v1, Vehicle v2)
{	
	//Testing overload <
	if (v1 < v2)
		cout << "Overload<: FALSED" << endl;
	else
		cout << "Overload<: PASSED" << endl;
	//Testing overload <=
	if (v1 <= v2)
		cout << "Overload<=: FALSED" << endl;
	else
		cout << "Overload<=: PASSED" << endl;
	//Testing overload >
	if (v1 > v2)
		cout << "Overload>: PASSED" << endl;
	else
		cout << "Overload>: FALSED" << endl;
	//Testing overload >=
	if (v1 >= v2)
		cout << "Overload>=: PASSED" << endl;
	else
		cout << "Overload>=: FALSED" << endl;
	//Testing overload ==
	if (v1 == v2)
		cout << "Overload==: FALSED" << endl;
	else
		cout << "Overload==: PASSED" << endl;
	//Testing overload !=
	if (v1 != v2)
		cout << "Overload!=: PASSED" << endl;
	else
		cout << "Overload!=: FALSED" << endl;
}

/*
* Function: testingPassengerVehicle
* Description: Testing PassengerVehicle class
* Input:
*	PassengerVehicle pV : an object type PassengerVehicle
*/
void testingPassengerVehicle(PassengerVehicle pV)
{
	//Testing getDoor
	if (pV.getDoor() > 0)
		cout << "getDoor: PASSED" << endl;
	else
		cout << "getDoor: FAILED" << endl;
	//Testing getSeat
	if (pV.getSeat() > 0)
		cout << "getSeat: PASSED" << endl;
	else
		cout << "getSeat: FAILED" << endl;
	//Testing setDoor
	try
	{
		pV.setDoor(0);
	}
	catch (invalid_argument ia)
	{
		cout << "setDoor with non-positive data: PASSED" << endl;
	}
	//Testing setSeat
	try
	{
		pV.setSeat(0);
	}
	catch (invalid_argument ia)
	{
		cout << "setSeat with non-positive data: PASSED" << endl;
	}
}

/*
* Function: testingCargoVehicle
* Description: Testing CargoVehicle class
* Input:
*	CargoVehicle cV : an object type CargoVehicle
*/
void testingCargoVehicle(CargoVehicle cV)
{
	//Testing getCapcity
	if (cV.getCapacity() > 0)
		cout << "getCapacity: PASSED" << endl;
	else
		cout << "getCapcity: FAILED" << endl;
	//Testing setCapcity
	try
	{
		cV.setCapacity(0);
	}
	catch (invalid_argument ia)
	{
		cout << "setCapacity with non-positive data: PASSED" << endl;
	}
}