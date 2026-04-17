/*	Author:					Bushra Rahman
	Course:					CS 1337 (Fall 2019)
	Date:					10/31/2019
	FreightAircraft.cpp:	This source file contains the definitions for the 7 methods defined in the FreightAircraft subclass. */

#include "FreightAircraft.h"	// header file for the subclass FreightAircraft
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;



/*	Function Type:		constructor
	Descr:				This function initializes the string fields in the FreightAircraft object.
	Param:    			string strFreightCompanyR, string strCargoCapacityR, int numberOfEngines, int seatCapacity
						These fields are unique to the FreightAircraft subclass.
						Additionally, Aircraft (seatCapacity, 3, numberOfEngines) is a member initializer list 
						that initializes those fields using the base class constructor:
						Aircraft(int seatCapacityR, int aircraftTypeR which is 3, int numberOfEnginesR).
	Return:				None, initializes a FreightAircraft object. */
FreightAircraft::FreightAircraft(string strFreightCompanyR, string strCargoCapacityR, int numberOfEngines, int seatCapacity) 
								: Aircraft (seatCapacity, 3, numberOfEngines)
{
	strFreightCompany = strFreightCompanyR;
	strCargoCapacity = strCargoCapacityR;
}



/*	Function Type:		destructor
	Descr:				This function de-allocates the memory used to create the string fields in the FreightAircraft object.
	Param:    			None.
	Return:				None. */
FreightAircraft::~FreightAircraft()
{
	delete &strFreightCompany;
	delete &strCargoCapacity;
}



/*	Function Name:		printCharacteristics()
	Descr:				This is an overriden base class method. It prints this class's fields.
						This method treats the object as a const to ensure it won't be modified.
	Param:    			None.
	Return:				None. */
void FreightAircraft::printCharacteristics() const
{
	// first call the base class printCharacteristics() method
	Aircraft::printCharacteristics();
	cout << endl << "    Freight Company: " << strFreightCompany << endl << "    Cargo Capacity: " << strCargoCapacity;
}



/*	Function Name:		getStrFreightCompany()
	Descr:				This is the getter for strFreightCompany.
						This method treats the object as a const to ensure it won't be modified.
	Param:    			None.
	Return:				string str
						The retrieved string strFreightCompany. */
string FreightAircraft::getStrFreightCompany() const
{
	string str = strFreightCompany;
	return str;
}



/*	Function Name:		setStrFreightCompany()
	Descr:				This is the setter for strFreightCompany.
	Param:    			string strFreightCompanyR
						The inputted string to be set as strFreightCompany.
	Return:				None. */
void FreightAircraft::setStrFreightCompany(string strFreightCompanyR)
{
	strFreightCompany = strFreightCompanyR;
}



/*	Function Name:		getStrCargoCapacity()
	Descr:				This is the getter for strCargoCapacity.
						This method treats the object as a const to ensure it won't be modified.
	Param:    			None.
	Return:				string str
						The retrieved string strCargoCapacity. */
string FreightAircraft::getStrCargoCapacity() const
{
	string str = strCargoCapacity;
	return str;
}



/*	Function Name:		setStrCargoCapacity()
	Descr:				This is the setter for strCargoCapacity.
	Param:    			string strCargoCapacityR
						The inputted string to be set as strCargoCapacity.
	Return:				None. */
void FreightAircraft::setStrCargoCapacity(string strCargoCapacityR)
{
	strCargoCapacity = strCargoCapacityR;
}