/*	Author:					Bushra Rahman
	Course:					CS 1337 (Fall 2019)
	Date:					11/14/2019
	CS1337Logger.cpp:		This source file contains the definitions for 4 of the 6 methods defined in the CS1337Logger abstract base class. */

// include the header files for this class and its subclasses
#include "CS1337Logger.h"
#include "ScreenLogger.h"
#include "FileLogger.h"
#include <iostream>
using namespace std;



/*	Function Type:		constructor
	Descr:				This constructor sets the private boolean variable loggingEnabled to false.
	Param:    			None.
	Return:				None, initializes a CS1337Logger object. */
CS1337Logger::CS1337Logger()
{
	loggingEnabled = false;
}



/*	Function Type:		destructor
	Descr:				This function de-allocates the memory used to create the CS1337Logger object.
						NOTE: There is NO memory to de-allocate in this class.
	Param:    			None.
	Return:				None. */
CS1337Logger::~CS1337Logger()
{
	//
}



/*	Function Name:		logMessage()
	Descr:				This function only allows displayMessage() to be called if logging is enabled.
	Param:    			const char* message
						Pointer to a string in memory.
	Return:				None. */
void CS1337Logger::logMessage(const char* message)
{
	if (loggingEnabled == true)
	{
		displayMessage(message);
	}
}



/*	Function Name:		Create()
	Descr:				This function implements a factory method design pattern to create objects of different types.
						Change is required only in this function to create a new object type.
						Called by LogSingleton's constructor.
	Param:    			LoggerType loggerType
						An instance of one of the two logger types defined in an enumeration in the CS1337Logger class.
	Return:				CS1337Logger*
						Pointer to a CS1337Logger object. */
CS1337Logger* CS1337Logger::Create(LoggerType loggerType)
{
    // checks against the enum and creates a new object corresponding to the enum's value
	if (loggerType == LT_FileLogger)
        return new FileLogger();
    else if (loggerType == LT_ScreenLogger)
        return new ScreenLogger();

    else return NULL;
}