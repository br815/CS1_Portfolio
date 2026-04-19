/*	Author:					Bushra Rahman
	Course:					CS 1337 (Fall 2019)
	Date:					11/14/2019
	FileLogger.h:			This header file contains the definition of the ScreenLogger subclass. 
							This class is derived from the CS1337Logger class. */

// header for #include guard (preprocessor directives)
#ifndef SCREENLOGGER_H_		// if SCREENLOGGER_H_ is not defined, define it (start of header guard)
#define SCREENLOGGER_H_		// define SCREENLOGGER_H_ once to prevent multiple inclusions
#include "CS1337Logger.h"	// include the header file for the base class
#include <string>
using namespace std;



class ScreenLogger : public CS1337Logger
{
public:
	// constructor
	ScreenLogger();
	// destructor
	virtual ~ScreenLogger();

	// override the base class's pure virtual function
	virtual void displayMessage(const char* message);

	// overridden function from the base class
	void logMessage(const char*);
};

#endif						// end of "if not defined" ifndef block