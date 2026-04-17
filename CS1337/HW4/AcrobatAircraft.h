/*	Author:		    		Bushra Rahman
	Course:		    		CS 1337 (Fall 2019)
	Date:					10/31/2019
	AcrobatAircraft.h:		This header file contains the definition for the AcrobatAircraft subclass. */

// header for #include guard (preprocessor directives)
#ifndef ACROBATAIRCRAFT_H_		// if ACROBATAIRCRAFT_H_ is not defined, define it (start of header guard)
#define ACROBATAIRCRAFT_H_		// define ACROBATAIRCRAFT_H_ once to prevent multiple inclusions
#include "Aircraft.h"			// include the header file for the base class
#include <string>
using namespace std;

class AcrobatAircraft : public Aircraft
{
private:
	// string fields that are unique to this class
	string strManufacturer;
	string strPerformanceCapability;

public:
	// constructor
	AcrobatAircraft(string strManufacturer,
			string strPerformanceCapability,
			int seatCapacity = 2,
			int numberOfEngines = 1);
	// destructor
	virtual ~AcrobatAircraft();

	// override the base class's member function
	void virtual printCharacteristics() const;

	// member function specific to this class
	void doAcrobaticManeuver();

	// getters and setters
	string getStrManufacturer() const;
	void setStrManufacturer(string strManufacturer);
	string getStrPerformanceCapability() const;
	void setStrPerformanceCapability(string strPerformanceCapability);
};

#endif							// end of "if not defined" ifndef block