/*	Author:			            Bushra Rahman
	Course:			            CS 1337 (Fall 2019)
	Date:			            12/5/2019
	SchoolObserver.h:	    	This header file contains the class definition for SchoolObserver, extended from AbstractObserver. */

// header for #include guard (preprocessor directives)
#ifndef SCHOOLOBSERVER_H_		// if SCHOOLOBSERVER_H_ is not defined, define it (start of header guard)
#define SCHOOLOBSERVER_H_		// define SCHOOLOBSERVER_H_ once to prevent multiple inclusions
#include "AbstractObserver.h"	// include the header file for the base class
#include <string>
#include <iostream>
using namespace std;

class SchoolObserver : public AbstractObserver
{
public:
	// overridden virtual function from AbstractObserver
	virtual void subjectChanged(string str)
	{
		cout << "object ID: " << getObserverID() << ". ";
		cout << "The SchoolObserver received an address change notification: <" << str << ">" << endl;
	}

	// inline destructor
	virtual ~SchoolObserver(){}
};

#endif							// end of "if not defined" ifndef block