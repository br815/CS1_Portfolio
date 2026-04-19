/*	Author:					Bushra Rahman
	Course:					CS 1337 (Fall 2019)
	Date:					11/14/2019
	LogSingleton-Test.cpp:	This source file is the main driver of the program. Its purpose is to demonstrate usage of the LogSingleton class.
							It contains 4 helper functions in addition to main(): 
							1) someFunction()
							2) anotherFunction
							3) differentFunction()
							4) singletonTest() */

// include the header files for the base class and its derived classes
#include "CS1337Logger.h"
#include "ScreenLogger.h"
#include "FileLogger.h"
#include "LogSingleton.h"
#include <iostream>
using namespace std;



/*	Function 1:		someFunction()
	Descr:			This function logs a message, which will only work if logging is already enabled.
	Param:    		None.
	Return:			None. */
void someFunction()
{
	// enter someFunction()
	cout << "Inside someFunction" << endl;

	//LogSingleton::GetLogger()->setLoggingEnabled(true);
	LogSingleton::GetLogger()->logMessage("some function log message");

	// exit someFunction()
	cout << "Leaving someFunction" << endl;
}



/*	Function 2:		anotherFunction()
	Descr:			This function logs a message, but it won't work because logging is disabled in this function.
	Param:    		None.
	Return:			None. */
void anotherFunction()
{
	// enter anotherFunction()
	cout << "Inside anotherFunction" << endl;

	// disables logging and then logs a message, which doesn't actually log because logging is disabled
	// logging must be enabled again elsewhere in order for new messages to be logged
	LogSingleton::GetLogger()->setLoggingEnabled(false);
	LogSingleton::GetLogger()->logMessage("another function log message - won't show because logging is disabled");

	// exit anotherFunction()
	cout << "Leaving anotherFunction" << endl;
}



/*	Function 3:		differentFunction()
	Descr:			This function logs a message after enabling logging, so the logging will work.
	Param:    		None.
	Return:			None. */
void differentFunction()
{
	// enter differentFunction()
	cout << "Inside differentFunction" << endl;

	// creates a pointer to a LogSingleton object
	LogSingleton* singleton = LogSingleton::getTheSingleton();

	// enables logging and logs a message
	singleton->GetLogger()->setLoggingEnabled(true);
	singleton->GetLogger()->logMessage("different function log message");

	// exit differentFunction()
	cout << "Leaving differentFunction" << endl;
}



/*	Function 4:		singletonTest()
	Descr:			This function exercises the LogSingleton class.
	Param:    		None.
	Return:			0 */
int singletonTest()
{

	// enables logging
	LogSingleton::GetLogger()->setLoggingEnabled(true);

	// since LogSingleton's constructor is set to Create(LT_ScreenLogger), these messages are outputted to the screen
	LogSingleton::GetLogger()->logMessage("Log Message #1");

	// pointers i1, i2, and i3 point to a single LogSingleton object
	LogSingleton *i1, *i2, *i3;


	// this is the first call to getTheSingleton(), so this is the only new LogSingleton that is made
	i1 = LogSingleton::getTheSingleton();

	// prints the number of instances of LogSingleton so far
	cout << "Instance Count: " << i1->getInstanceCount() << endl;

	i1->GetLogger()->logMessage("Log Message called on i1 Singleton Object");


	// this call to getTheSingleton again will not create a new object because ptrLogSingleton is no longer NULL
	i2 = LogSingleton::getTheSingleton();

	// disables logging
	i2->GetLogger()->setLoggingEnabled(false);

	i2->GetLogger()->logMessage("Log Message called on i2 Singleton Object");


	// this call to getTheSingleton again will not create a new object
	i3 = LogSingleton::getTheSingleton();

	i3->GetLogger()->logMessage("Log Message called on i3 Singleton Object");

	// enables logging again
	i3->GetLogger()->setLoggingEnabled(true);

	// proves all the pointers are pointing to the same LogSingleton object
	if ((i1 == i2) && (i2 == i3))
	{
		cout << endl << "All instances are the same" << endl << endl << endl;
	}


	// calls to someFunction(), anotherFunction(), and differentFunction()
	// these are functions that do not do anything other than log messages
	someFunction();			// logging is already enabled so the message will be logged
	anotherFunction();		// disables logging
	someFunction();			// won't show because logging has been disabled
	someFunction();			// won't show because logging has been disabled
	differentFunction();	// enables logging again

	return 0;
}



/*	Function 5:		main()
	Descr:			This function is the program driver and calls the singletonTest() function.
	Param:    		None.
	Return:			0 */
int main()
{

	// these 3 lines can commented or uncommented to toggle creation of Log.txt
	FileLogger* logger = new FileLogger;
	logger->setLoggingEnabled(true);
	logger->logMessage("testing testing testing");
	

	singletonTest();

	return 0;
}