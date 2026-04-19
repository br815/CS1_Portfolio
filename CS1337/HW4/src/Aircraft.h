/*	Author:		    Bushra Rahman
	Course:		    CS 1337 (Fall 2019)
	Date:			10/31/2019
	Aircraft.h:		This header file contains the base class from which all the derived classes are made for this project.
					It is #included in the header files of each of the derived classes. */

// header for #include guard (preprocessor directives)
#ifndef AIRCRAFT_H_		// if AIRCRAFT_H_ is not defined, define it (start of header guard)
#define AIRCRAFT_H_		// define AIRCRAFT_H_ once to prevent multiple inclusions

// This is the base class from which 3 derived classes are to be made. It is for generic Aircraft objects.
class Aircraft
{
private:
	// this value holds the total number of aircrafts made. It is initialized in Aircraft.cpp
	static int aircraftCount;

	// 0, 1, 2, or 3, depending on which class (base or derived) the object is of
	int aircraftType;
	// numberOfEngines and seatCapacity are two generic traits common to any aircraft
	int numberOfEngines;
	int seatCapacity;

	// number assigned to the object when it is made (ie. 1st, 2nd, 3rd, ... etc)
	int aircraftID;

public:
	// constructor
	Aircraft(int seatCapacity = 2, int aircraftType = 0, int numberOfEngines = 1);
	// destructor
	virtual ~Aircraft();

	// getters
	int getAircraftType() const;
	int getAircraftID() const;
	int getNumberOfEngines() const;
	int getSeatCapacity() const;

	// inline getter for aircraftCount
	int getAircraftCount() const
	{ return aircraftCount; };

	// setters
	void setAircraftType(int aircraftType);
	// void setAircraftID(int aircraftID);
	void setNumberOfEngines(int numberOfEngines);
	void setSeatCapacity(int seatCapacity);

	// virtual method that is overridden in the each derived class
	void virtual printCharacteristics() const;
};

// Not here in .h file, must be in .cpp file
//int Aircraft::aircraftCount = 0;

#endif 					// end of "if not defined" ifndef block