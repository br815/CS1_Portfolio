/*	Author:					Bushra Rahman
	Course:					CS 1337 (Fall 2019)
	Date:					11/14/2019
	LogSingleton.h:			This header file contains the definition of the LogSingleton class. */

// header for #include guard (preprocessor directives)
#ifndef LOGSINGLETON_H_		// if LOGSINGLETON_H_ is not defined, define it (start of header guard)
#define LOGSINGLETON_H_		// define LOGSINGLETON_H_ once to prevent multiple inclusions
// include the header files for all the logging classes
#include "CS1337Logger.h"
#include "FileLogger.h"
#include "ScreenLogger.h"
using namespace std;


class LogSingleton
{
private:
	// constructor
	LogSingleton();

	// a pointer to a LogSingleton object
	static LogSingleton* ptrLogSingleton;

	// a counter for all LogSingleton objects
	static int instanceCount;

	// a pointer to a CS1337Logger object
	CS1337Logger* ptrLogger;


public:
	// destructor
	virtual ~LogSingleton();

	// static member function
	static LogSingleton* getTheSingleton();

	// getter for instanceCount
	int getInstanceCount();

	// inline getter for ptrLogger, returns the pointer
	static CS1337Logger* GetLogger()
	{
		return LogSingleton::getTheSingleton()->ptrLogger;
	}

};

#endif						// end of "if not defined" ifndef block