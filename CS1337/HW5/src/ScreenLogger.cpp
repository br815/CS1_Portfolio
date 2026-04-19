/*	Author:					Bushra Rahman
	Course:					CS 1337 (Fall 2019)
	Date:					11/14/2019
	ScreenLogger.cpp:		This source file contains the definitions for the 4 methods defined in the ScreenLogger subclass. */

// include the header files for this subclass and its superclass
#include "CS1337Logger.h"
#include "ScreenLogger.h"
#include <iostream>



/*	Function Type:		constructor
	Descr:				This constructor creates a ScreenLogger object.
	Param:    			None.
	Return:				None, initializes a ScreenLogger object. */
ScreenLogger::ScreenLogger() : CS1337Logger()
{
	//
}



/*	Function Type:		destructor
	Descr:				This function de-allocates the memory used to create the ScreenLogger object.
						NOTE: There is NO memory to de-allocate in this class.
	Param:    			None.
	Return:				None. */
ScreenLogger::~ScreenLogger()
{
	//
}



/*	Function Name:		displayMessage()
	Descr:				This function is overridden from the base class's pure virtual function.
						This function displays the message given as an argument to the output console.
	Param:    			const char* message
						Pointer to a string in memory.
	Return:				None. */
void ScreenLogger::displayMessage(const char* message)
{
	cout << message << endl;
}



/*	Function Name:		logMessage()
	Descr:				This function only allows displayMessage() to be called if logging is enabled.
	Param:    			const char* message
						Pointer to a string in memory.
	Return:				None. */
void ScreenLogger::logMessage(const char* message)
{
	if (getLoggingEnabled() == true)
	{
		displayMessage(message);
	}
}