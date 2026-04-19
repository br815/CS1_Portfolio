/*	Author:		    		Bushra Rahman
	Course:		    		CS 1337 (Fall 2019)
	Date:					10/31/2019
	PassengerAircraft.h:	This header file contains the definition for the PassengerAircraft subclass. */

// header for #include guard (preprocessor directives)
#ifndef PASSENGERAIRCRAFT_H_	// if PASSENGERAIRCRAFT_H_ is not defined, define it (start of header guard)
#define PASSENGERAIRCRAFT_H_	// define PASSENGERAIRCRAFT_H_ once to prevent multiple inclusions
#include "Aircraft.h"			// include the header file for the base class
#include <string>
using namespace std;

class PassengerAircraft : public Aircraft
{
private:
	// string field that is unique to this class
	string strRangeAndSpeed;

public:
	// constructor
	PassengerAircraft(string strRangeAndSpeed,
			int seatCapacity = 2,
			int numberOfEngines = 1);
	// destructor
	virtual ~PassengerAircraft();

	// override the base class's member function
	void virtual printCharacteristics() const;

	// member function specific to this class
	void announceConnectingFlights();

	// getter and setter
	string getStrRangeAndSpeed() const;
	void setStrRangeAndSpeed(string strRangeAndSpeed);
};

#endif							// end of "if not defined" ifndef block