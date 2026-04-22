/*	Author:					Bushra Rahman
	Course:					CS 1337 (Fall 2019)
	Date:					11/14/2019
	FileLogger.h:			This header file contains the definition of the FileLogger subclass. 
							This class is derived from the CS1337Logger class. */

// header for #include guard (preprocessor directives)
#ifndef FILELOGGER_H_		// if FILELOGGER_H_ is not defined, define it (start of header guard)
#define FILELOGGER_H_		// define FILELOGGER_H_ once to prevent multiple inclusions
#include "CS1337Logger.h"	// include the header file for the base class
#include <string>
#include <fstream>
using namespace std;



class FileLogger : public CS1337Logger
{
private:
	// output file stream object
	ofstream fout;
	// name the output file: the output file provided is Log.txt
	const string FILENAME = "Log.txt";

public:
	// constructor
	FileLogger();
	// destructor
	virtual ~FileLogger();

	// override the base class's pure virtual function
	virtual void displayMessage(const char* message);

	// overridden function from the base class
	void logMessage(const char*);

};

#endif						// end of "if not defined" ifndef block