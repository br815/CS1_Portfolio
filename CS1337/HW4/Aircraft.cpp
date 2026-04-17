/*	Author:			Bushra Rahman
	Course:			CS 1337 (Fall 2019)
	Date:			10/31/2019
	Aircraft.cpp:	This source file contains the definitions for 10 of the 11 methods defined in the Aircraft base class. */

#include "Aircraft.h"	// header file for the base class Aircraft
#include <iostream>
//#include <cstdlib>
using namespace std;

int Aircraft::aircraftCount = 0;	// initializes static int aircraftCount



/*	Function Type:		constructor
	Descr:				This function initializes the aircraftID, aircraftType, numberOfEngines, and seatCapacity fields.
	Param:    			int seatCapacityR, int aircraftTypeR, int numberOfEnginesR
						These fields are in common across all classes derived from Aircraft.
	Return:				None, initializes an Aircraft object. */
Aircraft::Aircraft(int seatCapacityR, int aircraftTypeR, int numberOfEnginesR)
{
	// calls the methods that set each field to the given arguments
	setAircraftType(aircraftTypeR);
	setNumberOfEngines(numberOfEnginesR);
	setSeatCapacity(seatCapacityR);

	// initializes the aircraftID field by receiving the value in the static counter variable
	aircraftID = ++aircraftCount;

	//cout << endl << "constructor: ";
	//printCharacteristics();
}



/*	Function Type:		destructor
	Descr:				This function de-allocates the memory used to create the string fields in the Aircraft object.
						NOTE: There is NO memory to de-allocate in this class.
	Param:    			None.
	Return:				None. */
Aircraft::~Aircraft()
{
	// NO memory to de-allocate in this class.
}



/*	Function Name:		getAircraftType()
	Descr:				This is the getter for aircraftType.
						This method treats the object as a const to ensure it won't be modified.
	Param:    			None.
	Return:				int aircraftType
						The directly-retrieved int aircraftType. */
int Aircraft::getAircraftType() const
{
	return aircraftType;
}



/*	Function Name:		getAircraftID()
	Descr:				This is the getter for aircraftID.
						This method treats the object as a const to ensure it won't be modified.
	Param:    			None.
	Return:				int aircraftID
						The directly-retrieved int aircraftID. */
int Aircraft::getAircraftID() const
{
	return aircraftID;
}



/*	Function Name:		getNumberOfEngines()
	Descr:				This is the getter for numberOfEngines.
						This method treats the object as a const to ensure it won't be modified.
	Param:    			None.
	Return:				int numberOfEngines
						The directly-retrieved int numberOfEngines. */
int Aircraft::getNumberOfEngines() const
{
	return numberOfEngines;
}



/*	Function Name:		getSeatCapacity()
	Descr:				This is the getter for seatCapacity.
						This method treats the object as a const to ensure it won't be modified.
	Param:    			None.
	Return:				int seatCapacity
						The directly-retrieved int seatCapacity. */
int Aircraft::getSeatCapacity() const
{
	return seatCapacity;
}



/*	Function Name:		setAircraftType()
	Descr:				This is the setter for aircraftType.
	Param:    			int aircraftTypeR
						The inputted string to be set as aircraftType.
	Return:				None. */
void Aircraft::setAircraftType(int aircraftTypeR)
{
	// checks that the argument aircraftTypeR is valid (between 0 and 3 inclusive)
	if(aircraftTypeR >= 0 && aircraftTypeR <= 3)
	{
		aircraftType = aircraftTypeR;
	}
	else
	{
		cout << endl << "Invalid argument: " << aircraftTypeR
				<< " ** aircraft type must be within the range 0 through 3.";
		exit(EXIT_FAILURE);
	}
}



/*	Function Name:		setNumberOfEngines()
	Descr:				This is the setter for numberOfEngines.
	Param:    			int numberOfEnginesR
						The inputted string to be set as numberOfEngines.
	Return:				None. */
void Aircraft::setNumberOfEngines(int numberOfEnginesR)
{
	// checks that the argument numberOfEnginesR is within a range for the number of engines usually in an aircraft
	if(numberOfEnginesR >= 1 && numberOfEnginesR <= 6)
	{
		numberOfEngines = numberOfEnginesR;
	}
	else
	{
		cout << endl << "Invalid argument: " << numberOfEnginesR
				<< " ** Number of Engines must be within the range 1 through 6.";
		exit(EXIT_FAILURE);
	}
}



/*	Function Name:		setSeatCapacity()
	Descr:				This is the setter for seatCapacity.
	Param:    			int seatCapacityR
						The inputted string to be set as seatCapacity.
	Return:				None. */
void Aircraft::setSeatCapacity(int seatCapacityR)
{
	// checks that the argument seatCapacityR is within a range for the number of seats usually in an aircraft
	if(seatCapacityR >= 1 && seatCapacityR <= 1000)
	{
		seatCapacity = seatCapacityR;
	}
	else
	{
		cout << endl << "Invalid argument: " << seatCapacityR
				<< " ** Seat Capacity must be within the range 1 through 1000.";
		exit(EXIT_FAILURE);
	}
}



/*	Function Name:		printCharacteristics()
	Descr:				This is a virtual method that prints this class's fields.
						This method treats the object as a const to ensure it won't be modified.
	Param:    			None.
	Return:				None. */
void Aircraft::printCharacteristics() const
{
	cout << endl << "Aircraft ID: " << aircraftID
			<< " Aircraft Type: " << aircraftType
			<< " Number of Engines: " << numberOfEngines
			<< " Seat Capacity: " << seatCapacity;
}