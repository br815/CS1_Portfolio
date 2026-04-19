/*	Author:					Bushra Rahman
	Course:					CS 1337 (Fall 2019)
	Date:					10/31/2019
	PassengerAircraft.cpp:	This source file contains the definitions for the 6 methods defined in the PassengerAircraft subclass. */

#include "PassengerAircraft.h"	// header file for the subclass PassengerAircraft
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;



/*	Function Type:		constructor
	Descr:				This function initializes the string fields in the PassengerAircraft object.
	Param:    			string strRangeAndSpeed, int seatCapacity, int numberOfEngines
						These fields are unique to the PassengerAircraft subclass.
						Additionally, Aircraft (seatCapacity, 1, numberOfEngines) is a member initializer list 
						that initializes those fields using the base class constructor:
						Aircraft(int seatCapacityR, int aircraftTypeR which is 1, int numberOfEnginesR).
	Return:				None, initializes a PassengerAircraft object. */
PassengerAircraft::PassengerAircraft(string strRangeAndSpeed, int seatCapacity, int numberOfEngines) 
									: Aircraft (seatCapacity, 1, numberOfEngines)
{
	// use the "this" pointer to the object to initialize the object's string field
	this->strRangeAndSpeed = strRangeAndSpeed;
}



/*	Function Type:		destructor
	Descr:				This function de-allocates the memory used to create the string field in the PassengerAircraft object.
	Param:    			None.
	Return:				None. */
PassengerAircraft::~PassengerAircraft()
{
	delete &strRangeAndSpeed;
}



/*	Function Name:		printCharacteristics()
	Descr:				This is an overriden base class method. It prints this class's fields.
						This method treats the object as a const to ensure it won't be modified.
	Param:    			None.
	Return:				None. */
void PassengerAircraft::printCharacteristics() const
{
	// first call the base class printCharacteristics() method
	Aircraft::printCharacteristics();
	cout << endl << "    Description: " << strRangeAndSpeed;
}



/*	Function Name:		announceConnectingFlights()
	Descr:				This is a method unique to this class.
	Param:    			None.
	Return:				None. */
void PassengerAircraft::announceConnectingFlights()
{
	cout << endl << "Passenger Aircraft " << getAircraftID() << ": Connecting Flights Info Announced";
}



/*	Function Name:		getStrRangeAndSpeed()
	Descr:				This is the getter for strRangeAndSpeed.
						This method treats the object as a const to ensure it won't be modified.
	Param:    			None.
	Return:				string str
						The retrieved string strRangeAndSpeed. */
string PassengerAircraft::getStrRangeAndSpeed() const
{
	string str = strRangeAndSpeed;
	return str;
}



/*	Function Name:		setStrRangeAndSpeed()
	Descr:				This is the setter for strRangeAndSpeed.
	Param:    			string strRangeAndSpeed
						The inputted string to be set as setStrRangeAndSpeed.
	Return:				None. */
void PassengerAircraft::setStrRangeAndSpeed(string strRangeAndSpeed)
{
	this->strRangeAndSpeed = strRangeAndSpeed;
}