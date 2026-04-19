/*	Author:					Bushra Rahman
	Course:					CS 1337 (Fall 2019)
	Date:					11/14/2019
	FileLogger.cpp:			This source file contains the definitions for the 4 methods defined in the FileLogger subclass. */

// include the header files for this subclass and its superclass
#include "CS1337Logger.h"
#include "FileLogger.h"
#include <iostream>
#include <fstream>
using namespace std;



/*	Function Type:		constructor
	Descr:				This constructor opens the output file.
	Param:    			None.
	Return:				None, initializes a FileLogger object. */
FileLogger::FileLogger() : CS1337Logger()
{
	fout.open(FILENAME);
	if (!fout)
    {
        cerr << "ERROR: Could not open file: " << FILENAME << endl;
    }
}



/*	Function Type:		destructor
	Descr:				This destructor closes the output file.
	Param:    			None.
	Return:				None. */
FileLogger::~FileLogger()
{
	fout.close();
}



/*	Function Name:		displayMessage()
	Descr:				This function is overridden from the base class's pure virtual function.
						This function displays the message given as an argument in the output file.
	Param:    			const char* message
						Pointer to a string in memory.
	Return:				None. */
void FileLogger::displayMessage(const char* message)
{
	fout << message << endl;
}



/*	Function Name:		logMessage()
	Descr:				This function only allows displayMessage() to be called if logging is enabled.
	Param:    			const char* message
						Pointer to a string in memory.
	Return:				None. */
void FileLogger::logMessage(const char* message)
{
	if (getLoggingEnabled() == true)
	{
		displayMessage(message);
	}
}