/*	Author:					Bushra Rahman
	Course:					CS 1337 (Fall 2019)
	Date:					11/14/2019
	LogSingleton.cpp:		This source file contains the definitions for 4 of the 5 methods defined in the LogSingleton class. */

#include "LogSingleton.h"	// header file for this class
#include "CS1337Logger.h"	// header file for the CS1337Logger abstract class
using namespace std;

// initialize ptrLogSingleton to NULL
LogSingleton* LogSingleton::ptrLogSingleton = nullptr;
// create space for the static variable
int LogSingleton::instanceCount = 0;



/*	Function Type:		constructor (allows for a singleton design pattern)
	Descr:				This constructor calls the Create() function from the CS1337Logger class.
						This constructor, in turn, is called in getTheSingleton(), which creates a new LogSingleton object.
						Therefore only one ScreenLogger or FileLogger object gets created whenever a LogSingleton object is instantiated,
						and any subsequent call to getTheSingleton() will only create a new object if none currently exist.
	Param:    			None.
	Return:				None, initializes a LogSingleton object. */
LogSingleton::LogSingleton()
{
	// increments the instant count
	++LogSingleton::instanceCount;

	// is hard-coded to call Create() for a ScreenLogger object,
	// but the argument can be changed between LT_ScreenLogger and LT_FileLogger.
	// a single change to this line changes the type of logging object that's created.
	ptrLogger = CS1337Logger::Create(LT_ScreenLogger);
}



/*	Function Name:		getTheSingleton() (allows for a singleton design pattern)
	Descr:				This function creates a new LogSingleton object only if none currently exist.
	Param:    			None.
	Return:				ptrLogSingleton
						Pointer to a LogSingleton object. */
LogSingleton* LogSingleton::getTheSingleton()
{
	if (ptrLogSingleton == nullptr)
	{
		ptrLogSingleton = new LogSingleton();
	}
	return ptrLogSingleton;
}



/*	Function Name:		getInstanceCount()
	Descr:				This is the getter for instanceCount, the number of instances that have been created.
	Param:    			None.
	Return:				int instanceCount
						The directly-retrieved int instanceCount. */
int LogSingleton::getInstanceCount()
{
	return instanceCount;
}



/*	Function Type:		destructor
	Descr:				This function de-allocates the memory used to create the LogSingleton object.
						NOTE: There is NO memory to de-allocate in this class.
	Param:    			None.
	Return:				None. */
LogSingleton::~LogSingleton()
{
	//
}