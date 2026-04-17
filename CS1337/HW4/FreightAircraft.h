/*	Author:		    		Bushra Rahman
	Course:		    		CS 1337 (Fall 2019)
	Date:					10/31/2019
	FreightAircraft.h:		This header file contains the definition for the FreightAircraft subclass. */

// header for #include guard (preprocessor directives)
#ifndef FREIGHTAIRCRAFT_H_		// if FREIGHTAIRCRAFT_H_ is not defined, define it (start of header guard)
#define FREIGHTAIRCRAFT_H_		// define FREIGHTAIRCRAFT_H_ once to prevent multiple inclusions
#include "Aircraft.h"			// include the header file for the base class
#include <string>
using namespace std;

class FreightAircraft : public Aircraft
{
private:
	// string fields that are unique to this class
	string strFreightCompany;
	string strCargoCapacity;

public:
	// constructor
	FreightAircraft(string strFreightCompany,
			string strCargoCapacity,
			int numberOfEngines = 1,
			int seatCapacity = 2);
	// destructor
	virtual ~FreightAircraft();

	// override the base class's member function
	void virtual printCharacteristics() const;

	// insert member function specific to this class

	// getters and setters
	string getStrFreightCompany() const;
	void setStrFreightCompany(string strFreightCompany);
	string getStrCargoCapacity() const;
	void setStrCargoCapacity(string strCargoCapacity);
};

#endif							// end of "if not defined" ifndef block